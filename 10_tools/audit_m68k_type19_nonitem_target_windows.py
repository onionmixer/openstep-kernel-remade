"""Audit bounded raw windows for m68k type-19 targets not at text-item starts."""
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'


def rows(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def raw_item(binary, unit, text_start, text_offset):
    address = int(unit['address'], 16)
    raw = binary[text_offset + address - text_start:
                 text_offset + address - text_start + int(unit['length'])]
    assert raw.hex() == unit['bytes']
    return {'address': unit['address'], 'kind': unit['kind'],
            'original_bytes': raw.hex(), 'ida_disassembly': unit['disassembly']}


def decode(source, raw):
    word = int.from_bytes(raw[:2], 'big')
    if word & 0xf000 == 0x6000:
        low = word & 0xff
        displacement = int.from_bytes(raw[2:4] if low == 0 else raw[2:6] if low == 0xff else raw[1:2],
                                      'big', signed=True)
        return (source + 2 + displacement) & 0xffffffff, displacement, 'bcc'
    if word & 0xf0f8 == 0x50c8:
        displacement = int.from_bytes(raw[2:4], 'big', signed=True)
        return (source + 2 + displacement) & 0xffffffff, displacement, 'dbcc'
    if word & 0xff00 == 0xf200:
        displacement = int.from_bytes(raw[2:6], 'big', signed=True)
        return (source + 2 + displacement) & 0xffffffff, displacement, 'fpu_branch'
    if word == 0x4ef9:
        target = int.from_bytes(raw[2:6], 'big')
        return target, target, 'absolute_long_jmp'
    raise AssertionError(hex(word))


def main():
    binary = (ROOT / '03_original/m68k/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/m68k/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_end = text_start + int(text['size'])
    text_offset = int(text['file_offset'])
    unit_rows = rows(ROOT / '05_ida/exports/m68k/text-units.tsv')
    units = {int(row['address'], 16): row for row in unit_rows}
    index_by_address = {int(row['address'], 16): index for index, row in enumerate(unit_rows)}
    output_rows = []
    unique_targets = set()
    for xref in rows(ROOT / '05_ida/exports/m68k/xrefs.tsv'):
        source = int(xref['from'], 16)
        if xref['type'] != '19' or source not in units:
            continue
        source_item = raw_item(binary, units[source], text_start, text_offset)
        target, field_value, form = decode(source, bytes.fromhex(source_item['original_bytes']))
        assert target == int(xref['to'], 16)
        if target in units:
            continue
        assert text_start <= target < text_end
        containing = next(row for row in unit_rows
                          if int(row['address'], 16) < target < int(row['address'], 16) + int(row['length']))
        containing_item = raw_item(binary, containing, text_start, text_offset)
        target_offset = target - int(containing['address'], 16)
        target_raw = binary[text_offset + target - text_start:text_offset + target - text_start + 4]
        assert len(target_raw) == 4
        containing_index = index_by_address[int(containing['address'], 16)]
        window = [raw_item(binary, row, text_start, text_offset)
                  for row in unit_rows[max(0, containing_index - 2):containing_index + 3]]
        next_unit = units.get(source + len(bytes.fromhex(source_item['original_bytes'])))
        assert next_unit is not None
        output_rows.append({
            'source_item': source_item,
            'encoding_form': form,
            'signed_displacement_or_absolute_target_field': field_value,
            'computed_target': hex(target),
            'target_original_four_bytes': target_raw.hex(),
            'containing_item': containing_item,
            'target_byte_offset_within_containing_item': target_offset,
            'containing_item_bounded_window': window,
            'immediate_next_item': raw_item(binary, next_unit, text_start, text_offset),
        })
        unique_targets.add(target)
    assert len(output_rows) == 3 and len(unique_targets) == 2
    output = {
        'schema': 1,
        'architecture': 'm68k',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'type19_nonitem_target_edge_count': len(output_rows),
        'unique_nonitem_target_count': len(unique_targets),
        'all_raw_target_calculations_and_containing_item_windows_match_original_bytes': True,
        'interpretation_limit': ('non-item-start target byte mappings and bounded item windows do not establish '
                                 'instruction boundaries, code or data reclassification, branch execution, '
                                 'reachability, function boundaries, calling convention, ABI, or behavior'),
        'rows': output_rows,
    }
    (REPORT / 'm68k-type19-nonitem-target-windows-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'edge_count': len(output_rows), 'unique_target_count': len(unique_targets),
                      'all_checks_passed': True}))


if __name__ == '__main__':
    main()
