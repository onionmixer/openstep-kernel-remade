#!/usr/bin/env python3
"""m3_m68k_config_review.py -- plan 438 (M3-14): every x86 configuration option checked for
the m68k build.

  python3 10_tools/reconstruction/m3_m68k_config_review.py STAGE_DIR CC.cmd RECORD_IN.json RECORD_OUT.json

For each row of 06_reconstruction/config_options.tsv:
- the m68k override (06_reconstruction/config_options-m68k.tsv) if any, and whether the stage
  has generated/<header> (undetermined rows are not emitted);
- the '_' symbols named in the evidence column (a '/' before them is allowed) and their
  presence in the x86 and m68k original symbol tables;
- the macro's uses in STAGE_DIR (comments stripped; machdep/{i386,ppc,hppa,sparc} and */i386/
  directories excluded): '#if'/'#elif' value tests, '#ifdef'/'#ifndef'/'defined()' tests,
  '#define'/'#undef' of the macro, other lines;
- the objects among the compiled ones (CC.cmd -c sources) whose own source file has a value
  test, with their verdict in RECORD_IN.
Limits (recorded): textual scan, not the preprocessor closure; tests reached through other
macros (MACH_SLOCKS, PRI_SHIFT, ...) and header users are not attributed to objects.
Read-only apart from RECORD_OUT.
"""
import sys, os, re, csv, json, hashlib, collections

SKIP = re.compile(r'(^|/)machdep/(i386|ppc|hppa|sparc)(/|$)|(^|/)i386(/|$)')
SYM = re.compile(r'(?<![\w.])(_[A-Za-z][A-Za-z0-9_]{2,})')


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def names(p):
    return {r['name'] for r in csv.DictReader(open(p), delimiter='\t')}


def strip_comments(t):
    t = re.sub(r'/\*.*?\*/', lambda m: '\n' * m.group(0).count('\n'), t, flags=re.S)
    return re.sub(r'//[^\n]*', '', t)


def main(stage, ccmd, rec_in, out):
    X = names('03_original/x86/inventory/symbols.tsv')
    M = names('03_original/m68k/inventory/symbols.tsv')
    rows = list(csv.DictReader(open('06_reconstruction/config_options.tsv'), delimiter='\t'))
    over = {r['option']: r for r in csv.DictReader(open('06_reconstruction/config_options-m68k.tsv'), delimiter='\t')}
    texts = {}
    for r, ds, fs in os.walk(stage):
        ds.sort()
        for f in sorted(fs):
            p = os.path.join(r, f)
            rel = os.path.relpath(p, stage)
            if SKIP.search(rel) or not f.endswith(('.c', '.h', '.m', '.s', '.defs')):
                continue
            texts[rel] = strip_comments(open(p, errors='replace').read()).splitlines()
    srcs = {}
    for l in open(ccmd):
        if l.startswith('RUN ') and ' -c ' in l:
            w = l.split()
            srcs[w[w.index('-c') + 1][len('src/'):]] = os.path.basename(w[-1])
    verd = {}
    T = {}
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import m3_m68k_wide as W
    for t in W.targets():
        T[t['base']] = t['object']
    for o in json.load(open(rec_in))['objects']:
        verd[o['object']] = o['verdict']
    obj_of = {}
    for s, outname in srcs.items():
        base = re.sub(r'^O\d+__', '', outname)[:-2]
        obj_of[s] = T[base]
    out_rows = []
    for r in rows:
        mac = r['macro']
        syms = sorted(set(SYM.findall(r['evidence'])))
        pres = [dict(symbol=s, x86=s in X, m68k=s in M) for s in syms]
        uses = collections.defaultdict(list)
        if mac != '-':
            word = re.compile(r'\b%s\b' % re.escape(mac))
            for rel, L in texts.items():
                for i, l in enumerate(L):
                    if not word.search(l):
                        continue
                    s = l.strip()
                    if re.match(r'#\s*(define|undef)\b', s):
                        k = 'define'
                    elif re.match(r'#\s*(ifdef|ifndef)\b', s) or re.search(r'defined\s*\(?\s*%s' % re.escape(mac), s):
                        k = 'defined_test'
                    elif re.match(r'#\s*(if|elif)\b', s):
                        k = 'value_test'
                    else:
                        k = 'other'
                    uses[k].append('%s:%d' % (rel, i + 1))
        test_files = sorted({u.rsplit(':', 1)[0] for u in uses.get('value_test', [])})
        objs = sorted({obj_of[f] for f in test_files if f in obj_of})
        o = over.get(r['option'])
        emitted = os.path.exists(os.path.join(stage, 'generated', r['header'])) if r['header'] != '-' else None
        differ = [p['symbol'] for p in pres if p['x86'] != p['m68k']]
        if o:
            judge = 'override'
        elif r['status'] == 'undetermined':
            judge = 'not emitted (undetermined)'
        elif differ:
            judge = 'm68k evidence differs: deferred (no override)'
        elif pres:
            judge = 'same evidence'
        else:
            judge = 'no symbol evidence'
        out_rows.append(dict(option=r['option'], macro=mac, header=r['header'], x86_value=r['value'], x86_status=r['status'],
                             m68k_value=o['value'] if o else r['value'], m68k_status=o['status'] if o else None,
                             emitted=emitted, evidence_symbols=pres, evidence_differs=differ,
                             uses={k: v for k, v in uses.items()}, value_test_files=test_files,
                             compiled_objects_with_value_test=[[x, verd.get(x)] for x in objs], judgement=judge))
    S = collections.OrderedDict()
    S['options'] = len(out_rows)
    S['judgement'] = dict(collections.Counter(x['judgement'] for x in out_rows))
    S['deferred'] = {x['option']: dict(differs=x['evidence_differs'], value_tests=x['value_test_files'][:8],
                                       objects=x['compiled_objects_with_value_test'])
                     for x in out_rows if x['judgement'].startswith('m68k evidence differs')}
    json.dump(dict(plan=438, tool='10_tools/reconstruction/m3_m68k_config_review.py', tool_sha256=sha(os.path.abspath(__file__)),
                   stage=stage, cc_cmd=ccmd, record_in=rec_in, record_in_sha256=sha(rec_in),
                   tables={p: sha(p) for p in ('06_reconstruction/config_options.tsv', '06_reconstruction/config_options-m68k.tsv')},
                   limits='textual scan of the stage (comments stripped), not the preprocessor closure; macro tests through '
                          'other macros and header users are not attributed to objects',
                   summary=S, rows=out_rows), open(out, 'w'), indent=1)
    print(json.dumps(S, indent=1))


if __name__ == '__main__':
    if len(sys.argv) != 5:
        sys.exit(__doc__)
    main(*sys.argv[1:])
