"""Conservative intraprocedural reaching AF definitions for PUSHFD sites.

Opaque calls, restored flags, entry flags and undefined AF are retained as
distinct boundaries. No interprocedural, asynchronous or path-feasibility claim.
"""
import collections
import hashlib
import importlib.util
import json
from pathlib import Path
import sys
import capstone as C
from capstone import x86_const as X

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
spec = importlib.util.spec_from_file_location('original', HERE.parent / 'cautious-followup-20260911/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)


def terminal(ins):
    op = ins.mnemonic.split()[-1]
    if C.CS_GRP_CALL in ins.groups or op in ('call', 'lcall'):
        return 'opaque_call', False
    if op in ('popf', 'popfd', 'popfq', 'iret', 'iretd', 'iretq'):
        return 'restored_flags', False
    if op == 'sahf':
        return 'flags_from_ah', False
    if op in ('int', 'int3', 'into', 'syscall', 'sysenter'):
        return 'opaque_system_transition', False
    conditional = op in ('sal', 'shl', 'shr', 'sar', 'shld', 'shrd', 'rol', 'ror', 'rcl', 'rcr')
    if conditional and ins.operands[-1].type == R.X86_OP_IMM:
        count = ins.operands[-1].imm & 0x1f
        if count == 0:
            return None, False
        conditional = False
    if ins.eflags & X.X86_EFLAGS_UNDEFINED_AF:
        return 'undefined_af', conditional
    if ins.eflags & (X.X86_EFLAGS_MODIFY_AF | X.X86_EFLAGS_RESET_AF | X.X86_EFLAGS_SET_AF):
        return ('inc_dec' if op in ('inc', 'dec') else 'other_af_definition'), conditional
    return None, False


def graph(instructions):
    successors, escapes = {}, []
    for pc, ins in instructions.items():
        next_pc = pc + ins.size
        op = ins.mnemonic.split()[-1]
        out = []
        if C.CS_GRP_RET in ins.groups or C.CS_GRP_IRET in ins.groups or op in ('hlt', 'ud2'):
            pass
        elif C.CS_GRP_JUMP in ins.groups:
            if ins.operands and ins.operands[0].type == R.X86_OP_IMM:
                out.append(ins.operands[0].imm)
            else:
                escapes.append({'site': f'{pc:08x}', 'kind': 'indirect_jump'})
            if op not in ('jmp', 'ljmp'):
                out.append(next_pc)
        else:
            # Calls may return here, but the analysis records unknown flags.
            out.append(next_pc)
        successors[pc] = [a for a in out if a in instructions]
        escapes += [{'site': f'{pc:08x}', 'target': f'{a:08x}', 'kind': 'outside_function'} for a in out if a not in instructions]
    predecessors = {pc: [] for pc in instructions}
    for source, targets in successors.items():
        for target in targets:
            predecessors[target].append(source)
    return successors, predecessors, escapes


def inspect_consumer(entry, consumer, instructions):
    succ, pred, escapes = graph(instructions)
    origins = {}
    queue = collections.deque((p, [consumer, p]) for p in pred[consumer])
    if consumer == entry or not pred[consumer]:
        origins[('function_entry' if consumer == entry else 'unresolved_cfg_boundary', consumer)] = [consumer]
    seen = set()
    while queue:
        pc, witness = queue.popleft()
        if pc in seen:
            continue
        seen.add(pc)
        ins = instructions[pc]
        kind, also_preserves = terminal(ins)
        if kind:
            origins[(kind, pc)] = list(reversed(witness))
            if not also_preserves:
                continue
        if pc == entry:
            origins[('function_entry', pc)] = list(reversed(witness))
        if not pred[pc] and pc != entry:
            origins[('unresolved_cfg_boundary', pc)] = list(reversed(witness))
        queue.extend((p, witness + [p]) for p in pred[pc])
    return {'owner': f'{entry:08x}', 'name': R.FMAP[entry]['name'], 'consumer': f'{consumer:08x}',
            'origins': [{'kind': kind, 'site': f'{pc:08x}', 'bytes': instructions[pc].bytes.hex(),
                         'instruction': instructions[pc].mnemonic + ' ' + instructions[pc].op_str,
                         'witness': [f'{a:08x}' for a in path]} for (kind, pc), path in sorted(origins.items())],
            'nodes_visited': len(seen), 'cfg_escapes': escapes,
            'interpretation': 'Conservative local predecessors; opaque calls and function entry flags are unresolved origins.'}


def main():
    scan = json.loads((HERE.parent / 'continuous-review-20260911-14/scan.json').read_text())
    consumers = scan['flag_consumers']
    rows = []
    for record in consumers:
        entry, pc = int(record['owner'], 16), int(record['site'], 16)
        instructions = R.function_instructions(entry)
        assert instructions[pc].mnemonic == 'pushfd' and instructions[pc].bytes.hex() == record['bytes']
        rows.append(inspect_consumer(entry, pc, instructions))
    summary = {'consumers': len(rows), 'function_units': len({r['owner'] for r in rows}),
               'origin_records_by_kind': dict(collections.Counter(o['kind'] for r in rows for o in r['origins'])),
               'consumers_with_inc_dec_origin': sum(any(o['kind'] == 'inc_dec' for o in r['origins']) for r in rows),
               'binary_sha256': hashlib.sha256(R.RAW).hexdigest(),
               'global_af_impact_resolved': False}
    (HERE / 'reaching-flags.json').write_text(json.dumps({'summary': summary, 'consumers': rows,
        'limits': ['No full interprocedural call/return or indirect-entry analysis.', 'No asynchronous exception/interrupt edges.',
                   'Syntactic CFG paths may be infeasible; reaching origins are conservative, not proof of execution.',
                   'Instruction discovery and function-body limits are inherited from the current export.']}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))
    for row in rows:
        print(json.dumps({'consumer': row['consumer'], 'name': row['name'], 'origins': [(o['kind'], o['site'], o['instruction']) for o in row['origins']]}))


if __name__ == '__main__':
    main()
