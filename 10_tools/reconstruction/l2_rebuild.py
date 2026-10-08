#!/usr/bin/env python3
"""l2_rebuild.py -- plan 394 items 15-16 (D057): rebuild the recorded objects from the
current 07_kernel in groups, then check them.

  python3 10_tools/reconstruction/l2_rebuild.py groups
        print the groups of 06_reconstruction/l2_build_forms.tsv and their sizes
  python3 10_tools/reconstruction/l2_rebuild.py prepare GROUP RID [N1,N2,...]
        (with row numbers: only those rows of the group, in that order; recorded in
        08_build/runs/tools/RID.rows.json for check -- plan 395)
        stage the group's sources (+ per-row header companions) with one stage_headers
        call, write 08_build/runs/tools/RID.cmd (per row: a `cc -M` line, then the
        selected compile line with only -o changed to stage/L2_<row>__<name>.o, RUNIN
        rows @R/stage/...; one ABSROOT line for the ABSROOT group; EXPECT per object)
        and print the kr_run commands to run.  Nothing is launched.
  python3 10_tools/reconstruction/l2_rebuild.py check GROUP RID OUT.json
        after kr_run collect: (a) every expected object published; (b) every `cc -M`
        dependency mapped to the group manifest and equal (logical path, origin,
        SHA-256) to the manifest of a singleton stage of that row (source + companions,
        same options); dependencies read from outside 07_kernel / adopted copies are
        listed; (c) L1 of each new object compared structurally with the baseline L1
        (09_validation/reconstruction/s6-l2-baseline-20261008/, plan 394 item 14).
        zerofill reruns are a separate step (item 16).

Rows are identified by their 1-based row number in the forms table (the baseline uses the
same numbering), never by object id (x86-memcpy is used twice).

Plan 398: env L2_FORMS selects another forms table (default below; plan 398 uses
06_reconstruction/l2_build_forms-s6p398.tsv, whose rows 1..385 are the default table's rows),
env L2_EXPECT a json of per-row expectations (l2_forms_s6p398.py): for those rows check runs
l1_compare with the given --place placements and compares the object verdict and reasons with
the expectation instead of the baseline L1 (field expected_ok); other rows keep the baseline
comparison.
"""
import sys, os, csv, json, re, subprocess, shutil, hashlib, tempfile

FORMS = os.environ.get('L2_FORMS', '06_reconstruction/l2_build_forms.tsv')
EXPECT = json.load(open(os.environ['L2_EXPECT']))['expect'] if os.environ.get('L2_EXPECT') else {}
T = '08_build/runs/tools/'
R = '08_build/runs/'
BASE = '09_validation/reconstruction/s6-l2-baseline-20261008'
IMG = '03_original/x86/binaries/mach_kernel'
STAGE_OPTS = ['--prefer-07', '--nextdev', '--bsd-set', 'nextos', '--mach-set', 'sdk']
ABS_PREFIX = '/BinarySourceCache_Mario1A/mk/mk-183.34.4/'
SP = os.environ.get('L2_SCRATCH', tempfile.gettempdir())


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def rows():
    out = []
    for n, r in enumerate(csv.DictReader(open(FORMS), delimiter='\t'), 1):
        r['n'] = n
        r['opts'] = json.loads(r['stage_options']) if r['stage_options'] else {}
        r['w'] = r['argv'].split()
        out.append(r)
    return out


def selected_manifest(r):
    src = json.load(open(R + r['run'] + '/out/run.json'))['src']
    return json.load(open(src + '.manifest.json'))


def companions(r):
    """header companions of the selected run (manifest 'sources' ending in .h)"""
    return [s for s in r['opts'].get('sources', []) if s.endswith('.h')]


def group_of(r):
    pub = r['opts'].get('public_sdk', [])
    if pub:
        return 'G5'
    if r['runin_dir'] == 'src/src/objc-runtime/HashTable':
        return 'G6'
    if r['runin_dir'] == 'src/src/objc-runtime':
        return 'G4'
    if any(w.startswith('@ABS/') for w in r['w']):
        return 'G3'
    if r['runin_dir'] == 'src/src/driverkit/libDriver':
        files = {f[0] for f in selected_manifest(r)['files']}
        return 'G2a' if 'nextdev/objc/hashtable.h' in files else 'G2b'
    if r['runin_dir'] == '':
        return 'G1'
    raise SystemExit('row %d: no group (%s)' % (r['n'], r['runin_dir']))


def logical_source(r):
    w = r['w']
    s = w[w.index('-c') + 1]
    if s.startswith('@ABS/'):
        return s[len('@ABS/'):]
    if s.startswith('src/src/'):
        return s[len('src/src/'):]
    return os.path.normpath(os.path.join(r['runin_dir'][len('src/src/'):], s))


def out_name(r):
    w = r['w']
    return 'L2_%03d__%s' % (r['n'], os.path.basename(w[w.index('-o') + 1]).split('__', 1)[1])


def lines_for(r):
    w = list(r['w'])
    i = w.index('-o')
    obj = out_name(r)
    w[i + 1] = ('@R/stage/' if r['runin_dir'] else 'stage/') + obj
    dep = list(r['w'])
    del dep[dep.index('-o'):dep.index('-o') + 2]
    dep[dep.index('-c')] = '-M'
    pre = ('RUNIN %s ' % r['runin_dir']) if r['runin_dir'] else 'RUN '
    return [pre + ' '.join(dep), pre + ' '.join(w)], obj


def public_opts(rs):
    pubs = sorted({p for r in rs for p in r['opts'].get('public_sdk', [])})
    out = []
    for p in pubs:
        out += ['--public-sdk', p]
    return out


def cmd_groups():
    g = {}
    for r in rows():
        g.setdefault(group_of(r), []).append(r)
    for k in sorted(g):
        print(k, len(g[k]), [r['object'] for r in g[k]][:6])


def select_rows(group, rid=None, only=None):
    """rows of a group; a subset run (prepare with row numbers, plan 395) records its rows in
    08_build/runs/tools/RID.rows.json so that check uses the same ordered subset"""
    rs = [r for r in rows() if group_of(r) == group]
    side = T + rid + '.rows.json' if rid else None
    if only is None and side and os.path.exists(side):
        only = json.load(open(side))['rows']
    if only is not None:
        want = list(only)
        got = {r['n']: r for r in rs}
        missing = [n for n in want if n not in got]
        if missing:
            raise SystemExit('rows %s are not in group %s' % (missing, group))
        rs = [got[n] for n in want]
    return rs


def cmd_prepare(group, rid, only=None):
    rs = select_rows(group, None, only)
    assert rs, group
    st = T + rid + '-stage'
    cmdf = T + rid + '.cmd'
    for p in (st, st + '.manifest.json', cmdf):
        if os.path.exists(p):
            raise SystemExit('%s exists' % p)
    srcs = []
    for r in rs:
        for s in [logical_source(r)] + companions(r):
            if s not in srcs:
                srcs.append(s)
    p = subprocess.run(['python3', '10_tools/reconstruction/stage_headers.py'] + STAGE_OPTS + public_opts(rs)
                       + [st] + srcs, capture_output=True, text=True)
    print(p.stdout.strip()[-300:], p.stderr.strip()[-300:])
    if p.returncode:
        raise SystemExit('stage_headers failed')
    names, lower = set(), set()
    body = ['# %s: plan 394 (D057) rebuild of group %s from 07 (%d objects; l2_rebuild.py)' % (rid, group, len(rs))]
    if group == 'G3':
        body.append('ABSROOT')
    for r in rs:
        ls, obj = lines_for(r)
        if obj.lower() in lower:
            raise SystemExit('output name collision %s' % obj)
        lower.add(obj.lower())
        names.add(obj)
        body += ls
    body += ['EXPECT %s' % o for o in sorted(names)]
    open(cmdf, 'w').write('\n'.join(body) + '\n')
    if only is not None:
        json.dump({'group': group, 'rows': [r['n'] for r in rs]}, open(T + rid + '.rows.json', 'w'))
    print('wrote', cmdf, len(rs), 'objects')
    print('next: python3 10_tools/reconstruction/kr_run.py prepare %s %s %s; ... launch %s' % (rid, st, cmdf, rid))


def parse_deps(text):
    text = text.replace('\\\n', ' ')
    out = []
    for line in text.splitlines():
        if ':' not in line:
            continue
        out += line.split(':', 1)[1].split()
    return out


def dep_logical(dep, r, run_abs):
    """map a cc -M dependency path to a staged logical path (relative to the stage root)"""
    if dep.startswith(ABS_PREFIX):
        p = 'src/' + dep[len(ABS_PREFIX):]
    elif dep.startswith('/'):
        if not dep.startswith(run_abs + '/src/'):
            return None
        p = dep[len(run_abs) + len('/src/'):]
    else:
        base = r['runin_dir'] if r['runin_dir'] else ''
        p = os.path.normpath(os.path.join(base, dep))
        if not p.startswith('src/'):
            return None
        p = p[len('src/'):]
    return os.path.normpath(p)


def singleton_manifest(r, opts_pub):
    d = tempfile.mkdtemp(dir=SP, prefix='l2single-')
    st = os.path.join(d, 'stage')
    srcs = [logical_source(r)] + companions(r)
    p = subprocess.run(['python3', '10_tools/reconstruction/stage_headers.py'] + STAGE_OPTS + opts_pub + [st] + srcs,
                       capture_output=True, text=True)
    if p.returncode:
        shutil.rmtree(d)
        return None
    m = json.load(open(st + '.manifest.json'))
    shutil.rmtree(d)
    return {f[0]: (f[1], f[2]) for f in m['files']}


def l1_struct(d):
    secs = {}
    for k, v in d['sections'].items():
        secs[k] = {x: v.get(x) for x in ('placement', 'address', 'size', 'byte_differences', 'references',
                                         'refs_differ', 'refs_unverified', 'bytes')}
    fns = []
    for f in d['functions']:
        fns.append({x: f.get(x) for x in ('names', 'section', 'image_range', 'object_range', 'verdict',
                                          'byte_differences', 'refs', 'refs_differ', 'refs_unverified',
                                          'data_sections', 'zero_fill_placement_only')})
    return {'object_verdict': d['object_verdict'], 'object_reasons': d['object_reasons'], 'sections': secs,
            'functions': fns, 'methods': d.get('methods')}


def cmd_check(group, rid, outp):
    rs = select_rows(group, rid)
    run = R + rid
    rj = json.load(open(run + '/out/run.json'))
    man = json.load(open(rj['src'] + '.manifest.json'))
    gm = {f[0]: (f[1], f[2]) for f in man['files']}
    run_abs = '/ndrv/openstep-kernel-remade/' + run
    cmds = [l for l in open(run + '/run.cmd').read().splitlines() if l.startswith(('RUN ', 'RUNIN '))]
    res = {'group': group, 'run': rid, 'forms': FORMS, 'forms_sha256': sha(FORMS),
           'expect': os.environ.get('L2_EXPECT'), 'objects': []}
    pubs = public_opts(rs)
    for i, r in enumerate(rs):
        rec = {'n': r['n'], 'object': r['object'], 'source': r['source'], 'grade': r['grade']}
        obj = run + '/out/' + out_name(r)   # out_name keeps the .o of the selected output
        rec['obj'] = obj
        if not os.path.exists(obj):
            rec['problem'] = 'object not published'
            res['objects'].append(rec)
            continue
        rec['obj_sha256'] = sha(obj)
        dep_log = run + '/out/_log/%02d.out' % (2 * i)
        assert ' -M ' in cmds[2 * i] and logical_source(r).split('/')[-1] in cmds[2 * i], (i, cmds[2 * i][:80])
        deps = parse_deps(open(dep_log).read())
        single = singleton_manifest(r, pubs)
        if single is None:
            rec['problem'] = 'singleton staging failed'
        bad, outside = [], []
        for dp in deps:
            lg = dep_logical(dp, r, run_abs)
            if lg is None or lg not in gm:
                outside.append(dp)
                continue
            if single is not None and single.get(lg) != gm[lg]:
                bad.append(lg)
            if not gm[lg][0].startswith('07_kernel'):
                outside.append(lg + ' <- ' + gm[lg][0])
        rec['deps'] = len(deps)
        rec['deps_group_vs_singleton_differ'] = bad
        rec['deps_not_from_07'] = outside
        out = '09_validation/reconstruction/%s-l1-%03d.json' % (rid, r['n'])
        ex = EXPECT.get(str(r['n']))
        if ex is not None:
            assert ex['object'] == r['object'], (r['n'], ex['object'], r['object'])
        place = []
        for k, v in sorted((ex or {}).get('place', {}).items()):
            place += ['--place', '%s=%s' % (k, v)]
        cmd = [sys.executable, '10_tools/reconstruction/l1_compare.py', '--image', IMG, '--obj', obj,
               '--place-from-image'] + (['--place-from-objc'] if r['source'].endswith('.m') else []) + place + ['--out', out]
        p = subprocess.run(cmd, capture_output=True, text=True)
        if p.returncode or not os.path.exists(out):
            rec['problem'] = 'l1_compare failed'
            res['objects'].append(rec)
            continue
        new = l1_struct(json.load(open(out)))
        if ex is not None:
            rec['l1'] = out
            rec['verdict'] = new['object_verdict']
            rec['reasons'] = new['object_reasons']
            rec['expected'] = {'verdict': ex['verdict'], 'reasons': ex['reasons'], 'place': ex['place'], 'kind': ex['kind']}
            rec['expected_ok'] = (new['object_verdict'] == ex['verdict'] and sorted(new['object_reasons']) == sorted(ex['reasons']))
            res['objects'].append(rec)
            print(r['n'], r['object'], new['object_verdict'], 'expected-ok' if rec['expected_ok'] else 'EXPECTED-FAIL', len(bad), flush=True)
            continue
        bl = [f for f in os.listdir(BASE) if f.startswith('%03d-' % r['n'])]
        assert len(bl) == 1, (r['n'], bl)
        old = l1_struct(json.load(open(os.path.join(BASE, bl[0]))))
        rec['l1'] = out
        rec['verdict'] = new['object_verdict']
        rec['same_as_baseline'] = new == old
        if new != old:
            rec['diff_keys'] = [k for k in new if new[k] != old[k]]
        res['objects'].append(rec)
        print(r['n'], r['object'], new['object_verdict'], 'same' if new == old else 'DIFF', len(bad), flush=True)
    json.dump(res, open(outp, 'w'), indent=1)
    o = res['objects']
    print('objects', len(o), 'same', sum(1 for x in o if x.get('same_as_baseline')),
          'expected-ok', sum(1 for x in o if x.get('expected_ok')), 'expected-fail', sum(1 for x in o if 'expected_ok' in x and not x['expected_ok']),
          'problems', sum(1 for x in o if x.get('problem')),
          'group-vs-singleton dep differences', sum(1 for x in o if x.get('deps_group_vs_singleton_differ')))


if __name__ == '__main__':
    a = sys.argv[1:]
    if a[0] == 'groups':
        cmd_groups()
    elif a[0] == 'prepare':
        cmd_prepare(a[1], a[2], [int(x) for x in a[3].split(',')] if len(a) > 3 else None)
    elif a[0] == 'check':
        cmd_check(a[1], a[2], a[3])
    else:
        raise SystemExit(__doc__)
