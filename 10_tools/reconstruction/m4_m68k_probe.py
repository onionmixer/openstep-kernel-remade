#!/usr/bin/env python3
"""m4_m68k_probe.py -- plan 496 (M4-2): compile-path probe of m68k-only C sources (diagnostic).

  python3 10_tools/reconstruction/m4_m68k_probe.py stage SPEC.json STAGE_DIR
  python3 10_tools/reconstruction/m4_m68k_probe.py cmd SPEC.json CC.cmd
  python3 10_tools/reconstruction/m4_m68k_probe.py compare SPEC.json RUN_ID RECORD.json
  python3 10_tools/reconstruction/m4_m68k_probe.py funcs SPEC.json RUN_ID OTOOL_DIR RECORD.json

SPEC.json (kept under the ignored 08_build/artifacts; it names reference files, not their text):
  {"plan": 496, "base": "<m68k stage>", "m5_line": "<cmd file with one m68k M5 compile line>",
   "objects": [{"name": "dkbad", "m4_id": "m68k-271", "x86_rel": "machdep/i386/dkbad.c",
                "variants": {"N": "01_resources/upstream/nextmach/mk-108.1/next/dkbad.c", "X": null}}]}
  A variant path is copied to src/m4probe/<dir>/<file> of the stage; null compiles the base stage's
  src/<x86_rel> as it is; '@<rel>' (plan 497) compiles the base stage's src/<rel> as it is.
  Optional "refs" (plan 497): {name: [ref object, sha256]} for every object; compare then also checks
  each variant object against its REF (canon, obj_sig) and exits 1 unless every command exits 0 with
  no warning (plan 500: or, for a target in "known_warnings", a compile stderr equal to its listed lines), no dependency listing has an i386 header and every variant is a 'candidate' equal to REF.
stage    copy of the base stage plus the copied variant files (no quote includes allowed);
         STAGE_DIR.manifest.json lists [path, origin, sha256] and must equal the base manifest plus
         the added files.
cmd      per object its single x86 line of 08_build/runs/tools/s6l4-g1a.cmd with the plan 429
         replacements (-arch m68k, "-g -O2", no -fwritable-strings; each exactly once); per variant a
         compile (-o stage/Q<plan>__<name>_<V>.o) and a dependency listing (-M, no -o).
compare  reads the unpublished run directory (kr_run collect refuses nonzero exits): all collect
         checks except exit status 0 and EXPECT presence; per command status, warnings, first error
         and its class; per dependency listing the architecture/m68k and architecture/i386 paths and
         the origins outside 07; per object L1 (--place-from-image), __text size against the plan 495
         exact range, external text symbols against the original names in that range, undefined
         symbols missing from the original, and N/X object equality (canon, obj_sig).
Plan 499: m4_id may be a list of plan 495 rows (each exact, sorted by address, end of one = start of the
next; any kind); optional m4_id_alt is a second range hypothesis recorded beside it; full_span also
needs the L1 placement of __TEXT,__text at the range start; diag_gate (commands, warnings, i386
headers) is recorded with or without refs.
funcs    per object variant: the real-machine `otool -tv` listing OTOOL_DIR/<name>_<V>.txt against the
         original listing 08_build/artifacts/m0p414/otool-V10/image.txt, function by function (original
         entries of m68k-functions.tsv in the range, object labels; pairs by name incl. aliases):
         instruction counts, equality of the instruction sequences with hex numbers masked, object symbol
         external or not, unpaired functions.
Read-only apart from the outputs named above.
"""
import sys, os, re, json, shutil, hashlib, collections

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
X86CMD = '08_build/runs/tools/s6l4-g1a.cmd'
INV = '06_reconstruction/m68k-m4-inventory.tsv'
FUNCS = '06_reconstruction/m68k-functions.tsv'
OLD = ' -g -O3 -fno-omit-frame-pointer '


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def load(spec):
    s = json.load(open(spec))
    assert {'plan', 'base', 'm5_line', 'objects'} <= set(s) <= {'plan', 'base', 'm5_line', 'objects', 'refs', 'known_warnings'}, sorted(s)
    if 'known_warnings' in s:                 # plan 500: exact stderr lines accepted for a target's compile
        assert set(s['known_warnings']) <= {o['name'] for o in s['objects']}, sorted(s['known_warnings'])
        assert all(isinstance(v, list) and v for v in s['known_warnings'].values())
    if 'refs' in s:
        assert set(s['refs']) == {o['name'] for o in s['objects']}, sorted(s['refs'])
    for o in s['objects']:
        assert {'name', 'm4_id', 'x86_rel', 'variants'} <= set(o) <= {'name', 'm4_id', 'x86_rel', 'variants', 'm4_id_alt'}, sorted(o)
        assert re.match(r'^[A-Za-z0-9_]+$', o['name']) and all(re.match(r'^[A-Z][A-Z0-9]*$', v) for v in o['variants'])
        for v, p in o['variants'].items():       # plan 503: {"src": ..., "inc": [[rel, file], ...]}
            if isinstance(p, dict):
                assert set(p) in ({'src', 'inc'}, {'src', 'inc', 'defs'}) and all(len(x) == 2 and not x[0].startswith('/') and '..' not in x[0] for x in p['inc']), (o['name'], v)
                assert all(re.match(r'^-D[A-Za-z_][A-Za-z0-9_]*(=[^\s]+)?$', d) for d in p.get('defs', [])), (o['name'], v)   # plan 511
    return s


def vsrc(o, v):
    p = o['variants'][v]
    return p['src'] if isinstance(p, dict) else p


def vinc(o, v):
    p = o['variants'][v]
    return p['inc'] if isinstance(p, dict) else []


def vdefs(o, v):
    """plan 511: extra -D options of a dict variant (after the existing -D options)"""
    p = o['variants'][v]
    return p.get('defs', []) if isinstance(p, dict) else []


def incdir(o, v):
    return 'src/m4probe/inc_%s_%s' % (o['name'], v)


def vrel(o, v):
    p = vsrc(o, v)
    if isinstance(o['variants'][v], dict) and p is not None and not p.startswith('@'):
        return 'src/m4probe/v_%s_%s/%s' % (o['name'], v, os.path.basename(p))   # plan 503: one place per variant
    if p is not None and p.startswith('@'):
        return 'src/' + p[1:]
    return 'src/' + o['x86_rel'] if p is None else 'src/m4probe/%s/%s' % (os.path.basename(os.path.dirname(p)), os.path.basename(p))


def cmd_stage(spec, stage):
    s = load(spec)
    assert not os.path.exists(stage), stage
    base = json.load(open(s['base'] + '.manifest.json'))
    shutil.copytree(s['base'], stage, symlinks=False)
    files = [list(f[:3]) for f in base['files']]
    have = {f[0] for f in files}
    for f in files:
        assert sha(os.path.join(stage, f[0])) == f[2], f[0]
    added = []
    for o in s['objects']:
        for v in sorted(o['variants']):
            p = vsrc(o, v)
            for hrel, hp in vinc(o, v):           # plan 503: variant include directory
                r = incdir(o, v) + '/' + hrel
                assert r not in have, r
                os.makedirs(os.path.dirname(os.path.join(stage, r)), exist_ok=True)
                shutil.copyfile(hp, os.path.join(stage, r))
                added.append([r, hp, sha(hp)])
                have.add(r)
            if p is None or p.startswith('@'):
                assert vrel(o, v) in have, vrel(o, v)
                continue
            t = open(p, errors='replace').read()
            assert not re.search(r'^\s*#\s*(include|import)\s*"', t, re.M), ('quote include', p)
            r = vrel(o, v)
            assert r not in have, r
            os.makedirs(os.path.dirname(os.path.join(stage, r)), exist_ok=True)
            shutil.copyfile(p, os.path.join(stage, r))
            added.append([r, p, sha(p)])
            have.add(r)
    walk = sorted(os.path.relpath(os.path.join(d, n), stage) for d, _, ns in os.walk(stage) for n in ns)
    assert walk == sorted(have), sorted(set(walk) ^ have)[:5]
    m = dict(plan=s['plan'], base=s['base'], base_manifest_sha256=sha(s['base'] + '.manifest.json'), added=added, files=files + added)
    json.dump(m, open(stage.rstrip('/') + '.manifest.json', 'w'), indent=1)
    print('stage', stage, 'files', len(m['files']), 'added', len(added))


def span(inv, ids):
    """plan 499: the address range of one plan 495 row or of a list of adjoining exact rows;
    plan 511: or {"range": [lo, hi], "rows": [...], "basis": "..."}, an explicit range whose bounds are
    function-table entry boundaries (lo an entry, hi the end of the last entry in the range), whose
    overlapping plan 495 rows ([start_lo, end_hi)) are exactly "rows" and lie inside it"""
    if isinstance(ids, dict):
        assert set(ids) == {'range', 'rows', 'basis'} and isinstance(ids['basis'], str) and ids['basis'].strip(), sorted(ids)
        lo, hi = (int(x, 16) for x in ids['range'])
        rows = list(ids['rows'])
        assert lo < hi and rows and len(set(rows)) == len(rows) and all(i in inv for i in rows), ids
        fun = [l.split('\t') for l in open(FUNCS).read().split('\n') if l and not l.startswith('#')][1:]
        es = sorted((int(f_[0], 16), int(f_[1], 16)) for f_ in fun if lo <= int(f_[0], 16) < hi)
        assert es and es[0][0] == lo and es[-1][1] == hi, ('range not on entry boundaries', ids['range'])
        assert all(a[1] == b[0] for a, b in zip(es, es[1:])), ('gap in the range', ids['range'])
        ov = sorted(r['id'] for r in inv.values() if r['start_lo'] and r['end_hi']
                    and int(r['start_lo'], 16) < hi and int(r['end_hi'], 16) > lo)
        assert ov == sorted(rows), ('rows', sorted(set(ov) ^ set(rows)))
        assert all(lo <= int(inv[i]['start_lo'], 16) and int(inv[i]['end_hi'], 16) <= hi for i in rows), 'row outside range'
        return lo, hi, sorted(rows, key=lambda i: int(inv[i]['start_lo'], 16))
    ids = [ids] if isinstance(ids, str) else list(ids)
    assert ids and len(set(ids)) == len(ids) and all(i in inv for i in ids), ids
    rs = sorted((inv[i] for i in ids), key=lambda r: int(r['start_lo'], 16))
    for r in rs:
        assert r['exact'] == '1' and r['start_lo'] == r['start_hi'] and r['end_lo'] == r['end_hi'], r['id']
    for a, b in zip(rs, rs[1:]):
        assert a['end_lo'] == b['start_lo'], (a['id'], b['id'])
    return int(rs[0]['start_lo'], 16), int(rs[-1]['end_lo'], 16), [r['id'] for r in rs]


def entries(fun, lo, hi):
    es = [f_ for f_ in fun if lo <= int(f_[0], 16) < hi]
    return sorted({n for f_ in es for n in f_[3].split(',') if n}), sum(1 for f_ in es if not f_[3]), es


def x86_line(rel):
    L = [l.rstrip('\n') for l in open(X86CMD) if l.startswith('RUN ') and ' src/src/%s ' % rel in l]
    assert len(L) == 1, (rel, len(L))
    l = L[0]
    assert l.count(OLD) == 1 and l.split().count('-fwritable-strings') == 1 and l.count(' -arch i386 ') == 1, rel
    l = l.replace(' -arch i386 ', ' -arch m68k ').replace(OLD, ' -g -O2 ').replace(' -fwritable-strings ', ' ')
    w = l.split()
    assert 'i386' not in ' '.join(a for a in w if a != 'src/src/' + rel), ('i386 left', rel)
    return w


def opts(w):
    return [a for a in w if a.startswith(('-D', '-I'))]


def cmd_cmd(spec, out):
    s = load(spec)
    m5 = [l.split() for l in open(s['m5_line']) if l.startswith('RUN ')]
    assert len(m5) == 1
    L, E, D = [], [], []
    for o in s['objects']:
        base = x86_line(o['x86_rel'])
        D.append([o['name'], [a for a in opts(base) if a not in opts(m5[0])], [a for a in opts(m5[0]) if a not in opts(base)],
                  opts(base) == [a for a in opts(m5[0]) if a in opts(base)]])
        for v in sorted(o['variants']):
            w = list(base)
            w[w.index('-c') + 1] = 'src/' + vrel(o, v)
            w[w.index('-o') + 1] = 'stage/Q%d__%s_%s.o' % (s['plan'], o['name'], v)
            if vinc(o, v):                          # plan 503: after the existing -I directories
                k = max(i for i, a in enumerate(w) if a.startswith('-I'))
                w.insert(k + 1, '-Isrc/' + incdir(o, v))
            if vdefs(o, v):                         # plan 511: after the existing -D options
                k = max(i for i, a in enumerate(w) if a.startswith('-D'))
                w[k + 1:k + 1] = vdefs(o, v)
            L.append(' '.join(w))
            E.append('EXPECT Q%d__%s_%s.o' % (s['plan'], o['name'], v))
            k = w.index('-o')
            m = w[:k] + w[k + 2:]
            m[m.index('-c')] = '-M'
            L.append(' '.join(m))
    open(out, 'w').write('# m4p%d: plan %d m68k compile-path probe (m4_m68k_probe.py cmd)\n' % (s['plan'], s['plan']) + '\n'.join(L + E) + '\n')
    json.dump(D, open(out + '.opts.json', 'w'), indent=1)
    print('commands', len(L), 'option differences vs M5 line', D)


def run_checks(rid):
    import kr_run as K
    rdir = os.path.join('08_build/runs', rid)
    assert not os.path.exists(os.path.join(rdir, 'out')), 'run was published'
    meta = json.load(open(os.path.join(rdir, 'prepare.json')))
    f = []
    need = lambda c, m: None if c else f.append(m)
    need(os.path.exists(os.path.join(rdir, 'DONE')) and open(os.path.join(rdir, 'DONE')).read().split()[0] == rid, 'DONE')
    need(not os.path.exists(os.path.join(rdir, 'FAILED')), 'FAILED')
    exp = open(os.path.join(rdir, 'input.expected')).read()
    need(open(os.path.join(rdir, 'input.actual')).read() == exp and open(os.path.join(rdir, 'input.actual2')).read() == exp, 'input')
    for line in exp.splitlines():
        h, size, rel = line.split(' ')
        need(K.kr_line(os.path.join(rdir, rel), rel) == line, 'host input changed ' + rel)
    need(open(os.path.join(rdir, 'tools.actual')).read() == open(os.path.join(rdir, 'tools.expected')).read(), 'tools')
    need(open(os.path.join(rdir, 'nonregular')).read() == '' and open(os.path.join(rdir, 'hardlinks')).read() == '', 'nonregular/hardlinks')
    status = [l.split() for l in open(os.path.join(rdir, 'stage', '_log', 'status')).read().splitlines()]
    need(len(status) == len(meta['runs']), 'status count')
    man = {}
    for line in open(os.path.join(rdir, 'output.manifest')).read().splitlines():
        h, size, rel = line.split(' ')
        man[rel] = (h, int(size))
    host = K.walk_regular(rdir, 'stage')
    need(set(host) == set(man), 'stage set != manifest')
    for rel in host:
        need(rel in man and (sha(os.path.join(rdir, rel)), os.path.getsize(os.path.join(rdir, rel))) == man.get(rel), 'hash ' + rel)
    assert not f, f
    return rdir, meta, dict(status)


def err_class(err):
    t = '\n'.join(err)
    if re.search(r'No such file|cannot find|not found.*\.h', t):
        return 'header'
    if re.search(r'asm|invalid operand|unknown register|register name|impossible constraint|inconsistent operand', t, re.I):
        return 'asm'
    if re.search(r'undeclared|undefined|incomplete type|has no member', t):
        return 'definition'
    return 'other'


def cmd_compare(spec, rid, outj):
    import macho_obj
    import m0_m68k_cause as C
    import m3_m68k_diag as D
    import l2_prefix_diff as PD
    s = load(spec)
    rdir, meta, st = run_checks(rid)
    runs = [l for l in open(os.path.join(rdir, 'run.cmd')).read().splitlines() if l.startswith('RUN ')]
    stman = {}
    mpath = meta['src'] + '.manifest.json'          # plan 503: the stage the run used
    for f_ in json.load(open(mpath))['files']:
        stman[f_[0]] = f_[1]
    cmds = []
    for i, l in enumerate(runs):
        n = '%02d' % i
        err = open(os.path.join(rdir, 'stage', '_log', n + '.err'), errors='replace').read().splitlines()
        rc = int(st[n])
        r = dict(n=n, kind='deps' if ' -M ' in l else 'compile', source=l.split()[l.split().index('-M' if ' -M ' in l else '-c') + 1],
                 rc=rc, warnings=sum('warning' in e for e in err),
                 first_error=next((e for e in err if re.search(r'error|No such file', e, re.I)), '') if rc else '',
                 err_class=err_class(err) if rc else '')
        if r['kind'] == 'compile':
            r['target'] = re.match(r'^Q\d+__(.+)_[A-Z][A-Z0-9]*\.o$', os.path.basename(l.split()[l.split().index('-o') + 1])).group(1)
            r['err_lines'] = err
        if r['kind'] == 'deps' and rc == 0:
            out = open(os.path.join(rdir, 'stage', '_log', n + '.out'), errors='replace').read()
            deps = sorted(set(re.findall(r'(src/\S+\.h)', out)))
            r['headers'] = len(deps)
            r['arch_m68k'] = sum('architecture/m68k' in d for d in deps)
            r['arch_i386'] = sum('architecture/i386' in d for d in deps)
            r['i386_headers'] = sum('i386' in d for d in deps)   # plan 497.1: any i386 header path
            org = collections.Counter()
            for d in deps:
                o = stman.get(d[len('src/'):], '?')
                org[o.split('/')[0] + ('/' + o.split('/')[1] if o.startswith('07_kernel/') else '')] += 1
            r['origins'] = dict(org)
            r['dep_headers'] = [[d, stman.get(d[len('src/'):], '?')] for d in deps]
        cmds.append(r)
    rows = [l.split('\t') for l in open(INV).read().split('\n') if l and not l.startswith('#')]
    inv = {r[0]: dict(zip(rows[0], r)) for r in rows[1:]}
    fun = [l.split('\t') for l in open(FUNCS).read().split('\n') if l and not l.startswith('#')][1:]
    img = C.Img()
    names = {y['name'] for y in img.img.o['symbols']}
    art = '08_build/artifacts/m4p%d/%s' % (s['plan'], rid)
    os.makedirs(art, exist_ok=True)
    objs = []
    for o in s['objects']:
        lo, hi, ids = span(inv, o['m4_id'])
        onames, unnamed, _ = entries(fun, lo, hi)
        alt = span(inv, o['m4_id_alt']) if 'm4_id_alt' in o else None
        got = {}
        for v in sorted(o['variants']):
            p = os.path.join(rdir, 'stage', 'Q%d__%s_%s.o' % (s['plan'], o['name'], v))
            r = dict(variant=v, source=vrel(o, v), source_sha256=sha(os.path.join(rdir, 'src', vrel(o, v))),
                     exists=os.path.isfile(p) and os.path.getsize(p) > 0)
            if r['exists']:
                b = macho_obj.parse(open(p, 'rb').read())
                text = [x for x in b['sections'] if (x['segname'], x['sectname']) == ('__TEXT', '__text')]
                tsz = text[0]['size'] if text else 0
                ext = sorted(y['name'] for y in b['symbols'] if y['kind'] == 'SECT' and y['ext'] and not y['stab']
                             and text and y['sect'] == text[0]['index'])
                undef = sorted({y['name'] for y in b['symbols'] if y['kind'] == 'UNDF' and not y['stab']} - names)
                d = C.run_l1(p, os.path.join(art, 'l1-%s-%s.json' % (o['name'], v)))
                reasons = d.get('object_reasons') or []
                r.update(obj_sha256=sha(p), text_size=tsz, expected_text_size=hi - lo, ext_text_symbols=ext, original_names=onames,
                         undefined_not_in_original=undef, l1_verdict=d['object_verdict'], l1_reasons=reasons)
                placed = d['sections'].get('__TEXT,__text', {}).get('address') if isinstance(d['sections'], dict) else None
                r.update(range=[hex(lo), hex(hi)], rows=ids, unnamed_entries=unnamed, placed_text=hex(placed) if placed is not None else None)
                full = tsz == hi - lo and set(ext) == set(onames) and not undef and placed == lo
                r['full_span'] = full
                if alt:
                    an = entries(fun, alt[0], alt[1])[0]
                    r['alt'] = dict(rows=alt[2], range=[hex(alt[0]), hex(alt[1])], text_size_equal=tsz == alt[1] - alt[0],
                                    names_equal=set(ext) == set(an), missing=sorted(set(an) - set(ext)), extra=sorted(set(ext) - set(an)),
                                    placed_at_start=placed == alt[0])
                r['missing_names'] = sorted(set(onames) - set(ext))
                r['extra_names'] = sorted(set(ext) - set(onames))
                r['judgement'] = ('candidate' if full and d['object_verdict'] == 'OBJECT_MATCH' else
                                  'provisional' if full and reasons == ['__DATA,__bss: unverified'] else 'no')
                got[v] = p
                r['defined_symbols'] = sorted([y['name'], y['kind'], y['value'] if y['kind'] == 'COMMON' else None]
                                              for y in b['symbols'] if not y['stab'] and y['kind'] in ('COMMON', 'SECT') and y['ext'])
                if 'refs' in s:
                    ref, rsha = s['refs'][o['name']]
                    r.update(ref=ref, ref_sha256_ok=sha(ref) == rsha, ref_canon_equal=D.canon(p) == D.canon(ref),
                             ref_sig_equal=PD.obj_sig(p) == PD.obj_sig(ref))
            objs.append(dict(object=o['name'], m4_id=o['m4_id'], **r))
        ks = sorted(o['variants'])
        for i, x in enumerate(ks):                # plan 503: every pair; missing objects give None
            for y in ks[i + 1:]:
                if x in got and y in got:
                    objs.append(dict(object=o['name'], pair=[x, y], canon_equal=D.canon(got[x]) == D.canon(got[y]),
                                     sig_equal=PD.obj_sig(got[x]) == PD.obj_sig(got[y])))
                else:
                    objs.append(dict(object=o['name'], pair=[x, y], canon_equal=None, sig_equal=None))
    rec = dict(plan=s['plan'], tool=os.path.relpath(os.path.abspath(__file__)), tool_sha256=sha(os.path.abspath(__file__)),
               spec_sha256=sha(spec), run=rid, inputs={p: sha(p) for p in (X86CMD, INV, FUNCS, s['m5_line'], mpath)},
               options=json.load(open(os.path.join(os.path.dirname(spec), 'probe.cmd.opts.json'))) if os.path.exists(os.path.join(os.path.dirname(spec), 'probe.cmd.opts.json')) else None,
               commands=cmds, objects=objs)
    rec['diag_gate'] = dict(commands_ok=all(c['rc'] == 0 and c['warnings'] == 0 for c in cmds),
                            no_i386_headers=all(c.get('i386_headers', 1) == 0 for c in cmds if c['kind'] == 'deps'))
    if 'refs' in s:
        vs = [o for o in objs if 'variant' in o]
        kw = s.get('known_warnings', {})
        rec['gate'] = dict(commands_ok=all(c['rc'] == 0 and (c['err_lines'] == kw[c['target']] if c['kind'] == 'compile' and c['target'] in kw
                                                             else c['warnings'] == 0) for c in cmds),
                           no_i386_headers=all(c.get('i386_headers', 1) == 0 for c in cmds if c['kind'] == 'deps'),
                           all_candidates=bool(vs) and all(o.get('judgement') == 'candidate' for o in vs),
                           refs_equal=bool(vs) and all(o.get('ref_sha256_ok') and o.get('ref_canon_equal') and o.get('ref_sig_equal') for o in vs))
        rec['gate']['ok'] = all(rec['gate'].values())
    json.dump(rec, open(outj, 'w'), indent=1)
    for c in cmds:
        print(c['n'], c['kind'], c['source'], 'rc', c['rc'], 'warn', c['warnings'], c['err_class'], c.get('arch_m68k', ''), c.get('arch_i386', ''), c['first_error'][:90])
    for o in objs:
        print({k: o[k] for k in o if k not in ('original_names', 'ext_text_symbols', 'obj_sha256', 'source_sha256', 'ref')})
    if 'gate' in rec:
        print('gate', rec['gate'])
        sys.exit(0 if rec['gate']['ok'] else 1)


IMGLIST = '08_build/artifacts/m0p414/otool-V10/image.txt'


def listing(path, lo=None, hi=None):
    """otool -tv rows: (address, op, args) per label (object) or in [lo, hi) (image)"""
    labels, rows, cur = [], [], None
    for l in open(path, errors='replace'):
        s = l.rstrip('\n')
        m = re.match(r'^(_?[A-Za-z_][\w.$]*):$', s)
        if m:
            cur = [m.group(1), []]
            labels.append(cur)
            continue
        m = re.match(r'^([0-9a-f]{8})\s+(\S+)\s*(.*)$', s)
        if m:
            a = int(m.group(1), 16)
            if lo is None:
                if cur:
                    cur[1].append((a, m.group(2), m.group(3)))
            elif lo <= a < hi:
                rows.append((a, m.group(2), m.group(3)))
    return [x for x in labels if x[1]] if lo is None else rows


def norm(r):
    return r[1] + ' ' + re.sub(r'0x[0-9a-f]+', 'N', r[2])


def cmd_funcs(spec, rid, odir, outj):
    import macho_obj
    s = load(spec)
    rows = [l.split('\t') for l in open(INV).read().split('\n') if l and not l.startswith('#')]
    inv = {r[0]: dict(zip(rows[0], r)) for r in rows[1:]}
    fun = [l.split('\t') for l in open(FUNCS).read().split('\n') if l and not l.startswith('#')][1:]
    out = []
    for o in s['objects']:
        lo, hi, ids = span(inv, o['m4_id'])
        if 'm4_id_alt' in o:                  # compare functions over both hypotheses
            alo, ahi, _ = span(inv, o['m4_id_alt'])
            lo, hi = min(lo, alo), max(hi, ahi)
        img = listing(IMGLIST, lo, hi)
        es = entries(fun, lo, hi)[2]
        for v in sorted(o['variants']):
            lp = os.path.join(odir, '%s_%s.txt' % (o['name'], v))
            p = os.path.join('08_build/runs', rid, 'stage', 'Q%d__%s_%s.o' % (s['plan'], o['name'], v))
            if not os.path.exists(lp):
                out.append(dict(object=o['name'], variant=v, listing=None))
                continue
            b = macho_obj.parse(open(p, 'rb').read())
            extn = {y['name'] for y in b['symbols'] if y['kind'] == 'SECT' and y['ext'] and not y['stab']}
            ol = {n: ins for n, ins in listing(lp)}
            used, fr = set(), []
            for e in es:
                a0, a1 = int(e[0], 16), int(e[1], 16)
                oi = [norm(r) for r in img if a0 <= r[0] < a1]
                names = [n for n in e[3].split(',') if n]
                hit = next((n for n in names if n in ol), None)
                row = dict(entry=e[0], bytes=int(e[2]), names=names, original_insns=len(oi))
                if hit:
                    used.add(hit)
                    ni = [norm(r) for r in ol[hit]]
                    row.update(object_label=hit, object_insns=len(ni), same_masked=ni == oi, object_external=hit in extn)
                fr.append(row)
            out.append(dict(object=o['name'], variant=v, listing=lp, listing_sha256=sha(lp), range=[hex(lo), hex(hi)],
                            functions=fr, same=sum(1 for f_ in fr if f_.get('same_masked')),
                            unpaired_original=[f_['entry'] for f_ in fr if 'object_label' not in f_],
                            unpaired_object=sorted(set(ol) - used)))
    json.dump(dict(plan=s['plan'], tool_sha256=sha(os.path.abspath(__file__)), image_listing=IMGLIST, image_listing_sha256=sha(IMGLIST),
                   run=rid, objects=out), open(outj, 'w'), indent=1)
    for x in out:
        print(x['object'], x['variant'], 'functions', len(x.get('functions', [])), 'same', x.get('same'), 'unpaired original', len(x.get('unpaired_original', [])),
              'unpaired object', x.get('unpaired_object'))


if __name__ == '__main__':
    a = sys.argv[1:]
    {'stage': cmd_stage, 'cmd': cmd_cmd, 'compare': cmd_compare, 'funcs': cmd_funcs}[a[0]](*a[1:])
