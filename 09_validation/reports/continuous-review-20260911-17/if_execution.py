"""Original CLI/STI against raw semantics; minimal high-IR helper execution."""
import importlib.util
import itertools
import json
from audit_pcode import HERE, R, node

spec = importlib.util.spec_from_file_location('dispatch', HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py')
D = importlib.util.module_from_spec(spec)
spec.loader.exec_module(D)
X = D.X
IF = 1 << 9


def high_execute(function, if_node, old_if):
    assert len(function['high_blocks']) == 1
    state = {tuple(if_node): old_if}

    def get(value):
        key = node(value)
        return key[1] if key[0] == 'const' else state[key]

    for op in function['high_blocks'][0]['operations']:
        args = [get(v) for v in op['inputs']]
        if op['opcode'] == 'INT_AND':
            value = args[0] & args[1]
        elif op['opcode'] == 'COPY':
            value = args[0]
        elif op['opcode'] == 'RETURN':
            return args[1], state[tuple(if_node)]
        else:
            raise AssertionError(op)
        dest = node(op['output'])
        state[dest] = value & ((1 << (dest[2] * 8)) - 1)
    raise AssertionError('No RETURN')


def main():
    audit = json.loads((HERE / 'pcode-audit.json').read_text())
    raw_rows, helper_rows = [], []
    for row in audit['control_sites']:
        pc = int(row['site'], 16)
        ins = R.function_instructions(int(row['owner'], 16))[pc]
        for old_if, af, cf in itertools.product((0, 1), (0, 1), (0, 1)):
            uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
            initial = 2 | (old_if << 9) | (af << 4) | cf
            uc.reg_write(X.UC_X86_REG_EFLAGS, initial)
            D.run_to(uc, pc, pc + ins.size)
            raw_value = node(row['raw_operations'][0]['inputs'][0])[1]
            expected = (initial & ~IF) | (raw_value << 9)
            actual = uc.reg_read(X.UC_X86_REG_EFLAGS)
            assert actual == expected
            assert trace == [pc] and bytes(uc.mem_read(pc, ins.size)) == ins.bytes
            raw_rows.append({'site': row['site'], 'initial_flags': hex(initial),
                             'original_flags': hex(actual), 'raw_model_flags': hex(expected)})
    funcs = {f['entry']: f for f in json.loads((HERE / 'exports/pcode.json').read_text())}
    for name in ('_intr_disbl', '_intr_enbl'):
        entry = R.NAMES[name]
        function = funcs[f'{entry:08x}']
        for old_if, af, argument in itertools.product((0, 1), (0, 1), (0, 1, 0xffffffff)):
            if name == '_intr_disbl' and argument != 0:
                continue
            uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
            flags = 2 | (old_if << 9) | (af << 4)
            uc.reg_write(X.UC_X86_REG_EFLAGS, flags)
            D.put(uc, D.STACK, D.STOP, argument)
            D.run_to(uc, entry, D.STOP)
            actual_return = uc.reg_read(X.UC_X86_REG_EAX)
            actual_if = int(bool(uc.reg_read(X.UC_X86_REG_EFLAGS) & IF))
            ir_return, ir_if = high_execute(function, audit['if_node'], old_if)
            assert actual_return == ir_return == old_if
            assert actual_if == int(name == '_intr_enbl' and argument != 0)
            D.assert_callee_saved(uc)
            assert uc.reg_read(X.UC_X86_REG_ESP) == D.STACK + D.WORD
            for pc in trace:
                ins = next(R.CS.disasm(R.read_original(pc, 15), pc, count=1))
                assert bytes(uc.mem_read(pc, ins.size)) == ins.bytes
            helper_rows.append({'function': name, 'argument': hex(argument), 'initial_flags': hex(flags),
                                'original_return': actual_return, 'high_ir_return': ir_return,
                                'original_if': actual_if, 'high_ir_if': ir_if,
                                'if_mismatch': actual_if != ir_if, 'trace': [f'{p:08x}' for p in trace]})
    summary = {'raw_original_cases': len(raw_rows), 'raw_original_mismatches': 0,
               'helper_original_high_cases': len(helper_rows),
               'helper_return_mismatches': sum(r['original_return'] != r['high_ir_return'] for r in helper_rows),
               'helper_if_mismatches': sum(r['if_mismatch'] for r in helper_rows),
               'high_ir_if_fidelity_pass': False}
    (HERE / 'if-execution.json').write_text(json.dumps({'summary': summary, 'raw_cases': raw_rows,
        'helper_cases': helper_rows, 'limits': ['No STI interrupt-shadow timing, privilege checks, virtualized IF or external interrupt delivery.',
        'Single-instruction raw comparison and two straight-line high-IR helpers only.',
        'High IR interpreter supports only exported INT_AND/COPY/RETURN; not a general decompiler interpreter.',
        'Original full helpers execute; only return value and IF are compared with IR, not all flags or memory.']}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
