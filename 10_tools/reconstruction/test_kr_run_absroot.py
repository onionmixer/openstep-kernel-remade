#!/usr/bin/env python3
"""Tests for the kr_run ABSROOT directive (plan 304, D033): parsing, the input-hashed marker
and the generated run.sh lines.  prepare() runs against a temporary RUNS/REGISTRY with stub
tool hashes, so the real registry is not touched."""
import os, shutil, sys, tempfile
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import kr_run as K

TMP = tempfile.mkdtemp(prefix='krabs-')
results = []


def check(name, ok, info=None):
    results.append((name, bool(ok), info))


def parse(text):
    p = os.path.join(TMP, 'c.cmd')
    open(p, 'w').write(text)
    try:
        return K.parse_cmdfile(p)
    except SystemExit as e:
        return 'DIE ' + str(e)


GOOD = 'ABSROOT\nRUN /bin/cc -c @ABS/driverkit/KernLock.m -o stage/F__KernLock.o\nEXPECT F__KernLock.o\n'
r = parse(GOOD)
check('P1 ABSROOT parsed as a marker entry first', isinstance(r, tuple) and r[0][0] == ['ABSROOT'], r)
check('P2 plain RUN file unchanged', parse('RUN /bin/cc -c src/a.c -o stage/a.o\nEXPECT a.o\n') == ([['/bin/cc', '-c', 'src/a.c', '-o', 'stage/a.o']], ['a.o']))
check('N1 @ABS without ABSROOT', 'without ABSROOT' in str(parse(GOOD.replace('ABSROOT\n', ''))))
check('N2 ABSROOT twice', 'more than once' in str(parse('ABSROOT\n' + GOOD)))
check('N3 @ABS mid-word', 'bad @ABS' in str(parse(GOOD.replace('@ABS/driverkit', 'x@ABS/driverkit'))))
check('N4 @ABS twice in a word', 'bad @ABS' in str(parse(GOOD.replace('@ABS/driverkit', '@ABS/@ABS/driverkit'))))

# prepare against temporary RUNS / REGISTRY
old = (K.RUNS, K.REGISTRY, K.tool_hashes)
K.RUNS = os.path.join(TMP, 'runs'); os.makedirs(K.RUNS); K.REGISTRY = os.path.join(K.RUNS, 'REGISTRY')
K.tool_hashes = lambda: {t: dict(real='0' * 64, size=1) for t in K.ALLOWED_TOOLS}
src = os.path.join(TMP, 'stage'); os.makedirs(os.path.join(src, 'src', 'driverkit'))
open(os.path.join(src, 'src', 'driverkit', 'KernLock.m'), 'w').write('x\n')
cmd = os.path.join(TMP, 'run.cmd'); open(cmd, 'w').write(GOOD)
try:
    K.prepare('t-abs-1', src, cmd)
    rd = os.path.join(K.RUNS, 't-abs-1')
    sh = open(os.path.join(rd, 'run.sh')).read()
    exp = open(os.path.join(rd, 'input.expected')).read()
    check('P3 marker src/src/.krabs holds the run ID and is in input.expected',
          open(os.path.join(rd, 'src', 'src', '.krabs')).read() == 't-abs-1\n' and 'src/src/.krabs' in exp)
    check('P4 run.sh links ABSROOT after the input checks and verifies the marker',
          sh.index('cmp -s tools.actual') < sh.index('ln -s t-abs-1/src/src $A') < sh.index('ABSROOT marker'))
    check('P5 @ABS replaced by the absolute path in the command',
          '/bin/cc -c /BinarySourceCache_Mario1A/mk/mk-183.34.4/driverkit/KernLock.m -o stage/F__KernLock.o' in sh)
    check('P6 cleanup before LOCK release on success, in fail(), and a signal trap',
          sh.index('absclean\nsync\nrmdir') > 0 and 'fail() { echo "$1" > $R/FAILED; absclean;' in sh and "trap 'fail signal' 1 2 15" in sh)
    check('P7 a stale non-link ABSROOT is refused', 'ABSROOT is not a link' in sh)
    K.prepare('t-plain-1', src, os.path.join(TMP, 'p.cmd') if open(os.path.join(TMP, 'p.cmd'), 'w').write('RUN /bin/cc -c src/driverkit/KernLock.m -o stage/a.o\nEXPECT a.o\n') else None)
    sh2 = open(os.path.join(K.RUNS, 't-plain-1', 'run.sh')).read()
    check('P8 without ABSROOT: no link, no marker, no trap', 'ln -s' not in sh2 and '.krabs' not in sh2 and 'trap' not in sh2
          and not os.path.exists(os.path.join(K.RUNS, 't-plain-1', 'src', 'src', '.krabs')))
finally:
    K.RUNS, K.REGISTRY, K.tool_hashes = old
shutil.rmtree(TMP)
fails = [x for x in results if not x[1]]
for name, ok, info in results:
    print('%-4s %s %s' % ('ok' if ok else 'FAIL', name, '' if ok else info))
print('%d tests, %d failed' % (len(results), len(fails)))
sys.exit(1 if fails else 0)
