"""Global delta audit and independent forwarding-return fixtures, all in Python."""
import base64
import collections
import csv
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import sys
import unicorn as U
from unicorn import x86_const as X

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('original_input', HERE.parent / 'cautious-followup-20260911/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)


def load(stage, file):
    return json.loads((HERE / 'exports' / stage / file).read_text())


def table(stage, file):
    with (HERE / 'exports' / stage / file).open() as stream:
        return list(csv.DictReader(stream, delimiter='\t'))


def forwarding_return_tests():
    rows = []
    page, stack, stop = 0x1000, 0x710000, 0x730000
    for eax in (0, 1, 0x12345678, 0xffffffff):
        for edx in (0, 0x87654321, 0xffffffff):
            uc = U.Uc(U.UC_ARCH_X86, U.UC_MODE_32)
            for seg in R.META['segments']:
                if seg['name'] == '__PAGEZERO': continue
                a = int(seg['address'], 16); lo = a & -page
                uc.mem_map(lo, (a + seg['size'] - lo + page - 1) & -page)
                uc.mem_write(a, R.RAW[seg['file_offset']:seg['file_offset'] + seg['file_size']])
            uc.mem_map(stack - page, page * 2)
            uc.mem_map(stop, page)
            selector = struct.unpack('<I', uc.mem_read(0x1f9cf0, 4))[0]
            receiver, incoming_sel, saved_ebp = 0x600000, selector ^ 1, 0x44556677
            uc.mem_write(stack, struct.pack('<III', stop, receiver, incoming_sel))
            uc.reg_write(X.UC_X86_REG_ESP, stack); uc.reg_write(X.UC_X86_REG_EBP, saved_ebp)
            uc.emu_start(R.NAMES['__objc_msgForward'], R.NAMES['_objc_msgSend'], timeout=1000000, count=100)
            assert uc.reg_read(X.UC_X86_REG_EIP) == R.NAMES['_objc_msgSend']
            call_stack = uc.reg_read(X.UC_X86_REG_ESP)
            ret, arg1, arg2, arg3, arg4 = struct.unpack('<IIIII', uc.mem_read(call_stack, 20))
            assert (ret, arg1, arg2, arg3, arg4) == (0x1cebd5, receiver, selector, incoming_sel, stack + 4)
            # Explicit mock boundary: dispatcher has returned these GPR values.
            # Do not patch the original dispatcher or claim to execute it here.
            uc.reg_write(X.UC_X86_REG_EAX, eax); uc.reg_write(X.UC_X86_REG_EDX, edx)
            uc.reg_write(X.UC_X86_REG_ESP, call_stack + 4)
            uc.emu_start(ret, stop, timeout=1000000, count=100)
            assert uc.reg_read(X.UC_X86_REG_EIP) == stop
            assert uc.reg_read(X.UC_X86_REG_EAX) == eax and uc.reg_read(X.UC_X86_REG_EDX) == edx
            assert uc.reg_read(X.UC_X86_REG_EBP) == saved_ebp and uc.reg_read(X.UC_X86_REG_ESP) == stack + 4
            rows.append({'mock_dispatch_eax': hex(eax), 'mock_dispatch_edx': hex(edx),
                         'returned_eax': hex(uc.reg_read(X.UC_X86_REG_EAX)), 'returned_edx': hex(uc.reg_read(X.UC_X86_REG_EDX)),
                         'argument_forwarding_and_stack_verified': True})
    return {'tests': rows, 'count': len(rows), 'unicorn_version': U.__version__,
            'scope': 'Original forwarding prologue/call and epilogue; dispatcher return is mocked. Not an ObjC ABI, x87 or structure-return proof.'}


def main():
    job = json.loads((HERE / 'padding-job.json').read_text())
    start, end, call = int(job['start'], 16), int(job['end'], 16), int(job['call_site'], 16)
    stages = ('baseline', 'padding_only', 'combined', 'explicit_no_fallthrough')
    records = {}
    for stage in stages:
        funcs = load(stage, 'functions.json')
        assert all(f['completed'] for f in funcs)
        units = load(stage, 'padding-units.json')
        forward = next(f for f in funcs if f['name'] == '__objc_msgForward')
        outside = [a for a in forward['pcode_addresses'] if not any(int(r['start'], 16) <= int(a, 16) <= int(r['end'], 16) for r in forward['body'])]
        records[stage] = {'padding_unit_kinds': dict(collections.Counter(u['kind'] for u in units)),
                          'padding_byte_count': sum(len(base64.b64decode(u['bytes'])) for u in units),
                          'forward_body_bytes': sum(int(r['end'], 16) - int(r['start'], 16) + 1 for r in forward['body']),
                          'outside_body_pcode': outside, 'call': load(stage, 'call-unit.json')}
        assert b''.join(base64.b64decode(u['bytes']) for u in units) == R.read_original(start, end - start + 1)
    first, last = stages[0], stages[-1]
    b_units = {r['start']: r for r in table(first, 'all-code-units.tsv')}
    a_units = {r['start']: r for r in table(last, 'all-code-units.tsv')}
    changed = [{'start': key, 'before': b_units.get(key), 'after': a_units.get(key)}
               for key in sorted(b_units.keys() | a_units.keys()) if b_units.get(key) != a_units.get(key)]
    assert all(start <= int(x['start'], 16) <= end or int(x['start'], 16) == call for x in changed)
    b_refs = {tuple(r.values()) for r in table(first, 'all-references.tsv')}
    a_refs = {tuple(r.values()) for r in table(last, 'all-references.tsv')}
    refs_removed, refs_added = sorted(b_refs - a_refs), sorted(a_refs - b_refs)
    b_body = {f['entry']: f for f in load(first, 'all-function-bodies.json')}
    a_body = {f['entry']: f for f in load(last, 'all-function-bodies.json')}
    body_changed = [k for k in b_body.keys() | a_body.keys() if b_body.get(k) != a_body.get(k)]
    assert body_changed == [f'{R.NAMES["__objc_msgForward"]:08x}']
    b_mem, a_mem = load(first, 'initialized-memory.json'), load(last, 'initialized-memory.json')
    assert b_mem == a_mem
    covered = bytearray(len(R.RAW))
    for block in a_mem:
        a = int(block['start'], 16); data = base64.b64decode(block['bytes'])
        for seg in R.META['segments']:
            sa = int(seg['address'], 16); lo, hi = max(a, sa), min(a + len(data), sa + seg['file_size'])
            if lo >= hi: continue
            offset = seg['file_offset'] + lo - sa
            assert data[lo-a:hi-a] == R.RAW[offset:offset+hi-lo]
            covered[offset:offset+hi-lo] = bytes([1]) * (hi-lo)
    assert all(covered)
    c = {s: (HERE / 'exports' / s / '001cebb0.c').read_text() for s in stages}
    assert c['baseline'] == c['padding_only']
    assert c['combined'] == c['explicit_no_fallthrough']
    assert not records[last]['outside_body_pcode']
    assert records[last]['padding_unit_kinds'] == {'data': 1}
    assert not records[last]['call'].get('fallthrough') and records[last]['call']['fallthrough_override']
    for name in ('_objc_msgSendv', '_objc_msgSend', '__switch_tss'):
        texts = [(HERE / 'exports' / s / f'{R.NAMES[name]:08x}.c').read_text() for s in stages]
        assert all(t == texts[0] for t in texts)
    summary = {'all_function_bodies_checked': len(b_body), 'changed_function_bodies': len(body_changed),
               'padding_bytes': job['length'], 'removed_function_body_bytes': records[first]['forward_body_bytes'] - records[last]['forward_body_bytes'],
               'changed_code_unit_starts': len(changed), 'reference_edges_removed': len(refs_removed), 'reference_edges_added': len(refs_added),
               'initialized_blocks_unchanged': len(a_mem), 'original_file_bytes_verified': sum(covered),
               'padding_only_c_unchanged': True, 'combined_c_has_no_outside_body_pcode': True,
               'normal_return_type_still_inadequate': 'Corrected C is void; original epilogue preserves dispatcher EAX/EDX. Full ObjC return ABI remains unresolved.'}
    result = {'summary': summary, 'stages': records, 'code_unit_deltas': changed,
              'function_body_deltas': [{'before': b_body[k], 'after': a_body[k]} for k in body_changed],
              'reference_edges_removed': refs_removed, 'reference_edges_added': refs_added}
    (HERE / 'audit.json').write_text(json.dumps(result, indent=2) + '\n')
    returns = forwarding_return_tests()
    (HERE / 'forwarding-return-tests.json').write_text(json.dumps(returns, indent=2) + '\n')
    print(json.dumps({'audit': summary, 'return_fixtures': returns['count']}, indent=2))


if __name__ == '__main__':
    main()
