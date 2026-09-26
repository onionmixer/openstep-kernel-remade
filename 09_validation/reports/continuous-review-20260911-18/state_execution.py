"""Original descriptor loads, CLTS and a CR0-setting helper, bounded CPU model."""
import collections
import importlib.util
import itertools
import json
import struct
from audit_pcode import HERE, R, node

spec = importlib.util.spec_from_file_location('dispatch', HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py')
D = importlib.util.module_from_spec(spec)
spec.loader.exec_module(D)
X = D.X


def high_helper(function, cr0_node, initial):
    assert len(function['high_blocks']) == 1
    state = {tuple(cr0_node): initial}
    for op in function['high_blocks'][0]['operations']:
        args = [node(v)[1] if node(v)[0] == 'const' else state[node(v)] for v in op['inputs']]
        if op['opcode'] == 'COPY':
            state[node(op['output'])] = args[0]
        elif op['opcode'] == 'INT_OR':
            state[node(op['output'])] = args[0] | args[1]
        elif op['opcode'] == 'RETURN':
            return args[1], state[tuple(cr0_node)]
        else:
            raise AssertionError(op)
    raise AssertionError('Missing RETURN')


def main():
    audit = json.loads((HERE / 'pcode-audit.json').read_text())
    descriptors, clts, helper = [], [], []
    descriptor_size = struct.calcsize('<HI')
    for row in audit['sites']:
        if row['operation'] not in ('lgdt', 'lidt'):
            continue
        pc = int(row['site'], 16)
        ins = R.function_instructions(int(row['owner'], 16))[pc]
        address = ins.operands[0].mem.disp
        assert row['raw_descriptor_argument'] == ['ram', address, 4]
        assert ins.operands[0].size == descriptor_size
        for limit, low, high in itertools.product((0, 0xff, 0xffff), (0, 0xabcd), (0, 0x1234, 0xffff)):
            base = (high << 16) | low
            uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
            payload = struct.pack('<HI', limit, base)
            uc.mem_write(address, payload)
            reads = []

            def read_hook(engine, access, addr, size, value, unused):
                reads.append({'address': hex(addr), 'size': size})

            uc.hook_add(D.U.UC_HOOK_MEM_READ, read_hook)
            D.run_to(uc, pc, pc + ins.size)
            target = X.UC_X86_REG_GDTR if row['operation'] == 'lgdt' else X.UC_X86_REG_IDTR
            state = uc.reg_read(target)
            assert state[1] == base and state[2] == limit
            assert reads == [{'address': hex(address), 'size': struct.calcsize('<H')},
                             {'address': hex(address + struct.calcsize('<H')), 'size': struct.calcsize('<I')}]
            assert trace == [pc] and bytes(uc.mem_read(pc, ins.size)) == ins.bytes
            descriptors.append({'site': row['site'], 'operation': row['operation'], 'limit': limit, 'base': hex(base),
                                'raw_pcode_argument_value': int.from_bytes(payload[:row['raw_descriptor_argument'][2]], 'little'),
                                'loaded_register': list(state), 'reads': reads})
    groups = collections.defaultdict(list)
    for row in descriptors:
        groups[(row['site'], row['raw_pcode_argument_value'])].append(row)
    collisions = []
    for (site, value), group in groups.items():
        bases = sorted({r['loaded_register'][1] for r in group})
        assert len(bases) > 1
        collisions.append({'site': site, 'identical_raw_argument': hex(value), 'distinct_original_bases': [hex(v) for v in bases]})
    uc, _, _ = D.fixture(0x600, 'unlocked', 'hit')
    baseline = uc.reg_read(X.UC_X86_REG_CR0)
    patterns = sorted({baseline | (mp << 1) | (em << 2) | (ts << 3) | (ne << 5)
                       for mp, em, ts, ne in itertools.product((0, 1), repeat=4)})
    for row in audit['sites']:
        if row['operation'] != 'clts':
            continue
        pc = int(row['site'], 16)
        ins = R.function_instructions(int(row['owner'], 16))[pc]
        for initial in patterns:
            uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
            uc.reg_write(X.UC_X86_REG_CR0, initial)
            D.run_to(uc, pc, pc + ins.size)
            expected = initial & ~(1 << 3)
            raw_state = {tuple(row['special_output']): initial}
            for raw in row['raw_operations']:
                args = [node(v)[1] if node(v)[0] == 'const' else raw_state[node(v)] for v in raw['inputs']]
                if raw['opcode'] == 'INT_NEGATE':
                    value = ~args[0]
                elif raw['opcode'] == 'INT_AND':
                    value = args[0] & args[1]
                else:
                    raise AssertionError(raw)
                dest = node(raw['output'])
                raw_state[dest] = value & ((1 << (dest[2] * 8)) - 1)
            assert raw_state[tuple(row['special_output'])] == expected
            assert uc.reg_read(X.UC_X86_REG_CR0) == expected
            assert trace == [pc] and bytes(uc.mem_read(pc, ins.size)) == ins.bytes
            clts.append({'site': row['site'], 'initial_cr0': hex(initial), 'original_cr0': hex(expected)})
    function = next(f for f in json.loads((HERE / 'exports/pcode.json').read_text()) if f['entry'] == '0018a7e4')
    cr0_node = next(r['special_output'] for r in audit['sites'] if r['site'] == '0018a7f6')
    for initial in patterns:
        uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
        uc.reg_write(X.UC_X86_REG_CR0, initial)
        D.put(uc, D.STACK, D.STOP)
        D.run_to(uc, int(function['entry'], 16), D.STOP)
        original_return = uc.reg_read(X.UC_X86_REG_EAX)
        original_cr0 = uc.reg_read(X.UC_X86_REG_CR0)
        ir_return, ir_cr0 = high_helper(function, cr0_node, initial)
        assert original_return == ir_return == initial | (1 << 3)
        assert original_cr0 == initial | (1 << 3)
        D.assert_callee_saved(uc)
        assert uc.reg_read(X.UC_X86_REG_ESP) == D.STACK + D.WORD
        for pc in trace:
            ins = next(R.CS.disasm(R.read_original(pc, 15), pc, count=1))
            assert bytes(uc.mem_read(pc, ins.size)) == ins.bytes
        helper.append({'initial_cr0': hex(initial), 'original_return': hex(original_return), 'high_ir_return': hex(ir_return),
                       'original_cr0': hex(original_cr0), 'high_ir_cr0': hex(ir_cr0), 'cr0_mismatch': original_cr0 != ir_cr0})
    summary = {'descriptor_original_cases': len(descriptors), 'raw_argument_collision_groups': len(collisions),
               'clts_original_raw_cases': len(clts), 'clts_mismatches': 0,
               'helper_original_high_cases': len(helper), 'helper_return_mismatches': 0,
               'helper_cr0_mismatches': sum(r['cr0_mismatch'] for r in helper),
               'raw_descriptor_contract_self_sufficient': False, 'high_helper_state_fidelity_pass': False}
    (HERE / 'state-execution.json').write_text(json.dumps({'summary': summary, 'descriptors': descriptors,
        'proposed_descriptor_contract': {'status': 'analysis_only_not_integrated',
             'total_bytes': descriptor_size, 'limit_offset': 0, 'limit_bytes': struct.calcsize('<H'),
             'base_offset': struct.calcsize('<H'), 'base_bytes': struct.calcsize('<I'),
             'byte_order': 'little', 'state_target': 'GDTR for LGDT, IDTR for LIDT',
             'requires': ['Preserve original effective address and full descriptor value.',
                          'Do not discard upper base bytes when constructing an effect operation.',
                          'Privilege, fault, ordering and subsequent selector semantics remain separate obligations.']},
        'descriptor_collisions': collisions, 'clts': clts, 'helper': helper,
        'limits': ['Unicorn synthetic descriptors; no subsequent selector load, address translation or interrupt dispatch.',
                   'No descriptor privilege/fault validation; memory hooks are emulator events, not physical bus cycles.',
                   'Equal raw userop value cannot alone identify all observed descriptor states; a richer external contract could add context.',
                   'No WBINVD cache effects or CR3 TLB effects executed.',
                   'CR0 tests keep the existing paging mode; compare limited modeled states, not FPU fault behavior.']}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
