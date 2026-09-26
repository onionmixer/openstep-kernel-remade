"""Independent static census and raw relative-transfer audit.

Does not import branch_inventory. Relative destinations are decoded with Python
signed integers, independently of Capstone and the producer's CFG code.
"""
import collections
import importlib.util
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
EXPORT = ROOT / '04_ghidra/exports/x86/full-pass5'
spec = importlib.util.spec_from_file_location('original24', HERE.parent / 'continuous-review-20260911-24/audit_results.py')
A = importlib.util.module_from_spec(spec)
spec.loader.exec_module(A)


def relative_target(pc, raw):
    if raw[0] in (0xe8, 0xe9):
        assert len(raw) == 5
        displacement = int.from_bytes(raw[1:], 'little', signed=True)
    elif raw[0] == 0xeb or 0x70 <= raw[0] <= 0x7f:
        assert len(raw) == 2
        displacement = int.from_bytes(raw[1:], 'little', signed=True)
    else:
        assert raw[:1] == b'\x0f' and 0x80 <= raw[1] <= 0x8f and len(raw) == 6
        displacement = int.from_bytes(raw[2:], 'little', signed=True)
    return (pc + len(raw) + displacement) & 0xffffffff


def main():
    inventory = json.loads((HERE / 'branch-inventory.json').read_text())
    reported = json.loads((HERE / 'inventory-summary.json').read_text())
    cases = json.loads((HERE.parent / 'continuous-review-20260911-26/resident-cases.json').read_text())
    visits, edges, cases_seen = collections.Counter(), collections.Counter(), collections.defaultdict(set)
    for index, case in enumerate(cases):
        pcs = [int(pc, 16) for pc in case['trace']]
        visits.update(pcs)
        edges.update(zip(pcs, pcs[1:]))
        for pc in set(pcs):
            cases_seen[pc].add(index)
    expected_entries = [0x172038, 0x19065c, 0x17a248, 0x190cfc]
    assert [int(f['entry'], 16) for f in inventory['functions']] == expected_entries
    assert reported['report26_cases'] == len(cases)
    transfer_rows, totals, all_asm = [], [], {}
    for function, summary in zip(inventory['functions'], reported['functions'], strict=True):
        entry = int(function['entry'], 16)
        stem = EXPORT / 'functions' / f'{entry:08x}'
        listing = [line.split('\t', 2) for line in stem.with_suffix('.asm').read_text().splitlines()]
        meta = json.loads(stem.with_suffix('.json').read_text())
        assert function['body'] == meta['body'] and function['export_name'] == meta['name']
        claimed_heads = [int(r['pc'], 16) for r in function['rows']]
        assert claimed_heads == [int(line[0], 16) for line in listing]
        assert len(set(claimed_heads)) == len(claimed_heads)
        body = {a for part in meta['body'] for a in range(int(part['start'], 16), int(part['end_inclusive'], 16) + 1)}
        bytes_seen, conditional, outcomes, observed_outcomes, calls, observed_calls = set(), 0, 0, 0, 0, 0
        unresolved, returns, concatenated = [], [], bytearray()
        for row, (address, size_text, text) in zip(function['rows'], listing, strict=True):
            pc, size = int(address, 16), int(size_text)
            raw = A.original(pc, size)
            assert row['raw'] == raw.hex() and row['size'] == size and row['ghidra'] == text
            assert not bytes_seen.intersection(range(pc, pc + size))
            bytes_seen.update(range(pc, pc + size))
            concatenated.extend(raw)
            all_asm[pc] = text
            assert row['report26_visits'] == visits[pc] and row['report26_cases'] == len(cases_seen[pc])
            mnemonic = text.split()[0]
            successors, target = [], None
            if mnemonic == 'CALL':
                kind = 'call'
                calls += 1
                observed_calls += visits[pc] > 0
                target = relative_target(pc, raw)
                successors = [('call_return_assumed', pc + size, None)]
                assert edges[(pc, target)] == visits[pc]
            elif mnemonic.startswith('J'):
                target = relative_target(pc, raw)
                kind = 'jump' if mnemonic == 'JMP' else 'conditional'
                if kind == 'conditional':
                    conditional += 1
                    successors.append(('fallthrough', pc + size, edges[(pc, pc + size)]))
                successors.append(('taken', target, edges[(pc, target)]))
                assert sum(e[2] for e in successors) == visits[pc]
            elif mnemonic == 'RET':
                assert raw == b'\xc3'
                kind = 'return'
                returns.append(hex(pc))
            else:
                kind = 'linear'
                successors = [('fallthrough', pc + size, None)]
            assert row['kind'] == kind and row['target'] == (hex(target) if target is not None else None)
            if target is not None:
                assert target == int(text.split()[-1], 16)
            expected = [{'kind': k, 'target': hex(t), 'in_function': t in claimed_heads,
                         'report26_direct_transition_visits': n} for k, t, n in successors]
            assert row['successors'] == expected
            for edge in expected:
                if not edge['in_function']:
                    unresolved.append({'pc': hex(pc), **{k: v for k, v in edge.items() if k != 'report26_direct_transition_visits'}})
            if kind == 'conditional':
                outcomes += len(expected)
                observed_outcomes += sum(e['report26_direct_transition_visits'] > 0 for e in expected)
            if kind != 'linear':
                transfer_rows.append({'function': function['entry'], **row})
        assert bytes_seen == body
        assert function['body_instruction_sha256'] == A.hashlib.sha256(concatenated).hexdigest()
        expected_summary = {'entry': hex(entry), 'export_name': meta['name'], 'instruction_heads': len(claimed_heads),
                            'instruction_bytes': len(bytes_seen), 'report26_observed_heads': sum(visits[pc] > 0 for pc in claimed_heads),
                            'report26_unobserved_heads': sum(visits[pc] == 0 for pc in claimed_heads),
                            'direct_callsites': calls, 'report26_observed_callsites': observed_calls,
                            'conditional_branches': conditional, 'syntactic_conditional_outcomes': outcomes,
                            'report26_observed_conditional_outcomes': observed_outcomes, 'return_heads': returns,
                            'unresolved_edges': unresolved}
        assert summary == expected_summary
        totals.append(expected_summary)
    assert transfer_rows == json.loads((HERE / 'transfer-index.json').read_text())
    # These anchors validate the locations used in the human contract report.
    anchors = {
        0x1720dd: 'JZ 0x00172678', 0x1720e6: 'TEST AL,0x40', 0x1721de: 'MOV EAX,0xa',
        0x1721e8: 'TEST AL,0x1', 0x172254: 'CMP ESI,0x4', 0x1722ca: 'JZ 0x001720cc',
        0x172376: 'XOR EAX,EAX', 0x172380: 'TEST AL,0x20',
        0x1724c3: 'TEST dword ptr [ESI + 0x28],ECX', 0x1724c6: 'JZ 0x0017259c',
        0x172572: 'MOV EAX,0xa', 0x17269a: 'CALL 0x0017b200',
        0x1727ba: 'MOV EBX,dword ptr [EBP + 0x18]', 0x1727c3: 'CALL 0x0017a248',
        0x1727cd: 'JNZ 0x0017280c', 0x17280c: 'CMP EAX,0x2', 0x172922: 'MOV EAX,0xa',
        0x1729e4: 'CALL 0x0017b99c', 0x172a29: 'JMP 0x001720cc',
        0x172d13: 'XOR EAX,EAX', 0x172d30: 'CALL 0x0017b200',
        0x172e7d: 'CALL 0x00163320', 0x172e85: 'JMP 0x00172047',
        0x1730de: 'CALL 0x0017802c', 0x1731fe: 'MOV EAX,dword ptr [EBP + -0x30]',
        0x173401: 'JMP 0x00172047', 0x17344c: 'CALL 0x0019065c', 0x17357e: 'XOR EAX,EAX',
        0x17a274: 'MOV ECX,dword ptr [EBP + 0x10]', 0x17a279: 'CALL 0x0017d2d0',
        0x1907ac: 'CALL 0x00190cfc', 0x1907bc: 'JMP 0x00190780',
        0x1907d3: 'JNZ 0x00190914', 0x190990: 'CALL 0x0018f7f8',
        0x190a06: 'CALL 0x0016b790', 0x190a11: 'JMP 0x0019075c',
        0x190a40: 'CALL 0x00190f24', 0x190aa7: 'MOV dword ptr [EBX],EDI',
        0x190aeb: 'CALL 0x0016b84c', 0x190d76: 'CALL 0x00173d1c',
        0x190d80: 'JNZ 0x00190f1a', 0x190e38: 'JZ 0x00190e98', 0x190ef4: 'MOV dword ptr [EBX],ECX'}
    for pc, text in anchors.items():
        assert all_asm[pc] == text, (hex(pc), text)
    # Check selected semantic operands from original bytes, not only export text.
    X = A.capstone.x86
    memory_contracts = {
        0x1724c3: ('test', 0, 'esi', 0x28, 4),
        0x1727ba: ('mov', 1, 'ebp', 0x18, 4),
        0x17a274: ('mov', 1, 'ebp', 0x10, 4),
        0x1731fe: ('mov', 1, 'ebp', -0x30, 4),
        0x190aa7: ('mov', 0, 'ebx', 0, 4),
        0x190ef4: ('mov', 0, 'ebx', 0, 4)}
    for pc, (mnemonic, index, base, displacement, size) in memory_contracts.items():
        ins = A.instruction(pc)
        operand = ins.operands[index]
        assert ins.mnemonic == mnemonic and operand.type == X.X86_OP_MEM and operand.size == size
        assert ins.reg_name(operand.mem.base) == base and operand.mem.disp == displacement
        assert operand.mem.index == 0 and operand.mem.segment == 0
    for pc, expected_register, value in ((0x1721de, 'eax', 10), (0x172572, 'eax', 10), (0x172922, 'eax', 10),
                                          (0x172254, 'esi', 4), (0x1720e6, 'al', 0x40),
                                          (0x1721e8, 'al', 1), (0x172380, 'al', 0x20), (0x17280c, 'eax', 2)):
        ins = A.instruction(pc)
        assert ins.operands[0].type == X.X86_OP_REG and ins.reg_name(ins.operands[0].reg) == expected_register
        assert ins.operands[1].type == X.X86_OP_IMM and ins.operands[1].imm == value
    for pc in (0x172376, 0x172d13, 0x17357e):
        ins = A.instruction(pc)
        assert ins.mnemonic == 'xor' and all(o.type == X.X86_OP_REG and ins.reg_name(o.reg) == 'eax' for o in ins.operands)
    whole_listing = [line.split('\t', 2) for line in (EXPORT / 'whole-program.asm').read_text().splitlines()]
    callers = {int(p, 16) for p, size, text in whole_listing if text == 'CALL 0x00172038'}
    windows = {0x1735d5: (0x17358c, 0x1735ca), 0x192000: (0x191e50, 0x191fd8),
               0x1921e7: (0x1920f4, 0x1921bc), 0x19242d: (0x1923e0, 0x192405),
               0x1a143c: (0x1a13a0, 0x1a1413)}
    assert callers == set(windows)
    caller_evidence = []
    for site, (entry, start) in sorted(windows.items()):
        listing = [line.split('\t', 2) for line in (EXPORT / 'functions' / f'{entry:08x}.asm').read_text().splitlines()]
        selected = [(int(pc, 16), int(size), text) for pc, size, text in listing if start <= int(pc, 16) <= site]
        pushes = []
        for pc, size, text in selected:
            ins = A.instruction(pc)
            assert ins.size == size
            assert 'ESP' not in text, 'unexpected stack modification in argument window'
            if text.startswith('PUSH '):
                assert ins.mnemonic == 'push'
                pushes.append((pc, text))
            elif text.startswith('J'):
                target = relative_target(pc, A.original(pc, size))
                # These small alternatives only select protection; no argument PUSH is skipped.
                assert pc < target < site
                assert not any(p < target and p > pc and t.startswith('PUSH ') for p, s, t in selected)
            elif text.startswith('CALL '):
                assert pc == site and relative_target(pc, A.original(pc, size)) == 0x172038
        assert len(pushes) == 5 and pushes[0][1] == 'PUSH 0x0'
        assert A.original(pushes[0][0], 2) == b'\x6a\x00'
        fifth_offset = (5 + 1) * 4
        assert fifth_offset == 0x18
        caller_evidence.append({'callsite': hex(site), 'argument_window_start': hex(start),
                                'pushes': [{'pc': hex(pc), 'assembly': text} for pc, text in pushes],
                                'fifth_argument': 0, 'callee_ebp_offset': fifth_offset})
    (HERE / 'caller-contracts.json').write_text(json.dumps({'scope': 'direct CALLs in canonical whole-program listing; indirect callers not excluded',
                                                          'callers': caller_evidence}, indent=2) + '\n')
    result = {'function_bodies_audited': len(totals), 'original_relative_transfers_checked': len(transfer_rows) - sum(len(t['return_heads']) for t in totals),
              'contract_anchors_checked': len(anchors), 'direct_vm_fault_callers_checked': len(callers),
              'source26_cases': len(cases), 'mismatches': [], 'new_kernel_execution': False,
              'full_operand_text_equivalence_proven': False, 'static_feasibility_proven': False, 'whole_analysis_complete': False}
    (HERE / 'independent-audit.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
