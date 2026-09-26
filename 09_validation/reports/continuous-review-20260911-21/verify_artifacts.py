"""Check immutable earlier evidence, source projects, and paging review inputs."""
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
    manifests += [HERE.parent / f'continuous-review-20260911-{i:02d}/artifact-hashes.json' for i in range(1, 21)]
    checked = []
    for manifest in manifests:
        rows = json.loads(manifest.read_text())
        for row in rows:
            path = ROOT / row['path']
            assert digest(path) == row['sha256'], path
            if 'size' in row:
                assert path.stat().st_size == row['size'], path
        checked.append({'manifest': str(manifest.relative_to(ROOT)), 'files_verified': len(rows)})
    before_path = HERE.parent / 'continuous-review-20260911-19/source-project-before.json'
    before = json.loads(before_path.read_text())
    bases = [ROOT / '04_ghidra/projects']
    bases += [ROOT / '04_ghidra/projects/experiments' / name for name in (
        'protected-data-review-20260911', 'io-control-review-20260911',
        'cpu-state-review-20260911', 'segment-state-review-20260911')]
    for base in bases:
        for row in before:
            assert digest(base / row['path']) == row['sha256']
    inputs = [ROOT / '03_original/x86/binaries/mach_kernel', ROOT / '03_original/x86/inventory/macho.json',
              ROOT / '04_ghidra/exports/x86/full-pass5/functions.json',
              HERE.parent / 'cautious-followup-20260911/review.py',
              HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py', before_path,
              HERE.parent / 'continuous-review-20260911-18/exports/pcode.json',
              HERE.parent / 'continuous-review-20260911-18/exports/0018eee8.c',
              ROOT / '01_resources/upstream/darwin01/kernel/machdep/i386/pmap.c']
    result = json.loads((HERE / 'paging-review.json').read_text())
    entries = set(result['original_contexts'])
    rep_sites = {int(row['site'], 16) for case in result['cases'] for row in case['rep_tests']}
    # Additional original REP/MOV FS instruction contexts, identified from exports.
    for path in (ROOT / '04_ghidra/exports/x86/full-pass5/functions').glob('*.asm'):
        if any(int(line.split()[0], 16) in rep_sites | {0x186dfc} for line in path.read_text().splitlines() if line.startswith('0x')):
            entries.add(path.stem)
    inputs += [ROOT / f'04_ghidra/exports/x86/full-pass5/functions/{entry}.{suffix}'
               for entry in sorted(entries) for suffix in ('asm', 'c')]
    input_rows = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)} for p in inputs]
    (HERE / 'input-hashes.json').write_text(json.dumps(input_rows, indent=2) + '\n')
    scripts = sorted(HERE.glob('*.py'))
    for path in scripts:
        ast.parse(path.read_text(), filename=str(path))
    links = re.findall(r'\]\(([^)]+)\)', (HERE / 'README.md').read_text())
    for target in links:
        if target not in ('verification.json', 'artifact-hashes.json'):
            assert (HERE / target).exists(), target
    verification = {'prior_manifests': checked, 'project_files_per_copy_verified': len(before),
                    'project_copies_verified': len(bases), 'scripts_parsed': len(scripts),
                    'readme_links_checked': len(links), 'input_files_hashed': len(input_rows), 'mismatches': []}
    (HERE / 'verification.json').write_text(json.dumps(verification, indent=2) + '\n')
    rows = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)}
            for p in sorted(HERE.rglob('*')) if p.is_file() and '__pycache__' not in p.parts and p.name != 'artifact-hashes.json']
    (HERE / 'artifact-hashes.json').write_text(json.dumps(rows, indent=2) + '\n')
    assert all(digest(ROOT / row['path']) == row['sha256'] for row in rows)
    print(json.dumps({'verification': verification, 'new_artifacts': len(rows)}, indent=2))


if __name__ == '__main__':
    main()
