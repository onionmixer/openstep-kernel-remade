"""Original pmap_update GC from a freshly reproduced report33 live CPU state.

Prefix compact record relies on the producer's full equality check. Independent GC
audit starts at the recorded explicit-input boundary, not the prefix's hidden CPU steps.
"""
import hashlib
import itertools
import json
from pathlib import Path
import struct
import sys
import dirty_prefix as C
from check_helper import check as check_helper
from verify_artifacts import preserved

HERE = Path(__file__).resolve().parent
N, B, T, Q, P, D, U, X, reg = C.N, C.B, C.T, C.Q, C.P, C.D, C.U, C.X, C.reg
GC_REGIONS = {0x1f653c: 4, 0x1e773c: 4, 0x1f7aa0: 0x10, 0x1e25fc: 0x1e2618 - 0x1e25fc, 0x1dfd78: 4}
PD_HEAD = 0x1f7aa8


def save(name, value):
    (HERE / name).write_text(json.dumps(value, indent=2) + '\n')


def canonical(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(',', ':')).encode()).hexdigest()


def snapshot(uc, vm):
    s = C.snapshot(uc, vm)
    s['gc_regions'] = {hex(a): bytes(uc.mem_read(a, size)).hex() for a, size in GC_REGIONS.items()}
    return s


def case(params, last, tick, ref32, ref33):
    uc, fresh = C.case(params, ref32)
    fresh = json.loads(json.dumps(fresh))
    assert fresh == ref33, ('report33 full execution record mismatch', params)
    vm = fresh['prefix']['setup']['vm_size']
    pre_input = snapshot(uc, vm)
    assert {k: v for k, v in pre_input.items() if k != 'gc_regions'} == fresh['after']
    prefix_hash = canonical(fresh)  # Hash the freshly observed row, never copy a reference hash.
    assert prefix_hash == canonical(ref33)
    seeds = [(0x1f653c, [tick]), (0x1e773c, [last]), (0x1f7aa0, [0, 0, PD_HEAD, PD_HEAD])]
    for address, words in seeds:
        D.put(uc, address, *words)
    D.put(uc, N.CALL_STACK, D.STOP)
    uc.reg_write(X.UC_X86_REG_ESP, N.CALL_STACK)
    for register, value in D.REGS.values():
        uc.reg_write(register, value)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    before = snapshot(uc, vm)
    heads, writes, points = [], [], []
    nargs = {0x191144: 0, 0x16b84c: 2, 0x173e90: 3, 0x1765ac: 3, 0x176164: 3,
             0x1735f4: 2, 0x190c24: 2, 0x190b5c: 3, 0x178894: 1, 0x17b7bc: 1,
             0x1914c8: 4, 0x179bbc: 3, 0x18fb0c: 1, 0x17b540: 1, 0x17b5f8: 1,
             0x178c64: 1, 0x18fa44: 3, 0x190f90: 5}
    milestones = set(nargs) | {0x191171, 0x19117c, 0x1911b9, 0x1911cd, 0x1911e4, 0x1911f0,
        0x191260, 0x1913db, 0x190c03, 0x173660, 0x1788cc, 0x1788f0, 0x17b809,
        0x17645d, 0x18fbf1, 0x18fc55, 0x18fc9f, 0x18fcd8, 0x18fd17,
        0x179c0d, 0x17b5ee, 0x176481, 0x18faa5, 0x18f8b9, 0x178cb4, 0x178d57,
        0x17658c, 0x1765ef}
    def checkpoint(engine, pc):
        index = len(heads)
        heads.append(pc)
        assert pc not in (0x10ca6c, 0x163320, 0x1631a0, 0x16b790, 0x178d60, 0x179084,
            0x1790dc, 0x179764, 0x18b59b, 0x18b5dc, 0x18b5ef, 0x191205, 0x19129f), hex(pc)
        if pc in milestones:
            row = {'pc': hex(pc), 'trace_index': index, 'write_cursor': len(writes),
                   'cpu': T.snap(engine), 'state': snapshot(engine, vm)}
            if pc in nargs:
                row['args'] = D.words(engine, reg(engine, 'esp') + D.WORD, nargs[pc])
            points.append(row)
    def write(engine, access, address, width, value, unused):
        writes.append({'pc': reg(engine, 'eip'), 'trace_index': len(heads) - 1, 'address': address,
                       'width': width, 'value': value & ((1 << (width * 8)) - 1)})
    hook = uc.hook_add(U.UC_HOOK_MEM_WRITE, write)
    obs, failure = None, None
    try:
        obs = T.high_run(uc, 0x191144, {D.STOP}, True, checkpoint)
    except Exception as exc:
        failure = repr(exc)
    finally:
        uc.hook_del(hook)
    result = {'params': list(params), 'last': last, 'tick': tick,
        'prefix33': {'canonical_sha256': prefix_hash, 'scope': 'producer full-row equality; independent GC audit starts at explicit-input boundary'},
        'pre_input': pre_input, 'input': {'seeds': seeds, 'call_stack': N.CALL_STACK, 'stack_words': [D.STOP], 'eflags': 2},
        'before': before, 'observation': obs, 'recorded_heads': list(map(hex, heads)),
        'writes': writes, 'points': points, 'after': snapshot(uc, vm), 'failure': failure,
        'native_cpu_verified': False, 'whole_ownership_verified': False}
    save('latest-diagnostic.json', result)
    assert failure is None, failure
    assert obs['error'] is None and not obs['interrupts'] and obs['trace'] == result['recorded_heads']
    assert reg(uc, 'eip') == D.STOP and reg(uc, 'esp') == N.CALL_STACK + D.WORD
    D.assert_callee_saved(uc)
    T.guard_check(uc)
    gc = tick - (tick if last == 0 else last) > 1
    assert D.words(uc, 0x1e773c, 1) == [tick]
    assert D.words(uc, 0x1f7ad0, 1) == [0 if gc else 1]
    assert D.words(uc, 0x1f7ad4, 1) == [0 if gc else 1]
    assert D.words(uc, N.A.GLOBALS['free_count'], 1) == [int(gc)]
    assert D.words(uc, B.GLOBALS['wire_count'], 1) == [int(not gc)]
    assert D.words(uc, N.A.GLOBALS['active_count'], 1) == [1]
    assert result['after']['frame'] == before['frame'] and result['after']['new_pt_frame'] == before['new_pt_frame']
    assert result['after']['page'] == before['page'] and result['after']['object'] == before['object']
    if gc:
        assert D.words(uc, fresh['prefix']['setup']['kernel_pmap'] + 0x10, 2) == [0, 0]
        assert int.from_bytes(uc.mem_read(B.KO + 0x18, 2), 'little') == 1
        assert int.from_bytes(uc.mem_read(B.KO + 0x1a, 2), 'little') == 0
        assert bytes(uc.mem_read(B.PG + 0x1e, 1)) == b'\x28' and bytes(uc.mem_read(B.PG + 0x20, 1)) == b'\x00'
        assert D.words(uc, N.A.HEADS['free'], 2) == [B.PG, B.PG]
        assert D.words(uc, B.EZ + 8, 3) == [0, B.KE, B.KE]
        assert D.words(uc, B.XZ + 8, 3) == [0, N.EXTENSION, N.EXTENSION]
    return result


def main():
    check_helper()
    save('preservation-before.json', preserved())
    r32 = json.loads((HERE.parent / 'continuous-review-20260911-32/fault-new-pt-cases.json').read_text())
    r33 = json.loads((HERE.parent / 'continuous-review-20260911-33/dirty-remove-cases.json').read_text())
    refs32 = {tuple(r[k] for k in ('target', 'function', 'destination', 'flags', 'sleepable')): r for r in r32}
    refs33 = {tuple(r['params']): r for r in r33}
    plan = [(('A', '_copyout', 0x100, 2, 1), 1, 3)] if '--single' in sys.argv else [
        (p, 1, 3) for p in itertools.product(Q.ROOTS, N.S.TARGETS, (0x100, 0x1100), (2, 0x602), (1, 0))]
    if '--single' not in sys.argv:
        plan += [((t, '_copyout', 0x100, 2, 1), last, tick) for t in Q.ROOTS for last, tick in ((0, 3), (1, 1), (1, 2))]
    rows = []
    for params, last, tick in plan:
        rows.append(case(params, last, tick, refs32[params], refs33[params]))
        print(json.dumps({'case': len(rows), 'params': params, 'last': last, 'tick': tick}), flush=True)
    save('gc-cases.json', rows)
    save('gc-summary.json', {'cases': len(rows), 'gc_heads': sum(len(r['observation']['trace']) for r in rows),
        'gc_executed': sum('0x1911b9' in r['observation']['trace'] for r in rows),
        'status': 'runner assertions only; independent audit/negative controls/reproducibility incomplete', 'whole_goal_complete': False})
    save('preservation-after.json', preserved())


if __name__ == '__main__':
    main()
