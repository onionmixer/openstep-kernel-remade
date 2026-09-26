"""Original explicit CPU-state/register instruction inventory, not all MMIO."""
import collections
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
spec = importlib.util.spec_from_file_location('original', HERE.parent / 'cautious-followup-20260911/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)
SYSTEM = {'lgdt', 'lidt', 'lldt', 'ltr', 'sgdt', 'sidt', 'sldt', 'str', 'clts', 'lmsw', 'smsw',
          'invlpg', 'invd', 'wbinvd', 'rdmsr', 'wrmsr', 'rdtsc', 'cpuid', 'hlt',
          'lcall', 'ljmp', 'retf', 'retfd', 'iret', 'iretd', 'lds', 'les', 'lfs', 'lgs', 'lss'}
SEGMENTS = {'cs', 'ds', 'es', 'fs', 'gs', 'ss'}


def main():
    rows, heads, owners = [], set(), {}
    for entry in sorted(R.FMAP):
        instructions = R.function_instructions(entry)
        local = []
        for ins in instructions.values():
            heads.add(ins.address)
            op = ins.mnemonic.split()[-1]
            direct_regs = [ins.reg_name(o.reg) for o in ins.operands if o.type == R.X86_OP_REG]
            control = [r for r in direct_regs if re.fullmatch(r'(?:cr|dr)[0-9]+', r)]
            segments = [r for r in direct_regs if r in SEGMENTS]
            if not control and not segments and op not in SYSTEM:
                continue
            kind = 'control_debug_register' if control else 'segment_register' if segments else 'system_instruction'
            reads, writes = ins.regs_access()
            row = {'owner': f'{entry:08x}', 'name': R.FMAP[entry]['name'],
                   'site': f'{ins.address:08x}', 'bytes': ins.bytes.hex(),
                   'instruction': ins.mnemonic + ' ' + ins.op_str, 'operation': op, 'kind': kind,
                   'explicit_control_registers': control, 'explicit_segment_registers': segments,
                   'capstone_reads': [ins.reg_name(r) for r in reads],
                   'capstone_writes': [ins.reg_name(r) for r in writes]}
            if op == 'mov' and control:
                row['direction'] = 'write' if ins.reg_name(ins.operands[0].reg) in control else 'read'
                row['special_register'] = control[0]
            local.append(row)
            rows.append(row)
        if local:
            owners[f'{entry:08x}'] = {'name': R.FMAP[entry]['name'], 'instruction_count': len(instructions),
                'counts': dict(collections.Counter(r['kind'] for r in local))}
    assert len(rows) == len({r['site'] for r in rows})
    summary = {'function_units_scanned': len(R.FMAP), 'instruction_heads_scanned': len(heads),
               'sites': len(rows), 'owner_functions': len(owners),
               'by_kind': dict(collections.Counter(r['kind'] for r in rows)),
               'system_operations': dict(collections.Counter(r['operation'] for r in rows if r['kind'] == 'system_instruction')),
               'control_register_directions': dict(collections.Counter(r['special_register'] + '_' + r['direction'] for r in rows if 'direction' in r)),
               'binary_sha256': hashlib.sha256(R.RAW).hexdigest()}
    (HERE / 'scan.json').write_text(json.dumps({'summary': summary, 'sites': rows, 'owners': owners,
        'limits': ['Known exported instruction heads only.', 'Explicit segment register operands, not every implicit segment use.',
                   'Selected system instructions, not all privileged instructions or MMIO.',
                   'Capstone access metadata is inventory data, not full CPU semantics.']}, indent=2) + '\n')
    (HERE / 'job.json').write_text(json.dumps({'selected': sorted(owners), 'binary_sha256': summary['binary_sha256']}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
