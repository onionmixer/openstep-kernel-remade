"""Verify that every live-callback decompiler failure has an assembly corpus entry.

This is deliberately a provenance and byte-listing linkage audit.  It does not
interpret assembly as behavior, ABI, or a corrected decompilation.
"""
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
PROGRESS = ROOT / "09_validation/reports/multiarch-input-20260921/ghidradec-live-callback-corpus-progress-20260922.json"
OUTPUT = ROOT / "09_validation/reports/multiarch-input-20260921/ghidradec-live-callback-failure-asm-coverage-20260923.json"
ARCHES = ("m68k", "sparc")


def sha256(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def parse_error_address(text):
    for line in text.splitlines():
        marker = " @ 0x"
        if marker in line:
            return int(line.rsplit(marker, 1)[1], 16)
    raise ValueError("error output has no function address")


def main():
    progress = json.loads(PROGRESS.read_text())
    result = {"schema": 1, "scope": "live-callback decompiler error/fatal output to existing original-byte-validated assembly corpus linkage; no behavioral interpretation"}
    all_complete = True
    for arch in ARCHES:
        arch_root = ROOT / "05_ida/exports" / arch
        index_path = arch_root / "function-asm-index.json"
        summary_path = arch_root / "function-asm-summary.json"
        asm_index = json.loads(index_path.read_text())
        starts = {int(item["start"], 16): item for item in asm_index}
        failures = []
        error_dir = arch_root / "ghidradec-functions-live-callback-20260922/error-outputs"
        for error_path in sorted(error_dir.glob("*.c")):
            text = error_path.read_text(errors="replace")
            address = parse_error_address(text)
            failures.append({"kind": "decompiler_error_output", "address": address, "source": str(error_path.relative_to(ROOT)), "message_sha256": sha256(error_path)})
        for address_text, detail in progress["architectures"][arch]["single_candidate_fatal_plugin_failures"].items():
            failures.append({"kind": "fresh_copied_db_fatal_plugin_failure", "address": int(address_text, 16), "source": detail["slice_status"], "name": detail["name"], "return_code": detail["return_code"]})
        linked = []
        for failure in sorted(failures, key=lambda item: (item["address"], item["kind"])):
            candidate = starts.get(failure["address"])
            row = dict(failure)
            row["assembly_index_entry_present"] = candidate is not None
            if candidate is not None:
                asm_path = arch_root / candidate["asm"]
                row["assembly_path"] = str(asm_path.relative_to(ROOT))
                row["assembly_file_present"] = asm_path.is_file()
                if asm_path.is_file():
                    first = asm_path.read_text().splitlines()[0]
                    row["assembly_first_item_address"] = int(first.split(":", 1)[0], 16)
                    row["assembly_start_matches_failure"] = row["assembly_first_item_address"] == failure["address"]
                else:
                    row["assembly_start_matches_failure"] = False
            else:
                row["assembly_file_present"] = False
                row["assembly_start_matches_failure"] = False
            linked.append(row)
        complete = all(item["assembly_index_entry_present"] and item["assembly_file_present"] and item["assembly_start_matches_failure"] for item in linked)
        all_complete = all_complete and complete
        result[arch] = {
            "function_assembly_index_sha256_recomputed_with_python": sha256(index_path),
            "function_assembly_summary_sha256_recomputed_with_python": sha256(summary_path),
            "failure_count_recomputed_with_python": len(linked),
            "decompiler_error_output_count_recomputed_with_python": sum(item["kind"] == "decompiler_error_output" for item in linked),
            "fatal_plugin_failure_count_recomputed_with_python": sum(item["kind"] == "fresh_copied_db_fatal_plugin_failure" for item in linked),
            "all_failure_addresses_have_matching_assembly_corpus_start": complete,
            "failures": linked,
        }
    result["all_architectures_complete"] = all_complete
    OUTPUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n")
    if not all_complete:
        raise SystemExit("assembly linkage audit failed")
    print(json.dumps({"output": str(OUTPUT.relative_to(ROOT)), "all_architectures_complete": all_complete}, sort_keys=True))


if __name__ == "__main__":
    main()
