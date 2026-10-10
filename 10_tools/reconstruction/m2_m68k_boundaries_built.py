#!/usr/bin/env python3
"""m2_m68k_boundaries_built.py -- plan 439 (M3-15): undecided plan 418 __text boundaries decided
with the rebuilt m68k objects (run m3p438-cc1) (plan 439.1).

  python3 10_tools/reconstruction/m2_m68k_boundaries_built.py [--plan 440] TABLE.tsv RECORD.json

--plan 440 (plan 440.1; set after the plan 439 result, by user instruction): rule 4 for a
boundary where neither side is OBJECT_MATCH and rules 1-3/gate did not decide: the a object's
last min(size, 64) __text bytes (masked) end at an image entry point c that also starts b's
masked head (rule 3); exactly one such c in [lower, upper].  Tests: rule 4 on the decided
boundaries with the wide window (0 wrong required), cross-pair specificity (other objects'
tails / heads at the true boundary), +-2/+-4 shifts of the decision.

Rules (pre-registered, plan 439.1), for a boundary whose two sides are both rebuilt objects:
  1. b OBJECT_MATCH: boundary = b's L1 __text address.
  2. a OBJECT_MATCH: boundary = a's L1 __text address + size.
  3. neither: b's first min(size, 64) __text bytes, relocation fields masked (scattered PAIR
     entries skipped, 1 << r_length bytes otherwise), equal at exactly one image entry point
     (06_reconstruction/m68k-functions.tsv) in [lower, upper]; several -> abstain.
  Every value must lie in [lower, upper]; values from several rules must agree.
  A rule-3 value is accepted only with an a-side gate: the whole a object against the image
  range [a start (decided boundary), value) compared as in plan 436 (m3_m68k_diag3 blocks):
  object-minus-image bytes == object size - range size, object-only calls only _byte_swap_*,
  no image-only calls, every other block 0 bytes.
Negative tests: rules 1/2 against every decided boundary with both sides rebuilt; rule 3 with
the window (a_last, b_first] over the same boundaries (0 wrong required); +-2/+-4 shifts.
Outputs: TABLE.tsv = the plan 418 table with decided_439, boundary_439, basis_439 appended;
RECORD.json.  The plan 418 table and record are not changed.
"""
import sys, os, re, csv, json, glob, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m0_m68k_cause as C
import m3_m68k_wide as W
import m3_m68k_diag as D
import m3_m68k_diag3 as D3

REC418 = '09_validation/reconstruction/m2-m68k-data-order-20261009.json'
TAB418 = '06_reconstruction/m68k-text-boundaries-order.tsv'
OBJS = '06_reconstruction/m68k-objects.tsv'
FUNCS = '06_reconstruction/m68k-functions.tsv'
RUN = '08_build/runs/m3p438-cc1/out'
L1 = '08_build/artifacts/m3p438/l1'
OTOOL = {'x86-ufs_vfsops': '08_build/artifacts/m3p439/otool'}
N = 64
sha = C.sha


def masked_head(o, ob, ts):
    n = min(ts['size'], N)
    head = bytearray(ob[ts['offset']:ts['offset'] + n])
    mask = [False] * n
    for r in ts['relocs']:
        if r['scattered'] and r.get('type') == 1:      # PAIR entry: not a field location
            continue
        a = r['address']
        for i in range(a, min(a + (1 << r['length']), n)):
            if i >= 0:
                mask[i] = True
    return bytes(head), mask


def masked_tail(o, ob, ts):
    """plan 440: last min(size, N) bytes of __text and their relocation-field mask."""
    n = min(ts['size'], N)
    s0 = ts['size'] - n
    tail = bytes(ob[ts['offset'] + s0:ts['offset'] + ts['size']])
    mask = [False] * n
    for r in ts['relocs']:
        if r['scattered'] and r.get('type') == 1:
            continue
        for i in range(r['address'], r['address'] + (1 << r['length'])):
            if s0 <= i < ts['size']:
                mask[i - s0] = True
    return tail, mask


def rule4(img, A, Bo, cands):
    """plan 440: entry points c (from cands) where b's head starts and a's tail ends."""
    head, hm = masked_head(Bo['o'], Bo['ob'], Bo['ts'])
    tail, tm = masked_tail(A['o'], A['ob'], A['ts'])
    return [c for c in cands if eq_at(img, c, head, hm) and eq_at(img, c - len(tail), tail, tm)]


def eq_at(img, addr, head, mask):
    im = img.img.read(addr, len(head))
    return all(m or x == y for x, y, m in zip(head, im, mask))


PLAN = 439


def main(out_tsv, out_json):
    R418 = json.load(open(REC418))
    B = R418['boundaries']
    img = C.Img()
    T = {t['object']: t for t in W.targets()}
    built = {}
    for o, t in T.items():
        p = os.path.join(RUN, 'O438__%s.o' % t['base'])
        lj = os.path.join(L1, 'l1-%s.json' % o)
        if os.path.exists(p) and os.path.exists(lj):
            ob = open(p, 'rb').read()
            mo = macho_obj.parse(ob)
            ts = [s for s in mo['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
            l1 = json.load(open(lj))
            sec = l1['sections'].get('__TEXT,__text', {})
            built[o] = dict(path=p, ob=ob, o=mo, ts=ts, verdict=l1['object_verdict'], addr=sec.get('address'), size=ts['size'])
    entries = sorted(int(r['entry'], 16) for r in csv.DictReader(open(FUNCS).read().splitlines()[1:], delimiter='\t'))

    def rules(b, window):
        A, Bo = built.get(b['a']), built.get(b['b'])
        out = {}
        if Bo and Bo['verdict'] == 'OBJECT_MATCH' and Bo['addr'] is not None:
            out['rule1'] = Bo['addr']
        if A and A['verdict'] == 'OBJECT_MATCH' and A['addr'] is not None:
            out['rule2'] = A['addr'] + A['size']
        if Bo and not ('rule1' in out or 'rule2' in out):
            head, mask = masked_head(Bo['o'], Bo['ob'], Bo['ts'])
            lo, hi = window
            hits = [e for e in entries if lo <= e <= hi and eq_at(img, e, head, mask)]
            out['rule3_hits'] = hits
            if len(hits) == 1:
                out['rule3'] = hits[0]
        return out

    # negative tests on decided boundaries with both sides rebuilt
    neg = collections.Counter()
    neg_bad = []
    for b in B:
        if not b['decided'] or b['a'] not in built or b['b'] not in built:
            continue
        neg['decided_both_rebuilt'] += 1
        r = rules(b, (b['lower'], b['upper']))
        for k in ('rule1', 'rule2'):
            if k in r:
                neg[k + '_checked'] += 1
                if r[k] != b['upper']:
                    neg_bad.append([b['k'], k, hex(r[k]), hex(b['upper'])])
        # rule 3 alone, wide window (a_last, b_first]
        Bo = built[b['b']]
        head, mask = masked_head(Bo['o'], Bo['ob'], Bo['ts'])
        hits = [e for e in entries if b['a_last'] < e <= b['b_first'] and eq_at(img, e, head, mask)]
        if len(hits) == 1:
            neg['rule3_wide_correct' if hits[0] == b['upper'] else 'rule3_wide_wrong'] += 1
            if hits[0] != b['upper']:
                neg_bad.append([b['k'], 'rule3_wide', hex(hits[0]), hex(b['upper'])])
        elif hits:
            neg['rule3_wide_ambiguous'] += 1
        else:
            neg['rule3_wide_miss'] += 1
        for d in (-4, -2, 2, 4):
            if eq_at(img, b['upper'] + d, head, mask):
                neg['shift_false_match'] += 1
                neg_bad.append([b['k'], 'shift %+d' % d])
    # undecided boundaries
    dec = {}
    rows = []
    for b in B:
        if b['decided']:
            continue
        both = b['a'] in built and b['b'] in built
        row = dict(k=b['k'], a=b['a'], b=b['b'], lower='0x%x' % b['lower'], upper='0x%x' % b['upper'], both_rebuilt=both)
        if both:
            r = rules(b, (b['lower'], b['upper']))
            vals = {k: v for k, v in r.items() if k in ('rule1', 'rule2', 'rule3')}
            row['rules'] = {k: ('0x%x' % v) for k, v in vals.items()}
            row['rule3_hits'] = ['0x%x' % h for h in r.get('rule3_hits', [])]
            ok = bool(vals) and len(set(vals.values())) == 1 and all(b['lower'] <= v <= b['upper'] for v in vals.values())
            gate = None
            if ok and set(vals) == {'rule3'}:
                gate = a_gate(img, b, built, list(vals.values())[0])
                row['a_gate'] = gate
                ok = gate['pass']
            if ok:
                v = list(vals.values())[0]
                dec[b['k']] = (v, '+'.join(sorted(vals)) + (' + a-side gate' if gate else ''))
            row['decided_439'] = ok
            A_, B_ = built[b['a']], built[b['b']]
            if PLAN == 440 and not ok and A_['verdict'] != 'OBJECT_MATCH' and B_['verdict'] != 'OBJECT_MATCH':
                hits4 = rule4(img, A_, B_, [e for e in entries if b['lower'] <= e <= b['upper']])
                row['rule4_hits'] = ['0x%x' % h for h in hits4]
                if len(hits4) == 1:
                    c = hits4[0]
                    head, hm = masked_head(B_['o'], B_['ob'], B_['ts'])
                    tail, tm = masked_tail(A_['o'], A_['ob'], A_['ts'])
                    row['rule4_shifts'] = {('%+d' % d): eq_at(img, c + d, head, hm) and eq_at(img, c + d - len(tail), tail, tm)
                                           for d in (-4, -2, 2, 4)}
                    dec[b['k']] = (c, 'rule4 (plan 440)')
                    row['decided_440'] = True
        rows.append(row)
    # table: plan 418 rows + 3 columns
    lines = open(TAB418).read().splitlines()
    head_i = [i for i, l in enumerate(lines) if l.startswith('k\t')][0]
    out = ['# plan %s: plan 418 table with boundaries decided by rebuilt m68k objects (run m3p438-cc1; '
           'm2_m68k_boundaries_built.py%s); decided_439/boundary_439/basis_439 appended, earlier columns unchanged'
           % ('439' if PLAN == 439 else '439/440', '' if PLAN == 439 else ' --plan 440')]
    out += lines[:head_i] + [lines[head_i] + '\tdecided_439\tboundary_439\tbasis_439']
    n = 0
    for l in lines[head_i + 1:]:
        k = int(l.split('\t')[0])
        b = [x for x in B if x['k'] == k][0]
        if b['decided']:
            out.append(l + '\t1\t0x%x\tplan 418' % b['upper'])
        elif k in dec:
            out.append(l + '\t1\t0x%x\t%s' % dec[k])
        else:
            out.append(l + '\t0\t\t')
        n += 1
    assert n == len(B)
    open(out_tsv, 'w').write('\n'.join(out) + '\n')
    # exactness effect on the plan 423 object list
    ol = [r for r in csv.DictReader([l for l in open(OBJS).read().splitlines() if not l.startswith('#')], delimiter='\t')]
    text = [s for s in img.img.o['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]

    def ex(r, newb):
        if not all(r[c] for c in ('start_lo', 'start_hi', 'end_lo', 'end_hi')):   # data-only rows
            return False, 0
        st = [int(r['start_lo'], 16), int(r['start_hi'], 16)]
        en = [int(r['end_lo'], 16), int(r['end_hi'], 16)]
        for k, (v, _) in newb.items():
            b = [x for x in B if x['k'] == k][0]
            if st == [b['lower'], b['upper']] and r['x86_objects'] == b['b']:
                st = [v, v]
            if en == [b['lower'], b['upper']] and r['x86_objects'] == b['a']:
                en = [v, v]
        return st[0] == st[1] and en[0] == en[1], en[0] - st[1]
    before = [ex(r, {}) for r in ol]
    after = [ex(r, dec) for r in ol]
    newly = [r['id'] for r, x, y in zip(ol, before, after) if y[0] and not x[0]]
    eff = dict(exact_before=sum(1 for x in before if x[0]), exact_after=sum(1 for x in after if x[0]),
               exact_bytes_before=sum(x[1] for x in before if x[0]), exact_bytes_after=sum(x[1] for x in after if x[0]),
               text_size=text['size'], newly_exact=newly)
    eff['pct_before'] = round(100.0 * eff['exact_bytes_before'] / text['size'], 2)
    eff['pct_after'] = round(100.0 * eff['exact_bytes_after'] / text['size'], 2)
    S = collections.OrderedDict()
    S['undecided_418'] = len(rows)
    S['both_rebuilt'] = [r['k'] for r in rows if r['both_rebuilt']]
    S['decided_439'] = {k: ['0x%x' % v, why] for k, (v, why) in dec.items()}
    S['negative_tests'] = dict(neg)
    S['negative_failures'] = neg_bad
    if PLAN == 440:   # rule 4 tests on decided boundaries with both sides rebuilt (wide window)
        n4 = collections.Counter()
        bad4, cross_a, cross_b = [], 0, 0
        others = sorted(built)
        for b in B:
            if not b['decided'] or b['a'] not in built or b['b'] not in built:
                continue
            A_, B_ = built[b['a']], built[b['b']]
            h = rule4(img, A_, B_, [e for e in entries if b['a_last'] < e <= b['b_first']])
            if len(h) == 1:
                n4['correct' if h[0] == b['upper'] else 'wrong'] += 1
                if h[0] != b['upper']:
                    bad4.append([b['k'], '0x%x' % h[0], '0x%x' % b['upper']])
            else:
                n4['abstain_none' if not h else 'abstain_several'] += 1
            c = b['upper']
            head, hm = masked_head(B_['o'], B_['ob'], B_['ts'])
            tail, tm = masked_tail(A_['o'], A_['ob'], A_['ts'])
            okh, okt = eq_at(img, c, head, hm), eq_at(img, c - len(tail), tail, tm)
            for x in others:
                X = built[x]
                if okh and x != b['a']:
                    tx, txm = masked_tail(X['o'], X['ob'], X['ts'])
                    cross_a += eq_at(img, c - len(tx), tx, txm)
                if okt and x != b['b']:
                    hx, hxm = masked_head(X['o'], X['ob'], X['ts'])
                    cross_b += eq_at(img, c, hx, hxm)
        S['rule4_decided_boundaries'] = dict(n4)
        S['rule4_wrong'] = bad4
        S['rule4_cross_pairs'] = dict(other_a_tail_at_true_c=cross_a, other_b_head_at_true_c=cross_b)
    S['objects_exactness'] = eff
    json.dump(dict(plan=PLAN, tool='10_tools/reconstruction/m2_m68k_boundaries_built.py', tool_sha256=sha(os.path.abspath(__file__)),
                   inputs={p: sha(p) for p in (REC418, TAB418, OBJS, FUNCS)}, run=RUN, table=out_tsv, summary=S, rows=rows),
              open(out_json, 'w'), indent=1)
    print(json.dumps(S, indent=1))


def a_gate(img, b, built, value):
    """plan 439.1 a-side gate: whole a object against [a start, value)."""
    A = built[b['a']]
    prev = [x for x in json.load(open(REC418))['boundaries'] if x['b'] == b['a'] and x['decided']]
    assert len(prev) == 1, b['a']
    start = prev[0]['upper']
    ot = OTOOL[b['a']]
    shas = {os.path.basename(l.split()[-1]): l.split()[0] for l in open(os.path.join(ot, 'objects.sha'))}
    base = os.path.basename(A['path'])[:-2]
    assert sha(A['path']) == shas[base + '.o']
    ob, o, ts = A['ob'], A['o'], A['ts']
    names = {i: y['name'] for i, y in enumerate(o['symbols'])}
    rel = []
    for r in ts['relocs']:
        r = dict(r)
        if not r['scattered'] and r['extern']:
            r['symname'] = names[r['symbolnum']]
        r['address'] += ts['addr']
        rel.append(r)
    osym = C.Symbolizer(o['sections'], o['symbols'], lambda x, n: C.obj_read(o, ob, x, n))
    oins = C.read_otool(os.path.join(ot, base + '.txt'))
    iins = C.read_otool(D.IMG_LIST)
    isym = C.Symbolizer(img.img.o['sections'], img.img.o['symbols'], img.img.read)
    end = ts['addr'] + ts['size']
    A_, aa, _ = D.norm_with_addr(oins, ts['addr'], end, osym,
                                 lambda x, n: ob[ts['offset'] + x - ts['addr']:ts['offset'] + x - ts['addr'] + n], rel)
    Bn, ba, _ = D.norm_with_addr(iins, start, value, isym, img.img.read)
    bl, kinds = D3.blocks_of(A_, aa, Bn, ba, ts, D.lines_of(o, ts))
    # byte sizes of blocks from the normalised item addresses
    import difflib
    mk = lambda S: [(m, C.SYMTOK.sub(lambda q: 'L' if q.group(0).startswith('L+') else q.group(0), x)) for m, x in S]
    sm = difflib.SequenceMatcher(None, mk(A_), mk(Bn), autojunk=False)
    aa2, ba2 = aa + [end], ba + [value]
    blocks = []
    for (op, i1, i2, j1, j2), info in zip([x for x in sm.get_opcodes() if x[0] != 'equal'], bl):
        ob_bytes = aa2[i2] - aa2[i1]
        im_bytes = ba2[j2] - ba2[j1]
        blocks.append(dict(info, object_bytes=ob_bytes, image_bytes=im_bytes, delta=ob_bytes - im_bytes))
    delta = sum(x['delta'] for x in blocks)
    obj_only = sorted({c for x in blocks for c in x['calls_object_only']})
    img_only = sorted({c for x in blocks for c in x['calls_image_only']})
    others = [x for x in blocks if not any('_byte_swap_' in c for c in x['calls_object_only']) and x['delta'] != 0]
    want = ts['size'] - (value - start)
    ok = (delta == want and obj_only and all('_byte_swap_' in c for c in obj_only) and not img_only and not others)
    return dict(start='0x%x' % start, value='0x%x' % value, object_size=ts['size'], range_size=value - start,
                expected_delta=want, delta=delta, calls_object_only=obj_only, calls_image_only=img_only,
                nonzero_other_blocks=len(others), kinds=dict(kinds), blocks=blocks, **{'pass': bool(ok)})


if __name__ == '__main__':
    a = sys.argv[1:]
    if a[:2] == ['--plan', '440']:
        PLAN = 440
        a = a[2:]
    if len(a) != 2:
        sys.exit(__doc__)
    main(*a)
