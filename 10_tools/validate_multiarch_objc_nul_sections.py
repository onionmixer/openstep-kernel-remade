"""Independently validate the raw __OBJC NUL-section TSV against each original binary."""
import csv
import hashlib
import importlib.util
import json
from collections import defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT_DIR = ROOT / "09_validation/reports/multiarch-input-20260921"
MODULE_PATH = ROOT / "10_tools/export_multiarch_objc_nul_sections.py"


def load_export_module():
    spec = importlib.util.spec_from_file_location("objc_nul_export", MODULE_PATH)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def main():
    exporter = load_export_module()
    source_report = json.loads(
        (REPORT_DIR / "objc-nul-section-export-validation.json").read_text(encoding="utf-8")
    )
    targets = {}
    for architecture, expected in exporter.TARGETS.items():
        raw = expected["binary"].read_bytes()
        assert hashlib.sha256(raw).hexdigest() == expected["sha256"]
        cpu, sections = exporter.parse_macho_sections(raw)
        assert cpu == expected["cpu"]
        selected = {
            section["segment"] + "," + section["name"]: section
            for section in sections
            if section["segment"] == "__OBJC" and (section["flags"] & 0xFF) == exporter.S_CSTRING_LITERALS
        }
        tsv_path = ROOT / source_report["targets"][architecture]["tsv"]
        assert architecture in tsv_path.parts
        assert "x86" not in tsv_path.parts
        groups = defaultdict(list)
        with tsv_path.open(encoding="utf-8", newline="") as handle:
            for row in csv.DictReader(handle, delimiter="\t"):
                groups[row["section"]].append(row)
        assert set(groups).issubset(selected)
        summaries = {row["section"]: row for row in source_report["targets"][architecture]["sections"]}
        assert set(summaries) == set(selected)
        record_count = 0
        for section_name, section in selected.items():
            rows = sorted(groups[section_name], key=lambda row: int(row["index"]))
            assert [int(row["index"]) for row in rows] == list(range(len(rows)))
            expected_payload = raw[section["file_offset"]:section["file_offset"] + section["size"]]
            values = []
            current_address = section["address"]
            current_file_offset = section["file_offset"]
            for row in rows:
                value = bytes.fromhex(row["bytes"])
                assert int(row["address"], 16) == current_address
                assert int(row["file_offset"]) == current_file_offset
                assert int(row["byte_length"]) == len(value)
                assert row["ascii_escaped"] == exporter.escaped_ascii(value)
                values.append(value)
                current_address += len(value) + 1
                current_file_offset += len(value) + 1
            summary = summaries[section_name]
            assert summary["trailing_nul"] is True
            reconstructed = b"\0".join(values) + b"\0"
            assert reconstructed == expected_payload
            assert hashlib.sha256(reconstructed).hexdigest() == summary["raw_sha256"]
            assert len(rows) == summary["record_count"]
            record_count += len(rows)
        assert record_count == source_report["targets"][architecture]["record_count"]
        targets[architecture] = {
            "original_sha256_recomputed_with_python": expected["sha256"],
            "raw_cpu_type": cpu,
            "selected_section_count": len(selected),
            "tsv_record_count": record_count,
            "all_section_payloads_reconstructed_from_tsv": True,
        }
    report = {"schema": 1, "targets": targets, "all_checks_passed": True}
    output = REPORT_DIR / "objc-nul-section-tsv-validation.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
