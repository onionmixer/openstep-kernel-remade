#!/usr/bin/env python3
"""Tests for plan 357: darwin_of maps components/... only into the Darwin 0.1 component trees
architecture and driverkit-1; other darwin01 directories (objc-1 of D046, Libc) are reference
copies and are never staged as components/...  Real stages go to a temporary directory."""
import json, os, shutil, subprocess, sys, tempfile
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import stage_headers as S

REPO = os.path.dirname(os.path.dirname(HERE))
TOOL = os.path.join(HERE, 'stage_headers.py')
TMP = tempfile.mkdtemp(prefix='components-test-')
J = os.path.join
results = []


def check(name, ok, info=None):
    results.append((name, bool(ok), info))


try:
    check('a  objc-1 is not a component', S.darwin_of(J('components', 'objc', 'objc.h')) is None)
    check('b  Libc is not a component', S.darwin_of(J('components', 'Libc', 'gen', 'x.h')) is None)
    check('c  .. cannot leave the component list',
          S.darwin_of(J('components', '..', 'kernel', 'x.h')) is None
          and S.darwin_of(J('components', 'architecture', '..', 'objc', 'objc.h')) is None)
    check('d  architecture unchanged', S.darwin_of(J('components', 'architecture', 'byte_order.h')) == J(S.ARCH, 'byte_order.h'))
    check('e  driverkit-1 unchanged', S.darwin_of(J('components', 'driverkit-1', 'driverkit', 'IODevice.h'))
          == J(S.D01, 'driverkit-1', 'driverkit', 'IODevice.h'))
    check('f  src and nextdev unchanged', S.darwin_of(J('src', 'kern', 'zalloc.h')) == J(S.KERNEL, 'kern', 'zalloc.h')
          and S.darwin_of(J('nextdev', 'objc', 'objc.h')) == J(S.NEXTDEV, 'objc', 'objc.h'))
    check('g  logical_of still names every root (candidates)',
          S.logical_of(J(S.D01, 'objc', 'objc.h')) == J('components', 'objc', 'objc.h')
          and S.logical_of(J(S.ARCH, 'byte_order.h')) == J('components', 'architecture', 'byte_order.h')
          and S.logical_of(J(S.D01, 'driverkit-1', 'driverkit', 'x.h')) == J('components', 'driverkit-1', 'driverkit', 'x.h'))
    check('h  select of a components/objc name without a 07 copy is None',
          S.select(J('components', 'objc', 'objc.h'), True) is None)
    # real staging: kernserv/kern_server.c reads <objc/objc.h> textually (ddmPrivate.h, !KERNEL branch)
    for k, flags in (('i', ['--prefer-07', '--nextdev']), ('j', ['--nextdev'])):
        st = J(TMP, 's' + k)
        r = subprocess.run(['python3', TOOL] + flags + ['--bsd-set', 'nextos', '--mach-set', 'sdk', st, 'kernserv/kern_server.c'],
                           capture_output=True, text=True, cwd=REPO)
        rows = json.load(open(st + '.manifest.json'))['files'] if r.returncode == 0 else []
        bad = [x[:2] for x in rows if x[0].startswith(J('components', 'objc') + os.sep)]
        check('%s  staging %s succeeds, no components/objc rows' % (k, ' '.join(flags)), r.returncode == 0 and not bad, (r.stderr[-300:], bad))
        if k == 'i':
            ob = [x[:2] for x in rows if x[0] == J('nextdev', 'objc', 'objc.h')]
            check('i2 nextdev/objc/objc.h comes from the 07 SDK copy', ob and ob[0][1] == J('07_kernel', 'nextdev', 'objc', 'objc.h'), ob)
finally:
    shutil.rmtree(TMP)

bad = [x for x in results if not x[1]]
for name, ok, info in results:
    print('%-4s %s %s' % ('ok' if ok else 'FAIL', name, '' if ok else info))
print('%d tests, %d failed' % (len(results), len(bad)))
sys.exit(1 if bad else 0)
