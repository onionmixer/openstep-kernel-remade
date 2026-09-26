import hashlib
import json
from pathlib import Path
import subprocess
import sys

HERE = Path(__file__).resolve().parent
NAMES = ('resident-cases.json', 'resident-review.json', 'independent-audit.json',
         'latest-diagnostic.json', 'preservation-before.json', 'preservation-after.json')


def hashes():
    return {n: hashlib.sha256((HERE / n).read_bytes()).hexdigest() for n in NAMES}


def main():
    before = hashes()
    for name in ('resident_review.py', 'audit_results.py'):
        subprocess.run([sys.executable, '-B', str(HERE / name)], cwd=HERE.parents[2], check=True)
    after = hashes()
    mismatches = [n for n in NAMES if before[n] != after[n]]
    result = {'before': before, 'after': after, 'files_compared': len(NAMES), 'mismatches': mismatches}
    (HERE / 'reproducibility.json').write_text(json.dumps(result, indent=2) + '\n')
    assert not mismatches
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
