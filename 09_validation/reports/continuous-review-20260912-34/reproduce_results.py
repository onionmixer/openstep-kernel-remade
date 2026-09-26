"""Fresh report34 rerun only; do not run finalized predecessor producers."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
NAMES = ('gc-cases.json', 'gc-summary.json', 'independent-audit.json', 'negative-controls.json',
         'latest-diagnostic.json', 'preservation-before.json', 'preservation-after.json',
         'helper-check.json', 'legacy-stack-review.json')


def hashes():
    return {n: hashlib.sha256((HERE / n).read_bytes()).hexdigest() for n in NAMES}


def main():
    before = hashes()
    for script in ('pt_gc_review.py', 'audit_results.py', 'test_audit.py', 'legacy_stack_review.py'):
        subprocess.run([sys.executable, '-B', str(HERE / script)], cwd=ROOT, check=True)
    after = hashes()
    assert before == after, {n: (before[n], after[n]) for n in NAMES if before[n] != after[n]}
    result = {'files': list(NAMES), 'before': before, 'after': after, 'all_equal': True,
              'scope': 'same-backend fresh prefix and GC rerun; not independent native hardware'}
    (HERE / 'reproducibility.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'reproduced_files': len(NAMES), 'all_equal': True}))


if __name__ == '__main__':
    main()
