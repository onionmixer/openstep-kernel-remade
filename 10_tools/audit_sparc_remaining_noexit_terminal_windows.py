"""Preserve raw boundary windows for remaining SPARC no-exit terminal forms."""
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
COVERED = {'ba,a', 'call', 'restore', 'return', 'nop', 'illtrap'}


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def main():
    binary = (ROOT / '03_original/sparc/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/sparc/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    base = int(text['address'], 16)
    file_offset = int(text['file_offset'])
    terminals = [row for row in read_tsv(ROOT / '05_ida/exports/sparc/noexit-candidate-terminal-items.tsv')
                 if row['terminal_mnemonic'] not in COVERED]
    units = read_tsv(ROOT / '05_ida/exports/sparc/text-units.tsv')
    index_by_address = {int(unit['address'], 16): index for index, unit in enumerate(units)}
    rows = []
    counts = Counter()
    for terminal in terminals:
        address = int(terminal['terminal_address'], 16)
        index = index_by_address[address]
        prior_code = [unit for unit in units[:index] if unit['kind'] == 'code'][-2:]
        window = prior_code + [units[index]]
        assert int(window[-1]['address'], 16) == address
        checked_window = []
        for unit in window:
            virtual_address = int(unit['address'], 16)
            position = file_offset + virtual_address - base
            original = binary[position:position + int(unit['length'])]
            assert unit['kind'] == 'code'
            assert original.hex() == unit['bytes']
            checked_window.append({
                'address': unit['address'],
                'original_bytes': original.hex(),
                'ida_disassembly': unit['disassembly'],
            })
        candidate_end = int(terminal['end'], 16)
        next_unit = next((unit for unit in units
                          if int(unit['address'], 16) == candidate_end), None)
        checked_end = None
        if next_unit is not None:
            position = file_offset + candidate_end - base
            original = binary[position:position + int(next_unit['length'])]
            assert original.hex() == next_unit['bytes']
            checked_end = {
                'address': next_unit['address'],
                'kind': next_unit['kind'],
                'original_bytes': original.hex(),
                'ida_disassembly': next_unit['disassembly'],
            }
        counts[terminal['terminal_mnemonic']] += 1
        rows.append({
            'candidate_start': terminal['start'],
            'candidate_end': terminal['end'],
            'candidate_name': terminal['name'],
            'terminal_mnemonic': terminal['terminal_mnemonic'],
            'window': checked_window,
            'item_at_candidate_end': checked_end,
        })
    assert len(rows) == 39
    output = {
        'schema': 1,
        'architecture': 'sparc',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'remaining_terminal_window_count': len(rows),
        'terminal_mnemonic_counts': dict(counts),
        'rows': rows,
        'all_window_and_candidate_end_items_match_original': True,
        'interpretation_limit': ('bounded code windows and candidate-end adjacency do not establish '
                                'transfer semantics, reachability, function boundaries, ABI, or behavior'),
    }
    (REPORT / 'sparc-remaining-noexit-terminal-window-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'remaining_terminal_window_count': len(rows), 'all_checks_passed': True}))


if __name__ == '__main__':
    main()
