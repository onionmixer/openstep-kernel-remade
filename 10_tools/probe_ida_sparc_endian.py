"""Record whether a forced IDA SPARC processor configuration is big-endian."""
import hashlib
import json
import struct
import traceback
from pathlib import Path

import ida_auto
import ida_ida
import ida_nalt
import ida_pro


ROOT = Path(__file__).resolve().parents[1]
EXPECTED_SHA256 = "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1"


def main():
    input_path = Path(ida_nalt.get_input_file_path())
    data = input_path.read_bytes()
    if data[:4] != b"\xfe\xed\xfa\xce" or struct.unpack_from(">i", data, 4)[0] != 14:
        raise RuntimeError("expected OS42J big-endian SPARC Mach-O")
    if hashlib.sha256(data).hexdigest() != EXPECTED_SHA256:
        raise RuntimeError("unexpected SPARC input SHA-256")
    ida_auto.auto_wait()
    result = {
        "schema": 1,
        "input_sha256": EXPECTED_SHA256,
        "macho_magic_bytes": data[:4].hex().upper(),
        "macho_cpu_type": 14,
        "ida_processor": ida_ida.inf_get_procname(),
        "ida_big_endian": ida_ida.inf_is_be(),
        "ida_bits": 64 if ida_ida.inf_is_64bit() else 32 if ida_ida.inf_is_32bit_exactly() else 16,
    }
    output = ROOT / "05_ida/exports/sparc/probes"
    output.mkdir(parents=True, exist_ok=True)
    (output / "force-sparcb.json").write_text(
        json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, ensure_ascii=False, sort_keys=True))
    return result["ida_big_endian"]


try:
    ok = main()
except Exception:
    traceback.print_exc()
    ida_pro.qexit(1)
ida_pro.qexit(0 if ok else 1)
