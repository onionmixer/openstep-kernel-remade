"""Cross raw LINK/SAVE target entries with their lexical-return adjacent items."""
import csv
import hashlib
import json
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
EXPECTED = {
    'm68k': {'entry_target_count': 562, 'exit_item_count': 561},
    'sparc': {'entry_target_count': 2465, 'exit_item_count': 2462},
}


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def mnemonic(disassembly):
    return disassembly.split(None, 1)[0] if disassembly else '<empty>'


def parse_exits(value):
    return [(int(token.split(':', 1)[0], 16), token.split(':', 1)[1])
            for token in value.split(',')]


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
    for architecture in ('m68k', 'sparc'):
        binary = (ROOT / '03_original' / architecture / 'binaries/mach_kernel').read_bytes()
        inventory = json.loads((ROOT / '03_original' / architecture / 'inventory/macho.json').read_text())
        text = next(section for section in inventory['sections']
                    if section['segment'] == '__TEXT' and section['name'] == '__text')
        text_start = int(text['address'], 16)
        text_offset = int(text['file_offset'])
        edges = read_tsv(ROOT / '05_ida/exports' / architecture / 'direct-call-edges.tsv')
        callers = defaultdict(int)
        for edge in edges:
            callers[int(edge['target'], 16)] += 1
        candidates = {int(candidate['start'], 16): candidate for candidate in
                      read_tsv(ROOT / '05_ida/exports' / architecture / 'function-candidate-lexical-exits.tsv')}
        units = read_tsv(ROOT / '05_ida/exports' / architecture / 'text-units.tsv')
        units_by_address = {int(unit['address'], 16): unit for unit in units}
        unit_index = {int(unit['address'], 16): index for index, unit in enumerate(units)}
        selected_targets = []
        for target in callers:
            unit = units_by_address[target]
            selected_mnemonic = 'link' if architecture == 'm68k' else 'save'
            if mnemonic(unit['disassembly']) == selected_mnemonic:
                selected_targets.append(target)
        rows = []
        neighbor_counts = Counter()
        target_without_lexical_exit = 0
        for target in sorted(selected_targets):
            candidate = candidates.get(target)
            if candidate is None or int(candidate['lexical_exit_count']) == 0:
                target_without_lexical_exit += 1
                continue
            entry_unit = units_by_address[target]
            entry = raw_item(binary, entry_unit, text_start, text_offset)
            for exit_address, exit_kind in parse_exits(candidate['lexical_exits']):
                exit_unit = units_by_address[exit_address]
                exit_index = unit_index[exit_address]
                neighbor_unit = units[exit_index - 1] if architecture == 'm68k' else units[exit_index + 1]
                if architecture == 'm68k':
                    assert int(neighbor_unit['address'], 16) + int(neighbor_unit['length']) == exit_address
                else:
                    assert int(neighbor_unit['address'], 16) == exit_address + int(exit_unit['length'])
                exit_item = raw_item(binary, exit_unit, text_start, text_offset)
                neighbor = raw_item(binary, neighbor_unit, text_start, text_offset)
                neighbor_name = mnemonic(neighbor_unit['disassembly'])
                neighbor_counts[neighbor_name] += 1
                rows.append({
                    'target': hex(target),
                    'direct_caller_edge_count': callers[target],
                    'candidate_end': candidate['end'],
                    'entry_item': entry,
                    'lexical_exit_kind': exit_kind,
                    'lexical_exit_item': exit_item,
                    'adjacent_item_direction': 'preceding_item' if architecture == 'm68k' else 'delay_slot_item',
                    'adjacent_item': neighbor,
                })
        assert len(selected_targets) == EXPECTED[architecture]['entry_target_count']
        assert len(rows) == EXPECTED[architecture]['exit_item_count']
        architectures[architecture] = {
            'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
            'entry_target_count': len(selected_targets),
            'entry_target_without_lexical_exit_count': target_without_lexical_exit,
            'lexical_exit_item_count': len(rows),
            'return_adjacent_ida_mnemonic_counts': dict(neighbor_counts),
            'all_entry_exit_and_adjacent_items_match_original_big_endian_bytes': True,
            'rows': rows,
        }
    output = {
        'schema': 1,
        'architectures': architectures,
        'interpretation_limit': ('raw entry and return-adjacent instruction patterns are static structure observations '
                                'only; they do not establish a stack frame, return execution, paths, function boundaries, '
                                'calling convention, ABI, or behavior'),
    }
    (REPORT / 'direct-target-entry-exit-structure-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({architecture: {
        'entry_target_count': data['entry_target_count'],
        'entry_target_without_lexical_exit_count': data['entry_target_without_lexical_exit_count'],
        'lexical_exit_item_count': data['lexical_exit_item_count'],
        'all_checks_passed': True,
    } for architecture, data in architectures.items()}))


if __name__ == '__main__':
    main()
