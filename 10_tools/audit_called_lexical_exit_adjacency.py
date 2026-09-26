"""Preserve raw neighboring items for lexical exits in directly called candidates."""
import csv
import hashlib
import json
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
EXPECTED = {'m68k': 2317, 'sparc': 2578}


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def parse_exits(value):
    return [(int(token.split(':', 1)[0], 16), token.split(':', 1)[1])
            for token in value.split(',')]


def mnemonic(disassembly):
    return disassembly.split(None, 1)[0] if disassembly else '<empty>'


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
        called_targets = {int(edge['target'], 16) for edge in edges if int(edge['target'], 16) in candidates_by_start}
        units = read_tsv(ROOT / '05_ida/exports' / architecture / 'text-units.tsv')
        units_by_address = {int(unit['address'], 16): unit for unit in units}
        unit_index = {int(unit['address'], 16): index for index, unit in enumerate(units)}
        rows = []
        neighbor_mnemonics = Counter()
        neighbor_kinds = Counter()
        neighbor_relations = Counter()
        for target in sorted(called_targets):
            candidate = candidates_by_start[target]
            end = int(candidate['end'], 16)
            for exit_address, exit_kind in parse_exits(candidate['lexical_exits']):
                exit_unit = units_by_address[exit_address]
                exit_index = unit_index[exit_address]
                neighbor_unit = units[exit_index - 1] if architecture == 'm68k' else units[exit_index + 1]
                neighbor_address = int(neighbor_unit['address'], 16)
                if architecture == 'm68k':
                    assert neighbor_address + int(neighbor_unit['length']) == exit_address
                else:
                    assert neighbor_address == exit_address + int(exit_unit['length'])
                exit_position = text_offset + exit_address - text_start
                neighbor_position = text_offset + neighbor_address - text_start
                exit_raw = binary[exit_position:exit_position + int(exit_unit['length'])]
                neighbor_raw = binary[neighbor_position:neighbor_position + int(neighbor_unit['length'])]
                assert exit_unit['kind'] == 'code'
                assert exit_raw.hex() == exit_unit['bytes']
                assert neighbor_raw.hex() == neighbor_unit['bytes']
                relation = 'inside_same_candidate' if target <= neighbor_address < end else 'outside_same_candidate'
                neighbor_mnemonics[mnemonic(neighbor_unit['disassembly'])] += 1
                neighbor_kinds[neighbor_unit['kind']] += 1
                neighbor_relations[relation] += 1
                rows.append({
                    'candidate_start': candidate['start'],
                    'candidate_end': candidate['end'],
                    'lexical_exit_address': exit_unit['address'],
                    'lexical_exit_kind': exit_kind,
                    'lexical_exit_original_bytes': exit_raw.hex(),
                    'adjacent_item_direction': 'preceding_item' if architecture == 'm68k' else 'delay_slot_item',
                    'adjacent_item': {
                        'address': neighbor_unit['address'],
                        'kind': neighbor_unit['kind'],
                        'original_bytes': neighbor_raw.hex(),
                        'ida_disassembly': neighbor_unit['disassembly'],
                        'candidate_relation': relation,
                    },
                })
        assert len(rows) == EXPECTED[architecture]
        architectures[architecture] = {
            'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
            'called_lexical_exit_item_count': len(rows),
            'adjacent_item_kind_counts': dict(neighbor_kinds),
            'adjacent_item_candidate_relation_counts': dict(neighbor_relations),
            'adjacent_item_ida_mnemonic_counts': dict(neighbor_mnemonics),
            'all_lexical_exit_and_adjacent_items_match_original_big_endian_bytes': True,
            'rows': rows,
        }
    output = {
        'schema': 1,
        'architectures': architectures,
        'interpretation_limit': ('a return-adjacent raw item is a static observation only; it does not establish '
                                'return execution, a return target, path reachability, candidate boundaries, '
                                'calling convention, ABI, or behavior'),
    }
    (REPORT / 'called-lexical-exit-adjacency-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({architecture: {
        'called_lexical_exit_item_count': data['called_lexical_exit_item_count'],
        'adjacent_item_kind_counts': data['adjacent_item_kind_counts'],
        'adjacent_item_candidate_relation_counts': data['adjacent_item_candidate_relation_counts'],
        'all_checks_passed': True,
    } for architecture, data in architectures.items()}))


if __name__ == '__main__':
    main()
