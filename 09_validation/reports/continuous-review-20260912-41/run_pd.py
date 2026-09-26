"""Original pmap_create/destroy/update on actual newly allocated PD backing.

Legacy snapshot's new_pt_frame names a physical storage region, not its PD role.
"""
import json
import struct
import sys
import support as S

B = S.load('pd_setup31', S.R31 / 'new_pt_review.py')
N, T, Q, P, D, U, X, reg = B.N, B.T, B.Q, B.P, B.D, B.U, B.X, B.reg
NARGS = {0x15b54c: 2, 0x18f644: 1, 0x18f58c: 1, 0x18f40c: 1, 0x18f69c: 1,
         0x191144: 0, 0x173d1c: 3, 0x16b790: 1, 0x16b84c: 2, 0x173e90: 3,
         0x178894: 1, 0x18fb0c: 1, 0x17b540: 1, 0x190f90: 5}
MILESTONES = set(NARGS) | {0x18f429, 0x18f442, 0x18f461, 0x18f476, 0x18f484,
    0x18f4b4, 0x18f511, 0x18f54e, 0x18f57d, 0x18f60d, 0x18f684,
    0x18f756, 0x18f764, 0x18f786, 0x18f797, 0x1911fe, 0x191205,
    0x191220, 0x191234, 0x19124b, 0x19125c, 0x1913db,
    0x173f04, 0x173f92, 0x18fcbe, 0x18fcc5, 0x18fcd4, 0x18fcd8, 0x17b5ee}


def snapshot(uc, vm):
    result = B.snapshot(uc, vm)
    result['pd_regions'] = {hex(a): bytes(uc.mem_read(a, n)).hex() for a, n in S.EXTRA.items()}
    return result


def invoke(uc, vm, label, entry, args, tick=None):
    pre = snapshot(uc, vm)
    changes = [(N.CALL_STACK, struct.pack('<' + 'I' * (len(args) + 1), D.STOP, *args))]
    if tick is not None:
        changes.append((0x1f653c, struct.pack('<I', tick)))
    for address, value in changes:
        uc.mem_write(address, value)
    uc.reg_write(X.UC_X86_REG_ESP, N.CALL_STACK)
    for register, value in D.REGS.values():
        uc.reg_write(register, value)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    before = snapshot(uc, vm)
    heads, writes, points, copies = [], [], [], []
    def checkpoint(engine, pc):
        index = len(heads)
        heads.append(pc)
        assert pc not in (0x10ca6c, 0x163320, 0x1631a0, 0x16b3df,
                          0x18b59b, 0x18b5dc, 0x18b5ef, 0x19129f), ('unexpected path', hex(pc))
        if pc == 0x18f62e:
            cpu = T.snap(engine)
            copies.append({'trace_index': index, 'cpu': cpu,
                'source_value': D.words(engine, cpu['eax'], 1)[0],
                'destination_walk': P.walk(engine, cpu['cr3'], Q.BASE + cpu['edx'])})
        if pc in MILESTONES:
            item = {'pc': hex(pc), 'trace_index': index, 'write_cursor': len(writes),
                    'cpu': T.snap(engine), 'state': snapshot(engine, vm)}
            if pc in NARGS:
                item['args'] = D.words(engine, reg(engine, 'esp') + D.WORD, NARGS[pc])
            points.append(item)
    def write(engine, access, address, width, value, unused):
        writes.append({'pc': reg(engine, 'eip'), 'trace_index': len(heads) - 1,
                       'address': address, 'width': width, 'value': value & ((1 << (width * 8)) - 1)})
    hook = uc.hook_add(U.UC_HOOK_MEM_WRITE, write)
    observation, failure = None, None
    try:
        observation = T.high_run(uc, entry, {D.STOP}, True, checkpoint)
    except Exception as exc:
        failure = repr(exc)
    finally:
        uc.hook_del(hook)
    result = {'label': label, 'entry': entry, 'args': args, 'tick': tick, 'pre_input': pre,
        'input': {'memory_changes': [[a, raw.hex()] for a, raw in changes], 'eflags': 2},
        'before': before, 'after': snapshot(uc, vm), 'observation': observation, 'failure': failure,
        'recorded_heads': list(map(hex, heads)), 'writes': writes, 'points': points, 'copies': copies}
    S.save('latest-stage.json', result)
    assert failure is None, failure
    assert observation['error'] is None and not observation['interrupts']
    assert observation['trace'] == result['recorded_heads']
    assert reg(uc, 'eip') == D.STOP and reg(uc, 'esp') == N.CALL_STACK + D.WORD
    assert reg(uc, 'cr3') in Q.ROOTS.values()
    D.assert_callee_saved(uc)
    T.guard_check(uc)
    return result


def case(target, sleepable, first_destroy, reference):
    uc, setup = B.setup(target, sleepable)
    vm = setup['vm_size']
    D.put(uc, N.CALL_STACK, D.STOP, N.PMAP, Q.BUFFER)
    uc.reg_write(X.UC_X86_REG_ESP, N.CALL_STACK)
    for register, value in D.REGS.values():
        uc.reg_write(register, value)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    setup = json.loads(json.dumps(setup))
    fresh_before = B.snapshot(uc, vm)
    assert setup == reference['setup']
    assert fresh_before == reference['before']
    pre = snapshot(uc, vm)
    # Validate new pmap-zone storage against every prior captured physical region.
    auditor = S.load('pd_layout31', S.R31 / 'audit_results.py')
    prior_regions = auditor.regions(reference['before'])
    additions = [(S.ZONE, 0x40)] + [(p, 0x1c) for p in S.PMAPS]
    for a, n in additions:
        assert all(a + n <= b or b + len(raw) <= a for b, raw in prior_regions.items()), hex(a)
    for i, (a, n) in enumerate(additions):
        assert all(a + n <= b or b + m <= a for b, m in additions[i + 1:])
    zone = bytearray(0x40)
    # +0xc is last_insert hint, +0x10 is the free-elements head (not head/tail).
    struct.pack_into('<9I', zone, 0xc, S.PMAPS[1], S.PMAPS[0], len(S.PMAPS) * 0x1c,
                     len(S.PMAPS) * 0x1c, 0x1c, vm, 0, 0, sleepable)
    pmap0 = struct.pack('<7I', S.PMAPS[1], 0, 0, 0, 0, 0, 0)
    segments = bytearray(0x3c)
    shift = D.words(uc, 0x1f6ea4, 1)[0]
    for i, (page, phys) in enumerate(((N.PAGE_OBJECT, N.FRAME), (B.PG, B.PTFRAME))):
        struct.pack_into('<7I', segments, i * 0x1c, page, phys >> shift, 0, 0, 0, phys, phys + vm)
    struct.pack_into('<I', segments, 0x38, 2)
    changes = [(S.ZONE, bytes(zone)), (S.PMAPS[0], pmap0), (S.PMAPS[1], bytes(0x1c)),
               (0x1f7abc, struct.pack('<I', S.ZONE)),
               (0x1f7aa0, struct.pack('<4I', 0, 0, S.PD_HEAD, S.PD_HEAD)),
               (0x1e773c, struct.pack('<I', 1)), (0x1f653c, struct.pack('<I', 1)),
               (0x1f6e60, bytes(segments))]
    for a, raw in changes:
        uc.mem_write(a, raw)
    seeded = snapshot(uc, vm)
    stages = []
    if sleepable:
        stages.append(invoke(uc, vm, 'pmap_zone_lock_init', 0x15b54c, [S.ZONE + 0x30, 1]))
    sequence = [('create_slot0', 0x18f644, [0], None),
                ('gc_partial_first', 0x191144, [], 3),
                ('create_slot1', 0x18f644, [0], None),
                ('destroy_first', 0x18f69c, [S.PMAPS[first_destroy]], None),
                ('gc_partial_remaining', 0x191144, [], 5),
                ('destroy_last', 0x18f69c, [S.PMAPS[1 - first_destroy]], None),
                ('gc_empty', 0x191144, [], 7)]
    for label, entry, args, tick in sequence:
        stages.append(invoke(uc, vm, label, entry, args, tick))
    result = {'params': [target, sleepable, first_destroy],
        'prefix31': {'setup_sha256': S.canonical(setup), 'before_sha256': S.canonical(fresh_before),
                     'scope': 'fresh setup and pre-allocation boundary exact equality'},
        'pre_input': pre, 'input': [[a, raw.hex()] for a, raw in changes], 'seeded': seeded,
        'stages': stages, 'native_cpu_verified': False, 'whole_ownership_verified': False,
        'backing_role': 'PD allocated by original pmap_create, not an allocated PT relabeled as PD'}
    S.save('latest-case.json', result)
    return result


def main():
    preservation = S.preserve()
    refs, rows = S.references(), []
    smoke = '--smoke' in sys.argv
    for target, sleepable, first_destroy in S.matrix(smoke):
        rows.append(case(target, sleepable, first_destroy, refs[target, sleepable]))
        print(json.dumps({'case': len(rows), 'params': rows[-1]['params'], 'stages': len(rows[-1]['stages'])}), flush=True)
    stem = 'smoke' if smoke else 'pd'
    S.save(stem + '-cases.json', rows)
    stages = [s for r in rows for s in r['stages']]
    S.save(stem + '-summary.json', {'cases': len(rows), 'stages': len(stages),
        'heads': sum(len(s['recorded_heads']) for s in stages), 'writes': sum(len(s['writes']) for s in stages),
        'kernel_PDE_copies': sum(len(s['copies']) for s in stages),
        'status': 'execution records only, independent lifecycle audit not yet complete', 'whole_goal_complete': False})
    assert S.preserve() == preservation
    S.save('preservation.json', preservation)


if __name__ == '__main__':
    main()
