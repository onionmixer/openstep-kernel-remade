"""Original full-section aging removal; explicit synthetic inputs, no code patches."""
import json
import struct
import sys
import support as S

G = S.load('gc34_executor', S.R34 / 'pt_gc_review.py')
C, N, B, T, Q, D, U, X, reg = G.C, G.N, G.B, G.T, G.Q, G.D, G.U, G.X, G.reg
NARGS = {0x191144: 0, 0x18b964: 0, 0x18f7f8: 4, 0x178894: 1, 0x190f90: 5, 0x18b544: 1}
MILESTONES = set(NARGS) | {0x191174, 0x191260, 0x1912af, 0x1912e3, 0x1912eb, 0x1912f0,
    0x1912f6, 0x19133b, 0x19133e, 0x19139b, 0x1913bc, 0x1913c3, 0x1913db,
    0x18f95a, 0x18f95e, 0x18f96a, 0x18f96e, 0x18f9bc, 0x191040, 0x19104d, 0x191082}
FORBIDDEN = {0x10ca6c, 0x163320, 0x1631a0, 0x16b790, 0x16b84c, 0x173e90,
    0x17b540, 0x17b6e8, 0x18b59b, 0x18b5dc, 0x18b5ef, 0x191205}


def case(params, mode, reference):
    uc, prefix = C.prefix(params)
    prefix = json.loads(json.dumps(prefix))
    assert set(reference) - set(prefix) == {'points', 'zero_chunks'}
    assert all(prefix[k] == reference[k] for k in prefix)
    vm = prefix['setup']['vm_size']
    pre = G.snapshot(uc, vm)
    raw = bytearray(C.SEGCOUNT - C.SEGMENTS + D.WORD)
    shift = D.words(uc, 0x1f6ea4, 1)[0]
    for index, (page, physical) in enumerate(((N.PAGE_OBJECT, N.FRAME), (B.PG, B.PTFRAME))):
        struct.pack_into('<7I', raw, index * C.STRIDE, page, physical >> shift, 0, 0, 0, physical, physical + vm)
    struct.pack_into('<I', raw, C.SEGCOUNT - C.SEGMENTS, 2)
    age = 6 if mode == 'equal' else 7
    root = Q.ROOTS[params[0]]
    changes = [(C.SEGMENTS, bytes(raw)), (0x1f653c, struct.pack('<I', 3)),
               (0x1e773c, struct.pack('<I', 1)),
               (0x1f7aa0, struct.pack('<4I', 0, 0, G.PD_HEAD, G.PD_HEAD)),
               (N.EXTENSION + 0x1d, bytes([age]))]
    if mode == 'accessed':
        changes.append((root, bytes([uc.mem_read(root, 1)[0] | 0x20])))
    changes.append((N.CALL_STACK, struct.pack('<I', D.STOP)))
    for address, value in changes:
        uc.mem_write(address, value)
    uc.reg_write(X.UC_X86_REG_ESP, N.CALL_STACK)
    for register, value in D.REGS.values():
        uc.reg_write(register, value)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    before = G.snapshot(uc, vm)
    heads, writes, points, scans = [], [], [], []
    def checkpoint(engine, pc):
        index = len(heads)
        heads.append(pc)
        assert pc not in FORBIDDEN, ('unexpected original path', hex(pc))
        if pc == 0x18f8b4:
            edi = reg(engine, 'edi')
            scans.append({'trace_index': index, 'cpu': T.snap(engine),
                'local_va': D.words(engine, reg(engine, 'ebp') - 0xc, 1)[0],
                'ptes': bytes(engine.mem_read(edi, 8)).hex()})
        if pc in MILESTONES:
            row = {'pc': hex(pc), 'trace_index': index, 'write_cursor': len(writes),
                   'cpu': T.snap(engine), 'state': G.snapshot(engine, vm)}
            if pc in NARGS:
                row['args'] = D.words(engine, reg(engine, 'esp') + D.WORD, NARGS[pc])
            points.append(row)
    def write(engine, access, address, width, value, unused):
        writes.append({'pc': reg(engine, 'eip'), 'trace_index': len(heads) - 1,
                       'address': address, 'width': width, 'value': value & ((1 << (8 * width)) - 1)})
    hook = uc.hook_add(U.UC_HOOK_MEM_WRITE, write)
    observation, failure = None, None
    try:
        observation = T.high_run(uc, 0x191144, {D.STOP}, True, checkpoint)
    except Exception as exc:
        failure = repr(exc)
    finally:
        uc.hook_del(hook)
    row = {'params': list(params), 'mode': mode,
        'prefix32': {'keys': sorted(prefix), 'canonical_sha256': S.canonical(prefix),
                     'omitted_uncollected_fields': ['points', 'zero_chunks']},
        'pre_input': pre, 'input': {'memory_changes': [[a, v.hex()] for a, v in changes],
                                  'last': 1, 'tick': 3, 'age': age, 'eflags': 2},
        'before': before, 'observation': observation, 'recorded_heads': list(map(hex, heads)),
        'points': points, 'scans': scans, 'writes': writes, 'after': G.snapshot(uc, vm),
        'failure': failure, 'native_cpu_verified': False, 'whole_ownership_verified': False}
    S.save('latest-diagnostic.json', row)
    assert failure is None, failure
    assert observation['error'] is None and not observation['interrupts']
    assert observation['trace'] == row['recorded_heads']
    assert reg(uc, 'eip') == D.STOP and reg(uc, 'esp') == N.CALL_STACK + D.WORD
    D.assert_callee_saved(uc)
    T.guard_check(uc)
    return row


def main():
    preservation = S.preserve()
    refs = S.references()
    smoke = '--smoke' in sys.argv
    rows = []
    for params, mode in S.matrix(smoke):
        rows.append(case(params, mode, refs[params]))
        print(json.dumps({'case': len(rows), 'params': params, 'mode': mode,
                          'heads': len(rows[-1]['recorded_heads'])}), flush=True)
    stem = 'smoke' if smoke else 'removal'
    S.save(stem + '-cases.json', rows)
    S.save(stem + '-summary.json', {'cases': len(rows), 'heads': sum(len(r['recorded_heads']) for r in rows),
        'writes': sum(len(r['writes']) for r in rows), 'scanned_bundles': sum(len(r['scans']) for r in rows),
        'remove_calls': sum(r['recorded_heads'].count('0x18f7f8') for r in rows),
        'status': 'execution records only; independent audit separate', 'whole_goal_complete': False})
    assert S.preserve() == preservation
    S.save('preservation.json', preservation)


if __name__ == '__main__':
    main()
