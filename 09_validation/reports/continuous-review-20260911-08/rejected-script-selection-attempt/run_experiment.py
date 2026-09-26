"""Python computes layouts and preflights evidence before a disposable Ghidra run."""
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
SNAPSHOT = ROOT / '04_ghidra/projects/experiments/storage-isolated-review-20260911'
spec = importlib.util.spec_from_file_location('original', HERE.parent / 'cautious-followup-20260911/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)


def digest(p):
    return hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    if SNAPSHOT.exists():
        raise RuntimeError('Refusing to overwrite existing experiment snapshot')
    # Verify the bounded execution evidence that justifies the storage proposals.
    for folder in ('continuous-review-20260911-06', 'continuous-review-20260911-07'):
        for item in json.loads((HERE.parent / folder / 'artifact-hashes.json').read_text()):
            assert digest(ROOT / item['path']) == item['sha256']
    word = struct.calcsize('<I')
    node = 0x1ab830
    aggregate = 0x124cb8
    selected = sorted([aggregate, node, R.NAMES['_in_bootp'], R.NAMES['_compress'], R.NAMES['_acct'],
                       R.NAMES['_objc_msgSend'], R.NAMES['_strcpy']])
    hidden = []
    for entry, name, fields, params in (
        (aggregate, 'ifreq_result_bytes', [('name', 16, True), ('sockaddr_bytes', 16, False)], ['ifp', 'sin']),
        (node, 'token_address_bytes', [('bytes', 6, False)], ['receiver', 'selector'])):
        hidden.append({'entry': f'{entry:08x}', 'type_name': name,
                       'fields': [{'name': n, 'length': size, 'char': char} for n, size, char in fields],
                       'size': sum(size for _, size, _ in fields), 'pointer_size': word,
                       'stack_parameters': [{'name': n, 'offset': (index + 1) * word} for index, n in enumerate(params)],
                       'result_storage': 'EBX', 'return_storage': 'EAX'})
    refs = []
    with (R.G / 'references.tsv').open() as stream:
        for row in csv.DictReader(stream, delimiter='\t'):
            try:
                target = int(row['to'], 16)
            except ValueError:
                continue
            if target in (aggregate, node, R.NAMES['_compress']):
                refs.append(row)
    job = {'binary_sha256': hashlib.sha256(R.RAW).hexdigest(), 'word_size': word,
           'selected': [f'{a:08x}' for a in selected], 'hidden': hidden,
           'compress': {'entry': f'{R.NAMES["_compress"]:08x}', 'parameters': ['seconds', 'microseconds']},
           'references_to_changed_functions': refs}
    (HERE / 'job.json').write_text(json.dumps(job, indent=2) + '\n')
    source = ROOT / '04_ghidra/projects'
    files = [source / 'x86-full.gpr'] + sorted((source / 'x86-full.rep').rglob('*'))
    before = [{'path': str(p.relative_to(source)), 'sha256': digest(p)} for p in files if p.is_file()]
    SNAPSHOT.mkdir(parents=True)
    shutil.copy2(source / 'x86-full.gpr', SNAPSHOT / 'x86-full.gpr')
    shutil.copytree(source / 'x86-full.rep', SNAPSHOT / 'x86-full.rep')
    for row in before:
        assert digest(SNAPSHOT / row['path']) == row['sha256']
    (HERE / 'source-project-before.json').write_text(json.dumps(before, indent=2) + '\n')
    previous = HERE.parent / 'continuous-review-20260911-05'
    old_snapshot = ROOT / '04_ghidra/projects/experiments/padding-review-20260911'
    cmd = [a.replace(str(previous), str(HERE)).replace(str(old_snapshot), str(SNAPSHOT))
           .replace('PaddingExperiment.java', 'StorageExperiment.java').replace('padding-job.json', 'job.json')
           for a in json.loads((previous / 'command.json').read_text())]
    (HERE / 'exports').mkdir()
    runs = []
    for stage in ('baseline', 'hidden_only', 'compress_only', 'combined', 'reopened_baseline'):
        phase_cmd = [a.replace('/ghidra.log', f'/{stage}-ghidra.log').replace('/script.log', f'/{stage}-script.log') for a in cmd]
        phase_cmd.insert(phase_cmd.index(str(HERE / 'job.json')) + 1, stage)
        (HERE / f'{stage}-command.json').write_text(json.dumps(phase_cmd, indent=2) + '\n')
        with (HERE / f'{stage}-console.log').open('w') as stream:
            proc = subprocess.run(phase_cmd, cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT)
        changed = {label: [r['path'] for r in before if digest(base / r['path']) != r['sha256']]
                   for label, base in [('original', source), ('snapshot', SNAPSHOT)]}
        runs.append({'stage': stage, 'returncode': proc.returncode, 'changed': changed})
        (HERE / 'run-result.json').write_text(json.dumps({'runs': runs, 'files_per_copy': len(before)}, indent=2) + '\n')
        assert not any(changed.values()), changed
        print(json.dumps(runs[-1]), flush=True)
        if proc.returncode:
            raise SystemExit(proc.returncode)


if __name__ == '__main__':
    main()
