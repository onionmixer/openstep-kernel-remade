"""Audit whether the address-selected GhidraDec corpus contains C, not just files.

The previous bookkeeping audit deliberately checked address selection and file
integrity.  This separate audit checks the emitted text for the native address
space failure observed in the preloaded, non-live callback batch path.
"""

import hashlib
import json
from collections import Counter
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT_DIR = ROOT / "09_validation/reports/multiarch-input-20260921"
CORPUS_NAME = "ghidradec-functions-explicit-holes-20260922"
NATIVE_ADDRESS_FAILURE = "//Decompiler native message:  Low-level Error: Bad decompile address:"
ARCHES = ("m68k", "sparc")


def sha256(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def classify(text):
    stripped = text.lstrip()
    if stripped.startswith(NATIVE_ADDRESS_FAILURE):
        return "native_address_space_failure"
    if stripped.startswith("//Decompiler native message:"):
        return "other_native_message"
    if not text.strip():
        return "empty"
    return "non_native_text"


def audit_architecture(arch):
    root = ROOT / "05_ida/exports" / arch / CORPUS_NAME
    summary_path = root / "summary.json"
    records_path = root / "records.jsonl"
    summary = json.loads(summary_path.read_text(encoding="utf-8"))
    records = [json.loads(line) for line in records_path.read_text(encoding="utf-8").splitlines() if line]
    assert len(records) == summary["candidate_count"]
    counts = Counter()
    sizes = Counter()
    status_cross_tab = Counter()
    for record in records:
        output = root / record["c_output"]
        assert output.is_file()
        assert sha256(output) == record["c_output_sha256"]
        text = output.read_text(encoding="utf-8", errors="replace")
        category = classify(text)
        counts[category] += 1
        sizes[category] += output.stat().st_size
        status_cross_tab[(record["status"], category)] += 1
    assert counts["native_address_space_failure"] == summary["candidate_count"]
    assert counts["non_native_text"] == 0
    return {
        "candidate_count": summary["candidate_count"],
        "summary_sha256_recomputed_with_python": sha256(summary_path),
        "records_sha256_recomputed_with_python": sha256(records_path),
        "content_category_counts": dict(sorted(counts.items())),
        "content_category_byte_totals_recomputed_with_python": dict(sorted(sizes.items())),
        "record_status_by_content_category": {
            status + "|" + category: count
            for (status, category), count in sorted(status_cross_tab.items())
        },
        "valid_c_hypothesis_count": counts["non_native_text"],
        "all_outputs_are_the_same_native_address_space_failure": True,
    }


def main():
    architectures = {arch: audit_architecture(arch) for arch in ARCHES}
    output = {
        "schema": 1,
        "scope": "content validity of the historical address-selected GhidraDec corpus",
        "architectures": architectures,
        "all_architectures_have_zero_valid_c_hypotheses": all(
            item["valid_c_hypothesis_count"] == 0 for item in architectures.values()),
        "required_disposition": (
            "Quarantine this corpus from semantic, ABI, boundary, or behavior analysis. "
            "Its successful bookkeeping status means only that an address-selected file was emitted; "
            "it does not mean the file contains a decompilation result."
        ),
        "replacement_requirement": (
            "A replacement corpus must use a separately validated callback path and classify native messages "
            "as errors before any C text is admitted as a decompiler hypothesis."
        ),
    }
    destination = REPORT_DIR / "ghidradec-explicit-corpus-content-validity-20260922.json"
    destination.write_text(json.dumps(output, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({
        "output": str(destination.relative_to(ROOT)),
        "candidate_counts": {arch: architectures[arch]["candidate_count"] for arch in ARCHES},
        "valid_c_hypothesis_counts": {arch: architectures[arch]["valid_c_hypothesis_count"] for arch in ARCHES},
        "all_checks_passed": True,
    }, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
