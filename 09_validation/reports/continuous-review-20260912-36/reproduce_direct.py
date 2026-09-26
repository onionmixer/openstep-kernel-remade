"""Reproduce only the new supplemental producer/auditor/controls, not old mains."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys
from verify_artifacts import preserved

HERE = Path(__file__).resolve().parent


def hashes(names):
    return {n: hashlib.sha256((HERE / n).read_bytes()).hexdigest() for n in names}


def main():
    names = ('direct-cases.json', 'direct-latest.json', 'direct-run-summary.json',
             'direct-audit.json', 'direct-negative-controls.json')
    before, originals = hashes(names), preserved()
    commands = []
    for script in ('direct_review.py', 'audit_direct.py', 'test_direct.py'):
        result = subprocess.run([sys.executable, '-B', str(HERE / script)], cwd=HERE,
            text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        commands.append({'script': script, 'returncode': result.returncode,
                         'stdout': result.stdout, 'stderr': result.stderr})
        assert result.returncode == 0, commands[-1]
    after = hashes(names)
    assert before == after and preserved() == originals
    out = {'before': before, 'after': after, 'equal': True, 'commands': commands,
        'preservation': originals, 'actual_fault_reentry_verified': False, 'whole_goal_complete': False}
    (HERE / 'direct-reproducibility.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps({'reproduced_artifacts': len(names), 'actual_fault_reentry_verified': False}))


if __name__ == '__main__':
    main()
