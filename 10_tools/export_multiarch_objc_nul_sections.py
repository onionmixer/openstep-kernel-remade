"""Export NUL-delimited bytes from original __OBJC sections flagged 0x2, without semantic labels."""
import csv
import hashlib
import json
import struct
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT_DIR = ROOT / "09_validation/reports/multiarch-input-20260921"
EXPORT_DIR = ROOT / "03_original"
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
S_CSTRING_LITERALS = 0x2


def text(raw):
    return raw.split(b"\0", 1)[0].decode("ascii")


def parse_macho_sections(raw):
    magic, cpu, _subtype, _filetype, command_count, sizeofcmds, _flags = struct.unpack_from(
        ">7I", raw, 0
    )
    assert magic == 0xFEEDFACE
    command_offset = 28
    command_end = command_offset + sizeofcmds
    sections = []
    for _ in range(command_count):
        command, command_size = struct.unpack_from(">2I", raw, command_offset)
        assert command_size >= 8
        assert command_offset + command_size <= command_end
        if command == LC_SEGMENT:
            segment_name, _vmaddr, _vmsize, file_offset, file_size, _maxprot, _initprot, section_count, _segflags = (
                struct.unpack_from(">16s8I", raw, command_offset + 8)
            )
            assert command_size == 56 + section_count * 68
            assert file_offset + file_size <= len(raw)
            for section_index in range(section_count):
                fields = struct.unpack_from(">16s16s9I", raw, command_offset + 56 + section_index * 68)
                section_name = text(fields[0])
                owner = text(fields[1])
                address, size, section_file_offset, _align, _reloff, _nreloc, flags, _reserved1, _reserved2 = fields[2:]
                assert owner == text(segment_name)
                section_type = flags & 0xFF
                file_backed = section_type != 0x1
                if file_backed:
                    assert section_file_offset + size <= len(raw)
                sections.append({
                    "segment": owner,
                    "name": section_name,
                    "address": address,
                    "size": size,
                    "file_offset": section_file_offset,
                    "flags": flags,
                    "file_backed": file_backed,
                })
        command_offset += command_size
    assert command_offset == command_end
    return cpu, sections


def escaped_ascii(raw):
    return raw.decode("ascii", errors="backslashreplace")


def main():
    targets = {}
    for architecture, expected in TARGETS.items():
        raw = expected["binary"].read_bytes()
        assert hashlib.sha256(raw).hexdigest() == expected["sha256"]
        cpu, sections = parse_macho_sections(raw)
        assert cpu == expected["cpu"]
        selected = [
            section for section in sections
            if section["segment"] == "__OBJC"
            and (section["flags"] & 0xFF) == S_CSTRING_LITERALS
        ]
        rows = []
        summaries = []
        for section in selected:
            assert section["file_backed"] is True
            payload = raw[section["file_offset"]:section["file_offset"] + section["size"]]
            chunks = payload.split(b"\0")
            trailing_nul = chunks[-1] == b""
            records = chunks[:-1] if trailing_nul else chunks
            reconstructed = b"\0".join(records) + (b"\0" if trailing_nul else b"")
            assert reconstructed == payload
            for index, value in enumerate(records):
                prefix_length = sum(len(previous) + 1 for previous in records[:index])
                rows.append({
                    "section": section["segment"] + "," + section["name"],
                    "index": index,
                    "address": hex(section["address"] + prefix_length),
                    "file_offset": section["file_offset"] + prefix_length,
                    "byte_length": len(value),
                    "bytes": value.hex(),
                    "ascii_escaped": escaped_ascii(value),
                })
            summaries.append({
                "section": section["segment"] + "," + section["name"],
                "flags": hex(section["flags"]),
                "address": hex(section["address"]),
                "file_offset": section["file_offset"],
                "size": section["size"],
                "record_count": len(records),
                "trailing_nul": trailing_nul,
                "raw_sha256": hashlib.sha256(payload).hexdigest(),
                "reconstructed_bytes_match_original": True,
            })
        output = EXPORT_DIR / architecture / "inventory/objc-nul-sections.tsv"
        with output.open("w", encoding="utf-8", newline="") as handle:
            writer = csv.DictWriter(
                handle,
                fieldnames=["section", "index", "address", "file_offset", "byte_length", "bytes", "ascii_escaped"],
                delimiter="\t",
            )
            writer.writeheader()
            writer.writerows(rows)
        targets[architecture] = {
            "original_sha256_recomputed_with_python": expected["sha256"],
            "raw_cpu_type": cpu,
            "selected_section_count": len(selected),
            "record_count": len(rows),
            "sections": summaries,
            "tsv": str(output.relative_to(ROOT)),
            "interpretation_limit": (
                "section flag 0x2 and NUL-delimited byte records are raw layout facts; "
                "this export does not identify Objective-C classes, selectors, types, or behavior"
            ),
        }
    report = {
        "schema": 1,
        "byte_order": "Mach-O header and section fields use explicit big-endian parsing; NUL records are byte sequences",
        "targets": targets,
        "all_checks_passed": True,
    }
    output = REPORT_DIR / "objc-nul-section-export-validation.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
