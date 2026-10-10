#!/usr/bin/env python3
"""m5_m68k_ns.py -- plan 448 (M5-5): m68k ns_div / ns_div_val (68020 divull/divul) for
kern/ns_timer.c; assembler-syntax variants and per-span comparison with the original.

  python3 10_tools/reconstruction/m5_m68k_ns.py stage STAGE_DIR
  python3 10_tools/reconstruction/m5_m68k_ns.py cmd CC.cmd
  python3 10_tools/reconstruction/m5_m68k_ns.py compare RUN_ID PREFIX RECORD.json

stage    m0p447-a1-stage copy (manifest-checked) + src/kern/p448_<V>.c: the 07 main file with the
         i386 ns_div / ns_div_val replaced by the m68k forms (V1 colon "Dr:Dq", V2 comma "Dr,Dq").
cmd      the plan 430 cc1 compile line of kern/ns_timer.c (it failed there; same flags as cc.cmd)
         with source/output replaced (P448__<V>.o).
compare  for each object with PREFIX: L1 verdict, every external __text span (relocations
         masked; m0_m68k_cause.compare_object) and undefined symbols not in the original.
"""
import sys, os, json, shutil, hashlib, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

BASE = '08_build/runs/tools/m0p447-a1-stage'
CC = '08_build/artifacts/m3p430/cc.cmd'
REL = 'kern/ns_timer.c'
SEP = {'V1': ':', 'V2': ','}
# plan 448 diagnosis (second run): input-operand order variants, colon syntax.  A = divisor first
# (V1); B = divisor, rem, value; C = value, rem, divisor (NeXT gcc-2.7.2 longlong.h:436-441
# udiv_qrnnd); D = rem, value, divisor.
ORDER = {'V3': 'B', 'V4': 'C', 'V5': 'D'}


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def m68k_funcs(sep):
    div = ('static inline void\nns_div(ll, divisor, remain)\n\tns_time_t\t*ll;\n\tunsigned int\tdivisor;\n'
           '\tunsigned int\t*remain;\n{\n\tunsigned int\t*msw, *lsw;\n\tunsigned int\tquo, rem;\n\n'
           '\tmsw = &((unsigned int *)ll)[0];\n\tlsw = &((unsigned int *)ll)[1];\n\n'
           '\tasm("divull %%2,%%1%s%%0"\n\t    : "=d" (quo), "=d" (rem)\n\t    : "dmi" (divisor), "0" (*msw), "1" (0));\n'
           '\t*msw = quo;\n'
           '\tasm("divul %%2,%%1%s%%0"\n\t    : "=d" (quo), "=d" (*remain)\n\t    : "dmi" (divisor), "0" (*lsw), "1" (rem));\n'
           '\t*lsw = quo;\n}\n') % (sep, sep)
    val = ('static inline unsigned int\nns_div_val(ll, divisor)\n\tns_time_t\tll;\n\tunsigned int\tdivisor;\n{\n'
           '\tunsigned int\t*msw, *lsw;\n\tunsigned int\tquo, rem;\n\n'
           '\tmsw = &((unsigned int *)&ll)[0];\n\tlsw = &((unsigned int *)&ll)[1];\n\n'
           '\tasm("divull %%2,%%1%s%%0"\n\t    : "=d" (quo), "=d" (rem)\n\t    : "dmi" (divisor), "0" (*msw), "1" (0));\n'
           '\t*msw = quo;\n'
           '\tasm("divul %%2,%%1%s%%0"\n\t    : "=d" (quo), "=d" (rem)\n\t    : "dmi" (divisor), "0" (*lsw), "1" (rem));\n'
           '\treturn (quo);\n}\n') % (sep, sep)
    return div, val


def i386_funcs(text):
    """the two i386 function texts of the 07 main file (from 'static inline' to the closing brace)."""
    out = []
    for name in ('ns_div(', 'ns_div_val('):
        i = text.index('\n' + name)
        s = text.rindex('static inline', 0, i)
        e = text.index('\n}\n', i) + 3
        out.append(text[s:e])
    return out


def reorder(text, order):
    """rewrite the m68k asm input lists of m68k_funcs(':') into ORDER form B/C/D."""
    import re
    def fix(m):
        mn, outs, d, val, rem = m.group(1), m.group(2), m.group(3), m.group(4), m.group(5)
        if order == 'B':
            ins, k = '"dmi" (%s), "1" (%s), "0" (%s)' % (d, rem, val), 2
        elif order == 'C':
            ins, k = '"0" (%s), "1" (%s), "dmi" (%s)' % (val, rem, d), 4
        else:
            ins, k = '"1" (%s), "0" (%s), "dmi" (%s)' % (rem, val, d), 4
        return 'asm("%s %%%d,%%1:%%0"\n\t    : %s\n\t    : %s);' % (mn, k, outs, ins)
    pat = re.compile(r'asm\("(divull|divul) %2,%1:%0"\n\t    : (.*?)\n\t    : "dmi" \((.*?)\), "0" \((.*?)\), "1" \((.*?)\)\);')
    new, n = pat.subn(fix, text)
    assert n == 2, n   # two asm statements per function
    return new


def variant_text(sep, order=None):
    t = open('07_kernel/src/' + REL).read()
    a, b = i386_funcs(t)
    d, v = m68k_funcs(sep)
    if order:
        d, v = reorder(d, order), reorder(v, order)
    assert t.count(a) == 1 and t.count(b) == 1
    return t.replace(a, d).replace(b, v)


def cmd_stage(stage):
    m = json.load(open(BASE + '.manifest.json'))
    for e in m['files']:
        assert sha(os.path.join(BASE, e[0])) == e[2], e[0]
    assert not os.path.exists(stage)
    shutil.copytree(BASE, stage, symlinks=True)
    files = [list(e[:3]) for e in m['files']]
    V = dict((k, (s, None)) for k, s in SEP.items())
    V.update((k, (':', o)) for k, o in ORDER.items())
    for k, (sep, order) in sorted(V.items()):
        p = os.path.join(stage, 'src', 'kern', 'p448_%s.c' % k)
        open(p, 'w').write(variant_text(sep, order))
        files.append([os.path.relpath(p, stage), 'plan 448 variant %s' % k, sha(p)])
    json.dump(dict(plan=448, base=BASE, base_manifest_sha256=sha(BASE + '.manifest.json'), files=files),
              open(stage + '.manifest.json', 'w'), indent=1)
    print('stage', stage, 'files', len(files))


def cmd_cmd(out):
    line = None
    for l in open(CC):
        if l.startswith('RUN ') and ' src/src/%s ' % REL in l:
            line = l.split()
    assert line, 'no compile line for ' + REL
    L, E = [], []
    for k in sorted(list(SEP) + list(ORDER)):
        w = list(line)
        w[w.index('-c') + 1] = 'src/src/kern/p448_%s.c' % k
        w[w.index('-o') + 1] = 'stage/P448__%s.o' % k
        L.append(' '.join(w))
        E.append('EXPECT P448__%s.o' % k)
    open(out, 'w').write('# m5p448: plan 448 ns_div syntax variants (m5_m68k_ns.py cmd)\n' + '\n'.join(L + E) + '\n')
    print('commands', len(L))


def cmd_compare(rid, prefix, outj):
    import macho_obj
    import m0_m68k_cause as C
    import m3_m68k_wide as W
    img = C.Img()
    names = {y['name'] for y in img.img.o['symbols']}
    T = {t['object']: t for t in W.targets()}
    xo = macho_obj.parse(open(T['x86-ns_timer']['obj'], 'rb').read())
    xt = [s for s in xo['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
    ext = [y['name'] for y in xo['symbols'] if y['kind'] == 'SECT' and y.get('ext') and not y['stab'] and y['sect'] == xt['index']]
    rows = []
    outdir = os.path.join('08_build/runs', rid, 'out')
    for f in sorted(os.listdir(outdir)):
        if not (f.startswith(prefix) and f.endswith('.o')):
            continue
        p = os.path.join(outdir, f)
        d = C.run_l1(p, os.path.join('08_build/artifacts/m5p448', 'l1-%s.json' % f[:-2]))
        _, ts, spans = C.compare_object(img, p, ext)
        o = macho_obj.parse(open(p, 'rb').read())
        undef = sorted({y['name'] for y in o['symbols'] if y['kind'] == 'UNDF' and not y['stab']} - names)
        rows.append(dict(object=f, sha256=sha(p), verdict=d['object_verdict'],
                         spans={s['name']: s.get('equal') for s in spans if 'image_address' in s},
                         undefined_not_in_original=undef))
    json.dump(dict(plan=448, tool='10_tools/reconstruction/m5_m68k_ns.py', tool_sha256=sha(os.path.abspath(__file__)), run=rid,
                   objects=rows), open(outj, 'w'), indent=1)
    for r in rows:
        print(r['object'], r['verdict'], 'equal', sorted(k for k, v in r['spans'].items() if v),
              'differ', sorted(k for k, v in r['spans'].items() if not v), 'undef', r['undefined_not_in_original'])


def main():
    a = sys.argv[1:]
    if a[:1] == ['stage'] and len(a) == 2:
        cmd_stage(a[1])
    elif a[:1] == ['cmd'] and len(a) == 2:
        cmd_cmd(a[1])
    elif a[:1] == ['compare'] and len(a) == 4:
        cmd_compare(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
