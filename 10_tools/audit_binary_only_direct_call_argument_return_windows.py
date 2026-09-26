"""Census original-byte windows around every currently exported direct-call edge.

The output distinguishes literal operands and register/stack spelling in a
static listing from runtime arguments and return values.  No operand role or
execution path is inferred.
"""
import bisect
import csv
import hashlib
import json
import re
from collections import Counter
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT_DIR = ROOT / "09_validation/reports/multiarch-input-20260921"
OUTPUT = REPORT_DIR / "binary-only-direct-call-argument-return-window-audit-20260923.json"
ARCHITECTURES = ("x86", "m68k", "sparc")
PRECEDING_ITEM_LIMIT = 4
FOLLOWING_ITEM_LIMIT = 4
SPARC_O_REGISTER = re.compile(r"%o[0-7]\b")


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def read_tsv(path):
    with path.open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream, delimiter="\t"))


def context(arch):
    raw = (ROOT / "03_original" / arch / "binaries/mach_kernel").read_bytes()
    inventory = json.loads((ROOT / "03_original" / arch / "inventory/macho.json").read_text(encoding="utf-8"))
    text = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    return raw, int(text["address"], 16), int(text["file_offset"]), text["size"]


def original_text(raw, text_start, text_offset, address, length):
    position = text_offset + address - text_start
    if address < text_start or position < 0 or position + length > len(raw):
        raise ValueError("outside original __text: {}".format(hex(address)))
    return raw[position:position + length]


def mnemonic(disassembly):
    return disassembly.split(None, 1)[0].lower() if disassembly else ""


def x86_items(raw, text_start, text_offset, text_size):
    units = read_tsv(ROOT / "04_ghidra/exports/x86/full-pass5/code-units.tsv")
    listing = {}
    for line_number, line in enumerate((ROOT / "04_ghidra/exports/x86/full-pass5/whole-program.asm").read_text(encoding="utf-8").splitlines(), start=1):
        fields = line.split("\t", 2)
        if len(fields) != 3:
            raise RuntimeError("unexpected x86 listing line {}".format(line_number))
        listing[int(fields[0], 16)] = (int(fields[1]), fields[2])
    items = []
    for unit in units:
        address, length = int(unit["start"], 16), int(unit["length"])
        if not text_start <= address < text_start + text_size:
            continue
        listed_length, disassembly = listing[address]
        if listed_length != length:
            raise RuntimeError("x86 length mismatch at {}".format(hex(address)))
        items.append({"address": address, "length": length, "kind": unit["kind"], "bytes": original_text(raw, text_start, text_offset, address, length), "disassembly": disassembly})
    return items


def ida_items(arch, raw, text_start, text_offset):
    items = []
    for unit in read_tsv(ROOT / "05_ida/exports" / arch / "text-units.tsv"):
        address, length = int(unit["address"], 16), int(unit["length"])
        encoded = bytes.fromhex(unit["bytes"])
        if original_text(raw, text_start, text_offset, address, length) != encoded:
            raise RuntimeError("{} listing mismatch at {}".format(arch, hex(address)))
        items.append({"address": address, "length": length, "kind": unit["kind"], "bytes": encoded, "disassembly": unit["disassembly"]})
    return items


def x86_edges(items):
    edges = []
    for item in items:
        encoded = item["bytes"]
        if item["kind"] != "instruction" or len(encoded) != 5 or encoded[0] != 0xE8:
            continue
        target = item["address"] + len(encoded) + int.from_bytes(encoded[1:], "little", signed=True)
        edges.append({"source": item["address"], "target": target, "instruction_bytes": encoded})
    return edges


def ida_edges(arch, raw, text_start, text_offset):
    edges = []
    for row in read_tsv(ROOT / "05_ida/exports" / arch / "direct-call-edges.tsv"):
        source, target = int(row["source"], 16), int(row["target"], 16)
        encoded = bytes.fromhex(row["instruction_bytes"])
        if original_text(raw, text_start, text_offset, source, len(encoded)) != encoded:
            raise RuntimeError("{} call edge mismatch at {}".format(arch, hex(source)))
        edges.append({"source": source, "target": target, "instruction_bytes": encoded})
    return edges


def compact_item(item):
    return {"address": "0x{:x}".format(item["address"]), "original_bytes": item["bytes"].hex(), "current_listing_disassembly": item["disassembly"]}


def literal_observations(arch, previous, following):
    literals = []
    for item in previous:
        encoded, text = item["bytes"], item["disassembly"]
        if arch == "x86" and len(encoded) == 2 and encoded[0] == 0x6A:
            literals.append({"address": "0x{:x}".format(item["address"]), "kind": "raw_push_imm8", "encoded_value_signed_8bit_recomputed_with_python": int.from_bytes(encoded[1:], "little", signed=True), "original_bytes": encoded.hex(), "current_listing_disassembly": text})
        elif arch == "x86" and len(encoded) == 5 and encoded[0] == 0x68:
            literals.append({"address": "0x{:x}".format(item["address"]), "kind": "raw_push_imm32", "encoded_value_unsigned_32bit_recomputed_with_python": int.from_bytes(encoded[1:], "little", signed=False), "original_bytes": encoded.hex(), "current_listing_disassembly": text})
        elif arch == "m68k" and "#" in text and "-(sp)" in text.lower():
            literals.append({"address": "0x{:x}".format(item["address"]), "kind": "listing_immediate_to_predecrement_sp", "original_bytes": encoded.hex(), "current_listing_disassembly": text})
        elif arch == "sparc" and mnemonic(text) in ("mov", "set", "sethi") and SPARC_O_REGISTER.search(text):
            literals.append({"address": "0x{:x}".format(item["address"]), "kind": "listing_immediate_construction_with_o_register_token", "original_bytes": encoded.hex(), "current_listing_disassembly": text})
    token = {"x86": "eax", "m68k": "d0", "sparc": "%o0"}[arch]
    return_token_items = [compact_item(item) for item in following if token in item["disassembly"].lower()]
    return literals, return_token_items


def main():
    report = {
        "schema": 1,
        "scope": "all current direct-call edges, original-byte-validated local pre/post-call windows, architecture separated",
        "window_definition": {
            "preceding_current_text_item_limit": PRECEDING_ITEM_LIMIT,
            "following_current_text_item_limit": FOLLOWING_ITEM_LIMIT,
            "sparc_following_window_starts_at_delay_slot": True,
        },
        "interpretation_limit": (
            "A listed literal, stack spelling, register token, call edge, or local instruction sequence is not a proof "
            "that it is an argument or return value, nor of its runtime value, position, type, execution, ABI, or behavior."
        ),
        "architectures": {},
    }
    for arch in ARCHITECTURES:
        raw, text_start, text_offset, text_size = context(arch)
        items = x86_items(raw, text_start, text_offset, text_size) if arch == "x86" else ida_items(arch, raw, text_start, text_offset)
        items.sort(key=lambda item: item["address"])
        addresses = [item["address"] for item in items]
        by_address = {item["address"]: item for item in items}
        edges = x86_edges(items) if arch == "x86" else ida_edges(arch, raw, text_start, text_offset)
        records = []
        literal_kind_counts = Counter()
        return_token_item_count = 0
        all_source_and_window_bytes_match = True
        for edge in edges:
            source = edge["source"]
            source_item = by_address.get(source)
            if source_item is None or source_item["bytes"] != edge["instruction_bytes"]:
                raise RuntimeError("source item absent/mismatched at {}".format(hex(source)))
            source_index = bisect.bisect_left(addresses, source)
            if source_index >= len(items) or items[source_index]["address"] != source:
                raise RuntimeError("source index mismatch at {}".format(hex(source)))
            preceding = items[max(0, source_index - PRECEDING_ITEM_LIMIT):source_index]
            following_start = source + len(edge["instruction_bytes"])
            following_index = bisect.bisect_left(addresses, following_start)
            following = items[following_index:following_index + FOLLOWING_ITEM_LIMIT]
            source_match = original_text(raw, text_start, text_offset, source, len(edge["instruction_bytes"])) == edge["instruction_bytes"]
            window_match = all(original_text(raw, text_start, text_offset, item["address"], item["length"]) == item["bytes"] for item in preceding + following)
            all_source_and_window_bytes_match = all_source_and_window_bytes_match and source_match and window_match
            literals, return_tokens = literal_observations(arch, preceding, following)
            literal_kind_counts.update(row["kind"] for row in literals)
            return_token_item_count += len(return_tokens)
            records.append({
                "source": "0x{:x}".format(source),
                "target": "0x{:x}".format(edge["target"]),
                "direct_call_original_bytes": edge["instruction_bytes"].hex(),
                "source_and_window_items_match_original": source_match and window_match,
                "preceding_window_original_bytes_sha256_recomputed_with_python": sha256(b"".join(item["bytes"] for item in preceding)),
                "following_window_original_bytes_sha256_recomputed_with_python": sha256(b"".join(item["bytes"] for item in following)),
                "preceding_window_item_count_recomputed_with_python": len(preceding),
                "following_window_item_count_recomputed_with_python": len(following),
                "static_literal_operand_listing_observations": literals,
                "postcall_candidate_return_register_token": {"x86": "EAX", "m68k": "D0", "sparc": "%o0"}[arch],
                "postcall_candidate_return_register_token_listing_items": return_tokens,
            })
        report["architectures"][arch] = {
            "original_binary_sha256_recomputed_with_python": sha256(raw),
            "direct_call_edge_count_recomputed_with_python": len(records),
            "all_source_and_window_item_bytes_match_original": all_source_and_window_bytes_match,
            "static_literal_observation_kind_counts_recomputed_with_python": dict(sorted(literal_kind_counts.items())),
            "postcall_candidate_return_register_token_listing_item_count_recomputed_with_python": return_token_item_count,
            "records": records,
        }
    report["all_source_and_window_item_bytes_match_original"] = all(data["all_source_and_window_item_bytes_match_original"] for data in report["architectures"].values())
    report["runtime_argument_value_confirmed"] = False
    report["runtime_return_value_confirmed"] = False
    OUTPUT.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if not report["all_source_and_window_item_bytes_match_original"]:
        raise SystemExit("direct-call window raw-byte check failed")
    print(json.dumps({
        "output": str(OUTPUT.relative_to(ROOT)),
        "all_source_and_window_item_bytes_match_original": report["all_source_and_window_item_bytes_match_original"],
        "direct_call_edge_counts_recomputed_with_python": {arch: data["direct_call_edge_count_recomputed_with_python"] for arch, data in report["architectures"].items()},
    }, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
