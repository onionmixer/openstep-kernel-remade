"""Classify sources of xrefs that target SPARC raw __OBJC NUL-section records."""
import bisect
import csv
import hashlib
import importlib.util
import json
from collections import Counter, defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT_DIR = ROOT / "09_validation/reports/multiarch-input-20260921"
MODULE_PATH = ROOT / "10_tools/export_multiarch_objc_nul_sections.py"


def load_export_module():
    spec = importlib.util.spec_from_file_location("objc_nul_export", MODULE_PATH)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def containing(address, intervals, starts):
    index = bisect.bisect_right(starts, address) - 1
    if index >= 0 and intervals[index][0] <= address < intervals[index][1]:
        return intervals[index][2]
    return None


def main():
    exporter = load_export_module()
    expected = exporter.TARGETS["sparc"]
    raw = expected["binary"].read_bytes()
    assert hashlib.sha256(raw).hexdigest() == expected["sha256"]
    cpu, sections = exporter.parse_macho_sections(raw)
    assert cpu == expected["cpu"]
    selected = [
        section for section in sections
        if section["segment"] == "__OBJC" and (section["flags"] & 0xFF) == exporter.S_CSTRING_LITERALS
    ]
    source_report = json.loads((REPORT_DIR / "objc-nul-section-export-validation.json").read_text(encoding="utf-8"))
    endpoint_report = json.loads((REPORT_DIR / "sparc-objc-nul-xref-endpoint-audit.json").read_text(encoding="utf-8"))
    assert source_report["all_checks_passed"] is True
    assert endpoint_report["all_checks_passed"] is True
    target_intervals = [(section["address"], section["address"] + section["size"], section) for section in selected]
    target_starts = [interval[0] for interval in target_intervals]
    assert target_intervals == sorted(target_intervals)
    source_intervals = [(section["address"], section["address"] + section["size"], section) for section in sections if section["size"]]
    source_intervals.sort()
    source_starts = [interval[0] for interval in source_intervals]
    text_units = []
    with (ROOT / "05_ida/exports/sparc/text-units.tsv").open(encoding="utf-8", newline="") as handle:
        for row in csv.DictReader(handle, delimiter="\t"):
            start = int(row["address"], 16)
            text_units.append((start, start + int(row["length"]), row["kind"]))
    text_starts = [row[0] for row in text_units]
    assert text_units == sorted(text_units)
    source_section_counts = Counter()
    source_segment_counts = Counter()
    source_text_kind_counts = Counter()
    endpoint_count = 0
    with (ROOT / "05_ida/exports/sparc/xrefs.tsv").open(encoding="utf-8", newline="") as handle:
        for row in csv.DictReader(handle, delimiter="\t"):
            destination = int(row["to"], 16)
            if containing(destination, target_intervals, target_starts) is None:
                continue
            source = int(row["from"], 16)
            section = containing(source, source_intervals, source_starts)
            assert section is not None
            source_section_counts[section["segment"] + "," + section["name"]] += 1
            source_segment_counts[section["segment"]] += 1
            text_kind = containing(source, text_units, text_starts)
            source_text_kind_counts[text_kind if text_kind is not None else "outside___text"] += 1
            endpoint_count += 1
    assert endpoint_count == endpoint_report["xref_destination_count_in_nul_sections"]
    assert sum(source_section_counts.values()) == endpoint_count
    assert sum(source_segment_counts.values()) == endpoint_count
    assert sum(source_text_kind_counts.values()) == endpoint_count
    report = {
        "schema": 1,
        "architecture": "sparc",
        "original_sha256_recomputed_with_python": expected["sha256"],
        "raw_cpu_type": cpu,
        "xref_count_targeting_raw_nul_sections": endpoint_count,
        "source_segment_counts": dict(sorted(source_segment_counts.items())),
        "source_section_counts": dict(sorted(source_section_counts.items())),
        "source_text_item_kind_counts": dict(sorted(source_text_kind_counts.items())),
        "interpretation_limit": (
            "source section placement and IDA text-item kind are structural classifications only; "
            "this audit does not identify Objective-C fields, pointers, call behavior, or string meaning"
        ),
        "all_checks_passed": True,
    }
    output = REPORT_DIR / "sparc-objc-nul-xref-source-audit.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
