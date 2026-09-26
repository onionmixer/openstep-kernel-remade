"""Read-only follow-up review. All calculations and bounded models are Python.

This is not an x86 emulator or a boot test. The small interpreter deliberately
accepts only the instructions needed for two bounded state-transition checks.
"""
import bisect
import collections
import csv
import hashlib
import json
from pathlib import Path
import capstone
from capstone.x86_const import X86_OP_REG, X86_OP_MEM, X86_OP_IMM

ROOT = Path('/mnt/USERS/onion/DATA_ORIGN/Workspace/NeXT_DRIVER/openstep-kernel-remade')
OUT = ROOT / '09_validation/reports/cautious-followup-20260911'
G = ROOT / '04_ghidra/exports/x86/full-pass5'
RAW = (ROOT / '03_original/x86/binaries/mach_kernel').read_bytes()
META = json.loads((ROOT / '03_original/x86/inventory/macho.json').read_text())
FUNCS = json.loads((G / 'functions.json').read_text())
FMAP = {int(f['address'], 16): f for f in FUNCS}
NAMES = {f['name']: int(f['address'], 16) for f in FUNCS}
CS = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
CS.detail = True


def read_original(address, size):
    segment = next(s for s in META['segments'] if int(s['address'], 16) <= address
                   and address + size <= int(s['address'], 16) + s['file_size'])
    offset = segment['file_offset'] + address - int(segment['address'], 16)
    return RAW[offset:offset + size]


def function_instructions(entry):
    instructions = {}
    for line in (G / 'functions' / f'{entry:08x}.asm').read_text().splitlines():
        address, length, _ = line.split('\t', 2)
        address, length = int(address, 16), int(length)
        ins = next(CS.disasm(read_original(address, length), address, count=1))
        assert ins.size == length
        instructions[address] = ins
    return instructions


class BoundedModel:
    """Little-endian memory; no hardware, interrupts, or system interaction."""
    def __init__(self):
        self.regs = {}
        self.memory = {}
        self.zf = False
        self.trace = []

    def write(self, address, value, size=4):
        for i in range(size):
            self.memory[address + i] = (value >> (i * 8)) & 0xff

    def read(self, address, size=4):
        return sum(self.memory[address + i] << (i * 8) for i in range(size))

    def address(self, ins, op):
        assert not op.mem.segment
        base = self.regs[ins.reg_name(op.mem.base)] if op.mem.base else 0
        index = self.regs[ins.reg_name(op.mem.index)] if op.mem.index else 0
        return (base + index * op.mem.scale + op.mem.disp) & 0xffffffff

    def get(self, ins, op):
        if op.type == X86_OP_IMM:
            return op.imm & ((1 << (op.size * 8)) - 1)
        if op.type == X86_OP_REG:
            return self.regs[ins.reg_name(op.reg)]
        if op.type == X86_OP_MEM:
            return self.read(self.address(ins, op), op.size)
        raise ValueError('unsupported operand')

    def put(self, ins, op, value):
        value &= (1 << (op.size * 8)) - 1
        if op.type == X86_OP_REG:
            name = ins.reg_name(op.reg)
            assert op.size == 4, ('partial register not implemented', name)
            self.regs[name] = value
        elif op.type == X86_OP_MEM:
            self.write(self.address(ins, op), value, op.size)
        else:
            raise ValueError('unsupported destination')

    def push(self, value):
        self.regs['esp'] = (self.regs['esp'] - 4) & 0xffffffff
        self.write(self.regs['esp'], value)

    def pop(self):
        value = self.read(self.regs['esp'])
        self.regs['esp'] = (self.regs['esp'] + 4) & 0xffffffff
        return value

    def run(self, instructions, entry, mocked_calls=()):
        pc = entry
        for _ in range(200):
            ins = instructions[pc]
            self.trace.append(hex(pc))
            ops = ins.operands
            nxt = pc + ins.size
            if ins.mnemonic == 'mov':
                self.put(ins, ops[0], self.get(ins, ops[1]))
            elif ins.mnemonic == 'push':
                self.push(self.get(ins, ops[0]))
            elif ins.mnemonic == 'pop':
                self.put(ins, ops[0], self.pop())
            elif ins.mnemonic in ('and', 'xor', 'add'):
                a, b = self.get(ins, ops[0]), self.get(ins, ops[1])
                value = a & b if ins.mnemonic == 'and' else a ^ b if ins.mnemonic == 'xor' else a + b
                self.put(ins, ops[0], value)
                self.zf = (value & 0xffffffff) == 0
            elif ins.mnemonic == 'test':
                self.zf = (self.get(ins, ops[0]) & self.get(ins, ops[1])) == 0
            elif ins.mnemonic in ('jne', 'je'):
                if self.zf == (ins.mnemonic == 'je'):
                    nxt = self.get(ins, ops[0])
            elif ins.mnemonic == 'call':
                assert self.get(ins, ops[0]) in mocked_calls
                self.push(nxt)
                # Explicit assumption: mocked _splx returns normally, preserves the
                # restored callee-saved registers, and does not alter saved target.
                self.regs['eax'] = 0xfeedface
                assert self.pop() == nxt
            elif ins.mnemonic == 'ret':
                return self.pop()
            else:
                raise ValueError(('unsupported instruction', ins.mnemonic))
            pc = nxt
        raise ValueError('bounded model did not terminate')


def state_tests():
    recover_entry = 0x1924a0
    recover_ins = function_instructions(recover_entry)
    recover_tests = []
    for target in (0, 0x189b18, 0x18a1ac):
        for flags in (0, 0x202, 0x602, 0xffffffff):
            m = BoundedModel()
            m.regs = {'esp': 0x700000, 'ebp': 0x710000}
            m.write(0x700000, 0x12345678)
            m.write(0x700004, 0x500000)
            m.write(0x1e8b54, 0x600000)
            m.write(0x600074, target)
            m.write(0x500004, 0x87654321)
            m.write(0x500008, 0xdead1234)
            m.write(0x50000c, flags)
            returned = m.run(recover_ins, recover_entry)
            assert returned == 0x12345678 and m.regs['esp'] == 0x700004
            assert m.regs['ebp'] == 0x710000
            assert m.regs['eax'] == bool(target)
            assert m.read(0x500004) == (target if target else 0x87654321)
            assert m.read(0x500008) == (0xdead0008 if target else 0xdead1234)
            assert m.read(0x50000c) == (flags & 0xfffffbff if target else flags)
            assert m.read(0x600074) == 0
            recover_tests.append({'recover': hex(target), 'input_flags': hex(flags),
                                  'saved_eip_after': hex(m.read(0x500004)),
                                  'saved_cs_dword_after': hex(m.read(0x500008)),
                                  'saved_flags_after': hex(m.read(0x50000c)), 'trace': m.trace})
    jump_tests = []
    entry = NAMES['_jump_label']
    instructions = function_instructions(entry)
    for target in (0x101234, 0x12345678, 0xfedcba98):
        for argument in (0, 1, 42):
            m = BoundedModel()
            m.regs = {'esp': 0x700000}
            m.write(0x700000, 0x1cae30)
            m.write(0x700004, 0x500000)
            m.write(0x700008, argument)
            saved = [0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x800000, target, 0x55]
            for i, value in enumerate(saved):
                m.write(0x500000 + i * 4, value)
            returned = m.run(instructions, entry, (NAMES['_splx'],))
            assert returned == target and returned != 0x1cae30
            assert m.regs['esp'] == 0x800004 and m.regs['eax'] == 1
            for name, value in zip(('edi', 'esi', 'ebx', 'ebp'), saved):
                assert m.regs[name] == value
            jump_tests.append({'saved_target': hex(target), 'second_argument': argument,
                               'returned_target': hex(returned), 'eax_after': m.regs['eax'],
                               'esp_after': hex(m.regs['esp']), 'trace': m.trace})
    return {'recover_helper': recover_tests, 'jump_label': jump_tests,
            'scope': 'Bounded Python models of decoded original bytes; not hardware emulation or boot validation.',
            'jump_label_assumption': '_splx returns normally with its ABI-preserved registers and saved target intact.'}


def scan():
    ranges = sorted((int(r['start'], 16), int(r['end_inclusive'], 16), int(f['address'], 16))
                    for f in FUNCS for r in f['body'])
    starts = [r[0] for r in ranges]

    def owner(address):
        index = bisect.bisect_right(starts, address) - 1
        if index >= 0 and ranges[index][0] <= address <= ranges[index][1]:
            f = FMAP[ranges[index][2]]
            return {'entry': f['address'], 'name': f['name'], 'fragment': f['analysis_fragment']}
        return None

    candidates, calls = [], []
    with (G / 'code-units.tsv').open() as stream:
        for unit in csv.DictReader(stream, delimiter='\t'):
            if unit['kind'] != 'instruction':
                continue
            a, size = int(unit['start'], 16), int(unit['length'])
            ins = next(CS.disasm(read_original(a, size), a, count=1))
            assert ins.size == size
            ops = ins.operands
            if ins.mnemonic == 'mov' and len(ops) == 2 and ops[0].type == X86_OP_MEM and ops[1].type == X86_OP_IMM:
                target = ops[1].imm & 0xffffffff
                if ops[0].mem.disp == 0x74 and owner(target):
                    candidates.append({'store': hex(a), 'assembly': ins.mnemonic + ' ' + ins.op_str,
                                       'owner': owner(a), 'target': hex(target), 'target_owner': owner(target),
                                       'target_is_owner_entry': int(owner(target)['entry'], 16) == target,
                                       'classification': 'candidate recover-address store; base provenance requires evidence'})
            if ins.mnemonic == 'call' and ops[0].type == X86_OP_IMM:
                target = ops[0].imm & 0xffffffff
                if target in {NAMES[n] for n in ('_jump_label', '__return_with_state', '_thread_exception_return', '_panic')}:
                    calls.append({'from': hex(a), 'target': hex(target), 'target_name': FMAP[target]['name'],
                                  'owner': owner(a), 'fallthrough': hex(a + size)})
    high = [json.loads(line) for line in (ROOT / '09_validation/reports/deep-review-20260911/ghidra-functions.jsonl').read_text().splitlines()]
    no_return = {int(row['entry'], 16): row['noreturn'] for row in high}
    return {'candidate_recovery_stores': candidates, 'selected_calls': calls,
            'selected_function_noreturn_flags': {name: no_return[NAMES[name]] for name in
                ('_jump_label', '__return_with_state', '_thread_exception_return', '_thread_syscall_return', '_panic', '_abort')},
            'counts': {'candidate_stores': len(candidates), 'unique_candidate_targets': len({x['target'] for x in candidates}),
                       'targets_marked_fragment': len({x['target'] for x in candidates if x['target_owner']['fragment']}),
                       'targets_inside_owner_not_entry': len({x['target'] for x in candidates if not x['target_is_owner_entry']}),
                       'calls_by_target': dict(collections.Counter(x['target_name'] for x in calls))}}


def supplementary(inventory):
    contexts = []
    for candidate in inventory['candidate_recovery_stores']:
        insns = list(function_instructions(int(candidate['owner']['entry'], 16)).values())
        index = next(i for i, ins in enumerate(insns) if ins.address == int(candidate['store'], 16))
        store = insns[index]
        previous = insns[index - 1] if index else None
        direct = bool(previous and previous.mnemonic == 'mov'
                      and previous.operands[0].type == X86_OP_REG
                      and previous.operands[0].reg == store.operands[0].mem.base
                      and previous.operands[1].type == X86_OP_MEM
                      and previous.operands[1].mem.disp == 0x1e8b54
                      and not previous.operands[1].mem.base
                      and not previous.operands[1].mem.index
                      and previous.address + previous.size == store.address)
        contexts.append({**candidate, 'immediate_active_thread_base': direct,
                         'preceding_context': [f'{ins.address:#x}: {ins.mnemonic} {ins.op_str}'
                                               for ins in insns[max(0, index - 3):index + 1]]})
    cpu = function_instructions(0x18ac28)
    assert cpu[0x18ac33].mnemonic == 'or' and cpu[0x18ac3b].mnemonic == 'test'
    assert cpu[0x18ac33].operands[0].reg == cpu[0x18ac3b].operands[0].reg
    mask = cpu[0x18ac33].operands[1].imm
    assert mask == cpu[0x18ac3b].operands[1].imm and mask != 0
    # Abstract domain: the tested bit is initially either zero or one; all other
    # bits are irrelevant to TEST with this single-bit mask.
    assert mask & (mask - 1) == 0
    bit_cases = [{'initial_masked_bit': hex(value), 'test_result': hex((value | mask) & mask)}
                 for value in (0, mask)]
    shutdown = function_instructions(NAMES['_md_do_shutdown'])
    halt_loops = []
    for a, ins in shutdown.items():
        if ins.mnemonic == 'hlt':
            following = shutdown[a + ins.size]
            assert following.mnemonic == 'jmp' and following.operands[0].imm == a
            halt_loops.append(hex(a))
    integrity = []
    for rel in ('09_validation/reports/full-analysis/artifact-hashes.json',
                '09_validation/reports/deep-review-20260911/review-artifact-hashes.json'):
        entries = json.loads((ROOT / rel).read_text())
        failures = []
        for item in entries:
            path = ROOT / item['path']
            if not path.is_file():
                failures.append({'path': item['path'], 'reason': 'missing'})
                continue
            data = path.read_bytes()
            if len(data) != item['size'] or hashlib.sha256(data).hexdigest() != item['sha256']:
                failures.append({'path': item['path'], 'reason': 'size or hash differs'})
        integrity.append({'manifest': rel, 'checked': len(entries), 'failures': failures})
    return {'recovery_contexts': contexts,
            'recovery_provenance_counts': {
                'direct_active_thread_base': sum(c['immediate_active_thread_base'] for c in contexts),
                'base_provenance_not_proven_by_this_check': sum(not c['immediate_active_thread_base'] for c in contexts)},
            'frame_offsets_from_original_frame': {name: hex(0x34 + offset)
                for name, offset in (('eip', 4), ('cs', 8), ('eflags', 12))},
            'distinct_caller_owners': {name: len({c['owner']['entry'] for c in inventory['selected_calls']
                                                     if c['target_name'] == name})
                                       for name in inventory['counts']['calls_by_target']},
            'cpu_first_halt_test': {'mask': hex(mask), 'abstract_cases': bit_cases,
                'assumption': 'Normal sequential execution; intervening PUSH/POPFD does not change EDX.'},
            'shutdown': {'ret_instructions': [hex(a) for a, ins in shutdown.items() if ins.mnemonic.startswith('ret')],
                         'hlt_self_loops': halt_loops,
                         'scope': 'Structural evidence, not a proof of every callee or hardware behavior.'},
            'integrity': integrity, 'original_sha256': hashlib.sha256(RAW).hexdigest()}


def main():
    assert hashlib.sha256(RAW).hexdigest() == META['sha256']
    tests, inventory = state_tests(), scan()
    (OUT / 'bounded-state-tests.json').write_text(json.dumps(tests, indent=2) + '\n')
    (OUT / 'recovery-and-return-inventory.json').write_text(json.dumps(inventory, indent=2) + '\n')
    extra = supplementary(inventory)
    (OUT / 'supplementary-checks.json').write_text(json.dumps(extra, indent=2) + '\n')
    print(json.dumps({'test_counts': {k: len(tests[k]) for k in ('recover_helper', 'jump_label')},
                      'scan': inventory['counts'], 'noreturn': inventory['selected_function_noreturn_flags'],
                      'supplementary': {k: v for k, v in extra.items() if k != 'recovery_contexts'}}, indent=2))


if __name__ == '__main__':
    main()
