"""Audit bounded raw windows for data targets of verified SETHI/op3=0x38 edges."""
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


def signed13(word):
    value = word & 0x1fff
    return value - (1 << 13) if value & (1 << 12) else value


def main():
    binary = (ROOT / '03_original/sparc/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/sparc/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_offset = int(text['file_offset'])
    unit_rows = rows(ROOT / '05_ida/exports/sparc/text-units.tsv')
    units = {int(row['address'], 16): row for row in unit_rows}
    indices = {int(row['address'], 16): index for index, row in enumerate(unit_rows)}
    xrefs = rows(ROOT / '05_ida/exports/sparc/xrefs.tsv')
    results = []
    target_addresses = set()
    for xref in xrefs:
        if xref['type'] != '3' or xref['iscode'] != '0':
            continue
        source = int(xref['from'], 16)
        if source not in units:
            continue
        source_item = raw_item(binary, units[source], text_start, text_offset)
        word = int.from_bytes(bytes.fromhex(source_item['original_bytes']), 'big')
        if word >> 30 != 2 or ((word >> 19) & 0x3f) != 0x38:
            continue
        predecessor = units.get(source - 4)
        assert predecessor is not None
        predecessor_item = raw_item(binary, predecessor, text_start, text_offset)
        predecessor_word = int.from_bytes(bytes.fromhex(predecessor_item['original_bytes']), 'big')
        assert predecessor_word >> 30 == 0 and ((predecessor_word >> 22) & 0x7) == 4
        assert ((word >> 13) & 1) == 1
        assert ((predecessor_word >> 25) & 0x1f) == ((word >> 14) & 0x1f)
        target = (((predecessor_word & ((1 << 22) - 1)) << 10) + signed13(word)) & 0xffffffff
        assert target == int(xref['to'], 16)
        target_unit = units.get(target)
        assert target_unit is not None
        if target_unit['kind'] != 'data':
            continue
        target_index = indices[target]
        window = [raw_item(binary, row, text_start, text_offset)
                  for row in unit_rows[max(0, target_index - 2):target_index + 3]]
        results.append({
            'sethi_predecessor_item': predecessor_item,
            'op3_38_source_item': source_item,
            'computed_target': hex(target),
            'target_data_item': raw_item(binary, target_unit, text_start, text_offset),
            'target_item_bounded_window': window,
        })
        target_addresses.add(target)
    assert len(results) == 7 and len(target_addresses) == 6
    output = {
        'schema': 1,
        'architecture': 'sparc',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'sethi_op3_38_data_target_edge_count': len(results),
        'unique_data_target_count': len(target_addresses),
        'all_raw_two_item_calculations_target_data_items_and_windows_match_original_bytes': True,
        'interpretation_limit': ('raw target data items and bounded neighboring item windows do not establish code '
                                 'or data reclassification, transfer execution, delay-slot execution, reachability, '
                                 'function boundaries, calling convention, ABI, or behavior'),
        'rows': results,
    }
    (REPORT / 'sparc-sethi-op3-38-data-target-windows-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'edge_count': len(results), 'unique_data_target_count': len(target_addresses),
                      'all_checks_passed': True}))


if __name__ == '__main__':
    main()
