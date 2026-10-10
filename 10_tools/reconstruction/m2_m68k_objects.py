#!/usr/bin/env python3
"""m2_m68k_objects.py -- plan 423 (M2-9): one m68k object-candidate list from plans 415-422, with
denominators.  No new judgement; the earlier results are combined by fixed rules (plan 423.1).

  python3 10_tools/reconstruction/m2_m68k_objects.py OBJECTS.tsv RECORD.json

Labels per address group: the plan 421 unit holding it; else its contiguous x86 object; else
"unassigned" per plan 415 run.  An object candidate is a stretch of equal labels.
Boundaries: at a plan 415 run boundary the plan 418 boundary (decided -> exact; flagged ->
(last external symbol of A, first of B]; other undecided -> [lower, upper]); inside a run the
plan 416 rule (no unnamed entry, .word row, off-listing external symbol or unconfirmed entry in
the window -> exact at the group, else the window).
Read-only apart from the two output files.
"""
import sys, os, re, json, csv, bisect, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m2_m68k_text_map as T415
import m2_m68k_boundaries as B416
import m2_m68k_data_order as D418

IMG, IMG_SHA = D418.IMG, D418.IMG_SHA
MAP = '09_validation/reconstruction/m2-m68k-text-map-20261009.json'
R416 = '09_validation/reconstruction/m2-m68k-boundaries-20261009.json'
R418 = '09_validation/reconstruction/m2-m68k-data-order-20261009.json'
R419 = '09_validation/reconstruction/m2-m68k-data-map-20261009.json'
R421 = '09_validation/reconstruction/m2-m68k-regroup-20261009.json'
R422 = '09_validation/reconstruction/m2-m68k-libcc-20261009.json'
IDA = '05_ida/exports/m68k/initial-functions.json'
sha = T415.sha


def main(out_tsv, out_json):
    ib = open(IMG, 'rb').read()
    assert T415.hashlib.sha256(ib).hexdigest() == IMG_SHA
    img = macho_obj.parse(ib)
    text = [s for s in img['sections'] if s['sectname'] == '__text'][0]
    TLO, THI = text['addr'], text['addr'] + text['size']
    M, A416, A418, A419, A421 = (json.load(open(p)) for p in (MAP, R416, R418, R419, R421))
    klass = {o['n']: o['klass'] for o in M['objects']}
    oname = {o['n']: o['object'] for o in M['objects']}
    G = [dict(g, address=int(g['address'], 16)) for g in M['groups']]
    k = -1
    for i, g in enumerate(G):
        if i == 0 or G[i - 1]['owner'] != g['owner']:
            k += 1
        g['run'] = k
    nruns = k + 1
    assert len(A418['boundaries']) == nruns - 1
    gidx = {g['address']: i for i, g in enumerate(G)}

    # 1. labels
    label = [None] * len(G)
    for u_i, u in enumerate(A421['units']):
        i0 = gidx[int(u['start'], 16)]
        for i in range(i0, i0 + u['groups']):
            assert label[i] is None, 'units overlap'
            label[i] = ('unit', u_i)
        assert (G[i0 + u['groups']]['address'] if i0 + u['groups'] < len(G) else THI) == int(u['end_upper'], 16)
    for i, g in enumerate(G):
        if label[i] is None:
            if g['owner'] is not None and klass[g['owner']] == 'contiguous':
                label[i] = ('x86', g['owner'])
            else:
                label[i] = ('unassigned', g['run'])
        elif g['owner'] is not None:
            assert klass[g['owner']] != 'contiguous', 'unit holds a contiguous object group'
    S = collections.OrderedDict()
    S['group_labels'] = dict(collections.Counter(
        (A421['units'][l[1]]['kind'] if l[0] == 'unit' else l[0]) for l in label))
    stretches = []
    for i in range(len(G)):
        if stretches and label[stretches[-1][-1]] == label[i]:
            stretches[-1].append(i)
        else:
            stretches.append([i])
    keys = [label[s[0]] for s in stretches]
    dup = [k_ for k_, c in collections.Counter(keys).items() if c > 1]
    assert not [k_ for k_ in dup if k_[0] == 'unit'], 'a unit in several stretches'

    # 2. boundaries
    res = D418.main(extend=True)
    assert res['S']['decided'] == A418['summary']['decided']
    final, entries, tok = res['final'], res['entries'], res['tok']
    unnamed = sorted(e for e in entries if e not in tok)
    word_rows = sorted(a for a, m, _ in B416.read_listing() if m == '.word')
    off = {int(x, 16) for x in A416['off_listing']}
    unconf = sorted(int(x, 16) for x in A416['unconfirmed'])

    def any_in(L, lo, hi):
        j = bisect.bisect_left(L, lo)
        return j < len(L) and L[j] < hi

    bounds = []                      # boundary before stretch t (t >= 1): (lo, hi, kind)
    for t in range(1, len(stretches)):
        i = stretches[t][0]
        a, b = G[i - 1], G[i]
        if a['run'] != b['run']:
            B = A418['boundaries'][a['run']]
            assert B['k'] == a['run']
            if B['decided']:
                bounds.append((B['upper'], B['upper'], 'decided (418)'))
            elif B['flags'] and B['lower'] == B['upper']:
                bounds.append((B['a_last'], B['b_first'], 'flagged (418): ' + '; '.join(B['flags'])))
            else:
                bounds.append((B['lower'], B['upper'], 'undecided (418)'))
        else:
            lo, hi = a['address'], b['address']
            fl = []
            if any_in(unnamed, lo + 1, hi):
                fl.append('unnamed entries')
            if any_in(word_rows, lo, hi):
                fl.append('.word rows')
            if lo in off or hi in off:
                fl.append('external symbol off the listing')
            if any_in(unconf, lo + 1, hi):
                fl.append('unconfirmed entry')
            bounds.append((hi, hi, 'decided (416 rule, inside run)') if not fl else (lo, hi, 'inside run: ' + ', '.join(fl)))
    starts = [(TLO, TLO, 'text start')] + bounds
    ends = bounds + [(THI, THI, 'text end')]
    for x, y in zip(starts, starts[1:]):
        assert x[0] <= x[1] <= y[0] <= y[1], (x, y)
    # (a') cover: sum of object minima + windows = text size
    mins = [e[0] - s[1] for s, e in zip(starts, ends)]
    assert all(m >= 0 for m in mins)
    win = sum(b[1] - b[0] for b in bounds)
    assert sum(mins) + win == text['size'], (sum(mins), win, text['size'])

    # objects
    U = A421['units']
    rows = []
    for t, (st, en, s_) in enumerate(zip(starts, ends, stretches)):
        key = keys[t]
        if key[0] == 'unit':
            u = U[key[1]]
            kind, lab, basis = ('bracket' if u['kind'] == 'x86' else 'file'), u['label'], u['support']
        elif key[0] == 'x86':
            kind, lab, basis = 'x86', oname[key[1]], 'plan 415 name match (contiguous)'
        else:
            kind, lab, basis = 'unassigned', 'unassigned (run %d)' % key[1], 'none'
        gs = [G[i] for i in s_]
        x86s = sorted({oname[g['owner']] for g in gs if g['owner'] is not None})
        rows.append(dict(t=t, kind=kind, label=lab, basis=basis, start=st, end=en, groups=len(gs),
                         runs=sorted({g['run'] for g in gs}), x86_objects=x86s,
                         external_symbols=sum(len(g['names']) for g in gs),
                         exact=st[0] == st[1] and en[0] == en[1], bytes_min=en[0] - st[1], bytes_max=en[1] - st[0]))
    # entries per object (exact ranges) and in windows
    allent = sorted(entries)
    inwin = 0
    for e in allent:
        if any(lo <= e < hi for lo, hi, _ in bounds if lo < hi):
            inwin += 1
            continue
        j = bisect.bisect_right([r['start'][1] for r in rows], e) - 1
        r = rows[j]
        assert r['start'][1] <= e < r['end'][0] or r['start'][0] == r['start'][1], (hex(e), r['label'])
        r['entries'] = r.get('entries', 0) + 1
        if e not in tok:
            r['unnamed'] = r.get('unnamed', 0) + 1
    assert sum(r.get('entries', 0) for r in rows) + inwin == len(allent) == 3570

    # (b) validation objects (repeats plan 418): exact extents
    vb = []
    for v in A416['validation']:
        n = v['n']
        r = [x for x in rows if x['kind'] == 'x86' and x['label'] == oname[n]]
        assert len(r) == 1, v['object']
        vb.append(r[0]['start'] == (v['start'], v['start'], r[0]['start'][2]) and r[0]['end'][0] == r[0]['end'][1] == v['end'])
    # (e) owner of unnamed entries against object ranges
    def objs_for(tokn):
        if tokn[0] == 'obj':
            return [r for r in rows if oname[tokn[1]] in r['x86_objects']]
        return [r for r in rows if tokn[1] in r['runs']]
    viol, checked = [], 0
    for e in unnamed:
        o = final.get(e)
        if not isinstance(o, tuple):
            continue
        checked += 1
        rs = objs_for(o)
        if not any(r['start'][0] <= e < r['end'][1] for r in rs):
            viol.append(dict(entry='0x%x' % e, owner=res['tname'](o),
                             in_object=[r['label'] for r in rows if r['start'][0] <= e < r['end'][1]]))
    # (f) IDA diagnostic
    ida = {int(f['start'], 16) for f in json.load(open(IDA)) if TLO <= int(f['start'], 16) < THI}
    es = set(allent)

    # 4. data
    on2n = {v: k_ for k_, v in oname.items()}
    xd = {o['n']: o for o in M['objects']}
    datarows, unlinked = [], collections.Counter()
    for sk, L in A419['runs'].items():
        for dr in L:
            ow = dr['owner']
            if ow.startswith('unmapped#'):
                kk = int(ow.split('#')[1])
                cand = [r for r in rows if kk in r['runs']]
            else:
                cand = [r for r in rows if r['label'] == ow or ow in r['x86_objects']]
            if len(cand) == 1:
                cand[0].setdefault('data', []).append('%s %s' % (sk, dr['anchors'][0][0]))
                if ow == 'unmapped#287':
                    cand[0]['note'] = 'plan 419 suspect data owner (unmapped#287)'
            elif not cand and not ow.startswith('unmapped#') and on2n.get(ow) and not xd[on2n[ow]]['has_text']:
                datarows.append(dict(label=ow, section=sk, first_anchor=dr['anchors'][0][0], anchors=len(dr['anchors'])))
            else:
                unlinked['several objects' if cand else ('x86 object absent in m68k text' if on2n.get(ow) else 'no object')] += 1
                datarows.append(dict(label=ow, section=sk, first_anchor=dr['anchors'][0][0], anchors=len(dr['anchors']),
                                     unlinked='several objects (%d)' % len(cand) if cand else 'not in the m68k text map'))
    # ObjC and the other sections
    segs = sorted({s['segname'] for s in img['sections']})
    objc_names = [y['name'] for y in img['symbols'] if 'objc' in y['name'].lower()]
    other = {s['sectname']: s['size'] for s in img['sections'] if s['sectname'] in ('__cstring', '__bss', '__common')}

    kinds = collections.Counter(r['kind'] for r in rows)
    S['objects'] = dict(kinds)
    S['object_candidates'] = sum(v for k_, v in kinds.items() if k_ != 'unassigned')
    S['data_only_rows'] = sum(1 for d in datarows if 'unlinked' not in d)
    S['boundaries'] = dict(total=len(bounds), kinds=dict(collections.Counter(b[2].split(':')[0] for b in bounds)),
                           exact=sum(1 for b in bounds if b[0] == b[1]))
    S['text_bytes'] = dict(size=text['size'], exact_objects=sum(r['bytes_min'] for r in rows if r['exact']),
                           sum_minimum=sum(mins), windows=win,
                           exact_objects_count=sum(1 for r in rows if r['exact']))
    S['text_bytes']['exact_pct'] = round(100.0 * S['text_bytes']['exact_objects'] / text['size'], 2)
    S['entries'] = dict(total=len(allent), in_windows=inwin, note='function-entry candidates, not a function count')
    S['validation'] = dict(cover='monotone, first/last at __text bounds, sum(min)+windows = size',
                           plan418_objects=[sum(vb), len(vb)],
                           owner_vs_range=dict(checked=checked, violations=viol),
                           ida_starts=dict(ida=len(ida), both=len(ida & es), ida_only=len(ida - es), entries_only=len(es - ida)))
    S['data'] = dict(runs=sum(len(L) for L in A419['runs'].values()),
                     linked=sum(len(r.get('data', [])) for r in rows), data_only_rows=S['data_only_rows'],
                     unlinked=dict(unlinked))
    S['objc'] = dict(segments=segs, objc_segment=('__OBJC' in segs), names_containing_objc=objc_names,
                     note='ObjC-compiled objects carry __OBJC sections; none reached the linked image')
    S['not_assignable'] = dict(sizes=other, why={'__cstring': 'literals merged by the link editor across objects',
                                                 '__bss': 'no symbols', '__common': 'COMMON symbols placed by the link editor'})
    S['open'] = ['function denominator: entries are candidates; function ranges stay "boundary undetermined" where not proven (M2 open)',
                 'static-reference crossings not applied: next/pmap.c (run 291) <-> x86-pmap (plan 421), '
                 'unmapped run 172 (_ns_callout_init, _ns_timer_init) <-> x86-ns_timer (owner_vs_range)',
                 'unassigned groups and file-kind (weak) candidates']

    with open(out_tsv, 'w') as f:
        f.write('# plan 423: m68k object candidates (M2) -- kinds x86 (name match), bracket, file (weak, NeXTMach 1990 file), '
                'unassigned, data-only; start/end lo==hi means exact (m2_m68k_objects.py)\n')
        w = csv.writer(f, delimiter='\t', lineterminator='\n')
        w.writerow(['id', 'kind', 'label', 'basis', 'start_lo', 'start_hi', 'end_lo', 'end_hi', 'bytes_min', 'bytes_max',
                    'external_symbols', 'entries', 'unnamed_entries', 'x86_objects', 'data_runs', 'note'])
        n = 0
        for r in rows:
            n += 1
            w.writerow(['m68k-%03d' % n, r['kind'], r['label'], r['basis'], '0x%x' % r['start'][0], '0x%x' % r['start'][1],
                        '0x%x' % r['end'][0], '0x%x' % r['end'][1], r['bytes_min'], r['bytes_max'], r['external_symbols'],
                        r.get('entries', 0), r.get('unnamed', 0), ','.join(r['x86_objects']), len(r.get('data', [])), r.get('note', '')])
        for d in datarows:
            n += 1
            w.writerow(['m68k-%03d' % n, 'data-only' if 'unlinked' not in d else 'data-unlinked', d['label'],
                        'plan 419 data run', '', '', '', '', '', '', 0, 0, 0, '', 1,
                        '%s from %s (%d anchors)%s' % (d['section'], d['first_anchor'], d['anchors'],
                                                     ('; ' + d['unlinked']) if 'unlinked' in d else '')])
    json.dump(dict(plan=423, tool='10_tools/reconstruction/m2_m68k_objects.py', tool_sha256=sha(os.path.abspath(__file__)),
                   inputs={p: sha(p) for p in (MAP, R416, R418, R419, R421, R422, IDA)}, image=dict(path=IMG, sha256=IMG_SHA),
                   outputs={out_tsv: sha(out_tsv)},
                   note='M2 candidate list: x86 = plan 415 name match, bracket/file = plan 421 (file is weak), boundaries by the '
                        'plan 416/418 rules; no content match (L1) is implied.',
                   summary=S,
                   objects=[dict(r, start=['0x%x' % r['start'][0], '0x%x' % r['start'][1], r['start'][2]],
                                 end=['0x%x' % r['end'][0], '0x%x' % r['end'][1], r['end'][2]]) for r in rows],
                   data_rows=datarows), open(out_json, 'w'), indent=1)
    print(json.dumps(S, indent=1))


if __name__ == '__main__':
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    main(*sys.argv[1:])
