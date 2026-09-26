"""Add bounded original-byte evidence and conservative dispositions for deferred layout.

It intentionally distinguishes raw address/byte facts from code/data truth,
function ownership, transfer execution, return behavior, ABI, and behavior.
"""
import bisect
import csv
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORTS = ROOT / "09_validation/reports/multiarch-input-20260921"
GAPS = REPORTS / "candidate-gap-bounded-text-layout-audit.json"
UNKNOWN = REPORTS / "m68k-unknown-text-unit-review.json"
OUTPUT = REPORTS / "deferred-meaning-disposition-audit-20260923.json"
ARCHES = ("m68k", "sparc")


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def read_tsv(path):
    with path.open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream, delimiter="\t"))


def mapping(arch):
    inventory = json.loads((ROOT / "03_original" / arch / "inventory/macho.json").read_text(encoding="utf-8"))
    text = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    start = int(text["address"], 16)
    return start, start + int(text["size"]), text["file_offset"]


def raw_at(raw, text_start, text_offset, address, length):
    offset = text_offset + address - text_start
    if address < text_start or offset < 0 or offset + length > len(raw):
        raise ValueError("not a file-backed original __text address: {}".format(hex(address)))
    return raw[offset:offset + length]


def candidate_at(address, starts, candidates):
    index = bisect.bisect_right(starts, address) - 1
    if index >= 0 and address < int(candidates[index]["end"], 16):
        return candidates[index]
    return None


def gap_at(address, gaps):
    for gap in gaps:
        if gap["start"] <= address < gap["end"]:
            return gap
    return None


def unit_observation(unit, raw, text_start, text_offset):
    encoded = bytes.fromhex(unit["bytes"])
    address = int(unit["address"], 16)
    return {
        "address": unit["address"],
        "kind": unit["kind"],
        "original_bytes": encoded.hex(),
        "original_bytes_match_exported_item": raw_at(raw, text_start, text_offset, address, len(encoded)) == encoded,
        "ida_disassembly_observation": unit["disassembly"],
    }


def xref_observation(xref, units, raw, text_start, text_offset):
    source = int(xref["from"], 16)
    unit = units.get(source)
    if unit is None:
        return {"source": xref["from"], "target": xref["to"], "source_has_current_text_item": False,
                "ida_xref_type_observation": xref["type"], "ida_xref_iscode_observation": xref["iscode"]}
    return {"source": unit_observation(unit, raw, text_start, text_offset), "target": xref["to"],
            "source_has_current_text_item": True, "ida_xref_type_observation": xref["type"],
            "ida_xref_iscode_observation": xref["iscode"]}


def direct_call_observation(edge, raw, text_start, text_offset):
    source = int(edge["source"], 16)
    encoded = bytes.fromhex(edge["instruction_bytes"])
    return {"source": edge["source"], "target": edge["target"], "edge_kind": edge["edge_kind"],
            "original_instruction_bytes": encoded.hex(),
            "original_instruction_bytes_match_edge": raw_at(raw, text_start, text_offset, source, len(encoded)) == encoded,
            "target_raw_symbols_observation": edge["target_raw_symbols"],
            "ida_xref_type_observation": edge["xref_type"], "ida_xref_iscode_observation": edge["xref_iscode"]}


def main():
    gap_report = json.loads(GAPS.read_text(encoding="utf-8"))
    result = {
        "schema": 1,
        "scope": "additional bounded original-byte evidence for retained m68k unknown, candidate gaps, and lexical no-exit candidates; conservative semantic dispositions only",
        "gap_input_sha256_recomputed_with_python": sha256(GAPS.read_bytes()),
        "architectures": {},
        "interpretation_limit": "Current item kinds, IDA xrefs, and direct-call encodings do not prove code/data truth, execution, branch condition, fallthrough, reachability, function ownership/boundaries, return behavior, ABI, or original behavior.",
    }
    all_bytes_match = True
    for arch in ARCHES:
        raw_path = ROOT / "03_original" / arch / "binaries/mach_kernel"
        raw = raw_path.read_bytes()
        text_start, text_end, text_offset = mapping(arch)
        index_path = ROOT / "05_ida/exports" / arch / "function-asm-index.json"
        candidates = sorted(json.loads(index_path.read_text(encoding="utf-8")), key=lambda row: int(row["start"], 16))
        starts = [int(row["start"], 16) for row in candidates]
        units_path = ROOT / "05_ida/exports" / arch / "text-units.tsv"
        units_rows = read_tsv(units_path)
        units = {int(row["address"], 16): row for row in units_rows}
        xrefs_path = ROOT / "05_ida/exports" / arch / "xrefs.tsv"
        xrefs = read_tsv(xrefs_path)
        calls_path = ROOT / "05_ida/exports" / arch / "direct-call-edges.tsv"
        calls = read_tsv(calls_path)
        gaps = [{"start": int(row["gap"]["start"], 16), "end": int(row["gap"]["end"], 16),
                 "source_gap_direct_transfer_count": row["direct_transfer_source_count"]}
                for row in gap_report["targets"][arch]["rows"]]
        gap_cards = []
        for gap in gaps:
            local_units = [row for address, row in units.items() if gap["start"] <= address < gap["end"]]
            local_units.sort(key=lambda row: int(row["address"], 16))
            item_kinds = {}
            for row in local_units:
                item_kinds[row["kind"]] = item_kinds.get(row["kind"], 0) + 1
            outgoing_xrefs = [row for row in xrefs if row["type"] == "19" and gap["start"] <= int(row["from"], 16) < gap["end"]]
            incoming_xrefs = [row for row in xrefs if row["type"] == "19" and gap["start"] <= int(row["to"], 16) < gap["end"]]
            outgoing_calls = [row for row in calls if gap["start"] <= int(row["source"], 16) < gap["end"]]
            incoming_calls = [row for row in calls if gap["start"] <= int(row["target"], 16) < gap["end"]]
            observed_items = [unit_observation(row, raw, text_start, text_offset) for row in local_units]
            xref_cards = [xref_observation(row, units, raw, text_start, text_offset) for row in outgoing_xrefs + incoming_xrefs]
            call_cards = [direct_call_observation(row, raw, text_start, text_offset) for row in outgoing_calls + incoming_calls]
            item_ok = all(row["original_bytes_match_exported_item"] for row in observed_items)
            xref_ok = all(not row["source_has_current_text_item"] or row["source"]["original_bytes_match_exported_item"] for row in xref_cards)
            call_ok = all(row["original_instruction_bytes_match_edge"] for row in call_cards)
            all_bytes_match = all_bytes_match and item_ok and xref_ok and call_ok
            gap_cards.append({
                "range": {"start": "0x{:x}".format(gap["start"]), "end": "0x{:x}".format(gap["end"]),
                          "byte_length_recomputed_with_python": gap["end"] - gap["start"]},
                "current_text_item_kind_counts": item_kinds,
                "first_current_item": None if not observed_items else observed_items[0],
                "last_current_item": None if not observed_items else observed_items[-1],
                "all_current_item_bytes_match_original": item_ok,
                "outgoing_type19_xref_count_recomputed_with_python": len(outgoing_xrefs),
                "incoming_type19_xref_count_recomputed_with_python": len(incoming_xrefs),
                "outgoing_direct_call_count_recomputed_with_python": len(outgoing_calls),
                "incoming_direct_call_count_recomputed_with_python": len(incoming_calls),
                "all_related_xref_source_and_direct_call_bytes_match_original": xref_ok and call_ok,
                "disposition": "retain candidate gap; direct address relations and current item kinds do not assign ownership or function boundaries",
            })
        terminal_path = ROOT / "05_ida/exports" / arch / "noexit-candidate-terminal-items.tsv"
        terminals = read_tsv(terminal_path)
        noexit_cards = []
        for terminal in terminals:
            start, end, terminal_address = (int(terminal[key], 16) for key in ("start", "end", "terminal_address"))
            terminal_bytes = bytes.fromhex(terminal["terminal_original_bytes"])
            next_unit = units.get(end)
            next_observation = None if next_unit is None else unit_observation(next_unit, raw, text_start, text_offset)
            terminal_xrefs = [row for row in xrefs if row["type"] == "19" and int(row["from"], 16) == terminal_address]
            terminal_calls = [row for row in calls if int(row["source"], 16) == terminal_address]
            xref_cards = [xref_observation(row, units, raw, text_start, text_offset) for row in terminal_xrefs]
            call_cards = [direct_call_observation(row, raw, text_start, text_offset) for row in terminal_calls]
            terminal_ok = raw_at(raw, text_start, text_offset, terminal_address, len(terminal_bytes)) == terminal_bytes
            xref_ok = all(not row["source_has_current_text_item"] or row["source"]["original_bytes_match_exported_item"] for row in xref_cards)
            call_ok = all(row["original_instruction_bytes_match_edge"] for row in call_cards)
            next_ok = next_observation is None or next_observation["original_bytes_match_exported_item"]
            all_bytes_match = all_bytes_match and terminal_ok and xref_ok and call_ok and next_ok
            next_relation = "no_current_text_item_at_candidate_end"
            if next_unit is not None:
                next_candidate = candidate_at(end, starts, candidates)
                next_relation = "next_item_at_another_candidate" if next_candidate and int(next_candidate["start"], 16) == end else ("next_item_inside_candidate_gap" if next_candidate is None else "next_item_inside_candidate")
            noexit_cards.append({
                "candidate": {"start": terminal["start"], "end": terminal["end"], "name": terminal["name"]},
                "terminal": {"address": terminal["terminal_address"], "bytes": terminal["terminal_original_bytes"],
                             "ida_disassembly_observation": terminal["terminal_ida_disassembly"], "mnemonic_observation": terminal["terminal_mnemonic"],
                             "bytes_match_original": terminal_ok},
                "next_current_text_item": next_observation,
                "next_item_relation": next_relation,
                "terminal_type19_xref_count_recomputed_with_python": len(terminal_xrefs),
                "terminal_direct_call_count_recomputed_with_python": len(terminal_calls),
                "all_related_item_and_direct_call_bytes_match_original": xref_ok and call_ok and next_ok,
                "disposition": "retain lexical no-exit; terminal syntax and adjacent current item do not establish runtime non-return or candidate boundary truth",
            })
        result["architectures"][arch] = {
            "architecture_endianness": "big",
            "original_binary_sha256_recomputed_with_python": sha256(raw),
            "candidate_gap_count_recomputed_with_python": len(gap_cards),
            "all_gap_related_bytes_match_original": all(card["all_current_item_bytes_match_original"] and card["all_related_xref_source_and_direct_call_bytes_match_original"] for card in gap_cards),
            "lexical_noexit_candidate_count_recomputed_with_python": len(noexit_cards),
            "all_noexit_related_bytes_match_original": all(card["terminal"]["bytes_match_original"] and card["all_related_item_and_direct_call_bytes_match_original"] for card in noexit_cards),
            "candidate_gaps": gap_cards,
            "lexical_noexit_candidates": noexit_cards,
        }
    unknown = json.loads(UNKNOWN.read_text(encoding="utf-8"))
    m68_raw = (ROOT / "03_original/m68k/binaries/mach_kernel").read_bytes()
    text_start, _text_end, text_offset = mapping("m68k")
    source = unknown["xref_destination_observation"]["source_text_item"]
    source_bytes = bytes.fromhex(source["bytes"])
    source_address = int(source["address"], 16)
    target = int(unknown["range_start"], 16)
    field = int.from_bytes(source_bytes[4:8], "big")
    unknown_bytes = bytes.fromhex(unknown["bytes"])
    unknown_ok = (raw_at(m68_raw, text_start, text_offset, source_address, len(source_bytes)) == source_bytes and
                  raw_at(m68_raw, text_start, text_offset, target, len(unknown_bytes)) == unknown_bytes and field == target)
    all_bytes_match = all_bytes_match and unknown_ok
    result["m68k_retained_unknown"] = {
        "range": {"start": unknown["range_start"], "end_exclusive": unknown["range_end_exclusive"], "bytes": unknown["bytes"]},
        "source_instruction": {"address": source["address"], "bytes": source["bytes"], "ida_disassembly_observation": source["disassembly"],
                               "embedded_big_endian_32bit_field": "0x{:x}".format(field), "field_equals_unknown_start": field == target,
                               "source_and_unknown_bytes_match_original": unknown_ok},
        "independent_decoder_observation": "sequential decoding can interpret the bytes as instructions, while the source is an IDA non-code xref; neither observation proves code/data truth or reachability",
        "disposition": "retain six bytes as unknown; static evidence records a memory-operand address relation but does not prove code/data classification",
    }
    result["all_original_byte_checks_pass"] = all_bytes_match
    OUTPUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if not all_bytes_match:
        raise SystemExit("deferred meaning disposition audit found an original-byte mismatch")
    print(json.dumps({"output": str(OUTPUT.relative_to(ROOT)), "all_original_byte_checks_pass": all_bytes_match}, sort_keys=True))


if __name__ == "__main__":
    main()
