"""Negative controls for independent schedule/label validation; no CPU runs."""
import copy
import json
from pathlib import Path
import audit_results as A

HERE = Path(__file__).resolve().parent


def main():
    cases = json.loads((HERE / 'allocator-cases.json').read_text())
    original = next(r for r in cases if r['seed'] == 'cached' and r['scenario'] == 'equal_ordinary')
    outcomes = []
    for mutation in ('wrong reserve equality', 'wrong privilege', 'wrong function entry', 'missing seed operation', 'wrong seed label'):
        row = copy.deepcopy(original)
        admission = next(op for op in row['operations'] if op['name'] == 'admission_configuration')
        if mutation == 'wrong reserve equality':
            admission['reserved'] += 1
        elif mutation == 'wrong privilege':
            admission['privilege'] = 1
        elif mutation == 'wrong function entry':
            next(op for op in row['operations'] if op['name'] == 'addfree')['entry'] = '0x17b540'
        elif mutation == 'missing seed operation':
            row['operations'] = [op for op in row['operations'] if op['name'] != 'seed_busy_clear']
        else:
            row['seed'] = 'detached'
        try:
            A.validate_schedule(row)
        except AssertionError as exc:
            outcomes.append({'mutation': mutation, 'rejected': True, 'reason': str(exc)})
        else:
            raise AssertionError(('corruption accepted', mutation))
    A.validate_schedule(original)
    result = {'negative_controls': outcomes, 'rejections': len(outcomes), 'uncorrupted_control_passed': True,
              'scope': 'independent analyzer input checks, not kernel execution'}
    (HERE / 'negative-controls.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
