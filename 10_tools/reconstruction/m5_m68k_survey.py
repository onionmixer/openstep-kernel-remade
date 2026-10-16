#!/usr/bin/env python3
"""m5_m68k_survey.py -- plan 470 (M5-27): read-only survey of the m68k objects whose code still
differs from the original (07 unchanged); ranks them for the next plans.

  python3 10_tools/reconstruction/m5_m68k_survey.py cmd CC.cmd
  python3 10_tools/reconstruction/m5_m68k_survey.py otool RUN_ID OTOOL.sh
  python3 10_tools/reconstruction/m5_m68k_survey.py report RUN_ID OTOOL_DIR RECORD.json

cmd      the compile lines of OBJECTS from stage_m68k.ref_lines() (the 205 reference lines),
         only the output replaced by stage/O470__<base>.o (asserted: each object exactly one
         RUN line with -O2).
otool    a read-only real-machine script: otool -tv of every O470 object into OTOOL_DIR.
report   per object (plan 470.1):
         - equality with the plan 441 object (m3_m68k_diag.canon and l2_prefix_diff.obj_sig);
         - original extent from 06_reconstruction/m68k-objects.tsv; spans on both sides by the same
           rule: a prefix [extent start, first external symbol) and one span per external __text
           symbol to the next external symbol (statics stay inside), the original side capped at
           the extent end; names only on one side are listed;
         - per span: lengths and equality of the bytes outside the object's relocation fields;
           for unequal spans an instruction alignment of the two otool listings (operands with
           every hex number replaced by N, SequenceMatcher(autojunk=False)) with blocks marked R
           (same row count and mnemonics, operands differ) or S (otherwise);
         - L1 with --place-from-image and with --place __TEXT,__text=<extent start>;
         - undefined symbols not in the original and COMMON symbols.
         score = sum over unequal blocks of (object rows + original rows); ranking by score, then
         |text size - extent size|.  The score is an estimate for choosing the next object, not
         evidence of a match.
"""
import sys, os, re, csv, json, hashlib, difflib, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

PLAN = 470
OBJECTS = ['netif', 'miniMon', 'igmp', 'time_stamp', 'mfs_prim', 'nfs_client', 'kern_fork', 'cmu_syscalls', 'ufs_subr',
           'kern_exit', 'ipc_mig', 'kalloc', 'kern_proc', 'mach_clock', 'tty', 'callout', 'kdp_udp', 'mach_net', 'swapfs']
OBJMAP = '06_reconstruction/m68k-objects.tsv'
SYMS = '03_original/m68k/inventory/symbols.tsv'
IMG = '03_original/m68k/binaries/mach_kernel'
IMG_LIST = '08_build/artifacts/m0p414/otool-V10/image.txt'
RUN441 = '08_build/runs/m3p441-cc1/out'
STAGE = '08_build/runs/tools/m0p469-a1-stage'


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def selected():
    """[(object, base, ref_run, ref_prefix, line)] for OBJECTS, from stage_m68k.ref_lines()."""
    import stage_m68k as SM
    import m3_m68k_wide as W
    T = {t['base']: t for t in W.targets()}
    out = []
    for rid, pfx, l in SM.ref_lines():
        f = os.path.basename(l.split()[l.split().index('-o') + 1])
        assert f.startswith(pfx) and f.endswith('.o'), f
        base = f[len(pfx):-2]
        obj = T[base]['object']
        if obj[len('x86-'):] in OBJECTS:
            w = l.split()
            assert w[0] == 'RUN' and '-O2' in w and l.count('stage/' + pfx) == 1, l
            out.append((obj, base, rid, pfx, l))
    assert sorted(o[len('x86-'):] for o, *_ in out) == sorted(OBJECTS), [o for o, *_ in out]
    return out


def cmd_cmd(out):
    L, E = [], []
    for obj, base, rid, pfx, l in selected():
        L.append(l.replace('stage/' + pfx, 'stage/O%d__' % PLAN))
        E.append('EXPECT O%d__%s.o' % (PLAN, base))
    open(out, 'w').write('# m5p%d: plan %d survey compile of %d objects (m5_m68k_survey.py cmd)\n' % (PLAN, PLAN, len(L))
                         + '\n'.join(L + E) + '\n')
    print('commands', len(L))


def cmd_otool(rid, out):
    o = '/ndrv/openstep-kernel-remade/08_build/artifacts/m5p%d/otool' % PLAN
    k = '/ndrv/openstep-kernel-remade/08_build/runs/tools/target/krsha256-default'
    L = ['# plan %d: read-only otool listings of run %s' % (PLAN, rid)]
    for obj, base, *_ in selected():
        p = '/ndrv/openstep-kernel-remade/08_build/runs/%s/out/O%d__%s.o' % (rid, PLAN, base)
        n = 'O%d__%s' % (PLAN, base)
        L.append('/bin/otool -tv %s > %s/%s.txt 2> %s/%s.err; %s %s >> %s/objects.sha' % (p, o, n, o, n, k, p, o))
    open(out, 'w').write('\n'.join(L) + '\n')
    print('lines', len(L) - 1)


def extents():
    rows = list(csv.DictReader([l for l in open(OBJMAP) if not l.startswith('#')], delimiter='\t'))
    out = {}
    for r in rows:
        if r['x86_objects'].startswith('x86-') and r['x86_objects'][4:] in OBJECTS:
            assert r['start_lo'] == r['start_hi'] and r['end_lo'] == r['end_hi'], r['id']
            out[r['x86_objects']] = (r['id'], int(r['start_lo'], 16), int(r['end_lo'], 16))
    assert len(out) == len(OBJECTS)
    return out


def norm(m, o):
    return m + ' ' + re.sub(r'0x[0-9a-fA-F]+', 'N', o)


def align(a, b):
    """a, b: [(addr, mnemonic, operands)] -> blocks [(kind, obj_rows, orig_rows, first obj addr, first orig addr)]."""
    na, nb = [norm(m, o) for _, m, o in a], [norm(m, o) for _, m, o in b]
    out = []
    for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, na, nb, autojunk=False).get_opcodes():
        if tag == 'equal':
            continue
        same_shape = (i2 - i1 == j2 - j1) and [x[1] for x in a[i1:i2]] == [x[1] for x in b[j1:j2]]
        out.append(dict(kind='R' if same_shape else 'S', obj_rows=i2 - i1, orig_rows=j2 - j1,
                        obj_at=hex(a[i1][0]) if i1 < i2 else None, orig_at=hex(b[j1][0]) if j1 < j2 else None))
    return out


def cmd_report(rid, odir, outj):
    import macho_obj
    import m0_m68k_cause as C
    import m0_m68k_l1 as P413
    import m3_m68k_diag as D
    import l2_prefix_diff as PD
    img = C.Img()
    names_img = {y['name'] for y in img.img.o['symbols']}
    osyms = [(int(r['value'], 16), r['name']) for r in csv.DictReader(open(SYMS), delimiter='\t') if r['section'] == '1']
    image_rows = C.read_otool(IMG_LIST)
    EX = extents()
    status = dict(l.split() for l in open(os.path.join('08_build/runs', rid, 'out', '_log', 'status')) if l.strip())
    assert len(status) == len(OBJECTS) and all(v == '0' for v in status.values()), status
    art = '08_build/artifacts/m5p%d/%s' % (PLAN, rid)
    os.makedirs(art, exist_ok=True)
    rows = []
    for obj, base, refrun, pfx, line in selected():
        p = os.path.join('08_build/runs', rid, 'out', 'O%d__%s.o' % (PLAN, base))
        p441 = os.path.join(RUN441, 'O441__%s.o' % base)
        g, g441 = PD.obj_sig(p), PD.obj_sig(p441)
        same441 = dict(canon=D.canon(p) == D.canon(p441), header=g['header'] == g441['header'],
                       sections=g['sections'] == g441['sections'], symbols=g['symbols'] == g441['symbols'])
        oid, S, E = EX[obj]
        b = open(p, 'rb').read()
        o = macho_obj.parse(b)
        ts = [s for s in o['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
        covered, _ = P413.reloc_fields(o, ts)
        oext = sorted((y['value'] - ts['addr'], y['name']) for y in o['symbols']
                      if y['kind'] == 'SECT' and y.get('ext') and not y['stab'] and y['sect'] == ts['index'])
        iext = [(a, n) for a, n in sorted(osyms) if S <= a < E]

        def spans(ext, lo, hi):
            out = []
            if not ext or ext[0][0] > lo:
                out.append(('<prefix>', lo, ext[0][0] if ext else hi))
            for k, (a, n) in enumerate(ext):
                out.append((n, a, ext[k + 1][0] if k + 1 < len(ext) else hi))
            return out
        so = {n: (a, e) for n, a, e in spans(oext, 0, ts['size'])}
        si = {n: (a, e) for n, a, e in spans(iext, S, E)}
        lst = C.read_otool(os.path.join(odir, 'O%d__%s.txt' % (PLAN, base)))
        sp = []
        for n in [x for x in si if x in so]:
            (oa, oe), (ia, ie) = so[n], si[n]
            mine = b[ts['offset'] + oa:ts['offset'] + oe]
            got = img.img.read(ia, ie - ia)
            eq = (oe - oa == ie - ia) and all(mine[j] == got[j] for j in range(len(mine)) if (oa + j) not in covered)
            r = dict(name=n, object=[hex(oa), hex(oe)], original=[hex(ia), hex(ie)], object_len=oe - oa, original_len=ie - ia,
                     masked_equal=eq)
            if not eq:
                a_rows = [x for x in lst if oa <= x[0] < oe]
                b_rows = [x for x in image_rows if ia <= x[0] < ie]
                r['blocks'] = align(a_rows, b_rows)
                r['rows'] = [len(a_rows), len(b_rows)]
            sp.append(r)
        blocks = [bl for r in sp for bl in r.get('blocks', [])]
        score = sum(bl['obj_rows'] + bl['orig_rows'] for bl in blocks)
        d = C.run_l1(p, os.path.join(art, 'l1-%s.json' % obj))
        lp = os.path.join(art, 'l1place-%s.json' % obj)
        q = subprocess.run([sys.executable, os.path.join(HERE, 'l1_compare.py'), '--image', IMG, '--obj', p,
                            '--place', '__TEXT,__text=%#x' % S, '--out', lp], capture_output=True, text=True)
        assert q.returncode == 0, q.stderr[-400:]
        dp = json.load(open(lp))
        fv = [(f['names'], f['verdict']) for f in dp['functions'] if f['section'] == '__TEXT,__text']
        undef = sorted({y['name'] for y in o['symbols'] if y['kind'] == 'UNDF' and not y['stab']} - names_img)
        rows.append(dict(object=obj, base=base, ref_run=refrun, compile_line_sha256=hashlib.sha256(line.encode()).hexdigest(),
                         obj=p, obj_sha256=sha(p), listing_sha256=sha(os.path.join(odir, 'O%d__%s.txt' % (PLAN, base))),
                         same_as_441=same441, map_id=oid, extent=[hex(S), hex(E)], extent_size=E - S, text_size=ts['size'],
                         size_diff=ts['size'] - (E - S), names_only_original=sorted(set(si) - set(so)),
                         names_only_object=sorted(set(so) - set(si)), spans=sp,
                         spans_unequal=[r['name'] for r in sp if not r['masked_equal']],
                         blocks_R=sum(1 for bl in blocks if bl['kind'] == 'R'), blocks_S=sum(1 for bl in blocks if bl['kind'] == 'S'),
                         score=score, l1_verdict=d['object_verdict'], l1_reasons=d.get('object_reasons'),
                         l1place_match=[n for n, v in fv if v == 'MATCH'], l1place_other=[[n, v] for n, v in fv if v != 'MATCH'],
                         undefined_not_in_original=undef,
                         common=sorted((y['name'], y['value']) for y in o['symbols'] if y['kind'] == 'COMMON')))
    rank = sorted(rows, key=lambda r: (r['score'], abs(r['size_diff'])))
    S_ = dict(objects=len(rows), all_same_as_441=all(all(r['same_as_441'].values()) for r in rows),
              ranking=[[r['object'], r['score'], r['size_diff'], r['blocks_R'], r['blocks_S'], len(r['spans_unequal'])] for r in rank])
    json.dump(dict(plan=PLAN, tool='10_tools/reconstruction/m5_m68k_survey.py', tool_sha256=sha(os.path.abspath(__file__)),
                   run=rid, stage=STAGE, stage_manifest_sha256=sha(STAGE + '.manifest.json'), image_sha256=sha(IMG),
                   image_listing_sha256=sha(IMG_LIST), objects_map_sha256=sha(OBJMAP), summary=S_, objects=rows),
              open(outj, 'w'), indent=1)
    print(json.dumps(S_, indent=1))


def main():
    a = sys.argv[1:]
    if a[:1] == ['cmd'] and len(a) == 2:
        cmd_cmd(a[1])
    elif a[:1] == ['otool'] and len(a) == 3:
        cmd_otool(a[1], a[2])
    elif a[:1] == ['report'] and len(a) == 4:
        cmd_report(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
