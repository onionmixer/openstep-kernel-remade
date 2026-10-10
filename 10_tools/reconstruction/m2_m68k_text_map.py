#!/usr/bin/env python3
"""m2_m68k_text_map.py -- plan 415 (M2-1): candidate object map of the m68k original's
__TEXT,__text from its external symbols and the 402 rebuilt x86 objects (plan 409 record).

  python3 10_tools/reconstruction/m2_m68k_text_map.py RUNS.tsv OBJECTS.tsv RECORD.json

Every external __text symbol of 03_original/m68k/binaries/mach_kernel is grouped by address
(aliases); a group is owned by an x86 object when the x86 objects that define one of its names
in their __TEXT,__text agree on one object.  Runs are maximal address-ordered sequences of
groups with the same owner (unowned groups form "unmapped" runs).  A run starts at its first
symbol; its end is only an upper bound (the next run's first symbol): static or unnamed code
before or after the symbols is not assigned.  The interval sums are a provisional partition of
__text, not byte ownership.  A same-name mapping names an x86 counterpart, not an m68k source.
Read-only apart from the three output files.
"""
import sys, os, re, json, csv, hashlib, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj

IMG = '03_original/m68k/binaries/mach_kernel'
IMG_SHA = 'dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75'
SYMS = '03_original/m68k/inventory/symbols.tsv'
REC = '09_validation/reconstruction/m0-i386-18334-l1-20261009.json'
X86_SLICE_SYMS = '03_original/x86-mk-183.34/inventory/symbols.tsv'
X86_SYMS = '03_original/x86/inventory/symbols.tsv'
LINK = '08_build/runs/s6p404-ln1'


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def lis(seq):
    """indices of one longest strictly increasing subsequence (first-found on ties)."""
    import bisect
    tails, tidx, prev = [], [], [None] * len(seq)
    for i, v in enumerate(seq):
        k = bisect.bisect_left(tails, v)
        if k == len(tails):
            tails.append(v)
            tidx.append(i)
        else:
            tails[k] = v
            tidx[k] = i
        prev[i] = tidx[k - 1] if k else None
    out, i = [], tidx[-1] if tidx else None
    while i is not None:
        out.append(i)
        i = prev[i]
    return out[::-1]


def link_order(by_sha):
    """object n in the order of the reconstructed x86 link (ld -r bundles expanded)."""
    runs = [l.split() for l in open(os.path.join(LINK, 'run.cmd')).read().splitlines() if l.startswith('RUN ')]
    bundles, final = {}, None
    for w in runs:
        if w[1] != '/bin/ld':
            assert w[1] == '/bin/strip', w[:3]          # plan 402: strip of the linked kernel
            continue
        out = w[w.index('-o') + 1]
        ins = [x for x in w[1:] if x.endswith('.o') and x != out]
        if '-r' in w:
            bundles[out] = ins
        else:
            final = ins
    assert final and len(bundles) == 2, (len(bundles),)
    order = []
    for x in final:
        for y in bundles.get(x, [x]):
            assert y.startswith('src/objs/'), y
            order.append(by_sha[sha(os.path.join(LINK, y))])
    assert len(order) == len(set(order)) == len(by_sha), (len(order), len(set(order)))
    return order


def main(runs_tsv, objs_tsv, out_json):
    assert sha(IMG) == IMG_SHA
    img = macho_obj.parse(open(IMG, 'rb').read())
    secs = {s['index']: s for s in img['sections']}
    text = [s for s in img['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
    tend = text['addr'] + text['size']
    isyms = [y for y in img['symbols'] if y['kind'] == 'SECT' and not y['stab'] and y['sect'] == text['index']]
    assert all(y.get('ext') for y in isyms)
    inv = sorted((int(r['value'], 16), r['name']) for r in csv.DictReader(open(SYMS), delimiter='\t')
                 if r['debug'] == '0' and r['section'] == str(text['index']))
    assert inv == sorted((y['value'], y['name']) for y in isyms), 'inventory differs from the image'

    rec = json.load(open(REC))['slice']['objects']
    X, owner, nontext, common = {}, {}, {}, collections.Counter()
    by_sha = {}
    for o in rec:
        assert sha(o['obj']) == o['obj_sha256'], o['object']
        by_sha[o['obj_sha256']] = o['n']
        ob = macho_obj.parse(open(o['obj'], 'rb').read())
        osec = {s['index']: (s['segname'], s['sectname']) for s in ob['sections']}
        tsyms = []
        for y in ob['symbols']:
            if y['stab'] or not y.get('ext'):
                continue
            if y['kind'] == 'SECT':
                assert y['name'] not in owner and y['name'] not in nontext, y['name']
                if osec[y['sect']] == ('__TEXT', '__text'):
                    owner[y['name']] = o['n']
                    tsyms.append(y['name'])
                else:
                    nontext[y['name']] = (o['n'], '%s,%s' % osec[y['sect']])
            elif y['kind'] == 'COMMON':
                common[y['name']] += 1
        X[o['n']] = dict(n=o['n'], object=o['object'], source=o['source'], grade=o['grade'], objc=o['objc'],
                         has_text=any(s['sectname'] == '__text' and s['size'] for s in ob['sections']),
                         x86_text_symbols=tsyms, slice_text_address=o.get('text_address'))

    # address groups (aliases)
    groups = collections.OrderedDict()
    for a, n in inv:
        groups.setdefault(a, []).append(n)
    G = []
    for a, names in groups.items():
        own = sorted({owner[n] for n in names if n in owner})
        G.append(dict(address=a, names=names, mapped=[n for n in names if n in owner],
                      nontext=[n for n in names if n in nontext], owners=own,
                      owner=own[0] if len(own) == 1 else None, conflict=len(own) > 1))
    assert not any(g['conflict'] for g in G), [g for g in G if g['conflict']][:3]

    # runs
    R = []
    for g in G:
        if R and R[-1]['owner'] == g['owner']:
            R[-1]['groups'].append(g)
        else:
            R.append(dict(owner=g['owner'], groups=[g]))
    for i, r in enumerate(R):
        r['start'] = r['groups'][0]['address']
        r['end_upper'] = R[i + 1]['groups'][0]['address'] if i + 1 < len(R) else tend
        r['last_symbol'] = r['groups'][-1]['address']
    assert R[0]['start'] == text['addr'], hex(R[0]['start'])   # first symbol at the section start
    part = sum(r['end_upper'] - r['start'] for r in R)
    assert part == text['size'], (part, text['size'])

    runs_of = collections.defaultdict(list)
    for i, r in enumerate(R):
        if r['owner'] is not None:
            runs_of[r['owner']].append(i)
    for n, x in X.items():
        k = runs_of.get(n, [])
        present = [s for s in x['x86_text_symbols'] if s in {nm for g in G for nm in g['names']}]
        x['m68k_runs'] = len(k)
        x['m68k_symbols_present'] = len(present)
        x['klass'] = ('contiguous' if len(k) == 1 else 'split' if k else
                      ('no_external_text_symbol' if not x['x86_text_symbols'] else 'absent'))
        if len(k) > 1:
            between = []
            for a, b in zip(k, k[1:]):
                between.append([R[j]['owner'] if R[j]['owner'] is not None else 'unmapped' for j in range(a + 1, b)])
            x['between'] = [[X[o]['object'] if o != 'unmapped' else o for o in btw] for btw in between]
        x['m68k_first'] = R[k[0]]['start'] if k else None

    # unmapped names
    slice_names = {r['name'] for r in csv.DictReader(open(X86_SLICE_SYMS), delimiter='\t')}
    x86_names = {r['name'] for r in csv.DictReader(open(X86_SYMS), delimiter='\t')}
    un = [n for g in G for n in g['names'] if n not in owner]
    unc = collections.Counter('x86 slice and 183.34.4' if n in slice_names and n in x86_names else
                              'x86 slice only' if n in slice_names else '183.34.4 only' if n in x86_names else
                              'no x86 name' for n in un)

    # order: contiguous objects in m68k order vs the 1997 i386 slice address order and the x86 link order
    cont = sorted((x['m68k_first'], n) for n, x in X.items() if x['klass'] == 'contiguous')
    placed = [(a, n) for a, n in cont if X[n]['slice_text_address'] is not None]
    seq = [X[n]['slice_text_address'] for _, n in placed]
    keep = set(lis(seq))
    lorder = link_order(by_sha)
    lpos = {n: i for i, n in enumerate(lorder)}
    lseq = [lpos[n] for _, n in cont]
    lkeep = set(lis(lseq))
    order = dict(contiguous=len(cont),
                 slice_placed=len(placed), slice_unplaced=[X[n]['object'] for _, n in cont if X[n]['slice_text_address'] is None],
                 slice_lis=len(keep), slice_outside_lis=[X[placed[i][1]]['object'] for i in range(len(placed)) if i not in keep],
                 link_lis=len(lkeep), link_outside_lis=[X[cont[i][1]]['object'] for i in range(len(cont)) if i not in lkeep],
                 note='LIS = one longest increasing subsequence (first found); objects outside it are not proven out of order')

    # outputs
    S = collections.OrderedDict()
    S['text'] = dict(address=text['addr'], size=text['size'], align_pow2=text['align'])
    S['sections'] = [dict(name='%s,%s' % (s['segname'], s['sectname']), address=s['addr'], size=s['size']) for s in img['sections']]
    S['symbol_names'] = len(inv)
    S['addresses'] = len(G)
    S['alias_groups'] = sum(1 for g in G if len(g['names']) > 1)
    S['names_mapped'] = sum(len(g['mapped']) for g in G)
    S['addresses_owned'] = sum(1 for g in G if g['owner'] is not None)
    S['names_x86_nontext'] = sum(len(g['nontext']) for g in G)
    S['runs'] = len(R)
    S['runs_unmapped'] = sum(1 for r in R if r['owner'] is None)
    S['partition_bytes'] = dict(mapped=sum(r['end_upper'] - r['start'] for r in R if r['owner'] is not None),
                                unmapped=sum(r['end_upper'] - r['start'] for r in R if r['owner'] is None))
    S['objects'] = dict(collections.Counter(x['klass'] for x in X.values()))
    S['objects_seen'] = len(runs_of)
    S['unmapped_names'] = dict(unc)
    S['x86_common_names'] = len(common)
    S['functions'] = 'unresolved (no local symbols; boundaries of static code not determined)'
    S['order'] = order

    with open(runs_tsv, 'w') as f:
        f.write('# plan 415: m68k __TEXT,__text candidate runs by external-symbol name match with the 402 rebuilt x86 objects; '
                'end is an upper bound; not a boundary or source determination (m2_m68k_text_map.py)\n')
        w = csv.writer(f, delimiter='\t', lineterminator='\n')
        w.writerow(['seq', 'start', 'end_upper', 'bytes_upper', 'last_symbol_address', 'x86_n', 'x86_object',
                    'addresses', 'names', 'first_symbol', 'last_symbol', 'object_class'])
        for i, r in enumerate(R):
            o = X[r['owner']] if r['owner'] is not None else None
            w.writerow([i, '0x%x' % r['start'], '0x%x' % r['end_upper'], r['end_upper'] - r['start'], '0x%x' % r['last_symbol'],
                        o['n'] if o else '', o['object'] if o else 'unmapped', len(r['groups']),
                        sum(len(g['names']) for g in r['groups']), r['groups'][0]['names'][0], r['groups'][-1]['names'][-1],
                        o['klass'] if o else ''])
    with open(objs_tsv, 'w') as f:
        f.write('# plan 415: the 402 rebuilt x86 objects and their m68k __text candidate runs (m2_m68k_text_map.py)\n')
        w = csv.writer(f, delimiter='\t', lineterminator='\n')
        w.writerow(['x86_n', 'x86_object', 'source', 'grade', 'objc', 'x86_text_symbols', 'm68k_symbols_present',
                    'm68k_runs', 'm68k_first', 'class', 'between'])
        for n in sorted(X):
            x = X[n]
            w.writerow([n, x['object'], x['source'], x['grade'], int(x['objc']), len(x['x86_text_symbols']),
                        x['m68k_symbols_present'], x['m68k_runs'], '0x%x' % x['m68k_first'] if x['m68k_first'] else '',
                        x['klass'], ' | '.join('%d runs: %s%s' % (len(b), ','.join(b[:4]), ',...' if len(b) > 4 else '')
                                               for b in x.get('between', []))])
    json.dump(dict(plan=415, tool='10_tools/reconstruction/m2_m68k_text_map.py', tool_sha256=sha(os.path.abspath(__file__)),
                   macho_obj_sha256=sha(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'macho_obj.py')),
                   image=dict(path=IMG, sha256=IMG_SHA), symbols=dict(path=SYMS, sha256=sha(SYMS)),
                   record=dict(path=REC, sha256=sha(REC)), link=dict(path=LINK + '/run.cmd', sha256=sha(LINK + '/run.cmd')),
                   outputs={runs_tsv: sha(runs_tsv), objs_tsv: sha(objs_tsv)},
                   note='Candidate map by external-symbol name only. Runs end at an upper bound; static/unnamed code is not '
                        'assigned; the byte sums are a provisional partition, not ownership or coverage. A same-name mapping '
                        'names an x86 counterpart, not an m68k source file.',
                   summary=S, groups=[dict(g, address='0x%x' % g['address']) for g in G],
                   objects=[X[n] for n in sorted(X)]), open(out_json, 'w'), indent=1)
    print(json.dumps({k: v for k, v in S.items() if k not in ('sections', 'order')}, indent=1))
    print(json.dumps({k: (v if not isinstance(v, list) else len(v)) for k, v in order.items()}))


if __name__ == '__main__':
    if len(sys.argv) != 4:
        sys.exit(__doc__)
    main(*sys.argv[1:])
