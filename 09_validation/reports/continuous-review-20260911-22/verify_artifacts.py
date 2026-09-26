"""Read-only earlier-evidence verification; emit only new report artifacts."""
import ast
import hashlib
import json
from pathlib import Path
import re

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def preserved():
    manifests = [HERE.parent / 'full-analysis/artifact-hashes.json',
                 HERE.parent / 'deep-review-20260911/review-artifact-hashes.json',
                 HERE.parent / 'cautious-followup-20260911/artifact-hashes.json']
    manifests += [HERE.parent / f'continuous-review-20260911-{i:02d}/artifact-hashes.json' for i in range(1, 22)]
    checked = []
    for manifest in manifests:
        rows = json.loads(manifest.read_text())
        for row in rows:
            p = ROOT / row['path']
            assert digest(p) == row['sha256'], p
            if 'size' in row:
                assert p.stat().st_size == row['size'], p
        checked.append({'manifest': str(manifest.relative_to(ROOT)), 'files_verified': len(rows)})
    before = json.loads((HERE.parent / 'continuous-review-20260911-19/source-project-before.json').read_text())
    bases = [ROOT / '04_ghidra/projects']
    bases += [ROOT / '04_ghidra/projects/experiments' / name for name in (
        'protected-data-review-20260911', 'io-control-review-20260911',
        'cpu-state-review-20260911', 'segment-state-review-20260911')]
    for base in bases:
        for row in before:
            assert digest(base / row['path']) == row['sha256']
    return {'prior_manifests': checked, 'project_copies_verified': len(bases),
            'project_files_per_copy_verified': len(before), 'mismatches': []}


def main():
    result = preserved()
    inputs = [ROOT / '03_original/x86/binaries/mach_kernel', ROOT / '03_original/x86/inventory/macho.json',
              ROOT / '04_ghidra/exports/x86/full-pass5/functions.json',
              HERE.parent / 'cautious-followup-20260911/review.py',
              HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py',
              HERE.parent / 'continuous-review-20260911-21/paging_review.py',
              HERE.parent / 'continuous-review-20260911-21/paging-review.json',
              HERE.parent / 'continuous-review-20260911-02/README.md',
              HERE.parent / 'continuous-review-20260911-19/pcode-audit.json',
              HERE.parent / 'continuous-review-20260911-18/exports/pcode.json',
              HERE.parent / 'continuous-review-20260911-18/exports/0018d37c.c']
    prior = json.loads((HERE.parent / 'continuous-review-20260911-21/paging-review.json').read_text())
    entries = set(prior['original_contexts']) | {'001860dc', '00186ddc', '0018d37c', '0018a184', '00189a5c', '00189b34'}
    inputs += [ROOT / f'04_ghidra/exports/x86/full-pass5/functions/{e}.{suffix}'
               for e in sorted(entries) for suffix in ('asm', 'c')]
    rows = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)} for p in inputs]
    (HERE / 'input-hashes.json').write_text(json.dumps(rows, indent=2) + '\n')
    scripts = sorted(HERE.glob('*.py'))
    for p in scripts:
        ast.parse(p.read_text(), filename=str(p))
    links = re.findall(r'\]\(([^)]+)\)', (HERE / 'README.md').read_text())
    for target in links:
        if target not in ('verification.json', 'artifact-hashes.json'):
            assert (HERE / target).exists(), target
    result.update(input_files_hashed=len(rows), scripts_parsed=len(scripts), readme_links_checked=len(links))
    (HERE / 'verification.json').write_text(json.dumps(result, indent=2) + '\n')
    artifacts = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)}
                 for p in sorted(HERE.rglob('*')) if p.is_file() and '__pycache__' not in p.parts and p.name != 'artifact-hashes.json']
    (HERE / 'artifact-hashes.json').write_text(json.dumps(artifacts, indent=2) + '\n')
    print(json.dumps(dict(result, new_artifacts=len(artifacts)), indent=2))


if __name__ == '__main__':
    main()
