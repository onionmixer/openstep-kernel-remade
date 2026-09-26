"""Fresh execution and independent consumer repetition on the same backend."""
import hashlib
import json
import subprocess
import sys
import support as S

ARTIFACTS = ('removal-cases.json', 'removal-summary.json', 'removal-audit.json',
             'negative-controls.json', 'preservation.json', 'source-basis.json')


def hashes():
    return {n: hashlib.sha256((S.HERE / n).read_bytes()).hexdigest() for n in ARTIFACTS}


def main():
    before = hashes()
    commands = []
    for script in ('run_removal.py', 'audit_removal.py', 'test_audit.py', 'verify_basis.py'):
        cmd = [sys.executable, '-B', str(S.HERE / script)]
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=180)
        commands.append({'command': cmd, 'returncode': result.returncode, 'stdout': result.stdout, 'stderr': result.stderr})
        S.save('reproduction-progress.json', commands)
        assert result.returncode == 0, commands[-1]
        print(json.dumps({'completed': script}), flush=True)
    after = hashes()
    result = {'before': before, 'after': after, 'equal': before == after, 'commands': commands,
              'same_backend': True, 'native_cpu_verified': False, 'whole_goal_complete': False}
    S.save('reproducibility.json', result)
    assert result['equal'], result
    print(json.dumps({'reproduced_equal_artifacts': len(after)}))


if __name__ == '__main__':
    main()
