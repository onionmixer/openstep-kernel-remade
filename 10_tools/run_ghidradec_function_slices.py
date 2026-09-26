"""Export marked GhidraDec C hypotheses for all m68k or SPARC IDA candidates.

Every invocation opens a fresh copy of the canonical IDA database in /tmp.
The only address arithmetic, slice construction, hashing, and coverage
aggregation in this runner are performed by Python.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import time


ROOT = Path(__file__).resolve().parents[1]
MARKER = re.compile(r"/\* GHIDRADEC_FUNCTION index=(\d+) start=(0x[0-9a-f]+) \*/\n")
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


def sha256(path):
    digest = hashlib.sha256()
    with Path(path).open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def write_json(path, value):
    Path(path).write_text(json.dumps(value, ensure_ascii=False, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def write_jsonl(path, values):
    with Path(path).open("w", encoding="utf-8") as stream:
        for value in values:
            stream.write(json.dumps(value, ensure_ascii=False, sort_keys=True) + "\n")


def copy_input(source, destination):
    shutil.copy2(source, destination)
    source_hash = sha256(source)
    destination_hash = sha256(destination)
    if source_hash != destination_hash:
        raise RuntimeError("copied input hash differs from source: " + str(source))
    return source_hash


def split_marked_output(text):
    matches = list(MARKER.finditer(text))
    result = []
    for position, match in enumerate(matches):
        next_start = matches[position + 1].start() if position + 1 < len(matches) else len(text)
        result.append({
            "plugin_function_index": int(match.group(1), 10),
            "start_ea": match.group(2),
            "c_text": text[match.end():next_start],
        })
    return result


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--arch", required=True, choices=sorted(ARCHITECTURES))
    parser.add_argument("--slice-size", type=int, default=25)
    parser.add_argument("--start-index", type=int, default=0)
    parser.add_argument("--max-functions", type=int, default=0,
                        help="0 means all remaining candidate indexes")
    parser.add_argument("--timeout-seconds", type=int, default=600)
    parser.add_argument("--continue-on-failure", action="store_true",
                        help="record a failed slice and continue with later slices")
    parser.add_argument("--finalize-only", action="store_true",
                        help="rebuild records and summary from existing slice and function records")
    parser.add_argument("--output-dir", type=Path)
    parser.add_argument("--temporary-root", type=Path, default=Path("/tmp/ghidradec-function-slices"))
    parser.add_argument("--ida-wrapper", type=Path,
                        default=Path("/mnt/USERS/onion/DATA_ORIGN/local/ida-pro-9.3/idat-ghidradec"))
    parser.add_argument("--plugin", type=Path,
                        default=Path("/mnt/USERS/onion/DATA_ORIGN/local/ida-pro-9.3/plugins/ghidradec64.so"))
    return parser.parse_args()


def main():
    args = parse_args()
    if args.slice_size <= 0 or args.timeout_seconds <= 0 or args.start_index < 0 or args.max_functions < 0:
        raise SystemExit("slice size and timeout must be positive; indexes must be non-negative")
    config = ARCHITECTURES[args.arch]
    for required in (config["database"], config["binary"], config["candidates"], args.ida_wrapper, args.plugin):
        if not required.is_file():
            raise SystemExit("required file is missing: " + str(required))
    candidates = json.loads(config["candidates"].read_text(encoding="utf-8"))
    if not isinstance(candidates, list) or not candidates:
        raise SystemExit("candidate index must be a non-empty JSON list")
    candidate_by_start = {item["start"].lower(): item for item in candidates}
    if len(candidate_by_start) != len(candidates):
        raise SystemExit("candidate starts are not unique")
    candidate_count = len(candidates)
    if not args.finalize_only and args.start_index >= candidate_count:
        raise SystemExit("start index is outside candidate list")
    end_index = args.start_index if args.finalize_only else (
        candidate_count if args.max_functions == 0 else min(candidate_count, args.start_index + args.max_functions))
    output_dir = args.output_dir or ROOT / "05_ida/exports" / args.arch / "ghidradec-functions"
    c_dir = output_dir / "functions"
    record_dir = output_dir / "function-records"
    slice_dir = output_dir / "slices"
    for directory in (c_dir, record_dir, slice_dir):
        directory.mkdir(parents=True, exist_ok=True)

    binary_hash = sha256(config["binary"])
    database_hash = sha256(config["database"])
    candidate_hash = sha256(config["candidates"])
    plugin_hash = sha256(args.plugin)
    temporary_root = args.temporary_root / args.arch
    temporary_root.mkdir(parents=True, exist_ok=True)
    processed_indexes = set()
    missing_from_slice = {}
    failed_from_slice = {}

    for slice_start in range(args.start_index, end_index, args.slice_size):
        slice_end = min(end_index, slice_start + args.slice_size)
        slice_key = "slice-{:05d}-{:05d}".format(slice_start, slice_end)
        work_dir = temporary_root / slice_key
        work_dir.mkdir(parents=True, exist_ok=True)
        copied_database = work_dir / "kernel.i64"
        copied_binary = work_dir / "mach_kernel"
        combined_c = slice_dir / (slice_key + ".c")
        done_path = work_dir / "slice.done"
        stdout_path = slice_dir / (slice_key + ".stdout.log")
        stderr_path = slice_dir / (slice_key + ".stderr.log")
        status_path = slice_dir / (slice_key + ".json")
        copy_input(config["database"], copied_database)
        copy_input(config["binary"], copied_binary)
        environment = os.environ.copy()
        environment.update({
            # Full corpus runs use the plugin's preloaded IDA snapshot.  A
            # live IDA data lookup from the native decompiler worker has a
            # reproducible SIGSEGV on some valid m68k/SPARC data addresses.
            "GHIDRADEC_TEST_LIVE_CALLBACKS": "0",
            # GhidraDec's internal allFuncs order puts entry points before the
            # remaining IDA functions.  It is therefore a permutation of, not
            # an index match for, this canonical address-sorted inventory.
            # Select addresses explicitly so marker coverage is meaningful.
            "GHIDRADEC_BATCH_FUNCTION_STARTS": ",".join(
                candidates[index]["start"] for index in range(slice_start, slice_end)),
            "GHIDRADEC_BATCH_FUNCTION_MARKERS": "1",
            "GHIDRADEC_BATCH_INCLUDE_SKIPPED": "1",
            "GHIDRADEC_BATCH_CONSERVATIVE_DATA_HOLES": "1",
            "GHIDRADEC_BATCH_FORCE_MAPPED_SYMBOL_HOLES": "1",
            "GHIDRADEC_BATCH_OUTPUT": str(combined_c),
            "GHIDRADEC_BATCH_DONE": str(done_path),
            "GHIDRADEC_TEST_INPUT_PATH": str(copied_binary),
            "GHIDRADEC_EXPECTED_PROCESSOR": config["processor"],
            "GHIDRADEC_EXPECTED_ENDIAN": "big",
            "GHIDRADEC_TRACE": "1",
            "GHIDRADEC_TEST_TIMEOUT": str(args.timeout_seconds),
        })
        command = [str(args.ida_wrapper), "-A", "-S10_tools/ida_ghidradec_batch_slice.py", str(copied_database)]
        started = time.monotonic()
        try:
            completed = subprocess.run(command, cwd=ROOT, env=environment, text=True,
                                       capture_output=True, timeout=args.timeout_seconds)
            timeout = False
            stdout = completed.stdout
            stderr = completed.stderr
            return_code = completed.returncode
        except subprocess.TimeoutExpired as exc:
            timeout = True
            stdout = exc.stdout or ""
            stderr = exc.stderr or ""
            return_code = None
        elapsed_seconds = time.monotonic() - started
        stdout_path.write_text(stdout, encoding="utf-8", errors="replace")
        stderr_path.write_text(stderr, encoding="utf-8", errors="replace")
        completed_ok = (not timeout and return_code == 0 and combined_c.is_file() and done_path.is_file())
        marked = []
        if completed_ok:
            combined_text = combined_c.read_text(encoding="utf-8", errors="replace")
            marked = split_marked_output(combined_text)
            if not marked:
                completed_ok = False
        emitted_starts = []
        for item in marked:
            start = item["start_ea"].lower()
            emitted_starts.append(start)
            candidate = candidate_by_start.get(start)
            if candidate is None:
                raise RuntimeError("plugin emitted a start absent from candidate index: " + start)
            c_path = c_dir / ("{:08X}.c".format(int(start, 16)))
            c_path.write_text(item["c_text"], encoding="utf-8")
            status = ("plugin_error_output" if item["c_text"].lstrip().startswith(
                ("//Error decompiling function:", "//Decompiler native message:")) else "success")
            record = {
                "architecture": args.arch,
                "candidate_index": candidates.index(candidate),
                "plugin_function_index": item["plugin_function_index"],
                "start_ea": start,
                "end_ea": candidate["end"],
                "size_bytes": candidate["size"],
                "name": candidate["name"],
                "status": status,
                "c_output": str(c_path.relative_to(output_dir)),
                "c_output_size_bytes": c_path.stat().st_size,
                "c_output_sha256": sha256(c_path),
                "slice": slice_key,
            }
            write_json(record_dir / ("{:08X}.json".format(int(start, 16))), record)
        expected_starts = [candidates[index]["start"].lower()
                           for index in range(slice_start, slice_end)]
        if len(emitted_starts) != len(expected_starts) or set(emitted_starts) != set(expected_starts):
            completed_ok = False
        for candidate_index in range(slice_start, slice_end):
            processed_indexes.add(candidate_index)
            start = candidates[candidate_index]["start"].lower()
            if start not in emitted_starts:
                missing_from_slice[start] = slice_key
        slice_status = {
            "schema": 1,
            "architecture": args.arch,
            "scope": "GhidraDec headless batch slice from copied big-endian IDA database; C is a decompiler hypothesis",
            "slice_start_index": slice_start,
            "slice_end_index_exclusive": slice_end,
            "requested_candidate_count": slice_end - slice_start,
            "plugin_marker_count": len(marked),
            "plugin_marker_starts": emitted_starts,
            "expected_candidate_starts": expected_starts,
            "completed": completed_ok,
            "timeout": timeout,
            "return_code": return_code,
            "elapsed_seconds": elapsed_seconds,
            "combined_c": combined_c.name if combined_c.is_file() else None,
            "combined_c_sha256": sha256(combined_c) if combined_c.is_file() else None,
            "stdout": stdout_path.name,
            "stderr": stderr_path.name,
        }
        write_json(status_path, slice_status)
        if not completed_ok:
            for candidate_index in range(slice_start, slice_end):
                processed_indexes.add(candidate_index)
                failed_from_slice[candidate_index] = slice_key
            if args.continue_on_failure:
                continue
            raise RuntimeError("slice did not complete: " + slice_key)

    submitted_indexes = [False] * candidate_count
    slice_evidence = [[] for _ in range(candidate_count)]
    for status_path in sorted(slice_dir.glob("slice-*.json")):
        status = json.loads(status_path.read_text(encoding="utf-8"))
        interval_start = status["slice_start_index"]
        interval_end = status["slice_end_index_exclusive"]
        if interval_start < 0 or interval_end < interval_start or interval_end > candidate_count:
            raise RuntimeError("stored slice interval is outside candidate range: " + status_path.name)
        for candidate_index in range(interval_start, interval_end):
            submitted_indexes[candidate_index] = True
            slice_evidence[candidate_index].append(status_path.name)

    records = []
    for candidate_index, candidate in enumerate(candidates):
        start = candidate["start"].lower()
        record_path = record_dir / ("{:08X}.json".format(int(start, 16)))
        if record_path.is_file():
            records.append(json.loads(record_path.read_text(encoding="utf-8")))
        else:
            records.append({
                "architecture": args.arch,
                "candidate_index": candidate_index,
                "start_ea": start,
                "end_ea": candidate["end"],
                "size_bytes": candidate["size"],
                "name": candidate["name"],
                "status": ("slice_runner_failed" if candidate_index in failed_from_slice else
                           "not_emitted_by_plugin" if start in missing_from_slice else
                           "no_c_output_after_full_batch_attempt" if submitted_indexes[candidate_index] else
                           "not_attempted"),
                "slice": failed_from_slice.get(candidate_index, missing_from_slice.get(start)),
                "batch_slice_statuses": slice_evidence[candidate_index],
            })
    write_jsonl(output_dir / "records.jsonl", records)
    status_counts = {status: sum(1 for record in records if record["status"] == status)
                     for status in sorted({record["status"] for record in records})}
    summary = {
        "schema": 1,
        "architecture": args.arch,
        "scope": "full IDA function-candidate inventory with GhidraDec C hypotheses and explicit non-emission states",
        "big_endian_required": True,
        "processor": config["processor"],
        "original_binary": str(config["binary"].relative_to(ROOT)),
        "original_binary_sha256": binary_hash,
        "canonical_database": str(config["database"].relative_to(ROOT)),
        "canonical_database_sha256": database_hash,
        "candidate_index": str(config["candidates"].relative_to(ROOT)),
        "candidate_index_sha256": candidate_hash,
        "global_plugin_sha256": plugin_hash,
        "candidate_count": candidate_count,
        "requested_index_start": args.start_index,
        "requested_index_end_exclusive": end_index,
        "finalize_only": args.finalize_only,
        "slice_size": args.slice_size,
        "submitted_candidate_index_count": sum(1 for value in submitted_indexes if value),
        "status_counts": status_counts,
        "records": "records.jsonl",
    }
    write_json(output_dir / "summary.json", summary)
    print(json.dumps(summary, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
