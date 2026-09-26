"""Whole-export original INC/DEC inventory; all derivation is Python."""
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
    rows, consumers, heads = [], [], set()
    for entry in sorted(R.FMAP):
        for ins in R.function_instructions(entry).values():
            heads.add(ins.address)
            op = ins.mnemonic.split()[-1]
            if op in ('lahf', 'pushf', 'pushfd', 'pushfq', 'daa', 'das', 'aaa', 'aas'):
                consumers.append({'owner': f'{entry:08x}', 'site': f'{ins.address:08x}', 'mnemonic': ins.mnemonic,
                                  'bytes': ins.bytes.hex(), 'operands': ins.op_str})
            if op not in ('inc', 'dec'):
                continue
            assert len(ins.operands) == 1
            operand = ins.operands[0]
            row = {'owner': f'{entry:08x}', 'owner_name': R.FMAP[entry]['name'], 'site': f'{ins.address:08x}',
                   'mnemonic': op, 'disassembly': ins.mnemonic + ' ' + ins.op_str,
                   'bytes': ins.bytes.hex(), 'length': ins.size, 'width': operand.size,
                   'address_size': ins.addr_size, 'lock_prefix': 0xf0 in ins.prefix}
            if operand.type == R.X86_OP_MEM:
                row.update({'kind': 'memory', 'segment': ins.reg_name(operand.mem.segment),
                            'base': ins.reg_name(operand.mem.base), 'index': ins.reg_name(operand.mem.index),
                            'scale': operand.mem.scale, 'displacement': operand.mem.disp})
            else:
                assert operand.type == R.X86_OP_REG
                row.update({'kind': 'register', 'register': ins.reg_name(operand.reg)})
            rows.append(row)
    assert len({r['site'] for r in rows}) == len(rows)
    previous = json.loads((HERE.parent / 'continuous-review-20260911-13/job.json').read_text())
    subset = {r['site'] for r in previous['direct_operand_sites'] if r['instruction'].startswith(('inc ', 'dec '))}
    assert subset <= {r['site'] for r in rows}
    summary = {'function_units_scanned': len(R.FMAP), 'instruction_heads_scanned': len(heads), 'sites': len(rows),
               'by_kind': dict(collections.Counter(r['kind'] for r in rows)),
               'by_operation': dict(collections.Counter(r['mnemonic'] for r in rows)),
               'by_width_bytes': dict(collections.Counter(r['width'] for r in rows)),
               'explicit_lock_prefixes': sum(r['lock_prefix'] for r in rows),
               'memory_segments': dict(collections.Counter(str(r['segment']) for r in rows if r['kind'] == 'memory')),
               'prior_rmw_sites_included': len(subset), 'flag_materialization_consumer_sites': len(consumers),
               'binary_sha256': hashlib.sha256(R.RAW).hexdigest()}
    (HERE / 'scan.json').write_text(json.dumps({'summary': summary, 'sites': rows, 'flag_consumers': consumers}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
