"""Fresh read-only copy; reuse the existing Ghidra API-only exporter."""
import hashlib
import json
import shutil
import subprocess
from scan import HERE, ROOT

SNAPSHOT = ROOT / '04_ghidra/projects/experiments/io-control-review-20260911'


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    assert not SNAPSHOT.exists(), 'Refusing to overwrite existing snapshot'
    previous = HERE.parent / 'continuous-review-20260911-11'
    before = json.loads((HERE.parent / 'continuous-review-20260911-14/source-project-before.json').read_text())
    source = ROOT / '04_ghidra/projects'
    assert all(digest(source / r['path']) == r['sha256'] for r in before)
    SNAPSHOT.mkdir(parents=True)
    shutil.copy2(source / 'x86-full.gpr', SNAPSHOT / 'x86-full.gpr')
    shutil.copytree(source / 'x86-full.rep', SNAPSHOT / 'x86-full.rep')
    assert all(digest(SNAPSHOT / r['path']) == r['sha256'] for r in before)
    (HERE / 'source-project-before.json').write_text(json.dumps(before, indent=2) + '\n')
    old_snapshot = ROOT / '04_ghidra/projects/experiments/wait-pcode-review-20260911'
    cmd = [a.replace(str(previous), str(HERE)).replace(str(old_snapshot), str(SNAPSHOT))
           for a in json.loads((previous / 'command.json').read_text())]
    cmd[cmd.index('-scriptPath') + 1] = str(previous)
    assert '-readOnly' in cmd and '-noanalysis' in cmd
    (HERE / 'exports').mkdir()
    (HERE / 'command.json').write_text(json.dumps(cmd, indent=2) + '\n')
    with (HERE / 'console.log').open('w') as log:
        proc = subprocess.run(cmd, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT)
    changed = {label: [r['path'] for r in before if digest(base / r['path']) != r['sha256']]
               for label, base in [('original', source), ('snapshot', SNAPSHOT)]}
    result = {'returncode': proc.returncode, 'changed': changed,
              'selected_functions': len(json.loads((HERE / 'job.json').read_text())['selected']),
              'files_per_copy': len(before), 'exporter_reused_unchanged': str((previous / 'WaitPcodeEvidence.java').relative_to(ROOT))}
    (HERE / 'run-result.json').write_text(json.dumps(result, indent=2) + '\n')
    assert proc.returncode == 0 and not any(changed.values()), result
    assert json.loads((HERE / 'exports/execution-marker.json').read_text()) == {
        'class': 'WaitPcodeEvidence', 'version': 'wait-pcode-v1',
        'binary_sha256': json.loads((HERE / 'job.json').read_text())['binary_sha256']}
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
