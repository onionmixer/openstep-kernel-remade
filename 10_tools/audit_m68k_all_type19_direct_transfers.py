"""Verify every m68k text-sourced type-19 direct transfer against raw bytes."""
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


def decoder(source, raw):
    word = int.from_bytes(raw[:2], 'big')
    if word & 0xf000 == 0x6000:
        low = word & 0xff
        if low == 0:
            value = int.from_bytes(raw[2:4], 'big', signed=True)
            form = 'bcc_word_displacement'
        elif low == 0xff:
            value = int.from_bytes(raw[2:6], 'big', signed=True)
            form = 'bcc_long_displacement'
        else:
            value = int.from_bytes(raw[1:2], 'big', signed=True)
            form = 'bcc_byte_displacement'
        return (source + 2 + value) & 0xffffffff, value, form
    if word & 0xf0f8 == 0x50c8:
        value = int.from_bytes(raw[2:4], 'big', signed=True)
        return (source + 2 + value) & 0xffffffff, value, 'dbcc_word_displacement'
    if word & 0xff00 == 0xf200:
        value = int.from_bytes(raw[2:6], 'big', signed=True)
        return (source + 2 + value) & 0xffffffff, value, 'fpu_branch_long_displacement'
    if word == 0x4ef9:
        value = int.from_bytes(raw[2:6], 'big')
        return value, value, 'absolute_long_jmp_target_field'
    raise AssertionError(f'unsupported type-19 source word {word:#x}')


def source_membership(address, starts, ranges):
    index = bisect.bisect_right(starts, address) - 1
    return 'candidate' if index >= 0 and address < ranges[index][1] else 'candidate_gap'


def main():
    binary = (ROOT / '03_original/m68k/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/m68k/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_end = text_start + int(text['size'])
    text_offset = int(text['file_offset'])
    candidates = tsv_rows(ROOT / '05_ida/exports/m68k/function-candidate-lexical-exits.tsv')
    ranges = sorted((int(row['start'], 16), int(row['end'], 16)) for row in candidates)
    starts = [start for start, _ in ranges]
    units = {int(row['address'], 16): row
             for row in tsv_rows(ROOT / '05_ida/exports/m68k/text-units.tsv')}
    xrefs = tsv_rows(ROOT / '05_ida/exports/m68k/xrefs.tsv')
    kind_counts = Counter()
    membership_counts = Counter()
    target_mapping_counts = Counter()
    next_kind_counts = Counter()
    exceptions = []
    count = 0
    for xref in xrefs:
        source = int(xref['from'], 16)
        if xref['type'] != '19' or source not in units:
            continue
        source_item = raw_item(binary, units[source], text_start, text_offset)
        assert source_item['kind'] == 'code'
        raw = bytes.fromhex(source_item['original_bytes'])
        target, field_value, form = decoder(source, raw)
        assert target == int(xref['to'], 16)
        count += 1
        kind_counts[form] += 1
        membership_counts[source_membership(source, starts, ranges)] += 1
        target_unit = units.get(target)
        if target_unit is None:
            assert text_start <= target < text_end
            target_data = {'mapping_kind': 'mapped_text_without_item_start', 'address': hex(target),
                           'original_four_bytes': binary[text_offset + target - text_start:
                                                         text_offset + target - text_start + 4].hex()}
        else:
            target_data = {'mapping_kind': f"text_item_{target_unit['kind']}",
                           'item': raw_item(binary, target_unit, text_start, text_offset)}
        target_mapping_counts[target_data['mapping_kind']] += 1
        next_unit = units.get(source + len(raw))
        next_data = None if next_unit is None else raw_item(binary, next_unit, text_start, text_offset)
        next_kind = 'no_text_item' if next_data is None else next_data['kind']
        next_kind_counts[next_kind] += 1
        if target_data['mapping_kind'] == 'mapped_text_without_item_start' or next_kind != 'code':
            exceptions.append({'source_item': source_item, 'encoding_form': form,
                               'signed_displacement_or_absolute_target_field': field_value,
                               'target': hex(target), 'target_mapping': target_data,
                               'immediate_next_item': next_data})
    assert count == 28285
    assert len(exceptions) == 33
    output = {
        'schema': 1,
        'architecture': 'm68k',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'type19_direct_transfer_count': count,
        'encoding_form_counts': dict(sorted(kind_counts.items())),
        'source_candidate_membership_counts': dict(sorted(membership_counts.items())),
        'target_mapping_counts': dict(sorted(target_mapping_counts.items())),
        'immediate_next_item_kind_counts': dict(sorted(next_kind_counts.items())),
        'exception_count': len(exceptions),
        'all_computed_targets_match_raw_big_endian_fields_type19_xrefs_and_original_mappings': True,
        'interpretation_limit': ('direct transfer encodings, target mappings, and adjacent item classifications '
                                 'do not establish branch conditions, execution, fallthrough, path reachability, '
                                 'function boundaries, calling convention, ABI, or behavior'),
        'exceptions': exceptions,
    }
    (REPORT / 'm68k-all-type19-direct-transfers-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'type19_direct_transfer_count': count,
                      'exception_count': len(exceptions), 'all_checks_passed': True}))


if __name__ == '__main__':
    main()
