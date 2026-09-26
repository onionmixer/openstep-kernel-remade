"""Preservation checks and explicit report34 finalization after all evidence gates."""
import ast
import importlib.util
import json
from pathlib import Path
import re

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PRIOR = HERE.parent / 'continuous-review-20260911-33'
spec = importlib.util.spec_from_file_location('verifier33', PRIOR / 'verify_artifacts.py')
V = importlib.util.module_from_spec(spec)
spec.loader.exec_module(V)
digest = V.digest


def preserved():
    result = V.preserved()
    manifest = PRIOR / 'artifact-hashes.json'
    rows = json.loads(manifest.read_text())
    for row in rows:
        p = ROOT / row['path']
        assert p.stat().st_size == row['size'] and digest(p) == row['sha256'], p
    result['prior_manifests'].append({'manifest': str(manifest.relative_to(ROOT)), 'files_verified': len(rows)})
    return result


def main():
    result = preserved()
    assert json.loads((HERE / 'preservation-before.json').read_text()) == result
    assert json.loads((HERE / 'preservation-after.json').read_text()) == result
    def read(name):
        return json.loads((HERE / name).read_text())
    audit, controls, repro = read('independent-audit.json'), read('negative-controls.json'), read('reproducibility.json')
    summary, legacy, helper = read('gc-summary.json'), read('legacy-stack-review.json'), read('helper-check.json')
    assert audit['all_passed'] and all(r['passed'] for r in audit['cases'])
    assert controls['all_rejected'] and all(r['rejected'] for r in controls['controls'])
    assert len({r['name'] for r in controls['controls']}) == len(controls['controls'])
    assert legacy['all_passed'] and all(r['passed'] for r in legacy['cases']) and legacy['write_cardinality_applied'] is False
    assert helper['matched'] and helper['helper_sha256'] == digest(HERE / 'dirty_prefix.py')
    assert repro['all_equal'] and repro['before'] == repro['after']
    for name, expected in repro['after'].items():
        assert digest(HERE / name) == expected, name
    assert summary['cases'] == len(audit['cases'])
    for key in ('gc_heads', 'gc_executed'):
        assert summary[key] == sum(r[key] for r in audit['cases'])
    assert summary['whole_goal_complete'] is False
    inputs = [ROOT / r['path'] for r in json.loads((PRIOR / 'input-hashes.json').read_text())]
    inputs += [PRIOR / n for n in ('artifact-hashes.json', 'verify_artifacts.py', 'dirty_remove_review.py',
        'audit_results.py', 'dirty-remove-cases.json', 'independent-audit.json')]
    inputs += [ROOT / f'04_ghidra/exports/x86/full-pass5/functions/{entry}.{ext}'
        for entry in ('00191144', '0016b84c', '00173e90', '001765ac', '00176164', '001735f4',
                      '00190c24', '00190b5c', '00178894', '0017b7bc', '001914c8', '00179bbc',
                      '0018fb0c', '0017b540', '0017b5f8', '00178c64', '0018fa44', '00190f90')
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
        legacy_stack_cases=len(legacy['cases']), reproduced_files=len(repro['after']),
        report_status='bounded report34 evidence gates passed; whole analysis incomplete', whole_goal_complete=False)
    (HERE / 'verification.json').write_text(json.dumps(result, indent=2) + '\n')
    entries = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': digest(p)}
        for p in sorted(HERE.rglob('*')) if p.is_file() and '__pycache__' not in p.parts and p.name != 'artifact-hashes.json']
    (HERE / 'artifact-hashes.json').write_text(json.dumps(entries, indent=2) + '\n')
    print(json.dumps(dict(result, new_artifacts=len(entries)), indent=2))


if __name__ == '__main__':
    main()
