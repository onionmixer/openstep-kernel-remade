"""Decode original exported instructions and classify short wait backedges.

The exact pattern is JNE to the immediately preceding TEST/CMP. This does not
claim to discover all synchronization loops, indirect paths or unknown code.
"""
import collections
import hashlib
import importlib.util
import json
from pathlib import Path
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
spec = importlib.util.spec_from_file_location('original', HERE.parent / 'cautious-followup-20260911/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)


def item(ins):
    return {'address': f'{ins.address:08x}', 'size': ins.size, 'bytes': ins.bytes.hex(),
            'mnemonic': ins.mnemonic, 'operands': ins.op_str}


def main():
    rows, heads = [], set()
    for entry in sorted(R.FMAP):
        instructions = R.function_instructions(entry)
        ends = {i.address + i.size: i for i in instructions.values()}
        for branch in instructions.values():
            heads.add(branch.address)
            if branch.mnemonic != 'jne' or branch.operands[0].type != R.X86_OP_IMM:
                continue
            condition = instructions.get(branch.operands[0].imm)
            if not condition or condition.address + condition.size != branch.address or condition.mnemonic not in ('test', 'cmp'):
                continue
            previous = ends.get(condition.address)
            load = previous
            padding = []
            while load and load.mnemonic == 'nop':
                padding.append(item(load))
                load = ends.get(load.address)
            regs = all(op.type == R.X86_OP_REG for op in condition.operands)
            constant = all(op.type in (R.X86_OP_REG, R.X86_OP_IMM) for op in condition.operands)
            memory = any(op.type == R.X86_OP_MEM for op in condition.operands)
            kind = 'register_only' if constant else 'memory_poll' if memory else 'other'
            matching_load = (regs and condition.mnemonic == 'test' and condition.operands[0].reg == condition.operands[1].reg
                             and load and load.mnemonic == 'mov' and load.operands[0].type == R.X86_OP_REG
                             and load.operands[0].reg == condition.operands[0].reg and load.operands[1].type == R.X86_OP_MEM)
            # Static invariant: TEST/CMP change flags only, JNE changes flow only.
            if kind == 'register_only':
                _, writes = condition.regs_access()
                assert all(condition.reg_name(reg) == 'eflags' for reg in writes)
            window = []
            cursor = branch.address + branch.size
            for _ in range(12):
                ins = instructions.get(cursor)
                if ins is None:
                    break
                window.append(item(ins))
                cursor += ins.size
                if ins.mnemonic in ('xchg', 'ret', 'jmp', 'call'):
                    break
            rows.append({'owner': f'{entry:08x}', 'owner_name': R.FMAP[entry]['name'], 'kind': kind,
                         'condition': item(condition), 'branch': item(branch),
                         'preceding': item(previous) if previous else None,
                         'load': item(load) if matching_load else None, 'padding_before_test': list(reversed(padding)),
                         'matched_single_memory_load': bool(matching_load), 'following_window': window,
                         'nearby_exchange': any(i['mnemonic'] == 'xchg' for i in window)})
    assert len({r['branch']['address'] for r in rows}) == len(rows)
    summary = {'function_units_scanned': len(R.FMAP), 'unique_instruction_heads_decoded': len(heads),
               'pattern_sites': len(rows), 'by_kind': dict(collections.Counter(r['kind'] for r in rows)),
               'owners': len({r['owner'] for r in rows}),
               'register_only_owners': len({r['owner'] for r in rows if r['kind'] == 'register_only'}),
               'loads_separated_by_padding': sum(r['matched_single_memory_load'] and bool(r['padding_before_test']) for r in rows),
               'matched_single_memory_load': sum(r['matched_single_memory_load'] for r in rows),
               'register_only_nearby_exchange': sum(r['kind'] == 'register_only' and r['nearby_exchange'] for r in rows),
               'binary_sha256': hashlib.sha256(R.RAW).hexdigest()}
    (HERE / 'scan.json').write_text(json.dumps({'summary': summary, 'sites': rows}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))
    for r in rows:
        if not r['matched_single_memory_load']:
            print(json.dumps(r))


if __name__ == '__main__':
    main()
