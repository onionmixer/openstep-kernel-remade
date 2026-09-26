"""Build a binary-only calling/argument/return/layout evidence ledger.

The ledger is deliberately an observation corpus.  It validates listing bytes
against each original architecture binary, then records architecture-local
instruction patterns that a later, bounded ABI hypothesis may examine.  It
does not apply an external ABI, Objective-C runtime, compiler, or source-code
schema to the binaries.
"""
import bisect
import csv
import hashlib
import json
import re
from collections import Counter, defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT_DIR = ROOT / "09_validation/reports/multiarch-input-20260921"
OUTPUT = REPORT_DIR / "binary-only-contract-evidence-ledger-20260923.json"
ARCHITECTURES = ("x86", "m68k", "sparc")
ENDIANNESS = {"x86": "little", "m68k": "big", "sparc": "big"}

X86_EBP = re.compile(r"\[EBP\s*\+\s*(?P<sign>-)?0x(?P<value>[0-9A-Fa-f]+)\]")
M68K_A6 = re.compile(r"(?P<sign>-)?\$?(?P<value>[0-9A-Fa-f]+)\(a6\)", re.IGNORECASE)
SPARC_I = re.compile(r"%i[0-7]\b")
SPARC_O = re.compile(r"%o[0-7]\b")


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def read_tsv(path):
    with path.open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream, delimiter="\t"))


def original_context(arch):
    raw = (ROOT / "03_original" / arch / "binaries/mach_kernel").read_bytes()
    inventory = json.loads((ROOT / "03_original" / arch / "inventory/macho.json").read_text(encoding="utf-8"))
    text = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    return raw, inventory, int(text["address"], 16), int(text["file_offset"]), text["size"]


def raw_text(raw, text_start, text_file_offset, address, length):
    offset = text_file_offset + address - text_start
    if address < text_start or offset < 0 or offset + length > len(raw):
        raise ValueError("not file-backed original __text: {}".format(hex(address)))
    return raw[offset:offset + length]


def mnemonic(disassembly):
    return disassembly.split(None, 1)[0].lower() if disassembly else ""


def item_record(item):
    return {
        "address": "0x{:x}".format(item["address"]),
        "original_bytes": item["bytes"].hex(),
        "current_listing_disassembly": item["disassembly"],
    }


def x86_items(raw, text_start, text_file_offset, text_size):
    units = read_tsv(ROOT / "04_ghidra/exports/x86/full-pass5/code-units.tsv")
    listing = {}
    for line_number, line in enumerate((ROOT / "04_ghidra/exports/x86/full-pass5/whole-program.asm").read_text(encoding="utf-8").splitlines(), start=1):
        parts = line.split("\t", 2)
        if len(parts) != 3:
            raise RuntimeError("unexpected whole-program line {}".format(line_number))
        listing[int(parts[0], 16)] = (int(parts[1]), parts[2])
    items = []
    for unit in units:
        address = int(unit["start"], 16)
        length = int(unit["length"])
        if not (text_start <= address < text_start + text_size):
            continue
        listed_length, disassembly = listing.get(address, (None, None))
        if listed_length != length:
            raise RuntimeError("x86 listing length mismatch at {}".format(hex(address)))
        encoded = raw_text(raw, text_start, text_file_offset, address, length)
        items.append({
            "address": address,
            "length": length,
            "kind": "code" if unit["kind"] == "instruction" else unit["kind"],
            "bytes": encoded,
            "disassembly": disassembly,
        })
    return items


def ida_items(arch, raw, text_start, text_file_offset):
    items = []
    for unit in read_tsv(ROOT / "05_ida/exports" / arch / "text-units.tsv"):
        address = int(unit["address"], 16)
        encoded = bytes.fromhex(unit["bytes"])
        if raw_text(raw, text_start, text_file_offset, address, len(encoded)) != encoded:
            raise RuntimeError("{} listing mismatch at {}".format(arch, hex(address)))
        items.append({"address": address, "length": int(unit["length"]), "kind": unit["kind"], "bytes": encoded, "disassembly": unit["disassembly"]})
    return items


def functions(arch):
    if arch == "x86":
        rows = json.loads((ROOT / "04_ghidra/exports/x86/full-pass5/functions.json").read_text(encoding="utf-8"))
        result = []
        for row in rows:
            segments = [(int(segment["start"], 16), int(segment["end_inclusive"], 16) + 1) for segment in row["body"]]
            result.append({"start": int(row["address"], 16), "name": row["name"], "analysis_fragment": row["analysis_fragment"], "segments": segments})
        return result
    rows = json.loads((ROOT / "05_ida/exports" / arch / "function-asm-index.json").read_text(encoding="utf-8"))
    return [{"start": int(row["start"], 16), "name": row["name"], "analysis_fragment": False, "segments": [(int(row["start"], 16), int(row["end"], 16))]} for row in rows]


def inside_segments(address, segments):
    return any(start <= address < end for start, end in segments)


def items_in_segments(items, addresses, segments):
    selected = []
    for start, end in segments:
        lower = bisect.bisect_left(addresses, start)
        upper = bisect.bisect_left(addresses, end)
        selected.extend(item for item in items[lower:upper] if item["kind"] == "code")
    return selected


def x86_direct_calls(items):
    edges = []
    for item in items:
        raw = item["bytes"]
        if item["kind"] != "code" or len(raw) != 5 or raw[0] != 0xE8:
            continue
        target = item["address"] + len(raw) + int.from_bytes(raw[1:], "little", signed=True)
        edges.append({"source": item["address"], "target": target, "instruction_bytes": raw.hex(), "listing_mnemonic": mnemonic(item["disassembly"])})
    return edges


def ida_direct_calls(arch, raw, text_start, text_file_offset):
    edges = []
    for row in read_tsv(ROOT / "05_ida/exports" / arch / "direct-call-edges.tsv"):
        source = int(row["source"], 16)
        encoded = bytes.fromhex(row["instruction_bytes"])
        if raw_text(raw, text_start, text_file_offset, source, len(encoded)) != encoded:
            raise RuntimeError("{} direct-call mismatch at {}".format(arch, hex(source)))
        edges.append({"source": source, "target": int(row["target"], 16), "instruction_bytes": encoded.hex(), "listing_mnemonic": row["edge_kind"]})
    return edges


def direct_call_adjacency(arch, direct_edges, item_by_address):
    next_mnemonics = Counter()
    delay_mnemonics = Counter()
    post_delay_mnemonics = Counter()
    x86_add_esp_count = 0
    m68k_next_item_mentions_sp_count = 0
    sparc_delay_item_o_register_token_count = 0
    missing_immediate_next_item_count = 0
    for edge in direct_edges:
        source = edge["source"]
        length = len(bytes.fromhex(edge["instruction_bytes"]))
        if arch == "sparc":
            delay = item_by_address.get(source + length)
            post_delay = item_by_address.get(source + length * 2)
            if delay is None:
                missing_immediate_next_item_count += 1
            else:
                delay_mnemonics[mnemonic(delay["disassembly"])] += 1
                sparc_delay_item_o_register_token_count += len(SPARC_O.findall(delay["disassembly"]))
            if post_delay is not None:
                post_delay_mnemonics[mnemonic(post_delay["disassembly"])] += 1
            continue
        next_item = item_by_address.get(source + length)
        if next_item is None:
            missing_immediate_next_item_count += 1
            continue
        text = next_item["disassembly"]
        next_mnemonics[mnemonic(text)] += 1
        if arch == "x86" and text.upper().startswith("ADD ESP,"):
            x86_add_esp_count += 1
        if arch == "m68k" and "sp" in text.lower():
            m68k_next_item_mentions_sp_count += 1
    return {
        "immediate_next_item_missing_count_recomputed_with_python": missing_immediate_next_item_count,
        "next_item_listing_mnemonic_counts_recomputed_with_python": dict(sorted(next_mnemonics.items())),
        "x86_next_item_add_esp_listing_count_recomputed_with_python": x86_add_esp_count,
        "m68k_next_item_listing_mentions_sp_count_recomputed_with_python": m68k_next_item_mentions_sp_count,
        "sparc_delay_slot_listing_mnemonic_counts_recomputed_with_python": dict(sorted(delay_mnemonics.items())),
        "sparc_post_delay_listing_mnemonic_counts_recomputed_with_python": dict(sorted(post_delay_mnemonics.items())),
        "sparc_delay_slot_o_register_token_count_recomputed_with_python": sparc_delay_item_o_register_token_count,
    }


def relative_observations(arch, function_items):
    positives = Counter()
    negatives = Counter()
    registers = Counter()
    for item in function_items:
        text = item["disassembly"]
        if arch == "x86":
            matches = X86_EBP.finditer(text)
            for match in matches:
                value = int(match.group("value"), 16)
                (negatives if match.group("sign") else positives)[value] += 1
        elif arch == "m68k":
            for match in M68K_A6.finditer(text):
                value = int(match.group("value"), 16)
                (negatives if match.group("sign") else positives)[value] += 1
        else:
            registers["%i"] += len(SPARC_I.findall(text))
            registers["%o"] += len(SPARC_O.findall(text))
    return {
        "positive_displacement_occurrence_counts": {"0x{:x}".format(key): value for key, value in sorted(positives.items())},
        "negative_displacement_occurrence_counts": {"-0x{:x}".format(key): value for key, value in sorted(negatives.items())},
        "register_token_occurrence_counts": dict(sorted(registers.items())),
    }


def entry_and_exit_observations(arch, function_items):
    first = function_items[0] if function_items else None
    exits = []
    for item in function_items:
        raw = item["bytes"]
        item_mnemonic = mnemonic(item["disassembly"])
        if arch == "x86" and raw[:1] in (b"\xc3", b"\xc2"):
            exits.append(item_record(item))
        elif arch == "m68k" and raw in (bytes.fromhex("4e75"), bytes.fromhex("4e73")):
            exits.append(item_record(item))
        elif arch == "sparc" and item_mnemonic in ("ret", "retl", "ret!"):
            exits.append(item_record(item))
    entry = None if first is None else item_record(first)
    entry_patterns = {
        "x86_push_ebp_mov_ebp_esp_prefix": False,
        "m68k_link_prefix": False,
        "sparc_save_listing_mnemonic": False,
    }
    if arch == "x86" and len(function_items) >= 2:
        entry_patterns["x86_push_ebp_mov_ebp_esp_prefix"] = first["bytes"] == b"\x55" and function_items[1]["bytes"] == bytes.fromhex("89e5")
    elif arch == "m68k" and first is not None:
        entry_patterns["m68k_link_prefix"] = first["bytes"].startswith(bytes.fromhex("4e56"))
    elif arch == "sparc" and first is not None:
        entry_patterns["sparc_save_listing_mnemonic"] = mnemonic(first["disassembly"]) == "save"
    return entry, exits, entry_patterns


def objc_raw_word_layout(arch, raw, inventory):
    sections = inventory["sections"]
    objc = [row for row in sections if row["segment"] == "__OBJC"]
    file_backed = [row for row in sections if row["file_offset"] and row["size"]]
    output = []
    for section in objc:
        size = section["size"]
        offset = section["file_offset"]
        if size == 0:
            output.append({
                "section": "__OBJC," + section["name"],
                "raw_word_count_recomputed_with_python": 0,
                "raw_word_alignment_remainder_recomputed_with_python": 0,
                "word_location_counts": {},
                "section_original_bytes_sha256_recomputed_with_python": sha256(b""),
            })
            continue
        if offset + size > len(raw):
            raise RuntimeError("__OBJC outside original file: {} {}".format(arch, section["name"]))
        counts = Counter()
        word_count = size // 4
        for relative in range(0, word_count * 4, 4):
            value = int.from_bytes(raw[offset + relative:offset + relative + 4], ENDIANNESS[arch])
            if value == 0:
                counts["zero_word"] += 1
                continue
            containing = next((candidate for candidate in file_backed if int(candidate["address"], 16) <= value < int(candidate["address"], 16) + candidate["size"]), None)
            if containing is None:
                counts["nonzero_word_outside_file_backed_sections"] += 1
            else:
                counts["nonzero_word_inside_file_backed_sections"] += 1
                counts["target:" + containing["segment"] + "," + containing["name"]] += 1
        output.append({
            "section": "__OBJC," + section["name"],
            "raw_word_count_recomputed_with_python": word_count,
            "raw_word_alignment_remainder_recomputed_with_python": size % 4,
            "word_location_counts": dict(sorted(counts.items())),
            "section_original_bytes_sha256_recomputed_with_python": sha256(raw[offset:offset + size]),
        })
    return output


def main():
    report = {
        "schema": 1,
        "scope": "original OPENSTEP binary-only architecture-separated calling/argument/return/layout evidence ledger",
        "interpretation_limit": (
            "A listing mnemonic, frame-relative displacement, register token, lexical exit byte, direct-call edge, "
            "or raw __OBJC word does not by itself establish a calling convention, stack ownership, argument, return "
            "value, pointer, field, structure, object, true function boundary, code/data truth, execution, reachability, "
            "ABI, or behavior. No external ABI/compiler/runtime/source schema is applied."
        ),
        "architectures": {},
    }
    for arch in ARCHITECTURES:
        raw, inventory, text_start, text_file_offset, text_size = original_context(arch)
        items = x86_items(raw, text_start, text_file_offset, text_size) if arch == "x86" else ida_items(arch, raw, text_start, text_file_offset)
        addresses = [item["address"] for item in items]
        item_by_address = {item["address"]: item for item in items}
        rows = sorted(functions(arch), key=lambda row: row["start"])
        function_starts = {row["start"] for row in rows}
        direct_edges = x86_direct_calls(items) if arch == "x86" else ida_direct_calls(arch, raw, text_start, text_file_offset)
        edges_by_source = defaultdict(list)
        incoming = defaultdict(list)
        for edge in direct_edges:
            edges_by_source[edge["source"]].append(edge)
            if edge["target"] in function_starts:
                incoming[edge["target"]].append(edge)
        records = []
        all_item_checks = True
        for row in rows:
            function_items = items_in_segments(items, addresses, row["segments"])
            for item in function_items:
                all_item_checks = all_item_checks and raw_text(raw, text_start, text_file_offset, item["address"], item["length"]) == item["bytes"]
            entry, exits, entry_patterns = entry_and_exit_observations(arch, function_items)
            records.append({
                "candidate_start": "0x{:x}".format(row["start"]),
                "current_name_observation": row["name"],
                "analysis_fragment": row["analysis_fragment"],
                "current_candidate_body_segments": [{"start": "0x{:x}".format(start), "end_exclusive": "0x{:x}".format(end)} for start, end in row["segments"]],
                "code_item_count_recomputed_with_python": len(function_items),
                "all_current_code_item_bytes_match_original": all(raw_text(raw, text_start, text_file_offset, item["address"], item["length"]) == item["bytes"] for item in function_items),
                "entry_listing_observation": entry,
                "entry_pattern_observations": entry_patterns,
                "lexical_exit_listing_observations": exits,
                "relative_operand_or_register_observations": relative_observations(arch, function_items),
                "outgoing_direct_call_count_recomputed_with_python": sum(len(edges_by_source[item["address"]]) for item in function_items),
                "incoming_direct_call_to_current_start_count_recomputed_with_python": len(incoming[row["start"]]),
            })
        entry_counts = Counter()
        exit_count = 0
        positive_count = 0
        negative_count = 0
        register_counts = Counter()
        for row in records:
            for key, value in row["entry_pattern_observations"].items():
                entry_counts[key] += int(value)
            exit_count += len(row["lexical_exit_listing_observations"])
            operands = row["relative_operand_or_register_observations"]
            positive_count += sum(operands["positive_displacement_occurrence_counts"].values())
            negative_count += sum(operands["negative_displacement_occurrence_counts"].values())
            register_counts.update(operands["register_token_occurrence_counts"])
        report["architectures"][arch] = {
            "architecture_endianness": ENDIANNESS[arch],
            "original_binary_sha256_recomputed_with_python": sha256(raw),
            "current_function_or_analysis_fragment_count_recomputed_with_python": len(records),
            "current_code_item_count_recomputed_with_python": sum(item["kind"] == "code" for item in items),
            "all_current_code_item_bytes_match_original": all_item_checks,
            "direct_call_edge_count_recomputed_with_python": len(direct_edges),
            "direct_call_adjacency_observations": direct_call_adjacency(arch, direct_edges, item_by_address),
            "entry_pattern_counts_recomputed_with_python": dict(sorted(entry_counts.items())),
            "lexical_exit_item_count_recomputed_with_python": exit_count,
            "positive_displacement_occurrence_count_recomputed_with_python": positive_count,
            "negative_displacement_occurrence_count_recomputed_with_python": negative_count,
            "register_token_occurrence_counts_recomputed_with_python": dict(sorted(register_counts.items())),
            "raw_objc_word_layout": objc_raw_word_layout(arch, raw, inventory),
            "function_contract_evidence_records": records,
        }
    report["all_current_code_item_bytes_match_original"] = all(data["all_current_code_item_bytes_match_original"] for data in report["architectures"].values())
    report["architecture_record_count_recomputed_with_python"] = len(report["architectures"])
    OUTPUT.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if not report["all_current_code_item_bytes_match_original"]:
        raise SystemExit("original-byte validation failed")
    print(json.dumps({
        "output": str(OUTPUT.relative_to(ROOT)),
        "all_current_code_item_bytes_match_original": report["all_current_code_item_bytes_match_original"],
        "architectures": {
            arch: {
                "function_or_analysis_fragment_count": data["current_function_or_analysis_fragment_count_recomputed_with_python"],
                "direct_call_edge_count": data["direct_call_edge_count_recomputed_with_python"],
            }
            for arch, data in report["architectures"].items()
        },
    }, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
