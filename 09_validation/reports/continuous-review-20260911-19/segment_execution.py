"""Original FS loads and raw P-code across descriptor rewrite/reload stages.

Selected original instructions are composed in a synthetic fixture, NOT an
assertion that the kernel's own CFG connects these snippets in that sequence.
"""
import importlib.util
import itertools
import json
from pathlib import Path
import re
import struct
from audit_pcode import HERE, R, node

spec = importlib.util.spec_from_file_location('dispatch', HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py')
D = importlib.util.module_from_spec(spec)
spec.loader.exec_module(D)
X = D.X
HEADERS = R.ROOT.parent / 'ref/openstep/headers/NextDeveloper/Headers/architecture/i386'
DESC = (HEADERS / 'desc.h').read_text()
DATA_TYPE = int(re.search(r'#define DESC_DATA_WRITE\s+(0x[0-9a-f]+)', DESC)[1], 16)
GDT = D.DATA + 0xc00
SELECTOR = 0xa << 3
BASE_PAIRS = ((0x800000, 0x810000), (0x810000, 0x800000), (0x800000, 0x820000))
READ_ENTRY, READ_PC = 0x18a184, 0x18a197


def descriptor(base, limit=D.PAGE - 1, granular=0):
    # SDK desc.h: limit00/base00/base16/type+dpl+present/limit16+stksz+granular/base24.
    return struct.pack('<HHBBBB', limit & 0xffff, base & 0xffff, (base >> 16) & 0xff,
                       DATA_TYPE | (1 << 7), ((limit >> 16) & 0xf) | (1 << 6) | (granular << 7), (base >> 24) & 0xff)


class RawModel:
    def __init__(self, hidden_node, base):
        self.registers = bytearray(0x800)
        self.memory = {}
        self.reads = []
        self.put(tuple(hidden_node), base)

    def put(self, key, value):
        space, offset, size = key
        assert space == 'register'
        self.registers[offset:offset + size] = int(value).to_bytes(size, 'little')

    def store(self, address, value, size):
        self.memory.update({address + i: b for i, b in enumerate(value.to_bytes(size, 'little'))})

    def run(self, operations):
        temps = {}

        def get(v):
            space, offset, size = node(v)
            if space == 'const':
                return offset
            if space == 'register':
                return int.from_bytes(self.registers[offset:offset + size], 'little')
            return temps[(space, offset, size)]

        for op in operations:
            args = [get(v) for v in op['inputs']]
            dest = node(op['output'])
            if op['opcode'] == 'COPY':
                value = args[0]
            elif op['opcode'] == 'INT_ADD':
                value = args[0] + args[1]
            elif op['opcode'] == 'LOAD':
                address = args[1]
                value = int.from_bytes(bytes(self.memory[address + i] for i in range(dest[2])), 'little')
                self.reads.append({'address': hex(address), 'size': dest[2]})
            else:
                raise AssertionError(op)
            value &= (1 << (dest[2] * 8)) - 1
            if dest[0] == 'register':
                self.put(dest, value)
            else:
                temps[dest] = value


def case(row, base_a, base_b, offset, read_raw, hidden_node, selector_node):
    uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
    for base in sorted({v for pair in BASE_PAIRS for v in pair}):
        uc.mem_map(base, D.PAGE)
    slot = GDT + (SELECTOR >> 3) * struct.calcsize('<HHBBBB')
    uc.mem_write(slot, descriptor(base_a))
    # Make the synthetic stack's cached descriptor explicitly 32-bit. The default
    # SS cache must not silently become a 16-bit stack after another segment load.
    stack_selector = 0x2 << 3
    uc.mem_write(GDT + (stack_selector >> 3) * struct.calcsize('<HHBBBB'), descriptor(0, 0xfffff, 1))
    uc.reg_write(X.UC_X86_REG_GDTR, (0, GDT, 0xff, 0))
    uc.reg_write(X.UC_X86_REG_SS, stack_selector)
    val_a, val_b = 0x12345678, 0xaabbccdd
    D.put(uc, base_a + offset, val_a)
    D.put(uc, base_b + offset, val_b)
    model = RawModel(hidden_node, base_a)
    model.store(base_a + offset, val_a, D.WORD)
    model.store(base_b + offset, val_b, D.WORD)
    original_ins = R.function_instructions(int(row['owner'], 16))[int(row['site'], 16)]
    read_ins = R.function_instructions(READ_ENTRY)[READ_PC]
    effects = []

    def read_hook(engine, access, address, size, value, unused):
        effects.append({'kind': 'read', 'address': hex(address), 'size': size})

    def write_hook(engine, access, address, size, value, unused):
        effects.append({'kind': 'write', 'address': hex(address), 'size': size, 'value': value})

    uc.hook_add(D.U.UC_HOOK_MEM_READ, read_hook)
    uc.hook_add(D.U.UC_HOOK_MEM_WRITE, write_hook)

    def load_selector():
        if row['operation'] == 'mov':
            uc.reg_write(X.UC_X86_REG_EAX, SELECTOR)
            source_node = node(row['raw_operations'][0]['inputs'][0])
            model.put(source_node, SELECTOR)
        else:
            assert row['operation'] == 'pop'
            uc.reg_write(X.UC_X86_REG_ESP, D.STACK)
            D.put(uc, D.STACK, SELECTOR)
            source_node = node(row['raw_operations'][0]['inputs'][1])
            model.put(source_node, D.STACK)
            model.store(D.STACK, SELECTOR, D.WORD)
        effects.clear()
        D.run_to(uc, original_ins.address, original_ins.address + original_ins.size)
        captured = list(effects)
        model.run(row['raw_operations'])
        assert uc.reg_read(X.UC_X86_REG_FS) == SELECTOR
        assert int.from_bytes(model.registers[selector_node[1]:selector_node[1] + selector_node[2]], 'little') == SELECTOR
        assert int.from_bytes(model.registers[hidden_node[1]:hidden_node[1] + hidden_node[2]], 'little') == base_a
        if row['operation'] == 'pop':
            assert uc.reg_read(X.UC_X86_REG_ESP) == D.STACK + D.WORD
        loaded_desc = bytes(uc.mem_read(slot, struct.calcsize('<HHBBBB')))
        # CPU model sets the data descriptor's accessed bit on load.
        assert loaded_desc[5] & 1
        return {'memory_effects': captured, 'descriptor_after': loaded_desc.hex()}

    stages = []
    first_load = load_selector()
    for stage in ('loaded_a', 'gdt_changed_no_reload', 'same_selector_reloaded_b'):
        if stage == 'gdt_changed_no_reload':
            uc.mem_write(slot, descriptor(base_b))
        elif stage == 'same_selector_reloaded_b':
            second_load = load_selector()
        uc.reg_write(X.UC_X86_REG_EAX, offset)
        model.put(('register', 0, D.WORD), offset)
        effects.clear()
        model.reads.clear()
        D.run_to(uc, read_ins.address, read_ins.address + read_ins.size)
        model.run(read_raw)
        actual = uc.reg_read(X.UC_X86_REG_EDX)
        raw_dest = node(read_raw[-1]['output'])
        raw_value = int.from_bytes(model.registers[raw_dest[1]:raw_dest[1] + raw_dest[2]], 'little')
        expected_base = base_b if stage == 'same_selector_reloaded_b' else base_a
        assert actual == (val_b if expected_base == base_b else val_a)
        assert effects == [{'kind': 'read', 'address': hex(expected_base + offset), 'size': D.WORD}]
        assert raw_value == val_a
        assert model.reads == [{'address': hex(base_a + offset), 'size': D.WORD}]
        stages.append({'stage': stage, 'original_reads': list(effects), 'raw_reads': list(model.reads),
                       'original_value': hex(actual), 'raw_value': hex(raw_value), 'mismatch': actual != raw_value})
    for pc in trace:
        ins = next(R.CS.disasm(R.read_original(pc, 15), pc, count=1))
        assert bytes(uc.mem_read(pc, ins.size)) == ins.bytes
    return {'load_site': row['site'], 'operation': row['operation'], 'selector': hex(SELECTOR),
            'base_a': hex(base_a), 'base_b': hex(base_b), 'offset': hex(offset),
            'first_load': first_load, 'second_load': second_load, 'stages': stages,
            'trace': [f'{p:08x}' for p in trace]}


def main():
    audit = json.loads((HERE / 'pcode-audit.json').read_text())
    read = next(r for r in audit['memory_accesses'] if r['site'] == f'{READ_PC:08x}')
    hidden = tuple(audit['hidden_base_nodes']['fs'])
    selector = tuple(audit['selector_nodes']['fs'])
    assert node(read['raw_operations'][0]['inputs'][0]) == hidden
    rows = [case(r, a, b, offset, read['raw_operations'], hidden, selector)
            for r in audit['selector_writes'] if r['target_selector'] == 'fs'
            for (a, b), offset in itertools.product(BASE_PAIRS, (0x80, 0xff8))]
    summary = {'fs_load_sites_executed': len({r['load_site'] for r in rows}),
               'staged_cases': len(rows), 'original_instruction_executions': sum(len(r['trace']) for r in rows),
               'original_raw_read_comparisons': sum(len(r['stages']) for r in rows),
               'read_value_mismatches': sum(s['mismatch'] for r in rows for s in r['stages']),
               'mismatch_stages': sorted({s['stage'] for r in rows for s in r['stages'] if s['mismatch']}),
               'pop_original_stack_read_sizes': sorted({e['size'] for r in rows if r['operation'] == 'pop'
                   for key in ('first_load', 'second_load') for e in r[key]['memory_effects']
                   if e['kind'] == 'read' and e['address'] == hex(D.STACK)}),
               'pop_raw_stack_read_sizes': sorted({node(op['output'])[2] for r in audit['selector_writes']
                   if r['target_selector'] == 'fs' and r['operation'] == 'pop'
                   for op in r['raw_operations'] if op['opcode'] == 'LOAD'}),
               'raw_hidden_base_transition_fidelity_pass': False}
    (HERE / 'segment-execution.json').write_text(json.dumps({'summary': summary, 'cases': rows,
        'initial_condition': 'Raw FS_OFFSET is seeded to the correct already-known base A; no external repair after reload.',
        'proposed_contract': {'status': 'not_integrated', 'obligations': ['Track selector and cached base/limit/access attributes separately.',
             'Resolve descriptor and refresh cached state on selector load, including reload of the same selector.',
             'A descriptor memory rewrite alone must not be treated as a cached-base update.',
             'Preserve descriptor access effects; validate privilege, null selectors, limits and faults separately.']},
        'limits': ['Synthetic GDT and composed original instruction snippets, not whole kernel control flow.',
                   'Only valid present writable GDT data descriptors and FS were executed; GS is inventory-only.',
                   'No LDT/null/invalid selector, protection fault, CPL transition, interrupt or concurrent descriptor change.',
                   'Memory hooks are Unicorn observations, not physical bus transactions.',
                   'Raw interpreter only handles COPY/LOAD/INT_ADD needed here; no runtime hidden-state adapter is injected.']}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
