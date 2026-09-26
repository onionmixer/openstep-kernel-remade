"""Report35 preservation chain; no finalized producer invocation."""
import importlib.util
import ast
import json
from pathlib import Path
import re

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PRIOR = HERE.parent / 'continuous-review-20260912-34'
spec = importlib.util.spec_from_file_location('verify34', PRIOR / 'verify_artifacts.py')
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


def main():
    result = preserved()
    def read(name):
        return json.loads((HERE / name).read_text())
    assert read('preservation.json') == result
    regression, controls, repro, inventory = (read(name) for name in
        ('consumer-regression.json', 'negative-controls.json', 'reproducibility.json', 'consumer-inventory.json'))
    assert regression['all_passed'] and regression['whole_goal_complete'] is False
    assert all(r['original_audit_passed'] for r in regression['cases'])
    from review import SOURCES, rows
    expected = {(number, i) for number in SOURCES for i, row in enumerate(rows(number))}
    assert {(r['report'], r['index']) for r in regression['cases']} == expected
    assert len(regression['cases']) == len(expected)
    assert controls['all_rejected'] and all(c['rejected'] for c in controls['controls'])
    assert len({c['name'] for c in controls['controls']}) == len(controls['controls'])
    assert all(c['accepted'] for c in controls['component_positive_controls'])
    assert repro['all_equal'] and repro['before'] == repro['after']
    for name, sha in repro['after'].items():
        assert digest(HERE / name) == sha, name
    inputs = [ROOT / r['path'] for r in json.loads((PRIOR / 'input-hashes.json').read_text())]
    inputs += [PRIOR / n for n in ('artifact-hashes.json', 'verify_artifacts.py', 'audit_results.py', 'gc-cases.json')]
    inputs += [ROOT / r['path'] for r in inventory['files']]
    for r in inventory['files']:
        p = ROOT / r['path']
        assert p.stat().st_size == r['size'] and digest(p) == r['sha256']
    for directory, filename in SOURCES.values():
        inputs += [HERE.parent / directory / n for n in (filename, 'audit_results.py', 'artifact-hashes.json')]
    inputs += [ROOT / f'04_ghidra/exports/x86/full-pass5/functions/{entry}.{ext}'
               for entry in ('001861cc', '00186d20', '00187068', '00189cec', '00189e8c', '0017b200', '00190f90')
               for ext in ('asm', 'c', 'json')]
    entries = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)} for p in sorted(set(inputs))]
    (HERE / 'input-hashes.json').write_text(json.dumps(entries, indent=2) + '\n')
    for p in HERE.glob('*.py'):
        ast.parse(p.read_text(), filename=str(p))
    links = re.findall(r'\]\(([^)]+)\)', (HERE / 'README.md').read_text())
    for link in links:
        if link not in ('verification.json', 'artifact-hashes.json'):
            assert (HERE / link).exists(), link
    result.update(input_files_hashed=len(entries), regression_cases=len(expected),
        negative_controls_rejected=len(controls['controls']), component_positive_controls=len(controls['component_positive_controls']),
        reproduced_files=len(repro['after']), inventoried_files=len(inventory['files']), inventory_hits=len(inventory['findings']),
        readme_links_checked=len(links), whole_goal_complete=False,
        scope='bounded read-only consumer regression, not full CPU semantics or completed reconstruction')
    (HERE / 'verification.json').write_text(json.dumps(result, indent=2) + '\n')
    entries = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)}
               for p in sorted(HERE.rglob('*')) if p.is_file() and '__pycache__' not in p.parts and p.name != 'artifact-hashes.json']
    (HERE / 'artifact-hashes.json').write_text(json.dumps(entries, indent=2) + '\n')
    print(json.dumps(dict(result, new_artifacts=len(entries)), indent=2))


if __name__ == '__main__':
    main()
