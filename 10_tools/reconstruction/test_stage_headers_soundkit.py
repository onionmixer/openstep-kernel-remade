#!/usr/bin/env python3
"""Tests for the stage_headers EXTRA_LIST entry (plan 342, D042): <SoundKit/NXSoundParameterTags.h>
is the real-machine /NextLibrary/Frameworks/SoundKit.framework header kept verbatim in
07_kernel/nextdev/SoundKit/.  Real stages go to a temporary directory; nothing in the
repository is written."""
import hashlib, json, os, shutil, subprocess, sys, tempfile
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import stage_headers as S

REPO = os.path.dirname(os.path.dirname(HERE))
TOOL = os.path.join(HERE, 'stage_headers.py')
TMP = tempfile.mkdtemp(prefix='soundkit-test-')
NAME = os.path.join('SoundKit', 'NXSoundParameterTags.h')
LG = os.path.join('nextdev', NAME)
C07 = os.path.join(S.K07, 'nextdev', NAME)
LIST = json.load(open(S.EXTRA_LIST))
results = []


def check(name, ok, info=None):
    results.append((name, bool(ok), info))


def sha(f):
    return hashlib.sha256(open(f, 'rb').read()).hexdigest()


def fails(fn):
    try:
        fn()
    except SystemExit as e:
        return str(e)
    return None


try:
    x = LIST['files'][0]
    check('a  list names the framework path and the 07 copy matches it',
          x['name'] == NAME and x['path'].startswith('/NextLibrary/Frameworks/SoundKit.framework/Headers/')
          and sha(C07) == x['sha256'] and os.path.getsize(C07) == x['size'], x)
    n = S.extra_real(LG, C07)
    check('b  extra_real note names the real-machine path, sha256 and D042',
          n and x['path'] in n and x['sha256'] in n and 'D042' in n, n)
    check('c  other nextdev names -> None', S.extra_real(os.path.join('nextdev', 'driverkit', 'IOAudio.h'),
                                                         os.path.join(S.NEXTDEV, 'driverkit', 'IOAudio.h')) is None)
    check('c2 non-nextdev logical -> None', S.extra_real(os.path.join('src', NAME), C07) is None)

    # component level: changed copy, file outside 07, symbolic link
    old = S.K07
    k = os.path.join(TMP, 'k07', 'nextdev', 'SoundKit')
    os.makedirs(k)
    S.K07 = os.path.join(TMP, 'k07')
    try:
        bad = os.path.join(k, 'NXSoundParameterTags.h')
        open(bad, 'wb').write(open(C07, 'rb').read() + b'/* changed */\n')
        check('d  a changed 07 copy fails', fails(lambda: S.extra_real(LG, bad)))
        os.remove(bad)
        real = os.path.join(TMP, 'real.h')
        shutil.copyfile(C07, real)
        check('e  a file that is not the 07 copy fails', fails(lambda: S.extra_real(LG, real)))
        os.symlink(real, bad)
        check('f  a symbolic link in place of the 07 copy fails', fails(lambda: S.extra_real(LG, bad)))
        os.remove(bad)
        os.rmdir(k)
        os.symlink(os.path.dirname(real), k)
        check('f2 a symbolic-link directory on the path fails',
              fails(lambda: S.extra_real(LG, os.path.join(k, 'NXSoundParameterTags.h'))))
    finally:
        S.K07 = old

    # real staging (temporary directory): snd_server.m imports <SoundKit/NXSoundParameterTags.h>
    st = os.path.join(TMP, 's1')
    r = subprocess.run(['python3', TOOL, '--prefer-07', '--nextdev', '--bsd-set', 'nextos', '--mach-set', 'sdk',
                        '--public-sdk', 'kernserv/queue.h', st, 'driverkit/libDriver/Kernel/snd_server.m'],
                       capture_output=True, text=True, cwd=REPO)
    check('g1 staging succeeds', r.returncode == 0, r.stderr[-400:])
    man = json.load(open(st + '.manifest.json')) if os.path.exists(st + '.manifest.json') else {}
    rows = [y for y in man.get('files', []) if y[0] == LG]
    check('g2 one manifest row for the SoundKit header, from 07, with the D042 note',
          len(rows) == 1 and rows[0][1] == os.path.join('07_kernel', LG) and rows[0][2] == x['sha256']
          and any('D042' in z and x['path'] in z for z in rows[0][3:]), rows)
    check('g3 no "differs from the real machine" or "sha256 None" on that row',
          rows and not any('differs from the real machine' in z or 'sha256 None' in z for z in rows[0][3:]), rows)
    f = os.path.join(st, LG)
    check('g4 staged file is the real-machine file', os.path.isfile(f) and sha(f) == x['sha256'])
    other = [y for y in man.get('files', []) if y[0].startswith('nextdev' + os.sep) and y[0] != LG]
    check('h  other nextdev rows keep the /NextDeveloper/Headers note',
          other and all(any(z.startswith('real machine /NextDeveloper/Headers/') for z in y[3:]) for y in other),
          [y for y in other if not any(z.startswith('real machine /NextDeveloper/Headers/') for z in y[3:])][:3])
finally:
    shutil.rmtree(TMP)

bad = [x for x in results if not x[1]]
for name, ok, info in results:
    print('%-4s %s %s' % ('ok' if ok else 'FAIL', name, '' if ok else info))
print('%d tests, %d failed' % (len(results), len(bad)))
sys.exit(1 if bad else 0)
