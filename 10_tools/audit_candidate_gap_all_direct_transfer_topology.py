"""Combine raw-verified direct call and branch gap-edge topology by architecture."""
import bisect
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
BRANCH_REPORTS = {
    'm68k': ['m68k-candidate-gap-bcc-dbcc-branches-audit.json',
             'm68k-candidate-gap-remaining-type19-transfers-audit.json'],
    'sparc': ['sparc-candidate-gap-direct-branches-audit.json'],
}


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def gap_state(address, starts, ranges, text_start, text_end):
    index = bisect.bisect_right(starts, address) - 1
    if index >= 0 and address < ranges[index][1]:
        return 'candidate', ranges[index]
    lower = ranges[index][1] if index >= 0 else text_start
    upper = starts[index + 1] if index + 1 < len(starts) else text_end
    assert lower <= address < upper
    return 'gap', (lower, upper)


def range_key(pair):
    return f'{pair[0]:#x}..{pair[1]:#x}'


def main():
    targets = {}
    for architecture in ['m68k', 'sparc']:
        candidate_path = ROOT / f'05_ida/exports/{architecture}/function-candidate-lexical-exits.tsv'
        candidates = read_tsv(candidate_path)
        ranges = sorted((int(row['start'], 16), int(row['end'], 16)) for row in candidates)
        starts = [start for start, _ in ranges]
        candidate_starts = set(starts)
        assert all(left[1] <= right[0] for left, right in zip(ranges, ranges[1:]))
        inventory = json.loads((ROOT / f'03_original/{architecture}/inventory/macho.json').read_text())
        text = next(section for section in inventory['sections']
                    if section['segment'] == '__TEXT' and section['name'] == '__text')
        text_start = int(text['address'], 16)
        text_end = text_start + int(text['size'])
        call_path = ROOT / f'05_ida/exports/{architecture}/direct-call-edges.tsv'
        calls = read_tsv(call_path)
        branch_rows = []
        raw_input_hashes = {'direct-call-edges.tsv': hashlib.sha256(call_path.read_bytes()).hexdigest()}
        for filename in BRANCH_REPORTS[architecture]:
            path = REPORT / filename
            raw = path.read_bytes()
            raw_input_hashes[filename] = hashlib.sha256(raw).hexdigest()
            branch_rows.extend(json.loads(raw)['rows'])
        source_gap_counts = Counter()
        relation_counts = Counter()
        call_count = 0
        branch_count = 0
        for call in calls:
            source = int(call['source'], 16)
            source_kind, source_range = gap_state(source, starts, ranges, text_start, text_end)
            if source_kind != 'gap':
                continue
            target = int(call['target'], 16)
            target_kind, target_range = gap_state(target, starts, ranges, text_start, text_end)
            source_gap_counts[range_key(source_range)] += 1
            relation = 'call_target_candidate_start' if target in candidate_starts else (
                'call_target_candidate_interior' if target_kind == 'candidate' else 'call_target_gap')
            relation_counts[relation] += 1
            call_count += 1
        for row in branch_rows:
            source = int(row['source'], 16)
            target = int(row['target'], 16)
            source_kind, source_range = gap_state(source, starts, ranges, text_start, text_end)
            assert source_kind == 'gap'
            target_kind, target_range = gap_state(target, starts, ranges, text_start, text_end)
            source_gap_counts[range_key(source_range)] += 1
            if target_kind == 'candidate':
                relation = 'branch_target_candidate'
            elif target_range == source_range:
                relation = 'branch_target_same_gap'
            else:
                relation = 'branch_target_other_gap'
            relation_counts[relation] += 1
            branch_count += 1
        expected_calls = {'m68k': 1127, 'sparc': 28}[architecture]
        expected_branches = {'m68k': 2449, 'sparc': 232}[architecture]
        assert call_count == expected_calls and branch_count == expected_branches
        targets[architecture] = {
            'original_sha256_recomputed_with_python': hashlib.sha256(
                (ROOT / f'03_original/{architecture}/binaries/mach_kernel').read_bytes()).hexdigest(),
            'raw_verified_input_sha256': raw_input_hashes,
            'candidate_tsv_sha256': hashlib.sha256(candidate_path.read_bytes()).hexdigest(),
            'candidate_gap_direct_call_count': call_count,
            'candidate_gap_direct_branch_count': branch_count,
            'candidate_gap_all_direct_transfer_count': call_count + branch_count,
            'source_gap_count': len(source_gap_counts),
            'source_gap_all_direct_transfer_counts': dict(sorted(source_gap_counts.items())),
            'transfer_relation_counts': dict(sorted(relation_counts.items())),
        }
    output = {
        'schema': 1,
        'targets': targets,
        'interpretation_limit': ('this aggregates raw-verified direct call and branch edges only; it does not '
                                 'establish gap code ownership, branch conditions, execution, fallthrough, path '
                                 'reachability, function boundaries, calling convention, ABI, or behavior'),
    }
    (REPORT / 'candidate-gap-all-direct-transfer-topology-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({architecture: target['candidate_gap_all_direct_transfer_count']
                      for architecture, target in targets.items()}, sort_keys=True))


if __name__ == '__main__':
    main()
