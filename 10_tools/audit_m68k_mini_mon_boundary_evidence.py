"""Preserve bounded raw-byte boundary evidence for m68k _mini_mon.

The report does not claim that the lexical UNLK/RTS pair is reachable from all
paths, nor that it determines a complete function boundary or ABI.
"""
import csv
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ARCH = "m68k"
TARGET = 0x4093976
REPORT = ROOT / "09_validation/reports/multiarch-input-20260921"


def load_tsv(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def signed_u32(value):
    return value - (1 << 32) if value & (1 << 31) else value


def main():
    binary = (ROOT / "03_original" / ARCH / "binaries/mach_kernel").read_bytes()
    inventory = json.loads((ROOT / "03_original" / ARCH / "inventory/macho.json").read_text(encoding="utf-8"))
    text = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    text_address = int(text["address"], 16)
    text_file_offset = int(text["file_offset"])
    text_end = text_address + int(text["size"])
    units = load_tsv(ROOT / "05_ida/exports" / ARCH / "text-units.tsv")
    units_by_address = {int(row["address"], 16): row for row in units}
    symbols = load_tsv(ROOT / "03_original" / ARCH / "inventory/symbols.tsv")
    target_symbols = [row for row in symbols if int(row["value"], 16) == TARGET]
    assert [row["name"] for row in target_symbols] == ["_mini_mon"]
    target_unit = units_by_address[TARGET]
    assert target_unit["kind"] == "code"
    target_offset = text_file_offset + (TARGET - text_address)
    target_raw = binary[target_offset:target_offset + int(target_unit["length"])]
    assert target_raw.hex() == target_unit["bytes"] == "4e56fefc"

    edges = load_tsv(ROOT / "05_ida/exports" / ARCH / "direct-call-edges.tsv")
    incoming = [edge for edge in edges if int(edge["target"], 16) == TARGET]
    source_rows = []
    for edge in incoming:
        source = int(edge["source"], 16)
        source_unit = units_by_address[source]
        source_offset = text_file_offset + (source - text_address)
        raw = binary[source_offset:source_offset + int(source_unit["length"])]
        assert raw.hex() == edge["instruction_bytes"] == source_unit["bytes"]
        assert int.from_bytes(raw[:2], "big") == 0x61FF
        displacement = signed_u32(int.from_bytes(raw[2:6], "big"))
        computed_target = (source + 2 + displacement) & 0xFFFFFFFF
        assert computed_target == TARGET
        source_rows.append({
            "source": hex(source),
            "source_file_offset": source_offset,
            "source_original_bytes": raw.hex(),
            "signed_big_endian_displacement": displacement,
            "computed_target": hex(computed_target),
        })
    assert len(source_rows) == 5

    ordered = sorted((int(row["address"], 16), row) for row in units if TARGET <= int(row["address"], 16) < text_end)
    exit_pair = None
    for index, (address, row) in enumerate(ordered[:-1]):
        next_address, next_row = ordered[index + 1]
        if row["kind"] == "code" and next_row["kind"] == "code" and row["bytes"] == "4e5e" and next_row["bytes"] == "4e75":
            assert next_address == address + int(row["length"])
            unlk_offset = text_file_offset + (address - text_address)
            rts_offset = text_file_offset + (next_address - text_address)
            assert binary[unlk_offset:unlk_offset + 2].hex() == "4e5e"
            assert binary[rts_offset:rts_offset + 2].hex() == "4e75"
            exit_pair = {
                "unlk_address": hex(address), "unlk_file_offset": unlk_offset,
                "unlk_original_bytes": "4e5e", "rts_address": hex(next_address),
                "rts_file_offset": rts_offset, "rts_original_bytes": "4e75",
            }
            break
    assert exit_pair is not None
    report = {
        "schema": 1,
        "architecture": ARCH,
        "original_sha256_recomputed_with_python": hashlib.sha256(binary).hexdigest(),
        "target_raw_symbol": target_symbols[0],
        "target_code_item": {
            "address": hex(TARGET), "file_offset": target_offset,
            "original_bytes": target_raw.hex(), "ida_disassembly": target_unit["disassembly"],
        },
        "incoming_bsr_long_edge_count": len(source_rows),
        "incoming_bsr_long_edges": source_rows,
        "first_lexical_unlk_rts_code_pair_at_or_after_target": exit_pair,
        "all_raw_big_endian_byte_and_target_checks_passed": True,
        "conclusion": "the raw symbol, five BSR.L encodings, target prologue code item, and a later lexical UNLK/RTS code pair provide bounded function-boundary review evidence",
        "interpretation_limit": "this does not establish full function extent, control-flow reachability to the lexical exit pair, calling convention, argument locations, return value, ABI, or callee behavior",
    }
    output = REPORT / "m68k-mini-mon-boundary-evidence.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({
        "original_sha256": report["original_sha256_recomputed_with_python"],
        "incoming_bsr_long_edge_count": len(source_rows),
        "all_checks_passed": True,
    }, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
