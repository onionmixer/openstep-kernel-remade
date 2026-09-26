import hashlib
import json
from pathlib import Path
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
NAMES = ('fault-new-pt-cases.json', 'fault-new-pt-summary.json', 'independent-audit.json', 'negative-controls.json',
         'latest-diagnostic.json', 'preservation-before.json', 'preservation-after.json')


def hashes():
    return {n: hashlib.sha256((HERE / n).read_bytes()).hexdigest() for n in NAMES}


def main():
    before = hashes()
    for script in ('fault_new_pt_review.py', 'audit_results.py', 'test_audit.py'):
        subprocess.run([sys.executable, '-B', str(HERE / script)], cwd=ROOT, check=True)
    after = hashes()
    assert before == after, {n: (before[n], after[n]) for n in NAMES if before[n] != after[n]}
    out = {'files': list(NAMES), 'before': before, 'after': after, 'all_equal': True,
           'scope': 'same backend fresh rerun, not native hardware'}
    (HERE / 'reproducibility.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps({'reproduced_files': len(NAMES), 'all_equal': True}))


if __name__ == '__main__':
    main()
