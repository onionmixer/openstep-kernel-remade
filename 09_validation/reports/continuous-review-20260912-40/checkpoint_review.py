"""Bounded checkpoint gates; never marks the whole analysis goal complete."""
import hashlib
import json
import audit_removal as A


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    preserved = A.S.preserve()
    assert json.loads((A.S.HERE / 'preservation.json').read_text()) == preserved
    refs = A.S.references()
    rows = json.loads((A.S.HERE / 'removal-cases.json').read_text())
    assert [(tuple(r['params']), r['mode']) for r in rows] == A.S.matrix(False)
    checks = [A.check(r, refs[tuple(r['params'])]) for r in rows]
    audit = json.loads((A.S.HERE / 'removal-audit.json').read_text())
    assert audit['all_passed'] and audit['cases'] == checks
    summary = json.loads((A.S.HERE / 'removal-summary.json').read_text())
    assert summary['cases'] == len(rows)
    assert summary['heads'] == sum(len(r['recorded_heads']) for r in rows)
    assert summary['writes'] == sum(len(r['writes']) for r in rows)
    assert summary['scanned_bundles'] == sum(len(r['scans']) for r in rows)
    assert summary['remove_calls'] == sum(c['removed'] for c in checks)
    basis = json.loads((A.S.HERE / 'source-basis.json').read_text())
    assert basis['preservation_sha256'] == A.S.canonical(preserved)
    for item in basis['inputs']:
        path = A.S.ROOT / item['path']
        assert path.stat().st_size == item['size'] and sha(path) == item['sha256'], path
    controls = json.loads((A.S.HERE / 'negative-controls.json').read_text())
    assert controls['all_rejected'] and all(r['rejected'] for r in controls['controls'])
    assert len({r['name'] for r in controls['controls']}) == len(controls['controls'])
    repro = json.loads((A.S.HERE / 'reproducibility.json').read_text())
    assert repro['equal'] and repro['before'] == repro['after'] and all(c['returncode'] == 0 for c in repro['commands'])
    for name, value in repro['after'].items():
        assert sha(A.S.HERE / name) == value, name
    files = [{'path': str(p.relative_to(A.S.HERE)), 'size': p.stat().st_size, 'sha256': sha(p)}
             for p in sorted(A.S.HERE.rglob('*')) if p.is_file() and p.name != 'checkpoint.json' and '__pycache__' not in p.parts]
    A.S.save('checkpoint.json', {'files': files, 'cases_checked': len(checks),
        'negative_controls_rejected': len(controls['controls']), 'reproduced_artifacts': len(repro['after']),
        'original_remove_executed': True, 'bounded_checks_passed': True,
        'full_CPU_semantics_verified': False, 'native_cpu_verified': False,
        'report_finalized': False, 'whole_goal_complete': False})
    print(json.dumps({'checkpoint_files': len(files), 'cases_checked': len(checks),
                      'negative_controls_rejected': len(controls['controls'])}))


if __name__ == '__main__':
    main()
