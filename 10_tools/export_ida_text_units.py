"""Export every IDA item covering the original OS42J __text section."""
import csv
import hashlib
import json
import struct
import traceback
from pathlib import Path

import ida_auto
import ida_bytes
import ida_ida
import ida_lines
import ida_loader
import ida_nalt
import ida_pro


ROOT = Path(__file__).resolve().parents[1]
TARGETS = {
    6: ("m68k", "68K", "m68k-os42j.i64", "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75"),
    14: ("sparc", "sparcb", "sparc-os42j.i64", "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1"),
}


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def text_section(raw):
    _, _, _, _, command_count, command_bytes, _ = struct.unpack_from(">IiiIIII", raw, 0)
    offset = 28
    command_end = offset + command_bytes
    for _ in range(command_count):
        command, size = struct.unpack_from(">II", raw, offset)
        if size < 8 or size % 4 or offset + size > command_end:
            raise RuntimeError("invalid Mach-O load command")
        if command == 1:
            segment_values = struct.unpack_from(">16sIIIIiiII", raw, offset + 8)
            section_count = segment_values[7]
            for index in range(section_count):
                values = struct.unpack_from(">16s16sIIIIIIIII", raw, offset + 56 + index * 68)
                section_name, segment_name, address, size_value, file_offset = values[:5]
                if section_name.split(b"\0", 1)[0] == b"__text" and segment_name.split(b"\0", 1)[0] == b"__TEXT":
                    return address, size_value, file_offset
        offset += size
    raise RuntimeError("__TEXT,__text section not found")


def main():
    input_path = Path(ida_nalt.get_input_file_path())
    raw = input_path.read_bytes()
    if raw[:4] != b"\xfe\xed\xfa\xce":
        raise RuntimeError("expected big-endian thin 32-bit Mach-O")
    cpu_type = struct.unpack_from(">i", raw, 4)[0]
    target = TARGETS.get(cpu_type)
    if target is None:
        raise RuntimeError("unexpected CPU type")
    architecture, processor, database_name, expected_sha256 = target
    if sha256(raw) != expected_sha256:
        raise RuntimeError("input hash differs from preserved target")
    if Path(ida_loader.get_path(ida_loader.PATH_TYPE_IDB)).name != database_name:
        raise RuntimeError("refusing noncanonical or rejected database")
    ida_auto.auto_wait()
    if not ida_ida.inf_is_be() or ida_ida.inf_get_procname() != processor:
        raise RuntimeError("IDA byte order or processor differs from validated target")

    text_start, text_size, text_file_offset = text_section(raw)
    text_end = text_start + text_size
    output = ROOT / "05_ida" / "exports" / architecture
    output.mkdir(parents=True, exist_ok=True)
    rows = []
    category_bytes = {"code": 0, "data": 0, "unknown": 0}
    address = text_start
    while address < text_end:
        size = ida_bytes.get_item_size(address)
        if size <= 0 or address + size > text_end:
            raise RuntimeError("invalid IDA item extent at 0x%x" % address)
        item_bytes = ida_bytes.get_bytes(address, size)
        if item_bytes is None or len(item_bytes) != size:
            raise RuntimeError("unreadable IDA item at 0x%x" % address)
        flags = ida_bytes.get_full_flags(address)
        kind = "code" if ida_bytes.is_code(flags) else "data" if ida_bytes.is_data(flags) else "unknown"
        disassembly = ida_lines.generate_disasm_line(address, ida_lines.GENDSM_REMOVE_TAGS) if kind == "code" else ""
        rows.append({
            "address": hex(address), "file_offset": text_file_offset + address - text_start,
            "length": size, "kind": kind, "bytes": item_bytes.hex(), "disassembly": disassembly or "",
        })
        category_bytes[kind] += size
        address += size
    if address != text_end:
        raise RuntimeError("text traversal did not end at section boundary")
    with (output / "text-units.tsv").open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, ["address", "file_offset", "length", "kind", "bytes", "disassembly"], delimiter="\t", lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)
    summary = {
        "schema": 1, "architecture": architecture, "input_sha256": expected_sha256,
        "macho_cpu_type": cpu_type, "macho_magic_bytes": raw[:4].hex().upper(),
        "ida_processor": ida_ida.inf_get_procname(), "ida_big_endian": ida_ida.inf_is_be(),
        "text_start": hex(text_start), "text_size": text_size, "text_file_offset": text_file_offset,
        "unit_count": len(rows), "category_byte_counts": category_bytes,
        "scope": "complete sequential IDA item inventory of original __text; kind labels remain IDA hypotheses",
    }
    (output / "text-units-summary.json").write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(summary, ensure_ascii=False, sort_keys=True))


try:
    main()
except Exception:
    traceback.print_exc()
    ida_pro.qexit(1)
ida_pro.qexit(0)
