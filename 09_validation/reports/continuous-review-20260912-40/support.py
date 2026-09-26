"""Read-only loading and evidence identity; no emulation imports here."""
import hashlib
import importlib.util
import json
from pathlib import Path
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PRIOR = HERE.parent / 'continuous-review-20260912-39'
R34 = HERE.parent / 'continuous-review-20260912-34'
sys.path.insert(0, str(R34))


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
    files = {}
    checkpoint = PRIOR / 'checkpoint.json'
    assert hashlib.sha256(checkpoint.read_bytes()).hexdigest() == '8ebf06ddce63b8645e64f2c6c0016701abaf9baf60628cd501e2ec49f8f433f1'
    for entry in json.loads(checkpoint.read_text())['files']:
        path = PRIOR / entry['path']
        assert path.stat().st_size == entry['size']
        assert hashlib.sha256(path.read_bytes()).hexdigest() == entry['sha256']
        files[str(path.relative_to(ROOT))] = entry['sha256']
    manifests = [HERE.parent / f'{directory}/{name}'
        for directory in ('continuous-review-20260911-32', 'continuous-review-20260911-33',
                          'continuous-review-20260912-34', 'continuous-review-20260912-35')
        for name in ('artifact-hashes.json', 'input-hashes.json')]
    for manifest in manifests:
        for entry in json.loads(manifest.read_text()):
            path = ROOT / entry['path']
            assert path.stat().st_size == entry['size']
            assert hashlib.sha256(path.read_bytes()).hexdigest() == entry['sha256'], path
            files[str(path.relative_to(ROOT))] = entry['sha256']
        files[str(manifest.relative_to(ROOT))] = hashlib.sha256(manifest.read_bytes()).hexdigest()
    files[str(checkpoint.relative_to(ROOT))] = hashlib.sha256(checkpoint.read_bytes()).hexdigest()
    return files


def references():
    path = HERE.parent / 'continuous-review-20260911-32/fault-new-pt-cases.json'
    return {tuple(r[k] for k in ('target', 'function', 'destination', 'flags', 'sleepable')): r
            for r in json.loads(path.read_text())}


def matrix(smoke=False):
    import itertools
    if smoke:
        return [(('A', '_copyout', 0x100, 2, 1), 'remove')]
    rows = [(p, 'remove') for p in itertools.product(('A', 'B'), ('_copyout', '_copyoutmsg'),
            (0x100, 0x1100), (2, 0x602), (1, 0))]
    rows += [((target, '_copyout', 0x100, 2, 1), mode)
             for target in ('A', 'B') for mode in ('equal', 'accessed')]
    return rows
