"""Original-entry PC emulation fixtures with explicit synthetic fault delivery.

No original bytes/DB changes. All address/descriptor/count operations are Python.
Interrupt entry and IRET remain modeled; no boot/whole-input claim.
"""
import collections
import hashlib
import importlib.util
import itertools
import json
from pathlib import Path
import struct
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('copy_harness', HERE.parent / 'continuous-review-20260911-02/fault_execution.py')
F = importlib.util.module_from_spec(spec)
spec.loader.exec_module(F)
R, U, X = F.R, F.U, F.X
PAGE, STACK, THREAD, RETURN = F.PAGE, F.STACK, F.THREAD, F.RETURN
REGS, INITIAL, u32, get32 = F.REGS, F.INITIAL, F.u32, F.get32
PCB, LINK, COMMON, STATE = 0x610000, 0x620000, 0x630000, 0x640000
USER_CODE, USER_STACK, LDT, IDT = 0x80000, 0x90000, 0x82000, 0x83000


def descriptor(base, access, wide):
    # Software-parsed i386 segment descriptor; not installed as host/guest GDT.
    limit = 0xffff
    return struct.pack('<HHBBBB', limit & 0xffff, base & 0xffff,
                       (base >> 16) & 0xff, access, (0x40 if wide else 0) | (limit >> 16), (base >> 24) & 0xff)


class PCMachine:
    def __init__(self, entry, target, mode, opcode, gate, trapno, wide, inject_ordinal=0):
        self.entry, self.target = entry, target
        self.fixture = {'mode': mode, 'opcode': hex(opcode), 'gate': hex(gate), 'trapno': trapno,
                        'wide_stack': wide, 'inject_ordinal': inject_ordinal}
        self.uc = uc = U.Uc(U.UC_ARCH_X86, U.UC_MODE_32)
        for s in R.META['segments']:
            if s['name'] == '__PAGEZERO':
                continue
            a = int(s['address'], 16)
            lo = a & -PAGE
            uc.mem_map(lo, (a + s['size'] - lo + PAGE - 1) & -PAGE)
            uc.mem_write(a, R.RAW[s['file_offset']:s['file_offset'] + s['file_size']])
        for a, size in ((STACK - PAGE, PAGE * 2), (THREAD, PAGE), (PCB, PAGE), (LINK, PAGE),
                        (COMMON, PAGE), (STATE, PAGE), (USER_CODE, PAGE), (USER_STACK, PAGE),
                        (LDT, PAGE), (IDT, PAGE), (0, PAGE), (RETURN, PAGE)):
            uc.mem_map(a, size)
        for a, value in ((0x1e8b54, THREAD), (THREAD + 0x28, PCB), (PCB + 0xec, LINK), (LINK, COMMON),
                         (COMMON + 0x30, IDT), (COMMON + 0x34, 0x100),
                         (COMMON + 0x38, LDT), (COMMON + 0x3c, 0x100), (COMMON + 0x84, 0),
                         (STATE + 0x30, trapno), (STATE + 0x38, 0x100),
                         (STATE + 0x40, 0x202 | (0x20000 if mode == 'real' else 0)),
                         (STATE + 0x44, 0x800), (COMMON + 0x88 + 0x68, 1)):
            uc.mem_write(a, u32(value))
        cs, ss = (USER_CODE >> 4, USER_STACK >> 4) if mode == 'real' else (0x0c, 0x14)
        uc.mem_write(STATE + 0x3c, u32(cs))
        uc.mem_write(STATE + 0x48, u32(ss))
        uc.mem_write(LDT + 8, descriptor(USER_CODE, 0x9a, True))
        uc.mem_write(LDT + 16, descriptor(USER_STACK, 0x92, wide))
        for vector in range(32):
            uc.mem_write(IDT + vector * 8, struct.pack('<HHBBH', 0x200, 0x0c, 0, 0x80 | gate, 0))
            uc.mem_write(vector * 4, struct.pack('<HH', 0x200, USER_CODE >> 4))
        code = bytes((0xc4, 0xc4, opcode, 0)) if opcode in (0xfa, 0xfc, 0xfd, 0xfe) else bytes((opcode, 3, 0, 0))
        # BOP helpers expect c4 c4 xx; instruction helpers can select plain opcodes.
        if entry in (R.NAMES['_PCemulateREAL'], 0x1a37c0) and trapno != 6:
            code = bytes((opcode, 3, 0, 0))
        uc.mem_write(USER_CODE + 0x100, code)
        uc.mem_write(USER_STACK, bytes((i % 251) + 1 for i in range(PAGE)))
        # Small, mapped values for popped IP/CS/flags and BOP argument arrays.
        uc.mem_write(USER_STACK + 0x800, struct.pack('<IIIIII', 0x100, cs, 0x202, 0, 0, 0))
        args = (THREAD, STATE, trapno if entry == 0x1a3160 else 0, 0, 0)
        uc.mem_write(STACK, b''.join(u32(v) for v in (RETURN, *args)))
        for name, value in INITIAL.items():
            uc.reg_write(REGS[name], value)
        uc.reg_write(REGS['esp'], STACK)
        uc.reg_write(REGS['eflags'], 0x202)
        self.trace, self.helper_trace, self.writes, self.fault = [], [], [], None
        self.frontier, self.invalid, self.in_helper = None, [], False
        self.target_accesses = 0
        self.access_log = []
        self.initial_state = bytes(uc.mem_read(STATE, 0x80))
        self.initial_buffer = bytes(uc.mem_read(USER_STACK + 0x780, 0x100))

        def code_hook(engine, address, size, _):
            (self.helper_trace if self.in_helper else self.trace).append(address)
            ins = next(R.CS.disasm(bytes(engine.mem_read(address, size)), address, count=1))
            if not self.in_helper and self.fault is None and get32(engine, THREAD + 0x74) == target:
                if any(op.type == R.X86_OP_MEM and ins.reg_name(op.mem.segment) == 'fs' for op in ins.operands):
                    ordinal = self.target_accesses
                    self.target_accesses += 1
                    self.access_log.append({'ordinal': ordinal, 'pc': hex(address), 'assembly': ins.mnemonic + ' ' + ins.op_str})
                    if ordinal == inject_ordinal:
                        self.fault = {'pc': hex(address), 'assembly': ins.mnemonic + ' ' + ins.op_str,
                                      'recover': hex(target), 'access_ordinal': ordinal,
                                      'registers': {n: engine.reg_read(r) for n, r in REGS.items()},
                                      'state_before': bytes(engine.mem_read(STATE, 0x80)).hex(),
                                      'stack_buffer_before': bytes(engine.mem_read(USER_STACK + 0x780, 0x100)).hex()}
                        engine.emu_stop()
                        return
            if ins.mnemonic == 'call':
                callee = ins.operands[0].imm if ins.operands[0].type == R.X86_OP_IMM else engine.reg_read(getattr(X, 'UC_X86_REG_' + ins.reg_name(ins.operands[0].reg).upper())) if ins.operands[0].type == R.X86_OP_REG else None
                if callee is None or not 0x1a1b60 <= callee <= 0x1a3ac4:
                    self.frontier = {'site': hex(address), 'callee': hex(callee) if callee is not None else None,
                                     'reason': 'external call not replaced with a success stub'}
                    engine.emu_stop()
            elif ins.mnemonic.startswith('iret'):
                self.frontier = {'site': hex(address), 'reason': 'IRET outside this fixture scope'}
                engine.emu_stop()

        def invalid_hook(engine, access, address, size, value, _):
            self.invalid.append({'pc': hex(engine.reg_read(REGS['eip'])), 'address': hex(address), 'access': access})
            return False

        def write_hook(engine, access, address, size, value, _):
            if address == THREAD + 0x74:
                self.writes.append({'pc': hex(engine.reg_read(REGS['eip'])), 'value': hex(value & 0xffffffff)})

        uc.hook_add(U.UC_HOOK_CODE, code_hook)
        uc.hook_add(U.UC_HOOK_MEM_INVALID, invalid_hook)
        uc.hook_add(U.UC_HOOK_MEM_WRITE, write_hook)

    def execute(self):
        uc = self.uc
        error = None
        try:
            uc.emu_start(self.entry, RETURN, timeout=1000000, count=30000)
            if self.fault:
                saved = self.fault['registers']
                frame, helper_stack, helper_return = THREAD + 0x234, STACK - PAGE + 0x100, RETURN + 0x100
                uc.mem_write(frame, b''.join(u32(v) for v in (0, saved['eip'], 8, saved['eflags'])))
                uc.mem_write(helper_stack, u32(helper_return) + u32(frame))
                uc.reg_write(REGS['esp'], helper_stack)
                self.in_helper = True
                uc.emu_start(0x1924a0, helper_return, timeout=1000000, count=1000)
                self.in_helper = False
                assert uc.reg_read(REGS['eip']) == helper_return and uc.reg_read(REGS['eax']) == 1
                assert get32(uc, frame + 4) == self.target and get32(uc, THREAD + 0x74) == 0
                assert get32(uc, frame + 12) == saved['eflags'] & ~0x400
                for n, v in saved.items():
                    uc.reg_write(REGS[n], v)
                uc.reg_write(REGS['eflags'], get32(uc, frame + 12))
                uc.emu_start(self.target, RETURN, timeout=1000000, count=30000)
        except U.UcError as exc:
            error = str(exc)
        returned = uc.reg_read(REGS['eip']) == RETURN
        preserved = all(uc.reg_read(REGS[n]) == v for n, v in INITIAL.items())
        stack_ok = uc.reg_read(REGS['esp']) == STACK + 4
        result = {'entry': hex(self.entry), 'name': R.FMAP[self.entry]['name'], 'target': hex(self.target),
                  'fixture': self.fixture, 'fault': self.fault, 'returned': returned,
                  'callee_saved_ok': preserved, 'caller_stack_ok': stack_ok, 'eax': hex(uc.reg_read(REGS['eax'])),
                  'recover_after': hex(get32(uc, THREAD + 0x74)), 'frontier': self.frontier, 'invalid': self.invalid,
                  'emulator_error': error, 'trace': [hex(a) for a in self.trace],
                  'helper_trace': [hex(a) for a in self.helper_trace], 'recover_writes': self.writes,
                  'state_after': bytes(uc.mem_read(STATE, 0x80)).hex(),
                  'stack_buffer_after': bytes(uc.mem_read(USER_STACK + 0x780, 0x100)).hex()}
        result['target_accesses'] = self.access_log
        state_after = bytes.fromhex(result['state_after'])
        buffer_after = bytes.fromhex(result['stack_buffer_after'])
        result['state_changed_offsets'] = [hex(i) for i, (a, b) in enumerate(zip(self.initial_state, state_after)) if a != b]
        result['user_stack_changed_offsets'] = [hex(0x780 + i) for i, (a, b) in enumerate(zip(self.initial_buffer, buffer_after)) if a != b]
        result['state_control_fields'] = {name: {'before': hex(struct.unpack_from('<I', self.initial_state, off)[0]),
                                               'after': hex(struct.unpack_from('<I', state_after, off)[0])}
                                          for name, off in (('eip', 0x38), ('cs', 0x3c), ('eflags', 0x40), ('esp', 0x44), ('ss', 0x48))}
        result['status'] = 'fault-return-verified' if self.fault and returned and preserved and stack_ok and not self.invalid and get32(uc, THREAD + 0x74) == 0 else 'unverified'
        return result


def fixture_options(entry):
    if entry < 0x1a2b40 and entry not in (0x1a27b0, 0x1a28a0, 0x1a29dc):
        mode = 'real'
    elif entry in (0x1a27b0, 0x1a28a0, 0x1a29dc):
        mode = 'real'
    else:
        mode = 'prot'
    if entry in (0x1a1b60, 0x1a2b40):
        return [(mode, op, 0xe, 6, True) for op in (0xfa, 0xfc, 0xfd)]
    if entry == 0x1a3160:
        return [(mode, 0xcd, gate, trapno, wide) for gate, trapno, wide in itertools.product((0xe, 6), (3, 14), (True, False))]
    return [(mode, 0xcd, 0xe, 13, wide) for wide in (True, False)]


def main():
    assert hashlib.sha256(R.RAW).hexdigest() == R.META['sha256']
    inputs = json.loads((HERE.parent / 'continuous-review-20260911-01/dispatch-and-provenance-paths.json').read_text())
    candidates = [c for c in inputs['candidate_links'] if int(c['entry'], 16) >= 0x1a0000]
    rows, failures, attempts = [], [], []
    for c in candidates:
        entry, target = int(c['entry'], 16), int(c['target'], 16)
        found = None
        for fixture in fixture_options(entry):
            result = PCMachine(entry, target, *fixture).execute()
            attempts.append({k: v for k, v in result.items() if k not in ('trace', 'helper_trace', 'state_after', 'stack_buffer_after')})
            if result['status'] == 'fault-return-verified':
                found = result
                break
        if found:
            rows.append(found)
        else:
            failures.append({'entry': hex(entry), 'target': hex(target), 'last_result': result})
    partial_rows, end_probes = [], []
    for row in rows:
        v = row['fixture']
        options = (v['mode'], int(v['opcode'], 16), int(v['gate'], 16), v['trapno'], v['wide_stack'])
        for ordinal in range(1, 32):
            result = PCMachine(int(row['entry'], 16), int(row['target'], 16), *options, inject_ordinal=ordinal).execute()
            if result['status'] == 'fault-return-verified':
                partial_rows.append(result)
                continue
            end_probes.append({k: val for k, val in result.items() if k not in ('trace', 'helper_trace', 'state_after', 'stack_buffer_after')})
            # A probe that reaches no requested ordinal ends this bounded access
            # sequence; a reached fault with failed restoration is a real failure.
            assert result['fault'] is None, result
            break
        else:
            raise AssertionError(('access sequence bound reached', row['target']))
    all_verified = rows + partial_rows
    observed = {int(r['fault']['pc'], 16) for r in all_verified}
    coverage = []
    for entry in sorted({int(c['entry'], 16) for c in candidates}):
        insns = R.function_instructions(entry)
        fs_heads = {a for a, ins in insns.items() if any(op.type == R.X86_OP_MEM and ins.reg_name(op.mem.segment) == 'fs' for op in ins.operands)}
        coverage.append({'entry': hex(entry), 'fs_heads': [hex(a) for a in sorted(fs_heads)],
                         'tested_heads': [hex(a) for a in sorted(fs_heads & observed)],
                         'untested_heads': [hex(a) for a in sorted(fs_heads - observed)]})
    summary = {'candidate_targets': len(candidates), 'verified_target_fixtures': len(rows), 'unverified_targets': len(failures),
               'fixture_attempts': len(attempts), 'eax_distribution': dict(collections.Counter(r['eax'] for r in rows))}
    summary.update({'later_access_fault_tests': len(partial_rows), 'total_verified_fault_tests': len(all_verified),
                    'end_of_sequence_probes': len(end_probes),
                    'unique_fault_instruction_heads': len({r['fault']['pc'] for r in all_verified}),
                    'candidate_owner_functions': len(coverage),
                    'fs_heads': sum(len(c['fs_heads']) for c in coverage),
                    'untested_fs_heads': sum(len(c['untested_heads']) for c in coverage),
                    'failure_returns_with_partial_user_stack_writes': sum(r['eax'] == '0x0' and bool(r['user_stack_changed_offsets']) for r in all_verified)})
    result = {'summary': summary, 'verified': rows, 'later_access_verified': partial_rows,
              'end_of_sequence_probes': end_probes, 'unverified': failures, 'attempts': attempts,
              'fs_coverage': coverage,
              'binary_sha256': hashlib.sha256(R.RAW).hexdigest(),
              'runtime': {'python': sys.version, 'unicorn': U.__version__, 'capstone': R.capstone.__version__},
              'scope': 'Actual function entry and original helper/landing execution under synthetic PC thread/state/descriptor fixtures. Faults injected before selected FS accesses. IDT entry and IRET are modeled; no all-input/boot claim.'}
    (HERE / 'pc-fault-execution.json').write_text(json.dumps(result, indent=2) + '\n')
    prior = json.loads((HERE.parent / 'continuous-review-20260911-02/fault-execution.json').read_text())
    original_targets = {int(c['target'], 16) for c in inputs['candidate_links']}
    prior_targets = {int(f['recover'], 16) for t in prior['tests'] for f in t['faults']}
    pc_targets = {int(r['target'], 16) for r in rows}
    combined = {'original_candidate_targets': len(original_targets), 'copy_accessor_targets_tested': len(prior_targets),
                'pc_targets_tested': len(pc_targets), 'combined_tested_targets': len(prior_targets | pc_targets),
                'targets_without_any_fixture': [hex(a) for a in sorted(original_targets - prior_targets - pc_targets)],
                'copy_report': '../continuous-review-20260911-02/fault-execution.json', 'pc_report': 'pc-fault-execution.json',
                'completion_qualification': 'Only previously identified candidates have bounded fault fixtures. Not all aliases, all inputs, or actual trap/IRET/boot verification.'}
    (HERE / 'recovery-validation-index.json').write_text(json.dumps(combined, indent=2) + '\n')
    contracts = []
    for row in rows:
        target = int(row['target'], 16)
        suffix = row['trace'][row['trace'].index(hex(target)):]
        related = [r for r in all_verified if r['target'] == row['target']]
        calls = []
        for address in suffix:
            a = int(address, 16)
            ins = next(R.CS.disasm(R.read_original(a, 15), a, count=1))
            if ins.mnemonic == 'call':
                dst = ins.operands[0].imm if ins.operands[0].type == R.X86_OP_IMM else None
                calls.append({'site': address, 'target': hex(dst) if dst is not None else None,
                              'name': R.FMAP[dst]['name'] if dst in R.FMAP else None})
        final = next(R.CS.disasm(R.read_original(int(suffix[-1], 16), 15), int(suffix[-1], 16), count=1))
        assert final.mnemonic == 'ret'
        contracts.append({'target': row['target'], 'owning_entry': row['entry'], 'owning_name': row['name'],
                          'verified_fault_fixtures': len(related), 'observed_eax': sorted({r['eax'] for r in related}),
                          'sample_return_instruction': suffix[-1], 'sample_recovery_trace': suffix,
                          'sample_recovery_calls': calls,
                          'partial_user_stack_changes_on_failure': any(r['eax'] == '0x0' and r['user_stack_changed_offsets'] for r in related),
                          'interpretation': 'Non-call exception landing in owning function context, not an independent C ABI callback.',
                          'scope': 'Fixture-observed contract, not universal equivalence proof.'})
    (HERE / 'recovery-contracts.json').write_text(json.dumps(contracts, indent=2) + '\n')
    print(json.dumps(summary, indent=2))
    for f in failures:
        r = f['last_result']
        print(json.dumps({'entry': f['entry'], 'target': f['target'], 'fault_reached': bool(r['fault']),
                          'returned': r['returned'], 'eax': r['eax'], 'invalid': r['invalid'], 'frontier': r['frontier'],
                          'armed': sorted({w['value'] for w in r['recover_writes']})}))


if __name__ == '__main__':
    main()
