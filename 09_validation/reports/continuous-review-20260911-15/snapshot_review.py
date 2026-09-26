"""Local saved-EFLAGS use audit and bounded original-byte execution.

No hardware, asynchronous, full IRQ routine, or decompiled C execution claim.
"""
import collections
import hashlib
import importlib.util
import itertools
import json
from pathlib import Path
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    result = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(result)
    return result


F = module('reaching', HERE / 'reaching_flags.py')
D = module('dispatch', HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py')
R, X = F.R, D.X
AF, IF = 1 << 4, 1 << 9
EAX_ALIASES = {F.X.X86_REG_EAX, F.X.X86_REG_AX, F.X.X86_REG_AL, F.X.X86_REG_AH}


def dis(ins):
    return {'site': f'{ins.address:08x}', 'bytes': ins.bytes.hex(),
            'instruction': ins.mnemonic + ' ' + ins.op_str}


def local_snapshot(row):
    instructions = R.function_instructions(int(row['owner'], 16))
    site = int(row['consumer'], 16)
    pop = instructions[site + instructions[site].size]
    assert pop.mnemonic == 'pop' and pop.op_str == 'eax'
    start = pop.address + pop.size
    succ, _, escapes = F.graph(instructions)
    queue = collections.deque([start])
    seen, ends = set(), []
    while queue:
        pc = queue.popleft()
        if pc in seen:
            continue
        seen.add(pc)
        ins = instructions[pc]
        reads, writes = map(set, ins.regs_access())
        if F.C.CS_GRP_CALL in ins.groups:
            ends.append({'kind': 'opaque_call', **dis(ins)})
        elif reads & EAX_ALIASES:
            ends.append({'kind': 'snapshot_read', **dis(ins)})
        elif F.X.X86_REG_EAX in writes:
            ends.append({'kind': 'full_eax_overwrite', **dis(ins)})
        elif F.C.CS_GRP_RET in ins.groups:
            ends.append({'kind': 'unresolved_return_value', **dis(ins)})
        elif not succ[pc] or any(int(e['site'], 16) == pc for e in escapes):
            ends.append({'kind': 'unresolved_cfg_escape', **dis(ins)})
        else:
            queue.extend(succ[pc])
    # A cycle could retain a value indefinitely; reject that as a dead-value proof.
    active, done = set(), set()
    terminal_pcs = {int(e['site'], 16) for e in ends}

    def cyclic(pc):
        if pc in terminal_pcs or pc in done:
            return False
        if pc in active:
            return True
        active.add(pc)
        found = any(cyclic(n) for n in succ[pc])
        active.remove(pc)
        done.add(pc)
        return found

    cycle = cyclic(start)
    return {'owner': row['owner'], 'name': row['name'], 'consumer': row['consumer'],
            'pop': dis(pop), 'start': f'{start:08x}', 'endpoints': ends,
            'cycle': cycle, 'locally_discarded': bool(ends) and not cycle and
            all(e['kind'] == 'full_eax_overwrite' for e in ends),
            'visited': [dis(instructions[p]) for p in sorted(seen)]}


def verify_trace(uc, trace):
    for pc in trace:
        i = next(R.CS.disasm(R.read_original(pc, 15), pc, count=1))
        assert bytes(uc.mem_read(pc, i.size)) == i.bytes


def helper_cases():
    rows = []
    for name in ('_intr_disbl', '_intr_enbl'):
        for af, old_if, status, argument in itertools.product((0, AF), (0, IF), (0, 0x8c5), (0, 1, 0xffffffff)):
            if name == '_intr_disbl' and argument != 0:
                continue
            uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
            flags = 2 | af | old_if | status
            uc.reg_write(X.UC_X86_REG_EFLAGS, flags)
            D.put(uc, D.STACK, D.STOP, argument)
            D.run_to(uc, R.NAMES[name], D.STOP)
            result = uc.reg_read(X.UC_X86_REG_EAX)
            new_if = uc.reg_read(X.UC_X86_REG_EFLAGS) & IF
            assert result == bool(old_if)
            assert bool(new_if) == (name == '_intr_enbl' and argument != 0)
            assert uc.reg_read(X.UC_X86_REG_ESP) == D.STACK + D.WORD
            D.assert_callee_saved(uc)
            verify_trace(uc, trace)
            rows.append({'function': name, 'flags': hex(flags), 'argument': hex(argument),
                         'returned_old_if': result, 'new_if': bool(new_if),
                         'trace': [f'{p:08x}' for p in trace]})
    return rows


def suffix_cases(reaching, reviews):
    rows = []
    for row, review in zip(reaching, reviews):
        ins = R.function_instructions(int(row['owner'], 16))
        origin, = [o for o in row['origins'] if o['kind'] == 'inc_dec']
        inc = ins[int(origin['site'], 16)]
        assert inc.mnemonic == 'lock inc'
        counter = inc.operands[0].mem.disp
        site, start = int(row['consumer'], 16), int(review['start'], 16)
        endpoint, = review['endpoints']
        end_pc = int(endpoint['site'], 16)
        stop = end_pc + ins[end_pc].size if review['locally_discarded'] else end_pc
        condition = ins[start]
        assert condition.mnemonic in ('cmp', 'test')
        for old, saved_if, incoming_af, toggle_snapshot_af in itertools.product(
                (0, 0xe, 0xf, 0x7fffffff, 0xffffffff), (0, 1), (0, AF), (False, True)):
            uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
            uc.reg_write(X.UC_X86_REG_EFLAGS, 2 | incoming_af)
            frame = D.STACK - 0x100
            uc.reg_write(X.UC_X86_REG_EBP, frame)
            if condition.operands[0].type == R.X86_OP_MEM:
                mem = condition.operands[0].mem
                assert mem.base == F.X.X86_REG_EBP and mem.index == 0
                D.put(uc, frame + mem.disp, saved_if)
            else:
                register = condition.reg_name(condition.operands[0].reg)
                uc.reg_write(getattr(X, 'UC_X86_REG_' + register.upper()), saved_if)
            D.put(uc, counter, old)
            D.run_to(uc, inc.address, site)
            expected = (old + 1) & 0xffffffff
            expected_af = AF if (old & 0xf) == 0xf else 0
            assert D.words(uc, counter, 1) == [expected]
            assert uc.reg_read(X.UC_X86_REG_EFLAGS) & AF == expected_af
            flags = uc.reg_read(X.UC_X86_REG_EFLAGS)
            D.run_to(uc, site, start)
            assert uc.reg_read(X.UC_X86_REG_EAX) == flags
            injected = flags ^ AF if toggle_snapshot_af else flags
            uc.reg_write(X.UC_X86_REG_EAX, injected)
            D.run_to(uc, start, stop)
            assert bool(uc.reg_read(X.UC_X86_REG_EFLAGS) & IF) == bool(saved_if)
            eax = uc.reg_read(X.UC_X86_REG_EAX)
            assert eax == (1 if review['locally_discarded'] else injected)
            verify_trace(uc, trace)
            rows.append({'consumer': row['consumer'], 'old_counter': hex(old),
                         'saved_if': saved_if, 'incoming_af': bool(incoming_af),
                         'captured_af': bool(flags & AF), 'snapshot_af_toggled': toggle_snapshot_af,
                         'new_counter': hex(expected), 'eax_at_stop': hex(eax),
                         'stop': f'{stop:08x}', 'opaque_call_not_executed': not review['locally_discarded'],
                         'trace': [f'{p:08x}' for p in trace]})
    return rows


def gate_cases(reaching):
    rows = []
    for row in reaching:
        if row['consumer'] != row['owner']:
            continue
        ins = R.function_instructions(int(row['owner'], 16))
        seq = list(ins.values())
        # Stop immediately after the saved flags are copied, before selector changes.
        store = next(i for i in seq if i.mnemonic == 'mov' and i.operands[0].type == R.X86_OP_MEM)
        assert store.operands[0].mem.base == F.X.X86_REG_ESP and store.op_str.endswith(', eax')
        stop = store.address + store.size
        for af, old_if, cf, other in itertools.product((0, AF), (0, IF), (0, 1), (0, 0x8c4)):
            uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
            flags = 2 | af | old_if | cf | other
            uc.reg_write(X.UC_X86_REG_EFLAGS, flags)
            D.put(uc, D.STACK, *[0xabc00000 + i for i in range(16)])
            D.run_to(uc, int(row['owner'], 16), stop)
            esp = uc.reg_read(X.UC_X86_REG_ESP)
            address = esp + store.operands[0].mem.disp
            saved, = D.words(uc, address, 1)
            assert saved == flags
            verify_trace(uc, trace)
            rows.append({'entry': row['owner'], 'name': row['name'], 'flags': hex(flags),
                         'copied_flags': hex(saved), 'copy_address': hex(address),
                         'copy_offset_from_incoming_esp': address - D.STACK,
                         'stack_delta': esp - D.STACK, 'stop': f'{stop:08x}',
                         'trace': [f'{p:08x}' for p in trace]})
    return rows


def irq_if_cases(reaching):
    rows = []
    for row in reaching:
        if not row['name'].startswith('_intr_') or row['name'] in ('_intr_disbl', '_intr_enbl'):
            continue
        if any(o['kind'] == 'inc_dec' for o in row['origins']):
            continue
        ins = R.function_instructions(int(row['owner'], 16))
        pc = int(row['consumer'], 16)
        prefix = []
        while True:
            i = ins[pc]
            prefix.append(i)
            assert len(prefix) <= 6
            pc += i.size
            if i.mnemonic == 'and':
                assert i.operands[1].imm == 1
                target = i.reg_name(i.operands[0].reg)
                break
        assert [i.mnemonic for i in prefix[:4]] == ['pushfd', 'pop', 'cli', 'shr']
        assert prefix[3].op_str == 'eax, 9'
        if len(prefix) == 6:
            assert prefix[4].mnemonic == 'mov' and prefix[4].op_str == target + ', eax'
        else:
            assert target == 'eax'
        for af, old_if, cf, other in itertools.product((0, AF), (0, IF), (0, 1), (0, 0x8c4)):
            uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
            flags = 2 | af | old_if | cf | other
            uc.reg_write(X.UC_X86_REG_EFLAGS, flags)
            D.run_to(uc, int(row['consumer'], 16), pc)
            result = uc.reg_read(getattr(X, 'UC_X86_REG_' + target.upper()))
            assert result == bool(old_if)
            assert not (uc.reg_read(X.UC_X86_REG_EFLAGS) & IF)
            verify_trace(uc, trace)
            rows.append({'consumer': row['consumer'], 'flags': hex(flags), 'result_register': target,
                         'old_if_result': result, 'stop': f'{pc:08x}',
                         'trace': [f'{p:08x}' for p in trace]})
    return rows


def main():
    reaching = json.loads((HERE / 'reaching-flags.json').read_text())['consumers']
    candidates = [r for r in reaching if any(o['kind'] == 'inc_dec' for o in r['origins'])]
    reviews = [local_snapshot(r) for r in candidates]
    helpers = helper_cases()
    suffixes = suffix_cases(candidates, reviews)
    gates = gate_cases(reaching)
    irq_if = irq_if_cases(reaching)
    summary = {'inc_dec_reaching_consumers': len(candidates),
               'saved_eax_locally_discarded': sum(r['locally_discarded'] for r in reviews),
               'opaque_call_boundaries': sum(any(e['kind'] == 'opaque_call' for e in r['endpoints']) for r in reviews),
               'helper_executions': len(helpers), 'irq_suffix_executions': len(suffixes),
               'gate_prefix_executions': len(gates),
               'irq_if_extraction_executions': len(irq_if),
               'total_executions': len(helpers) + len(suffixes) + len(gates) + len(irq_if),
               'mismatches': [], 'binary_sha256': hashlib.sha256(R.RAW).hexdigest(),
               'global_af_impact_resolved': False}
    contexts = {}
    for row in reaching:
        entry = int(row['owner'], 16)
        if row['owner'] not in contexts:
            contexts[row['owner']] = {'name': row['name'],
                'original_instructions': [dis(i) for i in R.function_instructions(entry).values()]}
    nested = R.function_instructions(0x1946e0)
    contexts['001946e0'] = {'name': R.FMAP[0x1946e0]['name'],
                          'original_instructions': [dis(i) for i in nested.values()]}
    output = {'summary': summary, 'local_snapshot_flow': reviews, 'helper_cases': helpers,
              'irq_suffix_cases': suffixes, 'gate_prefix_cases': gates,
              'irq_if_extraction_cases': irq_if, 'original_contexts': contexts,
              'limits': ['No decompiled C or Ghidra IR execution in this report.',
                         'IRQ suffix starts at the final locked INC, not function entry; preceding OUT instructions excluded.',
                         'One suffix stops before an opaque nested call, preserving uncertainty.',
                         'Gate prefixes use synthetic stack and stop before selector writes; no IRET/privilege proof.',
                         'No BIOS far call, whole CPU probe, asynchronous interrupt, SMP or fault execution.',
                         'Unicorn instruction model observations are not hardware bus evidence.']}
    (HERE / 'snapshot-review.json').write_text(json.dumps(output, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
