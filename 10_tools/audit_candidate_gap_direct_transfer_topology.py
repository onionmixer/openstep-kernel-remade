"""Aggregate raw-verified direct-transfer rows by function-candidate gap topology."""
import bisect
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
INPUTS = {
    'm68k': [
        'm68k-candidate-gap-bcc-dbcc-branches-audit.json',
        'm68k-candidate-gap-remaining-type19-transfers-audit.json',
    ],
    'sparc': ['sparc-candidate-gap-direct-branches-audit.json'],
}


def candidate_ranges(architecture):
    path = ROOT / f'05_ida/exports/{architecture}/function-candidate-lexical-exits.tsv'
    with path.open(encoding='utf-8', newline='') as handle:
        candidates = list(csv.DictReader(handle, delimiter='\t'))
    ranges = sorted((int(row['start'], 16), int(row['end'], 16)) for row in candidates)
    assert all(left[1] <= right[0] for left, right in zip(ranges, ranges[1:]))
    return path, [start for start, _ in ranges], ranges


def text_bounds(architecture):
    inventory = json.loads((ROOT / f'03_original/{architecture}/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    start = int(text['address'], 16)
    return start, start + int(text['size'])


def gap_at(address, starts, ranges, text_start, text_end):
    index = bisect.bisect_right(starts, address) - 1
    if index >= 0 and address < ranges[index][1]:
        return None
    lower = ranges[index][1] if index >= 0 else text_start
    upper = starts[index + 1] if index + 1 < len(starts) else text_end
    assert lower <= address < upper
    return lower, upper


def gap_key(gap):
    return f'{gap[0]:#x}..{gap[1]:#x}'


def main():
    targets = {}
    for architecture, filenames in INPUTS.items():
        candidate_path, starts, ranges = candidate_ranges(architecture)
        text_start, text_end = text_bounds(architecture)
        input_hashes = {}
        rows = []
        for filename in filenames:
            path = REPORT / filename
            raw = path.read_bytes()
            input_hashes[filename] = hashlib.sha256(raw).hexdigest()
            data = json.loads(raw)
            assert data['architecture'] == architecture
            rows.extend(data['rows'])
        relation_counts = Counter()
        source_gap_counts = Counter()
        target_gap_counts = Counter()
        cross_gap_counts = Counter()
        for row in rows:
            source = int(row['source'], 16)
            target = int(row['target'], 16)
            source_gap = gap_at(source, starts, ranges, text_start, text_end)
            assert source_gap is not None
            target_gap = gap_at(target, starts, ranges, text_start, text_end)
            source_gap_counts[gap_key(source_gap)] += 1
            if target_gap is None:
                relation = 'target_candidate'
            elif target_gap == source_gap:
                relation = 'same_gap'
                target_gap_counts[gap_key(target_gap)] += 1
            else:
                relation = 'other_gap'
                target_gap_counts[gap_key(target_gap)] += 1
                cross_gap_counts[(gap_key(source_gap), gap_key(target_gap))] += 1
            relation_counts[relation] += 1
        expected = {'m68k': 2449, 'sparc': 232}[architecture]
        assert len(rows) == expected
        assert sum(relation_counts.values()) == expected
        targets[architecture] = {
            'raw_verified_input_reports_sha256': input_hashes,
            'candidate_tsv_sha256': hashlib.sha256(candidate_path.read_bytes()).hexdigest(),
            'direct_transfer_source_count': len(rows),
            'source_gap_count': len(source_gap_counts),
            'target_gap_count': len(target_gap_counts),
            'target_relation_counts': dict(sorted(relation_counts.items())),
            'source_gap_transfer_counts': dict(sorted(source_gap_counts.items())),
            'cross_gap_transfer_counts': [
                {'source_gap': source_gap, 'target_gap': target_gap, 'count': count}
                for (source_gap, target_gap), count in sorted(cross_gap_counts.items())
            ],
            'all_input_sources_are_in_candidate_gaps': True,
        }
    output = {
        'schema': 1,
        'targets': targets,
        'interpretation_limit': ('topology aggregates raw-verified direct-transfer edges only; it does not '
                                 'establish gap code ownership, branch conditions, execution, fallthrough, path '
                                 'reachability, function boundaries, calling convention, ABI, or behavior'),
    }
    (REPORT / 'candidate-gap-direct-transfer-topology-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({
        architecture: target['direct_transfer_source_count']
        for architecture, target in targets.items()
    }, sort_keys=True))


if __name__ == '__main__':
    main()
