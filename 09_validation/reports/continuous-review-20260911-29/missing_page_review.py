"""Original anonymous missing-page allocation/zero-fill/new managed mapping.

All memory API writes are setup or the explicitly injected CPU exception frame.
No original calls are mocked and no post-fault translation flush is injected.
"""
import importlib.util
import itertools
import json
from pathlib import Path
import sys
from verify_artifacts import preserved

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('allocator28', HERE.parent / 'continuous-review-20260911-28/allocator_review.py')
A = importlib.util.module_from_spec(spec)
spec.loader.exec_module(A)
F, T, Q, D, U, X = A.F, A.T, A.Q, A.D, A.U, A.X
S, P, R = F.S, F.P, F.R
reg = T.reg
OBJECT, PAGE_OBJECT, PMAP, BUCKETS = 0x682000, 0x683000, 0x684000, 0x685000
DESCRIPTORS, EXTENSION, PT_PAIR, FRAME, PHYS_END = 0x690000, 0x699000, 0x810000, 0xb00000, 0xc00000
PT_HEAD, PT_COUNT = 0x1f7ac8, 0x1f7ac0
CALL_STACK = D.STACK - 0x100


def save(name, value):
    (HERE / name).write_text(json.dumps(value, indent=2) + '\n')


def descriptor(phys, vm_size):
    n = vm_size // Q.PAGE
    assert n == 2
    return DESCRIPTORS + (((phys >> 12) >> (n - 1)) * 20)


def invoke(uc, entry, args, stop=D.STOP):
    D.put(uc, CALL_STACK, D.STOP, *args)
    uc.reg_write(X.UC_X86_REG_ESP, CALL_STACK)
    for register, value in D.REGS.values():
        uc.reg_write(register, value)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    obs = T.high_run(uc, entry, {stop}, True)
    assert obs['error'] is None and not obs['interrupts'] and reg(uc, 'eip') == stop, obs
    if stop == D.STOP:
        assert reg(uc, 'esp') == CALL_STACK + D.WORD
        D.assert_callee_saved(uc)
    return {'entry': hex(entry), 'args': args, 'observation': obs}


def snapshot(uc, vm_size):
    return {'cpu': T.snap(uc), 'object': bytes(uc.mem_read(OBJECT, 0x58)).hex(),
            'page': bytes(uc.mem_read(PAGE_OBJECT, 0x30)).hex(), 'pmap': bytes(uc.mem_read(PMAP, 0x1c)).hex(),
            'map': bytes(uc.mem_read(F.MAP, 0x50)).hex(), 'entry': bytes(uc.mem_read(F.ENTRY, 0x2c)).hex(),
            'frame': bytes(uc.mem_read(FRAME, vm_size)).hex(), 'pt_pair': bytes(uc.mem_read(PT_PAIR, vm_size)).hex(),
            'descriptor_arena': bytes(uc.mem_read(DESCRIPTORS, PHYS_END // vm_size * 20)).hex(),
            'extension': bytes(uc.mem_read(EXTENSION, 0x20)).hex(),
            'buckets': bytes(uc.mem_read(BUCKETS, 8 * 8)).hex(),
            'globals': {name: D.words(uc, a, 1)[0] for name, a in dict(A.GLOBALS, zero_count=0x1f6504, pt_count=PT_COUNT,
                        fault_count=0x1f6514, object_cache_lock=0x1f6f2c, exception_flag=0x1f74d4).items()},
            'contract_globals': {hex(a): D.words(uc, a, 1)[0] for a in (0x1f7ab0, 0x1f7ab8, 0x1f7ae0, 0x1f7ae8,
                                0x1e247c, 0x1e2480, 0x1f63f0, 0x1e0d0c, 0x1e89ec, 0x1f7438, 0x1f743c, 0x1f6ea4)},
            'queues': {name: D.words(uc, a, 2) for name, a in dict(A.HEADS, pt=PT_HEAD).items()},
            'roots': {name: bytes(uc.mem_read(root, Q.PAGE)).hex() for name, root in Q.ROOTS.items()},
            'copy_buffer_hashes': T.buffer_hashes(uc),
            'recover': D.words(uc, Q.THREAD + 0x74, 1)[0], 'uthread': bytes(uc.mem_read(F.UTHREAD + 0x68, 1)).hex()}


def setup(target, name, destination, flags):
    uc, info, unused = F.setup(target, name, 'entry', destination, 2, 3)
    vm_size, root = info['vm_size'], Q.ROOTS[target]
    assert vm_size == D.words(uc, 0x1e0d0c, 1)[0] and vm_size == Q.SPAN
    assert PT_PAIR % vm_size == FRAME % vm_size == 0
    arena_size = PHYS_END // vm_size * 20
    assert DESCRIPTORS + arena_size <= EXTENSION and EXTENSION + 0x20 < D.STACK - Q.PAGE
    prefix = invoke(uc, 0x17aa08, (), 0x17aade)
    template = bytearray(0x30)
    template[0x1e], template[0x20] = 0x20, 1
    assert bytes(uc.mem_read(A.TEMPLATE, 0x30)) == template
    # Explicit anonymous object, table/hash arena, managed descriptors and PT state.
    uc.mem_write(OBJECT, bytes(0x58))
    uc.mem_write(PAGE_OBJECT, bytes(0x30))
    uc.mem_write(PMAP, bytes(0x1c))
    uc.mem_write(BUCKETS, bytes(8 * 8))
    uc.mem_write(DESCRIPTORS, bytes(arena_size))
    uc.mem_write(EXTENSION, bytes(0x20))
    uc.mem_write(PT_PAIR, bytes(vm_size))
    uc.mem_write(FRAME, bytes((i * 19 + (i >> 7) + 0x53) & 0xff for i in range(vm_size)))
    offset = vm_size * 3
    D.put(uc, OBJECT, OBJECT, OBJECT)
    D.put(uc, OBJECT + 0x10, 1, offset + vm_size)
    uc.mem_write(OBJECT + 0x18, (1).to_bytes(2, 'little'))
    D.put(uc, F.ENTRY + 0x10, OBJECT, offset)
    D.put(uc, F.MAP + 0x24, PMAP)
    D.put(uc, PMAP, root, root, 1, 0, 0, 0, 1)
    assert PMAP != D.words(uc, 0x1f63f0, 1)[0]
    D.put(uc, 0x1f7438, BUCKETS, 7)
    D.put(uc, 0x1f6ea4, vm_size.bit_length() - 1)
    D.put(uc, 0x1f7ab0, DESCRIPTORS)
    D.put(uc, 0x1f7ab8, 0)
    D.put(uc, 0x1e247c, 0, PHYS_END)
    for key in ('active_count', 'inactive_count', 'free_count', 'reserved', 'minimum', 'target', 'inactive_target'):
        D.put(uc, A.GLOBALS[key], 0)
    D.put(uc, A.GLOBALS['queue_lock'], 1)
    D.put(uc, Q.THREAD + 0x78, 0)
    D.put(uc, 0x1f6f2c, 0)
    pt_desc = descriptor(PT_PAIR, vm_size)
    D.put(uc, pt_desc + 0xc, EXTENSION)
    D.put(uc, EXTENSION, PT_HEAD, PT_HEAD, pt_desc, PT_PAIR, PMAP, 0)
    D.put(uc, PT_HEAD, EXTENSION, EXTENSION)
    D.put(uc, PT_COUNT, 1)
    # Clear ONLY active user half after flat-CS calibration; shared high kernel remains.
    high_before = bytes(uc.mem_read(root + (Q.BASE >> 22) * D.WORD, Q.PAGE - (Q.BASE >> 22) * D.WORD))
    uc.mem_write(root, bytes((Q.BASE >> 22) * D.WORD))
    for i in range(vm_size // Q.PAGE):
        D.put(uc, root + i * D.WORD, (PT_PAIR + i * Q.PAGE) | 7)
    assert bytes(uc.mem_read(root + (Q.BASE >> 22) * D.WORD, len(high_before))) == high_before
    uc.reg_write(X.UC_X86_REG_EAX, root)
    flush = T.high_run(uc, Q.WRITE_CR3, {Q.SWITCH_END}, True)
    assert flush['error'] is None and not flush['interrupts'] and reg(uc, 'cr3') == root
    assert flush['trace'] == [hex(Q.WRITE_CR3)]
    direct = []
    for a in (FRAME, FRAME + vm_size - 1, PT_PAIR, PT_PAIR + vm_size - 1, DESCRIPTORS, EXTENSION, D.STACK):
        w = P.walk(uc, root, Q.BASE + a)
        assert w['present'] and w['writable'] and not w['user'] and int(w['physical'], 16) == a
        direct.append(w)
    seed = [invoke(uc, 0x17b134, [PAGE_OBJECT, OBJECT, offset, FRAME]), invoke(uc, 0x17b540, [PAGE_OBJECT])]
    assert D.words(uc, OBJECT, 2) == [OBJECT, OBJECT]
    assert int.from_bytes(uc.mem_read(OBJECT + 0x1a, 2), 'little') == 0
    assert bytes(uc.mem_read(BUCKETS, 8 * 8)) == bytes(8 * 8)
    assert D.words(uc, A.GLOBALS['free_count'], 1) == [1]
    # Release caller-held locks before vm_fault itself acquires them.
    D.put(uc, OBJECT + 0x10, 0)
    D.put(uc, A.GLOBALS['queue_lock'], 0)
    S.prepare(uc, target, name, 1, 0x100, destination)
    for a, value in T.GUARDS.items():
        uc.mem_write(a, value)
    uc.reg_write(X.UC_X86_REG_EFLAGS, flags)
    refs = A.mapped_frame_references(uc, [FRAME], vm_size)
    assert all(r['va'] >= Q.BASE for r in refs if r['root'] == target)
    assert not P.walk(uc, root, Q.BUFFER + destination)['present']
    info.update(startup_prefix=prefix, seed_calls=seed, original_pre_fault_cr3_reload=flush,
                object_offset=offset, direct_aliases=direct, pre_fault_frame_references=refs,
                frame=FRAME, pt_pair=PT_PAIR, pt_descriptor=pt_desc, frame_descriptor=descriptor(FRAME, vm_size),
                descriptor_arena=DESCRIPTORS, descriptor_arena_size=arena_size,
                synthetic_scope='anonymous object/hash/managed descriptors/PT pair+extension; not full pmap_init/ownership; inactive bootstrap aliases retained')
    return uc, info


def case(target, name, destination, flags):
    uc, info = setup(target, name, destination, flags)
    vm_size = info['vm_size']
    before = snapshot(uc, vm_size)
    fault_run = T.high_run(uc, R.NAMES[name], {D.STOP}, True)
    assert fault_run['error'] is None and len(fault_run['interrupts']) == 1
    event = fault_run['interrupts'][0]
    fault = event['snapshot']
    assert event['vector'] == 14 and fault['eip'] in S.FS and fault['cr2'] == Q.BUFFER + destination
    assert snapshot(uc, vm_size)['frame'] == before['frame']
    assert T.buffer_hashes(uc) == before['copy_buffer_hashes']
    assert not P.walk(uc, Q.ROOTS[target], fault['cr2'])['present']
    frame_address = fault['esp'] - T.FRAME_SIZE
    cpu_frame = fault['esp'] - 4 * D.WORD
    error_code = 2  # explicit NP/write/supervisor frame input, NOT CPU-produced error code.
    D.put(uc, cpu_frame, error_code, fault['eip'], fault['cs'], fault['eflags'])
    uc.reg_write(X.UC_X86_REG_ESP, cpu_frame)
    points = {0x187068, 0x1720d6, 0x17269f, 0x1729e9, 0x19065c, 0x173451, 0x1921ec, 0x186d7c, fault['eip']}
    milestones, writes, rep, zero_chunks = [], [], [], []
    captured = {}
    def checkpoint(engine, pc):
        assert pc not in (0x1924a0, 0x190cfc, 0x16b790, 0x17a248, 0x163320, 0x165328, 0x10ca6c,
                         0x1631a0, 0x17a338, 0x18b59b, 0x18b5dc, 0x18b5ef), hex(pc)
        if pc == 0x17b384:
            rep.append({k: reg(engine, k) for k in ('ecx', 'esi', 'edi', 'eflags')})
        if pc == 0x1019cc:
            zero_chunks.append({k: reg(engine, k) for k in ('eax', 'ecx', 'edx')})
        if pc not in points:
            return
        state = snapshot(engine, vm_size)
        raw = bytes(engine.mem_read(frame_address, T.FRAME_SIZE))
        row = {'pc': hex(pc), 'state': state, 'saved_frame': raw.hex()}
        if pc == 0x187068:
            expected = T.model_frame(fault, error_code)
            for field, off in T.OFFSETS.items():
                width = 2 if field in ('gs', 'fs', 'es', 'ds', 'cs') else D.WORD
                assert int.from_bytes(raw[off:off + width], 'little') == expected[field], field
            captured['frame'] = raw
        if pc == 0x1720d6:
            assert reg(engine, 'eax') == 0
        if pc == 0x17269f:
            assert reg(engine, 'eax') == PAGE_OBJECT
        if pc == 0x1729e9:
            assert bytes.fromhex(state['frame']) == bytes(vm_size)
        if pc == 0x19065c:
            row['args'] = D.words(engine, reg(engine, 'esp') + D.WORD, 5)
            assert row['args'] == [PMAP, Q.BUFFER, FRAME, 3, 0]
        if pc == 0x1921ec:
            assert reg(engine, 'eax') == 0
        if pc in (0x186d7c, fault['eip']):
            assert raw == captured['frame']
        if pc == fault['eip']:
            for field in ('eax', 'ebx', 'ecx', 'edx', 'esi', 'edi', 'ebp', 'esp', 'eflags', 'cs', 'ss', 'ds', 'es', 'fs', 'gs'):
                assert reg(engine, field) == fault[field], field
        milestones.append(row)
    def write(engine, access, address, width, value, unused):
        writes.append({'pc': reg(engine, 'eip'), 'address': address, 'width': width, 'value': value & ((1 << (width * 8)) - 1)})
    hook = uc.hook_add(U.UC_HOOK_MEM_WRITE, write)
    failure, handler = None, None
    try:
        handler = T.high_run(uc, 0x1861cc, {D.STOP}, True, checkpoint)
    except Exception as exc:
        failure = repr(exc)
    finally:
        uc.hook_del(hook)
    result = {'target': target, 'function': name, 'destination': destination, 'flags': flags, 'fixture': info,
              'before': before, 'fault': fault_run, 'error_frame_input': error_code,
              'cpu_frame_injected': True, 'native_frame_generation_verified': False,
              'handler': handler, 'milestones': milestones, 'writes': writes, 'allocator_rep': rep,
              'zero_chunks': zero_chunks, 'after': snapshot(uc, vm_size), 'failure': failure}
    save('latest-diagnostic.json', result)
    assert failure is None, failure
    assert handler['error'] is None and not handler['interrupts'], handler
    assert reg(uc, 'eip') == D.STOP and reg(uc, 'eax') == 0 and reg(uc, 'esp') == D.STACK + D.WORD
    D.assert_callee_saved(uc)
    T.guard_check(uc)
    assert {int(r['pc'], 16) for r in milestones} == points
    expected = bytearray(vm_size)
    expected[destination] = Q.PATTERNS['kernel'][0x100]
    assert bytes(uc.mem_read(FRAME, vm_size)) == expected
    assert T.buffer_hashes(uc) == before['copy_buffer_hashes']
    assert D.words(uc, PMAP + 0x10, 2) == [1, 0]
    assert int.from_bytes(uc.mem_read(EXTENSION + 0x18, 2), 'little') == 1
    assert int.from_bytes(uc.mem_read(EXTENSION + 0x1a, 2), 'little') == 0
    assert D.words(uc, descriptor(FRAME, vm_size), 3) == [0, PMAP, Q.BUFFER]
    for off in range(0, vm_size, Q.PAGE):
        w = P.walk(uc, Q.ROOTS[target], Q.BUFFER + off)
        assert w['present'] and w['writable'] and w['user'] and int(w['physical'], 16) == FRAME + off
    assert D.words(uc, OBJECT + 0x10, 1) == [0]
    assert int.from_bytes(uc.mem_read(OBJECT + 0x18, 2), 'little') == 1
    assert int.from_bytes(uc.mem_read(OBJECT + 0x1a, 2), 'little') == 1
    assert int.from_bytes(uc.mem_read(OBJECT + 0x44, 2), 'little') == 0
    assert D.words(uc, A.GLOBALS['free_count'], 1) == [0]
    assert D.words(uc, A.GLOBALS['active_count'], 1) == [1]
    assert D.words(uc, 0x1f6e40, 2) == [PAGE_OBJECT, PAGE_OBJECT]
    assert D.words(uc, Q.THREAD + 0x74, 1) == [S.TARGETS[name]]
    assert result['after']['uthread'] == before['uthread']
    assert result['after']['contract_globals'] == before['contract_globals']
    for field in ('cs', 'ds', 'es', 'ss', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4'):
        assert result['after']['cpu'][field] == fault[field], field
    assert reg(uc, 'eflags') & 0x600 == flags & 0x600
    assert result['after']['globals']['zero_count'] == (before['globals']['zero_count'] + 1) & 0xffffffff
    assert handler['trace'].count(hex(fault['eip'])) == 1
    for other in Q.ROOTS:
        if other != target:
            assert result['after']['roots'][other] == before['roots'][other]
    result['checks_passed'] = True
    return result


def main():
    save('preservation-before.json', preserved())
    matrix = [('A', '_copyout', 0x100, 2)] if '--single' in sys.argv else itertools.product(Q.ROOTS, S.TARGETS, (0x100, 0x1100), (2, 0x602))
    rows = []
    for params in matrix:
        rows.append(case(*params))
        print(json.dumps({'case': len(rows), 'params': params}), flush=True)
    save('missing-page-cases.json', rows)
    save('missing-page-summary.json', {'cases': len(rows), 'original_pte_stores': sum(w['pc'] == 0x190aa7 for r in rows for w in r['writes']),
                                      'original_zero_fill_stores': sum(0x1019cc <= w['pc'] <= 0x1019e1 for r in rows for w in r['writes']),
                                      'handler_instruction_visits': sum(len(r['handler']['trace']) for r in rows),
                                      'native_cpu_frames_verified': False, 'whole_vm_verified': False})
    save('preservation-after.json', preserved())


if __name__ == '__main__':
    main()
