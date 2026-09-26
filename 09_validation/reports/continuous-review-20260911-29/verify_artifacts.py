"""Read-only predecessor verification; only this report's main writes outputs."""
import ast
import hashlib
import importlib.util
import json
from pathlib import Path
import re

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PRIOR = HERE.parent / 'continuous-review-20260911-28'
spec = importlib.util.spec_from_file_location('verifier28', PRIOR / 'verify_artifacts.py')
V = importlib.util.module_from_spec(spec)
spec.loader.exec_module(V)
digest = V.digest


def preserved():
    result = V.preserved()
    manifest = PRIOR / 'artifact-hashes.json'
    rows = json.loads(manifest.read_text())
    for row in rows:
        path = ROOT / row['path']
        assert digest(path) == row['sha256'] and path.stat().st_size == row['size'], path
    result['prior_manifests'].append({'manifest': str(manifest.relative_to(ROOT)), 'files_verified': len(rows)})
    return result


def main():
    result = preserved()
    inputs = [ROOT / row['path'] for row in json.loads((PRIOR / 'input-hashes.json').read_text())]
    inputs += [PRIOR / name for name in ('artifact-hashes.json', 'verify_artifacts.py', 'allocator_review.py')]
    inputs += [ROOT / f'04_ghidra/exports/x86/full-pass5/functions/{entry}.{ext}'
               for entry in ('0017b99c', '00191428', '001019c0', '00190f24') for ext in ('asm', 'c', 'json')]
    inputs += [ROOT / '01_resources/upstream/darwin01/kernel/machdep/i386/pmap.c']
    rows = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)} for p in sorted(set(inputs))]
    (HERE / 'input-hashes.json').write_text(json.dumps(rows, indent=2) + '\n')
    for p in HERE.glob('*.py'):
        ast.parse(p.read_text(), filename=str(p))
    links = re.findall(r'\]\(([^)]+)\)', (HERE / 'README.md').read_text())
    for target in links:
        if target not in ('verification.json', 'artifact-hashes.json'):
            assert (HERE / target).exists(), target
    result.update(input_files_hashed=len(rows), readme_links_checked=len(links))
    (HERE / 'verification.json').write_text(json.dumps(result, indent=2) + '\n')
    rows = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)}
            for p in sorted(HERE.rglob('*')) if p.is_file() and '__pycache__' not in p.parts and p.name != 'artifact-hashes.json']
    (HERE / 'artifact-hashes.json').write_text(json.dumps(rows, indent=2) + '\n')
    print(json.dumps(dict(result, new_artifacts=len(rows)), indent=2))


if __name__ == '__main__':
    main()
