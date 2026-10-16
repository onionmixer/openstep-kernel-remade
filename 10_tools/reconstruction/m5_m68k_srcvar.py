#!/usr/bin/env python3
"""m5_m68k_srcvar.py -- plan 458 (M5-15): generic m68k source-form variant test for one 07 C file.

  python3 10_tools/reconstruction/m5_m68k_srcvar.py stage SPEC.json STAGE_DIR
  python3 10_tools/reconstruction/m5_m68k_srcvar.py cmd SPEC.json CC.cmd
  python3 10_tools/reconstruction/m5_m68k_srcvar.py compare SPEC.json RUN_ID RECORD.json

SPEC.json (kept under the ignored 08_build/artifacts, since variants may quote reference text):
  {"plan": 458, "rel": "bsd/netinet/in_pcb.c", "object": "x86-in_pcb",
   "base": "08_build/runs/tools/m0p457-a1-stage", "control": "K",
   "control_ref": "08_build/runs/m3p441-cc1/out/O441__L2_116__in_pcb.o",
   "variants": {"K": [], "D": [[old, new], ...], ...}}
  Each [old, new] replaces text of the 07 main file 07_kernel/src/<rel>; every old text must occur
  exactly once in the 07 main file and the replaced ranges must not overlap (all are located in the
  unmodified main file, then applied from the end).
  Optional key "source" (plan 469): the file whose text the replacements apply to instead of the 07
  main file (e.g. a 07_kernel/v183.34/m68k overlay); recorded with its SHA-256.

stage    copies the base staging after checking every manifest entry (path set and SHA-256), then
         writes src/<dir of rel>/p<plan>_<V>.c per variant; manifest beside the stage.
cmd      the single "-c" compile line of src/src/<rel> from plan 430 cc.cmd or the plan 429 run,
         with source and output replaced (P<plan>__<V>.o).
compare  per variant: object SHA-256, L1 verdict and reasons, external __text spans (relocations
         masked), undefined symbols not in the original, COMMON symbols, external defined symbols,
         and equal groups (non-STABS sections); the control variant must equal control_ref.
         The record keeps SHA-256 of the spec, the 07 main file, the base manifest, the compile
         line and this tool, but not the variant texts.
"""
import sys, os, json, shutil, hashlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

CCS = ['08_build/artifacts/m3p430/cc.cmd', '08_build/runs/m3p429-cc2/run.cmd']


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def shab(b):
    return hashlib.sha256(b).hexdigest()


def load(spec):
    s = json.load(open(spec))
    for k in ('plan', 'rel', 'object', 'base', 'control', 'control_ref', 'variants'):
        assert k in s, k
    assert s['control'] in s['variants'] and s['variants'][s['control']] == []
    for v in s['variants']:
        assert v.replace('_', '').isalnum(), v
    assert '..' not in s['rel'].split('/') and not s['rel'].startswith('/')
    return s


def source(s):
    """plan 469: the text the variants are made from (default: the 07 main file)."""
    return s.get('source', '07_kernel/src/' + s['rel'])


def variant_text(s, v):
    t = open(source(s)).read()
    spans = []
    for old, new in s['variants'][v]:
        assert t.count(old) == 1, (v, old[:60])
        i = t.index(old)
        spans.append((i, i + len(old), new))
    spans.sort()
    for a, b in zip(spans, spans[1:]):
        assert a[1] <= b[0], ('overlapping replacements', v)
    for i, j, new in reversed(spans):
        t = t[:i] + new + t[j:]
    return t


def vfile(s, v):
    return os.path.join(os.path.dirname(s['rel']), 'p%d_%s.c' % (s['plan'], v))


def cmd_stage(spec, stage):
    s = load(spec)
    base = s['base']
    m = json.load(open(base + '.manifest.json'))
    listed = set()
    for e in m['files']:
        assert sha(os.path.join(base, e[0])) == e[2], e[0]
        listed.add(e[0])
    found = set()
    for r, ds, fs in os.walk(base):
        for f in fs:
            found.add(os.path.relpath(os.path.join(r, f), base))
    assert found == listed, ('base staging differs from its manifest', sorted(found ^ listed)[:5])
    assert not os.path.exists(stage)
    shutil.copytree(base, stage, symlinks=True)
    files = [list(e[:3]) for e in m['files']]
    for v in sorted(s['variants']):
        p = os.path.join(stage, 'src', vfile(s, v))
        assert not os.path.exists(p)
        open(p, 'w').write(variant_text(s, v))
        files.append([os.path.relpath(p, stage), 'plan %d variant %s' % (s['plan'], v), sha(p)])
    json.dump(dict(plan=s['plan'], base=base, base_manifest_sha256=sha(base + '.manifest.json'), spec_sha256=sha(spec),
                   files=files), open(stage + '.manifest.json', 'w'), indent=1)
    print('stage', stage, 'files', len(files))


def cc_line(s):
    hits = []
    for c in CCS:
        for l in open(c):
            w = l.split()
            if l.startswith('RUN ') and ' src/src/%s ' % s['rel'] in l and '-c' in w and '-o' in w:
                hits.append(l.rstrip('\n'))
    assert len(hits) == 1, len(hits)
    return hits[0]


def cmd_cmd(spec, out):
    s = load(spec)
    line = cc_line(s)
    L, E = [], []
    for v in sorted(s['variants']):
        w = line.split()
        w[w.index('-c') + 1] = 'src/src/' + vfile(s, v)
        w[w.index('-o') + 1] = 'stage/P%d__%s.o' % (s['plan'], v)
        L.append(' '.join(w))
        E.append('EXPECT P%d__%s.o' % (s['plan'], v))
    open(out, 'w').write('# m5p%d: plan %d source-form variants of %s (m5_m68k_srcvar.py cmd)\n' % (s['plan'], s['plan'], s['rel'])
                         + '\n'.join(L + E) + '\n')
    print('commands', len(L))


def cmd_compare(spec, rid, outj):
    import macho_obj
    import m0_m68k_cause as C
    import m3_m68k_wide as W
    import m3_m68k_diag as D
    s = load(spec)
    img = C.Img()
    names = {y['name'] for y in img.img.o['symbols']}
    T = {t['object']: t for t in W.targets()}
    xo = macho_obj.parse(open(T[s['object']]['obj'], 'rb').read())
    xt = [x for x in xo['sections'] if (x['segname'], x['sectname']) == ('__TEXT', '__text')][0]
    ext = [y['name'] for y in xo['symbols'] if y['kind'] == 'SECT' and y.get('ext') and not y['stab'] and y['sect'] == xt['index']]
    art = '08_build/artifacts/m5p%d' % s['plan']
    os.makedirs(art, exist_ok=True)
    status = {}
    sp = os.path.join('08_build/runs', rid, 'out', '_log', 'status')
    if os.path.exists(sp):
        status = dict(l.split() for l in open(sp) if l.strip())
    rows, canon = [], {}
    for k, v in enumerate(sorted(s['variants'])):
        f = 'P%d__%s.o' % (s['plan'], v)
        p = os.path.join('08_build/runs', rid, 'out', f)
        if not os.path.exists(p):
            rows.append(dict(variant=v, object=f, missing=True, status=status.get('%02d' % k)))
            continue
        d = C.run_l1(p, os.path.join(art, 'l1-%s-%s.json' % (rid, v)))
        _, ts, spans = C.compare_object(img, p, ext)
        o = macho_obj.parse(open(p, 'rb').read())
        canon[v] = D.canon(p)
        rows.append(dict(variant=v, object=f, sha256=sha(p), status=status.get('%02d' % k), verdict=d['object_verdict'],
                         reasons=d.get('object_reasons'),
                         spans={x['name']: x.get('equal') for x in spans if 'image_address' in x},
                         undefined_not_in_original=sorted({y['name'] for y in o['symbols'] if y['kind'] == 'UNDF' and not y['stab']} - names),
                         common=sorted((y['name'], y.get('value')) for y in o['symbols'] if y['kind'] == 'COMMON'),
                         defined_external=sorted(y['name'] for y in o['symbols'] if y['kind'] == 'SECT' and y.get('ext') and not y['stab'])))
    groups = []
    for v in canon:
        for g in groups:
            if canon[g[0]] == canon[v]:
                g.append(v)
                break
        else:
            groups.append([v])
    ctl = s['control']
    control_ok = ctl in canon and canon[ctl] == D.canon(s['control_ref'])
    S = dict(control=ctl, control_equals_ref=control_ok,
             match=[r['variant'] for r in rows if r.get('verdict') == 'OBJECT_MATCH' and not r['undefined_not_in_original']],
             equal_groups=groups, missing=[r['variant'] for r in rows if r.get('missing')])
    json.dump(dict(plan=s['plan'], tool='10_tools/reconstruction/m5_m68k_srcvar.py', tool_sha256=sha(os.path.abspath(__file__)),
                   run=rid, spec_sha256=sha(spec), main_file='07_kernel/src/' + s['rel'], main_sha256=sha('07_kernel/src/' + s['rel']),
                   source=source(s), source_sha256=sha(source(s)), base=s['base'], base_manifest_sha256=sha(s['base'] + '.manifest.json'), compile_line_sha256=shab(cc_line(s).encode()),
                   control_ref=s['control_ref'], control_ref_sha256=sha(s['control_ref']), summary=S, variants=rows),
              open(outj, 'w'), indent=1)
    print(json.dumps(S))
    for r in rows:
        if r.get('missing'):
            print(r['variant'], 'missing', r['status'])
            continue
        print(r['variant'], r['status'], r['verdict'], 'differ', sorted(k for k, x in r['spans'].items() if not x),
              'undef', r['undefined_not_in_original'], 'common', r['common'])


def main():
    a = sys.argv[1:]
    if a[:1] == ['stage'] and len(a) == 3:
        cmd_stage(a[1], a[2])
    elif a[:1] == ['cmd'] and len(a) == 3:
        cmd_cmd(a[1], a[2])
    elif a[:1] == ['compare'] and len(a) == 4:
        cmd_compare(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
