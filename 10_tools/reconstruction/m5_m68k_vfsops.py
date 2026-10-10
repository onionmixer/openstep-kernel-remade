#!/usr/bin/env python3
"""m5_m68k_vfsops.py -- plan 450 (M5-7): m68k ufs_vfsops without the i386 byte swaps; frame
filler size variants of mountfs's `char unused[N]` (plan 450.1).

  python3 10_tools/reconstruction/m5_m68k_vfsops.py stage STAGE_DIR
  python3 10_tools/reconstruction/m5_m68k_vfsops.py cmd CC.cmd
  python3 10_tools/reconstruction/m5_m68k_vfsops.py compare RUN_ID RECORD.json

stage    m0p449-a1-stage copy (manifest-checked) + src/bsd/ufs/p450_N<n>.c: the 07 main file with
         the seven byte-swap statements (lines 257-258, 308, 329, 337, 416, 691, 715) removed and
         line 207 `char unused[64];` made `char unused[<n>];` (n in SIZES).
cmd      the plan 430 compile line of bsd/ufs/ufs_vfsops.c with source/output replaced.
compare  per variant: L1 verdict, every external span (relocations masked), undefined symbols
         not in the original, and which variants are equal to each other (non-STABS sections).
"""
import sys, os, json, shutil, hashlib, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

BASE = '08_build/runs/tools/m0p449-a1-stage'
CC = '08_build/artifacts/m3p430/cc.cmd'
REL = 'bsd/ufs/ufs_vfsops.c'
SIZES = [64, 62, 60, 58, 57, 56]
SWAP = [257, 258, 308, 329, 337, 416, 691, 715]
FILLER = (207, '\tchar unused[64];\t/* plan 216.1: frame is 0x40 larger in the original (0x143187); name and place inferred */\n')


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def variant(n):
    L = open('07_kernel/src/' + REL).readlines()
    assert L[FILLER[0] - 1] == FILLER[1]
    assert 'fsp = tp->b_un.b_fs;' in L[256] and all('byte_swap' in L[i - 1] for i in SWAP if i != 257), 'unexpected 07 lines'
    out = []
    for i, l in enumerate(L, 1):
        if i in SWAP:
            continue
        if i == FILLER[0]:
            l = '\tchar unused[%d];\n' % n
        out.append(l)
    return ''.join(out)


def cmd_stage(stage):
    m = json.load(open(BASE + '.manifest.json'))
    for e in m['files']:
        assert sha(os.path.join(BASE, e[0])) == e[2], e[0]
    assert not os.path.exists(stage)
    shutil.copytree(BASE, stage, symlinks=True)
    files = [list(e[:3]) for e in m['files']]
    for n in SIZES:
        p = os.path.join(stage, 'src', 'bsd', 'ufs', 'p450_N%d.c' % n)
        open(p, 'w').write(variant(n))
        files.append([os.path.relpath(p, stage), 'plan 450 variant N=%d' % n, sha(p)])
    json.dump(dict(plan=450, base=BASE, base_manifest_sha256=sha(BASE + '.manifest.json'), files=files),
              open(stage + '.manifest.json', 'w'), indent=1)
    print('stage', stage, 'files', len(files))


def cmd_cmd(out):
    line = [l.split() for l in open(CC) if l.startswith('RUN ') and ' src/src/%s ' % REL in l]
    assert len(line) == 1
    L, E = [], []
    for n in SIZES:
        w = list(line[0])
        w[w.index('-c') + 1] = 'src/src/bsd/ufs/p450_N%d.c' % n
        w[w.index('-o') + 1] = 'stage/P450__N%d.o' % n
        L.append(' '.join(w))
        E.append('EXPECT P450__N%d.o' % n)
    open(out, 'w').write('# m5p450: plan 450 ufs_vfsops filler variants (m5_m68k_vfsops.py cmd)\n' + '\n'.join(L + E) + '\n')
    print('commands', len(L))


def cmd_compare(rid, outj):
    import macho_obj
    import m0_m68k_cause as C
    import m3_m68k_wide as W
    import m3_m68k_diag as D
    img = C.Img()
    names = {y['name'] for y in img.img.o['symbols']}
    T = {t['object']: t for t in W.targets()}
    xo = macho_obj.parse(open(T['x86-ufs_vfsops']['obj'], 'rb').read())
    xt = [s for s in xo['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
    ext = [y['name'] for y in xo['symbols'] if y['kind'] == 'SECT' and y.get('ext') and not y['stab'] and y['sect'] == xt['index']]
    rows, canon = [], {}
    os.makedirs('08_build/artifacts/m5p450', exist_ok=True)
    for n in SIZES:
        f = 'P450__N%d.o' % n
        p = os.path.join('08_build/runs', rid, 'out', f)
        d = C.run_l1(p, os.path.join('08_build/artifacts/m5p450', 'l1-N%d.json' % n))
        _, ts, spans = C.compare_object(img, p, ext)
        o = macho_obj.parse(open(p, 'rb').read())
        undef = sorted({y['name'] for y in o['symbols'] if y['kind'] == 'UNDF' and not y['stab']} - names)
        canon[n] = D.canon(p)
        rows.append(dict(size=n, object=f, sha256=sha(p), verdict=d['object_verdict'], text=ts['size'],
                         spans={s['name']: s.get('equal') for s in spans if 'image_address' in s}, undefined_not_in_original=undef))
    groups = []
    for n in SIZES:
        for g in groups:
            if canon[g[0]] == canon[n]:
                g.append(n)
                break
        else:
            groups.append([n])
    S = dict(match=[r['size'] for r in rows if r['verdict'] == 'OBJECT_MATCH'], equal_groups=groups)
    json.dump(dict(plan=450, tool='10_tools/reconstruction/m5_m68k_vfsops.py', tool_sha256=sha(os.path.abspath(__file__)), run=rid,
                   summary=S, variants=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S))
    for r in rows:
        print(r['size'], r['verdict'], r['text'], 'differ', sorted(k for k, v in r['spans'].items() if not v), 'undef', r['undefined_not_in_original'])


def main():
    a = sys.argv[1:]
    if a[:1] == ['stage'] and len(a) == 2:
        cmd_stage(a[1])
    elif a[:1] == ['cmd'] and len(a) == 2:
        cmd_cmd(a[1])
    elif a[:1] == ['compare'] and len(a) == 3:
        cmd_compare(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
