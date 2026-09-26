"""Export GhidraDec C hypotheses through the validated live-callback path.

Every slice receives fresh copied IDA and kernel inputs in /tmp.  It never
opens a canonical database and treats any native decompiler message as an
error, even when a nonempty output file was emitted.
"""

import argparse
import fcntl
import hashlib
import json
import os
from pathlib import Path
import shutil
import signal
import subprocess
import sys
import time


ROOT = Path(__file__).resolve().parents[1]
ARCHITECTURES = {
    "m68k": {
        "database": ROOT / "05_ida/databases/m68k-os42j.i64",
        "binary": ROOT / "03_original/m68k/binaries/mach_kernel",
        "candidates": ROOT / "05_ida/exports/m68k/function-asm-index.json",
        "processor": "68K",
    },
    "sparc": {
        "database": ROOT / "05_ida/databases/sparc-os42j.i64",
        "binary": ROOT / "03_original/sparc/binaries/mach_kernel",
        "candidates": ROOT / "05_ida/exports/sparc/function-asm-index.json",
        "processor": "sparcb",
    },
}
NATIVE_MESSAGE = "//Decompiler native message:"


def sha256(path):
    digest = hashlib.sha256()
    with Path(path).open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def write_json(path, value):
    Path(path).write_text(json.dumps(value, ensure_ascii=False, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def copy_verified(source, destination):
    shutil.copy2(source, destination)
    source_hash = sha256(source)
    copied_hash = sha256(destination)
    if source_hash != copied_hash:
        raise RuntimeError("copied input SHA-256 mismatch: " + str(source))
    return source_hash


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--arch", required=True, choices=sorted(ARCHITECTURES))
    parser.add_argument("--slice-size", type=int, default=5)
    parser.add_argument("--start-index", type=int, default=0)
    parser.add_argument("--max-functions", type=int, default=0, help="0 means all remaining candidates")
    parser.add_argument("--skip-resolved", action="store_true",
                        help="skip candidates with a persistent record or a single-candidate fatal status")
    parser.add_argument("--timeout-seconds", type=int, default=600)
    parser.add_argument("--continue-on-failure", action="store_true")
    parser.add_argument("--keep-temporary", action="store_true",
                        help="retain per-slice /tmp copied inputs for a short-lived debugging session")
    parser.add_argument("--output-dir", type=Path)
    parser.add_argument("--temporary-root", type=Path, default=Path("/tmp/ghidradec-live-function-slices"))
    parser.add_argument("--ida-wrapper", type=Path,
                        default=Path("/mnt/USERS/onion/DATA_ORIGN/local/ida-pro-9.3/idat-ghidradec"))
    parser.add_argument("--plugin", type=Path,
                        default=Path("/mnt/USERS/onion/DATA_ORIGN/local/ida-pro-9.3/plugins/ghidradec64.so"))
    return parser.parse_args()


def copy_output(source, destination):
    destination.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(source, destination)
    if sha256(source) != sha256(destination):
        raise RuntimeError("persistent output SHA-256 mismatch: " + str(source))


def run_isolated(command, cwd, environment, timeout_seconds):
    """Run IDA in its own process group and clean up that complete group on timeout."""
    process = subprocess.Popen(
        command,
        cwd=cwd,
        env=environment,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        start_new_session=True,
    )
    try:
        stdout, stderr = process.communicate(timeout=timeout_seconds)
        return process.returncode, stdout, stderr, False, False
    except subprocess.TimeoutExpired:
        os.killpg(process.pid, signal.SIGTERM)
        try:
            stdout, stderr = process.communicate(timeout=15)
        except subprocess.TimeoutExpired:
            os.killpg(process.pid, signal.SIGKILL)
            stdout, stderr = process.communicate()
        return process.returncode, stdout or "", stderr or "", True, True


def main():
    args = parse_args()
    if args.slice_size <= 0 or args.timeout_seconds <= 0 or args.start_index < 0 or args.max_functions < 0:
        raise SystemExit("slice size and timeout must be positive; indexes must be non-negative")
    config = ARCHITECTURES[args.arch]
    for path in (config["database"], config["binary"], config["candidates"], args.ida_wrapper, args.plugin):
        if not path.is_file():
            raise SystemExit("required file is missing: " + str(path))
    candidates = json.loads(config["candidates"].read_text(encoding="utf-8"))
    if not isinstance(candidates, list) or not candidates:
        raise SystemExit("candidate index must be a non-empty JSON list")
    candidate_count = len(candidates)
    if args.start_index >= candidate_count:
        raise SystemExit("start index is outside candidate list")
    end_index = candidate_count if args.max_functions == 0 else min(candidate_count, args.start_index + args.max_functions)
    output_dir = (args.output_dir or ROOT / "05_ida/exports" / args.arch /
                  "ghidradec-functions-live-callback-20260922").resolve()
    function_dir = output_dir / "functions"
    error_dir = output_dir / "error-outputs"
    record_dir = output_dir / "function-records"
    slice_dir = output_dir / "slices"
    for directory in (function_dir, error_dir, record_dir, slice_dir):
        directory.mkdir(parents=True, exist_ok=True)
    lock_path = output_dir / ".runner.lock"
    lock_stream = lock_path.open("a", encoding="utf-8")
    try:
        fcntl.flock(lock_stream.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
    except BlockingIOError:
        raise SystemExit("another live-callback runner already owns: " + str(output_dir))
    temporary_root = args.temporary_root / args.arch
    temporary_root.mkdir(parents=True, exist_ok=True)
    failures = []
    decompiler_errors = []
    processed = []
    completed_slices = 0
    skipped_slices = []
    resolved_starts = set()
    if args.skip_resolved:
        for record_path in sorted(record_dir.glob("*.json")):
            record = json.loads(record_path.read_text(encoding="utf-8"))
            resolved_starts.add(record["start_ea"].lower())
        for status_path in sorted(slice_dir.glob("slice-*.json")):
            status = json.loads(status_path.read_text(encoding="utf-8"))
            starts = status.get("expected_candidate_starts", [])
            if (status.get("execution_completed") is False and len(starts) == 1 and
                    status.get("fatal_failure_reason") is not None):
                resolved_starts.add(starts[0].lower())
    for slice_start in range(args.start_index, end_index, args.slice_size):
        slice_end = min(end_index, slice_start + args.slice_size)
        key = "slice-{:05d}-{:05d}".format(slice_start, slice_end)
        selected = candidates[slice_start:slice_end]
        if args.skip_resolved:
            selected = [item for item in selected if item["start"].lower() not in resolved_starts]
        if not selected:
            skipped_slices.append(key)
            continue
        attempt = 0
        while (temporary_root / key / ("attempt-{:03d}".format(attempt))).exists():
            attempt += 1
        work = temporary_root / key / ("attempt-{:03d}".format(attempt))
        work.mkdir(parents=True, exist_ok=True)
        database = work / "kernel.i64"
        binary = work / "mach_kernel"
        export = work / "export"
        stdout_path = slice_dir / (key + ".stdout.log")
        stderr_path = slice_dir / (key + ".stderr.log")
        status_path = slice_dir / (key + ".json")
        database_hash = copy_verified(config["database"], database)
        binary_hash = copy_verified(config["binary"], binary)
        environment = os.environ.copy()
        environment.update({
            "GHIDRADEC_EXPORT_DIR": str(export),
            "GHIDRADEC_TEST_INPUT_PATH": str(binary),
            "GHIDRADEC_EXPECTED_PROCESSOR": config["processor"],
            "GHIDRADEC_EXPECTED_ENDIAN": "big",
            "GHIDRADEC_EXPORT_TARGETS": ",".join(item["start"] for item in selected),
            "GHIDRADEC_TEST_LIVE_CALLBACKS": "1",
        })
        command = [str(args.ida_wrapper), "-A", "-S10_tools/ida_ghidradec_export_functions.py", str(database)]
        started = time.monotonic()
        return_code, stdout, stderr, timed_out, terminated_process_group = run_isolated(
            command, ROOT, environment, args.timeout_seconds)
        elapsed = time.monotonic() - started
        stdout_path.write_text(stdout, encoding="utf-8", errors="replace")
        stderr_path.write_text(stderr, encoding="utf-8", errors="replace")
        expected_starts = [item["start"].lower() for item in selected]
        run_paths = sorted(export.glob("slice-*.json")) if export.is_dir() else []
        records = []
        fatal_problem = None
        if timed_out or return_code != 0:
            fatal_problem = "timeout" if timed_out else "nonzero_ida_exit"
        elif len(run_paths) != 1:
            fatal_problem = "missing_or_ambiguous_run_record"
        else:
            run = json.loads(run_paths[0].read_text(encoding="utf-8"))
            records_path = export / run["records"]
            if not records_path.is_file():
                fatal_problem = "missing_record_file"
            else:
                records = [json.loads(line) for line in records_path.read_text(encoding="utf-8").splitlines() if line]
                starts = [item["start_ea"].lower() for item in records]
                if starts != expected_starts:
                    fatal_problem = "recorded_starts_do_not_match_request"
                else:
                    for item in records:
                        c_path = export / item["c_output"]
                        if not c_path.is_file() or sha256(c_path) != item["c_output_sha256"]:
                            fatal_problem = "missing_or_hash_mismatched_c_output"
                            break
        completed = fatal_problem is None
        output_records = []
        slice_errors = []
        if completed:
            for item in records:
                start = int(item["start_ea"], 16)
                source_c = export / item["c_output"]
                c_text = source_c.read_text(encoding="utf-8", errors="replace")
                content_is_native_message = c_text.lstrip().startswith(NATIVE_MESSAGE)
                valid_c = item["status"] == "success" and not content_is_native_message
                destination_c = (function_dir if valid_c else error_dir) / ("{:08X}.c".format(start))
                copy_output(source_c, destination_c)
                item["architecture"] = args.arch
                item["slice"] = key
                item["content_validity"] = "valid_c_hypothesis" if valid_c else "plugin_error_output"
                item["c_output"] = str(destination_c.relative_to(output_dir))
                item["c_output_sha256"] = sha256(destination_c)
                destination_record = record_dir / ("{:08X}.json".format(start))
                write_json(destination_record, item)
                output_records.append(str(destination_record.relative_to(output_dir)))
                if valid_c:
                    processed.append(item["start_ea"].lower())
                else:
                    reason = "native_message_in_c_output" if content_is_native_message else item["status"]
                    entry = {"slice": key, "start_ea": item["start_ea"], "reason": reason}
                    slice_errors.append(entry)
                    decompiler_errors.append(entry)
            completed_slices += 1
        status = {
            "schema": 1,
            "architecture": args.arch,
            "scope": "live-callback GhidraDec slice from fresh copied big-endian IDA database",
            "slice_start_index": slice_start,
            "slice_end_index_exclusive": slice_end,
            "temporary_attempt": attempt,
            "expected_candidate_starts": expected_starts,
            "canonical_database_sha256_recomputed_with_python": database_hash,
            "original_binary_sha256_recomputed_with_python": binary_hash,
            "return_code": return_code,
            "timeout": timed_out,
            "timeout_terminated_isolated_process_group": terminated_process_group,
            "elapsed_seconds": elapsed,
            "execution_completed": completed,
            "all_outputs_are_valid_c_hypotheses": completed and not slice_errors,
            "fatal_failure_reason": fatal_problem,
            "decompiler_error_outputs": slice_errors,
            "persistent_records": output_records,
            "stdout": stdout_path.name,
            "stderr": stderr_path.name,
            "temporary_work_retained": args.keep_temporary,
        }
        write_json(status_path, status)
        if not args.keep_temporary:
            shutil.rmtree(work)
        if not completed:
            failures.append({"slice": key, "reason": fatal_problem})
            if not args.continue_on_failure:
                break
    summary = {
        "schema": 1,
        "scope": "live-callback GhidraDec C hypotheses; native messages are errors",
        "architecture": args.arch,
        "big_endian_required": True,
        "candidate_count": candidate_count,
        "requested_index_start": args.start_index,
        "requested_index_end_exclusive": end_index,
        "requested_candidate_count": end_index - args.start_index,
        "processed_success_count": len(processed),
        "decompiler_error_output_count": len(decompiler_errors),
        "decompiler_error_outputs": decompiler_errors,
        "completed_slice_count": completed_slices,
        "skipped_resolved_slice_count": len(skipped_slices),
        "skipped_resolved_slices": skipped_slices,
        "failed_slice_count": len(failures),
        "failures": failures,
        "original_binary_sha256_recomputed_with_python": sha256(config["binary"]),
        "canonical_database_sha256_recomputed_with_python": sha256(config["database"]),
        "global_plugin_sha256_recomputed_with_python": sha256(args.plugin),
        "interpretation_limit": (
            "Successful C is a decompiler hypothesis only. It does not establish function boundaries, "
            "code/data truth, reachability, ABI, return behavior, or original kernel behavior."
        ),
    }
    write_json(output_dir / "summary.json", summary)
    print(json.dumps({
        "output": str(output_dir.relative_to(ROOT)),
        "processed_success_count": len(processed),
        "decompiler_error_output_count": len(decompiler_errors),
        "failed_slice_count": len(failures),
        "all_requested_slices_completed": not failures and completed_slices + len(skipped_slices) ==
        len(range(args.start_index, end_index, args.slice_size)),
    }, ensure_ascii=False, sort_keys=True))
    return 0 if not failures and completed_slices == len(range(args.start_index, end_index, args.slice_size)) else 1


if __name__ == "__main__":
    sys.exit(main())
