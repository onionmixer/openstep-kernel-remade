"""Verify direct SPARC branch xrefs sourced in function-candidate gaps."""
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


def signed(value, bits):
    return value - (1 << bits) if value & (1 << (bits - 1)) else value


def raw_item(binary, unit, text_start, text_offset):
    address = int(unit['address'], 16)
    file_offset = text_offset + address - text_start
    raw = binary[file_offset:file_offset + int(unit['length'])]
    assert raw.hex() == unit['bytes']
    return {
        'address': unit['address'],
        'kind': unit['kind'],
        'original_bytes': raw.hex(),
        'ida_disassembly': unit['disassembly'],
    }


def candidate_at(address, starts, ranges):
    index = bisect.bisect_right(starts, address) - 1
    if index >= 0 and address < ranges[index]['end']:
        return ranges[index]
    return None


def source_gap(address, text_start, text_end, starts, ranges):
    index = bisect.bisect_right(starts, address) - 1
    assert candidate_at(address, starts, ranges) is None
    lower = ranges[index]['end'] if index >= 0 else text_start
    upper = starts[index + 1] if index + 1 < len(starts) else text_end
    assert lower <= address < upper
    return {'start': hex(lower), 'end': hex(upper)}


def main():
    binary = (ROOT / '03_original/sparc/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/sparc/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_end = text_start + int(text['size'])
    text_offset = int(text['file_offset'])
    candidate_rows = tsv_rows(ROOT / '05_ida/exports/sparc/function-candidate-lexical-exits.tsv')
    ranges = sorted(
        ({'start': int(row['start'], 16), 'end': int(row['end'], 16),
          'name': row['name'], 'lexical_exit_count': row['lexical_exit_count']}
         for row in candidate_rows),
        key=lambda row: row['start'])
    assert all(left['end'] <= right['start'] for left, right in zip(ranges, ranges[1:]))
    starts = [row['start'] for row in ranges]
    units_list = tsv_rows(ROOT / '05_ida/exports/sparc/text-units.tsv')
    units = {int(row['address'], 16): row for row in units_list}
    xrefs = tsv_rows(ROOT / '05_ida/exports/sparc/xrefs.tsv')
    rows = []
    source_gap_counts = Counter()
    target_relation_counts = Counter()
    mnemonic_counts = Counter()
    delay_kind_counts = Counter()
    post_delay_kind_counts = Counter()
    selected = [xref for xref in xrefs if xref['type'] == '19'
                and int(xref['from'], 16) in units
                and candidate_at(int(xref['from'], 16), starts, ranges) is None]
    for xref in selected:
        source = int(xref['from'], 16)
        target = int(xref['to'], 16)
        source_unit = units[source]
        source_item = raw_item(binary, source_unit, text_start, text_offset)
        raw = bytes.fromhex(source_item['original_bytes'])
        assert source_item['kind'] == 'code'
        assert len(raw) == 4
        word = int.from_bytes(raw, 'big')
        assert word >> 30 == 0 and ((word >> 22) & 0x7) == 2
        displacement = signed(word & ((1 << 22) - 1), 22)
        computed_target = (source + (displacement << 2)) & 0xffffffff
        assert computed_target == target
        assert target in units
        target_item = raw_item(binary, units[target], text_start, text_offset)
        assert target_item['kind'] == 'code'
        delay_unit = units.get(source + 4)
        assert delay_unit is not None
        delay_item = raw_item(binary, delay_unit, text_start, text_offset)
        assert delay_item['kind'] == 'code'
        post_delay_unit = units.get(source + 8)
        post_delay_kind = post_delay_unit['kind'] if post_delay_unit is not None else 'no_text_item'
        delay_kind_counts[delay_item['kind']] += 1
        post_delay_kind_counts[post_delay_kind] += 1
        gap = source_gap(source, text_start, text_end, starts, ranges)
        gap_key = f"{gap['start']}..{gap['end']}"
        source_gap_counts[gap_key] += 1
        target_candidate = candidate_at(target, starts, ranges)
        target_relation = 'candidate' if target_candidate is not None else 'candidate_gap'
        target_relation_counts[target_relation] += 1
        mnemonic = source_item['ida_disassembly'].split(None, 1)[0]
        mnemonic_counts[mnemonic] += 1
        rows.append({
            'source': hex(source),
            'source_gap': gap,
            'source_item': source_item,
            'signed_big_endian_disp22': displacement,
            'delay_slot_item': delay_item,
            'post_delay_item_kind': post_delay_kind,
            'target': hex(target),
            'target_item': target_item,
            'target_relation': target_relation,
            'target_candidate': None if target_candidate is None else {
                'name': target_candidate['name'],
                'start': hex(target_candidate['start']),
                'end': hex(target_candidate['end']),
                'lexical_exit_count': target_candidate['lexical_exit_count'],
            },
        })
    assert len(rows) == 232
    output = {
        'schema': 1,
        'architecture': 'sparc',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'direct_branch_source_count_in_candidate_gaps': len(rows),
        'source_gap_count': len(source_gap_counts),
        'source_gap_branch_counts': dict(sorted(source_gap_counts.items())),
        'branch_mnemonic_counts': dict(sorted(mnemonic_counts.items())),
        'target_relation_counts': dict(sorted(target_relation_counts.items())),
        'delay_slot_item_kind_counts': dict(sorted(delay_kind_counts.items())),
        'post_delay_item_kind_counts': dict(sorted(post_delay_kind_counts.items())),
        'all_direct_branch_targets_match_raw_big_endian_disp22_type19_xrefs_and_original_items': True,
        'rows': rows,
        'interpretation_limit': ('candidate-gap direct branch edges, delay-slot items, and target candidate '
                                 'membership do not establish gap code ownership, branch conditions, delay-slot '
                                 'execution, fallthrough, path reachability, function boundaries, calling '
                                 'convention, ABI, or behavior'),
    }
    (REPORT / 'sparc-candidate-gap-direct-branches-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'direct_branch_source_count_in_candidate_gaps': len(rows),
                      'source_gap_count': len(source_gap_counts), 'all_checks_passed': True}))


if __name__ == '__main__':
    main()
