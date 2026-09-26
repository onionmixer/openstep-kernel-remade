"""Verify the non-Bcc/DBcc m68k type-19 transfers in candidate gaps."""
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
    file_offset = text_offset + address - text_start
    raw = binary[file_offset:file_offset + int(unit['length'])]
    assert raw.hex() == unit['bytes']
    return {
        'address': unit['address'], 'kind': unit['kind'],
        'original_bytes': raw.hex(), 'ida_disassembly': unit['disassembly'],
    }


def candidate_at(address, starts, ranges):
    index = bisect.bisect_right(starts, address) - 1
    if index >= 0 and address < ranges[index]['end']:
        return ranges[index]
    return None


def gap_at(address, text_start, text_end, starts, ranges):
    index = bisect.bisect_right(starts, address) - 1
    assert candidate_at(address, starts, ranges) is None
    lower = ranges[index]['end'] if index >= 0 else text_start
    upper = starts[index + 1] if index + 1 < len(starts) else text_end
    assert lower <= address < upper
    return {'start': hex(lower), 'end': hex(upper)}


def decode(source, raw):
    word = int.from_bytes(raw[:2], 'big')
    if word & 0xff00 == 0xf200:
        assert len(raw) == 6
        displacement = int.from_bytes(raw[2:6], 'big', signed=True)
        return ((source + 2 + displacement) & 0xffffffff,
                displacement, 'fpu_branch_long_displacement')
    if word == 0x4ef9:
        assert len(raw) == 6
        absolute_target = int.from_bytes(raw[2:6], 'big')
        return absolute_target, absolute_target, 'absolute_long_jmp_target_field'
    raise AssertionError(f'unsupported transfer {word:#x}')


def main():
    binary = (ROOT / '03_original/m68k/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/m68k/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_end = text_start + int(text['size'])
    text_offset = int(text['file_offset'])
    candidate_rows = tsv_rows(ROOT / '05_ida/exports/m68k/function-candidate-lexical-exits.tsv')
    ranges = sorted(({'start': int(row['start'], 16), 'end': int(row['end'], 16),
                      'name': row['name'], 'lexical_exit_count': row['lexical_exit_count']}
                     for row in candidate_rows), key=lambda row: row['start'])
    assert all(left['end'] <= right['start'] for left, right in zip(ranges, ranges[1:]))
    starts = [row['start'] for row in ranges]
    units = {int(row['address'], 16): row
             for row in tsv_rows(ROOT / '05_ida/exports/m68k/text-units.tsv')}
    xrefs = tsv_rows(ROOT / '05_ida/exports/m68k/xrefs.tsv')
    rows = []
    transfer_kind_counts = Counter()
    target_relation_counts = Counter()
    source_gap_counts = Counter()
    next_kind_counts = Counter()
    for xref in xrefs:
        source = int(xref['from'], 16)
        if xref['type'] != '19' or source not in units:
            continue
        if candidate_at(source, starts, ranges) is not None:
            continue
        source_item = raw_item(binary, units[source], text_start, text_offset)
        raw = bytes.fromhex(source_item['original_bytes'])
        word = int.from_bytes(raw[:2], 'big')
        if not (word & 0xff00 == 0xf200 or word == 0x4ef9):
            continue
        target = int(xref['to'], 16)
        computed, field_value, transfer_kind = decode(source, raw)
        assert computed == target
        assert target in units
        target_item = raw_item(binary, units[target], text_start, text_offset)
        assert target_item['kind'] == 'code'
        next_unit = units.get(source + len(raw))
        assert next_unit is not None
        next_item = raw_item(binary, next_unit, text_start, text_offset)
        gap = gap_at(source, text_start, text_end, starts, ranges)
        source_gap_counts[f"{gap['start']}..{gap['end']}"] += 1
        transfer_kind_counts[transfer_kind] += 1
        next_kind_counts[next_item['kind']] += 1
        target_candidate = candidate_at(target, starts, ranges)
        relation = 'candidate' if target_candidate is not None else 'candidate_gap'
        target_relation_counts[relation] += 1
        rows.append({
            'source': hex(source), 'source_gap': gap, 'source_item': source_item,
            'transfer_kind': transfer_kind,
            'signed_displacement_or_absolute_target_field': field_value,
            'immediate_next_item': next_item,
            'target': hex(target), 'target_item': target_item,
            'target_relation': relation,
            'target_candidate': None if target_candidate is None else {
                'name': target_candidate['name'], 'start': hex(target_candidate['start']),
                'end': hex(target_candidate['end']), 'lexical_exit_count': target_candidate['lexical_exit_count'],
            },
        })
    assert len(rows) == 20
    assert transfer_kind_counts == Counter({'fpu_branch_long_displacement': 18,
                                            'absolute_long_jmp_target_field': 2})
    output = {
        'schema': 1,
        'architecture': 'm68k',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'remaining_type19_transfer_count_in_candidate_gaps': len(rows),
        'transfer_kind_counts': dict(sorted(transfer_kind_counts.items())),
        'source_gap_count': len(source_gap_counts),
        'source_gap_transfer_counts': dict(sorted(source_gap_counts.items())),
        'target_relation_counts': dict(sorted(target_relation_counts.items())),
        'immediate_next_item_kind_counts': dict(sorted(next_kind_counts.items())),
        'all_computed_targets_match_raw_big_endian_fields_type19_xrefs_and_original_items': True,
        'interpretation_limit': ('candidate-gap direct transfer encodings, next items, and target candidate '
                                 'membership do not establish gap code ownership, branch conditions, fallthrough, '
                                 'path reachability, function boundaries, calling convention, ABI, or behavior'),
        'rows': rows,
    }
    (REPORT / 'm68k-candidate-gap-remaining-type19-transfers-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'remaining_type19_transfer_count_in_candidate_gaps': len(rows),
                      'all_checks_passed': True}))


if __name__ == '__main__':
    main()
