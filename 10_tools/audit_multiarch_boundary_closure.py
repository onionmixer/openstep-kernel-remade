"""Close the m68k/SPARC boundary-review queue using raw-audit evidence.

This script aggregates only reports derived from the original kernels.  It
does not interpret a decompiler result as proof of a boundary or behavior.
"""
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORTS = ROOT / "09_validation/reports/multiarch-input-20260921"
OUTPUT = REPORTS / "function-boundary-closure-20260922.json"
ORIGINALS = {
    "m68k": ROOT / "03_original/m68k/binaries/mach_kernel",
    "sparc": ROOT / "03_original/sparc/binaries/mach_kernel",
}
EXPECTED = {
    "m68k": "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75",
    "sparc": "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1",
}


def sha256(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def read(name):
    return json.loads((REPORTS / name).read_text(encoding="utf-8"))


def require(value, message):
    if not value:
        raise RuntimeError(message)


def main():
    hashes = {architecture: sha256(path) for architecture, path in ORIGINALS.items()}
    require(hashes == EXPECTED, "original kernel hash mismatch")
    unknown = read("m68k-unknown-text-unit-review-summary.json")
    direct_calls = read("direct-call-function-candidate-coverage.json")
    topology = read("candidate-gap-all-direct-transfer-topology-audit.json")
    layouts = read("candidate-gap-bounded-text-layout-audit.json")
    mini_mon = read("m68k-mini-mon-bounded-text-layout-audit.json")
    sparc_window = read("sparc-gap-direct-call-window-audit.json")
    noexit = read("noexit-terminal-raw-coverage-closure-audit.json")
    require(unknown["length"] == 6 and unknown["conclusion"].startswith("insufficient evidence"), "m68k unknown review changed")
    require(direct_calls["all_checks_passed"], "direct-call candidate coverage failed")
    for architecture in ("m68k", "sparc"):
        require(topology["targets"][architecture]["original_sha256_recomputed_with_python"] == hashes[architecture], architecture + " topology hash mismatch")
        require(layouts["targets"][architecture]["all_gap_items_are_contiguous_and_match_original_bytes"], architecture + " gap layout mismatch")
        require(noexit["architectures"][architecture]["all_terminal_candidates_assigned_to_a_raw_audit"], architecture + " no-exit assignment incomplete")
    require(mini_mon["all_contiguous_text_items_match_original_big_endian_bytes"], "mini_mon raw layout mismatch")
    require(sparc_window["all_source_windows_match_original_big_endian_bytes"], "SPARC delay-slot window mismatch")
    require(sparc_window["all_disp30_targets_match_type17_xrefs"], "SPARC disp30 mismatch")
    result = {
        "schema": 1,
        "scope": "function-boundary and unclassified-area closure from original big-endian kernel bytes and raw-audit outputs",
        "original_sha256_recomputed_with_python": hashes,
        "m68k": {
            "unknown_bytes": {"range": [unknown["range_start"], unknown["range_end_exclusive"]], "length": unknown["length"], "classification": "retain_unknown"},
            "direct_call_sources_outside_candidate_count": direct_calls["targets"]["m68k"]["edge_source_function_candidate_membership_counts"]["0"],
            "direct_transfer_gap_count": topology["targets"]["m68k"]["source_gap_count"],
            "bounded_gap_raw_layout_matches_original": True,
            "mini_mon_noncode_item_count": len(mini_mon["noncode_items"]),
            "mini_mon_classification": "bounded_text_layout_only",
        },
        "sparc": {
            "direct_call_sources_outside_candidate_count": direct_calls["targets"]["sparc"]["edge_source_function_candidate_membership_counts"]["0"],
            "direct_transfer_gap_count": topology["targets"]["sparc"]["source_gap_count"],
            "bounded_gap_raw_layout_matches_original": True,
            "reviewed_call_gap": sparc_window["gap"],
            "delay_slot_items_are_raw_verified": sparc_window["all_source_windows_match_original_big_endian_bytes"],
        },
        "noexit_candidates": {
            "m68k": noexit["architectures"]["m68k"]["noexit_terminal_candidate_count"],
            "sparc": noexit["architectures"]["sparc"]["noexit_terminal_candidate_count"],
            "all_assigned_to_raw_audit": True,
        },
        "classification": "raw layout was rechecked; no candidate gap, delay slot, no-exit observation, or tool classification is promoted to a proven function boundary or behavior",
    }
    OUTPUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
