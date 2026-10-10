#!/usr/bin/env python3
"""m3_m68k_diag.py -- plan 428 (M3-4): instruction-level diagnosis of the four NOT_MATCH m68k
objects left after plan 427 (no compile; plan 428.1).

  python3 10_tools/reconstruction/m3_m68k_diag.py RECORD.json

1. The K427 objects (run m3p427-cc1) equal the V10 objects (run m0p414-fg2) in every section's
   bytes and in their relocations with external symbol numbers replaced by names (asserted),
   so the plan 414 real-machine otool listings of the V10 objects are reused.
2. Every unequal external span is normalised as in plan 414 (m0_m68k_cause.norm_span) with the
   address of each normalised item kept, aligned with difflib (branch targets masked), and each
   differing block gets object/image addresses, the object function (local symbols included),
   the image function (plan 424 table) and 07 source lines from N_SLINE stabs (address ranges;
   file from N_SO/N_SOL in symbol order).
Read-only apart from the record.
"""
import sys, os, re, json, csv, bisect, difflib, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m0_m68k_cause as C

OBJS = ['x86-ip_icmp', 'x86-kern_uname', 'x86-tcp_input', 'x86-vfs_dnlc']
V10 = '08_build/runs/m0p414-fg2/out/V10__%s.o'
K427 = '08_build/runs/m3p427-cc1/out/K427__%s.o'
LIST = '08_build/artifacts/m0p414/otool-V10/%s.txt'
IMG_LIST = '08_build/artifacts/m0p414/otool-V10/image.txt'
CLASS = '08_build/artifacts/m0p414/class-V10.json'
REC427 = '09_validation/reconstruction/m3-m68k-gdb-20261009.json'
FUNCS = '06_reconstruction/m68k-functions.tsv'
sha = C.sha


def canon(p):
    b = open(p, 'rb').read()
    o = macho_obj.parse(b)
    nm = {i: y['name'] for i, y in enumerate(o['symbols'])}
    out = {}
    for s in o['sections']:
        rel = [(r['address'], nm[r['symbolnum']] if (not r['scattered'] and r['extern']) else r.get('symbolnum', r.get('value')),
                r['length'], r['pcrel'], r['type'], r['scattered']) for r in s['relocs']]
        out['%s,%s' % (s['segname'], s['sectname'])] = (b[s['offset']:s['offset'] + s['size']] if s['offset'] else s['size'], rel)
    return out


def norm_with_addr(ins, lo, hi, symz, rd, relocs=None):
    out, notes = C.norm_span(ins, lo, hi, symz, rd, relocs)
    rows = [x for x in ins if lo <= x[0] < hi]
    tables = [tuple(int(v) for v in re.findall(r'(\d+)', n)) for n in notes if n.startswith('table')]
    addrs, ri, tk = [], 0, 0
    skip_to = None
    for item in out:
        if item[0] == '.long':
            base = lo + tables[tk - 1][1]
            k = sum(1 for a in addrs if a is not None and base <= a < base + 4 * tables[tk - 1][0])
            addrs.append(base + 4 * k)
            skip_to = base + 4 * tables[tk - 1][0]
            continue
        while ri < len(rows) and skip_to is not None and rows[ri][0] < skip_to:
            ri += 1
        skip_to = None
        addrs.append(rows[ri][0])
        if rows[ri][1] == 'jmp' and re.fullmatch(r'a[0-7]@', rows[ri][2]) and tk < len(tables):
            tk += 1
        ri += 1
    assert len(addrs) == len(out)
    return out, addrs, notes


def lines_of(obj, ts):
    """[(address, file, line)] from N_SO/N_SOL/N_SLINE in symbol order."""
    cur, out = None, []
    for y in obj['symbols']:
        if not y['stab']:
            continue
        t = y['type']
        if t in (0x64, 0x84) and y['name']:
            cur = y['name']
        elif t == 0x44:
            out.append((y['value'] - ts['addr'], cur, y['desc'] & 0xffff))
    return sorted(out, key=lambda x: x[0])


def main(out_json):
    T = {t['object']: t for t in json.load(open(C.TARGETS))['targets']}
    cls = json.load(open(CLASS))
    assert C.sha(IMG_LIST) == cls['otool_image_sha256']
    R427 = {r['object']: r for r in json.load(open(REC427))['objects']}
    img = C.Img()
    iins = C.read_otool(IMG_LIST)
    isym = C.Symbolizer(img.img.o['sections'], img.img.o['symbols'], img.img.read)
    F = [r for r in csv.DictReader(open(FUNCS).read().splitlines()[1:], delimiter='\t')]
    fst = sorted((int(r['entry'], 16), int(r['end'], 16), r['names'] or 'unnamed@' + r['entry']) for r in F)

    def img_func(a):
        j = bisect.bisect_right([x[0] for x in fst], a) - 1
        return fst[j][2] if j >= 0 and fst[j][0] <= a < fst[j][1] else None
    rows = []
    for on in OBJS:
        t = T[on]
        v, k = V10 % t['base'], K427 % t['base']
        eq = canon(v) == canon(k)
        assert eq, 'V10 and K427 differ: ' + on
        ob = open(v, 'rb').read()
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
        oins = C.read_otool(LIST % t['base'])
        ofs = sorted((y['value'] - ts['addr'], y['name']) for y in obj['symbols']
                     if y['kind'] == 'SECT' and not y['stab'] and y['sect'] == ts['index']
                     and not y['name'].startswith(('gcc2_compiled', '___gnu_compiled')))
        L = lines_of(obj, ts)

        def obj_func(off):
            j = bisect.bisect_right([x[0] for x in ofs], off) - 1
            return ofs[j][1] if j >= 0 else None

        def lines_at(o0, o1):
            return sorted({'%s:%d' % (os.path.basename(f or '?'), ln) for a, f, ln in L if o0 <= a <= o1})
        unequal = [n for n, e in R427[on]['spans'].items() if not e]
        sp = C.ext_spans(obj, None, ts, t['ext_text_symbols'])
        for name in unequal:
            o0, o1, statics = sp[name]
            ia = img.img.symbol(name)
            A, aa, na = norm_with_addr(oins, ts['addr'] + o0, ts['addr'] + o1, osym,
                                       lambda x, n: ob[ts['offset'] + x - ts['addr']:ts['offset'] + x - ts['addr'] + n], rel)
            B, ba, nb = norm_with_addr(iins, ia, ia + img.extent(ia), isym, img.img.read)
            mk = lambda S: [(m, C.SYMTOK.sub(lambda q: 'L' if q.group(0).startswith('L+') else q.group(0), o)) for m, o in S]
            sm = difflib.SequenceMatcher(None, mk(A), mk(B), autojunk=False)
            blocks = []
            for op, i1, i2, j1, j2 in sm.get_opcodes():
                if op == 'equal':
                    continue
                oa = aa[i1:i2] or [aa[i1 - 1] if i1 else aa[0]]
                ib = ba[j1:j2] or [ba[j1 - 1] if j1 else ba[0]]
                off0, off1 = oa[0] - ts['addr'], oa[-1] - ts['addr']
                blocks.append(dict(op=op, object=[hex(oa[0]), hex(oa[-1])], image=[hex(ib[0]), hex(ib[-1])],
                                   object_function=obj_func(off0), image_function=img_func(ib[0]),
                                   lines=lines_at(off0 - 4 if op == 'insert' else off0, off1 + (4 if op == 'insert' else 0)),
                                   object_ins=[' '.join(x) for x in A[i1:i2]][:8], image_ins=[' '.join(x) for x in B[j1:j2]][:8]))
            rows.append(dict(object=on, span=name, object_span=[o0, o1], statics=statics, image=hex(ia), image_extent=img.extent(ia),
                             instructions=[len(A), len(B)], notes=[na, nb], blocks=blocks))
            print('==', on, name, 'blocks', len(blocks), [len(A), len(B)])
            for b in blocks:
                print('  ', b['op'], b['object'], b['image'], b['object_function'], '|', b['image_function'], b['lines'][:4])
                print('      obj:', b['object_ins'][:4]); print('      img:', b['image_ins'][:4])
    json.dump(dict(plan=428, tool='10_tools/reconstruction/m3_m68k_diag.py', tool_sha256=sha(os.path.abspath(__file__)),
                   v10_equals_k427=True, image_listing_sha256=cls['otool_image_sha256'],
                   objects={on: dict(v10=V10 % T[on]['base'], v10_sha256=sha(V10 % T[on]['base']),
                                     k427_sha256=sha(K427 % T[on]['base'])) for on in OBJS},
                   spans=rows), open(out_json, 'w'), indent=1)


if __name__ == '__main__':
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    main(sys.argv[1])
