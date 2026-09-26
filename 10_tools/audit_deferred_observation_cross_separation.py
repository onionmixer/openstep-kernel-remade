"""Cross-check raw address separation for retained OS42J deferred observations."""
import csv
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORTS = ROOT / "09_validation/reports/multiarch-input-20260921"
OUT = REPORTS / "deferred-observation-cross-separation-audit-20260923.json"
ARCHES = ("m68k", "sparc")


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def read_tsv(path):
    with path.open(newline="", encoding="utf-8") as stream:
        return list(csv.DictReader(stream, delimiter="\t"))


def text_mapping(arch):
    inventory = json.loads((ROOT / "03_original" / arch / "inventory/macho.json").read_text())
    section = next(row for row in inventory["sections"] if row["segment"] == "__TEXT" and row["name"] == "__text")
    return int(section["address"], 16), section["file_offset"]


def raw_at(raw, text_address, text_offset, address, length):
    offset = text_offset + (address - text_address)
    if address < text_address or offset + length > len(raw):
        raise ValueError("address is not a file-backed __text span")
    return raw[offset:offset + length]


def main():
    bounded = json.loads((REPORTS / "candidate-gap-bounded-text-layout-audit.json").read_text())
    unknown = json.loads((REPORTS / "m68k-unknown-text-unit-review.json").read_text())
    result = {"schema": 1, "scope": "raw-address and original-byte cross-separation of retained unknown, candidate-gap, and lexical-no-exit observations; no control-flow, ownership, ABI, or behavior conclusion"}
    all_pass = True
    for arch in ARCHES:
        raw = (ROOT / "03_original" / arch / "binaries/mach_kernel").read_bytes()
        text_address, text_offset = text_mapping(arch)
        index = json.loads((ROOT / "05_ida/exports" / arch / "function-asm-index.json").read_text())
        candidate_by_start = {int(row["start"], 16): int(row["end"], 16) for row in index}
        noexit = read_tsv(ROOT / "05_ida/exports" / arch / "noexit-candidate-terminal-items.tsv")
        gaps = [(int(row["gap"]["start"], 16), int(row["gap"]["end"], 16), row["original_span_sha256_recomputed_with_python"]) for row in bounded["targets"][arch]["rows"]]
        gaps.sort()
        gap_nonoverlap = all(left[1] <= right[0] for left, right in zip(gaps, gaps[1:]))
        candidate_start_in_gap = [start for start in candidate_by_start if any(begin <= start < end for begin, end, _ in gaps)]
        gap_hash_matches = all(sha256(raw_at(raw, text_address, text_offset, begin, end - begin)) == digest for begin, end, digest in gaps)
        noexit_rows = []
        for row in noexit:
            start, end, terminal = (int(row[key], 16) for key in ("start", "end", "terminal_address"))
            terminal_bytes = bytes.fromhex(row["terminal_original_bytes"])
            matches_candidate = candidate_by_start.get(start) == end
            in_range = start <= terminal < end
            matches_raw = raw_at(raw, text_address, text_offset, terminal, len(terminal_bytes)) == terminal_bytes
            overlaps_gap = any(begin <= start < finish or begin <= terminal < finish for begin, finish, _ in gaps)
            noexit_rows.append({"start": hex(start), "terminal": hex(terminal), "candidate_range_matches_index": matches_candidate, "terminal_inside_candidate_range": in_range, "terminal_bytes_match_original": matches_raw, "candidate_or_terminal_overlaps_gap": overlaps_gap})
        noexit_ok = all(all(row[key] for key in ("candidate_range_matches_index", "terminal_inside_candidate_range", "terminal_bytes_match_original")) and not row["candidate_or_terminal_overlaps_gap"] for row in noexit_rows)
        arch_result = {
            "original_sha256_recomputed_with_python": sha256(raw),
            "candidate_count": len(candidate_by_start),
            "gap_count": len(gaps),
            "noexit_count": len(noexit_rows),
            "gap_ranges_nonoverlapping": gap_nonoverlap,
            "candidate_starts_inside_gap_count_recomputed_with_python": len(candidate_start_in_gap),
            "all_gap_span_hashes_match_original": gap_hash_matches,
            "all_noexit_rows_match_candidate_and_original_terminal_bytes_without_gap_overlap": noexit_ok,
            "noexit_rows": noexit_rows,
        }
        if arch == "m68k":
            begin, finish = int(unknown["range_start"], 16), int(unknown["range_end_exclusive"], 16)
            unknown_bytes = bytes.fromhex(unknown["bytes"])
            arch_result["retained_unknown"] = {
                "range": "%s..%s" % (hex(begin), hex(finish)),
                "bytes_match_original": raw_at(raw, text_address, text_offset, begin, len(unknown_bytes)) == unknown_bytes,
                "candidate_starts_inside_unknown_count_recomputed_with_python": sum(begin <= start < finish for start in candidate_by_start),
                "unknown_overlaps_gap": any(begin < end and gap_begin < finish for gap_begin, end, _ in gaps),
            }
        required = gap_nonoverlap and not candidate_start_in_gap and gap_hash_matches and noexit_ok
        if arch == "m68k":
            u = arch_result["retained_unknown"]
            required = required and u["bytes_match_original"] and not u["candidate_starts_inside_unknown_count_recomputed_with_python"] and not u["unknown_overlaps_gap"]
        arch_result["all_cross_separation_checks_pass"] = required
        all_pass = all_pass and required
        result[arch] = arch_result
    result["all_architectures_pass"] = all_pass
    OUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n")
    if not all_pass:
        raise SystemExit("deferred observation cross-separation audit failed")
    print(json.dumps({"output": str(OUT.relative_to(ROOT)), "all_architectures_pass": all_pass}, sort_keys=True))


if __name__ == "__main__":
    main()
