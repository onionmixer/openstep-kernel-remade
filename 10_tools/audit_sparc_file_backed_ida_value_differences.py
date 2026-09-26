"""Audit SPARC file-backed load-item values that differ from original bytes."""
import csv
import hashlib
import json
import struct
from collections import Counter, defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
EXPECTED_SHA256 = '287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1'


def parse_segments(raw):
    _, _, _, _, command_count, command_bytes, _ = struct.unpack_from('>IiiIIII', raw, 0)
    offset = 28
    command_end = offset + command_bytes
    result = {}
    for _ in range(command_count):
        command, size = struct.unpack_from('>II', raw, offset)
        assert size >= 8 and size % 4 == 0 and offset + size <= command_end
        if command == 1:
            fields = struct.unpack_from('>16sIIIIiiII', raw, offset + 8)
            name, address, virtual_size, file_offset, file_size = fields[:5]
            result[name.split(b'\0', 1)[0].decode('ascii')] = {
                'address': address, 'size': virtual_size,
                'file_offset': file_offset, 'file_size': file_size,
            }
        offset += size
    assert offset == command_end
    return result


def raw_window(raw, offset, length=16):
    return raw[offset:offset + length].hex()


def main():
    binary = (ROOT / '03_original/sparc/binaries/mach_kernel').read_bytes()
    assert hashlib.sha256(binary).hexdigest() == EXPECTED_SHA256
    segments = parse_segments(binary)
    with (ROOT / '05_ida/exports/sparc/load-units.tsv').open(encoding='utf-8', newline='') as stream:
        rows = list(csv.DictReader(stream, delimiter='\t'))
    mismatch_bytes = []
    item_counts = Counter()
    byte_counts = Counter()
    kind_byte_counts = Counter()
    pairs = Counter()
    ida_value_counts = Counter()
    for row in rows:
        if row['source_kind'] != 'file_backed':
            continue
        address = int(row['address'], 16)
        length = int(row['length'])
        file_offset = int(row['file_offset'])
        original = bytes.fromhex(row['original_bytes'])
        ida_value = bytes.fromhex(row['ida_bytes'])
        segment = segments[row['segment']]
        assert len(original) == len(ida_value) == length
        assert segment['address'] <= address < segment['address'] + segment['file_size']
        assert file_offset == segment['file_offset'] + address - segment['address']
        assert original == binary[file_offset:file_offset + length]
        differences = [(index, source_byte, ida_byte)
                       for index, (source_byte, ida_byte) in enumerate(zip(original, ida_value))
                       if source_byte != ida_byte]
        if not differences:
            continue
        item_counts[row['segment']] += 1
        for index, source_byte, ida_byte in differences:
            mismatch_bytes.append({
                'segment': row['segment'], 'address': address + index,
                'file_offset': file_offset + index,
                'original_byte': source_byte, 'ida_byte': ida_byte,
                'item_kind': row['kind'],
            })
            byte_counts[row['segment']] += 1
            kind_byte_counts[(row['segment'], row['kind'])] += 1
            pairs[(row['segment'], source_byte, ida_byte)] += 1
            ida_value_counts['%02x' % ida_byte] += 1
    mismatch_bytes.sort(key=lambda record: record['address'])
    runs = []
    for record in mismatch_bytes:
        if not runs or record['segment'] != runs[-1]['segment'] or record['address'] != runs[-1]['address_end']:
            runs.append({
                'segment': record['segment'], 'address_start': record['address'],
                'address_end': record['address'] + 1, 'file_offset_start': record['file_offset'],
                'file_offset_end': record['file_offset'] + 1, 'differing_byte_count': 1,
            })
        else:
            runs[-1]['address_end'] += 1
            runs[-1]['file_offset_end'] += 1
            runs[-1]['differing_byte_count'] += 1
    run_rows = []
    for run in runs:
        start = run['file_offset_start']
        end = run['file_offset_end']
        run_rows.append({
            'segment': run['segment'], 'address_start': hex(run['address_start']),
            'address_end': hex(run['address_end']), 'file_offset_start': start,
            'file_offset_end': end, 'differing_byte_count': run['differing_byte_count'],
            'original_first_16_bytes': raw_window(binary, start),
            'original_last_16_bytes': raw_window(binary, max(start, end - 16)),
        })
    expected_counts = {'__DATA': 3592, '__OBJC': 1091, '__LINKEDIT': 122696}
    assert dict(byte_counts) == expected_counts
    output = {
        'schema': 1, 'architecture': 'sparc',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'differing_item_counts_by_segment': dict(sorted(item_counts.items())),
        'differing_byte_counts_by_segment': dict(sorted(byte_counts.items())),
        'differing_byte_counts_by_segment_and_ida_item_kind': {
            '%s:%s' % key: value for key, value in sorted(kind_byte_counts.items())},
        'differing_ida_byte_value_counts': dict(sorted(ida_value_counts.items())),
        'original_to_ida_differing_byte_pair_counts': {
            '%s:%02x->%02x' % key: value for key, value in sorted(pairs.items())},
        'contiguous_differing_byte_runs': run_rows,
        'all_file_backed_row_original_bytes_match_raw_binary': True,
        'interpretation_limit': (
            'This records only that exported IDA database values differ from file-backed original bytes at '
            'these ranges. It does not identify a cause, and does not establish relocation, loader behavior, '
            'runtime memory, pointer meaning, code/data truth, execution, function boundaries, ABI, or behavior.'),
    }
    (REPORT / 'sparc-file-backed-ida-value-differences-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({'differing_byte_counts_by_segment': dict(byte_counts),
                      'differing_ida_byte_value_counts': dict(ida_value_counts),
                      'run_count': len(run_rows), 'all_checks_passed': True}, sort_keys=True))


if __name__ == '__main__':
    main()
