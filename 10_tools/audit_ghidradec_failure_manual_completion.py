"""Complete a conservative, per-function manual-analysis record for 52 failures.

Each record links original byte facts to a separately stored native-Ghidra C
hypothesis when available.  No decompiler output is promoted to original
behavior, ABI, reachability, or true function-boundary evidence.
"""
import bisect
import csv
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORTS = ROOT / "09_validation/reports/multiarch-input-20260921"
FAILURES = REPORTS / "ghidradec-live-callback-failure-asm-coverage-20260923.json"
MANUAL = REPORTS / "ghidradec-failure-manual-evidence-audit-20260923.json"
NATIVE = REPORTS / "ghidra-native-failure-exact-corpus-audit-20260923.json"
OUTPUT = REPORTS / "ghidradec-failure-manual-analysis-completion-20260923.json"
ARCHES = ("m68k", "sparc")


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def read_tsv(path):
    with path.open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream, delimiter="\t"))


def mapping(arch):
    inventory = json.loads((ROOT / "03_original" / arch / "inventory/macho.json").read_text(encoding="utf-8"))
    section = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    return int(section["address"], 16), section["file_offset"]


def raw_at(raw, text_address, text_offset, address, length):
    offset = text_offset + address - text_address
    if address < text_address or offset < 0 or offset + length > len(raw):
        raise ValueError("address is not backed by original __text: {}".format(hex(address)))
    return raw[offset:offset + length]


def owner(address, starts, candidates):
    position = bisect.bisect_right(starts, address) - 1
    if position >= 0 and address < int(candidates[position]["end"], 16):
        return candidates[position]
    return None


def c_metadata(path):
    text = path.read_text(encoding="utf-8", errors="replace")
    lines = text.splitlines()
    first_code = ""
    for line in lines:
        stripped = line.strip()
        if stripped and not stripped.startswith("/*") and not stripped.startswith("*") and not stripped.startswith("//"):
            first_code = stripped
            break
    return {
        "path": str(path.relative_to(ROOT)),
        "sha256_recomputed_with_python": sha256(path.read_bytes()),
        "byte_length_recomputed_with_python": len(text.encode("utf-8")),
        "line_count_recomputed_with_python": len(lines),
        "warning_comment_count_recomputed_with_python": sum("WARNING:" in line for line in lines),
        "first_noncomment_line_observation": first_code,
    }


def main():
    failures = json.loads(FAILURES.read_text(encoding="utf-8"))
    manual = json.loads(MANUAL.read_text(encoding="utf-8"))
    native = json.loads(NATIVE.read_text(encoding="utf-8"))
    result = {
        "schema": 1,
        "scope": "per-function manual static-analysis completion records for all prior live-callback GhidraDec failures, based on original bytes plus separately bounded native-Ghidra C hypotheses",
        "interpretation_limit": "Original-byte checks validate only bytes and static addresses. Native Ghidra C, names, types, calls, and control flow are hypotheses. This does not establish behavior, execution, reachability, ABI, arguments, return values, code/data truth, or true function boundaries.",
        "architectures": {},
    }
    all_complete = True
    for arch in ARCHES:
        raw = (ROOT / "03_original" / arch / "binaries/mach_kernel").read_bytes()
        text_address, text_offset = mapping(arch)
        index_path = ROOT / "05_ida/exports" / arch / "function-asm-index.json"
        candidates = sorted(json.loads(index_path.read_text(encoding="utf-8")), key=lambda row: int(row["start"], 16))
        starts = [int(row["start"], 16) for row in candidates]
        candidate_by_start = {int(row["start"], 16): row for row in candidates}
        units_path = ROOT / "05_ida/exports" / arch / "text-units.tsv"
        units = {int(row["address"], 16): row for row in read_tsv(units_path)}
        xrefs_path = ROOT / "05_ida/exports" / arch / "xrefs.tsv"
        type19 = [row for row in read_tsv(xrefs_path) if row["type"] == "19"]
        calls_path = ROOT / "05_ida/exports" / arch / "direct-call-edges.tsv"
        calls = read_tsv(calls_path)
        manual_cards = {int(row["address"], 16): row for row in manual["architectures"][arch]["cards"]}
        native_rows = {int(row["address"], 16): row for row in native["architectures"][arch]["rows"]}
        records = []
        for failure in failures[arch]["failures"]:
            address = failure["address"]
            candidate = candidate_by_start.get(address)
            card = manual_cards.get(address)
            native_row = native_rows.get(address)
            if candidate is None or card is None or native_row is None:
                raise RuntimeError("missing candidate/manual/native record: {}".format(hex(address)))
            begin, end = int(candidate["start"], 16), int(candidate["end"], 16)
            outgoing_calls = [row for row in calls if begin <= int(row["source"], 16) < end]
            incoming_calls = [row for row in calls if int(row["target"], 16) == begin]
            outgoing_type19 = [row for row in type19 if begin <= int(row["from"], 16) < end]
            call_ok = all(raw_at(raw, text_address, text_offset, int(row["source"], 16), len(bytes.fromhex(row["instruction_bytes"]))) == bytes.fromhex(row["instruction_bytes"]) for row in outgoing_calls + incoming_calls)
            type19_ok = True
            relations = {}
            for row in outgoing_type19:
                source = int(row["from"], 16)
                unit = units.get(source)
                if unit is None:
                    type19_ok = False
                    continue
                encoded = bytes.fromhex(unit["bytes"])
                type19_ok = type19_ok and raw_at(raw, text_address, text_offset, source, len(encoded)) == encoded
                target_owner = owner(int(row["to"], 16), starts, candidates)
                relation = "same_candidate" if target_owner is candidate else ("other_candidate" if target_owner else "candidate_gap_or_noncandidate")
                relations[relation] = relations.get(relation, 0) + 1
            native_status = native_row["native_ghidra_status"]
            native_c = None
            if native_status == "success_exact_function":
                c_path = ROOT / native_row["c_hypothesis"]
                native_c = c_metadata(c_path)
                if native_c["sha256_recomputed_with_python"] != native_row["c_hypothesis_sha256_recomputed_with_python"]:
                    raise RuntimeError("persistent native C hash changed: {}".format(c_path))
                if native_row["body_range_matches_ida_candidate"]:
                    disposition = "native C hypothesis retained for the same current candidate range; manual interpretation remains unproven"
                else:
                    disposition = "native C hypothesis retained separately but excluded from full-candidate interpretation because Ghidra body range differs"
            elif native_status == "no_exact_ghidra_function":
                disposition = "assembly-only manual record; no native C promoted because Ghidra has no exact function at the current candidate start"
            else:
                raise RuntimeError("unexpected native status: " + native_status)
            complete = (card["all_listed_item_bytes_match_original"] and
                        card["all_listed_items_are_inside_candidate_range"] and call_ok and type19_ok)
            all_complete = all_complete and complete
            records.append({
                "address": "0x{:x}".format(address),
                "prior_ghidradec_failure_kind": failure["kind"],
                "ida_name_observation": failure.get("name", candidate["name"]),
                "current_ida_candidate_range": {"start": candidate["start"], "end": candidate["end"], "size": candidate["size"]},
                "original_candidate_bytes_sha256_recomputed_with_python": card["candidate_range_original_bytes_sha256_recomputed_with_python"],
                "assembly_evidence": {"path": card["assembly_path"], "all_listed_bytes_match_original": card["all_listed_item_bytes_match_original"],
                                      "all_items_inside_candidate": card["all_listed_items_are_inside_candidate_range"],
                                      "entry_item": card["entry_item"], "trailing_items": card["trailing_items"],
                                      "lexical_return_item_count_recomputed_with_python": len(card["lexical_return_mnemonic_items"])},
                "direct_call_evidence": {"outgoing_count_recomputed_with_python": len(outgoing_calls),
                                         "incoming_to_candidate_start_count_recomputed_with_python": len(incoming_calls),
                                         "all_instruction_bytes_match_original": call_ok},
                "type19_xref_evidence": {"outgoing_count_recomputed_with_python": len(outgoing_type19),
                                           "source_item_bytes_match_original": type19_ok,
                                           "target_candidate_relation_counts": relations},
                "native_ghidra": None if native_c is None else {"body_range_matches_ida_candidate": native_row["body_range_matches_ida_candidate"], "c_hypothesis": native_c},
                "manual_analysis_disposition": disposition,
                "all_required_original_byte_evidence_checks_pass": complete,
            })
        complete = all(row["all_required_original_byte_evidence_checks_pass"] for row in records)
        result["architectures"][arch] = {
            "architecture_endianness": "big",
            "original_binary_sha256_recomputed_with_python": sha256(raw),
            "failure_record_count_recomputed_with_python": len(records),
            "native_c_aligned_candidate_count_recomputed_with_python": sum(row["native_ghidra"] is not None and row["native_ghidra"]["body_range_matches_ida_candidate"] for row in records),
            "native_c_boundary_disagreement_count_recomputed_with_python": sum(row["native_ghidra"] is not None and not row["native_ghidra"]["body_range_matches_ida_candidate"] for row in records),
            "assembly_only_no_exact_native_function_count_recomputed_with_python": sum(row["native_ghidra"] is None for row in records),
            "all_records_have_required_original_byte_evidence": complete,
            "records": records,
        }
    result["all_manual_analysis_records_complete"] = all_complete
    OUTPUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if not all_complete:
        raise SystemExit("a manual analysis record has missing original-byte evidence")
    print(json.dumps({"output": str(OUTPUT.relative_to(ROOT)), "all_manual_analysis_records_complete": all_complete}, sort_keys=True))


if __name__ == "__main__":
    main()
