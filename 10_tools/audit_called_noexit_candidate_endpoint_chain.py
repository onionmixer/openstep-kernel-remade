"""Join raw caller, target entry, and terminal evidence for called no-exit candidates."""
import csv
import hashlib
import json
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def computed_target(architecture, source, raw, kind):
    if architecture == 'm68k' and kind == 'bsr_long_relative':
        assert int.from_bytes(raw[:2], 'big') == 0x61ff
        displacement = int.from_bytes(raw[2:6], 'big', signed=True)
        return (source + 2 + displacement) & 0xffffffff
    if architecture == 'm68k' and kind == 'jsr_absolute_long':
        assert int.from_bytes(raw[:2], 'big') == 0x4eb9
        return int.from_bytes(raw[2:6], 'big')
    if architecture == 'sparc' and kind == 'call_relative':
        word = int.from_bytes(raw, 'big')
        assert word >> 30 == 1
        displacement = word & 0x3fffffff
        if displacement & 0x20000000:
            displacement -= 1 << 30
        return (source + (displacement << 2)) & 0xffffffff
    raise AssertionError((architecture, kind))


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
        noexit = {int(candidate['start'], 16): candidate for candidate in candidates
                  if int(candidate['lexical_exit_count']) == 0}
        terminals = {int(row['start'], 16): row for row in
                     read_tsv(ROOT / '05_ida/exports' / architecture / 'noexit-candidate-terminal-items.tsv')}
        units = read_tsv(ROOT / '05_ida/exports' / architecture / 'text-units.tsv')
        units_by_address = {int(unit['address'], 16): unit for unit in units}
        xrefs = read_tsv(ROOT / '05_ida/exports' / architecture / 'xrefs.tsv')
        xref_keys = {(int(xref['from'], 16), int(xref['to'], 16), xref['type'], xref['iscode'])
                     for xref in xrefs}
        incoming = defaultdict(list)
        for edge in edges:
            target = int(edge['target'], 16)
            if target in noexit:
                incoming[target].append(edge)
        rows = []
        for target, target_edges in sorted(incoming.items()):
            candidate = noexit[target]
            terminal = terminals[target]
            entry_unit = units_by_address[target]
            terminal_address = int(terminal['terminal_address'], 16)
            terminal_unit = units_by_address[terminal_address]
            entry_position = text_offset + target - text_start
            terminal_position = text_offset + terminal_address - text_start
            entry_raw = binary[entry_position:entry_position + int(entry_unit['length'])]
            terminal_raw = binary[terminal_position:terminal_position + int(terminal_unit['length'])]
            assert entry_unit['kind'] == 'code'
            assert terminal_unit['kind'] == 'code'
            assert entry_raw.hex() == entry_unit['bytes']
            assert terminal_raw.hex() == terminal_unit['bytes']
            caller_rows = []
            for edge in target_edges:
                source = int(edge['source'], 16)
                source_unit = units_by_address[source]
                source_position = text_offset + source - text_start
                source_raw = binary[source_position:source_position + int(source_unit['length'])]
                assert source_raw.hex() == edge['instruction_bytes'] == source_unit['bytes']
                assert computed_target(architecture, source, source_raw, edge['edge_kind']) == target
                assert (source, target, '17', '1') in xref_keys
                caller_rows.append({
                    'source': edge['source'],
                    'edge_kind': edge['edge_kind'],
                    'original_bytes': source_raw.hex(),
                })
            rows.append({
                'target': hex(target),
                'candidate_end': candidate['end'],
                'direct_caller_count': len(caller_rows),
                'callers': caller_rows,
                'entry_item': {
                    'address': entry_unit['address'],
                    'original_bytes': entry_raw.hex(),
                    'ida_disassembly': entry_unit['disassembly'],
                },
                'terminal_item': {
                    'address': terminal_unit['address'],
                    'original_bytes': terminal_raw.hex(),
                    'ida_disassembly': terminal_unit['disassembly'],
                    'terminal_mnemonic': terminal['terminal_mnemonic'],
                },
            })
        expected = 50 if architecture == 'm68k' else 59
        expected_edges = 264 if architecture == 'm68k' else 356
        assert len(rows) == expected
        assert sum(row['direct_caller_count'] for row in rows) == expected_edges
        architectures[architecture] = {
            'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
            'called_noexit_candidate_count': len(rows),
            'direct_caller_edge_count': sum(row['direct_caller_count'] for row in rows),
            'all_caller_encodings_compute_to_type17_xref_targets': True,
            'all_target_entry_and_terminal_items_match_original_big_endian_bytes': True,
            'rows': rows,
        }
    output = {
        'schema': 1,
        'architectures': architectures,
        'interpretation_limit': ('a raw direct caller, target entry, and lexical-no-exit terminal belong to a '
                                'static evidence chain only; this does not establish a path from entry to terminal, '
                                'call return, reachability, boundaries, ABI, or behavior'),
    }
    (REPORT / 'called-noexit-candidate-endpoint-chain-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({architecture: {
        'called_noexit_candidate_count': data['called_noexit_candidate_count'],
        'direct_caller_edge_count': data['direct_caller_edge_count'],
        'all_checks_passed': True,
    } for architecture, data in architectures.items()}))


if __name__ == '__main__':
    main()
