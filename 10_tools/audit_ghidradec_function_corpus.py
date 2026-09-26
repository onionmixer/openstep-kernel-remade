"""Verify per-candidate GhidraDec corpus records without treating C as evidence."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ARCHES = ("m68k", "sparc")


def sha256(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def main():
    result = {"schema": 1, "scope": "GhidraDec corpus bookkeeping; C remains a hypothesis", "architectures": {}}
    for arch in ARCHES:
        root = ROOT / "05_ida/exports" / arch / "ghidradec-functions"
        summary = json.loads((root / "summary.json").read_text(encoding="utf-8"))
        candidates = json.loads((ROOT / "05_ida/exports" / arch / "function-asm-index.json").read_text(encoding="utf-8"))
        records = [json.loads(line) for line in (root / "records.jsonl").read_text(encoding="utf-8").splitlines()]
        if len(records) != len(candidates):
            raise RuntimeError(arch + " record count mismatch")
        if {row["start_ea"] for row in records} != {row["start"].lower() for row in candidates}:
            raise RuntimeError(arch + " record start set mismatch")
        for row in records:
            if row["status"] in {"success", "plugin_error_output"}:
                path = root / row["c_output"]
                if not path.is_file() or path.stat().st_size == 0 or sha256(path) != row["c_output_sha256"]:
                    raise RuntimeError(arch + " C output verification failed at " + row["start_ea"])
        counts = {status: sum(1 for row in records if row["status"] == status)
                  for status in sorted({row["status"] for row in records})}
        if counts != summary["status_counts"]:
            raise RuntimeError(arch + " status count mismatch")
        result["architectures"][arch] = {"candidate_count": len(candidates), "status_counts": counts,
                                         "all_c_outputs_nonempty_and_hashed": True,
                                         "all_candidate_starts_accounted": True,
                                         "big_endian_required": summary["big_endian_required"]}
    output = ROOT / "09_validation/reports/multiarch-input-20260921/ghidradec-function-corpus-audit-20260922.json"
    output.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
