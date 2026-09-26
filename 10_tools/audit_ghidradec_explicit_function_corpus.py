"""Independently verify the address-selected GhidraDec C corpora.

This verifier deliberately treats every generated C file as a decompiler
hypothesis.  It checks bookkeeping, byte hashes, and exact selected-address
marker coverage; it does not infer kernel behavior from C text.
"""
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ARCHES = {
    "m68k": "ghidradec-functions-explicit-holes-20260922",
    "sparc": "ghidradec-functions-explicit-holes-20260922",
}
REPORT = ROOT / "09_validation/reports/multiarch-input-20260921/ghidradec-explicit-function-corpus-audit-20260922.json"


def sha256(path):
    digest = hashlib.sha256()
    with Path(path).open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def require(condition, message):
    if not condition:
        raise RuntimeError(message)


def main():
    result = {
        "schema": 1,
        "scope": "address-selected GhidraDec corpus bookkeeping; generated C remains a decompiler hypothesis",
        "architectures": {},
    }
    for arch, corpus_name in ARCHES.items():
        export_root = ROOT / "05_ida/exports" / arch
        corpus = export_root / corpus_name
        candidates = json.loads((export_root / "function-asm-index.json").read_text(encoding="utf-8"))
        summary = json.loads((corpus / "summary.json").read_text(encoding="utf-8"))
        records = [json.loads(line) for line in (corpus / "records.jsonl").read_text(encoding="utf-8").splitlines()]
        require(len(records) == len(candidates), arch + " record count mismatch")
        require(summary["candidate_count"] == len(candidates), arch + " summary candidate count mismatch")
        require(summary["big_endian_required"] is True, arch + " endian requirement is absent")
        expected_by_start = {row["start"].lower(): row for row in candidates}
        require(len(expected_by_start) == len(candidates), arch + " candidate starts are not unique")
        require({row["start_ea"] for row in records} == set(expected_by_start), arch + " record starts mismatch")
        require(all(row["status"] == "success" for row in records), arch + " has non-success output")
        for row in records:
            expected = expected_by_start[row["start_ea"]]
            require(row["candidate_index"] == candidates.index(expected), arch + " candidate index mismatch at " + row["start_ea"])
            require(row["end_ea"] == expected["end"] and row["size_bytes"] == expected["size"] and row["name"] == expected["name"],
                    arch + " candidate metadata mismatch at " + row["start_ea"])
            output = corpus / row["c_output"]
            require(output.is_file() and output.stat().st_size > 0, arch + " missing or empty C at " + row["start_ea"])
            require(sha256(output) == row["c_output_sha256"], arch + " C SHA-256 mismatch at " + row["start_ea"])
        slices = []
        for path in sorted((corpus / "slices").glob("slice-*.json")):
            row = json.loads(path.read_text(encoding="utf-8"))
            start = row["slice_start_index"]
            end = row["slice_end_index_exclusive"]
            expected_starts = [candidate["start"].lower() for candidate in candidates[start:end]]
            require(row["completed"] is True and row["return_code"] == 0 and row["timeout"] is False,
                    arch + " incomplete slice: " + path.name)
            require(row["expected_candidate_starts"] == expected_starts, arch + " selected-start evidence mismatch: " + path.name)
            require(row["plugin_marker_starts"] == expected_starts, arch + " marker order mismatch: " + path.name)
            require(row["plugin_marker_count"] == len(expected_starts), arch + " marker count mismatch: " + path.name)
            slices.append((start, end))
        covered = {index for start, end in slices for index in range(start, end)}
        require(covered == set(range(len(candidates))), arch + " slice coverage mismatch")
        result["architectures"][arch] = {
            "big_endian_required": True,
            "candidate_count": len(candidates),
            "success_count": len(records),
            "nonempty_c_outputs": len(records),
            "slice_count": len(slices),
            "corpus": str(corpus.relative_to(ROOT)),
            "global_plugin_sha256": summary["global_plugin_sha256"],
            "all_candidate_starts_accounted": True,
            "all_slice_markers_match_exact_requested_addresses": True,
            "all_c_outputs_nonempty_and_hashed": True,
        }
    REPORT.parent.mkdir(parents=True, exist_ok=True)
    REPORT.write_text(json.dumps(result, ensure_ascii=False, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    print(json.dumps(result, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
