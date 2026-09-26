"""Audit original __OBJC section word layout without applying runtime metadata schemas."""
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
        "cpu": 6,
        "sha256": "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75",
    },
    "sparc": {
        "binary": ROOT / "03_original/sparc/binaries/mach_kernel",
        "cpu": 14,
        "sha256": "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1",
    },
}
LC_SEGMENT = 0x1


def name(raw):
    return raw.split(b"\0", 1)[0].decode("ascii")


def parse_big_endian_macho(raw):
    magic, cpu, _subtype, _filetype, command_count, sizeofcmds, _flags = struct.unpack_from(
        ">7I", raw, 0
    )
    assert magic == 0xFEEDFACE
    command_offset = 28
    command_end = command_offset + sizeofcmds
    segments = []
    sections = []
    for _ in range(command_count):
        command, command_size = struct.unpack_from(">2I", raw, command_offset)
        assert command_size >= 8
        assert command_offset + command_size <= command_end
        if command == LC_SEGMENT:
            segment = struct.unpack_from(">16s8I", raw, command_offset + 8)
            segment_name = name(segment[0])
            vmaddr, vmsize, fileoff, filesize, _maxprot, _initprot, nsects, _segflags = segment[1:]
            assert command_size == 56 + nsects * 68
            assert fileoff + filesize <= len(raw)
            segments.append((segment_name, vmaddr, vmaddr + vmsize))
            section_offset = command_offset + 56
            for section_index in range(nsects):
                fields = struct.unpack_from(">16s16s9I", raw, section_offset + section_index * 68)
                section_name = name(fields[0])
                owner = name(fields[1])
                address, size, file_offset, alignment, relocation_offset, relocation_count, flags, reserved1, reserved2 = fields[2:]
                assert owner == segment_name
                section_type = flags & 0xFF
                file_backed = section_type != 0x1
                if file_backed:
                    assert file_offset + size <= len(raw)
                sections.append({
                    "segment": owner,
                    "name": section_name,
                    "address": address,
                    "size": size,
                    "file_offset": file_offset,
                    "alignment": alignment,
                    "relocation_offset": relocation_offset,
                    "relocation_count": relocation_count,
                    "flags": flags,
                    "file_backed": file_backed,
                    "reserved1": reserved1,
                    "reserved2": reserved2,
                })
        command_offset += command_size
    assert command_offset == command_end
    return cpu, segments, sections


def section_containing(value, sections):
    for section in sections:
        if section["size"] and section["address"] <= value < section["address"] + section["size"]:
            return section
    return None


def main():
    targets = {}
    for architecture, expected in TARGETS.items():
        raw = expected["binary"].read_bytes()
        assert hashlib.sha256(raw).hexdigest() == expected["sha256"]
        cpu, segments, sections = parse_big_endian_macho(raw)
        assert cpu == expected["cpu"]
        objc_sections = [section for section in sections if section["segment"] == "__OBJC"]
        for section in objc_sections:
            assert section["file_backed"] is True
            assert section["file_offset"] % 4 == 0
            assert section["size"] % 4 == 0
        section_rows = []
        overall = Counter()
        for section in objc_sections:
            values = [
                struct.unpack_from(">I", raw, section["file_offset"] + offset)[0]
                for offset in range(0, section["size"], 4)
            ]
            per_section = Counter()
            for value in values:
                if value == 0:
                    per_section["zero_word"] += 1
                    continue
                target = section_containing(value, sections)
                if target is None:
                    per_section["nonzero_value_outside_sections"] += 1
                else:
                    per_section["nonzero_value_in_section"] += 1
                    per_section["target_segment:" + target["segment"]] += 1
                    per_section["target_section:" + target["segment"] + "," + target["name"]] += 1
            assert sum(count for key, count in per_section.items() if key in {
                "zero_word", "nonzero_value_outside_sections", "nonzero_value_in_section"
            }) == len(values)
            overall.update(per_section)
            section_rows.append({
                "section": section["segment"] + "," + section["name"],
                "word_count": len(values),
                "value_location_counts": dict(sorted(per_section.items())),
            })
        targets[architecture] = {
            "original_sha256_recomputed_with_python": expected["sha256"],
            "raw_cpu_type": cpu,
            "objc_section_count": len(objc_sections),
            "objc_sections_all_file_backed_and_4_byte_aligned": True,
            "total_word_count": sum(row["word_count"] for row in section_rows),
            "zero_word_count": overall["zero_word"],
            "nonzero_value_in_section_count": overall["nonzero_value_in_section"],
            "nonzero_value_outside_sections_count": overall["nonzero_value_outside_sections"],
            "sections": section_rows,
            "aggregate_value_location_counts": dict(sorted(overall.items())),
            "interpretation_limit": (
                "32-bit big-endian values are only address candidates for this layout audit; "
                "the audit does not identify pointers, Objective-C fields, classes, methods, "
                "or runtime behavior"
            ),
        }
    report = {
        "schema": 1,
        "byte_order": "all Mach-O headers, section fields, and word values use explicit big-endian parsing",
        "targets": targets,
        "all_checks_passed": True,
    }
    output = REPORT_DIR / "objc-word-layout-audit.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
