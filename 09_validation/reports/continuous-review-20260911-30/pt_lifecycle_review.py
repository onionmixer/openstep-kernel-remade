"""Original PT retirement/reuse and real virtual-space exhaustion, no call mocks."""
import importlib.util
import itertools
import json
from pathlib import Path
import sys
from verify_artifacts import preserved

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('missing29', HERE.parent / 'continuous-review-20260911-29/missing_page_review.py')
N = importlib.util.module_from_spec(spec)
spec.loader.exec_module(N)
T, Q, P, D, U, X, F = N.T, N.Q, N.P, N.D, N.U, N.X, N.F
reg = T.reg
KM, KE = 0x69a000, 0x69a100
FREE_HEAD, FREE_COUNT, ALLOC_COUNT = 0x1f7ad8, 0x1f7ad4, 0x1f7ad0
VAS = (0x600000, 0xa00000)


def save(name, data):
    (HERE / name).write_text(json.dumps(data, indent=2) + '\n')


def snapshot(uc, vm):
    result = N.snapshot(uc, vm)
    kp = D.words(uc, 0x1f63f0, 1)[0]
    result.update(kernel_pmap=bytes(uc.mem_read(kp, 0x1c)).hex(),
                  kernel_map=bytes(uc.mem_read(KM, 0x50)).hex(), kernel_entry=bytes(uc.mem_read(KE, 0x2c)).hex(),
                  pt_free_queue=D.words(uc, FREE_HEAD, 2), pt_free_count=D.words(uc, FREE_COUNT, 1)[0],
                  pt_alloc_count=D.words(uc, ALLOC_COUNT, 1)[0],
                  tlb_counters=D.words(uc, 0x1f7af0, 2),
                  pt_contract={'kernel_map': D.words(uc, 0x1e8de8, 1)[0], 'kernel_object': D.words(uc, 0x1f6ea0, 1)[0],
                               'kernel_pmap_address': kp, 'kernel_root': D.words(uc, kp, 1)[0]})
    return result


def call(uc, vm, label, entry, args, repeat_boundary=False, probe_va=None):
    D.put(uc, N.CALL_STACK, D.STOP, *args)
    uc.reg_write(X.UC_X86_REG_ESP, N.CALL_STACK)
    for register, value in D.REGS.values():
        uc.reg_write(register, value)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    if probe_va is not None:
        uc.reg_write(X.UC_X86_REG_EAX, probe_va)
    before = snapshot(uc, vm)
    prepared_stack = D.words(uc, N.CALL_STACK, len(args) + 1)
    writes, points, invalidations, expand_visits = [], [], [], []
    point_set = {0x190cfc, 0x190d4d, 0x190d7b, 0x190e20, 0x190f1a, 0x1907b1, 0x173d60,
                 0x173d88, 0x174bf4, 0x190a45, 0x173d1c, 0x174a90, 0x190f90}
    stop = Q.decoded(entry).address + Q.decoded(entry).size if probe_va is not None else D.STOP
    def checkpoint(engine, pc):
        assert pc not in (0x10ca6c, 0x16b790, 0x178894, 0x173ebc, 0x163320, 0x1631a0, 0x18b59b, 0x18b5dc, 0x18b5ef), hex(pc)
        if pc == 0x190cfc:
            expand_visits.append({'pc': hex(pc), 'cpu': T.snap(engine), 'pde': D.words(engine, Q.ROOTS[active_target] + ((args[1] >> 22) * 4), 1)[0]})
            if repeat_boundary and len(expand_visits) == 3:
                engine.emu_stop()
        if pc == 0x18faac:
            invalidations.append(reg(engine, 'edx'))
        if pc in point_set:
            row = {'pc': hex(pc), 'cpu': T.snap(engine), 'state': snapshot(engine, vm)}
            if pc in (0x190cfc, 0x173d1c, 0x174a90, 0x190f90):
                row['args'] = D.words(engine, reg(engine, 'esp') + 4, {0x190cfc: 2, 0x173d1c: 3, 0x174a90: 6, 0x190f90: 5}[pc])
            points.append(row)
    def write(engine, access, address, width, value, unused):
        writes.append({'pc': reg(engine, 'eip'), 'address': address, 'width': width, 'value': value & ((1 << (width * 8)) - 1)})
    active_target = next(t for t, root in Q.ROOTS.items() if root == reg(uc, 'cr3'))
    hook = uc.hook_add(U.UC_HOOK_MEM_WRITE, write)
    obs, failure = None, None
    try:
        obs = T.high_run(uc, entry, {stop}, True, checkpoint)
    except Exception as exc:
        failure = repr(exc)
    finally:
        uc.hook_del(hook)
    result = {'label': label, 'entry': hex(entry), 'args': args, 'probe_va': probe_va,
              'prepared_stack': prepared_stack,
              'repeat_boundary': repeat_boundary, 'stop': hex(stop), 'before': before, 'observation': obs,
              'writes': writes, 'points': points, 'invalidations': invalidations, 'expand_visits': expand_visits,
              'after': snapshot(uc, vm), 'failure': failure}
    save('latest-diagnostic.json', result)
    assert failure is None, failure
    assert obs['error'] is None and not obs['interrupts'], obs
    if repeat_boundary:
        assert len(expand_visits) == 3 and reg(uc, 'eip') == 0x190cfc
    else:
        assert reg(uc, 'eip') == stop
        assert reg(uc, 'esp') == N.CALL_STACK + (0 if probe_va is not None else 4)
        D.assert_callee_saved(uc)
    T.guard_check(uc)
    assert result['before']['frame'] == result['after']['frame']
    assert result['before']['copy_buffer_hashes'] == result['after']['copy_buffer_hashes']
    return result


def common(target, residue, register_backing=True):
    uc, info = N.setup(target, '_copyout', 0x100, 2)
    vm = info['vm_size']
    # Allocate the data frame from its original free list before exposing it via pmap.
    D.put(uc, N.OBJECT + 0x10, 1)
    allocation = N.invoke(uc, 0x17b200, [N.OBJECT, info['object_offset'], 1])
    assert reg(uc, 'eax') == N.PAGE_OBJECT
    D.put(uc, N.OBJECT + 0x10, 0)
    kp = D.words(uc, 0x1f63f0, 1)[0]
    kernel_root = D.words(uc, kp, 1)[0]
    # Explicit preexisting wired PT backing contract, not whole kernel-pmap ownership.
    pt_desc = N.descriptor(N.PT_PAIR, vm)
    backing = []
    if register_backing:
        D.put(uc, pt_desc, 0, kp, N.PT_PAIR, N.EXTENSION)
        D.put(uc, kp + 0x10, 1, 1)
        for off in range(0, vm, Q.PAGE):
            w = P.walk(uc, kernel_root, N.PT_PAIR + off)
            assert w['present'] and int(w['physical'], 16) == N.PT_PAIR + off
            pte_addr = int(w['pte_address'], 16)
            D.put(uc, pte_addr, D.words(uc, pte_addr, 1)[0] | 0x200)
            backing.append(P.walk(uc, kernel_root, N.PT_PAIR + off))
    D.put(uc, FREE_HEAD, FREE_HEAD, FREE_HEAD)
    D.put(uc, FREE_COUNT, 0)
    D.put(uc, ALLOC_COUNT, 1)
    if residue:
        D.put(uc, N.PT_PAIR, 0xdeadbe00)
    info.update(data_allocation=allocation, kernel_pt_backing=backing, kernel_pmap=kp, kernel_root=kernel_root,
                residue=residue, register_backing=register_backing,
                kernel_ownership_scope='synthetic preexisting one wired PT mapping; bootstrap aliases not full accounted' if register_backing
                else 'no registered PT backing in final exhaustion input; initial N29 PT setup is superseded')
    return uc, info


def lifecycle(target, wired, residue):
    uc, info = common(target, residue)
    vm = info['vm_size']
    operations = [call(uc, vm, 'retire_empty', 0x190f90, [N.PMAP, VAS[0], 0, 0, 1])]
    for index, va in enumerate(VAS):
        assert all(not p & 1 for p in D.words(uc, N.PT_PAIR, vm // 4))
        assert D.words(uc, FREE_HEAD, 2) == [N.EXTENSION, N.EXTENSION]
        op = call(uc, vm, 'enter', 0x19065c, [N.PMAP, va, N.FRAME, 3, wired])
        operations.append(op)
        assert len(op['expand_visits']) == 1
        assert D.words(uc, FREE_HEAD, 2) == [FREE_HEAD, FREE_HEAD]
        assert D.words(uc, N.PMAP + 0x10, 2) == [1, wired]
        assert int.from_bytes(uc.mem_read(N.EXTENSION + 0x18, 2), 'little') == 1
        assert int.from_bytes(uc.mem_read(N.EXTENSION + 0x1a, 2), 'little') == wired
        assert D.words(uc, N.EXTENSION + 0x10, 2) == [N.PMAP, va & -D.words(uc, 0x1f7ae8, 1)[0]]
        probe = call(uc, vm, 'fs_read', 0x18a197, [], probe_va=va + 0x100)
        assert probe['after']['cpu']['edx'] == int.from_bytes(uc.mem_read(N.FRAME + 0x100, 4), 'little')
        operations.append(probe)
        section = va & -D.words(uc, 0x1f7ae8, 1)[0]
        skipped = call(uc, vm, 'remove_nonpresent', 0x18fa44, [N.PMAP, section, section + vm])
        operations.append(skipped)
        assert '0x18f8b9' in skipped['observation']['trace'] and '0x18f8d0' not in skipped['observation']['trace']
        assert [p['args'] for p in skipped['points'] if p['pc'] == '0x190f90'] == [[N.PMAP, section, 0, 0, 1]]
        assert D.words(uc, N.PMAP + 0x10, 2) == [1, wired]
        assert D.words(uc, N.PT_PAIR, 1) == [0xdeadbe00 if residue else 0]
        op = call(uc, vm, 'remove', 0x18fa44, [N.PMAP, va, va + vm])
        operations.append(op)
        assert op['invalidations'] == [va + off for off in range(0, vm, Q.PAGE)]
        assert D.words(uc, N.PMAP + 0x10, 2) == [0, 0]
        assert D.words(uc, N.descriptor(N.FRAME, vm) + 4, 1) == [0]
        assert D.words(uc, FREE_HEAD, 2) == [N.EXTENSION, N.EXTENSION]
        assert D.words(uc, N.PT_HEAD, 2) == [N.PT_HEAD, N.PT_HEAD]
        assert all(not p & 1 for p in D.words(uc, N.PT_PAIR, vm // 4))
        assert D.words(uc, N.PT_PAIR, 1) == [0xdeadbe00 if residue else 0]
    return {'kind': 'reuse_cycle', 'target': target, 'wired': wired, 'residue': residue,
            'fixture': info, 'operations': operations, 'checks_passed': True}


def exhausted(target, entry_kind):
    uc, info = common(target, False, register_backing=False)
    vm, root = info['vm_size'], Q.ROOTS[target]
    # Separate synthetic start: no registered PT resources; not a fake GC execution.
    uc.mem_write(root, bytes((Q.BASE >> 22) * 4))
    uc.mem_write(N.DESCRIPTORS, bytes(N.PHYS_END // vm * 20))
    uc.mem_write(N.EXTENSION, bytes(0x20))
    D.put(uc, N.PT_HEAD, N.PT_HEAD, N.PT_HEAD)
    D.put(uc, N.PT_COUNT, 0)
    D.put(uc, ALLOC_COUNT, 0)
    uc.mem_write(KM, bytes(0x50))
    uc.mem_write(KE, bytes(0x2c))
    sentinel, lo, hi = KM + 0xc, 0x820000, 0x820000 + vm
    D.put(uc, sentinel, KE, KE, lo, hi, 1)
    D.put(uc, KE, sentinel, sentinel, lo, hi)
    D.put(uc, KM + 0x28, vm)
    D.put(uc, KM + 0x38, KE, 0, KE)
    init = N.invoke(uc, 0x15b54c, [KM, 1])
    D.put(uc, 0x1e8de8, KM)
    D.put(uc, 0x1f6ea0, N.OBJECT)
    uc.reg_write(X.UC_X86_REG_EAX, root)
    flush = T.high_run(uc, Q.WRITE_CR3, {Q.SWITCH_END}, True)
    assert flush['error'] is None and not flush['interrupts']
    info.update(exhausted_kernel_map={'address': KM, 'entry': KE, 'range': [lo, hi], 'init': init,
                                      'scope': 'valid occupied interval; no attempt to model physical-page shortage'}, final_pre_call_flush=flush)
    if entry_kind == 'expand':
        op = call(uc, vm, 'new_va_failure', 0x190cfc, [N.PMAP, VAS[0]])
        assert len(op['expand_visits']) == 1
    else:
        op = call(uc, vm, 'caller_rechecks_failure', 0x19065c, [N.PMAP, VAS[0], N.FRAME, 3, 0], repeat_boundary=True)
    assert not P.walk(uc, root, VAS[0])['present']
    # Hardware may set Accessed on shared kernel PDEs during the call.
    for name in Q.ROOTS:
        before_words = bytes.fromhex(op['before']['roots'][name])
        after_words = bytes.fromhex(op['after']['roots'][name])
        for off in range(0, Q.PAGE, 4):
            old = int.from_bytes(before_words[off:off + 4], 'little')
            new = int.from_bytes(after_words[off:off + 4], 'little')
            assert new == old or (name == target and off >= (Q.BASE >> 22) * 4 and new == old | 0x20)
    assert op['before']['pmap'] == op['after']['pmap']
    assert op['before']['descriptor_arena'] == op['after']['descriptor_arena']
    assert op['before']['extension'] == op['after']['extension']
    assert op['after']['pt_alloc_count'] == op['after']['pt_free_count'] == 0
    return {'kind': 'new_va_failure', 'target': target, 'entry_kind': entry_kind, 'fixture': info,
            'operations': [op], 'checks_passed': True, 'caller_return_verified': entry_kind == 'expand'}


def main():
    save('preservation-before.json', preserved())
    rows = []
    matrix = [('A', 0, True)] if '--single' in sys.argv else itertools.product(Q.ROOTS, (0, 1), (False, True))
    for params in matrix:
        rows.append(lifecycle(*params))
        print(json.dumps({'case': len(rows), 'reuse': params}), flush=True)
    for params in itertools.product(Q.ROOTS, ('expand', 'pmap_enter')):
        rows.append(exhausted(*params))
        print(json.dumps({'case': len(rows), 'exhausted': params}), flush=True)
    save('pt-cases.json', rows)
    writes = [w for r in rows for op in r['operations'] for w in op['writes']]
    summary = {'fresh_cases': len(rows), 'reuse_cases': sum(r['kind'] == 'reuse_cycle' for r in rows),
               'new_va_failure_cases': sum(r['kind'] == 'new_va_failure' for r in rows),
               'original_pde_installs': sum(w['pc'] == 0x190ef4 for w in writes),
               'original_pte_installs': sum(w['pc'] == 0x190aa7 for w in writes),
               'original_pte_clears': sum(w['pc'] == 0x18f96e for w in writes),
               'original_pde_invalidations': sum(w['pc'] == 0x191040 for w in writes),
               'new_wired_allocation_success_verified': False, 'whole_pt_ownership_verified': False}
    save('pt-summary.json', summary)
    save('preservation-after.json', preserved())


if __name__ == '__main__':
    main()
