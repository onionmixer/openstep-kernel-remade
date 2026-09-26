"""Independently audit coverage and raw provenance of the contract ledger."""
import csv
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT_DIR = ROOT / "09_validation/reports/multiarch-input-20260921"
LEDGER = REPORT_DIR / "binary-only-contract-evidence-ledger-20260923.json"
OUTPUT = REPORT_DIR / "binary-only-contract-evidence-completion-audit-20260923.json"
ENDIANNESS = {"x86": "little", "m68k": "big", "sparc": "big"}


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def read_tsv(path):
    with path.open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream, delimiter="\t"))


def source_functions(arch):
    if arch == "x86":
        return json.loads((ROOT / "04_ghidra/exports/x86/full-pass5/functions.json").read_text(encoding="utf-8"))
    return json.loads((ROOT / "05_ida/exports" / arch / "function-asm-index.json").read_text(encoding="utf-8"))


def source_code_item_count(arch, text_start, text_size):
    if arch == "x86":
        rows = read_tsv(ROOT / "04_ghidra/exports/x86/full-pass5/code-units.tsv")
        return sum(row["kind"] == "instruction" and text_start <= int(row["start"], 16) < text_start + text_size for row in rows)
    rows = read_tsv(ROOT / "05_ida/exports" / arch / "text-units.tsv")
    return sum(row["kind"] == "code" for row in rows)


def source_direct_call_count_and_byte_check(arch, raw, text_start, text_offset, text_size):
    if arch == "x86":
        count = 0
        for row in read_tsv(ROOT / "04_ghidra/exports/x86/full-pass5/code-units.tsv"):
            if row["kind"] != "instruction" or int(row["length"]) != 5:
                continue
            address = int(row["start"], 16)
            if not text_start <= address < text_start + text_size:
                continue
            position = text_offset + address - text_start
            count += raw[position:position + 1] == b"\xe8"
        return count, True
    rows = read_tsv(ROOT / "05_ida/exports" / arch / "direct-call-edges.tsv")
    checks = []
    for row in rows:
        source = int(row["source"], 16)
        encoded = bytes.fromhex(row["instruction_bytes"])
        position = text_offset + source - text_start
        checks.append(raw[position:position + len(encoded)] == encoded)
    return len(rows), all(checks)


def raw_objc_sections(raw, inventory, arch):
    result = []
    for section in inventory["sections"]:
        if section["segment"] != "__OBJC":
            continue
        size, offset = section["size"], section["file_offset"]
        payload = raw[offset:offset + size] if size else b""
        if len(payload) != size:
            raise RuntimeError("__OBJC payload outside original: {} {}".format(arch, section["name"]))
        result.append(("__OBJC," + section["name"], size // 4, size % 4, sha256(payload)))
    return result


def main():
    ledger = json.loads(LEDGER.read_text(encoding="utf-8"))
    result = {
        "schema": 1,
        "scope": "independent coverage/provenance audit for original-binary-only contract evidence ledger",
        "ledger_sha256_recomputed_with_python": sha256(LEDGER.read_bytes()),
        "architectures": {},
        "semantic_disposition": {
            "calling_convention_confirmed": False,
            "argument_locations_or_values_confirmed": False,
            "return_value_locations_or_values_confirmed": False,
            "structure_or_object_field_layout_confirmed": False,
            "reason": (
                "The permitted evidence establishes only original bytes, current listing labels, and static address/layout "
                "relations. It does not provide a proof rule for runtime path execution, operand roles, type identity, "
                "or an external ABI/runtime schema."
            ),
        },
    }
    all_checks = True
    for arch, expected_endian in ENDIANNESS.items():
        raw = (ROOT / "03_original" / arch / "binaries/mach_kernel").read_bytes()
        inventory = json.loads((ROOT / "03_original" / arch / "inventory/macho.json").read_text(encoding="utf-8"))
        text = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
        text_start, text_offset, text_size = int(text["address"], 16), int(text["file_offset"]), text["size"]
        data = ledger["architectures"][arch]
        functions = source_functions(arch)
        source_starts = sorted(int(row["address" if arch == "x86" else "start"], 16) for row in functions)
        ledger_starts = sorted(int(row["candidate_start"], 16) for row in data["function_contract_evidence_records"])
        source_code_count = source_code_item_count(arch, text_start, text_size)
        direct_count, direct_bytes_ok = source_direct_call_count_and_byte_check(arch, raw, text_start, text_offset, text_size)
        source_objc = raw_objc_sections(raw, inventory, arch)
        ledger_objc = [
            (row["section"], row["raw_word_count_recomputed_with_python"], row["raw_word_alignment_remainder_recomputed_with_python"], row["section_original_bytes_sha256_recomputed_with_python"])
            for row in data["raw_objc_word_layout"]
        ]
        checks = {
            "endianness_matches_architecture_rule": data["architecture_endianness"] == expected_endian,
            "original_binary_sha256_matches": data["original_binary_sha256_recomputed_with_python"] == sha256(raw),
            "source_function_start_set_matches_ledger": source_starts == ledger_starts,
            "source_function_count_matches_ledger": len(functions) == data["current_function_or_analysis_fragment_count_recomputed_with_python"],
            "source_code_item_count_matches_ledger": source_code_count == data["current_code_item_count_recomputed_with_python"],
            "direct_call_count_matches_ledger": direct_count == data["direct_call_edge_count_recomputed_with_python"],
            "direct_call_instruction_bytes_match_original": direct_bytes_ok,
            "raw_objc_section_word_and_payload_hash_rows_match": source_objc == ledger_objc,
            "all_function_records_report_original_code_byte_match": all(row["all_current_code_item_bytes_match_original"] for row in data["function_contract_evidence_records"]),
            "ledger_architecture_original_code_byte_check_passes": data["all_current_code_item_bytes_match_original"],
        }
        all_checks = all_checks and all(checks.values())
        result["architectures"][arch] = {
            "architecture_endianness": expected_endian,
            "source_function_or_analysis_fragment_count_recomputed_with_python": len(functions),
            "source_code_item_count_recomputed_with_python": source_code_count,
            "source_direct_call_count_recomputed_with_python": direct_count,
            "source_raw_objc_section_count_recomputed_with_python": len(source_objc),
            "checks": checks,
        }
    result["raw_evidence_acquisition_complete"] = all_checks
    result["interpretation_limit"] = (
        "Passing this audit completes coverage and original-byte provenance for the evidence ledger only. "
        "The explicit false semantic dispositions are preserved results, not failed audit checks."
    )
    OUTPUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if not all_checks:
        raise SystemExit("contract evidence completion audit failed")
    print(json.dumps({
        "output": str(OUTPUT.relative_to(ROOT)),
        "raw_evidence_acquisition_complete": all_checks,
        "semantic_disposition": result["semantic_disposition"],
    }, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
