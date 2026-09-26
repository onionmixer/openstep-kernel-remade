"""Create original-byte-checked manual review cards for GhidraDec failures.

The cards deliberately record lexical assembly observations, not recovered C
meaning.  They keep C-generation failures, original bytes, and any later
manual semantic interpretation separate.
"""
import hashlib
import json
from pathlib import Path
import re


ROOT = Path(__file__).resolve().parents[1]
REPORTS = ROOT / "09_validation/reports/multiarch-input-20260921"
FAILURES = REPORTS / "ghidradec-live-callback-failure-asm-coverage-20260923.json"
RETRIES = REPORTS / "ghidradec-error-output-retry-20260923.json"
OUTPUT = REPORTS / "ghidradec-failure-manual-evidence-audit-20260923.json"
ARCHES = ("m68k", "sparc")
ITEM = re.compile(r"^([0-9A-Fa-f]+):\s+([0-9A-Fa-f]+)\s+(.*)$")


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def raw_text_mapping(arch):
    inventory = json.loads((ROOT / "03_original" / arch / "inventory/macho.json").read_text(encoding="utf-8"))
    section = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    return int(section["address"], 16), section["file_offset"]


def raw_at(raw, text_address, text_offset, address, length):
    offset = text_offset + address - text_address
    if address < text_address or offset < 0 or offset + length > len(raw):
        raise ValueError("address is not backed by the original __text bytes: {}".format(hex(address)))
    return raw[offset:offset + length]


def assembly_items(path):
    items = []
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        match = ITEM.match(line)
        if match is None:
            continue
        address = int(match.group(1), 16)
        shown_bytes = bytes.fromhex(match.group(2))
        disassembly = match.group(3)
        mnemonic = disassembly.split(None, 1)[0].lower() if disassembly else ""
        items.append({
            "address": address,
            "shown_bytes": shown_bytes,
            "disassembly": disassembly,
            "mnemonic": mnemonic,
        })
    if not items:
        raise ValueError("assembly file has no address/bytes items: {}".format(path))
    return items


def compact_item(item):
    return {
        "address": "0x{:x}".format(item["address"]),
        "bytes": item["shown_bytes"].hex(),
        "disassembly": item["disassembly"],
    }


def retry_disposition(failure, retry_by_address):
    if failure["kind"] == "fresh_copied_db_fatal_plugin_failure":
        return {
            "kind": "prior_single_candidate_plugin_SIGSEGV_not_retried",
            "prior_return_code": failure["return_code"],
            "reason": "repeating an already single-candidate crash without a changed tool condition is not additional evidence",
        }
    retry = retry_by_address.get(failure["address"])
    if retry is None:
        return {"kind": "retry_record_missing"}
    if retry["execution_completed"] and retry["decompiler_error_outputs"]:
        return {
            "kind": "fresh_single_candidate_plugin_error_reproduced",
            "retry_slice_status": retry["slice_status_path"],
            "retry_error_kinds": [row["reason"] for row in retry["decompiler_error_outputs"]],
        }
    if retry["execution_completed"]:
        return {"kind": "fresh_single_candidate_valid_C_hypothesis", "retry_slice_status": retry["slice_status_path"]}
    return {
        "kind": "fresh_single_candidate_fatal_or_incomplete_retry",
        "retry_slice_status": retry["slice_status_path"],
        "fatal_failure_reason": retry["fatal_failure_reason"],
    }


def main():
    failures = json.loads(FAILURES.read_text(encoding="utf-8"))
    retries = json.loads(RETRIES.read_text(encoding="utf-8"))
    result = {
        "schema": 1,
        "scope": "original-byte-checked lexical assembly evidence cards for every existing live-callback GhidraDec failure; no behavioral, ABI, ownership, reachability, or function-boundary conclusion",
        "failure_source": str(FAILURES.relative_to(ROOT)),
        "failure_source_sha256_recomputed_with_python": sha256(FAILURES.read_bytes()),
        "retry_source": str(RETRIES.relative_to(ROOT)),
        "retry_source_sha256_recomputed_with_python": sha256(RETRIES.read_bytes()),
        "architectures": {},
    }
    all_items_match_original = True
    all_items_within_ranges = True
    for arch in ARCHES:
        raw_path = ROOT / "03_original" / arch / "binaries/mach_kernel"
        raw = raw_path.read_bytes()
        text_address, text_offset = raw_text_mapping(arch)
        index_path = ROOT / "05_ida/exports" / arch / "function-asm-index.json"
        index = {int(row["start"], 16): row for row in json.loads(index_path.read_text(encoding="utf-8"))}
        retry_by_address = {row["address"]: row for row in retries["architectures"][arch]["attempts"]}
        cards = []
        for failure in failures[arch]["failures"]:
            address = failure["address"]
            candidate = index.get(address)
            if candidate is None:
                raise ValueError("failure is absent from candidate index: {}".format(hex(address)))
            start, end = int(candidate["start"], 16), int(candidate["end"], 16)
            asm_path = ROOT / failure["assembly_path"]
            items = assembly_items(asm_path)
            byte_mismatches = []
            outside_range = []
            discontinuities = []
            for position, item in enumerate(items):
                observed = raw_at(raw, text_address, text_offset, item["address"], len(item["shown_bytes"]))
                if observed != item["shown_bytes"]:
                    byte_mismatches.append({
                        "address": "0x{:x}".format(item["address"]),
                        "listing_bytes": item["shown_bytes"].hex(),
                        "original_bytes": observed.hex(),
                    })
                if not (start <= item["address"] and item["address"] + len(item["shown_bytes"]) <= end):
                    outside_range.append(compact_item(item))
                if position and items[position - 1]["address"] + len(items[position - 1]["shown_bytes"]) != item["address"]:
                    discontinuities.append({
                        "previous_end_exclusive": "0x{:x}".format(items[position - 1]["address"] + len(items[position - 1]["shown_bytes"])),
                        "next_address": "0x{:x}".format(item["address"]),
                    })
            call_items = [compact_item(item) for item in items if item["mnemonic"] in ("bsr", "bsr.s", "bsr.l", "jsr", "call")]
            return_items = [compact_item(item) for item in items if item["mnemonic"] in ("rts", "ret", "retl")]
            card = {
                "address": "0x{:x}".format(address),
                "failure_kind": failure["kind"],
                "ida_name_observation": failure.get("name", candidate["name"]),
                "candidate_index_entry": {
                    "start": candidate["start"],
                    "end": candidate["end"],
                    "size": candidate["size"],
                    "item_count": candidate["item_count"],
                    "code_item_count": candidate["code_item_count"],
                },
                "candidate_range_original_bytes_sha256_recomputed_with_python": sha256(raw_at(raw, text_address, text_offset, start, end - start)),
                "assembly_path": failure["assembly_path"],
                "assembly_file_sha256_recomputed_with_python": sha256(asm_path.read_bytes()),
                "listed_item_count_recomputed_with_python": len(items),
                "all_listed_item_bytes_match_original": not byte_mismatches,
                "listed_item_byte_mismatches": byte_mismatches,
                "all_listed_items_are_inside_candidate_range": not outside_range,
                "listed_items_outside_candidate_range": outside_range,
                "listing_address_discontinuity_count_recomputed_with_python": len(discontinuities),
                "listing_address_discontinuities": discontinuities,
                "entry_item": compact_item(items[0]),
                "trailing_items": [compact_item(item) for item in items[-2:]],
                "lexical_call_mnemonic_items": call_items,
                "lexical_return_mnemonic_items": return_items,
                "retry_disposition": retry_disposition(failure, retry_by_address),
                "manual_review_disposition": "assembly evidence retained; semantic interpretation remains required",
            }
            cards.append(card)
        items_match = all(card["all_listed_item_bytes_match_original"] for card in cards)
        items_in_range = all(card["all_listed_items_are_inside_candidate_range"] for card in cards)
        all_items_match_original = all_items_match_original and items_match
        all_items_within_ranges = all_items_within_ranges and items_in_range
        result["architectures"][arch] = {
            "original_binary": str(raw_path.relative_to(ROOT)),
            "original_binary_sha256_recomputed_with_python": sha256(raw),
            "architecture_endianness": "big",
            "candidate_index": str(index_path.relative_to(ROOT)),
            "candidate_index_sha256_recomputed_with_python": sha256(index_path.read_bytes()),
            "failure_card_count_recomputed_with_python": len(cards),
            "all_listed_item_bytes_match_original": items_match,
            "all_listed_items_are_inside_candidate_range": items_in_range,
            "listing_address_discontinuity_count_recomputed_with_python": sum(card["listing_address_discontinuity_count_recomputed_with_python"] for card in cards),
            "prior_SIGSEGV_card_count_recomputed_with_python": sum(card["retry_disposition"]["kind"] == "prior_single_candidate_plugin_SIGSEGV_not_retried" for card in cards),
            "fresh_plugin_error_reproduced_card_count_recomputed_with_python": sum(card["retry_disposition"]["kind"] == "fresh_single_candidate_plugin_error_reproduced" for card in cards),
            "cards": cards,
        }
    result["all_listed_item_bytes_match_original"] = all_items_match_original
    result["all_listed_items_are_inside_candidate_range"] = all_items_within_ranges
    OUTPUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if not all_items_match_original or not all_items_within_ranges:
        raise SystemExit("manual evidence audit found an original-byte or candidate-range mismatch")
    print(json.dumps({"output": str(OUTPUT.relative_to(ROOT)), "all_listed_item_bytes_match_original": all_items_match_original, "all_listed_items_are_inside_candidate_range": all_items_within_ranges}, sort_keys=True))


if __name__ == "__main__":
    main()
