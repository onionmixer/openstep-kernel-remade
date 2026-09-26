"""Fresh same-backend original lifecycle and read-only audit reproduction."""
import hashlib
import json
import subprocess
import sys
import support as S

ARTIFACTS = ('pd-cases.json', 'pd-summary.json', 'pd-audit.json',
             'negative-controls.json', 'source-basis.json', 'preservation.json')


def hashes():
    return {n: hashlib.sha256((S.HERE / n).read_bytes()).hexdigest() for n in ARTIFACTS}


def main():
    before, commands = hashes(), []
    for name in ('run_pd.py', 'audit_pd.py', 'test_audit.py', 'verify_basis.py'):
        cmd = [sys.executable, '-B', str(S.HERE / name)]
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=180)
        commands.append({'command': cmd, 'returncode': r.returncode, 'stdout': r.stdout, 'stderr': r.stderr})
        S.save('reproduction-progress.json', commands)
        assert r.returncode == 0, commands[-1]
        print(json.dumps({'completed': name}), flush=True)
    after = hashes()
    S.save('reproducibility.json', {'before': before, 'after': after, 'equal': before == after,
        'commands': commands, 'same_backend': True, 'native_cpu_verified': False, 'whole_goal_complete': False})
    assert before == after
    print(json.dumps({'equal_artifacts': len(after)}))


if __name__ == '__main__':
    main()
