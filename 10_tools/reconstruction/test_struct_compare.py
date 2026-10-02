#!/usr/bin/env python3
"""Fixture tests for struct_compare.definitions/mask (plan 79.1)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import struct_compare as C

CASES = [
    ('plain', 'struct a {\n\tint x;\n};\n', 'a', [['int x;']]),
    ('comment with braces', 'struct a { /* { not } */\n int x; // }\n};\n', 'a', [['int x;']]),
    ('string with brace', 'char *s = "}"; struct a {\n char c; /* x */\n};\n', 'a', [['char c;']]),
    ('nested struct', 'struct a {\n struct { int y; } in;\n int z;\n};\n', 'a', [['struct { int y; } in;', 'int z;']]),
    ('typedef', 'typedef struct a {\n int x;\n} a_t;\n', 'a', [['int x;']]),
    ('forward declaration only', 'struct a;\nstruct a *p;\n', 'a', []),
    ('conditional member kept', 'struct a {\n#if X\n int x;\n#else\n long y;\n#endif\n};\n', 'a',
     [['#if X', 'int x;', '#else', 'long y;', '#endif']]),
    ('two definitions', '#if A\nstruct a {\n int x;\n};\n#else\nstruct a {\n long x;\n};\n#endif\n', 'a',
     [['int x;'], ['long x;']]),
    ('name prefix not matched', 'struct ab {\n int q;\n};\n', 'a', []),
]


def main():
    bad = 0
    for name, text, tag, want in CASES:
        got = [d[2] for d in C.definitions(text, tag)]
        ok = got == want
        bad += not ok
        print('%-4s %s%s' % ('ok' if ok else 'FAIL', name, '' if ok else ': got %r' % got))
    print('%d tests, %d failed' % (len(CASES), bad))
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
