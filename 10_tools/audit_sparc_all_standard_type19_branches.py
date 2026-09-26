"""Verify every SPARC standard op=0/op2=2 type-19 branch from original bytes."""
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


def signed22(word):
    value = word & ((1 << 22) - 1)
    return value - (1 << 22) if value & (1 << 21) else value


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
    xrefs = rows(ROOT / '05_ida/exports/sparc/xrefs.tsv')
    mnemonic_counts = Counter()
    member_counts = Counter()
    target_kind_counts = Counter()
    delay_kind_counts = Counter()
    post_kind_counts = Counter()
    exceptions = []
    count = 0
    for xref in xrefs:
        source = int(xref['from'], 16)
        if xref['type'] != '19' or source not in units:
            continue
        source_item = raw_item(binary, units[source], text_start, text_offset)
        assert source_item['kind'] == 'code'
        word = int.from_bytes(bytes.fromhex(source_item['original_bytes']), 'big')
        if word >> 30 != 0 or ((word >> 22) & 0x7) != 2:
            continue
        displacement = signed22(word)
        target = (source + (displacement << 2)) & 0xffffffff
        assert target == int(xref['to'], 16)
        target_unit = units.get(target)
        assert target_unit is not None and target_unit['kind'] == 'code'
        target_item = raw_item(binary, target_unit, text_start, text_offset)
        delay_unit = units.get(source + 4)
        assert delay_unit is not None
        delay_item = raw_item(binary, delay_unit, text_start, text_offset)
        post_unit = units.get(source + 8)
        post_item = None if post_unit is None else raw_item(binary, post_unit, text_start, text_offset)
        mnemonic_counts[source_item['ida_disassembly'].split(None, 1)[0]] += 1
        member_counts[membership(source, starts, ranges)] += 1
        target_kind_counts[target_item['kind']] += 1
        delay_kind_counts[delay_item['kind']] += 1
        post_kind_counts['no_text_item' if post_item is None else post_item['kind']] += 1
        if delay_item['kind'] != 'code' or post_item is None or post_item['kind'] != 'code':
            exceptions.append({'source_item': source_item, 'signed_big_endian_disp22': displacement,
                               'target_item': target_item, 'delay_slot_item': delay_item,
                               'post_delay_item': post_item})
        count += 1
    assert count == 31743
    assert len(exceptions) == 43
    output = {
        'schema': 1,
        'architecture': 'sparc',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'standard_op0_op2_2_type19_branch_count': count,
        'ida_mnemonic_counts_as_tool_observations': dict(sorted(mnemonic_counts.items())),
        'source_candidate_membership_counts': dict(sorted(member_counts.items())),
        'target_item_kind_counts': dict(sorted(target_kind_counts.items())),
        'delay_slot_item_kind_counts': dict(sorted(delay_kind_counts.items())),
        'post_delay_item_kind_counts': dict(sorted(post_kind_counts.items())),
        'exception_count': len(exceptions),
        'all_computed_targets_match_raw_big_endian_disp22_type19_xrefs_and_original_items': True,
        'interpretation_limit': ('direct branch encodings, target items, and delay/post-delay item classifications '
                                 'do not establish branch conditions, delay-slot execution, fallthrough, path '
                                 'reachability, function boundaries, calling convention, ABI, or behavior'),
        'exceptions': exceptions,
    }
    (REPORT / 'sparc-all-standard-type19-branches-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'standard_op0_op2_2_type19_branch_count': count,
                      'exception_count': len(exceptions), 'all_checks_passed': True}))


if __name__ == '__main__':
    main()
