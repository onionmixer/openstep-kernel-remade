"""Verify raw two-item SETHI + op3=0x38 target construction for type-3 xrefs."""
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


def raw_item(binary, unit, text_start, text_offset):
    address = int(unit['address'], 16)
    raw = binary[text_offset + address - text_start:
                 text_offset + address - text_start + int(unit['length'])]
    assert raw.hex() == unit['bytes']
    return {'address': unit['address'], 'kind': unit['kind'],
            'original_bytes': raw.hex(), 'ida_disassembly': unit['disassembly']}


def membership(address, starts, ranges):
    index = bisect.bisect_right(starts, address) - 1
    return 'candidate' if index >= 0 and address < ranges[index][1] else 'candidate_gap'


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
    candidates = rows(ROOT / '05_ida/exports/sparc/function-candidate-lexical-exits.tsv')
    ranges = sorted((int(row['start'], 16), int(row['end'], 16)) for row in candidates)
    starts = [start for start, _ in ranges]
    units = {int(row['address'], 16): row for row in rows(ROOT / '05_ida/exports/sparc/text-units.tsv')}
    results = []
    source_membership_counts = Counter()
    target_membership_counts = Counter()
    target_kind_counts = Counter()
    delay_kind_counts = Counter()
    for xref in rows(ROOT / '05_ida/exports/sparc/xrefs.tsv'):
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
        assert (word >> 13) & 1 == 1
        assert ((predecessor_word >> 25) & 0x1f) == ((word >> 14) & 0x1f)
        high_field = predecessor_word & ((1 << 22) - 1)
        low_field = signed13(word)
        target = ((high_field << 10) + low_field) & 0xffffffff
        assert target == int(xref['to'], 16)
        target_unit = units.get(target)
        assert target_unit is not None
        target_item = raw_item(binary, target_unit, text_start, text_offset)
        delay_unit = units.get(source + 4)
        assert delay_unit is not None
        delay_item = raw_item(binary, delay_unit, text_start, text_offset)
        source_membership_counts[membership(source, starts, ranges)] += 1
        target_membership_counts[membership(target, starts, ranges)] += 1
        target_kind_counts[target_item['kind']] += 1
        delay_kind_counts[delay_item['kind']] += 1
        results.append({
            'sethi_predecessor_item': predecessor_item,
            'op3_38_source_item': source_item,
            'sethi_high_22_field': high_field,
            'op3_38_signed_low_13_field': low_field,
            'computed_target': hex(target),
            'target_item': target_item,
            'delay_slot_item': delay_item,
        })
    assert len(results) == 259
    output = {
        'schema': 1,
        'architecture': 'sparc',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'sethi_op3_38_type3_edge_count': len(results),
        'source_candidate_membership_counts': dict(sorted(source_membership_counts.items())),
        'target_candidate_membership_counts': dict(sorted(target_membership_counts.items())),
        'target_item_kind_counts': dict(sorted(target_kind_counts.items())),
        'delay_slot_item_kind_counts': dict(sorted(delay_kind_counts.items())),
        'all_computed_targets_match_raw_big_endian_two_item_fields_type3_xrefs_and_original_items': True,
        'interpretation_limit': ('the two-item raw address construction and target item do not establish transfer '
                                 'execution, delay-slot execution, path reachability, function boundaries, calling '
                                 'convention, ABI, or behavior'),
        'rows': results,
    }
    (REPORT / 'sparc-sethi-op3-38-type3-targets-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'sethi_op3_38_type3_edge_count': len(results),
                      'all_checks_passed': True}))


if __name__ == '__main__':
    main()
