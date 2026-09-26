"""Export all IDA xrefs from one validated OS42J big-endian database."""
import csv
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
import idautils


ROOT = Path(__file__).resolve().parents[1]
TARGETS = {
    6: ("m68k", "68K", "m68k-os42j.i64", "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75"),
    14: ("sparc", "sparcb", "sparc-os42j.i64", "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1"),
}


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
    if hashlib.sha256(raw).hexdigest() != expected_sha256:
        raise RuntimeError("input hash differs from preserved target")
    if Path(ida_loader.get_path(ida_loader.PATH_TYPE_IDB)).name != database_name:
        raise RuntimeError("refusing noncanonical or rejected database")
    ida_auto.auto_wait()
    if not ida_ida.inf_is_be() or ida_ida.inf_get_procname() != processor:
        raise RuntimeError("IDA byte order or processor differs from validated target")

    rows = []
    source_count = 0
    for address in idautils.Heads(ida_ida.inf_get_min_ea(), ida_ida.inf_get_max_ea()):
        source_count += 1
        for xref in idautils.XrefsFrom(address, 0):
            rows.append({"from": hex(xref.frm), "to": hex(xref.to), "type": xref.type, "iscode": int(xref.iscode)})
    rows.sort(key=lambda row: (int(row["from"], 16), int(row["to"], 16), row["type"], row["iscode"]))
    output = ROOT / "05_ida" / "exports" / architecture
    with (output / "xrefs.tsv").open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, ["from", "to", "type", "iscode"], delimiter="\t", lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)
    summary = {
        "schema": 1, "architecture": architecture, "input_sha256": expected_sha256,
        "macho_cpu_type": cpu_type, "macho_magic_bytes": raw[:4].hex().upper(),
        "ida_processor": ida_ida.inf_get_procname(), "ida_big_endian": ida_ida.inf_is_be(),
        "source_head_count": source_count, "xref_count": len(rows),
        "scope": "IDA autoanalysis xref inventory; endpoint classification and semantic interpretation are separate",
    }
    (output / "xrefs-summary.json").write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(summary, ensure_ascii=False, sort_keys=True))


try:
    main()
except Exception:
    traceback.print_exc()
    ida_pro.qexit(1)
ida_pro.qexit(0)
