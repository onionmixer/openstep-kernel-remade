"""Fresh original GC -> new copy NP -> existing DATA/new wired PT resource reuse.

Original CPU execution on the preserved backend, explicit caller and exception-frame
inputs only. No state correction after exception-frame input. Audit remains separate.
"""
import itertools
import json
from pathlib import Path
import sys
import gc_prefix as G
from check_helper import check
from verify_artifacts import preserved

HERE = Path(__file__).resolve().parent
N, B, T, Q, P, D, U, X, reg = G.N, G.B, G.T, G.Q, G.P, G.D, G.U, G.X, G.reg
SOURCE_OFFSET = 0x101
NARGS = {0x187068: 1, 0x17af58: 2, 0x190cfc: 2, 0x173d1c: 3, 0x174a90: 6,
         0x16b790: 1, 0x16b84c: 2, 0x176164: 3, 0x174848: 5, 0x173ebc: 4,
         0x17b200: 3, 0x175b2c: 4, 0x173898: 3, 0x17b6e8: 1, 0x19065c: 5,
         0x17b8cc: 1, 0x1019c0: 2}
MILESTONES = set(NARGS) | {0x1720d6, 0x1725f0, 0x172620, 0x17266f, 0x172672,
    0x173f04, 0x173f92, 0x173a11, 0x1735c3, 0x173e3a, 0x190d7b, 0x190d9b,
    0x190de5, 0x190e20, 0x190f1a, 0x1907b1, 0x173451, 0x1734bd, 0x1734c0,
    0x1921ec, 0x186d7c, 0x190aa7, 0x190ef4}


def save(name, value):
    (HERE / name).write_text(json.dumps(value, indent=2) + '\n')


def case(params, refs):
    target, name, destination, flags, sleepable = params
    uc, fresh = G.case(params, 1, 3, refs[32][params], refs[33][params])
    fresh = json.loads(json.dumps(fresh))
    assert fresh == refs[34][params], ('fresh full GC record differs', params)
    vm = refs[32][params]['setup']['vm_size']
    pre_input = G.snapshot(uc, vm)
    assert pre_input == fresh['after']
    caller = [D.STOP, Q.BUFFER + SOURCE_OFFSET, Q.BUFFER + destination, 1]
    D.put(uc, D.STACK, *caller)
    uc.reg_write(X.UC_X86_REG_ESP, D.STACK)
    for register, value in D.REGS.values():
        uc.reg_write(register, value)
    uc.reg_write(X.UC_X86_REG_EFLAGS, flags)
    before = G.snapshot(uc, vm)
    pre_heads, pre_writes = [], []
    def pre_checkpoint(engine, pc):
        pre_heads.append(pc)
    def pre_write(engine, access, address, width, value, unused):
        pre_writes.append(dict(pc=reg(engine, 'eip'), trace_index=len(pre_heads) - 1,
                               address=address, width=width, value=value & ((1 << (width * 8)) - 1)))
    hook = uc.hook_add(U.UC_HOOK_MEM_WRITE, pre_write)
    try:
        fault_run = T.high_run(uc, N.R.NAMES[name], {D.STOP}, True, pre_checkpoint)
    finally:
        uc.hook_del(hook)
    at_fault = G.snapshot(uc, vm)
    save('latest-prefault.json', {'params': params, 'pre_input': pre_input,
        'prefix34_canonical_sha256': G.canonical(fresh), 'caller_input': {'stack': D.STACK, 'words': caller, 'flags': flags},
        'before': before, 'fault': fault_run, 'recorded_heads': list(map(hex, pre_heads)),
        'writes': pre_writes, 'at_fault': at_fault})
    assert fault_run['error'] is None and len(fault_run['interrupts']) == 1
    event, fault = fault_run['interrupts'][0], fault_run['after']
    assert event['vector'] == 14, ('expected page fault; refusing to inject handler for other vector', event['vector'])
    assert event['snapshot'] == fault == at_fault['cpu']
    assert fault['eip'] in N.S.FS and fault['cr2'] == Q.BUFFER + destination
    assert not P.walk(uc, Q.ROOTS[target], fault['cr2'])['present']
    assert at_fault['frame'] == before['frame'] and at_fault['new_pt_frame'] == before['new_pt_frame']
    frame_address, cpu_frame = fault['esp'] - T.FRAME_SIZE, fault['esp'] - 4 * D.WORD
    words = [2, fault['eip'], fault['cs'], fault['eflags']]
    D.put(uc, cpu_frame, *words)
    uc.reg_write(X.UC_X86_REG_ESP, cpu_frame)
    injected = G.snapshot(uc, vm)
    heads, writes, points, zeros = [], [], [], []
    retry_next = fault['eip'] + Q.decoded(fault['eip']).size
    milestone = MILESTONES | {fault['eip'], retry_next}
    def checkpoint(engine, pc):
        index = len(heads)
        heads.append(pc)
        assert pc not in (0x10ca6c, 0x163320, 0x1631a0, 0x165328, 0x16b3df, 0x190e51,
                          0x1924a0, 0x18b59b, 0x18b5dc, 0x18b5ef, 0x18c12c, 0x18c174, 0x18c187), hex(pc)
        if pc == 0x1019cc:
            zeros.append(dict({k: reg(engine, k) for k in ('eax', 'ecx', 'edx')}, trace_index=index))
        if pc in milestone:
            row = dict(pc=hex(pc), trace_index=index, write_cursor=len(writes), cpu=T.snap(engine),
                       state=G.snapshot(engine, vm), saved_frame=bytes(engine.mem_read(frame_address, T.FRAME_SIZE)).hex())
            if pc in NARGS:
                row['args'] = D.words(engine, reg(engine, 'esp') + D.WORD, NARGS[pc])
            points.append(row)
    def write(engine, access, address, width, value, unused):
        writes.append(dict(pc=reg(engine, 'eip'), trace_index=len(heads) - 1,
                           address=address, width=width, value=value & ((1 << (width * 8)) - 1)))
    hook = uc.hook_add(U.UC_HOOK_MEM_WRITE, write)
    handler, failure = None, None
    try:
        handler = T.high_run(uc, 0x1861cc, {D.STOP}, True, checkpoint)
    except Exception as error:
        failure = repr(error)
    finally:
        uc.hook_del(hook)
    result = dict(params=list(params), target=target, function=name, destination=destination, flags=flags,
        sleepable=sleepable, source_offset=SOURCE_OFFSET,
        prefix34={'canonical_sha256': G.canonical(fresh), 'scope': 'producer full-row equality; independent reuse audit begins at explicit input boundary'},
        pre_input=pre_input, caller_input={'stack': D.STACK, 'words': caller, 'flags': flags}, before=before,
        fault=fault_run, prefault_writes=pre_writes, prefault_recorded_heads=list(map(hex, pre_heads)), at_fault=at_fault,
        cpu_frame_input={'address': cpu_frame, 'words': words}, frame_address=frame_address, injected=injected,
        handler=handler, recorded_heads=list(map(hex, heads)), writes=writes, points=points, zero_chunks=zeros,
        after=G.snapshot(uc, vm), failure=failure, native_cpu_frame_verified=False, whole_ownership_verified=False)
    save('latest-diagnostic.json', result)
    assert failure is None, failure
    assert handler['error'] is None and not handler['interrupts'] and handler['trace'] == result['recorded_heads']
    assert reg(uc, 'eip') == D.STOP and reg(uc, 'eax') == 0 and reg(uc, 'esp') == D.STACK + D.WORD
    D.assert_callee_saved(uc)
    T.guard_check(uc)
    assert handler['trace'].count(hex(fault['eip'])) == 1
    assert all(hex(pc) not in handler['trace'] for pc in (0x17269a, 0x1729e4, 0x1729e9))
    assert [p['args'] for p in points if p['pc'] == '0x17b200'] == [[B.KO, B.KVA, 1]]
    assert next(p for p in points if p['pc'] == '0x1720d6')['cpu']['eax'] == N.PAGE_OBJECT
    assert next(p for p in points if p['pc'] == '0x173f04')['cpu']['eax'] == B.PG
    expected = bytearray.fromhex(before['frame'])
    expected[destination] = Q.PATTERNS['kernel'][SOURCE_OFFSET]
    assert expected.hex() == result['after']['frame'] and expected.hex() != before['frame']
    assert result['after']['copy_buffer_hashes'] == before['copy_buffer_hashes']
    assert D.words(uc, N.A.GLOBALS['free_count'], 1) == [0]
    assert D.words(uc, N.A.GLOBALS['active_count'], 1) == [1]
    assert D.words(uc, B.GLOBALS['wire_count'], 1) == [1]
    assert D.words(uc, 0x1f6514, 1) == [4] and D.words(uc, 0x1f6504, 1) == [1]
    return result


def main():
    check()
    save('preservation-before.json', preserved())
    refs = {}
    for number, directory, filename in ((32, 'continuous-review-20260911-32', 'fault-new-pt-cases.json'),
        (33, 'continuous-review-20260911-33', 'dirty-remove-cases.json'), (34, 'continuous-review-20260912-34', 'gc-cases.json')):
        data = json.loads((HERE.parent / directory / filename).read_text())
        refs[number] = {tuple(r[k] for k in ('target', 'function', 'destination', 'flags', 'sleepable')) if number == 32 else tuple(r['params']): r
                        for r in data if number != 34 or (r['last'], r['tick']) == (1, 3)}
    plan = [('A', '_copyout', 0x100, 2, 1)] if '--single' in sys.argv else itertools.product(Q.ROOTS, N.S.TARGETS, (0x100, 0x1100), (2, 0x602), (1, 0))
    rows = []
    for params in plan:
        rows.append(case(params, refs))
        print(json.dumps({'case': len(rows), 'params': params}), flush=True)
    save('reuse-cases.json', rows)
    save('reuse-summary.json', {'cases': len(rows), 'handler_heads': sum(len(r['handler']['trace']) for r in rows),
        'status': 'runner assertions only; independent audit/negative controls/reproducibility incomplete', 'whole_goal_complete': False})
    save('preservation-after.json', preserved())


if __name__ == '__main__':
    main()
