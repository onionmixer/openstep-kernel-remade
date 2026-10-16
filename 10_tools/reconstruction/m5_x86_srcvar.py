#!/usr/bin/env python3
"""m5_x86_srcvar.py -- plan 467 (M5-24): x86 compile of the m5_m68k_srcvar.py variants of one 07 C
file, to see whether a form chosen for m68k keeps the x86 object (07 main-file candidates).

  python3 10_tools/reconstruction/m5_x86_srcvar.py stage SPEC.json STAGE_DIR
  python3 10_tools/reconstruction/m5_x86_srcvar.py cmd SPEC.json CC.cmd
  python3 10_tools/reconstruction/m5_x86_srcvar.py compare SPEC.json RUN_ID RECORD.json

The spec is the m5_m68k_srcvar.py spec (variant texts from m5_m68k_srcvar.variant_text); its m68k
base and control_ref are not used.  Instead:
  BASE    08_build/runs/tools/<X86>-g1a-stage (X86 = s6l5, the plan 466 rebuild), manifest-checked
  CMD     the single "RUN ... -c src/src/<rel> -o stage/L2_<row>__<name>.o" line of
          08_build/runs/tools/<X86>-g1a.cmd, input and output replaced (stage/X<plan>__<V>.o)
  REF     the rebuilt object of that line (08_build/runs/<X86>-g1a/out/L2_<row>__<name>.o), whose
          SHA-256 must equal the s6-l1 record of the rebuild
stage    copies BASE after checking every manifest entry (path set and SHA-256) and writes
         src/<dir of rel>/x<plan>_<V>.c per variant; manifest beside the stage.
compare  per variant: run status, object SHA-256, and against REF: m3_m68k_diag.canon (section
         bytes and relocations, external symbols by name), Mach-O header, section headers and
         all non-STABS symbols (l2_prefix_diff.obj_sig); the control variant must equal REF.
"""
import sys, os, json, glob, shutil, hashlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import m5_m68k_srcvar as SV

X86 = 's6l5'
BASE = '08_build/runs/tools/%s-g1a-stage' % X86
CMD = '08_build/runs/tools/%s-g1a.cmd' % X86


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def vfile(s, v):
    return os.path.join(os.path.dirname(s['rel']), 'x%d_%s.c' % (s['plan'], v))


def cc_line(s):
    hits = [l.rstrip('\n') for l in open(CMD) if l.startswith('RUN ') and ' -c src/src/%s ' % s['rel'] in l]
    assert len(hits) == 1, len(hits)
    return hits[0]


def ref_obj(s):
    w = cc_line(s).split()
    out = os.path.basename(w[w.index('-o') + 1])
    p = os.path.join('08_build/runs', '%s-g1a' % X86, 'out', out)
    recs = [x for f in glob.glob('09_validation/reconstruction/s6-l1-G1-%s-g1a.json' % X86)
            for x in json.load(open(f))['objects'] if x['obj'] == p]
    assert len(recs) == 1 and recs[0]['object'] == s['object'] and sha(p) == recs[0]['obj_sha256'], p
    return p


def cmd_stage(spec, stage):
    s = SV.load(spec)
    m = json.load(open(BASE + '.manifest.json'))
    listed = set()
    for e in m['files']:
        assert sha(os.path.join(BASE, e[0])) == e[2], e[0]
        listed.add(e[0])
    found = {os.path.relpath(os.path.join(r, f), BASE) for r, _, fs in os.walk(BASE) for f in fs}
    assert found == listed, sorted(found ^ listed)[:5]
    assert sha(os.path.join(BASE, 'src', s['rel'])) == sha('07_kernel/src/' + s['rel']), 'base differs from the 07 main file'
    assert not os.path.exists(stage)
    shutil.copytree(BASE, stage, symlinks=True)
    files = [list(e[:3]) for e in m['files']]
    for v in sorted(s['variants']):
        p = os.path.join(stage, 'src', vfile(s, v))
        assert not os.path.exists(p)
        open(p, 'w').write(SV.variant_text(s, v))
        files.append([os.path.relpath(p, stage), 'plan %d variant %s' % (s['plan'], v), sha(p)])
    json.dump(dict(plan=s['plan'], base=BASE, base_manifest_sha256=sha(BASE + '.manifest.json'), spec_sha256=sha(spec),
                   files=files), open(stage + '.manifest.json', 'w'), indent=1)
    print('stage', stage, 'files', len(files))


def cmd_cmd(spec, out):
    s = SV.load(spec)
    line = cc_line(s)
    L, E = [], []
    for v in sorted(s['variants']):
        w = line.split()
        w[w.index('-c') + 1] = 'src/src/' + vfile(s, v)
        w[w.index('-o') + 1] = 'stage/X%d__%s.o' % (s['plan'], v)
        L.append(' '.join(w))
        E.append('EXPECT X%d__%s.o' % (s['plan'], v))
    open(out, 'w').write('# m5p%d: plan %d x86 compile of the source-form variants of %s (m5_x86_srcvar.py cmd)\n'
                         % (s['plan'], s['plan'], s['rel']) + '\n'.join(L + E) + '\n')
    print('commands', len(L))


def cmd_compare(spec, rid, outj):
    import m3_m68k_diag as D
    import l2_prefix_diff as PD
    s = SV.load(spec)
    ref = ref_obj(s)
    cr, sr = D.canon(ref), PD.obj_sig(ref)
    status = {}
    sp = os.path.join('08_build/runs', rid, 'out', '_log', 'status')
    if os.path.exists(sp):
        status = dict(l.split() for l in open(sp) if l.strip())
    rows = []
    for k, v in enumerate(sorted(s['variants'])):
        p = os.path.join('08_build/runs', rid, 'out', 'X%d__%s.o' % (s['plan'], v))
        if not os.path.exists(p):
            rows.append(dict(variant=v, missing=True, status=status.get('%02d' % k)))
            continue
        sv = PD.obj_sig(p)
        rows.append(dict(variant=v, sha256=sha(p), status=status.get('%02d' % k), canon_equal=D.canon(p) == cr,
                         header_equal=sv['header'] == sr['header'], sections_equal=sv['sections'] == sr['sections'],
                         symbols_equal=sv['symbols'] == sr['symbols'], stabs=sv['stabs']))
    same = [r['variant'] for r in rows if not r.get('missing') and r['status'] == '0' and r['canon_equal']
            and r['header_equal'] and r['sections_equal'] and r['symbols_equal']]
    S = dict(control=s['control'], control_equals_ref=s['control'] in same, same_as_ref=same,
             missing=[r['variant'] for r in rows if r.get('missing')], failed=[r['variant'] for r in rows if r.get('status') not in ('0', None)])
    json.dump(dict(plan=s['plan'], tool='10_tools/reconstruction/m5_x86_srcvar.py', tool_sha256=sha(os.path.abspath(__file__)),
                   run=rid, spec_sha256=sha(spec), main_file='07_kernel/src/' + s['rel'], main_sha256=sha('07_kernel/src/' + s['rel']),
                   source=SV.source(s), source_sha256=sha(SV.source(s)), base=BASE, base_manifest_sha256=sha(BASE + '.manifest.json'), compile_line_sha256=hashlib.sha256(cc_line(s).encode()).hexdigest(),
                   ref=ref, ref_sha256=sha(ref), summary=S, variants=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S))
    for r in rows:
        print(r)


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
