"""Read-only initial IDA export for the OS42J m68k and SPARC kernel slices."""
import hashlib
import json
import struct
import traceback
from pathlib import Path

import ida_auto
import ida_funcs
import ida_ida
import ida_nalt
import ida_pro
import ida_segment
import idautils


ROOT = Path(__file__).resolve().parents[1]
INPUTS = {
    6: ("m68k", "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75"),
    14: ("sparc", "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1"),
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
    if cpu_type not in INPUTS:
        raise RuntimeError("unexpected Mach-O CPU type: %d" % cpu_type)
    architecture, expected_sha256 = INPUTS[cpu_type]
    if sha256(input_path) != expected_sha256:
        raise RuntimeError("input SHA-256 differs from OS42J preserved slice")

    ida_auto.auto_wait()
    if not ida_ida.inf_is_be():
        raise RuntimeError("IDA database is not big-endian")

    segments = []
    for start in idautils.Segments():
        segment = ida_segment.getseg(start)
        if segment is None:
            raise RuntimeError("segment enumeration returned no segment")
        segments.append({
            "start": hex(segment.start_ea),
            "end": hex(segment.end_ea),
            "size": segment.end_ea - segment.start_ea,
            "name": ida_segment.get_segm_name(segment),
            "class": ida_segment.get_segm_class(segment),
            "bitness": segment.bitness,
        })

    functions = []
    for address in idautils.Functions():
        function = ida_funcs.get_func(address)
        if function is None:
            raise RuntimeError("function iterator returned an unresolved address")
        functions.append({
            "start": hex(function.start_ea),
            "end": hex(function.end_ea),
            "size": function.end_ea - function.start_ea,
            "name": ida_funcs.get_func_name(function.start_ea),
            "flags": function.flags,
        })

    output = ROOT / "05_ida" / "exports" / architecture
    output.mkdir(parents=True, exist_ok=True)
    summary = {
        "schema": 1,
        "architecture": architecture,
        "input": str(input_path),
        "input_sha256": expected_sha256,
        "macho_cpu_type": cpu_type,
        "macho_magic_bytes": raw[:4].hex().upper(),
        "ida_processor": ida_ida.inf_get_procname(),
        "ida_big_endian": ida_ida.inf_is_be(),
        "ida_bits": 64 if ida_ida.inf_is_64bit() else 32 if ida_ida.inf_is_32bit_exactly() else 16,
        "image_min_ea": hex(ida_ida.inf_get_min_ea()),
        "image_max_ea": hex(ida_ida.inf_get_max_ea()),
        "segment_count": len(segments),
        "function_count": len(functions),
        "analysis_complete": True,
        "scope": "IDA autoanalysis inventory only; function boundaries, names, and types remain tool hypotheses",
    }
    (output / "initial-summary.json").write_text(
        json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    (output / "initial-segments.json").write_text(
        json.dumps(segments, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    (output / "initial-functions.json").write_text(
        json.dumps(functions, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(summary, ensure_ascii=False, sort_keys=True))


try:
    main()
except Exception:
    traceback.print_exc()
    ida_pro.qexit(1)
ida_pro.qexit(0)
