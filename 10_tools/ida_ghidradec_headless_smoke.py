"""Run one explicit GhidraDec selective-decompilation probe in IDA headless mode.

Use only a copied database.  The selected function address and output path must
be supplied through environment variables.  This is a tool-capability probe;
its C output is not original-kernel evidence.
"""
import os

import ida_auto
import ida_funcs
import ida_loader
import ida_name
import ida_nalt
import ida_pro


MARKER = "<ghidradec_select>"


def fail(message, code):
    print("[ghidradec-headless] FAIL: " + message)
    ida_pro.qexit(code)


def main():
    ida_auto.auto_wait()
    target_text = os.environ.get("GHIDRADEC_TEST_TARGET_EA", "").strip()
    output_path = os.environ.get("GHIDRADEC_BATCH_OUTPUT", "").strip()
    input_path = os.environ.get("GHIDRADEC_TEST_INPUT_PATH", "").strip()
    if not target_text or not output_path or not input_path:
        fail("GHIDRADEC_TEST_TARGET_EA, GHIDRADEC_BATCH_OUTPUT, and GHIDRADEC_TEST_INPUT_PATH are required", 2)
    if not os.path.isfile(input_path):
        fail("GHIDRADEC_TEST_INPUT_PATH does not exist: " + input_path, 2)
    ida_nalt.set_root_filename(input_path)
    try:
        target_ea = int(target_text, 0)
    except ValueError:
        fail("GHIDRADEC_TEST_TARGET_EA is not an integer: " + target_text, 2)
    function = ida_funcs.get_func(target_ea)
    if function is None or function.start_ea != target_ea:
        fail("target is not a function start: 0x{:x}".format(target_ea), 3)
    if os.path.exists(output_path):
        os.remove(output_path)
    old_comment = ida_funcs.get_func_cmt(function, False) or ""
    marker_comment = old_comment + ("\n" if old_comment else "") + MARKER
    if not ida_funcs.set_func_cmt(function, marker_comment, False):
        fail("could not mark target function", 4)
    try:
        loaded = False
        for plugin_name in ("ghidradec", "ghidradec64"):
            if ida_loader.load_and_run_plugin(plugin_name, 4):
                loaded = True
                break
        if not loaded:
            fail("could not load global ghidradec plugin", 5)
    finally:
        ida_funcs.set_func_cmt(function, old_comment, False)
    if not os.path.isfile(output_path) or os.path.getsize(output_path) == 0:
        fail("plugin did not produce output: " + output_path, 6)
    print("[ghidradec-headless] PASS: {} at 0x{:x}; {} bytes".format(
        ida_name.get_name(function.start_ea), function.start_ea, os.path.getsize(output_path)))
    ida_pro.qexit(0)


if __name__ == "__main__":
    main()
