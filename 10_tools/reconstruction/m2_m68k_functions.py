#!/usr/bin/env python3
"""m2_m68k_functions.py -- plan 424 (M2-10): m68k function candidates and their ranges by
reachability over the real-machine otool listing (rule RECONSTRUCTION_PLAN :78, plan 424.1).

  python3 10_tools/reconstruction/m2_m68k_functions.py FUNCTIONS.tsv RECORD.json

Candidate = entry (plan 418), range = [entry, next entry).  Reach from the entry: branches
bra/b<cc> (size suffix), db<cc> (no suffix), fb<cc>, absolute jmp; calls bsr/jsr continue;
rts/rte end; stop/trap continue; .word and <bad ef> rows are invalid; "jmp aN@" follows a GCC
jump table (movel #T / lea T to aN, movel aN@(0x0:b,Rm:l:4),aN) whose length is the preceding
moveq/cmpl bound + 1.  A final 2-byte nop right before the next entry ends a fall-through and
counts as covered (image observation, counted); a candidate that is only such a nop is padding
and an absolute call target inside a range (not its start) leaves it undetermined (plan 424.2).  Range confirmed = (a) no reach outside the
range, (b) every reached address a valid listing row, (c) indirect jumps resolved, (d) every
byte covered by reached rows or tables, (e) no non-call branch to another entry and no non-call
edge from another candidate into the range.  Entries that are data (off the listing, or whose
first row is invalid or a zero word) are a separate class.
Tests: the plan 414 V10 OBJECT_MATCH functions, a drop test and a split test.
Read-only apart from the two output files.
"""
import sys, os, re, json, csv, bisect, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m2_m68k_text_map as T415
import m2_m68k_boundaries as B416
import m2_m68k_data_order as D418

IMG, IMG_SHA, GRID = D418.IMG, D418.IMG_SHA, D418.GRID
LISTING, LISTING_SHA = B416.LISTING, B416.LISTING_SHA
OBJS = '06_reconstruction/m68k-objects.tsv'
IDA = '05_ida/exports/m68k/initial-functions.json'
sha = T415.sha
BR = re.compile(r'^(bra|b(hi|ls|cc|cs|ne|eq|vc|vs|pl|mi|ge|lt|gt|le)|db\w+|fb\w+)$')
TGT = re.compile(r'0x([0-9a-f]+)(?::[bwl])?$')


class Text:
    def __init__(self):
        assert sha(IMG) == IMG_SHA and sha(LISTING) == LISTING_SHA
        self.ib = open(IMG, 'rb').read()
        img = macho_obj.parse(self.ib)
        t = [s for s in img['sections'] if s['sectname'] == '__text'][0]
        self.lo, self.hi, self.off = t['addr'], t['addr'] + t['size'], t['offset']
        self.rows = [r for r in B416.read_listing() if self.lo <= r[0] < self.hi]
        self.addrs = [r[0] for r in self.rows]
        self.at = {r[0]: i for i, r in enumerate(self.rows)}

    def word(self, a, n=4):
        k = self.off + a - self.lo
        return int.from_bytes(self.ib[k:k + n], 'big')

    def nxt(self, i):
        return self.rows[i + 1][0] if i + 1 < len(self.rows) else self.hi


def invalid(m, o):
    return m == '.word' or '<bad ef>' in o


def table(X, i):
    """(base, n_entries) of a GCC jump table for the 'jmp aN@' row i, else None."""
    m, o = X.rows[i][1], X.rows[i][2]
    r = re.fullmatch(r'(a[0-7])@', o)
    if m != 'jmp' or not r:
        return None
    reg = r.group(1)
    prev = X.rows[max(0, i - 6):i]
    if not any(p[1] == 'movel' and re.fullmatch(r'%s@\(0x0:b,[ad][0-7]:l:4\),%s' % (reg, reg), p[2]) for p in prev):
        return None
    base = None
    for p in reversed(prev):
        mm = re.fullmatch(r'#?0x([0-9a-f]+):l,%s' % reg, p[2])
        if p[1] in ('movel', 'lea') and mm:
            base = int(mm.group(1), 16)
            break
    bound = None
    for p in reversed(X.rows[max(0, i - 8):i]):
        mm = re.match(r'#(-?\d+|0x[0-9a-f]+)(?::[bwl])?,', p[2])
        if p[1] in ('moveq', 'cmpl', 'cmpw') and mm:
            v = mm.group(1)
            bound = int(v, 16) if v.startswith('0x') else int(v)
            break
    if base is None or bound is None or base != X.rows[i][0] + 2 or bound < 0:
        return None
    return base, bound + 1


def reach(X, e, end, entries):
    """reached rows, covered table bytes, reasons and non-call edges for the candidate [e, end)."""
    reasons, edges, tables, covered = set(), [], [], set()
    allowance = 0
    todo, seen = [e], set()
    while todo:
        a = todo.pop()
        if a in seen:
            continue
        seen.add(a)
        if not (e <= a < end):
            reasons.add('reach outside range')
            edges.append(a)
            continue
        if a not in X.at:
            reasons.add('reach off listing')
            continue
        i = X.at[a]
        m, o = X.rows[i][1], X.rows[i][2]
        if invalid(m, o):
            reasons.add('invalid row reached')
            continue
        covered.add(a)
        fall = X.nxt(i)
        succ = []
        if m in ('rts', 'rte'):
            pass
        elif BR.match(m) or (m == 'jmp' and re.fullmatch(r'0x[0-9a-f]+:l', o)):
            t = TGT.search(o)
            if not t:
                reasons.add('branch operand not parsed')
            else:
                v = int(t.group(1), 16)
                if v in entries and v != e:
                    reasons.add('tail branch to another entry')
                    edges.append(v)
                else:
                    succ.append(v)
            if m not in ('bra', 'jmp'):
                succ.append(fall)
        elif m == 'jmp':
            tb = table(X, i)
            if tb is None:
                reasons.add('indirect jump unresolved')
            else:
                base, n = tb
                tables.append((base, base + 4 * n))
                for k in range(n):
                    v = X.word(base + 4 * k)
                    if v in entries and v != e:
                        reasons.add('tail branch to another entry')
                        edges.append(v)
                    else:
                        succ.append(v)
                if base + 4 * n not in X.at and base + 4 * n != X.hi:
                    reasons.add('table end off listing')
        else:                                   # calls, stop, trap and ordinary rows continue
            if m in ('bsr', 'jsr'):              # plan 424.2 (f): a call target inside the range
                t = re.fullmatch(r'0x([0-9a-f]+):[bl]', o)
                if t and e < int(t.group(1), 16) < end:
                    reasons.add('call target inside range')
            if m == 'nop' and fall == end and end in entries:
                allowance += 1                  # final nop before the next entry ends the fall-through
            else:
                succ.append(fall)
        for v in succ:
            if v == end and end in entries and v != e:
                if m == 'nop':
                    continue
                reasons.add('falls into the next entry')
                edges.append(v)
                continue
            todo.append(v)
    # (d) coverage
    unreached = 0
    i0 = X.at.get(e)
    if i0 is not None:
        i = i0
        while i < len(X.rows) and X.rows[i][0] < end:
            a = X.rows[i][0]
            n_ = X.nxt(i)
            if a not in covered and not any(b0 <= a < b1 for b0, b1 in tables):
                if X.rows[i][1] == 'nop' and n_ == end and n_ - a == 2:
                    allowance += 1
                else:
                    unreached += min(n_, end) - a
            i += 1
    if unreached:
        reasons.add('unreached bytes')
    return dict(reasons=reasons, edges=edges, allowance=allowance, unreached=unreached, tables=len(tables))


def candidate(X, e, end, entries):
    """class and reach of one candidate (plan 424, 424.2) without the incoming-edge test."""
    if e not in X.at or invalid(X.rows[X.at[e]][1], X.rows[X.at[e]][2]) or X.word(e, 2) == 0:
        r = dict(cls='data label', reasons={'data label'}, edges=[], allowance=0, unreached=0, tables=0)
    elif X.rows[X.at[e]][1] == 'nop' and X.nxt(X.at[e]) == end:
        r = dict(cls='padding (nop)', reasons={'padding'}, edges=[], allowance=0, unreached=0, tables=0)
    else:
        r = reach(X, e, end, entries)
        r['cls'] = 'function candidate'
    r['end'] = end
    return r


def analyse(X, entries):
    E = sorted(entries)
    out = {}
    for k, e in enumerate(E):
        out[e] = candidate(X, e, E[k + 1] if k + 1 < len(E) else X.hi, entries)
    # (e) incoming non-call edges
    for e, r in out.items():
        for v in r['edges']:
            k = bisect.bisect_right(E, v) - 1
            if k >= 0 and E[k] != e:
                out[E[k]]['reasons'].add('incoming edge from another candidate')
    for r in out.values():
        r['confirmed'] = r['cls'] == 'function candidate' and not r['reasons']
    return E, out


def main(out_tsv, out_json):
    X = Text()
    res = D418.main(extend=True)
    entries = set(res['entries'])
    tok, names = res['tok'], {}
    M = json.load(open('09_validation/reconstruction/m2-m68k-text-map-20261009.json'))
    for g in M['groups']:
        names[int(g['address'], 16)] = g['names']
    E, R = analyse(X, entries)
    assert len(E) == 3570

    # validation: plan 414 V10 OBJECT_MATCH functions
    G = json.load(open(GRID))
    true_f, verr = [], []
    for r in G['objects']:
        if r['variant'] != 'V10' or r['verdict'] != 'OBJECT_MATCH':
            continue
        d = json.load(open(os.path.join('08_build/artifacts/m0p414/l1', 'l1-V10-%s.json' % r['object'])))
        place = d['placements'].get('__TEXT,__text')
        if place is None:
            continue
        ob = macho_obj.parse(open(r['obj'], 'rb').read())
        ts = [s for s in ob['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
        st = sorted({place + y['value'] - ts['addr'] for y in ob['symbols'] if y['kind'] == 'SECT' and not y['stab']
                     and y['sect'] == ts['index'] and not y['name'].startswith(('gcc2_compiled', '___gnu_compiled'))})
        for k_, a in enumerate(st):
            b = st[k_ + 1] if k_ + 1 < len(st) else place + ts['size']
            got = R.get(a)
            ok = got is not None
            conf = ok and got['confirmed']
            if conf and got['end'] != b:
                verr.append(dict(object=r['object'], start='0x%x' % a, true_end='0x%x' % b, got_end='0x%x' % got['end']))
            true_f.append(dict(object=r['object'], start=a, end=b, is_entry=ok, confirmed=conf))
    # drop test: remove an entry whose candidate and predecessor are confirmed and adjacent
    drop_n = drop_bad = 0
    for k in range(1, len(E)):
        p, e = E[k - 1], E[k]
        if R[p]['confirmed'] and R[e]['confirmed'] and R[p]['end'] == e:
            drop_n += 1
            new_end = R[e]['end']
            r = candidate(X, p, new_end, entries - {e})
            if not r['reasons']:
                drop_bad += 1
    # split test: a fake entry after a barrier row inside a confirmed candidate
    split_n = split_bad = 0
    bad_examples = []
    for e in E:
        r = R[e]
        if not r['confirmed']:
            continue
        i = X.at[e]
        while X.rows[i][0] < r['end']:
            m = X.rows[i][1]
            f = X.nxt(i)
            if m in ('bra', 'rts', 'rte', 'jmp') and e < f < r['end'] and f in X.at:
                split_n += 1
                ent = entries | {f}
                r1 = candidate(X, e, f, ent)
                r2 = candidate(X, f, r['end'], ent)
                incoming = any(f <= v < r['end'] for v in r1['edges'])
                if not r2['reasons'] and not incoming and X.word(f, 2) != 0:
                    split_bad += 1
                    if len(bad_examples) < 5:
                        bad_examples.append(['0x%x' % e, '0x%x' % f])
            i += 1
            if i >= len(X.rows):
                break
    ok = not verr and drop_bad == 0 and split_bad == 0

    # objects (plan 423) and IDA
    orow = [r for r in csv.DictReader(open(OBJS).read().splitlines()[1:], delimiter='\t') if r['start_lo']]
    ost = [(int(r['start_hi'], 16), int(r['end_lo'], 16), r['id'], r['label']) for r in orow]
    ost.sort()

    def obj_of(a):
        j = bisect.bisect_right([x[0] for x in ost], a) - 1
        return ost[j][2] if j >= 0 and ost[j][0] <= a < ost[j][1] else ''
    ida = {int(f['start'], 16): int(f['end'], 16) for f in json.load(open(IDA))}
    conf = [e for e in E if R[e]['confirmed']]
    S = collections.OrderedDict()
    S['entries'] = len(E)
    S['classes'] = dict(collections.Counter(R[e]['cls'] for e in E))
    S['confirmed'] = len(conf)
    S['confirmed_bytes'] = sum(R[e]['end'] - e for e in conf)
    S['confirmed_pct_text'] = round(100.0 * S['confirmed_bytes'] / (X.hi - X.lo), 2)
    S['confirmed_with_nop_allowance'] = sum(1 for e in conf if R[e]['allowance'])
    S['confirmed_with_tables'] = sum(1 for e in conf if R[e]['tables'])
    S['undetermined_reasons'] = dict(collections.Counter(x for e in E if not R[e]['confirmed'] for x in R[e]['reasons']))
    S['undetermined_single_reason'] = dict(collections.Counter(next(iter(R[e]['reasons'])) for e in E
                                                               if not R[e]['confirmed'] and len(R[e]['reasons']) == 1))
    S['validation'] = dict(true_functions=len(true_f), are_entries=sum(t['is_entry'] for t in true_f),
                           confirmed=sum(t['confirmed'] for t in true_f), wrong_confirmed=verr,
                           drop_test=dict(trials=drop_n, still_confirmed=drop_bad),
                           split_test=dict(trials=split_n, wrong_confirmed=split_bad, examples=bad_examples), passed=ok)
    S['ida'] = dict(functions=len(ida), same_start_end=sum(1 for e in conf if ida.get(e) == R[e]['end']),
                    same_start_other_end=sum(1 for e in conf if e in ida and ida[e] != R[e]['end']),
                    confirmed_without_ida=sum(1 for e in conf if e not in ida),
                    ida_not_entry=sum(1 for a in ida if a not in entries and X.lo <= a < X.hi))
    S['note'] = '"confirmed" is the function range by this reachability rule, not a content match'
    print(json.dumps(S, indent=1))
    if not ok:
        sys.exit('validation failed; outputs not written')
    with open(out_tsv, 'w') as f:
        f.write('# plan 424: m68k function candidates with reachability-confirmed ranges (RECONSTRUCTION_PLAN :78); '
                'confirmed = range by rule, not content match (m2_m68k_functions.py)\n')
        w = csv.writer(f, delimiter='\t', lineterminator='\n')
        w.writerow(['entry', 'end', 'bytes', 'names', 'class', 'confirmed', 'reasons', 'object_id'])
        for e in E:
            r = R[e]
            w.writerow(['0x%x' % e, '0x%x' % r['end'], r['end'] - e, ','.join(names.get(e, [])), r['cls'],
                        int(r['confirmed']), '; '.join(sorted(r['reasons'])), obj_of(e)])
    json.dump(dict(plan=424, tool='10_tools/reconstruction/m2_m68k_functions.py', tool_sha256=sha(os.path.abspath(__file__)),
                   image=dict(path=IMG, sha256=IMG_SHA), listing=dict(path=LISTING, sha256=LISTING_SHA),
                   inputs={p: sha(p) for p in (OBJS, IDA, GRID)}, outputs={out_tsv: sha(out_tsv)},
                   summary=S, validation_functions=[dict(t, start='0x%x' % t['start'], end='0x%x' % t['end']) for t in true_f]),
              open(out_json, 'w'), indent=1)


if __name__ == '__main__':
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    main(*sys.argv[1:])
