"""Original GDT initialization references and explicit FS load provenance."""
import collections
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
spec = importlib.util.spec_from_file_location('original', HERE.parent / 'cautious-followup-20260911/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)
POINTER = 0x1e19b0
INITIAL_GDT = struct.unpack('<I', R.read_original(POINTER, 4))[0]
SELECTOR = 0x50
DESC_SIZE = struct.calcsize('<HHBBBB')
SLOT = INITIAL_GDT + (SELECTOR >> 3) * DESC_SIZE
TARGETS = {R.NAMES[n]: n for n in ('_gdt_init', '_locate_gdt', '_copyin', '_copyinmsg')}


def dis(i):
    return {'site': f'{i.address:08x}', 'bytes': i.bytes.hex(), 'instruction': i.mnemonic + ' ' + i.op_str}


def main():
    references, calls, fs_rows, heads = [], [], [], set()
    used = set(TARGETS)
    for entry in sorted(R.FMAP):
        instructions = R.function_instructions(entry)
        seq = list(instructions.values())
        for index, ins in enumerate(seq):
            heads.add(ins.address)
            matches = []
            for operand in ins.operands:
                if operand.type == R.X86_OP_MEM and not operand.mem.base and not operand.mem.index:
                    address = operand.mem.disp
                    for name, low, size in (('gdt_pointer', POINTER, DWord), ('initial_gdt', INITIAL_GDT, 0x100),
                                            ('gdtr_operand', 0x1e17b0, struct.calcsize('<HI'))):
                        if address < low + size and address + operand.size > low:
                            matches.append({'kind': name, 'address': hex(address), 'size': operand.size,
                                            'access': operand.access})
                elif operand.type == R.X86_OP_IMM and operand.imm in (POINTER, INITIAL_GDT, SLOT):
                    matches.append({'kind': 'address_immediate', 'address': hex(operand.imm)})
            if matches:
                used.add(entry)
                references.append({'owner': f'{entry:08x}', 'name': R.FMAP[entry]['name'], **dis(ins), 'references': matches})
            if ins.mnemonic == 'call' and ins.operands[0].type == R.X86_OP_IMM and ins.operands[0].imm in TARGETS:
                used.add(entry)
                calls.append({'owner': f'{entry:08x}', 'name': R.FMAP[entry]['name'], **dis(ins),
                              'target': TARGETS[ins.operands[0].imm]})
            if ins.mnemonic in ('mov', 'pop') and ins.operands[0].type == R.X86_OP_REG and ins.reg_name(ins.operands[0].reg) == 'fs':
                used.add(entry)
                before = seq[max(0, index - 4):index]
                after = seq[index + 1:index + 9]
                # All current MOV FS sources are AX and have a local constant definition.
                immediate = None
                if ins.mnemonic == 'mov':
                    assert ins.op_str == 'fs, ax'
                    for prev in reversed(before):
                        reads, writes = prev.regs_access()
                        names = {prev.reg_name(r) for r in writes}
                        if names & {'eax', 'ax', 'al', 'ah'}:
                            assert prev.mnemonic == 'mov' and prev.op_str.startswith('ax, ') and prev.operands[1].type == R.X86_OP_IMM
                            immediate = prev.operands[1].imm
                            break
                    assert immediate is not None
                fs_rows.append({'owner': f'{entry:08x}', 'name': R.FMAP[entry]['name'], **dis(ins),
                                'operation': ins.mnemonic, 'constant_selector': immediate,
                                'preceding_instructions': list(map(dis, before)), 'following_window': list(map(dis, after)),
                                'stack_selector_unresolved': ins.mnemonic == 'pop'})
    contexts = {f'{e:08x}': {'name': R.FMAP[e]['name'], 'instructions': list(map(dis, R.function_instructions(e).values()))} for e in sorted(used)}
    summary = {'instruction_heads_scanned': len(heads), 'reference_instructions': len(references),
               'reference_owner_functions': len({r['owner'] for r in references}),
               'explicit_gdt_pointer_write_instructions': sum(any(v['kind'] == 'gdt_pointer' and v.get('access', 0) & 2 for v in r['references']) for r in references),
               'direct_calls_by_target': dict(collections.Counter(r['target'] for r in calls)),
               'fs_mov_loads': sum(r['operation'] == 'mov' for r in fs_rows),
               'fs_mov_constant_selectors': sorted({r['constant_selector'] for r in fs_rows if r['operation'] == 'mov'}),
               'fs_pop_unresolved_loads': sum(r['stack_selector_unresolved'] for r in fs_rows),
               'global_copy_fs_zero_invariant_proven': False}
    result = {'summary': summary, 'initial_gdt_pointer': hex(INITIAL_GDT), 'ldata_descriptor_address': hex(SLOT),
              'initial_ldata_bytes': R.read_original(SLOT, DESC_SIZE).hex(), 'references': references,
              'direct_calls': calls, 'fs_loads': fs_rows, 'original_contexts': contexts,
              'binary_sha256': hashlib.sha256(R.RAW).hexdigest(),
              'limits': ['Only explicit absolute references and immediate direct calls are inventoried.',
                         'Indexed/aliased writes and indirect calls are not globally resolved.',
                         'Local AX constants do not establish the active GDTR or descriptor value on every entry.',
                         'POP FS values and asynchronous/firmware transitions remain separate obligations.']}
    (HERE / 'gdt-review.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(summary, indent=2))
    for row in references:
        if any(r['kind'] == 'gdt_pointer' and r.get('access', 0) & 2 for r in row['references']):
            print('POINTER WRITE', json.dumps(row))
    for row in calls:
        if row['target'] in ('_gdt_init', '_locate_gdt'):
            print('GDT CALL', json.dumps(row))


DWord = struct.calcsize('<I')
if __name__ == '__main__':
    main()
