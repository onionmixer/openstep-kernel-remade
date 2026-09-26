"""Resident RO mapping repair with original VM/pmap instructions.

Explicit synthetic preparation before fault, CPU frame injection after fault.
No PTE API writes or call mocks after the observed copy page fault.
"""
import importlib.util
import itertools
import json
from pathlib import Path
import sys
from verify_artifacts import preserved

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('protection25', HERE.parent / 'continuous-review-20260911-25/protection_review.py')
F = importlib.util.module_from_spec(spec)
spec.loader.exec_module(F)
T, Q, S, P, R, D, U, X = F.T, F.Q, F.S, F.P, F.R, F.D, F.U, F.X
OBJECT, PAGE_OBJECT, PMAP, BUCKETS = (0x682000, 0x683000, 0x684000, 0x685000)
reg = T.reg


def save(name, value):
    (HERE / name).write_text(json.dumps(value, indent=2) + '\n')


def state(uc):
    return {'cpu': T.snap(uc), 'object': bytes(uc.mem_read(OBJECT, 0x58)).hex(),
            'page': bytes(uc.mem_read(PAGE_OBJECT, 0x30)).hex(),
            'pmap': bytes(uc.mem_read(PMAP, 0x1c)).hex(),
            'map': bytes(uc.mem_read(F.MAP, 0x50)).hex(),
            'active_queue': D.words(uc, 0x1f6e40, 2), 'active_count': D.words(uc, 0x1f6e34, 1)[0],
            'bucket_data': bytes(uc.mem_read(BUCKETS, 8 * 8)).hex(),
            'buffer_hashes': T.buffer_hashes(uc),
            'uthread_byte': bytes(uc.mem_read(F.UTHREAD + 0x68, 1)).hex(),
            'recover': D.words(uc, Q.THREAD + 0x74, 1)[0]}


def mappings(uc):
    return [{'target': target, 'space': space, 'offset': off,
             'walk': P.walk(uc, root, base + Q.BUFFER + off)}
            for target, root in Q.ROOTS.items() for space, base in (('user', 0), ('kernel', Q.BASE))
            for off in range(0, Q.SPAN, Q.PAGE)]


def setup(target, name, destination, flags, queue):
    uc, info, unused = F.setup(target, name, 'entry', destination, 2, 3)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    uc.mem_write(OBJECT, bytes(0x58))
    uc.mem_write(PAGE_OBJECT, bytes(0x30))
    uc.mem_write(PMAP, bytes(0x1c))
    uc.mem_write(BUCKETS, bytes(8 * 8))
    vm_size = info['vm_size']
    offset = vm_size * 3
    D.put(uc, OBJECT, OBJECT, OBJECT)
    D.put(uc, OBJECT + 0x10, 1, offset + vm_size)
    uc.mem_write(OBJECT + 0x18, (1).to_bytes(2, 'little'))
    D.put(uc, PAGE_OBJECT + 0x20, 1, Q.PAYLOAD[target], 0)
    D.put(uc, F.ENTRY + 0x10, OBJECT, offset)
    D.put(uc, F.MAP + 0x24, PMAP)
    # Statistics are unused synthetic inputs, not counts derived from full root.
    D.put(uc, PMAP, Q.ROOTS[target], Q.ROOTS[target], 1, 0, 1, 0, 1)
    D.put(uc, 0x1f7438, BUCKETS, 7)
    shift = vm_size.bit_length() - 1
    D.put(uc, 0x1f6ea4, shift)
    for head, count in ((0x1f6e40, 0x1f6e34), (0x1f64e0, 0x1f64d8), (0x1f6e48, 0x1f6e38)):
        D.put(uc, head, head, head)
        D.put(uc, count, 0)
    for lock in (0x1f64e8, 0x1f6f2c):
        D.put(uc, lock, 0)
    info['initial_ipl'] = D.words(uc, 0x1e7714, 1)[0]
    info['pmap_protection_table'] = D.words(uc, 0x1f7b00, 8)
    assert info['pmap_protection_table'][3] & 3 == 3
    assert D.words(uc, 0x1f7ae0, 1)[0] == vm_size // Q.PAGE
    D.put(uc, D.STACK, D.STOP, PAGE_OBJECT, OBJECT, offset)
    uc.reg_write(X.UC_X86_REG_ESP, D.STACK)
    insertion = T.high_run(uc, 0x17ae0c, {D.STOP}, True)
    assert not insertion['error'] and not insertion['interrupts'] and reg(uc, 'eip') == D.STOP
    assert D.words(uc, PAGE_OBJECT + 0x14, 2) == [OBJECT, offset]
    assert int.from_bytes(uc.mem_read(OBJECT + 0x1a, 2), 'little') == 1
    bucket = BUCKETS + ((OBJECT + (offset >> shift)) & 7) * 8
    assert D.words(uc, bucket, 2) == [0, PAGE_OBJECT]
    assert D.words(uc, OBJECT, 2) == [PAGE_OBJECT, PAGE_OBJECT]
    if queue == 'active':
        assert int.from_bytes(uc.mem_read(PAGE_OBJECT + 0x1c, 4), 'little') == 0
        D.put(uc, 0x1f64e8, 1)
        D.put(uc, D.STACK, D.STOP, PAGE_OBJECT)
        uc.reg_write(X.UC_X86_REG_ESP, D.STACK)
        activation = T.high_run(uc, 0x17b8cc, {D.STOP}, True)
        assert not activation['error'] and not activation['interrupts'] and reg(uc, 'eip') == D.STOP
        assert D.words(uc, 0x1f6e40, 2) == [PAGE_OBJECT, PAGE_OBJECT]
        assert D.words(uc, 0x1f6e34, 1) == [1]
        D.put(uc, 0x1f64e8, 0)
        info['initial_activation'] = activation
    # Fault-preparation boundary, before any copy executes.
    D.put(uc, OBJECT + 0x10, 0)
    D.put(uc, PAGE_OBJECT + 0x20, 4)
    initial, expected, unused = S.prepare(uc, target, name, 1, 0x100, destination)
    for address, value in T.GUARDS.items():
        uc.mem_write(address, value)
    uc.reg_write(X.UC_X86_REG_EFLAGS, flags)
    info.update(insertion=insertion, object_offset=offset, hash_shift=shift, hash_bucket=bucket, initial_queue=queue,
                object_initialization='synthetic existing object; insert executed with object lock and page busy',
                pmap_stats_scope='unused target-model inputs; not whole-root accounting')
    return uc, info, initial, expected


def case(target='A', name='_copyout', destination=0x1100, flags=2, queue='unqueued'):
    uc, info, initial, expected = setup(target, name, destination, flags, queue)
    before = state(uc)
    mappings_before = mappings(uc)
    pte_addresses = {int(r['walk']['pte_address'], 16) for r in mappings_before if r['target'] == target and r['space'] == 'user'}
    fault_run = T.high_run(uc, R.NAMES[name], {D.STOP}, True)
    assert not fault_run['error'] and len(fault_run['interrupts']) == 1
    event = fault_run['interrupts'][0]
    fault = event['snapshot']
    assert event['vector'] == 14 and fault['eip'] in S.FS
    assert fault['cr2'] == Q.BUFFER + destination and fault == T.snap(uc)
    assert event['recover'] == S.TARGETS[name]
    S.buffers(uc, target, initial)
    frame = fault['esp'] - T.FRAME_SIZE
    cpu_frame = fault['esp'] - 4 * D.WORD
    D.put(uc, cpu_frame, 3, fault['eip'], fault['cs'], fault['eflags'])
    uc.reg_write(X.UC_X86_REG_ESP, cpu_frame)
    milestones, visits, invalidations, stores, stats_accesses, root_read_hooks, write_hooks = [], [], [], [], [], [], []
    captured = {}
    points = {0x187068, 0x172070, 0x1720d6, 0x172626, 0x19065c, 0x173451, 0x1921ec, 0x186d7c, fault['eip']}
    def checkpoint(engine, pc):
        visits.append(hex(pc))
        assert pc not in (0x1924a0, 0x190f24, 0x19108c, 0x1910e4, 0x18b59b, 0x18b5dc, 0x18b5ef), hex(pc)
        if pc == 0x1908b4:
            invalidations.append(reg(engine, 'edx'))
        if pc == 0x1908e8:
            stores.append({'address': reg(engine, 'ebx'), 'value': reg(engine, 'edi'),
                           'old': D.words(engine, reg(engine, 'ebx'), 1)[0]})
        if pc not in points:
            return
        snap = T.snap(engine)
        raw = bytes(engine.mem_read(frame, T.FRAME_SIZE))
        row = {'pc': hex(pc), 'state': state(engine), 'frame': raw.hex()}
        if pc == 0x187068:
            captured['frame'] = raw
            assert D.words(engine, snap['esp'] + D.WORD, 1)[0] == frame
            expected_frame = T.model_frame(fault, 3)
            for field, off in T.OFFSETS.items():
                width = 2 if field in ('gs', 'fs', 'es', 'ds', 'cs') else D.WORD
                assert int.from_bytes(raw[off:off + width], 'little') == expected_frame[field], field
        if pc == 0x172070:
            assert snap['eax'] == 0
        if pc == 0x1720d6:
            assert snap['eax'] == PAGE_OBJECT
        if pc == 0x172626:
            assert D.words(engine, 0x1f6e40, 2) == [0x1f6e40, 0x1f6e40]
            assert D.words(engine, 0x1f6e34, 1) == [0]
            assert not bytes(engine.mem_read(PAGE_OBJECT + 0x1e, 1))[0] & 2
        if pc == 0x19065c:
            row['arguments'] = D.words(engine, snap['esp'] + D.WORD, 5)
            assert row['arguments'] == [PMAP, Q.BUFFER, Q.PAYLOAD[target], 3, 0]
        if pc == 0x1921ec:
            assert snap['eax'] == 0
        if pc in (0x186d7c, fault['eip']):
            assert raw == captured['frame']
        if pc == fault['eip']:
            assert snap['esp'] == fault['esp'] and snap['eflags'] == fault['eflags']
            for field in ('eax', 'ebx', 'ecx', 'edx', 'esi', 'edi', 'ebp', 'cs', 'ss', 'ds', 'es', 'fs', 'gs'):
                assert snap[field] == fault[field], field
        milestones.append(row)
    def memory(engine, access, address, width, value, unused):
        if access == U.UC_MEM_WRITE and address in pte_addresses:
            write_hooks.append({'pc': reg(engine, 'eip'), 'address': address, 'width': width, 'value': value})
        if reg(engine, 'eip') == 0x190786:
            root_read_hooks.append({'access': access, 'address': address, 'width': width})
        if address < PMAP + 0x18 and address + width > PMAP + 0x10:
            stats_accesses.append({'pc': reg(engine, 'eip'), 'access': access, 'address': address, 'width': width})
    hook = uc.hook_add(U.UC_HOOK_MEM_READ | U.UC_HOOK_MEM_WRITE, memory)
    handler, failure = None, None
    try:
        handler = T.high_run(uc, 0x1861cc, {D.STOP}, True, checkpoint)
    except Exception as exc:
        failure = repr(exc)
    finally:
        uc.hook_del(hook)
    result = {'target': target, 'function': name, 'destination': destination, 'flags': flags,
              'fixture': info, 'before': before, 'fault': fault_run, 'handler': handler,
              'milestones': milestones, 'trace': visits, 'invalidations': invalidations,
              'pte_store_attempts': stores, 'pmap_stats_accesses': stats_accesses,
              'pmap_root_read_hooks': root_read_hooks,
              'pte_write_hooks': write_hooks,
              'mappings_before': mappings_before, 'mappings_after': mappings(uc),
              'after': state(uc), 'failure': failure, 'cpu_frame_injected': True,
              'native_frame_generation_verified': False, 'pager_io_verified': False}
    save('latest-diagnostic.json', result)
    assert failure is None, failure
    assert handler['error'] is None and not handler['interrupts'], handler
    assert reg(uc, 'eip') == D.STOP and reg(uc, 'eax') == 0
    assert reg(uc, 'esp') == D.STACK + D.WORD
    D.assert_callee_saved(uc)
    S.buffers(uc, target, expected)
    T.guard_check(uc)
    assert invalidations == [Q.BUFFER + off for off in range(0, info['vm_size'], Q.PAGE)]
    assert len(stores) == info['vm_size'] // Q.PAGE
    for off, store in zip(range(0, info['vm_size'], Q.PAGE), stores):
        walk = P.walk(uc, Q.ROOTS[target], Q.BUFFER + off)
        assert store['address'] == int(walk['pte_address'], 16)
        assert store['old'] & 3 == 1 and store['value'] == (Q.PAYLOAD[target] + off) | 7
        assert walk['present'] and walk['writable'] and int(walk['physical'], 16) == Q.PAYLOAD[target] + off
    assert not stats_accesses
    assert root_read_hooks == [{'access': U.UC_MEM_READ, 'address': PMAP, 'width': D.WORD}]
    assert write_hooks == [{'pc': 0x1908e8, 'address': s['address'], 'width': D.WORD, 'value': s['value']} for s in stores]
    for old, new in zip(mappings_before, result['mappings_after']):
        assert (old['target'], old['space'], old['offset']) == (new['target'], new['space'], new['offset'])
        a, b = old['walk'], new['walk']
        assert int(a['pde'], 16) & ~0x20 == int(b['pde'], 16) & ~0x20
        assert a['pte_address'] == b['pte_address'] and a['physical'] == b['physical']
        wanted = int(a['pte'], 16)
        if old['target'] == target and old['space'] == 'user':
            wanted |= 2
        assert wanted & ~0x60 == int(b['pte'], 16) & ~0x60
    assert bytes(uc.mem_read(PMAP, 0x1c)).hex() == before['pmap']
    assert bytes(uc.mem_read(F.MAP, 0x50)).hex() == before['map']
    assert D.words(uc, OBJECT + 0x10, 1) == [0]
    assert int.from_bytes(uc.mem_read(OBJECT + 0x18, 2), 'little') == 1
    assert int.from_bytes(uc.mem_read(OBJECT + 0x1a, 2), 'little') == 1
    assert int.from_bytes(uc.mem_read(OBJECT + 0x44, 2), 'little') == 0
    assert D.words(uc, 0x1f6e40, 2) == [PAGE_OBJECT, PAGE_OBJECT]
    assert D.words(uc, PAGE_OBJECT, 2) == [0x1f6e40, 0x1f6e40]
    assert D.words(uc, 0x1f6e34, 1) == [1]
    assert D.words(uc, Q.THREAD + 0x74, 1) == [S.TARGETS[name]]
    assert reg(uc, 'eflags') & 0x600 == flags & 0x600
    assert bytes(uc.mem_read(F.UTHREAD + 0x68, 1)) == bytes([0xa5])
    assert D.words(uc, 0x1e7714, 1) == [info['initial_ipl']]
    assert visits.count(hex(fault['eip'])) == 1
    for field in ('cs', 'ds', 'es', 'ss', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4'):
        assert reg(uc, field) == fault[field], field
    assert D.words(uc, PAGE_OBJECT + 0x20, 1) == [4]
    assert bytes(uc.mem_read(BUCKETS, 8 * 8)).hex() == before['bucket_data']
    assert bytes(uc.mem_read(OBJECT, 0x58)).hex() == before['object']
    assert {int(m['pc'], 16) for m in milestones} == points
    assert ('0x1725f6' in visits) == (queue == 'active')
    wanted_page = bytearray.fromhex(before['page'])
    wanted_page[:2 * D.WORD] = (0x1f6e40).to_bytes(D.WORD, 'little') * 2
    wanted_page[0x1e] |= 2
    assert bytes(uc.mem_read(PAGE_OBJECT, 0x30)) == wanted_page
    result['checks_passed'] = True
    return result


def main():
    save('preservation-before.json', preserved())
    rows = []
    for params in itertools.product(Q.ROOTS, S.TARGETS, (0x100, 0x1100), (2, 0x202, 0x402, 0x602), ('unqueued', 'active')):
        rows.append(case(*params))
        if len(rows) % 8 == 0:
            print('resident cases:', len(rows), flush=True)
    save('resident-cases.json', rows)
    summary = {'resident_permission_repair_and_restart_cases': len(rows),
               'original_pte_stores': sum(len(r['pte_store_attempts']) for r in rows),
               'original_invlpg_executions': sum(len(r['invalidations']) for r in rows),
               'handler_instruction_visits': sum(len(r['trace']) for r in rows),
               'df_set_success_cases': sum(bool(r['flags'] & 0x400) for r in rows),
               'active_initial_queue_cases': sum(r['fixture']['initial_queue'] == 'active' for r in rows),
               'native_frame_generation_verified': False, 'pager_io_verified': False,
               'whole_object_pmap_creation_verified': False, 'whole_analysis_complete': False}
    save('resident-review.json', summary)
    save('preservation-after.json', preserved())
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
