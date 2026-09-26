"""Export per-function IDA assembly from a validated OS42J big-endian work DB."""
import hashlib
import json
import struct
import traceback
from pathlib import Path

import ida_auto
import ida_bytes
import ida_funcs
import ida_ida
import ida_lines
import ida_loader
import ida_nalt
import ida_pro
import idautils


ROOT = Path(__file__).resolve().parents[1]
TARGETS = {
    6: {
        "architecture": "m68k",
        "sha256": "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75",
        "processor": "68K",
        "database_name": "m68k-os42j.i64",
    },
    14: {
        "architecture": "sparc",
        "sha256": "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1",
        "processor": "sparcb",
        "database_name": "sparc-os42j.i64",
    },
}


def sha256(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def main():
    input_path = Path(ida_nalt.get_input_file_path())
    raw = input_path.read_bytes()
    if raw[:4] != b"\xfe\xed\xfa\xce":
        raise RuntimeError("expected big-endian thin 32-bit Mach-O magic")
    cpu_type = struct.unpack_from(">i", raw, 4)[0]
    target = TARGETS.get(cpu_type)
    if target is None or sha256(input_path) != target["sha256"]:
        raise RuntimeError("database input does not match a preserved OS42J target")
    database_path = Path(ida_loader.get_path(ida_loader.PATH_TYPE_IDB))
    if database_path.name != target["database_name"]:
        raise RuntimeError("refusing to export from a noncanonical or rejected database")
    ida_auto.auto_wait()
    if not ida_ida.inf_is_be() or ida_ida.inf_get_procname() != target["processor"]:
        raise RuntimeError("IDA processor or byte order differs from validated target configuration")

    output = ROOT / "05_ida" / "exports" / target["architecture"]
    function_dir = output / "functions"
    function_dir.mkdir(parents=True, exist_ok=True)
    functions = []
    total_items = 0
    total_code_items = 0
    for start in idautils.Functions():
        function = ida_funcs.get_func(start)
        if function is None:
            raise RuntimeError("function iterator returned an unresolved address")
        rows = []
        item_count = 0
        code_item_count = 0
        for address in idautils.FuncItems(start):
            size = ida_bytes.get_item_size(address)
            if size <= 0:
                raise RuntimeError("nonpositive item size at 0x%x" % address)
            raw_item = ida_bytes.get_bytes(address, size)
            if raw_item is None or len(raw_item) != size:
                raise RuntimeError("unreadable item bytes at 0x%x" % address)
            flags = ida_bytes.get_full_flags(address)
            is_code = ida_bytes.is_code(flags)
            disassembly = ida_lines.generate_disasm_line(address, ida_lines.GENDSM_REMOVE_TAGS)
            rows.append("%08X: %-24s %s" % (address, raw_item.hex(), disassembly or ""))
            item_count += 1
            code_item_count += int(is_code)
        filename = "%08X.asm" % function.start_ea
        (function_dir / filename).write_text("\n".join(rows) + "\n", encoding="utf-8")
        functions.append({
            "start": hex(function.start_ea), "end": hex(function.end_ea),
            "size": function.end_ea - function.start_ea,
            "name": ida_funcs.get_func_name(function.start_ea), "flags": function.flags,
            "item_count": item_count, "code_item_count": code_item_count,
            "asm": "functions/" + filename,
        })
        total_items += item_count
        total_code_items += code_item_count
    summary = {
        "schema": 1,
        "architecture": target["architecture"],
        "input_sha256": target["sha256"],
        "macho_cpu_type": cpu_type,
        "macho_magic_bytes": raw[:4].hex().upper(),
        "ida_database": str(database_path),
        "ida_processor": ida_ida.inf_get_procname(),
        "ida_big_endian": ida_ida.inf_is_be(),
        "function_count": len(functions),
        "item_count": total_items,
        "code_item_count": total_code_items,
        "scope": "IDA autoanalysis function candidates with byte listings; boundaries, names, and code/data classification remain tool hypotheses",
    }
    (output / "function-asm-summary.json").write_text(
        json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    (output / "function-asm-index.json").write_text(
        json.dumps(functions, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(summary, ensure_ascii=False, sort_keys=True))


try:
    main()
except Exception:
    traceback.print_exc()
    ida_pro.qexit(1)
ida_pro.qexit(0)
