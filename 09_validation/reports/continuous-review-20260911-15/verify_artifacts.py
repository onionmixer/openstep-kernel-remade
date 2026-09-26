"""Verify unchanged prior evidence and canonical projects; seal this report."""
import ast
import hashlib
import json
from pathlib import Path
import re

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    manifests = [HERE.parent / 'full-analysis/artifact-hashes.json',
                 HERE.parent / 'deep-review-20260911/review-artifact-hashes.json',
                 HERE.parent / 'cautious-followup-20260911/artifact-hashes.json']
    manifests += [HERE.parent / f'continuous-review-20260911-{i:02d}/artifact-hashes.json' for i in range(1, 15)]
    checked = []
    for manifest in manifests:
        rows = json.loads(manifest.read_text())
        for row in rows:
            path = ROOT / row['path']
            assert digest(path) == row['sha256'], path
            if 'size' in row:
                assert path.stat().st_size == row['size'], path
        checked.append({'manifest': str(manifest.relative_to(ROOT)), 'files_verified': len(rows)})
    before_path = HERE.parent / 'continuous-review-20260911-14/source-project-before.json'
    before = json.loads(before_path.read_text())
    bases = [ROOT / '04_ghidra/projects', ROOT / '04_ghidra/projects/experiments/protected-data-review-20260911']
    for base in bases:
        for row in before:
            assert digest(base / row['path']) == row['sha256']
    inputs = [ROOT / '03_original/x86/binaries/mach_kernel',
              ROOT / '03_original/x86/inventory/macho.json',
              ROOT / '04_ghidra/exports/x86/full-pass5/functions.json',
              HERE.parent / 'cautious-followup-20260911/review.py',
              HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py',
              HERE.parent / 'continuous-review-20260911-14/scan.json', before_path]
    contexts = json.loads((HERE / 'snapshot-review.json').read_text())['original_contexts']
    inputs += [ROOT / f'04_ghidra/exports/x86/full-pass5/functions/{owner}.asm' for owner in contexts]
    input_rows = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)} for p in inputs]
    (HERE / 'input-hashes.json').write_text(json.dumps(input_rows, indent=2) + '\n')
    scripts = sorted(HERE.glob('*.py'))
    for path in scripts:
        ast.parse(path.read_text(), filename=str(path))
    links = re.findall(r'\]\(([^)]+)\)', (HERE / 'README.md').read_text())
    for target in links:
        if target not in ('verification.json', 'artifact-hashes.json'):
            assert (HERE / target).exists(), target
    result = {'prior_manifests': checked, 'project_files_per_copy_verified': len(before),
              'project_copies_verified': len(bases), 'scripts_parsed': len(scripts),
              'readme_links_checked': len(links), 'input_files_hashed': len(input_rows), 'mismatches': []}
    (HERE / 'verification.json').write_text(json.dumps(result, indent=2) + '\n')
    rows = []
    for path in sorted(HERE.rglob('*')):
        if not path.is_file() or '__pycache__' in path.parts or path.name == 'artifact-hashes.json':
            continue
        rows.append({'path': str(path.relative_to(ROOT)), 'size': path.stat().st_size, 'sha256': digest(path)})
    (HERE / 'artifact-hashes.json').write_text(json.dumps(rows, indent=2) + '\n')
    assert all(digest(ROOT / row['path']) == row['sha256'] for row in rows)
    print(json.dumps({'verification': result, 'new_artifacts': len(rows)}, indent=2))


if __name__ == '__main__':
    main()
