#!/usr/bin/env python3
"""m5_m68k_clock.py -- plan 455 (M5-12): m68k kern_clock hardclock SIMPLE_CLOCK block
(clock_value, last_hardclock, 64-bit division by 1000 with the m68k ns_div_val); variants.

  python3 10_tools/reconstruction/m5_m68k_clock.py stage STAGE_DIR [V,V,...]
  python3 10_tools/reconstruction/m5_m68k_clock.py cmd CC.cmd [V,V,...]
  python3 10_tools/reconstruction/m5_m68k_clock.py compare RUN_ID RECORD.json [V,V,...]
  (variant list defaults to A-G, the plan 455 first run; plan 455.2 second run: H,I,J)

stage    m0p454-a1-stage copy (manifest-checked) + src/bsd/kern/p455_<V>.c: the 07 main file with
         the plan 455 block inserted (V in VARIANTS; plan 455.1 list).
cmd      the plan 430 compile line of bsd/kern/kern_clock.c with source/output replaced (P455__<V>.o).
compare  per variant: L1 verdict, every external span (relocations masked), undefined symbols not
         in the original, COMMON symbols, local __text symbols, equal groups (non-STABS sections).
"""
import sys, os, json, shutil, hashlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import m5_m68k_ns as N

BASE = '08_build/runs/tools/m0p454-a1-stage'
CC = '08_build/artifacts/m3p430/cc.cmd'
REL = 'bsd/kern/kern_clock.c'
VARIANTS = ['A', 'B', 'C', 'D', 'E', 'F', 'G']
VARIANTS2 = ['H', 'I', 'J']           # plan 455.2: E helper; H/I Darwin-style array, J pointer
ANCHOR = {99: '#import <mach/boolean.h>\t/* plan 233: NeXTMach sys/boolean.h */\n',
          114: '\tregister thread_t\tthread;\n', 116: '\tthread = current_thread();\n', 169: '}\n'}


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def helper(v):
    """m68k ns_div_val: A = m5_m68k_ns.m68k_funcs(':') text; B-D = input orders; E = output order."""
    t = N.m68k_funcs(':')[1]
    if v in ('B', 'C', 'D'):
        return N.reorder(t, v)
    if v in ('E', 'H', 'I', 'J'):
        for a, b in (('asm("divull %2,%1:%0"\n\t    : "=d" (quo), "=d" (rem)\n\t    : "dmi" (divisor), "0" (*msw), "1" (0));',
                      'asm("divull %2,%0:%1"\n\t    : "=d" (rem), "=d" (quo)\n\t    : "dmi" (divisor), "1" (*msw), "0" (0));'),
                     ('asm("divul %2,%1:%0"\n\t    : "=d" (quo), "=d" (rem)\n\t    : "dmi" (divisor), "0" (*lsw), "1" (rem));',
                      'asm("divul %2,%0:%1"\n\t    : "=d" (rem), "=d" (quo)\n\t    : "dmi" (divisor), "1" (*lsw), "0" (rem));')):
            assert t.count(a) == 1
            t = t.replace(a, b)
    return t


def variant(v):
    L = open('07_kernel/src/' + REL).readlines()
    assert len(L) == 347
    for k, s in ANCHOR.items():
        assert L[k - 1] == s, (k, L[k - 1])
    arr = v in ('H', 'I')
    top = ['#if\tSIMPLE_CLOCK\n', '#import <kernserv/clock_timer.h>\n', 'extern ns_time_t\tclock_value();\n',
           'ns_time_t\tlast_hardclock%s;\n' % ('[NCPUS]' if arr else ''), '\n', helper(v), '#endif\t/* SIMPLE_CLOCK */\n']
    last = 'last_hardclock[cpu_number()]' if arr else ('*lastp' if v == 'J' else 'last_hardclock')
    decl = ['#if\tSIMPLE_CLOCK\n', '\tns_time_t\tnew_hardclock;\n']
    if v in ('F', 'I'):
        decl.append('\tns_time_t\tdelta_hardclock;\n')
    if v == 'J':
        decl.append('\tregister ns_time_t\t*lastp = &last_hardclock;\n')
    decl += ['\t%s\tmyticks;\n' % ('int' if v == 'G' else 'unsigned int'), '#define\ttick\tmyticks\n', '#endif\t/* SIMPLE_CLOCK */\n']
    if v in ('F', 'I'):
        body = ['\tnew_hardclock = clock_value(System);\n', '\tdelta_hardclock = new_hardclock - %s;\n' % last,
                '\tmyticks = ns_div_val(delta_hardclock, 1000);\n']
    else:
        body = ['\tnew_hardclock = clock_value(System);\n', '\tmyticks = ns_div_val(new_hardclock - %s, 1000);\n' % last]
    body = ['#if\tSIMPLE_CLOCK\n'] + body + ['\t%s = new_hardclock;\n' % last, '#endif\t/* SIMPLE_CLOCK */\n']
    tail = ['#if\tSIMPLE_CLOCK\n', '#undef\ttick\n', '#endif\t/* SIMPLE_CLOCK */\n']
    out = []
    for i, l in enumerate(L, 1):
        out.append(l)
        if i == 99:
            out += ['\n'] + top
        elif i == 114:
            out += decl
        elif i == 116:
            out += body
        elif i == 169:
            out += tail
    return ''.join(out)


def vlist(s):
    return s.split(',') if s else VARIANTS


def cmd_stage(stage, vs=None):
    m = json.load(open(BASE + '.manifest.json'))
    for e in m['files']:
        assert sha(os.path.join(BASE, e[0])) == e[2], e[0]
    assert not os.path.exists(stage)
    shutil.copytree(BASE, stage, symlinks=True)
    files = [list(e[:3]) for e in m['files']]
    for v in vlist(vs):
        p = os.path.join(stage, 'src', 'bsd', 'kern', 'p455_%s.c' % v)
        open(p, 'w').write(variant(v))
        files.append([os.path.relpath(p, stage), 'plan 455 variant %s' % v, sha(p)])
    json.dump(dict(plan=455, base=BASE, base_manifest_sha256=sha(BASE + '.manifest.json'), files=files),
              open(stage + '.manifest.json', 'w'), indent=1)
    print('stage', stage, 'files', len(files))


def cmd_cmd(out, vs=None):
    line = [l.split() for l in open(CC) if l.startswith('RUN ') and ' src/src/%s ' % REL in l]
    assert len(line) == 1 and '-c' in line[0]
    L, E = [], []
    for v in vlist(vs):
        w = list(line[0])
        w[w.index('-c') + 1] = 'src/src/bsd/kern/p455_%s.c' % v
        w[w.index('-o') + 1] = 'stage/P455__%s.o' % v
        L.append(' '.join(w))
        E.append('EXPECT P455__%s.o' % v)
    open(out, 'w').write('# m5p455: plan 455 kern_clock SIMPLE_CLOCK variants (m5_m68k_clock.py cmd)\n' + '\n'.join(L + E) + '\n')
    print('commands', len(L))


def cmd_compare(rid, outj, vs=None):
    import macho_obj
    import m0_m68k_cause as C
    import m3_m68k_wide as W
    import m3_m68k_diag as D
    img = C.Img()
    names = {y['name'] for y in img.img.o['symbols']}
    T = {t['object']: t for t in W.targets()}
    xo = macho_obj.parse(open(T['x86-kern_clock']['obj'], 'rb').read())
    xt = [s for s in xo['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
    ext = [y['name'] for y in xo['symbols'] if y['kind'] == 'SECT' and y.get('ext') and not y['stab'] and y['sect'] == xt['index']]
    rows, canon = [], {}
    os.makedirs('08_build/artifacts/m5p455', exist_ok=True)
    for v in vlist(vs):
        f = 'P455__%s.o' % v
        p = os.path.join('08_build/runs', rid, 'out', f)
        if not os.path.exists(p):
            rows.append(dict(variant=v, object=f, missing=True))
            continue
        d = C.run_l1(p, os.path.join('08_build/artifacts/m5p455', 'l1-%s.json' % v))
        _, ts, spans = C.compare_object(img, p, ext)
        o = macho_obj.parse(open(p, 'rb').read())
        ot = [s for s in o['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
        undef = sorted({y['name'] for y in o['symbols'] if y['kind'] == 'UNDF' and not y['stab']} - names)
        common = sorted((y['name'], y.get('value')) for y in o['symbols'] if y['kind'] == 'COMMON')
        local_text = sorted(y['name'] for y in o['symbols'] if y['kind'] == 'SECT' and not y.get('ext') and not y['stab']
                            and y['sect'] == ot['index'])
        canon[v] = D.canon(p)
        rows.append(dict(variant=v, object=f, sha256=sha(p), verdict=d['object_verdict'], reasons=d.get('object_reasons'),
                         text=ot['size'], spans={s['name']: s.get('equal') for s in spans if 'image_address' in s},
                         undefined_not_in_original=undef, common=common, local_text_symbols=local_text))
    groups = []
    for v in canon:
        for g in groups:
            if canon[g[0]] == canon[v]:
                g.append(v)
                break
        else:
            groups.append([v])
    S = dict(match=[r['variant'] for r in rows if r.get('verdict') == 'OBJECT_MATCH'], equal_groups=groups,
             missing=[r['variant'] for r in rows if r.get('missing')])
    json.dump(dict(plan=455, tool='10_tools/reconstruction/m5_m68k_clock.py', tool_sha256=sha(os.path.abspath(__file__)), run=rid,
                   summary=S, variants=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S))
    for r in rows:
        if r.get('missing'):
            print(r['variant'], 'missing')
            continue
        print(r['variant'], r['verdict'], r['text'], 'differ', sorted(k for k, x in r['spans'].items() if not x),
              'undef', r['undefined_not_in_original'], 'common', r['common'], 'local', r['local_text_symbols'])


def main():
    a = sys.argv[1:]
    if a[:1] == ['stage'] and len(a) in (2, 3):
        cmd_stage(*a[1:])
    elif a[:1] == ['cmd'] and len(a) in (2, 3):
        cmd_cmd(*a[1:])
    elif a[:1] == ['compare'] and len(a) in (3, 4):
        cmd_compare(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
