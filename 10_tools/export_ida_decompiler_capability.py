"""Record Hex-Rays availability without decompiling or changing a function."""
import hashlib
import json
import struct
import traceback
from pathlib import Path

import ida_auto
import ida_ida
import ida_loader
import ida_nalt
import ida_pro


ROOT = Path(__file__).resolve().parents[1]
TARGETS = {
    6: ("m68k", "68K", "m68k-os42j.i64", "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75"),
    14: ("sparc", "sparcb", "sparc-os42j.i64", "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1"),
}


def main():
    input_path = Path(ida_nalt.get_input_file_path())
    raw = input_path.read_bytes()
    cpu = struct.unpack_from(">i", raw, 4)[0] if raw[:4] == b"\xfe\xed\xfa\xce" else None
    target = TARGETS.get(cpu)
    if target is None:
        raise RuntimeError("expected preserved big-endian OS42J Mach-O input")
    architecture, processor, database_name, expected_hash = target
    if hashlib.sha256(raw).hexdigest() != expected_hash:
        raise RuntimeError("unexpected input hash")
    if Path(ida_loader.get_path(ida_loader.PATH_TYPE_IDB)).name != database_name:
        raise RuntimeError("refusing noncanonical or rejected database")
    ida_auto.auto_wait()
    if not ida_ida.inf_is_be() or ida_ida.inf_get_procname() != processor:
        raise RuntimeError("processor or byte order mismatch")
    try:
        import ida_hexrays
        initialized = bool(ida_hexrays.init_hexrays_plugin())
        version = ida_hexrays.get_hexrays_version() if initialized else None
        result = {"module_imported": True, "plugin_initialized": initialized, "version": version}
    except Exception as error:
        result = {"module_imported": False, "plugin_initialized": False, "version": None,
                  "error_type": type(error).__name__, "error": str(error)}
    result.update({
        "schema": 1, "architecture": architecture, "input_sha256": expected_hash,
        "ida_processor": ida_ida.inf_get_procname(), "ida_big_endian": ida_ida.inf_is_be(),
        "scope": "availability probe only; no function decompilation, type application, rename, or database classification change",
    })
    output = ROOT / "05_ida/exports" / architecture / "decompiler-capability.json"
    output.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, ensure_ascii=False, sort_keys=True))


try:
    main()
except Exception:
    traceback.print_exc()
    ida_pro.qexit(1)
ida_pro.qexit(0)
