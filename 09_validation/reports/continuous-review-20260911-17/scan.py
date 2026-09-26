"""Whole-export original port-I/O and interrupt-control inventory."""
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
IO = {'in', 'out', 'insb', 'insw', 'insd', 'outsb', 'outsw', 'outsd'}
CONTROL = {'cli', 'sti', 'pushf', 'pushfd', 'popf', 'popfd', 'iret', 'iretd'}


def main():
    rows, heads, owners = [], set(), {}
    for entry in sorted(R.FMAP):
        instructions = R.function_instructions(entry)
        local = []
        for ins in instructions.values():
            heads.add(ins.address)
            op = ins.mnemonic.split()[-1]
            if op not in IO | CONTROL:
                continue
            record = {'owner': f'{entry:08x}', 'name': R.FMAP[entry]['name'],
                      'site': f'{ins.address:08x}', 'bytes': ins.bytes.hex(),
                      'mnemonic': ins.mnemonic, 'operation': op, 'operands': ins.op_str,
                      'kind': 'port_io' if op in IO else 'interrupt_control',
                      'address_size': ins.addr_size, 'prefixes': list(ins.prefix)}
            if op in ('in', 'out'):
                port = ins.operands[1 if op == 'in' else 0]
                value = ins.operands[0 if op == 'in' else 1]
                record['width'] = value.size
                record['port'] = {'kind': 'immediate', 'value': port.imm} if port.type == R.X86_OP_IMM else {'kind': 'register', 'name': ins.reg_name(port.reg)}
            rows.append(record)
            local.append(record)
        if local:
            owners[f'{entry:08x}'] = {'name': R.FMAP[entry]['name'],
                                    'instruction_count': len(instructions),
                                    'counts': dict(collections.Counter(r['operation'] for r in local))}
    assert len({r['site'] for r in rows}) == len(rows)
    selected = sorted(owners)
    summary = {'function_units_scanned': len(R.FMAP), 'instruction_heads_scanned': len(heads),
               'sites': len(rows), 'owner_functions': len(owners),
               'by_operation': dict(collections.Counter(r['operation'] for r in rows)),
               'by_kind': dict(collections.Counter(r['kind'] for r in rows)),
               'selected_for_fresh_pcode': len(selected),
               'binary_sha256': hashlib.sha256(R.RAW).hexdigest()}
    (HERE / 'scan.json').write_text(json.dumps({'summary': summary, 'sites': rows, 'owners': owners,
        'limits': ['Existing function instruction boundaries, not undiscovered bytes.',
                   'Port I/O only: memory-mapped I/O and all other privileged effects not covered.']}, indent=2) + '\n')
    (HERE / 'job.json').write_text(json.dumps({'selected': selected, 'binary_sha256': summary['binary_sha256']}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))
    print(json.dumps({a: owners[a] for a in selected}, indent=2))


if __name__ == '__main__':
    main()
