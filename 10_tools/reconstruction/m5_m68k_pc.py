#!/usr/bin/env python3
"""m5_m68k_pc.py -- plan 444 (M5-1): m68k PC writes of mach_process.c / kern_exec.c with the SDK
PCH/PCL indices; variant probe and comparison with the original instruction sequences.

  python3 10_tools/reconstruction/m5_m68k_pc.py stage STAGE_DIR
  python3 10_tools/reconstruction/m5_m68k_pc.py cmd CC.cmd
  python3 10_tools/reconstruction/m5_m68k_pc.py otool RUN_ID OTOOL.sh
  python3 10_tools/reconstruction/m5_m68k_pc.py compare RUN_ID OTOOL_DIR RECORD.json [PREFIX]
  python3 10_tools/reconstruction/m5_m68k_pc.py cmd2 CC.cmd [PLAN NAMES]
  python3 10_tools/reconstruction/m5_m68k_pc.py final RUN_ID OTOOL_DIR RECORD.json [PLAN NAMES]
  (PLAN defaults to 444, NAMES to mach_process,kern_exec; plan 445 uses 445 kern_exec)
  python3 10_tools/reconstruction/m5_m68k_pc.py diag RUN_ID OTOOL_DIR PLAN NAME SPAN RECORD.json

stage    m0p441-stage copy (manifest-checked) + src/<dir of the source>/p444_<variant>.c, each the 07 main file
         with the PC line replaced by one candidate form (plan 444.1 list).
cmd      the plan 430 compile lines of the two files with source/output replaced (P444__<variant>.o).
otool    a read-only real-machine script: otool -tv + krsha256 of the run's objects.
compare  in each listing, the instruction run whose shape equals the original PC-write sequence
         (absolute addresses and a6 displacements masked; mnemonics, registers, other operands
         kept); variants with a match are reported.  PREFIX selects the objects (default P444__).
"""
import sys, os, re, json, shutil, hashlib, collections

BASE = '08_build/runs/tools/m0p441-stage'
CC430 = '08_build/artifacts/m3p430/cc.cmd'
IMG_LIST = '08_build/artifacts/m0p414/otool-V10/image.txt'
MP, KE = 'bsd/kern/mach_process.c', 'bsd/kern/kern_exec.c'
MP_OLD = '\t\t\tlocr0[PC] = (int)uap->addr;\n'
KE_OLD = '\tu.u_ar0[PC] = load_result.entry_point;\t/* plan 291 */\n'
PCH_P = '(int)uap->addr >> 16'
MPV = {'P1': '(int)uap->addr << 16', 'P2': '((int)uap->addr & 0xffff) << 16', 'P3': '(u_short)(int)uap->addr << 16'}
E_PCH = {'and': '\tu.u_ar0[PCH] = (u.u_ar0[PCH] & 0xffff0000) | ((unsigned)load_result.entry_point >> 16);\n',
         'short': '\t((short *)&u.u_ar0[PCH])[1] = load_result.entry_point >> 16;\n'}
E_PCL = {'mask': '\tu.u_ar0[PCL] = (load_result.entry_point << 16) | (u.u_ar0[PCL] & 0xffff);\n',
         'ushort': '\tu.u_ar0[PCL] = (load_result.entry_point << 16) | (u_short)u.u_ar0[PCL];\n'}
KEV = {'E1': ('and', 'mask'), 'E2': ('short', 'mask'), 'E3': ('short', 'ushort'), 'E4': ('and', 'ushort')}
REF = {MP: (0x400aeda, 0x400aef8), KE: (0x400503c, 0x4005062)}


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def variants():
    out = {}
    mp = open('07_kernel/src/' + MP).read()
    ke = open('07_kernel/src/' + KE).read()
    assert mp.count(MP_OLD) == 1 and ke.count(KE_OLD) == 1
    for k, pcl in MPV.items():
        out[k] = (MP, mp.replace(MP_OLD, '\t\t{\n\t\t\tlocr0[PCH] |= %s;\n\t\t\tlocr0[PCL] |= %s;\n\t\t}\n' % (PCH_P, pcl)))
    for k, (h, l) in KEV.items():
        out[k] = (KE, ke.replace(KE_OLD, E_PCH[h] + E_PCL[l]))
    return out


def cmd_stage(stage):
    m = json.load(open(BASE + '.manifest.json'))
    for e in m['files']:
        assert sha(os.path.join(BASE, e[0])) == e[2], e[0]
    assert not os.path.exists(stage)
    shutil.copytree(BASE, stage, symlinks=True)
    files = [list(e[:3]) for e in m['files']]
    for k, (rel, text) in sorted(variants().items()):
        # same directory as the original so that "" includes resolve alike
        p = os.path.join(stage, 'src', os.path.dirname(rel), 'p444_%s.c' % k)
        assert not os.path.exists(p)
        open(p, 'w').write(text)
        files.append([os.path.relpath(p, stage), 'plan 444 variant %s of %s' % (k, rel), sha(p)])
    json.dump(dict(plan=444, base=BASE, base_manifest_sha256=sha(BASE + '.manifest.json'), files=files),
              open(stage + '.manifest.json', 'w'), indent=1)
    print('stage', stage, 'files', len(files))


def cmd_cmd(out):
    lines = {}
    for l in open(CC430):
        for rel in (MP, KE):
            if l.startswith('RUN ') and ' src/src/%s ' % rel in l:
                lines[rel] = l.split()
    L, E = [], []
    for k, (rel, _) in sorted(variants().items()):
        w = list(lines[rel])
        w[w.index('-c') + 1] = 'src/src/%s/p444_%s.c' % (os.path.dirname(rel), k)
        w[w.index('-o') + 1] = 'stage/P444__%s.o' % k
        L.append(' '.join(w))
        E.append('EXPECT P444__%s.o' % k)
    open(out, 'w').write('# m5p444: plan 444 PC-write variants (m5_m68k_pc.py cmd)\n' + '\n'.join(L + E) + '\n')
    print('commands', len(L))


def cmd_otool(rid, out, prefix='P444__'):
    R = '/ndrv/openstep-kernel-remade'
    od = '%s/08_build/artifacts/%s/otool' % (R, rid)
    objs = sorted(f for f in os.listdir(os.path.join('08_build/runs', rid, 'out')) if f.startswith(prefix) and f.endswith('.o'))
    S = ['# plan 444: read-only otool listings of run %s' % rid, 'O=%s' % od, 'K=%s/08_build/runs/tools/target/krsha256-default' % R]
    for f in objs:
        b = f[:-2]
        S.append('/bin/otool -tv %s/08_build/runs/%s/out/%s > $O/%s.txt 2> $O/%s.err; $K %s/08_build/runs/%s/out/%s >> $O/objects.sha'
                 % (R, rid, f, b, b, R, rid, f))
    open(out, 'w').write('\n'.join(S) + '\n')
    print('objects', len(objs))


def read_list(path):
    out = []
    for l in open(path, errors='replace'):
        m = re.match(r'^([0-9a-f]{8})\t(\S+)(?:\t(.*))?$', l.rstrip('\n'))
        if m:
            out.append((int(m.group(1), 16), m.group(2), m.group(3) or ''))
    return out


def shape(ins):
    """mask absolute addresses (0x... with :l or bare), a6 displacements and branch targets."""
    m, o = ins
    o = re.sub(r'0x[0-9a-f]+:l', 'ABS', o)
    o = re.sub(r'a6@\(0x[0-9a-f]+:w\)', 'a6@(F)', o)
    if m.startswith(('b', 'j', 'db')) and m not in ('bset', 'bclr', 'btst', 'bchg', 'bfextu', 'bfexts', 'bftst', 'bfset', 'bfclr', 'bfins'):
        o = re.sub(r'0x[0-9a-f]+', 'T', o)
    return (m, o)


def cmd_compare(rid, odir, outj, prefix='P444__'):
    img = read_list(IMG_LIST)
    ref = {rel: [shape((m, o)) for a, m, o in img if lo <= a < hi] for rel, (lo, hi) in REF.items()}
    shas = {os.path.basename(l.split()[-1]): l.split()[0] for l in open(os.path.join(odir, 'objects.sha'))}
    V = variants()
    rows = []
    for f in sorted(os.listdir(os.path.join('08_build/runs', rid, 'out'))):
        if not (f.startswith(prefix) and f.endswith('.o')):
            continue
        p = os.path.join('08_build/runs', rid, 'out', f)
        assert sha(p) == shas[f], f
        k = f[len(prefix):-2]
        rel = V[k][0] if k in V else (MP if 'mach_process' in f else KE)
        lst = [shape((m, o)) for a, m, o in read_list(os.path.join(odir, f[:-2] + '.txt'))]
        r = ref[rel]
        hits = [i for i in range(len(lst) - len(r) + 1) if lst[i:i + len(r)] == r]
        rows.append(dict(object=f, variant=k, source=rel, ref_len=len(r), matches=len(hits), sha256=sha(p)))
    S = {r['variant']: r['matches'] for r in rows}
    json.dump(dict(plan=444, tool='10_tools/reconstruction/m5_m68k_pc.py', tool_sha256=sha(os.path.abspath(__file__)), run=rid,
                   reference={rel: dict(range=['0x%x' % lo, '0x%x' % hi], shape=ref[rel]) for rel, (lo, hi) in REF.items()},
                   summary=S, rows=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))
    for rel in ref:
        print(rel, ref[rel])


FILES = {'mach_process': MP, 'kern_exec': KE, 'vm_fault': 'vm/vm_fault.c', 'vm_pageout': 'vm/vm_pageout.c',
         'ufs_vnodeops': 'bsd/ufs/ufs_vnodeops.c', 'ufs_inode': 'bsd/ufs/ufs_inode.c',
         'ufs_vfsops': 'bsd/ufs/ufs_vfsops.c', 'ufs_dir': 'bsd/ufs/ufs_dir.c',
         'ufs_alloc': 'bsd/ufs/ufs_alloc.c'}   # plans 446-452


def cmd_cmd2(out, plan='444', names='mach_process,kern_exec'):
    """final compile of overlay sources: the plan 430 compile lines unchanged except the output
    (F<plan>__<name>.o); plan 445 generalisation (plan and file list as arguments)."""
    names = names.split(',')
    L, E = [], []
    src = list(open(CC430)) + list(open('08_build/runs/m3p429-cc2/run.cmd'))   # plan 451: the 88-object lines
    for l in src:
        for n in names:
            if l.startswith('RUN ') and ' src/src/%s ' % FILES[n] in l:
                w = l.split()
                w[w.index('-o') + 1] = 'stage/F%s__%s.o' % (plan, n)
                L.append(' '.join(w))
                E.append('EXPECT F%s__%s.o' % (plan, n))
    assert len(L) == len(names)
    open(out, 'w').write('# m5p%s: plan %s final compile of overlay sources (m5_m68k_pc.py cmd2)\n' % (plan, plan) + '\n'.join(L + E) + '\n')


def cmd_final(rid, odir, outj, plan='444', names='mach_process,kern_exec'):
    """plan 444 final: shape match, L1, external spans, undefined symbols not in the original."""
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import macho_obj
    import m0_m68k_cause as C
    import m3_m68k_wide as W
    names = names.split(',')
    cmd_compare(rid, odir, outj + '.shape.json', 'F%s__' % plan)
    shape_rows = json.load(open(outj + '.shape.json'))['rows']
    img = C.Img()
    img_names = {y['name'] for y in img.img.o['symbols']}
    T = {t['object']: t for t in W.targets()}
    rows = []
    for obj, n in [('x86-' + n, n) for n in names]:
        p = os.path.join('08_build/runs', rid, 'out', 'F%s__%s.o' % (plan, n))
        xo = macho_obj.parse(open(T[obj]['obj'], 'rb').read())
        xt = [s for s in xo['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
        ext = [y['name'] for y in xo['symbols'] if y['kind'] == 'SECT' and y.get('ext') and not y['stab'] and y['sect'] == xt['index']]
        os.makedirs('08_build/artifacts/m5p%s' % plan, exist_ok=True)
        d = C.run_l1(p, os.path.join('08_build/artifacts/m5p%s' % plan, 'l1-%s.json' % obj))
        _, ts, spans = C.compare_object(img, p, ext)
        o = macho_obj.parse(open(p, 'rb').read())
        undef = sorted({y['name'] for y in o['symbols'] if y['kind'] == 'UNDF' and not y['stab']} - img_names)
        rows.append(dict(object=obj, verdict=d['object_verdict'], reasons=d.get('object_reasons'),
                         spans={s['name']: s.get('equal') for s in spans if 'image_address' in s},
                         undefined_not_in_original=undef, sha256=sha(p),
                         shape=[r for r in shape_rows if n in r['object']]))
    json.dump(dict(plan=int(plan), tool='10_tools/reconstruction/m5_m68k_pc.py', tool_sha256=sha(os.path.abspath(__file__)), run=rid,
                   objects=rows), open(outj, 'w'), indent=1)
    for r in rows:
        print(r['object'], r['verdict'], r['reasons'], {k: v for k, v in r['spans'].items() if not v}, r['undefined_not_in_original'],
              [x['matches'] for x in r['shape']])


def cmd_diag(rid, odir, plan, name, span, outj):
    """plan 446: instruction-level blocks of one external span of F<plan>__<name>.o against the
    original (plan 436 method: m3_m68k_diag.norm_with_addr + m3_m68k_diag3.blocks_of)."""
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import macho_obj
    import m0_m68k_cause as C
    import m3_m68k_diag as D
    import m3_m68k_diag3 as D3
    import m3_m68k_wide as W
    f = 'F%s__%s.o' % (plan, name)
    p = os.path.join('08_build/runs', rid, 'out', f)
    shas = {os.path.basename(l.split()[-1]): l.split()[0] for l in open(os.path.join(odir, 'objects.sha'))}
    assert sha(p) == shas[f]
    img = C.Img()
    ob = open(p, 'rb').read()
    o = macho_obj.parse(ob)
    ts = [s for s in o['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
    nm = {i: y['name'] for i, y in enumerate(o['symbols'])}
    rel = []
    for r in ts['relocs']:
        r = dict(r)
        if not r['scattered'] and r['extern']:
            r['symname'] = nm[r['symbolnum']]
        r['address'] += ts['addr']
        rel.append(r)
    T = {t['object']: t for t in W.targets()}
    xo = macho_obj.parse(open(T['x86-' + name]['obj'], 'rb').read())
    xt = [s for s in xo['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
    ext = [y['name'] for y in xo['symbols'] if y['kind'] == 'SECT' and y.get('ext') and not y['stab'] and y['sect'] == xt['index']]
    _, _, spans = C.compare_object(img, p, ext)
    s = [x for x in spans if x['name'] == span][0]
    o0, o1, _ = C.ext_spans(o, None, ts, ext)[span]
    osym = C.Symbolizer(o['sections'], o['symbols'], lambda x, n: C.obj_read(o, ob, x, n))
    A, aa, _ = D.norm_with_addr(C.read_otool(os.path.join(odir, f[:-2] + '.txt')), ts['addr'] + o0, ts['addr'] + o1, osym,
                                lambda x, n: ob[ts['offset'] + x - ts['addr']:ts['offset'] + x - ts['addr'] + n], rel)
    isym = C.Symbolizer(img.img.o['sections'], img.img.o['symbols'], img.img.read)
    B, ba, _ = D.norm_with_addr(C.read_otool(D.IMG_LIST), s['image_address'], s['image_address'] + s['image_extent'], isym, img.img.read)
    bl, kinds = D3.blocks_of(A, aa, B, ba, ts, D.lines_of(o, ts))
    json.dump(dict(plan=int(plan), tool='10_tools/reconstruction/m5_m68k_pc.py', tool_sha256=sha(os.path.abspath(__file__)), run=rid,
                   object=f, span=span, equal=s.get('equal'), bytes=[o1 - o0, s['image_extent']], kinds=dict(kinds), blocks=bl),
              open(outj, 'w'), indent=1)
    print(span, 'equal', s.get('equal'), 'bytes', o1 - o0, s['image_extent'], dict(kinds))
    for b in bl:
        print(' ', b['op'], b['kind'], b['object'], b['image'], b['lines'], b['object_ins'][:4], '|', b['image_ins'][:4])


def main():
    a = sys.argv[1:]
    if a[:1] == ['stage'] and len(a) == 2:
        cmd_stage(a[1])
    elif a[:1] == ['cmd'] and len(a) == 2:
        cmd_cmd(a[1])
    elif a[:1] == ['otool'] and len(a) in (3, 4):
        cmd_otool(*a[1:])
    elif a[:1] == ['compare'] and len(a) in (4, 5):
        cmd_compare(*a[1:])
    elif a[:1] == ['cmd2'] and len(a) in (2, 4):
        cmd_cmd2(*a[1:])
    elif a[:1] == ['final'] and len(a) in (4, 6):
        cmd_final(*a[1:])
    elif a[:1] == ['diag'] and len(a) == 7:
        cmd_diag(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
