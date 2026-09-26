import hashlib
import json
from pathlib import Path
import subprocess
import sys

HERE = Path(__file__).resolve().parent
NAMES = ('branch-inventory.json', 'transfer-index.json', 'inventory-summary.json',
         'independent-audit.json', 'caller-contracts.json', 'negative-controls.json',
         'preservation-before.json', 'preservation-after.json')


def hashes():
    return {name: hashlib.sha256((HERE / name).read_bytes()).hexdigest() for name in NAMES}


def main():
    before = hashes()
    for name in ('branch_inventory.py', 'audit_results.py', 'test_inventory.py'):
        subprocess.run([sys.executable, '-B', str(HERE / name)], cwd=HERE.parents[2], check=True)
    after = hashes()
    mismatches = [name for name in NAMES if before[name] != after[name]]
    result = {'before': before, 'after': after, 'files_compared': len(NAMES), 'mismatches': mismatches}
    (HERE / 'reproducibility.json').write_text(json.dumps(result, indent=2) + '\n')
    assert not mismatches
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
