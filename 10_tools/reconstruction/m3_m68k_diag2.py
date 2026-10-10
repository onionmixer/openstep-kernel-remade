#!/usr/bin/env python3
"""m3_m68k_diag2.py -- plan 431 (M3-7): instruction-level diagnosis of the plan 430 clean-set
objects that are not OBJECT_MATCH (plan 431.1).

  python3 10_tools/reconstruction/m3_m68k_diag2.py RECORD.json

Listings: real-machine otool -tv of the run m3p430-it2 objects (08_build/artifacts/m3p431/otool,
object hashes checked against the krsha256 list written there) and of the original (plan 414).
Image span ends are capped by the plan 418 boundary after the last external symbol of a run.
Blocks: INS (image only) / DEL (object only) / REP, each classified CALL (calls on one side only,
with names and side), IMM (only '#' immediates differ), D-frame (only a6 displacements, link or
movem), D-struct (only displacements on other registers), R (registers only) or X; INS/DEL
blocks are clustered by a normalised signature (registers -> R).
Read-only apart from the record.
"""
import sys, os, re, json, csv, bisect, difflib, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m0_m68k_cause as C
import m3_m68k_diag as D
import m3_m68k_wide as W

REC430 = '09_validation/reconstruction/m3-m68k-machdep-20261009.json'
REC418 = '09_validation/reconstruction/m2-m68k-data-order-20261009.json'
OT = '08_build/artifacts/m3p431/otool'
RUN = '08_build/runs/m3p430-it2/out'
REG = re.compile(r'\b([ad][0-7]|sp|fp)\b')
sha = C.sha


def kind(a, b):
    """classification of one replaced pair of normalised instructions."""
    (ma, oa), (mb, ob) = a, b
    calls = ('bsr', 'jsr')
    if ma != mb:
        return 'X'
    if REG.sub('R', oa) == REG.sub('R', ob) and oa != ob:
        return 'R'
    na, nb = re.sub(r'#[-0-9a-fx:wbl]+', '#N', oa), re.sub(r'#[-0-9a-fx:wbl]+', '#N', ob)
    if na == nb:
        return 'IMM'
    fa, fb = re.sub(r'a6@\(0x[0-9a-f]+:[wb]\)', 'a6@(F)', oa), re.sub(r'a6@\(0x[0-9a-f]+:[wb]\)', 'a6@(F)', ob)
    if fa == fb or ma in ('linkw', 'moveml'):
        return 'D-frame'
    sa, sb = re.sub(r'@\(0x[0-9a-f]+:[wb]\)', '@(D)', oa), re.sub(r'@\(0x[0-9a-f]+:[wb]\)', '@(D)', ob)
    if sa == sb:
        return 'D-struct'
    return 'X'


def main(out_json):
    R430 = json.load(open(REC430))
    clean = [o for o in R430['objects'] if o['verdict'] != 'OBJECT_MATCH' and o['grade'] == 'A' and o['i386_slice'] == 'OBJECT_MATCH']
    assert len(clean) == 27
    T = {t['object']: t for t in W.targets()}
    shas = {}
    for l in open(os.path.join(OT, 'objects.sha')):
        w = l.split()
        shas[os.path.basename(w[-1])] = w[0]
    cls = json.load(open('08_build/artifacts/m0p414/class-V10.json'))
    assert sha(D.IMG_LIST) == cls['otool_image_sha256']
    img = C.Img()
    iins = C.read_otool(D.IMG_LIST)
    isym = C.Symbolizer(img.img.o['sections'], img.img.o['symbols'], img.img.read)
    isyms = {y['name'] for y in img.img.o['symbols']}
    B418 = json.load(open(REC418))['boundaries']
    cap = {b['a_last']: b['upper'] for b in B418 if b['decided']}
    rows, sigs, calls_img, calls_obj = [], collections.Counter(), collections.Counter(), collections.Counter()
    for o in clean:
        t = T[o['object']]
        p = os.path.join(RUN, 'M430__%s.o' % t['base'])
        assert sha(p) == shas['M430__%s.o' % t['base']], p
        ob = open(p, 'rb').read()
        obj = macho_obj.parse(ob)
        ts = [s for s in obj['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
        names = {i: y['name'] for i, y in enumerate(obj['symbols'])}
        rel = []
        for r in ts['relocs']:
            r = dict(r)
            if not r['scattered'] and r['extern']:
                r['symname'] = names[r['symbolnum']]
            r['address'] += ts['addr']
            rel.append(r)
        osym = C.Symbolizer(obj['sections'], obj['symbols'], lambda x, n: C.obj_read(obj, ob, x, n))
        oins = C.read_otool(os.path.join(OT, 'M430__%s.txt' % t['base']))
        xo = macho_obj.parse(open(t['obj'], 'rb').read())
        xt = [s for s in xo['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')]
        ext = [y['name'] for y in xo['symbols'] if xt and y['kind'] == 'SECT' and y.get('ext') and not y['stab'] and y['sect'] == xt[0]['index']]
        _, _, spans = C.compare_object(img, p, ext)
        L = D.lines_of(obj, ts)
        sp = C.ext_spans(obj, None, ts, ext)
        for s in spans:
            if 'image_address' not in s or s.get('equal'):
                continue
            name = s['name']
            o0, o1, statics = sp[name]
            ia = s['image_address']
            iend = ia + s['image_extent']
            capped = cap.get(ia)
            if capped is not None and capped < iend:
                iend = capped
            A, aa, na = D.norm_with_addr(oins, ts['addr'] + o0, ts['addr'] + o1, osym,
                                         lambda x, n: ob[ts['offset'] + x - ts['addr']:ts['offset'] + x - ts['addr'] + n], rel)
            Bn, ba, nb = D.norm_with_addr(iins, ia, iend, isym, img.img.read)
            mk = lambda S: [(m, C.SYMTOK.sub(lambda q: 'L' if q.group(0).startswith('L+') else q.group(0), x)) for m, x in S]
            sm = difflib.SequenceMatcher(None, mk(A), mk(Bn), autojunk=False)
            blocks, kinds = [], collections.Counter()
            for op, i1, i2, j1, j2 in sm.get_opcodes():
                if op == 'equal':
                    continue
                a_ins, b_ins = A[i1:i2], Bn[j1:j2]
                ca = [x[1] for x in a_ins if x[0] in ('bsr', 'jsr')]
                cb = [x[1] for x in b_ins if x[0] in ('bsr', 'jsr')]
                if op == 'replace' and len(a_ins) == len(b_ins) and not (set(ca) ^ set(cb)):
                    ks = collections.Counter(kind(x, y) for x, y in zip(a_ins, b_ins) if x != y)
                    k = 'X' if 'X' in ks else ('D-struct' if 'D-struct' in ks else ('IMM' if 'IMM' in ks else
                                                ('D-frame' if 'D-frame' in ks else 'R')))
                elif set(ca) ^ set(cb):
                    k = 'CALL'
                elif op == 'insert':
                    k = 'INS'
                elif op == 'delete':
                    k = 'DEL'
                else:
                    k = 'X'
                kinds[k] += 1
                sig = None
                if k in ('INS', 'DEL'):
                    sig = k + ' ' + '; '.join(REG.sub('R', ' '.join(x)) for x in (b_ins if k == 'INS' else a_ins))[:160]
                    sigs[sig] += 1
                for c in set(cb) - set(ca):
                    calls_img[c] += 1
                for c in set(ca) - set(cb):
                    calls_obj[c] += 1
                off0 = (aa[i1] if i1 < len(aa) else aa[-1]) - ts['addr']
                blocks.append(dict(op=op, kind=k, object='0x%x' % (aa[i1] if i1 < len(aa) else aa[-1]),
                                   image='0x%x' % (ba[j1] if j1 < len(ba) else ba[-1]),
                                   lines=sorted({'%s:%d' % (os.path.basename(f or '?'), ln) for a_, f, ln in L if off0 - 4 <= a_ <= off0 + 4})[:4],
                                   object_ins=[' '.join(x) for x in a_ins][:6], image_ins=[' '.join(x) for x in b_ins][:6],
                                   signature=sig, calls_image_only=sorted(set(cb) - set(ca)), calls_object_only=sorted(set(ca) - set(cb))))
            prio = ['CALL', 'INS', 'DEL', 'IMM', 'D-struct', 'X', 'R', 'D-frame']
            primary = next((k for k in prio if kinds[k]), 'none')
            rows.append(dict(object=o['object'], span=name, image='0x%x' % ia, image_end='0x%x' % iend, capped=capped is not None and capped == iend,
                             now_equal=not blocks, kinds=dict(kinds), primary=primary, blocks=blocks))
    S = collections.OrderedDict()
    S['spans'] = len(rows)
    S['equal_after_capping'] = [r['object'] + ' ' + r['span'] for r in rows if r['now_equal']]
    S['primary'] = dict(collections.Counter(r['primary'] for r in rows if not r['now_equal']))
    S['ins_del_signatures'] = [[k, v] for k, v in sigs.most_common(15)]
    S['calls_image_only'] = dict(calls_img.most_common(30))
    S['calls_object_only'] = dict(calls_obj.most_common(30))
    S['d_struct_blocks'] = sum(r['kinds'].get('D-struct', 0) for r in rows)
    json.dump(dict(plan=431, tool='10_tools/reconstruction/m3_m68k_diag2.py', tool_sha256=sha(os.path.abspath(__file__)),
                   listing_dir=OT, image_listing_sha256=cls['otool_image_sha256'], summary=S, spans=rows), open(out_json, 'w'), indent=1)
    print(json.dumps(S, indent=1))


if __name__ == '__main__':
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    main(sys.argv[1])
