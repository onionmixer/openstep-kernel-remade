"""Compute original direct CALL evidence, then run independent read-only JVMs."""
import csv
import hashlib
import importlib.util
import json
from pathlib import Path
import shutil
import struct
import subprocess
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
SNAPSHOT = ROOT / '04_ghidra/projects/experiments/api-contract-review-20260911'
spec = importlib.util.spec_from_file_location('original', HERE.parent / 'cautious-followup-20260911/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)
STAGES = ('baseline', 'prototype_only', 'noreturn_only', 'combined', 'reopened_baseline')


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def prepare():
    assert not SNAPSHOT.exists(), 'Refusing to overwrite snapshot'
    specs = [('_task_create', 'int', [('parent_task', 'ptr'), ('inherit_memory', 'int'), ('child_task', 'ptrptr')]),
             ('_thread_policy', 'int', [('thread', 'ptr'), ('policy', 'int'), ('data', 'int')]),
             ('_mig_dealloc_reply_port', 'void', [])]
    prototypes = [{'entry': f'{R.NAMES[n]:08x}', 'name': n, 'return': ret,
                   'parameters': [{'name': pn, 'type': pt} for pn, pt in params]}
                  for n, ret, params in specs]
    targets = {int(p['entry'], 16) for p in prototypes}
    # Index original listing membership; never infer ownership from nearest symbol.
    owners = {}
    for path in sorted((R.G / 'functions').glob('*.asm')):
        entry = int(path.stem, 16)
        for line in path.read_text().splitlines():
            addr, size, _ = line.split('\t', 2)
            owners.setdefault(int(addr, 16), []).append((entry, int(size)))
    refs, calls = [], []
    with (R.G / 'references.tsv').open() as stream:
        for row in csv.DictReader(stream, delimiter='\t'):
            try:
                source, target = int(row['from'], 16), int(row['to'], 16)
            except ValueError:
                continue
            if target not in targets:
                continue
            refs.append(row)
            if 'CALL' not in row['type']:
                continue
            assert len(owners[source]) == 1, (row, owners.get(source))
            owner, size = owners[source][0]
            ins = next(R.CS.disasm(R.read_original(source, size), source, count=1))
            assert ins.size == size and ins.mnemonic == 'call'
            assert ins.operands[0].type == R.X86_OP_IMM and ins.operands[0].imm == target
            calls.append({'site': f'{source:08x}', 'target': f'{target:08x}',
                          'owner': f'{owner:08x}', 'owner_name': R.FMAP[owner]['name'],
                          'bytes': ins.bytes.hex(), 'instruction': f'{ins.mnemonic} {ins.op_str}'})
    assert len({c['site'] for c in calls}) == len(calls)
    selected = sorted(targets | {int(c['owner'], 16) for c in calls} |
                      {R.NAMES['_strcpy'], R.NAMES['_objc_msgSend']})
    job = {'binary_sha256': hashlib.sha256(R.RAW).hexdigest(), 'word_size': struct.calcsize('<I'),
           'selected': [f'{a:08x}' for a in selected], 'prototypes': prototypes,
           'noreturn_entry': f'{R.NAMES["_mig_dealloc_reply_port"]:08x}',
           'references': refs, 'direct_calls': sorted(calls, key=lambda c: c['site'])}
    (HERE / 'job.json').write_text(json.dumps(job, indent=2) + '\n')
    source = ROOT / '04_ghidra/projects'
    paths = [source / 'x86-full.gpr'] + sorted((source / 'x86-full.rep').rglob('*'))
    before = [{'path': str(p.relative_to(source)), 'sha256': digest(p)} for p in paths if p.is_file()]
    assert before == json.loads((HERE.parent / 'continuous-review-20260911-08/source-project-before.json').read_text())
    SNAPSHOT.mkdir(parents=True)
    shutil.copy2(source / 'x86-full.gpr', SNAPSHOT / 'x86-full.gpr')
    shutil.copytree(source / 'x86-full.rep', SNAPSHOT / 'x86-full.rep')
    assert all(digest(SNAPSHOT / r['path']) == r['sha256'] for r in before)
    (HERE / 'source-project-before.json').write_text(json.dumps(before, indent=2) + '\n')
    print(json.dumps({'selected': len(selected), 'calls': len(calls), 'calls_by_target':
                     {p['name']: sum(c['target'] == p['entry'] for c in calls) for p in prototypes}}), flush=True)
    return before, source


def main():
    before, source = prepare()
    previous = HERE.parent / 'continuous-review-20260911-05'
    old_snapshot = ROOT / '04_ghidra/projects/experiments/padding-review-20260911'
    cmd = [a.replace(str(previous), str(HERE)).replace(str(old_snapshot), str(SNAPSHOT))
           .replace('PaddingExperiment.java', 'ApiContractExperiment.java').replace('padding-job.json', 'job.json')
           for a in json.loads((previous / 'command.json').read_text())]
    (HERE / 'exports').mkdir()
    runs = []
    for stage in STAGES:
        phase = [a.replace('/ghidra.log', f'/{stage}-ghidra.log').replace('/script.log', f'/{stage}-script.log')
                 .replace('/runtime/', f'/runtime-isolated/{stage}/') for a in cmd]
        phase.insert(phase.index(str(HERE / 'job.json')) + 1, stage)
        (HERE / f'{stage}-command.json').write_text(json.dumps(phase, indent=2) + '\n')
        with (HERE / f'{stage}-console.log').open('w') as stream:
            proc = subprocess.run(phase, cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT)
        changed = {label: [r['path'] for r in before if digest(base / r['path']) != r['sha256']]
                   for label, base in [('original', source), ('snapshot', SNAPSHOT)]}
        runs.append({'stage': stage, 'returncode': proc.returncode, 'changed': changed})
        (HERE / 'run-result.json').write_text(json.dumps({'runs': runs, 'files_per_copy': len(before)}, indent=2) + '\n')
        print(json.dumps(runs[-1]), flush=True)
        assert not any(changed.values()) and proc.returncode == 0, runs[-1]
        marker = json.loads((HERE / 'exports' / f'{stage}-execution-marker.json').read_text())
        assert marker == {'class': 'ApiContractExperiment', 'version': 'api-contract-v1', 'stage': stage}
        assert (HERE / 'exports' / f'{stage}-input-functions.json').exists()
        assert (HERE / 'exports' / stage / 'functions.json').exists()


if __name__ == '__main__':
    main()
