"""Original page metadata allocation/release; no kernel implementation or pager.

All synthetic initialization occurs at explicit operation boundaries. Original
functions are never patched or replaced and no memory API writes occur mid-call.
"""
import importlib.util
import itertools
import json
from pathlib import Path
import sys
from verify_artifacts import preserved

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('protection25', HERE.parent / 'continuous-review-20260911-25/protection_review.py')
F = importlib.util.module_from_spec(spec)
spec.loader.exec_module(F)
T, Q, D, U, X = F.T, F.Q, F.D, F.U, F.X
reg = T.reg
OBJECTS = (0x682000, 0x682100)
PAGES = (0x683000, 0x683100, 0x683200)
BUCKETS, TEMPLATE, CALL_STACK = 0x685000, 0x1f7440, D.STACK - 0x100
PHYS, PHYS_SIZE = 0x2000000, 0x10000
GLOBALS = {'active_count': 0x1f6e34, 'inactive_count': 0x1f64d8, 'free_count': 0x1f6e38,
           'queue_lock': 0x1f64e8, 'free_lock': 0x1f7418, 'ipl': 0x1e7714,
           'reserved': 0x1e0d1c, 'minimum': 0x1e0d14, 'target': 0x1e0d10, 'inactive_target': 0x1e0d18}
HEADS = {'active': 0x1f6e40, 'inactive': 0x1f64e0, 'free': 0x1f6e48}


def save(name, value):
    (HERE / name).write_text(json.dumps(value, indent=2) + '\n')


def snapshot(uc):
    return {'cpu': T.snap(uc), 'objects': {hex(a): bytes(uc.mem_read(a, 0x58)).hex() for a in OBJECTS},
            'pages': {hex(a): bytes(uc.mem_read(a, 0x30)).hex() for a in PAGES},
            'buckets': bytes(uc.mem_read(BUCKETS, 8 * 8)).hex(),
            'template': bytes(uc.mem_read(TEMPLATE, 0x30)).hex(),
            'globals': {name: D.words(uc, a, 1)[0] for name, a in GLOBALS.items()},
            'queues': {name: D.words(uc, a, 2) for name, a in HEADS.items()},
            'vm_privilege': D.words(uc, Q.THREAD + 0x78, 1)[0],
            'physical_hash': F.T.hashlib.sha256(bytes(uc.mem_read(PHYS, PHYS_SIZE))).hexdigest(),
            'copy_buffer_hashes': T.buffer_hashes(uc),
            'object_guards': [bytes(uc.mem_read(a + 0x58, 0x100 - 0x58)).hex() for a in OBJECTS],
            'descriptor_guards': [bytes(uc.mem_read(a + 0x30, 0x100 - 0x30)).hex() for a in PAGES]}


def prepare_caller(uc, args):
    D.put(uc, CALL_STACK, D.STOP, *args)
    uc.reg_write(X.UC_X86_REG_ESP, CALL_STACK)
    for register, value in D.REGS.values():
        uc.reg_write(register, value)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)


def call(uc, entry, args, operations, name):
    prepare_caller(uc, args)
    before = snapshot(uc)
    failure, observation = None, None
    rep_observations = []
    write_count, last_alloc_writes = 0, []
    allowed = [(D.STACK - Q.PAGE + 32, CALL_STACK + (len(args) + 1) * D.WORD)]
    allowed += [(a, a + 0x58) for a in OBJECTS] + [(a, a + 0x30) for a in PAGES]
    allowed += [(BUCKETS, BUCKETS + 8 * 8)] + [(a, a + 8) for a in HEADS.values()]
    allowed += [(a, a + D.WORD) for a in GLOBALS.values()]
    def memory_write(engine, access, address, size, value, unused):
        nonlocal write_count
        assert any(start <= address and address + size <= end for start, end in allowed), ('out-of-contract write', hex(reg(engine, 'eip')), hex(address), size)
        write_count += 1
        if reg(engine, 'eip') == 0x17b52d:
            last_alloc_writes.append({'address': address, 'size': size, 'value': value})
    def checkpoint(engine, pc):
        assert pc not in (0x1631a0, 0x17a338, 0x10ca6c, 0x18b59b, 0x18b5dc, 0x18b5ef), hex(pc)
        if pc in (0x17b150, 0x17b384):
            rep_observations.append({'pc': hex(pc), 'ecx': reg(engine, 'ecx'), 'esi': reg(engine, 'esi'),
                                     'edi': reg(engine, 'edi'), 'df': reg(engine, 'eflags') & 0x400})
    hook = uc.hook_add(U.UC_HOOK_MEM_WRITE, memory_write)
    try:
        observation = T.high_run(uc, entry, {D.STOP}, True, checkpoint)
        assert observation['error'] is None and not observation['interrupts']
        assert reg(uc, 'eip') == D.STOP and reg(uc, 'esp') == CALL_STACK + D.WORD
        D.assert_callee_saved(uc)
        T.guard_check(uc)
    except Exception as exc:
        failure = repr(exc)
    finally:
        uc.hook_del(hook)
    row = {'name': name, 'entry': hex(entry), 'arguments': args, 'before': before,
           'observation': observation, 'rep_observations': rep_observations, 'write_count': write_count,
           'last_alloc_writes': last_alloc_writes, 'after': snapshot(uc), 'failure': failure}
    operations.append(row)
    save('latest-diagnostic.json', row)
    assert failure is None, failure
    return reg(uc, 'eax')


def mapped_frame_references(uc, frames, vm_size):
    matches = []
    pages = {frame + off for frame in frames for off in range(0, vm_size, Q.PAGE)}
    for target, root in Q.ROOTS.items():
        for pdi, pde in enumerate(D.words(uc, root, 1024)):
            if not pde & 1:
                continue
            assert not pde & 0x80, 'large PDE not supported by scan'
            for pti, pte in enumerate(D.words(uc, pde & ~0xfff, 1024)):
                if pte & 1 and pte & ~0xfff in pages:
                    matches.append({'root': target, 'va': (pdi << 22) | (pti << 12), 'pte': pte})
    return matches


def setup(target):
    uc, info, unused = F.setup(target, '_copyout', 'entry', 0x100, 2, 3)
    uc.mem_map(PHYS, PHYS_SIZE)
    uc.mem_write(PHYS, bytes((i * 19 + (i >> 7) + 0x53) & 0xff for i in range(PHYS_SIZE)))
    assert bytes(uc.mem_read(TEMPLATE, 0x30)) == bytes(0x30), 'zero BSS template prerequisite'
    prepare_caller(uc, ())
    prefix = T.high_run(uc, 0x17aa08, {0x17aade}, True)
    assert prefix['error'] is None and not prefix['interrupts'] and reg(uc, 'eip') == 0x17aade
    template = bytearray(0x30)
    template[0x1e], template[0x20] = 0x20, 1
    assert bytes(uc.mem_read(TEMPLATE, 0x30)) == template
    for head in HEADS.values():
        assert D.words(uc, head, 2) == [head, head]
    assert D.words(uc, 0x1f64e8, 1) == D.words(uc, 0x1f7418, 1) == [0]
    # Explicit caller-owned synthetic initialization AFTER the startup prefix.
    for obj in OBJECTS:
        uc.mem_write(obj, bytes([0xc3]) * 0x100)
        uc.mem_write(obj, bytes(0x58))
        D.put(uc, obj, obj, obj)
        D.put(uc, obj + 0x10, 1, info['vm_size'] * 32)
        uc.mem_write(obj + 0x18, (1).to_bytes(2, 'little'))
    for page in PAGES:
        uc.mem_write(page, bytes([0xa7]) * 0x100)
    uc.mem_write(BUCKETS, bytes(8 * 8))
    D.put(uc, 0x1f7438, BUCKETS, 7)
    shift = info['vm_size'].bit_length() - 1
    D.put(uc, 0x1f6ea4, shift)
    for key in ('active_count', 'inactive_count', 'free_count', 'reserved', 'minimum', 'target', 'inactive_target'):
        D.put(uc, GLOBALS[key], 0)
    D.put(uc, GLOBALS['queue_lock'], 1)
    D.put(uc, Q.THREAD + 0x78, 0)
    frames = [PHYS + i * info['vm_size'] for i in range(len(PAGES))]
    references = mapped_frame_references(uc, frames, info['vm_size'])
    assert not references
    info.update(startup_prefix=prefix, template=template.hex(), synthetic_frames=frames,
                mapped_frame_references=references, frame_scan_scope='complete A/B fixture roots; not all original PV/ownership',
                hash_shift=shift, synthetic_boundary='objects/hash arena/frame backing and caller locks; original startup prefix only')
    return uc, info


def case(target, seed, sequential, scenario):
    uc, info = setup(target)
    operations = []
    offsets = [info['vm_size'] * (3 + 8 * i) for i in range(len(PAGES))]
    privilege = int(scenario.endswith('_privileged'))
    if not scenario.startswith('empty'):
        for page, offset, frame in zip(PAGES, offsets, info['synthetic_frames']):
            call(uc, 0x17b134, [page, OBJECTS[0], offset, frame], operations, 'init')
        if seed == 'cached':
            before = snapshot(uc)
            for page in PAGES:
                flags = bytes(uc.mem_read(page + 0x20, 1))[0]
                assert flags == 5 and not bytes(uc.mem_read(page + 0x1e, 1))[0] & 8
                uc.mem_write(page + 0x20, bytes([flags & ~1]))
            operations.append({'name': 'seed_busy_clear', 'before': before, 'after': snapshot(uc),
                               'scope': 'synthetic preparation, wanted=0; not execution of pageout/PV removal'})
        for index in (1, 0, 2):
            page = PAGES[index]
            assert not bytes(uc.mem_read(page + 0x1e, 1))[0] & 8
            assert not bytes(uc.mem_read(page + 0x20, 1))[0] & 8
            call(uc, 0x17b5f8 if seed == 'cached' else 0x17b540, [page], operations, 'addfree' if seed == 'cached' else 'free')
    count = D.words(uc, GLOBALS['free_count'], 1)[0]
    reserved = count + 1 if scenario.startswith('below') else count if scenario.startswith('equal') else max(0, count - 1) if scenario.startswith('above') else 0
    before = snapshot(uc)
    D.put(uc, GLOBALS['reserved'], reserved)
    D.put(uc, Q.THREAD + 0x78, privilege)
    operations.append({'name': 'admission_configuration', 'reserved': reserved, 'privilege': privilege,
                       'before': before, 'after': snapshot(uc), 'scope': 'explicit pre-call synthetic configuration'})
    allocation_results = []
    for offset in offsets if scenario == 'cycle' else offsets[:1]:
        result = call(uc, 0x17b200, [OBJECTS[1], offset, sequential], operations, 'alloc')
        allocation_results.append(result)
        lookup = call(uc, 0x17af58, [OBJECTS[1], offset], operations, 'lookup')
        assert lookup == result
    if scenario == 'cycle':
        assert allocation_results == [PAGES[i] for i in (1, 0, 2)]
        assert call(uc, 0x17b200, [OBJECTS[1], offsets[-1] + info['vm_size'], sequential], operations, 'alloc') == 0
        for page in (PAGES[0], PAGES[1], PAGES[2]):
            call(uc, 0x17b540, [page], operations, 'free')
        for offset, page in zip(offsets, PAGES):
            assert call(uc, 0x17b200, [OBJECTS[0], offset, sequential], operations, 'alloc') == page
            assert call(uc, 0x17af58, [OBJECTS[0], offset], operations, 'lookup') == page
    else:
        expected = 0 if count == 0 or (count < reserved and not privilege) else PAGES[1]
        assert allocation_results == [expected]
    final = snapshot(uc)
    for op in operations:
        for key in ('physical_hash', 'copy_buffer_hashes', 'descriptor_guards', 'object_guards', 'template'):
            assert op['before'][key] == op['after'][key] == final[key]
        if 'observation' in op:
            assert op['after']['globals']['queue_lock'] == 1 and op['after']['globals']['free_lock'] == 0
            for field in ('cs', 'ds', 'es', 'ss', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4'):
                assert op['before']['cpu'][field] == op['after']['cpu'][field]
    return {'target': target, 'seed': seed, 'sequential': sequential, 'scenario': scenario,
            'fixture': info, 'offsets': offsets, 'operations': operations, 'final': final}


def main():
    before = preserved()
    save('preservation-before.json', before)
    scenarios = ('cycle', 'empty_ordinary', 'empty_privileged', 'below_ordinary', 'below_privileged',
                 'equal_ordinary', 'equal_privileged', 'above_ordinary', 'above_privileged')
    matrix = [('A', 'cached', 1, 'cycle')] if '--single' in sys.argv else itertools.product(('A', 'B'), ('detached', 'cached'), (0, 1), scenarios)
    cases = []
    for item in matrix:
        cases.append(case(*item))
        print(json.dumps({'case': len(cases), 'parameters': item}), flush=True)
    save('allocator-cases.json', cases)
    calls = [op for row in cases for op in row['operations'] if 'observation' in op]
    save('allocator-summary.json', {'fresh_cases': len(cases), 'original_calls': len(calls),
                                    'allocation_successes': sum(op['name'] == 'alloc' and op['after']['cpu']['eax'] != 0 for op in calls),
                                    'allocation_rejections': sum(op['name'] == 'alloc' and op['after']['cpu']['eax'] == 0 for op in calls),
                                    'cached_removal_calls': sum('0x17b2d0' in op['observation']['trace'] for op in calls),
                                    'pager_io_verified': False, 'whole_vm_creation_verified': False, 'whole_analysis_complete': False})
    after = preserved()
    assert before == after
    save('preservation-after.json', after)
    print((HERE / 'allocator-summary.json').read_text())


if __name__ == '__main__':
    main()
