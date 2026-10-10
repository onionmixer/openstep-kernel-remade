#!/usr/bin/env python3
"""m2_m68k_data_map.py -- plan 419 (M2-5): candidate object map of the m68k original's __DATA,__data
and __TEXT,__const, with observations on __cstring, __bss and __common.

  python3 10_tools/reconstruction/m2_m68k_data_map.py MAP.tsv RECORD.json

Function owners are the plan 418 final owners (m2_m68k_data_order.main(extend=True)).  Code
references are the listing's 32-bit values, with or without the ':l' suffix.  The owner of a
referenced data address is the owner token shared by every referencing function (an unassigned
referencing function leaves it unresolved).
Anchors: (a) external data symbols defined directly by one x86 object; (b) other referenced data
addresses and m68k-only external data symbols, accepted with the plan 418 item rule: owner equal to
the owner of the nearest external data symbol before or after, or (plan 418.2) the nearest external
data symbols on both sides defined directly by x86 objects with link positions and the owner's
position between theirs.  Runs are address-ordered anchors of one owner; a boundary is only the
interval (last anchor of A, first anchor of B].  Unreferenced, unnamed data is not placed.
__cstring literals are merged by the link editor across objects (NeXT assembler manual), so its
owner order is descriptive only.  Zero-fill sections (__bss, __common) have no file bytes.
Validation: the plan 414 V10 data spans placed in the original (OBJECT_MATCH, and NOT_MATCH spans
with equal bytes and references) and the five plan 418 negative addresses.
Read-only apart from the two output files.
"""
import sys, os, re, json, csv, bisect, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m2_m68k_boundaries as B416
import m2_m68k_data_order as D418
import m2_m68k_text_map as T415

IMG, IMG_SHA, MAP, GRID, REC409 = D418.IMG, D418.IMG_SHA, D418.MAP, D418.GRID, D418.REC409
REC418 = '09_validation/reconstruction/m2-m68k-data-order-20261009.json'
NEGATIVE = D418.NEGATIVE
sha = D418.sha
VAL = re.compile(r'(?<![0-9a-fx])0x([0-9a-f]+)(?::l)?(?![0-9a-f:])')
MAPPED_SECTS = (('__DATA', '__data'), ('__TEXT', '__const'))


def main(out_tsv, out_json):
    res = D418.main(extend=True)
    R418 = json.load(open(REC418))
    assert res['S']['decided'] == R418['summary']['decided'] and res['S']['newly_owned'] == R418['summary']['newly_owned']
    final, entries, tname = res['final'], res['entries'], res['tname']
    ib = open(IMG, 'rb').read()
    img = macho_obj.parse(ib)
    secs = {(s['segname'], s['sectname']): s for s in img['sections']}
    bysec = {s['index']: s for s in img['sections']}
    M = json.load(open(MAP))
    klass = {o['n']: o['klass'] for o in M['objects']}
    runs = []
    for g in M['groups']:
        if runs and runs[-1]['owner'] == g['owner']:
            runs[-1]['first'] = runs[-1]['first']
        else:
            runs.append(dict(owner=g['owner'], first=int(g['address'], 16)))
    pos = {}
    for k, r in enumerate(runs):
        t = ('obj', r['owner']) if r['owner'] is not None else ('unmapped', k)
        if t[0] == 'unmapped' or klass[t[1]] == 'contiguous':
            pos.setdefault(t, r['first'])

    def sec_of(v):
        for s in img['sections']:
            if s['addr'] <= v < s['addr'] + s['size']:
                return s
        return None

    def func_of(a):
        k = bisect.bisect_right(entries, a) - 1
        return entries[k] if k >= 0 else None

    # code references to data (both operand forms)
    cref = collections.defaultdict(set)
    zf_refs = collections.Counter()
    for a, m, o in B416.read_listing():
        for t in VAL.findall(o):
            v = int(t, 16)
            s = sec_of(v)
            if s is None or s['sectname'] == '__text':
                continue
            if s['flags'] & 0xff == 1:                      # zero-fill: counted only
                zf_refs[s['sectname']] += 1
                continue
            cref[v].add(func_of(a))

    def code_owner(v):
        os_ = {final.get(f) if f is not None else None for f in cref.get(v, ())}
        if len(os_) == 1:
            o = next(iter(os_))
            return o if isinstance(o, tuple) else None
        return None

    # x86 data definitions and COMMON declarations
    rec409 = json.load(open(REC409))['slice']['objects']
    x86data, x86common = {}, collections.defaultdict(set)
    for o in rec409:
        assert sha(o['obj']) == o['obj_sha256']
        ob = macho_obj.parse(open(o['obj'], 'rb').read())
        osec = {s['index']: (s['segname'], s['sectname']) for s in ob['sections']}
        for y in ob['symbols']:
            if y['stab'] or not y.get('ext'):
                continue
            if y['kind'] == 'SECT' and osec[y['sect']] != ('__TEXT', '__text'):
                x86data[y['name']] = o['n']
            elif y['kind'] == 'COMMON':
                x86common[y['name']].add(o['n'])

    S = collections.OrderedDict()
    TSV, maps = [], {}
    for key in MAPPED_SECTS:
        s = secs[key]
        lo, hi = s['addr'], s['addr'] + s['size']
        ext = collections.defaultdict(list)
        for y in img['symbols']:
            if y['kind'] == 'SECT' and not y['stab'] and y.get('ext') and lo <= y['value'] < hi:
                ext[y['value']].append(y['name'])
        E = sorted(ext)

        def ext_owner(a):
            xs = {x86data[n] for n in ext[a] if n in x86data}
            if len(xs) == 1:
                return ('obj', xs.pop())
            return None if xs else code_owner(a)

        def direct(a):
            xs = {x86data[n] for n in ext[a] if n in x86data}
            return ('obj', xs.pop()) if len(xs) == 1 else None

        def accept(v, o):
            j = bisect.bisect_left(E, v) - 1
            before = E[j] if j >= 0 else None
            k = bisect.bisect_right(E, v)
            after = E[k] if k < len(E) else None
            if o in (ext_owner(before) if before is not None else None, ext_owner(after) if after is not None else None):
                return 'plan 417'
            if before is None and after is None:
                return None
            P = direct(before) if before is not None else None
            Q = direct(after) if after is not None else None
            if (before is not None and (P is None or P not in pos)) or (after is not None and (Q is None or Q not in pos)):
                return None
            if o not in pos:
                return None
            if (P is None or pos[P] <= pos[o]) and (Q is None or pos[o] <= pos[Q]):
                return 'plan 418.2'
            return None

        anchors, rejected = [], collections.Counter()
        for a in E:
            d = direct(a)
            if d is not None:
                anchors.append((a, d, 'a'))
                continue
            o = code_owner(a)
            if o is None:
                rejected['m68k-only external: no single owner'] += 1
                continue
            r = accept(a, o)
            if r:
                anchors.append((a, o, 'b ' + r))
            else:
                rejected['m68k-only external: rule'] += 1
        for v in sorted(x for x in cref if lo <= x < hi and x not in ext):
            o = code_owner(v)
            if o is None:
                rejected['reference: no single owner'] += 1
                continue
            r = accept(v, o)
            if r:
                anchors.append((v, o, 'b ' + r))
            else:
                rejected['reference: rule'] += 1
        anchors.sort()
        R = []
        for a, o, kd in anchors:
            if R and R[-1]['owner'] == o:
                R[-1]['anchors'].append((a, kd))
            else:
                R.append(dict(owner=o, anchors=[(a, kd)]))
        cnt = collections.Counter(r['owner'] for r in R)
        ps = [pos[r['owner']] for r in R if r['owner'] in pos]
        maps[key] = R
        S['%s,%s' % key] = dict(size=s['size'], external=len(E), anchors=dict(collections.Counter(k.split()[0] for _, _, k in anchors)),
                                anchors_by_rule=dict(collections.Counter(k for _, _, k in anchors)), rejected=dict(rejected),
                                runs=len(R), owners=len(cnt), split_owners=sorted(tname(o) for o, c in cnt.items() if c > 1),
                                positioned_runs=len(ps), positioned_lis=len(T415.lis(ps)),
                                unmapped_runs=sum(1 for r in R if r['owner'][0] == 'unmapped'))
        for i, r in enumerate(R):
            nxt = R[i + 1]['anchors'][0][0] if i + 1 < len(R) else hi
            TSV.append(['%s,%s' % key, i, '0x%x' % r['anchors'][0][0], '0x%x' % r['anchors'][-1][0], '0x%x' % nxt,
                        tname(r['owner']), sum(1 for _, k in r['anchors'] if k == 'a'),
                        sum(1 for _, k in r['anchors'] if k != 'a'), cnt[r['owner']] > 1])

    # validation
    G = json.load(open(GRID))
    byname = collections.defaultdict(list)
    for o in M['objects']:
        byname[o['object']].append(o['n'])
    VR, vbytes = [], collections.Counter()
    for r in G['objects']:
        if r['variant'] != 'V10':
            continue
        d = json.load(open(os.path.join('08_build/artifacts/m0p414/l1', 'l1-V10-%s.json' % r['object'])))
        n = byname[r['object']][0]
        for key in MAPPED_SECTS:
            sk = '%s,%s' % key
            sd = d['sections'].get(sk)
            if not sd or d['placements'].get(sk) is None:
                continue
            if not (r['verdict'] == 'OBJECT_MATCH' or (sd.get('byte_differences') == 0 and sd.get('refs_differ') == 0
                                                         and sd.get('refs_unverified') == 0)):
                continue
            start, end = d['placements'][sk], d['placements'][sk] + sd['size']
            vbytes[sk] += sd['size']
            R = maps[key]
            inside = [(a, o) for rr in R for a, _ in rr['anchors'] for o in [rr['owner']] if start <= a < end]
            mine = [i for i, rr in enumerate(R) if rr['owner'] == ('obj', n)]
            v = dict(object=r['object'], section=sk, start='0x%x' % start, end='0x%x' % end,
                     anchors_inside=len(inside), foreign_inside=sum(1 for _, o in inside if o != ('obj', n)),
                     runs=len(mine))
            if mine:
                first = R[mine[0]]['anchors'][0][0]
                last = R[mine[-1]]['anchors'][-1][0]
                v['own_anchors_in_range'] = start <= first and last < end
                i0, i1 = mine[0], mine[-1]
                if i0 > 0:
                    v['start_side'] = R[i0 - 1]['anchors'][-1][0] < start <= first
                if i1 + 1 < len(R):
                    v['end_side'] = last < end <= R[i1 + 1]['anchors'][0][0]
            VR.append(v)
    neg = []
    for a in NEGATIVE:
        hit = [(tname(rr['owner']), k) for key in MAPPED_SECTS for rr in maps[key] for aa, k in rr['anchors'] if aa == a]
        foreign = code_owner(a)
        neg.append(dict(address='0x%x' % a, anchor=hit, referencing_owner=tname(foreign) if foreign else None,
                        passed=not any(h[0] == tname(foreign) for h in hit) if foreign else True))
    V = dict(ranges=len(VR), anchorless=[v['object'] + ' ' + v['section'] for v in VR if not v['anchors_inside'] and not v['runs']],
             foreign_anchors_inside=sum(v['foreign_inside'] for v in VR),
             own_anchors_out_of_range=sum(1 for v in VR if v.get('own_anchors_in_range') is False),
             split=sum(1 for v in VR if v['runs'] > 1),
             sides_tested=sum(('start_side' in v) + ('end_side' in v) for v in VR),
             sides_failed=sum((v.get('start_side') is False) + (v.get('end_side') is False) for v in VR),
             validated_bytes={k: [b, round(100.0 * b / secs[tuple(k.split(','))]['size'], 2)] for k, b in vbytes.items()},
             negative=neg)
    S['validation'] = V

    # observations: __cstring, __bss, __common
    cs = secs[('__TEXT', '__cstring')]
    cb = ib[cs['offset']:cs['offset'] + cs['size']]
    lit = collections.defaultdict(set)
    for v, fs in cref.items():
        if cs['addr'] <= v < cs['addr'] + cs['size']:
            k = v - cs['addr']
            st = cb.rfind(b'\0', 0, k) + 1
            lit[cs['addr'] + st] |= fs
    lo_ = {}
    for a, fs in lit.items():
        os_ = {final.get(f) if f is not None else None for f in fs}
        lo_[a] = next(iter(os_)) if len(os_) == 1 and isinstance(next(iter(os_)), tuple) else (
            'multiple' if len({x for x in os_ if isinstance(x, tuple)}) > 1 else 'unresolved')
    seq = []
    for a in sorted(lo_):
        o = lo_[a]
        if isinstance(o, tuple) and o in pos and (not seq or seq[-1] != o):
            seq.append(o)
    S['__TEXT,__cstring'] = dict(size=cs['size'], referenced_addresses=sum(1 for v in cref if cs['addr'] <= v < cs['addr'] + cs['size']),
                                 literals=len(lit), single=sum(1 for o in lo_.values() if isinstance(o, tuple)),
                                 multiple=sum(1 for o in lo_.values() if o == 'multiple'),
                                 unresolved=sum(1 for o in lo_.values() if o == 'unresolved'),
                                 positioned_owner_runs=len(seq), positioned_lis=len(T415.lis([pos[o] for o in seq])),
                                 note='literals are merged by the link editor across objects; descriptive only')
    com = [y['name'] for y in img['symbols'] if y['kind'] == 'SECT' and not y['stab'] and bysec[y['sect']]['sectname'] == '__common']
    S['__DATA,__common'] = dict(size=secs[('__DATA', '__common')]['size'], external=len(com),
                                x86_common_names=sum(1 for n in com if n in x86common),
                                x86_common_in_several_objects=sum(1 for n in com if len(x86common.get(n, ())) > 1),
                                x86_data_defined=sum(1 for n in com if n in x86data), code_references=zf_refs['__common'],
                                note='COMMON declarations only; no exclusive ownership, order or m68k size')
    S['__DATA,__bss'] = dict(size=secs[('__DATA', '__bss')]['size'],
                             symbols=sum(1 for y in img['symbols'] if y['kind'] == 'SECT' and not y['stab']
                                         and bysec[y['sect']]['sectname'] == '__bss'),
                             code_references=zf_refs['__bss'])

    with open(out_tsv, 'w') as f:
        f.write('# plan 419: m68k __data/__const candidate object runs by anchors (x86-defined external data symbols, '
                'accepted code-referenced addresses); next_first is only an upper bound (m2_m68k_data_map.py)\n')
        w = csv.writer(f, delimiter='\t', lineterminator='\n')
        w.writerow(['section', 'seq', 'first_anchor', 'last_anchor', 'next_first', 'owner', 'anchors_a', 'anchors_b', 'owner_split'])
        for row in TSV:
            w.writerow(row[:8] + [int(row[8])])
    json.dump(dict(plan=419, tool='10_tools/reconstruction/m2_m68k_data_map.py', tool_sha256=sha(os.path.abspath(__file__)),
                   m2_m68k_data_order_sha256=sha(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'm2_m68k_data_order.py')),
                   image=dict(path=IMG, sha256=IMG_SHA), plan418=dict(path=REC418, sha256=sha(REC418)),
                   map=dict(path=MAP, sha256=sha(MAP)), grid=dict(path=GRID, sha256=sha(GRID)), outputs={out_tsv: sha(out_tsv)},
                   note='Candidate data map: runs are anchor intervals, not byte ownership; unreferenced unnamed data is not placed; '
                        'unmapped#k owners are plan 415 runs, not identified objects.',
                   summary=S, validation_detail=VR,
                   runs={'%s,%s' % k: [dict(owner=tname(r['owner']), anchors=[['0x%x' % a, kd] for a, kd in r['anchors']])
                                       for r in v] for k, v in maps.items()}), open(out_json, 'w'), indent=1)
    print(json.dumps(S, indent=1))


if __name__ == '__main__':
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    main(*sys.argv[1:])
