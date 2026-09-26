"""Classify IDA xref endpoints by exported __text item kind without semantic inference."""
import bisect
import csv
import hashlib
import json
import struct
from collections import Counter
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT_DIR = ROOT / "09_validation/reports/multiarch-input-20260921"
TARGETS = {
    "m68k": {
        "binary": ROOT / "03_original/m68k/binaries/mach_kernel",
        "xrefs": ROOT / "05_ida/exports/m68k/xrefs.tsv",
        "text_units": ROOT / "05_ida/exports/m68k/text-units.tsv",
        "processor": "68K",
        "sha256": "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75",
    },
    "sparc": {
        "binary": ROOT / "03_original/sparc/binaries/mach_kernel",
        "xrefs": ROOT / "05_ida/exports/sparc/xrefs.tsv",
        "text_units": ROOT / "05_ida/exports/sparc/text-units.tsv",
        "processor": "sparcb",
        "sha256": "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1",
    },
}
LC_SEGMENT = 0x1


def segment_ranges(raw):
    magic, cpu, _subtype, _filetype, command_count, sizeofcmds, _flags = struct.unpack_from(
        ">7I", raw, 0
    )
    assert magic == 0xFEEDFACE
    command_offset = 28
    command_end = command_offset + sizeofcmds
    ranges = []
    for _ in range(command_count):
        command, command_size = struct.unpack_from(">2I", raw, command_offset)
        assert command_size >= 8
        assert command_offset + command_size <= command_end
        if command == LC_SEGMENT:
            _name, vmaddr, vmsize, _fileoff, _filesize, _maxprot, _initprot, _nsects, _segflags = (
                struct.unpack_from(">16s8I", raw, command_offset + 8)
            )
            if vmsize:
                ranges.append((vmaddr, vmaddr + vmsize))
        command_offset += command_size
    assert command_offset == command_end
    return cpu, ranges


def load_text_units(path):
    units = []
    with path.open(encoding="utf-8", newline="") as handle:
        for row in csv.DictReader(handle, delimiter="\t"):
            start = int(row["address"], 16)
            length = int(row["length"])
            assert length > 0
            units.append((start, start + length, row["kind"]))
    assert units == sorted(units)
    starts = [unit[0] for unit in units]
    for previous, current in zip(units, units[1:]):
        assert previous[1] == current[0]
    return units, starts


def containing_unit(address, units, starts):
    index = bisect.bisect_right(starts, address) - 1
    if index >= 0:
        start, end, kind = units[index]
        if start <= address < end:
            return kind
    return None


def main():
    combined = {}
    for architecture, expected in TARGETS.items():
        raw = expected["binary"].read_bytes()
        assert hashlib.sha256(raw).hexdigest() == expected["sha256"]
        raw_cpu, ranges = segment_ranges(raw)
        expected_cpu = 6 if architecture == "m68k" else 14
        assert raw_cpu == expected_cpu
        units, starts = load_text_units(expected["text_units"])
        source_kind_counts = Counter()
        destination_kind_counts = Counter()
        xref_type_counts = Counter()
        iscode_counts = Counter()
        xref_count = 0
        with expected["xrefs"].open(encoding="utf-8", newline="") as handle:
            for row in csv.DictReader(handle, delimiter="\t"):
                source = int(row["from"], 16)
                assert any(start <= source < end for start, end in ranges)
                kind = containing_unit(source, units, starts)
                source_kind_counts[kind if kind is not None else "outside___text"] += 1
                destination = int(row["to"], 16)
                destination_kind = containing_unit(destination, units, starts)
                if destination_kind is not None:
                    destination_kind_counts[destination_kind] += 1
                elif any(start <= destination < end for start, end in ranges):
                    destination_kind_counts["outside___text_mapped"] += 1
                else:
                    destination_kind_counts["outside_original_mapped"] += 1
                xref_type_counts[row["type"]] += 1
                iscode_counts[row["iscode"]] += 1
                xref_count += 1
        assert sum(source_kind_counts.values()) == xref_count
        assert sum(destination_kind_counts.values()) == xref_count
        combined[architecture] = {
            "original_sha256_recomputed_with_python": expected["sha256"],
            "raw_cpu_type": raw_cpu,
            "expected_ida_processor": expected["processor"],
            "xref_count": xref_count,
            "all_xref_sources_in_original_mapped_segments": True,
            "source_text_item_kind_counts": dict(sorted(source_kind_counts.items())),
            "destination_text_item_or_mapping_counts": dict(sorted(destination_kind_counts.items())),
            "ida_xref_type_value_counts": dict(sorted(xref_type_counts.items())),
            "ida_xref_iscode_value_counts": dict(sorted(iscode_counts.items())),
            "interpretation_limit": (
                "item kind and IDA xref fields are tool classifications; this audit does not "
                "establish call, data-pointer, control-flow, or function-boundary semantics"
            ),
        }
    report = {
        "schema": 1,
        "byte_order": "all original Mach-O parsing uses explicit big-endian fields",
        "targets": combined,
        "all_checks_passed": True,
    }
    output = REPORT_DIR / "xref-source-kind-audit.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
