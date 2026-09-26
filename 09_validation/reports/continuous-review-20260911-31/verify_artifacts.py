"""Check preservation, completed report gates, input hashes and artifact hashes."""
import ast
import importlib.util
import json
from pathlib import Path
import re

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PRIOR = HERE.parent / 'continuous-review-20260911-30'
spec = importlib.util.spec_from_file_location('verifier30', PRIOR / 'verify_artifacts.py')
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
    before = json.loads((HERE / 'preservation-before.json').read_text())
    after = json.loads((HERE / 'preservation-after.json').read_text())
    assert before == after == result
    audit = json.loads((HERE / 'independent-audit.json').read_text())
    controls = json.loads((HERE / 'negative-controls.json').read_text())
    repro = json.loads((HERE / 'reproducibility.json').read_text())
    summary = json.loads((HERE / 'new-pt-summary.json').read_text())
    assert audit['all_passed'] and all(r['passed'] for r in audit['cases'])
    assert controls['all_rejected'] and all(r['rejected'] for r in controls['controls'])
    assert repro['all_equal'] and repro['before'] == repro['after']
    for name, expected in repro['after'].items():
        assert digest(HERE / name) == expected, name
    assert summary['cases'] == len(audit['cases'])
    assert summary['zero_dword_stores'] == sum(r['zero_dword_stores'] for r in audit['cases'])
    assert summary['whole_goal_complete'] is False
    inputs = [ROOT / row['path'] for row in json.loads((PRIOR / 'input-hashes.json').read_text())]
    inputs += [PRIOR / n for n in ('artifact-hashes.json', 'verify_artifacts.py', 'pt_lifecycle_review.py', 'audit_results.py')]
    inputs += [ROOT / f'04_ghidra/exports/x86/full-pass5/functions/{entry}.{ext}'
               for entry in ('00174848', '00176164', '00175b2c', '0017358c', '00173898', '0017b6e8',
                             '0016b790', '0016b84c', '0018c0d8', '00178c30', '00178c64', '0017af58', '0018eee8')
               for ext in ('asm', 'c', 'json')]
    inputs += [ROOT / n for n in ('AGENTS.md', '02_plan/FULL_ANALYSIS.md', '08_build/GCC27_COMPATIBILITY.md')]
    rows = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)} for p in sorted(set(inputs))]
    (HERE / 'input-hashes.json').write_text(json.dumps(rows, indent=2) + '\n')
    for p in HERE.glob('*.py'):
        ast.parse(p.read_text(), filename=str(p))
    links = re.findall(r'\]\(([^)]+)\)', (HERE / 'README.md').read_text())
    for target in links:
        if target not in ('verification.json', 'artifact-hashes.json'):
            assert (HERE / target).exists(), target
    result.update(input_files_hashed=len(rows), readme_links_checked=len(links),
                  independently_audited_cases=len(audit['cases']), negative_controls_rejected=len(controls['controls']),
                  reproduced_files=len(repro['after']))
    (HERE / 'verification.json').write_text(json.dumps(result, indent=2) + '\n')
    rows = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)}
            for p in sorted(HERE.rglob('*')) if p.is_file() and '__pycache__' not in p.parts and p.name != 'artifact-hashes.json']
    (HERE / 'artifact-hashes.json').write_text(json.dumps(rows, indent=2) + '\n')
    print(json.dumps(dict(result, new_artifacts=len(rows)), indent=2))


if __name__ == '__main__':
    main()
