"""Independently verify persisted one-function GhidraDec error-output retries."""
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORTS = ROOT / "09_validation/reports/multiarch-input-20260921"
FAILURES = REPORTS / "ghidradec-live-callback-failure-asm-coverage-20260923.json"
RETRIES = REPORTS / "ghidradec-error-output-retry-20260923.json"
OUTPUT = REPORTS / "ghidradec-error-output-retry-integrity-audit-20260923.json"
ARCHES = ("m68k", "sparc")
NATIVE_PREFIXES = ("//Decompiler native message:", "//Error decompiling function:")


def sha256(path):
    digest = hashlib.sha256()
    with Path(path).open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def main():
    failures = json.loads(FAILURES.read_text(encoding="utf-8"))
    retries = json.loads(RETRIES.read_text(encoding="utf-8"))
    result = {
        "schema": 1,
        "scope": "independent persistence and provenance audit for one-function fresh-copied-big-endian GhidraDec retries of prior C-error outputs; no original-behavior conclusion",
        "architectures": {},
    }
    all_ok = True
    for arch in ARCHES:
        expected = sorted(row["address"] for row in failures[arch]["failures"] if row["kind"] == "decompiler_error_output")
        attempts = retries["architectures"][arch]["attempts"]
        actual = sorted(row["address"] for row in attempts)
        raw_hash = sha256(ROOT / "03_original" / arch / "binaries/mach_kernel")
        db_hash = sha256(ROOT / "05_ida/databases" / (arch + "-os42j.i64"))
        retry_root = ROOT / "05_ida/exports" / arch / "ghidradec-functions-live-callback-retry-20260923"
        rows = []
        for attempt in attempts:
            status_path = ROOT / attempt["slice_status_path"]
            checks = {
                "status_file_present": status_path.is_file(),
                "requested_address_is_expected": attempt["address"] in expected,
            }
            if status_path.is_file():
                status = json.loads(status_path.read_text(encoding="utf-8"))
                checks.update({
                    "status_architecture_matches": status["architecture"] == arch,
                    "status_single_requested_address_matches": status["expected_candidate_starts"] == [attempt["address_hex"]],
                    "status_completed_without_timeout": status["execution_completed"] and not status["timeout"],
                    "status_normal_ida_exit": status["return_code"] == 0 and status["fatal_failure_reason"] is None,
                    "status_original_hash_matches_current_original": status["original_binary_sha256_recomputed_with_python"] == raw_hash,
                    "status_canonical_db_hash_matches_current_canonical": status["canonical_database_sha256_recomputed_with_python"] == db_hash,
                    "status_has_exactly_one_error_output_for_address": len(status["decompiler_error_outputs"]) == 1 and status["decompiler_error_outputs"][0]["start_ea"].lower() == attempt["address_hex"],
                    "status_has_exactly_one_persistent_record": len(status["persistent_records"]) == 1,
                })
                if checks["status_has_exactly_one_persistent_record"]:
                    record_path = retry_root / status["persistent_records"][0]
                    checks["persistent_record_present"] = record_path.is_file()
                    if record_path.is_file():
                        record = json.loads(record_path.read_text(encoding="utf-8"))
                        c_path = retry_root / record["c_output"]
                        checks.update({
                            "record_address_matches": record["start_ea"].lower() == attempt["address_hex"],
                            "record_is_plugin_error_output": record["content_validity"] == "plugin_error_output",
                            "record_c_file_present": c_path.is_file(),
                        })
                        if c_path.is_file():
                            text = c_path.read_text(encoding="utf-8", errors="replace").lstrip()
                            checks.update({
                                "record_c_hash_matches": sha256(c_path) == record["c_output_sha256"],
                                "record_c_is_native_error_text": text.startswith(NATIVE_PREFIXES),
                            })
            rows.append({"address": attempt["address_hex"], "checks": checks, "all_checks_pass": all(checks.values())})
        address_set_matches = expected == actual and len(actual) == len(set(actual))
        complete = address_set_matches and all(row["all_checks_pass"] for row in rows)
        all_ok = all_ok and complete
        result["architectures"][arch] = {
            "architecture_endianness": "big",
            "expected_prior_c_error_count_recomputed_with_python": len(expected),
            "persisted_retry_count_recomputed_with_python": len(actual),
            "retry_addresses_match_prior_c_errors_once": address_set_matches,
            "all_retry_provenance_and_output_checks_pass": complete,
            "rows": rows,
        }
    result["all_architectures_pass"] = all_ok
    OUTPUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if not all_ok:
        raise SystemExit("GhidraDec retry persistence audit failed")
    print(json.dumps({"output": str(OUTPUT.relative_to(ROOT)), "all_architectures_pass": all_ok}, sort_keys=True))


if __name__ == "__main__":
    main()
