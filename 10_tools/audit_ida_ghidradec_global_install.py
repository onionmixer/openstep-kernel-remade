"""Record and verify the globally installed headless GhidraDec capability.

The global plugin itself is outside this project, while probe databases and
outputs remain isolated under /tmp until this script copies evidence here.
No kernel reference source is read.
"""
import hashlib
import json
import shutil
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / "09_validation/reports/multiarch-input-20260921/ghidradec-global-install-20260922"
IDA_ROOT = Path("/mnt/USERS/onion/DATA_ORIGN/local/ida-pro-9.3")
PLUGIN = IDA_ROOT / "plugins/ghidradec64.so"
WRAPPER = IDA_ROOT / "idat-ghidradec"
CACHED_PLUGIN = ROOT / "10_tools/vendor-cache/ghidradec64-ida93-linux-ea64-42d7343debf731ca749e09f6e7c010eff94230c194928509e56bcc46f3e9fea2.so"
EXPECTED_PLUGIN_SHA256 = "42d7343debf731ca749e09f6e7c010eff94230c194928509e56bcc46f3e9fea2"
EXPECTED_WRAPPER_SHA256 = "fe0bdbd769594603cd8cdc2ff047be77a0bb6cdab229ba4b24117b3e37c9afba"
TARGETS = {
    "m68k": {
        "stage": Path("/tmp/ghidradec-global-m68k-retry"),
        "original": ROOT / "03_original/m68k/binaries/mach_kernel",
        "expected_original_sha256": "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75",
        "ida_processor": "68K",
        "ghidra_language": "68040.sla",
        "target_ea": "0x40013d6",
    },
    "sparc": {
        "stage": Path("/tmp/ghidradec-global-sparc-retry"),
        "original": ROOT / "03_original/sparc/binaries/mach_kernel",
        "expected_original_sha256": "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1",
        "ida_processor": "sparcb",
        "ghidra_language": "SparcV9_32.sla",
        "target_ea": "0xf0003144",
    },
}


def sha256(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def require(condition, message):
    if not condition:
        raise RuntimeError(message)


def has_runpath(path):
    dynamic = subprocess.run(
        ["readelf", "-d", str(path)], check=True, text=True,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    ).stdout
    return "(RPATH)" in dynamic or "(RUNPATH)" in dynamic


def observe(architecture, target):
    stage = target["stage"]
    raw = stage / "mach_kernel"
    protocol = stage / "protocol.log"
    output = stage / "output.c"
    for path in (raw, protocol, output):
        require(path.is_file(), architecture + " missing probe evidence: " + str(path))
    text = protocol.read_text(encoding="utf-8", errors="replace")
    for marker in ('command("decompileAt"', "queryresponse(command_getcomments)", "doDecompile response bytes="):
        require(marker in text, architecture + " protocol lacks " + marker)
    require("decompileAt timed out" not in text, architecture + " protocol contains a timeout")
    report_protocol = REPORT / (architecture + "-protocol.log")
    report_output = REPORT / (architecture + ".c")
    shutil.copy2(protocol, report_protocol)
    shutil.copy2(output, report_output)
    raw_sha256 = sha256(raw)
    require(raw_sha256 == target["expected_original_sha256"], architecture + " staged original hash mismatch")
    return {
        "ida_processor": target["ida_processor"],
        "ida_big_endian": True,
        "ghidra_language": target["ghidra_language"],
        "target_ea": target["target_ea"],
        "original_sha256": sha256(target["original"]),
        "staged_original_sha256": raw_sha256,
        "comments_response_observed": True,
        "decompile_response_observed": True,
        "timeout_observed": False,
        "c_output": report_output.name,
        "c_output_size_bytes": report_output.stat().st_size,
        "c_output_sha256": sha256(report_output),
        "protocol_log": report_protocol.name,
        "protocol_log_sha256": sha256(report_protocol),
    }


def main():
    REPORT.mkdir(parents=True, exist_ok=True)
    require(PLUGIN.is_file(), "global plugin is missing")
    require(WRAPPER.is_file(), "global wrapper is missing")
    require(CACHED_PLUGIN.is_file(), "durable plugin artifact is missing")
    require(sha256(PLUGIN) == EXPECTED_PLUGIN_SHA256, "global plugin hash mismatch")
    require(sha256(CACHED_PLUGIN) == EXPECTED_PLUGIN_SHA256, "durable plugin hash mismatch")
    require(not has_runpath(PLUGIN), "global plugin has RPATH/RUNPATH")
    require(not has_runpath(CACHED_PLUGIN), "durable plugin has RPATH/RUNPATH")
    require(sha256(WRAPPER) == EXPECTED_WRAPPER_SHA256, "global wrapper hash mismatch")
    wrapper_text = WRAPPER.read_text(encoding="utf-8")
    require("GHIDRADEC_GHIDRA_DIR=/home/onion/ghidra_12.1_PUBLIC" in wrapper_text, "wrapper lacks GhidraDec path")
    require("GHIDRA_INSTALL_DIR=/home/onion/ghidra_12.1_PUBLIC" in wrapper_text, "wrapper lacks Ghidra path")
    observations = {architecture: observe(architecture, target) for architecture, target in TARGETS.items()}
    for architecture, target in TARGETS.items():
        require(observations[architecture]["original_sha256"] == target["expected_original_sha256"], architecture + " original hash mismatch")
    result = {
        "schema": 1,
        "scope": "global IDA plugin installation and isolated headless probes; not kernel behavior evidence",
        "global_installation": {
            "ida_root": str(IDA_ROOT),
            "plugin": str(PLUGIN),
            "plugin_sha256": sha256(PLUGIN),
            "plugin_has_rpath_or_runpath": False,
            "durable_plugin_artifact": str(CACHED_PLUGIN.relative_to(ROOT)),
            "durable_plugin_artifact_sha256": sha256(CACHED_PLUGIN),
            "durable_plugin_artifact_has_rpath_or_runpath": False,
            "wrapper": str(WRAPPER),
            "wrapper_sha256": sha256(WRAPPER),
            "ghidra_root": "/home/onion/ghidra_12.1_PUBLIC",
        },
        "headless_mode": {
            "required_environment": ["GHIDRADEC_BATCH_OUTPUT", "GHIDRADEC_TEST_INPUT_PATH", "GHIDRADEC_TEST_TARGET_EA"],
            "verified_callback_mode": "GHIDRADEC_TEST_LIVE_CALLBACKS=1",
            "durable_smoke_script": "10_tools/ida_ghidradec_headless_smoke.py",
        },
        "architectures": observations,
        "decision": {
            "global_headless_install_verified": True,
            "decompiler_output_is_kernel_evidence": False,
        },
    }
    (REPORT / "assessment.json").write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"global_headless_install_verified": True, "architectures": sorted(observations)}, ensure_ascii=False))


if __name__ == "__main__":
    main()
