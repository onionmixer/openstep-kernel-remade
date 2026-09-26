"""Fresh original fault/write prefix followed by original dirty user-map removal.

No report32 producer runs. Prefix intermediate points/zero_chunks remain report32 evidence;
the newly recorded prefix establishes trace/store/boundary equality, not native hardware.
"""
import importlib.util
import itertools
import json
from pathlib import Path
import struct
import sys
from verify_artifacts import preserved

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('fault32', HERE.parent / 'continuous-review-20260911-32/fault_new_pt_review.py')
F = importlib.util.module_from_spec(spec)
spec.loader.exec_module(F)
B, N, T, Q, P, D, U, X = F.B, F.N, F.T, F.Q, F.P, F.D, F.U, F.X
reg = T.reg
SEGMENTS, SEGCOUNT, STRIDE = 0x1f6e60, 0x1f6e98, 0x1c


def save(name, data):
    (HERE / name).write_text(json.dumps(data, indent=2) + '\n')


def prefix(params):
    target, name, destination, flags, sleepable = params
    uc, info = F.setup(*params)
    vm = info['vm_size']
    before = F.snapshot(uc, vm)
    fault_run = T.high_run(uc, N.R.NAMES[name], {D.STOP}, True)
    assert fault_run['error'] is None and len(fault_run['interrupts']) == 1
    event = fault_run['interrupts'][0]
    fault = event['snapshot']
    assert event['vector'] == 14 and fault['eip'] in N.S.FS and fault['cr2'] == Q.BUFFER + destination
    at_fault = F.snapshot(uc, vm)
    frame_address = fault['esp'] - T.FRAME_SIZE
    cpu_frame = fault['esp'] - 4 * D.WORD
    words = [2, fault['eip'], fault['cs'], fault['eflags']]
    D.put(uc, cpu_frame, *words)
    uc.reg_write(X.UC_X86_REG_ESP, cpu_frame)
    injected = F.snapshot(uc, vm)
    heads, writes = [], []
    def checkpoint(engine, pc):
        heads.append(pc)
    def write(engine, access, address, width, value, unused):
        writes.append({'pc': reg(engine, 'eip'), 'trace_index': len(heads) - 1,
                       'address': address, 'width': width, 'value': value & ((1 << (width * 8)) - 1)})
    hook = uc.hook_add(U.UC_HOOK_MEM_WRITE, write)
    try:
        handler = T.high_run(uc, 0x1861cc, {D.STOP}, True, checkpoint)
    finally:
        uc.hook_del(hook)
    assert handler['error'] is None and not handler['interrupts'] and reg(uc, 'eip') == D.STOP
    result = {'target': target, 'function': name, 'destination': destination, 'flags': flags, 'sleepable': sleepable,
              'setup': info, 'before': before, 'fault': fault_run, 'at_fault': at_fault,
              'cpu_frame_input': {'address': cpu_frame, 'words': words}, 'frame_address': frame_address,
              'native_cpu_frame_verified': False, 'injected': injected, 'handler': handler,
              'recorded_heads': list(map(hex, heads)), 'writes': writes, 'after': F.snapshot(uc, vm), 'failure': None}
    return uc, result


def snapshot(uc, vm):
    result = F.snapshot(uc, vm)
    result['physical_segments'] = bytes(uc.mem_read(SEGMENTS, SEGCOUNT - SEGMENTS + D.WORD)).hex()
    return result


def case(params, reference):
    uc, prior = prefix(params)
    # Compare serialized evidence types (setup contains Python tuples/int keys).
    # This changes no emulator state or recorded value; no field is omitted.
    prior = json.loads(json.dumps(prior))
    for key in prior:
        assert prior[key] == reference[key], ('prefix mismatch', params, key)
    vm = prior['setup']['vm_size']
    pre_input = snapshot(uc, vm)
    raw = bytearray(SEGCOUNT - SEGMENTS + D.WORD)
    shift = D.words(uc, 0x1f6ea4, 1)[0]
    for index, (page, physical) in enumerate(((N.PAGE_OBJECT, N.FRAME), (B.PG, B.PTFRAME))):
        struct.pack_into('<7I', raw, index * STRIDE, page, physical >> shift, 0, 0, 0, physical, physical + vm)
    struct.pack_into('<I', raw, SEGCOUNT - SEGMENTS, 2)
    uc.mem_write(SEGMENTS, bytes(raw))
    args = [N.PMAP, Q.BUFFER, Q.BUFFER + vm]
    D.put(uc, N.CALL_STACK, D.STOP, *args)
    uc.reg_write(X.UC_X86_REG_ESP, N.CALL_STACK)
    for register, value in D.REGS.values():
        uc.reg_write(register, value)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    before = snapshot(uc, vm)
    heads, writes, points = [], [], []
    nargs = {0x18fa44: 3, 0x18f7f8: 4, 0x178894: 1, 0x190f90: 5}
    milestones = set(nargs) | {0x18faac, 0x18f8e4, 0x18f94c, 0x18f95a, 0x18f95e,
        0x18f96a, 0x18f96e, 0x18f9bc, 0x191040, 0x19104d, 0x191082, 0x1788cc, 0x1788f0}
    def checkpoint(engine, pc):
        index = len(heads)
        heads.append(pc)
        assert pc not in (0x10ca6c, 0x163320, 0x1631a0, 0x16b790, 0x16b84c,
                          0x17b540, 0x17b6e8, 0x18b59b, 0x18b5dc, 0x18b5ef), hex(pc)
        if pc in milestones:
            p = {'pc': hex(pc), 'trace_index': index, 'write_cursor': len(writes),
                 'cpu': T.snap(engine), 'state': snapshot(engine, vm)}
            if pc in nargs:
                p['args'] = D.words(engine, reg(engine, 'esp') + D.WORD, nargs[pc])
            points.append(p)
    def write(engine, access, address, width, value, unused):
        writes.append({'pc': reg(engine, 'eip'), 'trace_index': len(heads) - 1,
                       'address': address, 'width': width, 'value': value & ((1 << (width * 8)) - 1)})
    hook = uc.hook_add(U.UC_HOOK_MEM_WRITE, write)
    obs, failure = None, None
    try:
        obs = T.high_run(uc, 0x18fa44, {D.STOP}, True, checkpoint)
    except Exception as exc:
        failure = repr(exc)
    finally:
        uc.hook_del(hook)
    result = {'params': list(params), 'prefix': prior, 'pre_input': pre_input,
              'input': {'segments_address': SEGMENTS, 'segments_bytes': raw.hex(),
                        'call_stack': N.CALL_STACK, 'args': args, 'eflags': 2},
              'before': before, 'observation': obs, 'recorded_heads': list(map(hex, heads)),
              'writes': writes, 'points': points, 'after': snapshot(uc, vm), 'failure': failure,
              'native_cpu_frame_verified': False, 'whole_ownership_verified': False}
    save('latest-diagnostic.json', result)
    assert failure is None, failure
    assert obs['error'] is None and not obs['interrupts'] and obs['trace'] == result['recorded_heads']
    assert reg(uc, 'eip') == D.STOP and reg(uc, 'esp') == N.CALL_STACK + D.WORD
    D.assert_callee_saved(uc)
    T.guard_check(uc)
    assert result['after']['frame'] == before['frame'] and result['after']['copy_buffer_hashes'] == before['copy_buffer_hashes']
    assert bytes(uc.mem_read(N.PAGE_OBJECT + 0x1e, 1)) == b'\x02'
    assert bytes(uc.mem_read(N.PAGE_OBJECT + 0x20, 1)) == b'\x04'
    assert D.words(uc, N.PMAP + 0x10, 2) == [0, 0]
    assert D.words(uc, N.descriptor(N.FRAME, vm), 3) == [0, 0, Q.BUFFER]
    assert bytes(uc.mem_read(N.descriptor(N.FRAME, vm) + 0x10, 1)) == b'\x03'
    assert D.words(uc, N.PT_HEAD, 2) == [N.PT_HEAD, N.PT_HEAD]
    assert D.words(uc, 0x1f7ad8, 2) == [N.EXTENSION, N.EXTENSION]
    assert D.words(uc, 0x1f7ad4, 1) == [1]
    assert D.words(uc, prior['setup']['kernel_pmap'] + 0x10, 2) == [1, 1]
    for k in ('object', 'kernel_object', 'kernel_page', 'kernel_pmap', 'kernel_map', 'kernel_entry', 'entry_zone', 'extension_zone'):
        assert result['after'][k] == before[k], k
    return result


def main():
    save('preservation-before.json', preserved())
    reference = json.loads((HERE.parent / 'continuous-review-20260911-32/fault-new-pt-cases.json').read_text())
    lookup = {tuple(r[k] for k in ('target', 'function', 'destination', 'flags', 'sleepable')): r for r in reference}
    params = [('A', '_copyout', 0x100, 2, 1)] if '--single' in sys.argv else itertools.product(
        Q.ROOTS, N.S.TARGETS, (0x100, 0x1100), (2, 0x602), (1, 0))
    rows = []
    for p in params:
        rows.append(case(p, lookup[tuple(p)]))
        print(json.dumps({'case': len(rows), 'params': p}), flush=True)
    save('dirty-remove-cases.json', rows)
    writes = [w for r in rows for w in r['writes']]
    save('dirty-remove-summary.json', {'cases': len(rows), 'remove_heads': sum(len(r['observation']['trace']) for r in rows),
        'dirty_lookups': sum(r['observation']['trace'].count('0x178894') for r in rows),
        'pte_clears': sum(w['pc'] == 0x18f96e for w in writes),
        'pde_invalidations': sum(w['pc'] == 0x191040 for w in writes),
        'whole_goal_complete': False, 'status': 'runner assertions; independent audit and reproduction are separate'})
    save('preservation-after.json', preserved())


if __name__ == '__main__':
    main()
