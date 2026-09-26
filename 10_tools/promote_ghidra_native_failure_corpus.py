"""Validate /tmp native-Ghidra probes and promote separate C hypotheses.

Only native Ghidra output from an exact requested entry is copied.  It is kept
under 04_ghidra, separate from IDA/GhidraDec exports and original-byte facts.
"""
import csv
import hashlib
import json
from pathlib import Path
import shutil


ROOT = Path(__file__).resolve().parents[1]
REPORTS = ROOT / "09_validation/reports/multiarch-input-20260921"
FAILURES = REPORTS / "ghidradec-live-callback-failure-asm-coverage-20260923.json"
TMP_ROOT = Path("/tmp/ghidra-native-probe-20260923")
DATE = "20260923"
ARCHES = {
    "m68k": "68000:BE:32:default",
    "sparc": "sparc:BE:32:default",
}


def sha256(path):
    digest = hashlib.sha256()
    with Path(path).open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def read_tsv(path):
    with Path(path).open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream, delimiter="\t"))


def write_json(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, ensure_ascii=False, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def copy_verified(source, destination):
    destination.parent.mkdir(parents=True, exist_ok=True)
    source_hash = sha256(source)
    if destination.exists():
        if sha256(destination) != source_hash:
            raise RuntimeError("refusing to replace hash-mismatched persistent output: {}".format(destination))
    else:
        shutil.copy2(source, destination)
    if sha256(destination) != source_hash:
        raise RuntimeError("persistent copy hash mismatch: {}".format(destination))
    return source_hash


def main():
    failures = json.loads(FAILURES.read_text(encoding="utf-8"))
    result = {
        "schema": 1,
        "scope": "validated promotion of native Ghidra headless C hypotheses for prior GhidraDec failure addresses; native C is not original-byte evidence and does not establish behavior, ABI, boundaries, reachability, or types",
        "source_failure_audit": str(FAILURES.relative_to(ROOT)),
        "source_failure_audit_sha256_recomputed_with_python": sha256(FAILURES),
        "architectures": {},
    }
    all_pass = True
    for arch, language in ARCHES.items():
        tmp = TMP_ROOT / (arch + "-failures-exact-c")
        program_path = tmp / "program.tsv"
        manifest_path = tmp / "manifest.tsv"
        programs = read_tsv(program_path)
        manifest = read_tsv(manifest_path)
        if programs != [{"program_name": "mach_kernel", "language_id": language, "compiler_spec_id": "default"}]:
            raise RuntimeError("unexpected native Ghidra program metadata for " + arch)
        expected = {"0x{:x}".format(row["address"]): row for row in failures[arch]["failures"]}
        if set(row["requested_address"].lower() for row in manifest) != set(expected):
            raise RuntimeError("native manifest requested addresses differ from failure audit for " + arch)
        if len(manifest) != len(expected):
            raise RuntimeError("native manifest has duplicate requested addresses for " + arch)
        index_path = ROOT / "05_ida/exports" / arch / "function-asm-index.json"
        index = {row["start"].lower(): row for row in json.loads(index_path.read_text(encoding="utf-8"))}
        raw_path = ROOT / "03_original" / arch / "binaries/mach_kernel"
        raw_hash = sha256(raw_path)
        persistent = ROOT / "04_ghidra/exports" / arch / ("native-headless-failure-exact-" + DATE)
        copied = []
        rows = []
        for row in manifest:
            requested = row["requested_address"].lower()
            failure = expected[requested]
            candidate = index.get(requested)
            if candidate is None:
                raise RuntimeError("failure address is missing from IDA candidate index: " + requested)
            item = {
                "address": requested,
                "prior_ghidradec_failure_kind": failure["kind"],
                "prior_ghidradec_name_observation": failure.get("name", candidate["name"]),
                "ida_candidate_range": {"start": candidate["start"], "end": candidate["end"]},
                "native_ghidra_status": row["status"],
            }
            if row["status"] == "success_exact_function":
                if int(row["exact_function_start"], 16) != failure["address"]:
                    raise RuntimeError("native exact start does not match requested address: " + requested)
                body_min = int(row["exact_function_body_min"], 16)
                body_end = int(row["exact_function_body_max"], 16) + 1
                item["native_ghidra_body_range"] = {"start": row["exact_function_body_min"], "end_exclusive_recomputed_with_python": "0x{:x}".format(body_end)}
                item["body_range_matches_ida_candidate"] = (body_min == int(candidate["start"], 16) and body_end == int(candidate["end"], 16))
                source_c = tmp / row["output"]
                if not source_c.is_file() or source_c.stat().st_size == 0:
                    raise RuntimeError("native success has no nonempty C output: " + requested)
                destination_c = persistent / "functions" / ("{:08X}.c".format(failure["address"]))
                c_hash = copy_verified(source_c, destination_c)
                item["c_hypothesis"] = str(destination_c.relative_to(ROOT))
                item["c_hypothesis_sha256_recomputed_with_python"] = c_hash
                copied.append(item)
            elif row["status"] == "no_exact_ghidra_function":
                item["disposition"] = "no C promoted: Ghidra does not define an exact function at the IDA candidate start"
            else:
                raise RuntimeError("unexpected native Ghidra status: " + row["status"])
            rows.append(item)
        copy_verified(program_path, persistent / "program.tsv")
        copy_verified(manifest_path, persistent / "manifest.tsv")
        for item in copied:
            address = int(item["address"], 16)
            write_json(persistent / "records" / ("{:08X}.json".format(address)), item)
        success_count = sum(row["native_ghidra_status"] == "success_exact_function" for row in rows)
        no_exact_count = sum(row["native_ghidra_status"] == "no_exact_ghidra_function" for row in rows)
        matching_body_count = sum(row.get("body_range_matches_ida_candidate") is True for row in rows)
        differing_body_count = sum(row.get("body_range_matches_ida_candidate") is False for row in rows)
        complete = success_count + no_exact_count == len(rows)
        all_pass = all_pass and complete
        result["architectures"][arch] = {
            "architecture_endianness": "big",
            "original_binary": str(raw_path.relative_to(ROOT)),
            "original_binary_sha256_recomputed_with_python": raw_hash,
            "native_ghidra_language_id": language,
            "requested_failure_count_recomputed_with_python": len(rows),
            "native_success_exact_start_count_recomputed_with_python": success_count,
            "no_exact_ghidra_function_count_recomputed_with_python": no_exact_count,
            "native_body_range_matches_ida_candidate_count_recomputed_with_python": matching_body_count,
            "native_body_range_differs_from_ida_candidate_count_recomputed_with_python": differing_body_count,
            "persistent_corpus": str(persistent.relative_to(ROOT)),
            "rows": rows,
        }
    result["all_architectures_pass"] = all_pass
    output = REPORTS / "ghidra-native-failure-exact-corpus-audit-{}.json".format(DATE)
    write_json(output, result)
    if not all_pass:
        raise SystemExit("native Ghidra promotion audit failed")
    print(json.dumps({"output": str(output.relative_to(ROOT)), "all_architectures_pass": all_pass}, sort_keys=True))


if __name__ == "__main__":
    main()
