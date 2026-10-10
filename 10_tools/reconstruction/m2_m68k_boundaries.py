#!/usr/bin/env python3
"""m2_m68k_boundaries.py -- plan 416 (M2-2): boundaries between the plan 415 candidate runs of
the m68k original's __TEXT,__text, by assigning unnamed functions (statics) to objects.

  python3 10_tools/reconstruction/m2_m68k_boundaries.py BOUNDARIES.tsv RECORD.json

Entries: external symbols; prologues ("pea a6@ / movel sp,a6" or "linkw a6,...") on a listing
row whose previous row is rts/rte/jmp/bra/nop; absolute bsr/jsr targets on a listing row.  Other
prologues are recorded as unconfirmed entries.  A function runs from its entry to the next entry.
Ownership starts from the external symbols that plan 415 mapped to an x86 object (or to an
unmapped run); an unnamed function gets the owners of every external function that reaches it
through code references (bsr/jsr/jmp/pea/lea/movel # operands, branch targets into another
function) via unnamed functions only.  One owner -> assigned; several -> conflict; a chain that
ends in an unnamed function without code references, or data-only references -> unassigned.
A boundary between runs A and B is decided only when every unnamed entry between A's last and
B's first external symbol is assigned to A or B, A's come first, and the window holds no
.word row, no external symbol off the listing rows and no unconfirmed entry.
Validation: the statics and extents of the plan 414 V10 objects that are L1 OBJECT_MATCH.
Read-only apart from the two output files.
"""
import sys, os, re, json, csv, hashlib, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj

IMG = '03_original/m68k/binaries/mach_kernel'
IMG_SHA = 'dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75'
LISTING = '08_build/artifacts/m0p414/otool-V10/image.txt'
LISTING_SHA = '9bf1c2c74f1b8a417561f98216d1f4ac6bd4cd988054c0aca670a44061476e7b'
MAP = '09_validation/reconstruction/m2-m68k-text-map-20261009.json'
GRID = '08_build/artifacts/m0p414/grid.json'
FLOW_END = {'rts', 'rte', 'jmp', 'bra', 'nop'}
HEX_L = re.compile(r'0x([0-9a-f]+):l')
BRANCH = re.compile(r'^(b(ra|hi|ls|cc|cs|ne|eq|vc|vs|pl|mi|ge|lt|gt|le)|db\w+)$')


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def read_listing():
    rows = []
    for l in open(LISTING, errors='replace').read().splitlines():
        w = l.split('\t')
        if len(w) >= 2 and re.match(r'^[0-9a-f]{8}$', w[0]):
            rows.append((int(w[0], 16), w[1], w[2] if len(w) > 2 else ''))
    return rows


def is_prologue(rows, i):
    a, m, o = rows[i]
    if m == 'pea' and o == 'a6@':
        return i + 1 < len(rows) and rows[i + 1][1] == 'movel' and rows[i + 1][2] == 'sp,a6'
    return m == 'linkw' and o.startswith('a6,')


def main(out_tsv, out_json):
    assert sha(IMG) == IMG_SHA and sha(LISTING) == LISTING_SHA
    img = macho_obj.parse(open(IMG, 'rb').read())
    ib = open(IMG, 'rb').read()
    text = [s for s in img['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
    lo, hi = text['addr'], text['addr'] + text['size']
    M = json.load(open(MAP))
    assert M['outputs'] and M['image']['sha256'] == IMG_SHA
    groups = [dict(g, address=int(g['address'], 16)) for g in M['groups']]
    names = {o['n']: o['object'] for o in M['objects']}

    # plan 415 runs (owner tokens: ('obj', n) or ('unmapped', run index))
    runs = []
    for g in groups:
        if runs and runs[-1]['owner'] == g['owner']:
            runs[-1]['groups'].append(g)
        else:
            runs.append(dict(owner=g['owner'], groups=[g]))
    assert len(runs) == M['summary']['runs']
    tok = {}
    for k, r in enumerate(runs):
        r['token'] = ('obj', r['owner']) if r['owner'] is not None else ('unmapped', k)
        for g in r['groups']:
            tok[g['address']] = r['token']

    rows = read_listing()
    at = {a: i for i, (a, _, _) in enumerate(rows)}
    ext = sorted(tok)
    off_listing = [a for a in ext if a not in at]

    # entries
    kind = collections.defaultdict(set)
    for a in ext:
        kind[a].add('external')
    unconfirmed = []
    for i in range(len(rows)):
        if is_prologue(rows, i):
            a = rows[i][0]
            if i > 0 and rows[i - 1][1] in FLOW_END:
                kind[a].add('prologue')
            elif a not in kind:
                unconfirmed.append(a)
    for a, m, o in rows:
        if m in ('bsr', 'jsr'):
            t = HEX_L.fullmatch(o) or re.fullmatch(r'0x([0-9a-f]+):b', o)
            if t:
                v = int(t.group(1), 16)
                if lo <= v < hi and v in at:
                    kind[v].add('call target')
    entries = sorted(kind)
    unconfirmed = sorted(set(unconfirmed) - set(entries))
    import bisect

    def func_of(a):
        k = bisect.bisect_right(entries, a) - 1
        return entries[k] if k >= 0 else None

    # code references: referencing function -> referenced entry
    callers = collections.defaultdict(set)
    for a, m, o in rows:
        f = func_of(a)
        targets = [int(x, 16) for x in HEX_L.findall(o)]
        if BRANCH.match(m):
            t = re.fullmatch(r'(?:d[0-7],)?0x([0-9a-f]+):[bwl]', o)
            targets = [int(t.group(1), 16)] if t else []
        for v in targets:
            if v in kind and v != f:
                callers[v].add(f)
    # data references (recorded only)
    dref = collections.Counter()
    for s in img['sections']:
        if s['segname'] == '__DATA' or (s['segname'], s['sectname']) == ('__TEXT', '__const'):
            if s['sectname'] in ('__bss', '__common'):
                continue
            b = ib[s['offset']:s['offset'] + s['size']]
            for k in range(0, len(b) - 3, 2):
                v = int.from_bytes(b[k:k + 4], 'big')
                if v in kind:
                    dref[v] += 1

    # ownership by reachability from owned external functions through unnamed functions
    def owners(e):
        """owner tokens of the external functions reaching e through unnamed callers (reverse search)."""
        res, todo, seen = set(), [e], {e}
        while todo:
            x = todo.pop()
            cs = callers.get(x, set())
            if not cs:
                res.add(('none',))
            for c in cs:
                if c is None:
                    res.add(('none',))
                elif c in tok:
                    res.add(tok[c])
                elif c not in seen:
                    seen.add(c)
                    todo.append(c)
        return res

    owner = {}
    for e in entries:
        if e in tok:
            owner[e] = tok[e]
            continue
        o = owners(e)
        owner[e] = next(iter(o)) if len(o) == 1 and ('none',) not in o else (
            'conflict' if len([x for x in o if x != ('none',)]) > 1 else 'unassigned')

    # boundaries between consecutive runs
    word_rows = [a for a, m, _ in rows if m == '.word']
    B = []
    for k in range(len(runs) - 1):
        A_, B_ = runs[k], runs[k + 1]
        a_last = A_['groups'][-1]['address']
        b_first = B_['groups'][0]['address']
        win = [e for e in entries if a_last < e < b_first]
        flags = []
        if any(a_last <= w < b_first for w in word_rows):
            flags.append('.word rows')
        if a_last in off_listing or b_first in off_listing:
            flags.append('external symbol off the listing')
        if any(a_last < u < b_first for u in unconfirmed):
            flags.append('unconfirmed entry')
        own = [owner[e] for e in win]
        p = 0
        while p < len(own) and own[p] == A_['token']:
            p += 1
        s = 0
        while s < len(own) - p and own[len(own) - 1 - s] == B_['token']:
            s += 1
        lower = win[p] if p < len(win) else b_first
        upper = win[len(win) - s] if s else b_first
        if p + s < len(win):
            flags.append('unresolved entries: ' + ','.join(sorted({str(x[0]) if isinstance(x, tuple) else x
                                                                  for x in own[p:len(own) - s]})))
        decided = not flags and lower == upper
        B.append(dict(k=k, a=A_['token'], b=B_['token'], a_last=a_last, b_first=b_first, unnamed=len(win),
                      to_a=p, to_b=s, lower=lower, upper=upper, decided=decided, flags=flags))

    # validation: plan 414 V10 OBJECT_MATCH objects
    G = json.load(open(GRID))
    byname = collections.defaultdict(list)
    for o in M['objects']:
        byname[o['object']].append(o['n'])
    V = []
    for r in G['objects']:
        if r['variant'] != 'V10' or r['verdict'] != 'OBJECT_MATCH':
            continue
        d = json.load(open(os.path.join('08_build/artifacts/m0p414/l1', 'l1-V10-%s.json' % r['object'])))
        place = d['placements'].get('__TEXT,__text')
        if place is None:
            continue
        assert len(byname[r['object']]) == 1, r['object']
        n = byname[r['object']][0]
        ob = macho_obj.parse(open(r['obj'], 'rb').read())
        ts = [s for s in ob['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
        stat = [(place + y['value'] - ts['addr'], y['name']) for y in ob['symbols']
                if y['kind'] == 'SECT' and not y['stab'] and not y.get('ext') and y['sect'] == ts['index']
                and not y['name'].startswith(('gcc2_compiled', '___gnu_compiled'))]
        res = []
        for a, nm in stat:
            got = owner.get(a)
            res.append(dict(name=nm, address=a, detected=a in kind,
                            owner=('obj', n) == got if isinstance(got, tuple) else got))
        start, end = place, place + ts['size']
        bres = []
        for b in B:
            if b['decided'] and (b['a'] == ('obj', n) or b['b'] == ('obj', n)):
                want = end if b['a'] == ('obj', n) else start
                bres.append(dict(k=b['k'], side='end' if b['a'] == ('obj', n) else 'start', boundary=b['upper'],
                                 expected=want, ok=b['upper'] == want))
        V.append(dict(object=r['object'], n=n, start=start, end=end, statics=res, boundaries=bres))
    VS = dict(objects=len(V), statics=sum(len(v['statics']) for v in V),
              statics_detected=sum(1 for v in V for s in v['statics'] if s['detected']),
              statics_owner_correct=sum(1 for v in V for s in v['statics'] if s['owner'] is True),
              statics_owner_wrong_object=sum(1 for v in V for s in v['statics'] if s['owner'] is False),
              statics_abstained=sum(1 for v in V for s in v['statics'] if s['owner'] not in (True, False)),
              boundaries_checked=sum(len(v['boundaries']) for v in V),
              boundaries_wrong=sum(1 for v in V for b in v['boundaries'] if not b['ok']))

    S = collections.OrderedDict()
    S['entries'] = len(entries)
    S['entry_kinds'] = dict(collections.Counter('+'.join(sorted(kind[e])) for e in entries))
    S['unnamed_entries'] = sum(1 for e in entries if e not in tok)
    S['unconfirmed_prologues'] = len(unconfirmed)
    S['external_off_listing'] = len(off_listing)
    S['word_rows'] = len(word_rows)
    S['unnamed_owner'] = dict(collections.Counter(
        ('object' if owner[e][0] == 'obj' else 'unmapped run') if isinstance(owner[e], tuple) else owner[e]
        for e in entries if e not in tok))
    S['unnamed_with_data_refs'] = sum(1 for e in entries if e not in tok and dref[e])
    S['boundaries'] = len(B)
    S['decided'] = sum(b['decided'] for b in B)
    S['decided_with_unnamed'] = sum(1 for b in B if b['decided'] and b['unnamed'])
    S['flags'] = dict(collections.Counter(f.split(':')[0] for b in B for f in b['flags']))
    S['validation'] = VS

    def tname(t):
        return names[t[1]] if t[0] == 'obj' else 'unmapped#%d' % t[1]

    with open(out_tsv, 'w') as f:
        f.write('# plan 416: boundaries between the plan 415 runs of the m68k __text; decided = every unnamed entry in the '
                'window assigned by code references, no decoding doubt (m2_m68k_boundaries.py)\n')
        w = csv.writer(f, delimiter='\t', lineterminator='\n')
        w.writerow(['k', 'run_a', 'run_b', 'a_last_symbol', 'b_first_symbol', 'unnamed_entries', 'to_a', 'to_b',
                    'boundary_lower', 'boundary_upper', 'decided', 'flags'])
        for b in B:
            w.writerow([b['k'], tname(b['a']), tname(b['b']), '0x%x' % b['a_last'], '0x%x' % b['b_first'], b['unnamed'],
                        b['to_a'], b['to_b'], '0x%x' % b['lower'], '0x%x' % b['upper'], int(b['decided']), '; '.join(b['flags'])])
    json.dump(dict(plan=416, tool='10_tools/reconstruction/m2_m68k_boundaries.py', tool_sha256=sha(os.path.abspath(__file__)),
                   image=dict(path=IMG, sha256=IMG_SHA), listing=dict(path=LISTING, sha256=LISTING_SHA),
                   map=dict(path=MAP, sha256=sha(MAP)), grid=dict(path=GRID, sha256=sha(GRID)),
                   outputs={out_tsv: sha(out_tsv)},
                   note='Ownership of unnamed functions from code references reaching them from owned external functions; '
                        'data references are recorded but not used. A decided boundary rests on the entry rules; '
                        'validation covers the plan 414 V10 objects that are L1 OBJECT_MATCH (rebuilt spans equal at those addresses).',
                   summary=S, validation=V,
                   entries=[dict(address='0x%x' % e, kinds=sorted(kind[e]), owner=(tname(owner[e]) if isinstance(owner[e], tuple) and owner[e][0] in ('obj', 'unmapped') else owner[e]),
                                 callers=len(callers.get(e, ())), data_refs=dref[e]) for e in entries if e not in tok],
                   unconfirmed=['0x%x' % u for u in unconfirmed], off_listing=['0x%x' % a for a in off_listing],
                   boundaries=[dict(b, a=tname(b['a']), b=tname(b['b'])) for b in B]), open(out_json, 'w'), indent=1)
    print(json.dumps(S, indent=1))


if __name__ == '__main__':
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    main(*sys.argv[1:])
