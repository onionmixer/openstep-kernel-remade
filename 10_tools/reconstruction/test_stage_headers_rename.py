#!/usr/bin/env python3
"""Tests for the stage_headers NEXTMACH_RENAME entry (plan 335, D039): <dev/busvar.h> is
taken from NeXTMach mk-108.1/nextdev/busvar.h (07 copy 07_kernel/nextmach/nextdev/busvar.h).
Real stages go to a temporary directory; nothing in the repository is written."""
import hashlib, json, os, shutil, subprocess, sys, tempfile
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import stage_headers as S

REPO = os.path.dirname(os.path.dirname(HERE))
TOOL = os.path.join(HERE, 'stage_headers.py')
TMP = tempfile.mkdtemp(prefix='rename-test-')
NM = os.path.join(S.NEXTMACH, 'nextdev', 'busvar.h')
C07 = os.path.join(S.K07, 'nextmach', 'nextdev', 'busvar.h')
results = []


def check(name, ok, info=None):
    results.append((name, bool(ok), info))


def sha(f):
    return hashlib.sha256(open(f, 'rb').read()).hexdigest()


def stage(name):
    st = os.path.join(TMP, name)
    r = subprocess.run(['python3', TOOL, '--prefer-07', '--nextdev', '--bsd-set', 'nextos', '--mach-set', 'sdk',
                        st, 'driverkit/autoconfCommon.m'], capture_output=True, text=True, cwd=REPO)
    man = json.load(open(st + '.manifest.json')) if os.path.exists(st + '.manifest.json') else None
    return r, st, man


try:
    # selection
    h = S.bsd_pick(os.path.join('dev', 'busvar.h'))
    check('a  dev/busvar.h -> NeXTMach nextdev/busvar.h (kind nextmach)',
          h and h[1] == 'nextmach' and h[2] == os.path.join('nextdev', 'busvar.h')
          and os.path.realpath(h[0]) == os.path.realpath(NM), h)
    h = S.bsd_pick(os.path.join('dev', 'busvar.h'), True)
    check('b  prefer07 with the 07 copy -> nextmach07', os.path.isfile(C07) and h and h[1] == 'nextmach07'
          and os.path.realpath(h[0]) == os.path.realpath(C07), h)
    check('c1 other dev names unchanged: dev/nosuch.h -> None', S.bsd_pick(os.path.join('dev', 'nosuch.h'), True) is None)
    NM2 = os.path.join(S.NEXTMACH, 'nextdev', 'ohlfs12.h')
    h = S.bsd_pick(os.path.join('dev', 'i386', 'ohlfs12.h'))
    check('a2 dev/i386/ohlfs12.h -> NeXTMach nextdev/ohlfs12.h (plan 338)',
          h and h[1] == 'nextmach' and h[2] == os.path.join('nextdev', 'ohlfs12.h')
          and os.path.realpath(h[0]) == os.path.realpath(NM2), h)
    h = S.bsd_pick(os.path.join('dev', 'i386', 'ohlfs12.h'), True)
    check('b2 prefer07 with the 07 copy -> nextmach07 (plan 338)', h and h[1] == 'nextmach07', h)
    h = S.bsd_pick(os.path.join('dev', 'm68k', 'autoconf.h'), True)
    check('c2 dev/m68k/autoconf.h still sdk07', h and h[1] == 'sdk07', h)

    # real staging (temporary directory)
    r, st, man = stage('s1')
    f = os.path.join(st, 'src', 'bsd', 'dev', 'busvar.h')
    check('d1 staging succeeds', r.returncode == 0, r.stderr[-400:])
    check('d2 staged src/bsd/dev/busvar.h is the NeXTMach file', os.path.isfile(f) and sha(f) == sha(NM))
    rows = [x for x in (man or {}).get('files', []) if os.path.join('bsd', 'dev', 'busvar.h') in str(x[0])]
    check('d3 manifest row names the pinned NeXTMach commit', rows and S.NEXTMACH_COMMIT in json.dumps(rows), rows)
    check('f1 07 copy present: not in bsd_not_adopted',
          man is not None and not any('busvar' in x for x in man.get('bsd_not_adopted', [])), (man or {}).get('bsd_not_adopted'))

    # component level: a mismatching 07 copy is found by bsd_pick and differs from the verified blob
    k = os.path.join(TMP, 'k07', 'nextmach', 'nextdev')
    os.makedirs(k)
    open(os.path.join(k, 'busvar.h'), 'wb').write(open(NM, 'rb').read() + b'/* changed */\n')
    old = S.K07
    S.K07 = os.path.join(TMP, 'k07')
    try:
        h = S.bsd_pick(os.path.join('dev', 'busvar.h'), True)
        nf, note = S.verify_nextmach(h[2])
        check('e  a changed 07 copy is selected and fails the blob comparison used by staging',
              h[1] == 'nextmach07' and sha(h[0]) != sha(nf), h)
        os.remove(os.path.join(k, 'busvar.h'))
        h = S.bsd_pick(os.path.join('dev', 'busvar.h'), True)
        check('f2 without a 07 copy prefer07 falls back to kind nextmach (listed as not adopted by staging)',
              h and h[1] == 'nextmach', h)
    finally:
        S.K07 = old
finally:
    shutil.rmtree(TMP)

fails = [x for x in results if not x[1]]
for name, ok, info in results:
    print('%-4s %s %s' % ('ok' if ok else 'FAIL', name, '' if ok else info))
print('%d tests, %d failed' % (len(results), len(fails)))
sys.exit(1 if fails else 0)
