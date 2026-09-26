"""Validate direct startup call edges from original m68k and SPARC instruction bytes."""
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
        "text_start": 0x04000310,
        "text_file_offset": 784,
        "calls": [
            (0x04001328, "_m68k_init"),
            (0x040013B0, "_startup_early"),
            (0x040013B6, "_setup_main"),
            (0x040013BE, "_start_initial_context"),
        ],
    },
    "sparc": {
        "binary": ROOT / "03_original/sparc/binaries/mach_kernel",
        "sha256": "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1",
        "text_start": 0xF0002000,
        "text_file_offset": 8192,
        "calls": [
            (0xF0003110, "_module_setup"),
            (0xF0003118, "_sparc_init"),
            (0xF000312C, "_setup_main"),
            (0xF0003134, "_start_initial_context"),
        ],
    },
}


def load_rows(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def item_at(rows, address):
    matches = [row for row in rows if int(row["address"], 16) == address]
    assert len(matches) == 1
    return matches[0]


def symbol_value(rows, name):
    matches = [row for row in rows if row["name"] == name]
    assert len(matches) == 1
    return int(matches[0]["value"], 16), matches[0]


def main():
    targets = {}
    for architecture, expected in TARGETS.items():
        raw = expected["binary"].read_bytes()
        assert hashlib.sha256(raw).hexdigest() == expected["sha256"]
        text_units = load_rows(ROOT / "05_ida/exports" / architecture / "text-units.tsv")
        xrefs = load_rows(ROOT / "05_ida/exports" / architecture / "xrefs.tsv")
        symbols = load_rows(ROOT / "03_original" / architecture / "inventory/symbols.tsv")
        call_rows = []
        for source, target_name in expected["calls"]:
            target, target_symbol = symbol_value(symbols, target_name)
            source_item = item_at(text_units, source)
            assert source_item["kind"] == "code"
            source_offset = expected["text_file_offset"] + source - expected["text_start"]
            assert int(source_item["file_offset"]) == source_offset
            word = struct.unpack_from(">I", raw, source_offset)[0]
            if architecture == "m68k":
                absolute_target = struct.unpack_from(">I", raw, source_offset + 2)[0]
                assert (word >> 16) == 0x4EB9
                assert absolute_target == target
                raw_evidence = {"instruction_word": hex(word), "absolute_long_target": hex(absolute_target)}
            else:
                assert word >> 30 == 1
                displacement_30 = word & 0x3FFFFFFF
                if displacement_30 & 0x20000000:
                    displacement_30 -= 0x40000000
                computed_target = (source + (displacement_30 << 2)) & 0xFFFFFFFF
                assert computed_target == target
                raw_evidence = {
                    "instruction_word": hex(word),
                    "signed_disp30": displacement_30,
                    "computed_target": hex(computed_target),
                }
            matching_xrefs = [
                row for row in xrefs
                if int(row["from"], 16) == source and int(row["to"], 16) == target and row["iscode"] == "1"
            ]
            assert len(matching_xrefs) == 1
            call_rows.append({
                "source": hex(source),
                "target": hex(target),
                "target_symbol": target_symbol,
                "source_text_item": source_item,
                "xref_row": matching_xrefs[0],
                "raw_evidence": raw_evidence,
            })
        targets[architecture] = {
            "original_sha256_recomputed_with_python": expected["sha256"],
            "direct_call_count": len(call_rows),
            "calls": call_rows,
            "conclusion": "each listed direct startup call edge is corroborated by raw instruction encoding, raw target symbol, source code item, and one IDA xref row",
            "interpretation_limit": "call-edge evidence does not establish callee behavior, argument values, return behavior, ABI, or startup outcome",
        }
    report = {"schema": 1, "targets": targets, "all_checks_passed": True}
    output = REPORT_DIR / "startup-direct-call-edge-audit.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
