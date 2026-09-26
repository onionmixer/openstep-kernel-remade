"""Preserve original-byte evidence for type-19 xrefs in SIGSEGV candidates."""
import bisect
import csv
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORTS = ROOT / "09_validation/reports/multiarch-input-20260921"
FAILURES = REPORTS / "ghidradec-live-callback-failure-asm-coverage-20260923.json"
OUTPUT = REPORTS / "ghidradec-sigsegv-type19-xref-evidence-20260923.json"
ARCHES = ("m68k", "sparc")


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def read_tsv(path):
    with path.open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream, delimiter="\t"))


def text_mapping(arch):
    inventory = json.loads((ROOT / "03_original" / arch / "inventory/macho.json").read_text(encoding="utf-8"))
    section = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    start = int(section["address"], 16)
    return start, start + int(section["size"]), section["file_offset"]


def raw_at(raw, text_start, text_offset, address, length):
    offset = text_offset + address - text_start
    if address < text_start or offset < 0 or offset + length > len(raw):
        raise ValueError("not a file-backed original __text address: {}".format(hex(address)))
    return raw[offset:offset + length]


def candidate_owner(address, starts, candidates):
    index = bisect.bisect_right(starts, address) - 1
    if index >= 0 and address < int(candidates[index]["end"], 16):
        return candidates[index]
    return None


def item_observation(unit, raw, text_start, text_offset):
    item_bytes = bytes.fromhex(unit["bytes"])
    return {
        "address": unit["address"],
        "kind": unit["kind"],
        "ida_disassembly_observation": unit["disassembly"],
        "original_bytes": item_bytes.hex(),
        "original_bytes_match_exported_item": raw_at(raw, text_start, text_offset, int(unit["address"], 16), len(item_bytes)) == item_bytes,
    }


def main():
    failures = json.loads(FAILURES.read_text(encoding="utf-8"))
    result = {
        "schema": 1,
        "scope": "type-19 IDA xref source/target observations from original big-endian bytes for fresh-copied-DB GhidraDec SIGSEGV candidates; no transfer execution, condition, delay-slot, fallthrough, reachability, ABI, ownership, boundary, or behavior conclusion",
        "architectures": {},
    }
    all_pass = True
    for arch in ARCHES:
        raw = (ROOT / "03_original" / arch / "binaries/mach_kernel").read_bytes()
        text_start, text_end, text_offset = text_mapping(arch)
        index_path = ROOT / "05_ida/exports" / arch / "function-asm-index.json"
        candidates = sorted(json.loads(index_path.read_text(encoding="utf-8")), key=lambda row: int(row["start"], 16))
        starts = [int(row["start"], 16) for row in candidates]
        units_path = ROOT / "05_ida/exports" / arch / "text-units.tsv"
        units = {int(row["address"], 16): row for row in read_tsv(units_path)}
        xrefs_path = ROOT / "05_ida/exports" / arch / "xrefs.tsv"
        xrefs = [row for row in read_tsv(xrefs_path) if row["type"] == "19"]
        sigsegv = [row for row in failures[arch]["failures"] if row["kind"] == "fresh_copied_db_fatal_plugin_failure"]
        cards = []
        for failure in sigsegv:
            candidate = candidate_owner(failure["address"], starts, candidates)
            if candidate is None or int(candidate["start"], 16) != failure["address"]:
                raise ValueError("SIGSEGV function candidate missing: {}".format(hex(failure["address"])))
            begin, end = int(candidate["start"], 16), int(candidate["end"], 16)
            edges = []
            for xref in xrefs:
                source, target = int(xref["from"], 16), int(xref["to"], 16)
                if not begin <= source < end:
                    continue
                source_unit = units.get(source)
                if source_unit is None:
                    raise ValueError("type-19 source lacks a __text item: {}".format(hex(source)))
                source_observation = item_observation(source_unit, raw, text_start, text_offset)
                target_unit = units.get(target)
                if target_unit is not None:
                    target_observation = item_observation(target_unit, raw, text_start, text_offset)
                    target_owner = candidate_owner(target, starts, candidates)
                    relation = "same_candidate" if target_owner is candidate else ("other_candidate" if target_owner else "candidate_gap")
                else:
                    target_observation = None
                    target_owner = None
                    relation = "outside_current_text_item_starts" if not (text_start <= target < text_end) else "mapped_text_without_current_item_start"
                edges.append({
                    "source": source_observation,
                    "target": "0x{:x}".format(target),
                    "ida_xref_iscode_observation": xref["iscode"],
                    "target_item_observation": target_observation,
                    "target_relation_to_source_candidate": relation,
                    "target_candidate_observation": None if target_owner is None else {"start": target_owner["start"], "end": target_owner["end"], "name": target_owner["name"]},
                })
            bytes_ok = all(edge["source"]["original_bytes_match_exported_item"] and
                           (edge["target_item_observation"] is None or edge["target_item_observation"]["original_bytes_match_exported_item"])
                           for edge in edges)
            cards.append({
                "address": "0x{:x}".format(begin),
                "ida_name_observation": failure["name"],
                "candidate_range": {"start": candidate["start"], "end": candidate["end"], "size": candidate["size"]},
                "type19_xref_edge_count_recomputed_with_python": len(edges),
                "all_source_and_mapped_target_item_bytes_match_original": bytes_ok,
                "edges": edges,
            })
        byte_ok = all(card["all_source_and_mapped_target_item_bytes_match_original"] for card in cards)
        all_pass = all_pass and byte_ok
        result["architectures"][arch] = {
            "architecture_endianness": "big",
            "original_binary_sha256_recomputed_with_python": sha256(raw),
            "candidate_index_sha256_recomputed_with_python": sha256(index_path.read_bytes()),
            "text_units_tsv_sha256_recomputed_with_python": sha256(units_path.read_bytes()),
            "xrefs_tsv_sha256_recomputed_with_python": sha256(xrefs_path.read_bytes()),
            "sigsegv_candidate_count_recomputed_with_python": len(cards),
            "type19_xref_edge_count_recomputed_with_python": sum(card["type19_xref_edge_count_recomputed_with_python"] for card in cards),
            "all_source_and_mapped_target_item_bytes_match_original": byte_ok,
            "cards": cards,
        }
    result["all_architectures_pass"] = all_pass
    OUTPUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if not all_pass:
        raise SystemExit("SIGSEGV type-19 source/target original-byte audit failed")
    print(json.dumps({"output": str(OUTPUT.relative_to(ROOT)), "all_architectures_pass": all_pass}, sort_keys=True))


if __name__ == "__main__":
    main()
