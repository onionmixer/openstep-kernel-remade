"""Rerun report24 tests/audit and compare deterministic evidence hashes."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
NAMES = ('coordinate-gate.json', 'native-delivery.json', 'normal-high-cs.json',
         'trap-cases.json', 'latest-case.json', 'trap-review.json', 'independent-audit.json',
         'preservation-before.json', 'preservation-after.json')


def hashes():
    return {name: hashlib.sha256((HERE / name).read_bytes()).hexdigest() for name in NAMES}


def main():
    before = hashes()
    for name in ('trap_review.py', 'audit_results.py'):
        subprocess.run([sys.executable, '-B', str(HERE / name)], cwd=ROOT, check=True)
    after = hashes()
    mismatches = [name for name in NAMES if before[name] != after[name]]
    result = {'before': before, 'after': after, 'files_compared': len(NAMES), 'mismatches': mismatches}
    (HERE / 'reproducibility.json').write_text(json.dumps(result, indent=2) + '\n')
    assert not mismatches, mismatches
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
