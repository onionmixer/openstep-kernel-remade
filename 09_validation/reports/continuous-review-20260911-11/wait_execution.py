"""Execute every selected original wait window with synthetic lock memory.

No instruction patching. External memory release is a deterministic hook,
not a real second CPU, interrupt, scheduler or hardware concurrency test.
"""
import collections
import importlib.util
import json
import struct
from scan import HERE, R

spec = importlib.util.spec_from_file_location('dispatch', HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py')
D = importlib.util.module_from_spec(spec)
spec.loader.exec_module(D)
U, X = D.U, D.X
WORD = struct.calcsize('<I')
MASK = (1 << (WORD * 8)) - 1
LIMIT = 40


def register(uc, ins, capstone_reg):
    name = ins.reg_name(capstone_reg)
    return getattr(X, 'UC_X86_REG_' + name.upper())


def case(site, mode, value):
    ins = R.function_instructions(int(site['owner'], 16))
    cond = ins[int(site['condition']['address'], 16)]
    branch = ins[int(site['branch']['address'], 16)]
    frozen = site['kind'] == 'register_only'
    start_ins = ins[int(site['load']['address'], 16)] if frozen else cond
    mem = start_ins.operands[1] if frozen else cond.operands[0]
    assert mem.type == R.X86_OP_MEM and mem.size == WORD and not mem.mem.segment
    uc, trace, _ = D.fixture(0x603, 'unlocked', 'hit')
    for name in ('eax', 'ebx', 'ecx', 'edx', 'esi', 'edi', 'ebp'):
        uc.reg_write(getattr(X, 'UC_X86_REG_' + name.upper()), D.DATA + 0x800)
    if mem.mem.index:
        assert mem.mem.index != mem.mem.base
        uc.reg_write(register(uc, start_ins, mem.mem.index), 0)
    address = mem.mem.disp
    if mem.mem.base:
        address += uc.reg_read(register(uc, start_ins, mem.mem.base))
    if mem.mem.index:
        address += uc.reg_read(register(uc, start_ins, mem.mem.index)) * mem.mem.scale
    address &= MASK
    D.put(uc, address, value)
    if mode == 'release_before_read':
        D.put(uc, address, 0)
    reads, changes = [], []
    visits = collections.Counter()
    target_reg = register(uc, cond, cond.operands[0].reg) if frozen else None

    def code(engine, pc, size, unused):
        visits[pc] += 1
        if pc == branch.address and visits[pc] == 1:
            if mode == 'release_after_read':
                D.put(engine, address, 0)
                changes.append({'when': hex(pc), 'kind': 'synthetic_external_memory_release'})
            elif mode == 'clear_register_after_read':
                assert frozen
                engine.reg_write(target_reg, 0)
                changes.append({'when': hex(pc), 'kind': 'synthetic_register_perturbation_not_normal_unlock'})

    def read(engine, access, addr, size, val, unused):
        if addr == address:
            reads.append({'pc': hex(engine.reg_read(X.UC_X86_REG_EIP)), 'value': D.words(engine, addr, 1)[0], 'size': size})

    uc.hook_add(U.UC_HOOK_CODE, code)
    uc.hook_add(U.UC_HOOK_MEM_READ, read)
    end = branch.address + branch.size
    uc.emu_start(start_ins.address, end, timeout=1000000, count=LIMIT)
    pc = uc.reg_read(X.UC_X86_REG_EIP)
    escaped = pc == end
    expect_escape = value == 0 or mode == 'release_before_read' or mode == 'clear_register_after_read' or (not frozen and mode == 'release_after_read')
    assert escaped == expect_escape, (site['branch'], mode, value, pc)
    if frozen:
        assert len(reads) == 1
        if not escaped:
            assert len(trace) == LIMIT and pc in (cond.address, branch.address)
        assert uc.reg_read(target_reg) == (0 if mode in ('release_before_read', 'clear_register_after_read') else value)
    elif mode == 'release_after_read' and value:
        assert len(reads) == 2 and [r['value'] for r in reads] == [value, 0]
    elif not escaped:
        assert len(trace) == LIMIT and len(reads) > 1
    for addr in set(trace):
        original = ins[addr]
        assert bytes(uc.mem_read(addr, original.size)) == original.bytes
    return {'site': site['branch']['address'], 'owner': site['owner'], 'kind': site['kind'],
            'mode': mode, 'initial_value': value, 'lock_address': hex(address),
            'escaped_window': escaped, 'end_pc': hex(pc), 'memory_reads': reads,
            'memory_final': D.words(uc, address, 1)[0], 'changes': changes,
            'instructions_executed': len(trace), 'trace': [hex(a) for a in trace],
            'original_instruction_bytes_verified': True}


def main():
    scan = json.loads((HERE / 'scan.json').read_text())
    rows = []
    for site in scan['sites']:
        assert site['kind'] == 'memory_poll' or site['matched_single_memory_load'], site
        for mode, value in [('unchanged', 0), ('unchanged', 1), ('release_before_read', 1),
                            ('release_after_read', 1), ('release_after_read', MASK)]:
            rows.append(case(site, mode, value))
        if site['kind'] == 'register_only':
            rows.append(case(site, 'clear_register_after_read', 1))
    summary = {'sites_executed': len({r['site'] for r in rows}), 'cases': len(rows),
               'cases_by_kind': dict(collections.Counter(r['kind'] for r in rows)),
               'external_release_still_spinning': sum(r['mode'] == 'release_after_read' and not r['escaped_window'] for r in rows),
               'memory_poll_release_escaped': sum(r['mode'] == 'release_after_read' and r['kind'] == 'memory_poll' and r['escaped_window'] for r in rows),
               'instruction_limit': LIMIT, 'failures': 0}
    (HERE / 'wait-execution.json').write_text(json.dumps({'summary': summary, 'cases': rows}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
