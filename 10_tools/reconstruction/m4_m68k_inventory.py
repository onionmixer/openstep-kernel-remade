#!/usr/bin/env python3
"""m4_m68k_inventory.py -- plan 495 (M4-1): inventory of the m68k machine-dependent part (M4).

  python3 10_tools/reconstruction/m4_m68k_inventory.py OUT.tsv RECORD.json

M4 = the rows of 06_reconstruction/m68k-objects.tsv (plan 423) outside the M5 set of plan 429
(m68k-text-objects.tsv class contiguous, source .c, not under /i386/).  Per row: bounds, entries of
m68k-functions.tsv (plan 424) by object_id (function candidates, data labels, confirmed), the
candidate NeXTMach mk-108.1 file from the plan 420 index (m2_m68k_unmapped build_set/index/resolve;
names as written; a weak candidate, plan 420): the file that most named entries resolve to ('tie'
when several share the top count), coverage = named entries resolved to it / named entries, the
build unit and a group (plan 495.1, first match):
  H data-only/data-unlinked; A candidate .s/.sa; B candidate next/*.c; C candidate nextdev/ or
  nextif/ .c; D other candidate .c; I file kind without candidate; E x86 kind without candidate;
  F bracket without candidate; G unassigned without candidate.
The record holds input hashes (tables, resolver, this tool, NeXTMach build-set files), group sums,
the plan 495.1 checks, and the entries without object_id with the rows whose [start_lo, end_hi)
holds them.  Reference text is not copied; only paths and line numbers.
Read-only apart from the two output files; any failed check stops before writing.
"""
import sys, os, csv, json, hashlib, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import m2_m68k_unmapped as U

OBJS = '06_reconstruction/m68k-objects.tsv'
TOBJ = '06_reconstruction/m68k-text-objects.tsv'
FUNCS = '06_reconstruction/m68k-functions.tsv'
GROUPS = 'HABCDIEFG'
COLS = ['id', 'kind', 'label', 'basis', 'start_lo', 'start_hi', 'end_lo', 'end_hi', 'exact', 'bytes_min', 'bytes_max',
        'entries', 'functions', 'data_labels', 'confirmed', 'named', 'resolved', 'missing', 'ambiguous', 'candidate',
        'candidate_line', 'candidate_rows', 'coverage', 'lang', 'group', 'build_unit', 'x86_source', 'weak']


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def rd(p):
    return list(csv.DictReader([l for l in open(p).read().split('\n') if l and not l.startswith('#')], delimiter='\t'))


def hx(s):
    return int(s, 16) if s else None


def main(out_tsv, out_json):
    O, T, F = rd(OBJS), rd(TOBJ), rd(FUNCS)
    ids = [o['id'] for o in O]
    assert len(ids) == len(set(ids)), 'duplicate object ids'
    cont = collections.defaultdict(list)
    for t in T:
        if t['class'] == 'contiguous':
            cont[t['x86_object']].append(t)
    m5n = {k for k, v in cont.items() if v[0]['source'].endswith('.c') and '/i386/' not in v[0]['source']}
    m5 = [o for o in O if o['kind'] == 'x86' and o['label'] in m5n]
    m4 = [o for o in O if not (o['kind'] == 'x86' and o['label'] in m5n)]
    xsrc = {}
    for o in O:
        if o['kind'] == 'x86':
            assert len(cont[o['label']]) == 1, ('x86 join', o['id'], o['label'], len(cont[o['label']]))
            xsrc[o['id']] = cont[o['label']][0]['source']
    known = set(ids)
    fo = collections.defaultdict(list)
    for f in F:
        assert f['object_id'] == '' or f['object_id'] in known, ('dangling object_id', f['entry'], f['object_id'])
        fo[f['object_id']].append(f)

    files = U.build_set()
    defs = U.index(files)
    rows = []
    for o in m4:
        es = fo.get(o['id'], [])
        st = collections.Counter()
        per = []
        for f in es:
            ns = [n for n in f['names'].split(',') if n]
            if not ns:
                st['unnamed'] += 1
                continue
            got, amb = {}, False
            for n in ns:
                p, ln = U.resolve(defs, n)
                if p == 'ambiguous':
                    amb = True
                elif p:
                    got.setdefault(p, ln)
            per.append(got)
            st['resolved' if got else ('ambiguous' if amb else 'missing')] += 1
        cnt = collections.Counter(p for g in per for p in g)
        cand, cline, num = '', '', 0
        if cnt:
            top = cnt.most_common()
            if len(top) > 1 and top[1][1] == top[0][1]:
                cand = 'tie'
            else:
                cand, num = top[0][0], top[0][1]
                cline = min(g[cand] for g in per if cand in g)
        named = len(per)
        assert num <= named
        ok = cand not in ('', 'tie')
        lang = os.path.splitext(cand)[1][1:] if ok else 'unknown'
        if o['kind'] in ('data-only', 'data-unlinked'):
            g = 'H'
        elif ok and lang in ('s', 'sa'):
            g = 'A'
        elif ok and cand.startswith('next/'):
            g = 'B'
        elif ok and cand.startswith(('nextdev/', 'nextif/')):
            g = 'C'
        elif ok:
            g = 'D'
        else:
            g = dict(file='I', x86='E', bracket='F', unassigned='G')[o['kind']]
        bu = ''
        if ok:
            bu = 'fpsp/fpsp.o' if cand.startswith('fpsp/') else ('locore.o' if cand in U.EXTRA else cand)
        b = [hx(o[k]) for k in ('start_lo', 'start_hi', 'end_lo', 'end_hi')]
        if g != 'H':
            assert None not in b and b[0] <= b[1] and b[2] <= b[3], ('bounds', o['id'])
            assert int(o['bytes_min']) <= int(o['bytes_max']), ('bytes', o['id'])
        rows.append(dict(id=o['id'], kind=o['kind'], label=o['label'], basis=o['basis'],
                         start_lo=o['start_lo'], start_hi=o['start_hi'], end_lo=o['end_lo'], end_hi=o['end_hi'],
                         exact=int(g != 'H' and b[0] == b[1] and b[2] == b[3]), bytes_min=o['bytes_min'], bytes_max=o['bytes_max'],
                         entries=len(es), functions=sum(f['class'] == 'function candidate' for f in es),
                         data_labels=sum(f['class'] == 'data label' for f in es), confirmed=sum(f['confirmed'] == '1' for f in es),
                         named=named, resolved=st['resolved'], missing=st['missing'], ambiguous=st['ambiguous'],
                         candidate=cand, candidate_line=cline, candidate_rows='', coverage='%d/%d' % (num, named),
                         lang=lang, group=g, build_unit=bu, x86_source=xsrc.get(o['id'], ''), weak=int(ok)))
    crow = collections.Counter(r['candidate'] for r in rows if r['candidate'] not in ('', 'tie'))
    for r in rows:
        r['candidate_rows'] = crow[r['candidate']] if r['candidate'] in crow else ''

    # checks (plan 495.1)
    chk = collections.OrderedDict()
    m4ids, m5ids = {o['id'] for o in m4}, {o['id'] for o in m5}
    chk['1_rows_188_set_equal'] = len(rows) == 188 and {r['id'] for r in rows} == m4ids and not (m4ids & m5ids) and len(m5) == 208
    chk['2_groups_defined_sum'] = all(r['group'] in GROUPS for r in rows) and sum(collections.Counter(r['group'] for r in rows).values()) == 188
    mism = [[r['id'], r['label'], r['candidate']] for r in rows if r['kind'] == 'file' and r['weak'] and r['candidate'] != r['label']]
    chk['3_file_candidate_equals_label'] = not mism
    ent = lambda ids_: [f for i in ids_ for f in fo.get(i, [])]
    e4, e5, e0 = ent(m4ids), ent(m5ids), fo.get('', [])
    by = lambda es: sum(int(f['bytes']) for f in es)
    fc = [f for f in e4 if f['class'] == 'function candidate']
    dl = [f for f in e4 if f['class'] == 'data label']
    chk['4_function_table'] = (len(e4) + len(e5) + len(e0) == len(F) == 3570 and by(e4) + by(e5) + by(e0) == by(F) == 678510
                               and (len(e4), by(e4), len(fc), by(fc), len(dl), by(dl)) == (1053, 215874, 1030, 213022, 23, 2852))
    chk['5_bounds_and_coverage'] = True     # asserted per row above
    bad = [k for k, v in chk.items() if not v]
    if bad:
        print('CHECK FAILED', bad, mism)
        sys.exit(1)

    # entries without object_id: rows whose [start_lo, end_hi) holds them
    span = [(hx(o['start_lo']), hx(o['end_hi']), o['id'], 'M4' if o['id'] in m4ids else 'M5') for o in O if o['start_lo']]
    noobj = []
    for f in e0:
        a = hx(f['entry'])
        noobj.append(dict(entry=f['entry'], bytes=int(f['bytes']), names=f['names'], cls=f['class'],
                          rows=[[i, s] for lo, hi, i, s in span if lo <= a < hi]))
    nsum = collections.Counter('none' if not x['rows'] else ('+'.join(sorted({s for _, s in x['rows']}))) for x in noobj)

    gs = collections.OrderedDict()
    for g in GROUPS:
        rs = [r for r in rows if r['group'] == g]
        gs[g] = dict(rows=len(rs), bytes_min=sum(int(r['bytes_min'] or 0) for r in rs), bytes_max=sum(int(r['bytes_max'] or 0) for r in rs),
                     exact=sum(r['exact'] for r in rs), entries=sum(r['entries'] for r in rs), functions=sum(r['functions'] for r in rs),
                     full_coverage=sum(1 for r in rs if r['named'] and r['coverage'] == '%d/%d' % (r['named'], r['named'])))
    nm_files = sorted(set(files))
    rec = collections.OrderedDict(
        plan=495, tool='10_tools/reconstruction/m4_m68k_inventory.py', tool_sha256=sha(os.path.abspath(__file__)),
        inputs={p: sha(p) for p in (OBJS, TOBJ, FUNCS, '10_tools/reconstruction/m2_m68k_unmapped.py')},
        nextmach_root=U.NM, nextmach_files=len(nm_files),
        nextmach_files_sha256=hashlib.sha256(''.join('%s %s\n' % (p, sha(os.path.join(U.NM, p))) for p in nm_files).encode()).hexdigest(),
        checks=chk, groups=gs, kinds=dict(collections.Counter(r['kind'] for r in rows)),
        entries_m4=dict(entries=len(e4), bytes=by(e4), functions=len(fc), function_bytes=by(fc), data_labels=len(dl), data_bytes=by(dl),
                        confirmed=sum(f['confirmed'] == '1' for f in e4)),
        entries_m5=dict(entries=len(e5), bytes=by(e5)),
        entries_without_object=dict(entries=len(e0), bytes=by(e0), by_holder=dict(nsum), list=noobj),
        output=out_tsv)
    with open(out_tsv, 'w') as w:
        w.write('# plan 495: m68k M4 inventory (m4_m68k_inventory.py); candidate = weak NeXTMach mk-108.1 file (plan 420 index), coverage = named entries resolved to it / named entries\n')
        w.write('\t'.join(COLS) + '\n')
        for r in rows:
            w.write('\t'.join(str(r[c]) for c in COLS) + '\n')
    rec['output_sha256'] = sha(out_tsv)
    json.dump(rec, open(out_json, 'w'), indent=1)
    print(json.dumps(dict(checks=chk, groups=gs, without_object=dict(nsum)), indent=1))
    print('output', rec['output_sha256'])


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
