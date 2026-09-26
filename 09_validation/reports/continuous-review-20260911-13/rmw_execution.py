"""Original INC/DEC versus exported volatile memory-effect slices.

Unicorn architectural memory hooks are not a physical bus transaction trace.
The P-code slice tests memory effects only, not the entire decompiled function.
"""
import collections
import importlib.util
import json
from audit_experiment import HERE, R, BUILTINS, node, ops

spec = importlib.util.spec_from_file_location('dispatch', HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py')
D = importlib.util.module_from_spec(spec)
spec.loader.exec_module(D)
X, U = D.X, D.U
MASK = (1 << 32) - 1


def effect_slice(function, address):
    operations = [o for o in ops(function) if o['address'] == address]
    needed = {id(o) for o in operations if o['opcode'] == 'CALLOTHER'}
    while True:
        names = {text for o in operations if id(o) in needed for text in o['inputs']}
        enlarged = needed | {id(o) for o in operations if o.get('output') in names}
        if enlarged == needed:
            break
        needed = enlarged
    selected = [o for o in operations if id(o) in needed]
    assert all(o['opcode'] in ('CALLOTHER', 'INT_ADD') for o in selected)
    return selected, [o for o in operations if id(o) not in needed]


def execute_slice(operations, initial):
    values, memory, events = {}, initial, []

    def get(text):
        space, value, width = node(text)
        return value if space == 'const' else values[text]

    for o in operations:
        if o['opcode'] == 'INT_ADD':
            values[o['output']] = (get(o['inputs'][0]) + get(o['inputs'][1])) & MASK
            continue
        identifier = node(o['inputs'][0])[1]
        if identifier == BUILTINS['read']:
            values[o['output']] = memory
            events.append({'kind': 'read', 'value': memory})
        elif identifier == BUILTINS['write']:
            memory = get(o['inputs'][2]) & MASK
            events.append({'kind': 'write', 'value': memory})
        else:
            raise AssertionError(o)
    return memory, events


def case(ref, function, initial, carry):
    ins = R.function_instructions(int(ref['owner'], 16))[int(ref['site'], 16)]
    target = int(ref['target'], 16)
    uc, trace, _ = D.fixture(0x603, 'unlocked', 'hit')
    D.put(uc, target, initial)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 0x202 | carry)
    events = []

    def memory(engine, access, addr, size, value, unused):
        if addr == target:
            assert size == 4
            events.append({'kind': 'read' if access == U.UC_MEM_READ else 'write',
                           'value': D.words(engine, addr, 1)[0] if access == U.UC_MEM_READ else value & MASK})

    uc.hook_add(U.UC_HOOK_MEM_READ | U.UC_HOOK_MEM_WRITE, memory)
    D.run_to(uc, ins.address, ins.address + ins.size)
    assert trace == [ins.address]
    assert bytes(uc.mem_read(ins.address, ins.size)) == ins.bytes
    result = (initial + (1 if ins.mnemonic == 'inc' else -1)) & MASK
    assert D.words(uc, target, 1)[0] == result
    assert events == [{'kind': 'read', 'value': initial}, {'kind': 'write', 'value': result}]
    flags = {'CF': (0, carry), 'PF': (2, (result & 0xff).bit_count() % 2 == 0),
             'AF': (4, bool((initial ^ result) & 0x10)), 'ZF': (6, result == 0),
             'SF': (7, bool(result & (1 << 31))),
             'OF': (11, initial == (0x7fffffff if ins.mnemonic == 'inc' else 0x80000000))}
    actual_flags = uc.reg_read(X.UC_X86_REG_EFLAGS)
    assert all(bool(actual_flags & (1 << bit)) == bool(expected) for bit, expected in flags.values())
    selected, excluded = effect_slice(function, ref['site'])
    ir_result, ir_events = execute_slice(selected, initial)
    assert ir_result == result
    assert [e['kind'] for e in ir_events] == ['read', 'read', 'write', 'read', 'read', 'read']
    return {'owner': ref['owner'], 'site': ref['site'], 'target': ref['target'], 'mnemonic': ins.mnemonic,
            'initial': initial, 'incoming_cf': carry, 'result': result, 'raw_events': events,
            'ir_memory_effect_events': ir_events, 'raw_flags_verified': {name: bool(v) for name, (_, v) in flags.items()},
            'ir_flags_verified': False, 'excluded_non_effect_copy_operations': len(excluded),
            'same_final_value': True, 'same_memory_access_trace': False}


def main():
    job = json.loads((HERE / 'job.json').read_text())
    funcs = {f['entry']: f for f in json.loads((HERE / 'exports/combined/functions.json').read_text())}
    refs = [r for r in job['direct_operand_sites'] if r['instruction'].startswith(('inc ', 'dec '))]
    assert len({(r['owner'], r['site']) for r in refs}) == len(refs)
    rows = [case(ref, funcs[ref['owner']], initial, carry) for ref in refs
            for initial in (0, 1, 0x10, 0x7fffffff, 0x80000000, MASK) for carry in (0, 1)]
    summary = {'instruction_sites': len(refs), 'cases': len(rows),
               'sites_by_mnemonic': dict(collections.Counter(r['instruction'].split()[0] for r in refs)),
               'raw_and_ir_final_values_equal': sum(r['same_final_value'] for r in rows),
               'raw_and_ir_access_trace_mismatches': sum(not r['same_memory_access_trace'] for r in rows),
               'combined_model_access_fidelity_pass': False,
               'scope': 'Original one-instruction execution vs exported volatile memory-effect slice, stable memory; no bus/SMP/whole-C proof.'}
    (HERE / 'rmw-execution.json').write_text(json.dumps({'summary': summary, 'cases': rows}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
