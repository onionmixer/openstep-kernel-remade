"""Deep-review three assembly-only or boundary-disagreeing failure records.

This audit intentionally stays below semantic reconstruction.  It checks the
current IDA candidate listings, call/xref source encodings, neighbouring
candidate/layout observations, and (when present) the independently exported
native-Ghidra function body against the original, big-endian kernel bytes.
"""
import bisect
import csv
import hashlib
import json
import re
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORTS = ROOT / "09_validation/reports/multiarch-input-20260921"
NATIVE_AUDIT = REPORTS / "ghidra-native-failure-exact-corpus-audit-20260923.json"
OUTPUT = REPORTS / "ghidradec-failure-exception-boundary-deep-review-20260923.json"

TARGETS = (
    {
        "architecture": "m68k",
        "address": 0x4001F96,
        "review_class": "assembly_only_no_exact_native_ghidra_function",
        "limited_listing_observation": (
            "The original-byte-validated listing begins with movem.l and movec, "
            "contains bit-field/bit-test instructions and three listed direct-call "
            "sites, and ends with rte. This is a lexical listing observation only."
        ),
    },
    {
        "architecture": "sparc",
        "address": 0xF00EA3F0,
        "review_class": "assembly_only_no_exact_native_ghidra_function",
        "limited_listing_observation": (
            "The original-byte-validated listing contains register-relative clears/stores, "
            "two current type-19 target addresses inside the candidate, and retl followed "
            "by another listed item. It does not establish object layout, arguments, or "
            "instruction execution."
        ),
    },
    {
        "architecture": "sparc",
        "address": 0xF0097888,
        "review_class": "native_ghidra_body_boundary_disagrees_with_ida_candidate",
        "limited_listing_observation": (
            "The original-byte-validated listing contains seven listed direct-call sites "
            "and continues through ret and restore after the native-Ghidra body end. "
            "This is a static layout observation; it does not establish execution, "
            "reachability, delay-slot behaviour, or return behaviour."
        ),
    },
)

ASM_LINE = re.compile(r"^([0-9A-Fa-f]+):\s+([0-9A-Fa-f]+)\s+(.*)$")


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def read_tsv(path):
    with path.open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream, delimiter="\t"))


def text_mapping(arch):
    inventory = json.loads((ROOT / "03_original" / arch / "inventory/macho.json").read_text(encoding="utf-8"))
    section = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    return int(section["address"], 16), section["file_offset"]


def raw_at(raw, text_address, text_offset, address, length):
    offset = text_offset + address - text_address
    if address < text_address or offset < 0 or offset + length > len(raw):
        raise ValueError("address outside original __text: {}".format(hex(address)))
    return raw[offset:offset + length]


def candidate_owner(address, starts, candidates):
    position = bisect.bisect_right(starts, address) - 1
    if position >= 0 and address < int(candidates[position]["end"], 16):
        return candidates[position]
    return None


def parse_asm(path):
    items = []
    for number, line in enumerate(path.read_text(encoding="utf-8").splitlines(), start=1):
        match = ASM_LINE.match(line)
        if match is None:
            raise RuntimeError("unparseable assembly line {}:{}".format(path, number))
        items.append({
            "address": int(match.group(1), 16),
            "bytes": bytes.fromhex(match.group(2)),
            "disassembly": match.group(3),
        })
    if not items:
        raise RuntimeError("empty assembly listing: {}".format(path))
    return items


def entry_summary(item):
    return {
        "address": "0x{:x}".format(item["address"]),
        "bytes": item["bytes"].hex(),
        "disassembly": item["disassembly"],
    }


def c_metadata(path):
    text = path.read_text(encoding="utf-8", errors="replace")
    lines = text.splitlines()
    return {
        "path": str(path.relative_to(ROOT)),
        "sha256_recomputed_with_python": sha256(path.read_bytes()),
        "byte_length_recomputed_with_python": len(text.encode("utf-8")),
        "line_count_recomputed_with_python": len(lines),
        "warning_comment_count_recomputed_with_python": sum("WARNING:" in line for line in lines),
    }


def serialise_call(row):
    return {
        "source": row["source"],
        "target": row["target"],
        "edge_kind": row["edge_kind"],
        "instruction_bytes": row["instruction_bytes"],
        "target_raw_symbols": row["target_raw_symbols"],
        "xref_type": row["xref_type"],
    }


def main():
    native = json.loads(NATIVE_AUDIT.read_text(encoding="utf-8"))
    native_rows = {
        arch: {int(row["address"], 16): row for row in native["architectures"][arch]["rows"]}
        for arch in ("m68k", "sparc")
    }
    result = {
        "schema": 1,
        "scope": "deep static review of the two assembly-only and one native-Ghidra body-boundary-disagreement GhidraDec failure records",
        "interpretation_limit": (
            "All original-byte checks establish byte/address/layout correspondence only. "
            "IDA candidate boundaries, item kinds, names, xrefs, direct-call labels, and "
            "native-Ghidra C remain tool observations or hypotheses. This audit does not "
            "establish function boundaries, code/data truth, instruction semantics, execution, "
            "reachability, delay-slot behaviour, ABI, arguments, return values, object layout, "
            "or original behavior."
        ),
        "records": [],
    }
    cache = {}
    all_checks = True
    for target in TARGETS:
        arch = target["architecture"]
        if arch not in cache:
            raw = (ROOT / "03_original" / arch / "binaries/mach_kernel").read_bytes()
            text_address, text_offset = text_mapping(arch)
            candidates = sorted(json.loads((ROOT / "05_ida/exports" / arch / "function-asm-index.json").read_text(encoding="utf-8")), key=lambda row: int(row["start"], 16))
            cache[arch] = {
                "raw": raw,
                "text_address": text_address,
                "text_offset": text_offset,
                "candidates": candidates,
                "starts": [int(row["start"], 16) for row in candidates],
                "units": sorted(read_tsv(ROOT / "05_ida/exports" / arch / "text-units.tsv"), key=lambda row: int(row["address"], 16)),
                "unit_by_address": {int(row["address"], 16): row for row in read_tsv(ROOT / "05_ida/exports" / arch / "text-units.tsv")},
                "calls": read_tsv(ROOT / "05_ida/exports" / arch / "direct-call-edges.tsv"),
                "type19": [row for row in read_tsv(ROOT / "05_ida/exports" / arch / "xrefs.tsv") if row["type"] == "19"],
            }
        source = cache[arch]
        raw = source["raw"]
        candidates = source["candidates"]
        starts = source["starts"]
        address = target["address"]
        index = next((i for i, row in enumerate(candidates) if int(row["start"], 16) == address), None)
        if index is None:
            raise RuntimeError("current candidate missing: {} {}".format(arch, hex(address)))
        candidate = candidates[index]
        begin, end = int(candidate["start"], 16), int(candidate["end"], 16)
        asm_path = ROOT / "05_ida/exports" / arch / candidate["asm"]
        asm_items = parse_asm(asm_path)
        listing_checks = []
        for item in asm_items:
            actual = raw_at(raw, source["text_address"], source["text_offset"], item["address"], len(item["bytes"]))
            listing_checks.append(actual == item["bytes"] and begin <= item["address"] < end and item["address"] + len(item["bytes"]) <= end)
        raw_candidate = raw_at(raw, source["text_address"], source["text_offset"], begin, end - begin)
        predecessor = candidates[index - 1] if index else None
        successor = candidates[index + 1] if index + 1 < len(candidates) else None
        next_unit = source["unit_by_address"].get(end)
        preceding_exact = predecessor is not None and int(predecessor["end"], 16) == begin
        following_exact = successor is not None and int(successor["start"], 16) == end
        outgoing_calls = [row for row in source["calls"] if begin <= int(row["source"], 16) < end]
        incoming_calls = [row for row in source["calls"] if int(row["target"], 16) == begin]
        call_rows = outgoing_calls + incoming_calls
        call_checks = [
            raw_at(raw, source["text_address"], source["text_offset"], int(row["source"], 16), len(bytes.fromhex(row["instruction_bytes"]))) == bytes.fromhex(row["instruction_bytes"])
            for row in call_rows
        ]
        outgoing_type19 = [row for row in source["type19"] if begin <= int(row["from"], 16) < end]
        incoming_type19 = [row for row in source["type19"] if int(row["to"], 16) == begin]
        type19_details = []
        type19_checks = []
        for row in outgoing_type19 + incoming_type19:
            source_address = int(row["from"], 16)
            unit = source["unit_by_address"].get(source_address)
            source_valid = unit is not None
            if source_valid:
                encoded = bytes.fromhex(unit["bytes"])
                source_valid = raw_at(raw, source["text_address"], source["text_offset"], source_address, len(encoded)) == encoded
            type19_checks.append(source_valid)
            owner = candidate_owner(int(row["to"], 16), starts, candidates)
            type19_details.append({
                "from": row["from"],
                "to": row["to"],
                "source_text_item_bytes_match_original": source_valid,
                "target_current_candidate_relation": (
                    "same_candidate" if owner is candidate else
                    "other_candidate" if owner is not None else
                    "candidate_gap_or_noncandidate"
                ),
            })
        native_row = native_rows[arch].get(begin)
        if native_row is None:
            raise RuntimeError("native audit row missing: {} {}".format(arch, hex(begin)))
        native_status = native_row["native_ghidra_status"]
        native_record = {
            "status": native_status,
            "body_range_matches_current_ida_candidate": native_row.get("body_range_matches_ida_candidate"),
        }
        native_checks = []
        if native_status == "no_exact_ghidra_function":
            native_record["disposition"] = "No native-Ghidra C was exported; retain this as assembly-only."
            if target["review_class"] != "assembly_only_no_exact_native_ghidra_function":
                raise RuntimeError("unexpected assembly-only class")
        elif native_status == "success_exact_function":
            body = native_row["native_ghidra_body_range"]
            body_start, body_end = int(body["start"], 16), int(body["end_exclusive_recomputed_with_python"], 16)
            c_path = ROOT / native_row["c_hypothesis"]
            metadata = c_metadata(c_path)
            native_checks.append(metadata["sha256_recomputed_with_python"] == native_row["c_hypothesis_sha256_recomputed_with_python"])
            body_inside_candidate = begin <= body_start <= body_end <= end
            native_checks.append(body_inside_candidate)
            prefix = raw_at(raw, source["text_address"], source["text_offset"], body_start, body_end - body_start)
            tail = raw_at(raw, source["text_address"], source["text_offset"], body_end, end - body_end)
            tail_items = [entry_summary(item) for item in asm_items if body_end <= item["address"] < end]
            native_record.update({
                "native_ghidra_body_range": {
                    "start": "0x{:x}".format(body_start),
                    "end_exclusive": "0x{:x}".format(body_end),
                    "size_recomputed_with_python": body_end - body_start,
                    "original_bytes_sha256_recomputed_with_python": sha256(prefix),
                },
                "c_hypothesis": metadata,
                "body_is_within_current_ida_candidate": body_inside_candidate,
                "candidate_tail_after_native_body": {
                    "start": "0x{:x}".format(body_end),
                    "end_exclusive": "0x{:x}".format(end),
                    "size_recomputed_with_python": end - body_end,
                    "original_bytes_sha256_recomputed_with_python": sha256(tail),
                    "listed_items": tail_items,
                    "all_listed_item_bytes_match_original": all(
                        raw_at(raw, source["text_address"], source["text_offset"], int(item["address"], 16), len(bytes.fromhex(item["bytes"]))) == bytes.fromhex(item["bytes"])
                        for item in tail_items
                    ),
                },
                "disposition": (
                    "The native C is retained only as a separately bounded prefix hypothesis and "
                    "is excluded from full-current-candidate interpretation because its body end differs."
                    if not native_row["body_range_matches_ida_candidate"] else
                    "Native C range aligns with the current candidate; not applicable to this review class."
                ),
            })
        else:
            raise RuntimeError("unexpected native status: {}".format(native_status))
        all_listing_ok = all(listing_checks)
        all_calls_ok = all(call_checks)
        all_type19_ok = all(type19_checks)
        all_native_ok = all(native_checks)
        complete = all_listing_ok and all_calls_ok and all_type19_ok and all_native_ok
        all_checks = all_checks and complete
        result["records"].append({
            "architecture": arch,
            "architecture_endianness": "big",
            "address": "0x{:x}".format(begin),
            "ida_name_observation": candidate["name"],
            "review_class": target["review_class"],
            "current_ida_candidate_range": {
                "start": candidate["start"], "end_exclusive": candidate["end"],
                "size_recomputed_with_python": end - begin,
                "original_bytes_sha256_recomputed_with_python": sha256(raw_candidate),
                "assembly_listing": str(asm_path.relative_to(ROOT)),
                "listed_item_count_recomputed_with_python": len(asm_items),
                "all_listed_item_bytes_match_original": all_listing_ok,
                "entry_item": entry_summary(asm_items[0]),
                "trailing_item": entry_summary(asm_items[-1]),
            },
            "current_boundary_observations": {
                "previous_candidate": None if predecessor is None else {"start": predecessor["start"], "end_exclusive": predecessor["end"], "name": predecessor["name"], "ends_exactly_at_current_start": preceding_exact},
                "next_text_item_at_current_end": None if next_unit is None else {"address": next_unit["address"], "kind": next_unit["kind"], "bytes": next_unit["bytes"], "disassembly": next_unit["disassembly"], "bytes_match_original": raw_at(raw, source["text_address"], source["text_offset"], int(next_unit["address"], 16), len(bytes.fromhex(next_unit["bytes"]))) == bytes.fromhex(next_unit["bytes"])},
                "next_candidate": None if successor is None else {"start": successor["start"], "end_exclusive": successor["end"], "name": successor["name"], "starts_exactly_at_current_end": following_exact, "intervening_address_span_size_recomputed_with_python": int(successor["start"], 16) - end},
            },
            "direct_call_observations": {
                "outgoing_count_recomputed_with_python": len(outgoing_calls),
                "incoming_to_current_start_count_recomputed_with_python": len(incoming_calls),
                "all_call_instruction_bytes_match_original": all_calls_ok,
                "outgoing": [serialise_call(row) for row in outgoing_calls],
                "incoming": [serialise_call(row) for row in incoming_calls],
            },
            "type19_xref_observations": {
                "outgoing_count_recomputed_with_python": len(outgoing_type19),
                "incoming_to_current_start_count_recomputed_with_python": len(incoming_type19),
                "all_source_text_item_bytes_match_original": all_type19_ok,
                "outgoing_target_relation_counts_recomputed_with_python": {
                    relation: sum(detail["target_current_candidate_relation"] == relation for detail in type19_details[:len(outgoing_type19)])
                    for relation in ("same_candidate", "other_candidate", "candidate_gap_or_noncandidate")
                },
                "edges": type19_details,
            },
            "native_ghidra_review": native_record,
            "limited_listing_observation": target["limited_listing_observation"],
            "all_required_original_byte_and_corpus_integrity_checks_pass": complete,
        })
    result["reviewed_record_count_recomputed_with_python"] = len(result["records"])
    result["all_required_original_byte_and_corpus_integrity_checks_pass"] = all_checks
    OUTPUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if not all_checks:
        raise SystemExit("deep-review evidence check failed")
    print(json.dumps({
        "output": str(OUTPUT.relative_to(ROOT)),
        "reviewed_record_count_recomputed_with_python": len(result["records"]),
        "all_checks_pass": all_checks,
    }, sort_keys=True))


if __name__ == "__main__":
    main()
