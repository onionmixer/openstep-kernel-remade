"""Independently validate exported direct-call edge TSV rows against original bytes and xrefs."""
import bisect
import csv
import hashlib
import json
import struct
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT_DIR = ROOT / "09_validation/reports/multiarch-input-20260921"
EXPECTED = {
    "m68k": "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75",
    "sparc": "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1",
}


def rows(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def main():
    source_report = json.loads((REPORT_DIR / "direct-call-edge-export-validation.json").read_text(encoding="utf-8"))
    assert source_report["all_checks_passed"] is True
    targets = {}
    for architecture, expected_hash in EXPECTED.items():
        raw = (ROOT / "03_original" / architecture / "binaries/mach_kernel").read_bytes()
        assert hashlib.sha256(raw).hexdigest() == expected_hash
        text = []
        for row in rows(ROOT / "05_ida/exports" / architecture / "text-units.tsv"):
            start = int(row["address"], 16)
            text.append((start, start + int(row["length"]), row))
        starts = [row[0] for row in text]
        xref_pairs = {
            (int(row["from"], 16), int(row["to"], 16))
            for row in rows(ROOT / "05_ida/exports" / architecture / "xrefs.tsv")
            if row["type"] == "17" and row["iscode"] == "1"
        }
        tsv_path = ROOT / source_report["targets"][architecture]["tsv"]
        assert architecture in tsv_path.parts and "x86" not in tsv_path.parts
        edge_rows = rows(tsv_path)
        kind_counts = {}
        for edge in edge_rows:
            source = int(edge["source"], 16)
            target = int(edge["target"], 16)
            assert (source, target) in xref_pairs
            index = bisect.bisect_right(starts, source) - 1
            assert index >= 0
            item_start, item_end, item = text[index]
            assert item_start <= source < item_end and item["kind"] == "code"
            offset = int(item["file_offset"]) + source - item_start
            instruction = bytes.fromhex(edge["instruction_bytes"])
            assert raw[offset:offset + len(instruction)] == instruction
            word = struct.unpack_from(">I", raw, offset)[0]
            if edge["edge_kind"] == "jsr_absolute_long":
                assert architecture == "m68k" and word >> 16 == 0x4EB9
                computed = struct.unpack_from(">I", raw, offset + 2)[0]
            elif edge["edge_kind"] == "bsr_long_relative":
                assert architecture == "m68k" and word >> 16 == 0x61FF
                computed = (source + 2 + struct.unpack_from(">i", raw, offset + 2)[0]) & 0xFFFFFFFF
            elif edge["edge_kind"] == "call_relative":
                assert architecture == "sparc" and word >> 30 == 1
                displacement = word & 0x3FFFFFFF
                if displacement & 0x20000000:
                    displacement -= 0x40000000
                computed = (source + (displacement << 2)) & 0xFFFFFFFF
            else:
                raise AssertionError(edge["edge_kind"])
            assert computed == target
            kind_counts[edge["edge_kind"]] = kind_counts.get(edge["edge_kind"], 0) + 1
        assert len(edge_rows) == source_report["targets"][architecture]["raw_direct_call_edge_count"]
        assert kind_counts == source_report["targets"][architecture]["edge_kind_counts"]
        targets[architecture] = {
            "original_sha256_recomputed_with_python": expected_hash,
            "tsv_edge_count": len(edge_rows),
            "every_tsv_instruction_bytes_match_original": True,
            "every_tsv_target_calculation_matches_xref": True,
            "edge_kind_counts": kind_counts,
        }
    report = {"schema": 1, "targets": targets, "all_checks_passed": True}
    output = REPORT_DIR / "direct-call-edge-tsv-validation.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
