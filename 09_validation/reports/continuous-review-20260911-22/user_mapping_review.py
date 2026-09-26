"""Mixed-CS synthetic user mappings: original root selector and whole copyin.

PLAN.md predates this code and records independent pre-code review. No kernel,
original database or binary edits. All address/model calculations use Python.
"""
import collections
import hashlib
import importlib.util
import itertools
import json
from pathlib import Path
import re
import sys
import traceback
from verify_artifacts import preserved

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('paging21', HERE.parent / 'continuous-review-20260911-21/paging_review.py')
P = importlib.util.module_from_spec(spec)
spec.loader.exec_module(P)
R, D, U, X = P.R, P.D, P.U, P.X
PAGE, BASE = P.PAGE, P.BASE
BUFFER, SPAN, THREAD, TSS_OLD, TSS_NEW = 0x600000, PAGE * 2, 0x680000, 0x650000, 0x650100
ROOTS = {'A': 0x800000, 'B': 0x802000}
TABLES = {name: root + PAGE for name, root in ROOTS.items()}
PAYLOAD = {'A': 0x900000, 'B': 0xa00000}
SWITCH_START, SWITCH_END, WRITE_CR3 = 0x18d3e7, 0x18d3f2, 0x18d3ef
TARGETS = {'_copyin': 0x189b18, '_copyinmsg': 0x189c00}
PATTERNS = {name: bytes((i * 17 + (i >> 8) * 29 + seed) & 0xff for i in range(SPAN))
            for name, seed in (('A', 0x31), ('B', 0x79), ('kernel', 0xc7))}


def decoded(pc):
    return next(R.CS.disasm(R.read_original(pc, 15), pc, count=1))


def original_bytes(uc, trace):
    for pc in set(trace):
        ins = decoded(pc)
        assert bytes(uc.mem_read(pc, ins.size)) == ins.bytes, hex(pc)


def reset_buffers(uc):
    for name, physical in PAYLOAD.items():
        uc.mem_write(physical, PATTERNS[name])
    uc.mem_write(BUFFER, PATTERNS['kernel'])


def fixture():
    uc = P.fixture(0xc00000, 0x20000)
    P.run(uc, R.NAMES['_pmap_bootstrap'], D.STOP)
    initial_root = uc.reg_read(X.UC_X86_REG_CR3)
    assert not uc.reg_read(X.UC_X86_REG_CR4) & 0x20, 'PAE outside two-level walker contract'
    call = decoded(0x18ab8f)
    P.run(uc, 0x18ab84, call.address + call.size)
    # Execute original DS/ES/SS setup, but deliberately do not execute far CS jump.
    P.run(uc, 0x186117, 0x186124)
    fs = decoded(0x186dfc)
    uc.reg_write(X.UC_X86_REG_EAX, 0x50)
    P.run(uc, fs.address, fs.address + fs.size)
    expected_segments = {'cs': 0x48, 'ds': 0x10, 'es': 0x10, 'ss': 0x10, 'fs': 0x50}
    for name, value in expected_segments.items():
        assert uc.reg_read(getattr(X, 'UC_X86_REG_' + name.upper())) == value
    low_index = BUFFER >> 22
    assert (BUFFER + SPAN - 1) >> 22 == low_index
    old_pde, = D.words(uc, initial_root + low_index * D.WORD, 1)
    original_table = old_pde & 0xfffff000
    rows = []
    for name, root in ROOTS.items():
        uc.mem_write(root, bytes(uc.mem_read(initial_root, PAGE)))
        uc.mem_write(TABLES[name], bytes(uc.mem_read(original_table, PAGE)))
        D.put(uc, root + low_index * D.WORD, TABLES[name] | 7)
        for off in range(0, SPAN, PAGE):
            pte_address = TABLES[name] + (((BUFFER + off) >> 12) & 0x3ff) * D.WORD
            D.put(uc, pte_address, (PAYLOAD[name] + off) | 7)
            low = P.walk(uc, root, BUFFER + off)
            high = P.walk(uc, root, BASE + BUFFER + off)
            assert low['present'] and low['user'] and low['writable']
            assert int(low['physical'], 16) == PAYLOAD[name] + off
            assert high['present'] and not high['user'] and high['writable']
            assert int(high['physical'], 16) == BUFFER + off
            assert int(low['pte_address'], 16) & -PAGE != int(high['pte_address'], 16) & -PAGE
            rows.append({'context': name, 'low': low, 'high': high})
        # CS remains flat, whereas data/stack/GDT accesses may be high.
        for offset in (R.NAMES['_copyin'], R.NAMES['_copyinmsg'], SWITCH_START, D.STOP,
                       D.STACK, TSS_OLD, TSS_NEW, THREAD, 0x1e8b54):
            for linear in (offset, BASE + offset):
                mapping = P.walk(uc, root, linear)
                assert mapping['present'] and int(mapping['physical'], 16) == offset
        gdt_linear = uc.reg_read(X.UC_X86_REG_GDTR)[1]
        assert P.walk(uc, root, gdt_linear)['physical'] == hex(gdt_linear - BASE)
    reset_buffers(uc)
    return uc, {'initial_root': hex(initial_root), 'segments': expected_segments,
                'gdtr': list(uc.reg_read(X.UC_X86_REG_GDTR)), 'mapping_pairs': rows,
                'cr0': hex(uc.reg_read(X.UC_X86_REG_CR0)), 'cr4': hex(uc.reg_read(X.UC_X86_REG_CR4)),
                'tlb_mode': 'Unicorn default; no ctl_set_tlb_mode call',
                'tb_cache_helper': 'Inherited P.run calls ctl_remove_cache on start code page; not a TLB proof.'}


def switch(uc, target):
    old_root, new_root = uc.reg_read(X.UC_X86_REG_CR3), ROOTS[target]
    D.put(uc, TSS_OLD + 0x1c, old_root)
    D.put(uc, TSS_NEW + 0x1c, new_root)
    uc.reg_write(X.UC_X86_REG_EAX, TSS_NEW)
    uc.reg_write(X.UC_X86_REG_EDX, TSS_OLD)
    visits = []
    h = uc.hook_add(U.UC_HOOK_CODE, lambda u, pc, n, x: visits.append(pc))
    P.run(uc, SWITCH_START, SWITCH_END)
    uc.hook_del(h)
    assert uc.reg_read(X.UC_X86_REG_CR3) == new_root
    assert (WRITE_CR3 in visits) == (old_root != new_root)
    original_bytes(uc, visits)
    # Distinguish API physical backing access from executed FS linear access.
    reset_buffers(uc)
    address = BUFFER + 0x100
    direct = bytes(uc.mem_read(address, D.WORD))
    expected = PATTERNS[target][0x100:0x100 + D.WORD]
    assert direct == PATTERNS['kernel'][0x100:0x100 + D.WORD] and direct != expected
    uc.reg_write(X.UC_X86_REG_EAX, address)
    ins = decoded(0x18a197)
    P.run(uc, ins.address, ins.address + ins.size)
    observed = uc.reg_read(X.UC_X86_REG_EDX).to_bytes(D.WORD, 'little')
    assert observed == expected
    old_mapping = P.walk(uc, old_root, address)
    stale_root_prediction = bytes(uc.mem_read(int(old_mapping['physical'], 16), D.WORD))
    assert (stale_root_prediction != observed) == (old_root != new_root)
    original_bytes(uc, [ins.address])
    return {'target': target, 'old_root': hex(old_root), 'new_root': hex(new_root),
            'original_trace': list(map(hex, visits)), 'cr3_write_executed': WRITE_CR3 in visits,
            'api_direct_bytes': direct.hex(), 'fs_instruction_bytes_read': observed.hex(),
            'old_root_python_prediction': stale_root_prediction.hex(),
            'old_root_prediction_differs': stale_root_prediction != observed,
            'python_walk': P.walk(uc, new_root, address), 'api_coordinate_gate_passed': True}


def copy_case(uc, target, name, length, offset):
    reset_buffers(uc)
    source, destination = BUFFER + offset, BUFFER + 0x800 + (offset & 3)
    expected = bytearray(PATTERNS['kernel'])
    dest_offset = destination - BUFFER
    source_bytes = PATTERNS[target][offset:offset + length]
    expected[dest_offset:dest_offset + length] = source_bytes
    D.put(uc, 0x1e8b54, THREAD)
    D.put(uc, THREAD + 0x74, 0)
    D.put(uc, D.STACK, D.STOP, source, destination, length)
    for reg, value in D.REGS.values():
        uc.reg_write(reg, value)
    uc.reg_write(X.UC_X86_REG_ESP, D.STACK)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    visits = []
    hook = uc.hook_add(U.UC_HOOK_CODE, lambda u, pc, n, x: visits.append(pc))
    P.run(uc, R.NAMES[name], D.STOP)
    uc.hook_del(hook)
    assert uc.reg_read(X.UC_X86_REG_EAX) == 0
    assert uc.reg_read(X.UC_X86_REG_ESP) == D.STACK + D.WORD
    assert D.words(uc, D.STACK, 1) == [D.STOP]
    D.assert_callee_saved(uc)
    actual = bytes(uc.mem_read(BUFFER, SPAN))
    assert actual == expected
    for context, physical in PAYLOAD.items():
        assert bytes(uc.mem_read(physical, SPAN)) == PATTERNS[context]
    recover, = D.words(uc, THREAD + 0x74, 1)
    assert recover == (TARGETS[name] if length <= 15 else 0)
    original_bytes(uc, visits)
    # Explicitly labeled Python counterfactual: direct physical RAM source.
    wrong = bytearray(PATTERNS['kernel'])
    wrong[dest_offset:dest_offset + length] = PATTERNS['kernel'][offset:offset + length]
    wrong_differs = bytes(wrong) != actual
    assert wrong_differs == bool(length)
    crosses = bool(length and (source >> 12) != ((source + length - 1) >> 12))
    aliased_source = bytes(PATTERNS[target][(offset + i) % PAGE] for i in range(length))
    assert (aliased_source != source_bytes) == crosses
    return {'context': target, 'function': name, 'length': length, 'source': hex(source),
            'destination': hex(destination), 'source_page_crossing': crosses,
            'wrong_second_page_alias_prediction_differs': aliased_source != source_bytes,
            'kernel_buffer_sha256': hashlib.sha256(actual).hexdigest(),
            'returned_eax': 0, 'recover_after': hex(recover),
            'caller_argument_words_after': list(map(hex, D.words(uc, D.STACK + D.WORD, 3))),
            'wrong_direct_physical_source_model_differs': wrong_differs,
            'instruction_visits': len(visits), 'trace': list(map(hex, visits))}


def representation():
    exports = HERE.parent / 'continuous-review-20260911-18/exports'
    func = next(f for f in json.loads((exports / 'pcode.json').read_text()) if f['entry'] == '0018d37c')
    high = [op for block in func['high_blocks'] for op in block['operations']]
    instructions = R.function_instructions(R.NAMES['_switch_context'])
    rows = []
    for pc in (SWITCH_START, 0x18d3ea, 0x18d3ed, WRITE_CR3):
        ins = instructions[pc]
        raw = next(i for i in func['raw_instructions'] if int(i['address'], 16) == pc)
        selected_high = [op for op in high if int(op['address'], 16) == pc]
        assert raw['operations'] and not selected_high
        rows.append({'site': hex(pc), 'original_bytes': ins.bytes.hex(),
                     'original_instruction': ins.mnemonic + ' ' + ins.op_str,
                     'raw_operations': raw['operations'], 'high_operations_at_site': selected_high})
    cr3_writes = [op for op in high if op.get('output') == '(register, 0x32c, 4)']
    assert not cr3_writes
    canonical = (R.G / 'functions/0018d37c.c').read_text()
    canonical = re.sub(r'\A/\* Ghidra decompiler output, not reconstructed GCC 2\.7 source\..*?\*/\s*', '', canonical, flags=re.S).strip()
    assert canonical == (exports / '0018d37c.c').read_text().strip()
    return {'source': 'report18 immutable independent export, not a new Ghidra run',
            'root_selection_instructions': rows, 'whole_function_high_cr3_outputs': len(cr3_writes),
            'canonical_c_matches_previous_export': True,
            'interpretation': 'Original root selection changes later FS source bytes under the tested mapping; existing high/C omits the explicit CR3 operation.'}


def main():
    before = preserved()
    (HERE / 'preservation-before.json').write_text(json.dumps(before, indent=2) + '\n')
    pattern_gates = []
    for name, pattern in PATTERNS.items():
        differences = sum(a != b for a, b in zip(pattern[:PAGE], pattern[PAGE:]))
        assert differences == PAGE
        pattern_gates.append({'context': name, 'different_same_offset_bytes_between_pages': differences,
                              'sha256': hashlib.sha256(pattern).hexdigest()})
    uc, setup = fixture()
    transitions, cases = [], []
    for target in ('A', 'B', 'B', 'A'):
        transitions.append(switch(uc, target))
        for name, length, offset in itertools.product(TARGETS, (0, 1, 15, 16, 17, 19, 31, 64),
                                                      (0x100, 0x101, 0x102, 0x103, 0xff0, 0xfff)):
            cases.append(copy_case(uc, target, name, length, offset))
        print(json.dumps({'stage': len(transitions), 'target': target, 'cumulative_copy_cases': len(cases)}), flush=True)
    visited = {int(pc, 16) for r in cases for pc in r['trace']}
    rep_sites = {pc for pc in visited if decoded(pc).mnemonic.startswith('rep movs')}
    summary = {'root_selection_stages': len(transitions),
               'original_cr3_write_stages': sum(r['cr3_write_executed'] for r in transitions),
               'same_root_skip_stages': sum(not r['cr3_write_executed'] for r in transitions),
               'api_coordinate_gates_passed': sum(r['api_coordinate_gate_passed'] for r in transitions),
               'stale_root_prediction_mismatch_stages': sum(r['old_root_prediction_differs'] for r in transitions),
               'full_copy_normal_cases': len(cases), 'copy_instruction_visits': sum(r['instruction_visits'] for r in cases),
               'unique_copy_instruction_heads': len(visited), 'rep_sites_executed': len(rep_sites),
               'source_page_crossing_cases': sum(r['source_page_crossing'] for r in cases),
               'wrong_second_page_alias_prediction_mismatch_cases': sum(r['wrong_second_page_alias_prediction_differs'] for r in cases),
               'zero_length_controls': sum(r['length'] == 0 for r in cases),
               'wrong_physical_source_model_mismatch_cases': sum(r['wrong_direct_physical_source_model_differs'] for r in cases),
               'original_binary_or_db_writes': 0, 'full_context_switch_proven': False}
    result = {'summary': summary, 'representation': representation(),
              'pattern_gates': pattern_gates, 'setup': setup, 'transitions': transitions, 'copy_cases': cases,
              'rep_sites': list(map(hex, sorted(rep_sites))), 'binary_sha256': hashlib.sha256(R.RAW).hexdigest(),
              'tool_versions': {'unicorn': U.__version__, 'python': sys.version},
              'limits': ['Mixed synthetic state: CS flat 0x48, DS/ES/SS 0x10 high, FS 0x50 flat. Not complete kernel CPU state.',
                         'Only original root-selection fragment and normal copy functions, not whole switch_context or boot.',
                         'Page directories and private low page tables are synthesized, not allocated by original user-pmap constructor.',
                         'No CPL3 execution, page-fault recovery, POP FS provenance, interrupts or hardware TLB validation.',
                         'Python wrong-source counterfactual is neither compiled decompiler C nor full raw-pcode execution.',
                         'No kernel reconstruction, GCC 2.7 compilation, canonical analysis correction or IDA refresh.']}
    (HERE / 'user-mapping-review.json').write_text(json.dumps(result, indent=2) + '\n')
    assert preserved() == before
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    try:
        main()
    except Exception:
        # Preserve distinct fixture failures; never overwrite an earlier failure log.
        existing = sorted(HERE.glob('fixture-failure-*.txt'))
        (HERE / f'fixture-failure-{len(existing):02d}.txt').write_text(traceback.format_exc())
        raise
