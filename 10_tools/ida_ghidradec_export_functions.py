"""Export explicit IDA function candidates through the global GhidraDec plugin.

Run only on a copied IDA database.  Each C output and JSON record is written
under the architecture-specific export directory.  Outputs are decompiler
hypotheses, while raw binary and assembly corpora remain the byte evidence.
"""
import hashlib
import json
import os
from pathlib import Path

import ida_auto
import ida_funcs
import ida_ida
import ida_loader
import ida_name
import ida_nalt
import ida_pro


# GhidraDec's arg=4 implementation scans comments for this exact upstream
# protocol token.  Do not replace it with a project-specific marker.
MARKER = "<ghidradec_select>"
NATIVE_MESSAGE = "//Decompiler native message:"


def fail(message, code):
    print("[ghidradec-export] FAIL: " + message)
    ida_pro.qexit(code)


def sha256(path):
    digest = hashlib.sha256()
    with open(path, "rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def parse_targets(value):
    if not value:
        return []
    try:
        return [int(item.strip(), 0) for item in value.split(",") if item.strip()]
    except ValueError:
        fail("GHIDRADEC_EXPORT_TARGETS has a non-integer address", 2)


def main():
    ida_auto.auto_wait()
    export_dir_text = os.environ.get("GHIDRADEC_EXPORT_DIR", "").strip()
    input_path = os.environ.get("GHIDRADEC_TEST_INPUT_PATH", "").strip()
    expected_processor = os.environ.get("GHIDRADEC_EXPECTED_PROCESSOR", "").strip()
    expected_endian = os.environ.get("GHIDRADEC_EXPECTED_ENDIAN", "big").strip().lower()
    if not export_dir_text or not input_path or not expected_processor:
        fail("GHIDRADEC_EXPORT_DIR, GHIDRADEC_TEST_INPUT_PATH, and GHIDRADEC_EXPECTED_PROCESSOR are required", 2)
    if not os.path.isfile(input_path):
        fail("input binary is missing: " + input_path, 2)
    actual_processor = ida_ida.inf_get_procname()
    if actual_processor != expected_processor:
        fail("unexpected processor: " + actual_processor, 3)
    is_be = bool(ida_ida.inf_is_be())
    if is_be != (expected_endian == "big"):
        fail("unexpected endianness", 3)
    ida_nalt.set_root_filename(input_path)

    targets = parse_targets(os.environ.get("GHIDRADEC_EXPORT_TARGETS", ""))
    if targets:
        functions = []
        for target in targets:
            function = ida_funcs.get_func(target)
            if function is None or function.start_ea != target:
                fail("target is not a function start: 0x{:x}".format(target), 3)
            functions.append(function)
    else:
        start_index = int(os.environ.get("GHIDRADEC_EXPORT_START_INDEX", "0"), 0)
        max_functions = int(os.environ.get("GHIDRADEC_EXPORT_MAX_FUNCTIONS", "0"), 0)
        quantity = ida_funcs.get_func_qty()
        if start_index < 0 or start_index >= quantity:
            fail("start index is outside the IDA function list", 3)
        end_index = quantity if max_functions == 0 else min(quantity, start_index + max_functions)
        functions = [ida_funcs.getn_func(index) for index in range(start_index, end_index)]
        functions = [function for function in functions if function is not None]

    export_dir = Path(export_dir_text)
    export_dir.mkdir(parents=True, exist_ok=True)
    records_path = export_dir / ("slice-{:08x}-{:08x}.jsonl".format(
        functions[0].start_ea, functions[-1].start_ea))
    run_path = export_dir / ("slice-{:08x}-{:08x}.json".format(
        functions[0].start_ea, functions[-1].start_ea))
    run = {
        "schema": 1,
        "scope": "global headless GhidraDec export from copied IDA database; decompiler output is a hypothesis",
        "input_path": input_path,
        "input_sha256": sha256(input_path),
        "ida_processor": expected_processor,
        "ida_big_endian": is_be,
        "requested_function_count": len(functions),
        "records": records_path.name,
    }
    os.environ["GHIDRADEC_TEST_LIVE_CALLBACKS"] = "1"
    records = []
    for index, function in enumerate(functions):
        start = function.start_ea
        end = function.end_ea
        output_path = export_dir / ("{:08X}.c".format(start))
        if output_path.exists():
            record = {
                "ida_function_index": index,
                "start_ea": "0x{:x}".format(start),
                "end_ea": "0x{:x}".format(end),
                "size_bytes": end - start,
                "name": ida_name.get_name(start),
                "status": "skipped_existing_output",
                "c_output": output_path.name,
                "c_output_sha256": sha256(output_path),
            }
            records.append(record)
            with records_path.open("a", encoding="utf-8") as stream:
                stream.write(json.dumps(record, ensure_ascii=False, sort_keys=True) + "\n")
            continue
        old_comment = ida_funcs.get_func_cmt(function, False) or ""
        marker_comment = old_comment + ("\n" if old_comment else "") + MARKER
        record = {
            "ida_function_index": index,
            "start_ea": "0x{:x}".format(start),
            "end_ea": "0x{:x}".format(end),
            "size_bytes": end - start,
                "name": ida_name.get_name(start),
            "c_output": output_path.name,
        }
        if not ida_funcs.set_func_cmt(function, marker_comment, False):
            record["status"] = "could_not_mark_function"
            records.append(record)
            continue
        try:
            os.environ["GHIDRADEC_BATCH_OUTPUT"] = str(output_path)
            loaded = False
            for plugin_name in ("ghidradec", "ghidradec64"):
                if ida_loader.load_and_run_plugin(plugin_name, 4):
                    loaded = True
                    break
            if not loaded:
                record["status"] = "plugin_load_failed"
            elif not output_path.is_file() or output_path.stat().st_size == 0:
                record["status"] = "no_output"
            else:
                contents = output_path.read_text(encoding="utf-8", errors="replace")
                record["c_output_sha256"] = sha256(output_path)
                record["c_output_size_bytes"] = output_path.stat().st_size
                record["status"] = "plugin_error_output" if contents.lstrip().startswith(
                    ("//Error decompiling function:", NATIVE_MESSAGE)) else "success"
        except Exception as exc:
            record["status"] = "runner_exception"
            record["exception"] = repr(exc)
        finally:
            ida_funcs.set_func_cmt(function, old_comment, False)
        records.append(record)
        with records_path.open("a", encoding="utf-8") as stream:
            stream.write(json.dumps(record, ensure_ascii=False, sort_keys=True) + "\n")
        print("[ghidradec-export] {} {}".format(record["start_ea"], record["status"]))
    run["completed_records"] = len(records)
    run["status_counts"] = {status: sum(1 for item in records if item["status"] == status)
                            for status in sorted({item["status"] for item in records})}
    run_path.write_text(json.dumps(run, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print("[ghidradec-export] completed {} functions".format(len(records)))
    ida_pro.qexit(0)


if __name__ == "__main__":
    main()
