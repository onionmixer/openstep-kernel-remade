"""Bounded REP MOVS raw interpretation versus original FS-prefixed bytes."""
import itertools
import json
import struct
from segment_execution import HERE, R, D, X, GDT, SELECTOR, descriptor, RawModel, node


def run_raw(operations, site, end, model):
    temps, writes = {}, []

    def get(v):
        key = node(v)
        if key[0] == 'const':
            return key[1]
        if key[0] == 'register':
            return int.from_bytes(model.registers[key[1]:key[1] + key[2]], 'little')
        return temps[key]

    steps, index = 0, 0
    while steps < 10000:
        op = operations[index]
        steps += 1
        if op['opcode'] in ('BRANCH', 'CBRANCH'):
            taken = op['opcode'] == 'BRANCH' or get(op['inputs'][1]) != 0
            if taken:
                target = node(op['inputs'][0])
                assert target[0] == 'ram'
                if target[1] == end:
                    return writes
                assert target[1] == site
                index = 0
                continue
            index += 1
            continue
        args = [get(v) for v in op['inputs']]
        code = op['opcode']
        if code == 'STORE':
            size = node(op['inputs'][2])[2]
            model.store(args[1], args[2], size)
            writes.append({'address': hex(args[1]), 'size': size, 'value': args[2]})
            index += 1
            continue
        dest = node(op['output'])
        if code in ('COPY', 'INT_ZEXT'):
            value = args[0]
        elif code == 'INT_EQUAL':
            value = int(args[0] == args[1])
        elif code == 'INT_ADD':
            value = args[0] + args[1]
        elif code == 'INT_SUB':
            value = args[0] - args[1]
        elif code == 'INT_MULT':
            value = args[0] * args[1]
        elif code == 'LOAD':
            value = int.from_bytes(bytes(model.memory[args[1] + i] for i in range(dest[2])), 'little')
            model.reads.append({'address': hex(args[1]), 'size': dest[2]})
        else:
            raise AssertionError(op)
        value &= (1 << (dest[2] * 8)) - 1
        if dest[0] == 'register':
            model.put(dest, value)
        else:
            temps[dest] = value
        index += 1
    raise AssertionError('REP raw model budget exhausted')


def main():
    audit = json.loads((HERE / 'pcode-audit.json').read_text())
    candidates = [r for r in audit['memory_accesses'] if not r['raw_uses_hidden_base']]
    cases = []
    for row in candidates:
        ins = R.function_instructions(int(row['owner'], 16))[int(row['site'], 16)]
        assert ins.mnemonic in ('rep movsb', 'rep movsd')
        width = ins.operands[0].size
        df_nodes = {node(op['inputs'][0]) for op in row['raw_operations'] if op['opcode'] == 'INT_ZEXT'}
        df_node, = df_nodes
        for base, count, df in itertools.product((0, 0x800000), (0, 1, 3, 8), (0, 1)):
            uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
            source, destination = 0x100, D.DATA + 0x900
            uc.mem_map(0, D.PAGE)
            if base:
                uc.mem_map(base, D.PAGE)
            uc.mem_write(GDT + SELECTOR, descriptor(base))
            stack_selector = 0x2 << 3
            uc.mem_write(GDT + stack_selector, descriptor(0, 0xfffff, 1))
            uc.reg_write(X.UC_X86_REG_GDTR, (0, GDT, 0xff, 0))
            uc.reg_write(X.UC_X86_REG_SS, stack_selector)
            uc.reg_write(X.UC_X86_REG_ES, stack_selector)
            uc.reg_write(X.UC_X86_REG_EAX, SELECTOR)
            loader = R.function_instructions(0x186ddc)[0x186dfc]
            D.run_to(uc, loader.address, loader.address + loader.size)
            trace.clear()
            model = RawModel(tuple(audit['hidden_base_nodes']['fs']), base)
            for reg, register, value in ((X.UC_X86_REG_ECX, 4, count), (X.UC_X86_REG_ESI, 0x18, source),
                                         (X.UC_X86_REG_EDI, 0x1c, destination)):
                uc.reg_write(reg, value)
                model.put(('register', register, D.WORD), value)
            model.put(df_node, df)
            uc.reg_write(X.UC_X86_REG_EFLAGS, 2 | (df << 10))
            direction = -1 if df else 1
            addresses = [source + direction * i * width for i in range(count)]
            destinations = [destination + direction * i * width for i in range(count)]
            for src, dst in zip(addresses, destinations):
                for addr, byte in ((src, 0x5a), (base + src, 0xa5), (dst, 0xcc)):
                    value = int.from_bytes(bytes([byte]) * width, 'little')
                    uc.mem_write(addr, value.to_bytes(width, 'little'))
                    model.store(addr, value, width)
            reads, writes = [], []
            uc.hook_add(D.U.UC_HOOK_MEM_READ, lambda u, a, p, n, v, x: reads.append({'address': hex(p), 'size': n}))
            uc.hook_add(D.U.UC_HOOK_MEM_WRITE, lambda u, a, p, n, v, x: writes.append({'address': hex(p), 'size': n, 'value': v}))
            D.run_to(uc, ins.address, ins.address + ins.size)
            raw_writes = run_raw(row['raw_operations'], ins.address, ins.address + ins.size, model)
            assert reads == [{'address': hex(base + a), 'size': width} for a in addresses]
            assert model.reads == [{'address': hex(a), 'size': width} for a in addresses]
            assert [w['address'] for w in writes] == [w['address'] for w in raw_writes] == list(map(hex, destinations))
            for dst in destinations:
                assert bytes(uc.mem_read(dst, width)) == bytes([0xa5]) * width
                assert bytes(model.memory[dst + i] for i in range(width)) == bytes([0x5a if base else 0xa5]) * width
            assert uc.reg_read(X.UC_X86_REG_ECX) == 0
            for reg, offset, initial in ((X.UC_X86_REG_ESI, 0x18, source), (X.UC_X86_REG_EDI, 0x1c, destination)):
                expected = (initial + direction * count * width) & 0xffffffff
                assert uc.reg_read(reg) == expected
                assert int.from_bytes(model.registers[offset:offset + D.WORD], 'little') == expected
            assert bytes(uc.mem_read(ins.address, ins.size)) == ins.bytes
            assert set(trace) == {ins.address}
            cases.append({'site': row['site'], 'count': count, 'df': df, 'width': width,
                          'fs_base': hex(base), 'original_reads': reads, 'raw_reads': model.reads,
                          'original_writes': writes, 'raw_writes': raw_writes,
                          'copied_data_mismatch': count != 0 and base != 0, 'original_instruction_visits': len(trace)})
    summary = {'original_rep_sites': len(candidates), 'cases': len(cases),
               'positive_count_cases': sum(r['count'] != 0 for r in cases),
               'copied_data_mismatch_cases': sum(r['copied_data_mismatch'] for r in cases),
               'zero_count_cases': sum(r['count'] == 0 for r in cases),
               'flat_base_positive_count_controls': sum(r['count'] != 0 and int(r['fs_base'], 16) == 0 for r in cases),
               'raw_fs_offset_seeded_correctly': True, 'raw_rep_segment_fidelity_pass': False}
    (HERE / 'repeat-execution.json').write_text(json.dumps({'summary': summary, 'cases': cases,
        'limits': ['Valid synthetic FS data descriptor, flat ES, bounded count and two DF directions.',
                   'No REP fault restart, concurrent memory change, overlapping buffers or full copy function.',
                   'Raw source address omits FS base despite correctly seeded FS_OFFSET.',
                   'Raw model supports only operations seen in these exported REP instructions.']}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
