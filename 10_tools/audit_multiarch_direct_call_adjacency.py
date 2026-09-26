"""Export original-byte neighboring items around every raw direct call edge."""
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
EXPECTED = {'m68k': 10543, 'sparc': 17607}


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def item_evidence(binary, unit, text_start, text_offset):
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


def computed_target(architecture, source, raw, kind):
    if architecture == 'm68k' and kind == 'bsr_long_relative':
        assert int.from_bytes(raw[:2], 'big') == 0x61ff
        return (source + 2 + int.from_bytes(raw[2:6], 'big', signed=True)) & 0xffffffff
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
        units = read_tsv(ROOT / '05_ida/exports' / architecture / 'text-units.tsv')
        unit_index = {int(unit['address'], 16): index for index, unit in enumerate(units)}
        xrefs = read_tsv(ROOT / '05_ida/exports' / architecture / 'xrefs.tsv')
        xref_keys = {(int(xref['from'], 16), int(xref['to'], 16), xref['type'], xref['iscode'])
                     for xref in xrefs}
        rows = []
        neighbor_kind_counts = Counter()
        for edge in edges:
            source = int(edge['source'], 16)
            target = int(edge['target'], 16)
            index = unit_index[source]
            source_unit = units[index]
            source_evidence = item_evidence(binary, source_unit, text_start, text_offset)
            source_raw = bytes.fromhex(source_evidence['original_bytes'])
            assert source_unit['kind'] == 'code'
            assert source_raw.hex() == edge['instruction_bytes']
            assert computed_target(architecture, source, source_raw, edge['edge_kind']) == target
            assert (source, target, '17', '1') in xref_keys
            if architecture == 'm68k':
                selected = [('preceding_item', units[index - 1]), ('following_item', units[index + 1])]
                assert int(selected[0][1]['address'], 16) + int(selected[0][1]['length']) == source
                assert int(selected[1][1]['address'], 16) == source + int(source_unit['length'])
            else:
                selected = [
                    ('preceding_item', units[index - 1]),
                    ('delay_slot_item', units[index + 1]),
                    ('post_delay_item', units[index + 2]),
                ]
                assert int(selected[0][1]['address'], 16) + int(selected[0][1]['length']) == source
                assert int(selected[1][1]['address'], 16) == source + 4
                assert int(selected[2][1]['address'], 16) == source + 8
            neighbors = {}
            for role, unit in selected:
                evidence = item_evidence(binary, unit, text_start, text_offset)
                neighbors[role] = evidence
                neighbor_kind_counts[f'{role}:{unit["kind"]}'] += 1
            rows.append({
                'source': edge['source'],
                'target': edge['target'],
                'edge_kind': edge['edge_kind'],
                'call_item': source_evidence,
                'adjacent_items': neighbors,
            })
        assert len(rows) == EXPECTED[architecture]
        architectures[architecture] = {
            'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
            'direct_call_edge_count': len(rows),
            'adjacent_item_kind_counts': dict(neighbor_kind_counts),
            'all_caller_encodings_compute_to_type17_xref_targets': True,
            'all_call_and_adjacent_text_items_match_original_big_endian_bytes': True,
            'rows': rows,
        }
    output = {
        'schema': 1,
        'architectures': architectures,
        'interpretation_limit': ('call-adjacent raw items are static observations only; they do not establish '
                                'argument preparation, delay-slot execution, call return, reachability, function '
                                'boundaries, calling convention, ABI, or behavior'),
    }
    (REPORT / 'multiarch-direct-call-adjacency-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({architecture: {
        'direct_call_edge_count': data['direct_call_edge_count'],
        'adjacent_item_kind_counts': data['adjacent_item_kind_counts'],
        'all_checks_passed': True,
    } for architecture, data in architectures.items()}))


if __name__ == '__main__':
    main()
