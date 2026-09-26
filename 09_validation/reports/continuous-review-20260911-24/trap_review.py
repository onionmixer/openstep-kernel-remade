"""Original high-CS trap path. Synthetic CPU-frame boundary is explicit."""
import importlib.util
import itertools
import hashlib
import json
from pathlib import Path
import sys
from verify_artifacts import preserved

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('copy23', HERE.parent / 'continuous-review-20260911-23/copyout_review.py')
S = importlib.util.module_from_spec(spec)
spec.loader.exec_module(S)
Q, P, R, D, U, X = S.Q, S.P, S.R, S.D, S.U, S.X
BASE, PAGE = Q.BASE, Q.PAGE
reg = S.reg
TASK, MAP, UTHREAD = (Q.THREAD + off for off in (0x200, 0x400, 0x800))
FIELDS = ('gs', 'fs', 'es', 'ds', 'edi', 'esi', 'ebp', 'pushad_esp', 'ebx', 'edx',
          'ecx', 'eax', 'trap', 'error', 'eip', 'cs', 'eflags')
OFFSETS = {name: index * D.WORD for index, name in enumerate(FIELDS)}
FRAME_SIZE = len(FIELDS) * D.WORD
GUARDS = {D.STACK - PAGE: bytes([0xa7]) * 32,
          D.STACK + D.WORD * 4: bytes([0x5d]) * 32}


def save(name, data):
    (HERE / name).write_text(json.dumps(data, indent=2) + '\n')


def snap(uc):
    return {n: reg(uc, n) for n in ('eax', 'ebx', 'ecx', 'edx', 'esi', 'edi', 'ebp', 'esp',
                                   'eip', 'eflags', 'cs', 'ds', 'es', 'ss', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4')}


def idt(uc):
    D.put(uc, D.STACK, D.STOP)
    uc.reg_write(X.UC_X86_REG_ESP, D.STACK)
    P.run(uc, 0x18b1a4, D.STOP)
    low = list(uc.reg_read(X.UC_X86_REG_IDTR))
    P.run(uc, 0x18ab94, 0x18aba4)
    high = list(uc.reg_read(X.UC_X86_REG_IDTR))
    pointer = D.words(uc, 0x1e2204, 1)[0]
    assert low[1] == pointer and high[1] == BASE + pointer and high[2] == 0x7ff
    addr = pointer + 14 * 8
    raw = bytes(uc.mem_read(addr, 8))
    offset = int.from_bytes(raw[:2], 'little') | (int.from_bytes(raw[6:], 'little') << 16)
    selector = int.from_bytes(raw[2:4], 'little')
    assert offset == 0x1861cc and selector == 8 and raw[5] == 0x8f
    original = R.read_original(0x1e1a04 + 14 * 8, 8)
    assert int.from_bytes(original[:4], 'little') == offset
    assert int.from_bytes(original[4:], 'little') == 0x000f0008
    stub = list(R.CS.disasm(R.read_original(offset, 7), offset))
    assert stub[0].mnemonic == 'push' and stub[0].operands[0].imm == 14
    assert stub[1].mnemonic == 'jmp' and stub[1].operands[0].imm == 0x186d20
    walks = [P.walk(uc, reg(uc, 'cr3'), BASE + addr + off) for off in (0, len(raw) - 1)]
    for off, walk in zip((0, len(raw) - 1), walks):
        assert walk['present'] and int(walk['physical'], 16) == addr + off
    return {'low_idtr': low, 'high_idtr': high, 'vector14': raw.hex(), 'handler_offset': hex(offset),
            'selector': selector, 'type': 'trap gate', 'original_table': original.hex(),
            'vector14_high_mapping': walks,
            'stub': [{'pc': hex(i.address), 'bytes': i.bytes.hex(), 'asm': i.mnemonic + ' ' + i.op_str} for i in stub]}


def far_jump(uc):
    trace = []
    h = uc.hook_add(U.UC_HOOK_CODE, lambda u, pc, size, data: trace.append({'hook_pc': hex(pc), 'eip': hex(reg(u, 'eip'))}))
    try:
        uc.emu_start(0x186110, 0, timeout=1000000, count=1)
    finally:
        uc.hook_del(h)
    assert reg(uc, 'cs') == 8 and reg(uc, 'eip') == 0x186117
    return {'trace': trace, 'after': snap(uc)}


def coordinate_gate():
    rows = []
    for begin_kind in ('offset', 'linear'):
        uc, info = Q.fixture()
        gate = idt(uc)
        jump = far_jump(uc)
        visits = []
        h = uc.hook_add(U.UC_HOOK_CODE, lambda u, pc, size, data: visits.append({'hook_pc': hex(pc), 'eip': hex(reg(u, 'eip'))}))
        error = None
        try:
            uc.emu_start(0x186117 + (BASE if begin_kind == 'linear' else 0), 0, timeout=1000000, count=1)
        except U.UcError as exc:
            error = str(exc)
        finally:
            uc.hook_del(h)
        rows.append({'begin_kind': begin_kind, 'fixture': info, 'idt': gate, 'far_jump': jump,
                     'visits': visits, 'error': error, 'after': snap(uc)})
    save('coordinate-gate.json', rows)
    good, bad = rows
    assert good['error'] is None and good['visits'] == [{'hook_pc': hex(BASE + 0x186117), 'eip': hex(0x186117)}]
    assert good['after']['eip'] == 0x18611b and good['after']['eax'] & 0xffff == 0x10
    assert bad['error'] is not None and not bad['visits']
    return rows


def high_run(uc, entry, stops, interrupt_observer=False, checkpoint=None):
    visits, interrupts = [], []
    code_pages = {}
    stack_positions = []
    def code(engine, linear, size, unused):
        pc = linear - BASE
        assert reg(engine, 'cs') == 8 and reg(engine, 'eip') == pc, (hex(linear), snap(engine))
        if pc in stops:
            engine.emu_stop()
            return
        assert 0 <= pc < 0x1000000, hex(linear)
        root = reg(engine, 'cr3')
        for endpoint in (linear, linear + size - 1):
            page = endpoint & -PAGE
            key = (root, page)
            if key not in code_pages:
                walk = P.walk(engine, root, page)
                assert walk['present'] and int(walk['physical'], 16) == page - BASE
                code_pages[key] = walk
        esp = reg(engine, 'esp')
        assert D.STACK - PAGE + len(GUARDS[D.STACK - PAGE]) <= esp <= D.STACK + D.WORD
        stack_positions.append(esp)
        ins = Q.decoded(pc)
        assert ins.size == size and bytes(engine.mem_read(pc, size)) == ins.bytes
        visits.append(pc)
        if checkpoint:
            checkpoint(engine, pc)
    def intr(engine, vector, unused):
        interrupts.append({'vector': vector, 'snapshot': snap(engine),
                           'recover': D.words(engine, Q.THREAD + 0x74, 1)[0]})
        engine.emu_stop()
    hooks = [uc.hook_add(U.UC_HOOK_CODE, code)]
    if interrupt_observer:
        hooks.append(uc.hook_add(U.UC_HOOK_INTR, intr))
    error = None
    try:
        uc.ctl_remove_cache(BASE + (entry & -PAGE), BASE + (entry & -PAGE) + PAGE)
        uc.emu_start(entry, 0, timeout=3000000, count=20000)
    except U.UcError as exc:
        error = str(exc)
    finally:
        for handle in hooks:
            uc.hook_del(handle)
    Q.original_bytes(uc, visits)
    return {'trace': list(map(hex, visits)), 'interrupts': interrupts, 'error': error, 'after': snap(uc),
            'code_page_walks': list(code_pages.values()),
            'observed_esp_min': min(stack_positions) if stack_positions else None,
            'observed_esp_max': max(stack_positions) if stack_positions else None}


def guard_check(uc):
    for address, expected in GUARDS.items():
        assert bytes(uc.mem_read(address, len(expected))) == expected, hex(address)


def buffer_hashes(uc):
    return {name: hashlib.sha256(bytes(uc.mem_read(address, Q.SPAN))).hexdigest()
            for name, address in dict(Q.PAYLOAD, kernel=Q.BUFFER).items()}


def setup(target, name, mode, length, destination, flags):
    uc, info = Q.fixture()
    S.control_gate(uc)
    info['idt'] = idt(uc)
    page_offset = 0 if length == 1 else PAGE
    address = Q.BUFFER + page_offset
    mapping = P.walk(uc, Q.ROOTS[target], address)
    pte_address = int(mapping['pte_address'], 16)
    pte = D.words(uc, pte_address, 1)[0]
    if mode != 'writable':
        D.put(uc, pte_address, pte & ~(2 if mode == 'ro' else 1))
    info['destination_mapping'] = P.walk(uc, Q.ROOTS[target], address)
    # The low first page must stay readable for Q.switch's original FS gate.
    info['switch'] = Q.switch(uc, target)
    initial, expected, source = S.prepare(uc, target, name, length, 0x100, destination)
    for address, content in GUARDS.items():
        uc.mem_write(address, content)
    info['far_jump'] = far_jump(uc)
    uc.reg_write(X.UC_X86_REG_EFLAGS, flags)
    return uc, info, initial, expected, source


def native_trial():
    uc, info, initial, expected, source = setup('A', '_copyout', 'np', 19, PAGE - 18, 2)
    before = snap(uc)
    observation = high_run(uc, R.NAMES['_copyout'], {0x1861cc, D.STOP})
    delivered = reg(uc, 'eip') == 0x1861cc
    row = {'fixture': info, 'before': before, 'observation': observation,
           'native_idt_handler_reached': delivered, 'intr_hook_installed': False,
           'recover_after': D.words(uc, Q.THREAD + 0x74, 1)[0], 'buffer_hashes_after': buffer_hashes(uc)}
    guard_check(uc)
    save('native-delivery.json', row)
    return row


def model_frame(fault, error):
    # Saved EFLAGS is an explicit input, not a claim about CPU-generated RF.
    values = dict(fault)
    values.update(pushad_esp=fault['esp'] - 5 * D.WORD, trap=14, error=error)
    return {name: values[name] for name in FIELDS}


def empty_map(uc):
    uc.mem_write(MAP, bytes(0x40))
    D.put(uc, Q.THREAD + 0xc, TASK)
    D.put(uc, TASK + 0xc, MAP)
    sentinel = MAP + 0xc
    D.put(uc, sentinel, sentinel, sentinel, 0, 0xbfffffff)
    D.put(uc, MAP + 0x38, sentinel)
    D.put(uc, 0x1e875c, UTHREAD)
    uc.mem_write(UTHREAD + 0x68, bytes([0xa5]))
    D.put(uc, 0x1f74d4, 0)
    return bytes(uc.mem_read(MAP, 0x40))


def fault_case(target, name, mode, length, destination, flags):
    uc, info, initial, expected, source = setup(target, name, mode, length, destination, flags)
    attempts = []
    def copy_hook(engine, pc):
        if pc in S.FS:
            ins = S.FS[pc]
            mem, src = ins.operands
            addr = mem.mem.disp
            if mem.mem.base:
                addr += reg(engine, ins.reg_name(mem.mem.base))
            if mem.mem.index:
                addr += reg(engine, ins.reg_name(mem.mem.index)) * mem.mem.scale
            addr &= 0xffffffff
            attempts.append({'pc': pc, 'address': addr, 'width': mem.size,
                             'value': reg(engine, ins.reg_name(src.reg)) & ((1 << (8 * mem.size)) - 1)})
    fault_run = high_run(uc, R.NAMES[name], {D.STOP}, True, copy_hook)
    assert fault_run['error'] is None and len(fault_run['interrupts']) == 1
    event = fault_run['interrupts'][0]
    assert event['vector'] == 14 and event['recover'] == S.TARGETS[name]
    fault = event['snapshot']
    assert fault == snap(uc) and fault['eip'] == attempts[-1]['pc']
    assert fault['cr2'] == attempts[-1]['address']
    pending = attempts[-1]
    assert pending['address'] // PAGE == (pending['address'] + pending['width'] - 1) // PAGE
    partial = bytearray(initial)
    committed = 0 if length == 1 else 16
    partial[destination:destination + committed] = source[:committed]
    replay = bytearray(initial)
    for attempt in attempts[:-1]:
        index = attempt['address'] - Q.BUFFER
        assert attempt['address'] // PAGE == (attempt['address'] + attempt['width'] - 1) // PAGE
        replay[index:index + attempt['width']] = attempt['value'].to_bytes(attempt['width'], 'little')
    assert replay == partial
    S.buffers(uc, target, partial)
    guard_check(uc)
    fault_buffer_hashes = buffer_hashes(uc)
    assert sum(a['width'] for a in attempts[:-1]) == committed
    map_before = empty_map(uc)
    counter_before = D.words(uc, 0x1f6514, 1)[0]
    caller_before = bytes(uc.mem_read(fault['esp'], D.STACK + 4 * D.WORD - fault['esp']))
    error = (1 if mode == 'ro' else 0) | 2
    expected_frame = model_frame(fault, error)
    frame_ptr = fault['esp'] - FRAME_SIZE
    cpu_ptr = fault['esp'] - 4 * D.WORD
    # Only this explicit boundary writes the CPU part of the exception frame.
    D.put(uc, cpu_ptr, error, fault['eip'], fault['cs'], fault['eflags'])
    uc.reg_write(X.UC_X86_REG_ESP, cpu_ptr)
    milestones = []
    frame_capture = {}
    def check(engine, pc):
        points = (0x187068, 0x172038, 0x178040, 0x178131, 0x1924a0, 0x192213,
                  0x186d72, 0x186d7c, S.TARGETS[name])
        if pc not in points:
            return
        state = snap(engine)
        words = D.words(engine, frame_ptr, len(FIELDS))
        row = {'pc': hex(pc), 'snapshot': state, 'saved_state_words': words,
               'map_lock': bytes(engine.mem_read(MAP, 0xc)).hex(),
               'uthread_byte': bytes(engine.mem_read(UTHREAD + 0x68, 1)).hex(),
               'recover': D.words(engine, Q.THREAD + 0x74, 1)[0]}
        if pc == 0x187068:
            assert D.words(engine, state['esp'] + D.WORD, 1) == [frame_ptr]
            for index, field in enumerate(FIELDS):
                mask = 0xffff if field in ('gs', 'fs', 'es', 'ds', 'cs') else 0xffffffff
                assert words[index] & mask == expected_frame[field] & mask, (field, words[index], expected_frame[field])
            assert not state['eflags'] & 0x400
            assert state['eflags'] & 0x200 == fault['eflags'] & 0x200
            frame_capture['original'] = bytes(engine.mem_read(frame_ptr, FRAME_SIZE))
        if pc == 0x172038:
            args = D.words(engine, state['esp'] + D.WORD, 5)
            assert args == [MAP, fault['cr2'] & ~D.words(engine, 0x1e89ec, 1)[0], 3, 0, 0], args
            assert row['uthread_byte'] == '00'
            row['arguments'] = args
        if pc == 0x178040:
            assert int.from_bytes(engine.mem_read(MAP + 4, 2), 'little') == 1
        if pc == 0x178131:
            assert bytes(engine.mem_read(MAP, 0x40)) == map_before
        if pc == 0x1924a0:
            assert D.words(engine, state['esp'] + D.WORD, 1) == [frame_ptr + OFFSETS['error']]
            assert row['uthread_byte'] == 'a5'
        if pc == 0x192213:
            assert state['eax'] == 1 and row['recover'] == 0
            wanted = bytearray(frame_capture['original'])
            for field, value, width in (('eip', S.TARGETS[name], D.WORD), ('cs', 8, 2),
                                        ('eflags', fault['eflags'] & ~0x400, D.WORD)):
                offset = OFFSETS[field]
                wanted[offset:offset + width] = value.to_bytes(width, 'little')
            assert bytes(engine.mem_read(frame_ptr, FRAME_SIZE)) == wanted
            row['exact_frame_delta_verified'] = True
            for index, field in enumerate(FIELDS):
                mask = 0xffff if field in ('gs', 'fs', 'es', 'ds', 'cs') else 0xffffffff
                value = expected_frame[field]
                if field == 'eip':
                    value = S.TARGETS[name]
                elif field == 'cs':
                    value = 8
                elif field == 'eflags':
                    value &= ~0x400
                assert words[index] & mask == value & mask, field
        if pc == 0x186d7c:
            assert state['esp'] == fault['esp'] - 3 * D.WORD
            for field in ('eax', 'ebx', 'ecx', 'edx', 'esi', 'edi', 'ebp', 'ds', 'es', 'fs', 'gs', 'ss'):
                assert state[field] == fault[field], field
            assert D.words(engine, state['esp'], 3) == [S.TARGETS[name], 8, fault['eflags'] & ~0x400]
        if pc == S.TARGETS[name]:
            assert state['esp'] == fault['esp']
            assert state['eflags'] == fault['eflags'] & ~0x400
            assert bytes(engine.mem_read(fault['esp'], len(caller_before))) == caller_before
        milestones.append(row)
    handler = high_run(uc, 0x1861cc, {D.STOP}, True, check)
    result = {'target': target, 'function': name, 'mode': mode, 'length': length,
              'destination': destination, 'initial_flags': flags, 'fixture': info,
              'fault_run': fault_run, 'store_attempts': attempts, 'committed_bytes': committed,
              'fault_buffer_hashes': fault_buffer_hashes,
              'synthetic_cpu_frame': {'address': cpu_ptr, 'error': error, 'saved_eflags': fault['eflags'],
                                      'hardware_error_and_RF_verified': False, 'same_cpl': True},
              'frame_offsets': OFFSETS, 'frame_size': FRAME_SIZE, 'milestones': milestones, 'handler': handler}
    save('latest-case.json', result)
    assert handler['error'] is None and not handler['interrupts'], handler
    assert reg(uc, 'eip') == D.STOP and reg(uc, 'eax') == 14
    assert reg(uc, 'esp') == D.STACK + D.WORD
    D.assert_callee_saved(uc)
    assert bytes(uc.mem_read(MAP, 0x40)) == map_before
    assert bytes(uc.mem_read(UTHREAD + 0x68, 1)) == bytes([0xa5])
    assert D.words(uc, 0x1f6514, 1)[0] == (counter_before + 1) & 0xffffffff
    assert D.words(uc, Q.THREAD + 0x74, 1)[0] == 0
    assert reg(uc, 'cr2') == fault['cr2'] and reg(uc, 'cr3') == Q.ROOTS[target]
    assert reg(uc, 'eflags') & 0x600 == flags & 0x200
    S.buffers(uc, target, partial)
    guard_check(uc)
    assert [m['pc'] for m in milestones] == list(map(hex, (0x187068, 0x172038, 0x178040, 0x178131,
           0x1924a0, 0x192213, 0x186d72, 0x186d7c, S.TARGETS[name])))
    assert '0x172084' not in handler['trace'] and '0x1631a0' not in handler['trace']
    result['checks_passed'] = True
    return result


def normal_case(target, name, length, flags):
    destination = PAGE - 18
    uc, info, initial, expected, source = setup(target, name, 'writable', length, destination, flags)
    observation = high_run(uc, R.NAMES[name], {D.STOP}, True)
    assert observation['error'] is None and not observation['interrupts']
    assert reg(uc, 'eip') == D.STOP and reg(uc, 'eax') == 0
    assert reg(uc, 'esp') == D.STACK + D.WORD
    D.assert_callee_saved(uc)
    S.buffers(uc, target, expected)
    guard_check(uc)
    recover = D.words(uc, Q.THREAD + 0x74, 1)[0]
    assert recover == (S.TARGETS[name] if length <= 15 else 0)
    assert reg(uc, 'eflags') & 0x600 == flags & 0x600
    assert reg(uc, 'cr3') == Q.ROOTS[target]
    return {'target': target, 'function': name, 'length': length, 'flags': flags,
            'fixture': info, 'observation': observation, 'recover_after': recover,
            'buffer_hashes_after': buffer_hashes(uc), 'checks_passed': True}


def main():
    save('preservation-before.json', preserved())
    rows = coordinate_gate()
    print('high-CS offset / linear coordinate gates passed', flush=True)
    native = native_trial()
    print('native IDT reached:', native['native_idt_handler_reached'], 'error:', native['observation']['error'], flush=True)
    normal, faults = [], []
    flag_inputs = tuple(2 | df | interrupt for df, interrupt in itertools.product((0, 0x400), (0, 0x200)))
    for target, name, length, flags in itertools.product(Q.ROOTS, S.TARGETS, (1, 19), flag_inputs):
        normal.append(normal_case(target, name, length, flags))
    save('normal-high-cs.json', normal)
    print('normal high-CS controls:', len(normal), flush=True)
    scenarios = (('ro', 1, 0x100), ('ro', 32, PAGE - 16), ('np', 32, PAGE - 16),
                 ('ro', 19, PAGE - 18), ('np', 19, PAGE - 18))
    for target, name, scenario, flags in itertools.product(Q.ROOTS, S.TARGETS, scenarios, flag_inputs):
        mode, length, destination = scenario
        faults.append(fault_case(target, name, mode, length, destination, flags))
        if len(faults) % 10 == 0:
            print('connected trap cases:', len(faults), flush=True)
    save('trap-cases.json', faults)
    comparison = next(r for r in faults if (r['target'], r['function'], r['mode'], r['length'], r['initial_flags']) ==
                      ('A', '_copyout', 'np', 19, 2))
    assert not native['native_idt_handler_reached'] and native['observation']['error'] is not None
    assert native['observation']['after'] == comparison['fault_run']['after']
    assert native['recover_after'] == comparison['fault_run']['interrupts'][0]['recover']
    assert native['buffer_hashes_after'] == comparison['fault_buffer_hashes']
    summary = {'normal_high_cs_cases': len(normal), 'connected_synthetic_frame_cases': len(faults),
               'observed_page_faults': len(faults), 'partial_write_cases': sum(r['committed_bytes'] > 0 for r in faults),
               'df_cleared_cases': sum(bool(r['initial_flags'] & 0x400) for r in faults),
               'if_preserved_cases': len(faults), 'original_iretd_executions': sum(r['handler']['trace'].count('0x186d7c') for r in faults),
               'native_idt_delivery_verified': False, 'native_and_hooked_fault_snapshots_equal': True,
               'hardware_error_code_or_frame_creation_verified': False,
               'frame_size': FRAME_SIZE, 'frame_offsets': OFFSETS,
               'handler_unique_instruction_heads': len({pc for r in faults for pc in r['handler']['trace']}),
               'original_handler_instruction_visits': sum(len(r['handler']['trace']) for r in faults),
               'all_calls_original_unmocked': True, 'vm_outcome_scope': 'synthetic empty map lookup miss only',
               'whole_analysis_complete': False}
    save('trap-review.json', summary)
    save('preservation-after.json', preserved())
    print(json.dumps(summary, indent=2), flush=True)


if __name__ == '__main__':
    main()
