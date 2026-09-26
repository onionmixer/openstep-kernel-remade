"""Persist isolated successful GhidraDec runtime evidence.

This tool copies results from disposable /tmp databases.  It validates original
kernel hashes, selected big-endian targets, the RPATH-free candidate plugin,
and protocol completion before creating a report.  It does not read reference
source or write the IDA installation.
"""
import hashlib
import json
import shutil
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / "09_validation/reports/multiarch-input-20260921/ghidradec-candidate-followup-20260922"
PLUGIN = Path("/tmp/ghidradec-assessment/build/ida93-linux-ea64/ghidradec64.so")
GHIDRADEC = Path("/tmp/ghidradec-assessment")
IDA_SDK = Path("/tmp/idasdk93-assessment")
VENDOR_CACHE = ROOT / "10_tools/vendor-cache"
TARGETS = {
    "m68k": {
        "original": ROOT / "03_original/m68k/binaries/mach_kernel",
        "database": ROOT / "05_ida/databases/m68k-os42j.i64",
        "expected_original_sha256": "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75",
        "ida_processor": "68K",
        "ghidra_language": "68040.sla",
        "target_ea": "0x40013d6",
        "target_name": "_pflush_super",
        "target_size_bytes": 30,
    },
    "sparc": {
        "original": ROOT / "03_original/sparc/binaries/mach_kernel",
        "database": ROOT / "05_ida/databases/sparc-os42j.i64",
        "expected_original_sha256": "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1",
        "ida_processor": "sparcb",
        "ghidra_language": "SparcV9_32.sla",
        "target_ea": "0xf0003144",
        "target_name": "_return_with_state",
        "target_size_bytes": 44,
    },
}
MODES = {
    "batch": {
        "environment": "GHIDRADEC_BATCH_OUTPUT=<temporary output path>",
        "purpose": "Avoid the batch UI-dispatch deadlock while retaining the protocol comment response.",
    },
    "live": {
        "environment": "GHIDRADEC_TEST_LIVE_CALLBACKS=1",
        "purpose": "Exercise direct IDA API callbacks, including comments, without skipping them.",
    },
}


def sha256(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def git_value(path, args):
    return subprocess.run(
        ["git", "-C", str(path), *args], check=True, text=True,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    ).stdout.strip()


def has_runpath(binary):
    output = subprocess.run(
        ["readelf", "-d", str(binary)], check=True, text=True,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    ).stdout
    return "(RUNPATH)" in output or "(RPATH)" in output


def require(condition, message):
    if not condition:
        raise RuntimeError(message)


def observe(architecture, target, mode):
    stage = Path("/tmp/ghidradec-runtime-%s-%s" % (architecture, mode))
    staged_original = stage / "mach_kernel"
    staged_database = stage / "kernel.i64"
    staged_plugin = stage / "idausr/plugins/ghidradec64.so"
    protocol = stage / "ghidradec-protocol.log"
    output = stage / "mach_kernel.c"
    for path in (staged_original, staged_database, staged_plugin, protocol, output):
        require(path.is_file(), "%s/%s missing runtime evidence: %s" % (architecture, mode, path))
    protocol_text = protocol.read_text(encoding="utf-8", errors="replace")
    require('command("decompileAt"' in protocol_text, "%s/%s lacks decompile request" % (architecture, mode))
    require("query(command_getcomments" in protocol_text, "%s/%s lacks comments query" % (architecture, mode))
    require("queryresponse(command_getcomments)" in protocol_text, "%s/%s lacks comments response" % (architecture, mode))
    require("doDecompile response bytes=" in protocol_text, "%s/%s lacks decompile response" % (architecture, mode))
    require("decompileAt timed out" not in protocol_text, "%s/%s contains timeout" % (architecture, mode))
    report_protocol = REPORT / (architecture + "-" + mode + "-protocol.log")
    report_output = REPORT / (architecture + "-" + mode + ".c")
    shutil.copy2(protocol, report_protocol)
    shutil.copy2(output, report_output)
    return {
        "temporary_stage": str(stage),
        "staged_original_sha256": sha256(staged_original),
        "staged_working_database_sha256": sha256(staged_database),
        "staged_plugin_sha256": sha256(staged_plugin),
        "comments_query_observed": True,
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
    require(PLUGIN.is_file(), "candidate plugin is missing")
    require(not has_runpath(PLUGIN), "candidate plugin has RPATH/RUNPATH")
    results = {}
    for architecture, target in TARGETS.items():
        original_sha256 = sha256(target["original"])
        require(original_sha256 == target["expected_original_sha256"], architecture + " original hash mismatch")
        results[architecture] = {
            "ida_processor": target["ida_processor"],
            "ida_big_endian": True,
            "ghidra_language": target["ghidra_language"],
            "selected_target": {
                "ea": target["target_ea"], "name": target["target_name"],
                "size_bytes": target["target_size_bytes"],
            },
            "original_sha256": original_sha256,
            "canonical_database_sha256_before_test": sha256(target["database"]),
            "modes": {mode: observe(architecture, target, mode) for mode in MODES},
        }
        for mode in MODES:
            require(results[architecture]["modes"][mode]["staged_original_sha256"] == original_sha256,
                    architecture + "/" + mode + " staged original mismatch")
            require(results[architecture]["modes"][mode]["staged_plugin_sha256"] == sha256(PLUGIN),
                    architecture + "/" + mode + " staged plugin mismatch")
    result = {
        "schema": 1,
        "scope": "isolated IDA/GhidraDec candidate runtime validation; not original-kernel behavior evidence",
        "candidate": {
            "name": "GhidraDec",
            "source_commit": git_value(GHIDRADEC, ["rev-parse", "HEAD"]),
            "ida_sdk_commit": git_value(IDA_SDK, ["rev-parse", "HEAD"]),
            "plugin_sha256": sha256(PLUGIN),
            "plugin_has_rpath_or_runpath": False,
            "persistent_source_bundles": {
                "ghidradec": sha256(VENDOR_CACHE / "GhidraDec-35afec3d588407de8e2aae5330f26dea857c26bd.bundle"),
                "ida_sdk": sha256(VENDOR_CACHE / "ida-sdk-v9.3-d5db59ab4e9d2ae92038e9520082affd0da6fe20.bundle"),
            },
        },
        "test_modes": MODES,
        "architectures": results,
        "decision": {
            "candidate_core_runtime_verified": True,
            "eligible_for_global_ida_install": False,
            "reason": "Both big-endian targets completed only in explicit regression modes. A normal GUI invocation was inconclusive and must pass before deployment.",
            "next_step": "Perform and preserve a successful ordinary GUI selective-decompilation test for m68k and SPARC before installing the plugin globally.",
        },
        "interpretation_limit": "Decompiler output is a tool hypothesis. Validate any kernel claim against original bytes, and do not use this report as evidence of function boundaries, code/data classification, ABI, or behavior.",
    }
    (REPORT / "assessment.json").write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"candidate_core_runtime_verified": True, "architectures": sorted(results)}, ensure_ascii=False))


if __name__ == "__main__":
    main()
