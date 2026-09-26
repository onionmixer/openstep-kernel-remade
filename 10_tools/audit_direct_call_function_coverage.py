"""Measure direct-call edge coverage by IDA function-candidate ranges without confirming semantics."""
import csv
import json
from collections import Counter
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT_DIR = ROOT / "09_validation/reports/multiarch-input-20260921"


def load_tsv(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle, delimiter="\t"))


def main():
    targets = {}
    for architecture in ("m68k", "sparc"):
        edges = load_tsv(ROOT / "05_ida/exports" / architecture / "direct-call-edges.tsv")
        functions = json.loads((ROOT / "05_ida/exports" / architecture / "function-asm-index.json").read_text(encoding="utf-8"))
        ranges = [(int(row["start"], 16), int(row["end"], 16)) for row in functions]
        starts = {int(row["start"], 16) for row in functions}
        source_range_membership = Counter()
        target_start_membership = Counter()
        unique_sources = set()
        unique_targets = set()
        for edge in edges:
            source = int(edge["source"], 16)
            target = int(edge["target"], 16)
            membership = sum(start <= source < end for start, end in ranges)
            source_range_membership[str(membership)] += 1
            target_start_membership["candidate_start" if target in starts else "not_candidate_start"] += 1
            unique_sources.add(source)
            unique_targets.add(target)
        assert sum(source_range_membership.values()) == len(edges)
        assert sum(target_start_membership.values()) == len(edges)
        targets[architecture] = {
            "direct_call_edge_count": len(edges),
            "function_candidate_count": len(functions),
            "unique_direct_call_source_count": len(unique_sources),
            "unique_direct_call_target_count": len(unique_targets),
            "edge_source_function_candidate_membership_counts": dict(sorted(source_range_membership.items(), key=lambda row: int(row[0]))),
            "edge_target_function_candidate_start_counts": dict(sorted(target_start_membership.items())),
            "interpretation_limit": "IDA function ranges and starts are tool hypotheses; this audit measures address overlap only and does not confirm function boundaries or call semantics",
        }
    report = {"schema": 1, "targets": targets, "all_checks_passed": True}
    output = REPORT_DIR / "direct-call-function-candidate-coverage.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
