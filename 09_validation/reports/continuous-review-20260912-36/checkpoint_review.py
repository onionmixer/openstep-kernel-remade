"""Hash an in-progress evidence checkpoint, NOT report or whole-goal finalization."""
import hashlib
import json
from pathlib import Path
from verify_artifacts import preserved

HERE = Path(__file__).resolve().parent


def main():
    direct = json.loads((HERE / 'direct-audit.json').read_text())
    controls = json.loads((HERE / 'direct-negative-controls.json').read_text())
    repro = json.loads((HERE / 'direct-reproducibility.json').read_text())
    diagnostic = json.loads((HERE / 'diagnostic-verification.json').read_text())
    assert direct['all_passed'] and controls['all_rejected'] and repro['equal']
    assert direct['actual_fault_reentry_verified'] is False and diagnostic['report36_reuse_complete'] is False
    for name, expected in repro['after'].items():
        assert hashlib.sha256((HERE / name).read_bytes()).hexdigest() == expected
    for name, expected in diagnostic['reproducibility']['after'].items():
        assert hashlib.sha256((HERE / name).read_bytes()).hexdigest() == expected
    entries = []
    for path in sorted(HERE.iterdir()):
        if path.is_file() and path.name != 'checkpoint.json':
            entries.append({'name': path.name, 'size': path.stat().st_size,
                            'sha256': hashlib.sha256(path.read_bytes()).hexdigest()})
    out = {'files': entries, 'preservation': preserved(), 'direct_summary': direct['summary'],
        'negative_controls': len(controls['controls']), 'reproduced_direct_artifacts': len(repro['after']),
        'actual_fault_reentry_verified': False, 'report36_finalized': False, 'whole_goal_complete': False,
        'scope': 'dated in-progress checkpoint; original fault reentry obligation remains open'}
    (HERE / 'checkpoint.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps({'checkpoint_files': len(entries), 'report36_finalized': False}))


if __name__ == '__main__':
    main()
