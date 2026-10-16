#!/usr/bin/env python3
"""m5_m68k_nsq.py -- plan 468 (M5-25): m68k kern/ns_timer.c callout queue (ns_callout_init,
ns_timer_init, the static timer handler, ns_timeout, ns_abstimeout, ns_untimeout, ns_sleep);
source-form variants and the acceptance check of the 07 overlay object.

  python3 10_tools/reconstruction/m5_m68k_nsq.py stage SPEC.json STAGE_DIR
  python3 10_tools/reconstruction/m5_m68k_nsq.py cmd SPEC.json CC.cmd
  python3 10_tools/reconstruction/m5_m68k_nsq.py compare SPEC.json RUN_ID RECORD.json
  python3 10_tools/reconstruction/m5_m68k_nsq.py cmdf CC.cmd
  python3 10_tools/reconstruction/m5_m68k_nsq.py final RUN_ID REF.o RECORD.json

SPEC.json (under the ignored 08_build/artifacts): {"plan": 468, "common": [[old, new], ...],
  "variants": {"N": [], "H2": [[old, new]], ...}}.  A variant text is the 07 main file
  07_kernel/src/kern/ns_timer.c with the common replacements (each old text exactly once in the
  main file, ranges not overlapping), then the variant replacements (each old text exactly once
  in that result).  Variant R is reserved: the plan 448 V1 text (m5_m68k_ns.variant_text(':')),
  whose object must equal 08_build/runs/m5p448-var1/out/P448__V1.o (control).
stage    BASE copy after checking its manifest (path set and SHA-256) + src/kern/q468_<V>.c.
cmd      the single cc.cmd compile line of kern/ns_timer.c, source and output replaced
         (stage/Q468__<V>.o); cmdf: the same line with only the output replaced
         (stage/F468__ns_timer.o, the 07 overlay source of a stage_m68k.py stage).
compare  per variant: run status, SHA-256, L1 (--place-from-image) verdict and reasons, L1 with
         the text placed at the original object start (--place __TEXT,__text=0x404e3a8):
         verdicts of the queue functions, external spans of the 19 original external
         functions (m0_m68k_cause.compare_object), undefined symbols not in the original, COMMON
         symbols (name, size), external text definitions, local text symbols, canon groups.
         A candidate passes when (plan 468.1) all 19 names are present, the seven queue spans
         are equal, the eight queue functions are L1 MATCH, no undefined symbol is missing
         from the original, COMMON is exactly COMMON and the external text definitions are the
         19 names.  R passes when it equals P448__V1.o (canon, Mach-O header, section headers,
         non-STABS symbols).
final    the overlay object (RUN_ID/out/F468__ns_timer.o) must pass the candidate check and
         equal REF.o (the chosen variant object) in canon, Mach-O header, section headers and
         non-STABS symbols; asserted.
"""
import sys, os, json, glob, shutil, hashlib, subprocess, csv

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

PLAN = 468
BASE = '08_build/runs/tools/m0p467-a1-stage'
CC = '08_build/artifacts/m3p430/cc.cmd'
REL = 'kern/ns_timer.c'
IMG = '03_original/m68k/binaries/mach_kernel'
SYMS = '03_original/m68k/inventory/symbols.tsv'
LO, HI = 0x404e3a8, 0x404eaae              # original object [start, end)
P448 = '08_build/runs/m5p448-var1/out/P448__V1.o'
QUEUE = ['_ns_callout_init', '_ns_timer_init', '_ns_hardclock_init', '_ns_timeout', '_ns_abstimeout',
         '_ns_untimeout', '_ns_sleep']
HANDLER = '_ns_timer_int'                  # the static timer handler (original 0x404e458, no name)
COMMON = {'_hardclock_pc': 4, '_hardclock_ps': 4, '_ns_callfree': 4, '_ns_callout': 4, '_ns_calltodo': 24,
          '_ns_per_tick': 8,
          '_master_cpu': 4}                # kern/cpu_number.h tentative definition (plan 400), in 97 of the 207 objects


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def names19():
    """external __text symbols of the original object, in address order (symbols.tsv, section 1)."""
    rows = [r for r in csv.DictReader(open(SYMS), delimiter='\t')
            if r['section'] == '1' and LO <= int(r['value'], 16) < HI]
    out = [r['name'] for r in sorted(rows, key=lambda r: int(r['value'], 16))]
    assert len(out) == 19 and out[0] == '_ns_callout_init' and out[-1] == '_us_untimeout', out
    return out


def load(spec):
    s = json.load(open(spec))
    assert s['plan'] == PLAN and set(s) == {'plan', 'common', 'variants'}, sorted(s)
    assert 'R' not in s['variants']
    for v in s['variants']:
        assert v.replace('_', '').isalnum(), v
    return s


def apply(t, pairs, what):
    spans = []
    for old, new in pairs:
        assert t.count(old) == 1, (what, old[:60])
        i = t.index(old)
        spans.append((i, i + len(old), new))
    spans.sort()
    for a, b in zip(spans, spans[1:]):
        assert a[1] <= b[0], ('overlapping replacements', what)
    for i, j, new in reversed(spans):
        t = t[:i] + new + t[j:]
    return t


def variant_text(s, v):
    if v == 'R':
        import m5_m68k_ns
        return m5_m68k_ns.variant_text(':')
    t = apply(open('07_kernel/src/' + REL).read(), s['common'], 'common')
    return apply(t, s['variants'][v], v)


def vnames(s):
    return sorted(s['variants']) + ['R']


def cmd_stage(spec, stage):
    s = load(spec)
    m = json.load(open(BASE + '.manifest.json'))
    listed = set()
    for e in m['files']:
        assert sha(os.path.join(BASE, e[0])) == e[2], e[0]
        listed.add(e[0])
    found = {os.path.relpath(os.path.join(r, f), BASE) for r, _, fs in os.walk(BASE) for f in fs}
    assert found == listed, sorted(found ^ listed)[:5]
    assert not os.path.exists(stage)
    shutil.copytree(BASE, stage, symlinks=True)
    files = [list(e[:3]) for e in m['files']]
    for v in vnames(s):
        p = os.path.join(stage, 'src', 'kern', 'q%d_%s.c' % (PLAN, v))
        assert not os.path.exists(p)
        open(p, 'w').write(variant_text(s, v))
        files.append([os.path.relpath(p, stage), 'plan %d variant %s' % (PLAN, v), sha(p)])
    json.dump(dict(plan=PLAN, base=BASE, base_manifest_sha256=sha(BASE + '.manifest.json'), spec_sha256=sha(spec),
                   files=files), open(stage + '.manifest.json', 'w'), indent=1)
    print('stage', stage, 'files', len(files))


def cc_line():
    hits = [l.rstrip('\n') for l in open(CC) if l.startswith('RUN ') and ' src/src/%s ' % REL in l]
    assert len(hits) == 1, len(hits)
    return hits[0]


def cmd_cmd(spec, out):
    s = load(spec)
    L, E = [], []
    for v in vnames(s):
        w = cc_line().split()
        w[w.index('-c') + 1] = 'src/src/kern/q%d_%s.c' % (PLAN, v)
        w[w.index('-o') + 1] = 'stage/Q%d__%s.o' % (PLAN, v)
        L.append(' '.join(w))
        E.append('EXPECT Q%d__%s.o' % (PLAN, v))
    open(out, 'w').write('# m5p%d: plan %d ns_timer callout queue variants (m5_m68k_nsq.py cmd)\n' % (PLAN, PLAN)
                         + '\n'.join(L + E) + '\n')
    print('commands', len(L))


def cmd_cmdf(out):
    w = cc_line().split()
    assert w[w.index('-c') + 1] == 'src/src/' + REL
    w[w.index('-o') + 1] = 'stage/F%d__ns_timer.o' % PLAN
    open(out, 'w').write('# m5p%d: plan %d final compile of the ns_timer overlay (m5_m68k_nsq.py cmdf)\n' % (PLAN, PLAN)
                         + ' '.join(w) + '\nEXPECT F%d__ns_timer.o\n' % PLAN)
    print('commands', 1)


def l1(p, out, place=None):
    cmd = [sys.executable, os.path.join(HERE, 'l1_compare.py'), '--image', IMG, '--obj', p, '--out', out]
    cmd += ['--place', '__TEXT,__text=%#x' % place] if place else ['--place-from-image']
    r = subprocess.run(cmd, capture_output=True, text=True)
    assert r.returncode == 0 and os.path.exists(out), (p, r.stderr[-800:])
    d = json.load(open(out))
    assert d['inputs'][p] == sha(p)
    return d


def sig(p):
    import l2_prefix_diff as PD
    import m3_m68k_diag as D
    g = PD.obj_sig(p)
    return dict(canon=D.canon(p), header=g['header'], sections=g['sections'], symbols=g['symbols'])


def check(img, p, art, tag):
    """the plan 468.1 candidate check of one object."""
    import macho_obj
    import m0_m68k_cause as C
    N = names19()
    names = {y['name'] for y in img.img.o['symbols']}
    d = l1(p, os.path.join(art, 'l1-%s.json' % tag))
    dp = l1(p, os.path.join(art, 'l1place-%s.json' % tag), LO)
    fv = {}
    for f in dp['functions']:
        if f['section'] == '__TEXT,__text':
            for n in f['names']:
                fv[n] = f['verdict']
    _, ts, spans = C.compare_object(img, p, N)
    sp = {x['name']: x.get('equal') for x in spans if 'image_address' in x}
    o = macho_obj.parse(open(p, 'rb').read())
    text = [s for s in o['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
    undef = sorted({y['name'] for y in o['symbols'] if y['kind'] == 'UNDF' and not y['stab']} - names)
    common = {y['name']: y['value'] for y in o['symbols'] if y['kind'] == 'COMMON'}
    extdef = sorted(y['name'] for y in o['symbols'] if y['kind'] == 'SECT' and y.get('ext') and not y['stab']
                    and y['sect'] == text['index'])
    local = sorted(y['name'] for y in o['symbols'] if y['kind'] == 'SECT' and not y.get('ext') and not y['stab']
                   and y['sect'] == text['index'])
    q8 = {n: fv.get(n) for n in QUEUE + [HANDLER]}
    r = dict(sha256=sha(p), l1_verdict=d['object_verdict'], l1_reasons=d.get('object_reasons'),
             l1place_verdict=dp['object_verdict'], l1place_queue=q8,
             l1place_other={n: v for n, v in sorted(fv.items()) if n not in q8},
             spans_present=sorted(sp), spans_missing=sorted(set(N) - set(sp)), spans=sp,
             queue_spans_differ=[n for n in QUEUE if sp.get(n) is not True],
             other_spans_differ=[n for n in N if n not in QUEUE and sp.get(n) is not True],
             undefined_not_in_original=undef, common=common, external_text=extdef, local_text=local)
    r['ok'] = (not r['spans_missing'] and not r['queue_spans_differ'] and all(v == 'MATCH' for v in q8.values())
               and not undef and common == COMMON and set(extdef) == set(N) and len(extdef) == len(N))
    return r


def cmd_compare(spec, rid, outj):
    import m0_m68k_cause as C
    s = load(spec)
    img = C.Img()
    art = '08_build/artifacts/m5p%d/%s' % (PLAN, rid)
    os.makedirs(art, exist_ok=True)
    status = {}
    stp = os.path.join('08_build/runs', rid, 'out', '_log', 'status')
    if os.path.exists(stp):
        status = dict(l.split() for l in open(stp) if l.strip())
    rows, sigs = [], {}
    for k, v in enumerate(vnames(s)):
        p = os.path.join('08_build/runs', rid, 'out', 'Q%d__%s.o' % (PLAN, v))
        if not os.path.exists(p):
            rows.append(dict(variant=v, missing=True, status=status.get('%02d' % k)))
            continue
        r = dict(variant=v, status=status.get('%02d' % k))
        sigs[v] = sig(p)
        if v == 'R':
            ref = sig(P448)
            r.update(sha256=sha(p), equals_p448=sigs[v] == ref,
                     equal_parts={x: sigs[v][x] == ref[x] for x in ref})
        else:
            r.update(check(img, p, art, v))
        rows.append(r)
    groups = []
    for v in sigs:
        for g in groups:
            if sigs[g[0]]['canon'] == sigs[v]['canon']:
                g.append(v)
                break
        else:
            groups.append([v])
    R = [r for r in rows if r['variant'] == 'R'][0]
    S = dict(control_equals_p448=R.get('equals_p448'), ok=[r['variant'] for r in rows if r.get('ok')],
             canon_groups=groups, missing=[r['variant'] for r in rows if r.get('missing')],
             failed=[r['variant'] for r in rows if r.get('status') not in ('0', None)],
             queue_spans_differ={r['variant']: r['queue_spans_differ'] for r in rows if 'queue_spans_differ' in r},
             l1place_queue_not_match={r['variant']: [n for n, x in r['l1place_queue'].items() if x != 'MATCH']
                                      for r in rows if 'l1place_queue' in r})
    json.dump(dict(plan=PLAN, tool='10_tools/reconstruction/m5_m68k_nsq.py', tool_sha256=sha(os.path.abspath(__file__)),
                   run=rid, spec_sha256=sha(spec), main_file='07_kernel/src/' + REL, main_sha256=sha('07_kernel/src/' + REL),
                   base=BASE, base_manifest_sha256=sha(BASE + '.manifest.json'),
                   compile_line_sha256=hashlib.sha256(cc_line().encode()).hexdigest(), control_ref=P448,
                   control_ref_sha256=sha(P448), image_sha256=sha(IMG), symbols_sha256=sha(SYMS), names=names19(),
                   summary=S, variants=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))


def cmd_final(rid, ref, outj):
    import m0_m68k_cause as C
    img = C.Img()
    p = os.path.join('08_build/runs', rid, 'out', 'F%d__ns_timer.o' % PLAN)
    art = '08_build/artifacts/m5p%d/%s' % (PLAN, rid)
    os.makedirs(art, exist_ok=True)
    r = check(img, p, art, 'F%d' % PLAN)
    a, b = sig(p), sig(ref)
    r['ref'], r['ref_sha256'] = ref, sha(ref)
    r['ref_equal'] = {x: a[x] == b[x] for x in a}
    json.dump(dict(plan=PLAN, tool='10_tools/reconstruction/m5_m68k_nsq.py', tool_sha256=sha(os.path.abspath(__file__)),
                   run=rid, obj=p, image_sha256=sha(IMG), symbols_sha256=sha(SYMS), names=names19(), result=r),
              open(outj, 'w'), indent=1)
    print(json.dumps({k: r[k] for k in ('ok', 'ref_equal', 'l1place_queue', 'queue_spans_differ', 'other_spans_differ',
                                        'undefined_not_in_original', 'common')}, indent=1))
    assert r['ok'] and all(r['ref_equal'].values()), 'plan 468 final check failed'


def main():
    a = sys.argv[1:]
    if a[:1] == ['stage'] and len(a) == 3:
        cmd_stage(a[1], a[2])
    elif a[:1] == ['cmd'] and len(a) == 3:
        cmd_cmd(a[1], a[2])
    elif a[:1] == ['compare'] and len(a) == 4:
        cmd_compare(*a[1:])
    elif a[:1] == ['cmdf'] and len(a) == 2:
        cmd_cmdf(a[1])
    elif a[:1] == ['final'] and len(a) == 4:
        cmd_final(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
