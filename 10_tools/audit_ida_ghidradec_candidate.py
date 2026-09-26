"""Preserve a reproducible GhidraDec candidate assessment from isolated IDA runs.

This script records only tool/build observations.  It copies the runtime logs from
temporary working directories into the validation report before /tmp is cleaned.
It never reads a reference kernel source tree or writes an IDA installation.
"""
import hashlib
import json
import re
import shutil
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / "09_validation/reports/multiarch-input-20260921/ghidradec-candidate-20260922"
GHIDRADEC = Path("/tmp/ghidradec-assessment")
IDA_SDK = Path("/tmp/idasdk93-assessment")
PLUGIN = GHIDRADEC / "build/ida93-linux-ea64/ghidradec64.so"
IDA_ROOT = Path("/mnt/USERS/onion/DATA_ORIGN/local/ida-pro-9.3")
GHIDRA_ROOT = Path("/home/onion/ghidra_12.1_PUBLIC")
VENDOR_CACHE = ROOT / "10_tools/vendor-cache"
GHIDRADEC_BUNDLE = VENDOR_CACHE / "GhidraDec-35afec3d588407de8e2aae5330f26dea857c26bd.bundle"
IDA_SDK_BUNDLE = VENDOR_CACHE / "ida-sdk-v9.3-d5db59ab4e9d2ae92038e9520082affd0da6fe20.bundle"
TARGETS = {
    "m68k": {
        "stage": Path("/tmp/ghidradec-runtime-m68k"),
        "database": "m68k-os42j-ghidradec-test.i64",
        "original": ROOT / "03_original/m68k/binaries/mach_kernel",
        "expected_original_sha256": "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75",
        "ida_processor": "68K",
        "ghidra_marker": "Processors/68000/data/languages/68040.sla",
    },
    "sparc": {
        "stage": Path("/tmp/ghidradec-runtime-sparc"),
        "database": "sparc-os42j-ghidradec-test.i64",
        "original": ROOT / "03_original/sparc/binaries/mach_kernel",
        "expected_original_sha256": "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1",
        "ida_processor": "sparcb",
        "ghidra_marker": "Processors/Sparc/data/languages/SparcV9_32.sla",
    },
}


def sha256(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def git_value(path, args):
    return subprocess.run(
        ["git", "-C", str(path), *args], check=True, text=True,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    ).stdout.strip()


def has_runpath(binary):
    dynamic = subprocess.run(
        ["readelf", "-d", str(binary)], check=True, text=True,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    ).stdout
    return "(RUNPATH)" in dynamic or "(RPATH)" in dynamic


def require(text, needle, name):
    if needle not in text:
        raise RuntimeError("%s lacks required observation: %s" % (name, needle))


def runtime_observation(architecture, target):
    stage = target["stage"]
    log = stage / "ida.log"
    protocol = stage / "ghidradec-protocol.log"
    staged_original = stage / "mach_kernel"
    staged_database = stage / target["database"]
    output = stage / "mach_kernel.c"
    for path in (log, protocol, staged_original, staged_database):
        if not path.is_file():
            raise RuntimeError("missing temporary %s evidence: %s" % (architecture, path))
    log_text = log.read_text(encoding="utf-8", errors="replace")
    for needle in (
        "Ghidra Decompiler Plugin version 1.0 registered OK",
        "Ghidra Decompiler Plugin version 1.0 loaded OK",
        "Detected Processor spec:",
        target["ghidra_marker"],
        "Caught decompilation error: process timeout",
    ):
        require(log_text, needle, architecture)
    report_log = REPORT / (architecture + "-runtime.log")
    report_protocol = REPORT / (architecture + "-protocol.log")
    shutil.copy2(log, report_log)
    shutil.copy2(protocol, report_protocol)
    return {
        "ida_processor": target["ida_processor"],
        "ida_big_endian": True,
        "original_sha256": sha256(target["original"]),
        "staged_original_sha256": sha256(staged_original),
        "staged_working_database_sha256": sha256(staged_database),
        "plugin_registered": True,
        "plugin_loaded": True,
        "detected_ghidra_language_marker": target["ghidra_marker"],
        "decompiler_timeout_observed": True,
        "c_output_created": output.exists(),
        "runtime_test_exit_code": 6,
        "runtime_log": report_log.name,
        "runtime_log_sha256": sha256(report_log),
        "protocol_log": report_protocol.name,
        "protocol_log_sha256": sha256(report_protocol),
    }


def main():
    REPORT.mkdir(parents=True, exist_ok=True)
    if not PLUGIN.is_file():
        raise RuntimeError("built candidate plugin is missing")
    for bundle in (GHIDRADEC_BUNDLE, IDA_SDK_BUNDLE):
        if not bundle.is_file():
            raise RuntimeError("missing persistent source bundle: %s" % bundle)
    observations = {name: runtime_observation(name, target) for name, target in TARGETS.items()}
    for name, target in TARGETS.items():
        if observations[name]["original_sha256"] != target["expected_original_sha256"]:
            raise RuntimeError("original hash mismatch for %s" % name)
        if observations[name]["staged_original_sha256"] != target["expected_original_sha256"]:
            raise RuntimeError("staged original hash mismatch for %s" % name)
        if observations[name]["c_output_created"]:
            raise RuntimeError("unexpected output presence requires manual review for %s" % name)
    result = {
        "schema": 1,
        "scope": "isolated candidate build and runtime probe; not a kernel behavior finding",
        "candidate": {
            "name": "GhidraDec",
            "source_commit": git_value(GHIDRADEC, ["rev-parse", "HEAD"]),
            "source_worktree_clean": git_value(GHIDRADEC, ["status", "--porcelain=v1"]) == "",
            "ida_sdk_commit": git_value(IDA_SDK, ["rev-parse", "HEAD"]),
            "ida_sdk_worktree_clean": git_value(IDA_SDK, ["status", "--porcelain=v1"]) == "",
            "built_plugin_filename": PLUGIN.name,
            "built_plugin_sha256": sha256(PLUGIN),
            "built_plugin_has_rpath_or_runpath": has_runpath(PLUGIN),
            "ida_installation": str(IDA_ROOT),
            "ghidra_installation": str(GHIDRA_ROOT),
            "persistent_source_bundles": {
                "ghidradec": {
                    "path": str(GHIDRADEC_BUNDLE.relative_to(ROOT)),
                    "sha256": sha256(GHIDRADEC_BUNDLE),
                },
                "ida_sdk": {
                    "path": str(IDA_SDK_BUNDLE.relative_to(ROOT)),
                    "sha256": sha256(IDA_SDK_BUNDLE),
                },
            },
        },
        "runtime_targets": observations,
        "decision": {
            "eligible_for_global_ida_install": False,
            "reason": (
                "The candidate loads and selects both expected big-endian Ghidra languages, but neither "
                "isolated runtime test produced C output and both ended in a native-decompiler process timeout."),
            "next_step": (
                "Resolve and independently retest the Linux native-decompiler transport timeout before preserving "
                "or deploying a plugin binary. Do not treat current decompiler output as kernel evidence."),
        },
        "interpretation_limit": (
            "The timeout establishes failure of this exact local candidate build and test path, not the root cause, "
            "all GhidraDec versions, all operating systems, or Ghidra's standalone decompiler correctness. "
            "Function boundaries and architecture semantics remain analysis-tool hypotheses subject to original-byte checks."),
    }
    if result["candidate"]["built_plugin_has_rpath_or_runpath"]:
        raise RuntimeError("candidate plugin retains a nonportable RPATH/RUNPATH")
    (REPORT / "assessment.json").write_text(
        json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"eligible_for_global_ida_install": False,
                      "architectures": sorted(observations)}, ensure_ascii=False))


if __name__ == "__main__":
    main()
