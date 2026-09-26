"""Inspect the few called lexical-exit adjacency exceptions without reclassifying items."""
import csv
import hashlib
import json
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
EXCEPTIONS = {
    'm68k': {0x40018C2: 0x40018C2},
    'sparc': {
        0xF0007114: 0xF0007150,
        0xF00071D8: 0xF0007218,
        0xF0095100: 0xF009512C,
    },
}


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def raw_item(binary, unit, text_start, text_offset):
    address = int(unit['address'], 16)
    position = text_offset + address - text_start
    original = binary[position:position + int(unit['length'])]
    assert original.hex() == unit['bytes']
    return {
        'address': unit['address'],
        'kind': unit['kind'],
        'original_bytes': original.hex(),
        'ida_disassembly': unit['disassembly'],
    }


def main():
    architectures = {}
    for architecture, exception_exits in EXCEPTIONS.items():
        binary = (ROOT / '03_original' / architecture / 'binaries/mach_kernel').read_bytes()
        inventory = json.loads((ROOT / '03_original' / architecture / 'inventory/macho.json').read_text())
        text = next(section for section in inventory['sections']
                    if section['segment'] == '__TEXT' and section['name'] == '__text')
        text_start = int(text['address'], 16)
        text_offset = int(text['file_offset'])
        candidates = {int(candidate['start'], 16): candidate for candidate in
                      read_tsv(ROOT / '05_ida/exports' / architecture / 'function-candidate-lexical-exits.tsv')}
        units = read_tsv(ROOT / '05_ida/exports' / architecture / 'text-units.tsv')
        unit_index = {int(unit['address'], 16): index for index, unit in enumerate(units)}
        edges = read_tsv(ROOT / '05_ida/exports' / architecture / 'direct-call-edges.tsv')
        callers = defaultdict(list)
        for edge in edges:
            callers[int(edge['target'], 16)].append({
                'source': edge['source'],
                'edge_kind': edge['edge_kind'],
                'instruction_bytes': edge['instruction_bytes'],
            })
        rows = []
        for start, exit_address in sorted(exception_exits.items()):
            candidate = candidates[start]
            index = unit_index[start]
            end = int(candidate['end'], 16)
            candidate_exit_addresses = {int(token.split(':', 1)[0], 16)
                                        for token in candidate['lexical_exits'].split(',')}
            assert exit_address in candidate_exit_addresses
            exit_unit = units[unit_index[exit_address]]
            if architecture == 'm68k':
                assert int(exit_unit['address'], 16) == start
                adjacent_unit = units[index - 1]
            else:
                adjacent_unit = units[unit_index[int(exit_unit['address'], 16)] + 1]
            next_boundary_unit = units[unit_index[end]]
            previous_boundary_unit = units[index - 1]
            rows.append({
                'candidate': candidate,
                'direct_callers': callers[start],
                'item_before_candidate_start': raw_item(binary, previous_boundary_unit, text_start, text_offset),
                'lexical_exit_item': raw_item(binary, exit_unit, text_start, text_offset),
                'return_adjacent_item': raw_item(binary, adjacent_unit, text_start, text_offset),
                'item_at_candidate_end': raw_item(binary, next_boundary_unit, text_start, text_offset),
            })
        assert len(rows) == len(exception_exits)
        architectures[architecture] = {
            'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
            'exception_candidate_count': len(rows),
            'direct_caller_edge_count': sum(len(row['direct_callers']) for row in rows),
            'all_exception_boundary_items_match_original_big_endian_bytes': True,
            'rows': rows,
        }
    output = {
        'schema': 1,
        'architectures': architectures,
        'interpretation_limit': ('exception boundary items are raw layout evidence only; they do not justify code/data '
                                'reclassification or establish delay-slot execution, return behavior, reachability, '
                                'function boundaries, calling convention, ABI, or behavior'),
    }
    (REPORT / 'called-lexical-exit-adjacency-exceptions-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({architecture: {
        'exception_candidate_count': data['exception_candidate_count'],
        'direct_caller_edge_count': data['direct_caller_edge_count'],
        'all_checks_passed': True,
    } for architecture, data in architectures.items()}))


if __name__ == '__main__':
    main()
