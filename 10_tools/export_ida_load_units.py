"""Export all file-backed and zero-fill Mach-O load ranges from a copied IDA DB.

The canonical multiarch databases are never accepted as output targets.  This exporter
is intended for a disposable copy, and only reads IDA items while writing TSV/JSON
evidence outside the database.
"""
import csv
import hashlib
import json
import struct
import traceback
from pathlib import Path

import ida_auto
import ida_bytes
import ida_ida
import ida_lines
import ida_loader
import ida_nalt
import ida_pro


ROOT = Path(__file__).resolve().parents[1]
TARGETS = {
    6: ('m68k', '68K', 'dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75'),
    14: ('sparc', 'sparcb', '287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1'),
}


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def parse_segments(raw):
    _, _, _, _, command_count, command_bytes, _ = struct.unpack_from('>IiiIIII', raw, 0)
    offset = 28
    command_end = offset + command_bytes
    segments = []
    for _ in range(command_count):
        command, size = struct.unpack_from('>II', raw, offset)
        if size < 8 or size % 4 or offset + size > command_end:
            raise RuntimeError('invalid Mach-O load command')
        if command == 1:
            values = struct.unpack_from('>16sIIIIiiII', raw, offset + 8)
            name, address, virtual_size, file_offset, file_size = values[:5]
            decoded_name = name.split(b'\0', 1)[0].decode('ascii')
            if file_offset + file_size > len(raw):
                raise RuntimeError('segment file range exceeds original input')
            segments.append({
                'name': decoded_name,
                'address': address,
                'size': virtual_size,
                'file_offset': file_offset,
                'file_size': file_size,
            })
        offset += size
    if offset != command_end:
        raise RuntimeError('Mach-O command traversal did not end at command boundary')
    return segments


def kind_at(address):
    flags = ida_bytes.get_full_flags(address)
    if ida_bytes.is_code(flags):
        return 'code'
    if ida_bytes.is_data(flags):
        return 'data'
    return 'unknown'


def export_range(raw, segment, source_kind, start, end, file_start):
    rows = []
    counts = {'code': 0, 'data': 0, 'unknown': 0}
    comparison = {
        'matching_item_count': 0, 'matching_byte_count': 0,
        'differing_item_count': 0, 'differing_byte_count': 0,
        'first_difference': None,
    }
    address = start
    while address < end:
        length = ida_bytes.get_item_size(address)
        if length <= 0 or address + length > end:
            raise RuntimeError('IDA item does not fit %s %s range at 0x%x' %
                               (segment['name'], source_kind, address))
        item_bytes = ida_bytes.get_bytes(address, length)
        if item_bytes is None or len(item_bytes) != length:
            raise RuntimeError('unreadable IDA item at 0x%x' % address)
        kind = kind_at(address)
        if source_kind == 'file_backed':
            file_offset = file_start + address - start
            expected = raw[file_offset:file_offset + length]
            original_bytes = expected.hex()
            if expected == item_bytes:
                comparison['matching_item_count'] += 1
                comparison['matching_byte_count'] += length
            else:
                differing_byte_count = sum(left != right for left, right in zip(expected, item_bytes))
                comparison['differing_item_count'] += 1
                comparison['differing_byte_count'] += differing_byte_count
                if comparison['first_difference'] is None:
                    comparison['first_difference'] = {
                        'address': hex(address), 'file_offset': file_offset,
                        'original_bytes': original_bytes, 'ida_bytes': item_bytes.hex(),
                        'differing_byte_count': differing_byte_count,
                    }
        else:
            file_offset = None
            original_bytes = ''
        disassembly = ''
        if kind == 'code':
            disassembly = ida_lines.generate_disasm_line(address, ida_lines.GENDSM_REMOVE_TAGS) or ''
        rows.append({
            'segment': segment['name'],
            'source_kind': source_kind,
            'address': hex(address),
            'file_offset': '' if file_offset is None else str(file_offset),
            'length': str(length),
            'kind': kind,
            'original_bytes': original_bytes,
            'ida_bytes': item_bytes.hex(),
            'disassembly': disassembly,
        })
        counts[kind] += length
        address += length
    if address != end:
        raise RuntimeError('range traversal did not end at required boundary')
    return rows, counts, comparison


def main():
    input_path = Path(ida_nalt.get_input_file_path())
    raw = input_path.read_bytes()
    if raw[:4] != b'\xfe\xed\xfa\xce':
        raise RuntimeError('expected big-endian thin 32-bit Mach-O')
    cpu_type = struct.unpack_from('>i', raw, 4)[0]
    target = TARGETS.get(cpu_type)
    if target is None:
        raise RuntimeError('unexpected CPU type')
    architecture, processor, expected_sha256 = target
    if sha256(raw) != expected_sha256:
        raise RuntimeError('input hash differs from preserved target')
    database_path = Path(ida_loader.get_path(ida_loader.PATH_TYPE_IDB))
    if database_path.name in ('m68k-os42j.i64', 'sparc-os42j.i64'):
        raise RuntimeError('refusing to use canonical database; provide a copied working DB')
    if not database_path.name.endswith('-load-units-export.i64'):
        raise RuntimeError('working database name lacks load-units-export suffix')
    ida_auto.auto_wait()
    if not ida_ida.inf_is_be() or ida_ida.inf_get_procname() != processor:
        raise RuntimeError('IDA byte order or processor differs from validated target')

    all_rows = []
    summaries = []
    for segment in parse_segments(raw):
        address = segment['address']
        backed_end = address + segment['file_size']
        virtual_end = address + segment['size']
        if segment['file_size'] == 0:
            if segment['name'] != '__PAGEZERO' or address != 0:
                raise RuntimeError('unexpected file-empty Mach-O segment')
            summaries.append({
                'name': segment['name'], 'address_start': hex(address),
                'address_end': hex(virtual_end), 'file_offset_start': segment['file_offset'],
                'file_backed_byte_count': 0, 'virtual_byte_count': segment['size'],
                'ranges': [],
                'excluded_from_ida_item_inventory': (
                    'Mach-O __PAGEZERO has no file bytes and is an address-zero guard range, not a '
                    'file-backed or loader-mapped item range'),
            })
            continue
        source_summaries = []
        if segment['file_size']:
            rows, counts, comparison = export_range(raw, segment, 'file_backed', address, backed_end,
                                                    segment['file_offset'])
            all_rows.extend(rows)
            source_summaries.append({
                'source_kind': 'file_backed', 'address_start': hex(address),
                'address_end': hex(backed_end), 'file_offset_start': segment['file_offset'],
                'byte_count': segment['file_size'], 'item_count': len(rows),
                'category_byte_counts': counts,
                'original_to_ida_byte_comparison': comparison,
            })
        if segment['size'] > segment['file_size']:
            rows, counts, comparison = export_range(raw, segment, 'zero_fill', backed_end, virtual_end, None)
            all_rows.extend(rows)
            source_summaries.append({
                'source_kind': 'zero_fill', 'address_start': hex(backed_end),
                'address_end': hex(virtual_end), 'file_offset_start': None,
                'byte_count': segment['size'] - segment['file_size'], 'item_count': len(rows),
                'category_byte_counts': counts,
                'item_bytes_source': ('IDA database values only; this virtual range has no original '
                                      'file bytes for byte-for-byte comparison'),
            })
        summaries.append({
            'name': segment['name'], 'address_start': hex(address), 'address_end': hex(virtual_end),
            'file_offset_start': segment['file_offset'], 'file_backed_byte_count': segment['file_size'],
            'virtual_byte_count': segment['size'], 'ranges': source_summaries,
        })

    output = ROOT / '05_ida' / 'exports' / architecture
    with (output / 'load-units.tsv').open('w', encoding='utf-8', newline='') as stream:
        writer = csv.DictWriter(stream, fieldnames=['segment', 'source_kind', 'address', 'file_offset',
                                                     'length', 'kind', 'original_bytes', 'ida_bytes', 'disassembly'],
                                delimiter='\t', lineterminator='\n')
        writer.writeheader()
        writer.writerows(all_rows)
    summary = {
        'schema': 1, 'architecture': architecture,
        'input_sha256': expected_sha256, 'macho_cpu_type': cpu_type,
        'macho_magic_bytes': raw[:4].hex().upper(),
        'ida_processor': ida_ida.inf_get_procname(), 'ida_big_endian': ida_ida.inf_is_be(),
        'database_kind': 'copied_working_database', 'database_filename': database_path.name,
        'segments': summaries, 'item_count': len(all_rows),
        'scope': ('complete sequential IDA item inventory of every file-backed or zero-fill virtual Mach-O '
                  'segment range; IDA kind labels remain tool hypotheses'),
    }
    (output / 'load-units-summary.json').write_text(
        json.dumps(summary, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({'architecture': architecture, 'item_count': len(all_rows),
                      'segment_count': len(summaries), 'all_checks_passed': True}, sort_keys=True))


try:
    main()
except Exception:
    traceback.print_exc()
    ida_pro.qexit(1)
ida_pro.qexit(0)
