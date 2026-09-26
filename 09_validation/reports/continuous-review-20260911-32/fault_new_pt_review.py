"""Observed NP write -> original data/new PT allocation -> original IRETD/copy.

CPU exception-frame input is explicit; native exception-frame generation is not claimed.
No API memory corrections after that input boundary, and no call mocks or patched code.
"""
import importlib.util
import itertools
import json
from pathlib import Path
import sys
from verify_artifacts import preserved

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('newpt31', HERE.parent / 'continuous-review-20260911-31/new_pt_review.py')
B = importlib.util.module_from_spec(spec)
spec.loader.exec_module(B)
N, T, Q, P, D, U, X = B.N, B.T, B.Q, B.P, B.D, B.U, B.X
reg = T.reg


def save(name, data):
    (HERE / name).write_text(json.dumps(data, indent=2) + '\n')


def snapshot(uc, vm):
    s = B.snapshot(uc, vm)
    s['copy_stack'] = bytes(uc.mem_read(D.STACK, 4 * D.WORD)).hex()
    s['data_high_walks'] = [P.walk(uc, reg(uc, 'cr3'), Q.BASE + N.FRAME + off) for off in range(0, vm, Q.PAGE)]
    return s


def setup(target, name, destination, flags, sleepable):
    uc, info = B.setup(target, sleepable)
    vm = info['vm_size']
    calls = []
    def original(label, entry, args):
        before = snapshot(uc, vm)
        obs = N.invoke(uc, entry, args)
        calls.append({'label': label, 'before': before, 'call': obs, 'after': snapshot(uc, vm)})
    D.put(uc, B.KO + 0x10, 1)
    original('hold_pt_page', 0x17b200, [B.KO, B.KVA, 1])
    assert reg(uc, 'eax') == B.PG
    D.put(uc, B.KO + 0x10, 0)
    for obj, page, label in [(N.OBJECT, N.PAGE_OBJECT, 'free_data_first'), (B.KO, B.PG, 'free_pt_second')]:
        D.put(uc, obj + 0x10, 1)
        D.put(uc, N.A.GLOBALS['queue_lock'], 1)
        original(label, 0x17b540, [page])
        D.put(uc, obj + 0x10, 0)
        D.put(uc, N.A.GLOBALS['queue_lock'], 0)
    free = N.A.HEADS['free']
    assert D.words(uc, free, 2) == [N.PAGE_OBJECT, B.PG]
    assert D.words(uc, N.PAGE_OBJECT, 2) == [B.PG, free]
    assert D.words(uc, B.PG, 2) == [free, N.PAGE_OBJECT]
    assert D.words(uc, N.A.GLOBALS['free_count'], 1) == [2]
    assert bytes(uc.mem_read(N.BUCKETS, 64)) == bytes(64)
    for obj in (N.OBJECT, B.KO):
        assert D.words(uc, obj, 2) == [obj, obj]
        assert int.from_bytes(uc.mem_read(obj + 0x1a, 2), 'little') == 0
        assert D.words(uc, obj + 0x10, 1) == [0]
    N.S.prepare(uc, target, name, 1, 0x100, destination)
    for a, raw in T.GUARDS.items():
        uc.mem_write(a, raw)
    uc.reg_write(X.UC_X86_REG_EFLAGS, flags)
    assert not P.walk(uc, Q.ROOTS[target], Q.BUFFER + destination)['present']
    assert D.words(uc, Q.ROOTS[target] + ((Q.BUFFER + destination) >> 22) * 4, 1) == [0]
    info.update(queue_preparation=calls, copy_function=name, destination=destination, flags=flags,
                synthetic_scope32='inherited map/object/zone/bootstrap; original free-page FIFO reorder; explicit CPU-frame input only after real NP observation')
    return uc, info


def case(target, name, destination, flags, sleepable):
    uc, info = setup(target, name, destination, flags, sleepable)
    vm = info['vm_size']
    before = snapshot(uc, vm)
    fault_run = T.high_run(uc, N.R.NAMES[name], {D.STOP}, True)
    assert fault_run['error'] is None and len(fault_run['interrupts']) == 1
    event = fault_run['interrupts'][0]
    fault = event['snapshot']
    assert event['vector'] == 14 and fault['eip'] in N.S.FS and fault['cr2'] == Q.BUFFER + destination
    at_fault = snapshot(uc, vm)
    assert at_fault['frame'] == before['frame'] and at_fault['new_pt_frame'] == before['new_pt_frame']
    assert at_fault['copy_buffer_hashes'] == before['copy_buffer_hashes']
    assert not P.walk(uc, Q.ROOTS[target], fault['cr2'])['present']
    frame_address = fault['esp'] - T.FRAME_SIZE
    cpu_frame = fault['esp'] - 4 * D.WORD
    error = 2  # NP/write/supervisor input, not CPU-generated error-code evidence.
    D.put(uc, cpu_frame, error, fault['eip'], fault['cs'], fault['eflags'])
    uc.reg_write(X.UC_X86_REG_ESP, cpu_frame)
    injected = snapshot(uc, vm)
    writes, points, zero_chunks, heads = [], [], [], []
    captured = {}
    restart_next = fault['eip'] + Q.decoded(fault['eip']).size
    nargs = {0x190cfc: 2, 0x173d1c: 3, 0x174a90: 6, 0x16b790: 1, 0x16b84c: 2,
             0x176164: 3, 0x174848: 5, 0x173ebc: 4, 0x17b200: 3, 0x175b2c: 4,
             0x173898: 3, 0x17b6e8: 1, 0x19065c: 5}
    milestones = set(nargs) | {0x187068, 0x1720d6, 0x17269f, 0x1729e9, 0x173f04, 0x173f92,
                             0x173a11, 0x1735c3, 0x173e3a, 0x190d7b, 0x190de5, 0x190e20,
                             0x190f1a, 0x1907b1, 0x173451, 0x1921ec, 0x186d7c, fault['eip'], restart_next}
    def checkpoint(engine, pc):
        index = len(heads)
        heads.append(pc)
        assert pc not in (0x10ca6c, 0x163320, 0x1631a0, 0x16b3df, 0x190e51, 0x1924a0,
                          0x18b59b, 0x18b5dc, 0x18b5ef, 0x18c12c, 0x18c174, 0x18c187), hex(pc)
        if pc == 0x1019cc:
            zero_chunks.append(dict({k: reg(engine, k) for k in ('eax', 'ecx', 'edx')}, trace_index=index))
        if pc not in milestones:
            return
        s = snapshot(engine, vm)
        raw = bytes(engine.mem_read(frame_address, T.FRAME_SIZE))
        row = {'pc': hex(pc), 'trace_index': index, 'write_cursor': len(writes),
               'cpu': T.snap(engine), 'state': s, 'saved_frame': raw.hex()}
        if pc in nargs:
            row['args'] = D.words(engine, reg(engine, 'esp') + D.WORD, nargs[pc])
        points.append(row)
        if pc == 0x187068:
            wanted = T.model_frame(fault, error)
            for field, off in T.OFFSETS.items():
                width = 2 if field in ('gs', 'fs', 'es', 'ds', 'cs') else D.WORD
                assert int.from_bytes(raw[off:off + width], 'little') == wanted[field], field
            captured['frame'] = raw
        if pc == 0x17269f:
            assert reg(engine, 'eax') == N.PAGE_OBJECT
        if pc == 0x173f04:
            assert reg(engine, 'eax') == B.PG
        if pc == 0x1729e9:
            assert s['frame'] == bytes(vm).hex()
        if pc == 0x173f92:
            assert s['new_pt_frame'] == bytes(vm).hex()
        if pc in (0x186d7c, fault['eip']):
            assert raw == captured['frame']
        if pc == fault['eip']:
            for field in ('eax', 'ebx', 'ecx', 'edx', 'esi', 'edi', 'ebp', 'esp', 'eflags', 'cs', 'ss', 'ds', 'es', 'fs', 'gs'):
                assert reg(engine, field) == fault[field], field
    def write(engine, access, address, width, value, unused):
        writes.append({'pc': reg(engine, 'eip'), 'trace_index': len(heads) - 1,
                       'address': address, 'width': width, 'value': value & ((1 << (width * 8)) - 1)})
    hook = uc.hook_add(U.UC_HOOK_MEM_WRITE, write)
    handler, failure = None, None
    try:
        handler = T.high_run(uc, 0x1861cc, {D.STOP}, True, checkpoint)
    except Exception as exc:
        failure = repr(exc)
    finally:
        uc.hook_del(hook)
    result = {'target': target, 'function': name, 'destination': destination, 'flags': flags, 'sleepable': sleepable,
              'setup': info, 'before': before, 'fault': fault_run, 'at_fault': at_fault,
              'cpu_frame_input': {'address': cpu_frame, 'words': [error, fault['eip'], fault['cs'], fault['eflags']]},
              'frame_address': frame_address, 'native_cpu_frame_verified': False, 'injected': injected,
              'handler': handler, 'recorded_heads': list(map(hex, heads)), 'points': points, 'writes': writes,
              'zero_chunks': zero_chunks, 'after': snapshot(uc, vm), 'failure': failure}
    save('latest-diagnostic.json', result)
    assert failure is None, failure
    assert handler['error'] is None and not handler['interrupts']
    assert handler['trace'] == result['recorded_heads']
    assert reg(uc, 'eip') == D.STOP and reg(uc, 'eax') == 0 and reg(uc, 'esp') == D.STACK + D.WORD
    D.assert_callee_saved(uc)
    T.guard_check(uc)
    assert handler['trace'].count(hex(fault['eip'])) == 1
    expected = bytearray(vm)
    expected[destination] = Q.PATTERNS['kernel'][0x100]
    assert result['after']['frame'] == expected.hex()
    assert result['after']['copy_buffer_hashes'] == before['copy_buffer_hashes']
    assert D.words(uc, N.A.GLOBALS['free_count'], 1) == [0]
    assert D.words(uc, N.A.GLOBALS['active_count'], 1) == [1]
    assert D.words(uc, N.A.HEADS['active'], 2) == [N.PAGE_OBJECT, N.PAGE_OBJECT]
    assert D.words(uc, N.PMAP + 0x10, 2) == [1, 0]
    assert D.words(uc, info['kernel_pmap'] + 0x10, 2) == [1, 1]
    assert D.words(uc, B.GLOBALS['wire_count'], 1) == [1]
    assert D.words(uc, 0x1f6514, 1) == [2] and D.words(uc, 0x1f6504, 1) == [1]
    assert D.words(uc, N.descriptor(N.FRAME, vm), 3) == [0, N.PMAP, Q.BUFFER]
    assert D.words(uc, N.descriptor(B.PTFRAME, vm), 4) == [0, info['kernel_pmap'], B.KVA, N.EXTENSION]
    for obj, ref in [(N.OBJECT, 1), (B.KO, 2)]:
        assert D.words(uc, obj + 0x10, 1) == [0]
        assert int.from_bytes(uc.mem_read(obj + 0x18, 2), 'little') == ref
        assert int.from_bytes(uc.mem_read(obj + 0x1a, 2), 'little') == 1
        assert int.from_bytes(uc.mem_read(obj + 0x44, 2), 'little') == 0
    assert D.words(uc, Q.THREAD + 0x74, 1) == [N.S.TARGETS[name]]
    assert result['after']['uthread'] == before['uthread']
    assert reg(uc, 'eflags') & 0x600 == flags & 0x600
    for other in Q.ROOTS:
        if other != target:
            assert result['after']['roots'][other] == before['roots'][other]
    return result


def main():
    save('preservation-before.json', preserved())
    params = [('A', '_copyout', 0x100, 2, 1)] if '--single' in sys.argv else itertools.product(
        Q.ROOTS, N.S.TARGETS, (0x100, 0x1100), (2, 0x602), (1, 0))
    rows = []
    for args in params:
        rows.append(case(*args))
        print(json.dumps({'case': len(rows), 'params': args}), flush=True)
    save('fault-new-pt-cases.json', rows)
    save('fault-new-pt-summary.json', {'cases': len(rows), 'handler_heads': sum(len(r['handler']['trace']) for r in rows),
         'zero_dword_stores': sum(len(r['zero_chunks']) * 8 for r in rows),
         'status': 'original execution with runner assertions; independent audit and reproducibility are separate artifacts', 'whole_goal_complete': False})
    save('preservation-after.json', preserved())


if __name__ == '__main__':
    main()
