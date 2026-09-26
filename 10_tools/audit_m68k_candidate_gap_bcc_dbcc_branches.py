"""Verify m68k Bcc/DBcc type-19 xrefs sourced in function-candidate gaps."""
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


def decode_bcc_dbcc(source, raw):
    word = int.from_bytes(raw[:2], 'big')
    if word & 0xf000 == 0x6000:
        low_byte = word & 0xff
        if low_byte == 0:
            displacement = int.from_bytes(raw[2:4], 'big', signed=True)
            form = 'bcc_word_displacement'
        elif low_byte == 0xff:
            displacement = int.from_bytes(raw[2:6], 'big', signed=True)
            form = 'bcc_long_displacement'
        else:
            displacement = int.from_bytes(raw[1:2], 'big', signed=True)
            form = 'bcc_byte_displacement'
        return (source + 2 + displacement) & 0xffffffff, displacement, form
    if word & 0xf0f8 == 0x50c8:
        displacement = int.from_bytes(raw[2:4], 'big', signed=True)
        return (source + 2 + displacement) & 0xffffffff, displacement, 'dbcc_word_displacement'
    raise AssertionError(f'not Bcc/DBcc: {word:#x}')


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


def gap_at(address, text_start, text_end, starts, ranges):
    index = bisect.bisect_right(starts, address) - 1
    assert candidate_at(address, starts, ranges) is None
    lower = ranges[index]['end'] if index >= 0 else text_start
    upper = starts[index + 1] if index + 1 < len(starts) else text_end
    assert lower <= address < upper
    return {'start': hex(lower), 'end': hex(upper)}


def target_mapping(binary, target, units, text_start, text_end, text_offset):
    unit = units.get(target)
    if unit is not None:
        return {'mapping_kind': 'text_item_start',
                'item': raw_item(binary, unit, text_start, text_offset)}
    assert text_start <= target < text_end
    raw = binary[text_offset + target - text_start:text_offset + target - text_start + 4]
    assert len(raw) == 4
    return {'mapping_kind': 'mapped_text_without_item_start',
            'address': hex(target), 'original_four_bytes': raw.hex()}


def main():
    binary = (ROOT / '03_original/m68k/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/m68k/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_end = text_start + int(text['size'])
    text_offset = int(text['file_offset'])
    candidates = tsv_rows(ROOT / '05_ida/exports/m68k/function-candidate-lexical-exits.tsv')
    ranges = sorted(({'start': int(row['start'], 16), 'end': int(row['end'], 16),
                      'name': row['name'], 'lexical_exit_count': row['lexical_exit_count']}
                     for row in candidates), key=lambda row: row['start'])
    assert all(left['end'] <= right['start'] for left, right in zip(ranges, ranges[1:]))
    starts = [row['start'] for row in ranges]
    units_list = tsv_rows(ROOT / '05_ida/exports/m68k/text-units.tsv')
    units = {int(row['address'], 16): row for row in units_list}
    xrefs = tsv_rows(ROOT / '05_ida/exports/m68k/xrefs.tsv')
    selected = []
    for xref in xrefs:
        source = int(xref['from'], 16)
        if xref['type'] != '19' or source not in units:
            continue
        if candidate_at(source, starts, ranges) is not None:
            continue
        raw = bytes.fromhex(units[source]['bytes'])
        word = int.from_bytes(raw[:2], 'big')
        if word & 0xf000 == 0x6000 or word & 0xf0f8 == 0x50c8:
            selected.append(xref)
    rows = []
    source_gap_counts = Counter()
    target_relation_counts = Counter()
    target_mapping_counts = Counter()
    immediate_next_kind_counts = Counter()
    mnemonic_counts = Counter()
    encoding_form_counts = Counter()
    for xref in selected:
        source = int(xref['from'], 16)
        target = int(xref['to'], 16)
        source_item = raw_item(binary, units[source], text_start, text_offset)
        assert source_item['kind'] == 'code'
        computed, displacement, form = decode_bcc_dbcc(source, bytes.fromhex(source_item['original_bytes']))
        assert computed == target
        mapping = target_mapping(binary, target, units, text_start, text_end, text_offset)
        target_mapping_counts[mapping['mapping_kind']] += 1
        next_unit = units.get(source + len(bytes.fromhex(source_item['original_bytes'])))
        assert next_unit is not None
        next_item = raw_item(binary, next_unit, text_start, text_offset)
        immediate_next_kind_counts[next_item['kind']] += 1
        gap = gap_at(source, text_start, text_end, starts, ranges)
        source_gap_counts[f"{gap['start']}..{gap['end']}"] += 1
        target_candidate = candidate_at(target, starts, ranges)
        relation = 'candidate' if target_candidate is not None else 'candidate_gap'
        target_relation_counts[relation] += 1
        mnemonic = source_item['ida_disassembly'].split(None, 1)[0]
        mnemonic_counts[mnemonic] += 1
        encoding_form_counts[form] += 1
        rows.append({
            'source': hex(source),
            'source_gap': gap,
            'source_item': source_item,
            'signed_big_endian_displacement': displacement,
            'encoding_form': form,
            'immediate_next_item': next_item,
            'target': hex(target),
            'target_mapping': mapping,
            'target_relation': relation,
            'target_candidate': None if target_candidate is None else {
                'name': target_candidate['name'], 'start': hex(target_candidate['start']),
                'end': hex(target_candidate['end']),
                'lexical_exit_count': target_candidate['lexical_exit_count'],
            },
        })
    assert len(rows) == 2429
    output = {
        'schema': 1,
        'architecture': 'm68k',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'direct_bcc_dbcc_source_count_in_candidate_gaps': len(rows),
        'remaining_non_bcc_dbcc_type19_source_count_in_candidate_gaps': 20,
        'remaining_non_bcc_dbcc_encoding_counts': {'fpu_branch_family': 18, 'absolute_long_jmp': 2},
        'source_gap_count': len(source_gap_counts),
        'source_gap_branch_counts': dict(sorted(source_gap_counts.items())),
        'branch_mnemonic_counts': dict(sorted(mnemonic_counts.items())),
        'encoding_form_counts': dict(sorted(encoding_form_counts.items())),
        'target_relation_counts': dict(sorted(target_relation_counts.items())),
        'target_mapping_counts': dict(sorted(target_mapping_counts.items())),
        'immediate_next_item_kind_counts': dict(sorted(immediate_next_kind_counts.items())),
        'all_computed_targets_match_raw_big_endian_displacements_type19_xrefs_and_original_mappings': True,
        'rows': rows,
        'interpretation_limit': ('candidate-gap Bcc/DBcc edges, next items, and target candidate membership do not '
                                 'establish gap code ownership, branch conditions, fallthrough, path reachability, '
                                 'function boundaries, calling convention, ABI, or behavior'),
    }
    (REPORT / 'm68k-candidate-gap-bcc-dbcc-branches-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'direct_bcc_dbcc_source_count_in_candidate_gaps': len(rows),
                      'source_gap_count': len(source_gap_counts), 'all_checks_passed': True}))


if __name__ == '__main__':
    main()
