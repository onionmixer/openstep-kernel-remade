"""Independently close raw-byte evidence for deferred multi-architecture layout items.

This audit deliberately records structural facts only.  It does not promote an
IDA candidate, a direct-transfer encoding, or a decoder rendering into a
function-boundary or execution claim.
"""

import csv
import hashlib
import json
from collections import Counter
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT_DIR = ROOT / "09_validation/reports/multiarch-input-20260921"
ARCHES = ("m68k", "sparc")
M68K_UNKNOWN_START = 0x0409CE56
M68K_UNKNOWN_LENGTH = 6
SPARC_DELAY_DATA = (0xF0007154, 0xF000721C)


def sha256_bytes(value):
    return hashlib.sha256(value).hexdigest()


def sha256_path(path):
    return sha256_bytes(path.read_bytes())


def read_tsv(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def read_architecture(arch):
    original = ROOT / "03_original" / arch / "binaries" / "mach_kernel"
    inventory_path = ROOT / "03_original" / arch / "inventory" / "macho.json"
    inventory = json.loads(inventory_path.read_text(encoding="utf-8"))
    text = next(item for item in inventory["sections"]
                if item["segment"] == "__TEXT" and item["name"] == "__text")
    units = read_tsv(ROOT / "05_ida/exports" / arch / "text-units.tsv")
    unit_map = {int(item["address"], 16): item for item in units}
    candidates = json.loads((ROOT / "05_ida/exports" / arch / "function-asm-index.json").read_text(encoding="utf-8"))
    xrefs = read_tsv(ROOT / "05_ida/exports" / arch / "xrefs.tsv")
    terminal_items = read_tsv(ROOT / "05_ida/exports" / arch / "noexit-candidate-terminal-items.tsv")
    return {
        "binary": original.read_bytes(),
        "sha256": sha256_path(original),
        "text_start": int(text["address"], 16),
        "text_file_offset": int(text["file_offset"]),
        "units": unit_map,
        "unit_addresses": sorted(unit_map),
        "candidates": candidates,
        "xrefs": xrefs,
        "terminal_items": terminal_items,
    }


def original_at(arch_data, address, length):
    position = arch_data["text_file_offset"] + address - arch_data["text_start"]
    assert position >= 0
    result = arch_data["binary"][position:position + length]
    assert len(result) == length
    return position, result


def preceding_unit(arch_data, address):
    matches = []
    for item_address in arch_data["unit_addresses"]:
        item = arch_data["units"][item_address]
        if item_address + int(item["length"]) == address:
            matches.append((item_address, item))
    assert len(matches) == 1
    return matches[0]


def next_unit(arch_data, address):
    item = arch_data["units"].get(address)
    assert item is not None
    return item


def containing_candidates(arch_data, address):
    return [item for item in arch_data["candidates"]
            if int(item["start"], 16) <= address < int(item["end"], 16)]


def contiguous_raw_span(arch_data, start, end_exclusive):
    """Verify every exported text unit exactly tiles a deferred gap."""
    address = start
    item_count = 0
    kind_counts = Counter()
    assembled = bytearray()
    while address < end_exclusive:
        item = arch_data["units"].get(address)
        assert item is not None
        item_length = int(item["length"])
        assert address + item_length <= end_exclusive
        item_raw_offset, item_raw = original_at(arch_data, address, item_length)
        assert item_raw.hex() == item["bytes"]
        assert item_raw_offset == arch_data["text_file_offset"] + address - arch_data["text_start"]
        assembled.extend(item_raw)
        item_count += 1
        kind_counts[item["kind"]] += 1
        address += item_length
    assert address == end_exclusive
    raw_offset, original = original_at(arch_data, start, end_exclusive - start)
    assert bytes(assembled) == original
    return {
        "start": hex(start),
        "end_exclusive": hex(end_exclusive),
        "file_offset": raw_offset,
        "byte_length": end_exclusive - start,
        "text_item_count": item_count,
        "text_item_kind_counts": dict(sorted(kind_counts.items())),
        "original_span_sha256_recomputed_with_python": sha256_bytes(original),
    }


def audit_unknown(m68k):
    start = M68K_UNKNOWN_START
    end_exclusive = start + M68K_UNKNOWN_LENGTH
    offset, raw = original_at(m68k, start, M68K_UNKNOWN_LENGTH)
    assert raw.hex() == "c1e000000000"
    unknown_units = []
    for address in range(start, end_exclusive):
        item = m68k["units"].get(address)
        assert item is not None and item["kind"] == "unknown" and int(item["length"]) == 1
        unit_offset, unit_raw = original_at(m68k, address, 1)
        assert unit_offset == offset + address - start
        assert unit_raw.hex() == item["bytes"]
        unknown_units.append(item)
    incoming = [item for item in m68k["xrefs"] if int(item["to"], 16) == start]
    assert incoming == [{"from": "0x409e084", "to": "0x409ce56", "type": "3", "iscode": "0"}]
    source = int(incoming[0]["from"], 16)
    source_unit = m68k["units"][source]
    source_offset, source_raw = original_at(m68k, source, int(source_unit["length"]))
    literal_field = int.from_bytes(source_raw[-4:], byteorder="big", signed=False)
    assert literal_field == start
    previous_address, previous = preceding_unit(m68k, start)
    following = next_unit(m68k, end_exclusive)
    assert previous["kind"] == "data" and following["kind"] == "data"
    assert containing_candidates(m68k, start) == []
    return {
        "range": {"start": hex(start), "end_exclusive": hex(end_exclusive), "file_offset": offset,
                  "byte_length": M68K_UNKNOWN_LENGTH, "original_big_endian_bytes": raw.hex()},
        "ida_unit_state": {"unit_count": len(unknown_units), "kind": "unknown", "unit_length": 1},
        "incoming_noncode_xref": incoming[0],
        "source_raw_field": {
            "source_address": hex(source), "source_file_offset": source_offset,
            "source_original_bytes": source_raw.hex(), "field_offset_in_source": len(source_raw) - 4,
            "unsigned_big_endian_32bit_value": hex(literal_field), "equals_unknown_start": True,
            "ida_disassembly_observation": source_unit["disassembly"],
        },
        "adjacent_ida_items": {
            "previous": {"address": hex(previous_address), "kind": previous["kind"], "bytes": previous["bytes"]},
            "following": {"address": hex(end_exclusive), "kind": following["kind"], "bytes": following["bytes"]},
        },
        "overlapping_ida_candidate_count": 0,
        "required_disposition": "retain as six IDA unknown bytes",
    }


def audit_sparc_delay_data(sparc):
    rows = []
    for address in SPARC_DELAY_DATA:
        item = sparc["units"].get(address)
        assert item is not None and item["kind"] == "data" and int(item["length"]) == 4
        offset, raw = original_at(sparc, address, 4)
        assert raw.hex() == item["bytes"] == "01000000"
        predecessor_address, predecessor = preceding_unit(sparc, address)
        predecessor_offset, predecessor_raw = original_at(sparc, predecessor_address, int(predecessor["length"]))
        following = next_unit(sparc, address + 4)
        following_offset, following_raw = original_at(sparc, address + 4, int(following["length"]))
        assert predecessor_address == address - 4
        assert predecessor["kind"] == "code" and predecessor_raw.hex() == predecessor["bytes"] == "81c3e008"
        assert predecessor["disassembly"] == "retl"
        assert following["kind"] == "code" and following_raw.hex() == following["bytes"]
        assert containing_candidates(sparc, address) == []
        incoming = [item for item in sparc["xrefs"] if int(item["to"], 16) == address]
        assert incoming == []
        rows.append({
            "address": hex(address), "file_offset": offset, "ida_kind": item["kind"],
            "original_big_endian_word": raw.hex(), "raw_unsigned_big_endian_32bit_value": hex(int.from_bytes(raw, "big")),
            "immediate_predecessor": {"address": hex(predecessor_address), "file_offset": predecessor_offset,
                                      "kind": predecessor["kind"], "bytes": predecessor_raw.hex(),
                                      "ida_disassembly_observation": predecessor["disassembly"]},
            "immediate_following": {"address": hex(address + 4), "file_offset": following_offset,
                                    "kind": following["kind"], "bytes": following_raw.hex(),
                                    "ida_disassembly_observation": following["disassembly"]},
            "incoming_xref_count": len(incoming), "overlapping_ida_candidate_count": 0,
        })
    return {"address_count": len(rows), "rows": rows,
            "required_disposition": "retain both words as IDA data"}


def audit_gap_spans(arch, arch_data, bounded_report):
    result_rows = []
    for row in bounded_report["targets"][arch]["rows"]:
        gap = row["gap"]
        start = int(gap["start"], 16)
        end_exclusive = int(gap["end"], 16)
        observed = contiguous_raw_span(arch_data, start, end_exclusive)
        assert observed["byte_length"] == gap["byte_length"]
        assert observed["original_span_sha256_recomputed_with_python"] == row["original_span_sha256_recomputed_with_python"]
        result_rows.append(observed)
    totals = {
        "gap_count": len(result_rows),
        "total_byte_length_recomputed_with_python": sum(row["byte_length"] for row in result_rows),
        "total_text_item_count_recomputed_with_python": sum(row["text_item_count"] for row in result_rows),
        "all_gap_spans_are_contiguous_and_match_original_bytes": True,
    }
    assert totals["gap_count"] == bounded_report["targets"][arch]["direct_transfer_gap_count"]
    assert totals["total_byte_length_recomputed_with_python"] == bounded_report["targets"][arch]["total_bounded_gap_byte_length"]
    return totals


def audit_noexit_terminals(arch_data, closure_arch):
    terminal_rows = []
    mnemonic_counts = Counter()
    for item in arch_data["terminal_items"]:
        start = int(item["start"], 16)
        end = int(item["end"], 16)
        terminal_address = int(item["terminal_address"], 16)
        terminal_unit = arch_data["units"].get(terminal_address)
        assert terminal_unit is not None and terminal_unit["kind"] == "code"
        terminal_length = int(terminal_unit["length"])
        offset, original = original_at(arch_data, terminal_address, terminal_length)
        assert original.hex() == terminal_unit["bytes"] == item["terminal_original_bytes"]
        assert terminal_address + terminal_length == end
        assert len(containing_candidates(arch_data, terminal_address)) == 1
        assert start <= terminal_address < end
        mnemonic_counts[item["terminal_mnemonic"]] += 1
        terminal_rows.append({"candidate_start": item["start"], "candidate_end": item["end"],
                              "terminal_address": item["terminal_address"], "file_offset": offset,
                              "original_bytes": original.hex(), "mnemonic": item["terminal_mnemonic"]})
    expected_count = closure_arch["noexit_terminal_candidate_count"]
    assert len(terminal_rows) == expected_count
    assert sum(closure_arch["raw_audit_assignment_counts"].values()) == expected_count
    return {
        "terminal_candidate_count": len(terminal_rows),
        "terminal_items_end_exactly_at_candidate_end": True,
        "all_terminal_item_bytes_recomputed_from_original": True,
        "raw_audit_assignment_count_recomputed_with_python": sum(closure_arch["raw_audit_assignment_counts"].values()),
        "terminal_mnemonic_counts": dict(sorted(mnemonic_counts.items())),
    }


def main():
    data = {arch: read_architecture(arch) for arch in ARCHES}
    bounded_path = REPORT_DIR / "candidate-gap-bounded-text-layout-audit.json"
    topology_path = REPORT_DIR / "candidate-gap-all-direct-transfer-topology-audit.json"
    noexit_path = REPORT_DIR / "noexit-terminal-raw-coverage-closure-audit.json"
    bounded = json.loads(bounded_path.read_text(encoding="utf-8"))
    topology = json.loads(topology_path.read_text(encoding="utf-8"))
    noexit = json.loads(noexit_path.read_text(encoding="utf-8"))
    for arch in ARCHES:
        assert data[arch]["sha256"] == bounded["targets"][arch]["original_sha256_recomputed_with_python"]
        assert data[arch]["sha256"] == topology["targets"][arch]["original_sha256_recomputed_with_python"]
        assert data[arch]["sha256"] == noexit["architectures"][arch]["original_sha256_recomputed_with_python"]
    result = {
        "schema": 1,
        "scope": "raw layout deferred-item evidence closure; original kernel and analysis exports only",
        "original_sha256_recomputed_with_python": {arch: data[arch]["sha256"] for arch in ARCHES},
        "input_report_sha256_recomputed_with_python": {
            bounded_path.name: sha256_path(bounded_path), topology_path.name: sha256_path(topology_path),
            noexit_path.name: sha256_path(noexit_path),
        },
        "m68k_retained_unknown": audit_unknown(data["m68k"]),
        "sparc_retained_delay_data": audit_sparc_delay_data(data["sparc"]),
        "candidate_gap_raw_spans": {arch: {
            **audit_gap_spans(arch, data[arch], bounded),
            "raw_verified_direct_transfer_count_from_input_audit": topology["targets"][arch]["candidate_gap_all_direct_transfer_count"],
        } for arch in ARCHES},
        "noexit_terminal_items": {arch: audit_noexit_terminals(data[arch], noexit["architectures"][arch]) for arch in ARCHES},
        "interpretation_limit": (
            "This closes byte identity, item adjacency, literal-field equality, and coverage assignment only. "
            "It does not establish code-versus-data truth for the m68k unknown bytes, SPARC delay-slot execution, "
            "path reachability, function ownership or boundaries, transfer semantics, return behavior, ABI, or behavior."
        ),
        "disposition": {
            "m68k_unknown": "remain IDA unknown",
            "sparc_delay_data": "remain IDA data",
            "candidate_gaps": "retain as raw-layout candidate gaps; do not assign function ownership",
            "noexit": "retain as lexical no-exit candidates; do not infer runtime non-return or function behavior",
        },
    }
    output = REPORT_DIR / "raw-layout-deferred-evidence-closure-20260922.json"
    output.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({
        "output": str(output.relative_to(ROOT)),
        "gap_counts": {arch: result["candidate_gap_raw_spans"][arch]["gap_count"] for arch in ARCHES},
        "noexit_counts": {arch: result["noexit_terminal_items"][arch]["terminal_candidate_count"] for arch in ARCHES},
        "all_checks_passed": True,
    }, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
