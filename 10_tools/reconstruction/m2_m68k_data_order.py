#!/usr/bin/env python3
"""m2_m68k_data_order.py -- plan 418 (M2-4): the plan 417 rules plus one more acceptance of a
code-referenced data item start: its single referencing owner O lies, in __text link position,
between the owners P and Q of the nearest external data symbols before and after it, each of which
must be defined directly by an x86 object with a link position (plan 418.2; only in sections where
those owners are in link order).

  python3 10_tools/reconstruction/m2_m68k_data_order.py BOUNDARIES.tsv RECORD.json

The plan 417 result is first reproduced with the extension off (asserted against its record).
Checks: plan 417 validation sets, five foreign interior references that must not become items of
the referencing object, and a held-out run with the x86-defined data names of xdr_mbuf removed.
Code copied from m2_m68k_data_owner.py (plan 417), which is unchanged.
Read-only apart from the two output files.
"""
import sys, os, re, json, csv, hashlib, bisect, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m2_m68k_boundaries as B416

IMG, IMG_SHA, LISTING, LISTING_SHA = B416.IMG, B416.IMG_SHA, B416.LISTING, B416.LISTING_SHA
MAP, GRID = B416.MAP, B416.GRID
REC416 = '09_validation/reconstruction/m2-m68k-boundaries-20261009.json'
REC417 = '09_validation/reconstruction/m2-m68k-data-owner-20261009.json'
NEGATIVE = (0x40adbfc, 0x40add4c, 0x40ae4b0, 0x40af33a, 0x40af35e)   # plan 418.1: _sysent+168/+504, _linesw+4, _around+4, _inside+4
HELD_OUT = 'x86-xdr_mbuf'
REC409 = '09_validation/reconstruction/m0-i386-18334-l1-20261009.json'
HEX_L, BRANCH, FLOW_END = B416.HEX_L, B416.BRANCH, B416.FLOW_END
sha = B416.sha
DATA_SECTS = (('__DATA', '__data'), ('__TEXT', '__const'))


def main(out_tsv=None, out_json=None, extend=True, hidden=frozenset()):
    assert sha(IMG) == IMG_SHA and sha(LISTING) == LISTING_SHA
    ib = open(IMG, 'rb').read()
    img = macho_obj.parse(ib)
    text = [s for s in img['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
    lo, hi = text['addr'], text['addr'] + text['size']
    M = json.load(open(MAP))
    R416 = json.load(open(REC416))
    assert R416['map']['sha256'] == sha(MAP) and R416['listing']['sha256'] == LISTING_SHA
    groups = [dict(g, address=int(g['address'], 16)) for g in M['groups']]
    names = {o['n']: o['object'] for o in M['objects']}

    # ---- plan 416, same rules
    runs = []
    for g in groups:
        if runs and runs[-1]['owner'] == g['owner']:
            runs[-1]['groups'].append(g)
        else:
            runs.append(dict(owner=g['owner'], groups=[g]))
    tok = {}
    for k, r in enumerate(runs):
        r['token'] = ('obj', r['owner']) if r['owner'] is not None else ('unmapped', k)
        for g in r['groups']:
            tok[g['address']] = r['token']
    rows = B416.read_listing()
    at = {a: i for i, (a, _, _) in enumerate(rows)}
    ext = sorted(tok)
    off_listing = [a for a in ext if a not in at]
    kind = collections.defaultdict(set)
    for a in ext:
        kind[a].add('external')
    unconfirmed = []
    for i in range(len(rows)):
        if B416.is_prologue(rows, i):
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

    def func_of(a):
        k = bisect.bisect_right(entries, a) - 1
        return entries[k] if k >= 0 else None

    callers = collections.defaultdict(set)
    coderef_data = collections.defaultdict(set)      # data address -> referencing functions
    dsecs = [s for s in img['sections'] if (s['segname'], s['sectname']) in DATA_SECTS]

    def dsec_of(v):
        for s in dsecs:
            if s['addr'] <= v < s['addr'] + s['size']:
                return s
        return None
    for a, m, o in rows:
        f = func_of(a)
        targets = [int(x, 16) for x in HEX_L.findall(o)]
        for v in targets:
            if dsec_of(v):
                coderef_data[v].add(f)
        if BRANCH.match(m):
            t = re.fullmatch(r'(?:d[0-7],)?0x([0-9a-f]+):[bwl]', o)
            targets = [int(t.group(1), 16)] if t else []
        for v in targets:
            if v in kind and v != f:
                callers[v].add(f)
    dwords = collections.defaultdict(list)            # entry -> data word addresses pointing at it
    for s in dsecs:
        b = ib[s['offset']:s['offset'] + s['size']]
        for k in range(0, len(b) - 3, 2):
            v = int.from_bytes(b[k:k + 4], 'big')
            if v in kind:
                dwords[v].append(s['addr'] + k)

    def owners416(e):
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

    own416 = {}
    for e in entries:
        if e in tok:
            own416[e] = tok[e]
            continue
        o = owners416(e)
        own416[e] = next(iter(o)) if len(o) == 1 and ('none',) not in o else (
            'conflict' if len([x for x in o if x != ('none',)]) > 1 else 'unassigned')

    def tname(t):
        if isinstance(t, tuple) and t[0] == 'obj':
            return names[t[1]]
        if isinstance(t, tuple) and t[0] == 'unmapped':
            return 'unmapped#%d' % t[1]
        return t
    rec_e = {int(e['address'], 16): e['owner'] for e in R416['entries']}
    assert set(rec_e) == {e for e in entries if e not in tok}, 'plan 416 entries differ'
    assert all(rec_e[e] == tname(own416[e]) for e in rec_e), 'plan 416 owners differ'

    word_rows = [a for a, m, _ in rows if m == '.word']

    def boundaries(owner):
        out = []
        for k in range(len(runs) - 1):
            A_, B_ = runs[k], runs[k + 1]
            a_last, b_first = A_['groups'][-1]['address'], B_['groups'][0]['address']
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
            out.append(dict(k=k, a=A_['token'], b=B_['token'], a_last=a_last, b_first=b_first, unnamed=len(win),
                            to_a=p, to_b=s, lower=lower, upper=upper, decided=not flags and lower == upper, flags=flags))
        return out
    B0 = boundaries(own416)
    assert [(b['decided'], b['lower'], b['upper']) for b in B0] == \
        [(b['decided'], b['lower'], b['upper']) for b in R416['boundaries']], 'plan 416 boundaries differ'

    # ---- data items
    rec409 = json.load(open(REC409))['slice']['objects']
    x86data = {}
    for o in rec409:
        assert sha(o['obj']) == o['obj_sha256']
        ob = macho_obj.parse(open(o['obj'], 'rb').read())
        osec = {s['index']: (s['segname'], s['sectname']) for s in ob['sections']}
        for y in ob['symbols']:
            if y['kind'] == 'SECT' and y.get('ext') and not y['stab'] and osec[y['sect']] != ('__TEXT', '__text') \
                    and y['name'] not in hidden:
                x86data[y['name']] = o['n']
    dext = collections.defaultdict(list)              # data symbol address -> names
    for y in img['symbols']:
        if y['kind'] == 'SECT' and not y['stab'] and y.get('ext'):
            s = [x for x in img['sections'] if x['index'] == y['sect']][0]
            if (s['segname'], s['sectname']) in DATA_SECTS and y['name'] not in hidden:
                dext[y['value']].append(y['name'])
    starts = {}
    for s in dsecs:
        k = (s['segname'], s['sectname'])
        starts[k] = sorted(set(a for a in dext if s['addr'] <= a < s['addr'] + s['size']) |
                           set(a for a in coderef_data if s['addr'] <= a < s['addr'] + s['size']))
    ext_sorted = {k: sorted(a for a in dext if a in set(v)) for k, v in starts.items()}

    # plan 418: link positions and the directly defined, positioned external data symbols per section
    klass = {o['n']: o['klass'] for o in M['objects']}
    pos = {}
    for r in runs:
        t = r['token']
        if t[0] == 'unmapped' or klass[t[1]] == 'contiguous':
            pos[t] = r['groups'][0]['address']
    direct, order_ok = {}, {}
    for k, v in starts.items():
        L = []
        for a in ext_sorted[k]:
            xs = {x86data[n] for n in dext[a] if n in x86data}
            if len(xs) == 1 and ('obj', next(iter(xs))) in pos:
                L.append((a, ('obj', xs.pop())))
        direct[k] = L
        ps = [pos[t] for _, t in L]
        order_ok[k] = all(x <= y for x, y in zip(ps, ps[1:]))
    rule_of = {}

    def code_owner(addr, own):
        fs = coderef_data.get(addr, set())
        o = {own.get(f) if f is not None else None for f in fs}
        o = {x for x in o if not isinstance(x, tuple) or x[0] != 'none'}
        return next(iter(o)) if len(o) == 1 and isinstance(next(iter(o)), tuple) else None

    def ext_owner(addr, own):
        xs = {x86data[n] for n in dext[addr] if n in x86data}
        if len(xs) == 1:
            return ('obj', xs.pop())
        if xs:
            return None
        return code_owner(addr, own)

    def item_owner(w, own):
        s = dsec_of(w)
        if s is None:
            return None, None
        k = (s['segname'], s['sectname'])
        L = starts[k]
        i = bisect.bisect_right(L, w) - 1
        if i < 0:
            return None, None
        st = L[i]
        if st in dext:
            return ext_owner(st, own), st
        o = code_owner(st, own)
        if o is None:
            return None, st
        E = ext_sorted[k]
        j = bisect.bisect_right(E, st) - 1
        before = ext_owner(E[j], own) if j >= 0 else None
        after = ext_owner(E[j + 1], own) if j + 1 < len(E) else None
        if o in (before, after):
            rule_of[st] = 'plan 417'
            return o, st
        if not extend or not order_ok[k] or o not in pos:
            return None, st
        # plan 418.2: the nearest external data symbols of any kind; each present one must be directly
        # defined by an x86 object with a link position
        dmap = dict(direct[k])
        E = ext_sorted[k]
        j = bisect.bisect_right(E, st) - 1
        Pa = E[j] if j >= 0 else None
        Qa = E[j + 1] if j + 1 < len(E) else None
        if (Pa is None and Qa is None) or (Pa is not None and Pa not in dmap) or (Qa is not None and Qa not in dmap):
            return None, st
        P = dmap[Pa] if Pa is not None else None
        Q = dmap[Qa] if Qa is not None else None
        if (P is None or pos[P] <= pos[o]) and (Q is None or pos[o] <= pos[Q]):
            rule_of[st] = 'plan 418 order'
            return o, st
        return None, st

    # ---- iterate: data items and code propagation
    own = {e: own416[e] for e in entries if isinstance(own416[e], tuple)}

    def evidence(e, own):
        res, todo, seen = set(), [e], {e}
        while todo:
            x = todo.pop()
            cs = callers.get(x, set())
            ws = dwords.get(x, [])
            if not cs and not ws:
                res.add(('none',))
            for c in cs:
                if c is None:
                    res.add(('none',))
                elif c in own:
                    res.add(own[c])
                elif c not in seen:
                    seen.add(c)
                    todo.append(c)
            for w in ws:
                o, _ = item_owner(w, own)
                res.add(o if o is not None else ('none',))
        return res

    rounds = 0
    while True:
        rounds += 1
        new = {}
        for e in entries:
            if e in own:
                continue
            r = evidence(e, own)
            if len(r) == 1 and ('none',) not in r:
                new[e] = next(iter(r))
        if not new:
            break
        own.update(new)
    # contradictions: plan 416 owners against all final evidence
    contra = []
    for e in entries:
        if e in tok or not isinstance(own416[e], tuple):
            continue
        r = evidence(e, {k: v for k, v in own.items() if k != e}) - {('none',)}
        if r and r != {own416[e]}:
            contra.append(dict(entry='0x%x' % e, plan416=tname(own416[e]), evidence=sorted(tname(x) for x in r)))
    final = {e: (own[e] if e in own else ('conflict' if len(evidence(e, own) - {('none',)}) > 1 else 'unassigned'))
             for e in entries}
    B1 = boundaries(final)

    # ---- validation
    G = json.load(open(GRID))
    byname = collections.defaultdict(list)
    for o in M['objects']:
        byname[o['object']].append(o['n'])
    VD, VS, VB, fp = [], [], [], {}
    for r in G['objects']:
        if r['variant'] != 'V10':
            continue
        d = json.load(open(os.path.join('08_build/artifacts/m0p414/l1', 'l1-V10-%s.json' % r['object'])))
        assert len(byname[r['object']]) == 1, r['object']
        n = byname[r['object']][0]
        ob = macho_obj.parse(open(r['obj'], 'rb').read())
        osecs = {(s['segname'], s['sectname']): s for s in ob['sections']}
        tsec = osecs.get(('__TEXT', '__text'))
        for key in DATA_SECTS:
            sk = '%s,%s' % key
            sd = d['sections'].get(sk)
            if not sd or sk not in d['placements'] or d['placements'][sk] is None:
                continue
            ok = r['verdict'] == 'OBJECT_MATCH' or (sd.get('byte_differences') == 0 and sd.get('refs_differ') == 0
                                                     and sd.get('refs_unverified') == 0)
            if not ok:
                continue
            base, size = d['placements'][sk], sd['size']
            osd = osecs[key]
            fp[r['object']] = fp.get(r['object'], 0) + sum(
                1 for x in osd['relocs'] if not x['scattered'] and (
                    (not x['extern'] and tsec and x['symbolnum'] == tsec['index']) or
                    (x['extern'] and ob['symbols'][x['symbolnum']]['sect'] == (tsec['index'] if tsec else -1))))
            for w in range(base, base + size - 1, 2):
                o, st = item_owner(w, own)
                VD.append(dict(object=r['object'], section=sk, word='0x%x' % w, rule=rule_of.get(st) if o else None,
                               result='abstain' if o is None else ('ok' if o == ('obj', n) else 'wrong')))
        if r['verdict'] != 'OBJECT_MATCH' or d['placements'].get('__TEXT,__text') is None:
            continue
        place = d['placements']['__TEXT,__text']
        for y in ob['symbols']:
            if y['kind'] == 'SECT' and not y['stab'] and not y.get('ext') and y['sect'] == tsec['index'] \
                    and not y['name'].startswith(('gcc2_compiled', '___gnu_compiled')):
                a = place + y['value'] - tsec['addr']
                got = final.get(a)
                VS.append(dict(object=r['object'], name=y['name'], address='0x%x' % a, detected=a in kind,
                               result='ok' if got == ('obj', n) else ('wrong' if isinstance(got, tuple) else 'abstain')))
        start, end = place, place + tsec['size']
        for b in B1:
            if b['decided'] and (b['a'] == ('obj', n) or b['b'] == ('obj', n)):
                want = end if b['a'] == ('obj', n) else start
                VB.append(dict(object=r['object'], k=b['k'], ok=b['upper'] == want))
    neg = []
    for a in NEGATIVE:
        o, st = item_owner(a, own)
        foreign = code_owner(a, own)
        neg.append(dict(address='0x%x' % a, item_start='0x%x' % st if st else None, owner=tname(o) if o else None,
                        referencing_owner=tname(foreign) if foreign else None,
                        passed=(o is None or o != foreign)))
    V = dict(data_words=dict(collections.Counter(x['result'] for x in VD)),
             data_words_by_rule=dict(collections.Counter('%s %s' % (x['rule'], x['result']) for x in VD if x['rule'])),
             negative=neg,
             data_words_by_section=dict(collections.Counter('%s %s' % (x['section'], x['result']) for x in VD)),
             function_pointer_relocations=fp,
             statics=dict(collections.Counter(x['result'] for x in VS)), statics_detected=sum(x['detected'] for x in VS),
             boundaries_checked=len(VB), boundaries_wrong=sum(1 for x in VB if not x['ok']))

    S = collections.OrderedDict()
    S['plan416_reproduced'] = True
    S['rounds'] = rounds
    S['unnamed_entries'] = sum(1 for e in entries if e not in tok)
    S['unnamed_owner_416'] = dict(collections.Counter(
        ('object' if own416[e][0] == 'obj' else 'unmapped run') if isinstance(own416[e], tuple) else own416[e]
        for e in entries if e not in tok))
    S['unnamed_owner_417'] = dict(collections.Counter(
        ('object' if final[e][0] == 'obj' else 'unmapped run') if isinstance(final[e], tuple) else final[e]
        for e in entries if e not in tok))
    S['newly_owned'] = sum(1 for e in entries if e not in tok and not isinstance(own416[e], tuple) and isinstance(final[e], tuple))
    S['contradictions'] = len(contra)
    S['data_item_starts'] = {'%s,%s' % k: len(v) for k, v in starts.items()}
    S['boundaries'] = len(B1)
    S['decided_416'] = sum(b['decided'] for b in B0)
    S['decided'] = sum(b['decided'] for b in B1)
    S['order_ok'] = {'%s,%s' % k: v for k, v in order_ok.items()}
    S['direct_positioned_data_symbols'] = {'%s,%s' % k: len(v) for k, v in direct.items()}
    S['item_starts_by_rule'] = dict(collections.Counter(rule_of.values()))
    S['newly_decided'] = [dict(a=tname(b['a']), b=tname(b['b']), boundary='0x%x' % b['upper'])
                          for b0, b in zip(B0, B1) if b['decided'] and not b0['decided']]
    S['no_longer_decided'] = sum(1 for b0, b in zip(B0, B1) if b0['decided'] and not b['decided'])
    S['decided_moved'] = sum(1 for b0, b in zip(B0, B1) if b0['decided'] and b['decided'] and b0['upper'] != b['upper'])
    S['flags'] = dict(collections.Counter(f.split(':')[0] for b in B1 for f in b['flags']))
    S['validation'] = V

    res = dict(S=S, final=final, own416=own416, B0=B0, B1=B1, VD=VD, tok=tok, entries=entries, tname=tname, contra=contra,
               dwords=dwords, callers=callers)
    if out_tsv is None:
        return res
    with open(out_tsv, 'w') as f:
        f.write('# plan 418: plan 416 boundaries decided again with data-table ownership of unnamed functions, '
                'link-order acceptance of code-referenced data items (m2_m68k_data_order.py); rule-based\n')
        w = csv.writer(f, delimiter='\t', lineterminator='\n')
        w.writerow(['k', 'run_a', 'run_b', 'a_last_symbol', 'b_first_symbol', 'unnamed_entries', 'to_a', 'to_b',
                    'boundary_lower', 'boundary_upper', 'decided', 'decided_416', 'flags'])
        for b0, b in zip(B0, B1):
            w.writerow([b['k'], tname(b['a']), tname(b['b']), '0x%x' % b['a_last'], '0x%x' % b['b_first'], b['unnamed'],
                        b['to_a'], b['to_b'], '0x%x' % b['lower'], '0x%x' % b['upper'], int(b['decided']),
                        int(b0['decided']), '; '.join(b['flags'])])
    json.dump(dict(plan=418, tool='10_tools/reconstruction/m2_m68k_data_order.py', tool_sha256=sha(os.path.abspath(__file__)),
                   m2_m68k_data_owner_sha256=sha(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'm2_m68k_data_owner.py')),
                   plan417=dict(path=REC417, sha256=sha(REC417)), extra=EXTRA,
                   m2_m68k_boundaries_sha256=sha(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'm2_m68k_boundaries.py')),
                   image=dict(path=IMG, sha256=IMG_SHA), listing=dict(path=LISTING, sha256=LISTING_SHA),
                   map=dict(path=MAP, sha256=sha(MAP)), plan416=dict(path=REC416, sha256=sha(REC416)),
                   grid=dict(path=GRID, sha256=sha(GRID)), outputs={out_tsv: sha(out_tsv)},
                   note='Rule-based ownership as plan 417; a code-referenced data address is also accepted as an item start '
                        'when its referencing owner lies in link position between the directly defined external data symbols '
                        'around it. Pointer words are candidates; ownership is not content match or source determination.',
                   summary=S, contradictions=contra,
                   entries=[dict(address='0x%x' % e, owner416=tname(own416[e]), owner=tname(final[e]),
                                 data_words=len(dwords.get(e, [])), callers=len(callers.get(e, ())))
                            for e in entries if e not in tok and own416[e] != final[e]],
                   validation_detail=dict(data_words=[x for x in VD if x['result'] != 'ok'], statics=VS),
                   boundaries=[dict(b, a=tname(b['a']), b=tname(b['b'])) for b in B1]), open(out_json, 'w'), indent=1)
    print(json.dumps(S, indent=1))
    return res


EXTRA = {}


def cli(out_tsv, out_json):
    R = json.load(open(REC417))
    base = main(extend=False)
    S0 = base['S']
    assert S0['decided'] == R['summary']['decided_417'] and S0['newly_owned'] == R['summary']['newly_owned'] \
        and S0['contradictions'] == R['summary']['contradictions'], 'plan 417 summary not reproduced'
    tn = base['tname']
    got = sorted((('0x%x' % e), tn(base['final'][e])) for e in base['entries']
                 if e not in base['tok'] and base['own416'][e] != base['final'][e])
    assert got == sorted((x['address'], x['owner417']) for x in R['entries']), 'plan 417 owners not reproduced'
    assert [(b['decided'], b['upper']) for b in base['B1']] == [(b['decided'], b['upper']) for b in R['boundaries']]
    EXTRA['plan417_reproduced'] = True
    # held-out: the x86-defined data names of xdr_mbuf removed from inference
    rec409 = json.load(open(REC409))['slice']['objects']
    o = [x for x in rec409 if x['object'] == HELD_OUT]
    assert len(o) == 1
    ob = macho_obj.parse(open(o[0]['obj'], 'rb').read())
    osec = {s['index']: (s['segname'], s['sectname']) for s in ob['sections']}
    hide = frozenset(y['name'] for y in ob['symbols'] if y['kind'] == 'SECT' and y.get('ext') and not y['stab']
                     and osec[y['sect']] != ('__TEXT', '__text'))
    h = main(extend=True, hidden=hide)
    EXTRA['held_out'] = dict(object=HELD_OUT, hidden_names=sorted(hide),
                             data_words=dict(collections.Counter(x['result'] for x in h['VD'] if x['object'] == HELD_OUT)),
                             by_rule=dict(collections.Counter('%s %s' % (x['rule'], x['result'])
                                                              for x in h['VD'] if x['object'] == HELD_OUT)),
                             other_wrong=sum(1 for x in h['VD'] if x['result'] == 'wrong'))
    main(out_tsv, out_json, extend=True)


if __name__ == '__main__':
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    cli(*sys.argv[1:])
