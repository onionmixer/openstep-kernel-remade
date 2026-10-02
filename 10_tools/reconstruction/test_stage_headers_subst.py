#!/usr/bin/env python3
"""Focused tests for stage_headers.py --subst (plan 83.2).  Runs the tool on the real
trees; temporary maps and stages go to a temporary directory."""
import hashlib, json, os, subprocess, sys, tempfile
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import stage_headers as S

TOOL = os.path.join(HERE, 'stage_headers.py')
TMP = tempfile.mkdtemp(prefix='subst-test-')
PCB = 'machdep/i386/pcb.c'


def run(mapobj, *args, raw=None):
    mp = os.path.join(TMP, 'map%d.json' % len(os.listdir(TMP)))
    open(mp, 'w').write(raw if raw is not None else json.dumps(mapobj))
    r = subprocess.run(['python3', TOOL, '--subst', mp] + list(args), capture_output=True, text=True)
    return r.returncode, r.stdout, r.stderr


def fails(msg, mapobj, *args, raw=None):
    rc, out, err = run(mapobj, *args, raw=raw)
    return rc != 0 and msg in err


def listing(mapobj, *flags):
    rc, out, err = run(mapobj, *(flags + ('--nextdev', '--list', PCB)))
    assert rc == 0, err
    return out


def symlink_rejected():
    base = os.path.join(TMP, 'lnk')
    os.makedirs(os.path.join(base, 'real'))
    open(os.path.join(base, 'real', 'f.h'), 'w').write('x\n')
    os.symlink('real', os.path.join(base, 'via'))
    try:
        S._no_symlink(base, 'via/f.h')
    except SystemExit:
        S._no_symlink(base, 'real/f.h')
        return True
    return False


def stage_twice():
    """one source mapped to two names, plus a second-hop ARCH_INCLUDE mapping: staged bytes and manifest."""
    m = {'src/bsd/sys/proc.h': 'sdk:bsd/sys/proc.h', 'src/bsd/sys/proc_copy_test.h': 'sdk:bsd/sys/proc.h'}
    mp = os.path.join(TMP, 'stage-map.json')
    open(mp, 'w').write(json.dumps(m))
    st = os.path.join(TMP, 'stage')
    r = subprocess.run(['python3', TOOL, '--nextdev', '--subst', mp, st, PCB], capture_output=True, text=True)
    if r.returncode:
        return False
    sdk = open(os.path.join(S.NEXTDEV, 'bsd/sys/proc.h'), 'rb').read()
    man = json.load(open(st + '.manifest.json'))
    rows = {row[0]: row for row in man['files']}
    staged = open(os.path.join(st, 'src/bsd/sys/proc.h'), 'rb').read()
    # the second key is never included by pcb.c, so it must not be staged
    return (staged == sdk and 'src/bsd/sys/proc_copy_test.h' not in rows
            and rows['src/bsd/sys/proc.h'][3].startswith('substituted: real machine /NextDeveloper/Headers/bsd/sys/proc.h')
            and rows['src/bsd/sys/proc.h'][4].startswith('replaces darwin01/kernel/bsd/sys/proc.h')
            and man['subst']['map_sha256'] == hashlib.sha256(open(mp, 'rb').read()).hexdigest())


def arch_second_hop():
    """SDK machine/user.h uses ARCH_INCLUDE(bsd/, user.h): Darwin bsd/i386/user.h unless mapped too."""
    base = {'src/bsd/sys/proc.h': 'sdk:bsd/sys/proc.h', 'src/bsd/sys/user.h': 'sdk:bsd/sys/user.h',
            'src/bsd/machine/user.h': 'sdk:bsd/machine/user.h'}
    rc, out, err = run(base, '--nextdev', '--list', PCB)
    a = [l for l in out.split('\n') if l.startswith('src/bsd/i386/user.h ')]
    both = dict(base, **{'src/bsd/i386/user.h': 'sdk:bsd/i386/user.h'})
    rc2, out2, err2 = run(both, '--nextdev', '--list', PCB)
    b = [l for l in out2.split('\n') if l.startswith('src/bsd/i386/user.h ')]
    return rc == 0 and rc2 == 0, a, b


CASES = []


def case(name, fn):
    CASES.append((name, fn))


case('needs --nextdev', lambda: fails('needs --nextdev', {'src/bsd/sys/proc.h': 'sdk:bsd/sys/proc.h'}, '--list', PCB))
case('key outside src/bsd', lambda: fails('outside src/bsd', {'src/kern/x.h': 'sdk:bsd/sys/proc.h'}, '--nextdev', '--list', PCB))
case('key traversal', lambda: fails('not a clean', {'src/bsd/../kern/x.h': 'sdk:bsd/sys/proc.h'}, '--nextdev', '--list', PCB))
case('source traversal', lambda: fails('not a clean', {'src/bsd/sys/proc.h': 'nextmach:sys/../machine/user.h'}, '--nextdev', '--list', PCB))
case('absolute source', lambda: fails('not a clean', {'src/bsd/sys/proc.h': 'sdk:/etc/passwd'}, '--nextdev', '--list', PCB))
case('directory key', lambda: fails('directory in Darwin', {'src/bsd/sys': 'sdk:bsd/sys/proc.h'}, '--nextdev', '--list', PCB))
case('colliding keys', lambda: fails('collides', {'src/bsd/sysx': 'sdk:bsd/sys/proc.h', 'src/bsd/sysx/a.h': 'sdk:bsd/sys/proc.h'}, '--nextdev', '--list', PCB))
case('duplicate key', lambda: fails('duplicate key', None, '--nextdev', '--list', PCB,
                                    raw='{"src/bsd/sys/proc.h": "sdk:bsd/sys/proc.h", "src/bsd/sys/proc.h": "sdk:bsd/sys/user.h"}'))
case('bad scheme', lambda: fails('must start with', {'src/bsd/sys/proc.h': 'darwin:bsd/sys/proc.h'}, '--nextdev', '--list', PCB))
case('sdk name not in real-machine list', lambda: fails('real-machine list', {'src/bsd/sys/proc.h': 'sdk:bsd/sys/no_such.h'}, '--nextdev', '--list', PCB))
case('nextmach outside allowlist', lambda: fails('outside sys,', {'src/bsd/machine/user.h': 'nextmach:machine/user.h'}, '--nextdev', '--list', PCB))
case('nextmach missing file', lambda: fails('does not match', {'src/bsd/sys/proc.h': 'nextmach:sys/no_such.h'}, '--nextdev', '--list', PCB))
# plan 133: the only file left under 07_kernel/src/bsd is the BSD source libkern/strtol.c
case('07 copy shadows a key', lambda: fails('shadowed by 07_kernel', {'src/bsd/libkern/strtol.c': 'nextmach:sys/callout.h'}, '--prefer-07', '--nextdev', '--list', PCB))
case('same key accepted without --prefer-07', lambda: run({'src/bsd/libkern/strtol.c': 'nextmach:sys/callout.h'}, '--nextdev', '--list', PCB)[0] == 0)
case('symlink in a source path', symlink_rejected)
case('substituted proc.h read; its includes followed', lambda: (lambda o:
     ('src/bsd/sys/proc.h %s SUBST' % os.path.realpath(os.path.join(S.NEXTDEV, 'bsd/sys/proc.h'))) in o.split('\n'))(listing({'src/bsd/sys/proc.h': 'sdk:bsd/sys/proc.h'})))
case('nextmach proc.h accepted', lambda: ' SUBST' in listing({'src/bsd/sys/proc.h': 'nextmach:sys/proc.h'}))
case('stage bytes, manifest, unused key', stage_twice)


def main():
    bad = 0
    for name, fn in CASES:
        ok = bool(fn())
        bad += not ok
        print('%-4s %s' % ('ok' if ok else 'FAIL', name))
    ok, a, b = arch_second_hop()
    print('info ARCH second hop without/with mapping:', a, b)
    hop = ok and a and 'darwin01/kernel/bsd/i386/user.h' in a[0] and b and b[0].endswith('Headers/bsd/i386/user.h SUBST')
    bad += not hop
    print('%-4s %s' % ('ok' if hop else 'FAIL', 'ARCH_INCLUDE second hop'))
    print('%d tests, %d failed' % (len(CASES) + 1, bad))
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
