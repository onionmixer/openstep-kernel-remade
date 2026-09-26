"""Check startup direct-call targets against raw entry code items and IDA candidates."""
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
    targets = {}
    for arch, startup_rows in startup["targets"].items():
        binary = (ROOT / "03_original" / arch / "binaries/mach_kernel").read_bytes()
        inventory = json.loads((ROOT / "03_original" / arch / "inventory/macho.json").read_text(encoding="utf-8"))
        text = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
        text_address = int(text["address"], 16)
        text_offset = int(text["file_offset"])
        units = load_tsv(ROOT / "05_ida/exports" / arch / "text-units.tsv")
        by_address = {int(row["address"], 16): row for row in units}
        candidates = json.loads((ROOT / "05_ida/exports" / arch / "function-asm-index.json").read_text(encoding="utf-8"))
        candidates_by_start = {int(row["start"], 16): row for row in candidates}
        entries = []
        for call in startup_rows["calls"]:
            target = int(call["target"], 16)
            unit = by_address[target]
            assert unit["kind"] == "code"
            offset = text_offset + (target - text_address)
            raw = binary[offset:offset + int(unit["length"])]
            assert raw.hex() == unit["bytes"]
            candidate = candidates_by_start[target]
            entries.append({
                "target": call["target"], "raw_symbol": call["target_symbol"]["name"],
                "entry_file_offset": offset, "entry_original_bytes": raw.hex(),
                "entry_ida_disassembly": unit["disassembly"],
                "ida_function_candidate": {key: candidate[key] for key in ("start", "end", "size", "name", "flags")},
            })
        assert len(entries) == 4
        targets[arch] = {
            "original_sha256_recomputed_with_python": hashlib.sha256(binary).hexdigest(),
            "startup_callee_entry_count": len(entries),
            "every_entry_is_code_item_and_ida_candidate_start": True,
            "every_entry_code_item_matches_original": True,
            "entries": entries,
            "interpretation_limit": "a raw symbol, entry code item, and candidate start do not establish complete function extent, ABI, arguments, return behavior, or semantics",
        }
    report = {"schema": 1, "targets": targets, "all_checks_passed": True}
    output = REPORT / "startup-callee-entry-candidate-audit.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({arch: target["startup_callee_entry_count"] for arch, target in targets.items()} | {"all_checks_passed": True}, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
