"""Follow the remaining saved AF bit through original direct calls.

Bit-specific first-access proof, plus paired bounded execution with synthetic
ROM/PIC state. This is not a general taint engine or a hardware experiment.
"""
import collections
import hashlib
import importlib.util
import itertools
import json
from pathlib import Path
import struct
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('previous', HERE.parent / 'continuous-review-20260911-15/snapshot_review.py')
S = importlib.util.module_from_spec(spec)
spec.loader.exec_module(S)
R, F, D, X = S.R, S.F, S.D, S.X
ROOT = R.ROOT
ENTRIES = (0x18c4b4, 0x18c7b0, 0x1946e0, 0x101efc)
INS = {e: R.function_instructions(e) for e in ENTRIES}
COUNTER, MODE, INIT, PRESENT, SIGNATURE, ROM, TABLE = (0x1e7618, 0x1e7720, 0x1e7744, 0x1e2c50, 0x1e2c54, 0xfffd9, 0x1e2208)
START, CAPTURED, STOP = 0x18c578, 0x18c581, 0x18c596
AF, IF = 1 << 4, 1 << 9


def first_access():
    """Track EAX bit 4 until overwrite, read, escape, or unknown call.

    No copies encountered before killing; any source read is conservatively
    unresolved. AL/AX/EAX pure writes kill bit 4; AH does not. XOR r,r kills it.
    """
    relevant = {F.X.X86_REG_EAX, F.X.X86_REG_AX, F.X.X86_REG_AL}
    initial = (ENTRIES[0], CAPTURED, ())
    queue = collections.deque([(initial, [])])
    seen, endpoints, edges = set(), [], {}
    graphs = {e: F.graph(ins) for e, ins in INS.items()}
    while queue:
        state, path = queue.popleft()
        if state in seen:
            continue
        seen.add(state)
        owner, pc, stack = state
        ins = INS[owner][pc]
        witness = path + [pc]
        reads, writes = map(set, ins.regs_access())
        next_states, kind = [], None
        zero = (ins.mnemonic == 'xor' and len(ins.operands) == 2 and
                all(o.type == R.X86_OP_REG for o in ins.operands) and
                ins.operands[0].reg == ins.operands[1].reg and ins.operands[0].reg in relevant)
        if zero:
            kind = 'zero_idiom_kill'
        elif reads & relevant:
            kind = 'unresolved_bit_container_read'
        elif writes & relevant:
            kind = 'pure_write_kill'
        elif F.C.CS_GRP_CALL in ins.groups:
            if (ins.operands[0].type == R.X86_OP_IMM and ins.operands[0].imm in INS and len(stack) < len(ENTRIES)):
                target = ins.operands[0].imm
                next_states = [(target, target, stack + ((owner, pc + ins.size),))]
            else:
                kind = 'unresolved_call'
        elif F.C.CS_GRP_RET in ins.groups:
            if stack:
                return_owner, return_pc = stack[-1]
                next_states = [(return_owner, return_pc, stack[:-1])]
            else:
                kind = 'unresolved_top_return'
        else:
            succ, _, escapes = graphs[owner]
            if not succ[pc] or any(int(e['site'], 16) == pc for e in escapes):
                kind = 'unresolved_escape'
            else:
                next_states = [(owner, target, stack) for target in succ[pc]]
        edges[state] = next_states
        if kind:
            endpoints.append({'kind': kind, 'owner': f'{owner:08x}', **S.dis(ins),
                              'witness': [f'{a:08x}' for a in witness], 'call_depth': len(stack)})
        queue.extend((n, witness) for n in next_states)
    active, done = set(), set()

    def cyclic(state):
        if state in active:
            return True
        if state in done:
            return False
        active.add(state)
        found = any(cyclic(n) for n in edges[state])
        active.remove(state)
        done.add(state)
        return found

    cycle = cyclic(initial)
    assert not cycle and endpoints
    assert all(e['kind'] in ('pure_write_kill', 'zero_idiom_kill') for e in endpoints)
    return {'start': f'{CAPTURED:08x}', 'tracked_register_bit': 4,
            'visited_call_context_states': len(seen), 'cycle': cycle, 'endpoints': endpoints,
            'all_reachable_first_accesses_kill_saved_af_bit': True,
            'limits': ['Only the saved AF bit in EAX, not all saved flag bits or CPU EFLAGS.',
                       'Direct calls within explicit original functions; no interrupt/fault/indirect entry.',
                       'No memory-residue noninterference claim; any register read would stop as unresolved.']}


def execute(state, irq, registered, initial_mode, saved_if, old_counter, toggle):
    uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
    uc.mem_map(ROM & -D.PAGE, D.PAGE)
    signature = R.read_original(SIGNATURE, 4)
    rom_value = signature if state == 'cold_match' else bytes([signature[0] ^ 1]) + signature[1:]
    if state == 'cold_empty':
        rom_value = bytes(len(signature))
    uc.mem_write(ROM, rom_value)
    D.put(uc, INIT, int(state.startswith('cached')))
    D.put(uc, PRESENT, int(state == 'cached_present'))
    D.put(uc, TABLE + irq * D.WORD, int(registered))
    D.put(uc, COUNTER, old_counter)
    uc.mem_write(MODE, struct.pack('<H', initial_mode))
    uc.reg_write(X.UC_X86_REG_EBP, D.STACK - 0x100)
    uc.reg_write(X.UC_X86_REG_EBX, irq)
    uc.reg_write(X.UC_X86_REG_ESI, saved_if)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    events, all_writes = [], []

    def write_hook(engine, access, address, size, value, unused):
        if not D.STACK - D.PAGE <= address < D.STACK + D.PAGE:
            event = {'kind': 'write', 'address': hex(address), 'size': size, 'value': value}
            all_writes.append(event)
            if address in (COUNTER, MODE):
                events.append(event)

    def out_hook(engine, port, size, value, unused):
        events.append({'kind': 'out', 'port': hex(port), 'size': size, 'value': value,
                       'mode_at_out': struct.unpack('<H', engine.mem_read(MODE, 2))[0],
                       'counter_at_out': D.words(engine, COUNTER, 1)[0]})

    uc.hook_add(D.U.UC_HOOK_MEM_WRITE, write_hook)
    uc.hook_add(D.U.UC_HOOK_INSN, out_hook, None, 1, 0, X.UC_X86_INS_OUT)
    D.run_to(uc, START, CAPTURED)
    captured = uc.reg_read(X.UC_X86_REG_EAX)
    assert bool(captured & AF) == ((old_counter & 0xf) == 0xf)
    uc.reg_write(X.UC_X86_REG_EAX, captured ^ AF if toggle else captured)
    D.run_to(uc, CAPTURED, STOP)
    S.verify_trace(uc, trace)
    present = state in ('cached_present', 'cold_match')
    new_mode = initial_mode & ~(1 << irq) if present and registered else initial_mode
    changed = new_mode != initial_mode
    expected_counter = (old_counter + 1 + (2 if changed else 0)) & 0xffffffff
    assert D.words(uc, COUNTER, 1) == [expected_counter]
    assert struct.unpack('<H', uc.mem_read(MODE, 2))[0] == new_mode
    assert uc.reg_read(X.UC_X86_REG_EAX) == 1
    assert bool(uc.reg_read(X.UC_X86_REG_EFLAGS) & IF) == bool(saved_if)
    assert D.words(uc, INIT, 1) == [1] and D.words(uc, PRESENT, 1) == [int(present)]
    assert (0x101efc in trace) == state.startswith('cold')
    if changed:
        assert [e['kind'] for e in events] == ['write', 'write', 'out', 'write', 'out', 'write']
        out = [e for e in events if e['kind'] == 'out']
        assert [(e['port'], e['value']) for e in out] == [('0x4d0', new_mode & 0xff), ('0x4d1', new_mode >> 8)]
        assert [e['mode_at_out'] for e in out] == [new_mode, new_mode]
        assert [e['counter_at_out'] for e in out] == [(old_counter + 1) & 0xffffffff, (old_counter + 2) & 0xffffffff]
    else:
        assert len(events) == 1 and events[0]['address'] == hex(COUNTER)
    return {'state': state, 'irq': irq, 'registered': registered, 'initial_mode': hex(initial_mode),
            'saved_if': saved_if, 'old_counter': hex(old_counter), 'snapshot_af_toggled': toggle,
            'mode_changed': changed, 'events': events, 'nonstack_writes': all_writes,
            'observed': {'eax': uc.reg_read(X.UC_X86_REG_EAX),
                         'if': bool(uc.reg_read(X.UC_X86_REG_EFLAGS) & IF),
                         'mode': new_mode, 'counter': expected_counter,
                         'init': 1, 'present': int(present)},
            'trace': [f'{pc:08x}' for pc in trace]}


def main():
    flow = first_access()
    rows, pairs = [], []
    for args in itertools.product(('cached_absent', 'cached_present', 'cold_match', 'cold_mismatch', 'cold_empty'),
                                  (0, 1, 15), (False, True), (0, 0xffff), (0, 1), (0xe, 0xffffffff)):
        a, b = [execute(*args, toggle) for toggle in (False, True)]
        for key in ('events', 'nonstack_writes', 'observed', 'trace'):
            assert a[key] == b[key], (args, key)
        pairs.append({'conditions': list(args), 'matched': True})
        rows.extend((a, b))
    contexts = {f'{e:08x}': {'name': R.FMAP[e]['name'],
                  'instructions': [S.dis(i) for i in ins.values()],
                  'decompiled_c': (R.G / 'functions' / f'{e:08x}.c').read_text()} for e, ins in INS.items()}
    endpoint_sites = {e['site'] for e in flow['endpoints']}
    first_kills = collections.Counter(next(pc for pc in r['trace'] if pc in endpoint_sites) for r in rows)
    summary = {'saved_af_bit_proof': flow['all_reachable_first_accesses_kill_saved_af_bit'],
               'first_access_endpoints': len(flow['endpoints']),
               'first_access_kinds': dict(collections.Counter(e['kind'] for e in flow['endpoints'])),
               'paired_conditions': len(pairs), 'original_execution_cases': len(rows),
               'mode_changed_execution_cases': sum(r['mode_changed'] for r in rows),
               'nested_strncmp_execution_cases': sum('00101efc' in r['trace'] for r in rows),
               'first_kill_execution_counts': dict(first_kills),
               'mismatches': [], 'binary_sha256': hashlib.sha256(R.RAW).hexdigest(),
               'global_af_impact_resolved': False}
    result = {'summary': summary, 'register_bit_flow': flow, 'pairs': pairs, 'executions': rows,
              'original_contexts': contexts,
              'limits': ['Synthetic ROM bytes, port-OUT observation only; no BIOS or PIC hardware.',
                         'Starts at last INC in unregister suffix, stops before outer epilogue.',
                         'Nested original callees execute without mocks, including strncmp when reached.',
                         'Pair comparison excludes stack writes and unconstrained caller-clobbered registers.',
                         'No asynchronous interrupt, fault, SMP, full kernel or decompiled-C execution.']}
    (HERE / 'call-review.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(summary, indent=2))
    print(json.dumps(flow, indent=2))


if __name__ == '__main__':
    main()
