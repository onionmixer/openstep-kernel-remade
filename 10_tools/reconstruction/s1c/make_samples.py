#!/usr/bin/env python3
"""Build the S1-C sample sources and the option-matrix command file
(plan sections 13 and 13.1).

  make_samples.py OUTDIR      writes OUTDIR/src/*.c, OUTDIR/provenance.json,
                              OUTDIR/matrix.cmd (refuses an existing OUTDIR)

Function definitions are cut verbatim from Darwin 0.1 (APSL) by line range:
from the definition line (plus a preceding return-type-only line) to the
first line that is exactly "}".  Only typedefs/structs/includes/macro blocks
listed in ADDED are prepended.  NeXTMach text is never used (D013).
"""
import hashlib, json, os, re, sys

REPO = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', '..'))
UP = os.path.join(REPO, '01_resources', 'upstream', 'darwin01', 'kernel')

# (output file, family, reference path under darwin01/kernel, [functions in order], prelude, header mode)
SAMPLES = [
    ('yeartoday', 'rtc', 'bsd/dev/i386/rtc.c', ['yeartoday'], '', 'nostdinc'),
    ('hexdectodec', 'rtc', 'bsd/dev/i386/rtc.c', ['hexdectodec'], '', 'nostdinc'),
    ('dectohexdec', 'rtc', 'bsd/dev/i386/rtc.c', ['dectohexdec'], '', 'nostdinc'),
    ('locc', 'libkern', 'bsd/libkern/locc.c', ['locc'],
     'typedef unsigned char u_char;\ntypedef unsigned int u_int;\n', 'nostdinc'),
    ('skpc', 'libkern', 'bsd/libkern/skpc.c', ['skpc'],
     'typedef unsigned char u_char;\n', 'nostdinc'),
    ('strcpy', 'libc', 'machdep/i386/libc/strcpy.c', ['strcpy'], '', 'nostdinc'),
    ('strcmp', 'libc', 'machdep/i386/libc/strcmp.c', ['strcmp'], '', 'nostdinc'),
    ('timevaladd', 'kern_time', 'bsd/kern/kern_time.c', ['timevaladd'],
     'struct timeval { long tv_sec; long tv_usec; };\n', 'nostdinc'),
    ('timevalsub', 'kern_time', 'bsd/kern/kern_time.c', ['timevalsub'],
     'struct timeval { long tv_sec; long tv_usec; };\n', 'nostdinc'),
    ('timevalfix', 'kern_time', 'bsd/kern/kern_time.c', ['timevalfix'],
     'struct timeval { long tv_sec; long tv_usec; };\n', 'nostdinc'),
    ('kern_time_group', 'kern_time', 'bsd/kern/kern_time.c', ['timevaladd', 'timevalsub', 'timevalfix'],
     'struct timeval { long tv_sec; long tv_usec; };\n', 'nostdinc'),
    ('byte_swap_shorts', 'ufs', 'bsd/ufs/ufs/ufs_byte_order.c', ['byte_swap_shorts'], 'BYTEORDER', 'system'),
    ('byte_swap_ints', 'ufs', 'bsd/ufs/ufs/ufs_byte_order.c', ['byte_swap_ints'], 'BYTEORDER', 'system'),
]

BASE = '-arch i386 -static -fno-common -fwritable-strings -traditional-cpp'
SETS = [('s00', '')]
_n = 1
for opt in ('-O', '-O2', '-O3', '-O4'):
    for fp in ('', '-fomit-frame-pointer'):
        for m in ('', '-mno-486'):
            SETS.append(('s%02d' % _n, ' '.join(x for x in (opt, fp, m) if x)))
            _n += 1
for extra in ('-O4 -funroll-all-loops', '-O4 -funroll-all-loops -fomit-frame-pointer'):
    SETS.append(('s%02d' % _n, extra))
    _n += 1


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def cut(lines, name):
    """Line range [a, b] (0-based, inclusive) of the definition of name."""
    starts = [i for i, l in enumerate(lines) if re.match(r'^%s\s*\(' % re.escape(name), l)]
    if len(starts) != 1:
        raise SystemExit('%s: %d definition lines' % (name, len(starts)))
    a = starts[0]
    prev = lines[a - 1].strip() if a > 0 else ''
    if prev and not prev.endswith((';', '}', '*/', '{')) and not prev.startswith(('#', '/*', '*')):
        a -= 1                                     # return type on its own line
    b = next(i for i in range(starts[0], len(lines)) if lines[i].rstrip() == '}')
    return a, b


def byteorder_prelude(lines):
    a = next(i for i, l in enumerate(lines) if l.startswith('#if 0'))
    b = next(i for i in range(a, len(lines)) if l_is_endif(lines[i]))
    return '#include <architecture/byte_order.h>\n' + ''.join(lines[a:b + 1]), (a + 1, b + 1)


def l_is_endif(l):
    return l.startswith('#endif')


def main():
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    out = sys.argv[1]
    if os.path.exists(out):
        sys.exit('refusing: %s exists' % out)
    os.makedirs(os.path.join(out, 'src'))
    prov = dict(reference_tree='01_resources/upstream/darwin01/kernel', license='APSL (Darwin 0.1)',
                base_flags=BASE, sets=dict(SETS), samples=[])
    for fname, fam, rel, funcs, prelude, mode in SAMPLES:
        path = os.path.join(UP, rel)
        lines = open(path, errors='replace').read().splitlines(True)
        ranges, body = [], ''
        if len(funcs) > 1:                          # grouped: one contiguous span in file order
            a = cut(lines, funcs[0])[0]
            b = cut(lines, funcs[-1])[1]
            body = ''.join(lines[a:b + 1])
            ranges.append([a + 1, b + 1])
        else:
            a, b = cut(lines, funcs[0])
            body = ''.join(lines[a:b + 1])
            ranges.append([a + 1, b + 1])
        added = prelude
        macro_lines = None
        if prelude == 'BYTEORDER':
            added, macro_lines = byteorder_prelude(lines)
        header = ('/* S1-C sample %s -- cut verbatim from darwin01/kernel/%s lines %s\n'
                  ' * (SHA-256 %s, APSL; candidate text, not a fact about the original).\n'
                  ' * Prepended below the separator: %s */\n') % (
                      fname, rel, ', '.join('%d-%d' % tuple(r) for r in ranges), sha(path),
                      ('lines %d-%d of the same file' % macro_lines) if macro_lines else repr(prelude))
        text = header + added + '/* ---- verbatim ---- */\n' + body
        open(os.path.join(out, 'src', fname + '.c'), 'w').write(text)
        prov['samples'].append(dict(file='src/%s.c' % fname, family=fam, reference=rel,
                                    reference_sha256=sha(path), functions=funcs, lines=ranges,
                                    prelude=added, headers=mode))
    json.dump(prov, open(os.path.join(out, 'provenance.json'), 'w'), indent=1)
    L = ['# S1-C option matrix: %d sets x %d sample files (plan 13/13.1)' % (len(SETS), len(SAMPLES))]
    exp = []
    for sid, flags in SETS:
        for fname, fam, rel, funcs, prelude, mode in SAMPLES:
            inc = '-nostdinc' if mode == 'nostdinc' else ''
            o = 'stage/%s__%s.o' % (sid, fname)
            L.append(' '.join(x for x in ('RUN /bin/cc', BASE, flags, inc, '-c src/%s.c -o %s' % (fname, o)) if x))
            exp.append('EXPECT %s__%s.o' % (sid, fname))
    for fname, fam, rel, funcs, prelude, mode in SAMPLES:
        inc = '-nostdinc' if mode == 'nostdinc' else ''
        L.append(' '.join(x for x in ('RUN /bin/cc', BASE, '-O2', inc, '-E src/%s.c -o stage/E__%s.i' % (fname, fname)) if x))
        exp.append('EXPECT E__%s.i' % fname)
    open(os.path.join(out, 'matrix.cmd'), 'w').write('\n'.join(L + exp) + '\n')
    print('wrote %d samples, %d sets, %d compile lines' % (len(SAMPLES), len(SETS), len(SETS) * len(SAMPLES)))


if __name__ == '__main__':
    main()
