"""Inventory explicit FS/GS registers and FS/GS memory operands."""
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


def main():
    rows, heads = [], set()
    for entry in sorted(R.FMAP):
        for ins in R.function_instructions(entry).values():
            heads.add(ins.address)
            regs = [ins.reg_name(o.reg) for o in ins.operands if o.type == R.X86_OP_REG]
            mem = [ins.reg_name(o.mem.segment) for o in ins.operands if o.type == R.X86_OP_MEM]
            if not ({'fs', 'gs'} & set(regs + mem)):
                continue
            op = ins.mnemonic.split()[-1]
            write = (op in ('mov', 'pop') and ins.operands[0].type == R.X86_OP_REG
                     and ins.reg_name(ins.operands[0].reg) in ('fs', 'gs'))
            rows.append({'owner': f'{entry:08x}', 'name': R.FMAP[entry]['name'], 'site': f'{ins.address:08x}',
                         'bytes': ins.bytes.hex(), 'instruction': ins.mnemonic + ' ' + ins.op_str,
                         'operation': op, 'explicit_registers': regs, 'memory_segments': mem,
                         'selector_write': write,
                         'target_selector': ins.reg_name(ins.operands[0].reg) if write else None})
    assert len(rows) == len({r['site'] for r in rows})
    selected = sorted({r['owner'] for r in rows})
    summary = {'function_units_scanned': len(R.FMAP), 'instruction_heads_scanned': len(heads),
               'sites': len(rows), 'owner_functions': len(selected),
               'selector_writes': dict(collections.Counter(r['target_selector'] for r in rows if r['selector_write'])),
               'memory_override_sites': sum(bool({'fs', 'gs'} & set(r['memory_segments'])) for r in rows),
               'binary_sha256': hashlib.sha256(R.RAW).hexdigest()}
    (HERE / 'scan.json').write_text(json.dumps({'summary': summary, 'sites': rows,
        'limits': ['Known exported instruction heads only.', 'Explicit Capstone FS/GS operands; not all implicit selector effects.']}, indent=2) + '\n')
    (HERE / 'job.json').write_text(json.dumps({'selected': selected, 'binary_sha256': summary['binary_sha256']}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
