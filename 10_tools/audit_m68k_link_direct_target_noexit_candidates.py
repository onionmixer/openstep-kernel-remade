"""Bound raw LINK-entry evidence for the five directly called m68k no-exit candidates."""
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
TARGETS = (0x400159A, 0x40015E2, 0x400165E, 0x40016D0, 0x4095890)


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


def target_from_edge(source, raw, kind):
    if kind == 'bsr_long_relative':
        assert int.from_bytes(raw[:2], 'big') == 0x61ff
        return (source + 2 + int.from_bytes(raw[2:6], 'big', signed=True)) & 0xffffffff
    if kind == 'jsr_absolute_long':
        assert int.from_bytes(raw[:2], 'big') == 0x4eb9
        return int.from_bytes(raw[2:6], 'big')
    raise AssertionError(kind)


def main():
    binary = (ROOT / '03_original/m68k/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/m68k/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_offset = int(text['file_offset'])
    candidates = {int(candidate['start'], 16): candidate for candidate in
                  read_tsv(ROOT / '05_ida/exports/m68k/function-candidate-lexical-exits.tsv')}
    terminals = {int(row['start'], 16): row for row in
                 read_tsv(ROOT / '05_ida/exports/m68k/noexit-candidate-terminal-items.tsv')}
    units = read_tsv(ROOT / '05_ida/exports/m68k/text-units.tsv')
    units_by_address = {int(unit['address'], 16): unit for unit in units}
    edges = read_tsv(ROOT / '05_ida/exports/m68k/direct-call-edges.tsv')
    xrefs = read_tsv(ROOT / '05_ida/exports/m68k/xrefs.tsv')
    xref_keys = {(int(xref['from'], 16), int(xref['to'], 16), xref['type'], xref['iscode'])
                 for xref in xrefs}
    rows = []
    for target in TARGETS:
        candidate = candidates[target]
        assert int(candidate['lexical_exit_count']) == 0
        terminal = terminals[target]
        end = int(candidate['end'], 16)
        entry_unit = units_by_address[target]
        entry = raw_item(binary, entry_unit, text_start, text_offset)
        assert entry['original_bytes'].startswith('4e56')
        layout = [unit for unit in units if target <= int(unit['address'], 16) < end]
        assert int(layout[0]['address'], 16) == target
        assert int(layout[-1]['address'], 16) + int(layout[-1]['length']) == end
        assert all(unit['kind'] == 'code' for unit in layout)
        assert all(int(left['address'], 16) + int(left['length']) == int(right['address'], 16)
                   for left, right in zip(layout, layout[1:]))
        for unit in layout:
            raw_item(binary, unit, text_start, text_offset)
        terminal_unit = units_by_address[int(terminal['terminal_address'], 16)]
        target_edges = [edge for edge in edges if int(edge['target'], 16) == target]
        callers = []
        for edge in target_edges:
            source = int(edge['source'], 16)
            source_unit = units_by_address[source]
            source_item = raw_item(binary, source_unit, text_start, text_offset)
            raw = bytes.fromhex(source_item['original_bytes'])
            assert target_from_edge(source, raw, edge['edge_kind']) == target
            assert (source, target, '17', '1') in xref_keys
            callers.append({'source': edge['source'], 'edge_kind': edge['edge_kind'], 'original_bytes': raw.hex()})
        rows.append({
            'candidate': candidate,
            'entry_signed_16bit_immediate': int.from_bytes(bytes.fromhex(entry['original_bytes'])[2:4], 'big', signed=True),
            'candidate_contiguous_code_item_count': len(layout),
            'candidate_contiguous_code_byte_count': sum(int(unit['length']) for unit in layout),
            'direct_callers': callers,
            'entry_item': entry,
            'terminal_item': raw_item(binary, terminal_unit, text_start, text_offset),
            'terminal_mnemonic': terminal['terminal_mnemonic'],
        })
    assert len(rows) == 5
    assert sum(len(row['direct_callers']) for row in rows) == 135
    output = {
        'schema': 1,
        'architecture': 'm68k',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'candidate_count': len(rows),
        'direct_caller_edge_count': sum(len(row['direct_callers']) for row in rows),
        'all_link_entry_layout_terminal_and_caller_items_match_original_big_endian_bytes': True,
        'rows': rows,
        'separate_noncandidate_target': {
            'address': '0x4093976',
            'raw_symbol': '_mini_mon',
            'existing_audit': 'm68k-mini-mon-bounded-text-layout-audit.json',
        },
        'interpretation_limit': ('raw LINK entry, contiguous candidate layout, caller encoding, and terminal item do '
                                'not establish terminal reachability, function behavior, calling convention, ABI, '
                                'arguments, return values, or a complete function boundary'),
    }
    (REPORT / 'm68k-link-direct-target-noexit-candidates-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'candidate_count': len(rows), 'direct_caller_edge_count': output['direct_caller_edge_count'],
                      'all_checks_passed': True}))


if __name__ == '__main__':
    main()
