"""Validate original m68k and SPARC _start direct entry transitions without behavioral inference."""
import csv
import hashlib
import json
import struct
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT_DIR = ROOT / "09_validation/reports/multiarch-input-20260921"
TARGETS = {
    "m68k": {
        "binary": ROOT / "03_original/m68k/binaries/mach_kernel",
        "sha256": "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75",
        "start": 0x04000310,
        "target": 0x04001318,
        "start_bytes": "4ef904001318",
    },
    "sparc": {
        "binary": ROOT / "03_original/sparc/binaries/mach_kernel",
        "sha256": "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1",
        "start": 0xF0002000,
        "target": 0xF0003040,
        "start_bytes": "10800410",
    },
}


def load_rows(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def containing(rows, address):
    matches = []
    for row in rows:
        start = int(row["address"], 16)
        if start <= address < start + int(row["length"]):
            matches.append(row)
    assert len(matches) == 1
    return matches[0]


def symbol(rows, name):
    matches = [row for row in rows if row["name"] == name]
    assert len(matches) == 1
    return matches[0]


def main():
    targets = {}
    for architecture, expected in TARGETS.items():
        raw = expected["binary"].read_bytes()
        assert hashlib.sha256(raw).hexdigest() == expected["sha256"]
        text_units = load_rows(ROOT / "05_ida/exports" / architecture / "text-units.tsv")
        xrefs = load_rows(ROOT / "05_ida/exports" / architecture / "xrefs.tsv")
        symbols = load_rows(ROOT / "03_original" / architecture / "inventory/symbols.tsv")
        start_symbol = symbol(symbols, "_start")
        assert int(start_symbol["value"], 16) == expected["start"]
        source_unit = containing(text_units, expected["start"])
        target_unit = containing(text_units, expected["target"])
        source_offset = int(source_unit["file_offset"]) + expected["start"] - int(source_unit["address"], 16)
        source_bytes = bytes.fromhex(expected["start_bytes"])
        assert raw[source_offset:source_offset + len(source_bytes)] == source_bytes
        assert source_unit["kind"] == "code" and target_unit["kind"] == "code"
        matching_xrefs = [
            row for row in xrefs
            if int(row["from"], 16) == expected["start"] and int(row["to"], 16) == expected["target"]
        ]
        assert len(matching_xrefs) == 1
        assert matching_xrefs[0]["iscode"] == "1"
        if architecture == "m68k":
            opcode, absolute_target = struct.unpack(">HI", source_bytes)
            assert opcode == 0x4EF9
            assert absolute_target == expected["target"]
            decoder_evidence = {
                "raw_opcode": hex(opcode),
                "raw_absolute_long_target": hex(absolute_target),
                "ida_disassembly": source_unit["disassembly"],
            }
        else:
            word = struct.unpack(">I", source_bytes)[0]
            displacement_22 = word & 0x3FFFFF
            if displacement_22 & 0x200000:
                displacement_22 -= 0x400000
            computed_target = expected["start"] + (displacement_22 << 2)
            assert computed_target == expected["target"]
            entry_symbol = symbol(symbols, "entry")
            assert int(entry_symbol["value"], 16) == expected["target"]
            decoder_evidence = {
                "raw_instruction_word": hex(word),
                "signed_disp22": displacement_22,
                "computed_target": hex(computed_target),
                "target_symbol": entry_symbol["name"],
                "ida_disassembly": source_unit["disassembly"],
            }
        targets[architecture] = {
            "original_sha256_recomputed_with_python": expected["sha256"],
            "start_symbol": start_symbol,
            "source_text_item": source_unit,
            "target_text_item": target_unit,
            "xref_row": matching_xrefs[0],
            "decoder_evidence": decoder_evidence,
            "conclusion": "raw direct entry transition is corroborated by original bytes, a raw symbol, a code item, and one IDA xref row",
            "interpretation_limit": "this audit establishes only the direct entry transition; it does not establish startup behavior, ABI, arguments, or later control flow",
        }
    report = {"schema": 1, "targets": targets, "all_checks_passed": True}
    output = REPORT_DIR / "entry-transition-audit.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
