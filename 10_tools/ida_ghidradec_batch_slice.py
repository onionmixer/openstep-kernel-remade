"""Run one marked GhidraDec decompile-all slice from a copied IDA database.

The plugin emits ``GHIDRADEC_FUNCTION`` comments only when its locally built
headless batch extension is installed.  The generated C remains a decompiler
hypothesis; it is never byte evidence for the original kernel.
"""
import os

import ida_auto
import ida_ida
import ida_loader
import ida_nalt
import ida_pro


def fail(message, code):
    print("[ghidradec-batch-slice] FAIL: " + message)
    ida_pro.qexit(code)


def main():
    ida_auto.auto_wait()
    input_path = os.environ.get("GHIDRADEC_TEST_INPUT_PATH", "").strip()
    output_path = os.environ.get("GHIDRADEC_BATCH_OUTPUT", "").strip()
    expected_processor = os.environ.get("GHIDRADEC_EXPECTED_PROCESSOR", "").strip()
    expected_endian = os.environ.get("GHIDRADEC_EXPECTED_ENDIAN", "big").strip().lower()
    if not input_path or not output_path or not expected_processor:
        fail("input, output, expected processor, and expected endian are required", 2)
    if not os.path.isfile(input_path):
        fail("input binary is missing: " + input_path, 2)
    if ida_ida.inf_get_procname() != expected_processor:
        fail("unexpected processor: " + ida_ida.inf_get_procname(), 3)
    if bool(ida_ida.inf_is_be()) != (expected_endian == "big"):
        fail("unexpected endianness", 3)
    ida_nalt.set_root_filename(input_path)
    os.environ["GHIDRADEC_TEST_LIVE_CALLBACKS"] = "1"
    os.environ["GHIDRADEC_BATCH_FUNCTION_MARKERS"] = "1"
    loaded = False
    for plugin_name in ("ghidradec", "ghidradec64"):
        if ida_loader.load_and_run_plugin(plugin_name, 5):
            loaded = True
            break
    if not loaded:
        fail("could not load global ghidradec plugin", 4)
    if not os.path.isfile(output_path) or os.path.getsize(output_path) == 0:
        fail("plugin did not produce C output", 5)
    done_path = os.environ.get("GHIDRADEC_BATCH_DONE", "").strip()
    if not done_path or not os.path.isfile(done_path):
        fail("plugin did not produce a completion marker", 6)
    print("[ghidradec-batch-slice] PASS: " + output_path)
    ida_pro.qexit(0)


if __name__ == "__main__":
    main()
