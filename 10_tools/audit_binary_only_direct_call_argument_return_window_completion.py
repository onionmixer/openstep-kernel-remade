"""Check direct-call argument/return window census coverage against the ledger."""
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT_DIR = ROOT / "09_validation/reports/multiarch-input-20260921"
WINDOWS = REPORT_DIR / "binary-only-direct-call-argument-return-window-audit-20260923.json"
LEDGER = REPORT_DIR / "binary-only-contract-evidence-ledger-20260923.json"
OUTPUT = REPORT_DIR / "binary-only-direct-call-argument-return-window-completion-audit-20260923.json"


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def main():
    windows = json.loads(WINDOWS.read_text(encoding="utf-8"))
    ledger = json.loads(LEDGER.read_text(encoding="utf-8"))
    result = {
        "schema": 1,
        "scope": "coverage and integrity audit for every original-byte direct-call pre/post-window record",
        "window_audit_sha256_recomputed_with_python": sha256(WINDOWS.read_bytes()),
        "ledger_sha256_recomputed_with_python": sha256(LEDGER.read_bytes()),
        "architectures": {},
    }
    all_checks = True
    for arch in ("x86", "m68k", "sparc"):
        data = windows["architectures"][arch]
        records = data["records"]
        source_set = {(row["source"], row["target"], row["direct_call_original_bytes"]) for row in records}
        checks = {
            "original_binary_hash_matches_contract_ledger": data["original_binary_sha256_recomputed_with_python"] == ledger["architectures"][arch]["original_binary_sha256_recomputed_with_python"],
            "record_count_matches_contract_ledger_direct_call_count": len(records) == ledger["architectures"][arch]["direct_call_edge_count_recomputed_with_python"],
            "source_target_instruction_record_count_has_no_duplicates": len(source_set) == len(records),
            "all_records_report_original_source_and_window_byte_match": all(row["source_and_window_items_match_original"] for row in records),
            "all_preceding_window_counts_within_declared_limit": all(row["preceding_window_item_count_recomputed_with_python"] <= windows["window_definition"]["preceding_current_text_item_limit"] for row in records),
            "all_following_window_counts_within_declared_limit": all(row["following_window_item_count_recomputed_with_python"] <= windows["window_definition"]["following_current_text_item_limit"] for row in records),
            "all_window_hashes_are_sha256_hex": all(
                len(row["preceding_window_original_bytes_sha256_recomputed_with_python"]) == 64 and
                len(row["following_window_original_bytes_sha256_recomputed_with_python"]) == 64
                for row in records
            ),
        }
        all_checks = all_checks and all(checks.values())
        result["architectures"][arch] = {
            "direct_call_record_count_recomputed_with_python": len(records),
            "checks": checks,
        }
    result["runtime_argument_value_confirmed"] = windows["runtime_argument_value_confirmed"]
    result["runtime_return_value_confirmed"] = windows["runtime_return_value_confirmed"]
    result["all_direct_call_window_coverage_and_integrity_checks_pass"] = all_checks
    result["interpretation_limit"] = (
        "This audit establishes record coverage and byte provenance only. False runtime-value flags are preserved "
        "semantic dispositions, not failed coverage checks."
    )
    OUTPUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if not all_checks:
        raise SystemExit("direct-call window completion audit failed")
    print(json.dumps({
        "output": str(OUTPUT.relative_to(ROOT)),
        "all_direct_call_window_coverage_and_integrity_checks_pass": all_checks,
        "runtime_argument_value_confirmed": result["runtime_argument_value_confirmed"],
        "runtime_return_value_confirmed": result["runtime_return_value_confirmed"],
    }, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
