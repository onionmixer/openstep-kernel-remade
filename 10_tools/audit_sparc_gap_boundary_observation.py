"""Record raw boundary evidence for the SPARC direct-call source gap."""
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ARCH = "sparc"
GAP_START = 0xF0003AA4
GAP_END = 0xF0004E70
BRANCH = 0xF0003A9C
REPORT = ROOT / "09_validation/reports/multiarch-input-20260921"


def load_tsv(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def signed(value, bits):
    return value - (1 << bits) if value & (1 << (bits - 1)) else value


def main():
    binary = (ROOT / "03_original" / ARCH / "binaries/mach_kernel").read_bytes()
    inventory = json.loads((ROOT / "03_original" / ARCH / "inventory/macho.json").read_text(encoding="utf-8"))
    text = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    text_start = int(text["address"], 16)
    text_offset = int(text["file_offset"])
    functions = json.loads((ROOT / "05_ida/exports" / ARCH / "function-asm-index.json").read_text(encoding="utf-8"))
    candidate = next(row for row in functions if int(row["start"], 16) == 0xF00039BC)
    assert int(candidate["end"], 16) == GAP_START
    units = load_tsv(ROOT / "05_ida/exports" / ARCH / "text-units.tsv")
    units_by_address = {int(row["address"], 16): row for row in units}
    xrefs = load_tsv(ROOT / "05_ida/exports" / ARCH / "xrefs.tsv")

    branch_unit = units_by_address[BRANCH]
    delay_unit = units_by_address[BRANCH + 4]
    first_gap_unit = units_by_address[GAP_START]
    first_call_unit = units_by_address[GAP_START + 8]
    assert branch_unit["bytes"] == "10bffe81"
    assert delay_unit["bytes"] == "9c100017"
    assert first_gap_unit["bytes"] == "113c042990122384"
    assert first_call_unit["bytes"] == "400042eb"
    for address, unit in [(BRANCH, branch_unit), (BRANCH + 4, delay_unit), (GAP_START, first_gap_unit), (GAP_START + 8, first_call_unit)]:
        offset = text_offset + (address - text_start)
        assert binary[offset:offset + int(unit["length"])].hex() == unit["bytes"]
    branch_word = int.from_bytes(bytes.fromhex(branch_unit["bytes"]), "big")
    displacement = signed(branch_word & ((1 << 22) - 1), 22)
    branch_target = (BRANCH + (displacement << 2)) & 0xFFFFFFFF
    assert branch_target == 0xF00034A0
    branch_xrefs = [row for row in xrefs if int(row["from"], 16) == BRANCH]
    assert {tuple(sorted(row.items())) for row in branch_xrefs} == {
        tuple(sorted({"from": "0xf0003a9c", "to": "0xf00034a0", "type": "19", "iscode": "1"}.items())),
        tuple(sorted({"from": "0xf0003a9c", "to": "0xf0003aa0", "type": "21", "iscode": "1"}.items())),
    }
    incoming = [row for row in xrefs if GAP_START <= int(row["to"], 16) < GAP_END]
    control = [row for row in incoming if row["type"] in {"17", "19"}]
    assert len(incoming) == 1238
    assert Counter(row["type"] for row in incoming) == Counter({"21": 1086, "19": 152})
    assert len(control) == 152
    assert all(GAP_START <= int(row["from"], 16) < GAP_END for row in control)
    report = {
        "schema": 1,
        "architecture": ARCH,
        "original_sha256_recomputed_with_python": hashlib.sha256(binary).hexdigest(),
        "gap": {"start": hex(GAP_START), "end_exclusive": hex(GAP_END)},
        "preceding_ida_function_candidate": candidate,
        "preceding_branch_and_delay_slot": {
            "branch_address": hex(BRANCH), "branch_original_bytes": branch_unit["bytes"],
            "signed_big_endian_disp22": displacement, "computed_target": hex(branch_target),
            "delay_slot_address": hex(BRANCH + 4), "delay_slot_original_bytes": delay_unit["bytes"],
            "xref_rows": branch_xrefs,
        },
        "first_gap_code_items": [
            {"address": hex(GAP_START), "original_bytes": first_gap_unit["bytes"], "ida_disassembly": first_gap_unit["disassembly"]},
            {"address": hex(GAP_START + 8), "original_bytes": first_call_unit["bytes"], "ida_disassembly": first_call_unit["disassembly"]},
        ],
        "incoming_xref_type_counts": dict(Counter(row["type"] for row in incoming)),
        "incoming_control_xref_count": len(control),
        "incoming_control_xrefs_all_source_inside_gap": True,
        "conclusion": "the preceding candidate ends before the gap after a raw branch and delay slot whose direct target is outside the gap; observed direct control xrefs into the gap originate inside it",
        "interpretation_limit": "these static facts do not establish runtime reachability, gap ownership, a function boundary, interrupt behavior, ABI, or semantics",
    }
    output = REPORT / "sparc-direct-call-gap-boundary-observation.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"original_sha256": report["original_sha256_recomputed_with_python"], "incoming_control_xref_count": len(control), "all_checks_passed": True}, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
