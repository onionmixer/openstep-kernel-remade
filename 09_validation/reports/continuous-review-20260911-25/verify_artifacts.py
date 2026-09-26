import ast
import importlib.util
import json
import os
from pathlib import Path
import re

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PRIOR = HERE.parent / 'continuous-review-20260911-24'
spec = importlib.util.spec_from_file_location('verifier24', PRIOR / 'verify_artifacts.py')
V = importlib.util.module_from_spec(spec)
spec.loader.exec_module(V)
digest = V.digest


def preserved():
    result = V.preserved()
    manifest = PRIOR / 'artifact-hashes.json'
    rows = json.loads(manifest.read_text())
    for row in rows:
        p = ROOT / row['path']
        assert digest(p) == row['sha256'] and p.stat().st_size == row['size'], p
    result['prior_manifests'].append({'manifest': str(manifest.relative_to(ROOT)), 'files_verified': len(rows)})
    return result


def main():
    result = preserved()
    inputs = [ROOT / r['path'] for r in json.loads((PRIOR / 'input-hashes.json').read_text())]
    inputs += [PRIOR / n for n in ('trap_review.py', 'verify_artifacts.py', 'audit_results.py', 'trap-cases.json')]
    inputs += [ROOT / f'04_ghidra/exports/x86/full-pass5/functions/{entry}.{ext}'
               for entry in ('0015b54c', '00101600', '00101630') for ext in ('asm', 'c')]
    inputs += [ROOT / '01_resources/upstream/darwin01/kernel' / n for n in
               ('vm/vm_map.c', 'vm/vm_map.h', 'mach/kern_return.h', 'mach/vm_prot.h')]
    inputs += [ROOT / '01_resources/upstream/nextmach/mk-108.1/vm/vm_map.c']
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
