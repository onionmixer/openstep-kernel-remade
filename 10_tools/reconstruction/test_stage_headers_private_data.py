#!/usr/bin/env python3
"""Tests for the stage_headers PRIVATE_DATA rule (plan 395): under --bsd-set the authored
kernel-private data file 07_kernel/nextdev_private/bsd/dev/i386/PCKeymap.c is read for the
logical src/bsd/dev/i386/PCKeymap.c (#imported by EventSrcPCKeyboard.m) instead of Darwin,
unless --prefer-07 finds the same logical file in 07_kernel/src; other files keep their
selection.  Real stages go to a temporary directory; nothing in the repository is written."""
import hashlib, json, os, shutil, subprocess, sys, tempfile
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import stage_headers as S

REPO = os.path.dirname(os.path.dirname(HERE))
TOOL = os.path.join(HERE, 'stage_headers.py')
TMP = tempfile.mkdtemp(prefix='private-data-test-')
LG = os.path.join('src', 'bsd', 'dev', 'i386', 'PCKeymap.c')
PRIV = os.path.join(S.PRIVATE, 'bsd', 'dev', 'i386', 'PCKeymap.c')
DARWIN = S.darwin_of(LG)
results = []


def check(name, ok, info=None):
    results.append((name, bool(ok), info))


def sha(f):
    return hashlib.sha256(open(f, 'rb').read()).hexdigest()


def stage(name, opts, srcs):
    st = os.path.join(TMP, name)
    r = subprocess.run(['python3', TOOL] + opts + [st] + srcs, capture_output=True, text=True, cwd=REPO)
    man = json.load(open(st + '.manifest.json')) if os.path.exists(st + '.manifest.json') else None
    return r, st, man


FULL = ['--prefer-07', '--nextdev', '--bsd-set', 'nextos', '--mach-set', 'sdk']
try:
    check('a0 the private copy and the Darwin file exist and differ',
          os.path.isfile(PRIV) and DARWIN and os.path.isfile(DARWIN) and sha(PRIV) != sha(DARWIN))
    # selection, component level
    S.BSDSET['on'] = True
    try:
        check('a1 --bsd-set, prefer07: PCKeymap.c -> private copy',
              os.path.normpath(S.select(LG, True) or '') == os.path.normpath(PRIV), S.select(LG, True))
        check('a2 --bsd-set, no prefer07: PCKeymap.c -> private copy',
              os.path.normpath(S.select(LG, False) or '') == os.path.normpath(PRIV), S.select(LG, False))
        other = os.path.join('src', 'bsd', 'dev', 'i386', 'kbd_entries.c')
        check('b1 other non-header src/bsd file unchanged by the rule', S.private_data(other, True) is None)
        h = os.path.join('src', 'bsd', 'dev', 'i386', 'PCKeyboardDefs.h')
        check('b2 headers still routed by bsd_pick (private_data None)', S.private_data(h, True) is None)
        check('b3 generated/ unaffected', S.private_data(os.path.join('generated', 'PCKeymap.c'), True) is None)
        # a 07_kernel/src copy wins with prefer07
        k = os.path.join(TMP, 'k07')
        os.makedirs(os.path.join(k, os.path.dirname(LG)))
        shutil.copyfile(DARWIN, os.path.join(k, LG))
        old = S.K07
        S.K07 = k
        try:
            check('c1 prefer07 with a 07_kernel/src copy -> no private choice', S.private_data(LG, True) is None)
            check('c2 without prefer07 the 07_kernel/src copy is not considered', S.private_data(LG, False) is not None)
        finally:
            S.K07 = old
        # a missing private file -> no choice
        oldp = S.PRIVATE
        S.PRIVATE = os.path.join(TMP, 'noprivate')
        try:
            check('d1 missing private copy -> None', S.private_data(LG, True) is None)
        finally:
            S.PRIVATE = oldp
        # symbolic link in the private path is refused
        pl = os.path.join(TMP, 'privlink')
        os.makedirs(os.path.join(pl, 'bsd', 'dev'))
        os.symlink(os.path.dirname(PRIV), os.path.join(pl, 'bsd', 'dev', 'i386'))
        S.PRIVATE = pl
        try:
            try:
                S.private_data(LG, True)
                check('e1 a symlinked private directory is refused', False)
            except SystemExit:
                check('e1 a symlinked private directory is refused', True)
        finally:
            S.PRIVATE = oldp
    finally:
        S.BSDSET['on'] = False
    check('f1 without --bsd-set the rule is off', S.private_data(LG, True) is None)

    # real staging (temporary directory)
    r, st, man = stage('s1', FULL, ['bsd/dev/i386/EventSrcPCKeyboard.m'])
    f = os.path.join(st, LG)
    check('g1 staging succeeds', r.returncode == 0, r.stderr[-400:])
    check('g2 staged PCKeymap.c is the private copy', os.path.isfile(f) and sha(f) == sha(PRIV))
    rows = [x for x in (man or {}).get('files', []) if x[0] == LG]
    check('g3 manifest row: private origin, authored note, replaces Darwin',
          rows and rows[0][1].startswith('07_kernel/nextdev_private') and 'authored private data file' in json.dumps(rows)
          and 'replaces' in json.dumps(rows), rows)
    r2, st2, man2 = stage('s2', ['--prefer-07', '--nextdev'], ['bsd/dev/i386/EventSrcPCKeyboard.m'])
    f2 = os.path.join(st2, LG)
    check('h1 without --bsd-set staging keeps Darwin', r2.returncode == 0 and os.path.isfile(f2) and sha(f2) == sha(DARWIN),
          r2.stderr[-300:])
finally:
    shutil.rmtree(TMP)

fails = [x for x in results if not x[1]]
for name, ok, info in results:
    print('%-4s %s %s' % ('ok' if ok else 'FAIL', name, '' if ok else info))
print('%d tests, %d failed' % (len(results), len(fails)))
sys.exit(1 if fails else 0)
