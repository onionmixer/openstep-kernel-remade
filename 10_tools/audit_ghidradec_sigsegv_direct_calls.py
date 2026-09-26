"""Make raw direct-call evidence cards for single-candidate GhidraDec SIGSEGVs.

This does not infer that a call executes, returns, or establishes an ABI.  It
only connects original-byte-checked direct-call records to the already
separated failure candidates.
"""
import csv
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORTS = ROOT / "09_validation/reports/multiarch-input-20260921"
FAILURES = REPORTS / "ghidradec-live-callback-failure-asm-coverage-20260923.json"
OUTPUT = REPORTS / "ghidradec-sigsegv-direct-call-evidence-20260923.json"
ARCHES = ("m68k", "sparc")


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def read_tsv(path):
    with path.open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream, delimiter="\t"))


def raw_text_mapping(arch):
    inventory = json.loads((ROOT / "03_original" / arch / "inventory/macho.json").read_text(encoding="utf-8"))
    section = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    return int(section["address"], 16), section["file_offset"]


def raw_at(raw, text_address, text_offset, address, length):
    offset = text_offset + address - text_address
    if address < text_address or offset < 0 or offset + length > len(raw):
        raise ValueError("address is not file-backed original __text: {}".format(hex(address)))
    return raw[offset:offset + length]


def owner(candidates, address):
    for candidate in candidates:
        if int(candidate["start"], 16) <= address < int(candidate["end"], 16):
            return candidate
    return None


def compact_edge(row, candidate_by_start, candidates, direction):
    source, target = int(row["source"], 16), int(row["target"], 16)
    related = candidate_by_start.get(target) if direction == "outgoing" else owner(candidates, source)
    return {
        "source": row["source"],
        "target": row["target"],
        "edge_kind": row["edge_kind"],
        "instruction_bytes": row["instruction_bytes"],
        "target_raw_symbols_observation": row["target_raw_symbols"],
        "ida_xref_type_observation": row["xref_type"],
        "ida_xref_iscode_observation": row["xref_iscode"],
        ("target_is_candidate_start" if direction == "outgoing" else "source_owner_candidate"): (
            None if related is None else {"start": related["start"], "end": related["end"], "name": related["name"]}
        ),
    }


def main():
    failures = json.loads(FAILURES.read_text(encoding="utf-8"))
    result = {
        "schema": 1,
        "scope": "original-byte recheck of direct-call edge records entering or originating inside single-candidate GhidraDec SIGSEGV failure candidates; no execution, return, ABI, ownership, boundary, or behavior conclusion",
        "architectures": {},
    }
    all_pass = True
    for arch in ARCHES:
        raw = (ROOT / "03_original" / arch / "binaries/mach_kernel").read_bytes()
        text_address, text_offset = raw_text_mapping(arch)
        index_path = ROOT / "05_ida/exports" / arch / "function-asm-index.json"
        candidates = json.loads(index_path.read_text(encoding="utf-8"))
        candidate_by_start = {int(row["start"], 16): row for row in candidates}
        edge_path = ROOT / "05_ida/exports" / arch / "direct-call-edges.tsv"
        edges = read_tsv(edge_path)
        sigsegv = [row for row in failures[arch]["failures"] if row["kind"] == "fresh_copied_db_fatal_plugin_failure"]
        cards = []
        for failure in sigsegv:
            start = failure["address"]
            candidate = candidate_by_start.get(start)
            if candidate is None:
                raise ValueError("SIGSEGV address missing from candidate index: {}".format(hex(start)))
            end = int(candidate["end"], 16)
            outgoing = [row for row in edges if start <= int(row["source"], 16) < end]
            incoming = [row for row in edges if int(row["target"], 16) == start]
            all_related = outgoing + incoming
            byte_checks = []
            for row in all_related:
                source = int(row["source"], 16)
                listed = bytes.fromhex(row["instruction_bytes"])
                byte_checks.append({
                    "source": row["source"],
                    "instruction_bytes_match_original": raw_at(raw, text_address, text_offset, source, len(listed)) == listed,
                })
            cards.append({
                "address": "0x{:x}".format(start),
                "ida_name_observation": failure["name"],
                "candidate_range": {"start": candidate["start"], "end": candidate["end"], "size": candidate["size"]},
                "prior_single_candidate_plugin_return_code": failure["return_code"],
                "outgoing_direct_call_count_recomputed_with_python": len(outgoing),
                "incoming_direct_call_to_candidate_start_count_recomputed_with_python": len(incoming),
                "all_related_direct_call_bytes_match_original": all(row["instruction_bytes_match_original"] for row in byte_checks),
                "direct_call_byte_checks": byte_checks,
                "outgoing_direct_call_edges": [compact_edge(row, candidate_by_start, candidates, "outgoing") for row in outgoing],
                "incoming_direct_call_edges": [compact_edge(row, candidate_by_start, candidates, "incoming") for row in incoming],
                "interpretation_limit": "These are static source/target address relations from direct-call encodings. They do not establish that an edge executes or returns, or any callee meaning, ABI, parameter, return-value, ownership, or function-boundary truth.",
            })
        byte_ok = all(card["all_related_direct_call_bytes_match_original"] for card in cards)
        all_pass = all_pass and byte_ok
        result["architectures"][arch] = {
            "architecture_endianness": "big",
            "original_binary_sha256_recomputed_with_python": sha256(raw),
            "candidate_index_sha256_recomputed_with_python": sha256(index_path.read_bytes()),
            "direct_call_edge_tsv": str(edge_path.relative_to(ROOT)),
            "direct_call_edge_tsv_sha256_recomputed_with_python": sha256(edge_path.read_bytes()),
            "sigsegv_candidate_count_recomputed_with_python": len(cards),
            "all_related_direct_call_bytes_match_original": byte_ok,
            "cards": cards,
        }
    result["all_architectures_pass"] = all_pass
    OUTPUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if not all_pass:
        raise SystemExit("SIGSEGV direct-call raw-byte audit failed")
    print(json.dumps({"output": str(OUTPUT.relative_to(ROOT)), "all_architectures_pass": all_pass}, sort_keys=True))


if __name__ == "__main__":
    main()
