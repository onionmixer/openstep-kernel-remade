#!/usr/bin/env python3
"""m5_m68k_zerofill.py -- plan 464 (M5-21): zerofill_check.py on m68k objects whose __text is
verified, and the x86 regression gate for the plan 464 change of zerofill_check.py.

  python3 10_tools/reconstruction/m5_m68k_zerofill.py x86replay OUTDIR RECORD.json
  python3 10_tools/reconstruction/m5_m68k_zerofill.py m68k OUTDIR RECORD.json

x86replay  re-runs every 09_validation/reconstruction/*zerofill-check*.json with its recorded
           command (input SHA-256 checked first), writing to OUTDIR instead of the recorded --out,
           and compares the fields listed in FIELDS (absent in both = equal).
m68k       for each object in OBJECTS: the plan 441 object (by SHA-256 from the plan 441 record),
           l1_compare.py --place-from-image to OUTDIR, then zerofill_check.py --section
           __DATA,__bss --place-from-l1 with the m68k symbol table; candidate ranges must not
           overlap each other.
"""
import sys, os, json, glob, hashlib, shlex, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
IMG = '03_original/m68k/binaries/mach_kernel'
SYMS = '03_original/m68k/inventory/symbols.tsv'
P441 = '09_validation/reconstruction/m3-m68k-need-ast-20261009.json'
RUN441 = '08_build/runs/m3p441-cc1/out'
OBJECTS = ['xdr', 'in', 'if_ether', 'tty_pty', 'svc', 'spec_vfsops', 'ip_input', 'kern_notify', 'kernel_stack', 'vfs',
           'pmap_kgetport', 'ux_exception', 'power', 'vnode_pager', 'nfs_vnodeops', 'vol']
FIELDS = ['conclusion', 'candidate', 'distinct_deltas', 'references', 'checks', 'negative_check', 'records', 'problems',
          'section', 'source_section_deltas', 'delta_source', 'base_offsets', 'field_target_offsets', 'scattered_addends']


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def x86replay(outdir, outj):
    os.makedirs(outdir, exist_ok=True)
    rows = []
    for f in sorted(glob.glob('09_validation/reconstruction/*zerofill-check*.json')):
        d = json.load(open(f))
        bad = [p for p, h in d['inputs'].items() if not os.path.exists(p) or sha(p) != h]
        if bad:
            rows.append(dict(record=f, error='input missing or changed', inputs=bad))
            continue
        argv = shlex.split(d['command'])
        assert argv[0].endswith('zerofill_check.py'), argv[0]
        i = argv.index('--out')
        new = os.path.join(outdir, os.path.basename(f))
        argv = [sys.executable, os.path.join(HERE, 'zerofill_check.py')] + argv[1:i] + ['--out', new] + argv[i + 2:]
        p = subprocess.run(argv, capture_output=True, text=True)
        if p.returncode != 0 or not os.path.exists(new):
            rows.append(dict(record=f, error='run failed', stderr=p.stderr[-400:]))
            continue
        e = json.load(open(new))
        diff = [k for k in FIELDS if d.get(k) != e.get(k)]
        rows.append(dict(record=f, record_sha256=sha(f), replay=new, replay_sha256=sha(new), differing_fields=diff,
                         conclusion=e.get('conclusion')))
    S = dict(records=len(rows), same=sum(1 for r in rows if r.get('differing_fields') == []),
             errors=[r['record'] for r in rows if 'error' in r],
             differ=[(r['record'], r['differing_fields']) for r in rows if r.get('differing_fields')])
    json.dump(dict(plan=464, tool='10_tools/reconstruction/m5_m68k_zerofill.py', tool_sha256=sha(os.path.abspath(__file__)),
                   zerofill_check_sha256=sha(os.path.join(HERE, 'zerofill_check.py')), fields=FIELDS, summary=S, rows=rows),
              open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))


def m68k(outdir, outj):
    os.makedirs(outdir, exist_ok=True)
    rec = json.load(open(P441))
    bysha = {sha(p): p for p in glob.glob(os.path.join(RUN441, '*.o'))}
    O = {o['object']: o for o in rec['objects']}
    rows = []
    for n in OBJECTS:
        o = O['x86-' + n]
        obj = bysha[o['sha256']]
        l1 = os.path.join(outdir, 'l1-%s.json' % n)
        subprocess.run([sys.executable, os.path.join(HERE, 'l1_compare.py'), '--image', IMG, '--obj', obj, '--place-from-image',
                        '--out', l1], capture_output=True, check=True)
        z = os.path.join(outdir, 'zerofill-%s.json' % n)
        p = subprocess.run([sys.executable, os.path.join(HERE, 'zerofill_check.py'), '--image', IMG, '--obj', obj,
                            '--section', '__DATA,__bss', '--symbols', SYMS, '--place-from-l1', l1, '--out', z],
                           capture_output=True, text=True)
        e = json.load(open(z)) if os.path.exists(z) else {}
        l1d = json.load(open(l1))
        rows.append(dict(object='x86-' + n, obj=obj, obj_sha256=sha(obj), l1=l1, l1_verdict=l1d['object_verdict'],
                         l1_reasons=l1d.get('object_reasons'), zerofill=z, zerofill_sha256=sha(z) if e else None,
                         returncode=p.returncode, conclusion=e.get('conclusion'), references=e.get('references'),
                         candidate=e.get('candidate'), size=(e.get('section') or {}).get('size'),
                         problems=e.get('problems'), checks=e.get('checks'), negative_check=e.get('negative_check')))
    cands = sorted((r['candidate'][0], r['candidate'][1], r['object']) for r in rows if r.get('candidate'))
    overlaps = [(a[2], b[2]) for a, b in zip(cands, cands[1:]) if b[0] < a[1]]
    S = dict(objects=len(rows), conclusions={r['object']: r['conclusion'] for r in rows},
             inferred=sum(1 for r in rows if r['conclusion'] in ('reference-inferred', 'reference-inferred-single')),
             single=[r['object'] for r in rows if r['conclusion'] == 'reference-inferred-single'],
             fail=[r['object'] for r in rows if r['conclusion'] not in ('reference-inferred', 'reference-inferred-single')],
             overlaps=overlaps, l1_reasons_bss_only=all(r['l1_reasons'] == ['__DATA,__bss: unverified'] for r in rows))
    json.dump(dict(plan=464, tool='10_tools/reconstruction/m5_m68k_zerofill.py', tool_sha256=sha(os.path.abspath(__file__)),
                   zerofill_check_sha256=sha(os.path.join(HERE, 'zerofill_check.py')), image_sha256=sha(IMG), symbols_sha256=sha(SYMS),
                   summary=S, candidates=[[hex(a), hex(b), n] for a, b, n in cands], rows=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))
    for a, b, n in cands:
        print(hex(a), hex(b), b - a, n)


def main():
    a = sys.argv[1:]
    if a[:1] == ['x86replay'] and len(a) == 3:
        x86replay(a[1], a[2])
    elif a[:1] == ['m68k'] and len(a) == 3:
        m68k(a[1], a[2])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
