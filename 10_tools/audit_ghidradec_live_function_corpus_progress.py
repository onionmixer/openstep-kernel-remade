"""Validate current live-callback GhidraDec corpus progress without trusting metadata alone."""

import hashlib
import fcntl
import json
from collections import Counter
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / "09_validation/reports/multiarch-input-20260921/ghidradec-live-callback-corpus-progress-20260922.json"
NATIVE_MESSAGE = "//Decompiler native message:"
ARCHES = ("m68k", "sparc")


def sha256(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def completed_live_slice(status):
    """Accept both recorded live-slice schemas without weakening their success conditions."""
    if "execution_completed" in status:
        return status["execution_completed"] is True
    return (status.get("passed_content_validity") is True and
            status.get("failure_reason") is None and
            status.get("return_code") == 0 and
            status.get("timeout") is False)


def live_slice_failure(status):
    if "fatal_failure_reason" in status:
        return status["fatal_failure_reason"]
    return status.get("failure_reason")


def audit_architecture_locked(arch):
    candidate_path = ROOT / "05_ida/exports" / arch / "function-asm-index.json"
    candidates = json.loads(candidate_path.read_text(encoding="utf-8"))
    candidates_by_start = {item["start"].lower(): item for item in candidates}
    root = ROOT / "05_ida/exports" / arch / "ghidradec-functions-live-callback-20260922"
    original = ROOT / "03_original" / arch / "binaries/mach_kernel"
    database = ROOT / "05_ida/databases" / (arch + "-os42j.i64")
    original_hash = sha256(original)
    database_hash = sha256(database)
    records = []
    for record_path in sorted((root / "function-records").glob("*.json")):
        record = json.loads(record_path.read_text(encoding="utf-8"))
        start = record["start_ea"].lower()
        assert start in candidates_by_start
        assert record["end_ea"].lower() == candidates_by_start[start]["end"].lower()
        slice_name = record["slice"]
        slice_path = root / "slices" / (slice_name + ".json")
        assert slice_path.is_file()
        slice_status = json.loads(slice_path.read_text(encoding="utf-8"))
        assert completed_live_slice(slice_status)
        assert start in [value.lower() for value in slice_status["expected_candidate_starts"]]
        assert slice_status["canonical_database_sha256_recomputed_with_python"] == database_hash
        assert slice_status["original_binary_sha256_recomputed_with_python"] == original_hash
        assert str(record_path.relative_to(root)) in slice_status["persistent_records"]
        c_path = root / record["c_output"]
        assert c_path.is_file() and sha256(c_path) == record["c_output_sha256"]
        text = c_path.read_text(encoding="utf-8", errors="replace")
        native = text.lstrip().startswith(NATIVE_MESSAGE)
        valid = record["status"] == "success" and not native
        records.append((start, valid, native, record["status"]))
    starts = [item[0] for item in records]
    assert len(starts) == len(set(starts))
    valid_count = sum(item[1] for item in records)
    error_count = len(records) - valid_count
    native_error_count = sum(item[2] for item in records)
    status_counts = Counter(item[3] for item in records)
    fatal_single_candidates = {}
    for status_path in sorted((root / "slices").glob("slice-*.json")):
        status = json.loads(status_path.read_text(encoding="utf-8"))
        starts_in_slice = status.get("expected_candidate_starts", [])
        failure_reason = live_slice_failure(status)
        if (not completed_live_slice(status) and len(starts_in_slice) == 1 and
                failure_reason is not None):
            start = starts_in_slice[0].lower()
            candidate = candidates_by_start[start]
            fatal_single_candidates[start] = {
                "name": candidate["name"],
                "fatal_failure_reason": failure_reason,
                "return_code": status.get("return_code"),
                "slice_status": str(status_path.relative_to(ROOT)),
            }
    return {
        "candidate_count": len(candidates),
        "candidate_index_sha256_recomputed_with_python": sha256(candidate_path),
        "original_binary_sha256_recomputed_with_python": original_hash,
        "canonical_database_sha256_recomputed_with_python": database_hash,
        "persisted_candidate_record_count": len(records),
        "valid_c_hypothesis_count": valid_count,
        "error_output_count": error_count,
        "native_message_error_count": native_error_count,
        "record_status_counts": dict(sorted(status_counts.items())),
        "single_candidate_fatal_plugin_failures": dict(sorted(fatal_single_candidates.items())),
        "valid_c_hypothesis_coverage_percent_recomputed_with_python": (valid_count * 100.0) / len(candidates),
        "persistent_record_coverage_percent_recomputed_with_python": (len(records) * 100.0) / len(candidates),
        "all_persisted_records_have_unique_candidate_starts_matching_c_hashes_and_live_slice_provenance": True,
    }


def audit_architecture(arch):
    """Read one corpus only after its runner's exclusive lock has been released."""
    root = ROOT / "05_ida/exports" / arch / "ghidradec-functions-live-callback-20260922"
    lock_path = root / ".runner.lock"
    with lock_path.open("a", encoding="utf-8") as lock_stream:
        fcntl.flock(lock_stream.fileno(), fcntl.LOCK_SH)
        return audit_architecture_locked(arch)


def main():
    architectures = {arch: audit_architecture(arch) for arch in ARCHES}
    result = {
        "schema": 1,
        "scope": "current live-callback GhidraDec corpus progress; C remains a decompiler hypothesis",
        "architectures": architectures,
        "interpretation_limit": (
            "This validates files, selected candidate membership, hashes, and native-message classification only. "
            "Valid C does not establish original function boundaries, code/data truth, reachability, ABI, or behavior."
        ),
    }
    REPORT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({
        "output": str(REPORT.relative_to(ROOT)),
        "valid_c_hypothesis_counts": {arch: architectures[arch]["valid_c_hypothesis_count"] for arch in ARCHES},
        "error_output_counts": {arch: architectures[arch]["error_output_count"] for arch in ARCHES},
        "valid_c_hypothesis_coverage_percents": {
            arch: architectures[arch]["valid_c_hypothesis_coverage_percent_recomputed_with_python"]
            for arch in ARCHES
        },
        "persistent_record_coverage_percents": {
            arch: architectures[arch]["persistent_record_coverage_percent_recomputed_with_python"]
            for arch in ARCHES
        },
    }, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
