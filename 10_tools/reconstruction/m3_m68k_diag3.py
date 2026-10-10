#!/usr/bin/env python3
"""m3_m68k_diag3.py -- plan 436 (M3-12): instruction-level diagnosis of the clean NOT_MATCH
objects left undiagnosed after plan 435 (plan 436.1).

  python3 10_tools/reconstruction/m3_m68k_diag3.py RECORD.json

Listings: real-machine otool -tv of the run m3p435-cc1 objects (08_build/artifacts/m3p436/otool,
object hashes checked against the krsha256 list written there) and of the original (plan 414,
checked against class-V10.json).
1. External spans _in_pcbconnect, _panic, _ip_output: normalised, aligned with difflib and
   classified with the plan 431 rules (m3_m68k_diag2.kind); plan 418 end capping is recorded
   but is not used by these spans.
2. x86-ufs_vnodeops: the whole object __text against the original range from 0x403a056 (the
   address where the object's first bytes occur; upper of the undecided plan 418 boundary
   k=130) to the decided boundary k=131; L1's placement (from _rdwri) is not used.  The
   __data references are re-resolved: each object pointer target, relocated to the image
   placement, against the image word.
Read-only apart from the record.
"""
import sys, os, re, json, difflib, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m0_m68k_cause as C
import m3_m68k_diag as D
import m3_m68k_diag2 as D2
import m3_m68k_wide as W

RUN = '08_build/runs/m3p435-cc1/out'
OT = '08_build/artifacts/m3p436/otool'
REC418 = '09_validation/reconstruction/m2-m68k-data-order-20261009.json'
SPANS = [('x86-in_pcb', 'L2_116__in_pcb', '_in_pcbconnect'), ('x86-subr_prf', 'L2_159__subr_prf', '_panic'),
         ('x86-ip_output', 'L2_314__ip_output', '_ip_output')]
UFS = ('x86-ufs_vnodeops', 'L2_158__ufs_vnodeops')
UFS_START = 0x403a056
sha = C.sha


def load(base, shas):
    p = os.path.join(RUN, 'O435__%s.o' % base)
    assert sha(p) == shas['O435__%s.o' % base], p
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
    oins = C.read_otool(os.path.join(OT, 'O435__%s.txt' % base))
    return p, ob, obj, ts, rel, osym, oins


def blocks_of(A, aa, Bn, ba, ts, L):
    mk = lambda S: [(m, C.SYMTOK.sub(lambda q: 'L' if q.group(0).startswith('L+') else q.group(0), x)) for m, x in S]
    sm = difflib.SequenceMatcher(None, mk(A), mk(Bn), autojunk=False)
    out, kinds = [], collections.Counter()
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        if op == 'equal':
            continue
        a_ins, b_ins = A[i1:i2], Bn[j1:j2]
        ca = [x[1] for x in a_ins if x[0] in ('bsr', 'jsr')]
        cb = [x[1] for x in b_ins if x[0] in ('bsr', 'jsr')]
        if op == 'replace' and len(a_ins) == len(b_ins) and not (set(ca) ^ set(cb)):
            ks = collections.Counter(D2.kind(x, y) for x, y in zip(a_ins, b_ins) if x != y)
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
        oa = aa[i1] if i1 < len(aa) else aa[-1]
        off0 = oa - ts['addr']
        out.append(dict(op=op, kind=k, object='0x%x' % oa, image='0x%x' % (ba[j1] if j1 < len(ba) else ba[-1]),
                        lines=sorted({'%s:%d' % (os.path.basename(f or '?'), ln) for a_, f, ln in L if off0 - 4 <= a_ <= off0 + 4})[:4],
                        object_ins=[' '.join(x) for x in a_ins][:8], image_ins=[' '.join(x) for x in b_ins][:8],
                        calls_image_only=sorted(set(cb) - set(ca)), calls_object_only=sorted(set(ca) - set(cb))))
    return out, kinds


def main(out_json):
    shas = {}
    for l in open(os.path.join(OT, 'objects.sha')):
        w = l.split()
        shas[os.path.basename(w[-1])] = w[0]
    cls = json.load(open('08_build/artifacts/m0p414/class-V10.json'))
    assert sha(D.IMG_LIST) == cls['otool_image_sha256']
    img = C.Img()
    iins = C.read_otool(D.IMG_LIST)
    isym = C.Symbolizer(img.img.o['sections'], img.img.o['symbols'], img.img.read)
    B418 = json.load(open(REC418))['boundaries']
    cap = {b['a_last']: b['upper'] for b in B418 if b['decided']}
    rows = []
    T = {t['object']: t for t in W.targets()}
    for obj_name, base, span in SPANS:
        p, ob, obj, ts, rel, osym, oins = load(base, shas)
        xo = macho_obj.parse(open(T[obj_name]['obj'], 'rb').read())   # the x86 object's external __text names (plan 431)
        xt = [s for s in xo['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
        ext = [y['name'] for y in xo['symbols'] if y['kind'] == 'SECT' and y.get('ext') and not y['stab'] and y['sect'] == xt['index']]
        assert span in ext
        _, _, spans = C.compare_object(img, p, ext)
        s = [x for x in spans if x['name'] == span][0]
        sp = C.ext_spans(obj, None, ts, ext)
        o0, o1, statics = sp[span]
        ia = s['image_address']
        iend = ia + s['image_extent']
        capped = cap.get(ia)
        A, aa, na = D.norm_with_addr(oins, ts['addr'] + o0, ts['addr'] + o1, osym,
                                     lambda x, n: ob[ts['offset'] + x - ts['addr']:ts['offset'] + x - ts['addr'] + n], rel)
        Bn, ba, nb = D.norm_with_addr(iins, ia, iend, isym, img.img.read)
        bl, kinds = blocks_of(A, aa, Bn, ba, ts, D.lines_of(obj, ts))
        rows.append(dict(object=obj_name, span=span, equal=s.get('equal'), object_bytes=o1 - o0, image='0x%x' % ia,
                         image_bytes=iend - ia, capping_used=capped is not None and capped < iend,
                         instructions=[len(A), len(Bn)], kinds=dict(kinds), blocks=bl))
    # ufs_vnodeops
    p, ob, obj, ts, rel, osym, oins = load(UFS[1], shas)
    k130 = [b for b in B418 if b['k'] == 130][0]
    k131 = [b for b in B418 if b['k'] == 131][0]
    assert k130['upper'] == UFS_START and not k130['decided'] and k131['decided'] and k131['a'] == UFS[0]
    iend = k131['upper']
    txt = ob[ts['offset']:ts['offset'] + ts['size']]
    first = 36
    start_check = {('0x%x' % a): sum(x != y for x, y in zip(txt[:first], img.img.read(a, first))) for a in (UFS_START, UFS_START - 54)}
    A, aa, na = D.norm_with_addr(oins, ts['addr'], ts['addr'] + ts['size'], osym,
                                 lambda x, n: ob[ts['offset'] + x - ts['addr']:ts['offset'] + x - ts['addr'] + n], rel)
    Bn, ba, nb = D.norm_with_addr(iins, UFS_START, iend, isym, img.img.read)
    bl, kinds = blocks_of(A, aa, Bn, ba, ts, D.lines_of(obj, ts))
    fsym = sorted((y['value'] - ts['addr'], y['name']) for y in obj['symbols']
                  if y['kind'] == 'SECT' and not y['stab'] and y['sect'] == ts['index'] and not y['name'].startswith(('gcc2_', '___gnu')))
    def fn(addr):
        off = int(addr, 16) - ts['addr']
        c = [n for o, n in fsym if o <= off]
        return c[-1] if c else None
    for b in bl:
        b['function'] = fn(b['object'])
    # __data pointers into __text, relocated to the image placement
    dsec = [s for s in obj['sections'] if (s['segname'], s['sectname']) == ('__DATA', '__data')][0]
    l1 = json.load(open('08_build/artifacts/m3p435/l1/l1-x86-ufs_vnodeops.json'))
    dimg = l1['sections']['__DATA,__data']['address']
    ptrs = []
    for r in dsec['relocs']:
        if r['scattered'] or r['extern'] or r['symbolnum'] != ts['index']:
            continue
        off = r['address']
        v = int.from_bytes(ob[dsec['offset'] + off:dsec['offset'] + off + 4], 'big')
        tgt_off = v - ts['addr']
        iw = int.from_bytes(img.img.read(dimg + off, 4), 'big')
        ptrs.append(dict(data_offset=off, object_target=fn('0x%x' % v), object_offset=tgt_off, image_word='0x%x' % iw,
                         shift=iw - (UFS_START + tgt_off)))   # image address minus (start + object offset)
    rows.append(dict(object=UFS[0], span='whole __text from 0x%x' % UFS_START, object_bytes=ts['size'], image='0x%x' % UFS_START,
                     image_bytes=iend - UFS_START, first_bytes_differences=start_check, instructions=[len(A), len(Bn)],
                     kinds=dict(kinds), block_functions=dict(collections.Counter(b['function'] for b in bl)),
                     data_text_pointers=ptrs, blocks=bl))
    S = collections.OrderedDict()
    for r in rows:
        S[r['object'] + ' ' + r['span']] = dict(bytes=[r['object_bytes'], r['image_bytes']], kinds=r['kinds'],
                                                calls_image_only=sorted({c for b in r['blocks'] for c in b['calls_image_only']}),
                                                calls_object_only=sorted({c for b in r['blocks'] for c in b['calls_object_only']}))
    S['ufs_vnodeops_data_pointer_shifts'] = dict(collections.Counter(x['shift'] for x in ptrs))
    S['ufs_vnodeops_shift_by_offset'] = sorted({(x['object_offset'], x['shift']) for x in ptrs})
    json.dump(dict(plan=436, tool='10_tools/reconstruction/m3_m68k_diag3.py', tool_sha256=sha(os.path.abspath(__file__)),
                   listing_dir=OT, image_listing_sha256=cls['otool_image_sha256'], summary=S, rows=rows),
              open(out_json, 'w'), indent=1)
    print(json.dumps(S, indent=1))


if __name__ == '__main__':
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    main(sys.argv[1])
