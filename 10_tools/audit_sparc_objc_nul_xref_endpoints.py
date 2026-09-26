"""Classify SPARC IDA xref destinations at raw __OBJC NUL-record boundaries only."""
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
ARCHITECTURE = "sparc"


def load_export_module():
    spec = importlib.util.spec_from_file_location("objc_nul_export", MODULE_PATH)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def main():
    exporter = load_export_module()
    expected = exporter.TARGETS[ARCHITECTURE]
    raw = expected["binary"].read_bytes()
    assert hashlib.sha256(raw).hexdigest() == expected["sha256"]
    cpu, sections = exporter.parse_macho_sections(raw)
    assert cpu == expected["cpu"]
    source_report = json.loads(
        (REPORT_DIR / "objc-nul-section-export-validation.json").read_text(encoding="utf-8")
    )
    tsv_validation = json.loads(
        (REPORT_DIR / "objc-nul-section-tsv-validation.json").read_text(encoding="utf-8")
    )
    assert source_report["all_checks_passed"] is True
    assert tsv_validation["all_checks_passed"] is True
    tsv_path = ROOT / source_report["targets"][ARCHITECTURE]["tsv"]
    assert ARCHITECTURE in tsv_path.parts
    records_by_section = defaultdict(list)
    with tsv_path.open(encoding="utf-8", newline="") as handle:
        for row in csv.DictReader(handle, delimiter="\t"):
            records_by_section[row["section"]].append(row)
    selected = {
        section["segment"] + "," + section["name"]: section
        for section in sections
        if section["segment"] == "__OBJC" and (section["flags"] & 0xFF) == exporter.S_CSTRING_LITERALS
    }
    assert set(records_by_section) == set(selected)
    interval_by_section = {}
    for section_name, section in selected.items():
        records = sorted(records_by_section[section_name], key=lambda row: int(row["index"]))
        intervals = []
        for index, row in enumerate(records):
            start = int(row["address"], 16)
            value = bytes.fromhex(row["bytes"])
            assert int(row["file_offset"]) == section["file_offset"] + start - section["address"]
            assert raw[int(row["file_offset"]):int(row["file_offset"]) + len(value)] == value
            intervals.append((start, start + len(value), start + len(value)))
            if index:
                assert intervals[index - 1][2] + 1 == start
        assert intervals
        assert intervals[0][0] == section["address"]
        assert intervals[-1][2] + 1 == section["address"] + section["size"]
        interval_by_section[section_name] = (intervals, [interval[0] for interval in intervals])
    boundary_counts = Counter()
    section_counts = Counter()
    xref_type_counts = Counter()
    endpoint_count = 0
    with (ROOT / "05_ida/exports/sparc/xrefs.tsv").open(encoding="utf-8", newline="") as handle:
        for row in csv.DictReader(handle, delimiter="\t"):
            destination = int(row["to"], 16)
            for section_name, (intervals, starts) in interval_by_section.items():
                section = selected[section_name]
                if not section["address"] <= destination < section["address"] + section["size"]:
                    continue
                index = bisect.bisect_right(starts, destination) - 1
                assert index >= 0
                start, body_end, terminator = intervals[index]
                if destination == start:
                    boundary = "record_start"
                elif destination < body_end:
                    boundary = "record_body"
                elif destination == terminator:
                    boundary = "record_terminator"
                else:
                    raise AssertionError((section_name, hex(destination), index))
                boundary_counts[boundary] += 1
                section_counts[section_name] += 1
                xref_type_counts[row["type"]] += 1
                endpoint_count += 1
                break
    assert sum(boundary_counts.values()) == endpoint_count
    report = {
        "schema": 1,
        "architecture": ARCHITECTURE,
        "original_sha256_recomputed_with_python": expected["sha256"],
        "raw_cpu_type": cpu,
        "nul_section_count": len(selected),
        "xref_destination_count_in_nul_sections": endpoint_count,
        "destination_boundary_counts": dict(sorted(boundary_counts.items())),
        "destination_section_counts": dict(sorted(section_counts.items())),
        "ida_xref_type_value_counts": dict(sorted(xref_type_counts.items())),
        "interpretation_limit": (
            "xref fields and NUL-record boundaries establish only address placement; this audit "
            "does not identify string meaning, call behavior, selectors, types, or pointers"
        ),
        "all_checks_passed": True,
    }
    output = REPORT_DIR / "sparc-objc-nul-xref-endpoint-audit.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
