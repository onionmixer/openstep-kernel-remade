"""Census raw m68k JSR opcode-pattern items without resolving EA runtime targets."""
import bisect
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'


def tsv_rows(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def raw_item(binary, unit, text_start, text_offset):
    address = int(unit['address'], 16)
    raw = binary[text_offset + address - text_start:
                 text_offset + address - text_start + int(unit['length'])]
    assert raw.hex() == unit['bytes']
    return {'address': unit['address'], 'kind': unit['kind'],
            'original_bytes': raw.hex(), 'ida_disassembly': unit['disassembly']}


def candidate_membership(address, starts, ranges):
    index = bisect.bisect_right(starts, address) - 1
    return index >= 0 and address < ranges[index][1]


def main():
    binary = (ROOT / '03_original/m68k/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/m68k/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_offset = int(text['file_offset'])
    candidate_rows = tsv_rows(ROOT / '05_ida/exports/m68k/function-candidate-lexical-exits.tsv')
    ranges = sorted((int(row['start'], 16), int(row['end'], 16)) for row in candidate_rows)
    starts = [start for start, _ in ranges]
    units_list = tsv_rows(ROOT / '05_ida/exports/m68k/text-units.tsv')
    units = {int(row['address'], 16): row for row in units_list}
    xrefs = tsv_rows(ROOT / '05_ida/exports/m68k/xrefs.tsv')
    xrefs_by_source = {}
    for xref in xrefs:
        xrefs_by_source.setdefault(int(xref['from'], 16), []).append(xref)
    direct_edges = tsv_rows(ROOT / '05_ida/exports/m68k/direct-call-edges.tsv')
    direct_by_source = {int(row['source'], 16): row for row in direct_edges}
    rows = []
    pattern_counts = Counter()
    source_membership_counts = Counter()
    xref_shape_counts = Counter()
    next_item_kind_counts = Counter()
    direct_source_count = 0
    nonabsolute_source_count = 0
    for unit in units_list:
        if unit['kind'] != 'code':
            continue
        source = int(unit['address'], 16)
        source_item = raw_item(binary, unit, text_start, text_offset)
        raw = bytes.fromhex(source_item['original_bytes'])
        if len(raw) < 2 or int.from_bytes(raw[:2], 'big') & 0xffc0 != 0x4e80:
            continue
        word = int.from_bytes(raw[:2], 'big')
        membership = 'candidate' if candidate_membership(source, starts, ranges) else 'candidate_gap'
        source_membership_counts[membership] += 1
        source_xrefs = sorted(xrefs_by_source.get(source, []), key=lambda row: (row['type'], row['to']))
        xref_shape = tuple((row['type'], row['iscode']) for row in source_xrefs)
        xref_shape_counts[str(xref_shape)] += 1
        next_address = source + len(raw)
        next_unit = units.get(next_address)
        next_item = None if next_unit is None else raw_item(binary, next_unit, text_start, text_offset)
        next_item_kind_counts['no_text_item' if next_item is None else next_item['kind']] += 1
        if word == 0x4eb9:
            kind = 'absolute_long_direct'
            target = int.from_bytes(raw[2:6], 'big')
            edge = direct_by_source.get(source)
            assert edge is not None and edge['edge_kind'] == 'jsr_absolute_long'
            assert target == int(edge['target'], 16)
            assert any(row['type'] == '17' and int(row['to'], 16) == target for row in source_xrefs)
            direct_source_count += 1
            target_data = {'absolute_target_field': hex(target),
                           'direct_call_corpus_target': edge['target']}
        else:
            kind = f'effective_address_word_{word:04x}'
            assert source not in direct_by_source
            nonabsolute_source_count += 1
            target_data = {'runtime_target': 'unresolved_from_original_file_bytes'}
        pattern_counts[kind] += 1
        rows.append({
            'source_item': source_item,
            'source_candidate_membership': membership,
            'opcode_pattern': kind,
            'next_text_item': next_item,
            'source_xrefs': source_xrefs,
            'target_data': target_data,
        })
    assert len(rows) == 1761
    assert direct_source_count == 22 and nonabsolute_source_count == 1739
    output = {
        'schema': 1,
        'architecture': 'm68k',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'direct_call_corpus_sha256': hashlib.sha256(
            (ROOT / '05_ida/exports/m68k/direct-call-edges.tsv').read_bytes()).hexdigest(),
        'jsr_opcode_pattern_count': len(rows),
        'opcode_pattern_counts': dict(sorted(pattern_counts.items())),
        'source_candidate_membership_counts': dict(sorted(source_membership_counts.items())),
        'xref_shape_counts': dict(sorted(xref_shape_counts.items())),
        'next_text_item_kind_counts': dict(sorted(next_item_kind_counts.items())),
        'absolute_long_direct_count': direct_source_count,
        'nonabsolute_effective_address_count_with_runtime_target_unresolved': nonabsolute_source_count,
        'all_opcode_items_match_original_bytes_and_absolute_targets_match_direct_call_corpus': True,
        'interpretation_limit': ('this opcode-pattern census does not establish JSR execution, return behavior, '
                                 'effective-address values, runtime targets, function boundaries, calling convention, '
                                 'ABI, or behavior'),
        'rows': rows,
    }
    (REPORT / 'm68k-jsr-opcode-pattern-census-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'jsr_opcode_pattern_count': len(rows),
                      'runtime_target_unresolved_count': nonabsolute_source_count,
                      'all_checks_passed': True}))


if __name__ == '__main__':
    main()
