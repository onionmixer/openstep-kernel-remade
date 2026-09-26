"""Audit raw m68k direct branches to shared targets outside bounded no-exit candidates."""
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
TARGETS = (0x4001826, 0x4001836)


def tsv_rows(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def decode_branch_target(source, raw):
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
    raise AssertionError(f'not a supported m68k direct branch: {word:#x}')


def original_item(binary, unit, text_start, text_file_offset):
    address = int(unit['address'], 16)
    offset = text_file_offset + address - text_start
    raw = binary[offset:offset + int(unit['length'])]
    assert raw.hex() == unit['bytes']
    return {
        'address': unit['address'],
        'kind': unit['kind'],
        'original_bytes': raw.hex(),
        'ida_disassembly': unit['disassembly'],
    }


def candidate_at(candidates, address):
    matches = [row for row in candidates
               if int(row['start'], 16) <= address < int(row['end'], 16)]
    assert len(matches) <= 1
    return matches[0] if matches else None


def main():
    binary = (ROOT / '03_original/m68k/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/m68k/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_file_offset = int(text['file_offset'])
    candidates = tsv_rows(ROOT / '05_ida/exports/m68k/function-candidate-lexical-exits.tsv')
    units_list = tsv_rows(ROOT / '05_ida/exports/m68k/text-units.tsv')
    units = {int(row['address'], 16): row for row in units_list}
    unit_index = {int(row['address'], 16): index for index, row in enumerate(units_list)}
    xrefs = tsv_rows(ROOT / '05_ida/exports/m68k/xrefs.tsv')
    target_rows = []
    total_branches = 0
    for target in TARGETS:
        target_unit = units[target]
        target_index = unit_index[target]
        target_window = [original_item(binary, unit, text_start, text_file_offset)
                         for unit in units_list[target_index:target_index + 3]]
        assert all(item['kind'] == 'code' for item in target_window)
        inbound = [xref for xref in xrefs
                   if xref['type'] == '19' and int(xref['to'], 16) == target]
        branches = []
        source_candidate_counts = Counter()
        source_exit_class_counts = Counter()
        for xref in inbound:
            source = int(xref['from'], 16)
            source_item = original_item(binary, units[source], text_start, text_file_offset)
            computed, displacement, form = decode_branch_target(
                source, bytes.fromhex(source_item['original_bytes']))
            assert computed == target
            candidate = candidate_at(candidates, source)
            assert candidate is not None
            candidate_key = f"{candidate['name']}@{candidate['start']}"
            source_candidate_counts[candidate_key] += 1
            exit_class = ('with_lexical_exit' if int(candidate['lexical_exit_count']) > 0
                          else 'without_lexical_exit')
            source_exit_class_counts[exit_class] += 1
            branches.append({
                'source': hex(source),
                'source_item': source_item,
                'signed_big_endian_displacement': displacement,
                'encoding_form': form,
                'source_candidate': {
                    'name': candidate['name'],
                    'start': candidate['start'],
                    'end': candidate['end'],
                    'lexical_exit_count': candidate['lexical_exit_count'],
                },
            })
        total_branches += len(branches)
        target_rows.append({
            'target': hex(target),
            'target_has_function_candidate': candidate_at(candidates, target) is not None,
            'target_item_and_two_following_items': target_window,
            'inbound_type19_direct_branch_count': len(branches),
            'source_candidate_counts': dict(sorted(source_candidate_counts.items())),
            'source_lexical_exit_class_counts': dict(sorted(source_exit_class_counts.items())),
            'branches': branches,
        })
    assert [row['inbound_type19_direct_branch_count'] for row in target_rows] == [5, 16]
    assert total_branches == 21
    output = {
        'schema': 1,
        'architecture': 'm68k',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'shared_external_targets_from_prior_noexit_branch_audit': [hex(target) for target in TARGETS],
        'target_count': len(target_rows),
        'inbound_type19_direct_branch_count': total_branches,
        'all_branch_targets_match_raw_big_endian_displacements_type19_xrefs_and_original_items': True,
        'rows': target_rows,
        'interpretation_limit': ('shared direct-branch targets, raw item windows, and candidate membership do not '
                                 'establish branch conditions, fallthrough, execution, return behavior, path '
                                 'reachability, function boundaries, calling convention, ABI, or behavior'),
    }
    (REPORT / 'm68k-shared-external-branch-targets-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'target_count': len(target_rows), 'direct_branch_count': total_branches,
                      'all_checks_passed': True}))


if __name__ == '__main__':
    main()
