"""PD lifecycle evidence helpers; no emulator import."""
import hashlib
import importlib.util
import itertools
import json
from pathlib import Path
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
R31 = HERE.parent / 'continuous-review-20260911-31'
R40 = HERE.parent / 'continuous-review-20260912-40'
sys.path.insert(0, str(HERE.parent / 'continuous-review-20260912-34'))
ZONE, PMAPS = 0x6a0000, (0x6a1000, 0x6a1020)
PD_HEAD = 0x1f7aa8
EXTRA = {ZONE: 0x40, PMAPS[0]: 0x1c, PMAPS[1]: 0x1c,
         0x1f7aa0: 0x10, 0x1f7abc: 4, 0x1f653c: 4, 0x1e773c: 4,
         0x1e25fc: 0x1c, 0x1dfd78: 4, 0x1f6e60: 0x3c}


def load(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def canonical(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(',', ':')).encode()).hexdigest()


def save(name, value):
    (HERE / name).write_text(json.dumps(value, indent=2) + '\n')


def preserve():
    previous = load('preserved40', R40 / 'support.py').preserve()
    cp = R40 / 'checkpoint.json'
    assert hashlib.sha256(cp.read_bytes()).hexdigest() == '66ad52ae472d248dd3d865209e712830264f22c419d996216c973bbc3f715e35'
    for item in json.loads(cp.read_text())['files']:
        path = R40 / item['path']
        assert path.stat().st_size == item['size'] and hashlib.sha256(path.read_bytes()).hexdigest() == item['sha256']
        previous[str(path.relative_to(ROOT))] = item['sha256']
    previous[str(cp.relative_to(ROOT))] = hashlib.sha256(cp.read_bytes()).hexdigest()
    return previous


def references():
    rows = json.loads((R31 / 'new-pt-cases.json').read_text())
    return {(r['target'], r['sleepable']): r for r in rows if not r['caller']}


def matrix(smoke=False):
    return [('A', 1, 0)] if smoke else list(itertools.product(('A', 'B'), (1, 0), (0, 1)))
