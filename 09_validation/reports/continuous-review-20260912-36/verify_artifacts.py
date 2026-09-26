"""Preservation chain for in-progress report36. Finalization is not yet implemented."""
import importlib.util
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PRIOR = HERE.parent / 'continuous-review-20260912-35'
spec = importlib.util.spec_from_file_location('verify35', PRIOR / 'verify_artifacts.py')
V = importlib.util.module_from_spec(spec)
spec.loader.exec_module(V)
digest = V.digest


def preserved():
    result = V.preserved()
    manifest = PRIOR / 'artifact-hashes.json'
    entries = json.loads(manifest.read_text())
    for row in entries:
        p = ROOT / row['path']
        assert p.stat().st_size == row['size'] and digest(p) == row['sha256'], p
    result['prior_manifests'].append({'manifest': str(manifest.relative_to(ROOT)), 'files_verified': len(entries)})
    return result
