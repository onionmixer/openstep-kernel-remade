"""Recheck bounded evidence; keep full analysis and native/build claims open."""
import hashlib
import json
import re
import audit_pd as A


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    here, root = A.S.HERE, A.S.ROOT
    preserved = A.S.preserve()
    assert preserved == json.loads((here / 'preservation.json').read_text())
    rows = json.loads((here / 'pd-cases.json').read_text())
    assert [tuple(r['params']) for r in rows] == A.S.matrix(False)
    refs = A.S.references()
    results = [A.lifecycle(r, refs[tuple(r['params'][:2])]) for r in rows]
    audit = json.loads((here / 'pd-audit.json').read_text())
    assert audit['all_passed'] and audit['cases'] == results
    stages = [s for r in rows for s in r['stages']]
    summary = json.loads((here / 'pd-summary.json').read_text())
    expected = {'cases': len(rows), 'stages': len(stages), 'heads': sum(len(s['recorded_heads']) for s in stages),
                'writes': sum(len(s['writes']) for s in stages), 'kernel_PDE_copies': sum(len(s['copies']) for s in stages)}
    assert all(summary[k] == v for k, v in expected.items())
    basis = json.loads((here / 'source-basis.json').read_text())
    assert basis['preservation_sha256'] == A.S.canonical(preserved)
    for item in basis['inputs']:
        f = root / item['path']
        assert f.stat().st_size == item['size'] and sha(f) == item['sha256'], f
    controls = json.loads((here / 'negative-controls.json').read_text())
    assert controls['all_rejected'] and all(r['rejected'] for r in controls['controls'])
    assert len({r['name'] for r in controls['controls']}) == len(controls['controls'])
    repro = json.loads((here / 'reproducibility.json').read_text())
    assert repro['equal'] and repro['before'] == repro['after']
    assert all(c['returncode'] == 0 for c in repro['commands'])
    for name, value in repro['after'].items():
        assert sha(here / name) == value, name
    for name in ('README.md', 'CROSS_REVIEW.md', 'OPEN_ITEMS.md'):
        for link in re.findall(r'\]\(([^)]+)\)', (here / name).read_text()):
            if link != 'checkpoint.json':
                assert (here / link).is_file(), link
    files = [{'path': str(p.relative_to(here)), 'size': p.stat().st_size, 'sha256': sha(p)}
        for p in sorted(here.rglob('*')) if p.is_file() and p.name != 'checkpoint.json' and '__pycache__' not in p.parts]
    A.S.save('checkpoint.json', {'files': files, 'cases_checked': len(rows), 'stages_checked': len(stages),
        'negative_controls_rejected': len(controls['controls']), 'reproduced_artifacts': len(repro['after']),
        'bounded_PD_lifecycle_checks_passed': True, 'full_CPU_semantics_verified': False,
        'native_cpu_verified': False, 'report_finalized': False, 'whole_goal_complete': False})
    print(json.dumps({'checkpoint_files': len(files), 'cases_checked': len(rows), 'stages_checked': len(stages)}))


if __name__ == '__main__':
    main()
