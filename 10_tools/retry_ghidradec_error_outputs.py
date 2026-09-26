"""Retry only persisted GhidraDec C-error outputs on fresh copied inputs.

Fatal plugin failures are intentionally excluded: the prior corpus proved they
already crash in a fresh copied database with one selected function.  Each
retry here is a single candidate in a new copied big-endian IDA database.  The
underlying runner owns a separate process group and terminates it on timeout.
This records tool reproducibility; emitted C remains a hypothesis.
"""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import sys


ROOT = Path(__file__).resolve().parents[1]
FAILURES = ROOT / "09_validation/reports/multiarch-input-20260921/ghidradec-live-callback-failure-asm-coverage-20260923.json"
RUNNER = ROOT / "10_tools/run_ghidradec_live_function_slices.py"
RUN_DATE = "20260923"


def sha256(path):
    digest = hashlib.sha256()
    with Path(path).open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def write_json(path, value):
    path.write_text(json.dumps(value, ensure_ascii=False, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--arch", choices=("m68k", "sparc"), action="append")
    parser.add_argument("--timeout-seconds", type=int, default=120)
    parser.add_argument("--max-attempts", type=int, default=0, help="0 means every persisted C-error output")
    return parser.parse_args()


def main():
    args = parse_args()
    if args.timeout_seconds <= 0 or args.max_attempts < 0:
        raise SystemExit("timeout must be positive and max attempts cannot be negative")
    source = json.loads(FAILURES.read_text(encoding="utf-8"))
    selected_arches = args.arch or ("m68k", "sparc")
    report = ROOT / "09_validation/reports/multiarch-input-20260921/ghidradec-error-output-retry-{}".format(RUN_DATE)
    report = report.with_suffix(".json")
    source_hash = sha256(FAILURES)
    result = {
        "schema": 1,
        "scope": "one fresh-copied-big-endian-IDA retry per existing GhidraDec C-error output; excludes already-single-candidate SIGSEGV failures",
        "source_failure_audit": str(FAILURES.relative_to(ROOT)),
        "source_failure_audit_sha256_recomputed_with_python": source_hash,
        "architectures": {},
        "interpretation_limit": "A retry result characterizes this plugin path only. Valid C remains a decompiler hypothesis and does not establish original behavior, ABI, reachability, or function boundaries.",
    }
    if report.is_file():
        existing = json.loads(report.read_text(encoding="utf-8"))
        if existing.get("source_failure_audit_sha256_recomputed_with_python") != source_hash:
            raise RuntimeError("existing retry report uses a different source failure audit")
        result["architectures"].update(existing.get("architectures", {}))
    all_complete = True
    for arch in selected_arches:
        index_path = ROOT / "05_ida/exports" / arch / "function-asm-index.json"
        candidates = json.loads(index_path.read_text(encoding="utf-8"))
        candidate_indices = {int(row["start"], 16): index for index, row in enumerate(candidates)}
        failures = [row for row in source[arch]["failures"] if row["kind"] == "decompiler_error_output"]
        if args.max_attempts:
            failures = failures[:args.max_attempts]
        output_dir = ROOT / "05_ida/exports" / arch / ("ghidradec-functions-live-callback-retry-" + RUN_DATE)
        output_dir.mkdir(parents=True, exist_ok=True)
        attempts = []
        for failure in failures:
            address = failure["address"]
            if address not in candidate_indices:
                raise RuntimeError("failure address is absent from candidate index: {}".format(hex(address)))
            index = candidate_indices[address]
            command = [
                sys.executable, str(RUNNER), "--arch", arch,
                "--slice-size", "1",
                "--start-index", str(index),
                "--max-functions", "1",
                "--timeout-seconds", str(args.timeout_seconds),
                "--output-dir", str(output_dir),
                "--continue-on-failure",
            ]
            completed = subprocess.run(command, cwd=ROOT, text=True, capture_output=True)
            status_path = output_dir / "slices" / ("slice-{:05d}-{:05d}.json".format(index, index + 1))
            row = {
                "address": address,
                "address_hex": "0x{:x}".format(address),
                "candidate_index": index,
                "runner_return_code": completed.returncode,
                "runner_stdout_sha256_recomputed_with_python": hashlib.sha256(completed.stdout.encode("utf-8", "replace")).hexdigest(),
                "runner_stderr_sha256_recomputed_with_python": hashlib.sha256(completed.stderr.encode("utf-8", "replace")).hexdigest(),
                "slice_status_path": str(status_path.relative_to(ROOT)),
                "slice_status_present": status_path.is_file(),
            }
            if status_path.is_file():
                status = json.loads(status_path.read_text(encoding="utf-8"))
                row["execution_completed"] = status["execution_completed"]
                row["timeout"] = status["timeout"]
                row["return_code"] = status["return_code"]
                row["fatal_failure_reason"] = status["fatal_failure_reason"]
                row["decompiler_error_outputs"] = status["decompiler_error_outputs"]
                row["timeout_terminated_isolated_process_group"] = status.get("timeout_terminated_isolated_process_group", False)
                row["persistent_records"] = status["persistent_records"]
            else:
                row["execution_completed"] = False
                row["timeout"] = False
                row["return_code"] = None
                row["fatal_failure_reason"] = "runner_did_not_write_slice_status"
                row["decompiler_error_outputs"] = []
                row["timeout_terminated_isolated_process_group"] = False
                row["persistent_records"] = []
            attempts.append(row)
        complete = all(row["slice_status_present"] for row in attempts)
        all_complete = all_complete and complete
        result["architectures"][arch] = {
            "candidate_index_sha256_recomputed_with_python": sha256(index_path),
            "persisted_c_error_count_recomputed_with_python": len([row for row in source[arch]["failures"] if row["kind"] == "decompiler_error_output"]),
            "attempted_c_error_count_recomputed_with_python": len(attempts),
            "all_attempts_wrote_status": complete,
            "attempts": attempts,
        }
    result["all_requested_attempts_wrote_status"] = all_complete
    write_json(report, result)
    print(json.dumps({"output": str(report.relative_to(ROOT)), "all_requested_attempts_wrote_status": all_complete}, sort_keys=True))
    return 0 if all_complete else 1


if __name__ == "__main__":
    sys.exit(main())
