"""Offline independent arithmetic/trace audit; does not import fixture code.

Original file mapping is parsed here from Mach-O load commands. JSON is observed
evidence, not a substitute for hardware validation or an independent CPU backend.
"""
import hashlib
import itertools
import json
from pathlib import Path
import struct
import capstone

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
RAW = (ROOT / '03_original/x86/binaries/mach_kernel').read_bytes()
assert hashlib.sha256(RAW).hexdigest() == '33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890'
header = struct.unpack_from('<7I', RAW)
assert header[0] == 0xfeedface and header[1] == 7
cursor = struct.calcsize('<7I')
segments = []
for unused in range(header[4]):
    command, size = struct.unpack_from('<2I', RAW, cursor)
    assert size >= struct.calcsize('<2I')
    if command == 1:
        fields = struct.unpack_from('<II16sIIIIiiII', RAW, cursor)
        segments.append(fields[3:7])
    cursor += size
assert cursor == struct.calcsize('<7I') + header[5]


def original(address, size):
    for vmaddr, vmsize, fileoff, filesize in segments:
        if vmaddr <= address and address + size <= vmaddr + filesize:
            offset = fileoff + address - vmaddr
            return RAW[offset:offset + size]
    raise AssertionError((hex(address), size))


CS = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
CS.detail = True
DECODED = {}


def instruction(pc):
    if pc not in DECODED:
        DECODED[pc] = next(CS.disasm(original(pc, 15), pc, count=1))
    return DECODED[pc]


def trace_audit(trace):
    """Check direct branches, call/return nesting, and original IRET landing."""
    pcs = list(map(lambda x: int(x, 16), trace))
    calls = []
    for pc, following in zip(pcs, pcs[1:] + [0x740000]):
        ins = instruction(pc)
        if ins.mnemonic == 'call':
            assert ins.operands[0].type == capstone.x86.X86_OP_IMM
            assert following == ins.operands[0].imm
            calls.append(pc + ins.size)
        elif ins.mnemonic == 'ret':
            assert following == (calls.pop() if calls else 0x740000)
        elif ins.mnemonic.startswith('iret'):
            assert pc == 0x186d7c and following in (0x189e70, 0x18a018)
        elif ins.group(capstone.CS_GRP_JUMP):
            if ins.operands[0].type == capstone.x86.X86_OP_IMM:
                allowed = {ins.operands[0].imm}
                if ins.mnemonic != 'jmp':
                    allowed.add(pc + ins.size)
                assert following in allowed, (hex(pc), hex(following))
            else:
                assert pc == 0x19211a
                assert following == struct.unpack('<I', original(0x192124 + (14 - 1) * 4, 4))[0]
        else:
            assert following == pc + ins.size, (hex(pc), hex(following), ins.mnemonic)
    assert not calls


def load(name):
    return json.loads((HERE / name).read_text())


def expected_hashes(target, length, destination, committed):
    patterns = {name: bytes((i * 17 + (i >> 8) * 29 + seed) & 0xff for i in range(0x2000))
                for name, seed in (('A', 0x31), ('B', 0x79), ('kernel', 0xc7))}
    source = patterns['kernel'][0x100:0x100 + length]
    active = bytearray(patterns[target])
    active[destination:destination + length] = bytes(b ^ 0xff for b in source)
    active[destination:destination + committed] = source[:committed]
    patterns[target] = bytes(active)
    return {name: hashlib.sha256(data).hexdigest() for name, data in patterns.items()}


def main():
    normal, faults, summary = load('normal-high-cs.json'), load('trap-cases.json'), load('trap-review.json')
    flags = {2 | df | intr for df, intr in itertools.product((0, 0x400), (0, 0x200))}
    roots, names = {'A', 'B'}, {'_copyout', '_copyoutmsg'}
    assert {(r['target'], r['function'], r['length'], r['flags']) for r in normal} == set(itertools.product(roots, names, (1, 19), flags))
    scenarios = {('ro', 1, 0x100), ('ro', 32, 0x1000 - 16), ('np', 32, 0x1000 - 16),
                 ('ro', 19, 0x1000 - 18), ('np', 19, 0x1000 - 18)}
    expected_cases = {(t, n, mode, length, dest, f) for t, n, (mode, length, dest), f in itertools.product(roots, names, scenarios, flags)}
    actual_cases = {(r['target'], r['function'], r['mode'], r['length'], r['destination'], r['initial_flags']) for r in faults}
    assert actual_cases == expected_cases and len(faults) == len(expected_cases)
    assert len(normal) == len(roots) * len(names) * 2 * len(flags)
    assert len(normal) == summary['normal_high_cs_cases'] and len(faults) == summary['connected_synthetic_frame_cases']
    for row in normal:
        trace_audit(row['observation']['trace'])
        assert row['buffer_hashes_after'] == expected_hashes(row['target'], row['length'], 0x1000 - 18, row['length'])
    fields = ['gs', 'fs', 'es', 'ds', 'edi', 'esi', 'ebp', 'pushad_esp', 'ebx', 'edx', 'ecx', 'eax', 'trap', 'error', 'eip', 'cs', 'eflags']
    offsets = {name: index * struct.calcsize('<I') for index, name in enumerate(fields)}
    assert summary['frame_offsets'] == offsets
    assert summary['frame_size'] == struct.calcsize('<' + 'I' * len(fields))
    for row in faults:
        trace_audit(row['handler']['trace'])
        assert row['fault_buffer_hashes'] == expected_hashes(row['target'], row['length'], row['destination'], 0 if row['length'] == 1 else 16)
        event = row['fault_run']['interrupts'][0]
        fault = event['snapshot']
        assert event['vector'] == 14 and fault == row['fault_run']['after']
        assert not row['handler']['interrupts'] and row['handler']['error'] is None
        milestones = {int(m['pc'], 16): m for m in row['milestones']}
        before = milestones[0x187068]['saved_state_words']
        after = milestones[0x192213]['saved_state_words']
        landing = {'_copyout': 0x189e70, '_copyoutmsg': 0x18a018}[row['function']]
        assert instruction(landing + 12).mnemonic == 'mov'
        assert instruction(landing + 12).operands[1].imm == row['handler']['after']['eax'] == 14
        wanted = before.copy()
        wanted[fields.index('eip')] = landing
        wanted[fields.index('cs')] = (wanted[fields.index('cs')] & ~0xffff) | 8
        wanted[fields.index('eflags')] &= ~0x400
        assert wanted == after
        frame = dict(zip(fields, before))
        for name in ('gs', 'fs', 'es', 'ds', 'cs'):
            assert frame[name] & 0xffff == fault[name]
        for name in ('edi', 'esi', 'ebp', 'ebx', 'edx', 'ecx', 'eax', 'eip', 'eflags'):
            assert frame[name] == fault[name]
        assert frame['trap'] == 14 and frame['error'] == (3 if row['mode'] == 'ro' else 2)
        assert frame['pushad_esp'] == fault['esp'] - 5 * struct.calcsize('<I')
        assert milestones[landing]['snapshot']['eflags'] == fault['eflags'] & ~0x400
        assert row['handler']['after']['esp'] == 0x710000 + struct.calcsize('<I')
        assert milestones[0x178040]['map_lock'][8:12] == '0100'
        assert milestones[0x178131]['map_lock'] == bytes(12).hex()
        assert row['handler']['trace'].count('0x172038') == row['handler']['trace'].count('0x186d7c') == 1
    native = load('native-delivery.json')
    equal = next(r for r in faults if (r['target'], r['function'], r['mode'], r['length'], r['initial_flags']) == ('A', '_copyout', 'np', 19, 2))
    assert native['observation']['after'] == equal['fault_run']['after']
    assert native['buffer_hashes_after'] == equal['fault_buffer_hashes']
    assert not native['native_idt_handler_reached'] and native['observation']['error'] is not None
    asm_path = ROOT / '04_ghidra/exports/x86/full-pass5/functions/00186d20.asm'
    c_path = asm_path.with_suffix('.c')
    assert 'IRETD' in asm_path.read_text() and 'return CONCAT44(param_2,param_1)' in c_path.read_text()
    assert instruction(0x186d7c).mnemonic.startswith('iret')
    result = {'normal_case_matrix_verified': len(normal), 'fault_case_matrix_verified': len(faults),
              'original_trace_call_return_audits': len(normal) + len(faults),
              'distinct_original_instructions_decoded': len(DECODED),
              'frame_model_and_exact_recovery_delta_verified': len(faults),
              'independent_expected_buffer_hashes_verified': len(normal) + len(faults),
              'native_vs_hooked_failure_equivalence': True,
              'canonical_c_boundary': {'function': '00186d20', 'c_return': 'CONCAT44(param_2,param_1)',
                                       'original_exit': 'IRETD', 'ordinary_c_return_equivalence_verified': False,
                                       'reconstruction_constraint': 'preserve exception-frame/segment/flags/IRETD assembly contract'},
              'hardware_or_whole_analysis_completion_claim': False, 'mismatches': []}
    (HERE / 'independent-audit.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
