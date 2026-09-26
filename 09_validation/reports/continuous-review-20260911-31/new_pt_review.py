"""Original new wired PT allocation; synthetic prerequisites are explicitly recorded.

Diagnostic-stage runner. Not a completed independent audit or full boot proof.
"""
import importlib.util
import json
from pathlib import Path
import sys
from verify_artifacts import preserved

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('pt30', HERE.parent / 'continuous-review-20260911-30/pt_lifecycle_review.py')
B = importlib.util.module_from_spec(spec)
spec.loader.exec_module(B)
N, T, Q, P, D, U, X = B.N, B.T, B.Q, B.P, B.D, B.U, B.X
reg = T.reg
KM, KE, KO, PG = B.KM, B.KE, 0x69a200, 0x683100
EZ, XZ, KVA, PTFRAME = 0x69a300, 0x69a400, 0x820000, 0xb02000
GLOBALS = {'wire_count': 0x1f7470, 'kernel_map': 0x1e8de8, 'kernel_object': 0x1f6ea0,
           'entry_zone': 0x1f6ec0, 'extension_zone': 0x1f7ab4, 'ipl': 0x1e7714}


def save(name, value):
    (HERE / name).write_text(json.dumps(value, indent=2) + '\n')


def snapshot(uc, vm):
    s = B.snapshot(uc, vm)
    s.update(kernel_object=bytes(uc.mem_read(KO, 0x58)).hex(),
             kernel_page=bytes(uc.mem_read(PG, 0x30)).hex(),
             entry_zone=bytes(uc.mem_read(EZ, 0x40)).hex(),
             extension_zone=bytes(uc.mem_read(XZ, 0x40)).hex(),
             new_pt_frame=bytes(uc.mem_read(PTFRAME, vm)).hex(),
             new_globals={k: D.words(uc, a, 1)[0] for k, a in GLOBALS.items()})
    kr = s['pt_contract']['kernel_root']
    ar = reg(uc, 'cr3')
    shared = D.words(uc, kr + (KVA >> 22) * D.WORD, 1)[0] & -Q.PAGE
    s['raw_translation'] = {hex(a): bytes(uc.mem_read(a, Q.PAGE)).hex() for a in (kr, shared)}
    s['protection_tables'] = {hex(a): bytes(uc.mem_read(a, 8 * D.WORD)).hex() for a in (0x1f7a80, 0x1f7b00)}
    s['stack_memory'] = bytes(uc.mem_read(0x70f020, 0x710004 - 0x70f020)).hex()
    s['new_walks'] = {name: [P.walk(uc, root, va + off) for off in range(0, vm, Q.PAGE)]
                      for name, root, va in [('kernel_low', kr, KVA), ('kernel_high', ar, Q.BASE + KVA),
                                             ('frame_high', ar, Q.BASE + PTFRAME), ('user', ar, Q.BUFFER)]}
    return s


def setup(target, sleepable):
    uc, info = B.common(target, False, register_backing=False)
    vm, kp, root = info['vm_size'], info['kernel_pmap'], Q.ROOTS[target]
    ranges = [(KM, 0x50), (KE, 0x2c), (KO, 0x58), (PG, 0x30), (EZ, 0x40), (XZ, 0x40),
              (N.EXTENSION, 0x20), (N.DESCRIPTORS, N.PHYS_END // vm * 20), (PTFRAME, vm)]
    for i, (a, size) in enumerate(ranges):
        assert all(a + size <= b or b + n <= a for b, n in ranges[i + 1:])
        uc.mem_write(a, bytes(size))
    uc.mem_write(PTFRAME, bytes((i * 23 + (i >> 8) + 0x79) & 0xff for i in range(vm)))
    # Supersede the inherited preexisting user PT contract; no reusable table exists.
    uc.mem_write(root, bytes((Q.BASE >> 22) * D.WORD))
    D.put(uc, N.PT_HEAD, N.PT_HEAD, N.PT_HEAD)
    D.put(uc, N.PT_COUNT, 0)
    D.put(uc, B.FREE_HEAD, B.FREE_HEAD, B.FREE_HEAD)
    D.put(uc, B.FREE_COUNT, 0)
    D.put(uc, B.ALLOC_COUNT, 0)
    D.put(uc, kp + 0x10, 0, 0)
    D.put(uc, GLOBALS['wire_count'], 0)
    # Explicit quiescent IPL7 keeps spin-zone runs out of pending IRQ/MMIO handling.
    D.put(uc, GLOBALS['ipl'], 7)
    D.put(uc, KO, KO, KO)
    D.put(uc, KO + 0x10, 1, KVA + vm)
    uc.mem_write(KO + 0x18, (1).to_bytes(2, 'little'))
    D.put(uc, N.A.GLOBALS['queue_lock'], 1)
    seeds = [N.invoke(uc, 0x17b134, [PG, KO, KVA, PTFRAME]), N.invoke(uc, 0x17b540, [PG])]
    D.put(uc, KO + 0x10, 0)
    D.put(uc, N.A.GLOBALS['queue_lock'], 0)
    D.put(uc, KM + 0xc, KM + 0xc, KM + 0xc, KVA, KVA + vm, 0, 0, kp, 0, 1)
    D.put(uc, KM + 0x38, KM + 0xc, 0, KM + 0xc)
    inits = [N.invoke(uc, 0x15b54c, [KM, 1])]
    for zone, element, size in [(EZ, KE, 0x2c), (XZ, N.EXTENSION, 0x20)]:
        D.put(uc, zone + 0xc, element, element, size, size, size, vm, 0, 0, sleepable)
        if sleepable:
            inits.append(N.invoke(uc, 0x15b54c, [zone + 0x30, 1]))
    for key, value in [('kernel_map', KM), ('kernel_object', KO), ('entry_zone', EZ), ('extension_zone', XZ)]:
        D.put(uc, GLOBALS[key], value)
    removed = []
    for off in range(0, vm, Q.PAGE):
        low = P.walk(uc, info['kernel_root'], KVA + off)
        high = P.walk(uc, root, Q.BASE + KVA + off)
        assert low['pte_address'] == high['pte_address'] and low['present'] and high['present']
        address = int(low['pte_address'], 16)
        removed.append({'kernel': low, 'active': high, 'old': D.words(uc, address, 1)[0]})
        D.put(uc, address, 0)
    uc.reg_write(X.UC_X86_REG_EAX, root)
    reload = T.high_run(uc, Q.WRITE_CR3, {Q.SWITCH_END}, True)
    assert reload['error'] is None and not reload['interrupts']
    assert reload['trace'] == [hex(Q.WRITE_CR3)]
    for off in range(0, vm, Q.PAGE):
        assert not P.walk(uc, root, Q.BASE + KVA + off)['present']
        w = P.walk(uc, root, Q.BASE + PTFRAME + off)
        assert w['present'] and w['writable'] and not w['user'] and int(w['physical'], 16) == PTFRAME + off
    assert D.words(uc, N.A.GLOBALS['free_count'], 1) == [1]
    info.update(new_seed_calls=seeds, new_lock_init=inits, replaced_kernel_aliases=removed,
                new_cr3_reload=reload, sleepable=sleepable,
                new_contract='synthetic empty main kernel map/object, preexisting free zone elements and detached free page; IPL7; not full boot ownership')
    return uc, info


def case(target, sleepable, caller):
    uc, info = setup(target, sleepable)
    vm = info['vm_size']
    entry = 0x19065c if caller else 0x190cfc
    args = [N.PMAP, Q.BUFFER, N.FRAME, 3, 0] if caller else [N.PMAP, Q.BUFFER]
    D.put(uc, N.CALL_STACK, D.STOP, *args)
    uc.reg_write(X.UC_X86_REG_ESP, N.CALL_STACK)
    for register, value in D.REGS.values():
        uc.reg_write(register, value)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    before = snapshot(uc, vm)
    points, writes, zero_chunks = [], [], []
    step = -1
    prepared_stack = D.words(uc, N.CALL_STACK, len(args) + 1)
    nargs = {0x190cfc: 2, 0x173d1c: 3, 0x174a90: 6, 0x16b790: 1, 0x16b84c: 2,
             0x176164: 3, 0x174848: 5, 0x173ebc: 4, 0x17b200: 3, 0x175b2c: 4,
             0x173898: 3, 0x17b6e8: 1, 0x19065c: 5}
    milestones = set(nargs) | {0x174bf4, 0x173f92, 0x173a11, 0x1735c3, 0x173e3a, 0x190d7b, 0x190de5, 0x190e20, 0x190f1a, 0x1907b1}
    def checkpoint(engine, pc):
        nonlocal step
        step += 1
        assert pc not in (0x10ca6c, 0x163320, 0x1631a0, 0x16b3df, 0x190e51,
                          0x18b59b, 0x18b5dc, 0x18b5ef, 0x18c12c, 0x18c174, 0x18c187), hex(pc)
        if pc == 0x1019cc:
            zero_chunks.append(dict({k: reg(engine, k) for k in ('eax', 'ecx', 'edx')}, trace_index=step))
        if pc in milestones:
            row = {'pc': hex(pc), 'cpu': T.snap(engine), 'state': snapshot(engine, vm), 'trace_index': step, 'write_cursor': len(writes)}
            if pc in nargs:
                row['args'] = D.words(engine, reg(engine, 'esp') + D.WORD, nargs[pc])
            points.append(row)
    def write(engine, access, address, width, value, unused):
        writes.append({'pc': reg(engine, 'eip'), 'address': address, 'width': width,
                       'value': value & ((1 << (width * 8)) - 1), 'trace_index': step})
    hook = uc.hook_add(U.UC_HOOK_MEM_WRITE, write)
    obs, failure = None, None
    try:
        obs = T.high_run(uc, entry, {D.STOP}, True, checkpoint)
    except Exception as exc:
        failure = repr(exc)
    finally:
        uc.hook_del(hook)
    result = {'target': target, 'sleepable': sleepable, 'caller': caller, 'setup': info,
              'entry': hex(entry), 'args': args, 'prepared_stack': prepared_stack, 'before': before, 'observation': obs,
              'points': points, 'writes': writes, 'zero_chunks': zero_chunks,
              'after': snapshot(uc, vm), 'failure': failure}
    save('latest-diagnostic.json', result)
    assert failure is None, failure
    assert obs['error'] is None and not obs['interrupts'], obs
    assert reg(uc, 'eip') == D.STOP and reg(uc, 'esp') == N.CALL_STACK + D.WORD
    D.assert_callee_saved(uc)
    T.guard_check(uc)
    assert D.words(uc, B.ALLOC_COUNT, 1) == [1] and D.words(uc, B.FREE_COUNT, 1) == [0]
    assert D.words(uc, N.PT_COUNT, 1) == [1]
    assert D.words(uc, N.EXTENSION + 8, 4) == [N.descriptor(PTFRAME, vm), PTFRAME, N.PMAP, 0]
    assert D.words(uc, N.descriptor(PTFRAME, vm), 4) == [0, info['kernel_pmap'], KVA, N.EXTENSION]
    assert D.words(uc, info['kernel_pmap'] + 0x10, 2) == [1, 1]
    assert D.words(uc, GLOBALS['wire_count'], 1) == [1]
    assert int.from_bytes(uc.mem_read(PG + 0x1c, 2), 'little') == 1
    for z in (EZ, XZ):
        assert D.words(uc, z + 8, 3) == [1, 0, 0]
    assert D.words(uc, PG + 0x14, 2) == [KO, KVA]
    assert bytes(uc.mem_read(PG + 0x1e, 3)) == bytes([0x20, 0, 4])
    assert int.from_bytes(uc.mem_read(KO + 0x18, 2), 'little') == 2
    assert int.from_bytes(uc.mem_read(KO + 0x1a, 2), 'little') == 1
    assert D.words(uc, KO + 0x10, 1) == [0]
    assert int.from_bytes(uc.mem_read(KO + 0x44, 2), 'little') == 0
    assert D.words(uc, KE + 8, 4) == [KVA, KVA + vm, KO, KVA]
    assert int.from_bytes(uc.mem_read(KE + 0x28, 2), 'little') == 1
    for off in range(0, vm, Q.PAGE):
        w = P.walk(uc, info['kernel_root'], KVA + off)
        assert w['present'] and int(w['physical'], 16) == PTFRAME + off
        assert D.words(uc, int(w['pte_address'], 16), 1)[0] & 0x200
        assert D.words(uc, Q.ROOTS[target] + off // Q.PAGE * D.WORD, 1) == [(PTFRAME + off) | 7]
    expected_pt = bytearray(vm)
    if caller:
        for off in range(0, vm, Q.PAGE):
            pos = (((Q.BUFFER + off) >> 12) % (vm // D.WORD)) * D.WORD
            expected_pt[pos:pos + D.WORD] = ((N.FRAME + off) | 7).to_bytes(D.WORD, 'little')
        assert D.words(uc, N.PMAP + 0x10, 2) == [1, 0]
    assert bytes(uc.mem_read(PTFRAME, vm)) == expected_pt
    assert before['frame'] == result['after']['frame']
    assert before['copy_buffer_hashes'] == result['after']['copy_buffer_hashes']
    return result


def main():
    save('preservation-before.json', preserved())
    cases = [case(target, sleepable, caller) for target in ('A', 'B')
             for sleepable in (1, 0) for caller in (False, True)]
    save('new-pt-cases.json', cases)
    summary = {'cases': len(cases), 'zero_dword_stores': sum(len(c['zero_chunks']) * 8 for c in cases),
               'status': 'original execution with runner assertions; independent audit and reproducibility are separate artifacts',
               'whole_goal_complete': False}
    save('new-pt-summary.json', summary)
    save('preservation-after.json', preserved())
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
