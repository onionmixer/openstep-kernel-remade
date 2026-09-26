"""Export direct-call instruction edges whose raw target calculation matches canonical IDA xrefs."""
import bisect
import csv
import hashlib
import json
import struct
from collections import Counter, defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
TARGETS = {
    "m68k": {
        "binary": ROOT / "03_original/m68k/binaries/mach_kernel",
        "sha256": "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75",
    },
    "sparc": {
        "binary": ROOT / "03_original/sparc/binaries/mach_kernel",
        "sha256": "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1",
    },
}


def load_tsv(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def code_item_at(units, starts, address):
    index = bisect.bisect_right(starts, address) - 1
    assert index >= 0
    start, end, row = units[index]
    assert start <= address < end and row["kind"] == "code"
    return start, end, row


def main():
    summaries = {}
    for architecture, expected in TARGETS.items():
        raw = expected["binary"].read_bytes()
        assert hashlib.sha256(raw).hexdigest() == expected["sha256"]
        units = []
        for row in load_tsv(ROOT / "05_ida/exports" / architecture / "text-units.tsv"):
            start = int(row["address"], 16)
            units.append((start, start + int(row["length"]), row))
        assert units == sorted(units)
        starts = [row[0] for row in units]
        symbols_by_value = defaultdict(list)
        for row in load_tsv(ROOT / "03_original" / architecture / "inventory/symbols.tsv"):
            symbols_by_value[int(row["value"], 16)].append(row["name"])
        edges = []
        edge_kind_counts = Counter()
        target_symbol_edge_count = 0
        type17_count = 0
        for xref in load_tsv(ROOT / "05_ida/exports" / architecture / "xrefs.tsv"):
            if xref["type"] != "17":
                continue
            type17_count += 1
            source = int(xref["from"], 16)
            target = int(xref["to"], 16)
            item_start, _item_end, item = code_item_at(units, starts, source)
            source_offset = int(item["file_offset"]) + source - item_start
            word = struct.unpack_from(">I", raw, source_offset)[0]
            if architecture == "m68k":
                opcode = word >> 16
                if opcode == 0x4EB9:
                    instruction_length = 6
                    computed_target = struct.unpack_from(">I", raw, source_offset + 2)[0]
                    edge_kind = "jsr_absolute_long"
                elif opcode == 0x61FF:
                    instruction_length = 6
                    displacement = struct.unpack_from(">i", raw, source_offset + 2)[0]
                    computed_target = (source + 2 + displacement) & 0xFFFFFFFF
                    edge_kind = "bsr_long_relative"
                else:
                    raise AssertionError((architecture, hex(source), hex(word)))
            else:
                assert word >> 30 == 1
                instruction_length = 4
                displacement = word & 0x3FFFFFFF
                if displacement & 0x20000000:
                    displacement -= 0x40000000
                computed_target = (source + (displacement << 2)) & 0xFFFFFFFF
                edge_kind = "call_relative"
            assert computed_target == target
            instruction_bytes = raw[source_offset:source_offset + instruction_length]
            assert instruction_bytes == bytes.fromhex(item["bytes"])[:instruction_length]
            names = sorted(symbols_by_value[target])
            if names:
                target_symbol_edge_count += 1
            edge_kind_counts[edge_kind] += 1
            edges.append({
                "source": hex(source),
                "target": hex(target),
                "edge_kind": edge_kind,
                "instruction_bytes": instruction_bytes.hex(),
                "target_raw_symbols": "|".join(names),
                "xref_type": xref["type"],
                "xref_iscode": xref["iscode"],
            })
        assert len(edges) == type17_count
        output = ROOT / "05_ida/exports" / architecture / "direct-call-edges.tsv"
        with output.open("w", encoding="utf-8", newline="") as handle:
            writer = csv.DictWriter(handle, fieldnames=list(edges[0]), delimiter="\t")
            writer.writeheader()
            writer.writerows(edges)
        summaries[architecture] = {
            "original_sha256_recomputed_with_python": expected["sha256"],
            "type17_xref_count": type17_count,
            "raw_direct_call_edge_count": len(edges),
            "edge_kind_counts": dict(sorted(edge_kind_counts.items())),
            "edges_with_exact_raw_symbol_target": target_symbol_edge_count,
            "tsv": str(output.relative_to(ROOT)),
            "interpretation_limit": "raw direct-call instruction edges do not establish callee behavior, argument values, return behavior, ABI, or complete function semantics",
        }
    report = {"schema": 1, "targets": summaries, "all_checks_passed": True}
    output = ROOT / "09_validation/reports/multiarch-input-20260921/direct-call-edge-export-validation.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
