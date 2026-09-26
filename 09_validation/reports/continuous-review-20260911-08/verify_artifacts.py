"""Verify original/project/prior evidence and manifest accepted plus rejected evidence."""
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
    manifests += [HERE.parent / f'continuous-review-20260911-{i:02d}/artifact-hashes.json' for i in range(1, 8)]
    manifests.append(HERE.parent / 'continuous-review-20260911-07/input-hashes.json')
    checked = []
    for manifest in manifests:
        rows = json.loads(manifest.read_text())
        for row in rows:
            path = ROOT / row['path']
            assert digest(path) == row['sha256'], path
            if 'size' in row:
                assert path.stat().st_size == row['size'], path
        checked.append({'manifest': str(manifest.relative_to(ROOT)), 'files_verified': len(rows)})
    before = json.loads((HERE / 'source-project-before.json').read_text())
    bases = [ROOT / '04_ghidra/projects', ROOT / '04_ghidra/projects/experiments/storage-isolated-v2-review-20260911']
    for base in bases:
        for row in before:
            assert digest(base / row['path']) == row['sha256']
    kernel = ROOT / '03_original/x86/binaries/mach_kernel'
    assert digest(kernel) == '33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890'
    scripts = sorted(HERE.glob('*.py'))
    for path in scripts:
        ast.parse(path.read_text(), filename=str(path))
    links = re.findall(r'\]\(([^)]+)\)', (HERE / 'README.md').read_text())
    for target in links:
        if target not in ('verification.json', 'artifact-hashes.json'):
            assert (HERE / target).exists(), target
    result = {'prior_manifests': checked, 'project_files_per_copy': len(before), 'project_copies': len(bases),
              'scripts_parsed': len(scripts), 'readme_links_checked': len(links), 'mismatches': []}
    (HERE / 'verification.json').write_text(json.dumps(result, indent=2) + '\n')
    rows = []
    for path in sorted(HERE.rglob('*')):
        relative = path.relative_to(HERE)
        if not path.is_file() or any(p.startswith('runtime') or p == '__pycache__' for p in relative.parts):
            continue
        if relative == Path('artifact-hashes.json'):
            continue
        rows.append({'path': str(path.relative_to(ROOT)), 'size': path.stat().st_size, 'sha256': digest(path)})
    (HERE / 'artifact-hashes.json').write_text(json.dumps(rows, indent=2) + '\n')
    for row in rows:
        assert digest(ROOT / row['path']) == row['sha256']
    print(json.dumps({'verification': result, 'new_artifacts_including_rejected_evidence': len(rows)}, indent=2))


if __name__ == '__main__':
    main()
