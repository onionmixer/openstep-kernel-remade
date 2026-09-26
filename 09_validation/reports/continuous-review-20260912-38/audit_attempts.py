"""Verify terminal pre-guest failures; never fabricate a Bochs RF observation."""
import hashlib
import json
from pathlib import Path
import run_bochs as R

HERE = Path(__file__).resolve().parent


def main():
    prior = R.preserve()
    failures = []
    for name, message in (
        ('case-2', 'wxWidgets was not used as the configuration interface'),
        ('case-2-wx', 'Unable to initialize GTK+'),
        ('case-2-nogui', "display library 'nogui' not available")):
        directory = HERE / name
        row = json.loads((directory / 'run.json').read_text())
        assert row['flags'] == 2 and row['returncode'] == 1 and row['timed_out'] is False
        assert row['RF_contract_verified'] is False and row['whole_goal_complete'] is False
        assert row['config_sha256'] == R.sha(HERE / 'bochsrc')
        assert row['debugger_script_sha256'] == R.sha(HERE / 'debugger.rc')
        assert row['bochs_sha256'] == R.sha(Path('/usr/bin/bochs-bin'))
        for filename, value in row['hashes'].items():
            assert R.sha(directory / filename) == value, (name, filename)
        assert set(row['input_hashes']) == {'bios.bin', 'code.bin', 'data.bin', 'tables.bin'}
        for filename, value in row['input_hashes'].items():
            assert R.sha(directory / filename) == R.sha(R.PRIOR / 'case-2' / filename) == value
        text = (directory / 'stdout.bin').read_bytes() + (directory / 'stderr.bin').read_bytes()
        assert message.encode() in text
        assert not list(directory.glob('*frame*.bin'))
        assert not (directory / 'results.bin').exists()
        assert not (directory / 'code-after.bin').exists()
        if name == 'case-2-wx':
            assert 'Cannot establish any listening sockets' in (directory / 'xvfb.log').read_text()
            assert 'config_interface: wx' in row['command']
        if name == 'case-2-nogui':
            assert row['command'][0] == '/usr/bin/bochs-bin'
            assert 'display_library: nogui' in row['command']
        failures.append({'case': name, 'terminal_pre_guest_failure': True,
                         'message': message, 'RF_observation': None})
    out = {'failures': failures, 'prior_checkpoint_sha256': prior, 'Bochs_RF_verified': False,
           'installed_QEMU_source_cause_verified': False, 'whole_goal_complete': False}
    (HERE / 'attempt-audit.json').write_text(json.dumps(out, indent=2) + '\n')
    entries = []
    for path in sorted(HERE.rglob('*')):
        if path.is_file() and path.name != 'checkpoint.json' and '__pycache__' not in path.parts:
            entries.append({'path': str(path.relative_to(HERE)), 'size': path.stat().st_size,
                            'sha256': hashlib.sha256(path.read_bytes()).hexdigest()})
    (HERE / 'checkpoint.json').write_text(json.dumps({'files': entries,
        'prior_checkpoint_sha256': prior, 'Bochs_RF_verified': False,
        'report_finalized': False, 'whole_goal_complete': False}, indent=2) + '\n')
    print(json.dumps({'verified_failed_attempts': len(failures), 'checkpoint_files': len(entries),
                      'Bochs_RF_verified': False}))


if __name__ == '__main__':
    main()
