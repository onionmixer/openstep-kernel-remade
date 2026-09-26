"""Preserve source-next-item evidence for all m68k direct calls in candidate gaps."""
import csv
import hashlib
import json
from bisect import bisect_right
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def signed_u32(value):
    return value - (1 << 32) if value & (1 << 31) else value


def main():
    binary = (ROOT / '03_original/m68k/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/m68k/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_offset = int(text['file_offset'])
    gaps = json.loads((REPORT / 'm68k-direct-call-outside-function-candidates.json').read_text())
    gap_ranges = [(int(row['gap_start'], 16), int(row['gap_end_exclusive'], 16))
                  for row in gaps['gaps_containing_direct_call_sources']]
    gap_starts = [start for start, _ in gap_ranges]
    edges = read_tsv(ROOT / '05_ida/exports/m68k/direct-call-edges.tsv')
    units = read_tsv(ROOT / '05_ida/exports/m68k/text-units.tsv')
    units_by_address = {int(unit['address'], 16): unit for unit in units}
    unit_index = {int(unit['address'], 16): index for index, unit in enumerate(units)}
    xrefs = read_tsv(ROOT / '05_ida/exports/m68k/xrefs.tsv')
    xrefs_by_key = {}
    for xref in xrefs:
        key = (int(xref['from'], 16), int(xref['to'], 16), xref['type'], xref['iscode'])
        xrefs_by_key.setdefault(key, []).append(xref)
    candidates = json.loads((ROOT / '05_ida/exports/m68k/function-asm-index.json').read_text())
    candidate_ranges = sorted((int(candidate['start'], 16), int(candidate['end'], 16))
                              for candidate in candidates)

    def candidate_relation(address):
        for start, end in candidate_ranges:
            if start <= address < end:
                return 'inside_ida_candidate_range'
        index = bisect_right(gap_starts, address) - 1
        if index >= 0 and gap_ranges[index][0] <= address < gap_ranges[index][1]:
            return 'inside_candidate_gap'
        return 'outside_ida_candidate_and_gap_ranges'

    rows = []
    kind_counts = Counter()
    relation_counts = Counter()
    for edge in edges:
        source = int(edge['source'], 16)
        gap_index = bisect_right(gap_starts, source) - 1
        if gap_index < 0 or not (gap_ranges[gap_index][0] <= source < gap_ranges[gap_index][1]):
            continue
        target = int(edge['target'], 16)
        source_unit = units_by_address[source]
        source_index = unit_index[source]
        next_unit = units[source_index + 1]
        source_position = text_offset + source - text_start
        source_raw = binary[source_position:source_position + int(source_unit['length'])]
        assert source_raw.hex() == edge['instruction_bytes'] == source_unit['bytes']
        if edge['edge_kind'] == 'bsr_long_relative':
            assert int.from_bytes(source_raw[:2], 'big') == 0x61ff
            computed_target = (source + 2 + signed_u32(int.from_bytes(source_raw[2:6], 'big'))) & 0xffffffff
        elif edge['edge_kind'] == 'jsr_absolute_long':
            assert int.from_bytes(source_raw[:2], 'big') == 0x4eb9
            computed_target = int.from_bytes(source_raw[2:6], 'big')
        else:
            raise AssertionError(edge['edge_kind'])
        assert computed_target == target
        matching_xrefs = xrefs_by_key.get((source, target, '17', '1'), [])
        assert len(matching_xrefs) == 1
        next_address = int(next_unit['address'], 16)
        expected_next_address = source + int(source_unit['length'])
        assert next_address == expected_next_address
        next_position = text_offset + next_address - text_start
        next_raw = binary[next_position:next_position + int(next_unit['length'])]
        assert next_raw.hex() == next_unit['bytes']
        relation = candidate_relation(next_address)
        kind_counts[next_unit['kind']] += 1
        relation_counts[relation] += 1
        rows.append({
            'gap_start': hex(gap_ranges[gap_index][0]),
            'gap_end_exclusive': hex(gap_ranges[gap_index][1]),
            'source': edge['source'],
            'target': edge['target'],
            'edge_kind': edge['edge_kind'],
            'source_original_bytes': source_raw.hex(),
            'xref': matching_xrefs[0],
            'next_text_item': {
                'address': next_unit['address'],
                'kind': next_unit['kind'],
                'original_bytes': next_raw.hex(),
                'ida_disassembly': next_unit['disassembly'],
                'range_relation': relation,
            },
        })
    assert len(rows) == 1127
    output = {
        'schema': 1,
        'architecture': 'm68k',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'gap_direct_call_source_count': len(rows),
        'next_text_item_kind_counts': dict(kind_counts),
        'next_text_item_range_relation_counts': dict(relation_counts),
        'all_source_encodings_compute_to_type17_xref_targets': True,
        'all_immediate_next_text_items_match_original_big_endian_bytes': True,
        'rows': rows,
        'interpretation_limit': ('the immediate item after a CALL is a static adjacent address only; it does not '
                                'establish call return, execution, function ownership, reachability, ABI, or behavior'),
    }
    (REPORT / 'm68k-gap-direct-call-next-item-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'gap_direct_call_source_count': len(rows),
                      'next_text_item_kind_counts': dict(kind_counts),
                      'next_text_item_range_relation_counts': dict(relation_counts),
                      'all_checks_passed': True}))


if __name__ == '__main__':
    main()
