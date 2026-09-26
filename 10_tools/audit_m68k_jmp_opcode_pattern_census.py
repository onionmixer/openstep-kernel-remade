"""Census raw m68k JMP opcode-pattern items without resolving EA runtime targets."""
import bisect
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'


def rows(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def item(binary, row, text_start, text_offset):
    address = int(row['address'], 16)
    raw = binary[text_offset + address - text_start:text_offset + address - text_start + int(row['length'])]
    assert raw.hex() == row['bytes']
    return {'address': row['address'], 'kind': row['kind'],
            'original_bytes': raw.hex(), 'ida_disassembly': row['disassembly']}


def candidate_member(address, starts, ranges):
    index = bisect.bisect_right(starts, address) - 1
    return index >= 0 and address < ranges[index][1]


def main():
    binary = (ROOT / '03_original/m68k/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/m68k/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_offset = int(text['file_offset'])
    candidates = rows(ROOT / '05_ida/exports/m68k/function-candidate-lexical-exits.tsv')
    ranges = sorted((int(row['start'], 16), int(row['end'], 16)) for row in candidates)
    starts = [start for start, _ in ranges]
    unit_rows = rows(ROOT / '05_ida/exports/m68k/text-units.tsv')
    unit_by_address = {int(row['address'], 16): row for row in unit_rows}
    xrefs_by_source = {}
    for xref in rows(ROOT / '05_ida/exports/m68k/xrefs.tsv'):
        xrefs_by_source.setdefault(int(xref['from'], 16), []).append(xref)
    results = []
    pattern_counts = Counter()
    membership_counts = Counter()
    xref_shape_counts = Counter()
    direct_target_kind_counts = Counter()
    direct_count = 0
    unresolved_count = 0
    for row in unit_rows:
        if row['kind'] != 'code':
            continue
        source = int(row['address'], 16)
        source_item = item(binary, row, text_start, text_offset)
        raw = bytes.fromhex(source_item['original_bytes'])
        if len(raw) < 2 or int.from_bytes(raw[:2], 'big') & 0xffc0 != 0x4ec0:
            continue
        word = int.from_bytes(raw[:2], 'big')
        source_xrefs = sorted(xrefs_by_source.get(source, []), key=lambda x: (x['type'], x['to']))
        membership = 'candidate' if candidate_member(source, starts, ranges) else 'candidate_gap'
        membership_counts[membership] += 1
        xref_shape_counts[str(tuple((x['type'], x['iscode']) for x in source_xrefs))] += 1
        if word == 0x4ef9:
            target = int.from_bytes(raw[2:6], 'big')
            assert any(x['type'] == '19' and int(x['to'], 16) == target for x in source_xrefs)
            target_row = unit_by_address.get(target)
            direct_target_kind_counts['no_text_item' if target_row is None else target_row['kind']] += 1
            target_data = {'absolute_target_field': hex(target),
                           'target_text_item': None if target_row is None else item(binary, target_row, text_start, text_offset)}
            kind = 'absolute_long_direct'
            direct_count += 1
        else:
            assert not source_xrefs
            target_data = {'runtime_target': 'unresolved_from_original_file_bytes'}
            kind = f'effective_address_word_{word:04x}'
            unresolved_count += 1
        pattern_counts[kind] += 1
        results.append({'source_item': source_item, 'source_candidate_membership': membership,
                        'opcode_pattern': kind, 'source_xrefs': source_xrefs, 'target_data': target_data})
    assert len(results) == 164
    assert direct_count == 42 and unresolved_count == 122
    output = {
        'schema': 1,
        'architecture': 'm68k',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'jmp_opcode_pattern_count': len(results),
        'opcode_pattern_counts': dict(sorted(pattern_counts.items())),
        'source_candidate_membership_counts': dict(sorted(membership_counts.items())),
        'xref_shape_counts': dict(sorted(xref_shape_counts.items())),
        'absolute_long_direct_count': direct_count,
        'absolute_long_direct_target_item_kind_counts': dict(sorted(direct_target_kind_counts.items())),
        'nonabsolute_effective_address_count_with_runtime_target_unresolved': unresolved_count,
        'all_opcode_items_match_original_bytes_and_absolute_targets_match_type19_xrefs': True,
        'interpretation_limit': ('this opcode-pattern census does not establish JMP execution, effective-address '
                                 'values, runtime targets, path reachability, function boundaries, calling '
                                 'convention, ABI, or behavior'),
        'rows': results,
    }
    (REPORT / 'm68k-jmp-opcode-pattern-census-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'jmp_opcode_pattern_count': len(results),
                      'runtime_target_unresolved_count': unresolved_count,
                      'all_checks_passed': True}))


if __name__ == '__main__':
    main()
