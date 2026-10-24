#!/usr/bin/env python3
"""m4_m68k_headers.py -- plan 498 (M4-4): direct-include gap table of the remaining first-target m68k C
units (diagnostic; nothing is compiled).

  python3 10_tools/reconstruction/m4_m68k_headers.py OUT.tsv RECORD.json

Units: the plan 495 build units whose rows all have exact bounds and full coverage, without the
plan 497 files, next/in_cksum.c and assembly (15 C units).  Per direct #import/#include of the
NeXTMach mk-108.1 source (nested includes are not followed): the enclosing conditional lines
(#if/#ifdef/#ifndef with #elif/#else appended; values not evaluated), activity
unconditional/conditional, and the first matching class (plan 498.1):
  resolves          found in the stage m0p497-a1-stage: quote includes first in src/machdep/m68k/
                    (D103), then the -I directories of the M5 m68k line in order
  config-candidate  cputypes.h, confdep.h, or the name before .h equals the first requirement word
                    after "optional" (not device-driver/profiling-routine) of a conf/files or
                    conf/files.NeXT line (NeXTMach config f_needs)
  stage-other-path  a file of the same name, not on an i386 path, elsewhere in the stage
  nextmach-only     a file of the same name only in the NeXTMach tree
  none
The record also holds, per unit, the x86 objects whose 07 source has the same file name (any class
of m68k-text-objects.tsv, with M5 membership), the neighbouring objects and the unit's function names
defined in those 07 sources (plan 499.1: return type may share the line): ownership candidates only.  No reference text is copied.
Read-only apart from the two output files.
"""
import sys, os, re, json, hashlib, collections

NM = '01_resources/upstream/nextmach/mk-108.1'
INV = '06_reconstruction/m68k-m4-inventory.tsv'
OBJS = '06_reconstruction/m68k-objects.tsv'
TOBJ = '06_reconstruction/m68k-text-objects.tsv'
FUNCS = '06_reconstruction/m68k-functions.tsv'
STAGE = '08_build/runs/tools/m0p497-a1-stage'
M5LINE = '08_build/artifacts/m5p494/final.cmd'
DONE = {'next/checksum_16.c', 'next/dkbad.c', 'next/ufs_machdep.c'}
COLS = ['unit', 'm4_ids', 'line', 'form', 'include', 'activity', 'conditions', 'class', 'stage_path', 'evidence', 'candidates']


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def tsv(p):
    L = [l.split('\t') for l in open(p).read().split('\n') if l and not l.startswith('#')]
    return [dict(zip(L[0], r)) for r in L[1:]]


def units():
    R = tsv(INV)
    U = collections.defaultdict(list)
    for r in R:
        if r['build_unit']:
            U[r['build_unit']].append(r)
    good = [u for u, rs in U.items() if all(r['exact'] == '1' and r['named'] != '0' and r['coverage'] == '%s/%s' % (r['named'], r['named']) for r in rs)]
    out = sorted((u for u in good if u.endswith('.c') and u not in DONE and u != 'next/in_cksum.c'),
                 key=lambda u: (sum(int(r['bytes_min']) for r in U[u]), u))
    return out, U, len(good)


def config_words():
    w = {}
    for cf in ('conf/files', 'conf/files.NeXT'):
        for i, l in enumerate(open(os.path.join(NM, cf), errors='replace').read().splitlines(), 1):
            t = l.split()
            if len(t) < 3 or t[0].startswith('#') or t[1] != 'optional':
                continue
            for x in t[2:]:
                if x in ('device-driver', 'profiling-routine'):
                    break
                w.setdefault(x, '%s:%d' % (cf, i))
                break
    return w


def includes(path):
    out, stack = [], []
    for i, l in enumerate(open(path, errors='replace').read().splitlines(), 1):
        m = re.match(r'^\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b(.*)$', l)
        if m:
            k = m.group(1)
            if k in ('if', 'ifdef', 'ifndef'):
                stack.append(l.strip())
            elif k in ('elif', 'else') and stack:
                stack[-1] = stack[-1] + ' / ' + l.strip()
            elif k == 'endif' and stack:
                stack.pop()
            continue
        m = re.match(r'^\s*#\s*(?:import|include)\s*([<"])([^>"]+)[>"]', l)
        if m:
            out.append(dict(line=i, form=m.group(1), include=m.group(2), conditions=list(stack)))
    return out


def defined_in(name, text):
    """plan 499.1: a definition of name at file level -- a line not starting with #, blank or comment
    whose text before name has no ;{}(), and whose balanced parameter list is not followed by ; or ,
    (a prototype); the return type may stand on the same line."""
    n = name.lstrip('_')
    for m in re.finditer(r'^(?![#\s/*])[^;{}()\n]*?\b%s\s*\(' % re.escape(n), text, re.M):
        i, d = m.end(), 1
        while i < len(text) and d:
            d += {'(': 1, ')': -1}.get(text[i], 0)
            i += 1
        if text[i:].lstrip()[:1] not in (';', ','):
            return True
    return False


def main(out_tsv, out_json):
    us, U, ngood = units()
    man = json.load(open(STAGE + '.manifest.json'))
    have = {e[0]: e[1] for e in man['files']}
    byname = collections.defaultdict(list)
    for p in have:
        byname[os.path.basename(p)].append(p)
    nmname = collections.defaultdict(list)
    for d, _, fs in os.walk(NM):
        for f in fs:
            nmname[f].append(os.path.relpath(os.path.join(d, f), NM))
    m5 = [l.split() for l in open(M5LINE) if l.startswith('RUN ')]
    assert len(m5) == 1
    idirs = [a[2:] for a in m5[0] if a.startswith('-I')]
    assert all(d.startswith('src/') for d in idirs), idirs
    cw = config_words()
    rows, counts = [], {}
    for u in us:
        ids = ','.join(r['id'] for r in U[u])
        src = os.path.join(NM, u)
        txt = open(src, errors='replace').read()
        n_re = len(re.findall(r'^\s*#\s*(?:import|include)\s*[<"]', txt, re.M))
        inc = includes(src)
        counts[u] = (len(inc), n_re)
        for x in inc:
            h = x['include']
            dirs = (['src/machdep/m68k'] if x['form'] == '"' else []) + idirs
            hit = next((d[len('src/'):] + '/' + h for d in dirs if (d[len('src/'):] + '/' + h) in have), '')
            b, base = os.path.basename(h), os.path.splitext(os.path.basename(h))[0]
            other = sorted(p for p in byname.get(b, []) if 'i386' not in p and p != hit)
            nmc = sorted(nmname.get(b, []))
            if hit:
                cls, ev = 'resolves', have[hit]
            elif b in ('cputypes.h', 'confdep.h') or base in cw:
                cls, ev = 'config-candidate', cw.get(base, 'src/config/mkmakefile.c (generated separately)')
            elif other:
                cls, ev = 'stage-other-path', '; '.join('%s <- %s' % (p, have[p]) for p in other)
            elif nmc:
                cls, ev = 'nextmach-only', ''
            else:
                cls, ev = 'none', ''
            rows.append(dict(unit=u, m4_ids=ids, line=x['line'], form='quote' if x['form'] == '"' else 'angle', include=h,
                             activity='conditional' if x['conditions'] else 'unconditional', conditions=' | '.join(x['conditions']),
                             cls=cls, stage_path=hit, evidence=ev, candidates='; '.join(nmc)))

    # relationships (ownership candidates)
    T = tsv(TOBJ)
    m5set = {t['x86_object'] for t in T if t['class'] == 'contiguous' and t['source'].endswith('.c') and '/i386/' not in t['source']}
    O = [o for o in tsv(OBJS) if o['start_lo']]
    O.sort(key=lambda o: int(o['start_lo'], 16))
    pos = {o['id']: k for k, o in enumerate(O)}
    F = tsv(FUNCS)
    rel = []
    for u in us:
        ids = [r['id'] for r in U[u]]
        b = os.path.basename(u)
        same = [dict(x86_object=t['x86_object'], source=t['source'], cls=t['class'], m5=t['x86_object'] in m5set)
                for t in T if os.path.basename(t['source']) == b]
        ks = sorted(pos[i] for i in ids)
        nb = [dict(side=s, id=O[k]['id'], kind=O[k]['kind'], label=O[k]['label']) for s, k in (('before', ks[0] - 1), ('after', ks[-1] + 1)) if 0 <= k < len(O)]
        names = sorted({n for f in F if f['object_id'] in ids for n in f['names'].split(',') if n})
        defined = []
        for s in sorted({x['source'] for x in same}):
            if os.path.isfile(s):
                t = open(s, errors='replace').read()
                defined += ['%s in %s' % (n, s) for n in names if defined_in(n, t)]
        rel.append(dict(unit=u, m4_ids=ids, same_name_x86=same, neighbours=nb, names=names, names_in_07_same_name=defined))

    chk = collections.OrderedDict()
    chk['1_units_15_and_include_counts'] = len(us) == 15 and ngood == 21 and all(a == b for a, b in counts.values())
    chk['2_class_defined'] = all(r['cls'] in ('resolves', 'config-candidate', 'stage-other-path', 'nextmach-only', 'none') for r in rows)
    chk['3_resolves_in_manifest'] = all(r['stage_path'] in have for r in rows if r['cls'] == 'resolves')
    bad = [k for k, v in chk.items() if not v]
    if bad:
        print('CHECK FAILED', bad, counts)
        sys.exit(1)
    agg = collections.OrderedDict()
    for c in ('resolves', 'config-candidate', 'stage-other-path', 'nextmach-only', 'none'):
        rs = [r for r in rows if r['cls'] == c]
        agg[c] = dict(rows=len(rs), distinct=len({r['include'] for r in rs}),
                      unconditional=len({r['include'] for r in rs if r['activity'] == 'unconditional'}))
    per = {u: dict(includes=counts[u][0], not_resolved=sum(1 for r in rows if r['unit'] == u and r['cls'] != 'resolves'),
                   not_resolved_unconditional=sum(1 for r in rows if r['unit'] == u and r['cls'] != 'resolves' and r['activity'] == 'unconditional'))
           for u in us}
    with open(out_tsv, 'w') as w:
        w.write('# plan 498: direct includes of the remaining first-target m68k C units (m4_m68k_headers.py); classes resolves/config-candidate/stage-other-path/nextmach-only/none; conditions not evaluated\n')
        w.write('\t'.join(COLS) + '\n')
        for r in rows:
            w.write('\t'.join(str(r['cls'] if c == 'class' else r[c]).replace('\t', ' ') for c in COLS) + '\n')   # plan 503: no tab inside a field
    rec = collections.OrderedDict(plan=498, tool='10_tools/reconstruction/m4_m68k_headers.py', tool_sha256=sha(os.path.abspath(__file__)),
                                  inputs={p: sha(p) for p in (INV, OBJS, TOBJ, FUNCS, STAGE + '.manifest.json', M5LINE,
                                                              os.path.join(NM, 'conf/files'), os.path.join(NM, 'conf/files.NeXT'))},
                                  nextmach_sources={u: sha(os.path.join(NM, u)) for u in us},
                                  checks=chk, classes=agg, units=per, relationships=rel, output=out_tsv, output_sha256=sha(out_tsv))
    json.dump(rec, open(out_json, 'w'), indent=1)
    print(json.dumps(dict(checks=chk, classes=agg, units=per), indent=1))
    for r in rel:
        print(r['unit'], [(x['x86_object'], x['cls'], x['m5']) for x in r['same_name_x86']], [(n['side'], n['id'], n['kind'], n['label']) for n in r['neighbours']], r['names_in_07_same_name'])
    print('output', rec['output_sha256'])


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
