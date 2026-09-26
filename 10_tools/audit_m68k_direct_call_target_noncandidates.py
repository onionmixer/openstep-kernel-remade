"""Audit m68k direct-call targets that are not IDA function-candidate starts.

This is a bounded raw-byte review only.  It does not modify the IDA database or
infer missing function boundaries.
"""
import csv
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ARCH = "m68k"
REPORT = ROOT / "09_validation/reports/multiarch-input-20260921"


def load_tsv(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def hex_address(value):
    return f"0x{value:x}"


def main():
    binary_path = ROOT / "03_original" / ARCH / "binaries/mach_kernel"
    binary = binary_path.read_bytes()
    original_sha256 = hashlib.sha256(binary).hexdigest()
    macho = json.loads((ROOT / "03_original" / ARCH / "inventory/macho.json").read_text(encoding="utf-8"))
    text = next(section for section in macho["sections"] if section["segment"] == "__TEXT" and section["name"] == "__text")
    text_address = int(text["address"], 16)
    text_file_offset = int(text["file_offset"])
    text_size = int(text["size"])
    text_end = text_address + text_size

    edges = load_tsv(ROOT / "05_ida/exports" / ARCH / "direct-call-edges.tsv")
    functions = json.loads((ROOT / "05_ida/exports" / ARCH / "function-asm-index.json").read_text(encoding="utf-8"))
    function_starts = {int(row["start"], 16) for row in functions}
    text_units = load_tsv(ROOT / "05_ida/exports" / ARCH / "text-units.tsv")
    units_by_address = {int(row["address"], 16): row for row in text_units}
    symbols = load_tsv(ROOT / "03_original" / ARCH / "inventory/symbols.tsv")
    symbols_by_value = {}
    for row in symbols:
        symbols_by_value.setdefault(int(row["value"], 16), []).append(row)

    unmatched = [row for row in edges if int(row["target"], 16) not in function_starts]
    rows = []
    for edge in unmatched:
        source = int(edge["source"], 16)
        target = int(edge["target"], 16)
        assert text_address <= source < text_end
        assert text_address <= target < text_end
        source_unit = units_by_address[source]
        target_unit = units_by_address[target]
        assert source_unit["kind"] == "code"
        assert target_unit["kind"] == "code"
        source_offset = text_file_offset + (source - text_address)
        target_offset = text_file_offset + (target - text_address)
        source_bytes = binary[source_offset:source_offset + int(source_unit["length"])]
        target_bytes = binary[target_offset:target_offset + int(target_unit["length"])]
        assert source_bytes.hex() == source_unit["bytes"]
        assert target_bytes.hex() == target_unit["bytes"]
        containing_candidates = [
            {"start": row["start"], "end": row["end"], "name": row["name"]}
            for row in functions
            if int(row["start"], 16) <= target < int(row["end"], 16)
        ]
        rows.append({
            "source": hex_address(source),
            "target": hex_address(target),
            "edge_kind": edge["edge_kind"],
            "source_file_offset": source_offset,
            "source_original_bytes": source_bytes.hex(),
            "source_text_unit_disassembly": source_unit["disassembly"],
            "target_file_offset": target_offset,
            "target_original_bytes": target_bytes.hex(),
            "target_text_unit_disassembly": target_unit["disassembly"],
            "raw_symbol_names_at_target": [row["name"] for row in symbols_by_value.get(target, [])],
            "ida_candidate_ranges_containing_target": containing_candidates,
        })
    assert len(unmatched) == 5
    assert len(rows) == 5
    report = {
        "schema": 1,
        "architecture": ARCH,
        "original_sha256_recomputed_with_python": original_sha256,
        "original_text_mapping": {
            "address": hex_address(text_address),
            "end_exclusive": hex_address(text_end),
            "file_offset": text_file_offset,
            "size": text_size,
        },
        "direct_call_target_not_ida_candidate_start_count": len(rows),
        "rows": rows,
        "all_source_and_target_text_units_match_original_bytes": True,
        "interpretation_limit": "the five targets are proven direct-call destinations and code-item starts, but nonmembership in the IDA candidate-start set does not establish a missing function boundary, ABI, return behavior, arguments, or callee semantics",
    }
    output = REPORT / "m68k-direct-call-target-noncandidate-review.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({
        "original_sha256": original_sha256,
        "target_not_candidate_start_count": len(rows),
        "all_original_byte_checks_passed": True,
    }, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
