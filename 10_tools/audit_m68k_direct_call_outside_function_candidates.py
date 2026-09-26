"""Locate m68k raw direct-call sources outside IDA function-candidate ranges."""
import csv
import json
from bisect import bisect_right
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT_DIR = ROOT / "09_validation/reports/multiarch-input-20260921"


def load_tsv(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def main():
    architecture = "m68k"
    edges = load_tsv(ROOT / "05_ida/exports" / architecture / "direct-call-edges.tsv")
    functions = json.loads((ROOT / "05_ida/exports" / architecture / "function-asm-index.json").read_text(encoding="utf-8"))
    inventory = json.loads((ROOT / "03_original" / architecture / "inventory/macho.json").read_text(encoding="utf-8"))
    text = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    text_start = int(text["address"], 16)
    text_end = text_start + text["size"]
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
    gap_starts = [gap[0] for gap in gaps]
    calls_by_gap = {gap: [] for gap in gaps}
    for edge in edges:
        source = int(edge["source"], 16)
        if any(start <= source < end for start, end in merged):
            continue
        index = bisect_right(gap_starts, source) - 1
        assert index >= 0
        gap = gaps[index]
        assert gap[0] <= source < gap[1]
        calls_by_gap[gap].append(edge)
    symbols = load_tsv(ROOT / "03_original" / architecture / "inventory/symbols.tsv")
    report_rows = []
    for start, end in gaps:
        calls = sorted(calls_by_gap[(start, end)], key=lambda row: int(row["source"], 16))
        if not calls:
            continue
        names = sorted({
            row["name"] for row in symbols
            if row["section"] == "1" and start <= int(row["value"], 16) < end
        })
        report_rows.append({
            "gap_start": hex(start),
            "gap_end_exclusive": hex(end),
            "gap_size": end - start,
            "direct_call_source_count": len(calls),
            "first_direct_call_source": calls[0]["source"],
            "last_direct_call_source": calls[-1]["source"],
            "raw_text_symbol_names_in_gap": names,
        })
    outside_count = sum(row["direct_call_source_count"] for row in report_rows)
    assert outside_count == 1127
    ranked_gaps = sorted(
        report_rows,
        key=lambda row: (-row["direct_call_source_count"], -row["gap_size"], row["gap_start"]),
    )
    report = {
        "schema": 1,
        "architecture": architecture,
        "text_range": {"start": hex(text_start), "end_exclusive": hex(text_end)},
        "ida_function_candidate_range_count": len(ranges),
        "merged_candidate_range_count": len(merged),
        "gap_count": len(gaps),
        "gap_count_containing_direct_call_sources": len(report_rows),
        "gaps_containing_direct_call_sources": report_rows,
        "top_ten_gaps_by_direct_call_source_count": ranked_gaps[:10],
        "direct_call_source_count_outside_candidate_ranges": outside_count,
        "conclusion": "these direct-call source addresses fall in original __text gaps not covered by the current IDA function-candidate ranges",
        "interpretation_limit": "a gap is a review target, not proof of a missing function, code/data classification error, or specific behavior",
    }
    output = REPORT_DIR / "m68k-direct-call-outside-function-candidates.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
