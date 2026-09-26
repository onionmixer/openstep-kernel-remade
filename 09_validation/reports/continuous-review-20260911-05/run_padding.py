"""Compute and preflight exact padding bounds in Python; run isolated Ghidra experiment."""
import csv
import hashlib
import importlib.util
import json
from pathlib import Path
import shutil
import subprocess
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
spec = importlib.util.spec_from_file_location('original_input', HERE.parent / 'cautious-followup-20260911/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)
SNAPSHOT = ROOT / '04_ghidra/projects/experiments/padding-review-20260911'


def main():
    if SNAPSHOT.exists():
        raise RuntimeError('Refusing to overwrite an existing experiment snapshot')
    f = R.FMAP[R.NAMES['__objc_msgForward']]
    instructions = R.function_instructions(int(f['address'], 16))
    calls = [ins for ins in instructions.values() if ins.mnemonic == 'call' and ins.operands[0].type == R.X86_OP_IMM
             and ins.operands[0].imm == R.NAMES['___objc_error']]
    assert len(calls) == 1
    call = calls[0]
    next_entry = min(a for a in R.FMAP if a > max(int(r['end_inclusive'], 16) for r in f['body']))
    start, end = call.address + call.size, next_entry - 1
    raw = R.read_original(start, end - start + 1)
    assert raw == bytes(len(raw))
    refs, symbols = [], []
    for filename, field, dest in (('references.tsv', 'to', refs), ('symbols.tsv', 'address', symbols)):
        with (R.G / filename).open() as stream:
            for row in csv.DictReader(stream, delimiter='\t'):
                try: address = int(row[field], 16)
                except ValueError: continue
                if start <= address <= end: dest.append(row)
    assert not refs and not symbols, (refs, symbols)
    owners = [x['name'] for x in R.FUNCS if any(int(r['start'], 16) <= end and start <= int(r['end_inclusive'], 16) for r in x['body'])]
    assert owners == ['__objc_msgForward'], owners
    job = {'function_name': f['name'], 'start': f'{start:08x}', 'end': f'{end:08x}', 'length': len(raw),
           'call_site': f'{call.address:08x}', 'next_function': R.FMAP[next_entry]['name'],
           'next_entry': f'{next_entry:08x}', 'bytes_hex': raw.hex(), 'references_to_padding': refs,
           'symbols_in_padding': symbols, 'overlapping_function_owners': owners,
           'binary_sha256': hashlib.sha256(R.RAW).hexdigest()}
    (HERE / 'padding-job.json').write_text(json.dumps(job, indent=2) + '\n')
    source = ROOT / '04_ghidra/projects'
    source_files = [source / 'x86-full.gpr'] + sorted((source / 'x86-full.rep').rglob('*'))
    before = [{'path': str(p.relative_to(source)), 'sha256': hashlib.sha256(p.read_bytes()).hexdigest()}
              for p in source_files if p.is_file()]
    SNAPSHOT.mkdir(parents=True)
    shutil.copy2(source / 'x86-full.gpr', SNAPSHOT / 'x86-full.gpr')
    shutil.copytree(source / 'x86-full.rep', SNAPSHOT / 'x86-full.rep')
    for item in before: assert hashlib.sha256((SNAPSHOT / item['path']).read_bytes()).hexdigest() == item['sha256']
    (HERE / 'source-project-before.json').write_text(json.dumps(before, indent=2) + '\n')
    old = HERE.parent / 'continuous-review-20260911-04'
    old_cmd = json.loads((old / 'command.json').read_text())
    old_snap = ROOT / '04_ghidra/projects/experiments/noreturn-review-20260911'
    cmd = [a.replace(str(old), str(HERE)).replace(str(old_snap), str(SNAPSHOT)).replace('FlowContractExperiment.java', 'PaddingExperiment.java') for a in old_cmd]
    idx = cmd.index(str(HERE / 'exports'))
    cmd.insert(idx + 1, str(HERE / 'padding-job.json'))
    (HERE / 'command.json').write_text(json.dumps(cmd, indent=2) + '\n')
    with (HERE / 'console.log').open('w') as stream:
        proc = subprocess.run(cmd, cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT)
    original_changed = [i['path'] for i in before if hashlib.sha256((source / i['path']).read_bytes()).hexdigest() != i['sha256']]
    snapshot_changed = [i['path'] for i in before if hashlib.sha256((SNAPSHOT / i['path']).read_bytes()).hexdigest() != i['sha256']]
    assert not original_changed
    (HERE / 'run-result.json').write_text(json.dumps({'returncode': proc.returncode, 'original_changed': original_changed,
         'snapshot_changed': snapshot_changed, 'source_files_checked': len(before)}, indent=2) + '\n')
    print(json.dumps({'returncode': proc.returncode, 'padding_bytes': len(raw), 'original_changed': original_changed,
                      'snapshot_changed': snapshot_changed}, indent=2))
    raise SystemExit(proc.returncode)


if __name__ == '__main__':
    main()
