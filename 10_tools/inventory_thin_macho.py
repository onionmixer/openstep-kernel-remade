#!/usr/bin/env python3
"""Create a raw inventory for one thin 32-bit Mach-O without disassembly.

The caller must provide the expected byte order and CPU type.  This makes a
wrong-endian parse a hard failure rather than a plausible-looking inventory.
"""
import argparse
import csv
import hashlib
import json
import re
import struct
from pathlib import Path


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def cstring(raw):
    return raw.split(b"\0", 1)[0].decode("utf-8", "replace")


def parse(path, expected_endian, expected_cpu):
    data = path.read_bytes()
    magic_for_endian = {"big": b"\xfe\xed\xfa\xce", "little": b"\xce\xfa\xed\xfe"}
    if data[:4] != magic_for_endian[expected_endian]:
        raise ValueError("Mach-O magic does not match requested byte order")
    endian = ">" if expected_endian == "big" else "<"

    def unpack(fmt, offset):
        size = struct.calcsize(endian + fmt)
        if offset < 0 or offset + size > len(data):
            raise ValueError("out-of-bounds Mach-O structure at %d" % offset)
        return struct.unpack_from(endian + fmt, data, offset)

    _, cpu_type, cpu_subtype, filetype, ncmds, sizeofcmds, flags = unpack("IiiIIII", 0)
    if cpu_type != expected_cpu:
        raise ValueError("CPU type %d differs from expected %d" % (cpu_type, expected_cpu))
    command_end = 28 + sizeofcmds
    if command_end > len(data):
        raise ValueError("load commands exceed file")

    commands = []
    segments = []
    sections = []
    symtabs = []
    offset = 28
    for command_index in range(ncmds):
        command, command_size = unpack("II", offset)
        if command_size < 8 or command_size % 4 or offset + command_size > command_end:
            raise ValueError("invalid load command at %d" % offset)
        commands.append({"index": command_index, "command": command,
                         "offset": offset, "size": command_size})
        if command == 1:
            if command_size < 56:
                raise ValueError("truncated LC_SEGMENT")
            (name, address, virtual_size, file_offset, file_size, max_protection,
             initial_protection, section_count, segment_flags) = unpack(
                 "16sIIIIiiII", offset + 8)
            if file_offset + file_size > len(data) or 56 + section_count * 68 > command_size:
                raise ValueError("invalid segment extent or section list")
            segments.append({
                "name": cstring(name), "address": hex(address), "size": virtual_size,
                "file_offset": file_offset, "file_size": file_size,
                "max_protection": max_protection, "initial_protection": initial_protection,
                "flags": segment_flags,
            })
            for local_index in range(section_count):
                values = unpack("16s16sIIIIIIIII", offset + 56 + local_index * 68)
                (section_name, segment_name, address, size, file_offset, alignment,
                 relocation_offset, relocation_count, section_flags, reserved1,
                 reserved2) = values
                sections.append({
                    "index": len(sections) + 1, "segment": cstring(segment_name),
                    "name": cstring(section_name), "address": hex(address), "size": size,
                    "file_offset": file_offset, "alignment_exponent": alignment,
                    "relocation_offset": relocation_offset, "relocation_count": relocation_count,
                    "flags": hex(section_flags), "reserved1": reserved1, "reserved2": reserved2,
                })
        elif command == 2:
            if command_size < 24:
                raise ValueError("truncated LC_SYMTAB")
            symtabs.append(unpack("IIII", offset + 8))
        offset += command_size
    if offset != command_end:
        raise ValueError("load command count does not terminate at command end")

    symbols = []
    for symoff, count, stroff, strsize in symtabs:
        if symoff + count * 12 > len(data) or stroff + strsize > len(data):
            raise ValueError("symbol or string table exceeds file")
        strings = data[stroff:stroff + strsize]
        for index in range(count):
            strx, ntype, section, description, value = unpack("IBBHI", symoff + index * 12)
            if strx >= strsize or strings.find(b"\0", strx) == -1:
                raise ValueError("invalid symbol string offset")
            debug = bool(ntype & 0xe0)
            defined_external = not debug and bool(ntype & 1) and (ntype & 0x0e) != 0
            symbols.append({
                "index": len(symbols), "value": hex(value), "name": cstring(strings[strx:]),
                "type": hex(ntype), "section": section, "description": description,
                "debug": int(debug), "defined_external": int(defined_external),
            })
    printable_strings = [
        {"file_offset": hex(match.start()), "text": match.group().decode("ascii")}
        for match in re.finditer(rb"[\x20-\x7e]{8,}", data)
    ]
    report = {
        "schema": 1,
        "sha256": sha256(data),
        "file_size": len(data),
        "magic_bytes": data[:4].hex().upper(),
        "endian": expected_endian,
        "bits": 32,
        "cpu_type": cpu_type,
        "cpu_subtype": cpu_subtype,
        "filetype": filetype,
        "flags": flags,
        "command_count": ncmds,
        "commands_size": sizeofcmds,
        "commands": commands,
        "segments": segments,
        "sections": sections,
        "nlist_count": len(symbols),
        "defined_external_symbol_count": sum(row["defined_external"] for row in symbols),
        "caveat": "raw big/little-endian Mach-O parse; nlist entries are not function boundaries; no disassembly performed",
    }
    return report, symbols, printable_strings


def write_tsv(path, fields, rows):
    with path.open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fields, delimiter="\t", lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("input", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--expected-endian", choices=("big", "little"), required=True)
    parser.add_argument("--expected-cpu", type=lambda value: int(value, 0), required=True)
    args = parser.parse_args()
    before = args.input.read_bytes()
    report, symbols, strings = parse(args.input, args.expected_endian, args.expected_cpu)
    after = args.input.read_bytes()
    if before != after or sha256(before) != report["sha256"]:
        raise ValueError("input changed while inventory was created")
    args.output.mkdir(parents=True, exist_ok=True)
    (args.output / "macho.json").write_text(
        json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    write_tsv(args.output / "symbols.tsv", [
        "index", "value", "name", "type", "section", "description", "debug", "defined_external",
    ], symbols)
    write_tsv(args.output / "strings.tsv", ["file_offset", "text"], strings)
    print(json.dumps({
        "input_sha256": report["sha256"], "endian": report["endian"],
        "cpu_type": report["cpu_type"], "segments": len(report["segments"]),
        "sections": len(report["sections"]), "symbols": len(symbols),
        "strings": len(strings),
    }, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
