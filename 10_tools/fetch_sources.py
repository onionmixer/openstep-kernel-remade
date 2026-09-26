#!/usr/bin/env python3
"""Fetch only reference inputs; record revisions and checksums, including failures."""
import gzip
import hashlib
import json
import os
import subprocess
import sys
import tarfile
import urllib.request
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MANIFEST = ROOT / "01_resources/manifests/acquisition.json"
SOURCES = [
    ("mach4", "git", "https://github.com/openmach/mach4.git", "01_resources/upstream/mach4"),
    ("nextmach", "git", "https://github.com/johnsonjh/NeXTMach.git", "01_resources/upstream/nextmach"),
]
for filename in ("kernel-1.tar.gz", "driverkit-139.1-1.tar.gz", "architecture-1.tar.gz", "APPLE_LICENSE.txt"):
    SOURCES.append(("darwin01-" + filename, "archive" if filename.endswith(".gz") else "text",
                    "https://downloads.sourceforge.net/project/aapl-darwin/Darwin-0.1/" + filename,
                    "01_resources/archives/" + filename))


def git(*args):
    result = subprocess.run(["git", *args], text=True, capture_output=True, timeout=120,
                            env={**os.environ, "GIT_TERMINAL_PROMPT": "0"})
    if result.returncode:
        raise RuntimeError(result.stderr.strip())
    return result.stdout.strip()


def digest(path):
    result = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            result.update(block)
    return result.hexdigest()


def validate_file(path, kind):
    if kind == "archive":
        # Some historical SourceForge .tar.gz files are actually uncompressed tar.
        # Inspect bytes, never infer compression solely from the published filename.
        with path.open("rb") as stream:
            compressed = stream.read(2) == b"\x1f\x8b"
        members = 0
        with tarfile.open(path, "r:gz" if compressed else "r:") as archive:
            for member in archive:
                members += 1
                if member.isfile():
                    with archive.extractfile(member) as stream:
                        while stream.read(1024 * 1024):
                            pass  # Read all payloads, so truncated final members fail.
            if not members:
                raise ValueError("Empty archive")
        if compressed:
            with gzip.open(path, "rb") as stream:
                while stream.read(1024 * 1024):
                    pass  # Verify compressed stream, including trailer.
        return {"archive_format": "tar+gzip" if compressed else "tar",
                "archive_member_count": members}
    else:
        text = path.read_text(errors="replace")
        if "<html" in text.lower() or "license" not in text.lower():
            raise ValueError("Expected license text; received another document")
        return {}


def main():
    previous = json.loads(MANIFEST.read_text()) if MANIFEST.exists() else {"sources": []}
    locked = {row["id"]: row for row in previous["sources"]}
    rows = []
    for source_id, kind, url, name in SOURCES:
        path = ROOT / name
        row = dict(id=source_id, kind=kind, url=url, path=name,
                   attempted_utc=datetime.now(timezone.utc).isoformat())
        old = locked.get(source_id, {})
        try:
            path.parent.mkdir(parents=True, exist_ok=True)
            if kind == "git":
                if not path.exists():
                    git("clone", "--depth", "1", "--", url, str(path))
                if not (path / ".git").is_dir():
                    raise ValueError("Existing destination is not a Git checkout")
                if git("-C", str(path), "remote", "get-url", "origin") != url:
                    raise ValueError("Existing checkout has a different origin")
                if git("-C", str(path), "status", "--porcelain"):
                    raise ValueError("Reference checkout has local modifications")
                commit = git("-C", str(path), "rev-parse", "HEAD")
                if old.get("commit") and old["commit"] != commit:
                    raise ValueError("Checkout revision differs from acquisition lock")
                if source_id == "nextmach" and not (path / "mk-108.1").is_dir():
                    raise ValueError("mk-108.1 source directory not found")
                row.update(commit=commit, status="acquired")
            else:
                if not path.exists():
                    part = path.with_name(path.name + ".part")
                    # Recover a previously downloaded input only after full validation.
                    # Invalid partials remain untouched, with the validation error reported.
                    reused_partial = part.exists()
                    if not reused_partial:
                        with urllib.request.urlopen(url, timeout=25) as response, part.open("xb") as output:
                            while True:
                                block = response.read(1024 * 1024)
                                if not block:
                                    break
                                output.write(block)
                    row.update(validate_file(part, kind))
                    if old.get("sha256") and old["sha256"] != digest(part):
                        raise ValueError("Partial file hash differs from acquisition lock")
                    part.rename(path)
                    row["recovered_from_partial"] = reused_partial
                else:
                    row.update(validate_file(path, kind))
                sha = digest(path)
                if old.get("sha256") and old["sha256"] != sha:
                    raise ValueError("File hash differs from acquisition lock")
                row.update(status="acquired", sha256=sha, size=path.stat().st_size,
                           publisher_checksum_verified=False, extracted=old.get("extracted", False))
        except (OSError, ValueError, RuntimeError, subprocess.TimeoutExpired, tarfile.TarError, EOFError) as error:
            # Preserve a previous good lock even on later failure.
            row.update({key: old[key] for key in ("sha256", "commit") if key in old})
            row.update(status="failed", error=str(error))
        rows.append(row)
        print(f"{source_id}: {row['status']}", flush=True)
        MANIFEST.parent.mkdir(parents=True, exist_ok=True)
        # Keep unattempted rows explicitly marked, with any prior lock preserved.
        pending = [{**locked.get(sid, {}), "id": sid, "status": "not_attempted_this_run"}
                   for sid, *_ in SOURCES[len(rows):]]
        MANIFEST.write_text(json.dumps({"schema": 1, "sources": rows + pending}, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    return 1 if any(row["status"] != "acquired" for row in rows) else 0


if __name__ == "__main__":
    sys.exit(main())
