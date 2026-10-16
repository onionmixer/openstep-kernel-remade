#!/usr/bin/env python3
"""m5_m68k_final.py -- plan 471 (M5-28): final compile and acceptance of m68k objects changed in 07
(main file or m68k overlay), against the chosen variant objects.

  python3 10_tools/reconstruction/m5_m68k_final.py cmd SPEC.json CC.cmd
  python3 10_tools/reconstruction/m5_m68k_final.py check SPEC.json RUN_ID RECORD.json

SPEC.json: {"plan": 471,
  "objects": [{"name": "kern_exit", "object": "x86-kern_exit", "rel": "bsd/kern/kern_exit.c",
               "ref": "<chosen variant object>", "ref_sha256": "...", "reasons": []}, ...],
  "bss_records": [<earlier zerofill records whose summary.candidates must not overlap>]}
cmd    per object the single compile line of src/src/<rel> (m5_m68k_srcvar.cc_line: plan 430 cc.cmd or
       the plan 429 run) with only the output replaced by stage/F<plan>__<name>.o.
check  asserts: every command status 0 and every object present; per object the REF hash, equality
       with REF in m3_m68k_diag.canon, Mach-O header, section headers and non-STABS symbols
       (l2_prefix_diff.obj_sig), L1 (--place-from-image) reasons exactly "reasons" (OBJECT_MATCH when
       empty), no undefined symbol missing from the original; for the objects whose reasons are
       ['__DATA,__bss: unverified'] one m5_m68k_zerofill.py objs run (it also checks the plan 464
       candidates) and no overlap (half-open) with the candidates of bss_records.
"""
import sys, os, json, hashlib, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
BSS = ['__DATA,__bss: unverified']


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def load(spec):
    s = json.load(open(spec))
    assert set(s) == {'plan', 'objects', 'bss_records'}, sorted(s)
    for o in s['objects']:
        assert set(o) == {'name', 'object', 'rel', 'ref', 'ref_sha256', 'reasons'}, sorted(o)
        assert o['reasons'] in ([], BSS), o['reasons']
    return s


def cmd_cmd(spec, out):
    import m5_m68k_srcvar as SV
    s = load(spec)
    L, E = [], []
    for o in s['objects']:
        w = SV.cc_line({'rel': o['rel']}).split()
        assert w[w.index('-c') + 1] == 'src/src/' + o['rel'], o['rel']
        w[w.index('-o') + 1] = 'stage/F%d__%s.o' % (s['plan'], o['name'])
        L.append(' '.join(w))
        E.append('EXPECT F%d__%s.o' % (s['plan'], o['name']))
    open(out, 'w').write('# m5p%d: plan %d final compile (m5_m68k_final.py cmd)\n' % (s['plan'], s['plan']) + '\n'.join(L + E) + '\n')
    print('commands', len(L))


def cmd_check(spec, rid, outj):
    import macho_obj
    import m0_m68k_cause as C
    import m3_m68k_diag as D
    import l2_prefix_diff as PD
    s = load(spec)
    P = s['plan']
    st = dict(l.split() for l in open(os.path.join('08_build/runs', rid, 'out', '_log', 'status')) if l.strip())
    assert len(st) == len(s['objects']) and all(v == '0' for v in st.values()), st
    art = '08_build/artifacts/m5p%d/%s' % (P, rid)
    os.makedirs(art, exist_ok=True)
    img = C.Img()
    names = {y['name'] for y in img.img.o['symbols']}
    rows, bss = [], []
    for o in s['objects']:
        p = os.path.join('08_build/runs', rid, 'out', 'F%d__%s.o' % (P, o['name']))
        assert os.path.exists(p), p
        assert sha(o['ref']) == o['ref_sha256'], o['ref']
        ga, gb = PD.obj_sig(p), PD.obj_sig(o['ref'])
        eq = dict(canon=D.canon(p) == D.canon(o['ref']), header=ga['header'] == gb['header'],
                  sections=ga['sections'] == gb['sections'], symbols=ga['symbols'] == gb['symbols'])
        d = C.run_l1(p, os.path.join(art, 'l1-%s.json' % o['object']))
        b = macho_obj.parse(open(p, 'rb').read())
        undef = sorted({y['name'] for y in b['symbols'] if y['kind'] == 'UNDF' and not y['stab']} - names)
        reasons = d.get('object_reasons') or []
        r = dict(object=o['object'], obj=p, obj_sha256=sha(p), ref=o['ref'], ref_sha256=o['ref_sha256'], ref_equal=eq,
                 l1_verdict=d['object_verdict'], l1_reasons=reasons, expected_reasons=o['reasons'],
                 undefined_not_in_original=undef)
        r['ok'] = (all(eq.values()) and reasons == o['reasons'] and not undef
                   and (d['object_verdict'] == 'OBJECT_MATCH') == (o['reasons'] == []))
        rows.append(r)
        if o['reasons'] == BSS:
            bss.append('%s:%s:%s' % (o['object'], p, o['ref']))
    z = None
    if bss:
        zj = os.path.join(art, 'zerofill-objs.json')
        q = subprocess.run([sys.executable, os.path.join(HERE, 'm5_m68k_zerofill.py'), 'objs', os.path.join(art, 'zerofill'), zj,
                            str(P)] + bss, capture_output=True, text=True)
        zr = json.load(open(zj)) if os.path.exists(zj) else {}
        cand = (zr.get('summary') or {}).get('candidates', {})
        prev = []
        for f in s['bss_records']:
            for n, (lo, hi) in json.load(open(f))['summary']['candidates'].items():
                prev.append((int(lo, 16), int(hi, 16), n, f))
        ov = [[n, m] for n, (lo, hi) in cand.items() for a, e, m, f in prev if int(lo, 16) < e and a < int(hi, 16)]
        z = dict(returncode=q.returncode, record=zj, record_sha256=sha(zj) if os.path.exists(zj) else None,
                 candidates=cand, overlaps_earlier=ov, earlier=[[f, sha(f)] for f in s['bss_records']],
                 ok=(q.returncode == 0 and len(cand) == len(bss) and not ov))
    S = dict(ok=[r['object'] for r in rows if r['ok']], not_ok=[r['object'] for r in rows if not r['ok']],
             zerofill_ok=None if z is None else z['ok'])
    json.dump(dict(plan=P, tool='10_tools/reconstruction/m5_m68k_final.py', tool_sha256=sha(os.path.abspath(__file__)),
                   run=rid, spec_sha256=sha(spec), summary=S, objects=rows, zerofill=z), open(outj, 'w'), indent=1)
    print(json.dumps(dict(summary=S, objects=[{k: r[k] for k in ('object', 'ref_equal', 'l1_verdict', 'l1_reasons', 'ok')} for r in rows],
                          zerofill=z), indent=1))
    assert not S['not_ok'] and S['zerofill_ok'] in (None, True), 'plan %d final check failed' % P


def main():
    a = sys.argv[1:]
    if a[:1] == ['cmd'] and len(a) == 3:
        cmd_cmd(a[1], a[2])
    elif a[:1] == ['check'] and len(a) == 4:
        cmd_check(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
