"""Cross-check power edges, original prefixes, registry contract and source provenance."""
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
spec = importlib.util.spec_from_file_location('power', HERE / 'power_execution.py')
P = importlib.util.module_from_spec(spec)
spec.loader.exec_module(P)
R, ROOT = P.R, P.R.ROOT


def cstring(address):
    data = bytearray()
    for offset in range(4096):
        b = R.read_original(address + offset, 1)
        if b == b'\0':
            return data.decode('ascii')
        data.extend(b)
    raise AssertionError('Unterminated string')


def main():
    targets = {P.POWER, P.MANAGEMENT, R.NAMES['_PMSetPowerState'], R.NAMES['_md_shutdown_devices']}
    refs = []
    with (R.G / 'references.tsv').open() as stream:
        for row in csv.DictReader(stream, delimiter='\t'):
            try:
                target, source = int(row['to'], 16), int(row['from'], 16)
            except ValueError:
                continue
            if target in targets:
                owners = [f['name'] for f in R.FUNCS if any(int(r['start'], 16) <= source <= int(r['end_inclusive'], 16) for r in f['body'])]
                if row['type'] == 'UNCONDITIONAL_CALL':
                    ins = next(R.CS.disasm(R.read_original(source, 5), source, count=1))
                    assert ins.mnemonic == 'call' and ins.operands[0].imm == target
                refs.append({**row, 'owners': owners})
    # Independently identify direct CALLs to the two wrappers over all exported
    # instruction lists, deduplicating analysis-fragment overlap by address.
    direct = {}
    for f in R.FUNCS:
        for ins in R.function_instructions(int(f['address'], 16)).values():
            if ins.mnemonic == 'call' and ins.operands[0].type == R.X86_OP_IMM and ins.operands[0].imm in (P.POWER, P.MANAGEMENT):
                direct[ins.address] = ins.operands[0].imm
    exported = {int(r['from'], 16): int(r['to'], 16) for r in refs
                if r['type'] == 'UNCONDITIONAL_CALL' and int(r['to'], 16) in (P.POWER, P.MANAGEMENT)}
    assert direct == exported
    metadata = json.loads((ROOT / '03_original/x86/inventory/objc.json').read_text())
    method = next(r for r in metadata['methods'] if r['selector'] == 'lookupByObjectNumber:instance:')
    sel, types, imp = struct.unpack('<III', R.read_original(int(method['metadata_address'], 16), 12))
    assert imp == P.LOOKUP_METHOD and cstring(sel) == method['selector'] and cstring(types) == method['types']
    paths = {
        ROOT / '01_resources/upstream/darwin01/kernel/driverkit/autoconfCommon.m': ['IOObjectNumber i = 0;', 'lookupByObjectNumber:i++', '_io_setDriverPowerState(', '_ioSetDriverPowerManagementState('],
        ROOT / '01_resources/upstream/darwin01/driverkit-1/libDriver/IODevice.m': ['static IOReturn objectNumToId(', 'objectNumber >= globalObjectCounter', 'IO_R_OFFLINE', 'lookupByObjectNumber', 'globalObjectCounter++'],
        ROOT / '01_resources/upstream/darwin01/kernel/kern/power.c': ['power_callout(', 'thread_call_t\tcallout', 'get_power_event(0)', 'thread_call_allocate'],
        ROOT / '01_resources/upstream/darwin01/kernel/machdep/i386/APM_i386.c': ['_io_setDriverPowerState(state)'],
        ROOT / '01_resources/upstream/darwin01/kernel/machdep/i386/machdep.c': ['_io_setDriverPowerState(PM_OFF)'],
        ROOT / '01_resources/upstream/darwin01/driverkit-1/driverkit/return.h': ['IO_R_NO_DEVICE', 'IO_R_OFFLINE'],
    }
    source_rows = []
    for path, needles in paths.items():
        raw = path.read_bytes()
        lines = raw.decode(errors='replace').splitlines()
        assert all(any(n in line for line in lines) for n in needles), path
        source_rows.append({'path': str(path.relative_to(ROOT)), 'sha256': hashlib.sha256(raw).hexdigest(),
                            'lines': [{'line': i, 'text': line} for i, line in enumerate(lines, 1) if any(n in line for n in needles)]})
    origin = json.loads((ROOT / '03_original/manifest.json').read_text())
    binary_copies = []
    for item in origin['files']:
        if item['kind'] in ('kernel', 'same_kernel'):
            path = ROOT.parent / item['source']
            actual = hashlib.sha256(path.read_bytes()).hexdigest()
            assert actual == item['sha256'] == hashlib.sha256(R.RAW).hexdigest()
            binary_copies.append({'path': str(path), 'sha256': actual})
    rows = json.loads((HERE / 'power-execution.json').read_text())['cases']
    comparisons = [{k: r[k] for k in ('route', 'ambient_or_handle_ebx', 'lookup_numbers', 'performed')}
                   for r in rows if r['route'] in ('init', 'callout', 'shutdown')
                   and r['ambient_or_handle_ebx'] in ('0x0', '0x1', '0x600100')
                   and r['layout'] == 'all' and r['requested_state'] == 3]
    result = {'references': refs, 'raw_wrapper_direct_calls': {hex(a): hex(b) for a, b in direct.items()},
              'wrapper_direct_call_counts': {hex(target): sum(v == target for v in direct.values()) for target in (P.POWER, P.MANAGEMENT)},
              'lookup_metadata_verified': method,
              'selectors': {n: {'pointer': hex(p), 'text': cstring(p)} for n, p in P.SELECTORS.items()},
              'source_evidence': source_rows, 'binary_copies': binary_copies, 'comparisons': comparisons,
              'nop_pairs': [{'address': hex(a), 'bytes': R.read_original(a, 2).hex()} for a in (0x17e5fe, 0x17e68e)],
              'limits': 'Agreement of local copies is not a pristine-vendor or historical patch-provenance proof. Direct-call search covers existing exported instructions, not arbitrary runtime indirect targets.'}
    (HERE / 'evidence.json').write_text(json.dumps(result, indent=2) + '\n')
    inputs = list(paths) + [ROOT / '03_original/manifest.json', ROOT / '03_original/x86/binaries/mach_kernel',
                           ROOT / '03_original/x86/inventory/objc.json', R.G / 'references.tsv']
    for entry in sorted(set(P.ENTRIES + [R.NAMES['_boot']])):
        for ext in ('.asm', '.c'):
            inputs.append(R.G / 'functions' / (f'{entry:08x}' + ext))
        ida = ROOT / '05_ida/exports/x86/functions' / f'{entry:08x}.c'
        if ida.exists():
            inputs.append(ida)
    manifest = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': hashlib.sha256(p.read_bytes()).hexdigest()} for p in inputs]
    (HERE / 'input-hashes.json').write_text(json.dumps(manifest, indent=2) + '\n')
    print(json.dumps({'direct_call_counts': result['wrapper_direct_call_counts'], 'input_files': len(manifest),
                      'local_binary_copies_verified': len(binary_copies), 'comparison_rows': len(comparisons)}, indent=2))


if __name__ == '__main__':
    main()
