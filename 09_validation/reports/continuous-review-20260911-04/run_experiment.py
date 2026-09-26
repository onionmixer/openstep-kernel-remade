"""Copy saved project, run no-analysis/read-only decompiler experiment, hash inputs."""
import hashlib
import json
from pathlib import Path
import shutil
import subprocess

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
GHIDRA = Path('/home/onion/ghidra_12.1_PUBLIC')
SOURCE = ROOT / '04_ghidra/projects'
SNAPSHOT = ROOT / '04_ghidra/projects/experiments/noreturn-review-20260911'


def hashes():
    paths = [SOURCE / 'x86-full.gpr'] + sorted((SOURCE / 'x86-full.rep').rglob('*'))
    return [{'path': str(p.relative_to(ROOT)), 'sha256': hashlib.sha256(p.read_bytes()).hexdigest(), 'size': p.stat().st_size}
            for p in paths if p.is_file()]


def main():
    if SNAPSHOT.exists():
        raise RuntimeError('Snapshot path already exists; do not overwrite an earlier experiment.')
    before = hashes()
    (HERE / 'source-project-before.json').write_text(json.dumps(before, indent=2) + '\n')
    SNAPSHOT.mkdir(parents=True)
    shutil.copy2(SOURCE / 'x86-full.gpr', SNAPSHOT / 'x86-full.gpr')
    shutil.copytree(SOURCE / 'x86-full.rep', SNAPSHOT / 'x86-full.rep')
    for item in before:
        rel = Path(item['path']).relative_to('04_ghidra/projects')
        assert hashlib.sha256((SNAPSHOT / rel).read_bytes()).hexdigest() == item['sha256']
    runtime = HERE / 'runtime'
    cmd = ['java', '-Xmx2G', '-XX:ParallelGCThreads=2', '-XX:CICompilerCount=2',
           '-Djava.awt.headless=true', '-Djava.system.class.loader=ghidra.GhidraClassLoader',
           '-Dfile.encoding=UTF8', '-Duser.language=en', '-Duser.country=US',
           '-Dapplication.settingsdir=' + str(runtime / 'settings'),
           '-Dapplication.cachedir=' + str(runtime / 'cache'),
           '-Dapplication.tempdir=' + str(runtime / 'temp'),
           '-Djava.util.prefs.userRoot=' + str(runtime / 'prefs'),
           '-cp', str(GHIDRA / 'Ghidra/Framework/Utility/lib/Utility.jar'),
           'ghidra.Ghidra', 'ghidra.app.util.headless.AnalyzeHeadless', str(SNAPSHOT), 'x86-full',
           '-process', 'mach_kernel', '-readOnly', '-noanalysis', '-scriptPath', str(HERE),
           '-postScript', 'FlowContractExperiment.java', str(HERE / 'exports'),
           '-log', str(HERE / 'ghidra.log'), '-scriptlog', str(HERE / 'script.log')]
    (HERE / 'command.json').write_text(json.dumps(cmd, indent=2) + '\n')
    with (HERE / 'console.log').open('w') as stream:
        proc = subprocess.run(cmd, cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT)
    after = hashes()
    assert before == after, 'Original project changed during experiment'
    result = {'returncode': proc.returncode, 'source_project_unchanged': True, 'source_files_checked': len(before),
              'snapshot_project': str(SNAPSHOT.relative_to(ROOT)), 'mode': 'copied project / readOnly / noanalysis'}
    (HERE / 'run-result.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result, indent=2))
    raise SystemExit(proc.returncode)


if __name__ == '__main__':
    main()
