"""Census current x86 non-rel32 CALL/JMP listing observations from original bytes."""
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / "09_validation/reports/multiarch-input-20260921"
OUTPUT = REPORT / "x86-nonrel-call-jmp-census-audit-20260923.json"


def read_tsv(path):
    with path.open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream, delimiter="\t"))


def mnemonic(text):
    return text.split(None, 1)[0].lower() if text else ""


def main():
    raw = (ROOT / "03_original/x86/binaries/mach_kernel").read_bytes()
    inventory = json.loads((ROOT / "03_original/x86/inventory/macho.json").read_text(encoding="utf-8"))
    text = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    text_start, text_offset, text_size = int(text["address"], 16), int(text["file_offset"]), text["size"]
    listing = {}
    for line_number, line in enumerate((ROOT / "04_ghidra/exports/x86/full-pass5/whole-program.asm").read_text(encoding="utf-8").splitlines(), start=1):
        fields = line.split("\t", 2)
        if len(fields) != 3:
            raise RuntimeError("unexpected whole-program line {}".format(line_number))
        listing[int(fields[0], 16)] = (int(fields[1]), fields[2])
    rows = []
    all_instruction_bytes_match = True
    direct_rel32_call_count = 0
    current_nonrel_call_count = 0
    current_nonrelative_jmp_count = 0
    leading_byte_counts = Counter()
    listing_mnemonic_counts = Counter()
    for unit in read_tsv(ROOT / "04_ghidra/exports/x86/full-pass5/code-units.tsv"):
        if unit["kind"] != "instruction":
            continue
        address, length = int(unit["start"], 16), int(unit["length"])
        if not text_start <= address < text_start + text_size:
            continue
        listed_length, disassembly = listing[address]
        if listed_length != length:
            raise RuntimeError("listing length mismatch at {}".format(hex(address)))
        position = text_offset + address - text_start
        encoded = raw[position:position + length]
        all_instruction_bytes_match = all_instruction_bytes_match and len(encoded) == length
        name = mnemonic(disassembly)
        if name == "call" and len(encoded) == 5 and encoded[0] == 0xE8:
            direct_rel32_call_count += 1
            continue
        if name not in ("call", "jmp", "jmpf"):
            continue
        kind = "current_listing_nonrel32_call" if name == "call" else "current_listing_nonrelative_jmp"
        if name == "call":
            current_nonrel_call_count += 1
        else:
            current_nonrelative_jmp_count += 1
        leading_byte_counts[encoded[:1].hex()] += 1
        listing_mnemonic_counts[name] += 1
        rows.append({
            "address": "0x{:x}".format(address),
            "original_bytes": encoded.hex(),
            "current_listing_disassembly": disassembly,
            "classification": kind,
        })
    report = {
        "schema": 1,
        "scope": "x86 current listing CALL/JMP observations whose CALL encoding is not raw E8 rel32",
        "original_binary_sha256_recomputed_with_python": hashlib.sha256(raw).hexdigest(),
        "direct_rel32_call_count_recomputed_with_python": direct_rel32_call_count,
        "current_listing_nonrel32_call_count_recomputed_with_python": current_nonrel_call_count,
        "current_listing_nonrelative_jmp_count_recomputed_with_python": current_nonrelative_jmp_count,
        "current_listing_mnemonic_counts": dict(sorted(listing_mnemonic_counts.items())),
        "raw_leading_byte_counts": dict(sorted(leading_byte_counts.items())),
        "all_current_instruction_bytes_match_original": all_instruction_bytes_match,
        "interpretation_limit": (
            "Current CALL/JMP listing labels and raw opcode bytes do not establish indirect target values, execution, "
            "tail-call behavior, function boundaries, calling convention, ABI, arguments, returns, or behavior."
        ),
        "rows": rows,
    }
    OUTPUT.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if not all_instruction_bytes_match:
        raise SystemExit("x86 instruction byte validation failed")
    print(json.dumps({
        "output": str(OUTPUT.relative_to(ROOT)),
        "direct_rel32_call_count_recomputed_with_python": direct_rel32_call_count,
        "current_listing_nonrel32_call_count_recomputed_with_python": current_nonrel_call_count,
        "current_listing_nonrelative_jmp_count_recomputed_with_python": current_nonrelative_jmp_count,
        "all_current_instruction_bytes_match_original": all_instruction_bytes_match,
    }, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
