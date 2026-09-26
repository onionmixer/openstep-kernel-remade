"""Read-only evidence checks, followed by generation of this review's manifest."""
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
    reports = HERE.parent
    manifests = [reports / 'full-analysis/artifact-hashes.json',
                 reports / 'deep-review-20260911/review-artifact-hashes.json',
                 reports / 'cautious-followup-20260911/artifact-hashes.json']
    manifests.extend(reports / f'continuous-review-20260911-{i:02d}/artifact-hashes.json'
                     for i in range(1, 5))
    checked = []
    for manifest in manifests:
        rows = json.loads(manifest.read_text())
        for row in rows:
            path = ROOT / row['path']
            assert digest(path) == row['sha256'], path
            if 'size' in row:
                assert path.stat().st_size == row['size'], path
        checked.append({'manifest': str(manifest.relative_to(ROOT)), 'files_verified': len(rows)})
    project_rows = json.loads((HERE / 'source-project-before.json').read_text())
    project_roots = [ROOT / '04_ghidra/projects',
                     ROOT / '04_ghidra/projects/experiments/padding-review-20260911']
    for base in project_roots:
        for row in project_rows:
            assert digest(base / row['path']) == row['sha256'], base / row['path']
    kernel = ROOT / '03_original/x86/binaries/mach_kernel'
    assert digest(kernel) == '33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890'
    scripts = sorted(HERE.glob('*.py'))
    for script in scripts:
        ast.parse(script.read_text(), filename=str(script))
    links = re.findall(r'\]\(([^)]+)\)', (HERE / 'README.md').read_text())
    generated = {'verification.json', 'artifact-hashes.json'}
    for target in links:
        if target not in generated:
            assert (HERE / target).exists(), target
    result = {'prior_manifests': checked, 'project_files_verified_per_copy': len(project_rows),
              'project_copies_verified': len(project_roots), 'kernel_sha256': digest(kernel),
              'python_scripts_parsed': len(scripts), 'readme_link_targets_checked': len(links),
              'mismatches': []}
    (HERE / 'verification.json').write_text(json.dumps(result, indent=2) + '\n')
    rows = []
    for path in sorted(HERE.rglob('*')):
        relative = path.relative_to(HERE)
        if not path.is_file() or 'runtime' in relative.parts or '__pycache__' in relative.parts:
            continue
        if relative == Path('artifact-hashes.json'):
            continue
        rows.append({'path': str(path.relative_to(ROOT)), 'size': path.stat().st_size,
                     'sha256': digest(path)})
    (HERE / 'artifact-hashes.json').write_text(json.dumps(rows, indent=2) + '\n')
    for row in rows:
        assert digest(ROOT / row['path']) == row['sha256']
    print(json.dumps({'verification': result, 'new_artifacts': len(rows)}, indent=2))


if __name__ == '__main__':
    main()
