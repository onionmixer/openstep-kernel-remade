"""Independently validate all-range IDA item exports against original Mach-O bytes."""
import csv
import hashlib
import json
import struct
from collections import Counter, defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
EXPECTED = {
    'm68k': 'dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75',
    'sparc': '287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1',
}


def parse_segments(raw):
    _, _, _, _, command_count, command_bytes, _ = struct.unpack_from('>IiiIIII', raw, 0)
    offset = 28
    command_end = offset + command_bytes
    segments = []
    for _ in range(command_count):
        command, size = struct.unpack_from('>II', raw, offset)
        assert size >= 8 and size % 4 == 0 and offset + size <= command_end
        if command == 1:
            values = struct.unpack_from('>16sIIIIiiII', raw, offset + 8)
            name, address, virtual_size, file_offset, file_size = values[:5]
            segments.append({
                'name': name.split(b'\0', 1)[0].decode('ascii'), 'address': address,
                'size': virtual_size, 'file_offset': file_offset, 'file_size': file_size,
            })
        offset += size
    assert offset == command_end
    return segments


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as stream:
        return list(csv.DictReader(stream, delimiter='\t'))


def expected_ranges(segments):
    result = {}
    excluded = []
    for segment in segments:
        if segment['file_size'] == 0:
            assert segment['name'] == '__PAGEZERO' and segment['address'] == 0
            excluded.append(segment['name'])
            continue
        if segment['file_size']:
            result[(segment['name'], 'file_backed')] = {
                'address_start': segment['address'],
                'address_end': segment['address'] + segment['file_size'],
                'file_offset_start': segment['file_offset'],
            }
        if segment['size'] > segment['file_size']:
            result[(segment['name'], 'zero_fill')] = {
                'address_start': segment['address'] + segment['file_size'],
                'address_end': segment['address'] + segment['size'],
                'file_offset_start': None,
            }
    return result, excluded


def validate_architecture(architecture):
    binary = (ROOT / '03_original' / architecture / 'binaries/mach_kernel').read_bytes()
    assert hashlib.sha256(binary).hexdigest() == EXPECTED[architecture]
    rows = read_tsv(ROOT / '05_ida/exports' / architecture / 'load-units.tsv')
    summary = json.loads((ROOT / '05_ida/exports' / architecture / 'load-units-summary.json').read_text())
    assert summary['architecture'] == architecture
    assert summary['input_sha256'] == EXPECTED[architecture]
    groups = defaultdict(list)
    for row in rows:
        assert set(row) == {'segment', 'source_kind', 'address', 'file_offset', 'length', 'kind',
                            'original_bytes', 'ida_bytes', 'disassembly'}
        assert row['source_kind'] in {'file_backed', 'zero_fill'}
        assert row['kind'] in {'code', 'data', 'unknown'}
        assert len(bytes.fromhex(row['ida_bytes'])) == int(row['length'])
        groups[(row['segment'], row['source_kind'])].append(row)
    ranges, excluded = expected_ranges(parse_segments(binary))
    assert set(groups) == set(ranges)
    range_results = []
    for key, expected in sorted(ranges.items()):
        group = groups[key]
        address = expected['address_start']
        category_bytes = Counter()
        matching_items = matching_bytes = differing_items = differing_bytes = 0
        first_difference = None
        for row in group:
            length = int(row['length'])
            assert int(row['address'], 16) == address
            category_bytes[row['kind']] += length
            if key[1] == 'file_backed':
                file_offset = expected['file_offset_start'] + address - expected['address_start']
                assert int(row['file_offset']) == file_offset
                original = binary[file_offset:file_offset + length]
                assert row['original_bytes'] == original.hex()
                ida_value = bytes.fromhex(row['ida_bytes'])
                if original == ida_value:
                    matching_items += 1
                    matching_bytes += length
                else:
                    difference = sum(left != right for left, right in zip(original, ida_value))
                    differing_items += 1
                    differing_bytes += difference
                    if first_difference is None:
                        first_difference = {'address': row['address'], 'file_offset': file_offset,
                                            'original_bytes': row['original_bytes'],
                                            'ida_bytes': row['ida_bytes'],
                                            'differing_byte_count': difference}
            else:
                assert row['file_offset'] == ''
                assert row['original_bytes'] == ''
            address += length
        assert address == expected['address_end']
        result = {
            'segment': key[0], 'source_kind': key[1],
            'address_start': hex(expected['address_start']), 'address_end': hex(expected['address_end']),
            'item_count': len(group), 'byte_count': address - expected['address_start'],
            'category_byte_counts': {kind: category_bytes[kind]
                                     for kind in ('code', 'data', 'unknown')},
            'continuous_address_coverage': True,
            'all_ida_value_lengths_match_item_lengths': True,
        }
        if key[1] == 'file_backed':
            result['file_offset_start'] = expected['file_offset_start']
            result['all_original_bytes_match_raw_binary'] = True
            result['original_to_ida_byte_comparison'] = {
                'matching_item_count': matching_items, 'matching_byte_count': matching_bytes,
                'differing_item_count': differing_items, 'differing_byte_count': differing_bytes,
                'first_difference': first_difference,
            }
        else:
            result['file_offset_start'] = None
            result['original_byte_comparison'] = 'not_applicable_no_file_bytes'
        range_results.append(result)
    summary_ranges = {
        (segment['name'], entry['source_kind']): entry
        for segment in summary['segments'] for entry in segment['ranges']
    }
    assert set(summary_ranges) == set(ranges)
    for result in range_results:
        exported = summary_ranges[(result['segment'], result['source_kind'])]
        assert exported['byte_count'] == result['byte_count']
        assert exported['item_count'] == result['item_count']
        assert exported['category_byte_counts'] == result['category_byte_counts']
        if result['source_kind'] == 'file_backed':
            assert exported['original_to_ida_byte_comparison'] == result['original_to_ida_byte_comparison']
    assert summary['item_count'] == len(rows)
    return {
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'item_count': len(rows), 'pagezero_excluded_segments': excluded,
        'ranges': range_results,
        'all_expected_non_pagezero_load_ranges_exported': True,
        'all_file_backed_original_bytes_match_raw_binary': True,
        'all_ranges_have_continuous_address_coverage': True,
        'all_ida_value_lengths_match_item_lengths': True,
        'summary_matches_tsv_recomputation': True,
    }


def main():
    targets = {architecture: validate_architecture(architecture) for architecture in EXPECTED}
    output = {
        'schema': 1, 'targets': targets,
        'interpretation_limit': (
            'This verifies raw Mach-O file-byte mapping and IDA item-range coverage only. IDA code/data/'
            'unknown labels remain tool hypotheses. Where recorded IDA values differ from original file bytes, '
            'the original_bytes field is the binary evidence; the difference does not establish relocation, '
            'runtime memory, pointer meaning, execution, function boundaries, ABI, or behavior. Zero-fill '
            'ranges have no original file bytes and are therefore not byte-compared.'),
    }
    (REPORT / 'all-load-units-validation.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({architecture: target['item_count'] for architecture, target in targets.items()},
                     sort_keys=True))


if __name__ == '__main__':
    main()
