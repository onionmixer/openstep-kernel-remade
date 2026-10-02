#!/usr/bin/env python3
"""Unit tests for l1_compare.sect_of zero-size handling (plan 71)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import l1_compare as L


def obj(*secs):
    return {'sections': [dict(index=i + 1, addr=a, size=s) for i, (a, s) in enumerate(secs)]}


CASES = [
    ('empty section before a section at the same address', obj((0, 0x17c), (0x17c, 0), (0x17c, 0x40)), 0x17c, 3),
    ('inside the following section', obj((0, 0x17c), (0x17c, 0), (0x17c, 0x40)), 0x1bb, 3),
    ('end of the last section', obj((0, 0x17c), (0x17c, 0), (0x17c, 0x40)), 0x1bc, None),
    ('trailing empty section', obj((0, 0x10), (0x10, 0)), 0x10, None),
    ('ordinary first byte', obj((0, 0x10), (0x10, 8)), 0x0, 1),
    ('ordinary boundary', obj((0, 0x10), (0x10, 8)), 0x10, 2),
    ('ordinary last byte', obj((0, 0x10), (0x10, 8)), 0x17, 2),
]


def main():
    bad = 0
    for name, o, addr, want in CASES:
        got = L.sect_of(o, addr)
        ok = got == want
        bad += not ok
        print('%-4s %s: sect_of(%#x) = %r (want %r)' % ('ok' if ok else 'FAIL', name, addr, got, want))
    print('%d tests, %d failed' % (len(CASES), bad))
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
