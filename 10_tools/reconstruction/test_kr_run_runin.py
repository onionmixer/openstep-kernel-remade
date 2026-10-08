#!/usr/bin/env python3
"""Tests for the kr_run RUNIN directive (plan 297, D031): parse_cmdfile accepts a run in a
src/ subdirectory with @R/ (or -I@R/) prefixed arguments and rejects anything else.
Plan 361.1: also a run in stage/<name> (made by run.sh after stage/_log), checked here by
parse cases and by prepare against a temporary RUNS/REGISTRY (as test_kr_run_absroot.py)."""
import os, sys, tempfile, shutil
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import kr_run as K

TMP = tempfile.mkdtemp(prefix='krrunin-')


def parse(text):
    p = os.path.join(TMP, 'c.cmd')
    open(p, 'w').write(text)
    try:
        return K.parse_cmdfile(p)
    except SystemExit as e:
        return 'DIE ' + str(e)


GOOD = ('RUNIN src/src/driverkit/libDriver /bin/cc -c -O3 -I@R/src/src -imacros @R/src/generated/m.h '
        'Kernel/NXSpinLock.m -o @R/stage/F__NXSpinLock.o\nEXPECT F__NXSpinLock.o\n')
CASES = [
    ('good', GOOD, lambda r: isinstance(r, tuple) and r[0][0][:3] == ['RUNIN', 'src/src/driverkit/libDriver', '/bin/cc']),
    ('run unchanged', 'RUN /bin/cc -c src/a.c -o stage/a.o\nEXPECT a.o\n',
     lambda r: isinstance(r, tuple) and r[0] == [['/bin/cc', '-c', 'src/a.c', '-o', 'stage/a.o']]),
    ('dotdot dir', GOOD.replace('src/src/driverkit/libDriver', 'src/../x'), lambda r: 'bad RUNIN directory' in str(r)),
    ('absolute dir', GOOD.replace('src/src/driverkit/libDriver', '/tmp'), lambda r: 'bad RUNIN directory' in str(r)),
    ('dir outside src', GOOD.replace('src/src/driverkit/libDriver', 'stage'), lambda r: 'bad RUNIN directory' in str(r)),
    ('@R mid-word', GOOD.replace('-I@R/src/src', '-Ix@R/src'), lambda r: 'bad @R use' in str(r)),
    ('@R twice', GOOD.replace('-I@R/src/src', '-I@R/@R/src'), lambda r: 'bad @R use' in str(r)),
    ('tool not allowed', GOOD.replace('/bin/cc', '/bin/sh'), lambda r: 'not allowed' in str(r)),
    ('shell metachar', GOOD.replace('-O3', '-O3;rm'), lambda r: 'bad argument' in str(r)),
    ('dotdot arg', GOOD.replace('Kernel/NXSpinLock.m', '../x.m'), lambda r: '".."' in str(r)),
]
MIG = 'RUNIN stage/migi /usr/bin/mig -DKERNEL -header mach_interface.h -i -server /dev/null @R/src/nextdev/mach/mach.defs\n'
CASES += [   # plan 361.1
    ('stage dir', MIG + 'EXPECT migi/port_allocate.c\n', lambda r: isinstance(r, tuple) and r[0][0][:2] == ['RUNIN', 'stage/migi']),
    ('stage dir repeated', MIG + MIG + 'EXPECT migi/x.c\n', lambda r: isinstance(r, tuple) and len(r[0]) == 2),
    ('stage dirs mixed with src RUNIN and RUN', MIG + MIG.replace('stage/migi', 'stage/migi_r') + GOOD + 'RUN /bin/cc -c src/a.c -o stage/a.o\n',
     lambda r: isinstance(r, tuple) and [c[1] for c in r[0][:3]] == ['stage/migi', 'stage/migi_r', 'src/src/driverkit/libDriver']),
    ('stage _log', MIG.replace('stage/migi', 'stage/_log') + 'EXPECT a\n', lambda r: 'bad RUNIN directory' in str(r)),
    ('stage _LOG', MIG.replace('stage/migi', 'stage/_LOG') + 'EXPECT a\n', lambda r: 'bad RUNIN directory' in str(r)),
    ('stage case collision', MIG + MIG.replace('stage/migi', 'stage/MIGI') + 'EXPECT a\n', lambda r: 'collides' in str(r)),
    ('stage two levels', MIG.replace('stage/migi', 'stage/a/b') + 'EXPECT a\n', lambda r: 'bad RUNIN directory' in str(r)),
    ('stage empty name', MIG.replace('stage/migi', 'stage/') + 'EXPECT a\n', lambda r: 'bad RUNIN directory' in str(r)),
    ('stage trailing slash', MIG.replace('stage/migi', 'stage/migi/') + 'EXPECT a\n', lambda r: 'bad RUNIN directory' in str(r)),
    ('stage double slash', MIG.replace('stage/migi', 'stage//migi') + 'EXPECT a\n', lambda r: 'bad RUNIN directory' in str(r)),
    ('stage dot', MIG.replace('stage/migi', 'stage/.') + 'EXPECT a\n', lambda r: 'bad RUNIN directory' in str(r)),
    ('stage dotdot', MIG.replace('stage/migi', 'stage/..') + 'EXPECT a\n', lambda r: 'bad RUNIN directory' in str(r)),
    ('stage punctuation', MIG.replace('stage/migi', 'stage/mi-gi') + 'EXPECT a\n', lambda r: 'bad RUNIN directory' in str(r)),
    ('stage @R', MIG.replace('stage/migi', 'stage/@R') + 'EXPECT a\n', lambda r: 'bad RUNIN directory' in str(r)),
    ('stage itself', MIG.replace('stage/migi', 'stage') + 'EXPECT a\n', lambda r: 'bad RUNIN directory' in str(r)),
]
fails = 0
for name, text, ok in CASES:
    r = parse(text)
    good = ok(r)
    fails += not good
    print('ok  ' if good else 'FAIL', name, '' if good else r)
# plan 361.1: prepare against a temporary RUNS / REGISTRY (stubbed tool hashes)
PRE = []
old = (K.RUNS, K.REGISTRY, K.tool_hashes)
K.RUNS = os.path.join(TMP, 'runs'); os.makedirs(K.RUNS); K.REGISTRY = os.path.join(K.RUNS, 'REGISTRY')
K.tool_hashes = lambda: {t: dict(real='0' * 64, size=1) for t in K.ALLOWED_TOOLS}
src = os.path.join(TMP, 'srcfix'); os.makedirs(os.path.join(src, 'src', 'driverkit', 'libDriver'))
open(os.path.join(src, 'src', 'driverkit', 'libDriver', 'a.m'), 'w').write('x\n')
def prep(rid, text):
    c = os.path.join(TMP, rid + '.cmd'); open(c, 'w').write(text)
    try:
        K.prepare(rid, src, c)
    except SystemExit as e:
        return ('DIE', str(e))   # not a str: the run.sh checks below then fail
    return open(os.path.join(K.RUNS, rid, 'run.sh')).read()
try:
    sh = prep('t-stage-1', MIG + MIG + MIG.replace('stage/migi', 'stage/migi_r') + GOOD)
    exp = open(os.path.join(K.RUNS, 't-stage-1', 'input.expected')).read() if isinstance(sh, str) else ''
    PRE.append(('prepare: stage dirs need not exist on the host', isinstance(sh, str) and not os.path.exists(os.path.join(K.RUNS, 't-stage-1', 'stage'))))
    PRE.append(('prepare: one mkdir per stage dir, after stage/_log, before status and commands',
                isinstance(sh, str) and sh.count('mkdir stage/migi ||') == 1 and sh.count('mkdir stage/migi_r ||') == 1
                and sh.index('mkdir stage stage/_log') < sh.index('mkdir stage/migi ||') < sh.index('mkdir stage/migi_r ||') < sh.index(': > stage/_log/status') < sh.index('(cd stage/migi &&')))
    PRE.append(('prepare: mkdir failure calls fail', isinstance(sh, str) and 'mkdir stage/migi || fail "mkdir stage/migi"' in sh))
    PRE.append(('prepare: (cd stage/migi && ...) with @R made absolute, logs relative to the run dir',
                isinstance(sh, str) and '(cd stage/migi && /usr/bin/mig -DKERNEL -header mach_interface.h -i -server /dev/null $R/src/nextdev/mach/mach.defs) > stage/_log/00.out 2> stage/_log/00.err' in sh))
    PRE.append(('prepare: run.sh is input-hashed', ' run.sh' in exp and ' run.cmd' in exp))
    r = prep('t-stage-2', MIG + GOOD.replace('src/src/driverkit/libDriver', 'src/src/missing'))
    PRE.append(('prepare: a missing src RUNIN directory still fails', 'not in SRC' in str(r)))
    sh3 = prep('t-stage-3', 'ABSROOT\n' + MIG + 'RUN /bin/cc -c @ABS/driverkit/a.m -o stage/a.o\nEXPECT a.o\n')
    os.makedirs(os.path.join(src, 'src', 'src'), exist_ok=True)
    sh3 = prep('t-stage-4', 'ABSROOT\n' + MIG + 'RUN /bin/cc -c @ABS/driverkit/a.m -o stage/a.o\nEXPECT a.o\n')
    PRE.append(('prepare: with ABSROOT the stage dir is made and the link set up',
                isinstance(sh3, str) and 'mkdir stage/migi ||' in sh3 and 'ln -s t-stage-4/src/src $A' in sh3))
finally:
    K.RUNS, K.REGISTRY, K.tool_hashes = old
shutil.rmtree(TMP)
for name, good in PRE:
    fails += not good
    print('ok  ' if good else 'FAIL', name)
print('%d tests, %d failed' % (len(CASES) + len(PRE), fails))
sys.exit(1 if fails else 0)
