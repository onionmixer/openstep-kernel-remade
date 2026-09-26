"""Read-only guest observation of preserved report37 fixture on installed Bochs."""
import hashlib
import json
import os
from pathlib import Path
import signal
import subprocess
import sys

HERE = Path(__file__).resolve().parent
PRIOR = HERE.parent / 'continuous-review-20260912-37'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def preserve():
    checkpoint = json.loads((PRIOR / 'checkpoint.json').read_text())
    for row in checkpoint['files']:
        path = PRIOR / row['path']
        assert path.stat().st_size == row['size'] and sha(path) == row['sha256'], path
    return sha(PRIOR / 'checkpoint.json')


def run(flags):
    case_name = 'case-' + format(flags, 'x')
    mode = '-nogui' if '--nogui' in sys.argv else ('-wx' if '--wx' in sys.argv else '')
    directory = HERE / (case_name + mode)
    # No stale dumps may be mistaken for this execution. Keep attempts immutable.
    directory.mkdir(exist_ok=False)
    original = PRIOR / case_name
    inputs = {}
    for name in ('bios.bin', 'tables.bin', 'code.bin', 'data.bin'):
        raw = (original / name).read_bytes()
        (directory / name).write_bytes(raw)
        inputs[name] = sha(original / name)
        assert sha(directory / name) == inputs[name]
    command = ['/usr/bin/xvfb-run', '-a', '-e', str(directory / 'xvfb.log'),
        '/usr/bin/bochs-bin', '-q', '-f', str(HERE / 'bochsrc'), '-rc', str(HERE / 'debugger.rc')]
    if '--wx' in sys.argv:
        command.append('config_interface: wx')
    if '--nogui' in sys.argv:
        command = ['/usr/bin/bochs-bin', '-q', '-f', str(HERE / 'bochsrc'),
                   '-rc', str(HERE / 'debugger.rc'), 'display_library: nogui']
    env = dict(os.environ)
    env.pop('LTDL_LIBRARY_PATH', None)
    env.pop('BXSHARE', None)
    timed_out = False
    with (directory / 'stdout.bin').open('wb') as stdout, (directory / 'stderr.bin').open('wb') as stderr:
        process = subprocess.Popen(command, cwd=directory, env=env, stdin=subprocess.DEVNULL,
                                   stdout=stdout, stderr=stderr, start_new_session=True)
        try:
            process.wait(timeout=25)
        except subprocess.TimeoutExpired:
            timed_out = True
            os.killpg(process.pid, signal.SIGTERM)
            try:
                process.wait(timeout=3)
            except subprocess.TimeoutExpired:
                os.killpg(process.pid, signal.SIGKILL)
                process.wait(timeout=3)
    result = {'flags': flags, 'command': command, 'input_hashes': inputs,
        'returncode': process.returncode, 'timed_out': timed_out,
        'bochs_sha256': sha(Path('/usr/bin/bochs-bin')),
        'config_sha256': sha(HERE / 'bochsrc'), 'debugger_script_sha256': sha(HERE / 'debugger.rc'),
        'hashes': {p.name: sha(p) for p in sorted(directory.iterdir()) if p.is_file()},
        'RF_contract_verified': False, 'original_handler_executed': False, 'whole_goal_complete': False}
    (directory / 'run.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'flags': flags, 'returncode': process.returncode, 'timed_out': timed_out,
        'dump_files': [p.name for p in sorted(directory.glob('*frame*.bin'))]}), flush=True)
    return result


def main():
    before = preserve()
    flags = (2,) if '--single' in sys.argv else (2, 0x202, 0x402, 0x602)
    results = [run(value) for value in flags]
    assert preserve() == before
    output = 'runs-nogui.json' if '--nogui' in sys.argv else ('runs-wx.json' if '--wx' in sys.argv else 'runs.json')
    (HERE / output).write_text(json.dumps({'cases': results, 'prior_checkpoint_sha256': before,
        'whole_goal_complete': False}, indent=2) + '\n')


if __name__ == '__main__':
    main()
