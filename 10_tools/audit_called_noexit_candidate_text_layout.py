"""Verify original contiguous code-item layout of directly called no-exit candidates."""
import csv
import hashlib
import json
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
EXPECTED = {'m68k': 50, 'sparc': 59}


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def main():
    architectures = {}
    for architecture in ('m68k', 'sparc'):
        binary = (ROOT / '03_original' / architecture / 'binaries/mach_kernel').read_bytes()
        inventory = json.loads((ROOT / '03_original' / architecture / 'inventory/macho.json').read_text())
        text = next(section for section in inventory['sections']
                    if section['segment'] == '__TEXT' and section['name'] == '__text')
        text_start = int(text['address'], 16)
        text_offset = int(text['file_offset'])
        edges = read_tsv(ROOT / '05_ida/exports' / architecture / 'direct-call-edges.tsv')
        candidates = {int(candidate['start'], 16): candidate for candidate in
                      read_tsv(ROOT / '05_ida/exports' / architecture / 'function-candidate-lexical-exits.tsv')
                      if int(candidate['lexical_exit_count']) == 0}
        callers = defaultdict(int)
        for edge in edges:
            target = int(edge['target'], 16)
            if target in candidates:
                callers[target] += 1
        units = read_tsv(ROOT / '05_ida/exports' / architecture / 'text-units.tsv')
        rows = []
        total_items = 0
        total_bytes = 0
        for start, caller_count in sorted(callers.items()):
            candidate = candidates[start]
            end = int(candidate['end'], 16)
            candidate_units = [unit for unit in units if start <= int(unit['address'], 16) < end]
            assert candidate_units
            assert int(candidate_units[0]['address'], 16) == start
            assert int(candidate_units[-1]['address'], 16) + int(candidate_units[-1]['length']) == end
            assert all(unit['kind'] == 'code' for unit in candidate_units)
            assert all(int(left['address'], 16) + int(left['length']) == int(right['address'], 16)
                       for left, right in zip(candidate_units, candidate_units[1:]))
            for unit in candidate_units:
                address = int(unit['address'], 16)
                position = text_offset + address - text_start
                original = binary[position:position + int(unit['length'])]
                assert original.hex() == unit['bytes']
            item_count = len(candidate_units)
            byte_count = sum(int(unit['length']) for unit in candidate_units)
            total_items += item_count
            total_bytes += byte_count
            rows.append({
                'candidate_start': candidate['start'],
                'candidate_end': candidate['end'],
                'name': candidate['name'],
                'direct_caller_edge_count': caller_count,
                'contiguous_code_item_count': item_count,
                'contiguous_code_byte_count': byte_count,
            })
        assert len(rows) == EXPECTED[architecture]
        architectures[architecture] = {
            'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
            'called_noexit_candidate_count': len(rows),
            'total_contiguous_code_item_count': total_items,
            'total_contiguous_code_byte_count': total_bytes,
            'all_called_noexit_candidate_ranges_are_contiguous_original_code_items': True,
            'rows': rows,
        }
    output = {
        'schema': 1,
        'architectures': architectures,
        'interpretation_limit': ('a contiguous code-item layout is not evidence that the terminal is reachable from '
                                'entry or that the candidate is a complete function; it does not establish control '
                                'flow, calling convention, ABI, or behavior'),
    }
    (REPORT / 'called-noexit-candidate-text-layout-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({architecture: {
        'called_noexit_candidate_count': data['called_noexit_candidate_count'],
        'total_contiguous_code_item_count': data['total_contiguous_code_item_count'],
        'total_contiguous_code_byte_count': data['total_contiguous_code_byte_count'],
        'all_checks_passed': True,
    } for architecture, data in architectures.items()}))


if __name__ == '__main__':
    main()
