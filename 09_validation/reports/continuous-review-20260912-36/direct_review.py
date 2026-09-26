"""Supplemental original pmap_enter after actual GC; NOT fault reentry completion."""
import itertools
import json
from pathlib import Path
import sys
import gc_prefix as G
from check_helper import check
from verify_artifacts import preserved

HERE = Path(__file__).resolve().parent
N, B, T, Q, P, D, U, X, reg = G.N, G.B, G.T, G.Q, G.P, G.D, G.U, G.X, G.reg
NARGS = {0x19065c: 5, 0x190cfc: 2, 0x173d1c: 3, 0x174a90: 6,
         0x16b790: 1, 0x16b84c: 2, 0x176164: 3, 0x174848: 5, 0x173ebc: 4,
         0x17b200: 3, 0x175b2c: 4, 0x173898: 3, 0x17b6e8: 1}
MILESTONES = set(NARGS) | {0x174bf4, 0x173f04, 0x173f92, 0x173a11, 0x1735c3,
    0x173e3a, 0x190d7b, 0x190d9b, 0x190de5, 0x190e20, 0x190f1a, 0x1907b1,
    0x190788, 0x1909d5, 0x1909ed, 0x190aa7, 0x190ef4, 0x190af0, 0x16b3c1, 0x174933}


def save(name, value):
    (HERE / name).write_text(json.dumps(value, indent=2) + '\n')


def references():
    refs = {}
    for number, directory, filename in ((32, 'continuous-review-20260911-32', 'fault-new-pt-cases.json'),
        (33, 'continuous-review-20260911-33', 'dirty-remove-cases.json'),
        (34, 'continuous-review-20260912-34', 'gc-cases.json')):
        data = json.loads((HERE.parent / directory / filename).read_text())
        refs[number] = {tuple(r[k] for k in ('target', 'function', 'destination', 'flags', 'sleepable'))
                        if number == 32 else tuple(r['params']): r
                        for r in data if number != 34 or (r['last'], r['tick']) == (1, 3)}
    return refs


def case(params, refs):
    uc, fresh = G.case(params, 1, 3, refs[32][params], refs[33][params])
    fresh = json.loads(json.dumps(fresh))
    assert fresh == refs[34][params]
    vm = refs[32][params]['setup']['vm_size']
    pre = G.snapshot(uc, vm)
    assert pre == fresh['after']
    args = [N.PMAP, Q.BUFFER, N.FRAME, 3, 0]
    words = [D.STOP] + args
    D.put(uc, N.CALL_STACK, *words)
    uc.reg_write(X.UC_X86_REG_ESP, N.CALL_STACK)
    for register, value in D.REGS.values():
        uc.reg_write(register, value)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    before = G.snapshot(uc, vm)
    heads, writes, points, zeros = [], [], [], []
    def checkpoint(engine, pc):
        index = len(heads)
        heads.append(pc)
        assert pc not in (0x10ca6c, 0x163320, 0x1631a0, 0x16b3df, 0x190e51,
            0x172038, 0x17390e, 0x18b59b, 0x18b5dc, 0x18b5ef,
            0x18c12c, 0x18c174, 0x18c187), hex(pc)
        if pc == 0x1019cc:
            zeros.append(dict({k: reg(engine, k) for k in ('eax', 'ecx', 'edx')}, trace_index=index))
        if pc in MILESTONES:
            row = dict(pc=hex(pc), trace_index=index, write_cursor=len(writes),
                       cpu=T.snap(engine), state=G.snapshot(engine, vm))
            if pc in NARGS:
                row['args'] = D.words(engine, reg(engine, 'esp') + D.WORD, NARGS[pc])
            points.append(row)
    def write(engine, access, address, width, value, unused):
        writes.append(dict(pc=reg(engine, 'eip'), trace_index=len(heads) - 1,
            address=address, width=width, value=value & ((1 << (width * 8)) - 1)))
    hook = uc.hook_add(U.UC_HOOK_MEM_WRITE, write)
    observation, failure = None, None
    try:
        observation = T.high_run(uc, 0x19065c, {D.STOP}, True, checkpoint)
    except Exception as error:
        failure = repr(error)
    finally:
        uc.hook_del(hook)
    row = dict(params=list(params), prefix34_canonical_sha256=G.canonical(fresh),
        prefix_scope='producer full-row equality; independent direct audit starts at caller input',
        pre_input=pre, input={'call_stack': N.CALL_STACK, 'words': words, 'eflags': 2},
        before=before, observation=observation, failure=failure, points=points, writes=writes,
        recorded_heads=list(map(hex, heads)), zero_chunks=zeros, after=G.snapshot(uc, vm),
        actual_fault_reentry_verified=False, native_exception_verified=False, whole_ownership_verified=False)
    save('direct-latest.json', row)
    assert failure is None, failure
    assert observation['error'] is None and not observation['interrupts']
    assert observation['trace'] == row['recorded_heads']
    assert reg(uc, 'eip') == D.STOP and reg(uc, 'esp') == N.CALL_STACK + D.WORD
    D.assert_callee_saved(uc)
    T.guard_check(uc)
    for field in ('frame', 'page', 'object', 'copy_buffer_hashes'):
        assert row['after'][field] == before[field], field
    assert [p['args'] for p in points if p['pc'] == '0x17b200'] == [[B.KO, B.KVA, 1]]
    assert next(p for p in points if p['pc'] == '0x173f04')['cpu']['eax'] == B.PG
    assert next(p for p in points if p['pc'] == '0x190d9b')['cpu']['eax'] == N.EXTENSION
    assert D.words(uc, N.A.GLOBALS['free_count'], 1) == [0]
    assert D.words(uc, N.A.GLOBALS['active_count'], 1) == [1]
    assert D.words(uc, B.GLOBALS['wire_count'], 1) == [1]
    assert row['after']['globals']['fault_count'] == before['globals']['fault_count'] + 1
    assert row['after']['globals']['zero_count'] == before['globals']['zero_count']
    return row


def main():
    check()
    old = preserved()
    refs = references()
    plan = [('A', '_copyout', 0x100, 2, 1)] if '--single' in sys.argv else itertools.product(
        Q.ROOTS, N.S.TARGETS, (0x100, 0x1100), (2, 0x602), (1, 0))
    rows = []
    for params in plan:
        rows.append(case(params, refs))
        print(json.dumps({'direct_case': len(rows), 'params': params}), flush=True)
    save('direct-cases.json', rows)
    assert preserved() == old
    save('direct-run-summary.json', {'cases': len(rows), 'preservation': old,
        'status': 'runner assertions only; supplemental direct boundary, not actual fault reentry',
        'actual_fault_reentry_verified': False, 'whole_goal_complete': False})


if __name__ == '__main__':
    main()
