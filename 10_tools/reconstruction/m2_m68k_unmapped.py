#!/usr/bin/env python3
"""m2_m68k_unmapped.py -- plan 420 (M2-6): candidate NeXTMach (mk-108.1) source files for the
m68k-only ("unmapped") __text runs of the plan 415 map.

  python3 10_tools/reconstruction/m2_m68k_unmapped.py UNMAPPED.tsv RECORD.json

Index (plan 420.1): files listed in conf/files and conf/files.NeXT that exist, plus next/locore.s
and next/scb.s (concatenated into locore.o by conf/Makefile.NeXT) and fpsp/*.sa (members of the
prebuilt fpsp/fpsp.o).  C definitions: a line starting at column 0 containing "name(" followed,
after indented lines only (K&R parameters), by a column-0 "{"; "static" on that line or on the
line before is recorded.  .s: column-0 labels and PROCENTRY(name) -> _name.  .sa: column-0
labels.  A name in several files resolves to the only non-static definition, else ambiguous.
Unmapped runs sandwiched between runs of one x86 object are only marked as absorption candidates.
Checks: candidate-file basename agreement on the mapped names by directory, source order against
address order per file, and fpsp member order against fpsp/Makefile TRANS.
Reference text is not copied; only paths and line numbers are recorded.
Read-only apart from the two output files.
"""
import sys, os, re, json, csv, hashlib, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import m2_m68k_text_map as T415

NM = '01_resources/upstream/nextmach/mk-108.1'
MAP = '09_validation/reconstruction/m2-m68k-text-map-20261009.json'
RUNS = '06_reconstruction/m68k-text-map.tsv'
OBJS = '06_reconstruction/m68k-text-objects.tsv'
EXTRA = ['next/locore.s', 'next/scb.s']          # conf/Makefile.NeXT LOCORE_DEPS
GATE = ('next', 'nextdev', 'nextif')
sha = T415.sha


def build_set():
    files = []
    for cf in ('conf/files', 'conf/files.NeXT'):
        for l in open(os.path.join(NM, cf), errors='replace'):
            w = l.split()
            if not w or w[0].startswith('#') or w[0].startswith('OPTIONS/'):
                continue
            p = os.path.normpath(w[0])
            if p.endswith(('.c', '.s')) and os.path.isfile(os.path.join(NM, p)):
                files.append(p)
    files += [p for p in EXTRA if p not in files]
    sa = sorted(p for p in os.listdir(os.path.join(NM, 'fpsp')) if p.endswith('.sa'))
    files += ['fpsp/' + p for p in sa]
    return files


def index(files):
    defs = collections.defaultdict(list)       # name -> [(path, line, static)]
    for p in files:
        L = open(os.path.join(NM, p), errors='replace').read().splitlines()
        if p.endswith('.c'):
            for i, l in enumerate(L):
                if not l or l[0] in ' \t#/*{}' or l.rstrip().endswith(';'):
                    continue
                m = re.search(r'([A-Za-z_]\w*)\s*\(', l)
                if not m or m.group(1) in ('if', 'while', 'for', 'switch', 'return', 'sizeof'):
                    continue
                j = i + 1
                while j < len(L) and (not L[j].strip() or L[j][0] in ' \t'):
                    j += 1
                if j < len(L) and L[j].startswith('{'):
                    st = 'static' in l.split(m.group(1))[0] or (i > 0 and L[i - 1].startswith('static'))
                    defs['_' + m.group(1)].append((p, i + 1, st))
        else:
            for i, l in enumerate(L):
                m = re.match(r'^([A-Za-z_][\w.]*):', l)
                if m:
                    defs[m.group(1)].append((p, i + 1, False))
                m = re.search(r'PROCENTRY\s*\(\s*(\w+)\s*\)', l)
                if m and p.endswith('.s'):
                    defs['_' + m.group(1)].append((p, i + 1, False))
    return defs


def resolve(defs, name):
    d = defs.get(name, [])
    files = {p for p, _, _ in d}
    if not d:
        return None, None
    if len(files) == 1:
        return d[0][0], d[0][1]
    ns = [x for x in d if not x[2]]
    if len({p for p, _, _ in ns}) == 1:
        return ns[0][0], ns[0][1]
    return 'ambiguous', None


def stem(p):
    return os.path.splitext(os.path.basename(p))[0]


def main(out_tsv, out_json):
    files = build_set()
    defs = index(files)
    M = json.load(open(MAP))
    rows = [r for r in csv.DictReader(open(RUNS).read().splitlines()[1:], delimiter='\t')]
    objsrc = {int(r['x86_n']): r['source'] for r in csv.DictReader(open(OBJS).read().splitlines()[1:], delimiter='\t')}   # plan 421.1: by n (x86-memcpy twice)
    groups = M['groups']
    # runs again from the groups (same rule as plan 415), with their names
    runs = []
    for g in groups:
        if runs and runs[-1]['owner'] == g['owner']:
            runs[-1]['groups'].append(g)
        else:
            runs.append(dict(owner=g['owner'], groups=[g]))
    assert len(runs) == len(rows)
    names_n = {o['n']: o['object'] for o in M['objects']}

    # (i) method check on mapped names
    strata = collections.defaultdict(lambda: [0, 0])
    disagree = []
    for g in groups:
        for nm in g['mapped']:
            f, ln = resolve(defs, nm)
            if f in (None, 'ambiguous'):
                continue
            ok = stem(f) == stem(objsrc[g['owner']])
            top = f.split('/')[0]
            strata[top][0] += ok
            strata[top][1] += 1
            if not ok:
                disagree.append([nm, f, objsrc[g['owner']]])
    gate = [sum(strata[t][0] for t in GATE), sum(strata[t][1] for t in GATE)]
    gate_rate = round(100.0 * gate[0] / gate[1], 2) if gate[1] else None
    weak = gate_rate is None or gate_rate < 90.0

    # unmapped runs
    out, per_name, absorbed = [], [], []
    for k, r in enumerate(runs):
        if r['owner'] is not None:
            continue
        sand = 0 < k < len(runs) - 1 and runs[k - 1]['owner'] is not None and runs[k - 1]['owner'] == runs[k + 1]['owner']
        subs = []
        for g in r['groups']:
            cand = set()
            for nm in g['names']:
                f, ln = resolve(defs, nm)
                per_name.append(dict(name=nm, address=g['address'], run=k, file=f, line=ln))
                cand.add(f if f is not None else 'none')
            c = cand.pop() if len(cand) == 1 else 'ambiguous'
            if subs and subs[-1]['file'] == c:
                subs[-1]['groups'].append(g)
            else:
                subs.append(dict(file=c, groups=[g]))
        nxt = int(rows[k + 1]['start'], 16) if k + 1 < len(rows) else int(rows[k]['end_upper'], 16)
        for i, s in enumerate(subs):
            a0 = int(s['groups'][0]['address'], 16)
            a1 = int(subs[i + 1]['groups'][0]['address'], 16) if i + 1 < len(subs) else nxt
            gap = (s['file'] == 'none' and 0 < i < len(subs) - 1 and subs[i - 1]['file'] == subs[i + 1]['file']
                   and subs[i - 1]['file'] not in ('none', 'ambiguous'))
            out.append(dict(run=k, sub=i, start=a0, end_upper=a1, file=s['file'], symbols=sum(len(g['names']) for g in s['groups']),
                            first=s['groups'][0]['names'][0], last=s['groups'][-1]['names'][-1],
                            note='absorption candidate (between runs of %s)' % names_n[runs[k - 1]['owner']] if sand
                            else ('gap inside file' if gap else '')))
        if sand:
            absorbed.append(dict(run=k, between=names_n[runs[k - 1]['owner']], bytes=int(rows[k]['bytes_upper'])))
    fc = collections.Counter(s['file'] for s in out if not s['note'].startswith('absorption'))
    split_files = sorted(f for f, c in fc.items() if c > 1 and f not in ('none', 'ambiguous'))

    # (ii) source order against address order per candidate file
    byfile = collections.defaultdict(list)
    for x in per_name:
        if x['file'] not in (None, 'ambiguous'):
            byfile[x['file']].append((int(x['address'], 16), x['line']))
    order = dict(files=0, monotone=0, names=0, outside=0)
    for f, L in byfile.items():
        if len(L) < 2:
            continue
        L.sort()
        k = len(T415.lis([ln for _, ln in L]))
        order['files'] += 1
        order['monotone'] += k == len(L)
        order['names'] += len(L)
        order['outside'] += len(L) - k
    # (iii) fpsp member order against TRANS
    trans = None
    for l in open(os.path.join(NM, 'fpsp/Makefile')):
        if l.startswith('TRANS'):
            trans = [w[:-2] for w in l.split('=', 1)[1].split()]
    fsubs = [stem(s['file']) for s in out if s['file'].startswith('fpsp/')]
    seq = []
    for f in fsubs:
        if not seq or seq[-1] != f:
            seq.append(f)
    fp = dict(subruns=len(fsubs), member_runs=len(seq), distinct=len(set(seq)),
              lis_in_trans_order=len(T415.lis([trans.index(f) for f in seq])), trans=len(trans))

    S = collections.OrderedDict()
    S['index'] = dict(files=len(files), c=sum(1 for p in files if p.endswith('.c')), s=sum(1 for p in files if p.endswith('.s')),
                      sa=sum(1 for p in files if p.endswith('.sa')), names=len(defs))
    un = [x for x in per_name]
    S['unmapped_names'] = len(un)
    S['unmapped_resolved'] = dict(collections.Counter('none' if x['file'] is None else 'ambiguous' if x['file'] == 'ambiguous'
                                                      else x['file'].split('/')[0] for x in un))
    S['unmapped_runs'] = sum(1 for r in runs if r['owner'] is None)
    S['absorption_candidates'] = dict(runs=len(absorbed), bytes=sum(a['bytes'] for a in absorbed))
    S['subruns'] = len(out)
    S['subruns_by_kind'] = dict(collections.Counter('absorption' if s['note'].startswith('absorption') else
                                                    ('gap inside file' if s['note'] else
                                                     ('file' if s['file'] not in ('none', 'ambiguous') else s['file']))
                                                    for s in out))
    S['candidate_files'] = len({s['file'] for s in out if s['file'] not in ('none', 'ambiguous')})
    S['files_in_several_subruns'] = split_files
    S['method_check'] = dict(strata={k: dict(agree=v[0], total=v[1], pct=round(100.0 * v[0] / v[1], 2)) for k, v in sorted(strata.items())},
                             overall=[sum(v[0] for v in strata.values()), sum(v[1] for v in strata.values())],
                             gate_strata=list(GATE), gate=gate, gate_pct=gate_rate, weak_candidates=weak)
    S['source_order'] = order
    S['fpsp_trans_order'] = fp

    with open(out_tsv, 'w') as f:
        f.write('# plan 420: m68k-only __text runs split by candidate NeXTMach mk-108.1 file (same-name definitions in the build set); '
                'end is an upper bound; candidates %s (m2_m68k_unmapped.py)\n' % ('WEAK' if weak else 'per method check'))
        w = csv.writer(f, delimiter='\t', lineterminator='\n')
        w.writerow(['run', 'sub', 'start', 'end_upper', 'bytes_upper', 'candidate_file', 'symbols', 'first_symbol', 'last_symbol', 'note'])
        for s in out:
            w.writerow([s['run'], s['sub'], '0x%x' % s['start'], '0x%x' % s['end_upper'], s['end_upper'] - s['start'],
                        s['file'], s['symbols'], s['first'], s['last'], s['note']])
    json.dump(dict(plan=420, tool='10_tools/reconstruction/m2_m68k_unmapped.py', tool_sha256=sha(os.path.abspath(__file__)),
                   reference=dict(tree=NM, files_sha256=sha(os.path.join(NM, 'conf/files')),
                                  files_next_sha256=sha(os.path.join(NM, 'conf/files.NeXT'))),
                   map=dict(path=MAP, sha256=sha(MAP)), runs=dict(path=RUNS, sha256=sha(RUNS)), outputs={out_tsv: sha(out_tsv)},
                   note='Same-name definitions in the 1990 NeXTMach build set are file candidates, not the 1997 m68k sources or '
                        'object boundaries. Only paths and line numbers of the reference are recorded.',
                   summary=S, absorbed=absorbed, disagreements_mapped=disagree,
                   names=[dict(x, address=x['address']) for x in per_name]), open(out_json, 'w'), indent=1)
    print(json.dumps(S, indent=1))


if __name__ == '__main__':
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    main(*sys.argv[1:])
