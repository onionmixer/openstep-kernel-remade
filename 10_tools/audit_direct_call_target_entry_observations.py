"""Preserve raw entry observations for unique direct-call targets by architecture."""
import csv
import hashlib
import json
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


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
        units = read_tsv(ROOT / '05_ida/exports' / architecture / 'text-units.tsv')
        units_by_address = {int(unit['address'], 16): unit for unit in units}
        candidates = read_tsv(ROOT / '05_ida/exports' / architecture / 'function-candidate-lexical-exits.tsv')
        candidates_by_start = {int(candidate['start'], 16): candidate for candidate in candidates}
        target_edges = defaultdict(list)
        for edge in edges:
            target_edges[int(edge['target'], 16)].append(edge)
        rows = []
        edge_classes = Counter()
        target_classes = Counter()
        entry_mnemonics = Counter()
        entry_raw_prefixes = Counter()
        for target, incoming in sorted(target_edges.items()):
            unit = units_by_address[target]
            assert unit['kind'] == 'code'
            position = text_offset + target - text_start
            original = binary[position:position + int(unit['length'])]
            assert original.hex() == unit['bytes']
            candidate = candidates_by_start.get(target)
            if candidate is None:
                classification = 'not_ida_candidate_start'
                lexical_exit_count = None
            elif int(candidate['lexical_exit_count']):
                classification = 'candidate_with_lexical_exit'
                lexical_exit_count = int(candidate['lexical_exit_count'])
            else:
                classification = 'candidate_without_lexical_exit'
                lexical_exit_count = 0
            edge_classes[classification] += len(incoming)
            target_classes[classification] += 1
            entry_mnemonics[mnemonic(unit['disassembly'])] += 1
            entry_raw_prefixes[original[:2].hex() if architecture == 'm68k' else original[:4].hex()] += 1
            rows.append({
                'target': hex(target),
                'direct_call_edge_count': len(incoming),
                'raw_symbol_names': sorted({edge['target_raw_symbols'] for edge in incoming if edge['target_raw_symbols']}),
                'target_classification': classification,
                'candidate_end': candidate['end'] if candidate else None,
                'lexical_exit_count': lexical_exit_count,
                'entry_item': {
                    'address': unit['address'],
                    'original_bytes': original.hex(),
                    'ida_disassembly': unit['disassembly'],
                    'ida_mnemonic': mnemonic(unit['disassembly']),
                },
            })
        assert sum(edge_classes.values()) == len(edges)
        architectures[architecture] = {
            'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
            'direct_call_edge_count': len(edges),
            'unique_direct_call_target_count': len(rows),
            'direct_call_edge_target_classification_counts': dict(edge_classes),
            'unique_target_classification_counts': dict(target_classes),
            'entry_ida_mnemonic_counts': dict(entry_mnemonics),
            'entry_raw_prefix_counts': dict(entry_raw_prefixes),
            'all_unique_target_entries_match_original_bytes': True,
            'all_unique_target_entries_are_original_code_items': True,
            'rows': rows,
        }
    output = {
        'schema': 1,
        'architectures': architectures,
        'interpretation_limit': ('entry bytes and IDA mnemonic observations do not establish a function boundary, '
                                'prologue semantics, calling convention, ABI, argument locations, return values, or behavior'),
    }
    (REPORT / 'direct-call-target-entry-observations.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({architecture: {
        'unique_direct_call_target_count': data['unique_direct_call_target_count'],
        'all_checks_passed': True,
    } for architecture, data in architectures.items()}))


if __name__ == '__main__':
    main()
