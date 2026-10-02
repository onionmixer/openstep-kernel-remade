#!/usr/bin/env python3
"""Tests for zerofill_check.conclude (decision D019, plan 84.1)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import zerofill_check as Z

R = dict(scattered=False, pcrel=False)
UND = dict(detected=False)
DET = dict(detected=True)
CASES = [
    ('all checks and negative pass', (True, True, [R, R], DET), 'reference-inferred'),
    ('single plain reference, negative undetected', (False, True, [R], UND), 'reference-inferred-single'),
    ('two references, negative undetected', (False, True, [R, R], UND), 'fail'),
    ('single reference, another check failed', (False, False, [R], UND), 'fail'),
    ('single scattered reference', (False, True, [dict(R, scattered=True)], UND), 'fail'),
    ('single pc-relative reference', (False, True, [dict(R, pcrel=True)], UND), 'fail'),
    ('single reference, negative detected but other failure', (False, False, [R], DET), 'fail'),
    ('no references', (False, False, [], None), 'fail'),
]


def main():
    bad = 0
    for name, args, want in CASES:
        got = Z.conclude(*args)
        ok = got == want
        bad += not ok
        print('%-4s %s%s' % ('ok' if ok else 'FAIL', name, '' if ok else ': got %s' % got))
    print('%d tests, %d failed' % (len(CASES), bad))
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
