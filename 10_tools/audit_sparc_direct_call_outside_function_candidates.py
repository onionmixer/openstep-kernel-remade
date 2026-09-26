"""Locate SPARC direct-call sources outside IDA function-candidate ranges.

All reported source instruction bytes are rechecked against the big-endian
original.  Candidate ranges remain hypotheses and are never edited here.
"""
import csv
import hashlib
import json
from bisect import bisect_right
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ARCH = "sparc"
REPORT = ROOT / "09_validation/reports/multiarch-input-20260921"


def load_tsv(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def main():
    binary = (ROOT / "03_original" / ARCH / "binaries/mach_kernel").read_bytes()
    inventory = json.loads((ROOT / "03_original" / ARCH / "inventory/macho.json").read_text(encoding="utf-8"))
    text = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    text_start = int(text["address"], 16)
    text_end = text_start + int(text["size"])
    text_file_offset = int(text["file_offset"])
    edges = load_tsv(ROOT / "05_ida/exports" / ARCH / "direct-call-edges.tsv")
    functions = json.loads((ROOT / "05_ida/exports" / ARCH / "function-asm-index.json").read_text(encoding="utf-8"))
    text_units = load_tsv(ROOT / "05_ida/exports" / ARCH / "text-units.tsv")
    units_by_address = {int(row["address"], 16): row for row in text_units}
    ranges = sorted((int(row["start"], 16), int(row["end"], 16)) for row in functions)
    merged = []
    for start, end in ranges:
        assert text_start <= start < end <= text_end
        if not merged or start > merged[-1][1]:
            merged.append([start, end])
        else:
            merged[-1][1] = max(merged[-1][1], end)
    gaps = []
    cursor = text_start
    for start, end in merged:
        if cursor < start:
            gaps.append((cursor, start))
        cursor = max(cursor, end)
    if cursor < text_end:
        gaps.append((cursor, text_end))
    gap_starts = [start for start, _end in gaps]
    calls_by_gap = {gap: [] for gap in gaps}
    outside_edges = []
    for edge in edges:
        source = int(edge["source"], 16)
        if any(start <= source < end for start, end in merged):
            continue
        assert text_start <= source < text_end
        unit = units_by_address[source]
        assert unit["kind"] == "code"
        source_offset = text_file_offset + (source - text_start)
        raw = binary[source_offset:source_offset + int(unit["length"])]
        assert raw.hex() == edge["instruction_bytes"] == unit["bytes"]
        index = bisect_right(gap_starts, source) - 1
        assert index >= 0
        gap = gaps[index]
        assert gap[0] <= source < gap[1]
        calls_by_gap[gap].append(edge)
        outside_edges.append(edge)
    symbols = load_tsv(ROOT / "03_original" / ARCH / "inventory/symbols.tsv")
    report_rows = []
    for start, end in gaps:
        calls = sorted(calls_by_gap[(start, end)], key=lambda row: int(row["source"], 16))
        if calls:
            report_rows.append({
                "gap_start": hex(start),
                "gap_end_exclusive": hex(end),
                "gap_size": end - start,
                "direct_call_source_count": len(calls),
                "first_direct_call_source": calls[0]["source"],
                "last_direct_call_source": calls[-1]["source"],
                "raw_text_symbol_names_in_gap": sorted({
                    row["name"] for row in symbols
                    if row["section"] == "1" and start <= int(row["value"], 16) < end
                }),
            })
    outside_count = len(outside_edges)
    assert outside_count == 28
    report = {
        "schema": 1,
        "architecture": ARCH,
        "original_sha256_recomputed_with_python": hashlib.sha256(binary).hexdigest(),
        "original_text_mapping": {
            "address": hex(text_start), "end_exclusive": hex(text_end),
            "file_offset": text_file_offset, "size": int(text["size"]),
        },
        "ida_function_candidate_range_count": len(ranges),
        "merged_candidate_range_count": len(merged),
        "gap_count": len(gaps),
        "gap_count_containing_direct_call_sources": len(report_rows),
        "gaps_containing_direct_call_sources": report_rows,
        "direct_call_source_count_outside_candidate_ranges": outside_count,
        "every_outside_source_instruction_matches_original_big_endian_bytes": True,
        "conclusion": "these 28 direct-call source addresses are original code instructions in __text gaps not covered by current IDA function-candidate ranges",
        "interpretation_limit": "the gaps are review targets only; this does not prove missing functions, code/data errors, branch reachability, ABI, or behavior",
    }
    output = REPORT / "sparc-direct-call-outside-function-candidates.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({
        "original_sha256": report["original_sha256_recomputed_with_python"],
        "outside_direct_call_source_count": outside_count,
        "gap_count": len(report_rows),
        "original_big_endian_byte_checks_passed": True,
    }, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
