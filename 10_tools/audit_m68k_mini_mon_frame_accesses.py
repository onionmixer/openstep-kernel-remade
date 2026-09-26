"""Preserve raw-byte frame-relative operand observations for m68k _mini_mon."""
import csv
import hashlib
import json
import re
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ARCH = "m68k"
START = 0x4093976
END = 0x4093E4A
REPORT = ROOT / "09_validation/reports/multiarch-input-20260921"
OFFSET = re.compile(r"(?P<sign>-)?(?:\$)?(?P<hex>[0-9A-F]+)\(a6\)")


def load_tsv(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def main():
    binary = (ROOT / "03_original" / ARCH / "binaries/mach_kernel").read_bytes()
    inventory = json.loads((ROOT / "03_original" / ARCH / "inventory/macho.json").read_text(encoding="utf-8"))
    text = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    text_address = int(text["address"], 16)
    text_offset = int(text["file_offset"])
    units = load_tsv(ROOT / "05_ida/exports" / ARCH / "text-units.tsv")
    observations = []
    positive_offsets = set()
    negative_offsets = set()
    for unit in units:
        address = int(unit["address"], 16)
        if not (START <= address < END) or unit["kind"] != "code" or "a6)" not in unit["disassembly"]:
            continue
        offset = text_offset + (address - text_address)
        raw = binary[offset:offset + int(unit["length"])]
        assert raw.hex() == unit["bytes"]
        matches = list(OFFSET.finditer(unit["disassembly"]))
        assert matches
        parsed = []
        for match in matches:
            value = int(match.group("hex"), 16)
            value = -value if match.group("sign") else value
            parsed.append(value)
            (negative_offsets if value < 0 else positive_offsets).add(value)
        observations.append({
            "address": hex(address), "file_offset": offset, "original_bytes": raw.hex(),
            "ida_disassembly": unit["disassembly"], "a6_relative_offsets": parsed,
        })
    assert len(observations) == 20
    assert sorted(positive_offsets) == [8, 12, 16, 20, 24, 28, 32]
    assert sorted(negative_offsets) == [-300, -260, -258, -256, -255]
    prologue = next(row for row in units if int(row["address"], 16) == START)
    register_save = next(row for row in units if int(row["address"], 16) == START + 4)
    register_restore = next(row for row in units if int(row["address"], 16) == 0x4093E40)
    lexical_exit = next(row for row in units if int(row["address"], 16) == 0x4093E46)
    assert (prologue["bytes"], register_save["bytes"], register_restore["bytes"], lexical_exit["bytes"]) == ("4e56fefc", "48e73f3c", "4cee3cfcfed4", "4e5e")
    report = {
        "schema": 1,
        "architecture": ARCH,
        "original_sha256_recomputed_with_python": hashlib.sha256(binary).hexdigest(),
        "bounded_range": {"start": hex(START), "end_exclusive": hex(END)},
        "frame_related_code_items": {
            "prologue": {"address": hex(START), "original_bytes": prologue["bytes"], "ida_disassembly": prologue["disassembly"]},
            "register_save": {"address": hex(START + 4), "original_bytes": register_save["bytes"], "ida_disassembly": register_save["disassembly"]},
            "register_restore": {"address": "0x4093e40", "original_bytes": register_restore["bytes"], "ida_disassembly": register_restore["disassembly"]},
            "lexical_exit": {"address": "0x4093e46", "original_bytes": lexical_exit["bytes"], "ida_disassembly": lexical_exit["disassembly"]},
        },
        "a6_relative_code_item_count": len(observations),
        "positive_a6_offsets_observed": [hex(value) for value in sorted(positive_offsets)],
        "negative_a6_offsets_observed": [hex(value) for value in sorted(negative_offsets)],
        "a6_relative_code_items": observations,
        "all_observed_original_bytes_match_ida_text_units": True,
        "conclusion": "the bounded raw code evidence supports a frame-like layout hypothesis with positive and negative a6-relative operands",
        "interpretation_limit": "positive offsets are not confirmed call arguments, negative offsets are not confirmed local variables, and this does not establish ABI, types, values, full control flow, or callee behavior",
    }
    output = REPORT / "m68k-mini-mon-frame-access-observation.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"original_sha256": report["original_sha256_recomputed_with_python"], "a6_relative_code_item_count": len(observations), "all_checks_passed": True}, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
