"""Calculate and preserve read-only review checks; no database/source modifications."""
import ast
import base64
import collections
import csv
import hashlib
import json
import struct
from pathlib import Path

ROOT = Path('/mnt/USERS/onion/DATA_ORIGN/Workspace/NeXT_DRIVER/openstep-kernel-remade')
OUT = ROOT / '09_validation/reports/deep-review-20260911'
G = ROOT / '04_ghidra/exports/x86/full-pass5'


def load(path):
    return json.loads(path.read_text())


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    meta = load(ROOT / '03_original/x86/inventory/macho.json')
    raw = (ROOT / '03_original/x86/binaries/mach_kernel').read_bytes()
    assert hashlib.sha256(raw).hexdigest() == meta['sha256']
    blocks = load(OUT / 'ghidra-memory.json')
    covered = set()
    memory_errors = []
    for block in blocks:
        if not block['initialized']:
            continue
        address = int(block['start'], 16)
        data = base64.b64decode(block['base64'])
        segment = next(s for s in meta['segments'] if int(s['address'], 16) <= address
                       and address + len(data) <= int(s['address'], 16) + s['file_size'])
        offset = segment['file_offset'] + address - int(segment['address'], 16)
        covered.update(range(offset, offset + len(data)))
        if data != raw[offset:offset + len(data)]:
            memory_errors.append(block['name'])
    records = load(ROOT / '09_validation/reports/full-analysis/artifact-hashes.json')
    changed = [row['path'] for row in records if digest(ROOT / row['path']) != row['sha256']
               or (ROOT / row['path']).stat().st_size != row['size']]
    functions = load(G / 'functions.json')
    function_map = {int(row['address'], 16): row for row in functions}
    symbols = {row['name']: int(row['value'], 16) for row in csv.DictReader(
        (ROOT / '03_original/x86/inventory/symbols.tsv').open(), delimiter='\t')}

    def read(address, length):
        segment = next(s for s in meta['segments'] if int(s['address'], 16) <= address
                       < int(s['address'], 16) + s['file_size'])
        offset = segment['file_offset'] + address - int(segment['address'], 16)
        return raw[offset:offset + length]

    tables = []
    for name, count_name, fmt, handler_index in [('_sysent', '_nsysent', '<hhI', 2),
                                                ('_mach_trap_table', '_mach_trap_count', '<4I', 1)]:
        count = struct.unpack('<I', read(symbols[count_name], 4))[0]
        size = struct.calcsize(fmt)
        rows = [struct.unpack(fmt, read(symbols[name] + i * size, size)) for i in range(count)]
        targets = [row[handler_index] for row in rows]
        tables.append({'name': name, 'address': hex(symbols[name]), 'entries': count,
                       'entry_size': size, 'unique_targets': len(set(targets)),
                       'missing_function_entries': [hex(a) for a in targets if a not in function_map],
                       'rows': rows})

    ida = load(ROOT / '05_ida/exports/x86/index.json')
    groups = collections.defaultdict(list)
    for row in ida['functions']:
        if not row.get('pseudocode'):
            continue
        text = (ROOT / row['pseudocode']).read_text()
        code = text[text.index('*/') + 2:]
        groups[hashlib.sha256(code.encode()).hexdigest()].append(row['address'])
    duplicates = [group for group in groups.values() if len(group) > 1]
    failed = {int(row['address'], 16) for row in ida['functions'] if not row.get('pseudocode')}
    warnings = load(ROOT / '09_validation/reports/full-analysis/decompiler-warnings.json')
    warning_addresses = {int(row['address'], 16) for row in warnings}
    instruction_audit = load(OUT / 'instruction-audit.json')
    pattern_counts = {}
    for name, addresses in instruction_audit['patterns'].items():
        pattern_counts[name] = dict(collections.Counter(
            'fragment' if function_map[int(a, 16)]['analysis_fragment'] else 'function' for a in addresses))
    high = [json.loads(line) for line in (OUT / 'ghidra-functions.jsonl').read_text().splitlines()]
    assert {int(row['entry'], 16) for row in high} == set(function_map)
    assert all(row['completed'] for row in high)
    headers = [ROOT.parent / 'ref/openstep/headers/NextDeveloper/Headers/bsd/sys/systm.h',
               ROOT / '01_resources/upstream/darwin01/kernel/kern/syscall_sw.h',
               ROOT / '01_resources/upstream/darwin01/kernel/machdep/i386/fault_copy.c',
               ROOT / '01_resources/upstream/nextmach/mk-108.1/nextdev/vol.c']
    report = {
        'binary_sha256': meta['sha256'],
        'original_file_bytes': len(raw),
        'ghidra_memory_compared_file_bytes': len(covered),
        'missing_file_offsets': len(set(range(len(raw))) - covered),
        'initialized_memory_blocks': sum(block['initialized'] for block in blocks),
        'memory_mismatch_blocks': memory_errors,
        'verified_existing_export_files': len(records),
        'changed_existing_exports': changed,
        'highfunction_units_rechecked': len(high),
        'dispatch_tables': tables,
        'ida_successful_request_addresses': ida['successful_addresses'],
        'ida_failed_request_addresses': len(failed),
        'ida_exact_duplicate_output_groups': duplicates,
        'ida_failed_and_ghidra_warning_addresses': [hex(a) for a in sorted(failed & warning_addresses)],
        'ida_internal_database_bytes_verified': False,
        'pattern_file_counts': pattern_counts,
        'fragment_body_bytes': sum(f['body_bytes'] for f in functions if f['analysis_fragment']),
        'false_zero_padding_instruction_bytes_at_objc_forward': 0x1cebff - 0x1cebf3,
        'zero_gap_bytes_before_next_function': 0x1cec00 - 0x1cebf3,
        'local_reference_hashes': [{'path': str(p), 'sha256': digest(p)} for p in headers],
        'verdict': 'Raw material integrity passes; semantic completeness and correct function classification do not pass.',
        'implementation_or_database_fixes_applied': False,
    }
    (OUT / 'supplemental.json').write_text(json.dumps(report, indent=2) + '\n')
    for path in (OUT / 'scripts').glob('*.py'):
        ast.parse(path.read_text(), filename=str(path))
    hashes = [{'path': str(path.relative_to(ROOT)), 'size': path.stat().st_size, 'sha256': digest(path)}
              for path in sorted(OUT.rglob('*')) if path.is_file() and path.name != 'review-artifact-hashes.json']
    (OUT / 'review-artifact-hashes.json').write_text(json.dumps(hashes, indent=2) + '\n')
    print(json.dumps({k: v for k, v in report.items() if k != 'dispatch_tables'}, indent=2))
    assert not memory_errors and not changed
    assert len(covered) == len(raw)
    assert all(not table['missing_function_entries'] for table in tables)


if __name__ == '__main__':
    main()
