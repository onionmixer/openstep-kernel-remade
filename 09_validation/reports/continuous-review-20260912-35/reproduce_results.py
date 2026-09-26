"""Re-run only new read-only regression tools, never the old CPU producers."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

HERE = Path(__file__).resolve().parent
NAMES = ('consumer-regression.json', 'negative-controls.json', 'consumer-inventory.json', 'preservation.json')


def hashes():
    return {name: hashlib.sha256((HERE / name).read_bytes()).hexdigest() for name in NAMES}


def main():
    before = hashes()
    for script in ('review.py', 'test_review.py', 'inventory.py'):
        subprocess.run([sys.executable, '-B', str(HERE / script)], cwd=HERE, check=True)
    after = hashes()
    assert before == after, {name: (before[name], after[name]) for name in NAMES if before[name] != after[name]}
    (HERE / 'reproducibility.json').write_text(json.dumps({'before': before, 'after': after,
        'all_equal': True, 'scope': 'same preserved inputs, fresh independent audit processes; no CPU producer rerun'}, indent=2) + '\n')
    print(json.dumps({'reproduced_files': len(NAMES), 'all_equal': True}))


if __name__ == '__main__':
    main()
