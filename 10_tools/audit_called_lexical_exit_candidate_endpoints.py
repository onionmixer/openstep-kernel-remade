"""Join direct-call target entries to lexical-exit bytes for called candidates."""
import csv
import hashlib
import json
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
EXPECTED = {'m68k': (2262, 10274), 'sparc': (2548, 17251)}


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def parse_exits(value):
    exits = []
    for token in value.split(','):
        address, kind = token.split(':', 1)
        exits.append((int(address, 16), kind))
    return exits


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
        candidates = read_tsv(ROOT / '05_ida/exports' / architecture / 'function-candidate-lexical-exits.tsv')
        candidates_by_start = {int(candidate['start'], 16): candidate for candidate in candidates
                               if int(candidate['lexical_exit_count']) > 0}
        units = read_tsv(ROOT / '05_ida/exports' / architecture / 'text-units.tsv')
        units_by_address = {int(unit['address'], 16): unit for unit in units}
        incoming = defaultdict(list)
        for edge in edges:
            target = int(edge['target'], 16)
            if target in candidates_by_start:
                incoming[target].append(edge)
        rows = []
        total_exit_items = 0
        for target, target_edges in sorted(incoming.items()):
            candidate = candidates_by_start[target]
            entry_unit = units_by_address[target]
            entry_position = text_offset + target - text_start
            entry_raw = binary[entry_position:entry_position + int(entry_unit['length'])]
            assert entry_unit['kind'] == 'code'
            assert entry_raw.hex() == entry_unit['bytes']
            exit_items = []
            for address, kind in parse_exits(candidate['lexical_exits']):
                assert target <= address < int(candidate['end'], 16)
                unit = units_by_address[address]
                position = text_offset + address - text_start
                original = binary[position:position + int(unit['length'])]
                assert unit['kind'] == 'code'
                assert original.hex() == unit['bytes']
                exit_items.append({
                    'address': unit['address'],
                    'kind': kind,
                    'original_bytes': original.hex(),
                    'ida_disassembly': unit['disassembly'],
                })
            assert len(exit_items) == int(candidate['lexical_exit_count'])
            total_exit_items += len(exit_items)
            rows.append({
                'target': hex(target),
                'candidate_end': candidate['end'],
                'direct_caller_edge_count': len(target_edges),
                'entry_item': {
                    'address': entry_unit['address'],
                    'original_bytes': entry_raw.hex(),
                    'ida_disassembly': entry_unit['disassembly'],
                },
                'lexical_exit_items': exit_items,
            })
        expected_candidates, expected_edges = EXPECTED[architecture]
        assert len(rows) == expected_candidates
        assert sum(row['direct_caller_edge_count'] for row in rows) == expected_edges
        architectures[architecture] = {
            'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
            'called_candidate_with_lexical_exit_count': len(rows),
            'direct_caller_edge_count': sum(row['direct_caller_edge_count'] for row in rows),
            'lexical_exit_code_item_count_within_called_candidates': total_exit_items,
            'all_called_candidate_entry_and_lexical_exit_items_match_original_big_endian_bytes': True,
            'rows': rows,
        }
    output = {
        'schema': 1,
        'architectures': architectures,
        'interpretation_limit': ('a direct-call target entry and lexical exit opcode are static endpoint evidence '
                                'only; they do not establish a path between them, call return, reachability, '
                                'function boundaries, calling convention, ABI, or behavior'),
    }
    (REPORT / 'called-lexical-exit-candidate-endpoints-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({architecture: {
        'called_candidate_with_lexical_exit_count': data['called_candidate_with_lexical_exit_count'],
        'direct_caller_edge_count': data['direct_caller_edge_count'],
        'lexical_exit_code_item_count_within_called_candidates': data['lexical_exit_code_item_count_within_called_candidates'],
        'all_checks_passed': True,
    } for architecture, data in architectures.items()}))


if __name__ == '__main__':
    main()
