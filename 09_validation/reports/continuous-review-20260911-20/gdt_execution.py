"""Original GDT initializer, FS entry constants, and non-flat ES REP probes."""
import importlib.util
import itertools
import json
import struct
import sys
from gdt_review import HERE, R, POINTER, INITIAL_GDT, SELECTOR, DESC_SIZE

sys.path.insert(0, str(HERE.parent / 'continuous-review-20260911-19'))
import repeat_execution as REP
from segment_execution import RawModel, node
D, X = REP.D, REP.X


def decode(payload):
    lo, base_lo, base_mid, access, flags, base_hi = struct.unpack('<HHBBBB', payload)
    encoded_limit = lo | ((flags & 0xf) << 16)
    granular = (flags >> 7) & 1
    limit = (encoded_limit << 12) | 0xfff if granular else encoded_limit
    return {'base': base_lo | (base_mid << 16) | (base_hi << 24), 'limit': limit,
            'type': access & 0x1f, 'dpl': (access >> 5) & 3, 'present': bool(access & 0x80),
            'flags': flags, 'bytes': payload.hex()}


def initialized(table, seed):
    uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
    uc.mem_write(table, bytes([seed]) * 0x100)
    D.put(uc, POINTER, table)
    D.put(uc, D.STACK, D.STOP)
    D.run_to(uc, R.NAMES['_gdt_init'], D.STOP)
    assert uc.reg_read(X.UC_X86_REG_GDTR)[1:3] == (table, 0xff)
    descriptors = {hex(sel): decode(bytes(uc.mem_read(table + (sel >> 3) * DESC_SIZE, DESC_SIZE)))
                   for sel in (0x8, 0x10, 0x48, 0x50, 0x60, 0x68)}
    assert descriptors['0x50']['base'] == 0 and descriptors['0x10']['base'] == 0xc0000000
    assert descriptors['0x50']['limit'] == 0xbfffffff and descriptors['0x10']['limit'] == 0x3fffffff
    D.assert_callee_saved(uc)
    assert uc.reg_read(X.UC_X86_REG_ESP) == D.STACK + D.WORD
    for pc in trace:
        ins = next(R.CS.disasm(R.read_original(pc, 15), pc, count=1))
        assert bytes(uc.mem_read(pc, ins.size)) == ins.bytes
    return uc, trace, descriptors


def main():
    inventory = json.loads((HERE / 'gdt-review.json').read_text())
    fs_loads = [r for r in inventory['fs_loads'] if r['operation'] == 'mov']
    init_rows, fs_rows, rep_rows, relocation_rows = [], [], [], []
    for table, seed in itertools.product((INITIAL_GDT, D.DATA + 0xc00), (0, 0x5a, 0xff)):
        uc, trace, desc = initialized(table, seed)
        init_rows.append({'table': hex(table), 'initial_fill': seed, 'descriptors': desc,
                          'gdtr': list(uc.reg_read(X.UC_X86_REG_GDTR)), 'trace': list(map(hex, trace))})
        relocated, relocation_trace, _ = initialized(table, seed)
        relocation_call = R.function_instructions(R.NAMES['_i386_init'])[0x18ab8f]
        D.run_to(relocated, 0x18ab84, relocation_call.address + relocation_call.size)
        expected_gdtr_base = (table + 0xc0000000) & 0xffffffff
        assert relocated.reg_read(X.UC_X86_REG_GDTR)[1:3] == (expected_gdtr_base, 0xff)
        assert D.words(relocated, POINTER, 1) == [table]
        for pc in relocation_trace:
            original = next(R.CS.disasm(R.read_original(pc, 15), pc, count=1))
            assert bytes(relocated.mem_read(pc, original.size)) == original.bytes
        relocation_rows.append({'table_pointer': hex(table), 'initial_fill': seed,
                                'relocated_gdtr_base': hex(expected_gdtr_base), 'pointer_storage_unchanged': True,
                                'whole_page_mapping_validated': False})
        # Arbitrary fill patterns test initialization fields, not validity of all reserved bits.
        if seed != 0:
            continue
        for row in fs_loads:
            ins = R.function_instructions(int(row['owner'], 16))[int(row['site'], 16)]
            assert row['constant_selector'] == SELECTOR
            uc.reg_write(X.UC_X86_REG_EAX, SELECTOR)
            D.run_to(uc, ins.address, ins.address + ins.size)
            assert uc.reg_read(X.UC_X86_REG_FS) == SELECTOR
            address, value = D.DATA + 0x500, 0x98765432
            D.put(uc, address, value)
            uc.reg_write(X.UC_X86_REG_EAX, address)
            read = R.function_instructions(0x18a184)[0x18a197]
            reads = []
            hook = uc.hook_add(D.U.UC_HOOK_MEM_READ, lambda u, a, p, n, v, x: reads.append((p, n)))
            D.run_to(uc, read.address, read.address + read.size)
            uc.hook_del(hook)
            assert reads == [(address, D.WORD)] and uc.reg_read(X.UC_X86_REG_EDX) == value
            fs_rows.append({'load_site': row['site'], 'table': hex(table), 'selector': hex(SELECTOR),
                            'observed_fs_read_address': hex(reads[0][0]), 'logical_offset': hex(address), 'base_zero_observed': True})
    previous = json.loads((HERE.parent / 'continuous-review-20260911-19/pcode-audit.json').read_text())
    rep_sites = [r for r in previous['memory_accesses'] if not r['raw_uses_hidden_base']]
    for row in rep_sites:
        ins = R.function_instructions(int(row['owner'], 16))[int(row['site'], 16)]
        width = ins.operands[0].size
        df_node, = {node(op['inputs'][0]) for op in row['raw_operations'] if op['opcode'] == 'INT_ZEXT'}
        for count, df in itertools.product((1, 3), (0, 1)):
            table = INITIAL_GDT
            uc, trace, desc = initialized(table, 0)
            # These are original initialized GDT descriptors. Flat CS/SS remain fixture state;
            # paging is off, so hooks expose linear addresses, not real kernel physical mappings.
            uc.reg_write(X.UC_X86_REG_ES, 0x10)
            fs_ins = R.function_instructions(0x186ddc)[0x186dfc]
            uc.reg_write(X.UC_X86_REG_EAX, SELECTOR)
            D.run_to(uc, fs_ins.address, fs_ins.address + fs_ins.size)
            source, destination = D.DATA + 0x500, D.DATA + 0x900
            es_base = desc['0x10']['base']
            linear_dest = (es_base + destination) & 0xffffffff
            uc.mem_map(linear_dest & -D.PAGE, D.PAGE)
            model = RawModel(tuple(previous['hidden_base_nodes']['fs']), 0)
            for reg, address, value in ((X.UC_X86_REG_ECX, 4, count), (X.UC_X86_REG_ESI, 0x18, source),
                                         (X.UC_X86_REG_EDI, 0x1c, destination)):
                uc.reg_write(reg, value)
                model.put(('register', address, D.WORD), value)
            model.put(df_node, df)
            uc.reg_write(X.UC_X86_REG_EFLAGS, 2 | (df << 10))
            direction = -1 if df else 1
            srcs = [source + direction * i * width for i in range(count)]
            dsts = [destination + direction * i * width for i in range(count)]
            for src, dst in zip(srcs, dsts):
                for address, byte in ((src, 0xa5), (dst, 0xcc), ((es_base + dst) & 0xffffffff, 0xdd)):
                    payload = bytes([byte]) * width
                    uc.mem_write(address, payload)
                    model.store(address, int.from_bytes(payload, 'little'), width)
            reads, writes = [], []
            uc.hook_add(D.U.UC_HOOK_MEM_READ, lambda u, a, p, n, v, x: reads.append({'address': hex(p), 'size': n}))
            uc.hook_add(D.U.UC_HOOK_MEM_WRITE, lambda u, a, p, n, v, x: writes.append({'address': hex(p), 'size': n, 'value': v}))
            trace.clear()
            D.run_to(uc, ins.address, ins.address + ins.size)
            raw_writes = REP.run_raw(row['raw_operations'], ins.address, ins.address + ins.size, model)
            assert reads == model.reads == [{'address': hex(src), 'size': width} for src in srcs]
            assert [w['address'] for w in writes] == [hex((es_base + dst) & 0xffffffff) for dst in dsts]
            assert [w['address'] for w in raw_writes] == list(map(hex, dsts))
            for dst in dsts:
                assert bytes(uc.mem_read((es_base + dst) & 0xffffffff, width)) == bytes([0xa5]) * width
                assert bytes(uc.mem_read(dst, width)) == bytes([0xcc]) * width
                assert bytes(model.memory[dst + i] for i in range(width)) == bytes([0xa5]) * width
            assert bytes(uc.mem_read(ins.address, ins.size)) == ins.bytes
            rep_rows.append({'site': row['site'], 'count': count, 'df': df, 'fs_base': 0, 'es_base': hex(es_base),
                             'original_reads': reads, 'raw_reads': model.reads, 'original_writes': writes,
                             'raw_writes': raw_writes, 'linear_destination_mismatch': True,
                             'interpretation': 'Raw RAM treated as linear memory; no external coordinate translation adapter.'})
    summary = {'gdt_initializer_cases': len(init_rows), 'initialized_base_checks_passed': True,
               'original_fs_constant_load_probes': len(fs_rows), 'fs_zero_observed_probes': sum(r['base_zero_observed'] for r in fs_rows),
               'original_gdtr_relocation_probes': len(relocation_rows),
               'nonflat_es_rep_cases': len(rep_rows),
               'linear_destination_mismatch_cases': sum(r['linear_destination_mismatch'] for r in rep_rows),
               'global_copy_fs_zero_invariant_proven': False, 'flat_ram_model_whole_kernel_equivalent': False}
    (HERE / 'gdt-execution.json').write_text(json.dumps({'summary': summary, 'initialization': init_rows,
        'fs_entry_probes': fs_rows, 'gdtr_relocation_probes': relocation_rows, 'nonflat_es_rep': rep_rows,
        'limits': ['Original GDT initialization runs, but full boot, page tables, privilege transitions and interrupts do not.',
                   'Only explicit entry MOV FS sites use known initialized GDT; POP FS and every caller path are not proven.',
                   'Linear-address comparison is conditional on raw RAM coordinate interpretation.',
                   'Ghidra address-space adapters or source-level compiler segment conventions may supply extra context.',
                   'No assertion that original copy code is faulty or that reconstructed C has been compiled.']}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))
    print(json.dumps(init_rows[0]['descriptors'], indent=2))


if __name__ == '__main__':
    main()
