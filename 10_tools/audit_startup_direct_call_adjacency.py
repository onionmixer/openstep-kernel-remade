"""Preserve raw adjacent code-item evidence around verified startup calls."""
import csv
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / "09_validation/reports/multiarch-input-20260921"


def load_tsv(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def main():
    startup = json.loads((REPORT / "startup-direct-call-edge-audit.json").read_text(encoding="utf-8"))
    output_targets = {}
    for arch, target_data in startup["targets"].items():
        binary = (ROOT / "03_original" / arch / "binaries/mach_kernel").read_bytes()
        inventory = json.loads((ROOT / "03_original" / arch / "inventory/macho.json").read_text(encoding="utf-8"))
        text = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
        text_address = int(text["address"], 16)
        text_offset = int(text["file_offset"])
        units = load_tsv(ROOT / "05_ida/exports" / arch / "text-units.tsv")
        by_address = {int(row["address"], 16): row for row in units}
        ordered_addresses = [int(row["address"], 16) for row in units]
        rows = []
        for call in target_data["calls"]:
            source = int(call["source"], 16)
            index = ordered_addresses.index(source)
            call_unit = units[index]
            before_unit = units[index - 1]
            after_unit = units[index + 1]
            assert int(after_unit["address"], 16) == source + int(call_unit["length"])
            selected = {"preceding": before_unit, "call": call_unit, "following": after_unit}
            for unit in selected.values():
                address = int(unit["address"], 16)
                offset = text_offset + (address - text_address)
                raw = binary[offset:offset + int(unit["length"])]
                assert raw.hex() == unit["bytes"]
                assert unit["kind"] == "code"
            rows.append({
                "source": call["source"], "target": call["target"], "target_raw_symbol": call["target_symbol"]["name"],
                "preceding_code_item": {"address": before_unit["address"], "original_bytes": before_unit["bytes"], "ida_disassembly": before_unit["disassembly"]},
                "call_code_item": {"address": call_unit["address"], "original_bytes": call_unit["bytes"], "ida_disassembly": call_unit["disassembly"]},
                "following_code_item": {"address": after_unit["address"], "original_bytes": after_unit["bytes"], "ida_disassembly": after_unit["disassembly"]},
            })
        assert len(rows) == 4
        output_targets[arch] = {
            "original_sha256_recomputed_with_python": hashlib.sha256(binary).hexdigest(),
            "startup_direct_call_window_count": len(rows),
            "windows": rows,
            "all_adjacent_code_item_bytes_match_original": True,
            "interpretation_limit": "adjacent instructions do not independently establish argument values, calling convention, ABI, return values, side effects, or callee behavior",
        }
    report = {"schema": 1, "targets": output_targets, "all_checks_passed": True}
    output = REPORT / "startup-direct-call-adjacency-audit.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({arch: data["startup_direct_call_window_count"] for arch, data in output_targets.items()} | {"all_checks_passed": True}, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
