"""Run read-only Ghidra extraction against a fresh validated project copy."""
import hashlib
import json
import shutil
import subprocess
from scan import HERE, ROOT, R

SNAPSHOT = ROOT / '04_ghidra/projects/experiments/wait-pcode-review-20260911'


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    assert not SNAPSHOT.exists(), 'Refusing to overwrite existing snapshot'
    scan = json.loads((HERE / 'scan.json').read_text())
    selected = {R.NAMES['_thread_policy'], R.NAMES['_task_create'], R.NAMES['_panic'], R.NAMES['_mfs_cache_trim']}
    selected |= {int(r['owner'], 16) for r in scan['sites'] if r['kind'] == 'memory_poll'}
    job = {'selected': [f'{a:08x}' for a in sorted(selected)], 'binary_sha256': hashlib.sha256(R.RAW).hexdigest()}
    (HERE / 'job.json').write_text(json.dumps(job, indent=2) + '\n')
    source = ROOT / '04_ghidra/projects'
    before = json.loads((HERE.parent / 'continuous-review-20260911-10/source-project-before.json').read_text())
    assert all(digest(source / row['path']) == row['sha256'] for row in before)
    SNAPSHOT.mkdir(parents=True)
    shutil.copy2(source / 'x86-full.gpr', SNAPSHOT / 'x86-full.gpr')
    shutil.copytree(source / 'x86-full.rep', SNAPSHOT / 'x86-full.rep')
    assert all(digest(SNAPSHOT / row['path']) == row['sha256'] for row in before)
    (HERE / 'source-project-before.json').write_text(json.dumps(before, indent=2) + '\n')
    previous = HERE.parent / 'continuous-review-20260911-10'
    old_snapshot = ROOT / '04_ghidra/projects/experiments/api-contract-review-20260911'
    old = json.loads((previous / 'baseline-command.json').read_text())
    cmd = [a.replace(str(previous), str(HERE)).replace(str(old_snapshot), str(SNAPSHOT))
           .replace('ApiContractExperiment.java', 'WaitPcodeEvidence.java') for a in old]
    cmd.remove('baseline')
    (HERE / 'exports').mkdir()
    (HERE / 'command.json').write_text(json.dumps(cmd, indent=2) + '\n')
    with (HERE / 'console.log').open('w') as log:
        proc = subprocess.run(cmd, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT)
    changed = {label: [r['path'] for r in before if digest(base / r['path']) != r['sha256']]
               for label, base in [('original', source), ('snapshot', SNAPSHOT)]}
    result = {'returncode': proc.returncode, 'changed': changed, 'selected_functions': len(selected), 'files_per_copy': len(before)}
    (HERE / 'run-result.json').write_text(json.dumps(result, indent=2) + '\n')
    assert proc.returncode == 0 and not any(changed.values()), result
    assert json.loads((HERE / 'exports/execution-marker.json').read_text()) == {
        'class': 'WaitPcodeEvidence', 'version': 'wait-pcode-v1', 'binary_sha256': job['binary_sha256']}
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
