"""Immutable prior evidence checks and hashes for report24 only."""
import ast
import importlib.util
import json
from pathlib import Path
import re

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PRIOR = HERE.parent / 'continuous-review-20260911-23'
spec = importlib.util.spec_from_file_location('verifier23', PRIOR / 'verify_artifacts.py')
V = importlib.util.module_from_spec(spec)
spec.loader.exec_module(V)
digest = V.digest


def preserved():
    result = V.preserved()
    manifest = PRIOR / 'artifact-hashes.json'
    rows = json.loads(manifest.read_text())
    for row in rows:
        path = ROOT / row['path']
        assert digest(path) == row['sha256'], path
        assert path.stat().st_size == row['size'], path
    result['prior_manifests'].append({'manifest': str(manifest.relative_to(ROOT)), 'files_verified': len(rows)})
    return result


def main():
    result = preserved()
    inputs = [ROOT / row['path'] for row in json.loads((PRIOR / 'input-hashes.json').read_text())]
    inputs += [PRIOR / name for name in ('copyout_review.py', 'verify_artifacts.py', 'paging-copyout.json')]
    inputs += [ROOT / f'04_ghidra/exports/x86/full-pass5/functions/{entry}.{suffix}'
               for entry in ('001860dc', '00186d20', '00187068', '001920f4', '001924a0',
                             '00172038', '0017802c', '0015b7d0', '0015b73c',
                             '0018b1a4', '0018b184', '0018aafc') for suffix in ('asm', 'c')]
    inputs += [ROOT.parent / 'ref/openstep/headers/NextDeveloper/Headers/architecture/i386/frame.h',
               ROOT / '01_resources/upstream/darwin01/kernel/machdep/i386/regs.h']
    import os
    rows = [{'path': os.path.relpath(p, ROOT), 'size': p.stat().st_size, 'sha256': digest(p)} for p in sorted(set(inputs))]
    (HERE / 'input-hashes.json').write_text(json.dumps(rows, indent=2) + '\n')
    for p in HERE.glob('*.py'):
        ast.parse(p.read_text(), filename=str(p))
    links = re.findall(r'\]\(([^)]+)\)', (HERE / 'README.md').read_text())
    for target in links:
        if target not in ('verification.json', 'artifact-hashes.json'):
            assert (HERE / target).exists(), target
    result.update(input_files_hashed=len(rows), readme_links_checked=len(links))
    (HERE / 'verification.json').write_text(json.dumps(result, indent=2) + '\n')
    artifacts = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)}
                 for p in sorted(HERE.rglob('*')) if p.is_file() and '__pycache__' not in p.parts and p.name != 'artifact-hashes.json']
    (HERE / 'artifact-hashes.json').write_text(json.dumps(artifacts, indent=2) + '\n')
    print(json.dumps(dict(result, new_artifacts=len(artifacts)), indent=2))


if __name__ == '__main__':
    main()
