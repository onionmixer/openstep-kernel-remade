"""Original copyout in mixed-CS synthetic mappings, plus observed paging faults.

No original patches/call mocks/IDT delivery. PLAN.md precedes this code.
All calculations are Python, including store ordering and expected memory effects.
"""
import collections
import importlib.util
import itertools
import json
from pathlib import Path
import sys
import traceback
from verify_artifacts import preserved, digest

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('mapping22', HERE.parent / 'continuous-review-20260911-22/user_mapping_review.py')
Q = importlib.util.module_from_spec(spec)
spec.loader.exec_module(Q)
R, D, U, X, P = Q.R, Q.D, Q.U, Q.X, Q.P
PAGE, BUFFER, SPAN = Q.PAGE, Q.BUFFER, Q.SPAN
TARGETS = {'_copyout': 0x189e70, '_copyoutmsg': 0x18a018}
INSTRUCTIONS = {name: R.function_instructions(R.NAMES[name]) for name in TARGETS}
ALL = {pc: ins for seq in INSTRUCTIONS.values() for pc, ins in seq.items()}
FS = {pc: ins for pc, ins in ALL.items() if ins.mnemonic == 'mov' and
      ins.operands[0].type == R.X86_OP_MEM and ins.reg_name(ins.operands[0].mem.segment) == 'fs'}
LENGTHS = (0, 1, 2, 3, 4, 7, 15, 16, 17, 19, 31, 32, 63, 64)
OFFSETS = (0x100, 0x101, 0x102, 0x103, 0xff0, 0xfff)


def reg(uc, name):
    return uc.reg_read(getattr(X, 'UC_X86_REG_' + name.upper()))


def control_gate(uc):
    for bit in (5, 7, 20, 21):
        assert not reg(uc, 'cr4') & (1 << bit)
    wanted = (1 << 31) | (1 << 16) | 1
    assert reg(uc, 'cr0') & wanted == wanted


def hook_coordinates(row, target):
    # Observation contract for this backend only. Hooks do not prove commitment.
    completed = row['store_attempts'][:-1] if row['interrupts'] else row['store_attempts']
    assert len(completed) == len(row['memory_write_hooks'])
    for attempt, hook in zip(completed, row['memory_write_hooks']):
        physical = int(attempt['linear'], 16) - BUFFER + Q.PAYLOAD[target]
        assert (attempt['pc'], physical, attempt['size'], attempt['value']) == (
            hook['pc'], int(hook['address'], 16), hook['size'], hook['value'])


def original_bytes(uc, trace):
    for pc in set(trace):
        ins = ALL[pc]
        assert bytes(uc.mem_read(pc, ins.size)) == ins.bytes, hex(pc)


def prepare(uc, target, name, length, source_offset, destination_offset):
    Q.reset_buffers(uc)
    source = Q.PATTERNS['kernel'][source_offset:source_offset + length]
    assert len(source) == length
    initial = bytearray(Q.PATTERNS[target])
    # Every intended destination byte differs from its incoming source byte.
    # This makes wrong-root/wrong-destination writes observable even for length 1.
    initial[destination_offset:destination_offset + length] = bytes(b ^ 0xff for b in source)
    uc.mem_write(Q.PAYLOAD[target], bytes(initial))
    expected = bytearray(initial)
    expected[destination_offset:destination_offset + length] = source
    D.put(uc, 0x1e8b54, Q.THREAD)
    D.put(uc, Q.THREAD + 0x74, 0)
    D.put(uc, D.STACK, D.STOP, BUFFER + source_offset, BUFFER + destination_offset, length)
    for register, value in D.REGS.values():
        uc.reg_write(register, value)
    uc.reg_write(X.UC_X86_REG_ESP, D.STACK)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    return bytes(initial), bytes(expected), source


def observe(uc, name, allow_fault=False):
    visits, attempts, hooks_seen, interrupts = [], [], [], []
    def code(engine, pc, size, unused):
        assert pc in INSTRUCTIONS[name], hex(pc)
        visits.append(pc)
        if pc in FS:
            ins = FS[pc]
            mem, src = ins.operands
            address = mem.mem.disp
            if mem.mem.base:
                address += reg(engine, ins.reg_name(mem.mem.base))
            if mem.mem.index:
                address += reg(engine, ins.reg_name(mem.mem.index)) * mem.mem.scale
            address &= 0xffffffff
            assert src.type == R.X86_OP_REG
            value = reg(engine, ins.reg_name(src.reg)) & ((1 << (mem.size * 8)) - 1)
            attempts.append({'pc': hex(pc), 'linear': hex(address), 'size': mem.size, 'value': hex(value)})
    def writes(engine, access, address, size, value, unused):
        pc = reg(engine, 'eip')
        if pc in FS:
            hooks_seen.append({'pc': hex(pc), 'address': hex(address), 'size': size, 'value': hex(value & ((1 << (size * 8)) - 1))})
    def interrupt(engine, vector, unused):
        interrupts.append({'vector': vector, 'eip': hex(reg(engine, 'eip')), 'cr2': hex(reg(engine, 'cr2')),
                           'recover': hex(D.words(engine, Q.THREAD + 0x74, 1)[0])})
        engine.emu_stop()
    handles = [uc.hook_add(U.UC_HOOK_CODE, code), uc.hook_add(U.UC_HOOK_MEM_WRITE, writes),
               uc.hook_add(U.UC_HOOK_INTR, interrupt)]
    entry = R.NAMES[name]
    uc.ctl_remove_cache(entry & -PAGE, (entry & -PAGE) + PAGE)
    error = None
    try:
        uc.emu_start(entry, D.STOP, timeout=1000000, count=20000)
    except U.UcError as exc:
        error = str(exc)
    finally:
        for h in handles:
            uc.hook_del(h)
    assert error is None, {'error': error, 'interrupts': interrupts, 'last_visits': visits[-8:]}
    if interrupts:
        assert allow_fault and len(interrupts) == 1
        assert interrupts[0]['vector'] == 14, interrupts
        assert int(interrupts[0]['eip'], 16) in FS
        assert interrupts[0]['recover'] == hex(TARGETS[name])
    else:
        assert reg(uc, 'eip') == D.STOP
        assert reg(uc, 'eax') == 0 and reg(uc, 'esp') == D.STACK + D.WORD
        assert D.words(uc, D.STACK, 1) == [D.STOP]
        D.assert_callee_saved(uc)
    original_bytes(uc, visits)
    return {'trace': list(map(hex, visits)), 'store_attempts': attempts,
            'memory_write_hooks': hooks_seen, 'interrupts': interrupts}


def buffers(uc, target, expected):
    assert bytes(uc.mem_read(Q.PAYLOAD[target], SPAN)) == expected
    assert bytes(uc.mem_read(BUFFER, SPAN)) == Q.PATTERNS['kernel']
    for other, physical in Q.PAYLOAD.items():
        if other != target:
            assert bytes(uc.mem_read(physical, SPAN)) == Q.PATTERNS[other]


def normal_case(uc, target, name, length, src, dst):
    initial, expected, source = prepare(uc, target, name, length, src, dst)
    row = observe(uc, name)
    hook_coordinates(row, target)
    buffers(uc, target, expected)
    recover, = D.words(uc, Q.THREAD + 0x74, 1)
    assert recover == (TARGETS[name] if length <= 15 else 0)
    # Replay original observed store operands into an independent expected buffer.
    replay = bytearray(initial)
    for event in row['store_attempts']:
        index = int(event['linear'], 16) - BUFFER
        width = event['size']
        assert dst <= index and index + width <= dst + length
        replay[index:index + width] = int(event['value'], 16).to_bytes(width, 'little')
    assert replay == expected
    assert sum(e['size'] for e in row['store_attempts']) == length
    # Direct/inactive-root destination counterfactuals leave active buffer untouched.
    assert (initial != expected) == bool(length)
    # Original _copyout changes caller destination only; msg uses local storage.
    destination_after = BUFFER + dst
    if name == '_copyout' and length > 15:
        alignment = (-(BUFFER + src)) & 3
        remaining = length - alignment
        destination_after += alignment
        if remaining & 3:
            destination_after += remaining & ~3
    expected_args = [BUFFER + src, destination_after, length]
    assert D.words(uc, D.STACK + D.WORD, 3) == expected_args
    for off, base in ((src, Q.BASE + BUFFER), (dst, BUFFER)):
        for i in range(length):
            mapping = P.walk(uc, Q.ROOTS[target], base + off + i)
            expected_physical = BUFFER + off + i if base != BUFFER else Q.PAYLOAD[target] + off + i
            assert mapping['present'] and int(mapping['physical'], 16) == expected_physical
    return dict(row, target=target, function=name, length=length, source_offset=src, destination_offset=dst,
                source_crosses=bool(length and src // PAGE != (src + length - 1) // PAGE),
                destination_crosses=bool(length and dst // PAGE != (dst + length - 1) // PAGE),
                recover_after=hex(recover), active_changed=initial != expected,
                caller_destination_slot_changed=destination_after != BUFFER + dst,
                caller_arguments_after=list(map(hex, D.words(uc, D.STACK + D.WORD, 3))))


def fault_case(target, name, mode, length, dst, bad_page, wp):
    uc, setup = Q.fixture()
    control_gate(uc)
    # Install permissions before selecting the target root. First-page reads stay
    # valid for Q.switch's scalar gate; even the first-page RO case remains readable.
    pte_address = Q.TABLES[target] + (((BUFFER + bad_page * PAGE) >> 12) & 0x3ff) * D.WORD
    old_pte, = D.words(uc, pte_address, 1)
    new_pte = old_pte if mode == 'writable' else old_pte & ~(1 if mode == 'not-present' else 2)
    D.put(uc, pte_address, new_pte)
    bad_mapping = P.walk(uc, Q.ROOTS[target], BUFFER + bad_page * PAGE)
    assert bad_mapping['present'] == (mode != 'not-present')
    if bad_mapping['present']:
        assert bad_mapping['writable'] == (mode == 'writable')
    high_mapping = P.walk(uc, Q.ROOTS[target], Q.BASE + BUFFER + bad_page * PAGE)
    assert high_mapping['present'] and high_mapping['writable']
    assert int(high_mapping['physical'], 16) == BUFFER + bad_page * PAGE
    cr0_before = reg(uc, 'cr0')
    cr0_new = cr0_before | (1 << 16) if wp else cr0_before & ~(1 << 16)
    ins = Q.decoded(0x18f323)
    uc.reg_write(X.UC_X86_REG_EBX, cr0_new)
    P.run(uc, ins.address, ins.address + ins.size)
    assert reg(uc, 'cr0') == cr0_new
    transition = Q.switch(uc, target)
    initial, complete, source = prepare(uc, target, name, length, 0x100, dst)
    row = observe(uc, name, allow_fault=True)
    hook_coordinates(row, target)
    should_fault = bool(length and (mode == 'not-present' or (mode == 'read-only' and wp)))
    assert bool(row['interrupts']) == should_fault
    if should_fault:
        fault = row['interrupts'][0]
        pending = row['store_attempts'][-1]
        pending_address = int(pending['linear'], 16)
        assert pending_address // PAGE == (pending_address + pending['size'] - 1) // PAGE
        assert pending['pc'] == fault['eip']
        assert fault['cr2'] == pending['linear']
        expected = bytearray(initial)
        for event in row['store_attempts'][:-1]:
            address, width = int(event['linear'], 16), event['size']
            assert address // PAGE == (address + width - 1) // PAGE
            index = address - BUFFER
            expected[index:index + width] = int(event['value'], 16).to_bytes(width, 'little')
        # Independent expected commitment for explicitly aligned, non-straddling cases.
        committed = 0 if bad_page == 0 else 16
        independent = bytearray(initial)
        independent[dst:dst + committed] = source[:committed]
        assert expected == independent
        buffers(uc, target, bytes(expected))
        assert D.words(uc, Q.THREAD + 0x74, 1) == [TARGETS[name]]
        if length == 19:
            assert int(pending['linear'], 16) == BUFFER + dst + 18
            assert bytes(expected[dst + 16:dst + 18]) == initial[dst + 16:dst + 18]
    else:
        committed = length
        buffers(uc, target, complete)
        assert D.words(uc, Q.THREAD + 0x74, 1) == [TARGETS[name] if length <= 15 else 0]
    actual = bytes(uc.mem_read(Q.PAYLOAD[target], SPAN))
    assert sum(a != b for a, b in zip(initial, actual)) == committed
    return dict(row, target=target, function=name, mode=mode, wp=wp, length=length, destination_offset=dst,
                bad_page=bad_page, pte_address=hex(pte_address), pte_before=hex(old_pte), pte_installed=hex(new_pte),
                cr0_before=hex(cr0_before), cr0_after=hex(cr0_new), transition=transition,
                controlled_low_mapping=bad_mapping, unchanged_high_mapping=high_mapping,
                destination_before=initial[dst:dst + length].hex(), destination_after=actual[dst:dst + length].hex(),
                paging_fault_observed=should_fault, bytes_committed_before_stop=committed,
                actual_trap_handler_or_recovery_executed=False)


def inventory(visited):
    missed = sorted(set(FS) - visited)
    assert missed == [0x189da9, 0x189f51], list(map(hex, missed))
    proof = [{'source_mod4': r, 'alignment_bytes': 4 - r, 'dword_iterations': (4 - r) >> 2} for r in range(1, 4)]
    assert all(row['dword_iterations'] == 0 for row in proof)
    return {'owners': {name: {'entry': hex(R.NAMES[name]), 'instructions': len(seq),
                             'fs_stores': sum(pc in FS for pc in seq),
                             'rep_instructions': sum(i.mnemonic.startswith('rep ') for i in seq.values())}
                       for name, seq in INSTRUCTIONS.items()},
            'fs_store_sites': list(map(hex, sorted(FS))), 'normal_unvisited_fs_stores': list(map(hex, missed)),
            'alignment_arithmetic': proof,
            'limits': 'Matches prior report02 normal-entry alignment proof; not arbitrary mid-function entry coverage.'}


def main():
    before = preserved()
    (HERE / 'preservation-before.json').write_text(json.dumps(before, indent=2) + '\n')
    uc, setup = Q.fixture()
    # Restrict model features relevant to this non-PAE, supervisor-mode experiment.
    control_gate(uc)
    for pattern in Q.PATTERNS.values():
        assert all(a != b for a, b in zip(pattern[:PAGE], pattern[PAGE:]))
    normal, transitions, faults = [], [], []
    for target in ('A', 'B', 'B', 'A'):
        transitions.append(Q.switch(uc, target))
        for name, length, src, dst in itertools.product(TARGETS, LENGTHS, OFFSETS, OFFSETS):
            normal.append(normal_case(uc, target, name, length, src, dst))
        print(json.dumps({'stage': len(transitions), 'normal_cases': len(normal)}), flush=True)
    (HERE / 'normal-copyout.json').write_text(json.dumps({'setup': setup, 'transitions': transitions, 'cases': normal}, indent=2) + '\n')
    conditions = [('read-only', 1, 0x100, 0, 1), ('read-only', 0, 0x100, 0, 1)]
    conditions += [(mode, length, PAGE - prefix, 1, wp)
                   for mode in ('writable', 'read-only', 'not-present')
                   for length, prefix in ((32, 16), (19, 18)) for wp in (0, 1)]
    for target, name, condition in itertools.product(Q.ROOTS, TARGETS, conditions):
        mode, length, dst, page, wp = condition
        faults.append(fault_case(target, name, mode, length, dst, page, wp))
        print(json.dumps({'paging_condition_cases': len(faults), 'last_fault': faults[-1]['paging_fault_observed']}), flush=True)
    (HERE / 'paging-copyout.json').write_text(json.dumps({'cases': faults}, indent=2) + '\n')
    visited = {int(pc, 16) for row in normal for pc in row['trace']}
    summary = {'normal_copy_cases': len(normal), 'normal_source_crossing_cases': sum(r['source_crosses'] for r in normal),
               'normal_destination_crossing_cases': sum(r['destination_crosses'] for r in normal),
               'normal_both_crossing_cases': sum(r['source_crosses'] and r['destination_crosses'] for r in normal),
               'normal_zero_length_controls': sum(r['length'] == 0 for r in normal),
               'normal_wrong_destination_or_inactive_root_discriminating_cases': sum(r['active_changed'] for r in normal),
               'normal_fs_store_sites_visited': len(visited & set(FS)),
               'caller_destination_slot_changed_cases': sum(r['caller_destination_slot_changed'] for r in normal),
               'paging_condition_cases': len(faults), 'observed_page_faults': sum(r['paging_fault_observed'] for r in faults),
               'faults_after_partial_writes': sum(r['paging_fault_observed'] and bool(r['bytes_committed_before_stop']) for r in faults),
               'tail_high_offset_first_fault_cases': sum(r['paging_fault_observed'] and r['length'] == 19 for r in faults),
               'full_trap_or_context_switch_proven': False}
    result = {'summary': summary, 'inventory': inventory(visited),
              'binary_sha256': digest(R.ROOT / '03_original/x86/binaries/mach_kernel'),
              'limits': ['Mixed CS-flat/DS-ES-SS-high/FS-flat synthetic CPU state inherited from report22.',
                         'User roots/tables synthesized, not original user-pmap constructor output.',
                         'Vector14 observation stopped before IDT/trap handler/recovery/IRETD.',
                         'Page-fault error-code bits are not captured or verified.',
                         'Memory hooks are emulator callbacks, not bus events or proof of committed stores.',
                         'Final buffers and original store operands validate tested non-straddling fault effects.',
                         'No permission claim for CPL3, descriptor limits, POP FS or hardware TLB/cache behavior.']}
    (HERE / 'copyout-review.json').write_text(json.dumps(result, indent=2) + '\n')
    assert preserved() == before
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    try:
        main()
    except Exception:
        existing = sorted(HERE.glob('fixture-failure-*.txt'))
        (HERE / f'fixture-failure-{len(existing):02d}.txt').write_text(traceback.format_exc())
        raise
