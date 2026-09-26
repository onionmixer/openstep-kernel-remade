import ast
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PRIOR = HERE.parent / 'continuous-review-20260911-26'
spec = importlib.util.spec_from_file_location('verifier26', PRIOR / 'verify_artifacts.py')
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
    inputs += [PRIOR / name for name in ('resident-cases.json', 'verify_artifacts.py', 'artifact-hashes.json')]
    inputs += [ROOT / f'04_ghidra/exports/x86/full-pass5/functions/{entry}.{ext}'
               for entry in ('00172038', '0019065c', '0017a248', '00190cfc', '0017358c', '001920f4', '00191e50', '001a13a0', '001923e0', '0017b200', '0017d2d0')
               for ext in ('asm', 'json', 'c')]
    inputs += [ROOT / '04_ghidra/exports/x86/full-pass5' / name for name in ('symbols.tsv', 'whole-program.asm')]
    inputs += [ROOT / '01_resources/upstream' / folder / name
               for folder in ('nextmach/mk-108.1', 'darwin01/kernel')
               for name in ('vm/vm_fault.c', 'vm/vm_pager.h')]
    inputs += [ROOT / '01_resources/upstream/darwin01/kernel/machdep/i386/pmap.c']
    inputs += [HERE.parent / 'continuous-review-20260911-24/audit_results.py']
    records = [{'path': os.path.relpath(p, ROOT), 'size': p.stat().st_size, 'sha256': digest(p)} for p in sorted(set(inputs))]
    (HERE / 'input-hashes.json').write_text(json.dumps(records, indent=2) + '\n')
    for path in HERE.glob('*.py'):
        ast.parse(path.read_text(), filename=str(path))
    links = re.findall(r'\]\(([^)]+)\)', (HERE / 'README.md').read_text())
    for target in links:
        if target not in ('verification.json', 'artifact-hashes.json'):
            assert (HERE / target).exists(), target
    result.update(input_files_hashed=len(records), readme_links_checked=len(links))
    (HERE / 'verification.json').write_text(json.dumps(result, indent=2) + '\n')
    records = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)}
               for p in sorted(HERE.rglob('*')) if p.is_file() and '__pycache__' not in p.parts and p.name != 'artifact-hashes.json']
    (HERE / 'artifact-hashes.json').write_text(json.dumps(records, indent=2) + '\n')
    print(json.dumps(dict(result, new_artifacts=len(records)), indent=2))


if __name__ == '__main__':
    main()
