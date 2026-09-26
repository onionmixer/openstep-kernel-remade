#!/usr/bin/env python3
"""Thirty isolated static audits for the preserved OS42J m68k and SPARC kernels."""
import csv
import hashlib
import json
import re
import struct
from pathlib import Path

import capstone


ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "09_validation/reports/multiarch-continuous-20260921"
ARCHES = ("m68k", "sparc")
EXPECTED = {
    "m68k": (6, "68K", "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75"),
    "sparc": (14, "sparcb", "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1"),
}


def digest(data):
    return hashlib.sha256(data).hexdigest()


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8"))


def tsv(path):
    with path.open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream, delimiter="\t"))


def load(arch):
    raw_path = ROOT / "03_original" / arch / "binaries/mach_kernel"
    return {
        "raw_path": raw_path,
        "raw": raw_path.read_bytes(),
        "inventory": read_json(ROOT / "03_original" / arch / "inventory/macho.json"),
        "symbols": tsv(ROOT / "03_original" / arch / "inventory/symbols.tsv"),
        "text": tsv(ROOT / "05_ida/exports" / arch / "text-units.tsv"),
        "text_summary": read_json(ROOT / "05_ida/exports" / arch / "text-units-summary.json"),
        "functions": read_json(ROOT / "05_ida/exports" / arch / "function-asm-index.json"),
        "function_summary": read_json(ROOT / "05_ida/exports" / arch / "function-asm-summary.json"),
        "xrefs": tsv(ROOT / "05_ida/exports" / arch / "xrefs.tsv"),
        "xref_summary": read_json(ROOT / "05_ida/exports" / arch / "xrefs-summary.json"),
    }


def segment_ranges(info):
    result = []
    for segment in info["inventory"]["segments"]:
        start = int(segment["address"], 16)
        result.append((start, start + segment["size"], start + segment["file_size"], segment["name"]))
    return result


def in_segment(ranges, address):
    return [entry for entry in ranges if entry[0] <= address < entry[1]]


def parse_load_commands(raw):
    magic, cpu, subtype, filetype, count, command_bytes, flags = struct.unpack_from(">IiiIIII", raw, 0)
    cursor = 28
    end = cursor + command_bytes
    commands = []
    for index in range(count):
        command, size = struct.unpack_from(">II", raw, cursor)
        assert size >= 8 and size % 4 == 0 and cursor + size <= end
        commands.append((index, command, cursor, size))
        cursor += size
    assert cursor == end and end <= len(raw)
    return {"magic": magic, "cpu": cpu, "subtype": subtype, "filetype": filetype, "flags": flags, "commands": commands}


def decoder(arch):
    if arch == "m68k":
        return capstone.Cs(capstone.CS_ARCH_M68K, capstone.CS_MODE_BIG_ENDIAN | capstone.CS_MODE_M68K_000)
    return capstone.Cs(capstone.CS_ARCH_SPARC, capstone.CS_MODE_BIG_ENDIAN)


def main():
    if OUT.exists():
        raise SystemExit("refusing to overwrite existing round directory")
    OUT.mkdir(parents=True)
    provenance = read_json(ROOT / "03_original/installation-media/os42j/provenance.json")
    container_path = ROOT / provenance["container"]["destination"]
    container = container_path.read_bytes()
    info = {arch: load(arch) for arch in ARCHES}
    rounds = []

    def add(slug, details, status="pass"):
        number = len(rounds) + 1
        record = {"schema": 1, "round": number, "slug": slug, "status": status, "details": details}
        (OUT / ("%03d-%s.json" % (number, slug))).write_text(json.dumps(record, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        rounds.append(record)

    # 001-008: provenance and raw Mach-O structure
    assert digest(container) == provenance["container"]["sha256"] and len(container) == provenance["container"]["size"]
    add("container-hash", {"sha256": digest(container), "size": len(container), "fat_magic": container[:4].hex().upper()})
    count = struct.unpack_from(">I", container, 4)[0]
    assert count == provenance["container"]["fat_arch_count"]
    add("fat-architecture-count", {"fat_arch_count": count})
    for arch in ARCHES:
        entry = next(row for row in provenance["slices"] if row["architecture"] == arch)
        index = entry["fat_index"]
        cpu, subtype, offset, size, align = struct.unpack_from(">IIIII", container, 8 + index * 20)
        raw = info[arch]["raw"]
        assert offset + size <= len(container) and container[offset:offset + size] == raw
        assert cpu == int(entry["cputype_raw"], 16) and subtype == int(entry["cpusubtype_raw"], 16)
        add("%s-fat-slice" % arch, {"fat_index": index, "offset": offset, "size": size, "alignment_exponent": align, "sha256": digest(raw)})
    for arch in ARCHES:
        current = info[arch]
        cpu, processor, expected_hash = EXPECTED[arch]
        assert digest(current["raw"]) == expected_hash == current["inventory"]["sha256"]
        assert current["raw"][:4] == b"\xfe\xed\xfa\xce" and current["inventory"]["endian"] == "big"
        assert current["inventory"]["cpu_type"] == cpu
        add("%s-big-endian-header" % arch, {"magic": current["raw"][:4].hex().upper(), "cpu_type": cpu, "sha256": expected_hash})
    for arch in ARCHES:
        parsed = parse_load_commands(info[arch]["raw"])
        assert len(parsed["commands"]) == info[arch]["inventory"]["command_count"]
        add("%s-load-command-bounds" % arch, {"command_count": len(parsed["commands"]), "command_bytes": sum(row[3] for row in parsed["commands"])})
    # 009-014: mapped structures and raw symbol inventories
    for arch in ARCHES:
        current = info[arch]
        for segment in current["inventory"]["segments"]:
            assert segment["file_offset"] + segment["file_size"] <= len(current["raw"])
        add("%s-segment-file-bounds" % arch, {"segment_count": len(current["inventory"]["segments"])})
    for arch in ARCHES:
        current = info[arch]
        for section in current["inventory"]["sections"]:
            assert section["file_offset"] + section["size"] <= len(current["raw"])
        add("%s-section-file-bounds" % arch, {"section_count": len(current["inventory"]["sections"])})
    for arch in ARCHES:
        current = info[arch]
        text = next(row for row in current["inventory"]["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
        assert current["raw"][text["file_offset"]:text["file_offset"] + text["size"]]
        add("%s-raw-text-section" % arch, {"address": text["address"], "file_offset": text["file_offset"], "size": text["size"]})
    for arch in ARCHES:
        current = info[arch]
        assert len(current["symbols"]) == current["inventory"]["nlist_count"]
        assert all(row["name"] for row in current["symbols"])
        add("%s-symbol-row-integrity" % arch, {"symbol_row_count": len(current["symbols"]), "nlist_count": current["inventory"]["nlist_count"]})
    # 015-020: text and function export byte integrity
    for arch in ARCHES:
        current = info[arch]
        summary = current["text_summary"]
        rows = current["text"]
        expected_address = int(summary["text_start"], 16)
        expected_offset = summary["text_file_offset"]
        for row in rows:
            item = bytes.fromhex(row["bytes"])
            assert int(row["address"], 16) == expected_address and int(row["file_offset"]) == expected_offset
            assert len(item) == int(row["length"]) and current["raw"][expected_offset:expected_offset + len(item)] == item
            expected_address += len(item); expected_offset += len(item)
        assert expected_address == int(summary["text_start"], 16) + summary["text_size"]
        add("%s-text-unit-continuity" % arch, {"unit_count": len(rows), "text_size": summary["text_size"], "category_byte_counts": summary["category_byte_counts"]})
    for arch in ARCHES:
        current = info[arch]
        index = current["functions"]
        asm_root = ROOT / "05_ida/exports" / arch
        assert len({row["start"] for row in index}) == len(index)
        for row in index:
            path = (asm_root / row["asm"]).resolve(); path.relative_to(asm_root.resolve())
            assert path.is_file() and path.read_text(encoding="utf-8").strip()
        add("%s-function-assembly-presence" % arch, {"function_candidate_count": len(index)})
    # 021-024: function range / symbol-start audits
    for arch in ARCHES:
        current = info[arch]
        text = next(row for row in current["inventory"]["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
        start, end = int(text["address"], 16), int(text["address"], 16) + text["size"]
        assert all(start <= int(row["start"], 16) < int(row["end"], 16) <= end for row in current["functions"])
        add("%s-function-range-bounds" % arch, {"function_candidate_count": len(current["functions"]), "text_start": hex(start), "text_end": hex(end)})
    for arch in ARCHES:
        current = info[arch]
        values = {int(row["value"], 16) for row in current["symbols"]}
        matching = sum(int(int(row["start"], 16) in values) for row in current["functions"])
        add("%s-function-start-symbol-observation" % arch, {"function_candidate_count": len(current["functions"]), "starts_matching_any_raw_symbol_value": matching}, "observed")
    # 025-028: xrefs and independent code-item decoder observations
    for arch in ARCHES:
        current = info[arch]; ranges = segment_ranges(current)
        assert all(len(in_segment(ranges, int(row["from"], 16))) == 1 for row in current["xrefs"])
        outside_to = sum(int(len(in_segment(ranges, int(row["to"], 16))) == 0) for row in current["xrefs"])
        add("%s-xref-source-mapping" % arch, {"xref_count": len(current["xrefs"]), "outside_mapped_destination_count": outside_to})
    for arch in ARCHES:
        current = info[arch]; dis = decoder(arch)
        code_rows = [row for row in current["text"] if row["kind"] == "code"]
        exact = 0
        undecodable = 0
        for row in code_rows:
            item = bytes.fromhex(row["bytes"])
            instruction = next(dis.disasm(item, int(row["address"], 16)), None)
            if instruction is None:
                undecodable += 1
            elif instruction.size == len(item):
                exact += 1
        add("%s-capstone-code-item-observation" % arch, {"ida_code_item_count": len(code_rows), "capstone_exact_first_instruction_count": exact, "capstone_undecodable_count": undecodable}, "observed")
    # 029-030: special retention and isolation/audit bookkeeping
    unknown = read_json(ROOT / "09_validation/reports/multiarch-input-20260921/m68k-unknown-text-unit-review.json")
    assert unknown["length"] == 6 and "retain IDA unknown state" in unknown["conclusion"]
    add("m68k-unknown-retained", {"length": unknown["length"], "conclusion": unknown["conclusion"]}, "observed")
    all_paths = []
    for arch in ARCHES:
        all_paths += [ROOT / "03_original" / arch, ROOT / "05_ida/exports" / arch, ROOT / "05_ida/databases" / (arch + "-os42j.i64")]
    assert all(path.exists() for path in all_paths)
    assert all("x86" not in str(path) for path in all_paths)
    add("architecture-path-isolation", {"checked_paths": [str(path.relative_to(ROOT)) for path in all_paths]}, "pass")

    assert len(rounds) == 30
    aggregate = {"schema": 1, "round_count": len(rounds), "pass_count": sum(row["status"] == "pass" for row in rounds), "observed_count": sum(row["status"] == "observed" for row in rounds), "rounds": rounds}
    (OUT / "aggregate.json").write_text(json.dumps(aggregate, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({key: aggregate[key] for key in ("round_count", "pass_count", "observed_count")}, ensure_ascii=False))


if __name__ == "__main__":
    main()
