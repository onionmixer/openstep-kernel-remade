#!/usr/bin/env python3
"""m2_m68k_regroup.py -- plan 421 (M2-7): m68k object candidates for the split x86 objects and the
m68k-only __text runs, at the level of address groups (plan 421.1).

  python3 10_tools/reconstruction/m2_m68k_regroup.py REGROUP.tsv RECORD.json

Targets: address groups of unmapped runs and of split x86 objects; groups of contiguous x86
objects are not targets and stop every unit.
1. Bracket: a split x86 object X whose groups become one stretch once the unmapped groups lying
   between them are added is reunited as unit X (support "bracket").
2. File: the remaining target groups are labelled by their NeXTMach mk-108.1 candidate file
   (plan 420 index; _bcmp/_ffs/_strlen without the bsd/subr_xxx.c definitions, which are in the
   #else branch of "#if BALANCE || NeXT || vax"); consecutive groups of one file F form unit F,
   groups without a definition between two groups of F are gaps; a different file, a group with
   two files or a non-target group ends the unit.
Tests: (a) a file in several units, (b) source order inside a file unit, (c) plan 418 decided
boundaries inside units, (d) static bridges: external callers of unnamed entries whose plan 418
owner is a conflict, (e) prologue fingerprint (plan 421.2): "linkw a6,#0x0" (NeXTMach assembly macro) in a .c or
x86 unit, or the GCC empty-frame prologue "pea a6@ / movel sp,a6" at an external function of a
.s/.sa unit; a negative linkw is neutral.
Read-only apart from the two output files.
"""
import sys, os, re, json, csv, bisect, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import m2_m68k_unmapped as U420
import m2_m68k_text_map as T415
import m2_m68k_boundaries as B416
import m2_m68k_data_order as D418

MAP = U420.MAP
RUNS = U420.RUNS
REC418 = '09_validation/reconstruction/m2-m68k-data-order-20261009.json'
REC420 = '09_validation/reconstruction/m2-m68k-unmapped-20261009.json'
NOT_FOR_NEXT = {'_bcmp', '_ffs', '_strlen'}            # bsd/subr_xxx.c:169-206 #else branch
sha = T415.sha


def main(out_tsv, out_json):
    defs = U420.index(U420.build_set())
    for n in NOT_FOR_NEXT:
        defs[n] = [d for d in defs.get(n, []) if d[0] != 'bsd/subr_xxx.c']

    def files_of(names):
        fs = set()
        for nm in names:
            f, _ = U420.resolve(defs, nm)
            if f not in (None, 'ambiguous'):
                fs.add(f)
        return fs

    M = json.load(open(MAP))
    klass = {o['n']: o['klass'] for o in M['objects']}
    oname = {o['n']: o['object'] for o in M['objects']}
    G = [dict(g, address=int(g['address'], 16)) for g in M['groups']]
    rows = list(csv.DictReader(open(RUNS).read().splitlines()[1:], delimiter='\t'))
    text_end = int(rows[-1]['end_upper'], 16)
    # run index of each group (plan 415 rule)
    k = -1
    for i, g in enumerate(G):
        if i == 0 or G[i - 1]['owner'] != g['owner']:
            k += 1
        g['run'] = k
    assert k + 1 == len(rows)
    for i, g in enumerate(G):
        g['target'] = g['owner'] is None or klass[g['owner']] == 'split'
        g['files'] = files_of(g['names'])
        g['next'] = G[i + 1]['address'] if i + 1 < len(G) else text_end

    # 1. bracket
    unit = [None] * len(G)
    support = {}
    for X in sorted({g['owner'] for g in G if g['owner'] is not None and klass[g['owner']] == 'split'}):
        idx = [i for i, g in enumerate(G) if g['owner'] == X]
        lo, hi = idx[0], idx[-1]
        if all(G[i]['owner'] in (X, None) for i in range(lo, hi + 1)):
            for i in range(lo, hi + 1):
                unit[i] = ('x86', X)
            support[('x86', X)] = 'bracket'
    # 2. file units over the remaining target groups
    i = 0
    while i < len(G):
        g = G[i]
        if unit[i] is not None or not g['target'] or len(g['files']) != 1:
            i += 1
            continue
        F = next(iter(g['files']))
        j = i
        members = [i]
        while True:
            # extend over gaps (no definition) only if a group of F follows
            t = j + 1
            while t < len(G) and unit[t] is None and G[t]['target'] and not G[t]['files']:
                t += 1
            if t < len(G) and unit[t] is None and G[t]['target'] and G[t]['files'] == {F}:
                members += list(range(j + 1, t + 1))
                j = t
                continue
            break
        key = ('file', F)
        n_same = sum(1 for u in support if u[0] == 'file' and u[1] == F)
        key = ('file', F, n_same)                    # a file may give several units (test a)
        for m in members:
            unit[m] = key
        support[key] = 'file'
        i = j + 1

    # units in address order
    U = collections.OrderedDict()
    for i, g in enumerate(G):
        if unit[i] is None:
            continue
        U.setdefault(unit[i], []).append(i)
    # tests
    rows_l = B416.read_listing()
    at = {a: (m, o) for a, m, o in rows_l}
    nxt = {}
    for t, (a, m, o) in enumerate(rows_l[:-1]):
        nxt[a] = rows_l[t + 1]
    def prologue(a):
        if a not in at:
            return 'off listing'
        m, o = at[a]
        if m == 'linkw' and o in ('a6,#0x0', 'a6,#0'):
            return 'asm'
        if m == 'pea' and o == 'a6@' and a in nxt and nxt[a][1] == 'movel' and nxt[a][2] == 'sp,a6':
            return 'C'
        if m == 'linkw' and o.startswith('a6,'):
            return 'link (neutral)'            # plan 421.2: FPSP .sa also uses link a6,#-LOCAL_SIZE
        return 'other'
    res418 = D418.main(extend=True)
    R418 = json.load(open(REC418))
    assert res418['S']['decided'] == R418['summary']['decided']
    final, callers, tok = res418['final'], res418['callers'], res418['tok']
    gi_of = {g['address']: i for i, g in enumerate(G)}
    bridges = []
    for e, o in final.items():
        if o != 'conflict':
            continue
        cs = sorted(c for c in callers.get(e, ()) if c in gi_of)
        us = sorted({str(unit[gi_of[c]]) if unit[gi_of[c]] else 'run %d' % G[gi_of[c]]['run'] for c in cs})
        j = bisect.bisect_right([g['address'] for g in G], e) - 1      # group whose span holds the entry
        loc = str(unit[j]) if j >= 0 and unit[j] else ('run %d' % G[j]['run'] if j >= 0 else None)
        bridges.append(dict(entry='0x%x' % e, external_callers=len(cs), units=us, entry_in=loc,
                            links_units=(len(us) == 1 and loc is not None and loc != us[0])))
    decided = {b['k']: b for b in R418['boundaries']}
    out, S = [], collections.OrderedDict()
    fcount = collections.Counter(u[1] for u in U if u[0] == 'file')
    for u, members in U.items():
        gs = [G[i] for i in members]
        lab = oname[u[1]] if u[0] == 'x86' else u[1]
        start, end = gs[0]['address'], gs[-1]['next']
        x86s = sorted({oname[g['owner']] for g in gs if g['owner'] is not None})
        gaps = sum(1 for g in gs if not g['files'] and u[0] == 'file')
        # (b) source order
        lines = []
        if u[0] == 'file':
            for g in gs:
                for nm in g['names']:
                    f, ln = U420.resolve(defs, nm)
                    if f == u[1]:
                        lines.append(ln)
        lis = len(T415.lis(lines)) if lines else 0
        # (c) plan 418 boundaries inside the unit
        runs_in = sorted({g['run'] for g in gs})
        inner_b = [decided[r] for r in range(runs_in[0], runs_in[-1])]
        # (e) prologue fingerprint
        pro = collections.Counter(prologue(g['address']) for g in gs)
        contra = 0
        if u[0] == 'file' and u[1].endswith(('.s', '.sa')):
            contra = pro['C']
        else:
            contra = pro['asm']
        br = [b for b in bridges if str(u) in b['units']]
        grade = support[u]
        if any(len(b['units']) == 1 and str(u) in b['units'] for b in br):
            grade += '+static bridge'
        if u[0] == 'file' and u[1].endswith(('.s', '.sa')) and pro['asm']:
            grade += '+asm prologue'
        out.append(dict(kind=u[0], label=lab, start=start, end_upper=end, bytes=end - start, groups=len(gs),
                        runs=[runs_in[0], runs_in[-1]], x86_objects=x86s,
                        unmapped_groups=sum(1 for g in gs if g['owner'] is None), gaps=gaps,
                        file_in_several_units=(u[0] == 'file' and fcount[u[1]] > 1),
                        source_order=[lis, len(lines)], inner_boundaries=len(inner_b),
                        inner_decided_418=sum(1 for b in inner_b if b['decided']),
                        prologues=dict(pro), prologue_contradictions=contra, support=grade,
                        bridges=[b['entry'] for b in br]))
    # split objects: reunited or spread
    split = sorted(n for n, c in klass.items() if c == 'split')
    S['split_objects'] = {}
    for n in split:
        fs = sorted({unit[i][1] for i, g in enumerate(G) if g['owner'] == n and unit[i] and unit[i][0] == 'file'})
        left = sum(1 for i, g in enumerate(G) if g['owner'] == n and not unit[i])
        S['split_objects'][oname[n]] = ('reunited (bracket)' if ('x86', n) in support else
                                        'file units: %s; groups left: %d' % (','.join(fs) or '-', left))
    tg = [i for i, g in enumerate(G) if g['target']]
    S['target_groups'] = len(tg)
    S['target_groups_assigned'] = dict(collections.Counter(unit[i][0] if unit[i] else 'none' for i in tg))
    S['unmapped_bytes_assigned'] = dict(collections.Counter())
    for i in tg:
        if G[i]['owner'] is None:
            S['unmapped_bytes_assigned'][unit[i][0] if unit[i] else 'none'] = \
                S['unmapped_bytes_assigned'].get(unit[i][0] if unit[i] else 'none', 0) + G[i]['next'] - G[i]['address']
    S['units'] = dict(collections.Counter(o['kind'] for o in out))
    S['units_with_prologue_contradiction'] = [o['label'] for o in out if o['prologue_contradictions']]
    S['files_in_several_units'] = sorted({o['label'] for o in out if o['file_in_several_units']})
    S['source_order_outside'] = sum(o['source_order'][1] - o['source_order'][0] for o in out)
    S['bridges'] = bridges
    S['unit_bytes'] = dict(collections.Counter())
    for o in out:
        S['unit_bytes'][o['kind']] = S['unit_bytes'].get(o['kind'], 0) + o['bytes']
    S['multi_unit_x86'] = sorted({x for o in out for x in o['x86_objects'] if sum(x in p['x86_objects'] for p in out) > 1})

    with open(out_tsv, 'w') as f:
        f.write('# plan 421: m68k object candidates for split x86 objects and m68k-only __text groups '
                '(bracket by one x86 object, or NeXTMach mk-108.1 file = weak); end is an upper bound (m2_m68k_regroup.py)\n')
        w = csv.writer(f, delimiter='\t', lineterminator='\n')
        w.writerow(['kind', 'label', 'start', 'end_upper', 'bytes', 'groups', 'first_run', 'last_run', 'x86_objects',
                    'unmapped_groups', 'gaps', 'support', 'prologue_contradictions', 'file_in_several_units',
                    'source_order_lis', 'source_order_names', 'inner_boundaries_418', 'inner_decided_418'])
        for o in out:
            w.writerow([o['kind'], o['label'], '0x%x' % o['start'], '0x%x' % o['end_upper'], o['bytes'], o['groups'],
                        o['runs'][0], o['runs'][1], ','.join(o['x86_objects']), o['unmapped_groups'], o['gaps'], o['support'],
                        o['prologue_contradictions'], int(o['file_in_several_units']), o['source_order'][0], o['source_order'][1],
                        o['inner_boundaries'], o['inner_decided_418']])
    json.dump(dict(plan=421, tool='10_tools/reconstruction/m2_m68k_regroup.py', tool_sha256=sha(os.path.abspath(__file__)),
                   m2_m68k_unmapped_sha256=sha(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'm2_m68k_unmapped.py')),
                   map=dict(path=MAP, sha256=sha(MAP)), plan418=dict(path=REC418, sha256=sha(REC418)),
                   plan420=dict(path=REC420, sha256=sha(REC420)), outputs={out_tsv: sha(out_tsv)},
                   note='Candidates only. Bracket = unmapped groups between groups of one split x86 object; file = same-name '
                        'definitions in the 1990 NeXTMach build set (weak, plan 420). Contiguous x86 objects are never merged.',
                   summary=S, units=[dict(o, start='0x%x' % o['start'], end_upper='0x%x' % o['end_upper']) for o in out]),
              open(out_json, 'w'), indent=1)
    print(json.dumps({k: v for k, v in S.items() if k != 'bridges'}, indent=1))
    print('bridges', bridges)


if __name__ == '__main__':
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    main(*sys.argv[1:])
