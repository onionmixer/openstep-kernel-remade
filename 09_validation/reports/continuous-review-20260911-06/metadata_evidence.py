"""Validate exported ObjC method records against raw binary and pin local sources."""
import collections
import csv
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('dispatch', HERE / 'dispatch_execution.py')
D = importlib.util.module_from_spec(spec)
spec.loader.exec_module(D)
R, ROOT = D.R, D.ROOT


def cstring(address):
    result = bytearray()
    for offset in range(4096):
        byte = R.read_original(address + offset, 1)
        if byte == b'\x00':
            return result.decode('ascii')
        result.extend(byte)
    raise AssertionError('Unterminated string')


def main():
    metadata = json.loads((ROOT / '03_original/x86/inventory/objc.json').read_text())
    checked = []
    for row in metadata['methods']:
        address = int(row['metadata_address'], 16)
        sel, types, imp = struct.unpack('<III', R.read_original(address, struct.calcsize('<III')))
        assert cstring(sel) == row['selector']
        assert cstring(types) == row['types']
        assert imp == int(row['imp'], 16)
        checked.append({**row, 'selector_pointer': hex(sel), 'types_pointer': hex(types)})
    headers = ROOT.parent / 'ref/openstep/headers/NextDeveloper/Headers/objc'
    for row in metadata['layout_headers']:
        assert hashlib.sha256(Path(row['path']).read_bytes()).hexdigest() == row['sha256']
    source_files = {
        headers / 'objc-runtime.h': ['objc_msgSend(', 'objc_msgSendSuper(', 'objc_msgSendv(', 'struct objc_super'],
        headers / 'objc-class.h': ['struct objc_cache {', 'Method buckets', 'IMP method_imp'],
        headers / 'Object.h': ['forward:', 'performv:'],
        ROOT / '01_resources/upstream/darwin01/kernel/driverkit/KernBus.m': ['(Range)mappedRange', 'return _mappedRange'],
        ROOT / '01_resources/upstream/darwin01/driverkit-1/libDriver/Kernel/SCSIGeneric.m': ['(unsigned long long)SCSI3_lun', 'return _lun'],
        ROOT / '01_resources/upstream/darwin01/driverkit-1/libDriver/Kernel/IOTokenRing.m': ['(token_addr_t)nodeAddress', 'return _nodeAddress'],
    }
    source_evidence = []
    for path, needles in source_files.items():
        data = path.read_bytes()
        lines = data.decode('utf-8', errors='replace').splitlines()
        matches = [{'line': i, 'text': line} for i, line in enumerate(lines, 1)
                   if any(needle in line for needle in needles)]
        assert all(any(needle in line for line in lines) for needle in needles), path
        source_evidence.append({'path': str(path), 'sha256': hashlib.sha256(data).hexdigest(), 'matches': matches})
    selected = [r for r in checked if r['types'].startswith(('{', 'Q')) or r['selector'] in ('forward::', 'performv::')]
    node = next(r for r in checked if r['owner'] == 'IOTokenRing' and r['selector'] == 'nodeAddress')
    refs = []
    with (R.G / 'references.tsv').open() as stream:
        for row in csv.DictReader(stream, delimiter='\t'):
            try:
                address = int(row['to'], 16)
            except ValueError:
                continue
            if address == int(node['selector_pointer'], 16):
                refs.append(row)
    result = {'method_records_verified': len(checked),
              'leading_encoding_characters': dict(collections.Counter(r['types'][0] for r in checked)),
              'qualification': 'Leading-character counts are not a complete Objective-C type parser; r is a qualifier.',
              'selected_methods': selected, 'local_source_evidence': source_evidence,
              'node_address_selector_references': refs,
              'limits': 'Validates fields of existing inventory records, not completeness of all runtime-added classes/methods or owner attribution.'}
    (HERE / 'metadata-evidence.json').write_text(json.dumps(result, indent=2) + '\n')
    inputs = [ROOT / '03_original/x86/binaries/mach_kernel', ROOT / '03_original/x86/inventory/objc.json',
              ROOT / '03_original/x86/inventory/macho.json', R.G / 'references.tsv'] + list(source_files)
    entries = [R.NAMES[n] for n in D.TARGETS] + [0x17f348, 0x1ae96c, 0x1ab830]
    for entry in entries:
        inputs.extend([R.G / 'functions' / f'{entry:08x}.asm', R.G / 'functions' / f'{entry:08x}.c',
                       ROOT / '05_ida/exports/x86/functions' / f'{entry:08x}.c'])
    rows = [{'path': str(p), 'size': p.stat().st_size, 'sha256': hashlib.sha256(p.read_bytes()).hexdigest()} for p in inputs]
    (HERE / 'input-hashes.json').write_text(json.dumps(rows, indent=2) + '\n')
    print(json.dumps({'method_records_verified': len(checked), 'selected_records': len(selected),
                      'source_files': len(source_evidence), 'input_files': len(rows),
                      'node_selector_references': refs}, indent=2))


if __name__ == '__main__':
    main()
