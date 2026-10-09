#!/usr/bin/env python3
"""m0_slice_l1.py -- plan 409 (M0-1): L1 of the s6 rebuilt objects against the i386 mk-183.34
kernel (fat slice 1 of the OPENSTEP 4.2J universal /mach_kernel), with an x86 self-test.

  python3 10_tools/reconstruction/m0_slice_l1.py slice  WORKDIR SUMMARY.json
  python3 10_tools/reconstruction/m0_slice_l1.py selftest WORKDIR SUMMARY.json

Objects: the 402 objects of 09_validation/reconstruction/s6-l1-G*-s6l4-*.json (SHA-256
checked); the two libcc members are not among them.  Each object goes through
l1_compare.py --place-from-image (+ --place-from-objc for .m sources), the rule of
l2_baseline.py.
  slice     the slice is cut from 03_original/installation-media/os42j/binaries/
            mach_kernel.universal by its fat header and must hash to SLICE_SHA; it is
            written to WORKDIR (keep WORKDIR out of the tracked tree).  The explicit
            __const placements of l2_expect-s6p398.json are x86 addresses and are NOT used.
  selftest  the x86 original, with the explicit placements of l2_expect-s6p398.json
            (as l2_rebuild.py does); verdict and reasons must equal the recorded s6l4 L1 of
            every object.
Grades are those of the current 06_reconstruction tables.  Function counts and bytes
cover __TEXT,__text only (l1_compare also lists __TEXT,__const ranges as functions).
An OBJECT_MATCH means the recorded rebuilt object passes this comparison in the
image; it does not establish the original object file, flags, headers or compiler.
Read-only apart from WORKDIR and SUMMARY.
"""
import sys, os, glob, json, hashlib, struct, subprocess, collections

UNIVERSAL = '03_original/installation-media/os42j/binaries/mach_kernel.universal'
UNIVERSAL_SHA = 'f3b57f877218adf9e0814f69c5494aca74e7c7b4e9dbd395156cce78d62de148'
SLICE_SHA = 'cb6217c2f454c07b4eb8d6a98850cb2e3bb9cadac477449ea1ad17999bcdf78f'
X86 = '03_original/x86/binaries/mach_kernel'
X86_SHA = '33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890'
GROUPS = '09_validation/reconstruction/s6-l1-G*-s6l4-*.json'
EXPECT = '06_reconstruction/l2_expect-s6p398.json'
TABLES = {'objects_confirmed': '06_reconstruction/objects_confirmed.tsv',
          'objects_partial': '06_reconstruction/objects_partial.tsv',
          'objects_data': '06_reconstruction/objects_data.tsv'}
TEXT = '__TEXT,__text'


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def cut_slice(workdir):
    u = open(UNIVERSAL, 'rb').read()
    assert hashlib.sha256(u).hexdigest() == UNIVERSAL_SHA
    magic, n = struct.unpack('>II', u[:8])
    assert magic == 0xcafebabe and n == 3, (hex(magic), n)
    cpu, sub, off, size, align = struct.unpack('>5I', u[8 + 20:8 + 40])
    assert cpu == 7, cpu
    s = u[off:off + size]
    assert hashlib.sha256(s).hexdigest() == SLICE_SHA
    p = os.path.join(workdir, 'mach_kernel.i386-mk-183.34')
    open(p, 'wb').write(s)
    assert sha(p) == SLICE_SHA
    return p, dict(universal=UNIVERSAL, universal_sha256=UNIVERSAL_SHA, fat_index=1, cputype=cpu,
                   cpusubtype=sub, offset=off, size=size, sha256=SLICE_SHA)


def grades():
    g = {}
    for t, p in TABLES.items():
        lines = open(p).read().split('\n')
        hdr = lines[0].split('\t')
        ig, isrc = hdr.index('grade'), hdr.index('source')
        for l in lines[1:]:
            if l:
                r = l.split('\t')
                k = (r[0], r[isrc].split()[0])     # object IDs are not unique (two x86-memcpy)
                assert k not in g, k
                g[k] = (t, r[ig])
    return g


def main():
    mode, workdir, summ = sys.argv[1:4]
    assert mode in ('slice', 'selftest')
    os.makedirs(workdir, exist_ok=True)
    if mode == 'slice':
        img, imgrec = cut_slice(workdir)
    else:
        img = X86
        assert sha(img) == X86_SHA
        imgrec = dict(path=X86, sha256=X86_SHA)
    exp = json.load(open(EXPECT))['expect']
    gr = grades()
    objs = []
    for f in sorted(glob.glob(GROUPS)):
        for o in json.load(open(f))['objects']:
            objs.append((f, o))
    assert len(objs) == 402 and len({o['n'] for _, o in objs}) == 402
    assert {(o['object'], o['source']) for _, o in objs} == set(gr)
    rows = []
    for f, o in objs:
        assert sha(o['obj']) == o['obj_sha256'], o['object']
        place = []
        ex = exp.get(str(o['n']))
        if ex is not None:
            assert ex['object'] == o['object'], (o['n'], ex['object'], o['object'])
        if mode == 'selftest':
            for k, v in sorted((ex or {}).get('place', {}).items()):
                place += ['--place', '%s=%s' % (k, v)]
        objc = o['source'].endswith('.m')
        out = os.path.join(workdir, '%s-%03d-%s.json' % (mode, o['n'], o['object']))
        cmd = [sys.executable, '10_tools/reconstruction/l1_compare.py', '--image', img, '--obj', o['obj'],
               '--place-from-image'] + (['--place-from-objc'] if objc else []) + place + ['--out', out]
        p = subprocess.run(cmd, capture_output=True, text=True)
        assert p.returncode == 0 and os.path.exists(out), (o['object'], p.stderr[-500:])
        d = json.load(open(out))
        assert d['inputs'] == {img: sha(img), o['obj']: o['obj_sha256']}
        fc, fb = collections.Counter(), collections.Counter()
        for fn in d['functions']:
            if fn['section'] == TEXT:
                fc[fn['verdict']] += 1
                fb[fn['verdict']] += fn['object_range'][1] - fn['object_range'][0]
        sec = d['sections'].get(TEXT)
        t, g = gr[(o['object'], o['source'])]
        r = dict(n=o['n'], object=o['object'], table=t, grade=g, source=o['source'],
                 objc=objc, obj=o['obj'], obj_sha256=o['obj_sha256'], explicit_place=place,
                 verdict=d['object_verdict'], reasons=d['object_reasons'],
                 text_size=sec['size'] if sec else 0,
                 text_placement=sec['placement'] if sec else None,
                 text_address=d['placements'].get(TEXT),
                 func_count=dict(fc), func_bytes=dict(fb),
                 detail=out, detail_sha256=sha(out))
        if objc:
            m = d.get('methods') or {}
            r['objc_info'] = dict(methods=m.get('methods'), placed=m.get('placed'), missing=len(m.get('missing', [])),
                             ambiguous=len(m.get('ambiguous', [])), records=m.get('records'))
        if mode == 'selftest':
            old = json.load(open(o['l1']))
            r['recorded'] = dict(l1=o['l1'], verdict=old['object_verdict'], reasons=old['object_reasons'])
            r['selftest_ok'] = (old['object_verdict'] == d['object_verdict']
                                and sorted(old['object_reasons']) == sorted(d['object_reasons']))
        rows.append(r)
    # aggregation (python; every figure below is derived from rows)
    S = {}
    S['objects'] = len(rows)
    S['verdict'] = dict(collections.Counter(r['verdict'] for r in rows))
    S['verdict_by_grade'] = {g: dict(collections.Counter(r['verdict'] for r in rows if r['grade'] == g))
                             for g in sorted({r['grade'] for r in rows})}
    S['verdict_objc'] = {('objc' if k else 'not_objc'): dict(collections.Counter(r['verdict'] for r in rows if r['objc'] is k))
                         for k in (False, True)}
    S['objc_records'] = dict(collections.Counter(
        ((r['objc_info']['records'] or {}).get('error') or 'placed').split(' ')[0] for r in rows if r['objc']))
    withtext = [r for r in rows if r['text_size']]
    S['objects_with_text'] = len(withtext)
    S['text_placement'] = dict(collections.Counter(r['text_placement'] for r in withtext))
    S['text_bytes_total'] = sum(r['text_size'] for r in withtext)
    S['text_bytes_placed'] = sum(r['text_size'] for r in withtext if r['text_address'] is not None)
    S['text_bytes_unplaced'] = S['text_bytes_total'] - S['text_bytes_placed']
    fc, fb = collections.Counter(), collections.Counter()
    for r in rows:
        fc.update(r['func_count'])
        fb.update(r['func_bytes'])
    S['functions'] = dict(fc)
    S['function_bytes'] = dict(fb)
    kinds = collections.Counter()
    for r in rows:
        for x in r['reasons']:
            kinds['refs differ/unverified' if 'refs differ' in x else
                  x.split(': ', 1)[1] if ': ' in x else x] += 1
    S['reason_kinds'] = dict(kinds)
    S['all_text_functions_match'] = sum(1 for r in withtext if r['text_address'] is not None
                                        and set(r['func_count']) == {'MATCH'})
    bydir = collections.defaultdict(collections.Counter)
    for r in rows:
        parts = r['source'].split()[0].split('/')
        dk = '/'.join(parts[2:4]) if len(parts) > 4 else '/'.join(parts[2:3])
        bydir[dk][r['verdict']] += 1
    S['verdict_by_dir'] = {k: dict(v) for k, v in sorted(bydir.items())}
    if mode == 'selftest':
        S['selftest_ok'] = sum(1 for r in rows if r['selftest_ok'])
        S['selftest_failed'] = [r['object'] for r in rows if not r['selftest_ok']]
    res = dict(plan=409, mode=mode, tool='10_tools/reconstruction/m0_slice_l1.py', image=imgrec,
               l1_compare_sha256=sha('10_tools/reconstruction/l1_compare.py'),
               expect=EXPECT, expect_sha256=sha(EXPECT), summary=S, objects=rows)
    open(summ, 'w').write(json.dumps(res, indent=1) + '\n')
    print(json.dumps(S, indent=1))


if __name__ == '__main__':
    main()
