"""Original VM-entry protection rejection versus permission gate only.

All arithmetic is Python. No original instruction/call mocking. CPU exception
frame is synthetic, immediately following the observed CPU-model page fault.
"""
import importlib.util
import itertools
import json
from pathlib import Path
import sys
from verify_artifacts import preserved

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('trap24', HERE.parent / 'continuous-review-20260911-24/trap_review.py')
T = importlib.util.module_from_spec(spec)
spec.loader.exec_module(T)
Q, S, P, R, D, U, X = T.Q, T.S, T.P, T.R, T.D, T.U, T.X
MAP, TASK, UTHREAD, ENTRY = T.MAP, T.TASK, T.UTHREAD, Q.THREAD + 0x600
reg = T.reg


def save(name, value):
    (HERE / name).write_text(json.dumps(value, indent=2) + '\n')


def setup(target, name, hint, destination, flags, protection):
    uc, info = Q.fixture()
    S.control_gate(uc)
    info['idt'] = T.idt(uc)
    mask = D.words(uc, 0x1e89ec, 1)[0]
    vm_size = mask + 1
    assert vm_size == Q.SPAN and Q.BUFFER & mask == 0
    mappings = []
    for off in range(0, vm_size, Q.PAGE):
        low = P.walk(uc, Q.ROOTS[target], Q.BUFFER + off)
        address = int(low['pte_address'], 16)
        D.put(uc, address, D.words(uc, address, 1)[0] & ~2)
        low = P.walk(uc, Q.ROOTS[target], Q.BUFFER + off)
        high = P.walk(uc, Q.ROOTS[target], Q.BASE + Q.BUFFER + off)
        assert low['present'] and low['user'] and not low['writable']
        assert high['present'] and high['writable'] and not high['user']
        assert int(high['physical'], 16) == Q.BUFFER + off
        assert int(low['physical'], 16) == Q.PAYLOAD[target] + off
        mappings.append({'low': low, 'high': high})
    info.update(vm_size=vm_size, page_mask=mask, mappings=mappings)
    info['switch'] = Q.switch(uc, target)
    info['far_jump'] = T.far_jump(uc)
    uc.mem_write(MAP, bytes(0x50))
    uc.mem_write(ENTRY, bytes(0x2c))
    sentinel = MAP + 0xc
    D.put(uc, sentinel, ENTRY, ENTRY, 0, 0xbfffffff, 1)
    D.put(uc, ENTRY, sentinel, sentinel, Q.BUFFER, Q.BUFFER + vm_size)
    D.put(uc, ENTRY + 0x1c, protection, 3)
    D.put(uc, MAP + 0x38, ENTRY if hint == 'entry' else sentinel)
    D.put(uc, Q.THREAD + 0xc, TASK)
    D.put(uc, TASK + 0xc, MAP)
    D.put(uc, 0x1e875c, UTHREAD)
    uc.mem_write(UTHREAD + 0x68, bytes([0xa5]))
    D.put(uc, 0x1f74d4, 0)
    # Run initialization before preparing/observing the copy fault.
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    D.put(uc, D.STACK, D.STOP, MAP, 1)
    uc.reg_write(X.UC_X86_REG_ESP, D.STACK)
    init = T.high_run(uc, 0x15b54c, {D.STOP}, True)
    assert not init['error'] and not init['interrupts'] and reg(uc, 'eip') == D.STOP
    assert D.words(uc, MAP, 3) == [0xffffffff, 8 << 16, 0]
    initial, expected, source = S.prepare(uc, target, name, 1, 0x100, destination)
    for address, value in T.GUARDS.items():
        uc.mem_write(address, value)
    uc.reg_write(X.UC_X86_REG_EFLAGS, flags)
    info['lock_init'] = init
    return uc, info, initial


def case(target, name, hint, destination, flags, protection):
    uc, info, initial = setup(target, name, hint, destination, flags, protection)
    map_before = bytes(uc.mem_read(MAP, 0x50))
    entry_before = bytes(uc.mem_read(ENTRY, 0x2c))
    counter = D.words(uc, 0x1f6514, 1)[0]
    fault_run = T.high_run(uc, R.NAMES[name], {D.STOP}, True)
    assert fault_run['error'] is None and len(fault_run['interrupts']) == 1
    event = fault_run['interrupts'][0]
    fault = event['snapshot']
    assert event['vector'] == 14 and event['recover'] == S.TARGETS[name]
    assert fault == T.snap(uc) and fault['eip'] in S.FS
    assert fault['cr2'] == Q.BUFFER + destination
    S.buffers(uc, target, initial)
    T.guard_check(uc)
    fault_hashes = T.buffer_hashes(uc)
    caller = bytes(uc.mem_read(fault['esp'], D.STACK + 4 * D.WORD - fault['esp']))
    frame = fault['esp'] - T.FRAME_SIZE
    cpu_frame = fault['esp'] - 4 * D.WORD
    D.put(uc, cpu_frame, 3, fault['eip'], fault['cs'], fault['eflags'])
    uc.reg_write(X.UC_X86_REG_ESP, cpu_frame)
    milestones, captured = [], {}
    points = {0x187068, 0x172038, 0x178040, 0x178144, 0x178165, 0x178177,
              0x172070, 0x1921ec, 0x1924a0, 0x192213, 0x186d7c, S.TARGETS[name]}
    def checkpoint(engine, pc):
        if pc not in points:
            return
        state = T.snap(engine)
        raw = bytes(engine.mem_read(frame, T.FRAME_SIZE))
        row = {'pc': hex(pc), 'state': state, 'frame': raw.hex(),
               'map': bytes(engine.mem_read(MAP, 0x50)).hex(),
               'recover': D.words(engine, Q.THREAD + 0x74, 1)[0],
               'uthread_byte': bytes(engine.mem_read(UTHREAD + 0x68, 1)).hex()}
        if pc == 0x187068:
            assert D.words(engine, state['esp'] + D.WORD, 1) == [frame]
            expected = T.model_frame(fault, 3)
            for field, offset in T.OFFSETS.items():
                width = 2 if field in ('gs', 'fs', 'es', 'ds', 'cs') else D.WORD
                assert int.from_bytes(raw[offset:offset + width], 'little') == expected[field]
            captured['frame'] = raw
        if pc == 0x172038:
            row['arguments'] = D.words(engine, state['esp'] + D.WORD, 5)
            assert row['arguments'] == [MAP, fault['cr2'] & ~info['page_mask'], 3, 0, 0]
            assert row['uthread_byte'] == '00'
        if pc in (0x178040, 0x178144, 0x178165):
            assert int.from_bytes(engine.mem_read(MAP + 4, 2), 'little') == 1
        if pc in (0x178144, 0x178165):
            assert state['edx'] == ENTRY
        if pc == 0x178165:
            assert state['eax'] == 3 and state['ebx'] == protection
        if pc in (0x178177, 0x172070, 0x1921ec):
            assert state['eax'] == 2 and bytes(engine.mem_read(MAP, 0x50)) == map_before
        if pc == 0x1924a0:
            assert row['uthread_byte'] == 'a5'
            assert D.words(engine, state['esp'] + D.WORD, 1) == [frame + T.OFFSETS['error']]
        if pc == 0x192213:
            expected = bytearray(captured['frame'])
            for field, value, width in (('eip', S.TARGETS[name], D.WORD), ('cs', 8, 2),
                                       ('eflags', fault['eflags'] & ~0x400, D.WORD)):
                off = T.OFFSETS[field]
                expected[off:off + width] = value.to_bytes(width, 'little')
            assert raw == expected and row['recover'] == 0
        if pc == 0x186d7c:
            assert state['esp'] == fault['esp'] - 3 * D.WORD
            for field in ('eax', 'ebx', 'ecx', 'edx', 'edi', 'esi', 'ebp', 'ds', 'es', 'fs', 'gs', 'ss'):
                assert state[field] == fault[field], field
        if pc == S.TARGETS[name]:
            assert state['eflags'] == fault['eflags'] & ~0x400 and state['esp'] == fault['esp']
            assert bytes(engine.mem_read(fault['esp'], len(caller))) == caller
        milestones.append(row)
    stop = D.STOP if protection == 1 else 0x17817c
    handler = T.high_run(uc, 0x1861cc, {stop}, True, checkpoint)
    assert handler['error'] is None and not handler['interrupts'] and reg(uc, 'eip') == stop
    assert bytes(uc.mem_read(ENTRY, 0x2c)) == entry_before
    assert D.words(uc, 0x1f6514, 1)[0] == (counter + 1) & 0xffffffff
    assert reg(uc, 'cr2') == fault['cr2'] and reg(uc, 'cr3') == Q.ROOTS[target]
    S.buffers(uc, target, initial)
    T.guard_check(uc)
    trace = handler['trace']
    assert ('0x178081' in trace) == (hint == 'sentinel')
    assert ('0x1780a7' in trace) == (hint == 'sentinel')
    assert '0x178144' in trace and '0x178165' in trace and '0x178131' not in trace
    if protection == 1:
        assert reg(uc, 'eax') == 14 and reg(uc, 'esp') == D.STACK + D.WORD
        D.assert_callee_saved(uc)
        assert bytes(uc.mem_read(MAP, 0x50)) == map_before
        assert D.words(uc, Q.THREAD + 0x74, 1)[0] == 0
        assert bytes(uc.mem_read(UTHREAD + 0x68, 1)) == bytes([0xa5])
        assert reg(uc, 'eflags') & 0x600 == flags & 0x200
        assert set(points) == {int(m['pc'], 16) for m in milestones}
        assert '0x17816d' in trace and '0x186d7c' in trace and '0x172084' not in trace
        for field in ('ds', 'es', 'ss', 'fs', 'gs', 'cs', 'cr0', 'cr4'):
            assert reg(uc, field) == fault[field], field
    else:
        assert int.from_bytes(uc.mem_read(MAP + 4, 2), 'little') == 1
        wanted = bytearray(map_before)
        wanted[4:6] = (1).to_bytes(2, 'little')
        assert bytes(uc.mem_read(MAP, 0x50)) == wanted
        assert D.words(uc, Q.THREAD + 0x74, 1)[0] == S.TARGETS[name]
        assert bytes(uc.mem_read(UTHREAD + 0x68, 1)) == bytes([0])
        assert '0x17816d' not in trace and '0x186d7c' not in trace
    return {'target': target, 'function': name, 'hint': hint, 'destination': destination, 'flags': flags,
            'protection': protection, 'fixture': info, 'map_before': map_before.hex(), 'entry_before': entry_before.hex(),
            'fault': fault_run, 'fault_buffer_hashes': fault_hashes, 'cpu_frame_injected': True,
            'hardware_frame_generation_verified': False, 'milestones': milestones, 'handler': handler,
            'final_buffer_hashes': T.buffer_hashes(uc),
            'final_memory': {'map': bytes(uc.mem_read(MAP, 0x50)).hex(),
                             'entry': bytes(uc.mem_read(ENTRY, 0x2c)).hex(),
                             'uthread_byte': bytes(uc.mem_read(UTHREAD + 0x68, 1)).hex(),
                             'recover': D.words(uc, Q.THREAD + 0x74, 1)[0],
                             'fault_counter_before': counter, 'fault_counter_after': D.words(uc, 0x1f6514, 1)[0],
                             'stack_guards': {hex(addr): bytes(uc.mem_read(addr, len(value))).hex() for addr, value in T.GUARDS.items()}},
            'outcome': 'protection_failure_to_EFAULT' if protection == 1 else 'permission_gate_only',
            'checks_passed': True}


def main():
    save('preservation-before.json', preserved())
    rows = []
    for params in itertools.product(Q.ROOTS, S.TARGETS, ('entry', 'sentinel'), (0x100, 0x1100), (2, 0x602), (1, 3)):
        rows.append(case(*params))
        if len(rows) % 8 == 0:
            print('cases:', len(rows), flush=True)
    save('protection-cases.json', rows)
    summary = {'cases': len(rows), 'protection_failure_to_EFAULT': sum(r['protection'] == 1 for r in rows),
               'permission_gate_only': sum(r['protection'] == 3 for r in rows),
               'list_lookup_cases': sum(r['hint'] == 'sentinel' for r in rows),
               'native_frame_creation_verified': False, 'page_in_success_verified': False,
               'original_lock_init_executions': len(rows), 'whole_analysis_complete': False}
    save('protection-review.json', summary)
    save('preservation-after.json', preserved())
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
