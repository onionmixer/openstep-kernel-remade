"""Record an independent decoder observation for the retained m68k unknown bytes."""
import csv
import hashlib
import json
from pathlib import Path

from capstone import CS_ARCH_M68K, CS_MODE_BIG_ENDIAN, CS_MODE_M68K_000, Cs


ROOT = Path(__file__).resolve().parents[1]
ARCH = "m68k"
UNKNOWN = 0x409CE56
UNKNOWN_LENGTH = 6
REPORT = ROOT / "09_validation/reports/multiarch-input-20260921"


def load_tsv(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def decode(decoder, raw, address):
    return [{
        "address": hex(item.address), "size": item.size,
        "bytes": item.bytes.hex(), "mnemonic": item.mnemonic, "operands": item.op_str,
    } for item in decoder.disasm(raw, address)]


def main():
    binary = (ROOT / "03_original" / ARCH / "binaries/mach_kernel").read_bytes()
    inventory = json.loads((ROOT / "03_original" / ARCH / "inventory/macho.json").read_text(encoding="utf-8"))
    text = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    text_address = int(text["address"], 16)
    text_file_offset = int(text["file_offset"])
    unknown_offset = text_file_offset + (UNKNOWN - text_address)
    unknown_raw = binary[unknown_offset:unknown_offset + UNKNOWN_LENGTH]
    assert unknown_raw.hex() == "c1e000000000"
    units = load_tsv(ROOT / "05_ida/exports" / ARCH / "text-units.tsv")
    unknown_units = [row for row in units if UNKNOWN <= int(row["address"], 16) < UNKNOWN + UNKNOWN_LENGTH]
    assert len(unknown_units) == 6
    assert all(row["kind"] == "unknown" and row["length"] == "1" for row in unknown_units)
    xrefs = load_tsv(ROOT / "05_ida/exports" / ARCH / "xrefs.tsv")
    incoming = [row for row in xrefs if int(row["to"], 16) == UNKNOWN]
    assert incoming == [{"from": "0x409e084", "to": "0x409ce56", "type": "3", "iscode": "0"}]
    source = int(incoming[0]["from"], 16)
    source_unit = next(row for row in units if int(row["address"], 16) == source)
    source_offset = text_file_offset + (source - text_address)
    source_raw = binary[source_offset:source_offset + int(source_unit["length"])]
    assert source_raw.hex() == source_unit["bytes"] == "f23954380409ce56"
    decoder = Cs(CS_ARCH_M68K, CS_MODE_M68K_000 | CS_MODE_BIG_ENDIAN)
    known_raw = bytes.fromhex("4ef904001318")
    known = decode(decoder, known_raw, 0x4000310)
    candidate = decode(decoder, unknown_raw, UNKNOWN)
    assert known == [{"address": "0x4000310", "size": 6, "bytes": "4ef904001318", "mnemonic": "jmp", "operands": "$4001318.l"}]
    assert candidate == [
        {"address": "0x409ce56", "size": 2, "bytes": "c1e0", "mnemonic": "muls.w", "operands": "-(a0), d0"},
        {"address": "0x409ce58", "size": 4, "bytes": "00000000", "mnemonic": "ori.b", "operands": "#$0, d0"},
    ]
    report = {
        "schema": 1,
        "architecture": ARCH,
        "original_sha256_recomputed_with_python": hashlib.sha256(binary).hexdigest(),
        "unknown_range": {"start": hex(UNKNOWN), "end_exclusive": hex(UNKNOWN + UNKNOWN_LENGTH), "file_offset": unknown_offset, "bytes": unknown_raw.hex()},
        "ida_text_unit_state": {"unit_count": len(unknown_units), "kind": "unknown", "unit_length": 1},
        "incoming_xref_observation": {"xref": incoming[0], "source_original_bytes": source_raw.hex(), "source_ida_disassembly": source_unit["disassembly"]},
        "capstone_m68k_000_big_endian_control_decode": known,
        "capstone_m68k_000_big_endian_candidate_decode": candidate,
        "conclusion": "the independent decoder offers one sequential instruction interpretation, but it conflicts with the retained IDA unknown state and does not distinguish code from embedded data or establish reachability",
        "required_disposition": "retain the six bytes as IDA unknown and do not modify the database",
    }
    output = REPORT / "m68k-unknown-independent-decoder-observation.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"original_sha256": report["original_sha256_recomputed_with_python"], "unknown_byte_count": UNKNOWN_LENGTH, "required_disposition": report["required_disposition"]}, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
