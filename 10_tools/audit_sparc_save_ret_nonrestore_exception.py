"""Preserve bounded raw evidence for the called SAVE/RET non-RESTORE adjacency exception."""
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
TARGET = 0xF000791C


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


def target_from_call(source, raw):
    word = int.from_bytes(raw, 'big')
    assert word >> 30 == 1
    displacement = word & 0x3fffffff
    if displacement & 0x20000000:
        displacement -= 1 << 30
    return (source + (displacement << 2)) & 0xffffffff


def main():
    binary = (ROOT / '03_original/sparc/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/sparc/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_offset = int(text['file_offset'])
    candidates = {int(candidate['start'], 16): candidate for candidate in
                  read_tsv(ROOT / '05_ida/exports/sparc/function-candidate-lexical-exits.tsv')}
    candidate = candidates[TARGET]
    end = int(candidate['end'], 16)
    assert candidate['lexical_exits'] == '0xf0007f64:ret,0xf0007f74:ret,0xf0007f98:ret'
    units = read_tsv(ROOT / '05_ida/exports/sparc/text-units.tsv')
    units_by_address = {int(unit['address'], 16): unit for unit in units}
    unit_index = {int(unit['address'], 16): index for index, unit in enumerate(units)}
    candidate_units = [unit for unit in units if TARGET <= int(unit['address'], 16) < end]
    assert int(candidate_units[0]['address'], 16) == TARGET
    assert int(candidate_units[-1]['address'], 16) + int(candidate_units[-1]['length']) == end
    assert all(unit['kind'] == 'code' for unit in candidate_units)
    assert all(int(left['address'], 16) + int(left['length']) == int(right['address'], 16)
               for left, right in zip(candidate_units, candidate_units[1:]))
    for unit in candidate_units:
        raw_item(binary, unit, text_start, text_offset)
    xrefs = read_tsv(ROOT / '05_ida/exports/sparc/xrefs.tsv')
    xref_keys = {(int(xref['from'], 16), int(xref['to'], 16), xref['type'], xref['iscode'])
                 for xref in xrefs}
    edges = [edge for edge in read_tsv(ROOT / '05_ida/exports/sparc/direct-call-edges.tsv')
             if int(edge['target'], 16) == TARGET]
    callers = []
    for edge in edges:
        source = int(edge['source'], 16)
        unit = units_by_address[source]
        evidence = raw_item(binary, unit, text_start, text_offset)
        raw = bytes.fromhex(evidence['original_bytes'])
        assert target_from_call(source, raw) == TARGET
        assert (source, TARGET, '17', '1') in xref_keys
        callers.append({'source': edge['source'], 'original_bytes': raw.hex()})
    exit_pairs = []
    for token in candidate['lexical_exits'].split(','):
        exit_address = int(token.split(':', 1)[0], 16)
        exit_unit = units_by_address[exit_address]
        delay_unit = units[unit_index[exit_address] + 1]
        assert int(delay_unit['address'], 16) == exit_address + int(exit_unit['length'])
        exit_pairs.append({
            'ret_item': raw_item(binary, exit_unit, text_start, text_offset),
            'delay_slot_item': raw_item(binary, delay_unit, text_start, text_offset),
        })
    assert len(callers) == 30
    assert [pair['delay_slot_item']['original_bytes'] for pair in exit_pairs][1:] == ['f60e4000', 'c02e0000']
    output = {
        'schema': 1,
        'architecture': 'sparc',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'candidate': candidate,
        'candidate_contiguous_code_item_count': len(candidate_units),
        'candidate_contiguous_code_byte_count': sum(int(unit['length']) for unit in candidate_units),
        'direct_callers': callers,
        'entry_item': raw_item(binary, units_by_address[TARGET], text_start, text_offset),
        'lexical_exit_pairs': exit_pairs,
        'all_bounded_items_and_callers_match_original_big_endian_bytes': True,
        'interpretation_limit': ('this bounded SAVE/RET layout and caller evidence does not establish delay-slot '
                                'execution, return behavior, path reachability, function boundaries, calling convention, ABI, or behavior'),
    }
    (REPORT / 'sparc-save-ret-nonrestore-exception-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'candidate_contiguous_code_item_count': len(candidate_units),
                      'direct_caller_edge_count': len(callers), 'all_checks_passed': True}))


if __name__ == '__main__':
    main()
