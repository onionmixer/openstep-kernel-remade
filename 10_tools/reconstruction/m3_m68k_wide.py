#!/usr/bin/env python3
"""m3_m68k_wide.py -- plan 429 (M3-5): compile the 208 contiguous name-matched 07 C sources
(outside i386 directories) for m68k with the plan 427 stage and compare with the original.

  python3 10_tools/reconstruction/m3_m68k_wide.py cmd1 CC1.cmd
  python3 10_tools/reconstruction/m3_m68k_wide.py diag RUN_ID DIAG.json
  python3 10_tools/reconstruction/m3_m68k_wide.py cmd2 DIAG.json CC2.cmd
  python3 10_tools/reconstruction/m3_m68k_wide.py compare RUN_ID WORKDIR DIAG.json RECORD.json

cmd1     s6l4-g1a compile lines with -arch m68k, "-g -O2" for "-g -O3 -fno-omit-frame-pointer" and
         -fwritable-strings removed (the per-file -D/-I sets are the x86 makefile's), outputs
         stage/W429__BASE.o.
diag     a run that was not published: its stage/_log files are checked against the run's
         output.manifest and read as diagnostics only; every failing command is classified by
         its first error line.
cmd2     the compiling objects again plus their -M lines (a publishable run).
compare  plan 414 helpers (L1 and external spans); external names are the x86 object's external
         __text symbols; the plan 427 subset must be byte-identical to the K427 objects.
Read-only apart from the outputs named above.
"""
import sys, os, re, csv, json, hashlib, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m0_m68k_cause as C

OBJS = '06_reconstruction/m68k-text-objects.tsv'
REC409 = '09_validation/reconstruction/m0-i386-18334-l1-20261009.json'
S6L4 = '08_build/runs/s6l4-g1a/run.cmd'
K427 = '08_build/runs/m3p427-cc1/out/K427__%s.o'
PFX = 'W429__'
OLD = ' -g -O3 -fno-omit-frame-pointer '
KNOWN = {'x86-ufs_alloc': 'i386 byte-swap helper _verify_and_swap_cg (plan 214/355) absent in the m68k original',
         'x86-ufs_dir': 'i386 byte-swap helper _brelse_and_swap absent in the m68k original',
         'x86-kern_uname': 'm68k-only machine_type switch (plan 428)'}
sha = C.sha


def targets():
    rec = {o['object']: o for o in json.load(open(REC409))['slice']['objects']}
    rows = [r for r in csv.DictReader(open(OBJS).read().splitlines()[1:], delimiter='\t')]
    lines = [l for l in open(S6L4).read().splitlines() if l.startswith('RUN ') and ' -c ' in l]
    byout = {}
    for l in lines:
        byout.setdefault(os.path.basename(l.split()[-1]), []).append(l)
    out = []
    for r in rows:
        if r['class'] != 'contiguous' or not r['source'].endswith('.c') or '/i386/' in r['source']:
            continue
        o = [x for x in rec.values() if x['n'] == int(r['x86_n'])][0]
        base = os.path.basename(o['obj'])
        assert len(byout[base]) == 1, base
        out.append(dict(object=r['x86_object'], n=int(r['x86_n']), base=base[:-2], line=byout[base][0], obj=o['obj'],
                        grade=o['grade'], i386_slice=o['verdict']))
    assert len(out) == 208
    return out


def m68k_line(l, out):
    assert l.count(OLD) == 1 and l.split().count('-fwritable-strings') == 1 and l.count(' -arch i386 ') == 1
    l = l.replace(' -arch i386 ', ' -arch m68k ').replace(OLD, ' -g -O2 ').replace(' -fwritable-strings ', ' ')
    w = l.split()
    w[-1] = out
    return ' '.join(w)


def cmd1(out):
    T = targets()
    L = [m68k_line(t['line'], 'stage/%s%s.o' % (PFX, t['base'])) for t in T]
    E = ['EXPECT %s%s.o' % (PFX, t['base']) for t in T]
    open(out, 'w').write('\n'.join(['# m3p429-cc1: plan 429 m68k compile of 208 objects (m3_m68k_wide.py cmd1)'] + L + E) + '\n')
    print('commands', len(L))


def diag(rid, outj):
    rdir = os.path.join('08_build/runs', rid)
    assert not os.path.exists(os.path.join(rdir, 'out')), 'run was published'
    man = {}
    for l in open(os.path.join(rdir, 'output.manifest')).read().splitlines():
        w = l.split()
        man[w[-1]] = w[0]
    for p in list(man):
        if '/_log/' in p:
            q = os.path.join(rdir, p.split('stage/', 1)[-1] if 'stage/' in p else p)
            q = os.path.join(rdir, 'stage', p.split('stage/', 1)[1]) if 'stage/' in p else q
            if os.path.exists(q):
                assert sha(q) == man[p], 'log differs from output.manifest: ' + p
    runs = [l for l in open(os.path.join(rdir, 'run.cmd')).read().splitlines() if l.startswith('RUN ')]
    status = dict(l.split() for l in open(os.path.join(rdir, 'stage', '_log', 'status')).read().splitlines())
    T = {t['base']: t for t in targets()}
    rows = []
    for i, l in enumerate(runs):
        base = l.split()[-1][len('stage/' + PFX):-2]
        rc = status['%02d' % i]
        err = open(os.path.join(rdir, 'stage', '_log', '%02d.err' % i), errors='replace').read().splitlines()
        first = next((e for e in err if re.search(r'error|#error|No such file', e, re.I)), err[0] if err and rc != '0' else '')
        m = re.match(r'^(\S+?):(\d+): (.*)$', first)
        rows.append(dict(object=T[base]['object'], base=base, rc=int(rc), first_error=first,
                         file=m.group(1) if m else None, message=m.group(3) if m else None))
    fail = [r for r in rows if r['rc']]
    S = dict(commands=len(rows), failed=len(fail), compiled=len(rows) - len(fail),
             first_error_file=dict(collections.Counter(r['file'] for r in fail)),
             first_error_message=dict(collections.Counter(r['message'] for r in fail)))
    json.dump(dict(plan=429, run=rid, note='diagnostic read of an unpublished run (logs hash-checked against its output.manifest)',
                   manifest_sha256=sha(os.path.join(rdir, 'output.manifest')), summary=S, rows=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))


def cmd2(dj, out):
    D = json.load(open(dj))
    ok = {r['base'] for r in D['rows'] if r['rc'] == 0}
    T = [t for t in targets() if t['base'] in ok]
    L = [m68k_line(t['line'], 'stage/%s%s.o' % (PFX, t['base'])) for t in T]
    M = []
    for l in L:
        w = l.split()
        w[w.index('-c')] = '-M'
        M.append(' '.join(w[:w.index('-o')]))
    E = ['EXPECT %s%s.o' % (PFX, t['base']) for t in T]
    open(out, 'w').write('\n'.join(['# m3p429-cc2: plan 429 m68k compile of the %d compiling objects + -M (m3_m68k_wide.py cmd2)'
                                    % len(T)] + L + M + E) + '\n')
    print('objects', len(T), 'commands', len(L) + len(M))


def compare(rid, workdir, dj, outj):
    D = json.load(open(dj))
    T = {t['base']: t for t in targets()}
    T46 = {t['base'] for t in json.load(open(C.TARGETS))['targets']}
    img = C.Img()
    os.makedirs(workdir, exist_ok=True)
    rows = []
    for base, t in sorted(T.items()):
        p = os.path.join('08_build/runs', rid, 'out', '%s%s.o' % (PFX, base))
        if not os.path.exists(p):
            continue
        xo = macho_obj.parse(open(t['obj'], 'rb').read())
        xt = [s for s in xo['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')]
        ext = [y['name'] for y in xo['symbols'] if xt and y['kind'] == 'SECT' and y.get('ext') and not y['stab']
               and y['sect'] == xt[0]['index']]
        same46 = (sha(p) == sha(K427 % base)) if base in T46 else None
        d = C.run_l1(p, os.path.join(workdir, 'l1-%s.json' % t['object']))
        _, ts, spans = C.compare_object(img, p, ext)
        f = [x for x in d['functions'] if x['section'] == '__TEXT,__text']
        rows.append(dict(object=t['object'], grade=t['grade'], i386_slice=t['i386_slice'], in46=base in T46, same_as_k427=same46,
                         verdict=d['object_verdict'], text_size=ts['size'],
                         functions=dict(collections.Counter(x['verdict'] for x in f)),
                         function_bytes=sum(x['object_range'][1] - x['object_range'][0] for x in f if x['verdict'] == 'MATCH'),
                         spans_equal=sum(1 for s in spans if s.get('equal')), spans=sum(1 for s in spans if 'image_address' in s),
                         ext_missing_in_image=sorted(s['name'] for s in spans if s.get('image') is None and 'image_address' not in s),
                         known=KNOWN.get(t['object'], '')))
    def agg(R):
        return dict(objects=len(R), object_match=sum(r['verdict'] == 'OBJECT_MATCH' for r in R),
                    functions=dict(sum((collections.Counter(r['functions']) for r in R), collections.Counter())),
                    match_bytes=sum(r['function_bytes'] for r in R), text_bytes=sum(r['text_size'] for r in R),
                    spans_equal=sum(r['spans_equal'] for r in R), spans=sum(r['spans'] for r in R))
    S = collections.OrderedDict()
    S['compiled'] = len(rows)
    S['failed_diag'] = D['summary']
    S['subset46_identical'] = [sum(1 for r in rows if r['in46'] and r['same_as_k427']), sum(1 for r in rows if r['in46'])]
    S['all'] = agg(rows)
    S['new'] = agg([r for r in rows if not r['in46']])
    S['new_i386_slice_object_match_grade_A'] = agg([r for r in rows if not r['in46'] and r['i386_slice'] == 'OBJECT_MATCH' and r['grade'] == 'A'])
    S['new_other'] = [r['object'] for r in rows if not r['in46'] and not (r['i386_slice'] == 'OBJECT_MATCH' and r['grade'] == 'A')]
    by = collections.defaultdict(list)
    for r in rows:
        src = [t for t in T.values() if t['object'] == r['object']][0]['line'].split()
        by[os.path.dirname(src[src.index('-c') + 1]).replace('src/src/', '')].append(r)
    S['by_dir'] = {k: [sum(x['verdict'] == 'OBJECT_MATCH' for x in v), len(v)] for k, v in sorted(by.items())}
    S['new_not_match'] = sorted('%s%s' % (r['object'], (' [' + r['known'] + ']') if r['known'] else '')
                                for r in rows if not r['in46'] and r['verdict'] != 'OBJECT_MATCH')
    json.dump(dict(plan=429, tool='10_tools/reconstruction/m3_m68k_wide.py', tool_sha256=sha(os.path.abspath(__file__)),
                   run=rid, diag=dj, diag_sha256=sha(dj), stage='08_build/runs/tools/m0p427-stage',
                   note='per-file -D/-I sets are the x86 makefile defines; results are measurements under the plan 427 configuration',
                   summary=S, objects=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))


def main():
    a = sys.argv[1:]
    if a[:1] == ['cmd1'] and len(a) == 2:
        cmd1(a[1])
    elif a[:1] == ['diag'] and len(a) == 3:
        diag(a[1], a[2])
    elif a[:1] == ['cmd2'] and len(a) == 3:
        cmd2(a[1], a[2])
    elif a[:1] == ['compare'] and len(a) == 5:
        compare(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
