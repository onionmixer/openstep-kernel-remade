"""Execute original copy/accessor bytes in a bounded Python/Unicorn harness.

Fault delivery is modeled, not a real IDT/IRET execution or kernel boot.
Original files and analysis DBs are read only. All arithmetic is Python.
"""
import collections
import hashlib
import importlib.util
import json
import re
from pathlib import Path
import struct
import sys
import unicorn as U
from unicorn import x86_const as X

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('review_input', HERE.parent / 'cautious-followup-20260911/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)
PAGE = 0x1000
STACK, THREAD, SOURCE, DEST, RETURN = 0x710000, 0x600000, 0x500000, 0x520000, 0x730000
REGS = {n: getattr(X, 'UC_X86_REG_' + n.upper()) for n in ('eax', 'ebx', 'ecx', 'edx', 'esi', 'edi', 'ebp', 'esp', 'eip', 'eflags')}
INITIAL = {'ebx': 0x11223344, 'esi': 0x22334455, 'edi': 0x33445566, 'ebp': 0x44556677}


def u32(value):
    return struct.pack('<I', value & 0xffffffff)


def get32(uc, address):
    return struct.unpack('<I', uc.mem_read(address, 4))[0]


class Run:
    def __init__(self, name, args, src_data=b'', dst_data=b'', flags=0x202, inject_at=None):
        self.name, self.entry = name, R.NAMES[name]
        self.uc = uc = U.Uc(U.UC_ARCH_X86, U.UC_MODE_32)
        for s in R.META['segments']:
            if s['name'] == '__PAGEZERO':
                continue
            a = int(s['address'], 16)
            lo = a & -PAGE
            uc.mem_map(lo, (a + s['size'] - lo + PAGE - 1) & -PAGE)
            uc.mem_write(a, R.RAW[s['file_offset']:s['file_offset'] + s['file_size']])
        for a, size in ((STACK - PAGE, PAGE * 2), (THREAD, PAGE), (SOURCE, PAGE), (DEST, PAGE), (RETURN, PAGE)):
            uc.mem_map(a, size)
        uc.mem_write(0x1e8b54, u32(THREAD))
        uc.mem_write(THREAD + 0x74, u32(0))
        uc.mem_write(SOURCE, (src_data + bytes(PAGE))[:PAGE])
        uc.mem_write(DEST, (dst_data + bytes(PAGE))[:PAGE])
        uc.mem_write(STACK, b''.join(u32(v) for v in (RETURN, *args)))
        for name, value in INITIAL.items():
            uc.reg_write(REGS[name], value)
        uc.reg_write(REGS['esp'], STACK)
        uc.reg_write(REGS['eflags'], flags)
        self.faults, self.trace, self.recover_writes = [], [], []
        self.helper_trace = []
        self.executing_helper = False
        self.inject_at = inject_at

        def invalid(engine, access, address, size, value, _):
            self.faults.append({'pc': hex(engine.reg_read(REGS['eip'])), 'access': access,
                                'address': hex(address), 'size': size,
                                'recover': hex(get32(engine, THREAD + 0x74)),
                                'registers': {n: hex(engine.reg_read(r)) for n, r in REGS.items()}})
            return False

        def code(engine, address, size, _):
            (self.helper_trace if self.executing_helper else self.trace).append(address)
            if not self.executing_helper and self.inject_at == address:
                self.inject_at = None
                self.faults.append({'pc': hex(address), 'access': 'synthetic-before-instruction',
                                    'address': None, 'size': size,
                                    'recover': hex(get32(engine, THREAD + 0x74)),
                                    'registers': {n: hex(engine.reg_read(r)) for n, r in REGS.items()}})
                engine.emu_stop()
                return
            ins = next(R.CS.disasm(bytes(engine.mem_read(address, size)), address, count=1))
            if ins.mnemonic.startswith('call') or ins.mnemonic.startswith('iret'):
                raise RuntimeError(('unmodeled control transfer', hex(address), ins.mnemonic))

        def writes(engine, access, address, size, value, _):
            if address == THREAD + 0x74:
                self.recover_writes.append({'pc': hex(engine.reg_read(REGS['eip'])), 'value': hex(value & 0xffffffff)})

        uc.hook_add(U.UC_HOOK_MEM_INVALID, invalid)
        uc.hook_add(U.UC_HOOK_CODE, code)
        uc.hook_add(U.UC_HOOK_MEM_WRITE, writes)

    def execute(self, expected_fault=False):
        uc = self.uc
        try:
            uc.emu_start(self.entry, RETURN, timeout=1000000, count=20000)
        except U.UcError:
            if not self.faults:
                raise
        if self.faults:
            # A split unaligned access may emit several invalid-memory callbacks
            # for one instruction. Preserve them, but require identical PC/GPRs.
            assert len({f['pc'] for f in self.faults}) == 1
            assert all(f['registers'] == self.faults[0]['registers'] for f in self.faults)
            callback_count = len(self.faults)
            target = get32(uc, THREAD + 0x74)
            assert target in R.FMAP and R.FMAP[target]['analysis_fragment']
            # Run the actual recovery helper on a synthetic saved-state tail and
            # a separate scratch stack. Only interrupt entry/IRET is modeled.
            saved = {n: uc.reg_read(r) for n, r in REGS.items()}
            frame = THREAD + 0x234
            helper_stack = STACK - PAGE + 0x100
            helper_return = RETURN + 0x100
            uc.mem_write(frame, b''.join(u32(v) for v in (0, saved['eip'], 8, saved['eflags'])))
            uc.mem_write(helper_stack, u32(helper_return) + u32(frame))
            uc.reg_write(REGS['esp'], helper_stack)
            self.executing_helper = True
            uc.emu_start(0x1924a0, helper_return, timeout=1000000, count=20000)
            self.executing_helper = False
            assert uc.reg_read(REGS['eip']) == helper_return
            assert uc.reg_read(REGS['esp']) == helper_stack + 4
            assert uc.reg_read(REGS['eax']) == 1
            assert get32(uc, frame + 4) == target
            assert get32(uc, frame + 8) == 8
            assert get32(uc, frame + 12) == saved['eflags'] & ~0x400
            assert get32(uc, THREAD + 0x74) == 0
            for n, value in saved.items():
                uc.reg_write(REGS[n], value)
            uc.reg_write(REGS['eflags'], get32(uc, frame + 12))
            uc.emu_start(target, RETURN, timeout=1000000, count=20000)
            assert len(self.faults) == callback_count
        assert bool(self.faults) == expected_fault, (self.name, self.faults)
        assert uc.reg_read(REGS['eip']) == RETURN, (self.name, 'did not return')
        assert uc.reg_read(REGS['esp']) == STACK + 4
        assert all(uc.reg_read(REGS[n]) == v for n, v in INITIAL.items())
        if self.faults:
            assert get32(uc, THREAD + 0x74) == 0
            assert uc.reg_read(REGS['eflags']) & 0x400 == 0
        return {'name': self.name, 'entry': hex(self.entry), 'faults': self.faults,
                'eax': hex(uc.reg_read(REGS['eax'])), 'recover_after': hex(get32(uc, THREAD + 0x74)),
                'callee_saved_and_stack_restored': True, 'eflags_after': hex(uc.reg_read(REGS['eflags'])),
                'actual_recovery_helper_trace': [hex(a) for a in self.helper_trace],
                'recover_writes': self.recover_writes, 'trace': [hex(a) for a in self.trace]}


def tests():
    results = []
    copy_names = ('_copyin', '_copyinmsg', '_copywithin', '_copyout', '_copyoutmsg')
    for name in copy_names:
        for count in (0, 1, 15, 16, 17, 64):
            for alignment in range(4):
                payload = bytes((i % 251) + 1 for i in range(PAGE))
                run = Run(name, (SOURCE + alignment, DEST + alignment, count), payload)
                row = run.execute()
                assert row['eax'] == '0x0'
                assert bytes(run.uc.mem_read(DEST + alignment, count)) == payload[alignment:alignment + count] if count else True
                results.append({**row, 'case': 'copy-success', 'count': count, 'alignment': alignment})
        for side in ('source', 'destination'):
            for count, prefix in ((1, 0), (15, 3), (16, 4), (17, 8), (64, 1)):
                src = SOURCE + PAGE - prefix if side == 'source' else SOURCE
                dst = DEST + PAGE - prefix if side == 'destination' else DEST
                run = Run(name, (src, dst, count), bytes([0x5a]) * PAGE)
                row = run.execute(expected_fault=True)
                assert row['eax'] == hex(14)
                results.append({**row, 'case': 'copy-fault', 'count': count, 'valid_prefix': prefix, 'fault_side': side})
    for name in ('_copystr', '_copyinstr', '_copyoutstr'):
        for size in (1, 2, 15, 16, 17):
            payload = b'A' * (size - 1) + b'\0'
            run = Run(name, (SOURCE, DEST, size + 1, THREAD + 0x100), payload)
            row = run.execute()
            assert row['eax'] == '0x0'
            assert bytes(run.uc.mem_read(DEST, size)) == payload
            assert get32(run.uc, THREAD + 0x100) == size
            results.append({**row, 'case': 'string-success', 'string_bytes': size})
        for side in ('source', 'destination'):
            for prefix in (0, 1, 3):
                src = SOURCE + PAGE - prefix if side == 'source' else SOURCE
                dst = DEST + PAGE - prefix if side == 'destination' else DEST
                run = Run(name, (src, dst, 8, THREAD + 0x100), b'A' * PAGE)
                row = run.execute(expected_fault=True)
                assert row['eax'] == hex(14)
                results.append({**row, 'case': 'string-fault', 'fault_side': side, 'valid_prefix': prefix})
    for name in ('_fuword', '_fubyte', '_fuibyte', '_suword', '_subyte', '_suibyte'):
        is_read = name.startswith('_fu')
        width = 4 if name.endswith('word') else 1
        for value in (0, 0x7f, 0x80, 0xff, 0x12345678):
            run = Run(name, (SOURCE, value), u32(value))
            row = run.execute()
            if is_read:
                expected = value if width == 4 else int.from_bytes(bytes([value & 0xff]), 'little', signed=True) & 0xffffffff
                assert int(row['eax'], 16) == expected
            else:
                assert row['eax'] == '0x0'
                assert bytes(run.uc.mem_read(SOURCE, width)) == u32(value)[:width]
            results.append({**row, 'case': 'accessor-success', 'value': hex(value), 'width': width})
        for flags in (0x202, 0x602):
            run = Run(name, (SOURCE + PAGE, 0x12345678), flags=flags)
            row = run.execute(expected_fault=True)
            assert row['eax'] == '0xffffffff'
            results.append({**row, 'case': 'accessor-fault', 'initial_flags': hex(flags)})
    return results


def supplemental_faults(rows):
    observed = {int(f['pc'], 16) for r in rows for f in r['faults']}
    injected, not_reached = [], []
    for name in sorted({r['name'] for r in rows}):
        insns = R.function_instructions(R.NAMES[name])
        fs_heads = {a for a, ins in insns.items() if any(op.type == R.X86_OP_MEM and ins.reg_name(op.mem.segment) == 'fs'
                                                      for op in ins.operands)}
        for a in sorted(fs_heads - observed):
            fixture = next((r for r in rows if r['name'] == name and not r['faults'] and hex(a) in r['trace']), None)
            if fixture is None:
                not_reached.append({'name': name, 'site': hex(a), 'reason': 'not reached by successful fixtures'})
                continue
            if fixture['case'] == 'copy-success':
                alignment, count = fixture['alignment'], fixture['count']
                payload = bytes((i % 251) + 1 for i in range(PAGE))
                run = Run(name, (SOURCE + alignment, DEST + alignment, count), payload, inject_at=a)
            elif fixture['case'] == 'string-success':
                size = fixture['string_bytes']
                run = Run(name, (SOURCE, DEST, size + 1, THREAD + 0x100), b'A' * (size - 1) + b'\0', inject_at=a)
            elif fixture['case'] == 'accessor-success':
                value = int(fixture['value'], 16)
                run = Run(name, (SOURCE, value), u32(value), inject_at=a)
            else:
                raise AssertionError(fixture)
            row = run.execute(expected_fault=True)
            expected = 0xffffffff if name.startswith(('_fu', '_su')) else 14
            assert int(row['eax'], 16) == expected
            injected.append({**row, 'case': 'synthetic-fault-at-uncovered-fs-head', 'injected_pc': hex(a),
                             'fixture': {k: v for k, v in fixture.items() if k in ('case', 'count', 'alignment', 'string_bytes', 'value')}})
    # These two alignment-copy dword loops have an impossible positive trip
    # count: source residue r in {1,2,3} gives (4-r)>>2 == 0.
    proofs = []
    expected_dead = {'_copyout': 0x189da9, '_copyoutmsg': 0x189f51}
    proof_addresses = {
        '_copyout': (0x189d5e, 0x189d63, 0x189d68, 0x189d6a, 0x189d9d, 0x189d9f, 0x189da2, 0x189db5, 0x189db6, 0x189db9, 0x189da4),
        '_copyoutmsg': (0x189f06, 0x189f0b, 0x189f10, 0x189f12, 0x189f45, 0x189f47, 0x189f4a, 0x189f5d, 0x189f5e, 0x189f61, 0x189f4c),
    }
    for item in not_reached:
        a = int(item['site'], 16)
        assert expected_dead.get(item['name']) == a, item
        insns = R.function_instructions(R.NAMES[item['name']])
        addresses = proof_addresses[item['name']]
        for addr, token in zip(addresses, ('and edx, 3', 'mov ebx, 4', 'sub ebx, edx', 'mov edx, ebx', 'mov eax, edx', 'sar eax, 2')):
            ins = insns[addr]
            assert f'{ins.mnemonic} {ins.op_str}' == token, (item, token)
        for addr, ins in insns.items():
            if addresses[3] < addr < addresses[4]:
                assert not {'edx', 'dx', 'dl', 'dh'} & {ins.reg_name(r) for r in ins.regs_access()[1]}
        jump, dec, cmp, branch, body = addresses[6:]
        assert insns[jump].mnemonic == 'jmp' and insns[jump].operands[0].imm == dec
        assert insns[dec].mnemonic == 'dec' and insns[dec].op_str == 'eax'
        assert insns[cmp].mnemonic == 'cmp' and insns[cmp].operands[0].reg == insns[dec].operands[0].reg
        assert insns[cmp].operands[1].imm & 0xffffffff == 0xffffffff
        assert insns[branch].mnemonic == 'jne' and insns[branch].operands[0].imm == body
        predecessors = [addr for addr, ins in insns.items() if ins.mnemonic.startswith('j') and ins.operands[0].type == R.X86_OP_IMM and ins.operands[0].imm == body]
        assert predecessors == [branch]
        cases = [{'source_residue': r, 'alignment_bytes': 4 - r, 'dword_count': (4 - r) >> 2} for r in range(1, 4)]
        assert all(c['dword_count'] == 0 for c in cases)
        proofs.append({**item, 'classification': 'normal-entry alignment invariant makes this dword-copy loop unreachable',
                       'cases': cases, 'instruction_evidence': [f'{addr:#x}: {insns[addr].mnemonic} {insns[addr].op_str}' for addr in addresses],
                       'qualification': 'Requires the observed alignment setup and unmodified normal control flow; sequence checked against saved original-byte decode.'})
    return injected, proofs


def access_coverage(rows):
    observed = {int(f['pc'], 16) for r in rows for f in r['faults']}
    functions = []
    for name in sorted({r['name'] for r in rows}):
        insns = R.function_instructions(R.NAMES[name])
        fs_accesses = {a for a, ins in insns.items() if any(op.type == R.X86_OP_MEM
                       and ins.reg_name(op.mem.segment) == 'fs' for op in ins.operands)}
        functions.append({'name': name, 'entry': hex(R.NAMES[name]),
                          'fs_access_heads': [hex(a) for a in sorted(fs_accesses)],
                          'fs_fault_heads_tested': [hex(a) for a in sorted(fs_accesses & observed)],
                          'fs_fault_heads_untested': [hex(a) for a in sorted(fs_accesses - observed)],
                          'other_fault_heads_tested': [hex(a) for a in sorted(set(insns) & observed - fs_accesses)]})
    return {'scope': 'FS memory operand inventory for the tested functions only; excludes other possible fault causes and computed aliases.',
            'functions': functions, 'counts': {'unique_fault_instruction_heads': len(observed),
               'fs_access_heads': sum(len(f['fs_access_heads']) for f in functions),
               'fs_fault_heads_tested': sum(len(f['fs_fault_heads_tested']) for f in functions),
               'fs_fault_heads_untested': sum(len(f['fs_fault_heads_untested']) for f in functions)}}


def segment_rendering_review():
    comparisons = []
    for name in ('_copyin', '_copyinmsg'):
        entry = R.NAMES[name]
        insns = R.function_instructions(entry)
        ida_path = R.ROOT / '05_ida/exports/x86/functions' / f'{entry:08x}.c'
        for line in ida_path.read_text().splitlines():
            match = re.search(r'/\*(0x[0-9a-fA-F]+)\*/', line)
            if '__writefs' not in line or match is None:
                continue
            a = int(match.group(1), 16)
            ins = insns[a]
            segments = [ins.reg_name(op.mem.segment) for op in ins.operands if op.type == R.X86_OP_MEM]
            if segments == ['es', 'fs']:
                comparisons.append({'function': name, 'site': hex(a), 'bytes': R.read_original(a, ins.size).hex(),
                                    'original_decode': ins.mnemonic + ' ' + ins.op_str,
                                    'destination_segment': 'es', 'source_segment': 'fs',
                                    'ida_rendering': line.strip(), 'ida_file': str(ida_path.relative_to(R.ROOT))})
    return {'comparisons': comparisons, 'count': len(comparisons),
            'verdict': 'Saved IDA C assigns FS to both sides where original-byte decoder identifies ES destination and FS source.',
            'limits': 'Underlying IDA database bytes/bounds are not independently revalidated here. Flat-base test success cannot validate segment privilege/limit semantics.'}


def main():
    assert hashlib.sha256(R.RAW).hexdigest() == R.META['sha256']
    rows = tests()
    injected, dead_proofs = supplemental_faults(rows)
    rows.extend(injected)
    summary = {'tests': len(rows), 'by_case': dict(collections.Counter(r['case'] for r in rows)),
               'functions': len({r['name'] for r in rows}),
               'success_with_recover_still_set': sum(not r['faults'] and r['recover_after'] != '0x0' for r in rows),
               'fault_tests': sum(bool(r['faults']) for r in rows)}
    result = {'summary': summary, 'runtime': {'python': sys.version, 'unicorn': U.__version__, 'capstone': R.capstone.__version__},
              'binary_sha256': R.META['sha256'], 'tests': rows,
              'normal_entry_unreachable_fs_heads': dead_proofs,
              'limitations': ['Flat zero-base segment harness, no segment permission/limit proof.',
                              'The original recovery helper executes on a synthetic frame; interrupt entry and final frame restoration are modeled, not actual IDT/trap/IRET execution.',
                              'Only listed input fixtures; no complete-input or boot correctness claim.',
                              'GPR/ESP restoration is checked for these fixtures; arbitrary interrupt interleavings are not modeled.']}
    (HERE / 'fault-execution.json').write_text(json.dumps(result, indent=2) + '\n')
    coverage = access_coverage(rows)
    (HERE / 'memory-access-coverage.json').write_text(json.dumps(coverage, indent=2) + '\n')
    rendering = segment_rendering_review()
    (HERE / 'segment-rendering-review.json').write_text(json.dumps(rendering, indent=2) + '\n')
    print(json.dumps(summary, indent=2))
    print(json.dumps(coverage['counts'], indent=2))
    print(json.dumps({'saved_ida_segment_mismatches': rendering['count']}, indent=2))


if __name__ == '__main__':
    main()
