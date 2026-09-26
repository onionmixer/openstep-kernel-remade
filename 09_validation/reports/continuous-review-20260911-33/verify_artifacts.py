"""Preserve all finalized reports, including report32. Finalization is a separate step."""
import importlib.util
import json
from pathlib import Path
import ast
import re

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PRIOR = HERE.parent / 'continuous-review-20260911-32'
spec = importlib.util.spec_from_file_location('verifier32', PRIOR / 'verify_artifacts.py')
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
    assert json.loads((HERE / 'preservation-before.json').read_text()) == result
    assert json.loads((HERE / 'preservation-after.json').read_text()) == result
    audit = json.loads((HERE / 'independent-audit.json').read_text())
    controls = json.loads((HERE / 'negative-controls.json').read_text())
    repro = json.loads((HERE / 'reproducibility.json').read_text())
    summary = json.loads((HERE / 'dirty-remove-summary.json').read_text())
    assert audit['all_passed'] and all(r['passed'] for r in audit['cases'])
    assert controls['all_rejected'] and all(r['rejected'] for r in controls['controls'])
    assert repro['all_equal'] and repro['before'] == repro['after']
    for name, expected in repro['after'].items():
        assert digest(HERE / name) == expected, name
    assert summary['cases'] == len(audit['cases'])
    for key in ('remove_heads', 'dirty_lookups', 'pte_clears', 'pde_invalidations'):
        assert summary[key] == sum(r[key] for r in audit['cases'])
    assert summary['whole_goal_complete'] is False
    inputs = [ROOT / r['path'] for r in json.loads((PRIOR / 'input-hashes.json').read_text())]
    inputs += [PRIOR / n for n in ('artifact-hashes.json', 'verify_artifacts.py', 'fault_new_pt_review.py',
        'audit_results.py', 'fault-new-pt-cases.json', 'independent-audit.json')]
    inputs += [ROOT / f'04_ghidra/exports/x86/full-pass5/functions/{entry}.{ext}'
               for entry in ('00178894', '0018f7f8', '0018fa44', '00190f90', '0018b964', '0018b544', '00191144', '001913ec')
               for ext in ('asm', 'c', 'json')]
    entries = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)} for p in sorted(set(inputs))]
    (HERE / 'input-hashes.json').write_text(json.dumps(entries, indent=2) + '\n')
    for p in HERE.glob('*.py'):
        ast.parse(p.read_text(), filename=str(p))
    links = re.findall(r'\]\(([^)]+)\)', (HERE / 'README.md').read_text())
    for link in links:
        if link not in ('verification.json', 'artifact-hashes.json'):
            assert (HERE / link).exists(), link
    result.update(input_files_hashed=len(entries), readme_links_checked=len(links),
        independently_audited_cases=len(audit['cases']), negative_controls_rejected=len(controls['controls']),
        reproduced_files=len(repro['after']))
    (HERE / 'verification.json').write_text(json.dumps(result, indent=2) + '\n')
    entries = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)}
               for p in sorted(HERE.rglob('*')) if p.is_file() and '__pycache__' not in p.parts and p.name != 'artifact-hashes.json']
    (HERE / 'artifact-hashes.json').write_text(json.dumps(entries, indent=2) + '\n')
    print(json.dumps(dict(result, new_artifacts=len(entries)), indent=2))


if __name__ == '__main__':
    main()
