"""Original-byte static inventory; not execution or whole-kernel coverage.

Calls have conditional-on-return continuations. Every observed branch edge is
read from adjacent heads of one complete report26 trace, never filtered traces.
"""
import collections
import hashlib
import importlib.util
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
EXPORT = ROOT / '04_ghidra/exports/x86/full-pass5'
ENTRIES = (0x172038, 0x19065c, 0x17a248, 0x190cfc)
spec = importlib.util.spec_from_file_location('original_audit24', HERE.parent / 'continuous-review-20260911-24/audit_results.py')
A = importlib.util.module_from_spec(spec)
spec.loader.exec_module(A)
ALIASES = {'jz': 'je', 'jnz': 'jne', 'jc': 'jb', 'jnc': 'jae', 'setz': 'sete', 'setnz': 'setne'}


def load(name):
    return json.loads((HERE / name).read_text())


def save(name, value):
    (HERE / name).write_text(json.dumps(value, indent=2) + '\n')


def parse_function(entry, asm_text=None, metadata=None):
    stem = EXPORT / 'functions' / f'{entry:08x}'
    meta = metadata if metadata is not None else json.loads(stem.with_suffix('.json').read_text())
    body = set()
    for part in meta['body']:
        start, end = int(part['start'], 16), int(part['end_inclusive'], 16)
        assert part['bytes'] == end - start + 1
        span = set(range(start, end + 1))
        assert not body.intersection(span), 'overlapping body'
        body.update(span)
    rows, seen = [], set()
    source = asm_text if asm_text is not None else stem.with_suffix('.asm').read_text()
    for line in source.splitlines():
        address, size, text = line.split('\t', 2)
        pc, length = int(address, 16), int(size)
        ins = A.instruction(pc)
        assert ins.size == length, ('length', address)
        mnemonic = text.split()[0].lower()
        assert ALIASES.get(mnemonic, mnemonic) == ins.mnemonic, ('mnemonic', address, text, ins.mnemonic)
        span = set(range(pc, pc + length))
        assert not seen.intersection(span), 'duplicate instruction bytes'
        seen.update(span)
        target = None
        kind = 'linear'
        if ins.group(A.capstone.CS_GRP_CALL):
            kind = 'call'
        elif ins.group(A.capstone.CS_GRP_JUMP):
            kind = 'jump' if ins.mnemonic == 'jmp' else 'conditional'
        elif ins.group(A.capstone.CS_GRP_RET):
            kind = 'return'
        if kind in ('call', 'jump', 'conditional'):
            if ins.operands[0].type == A.capstone.x86.X86_OP_IMM:
                target = ins.operands[0].imm
                assert int(text.split()[-1], 16) == target, ('target', address)
        successors = []
        if kind in ('linear', 'call', 'conditional'):
            successors.append({'kind': 'call_return_assumed' if kind == 'call' else 'fallthrough', 'target': hex(pc + length)})
        if kind in ('jump', 'conditional'):
            successors.append({'kind': 'taken' if target is not None else 'unresolved_indirect', 'target': hex(target) if target is not None else None})
        rows.append({'pc': hex(pc), 'size': length, 'raw': bytes(ins.bytes).hex(),
                     'ghidra': text, 'decoded': ins.mnemonic + (' ' + ins.op_str if ins.op_str else ''),
                     'kind': kind, 'target': hex(target) if target is not None else None,
                     'successors': successors})
    assert seen == body, ('body coverage', hex(entry), len(seen - body), len(body - seen))
    assert rows[0]['pc'] == hex(entry)
    heads = {r['pc'] for r in rows}
    unresolved = []
    for row in rows:
        for edge in row['successors']:
            edge['in_function'] = edge['target'] in heads
            if not edge['in_function']:
                unresolved.append({'pc': row['pc'], **edge})
    return {'entry': hex(entry), 'export_name': meta['name'], 'body': meta['body'],
            'instruction_bytes': len(seen), 'rows': rows, 'unresolved_edges': unresolved,
            'body_instruction_sha256': hashlib.sha256(b''.join(bytes.fromhex(r['raw']) for r in rows)).hexdigest()}


def observations(functions, cases):
    all_rows = {int(row['pc'], 16): row for f in functions for row in f['rows']}
    visits, cases_seen, edge_visits = collections.Counter(), collections.defaultdict(set), collections.Counter()
    for index, case in enumerate(cases):
        trace = [int(pc, 16) for pc in case['trace']]
        # Check the original complete trace before doing any per-function filtering.
        for pos, pc in enumerate(trace):
            if pc not in all_rows:
                continue
            row = all_rows[pc]
            visits[pc] += 1
            cases_seen[pc].add(index)
            if row['kind'] in ('conditional', 'jump', 'call'):
                assert pos + 1 < len(trace), ('truncated transfer trace', hex(pc))
                following = trace[pos + 1]
                if row['kind'] == 'call':
                    assert row['target'] is not None, 'indirect call not modeled'
                    assert following == int(row['target'], 16), ('call target', hex(pc))
                else:
                    allowed = {int(e['target'], 16) for e in row['successors'] if e['target'] is not None}
                    assert following in allowed, ('invalid observed edge', hex(pc), hex(following))
                    edge_visits[(pc, following)] += 1
    for function in functions:
        for row in function['rows']:
            pc = int(row['pc'], 16)
            row['report26_visits'] = visits[pc]
            row['report26_cases'] = len(cases_seen[pc])
            for edge in row['successors']:
                edge['report26_direct_transition_visits'] = (
                    edge_visits[(pc, int(edge['target'], 16))]
                    if edge['target'] is not None and row['kind'] in ('conditional', 'jump') else None)


def summary(function):
    rows = function['rows']
    conditional = [r for r in rows if r['kind'] == 'conditional']
    calls = [r for r in rows if r['kind'] == 'call']
    return {'entry': function['entry'], 'export_name': function['export_name'],
            'instruction_heads': len(rows), 'instruction_bytes': function['instruction_bytes'],
            'report26_observed_heads': sum(r['report26_visits'] > 0 for r in rows),
            'report26_unobserved_heads': sum(r['report26_visits'] == 0 for r in rows),
            'direct_callsites': sum(r['target'] is not None for r in calls),
            'report26_observed_callsites': sum(r['report26_visits'] > 0 for r in calls),
            'conditional_branches': len(conditional),
            'syntactic_conditional_outcomes': sum(len(r['successors']) for r in conditional),
            'report26_observed_conditional_outcomes': sum(e['report26_direct_transition_visits'] > 0 for r in conditional for e in r['successors']),
            'return_heads': [r['pc'] for r in rows if r['kind'] == 'return'],
            'unresolved_edges': function['unresolved_edges']}


def main():
    from verify_artifacts import preserved
    before = preserved()
    save('preservation-before.json', before)
    functions = [parse_function(entry) for entry in ENTRIES]
    cases = json.loads((HERE.parent / 'continuous-review-20260911-26/resident-cases.json').read_text())
    observations(functions, cases)
    save('branch-inventory.json', {'scope': 'four selected function bodies; observations from report26 handler traces only',
                                 'static_edges_prove_feasibility': False, 'functions': functions})
    transfers = [{'function': f['entry'], **r} for f in functions for r in f['rows'] if r['kind'] != 'linear']
    save('transfer-index.json', transfers)
    save('inventory-summary.json', {'functions': [summary(f) for f in functions],
                                    'report26_cases': len(cases), 'native_execution_added': False,
                                    'whole_analysis_complete': False})
    after = preserved()
    assert before == after, 'protected inputs changed'
    save('preservation-after.json', after)
    print(json.dumps(load('inventory-summary.json'), indent=2))


if __name__ == '__main__':
    main()
