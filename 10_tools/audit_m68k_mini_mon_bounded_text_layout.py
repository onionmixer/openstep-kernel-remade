"""Preserve the original text-item layout through _mini_mon's first lexical RTS."""
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
START = 0x4093976
END = 0x4093E4A


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def main():
    binary = (ROOT / '03_original/m68k/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/m68k/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_offset = int(text['file_offset'])
    units = read_tsv(ROOT / '05_ida/exports/m68k/text-units.tsv')
    selected = [unit for unit in units if START <= int(unit['address'], 16) < END]
    assert int(selected[0]['address'], 16) == START
    assert int(selected[-1]['address'], 16) + int(selected[-1]['length']) == END
    assert all(int(left['address'], 16) + int(left['length']) == int(right['address'], 16)
               for left, right in zip(selected, selected[1:]))
    items = []
    for unit in selected:
        address = int(unit['address'], 16)
        position = text_offset + address - text_start
        original = binary[position:position + int(unit['length'])]
        assert original.hex() == unit['bytes']
        items.append({
            'address': unit['address'],
            'kind': unit['kind'],
            'original_bytes': original.hex(),
            'ida_disassembly': unit['disassembly'],
        })
    xrefs = read_tsv(ROOT / '05_ida/exports/m68k/xrefs.tsv')
    controls = [xref for xref in xrefs if xref['type'] in {'17', '19'}]
    incoming = [xref for xref in controls if START <= int(xref['to'], 16) < END]
    outgoing = [xref for xref in controls if START <= int(xref['from'], 16) < END]
    data_items = [item for item in items if item['kind'] == 'data']
    assert len(items) == 347
    assert Counter(item['kind'] for item in items) == Counter({'code': 346, 'data': 1})
    assert items[-2]['original_bytes'] == '4e5e'
    assert items[-1]['original_bytes'] == '4e75'
    output = {
        'schema': 1,
        'architecture': 'm68k',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'bounded_range': {'start': hex(START), 'end_exclusive': hex(END)},
        'contiguous_text_item_count': len(items),
        'text_item_kind_counts': dict(Counter(item['kind'] for item in items)),
        'noncode_items': data_items,
        'first_lexical_exit_pair': {
            'unlk': items[-2],
            'rts': items[-1],
        },
        'incoming_control_xref_type_counts': dict(Counter(xref['type'] for xref in incoming)),
        'incoming_control_xref_source_location_counts': {
            'inside_bounded_range': sum(START <= int(xref['from'], 16) < END for xref in incoming),
            'outside_bounded_range': sum(not (START <= int(xref['from'], 16) < END) for xref in incoming),
        },
        'outgoing_control_xref_type_counts': dict(Counter(xref['type'] for xref in outgoing)),
        'outgoing_control_xref_target_location_counts': {
            'inside_bounded_range': sum(START <= int(xref['to'], 16) < END for xref in outgoing),
            'outside_bounded_range': sum(not (START <= int(xref['to'], 16) < END) for xref in outgoing),
        },
        'all_contiguous_text_items_match_original_big_endian_bytes': True,
        'interpretation_limit': ('one IDA data item within this bounded text layout prevents treating it as a '
                                'proven contiguous code/function extent; xref distributions do not establish '
                                'reachability, ownership, ABI, arguments, return values, or behavior'),
    }
    (REPORT / 'm68k-mini-mon-bounded-text-layout-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'contiguous_text_item_count': len(items),
                      'text_item_kind_counts': output['text_item_kind_counts'],
                      'all_checks_passed': True}))


if __name__ == '__main__':
    main()
