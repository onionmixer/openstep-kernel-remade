#!/usr/bin/env python3
"""Tests for kr_run.tool_hashes (plan 86.1): VM-agreed tools and the real-only record."""
import json, os, sys, tempfile
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import kr_run as K

AGREED = json.load(open(os.path.join(K.REPO, K.TOOLS_JSON)))
REAL = json.load(open(os.path.join(K.REPO, K.REAL_ONLY_JSON)))
TMP = tempfile.mkdtemp(prefix='krtools-')


def run(agreed, real):
    a, r = os.path.join(TMP, 'a.json'), os.path.join(TMP, 'r.json')
    json.dump(agreed, open(a, 'w'))
    json.dump(real, open(r, 'w'))
    old = K.TOOLS_JSON, K.REAL_ONLY_JSON
    K.TOOLS_JSON, K.REAL_ONLY_JSON = a, r
    try:
        return K.tool_hashes()
    except SystemExit as e:
        return 'DIE ' + str(e)
    finally:
        K.TOOLS_JSON, K.REAL_ONLY_JSON = old


def mod(d, path, **kw):
    d = json.loads(json.dumps(d))
    tgt = d['tools'] if 'tools' in d and path not in d else d
    if kw.get('drop'):
        tgt.pop(path)
    else:
        tgt[path].update(kw)
    return d


CASES = [
    ('current records accepted', lambda: run(AGREED, REAL), lambda r: isinstance(r, dict) and len(r) == len(K.ALLOWED_TOOLS)
     and r['/usr/lib/migcom3'] == dict(real=REAL['tools']['/usr/lib/migcom3']['real'], size=91144)
     and r['/lib/i386/cpp']['real'] == AGREED['/lib/i386/cpp']['real']),
    ('real-only entry missing', lambda: run(AGREED, mod(REAL, '/usr/lib/migcom3', drop=True)), lambda r: 'no real-machine hash' in r),
    ('real-only digest malformed', lambda: run(AGREED, mod(REAL, '/usr/lib/migcom3', real='xyz')), lambda r: 'no real-machine hash' in r),
    ('real-only size missing', lambda: run(AGREED, mod(REAL, '/usr/lib/migcom3', size='91144')), lambda r: 'no real-machine hash' in r),
    ('i386 cpp VM mismatch', lambda: run(mod(AGREED, '/lib/i386/cpp', vm='0' * 64), REAL), lambda r: 'no agreed hash' in r and '/lib/i386/cpp' in r),
    ('i386 cpp missing', lambda: run(mod(AGREED, '/lib/i386/cpp', drop=True), REAL), lambda r: 'no agreed hash' in r),
    ('agreed record cannot stand in for real-only tool', lambda: run(dict(AGREED, **{'/usr/lib/migcom3': dict(real='a' * 64, vm='a' * 64, size=1)}),
                                                                    mod(REAL, '/usr/lib/migcom3', drop=True)), lambda r: 'no real-machine hash' in r),
]


def main():
    bad = 0
    for name, f, ok in CASES:
        r = f()
        good = bool(ok(r))
        bad += not good
        print('%-4s %s%s' % ('ok' if good else 'FAIL', name, '' if good else ': %r' % (r,)))
    print('%d tests, %d failed' % (len(CASES), bad))
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
