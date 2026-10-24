#!/usr/bin/env python3
"""m4_m68k_status.py -- plan 500 (M4-6): table of the accepted m68k M4 objects.

  python3 10_tools/reconstruction/m4_m68k_status.py OUT.tsv RECORD.json

Reads the accepted final records of m4_m68k_probe.py listed in ACCEPTED (path, SHA-256) and re-checks
each of their objects now (any failure stops before writing): record hash and gate.ok; the spec
(08_build/artifacts/m4p<plan>/spec.json) hash equals the record's spec_sha256; the 07 source hash
equals the record's source_sha256; the run's compile line for that source is unique; the run object
exists with the recorded SHA-256; the REF hash equals the spec and REF equality (canon, obj_sig) holds;
the range recomputed from the plan 495 inventory (m4_m68k_probe.span) has the object's __text size and
the L1 output (08_build/artifacts/m4p<plan>/<run>/l1-<name>-<V>.json, input hash checked) places
__TEXT,__text at its start with verdict OBJECT_MATCH; the evidence document exists; plan 506: for every
NeXTMach-only header the spec's base stage manifest lists in m4_headers, the current 07 origin hash equals
the manifest hash.  Across objects:
no duplicate name, no row covered twice, no overlapping address range.
Counts: accepted objects, covered plan 495 rows of 188, bytes of the M4 minimum bytes; the M5 set
(plan 429) is not counted here.  Read-only apart from the two output files.
"""
import sys, os, json, hashlib, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import m4_m68k_probe as P

ACCEPTED = [
    ('09_validation/reconstruction/m4-m68k-p497-final-20261024.json', 'eefdb8424d310857770fdee84ded0867bbbb2608696e779549f96e223fa6cfc8'),
    ('09_validation/reconstruction/m4-m68k-p500-final-20261024.json', 'b994bb01d74e0f544c7b0e15da77e59a6c69a09b7635802e27923cf68599e98b'),
    ('09_validation/reconstruction/m4-m68k-p502-final-20261024.json', '86a2f93903a5125e9d1cbd960a73892582109f9ca29c8d0eed3ae1585de762dc'),
    ('09_validation/reconstruction/m4-m68k-p504-final-20261024.json', 'fb3c933e77cc9c14b3015c7f7ee2343111c3539e5633663ef8d33591cdf03017'),
    ('09_validation/reconstruction/m4-m68k-p506-final-20261024.json', 'f64b2a69110ce776c81e5018f74b9e402d23ec8890851e3fb24e056296bb1ab1'),
    ('09_validation/reconstruction/m4-m68k-p508-final-20261024.json', '8ecb385e2dc3a836a8850f9b1b1e35c1ed0d5d55e4f6a2454bada0e8ff5fdb8e'),
    ('09_validation/reconstruction/m4-m68k-p510-final-20261024.json', '7cdd7e9a47cecc763bf9b9dc6862cdb98bae944e8fb78b63e33e7eca1201d47f'),
    ('09_validation/reconstruction/m4-m68k-p512-final-20261024.json', 'b1194545b5937709d0662380b0b0db538d82b526b59acc1d5249609585d60be7'),
    ('09_validation/reconstruction/m4-m68k-p514-final-20261024.json', 'c30016d32daacb04b8a73f5b73515d8e0fad7bc8f318b3c8cd5fb0f97d963c1c'),
]
COLS = ['name', 'source', 'rows', 'groups', 'kinds', 'start', 'end', 'bytes', 'plan', 'record', 'l1', 'obj_sha256', 'evidence']


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def main(out_tsv, out_json):
    import m3_m68k_diag as D
    import l2_prefix_diff as PD
    rows = [l.split('\t') for l in open(P.INV).read().split('\n') if l and not l.startswith('#')]
    inv = {r[0]: dict(zip(rows[0], r)) for r in rows[1:]}
    out, seen_rows, spans = [], {}, []
    for path, want in ACCEPTED:
        assert sha(path) == want, ('record changed', path)
        rec = json.load(open(path))
        assert rec['gate']['ok'] is True, path
        plan, rid = rec['plan'], rec['run']
        spec = '08_build/artifacts/m4p%d/spec.json' % plan
        assert sha(spec) == rec['spec_sha256'], spec
        s = P.load(spec)
        man = json.load(open(s['base'] + '.manifest.json'))   # plan 506: staged NeXTMach-only headers still current
        mf = {e[0]: e for e in man['files']}
        for dst in man.get('m4_headers', []):
            assert sha(mf[dst][1]) == mf[dst][2], ('header changed', mf[dst][1])
        objs = {o['name']: o for o in s['objects']}
        runcmd = open(os.path.join('08_build/runs', rid, 'run.cmd')).read().splitlines()
        for r in [x for x in rec['objects'] if 'variant' in x]:
            o = objs[r['object']]
            rel = r['source'][len('src/'):]
            src = os.path.join('07_kernel/src', rel)
            assert sha(src) == r['source_sha256'], ('source changed', src)
            obj = 'Q%d__%s_%s.o' % (plan, r['object'], r['variant'])
            lines = [l for l in runcmd if ' -c src/src/%s ' % rel in l + ' ' and ('stage/' + obj) in l]
            assert len(lines) == 1, (rid, rel, len(lines))
            op = os.path.join('08_build/runs', rid, 'stage', obj)
            assert sha(op) == r['obj_sha256'], op
            ref, rsha = s['refs'][r['object']]
            assert sha(ref) == rsha and D.canon(op) == D.canon(ref) and PD.obj_sig(op) == PD.obj_sig(ref), ('ref', r['object'])
            lo, hi, ids = P.span(inv, o['m4_id'])
            assert r['text_size'] == hi - lo, (r['object'], r['text_size'], hi - lo)
            l1p = '08_build/artifacts/m4p%d/%s/l1-%s-%s.json' % (plan, rid, r['object'], r['variant'])
            d = json.load(open(l1p))
            assert d['inputs'][op] == r['obj_sha256'] and d['object_verdict'] == 'OBJECT_MATCH', l1p
            assert d['sections']['__TEXT,__text']['address'] == lo, (l1p, d['sections']['__TEXT,__text']['address'], lo)
            ev = '06_reconstruction/evidence/m68k-%s.md' % r['object']
            assert os.path.isfile(ev), ev
            assert r['object'] not in {x['name'] for x in out}, ('duplicate', r['object'])
            for i in ids:
                assert i not in seen_rows, ('row twice', i)
                seen_rows[i] = r['object']
            assert all(hi <= a or b <= lo for a, b in spans), ('overlap', r['object'])
            spans.append((lo, hi))
            out.append(dict(name=r['object'], source=src, rows=','.join(ids), groups=','.join(inv[i]['group'] for i in ids),
                            kinds=','.join(inv[i]['kind'] for i in ids), start=hex(lo), end=hex(hi), bytes=hi - lo, plan=plan,
                            record=path, l1=d['object_verdict'], obj_sha256=r['obj_sha256'], evidence=ev))
    out.sort(key=lambda x: int(x['start'], 16))
    updated = max(x['plan'] for x in out)   # plan 502: latest accepted record
    m4min = sum(int(r['bytes_min'] or 0) for r in inv.values())
    covered_bytes = sum(int(inv[i]['bytes_min']) for i in seen_rows)
    summ = collections.OrderedDict(objects=len(out), rows_covered=len(seen_rows), rows_total=len(inv), bytes_covered=covered_bytes,
                                   m4_min_bytes=m4min, percent=round(100.0 * covered_bytes / m4min, 2),
                                   rows_unassigned_before=sorted(i for i in seen_rows if inv[i]['kind'] == 'unassigned'))
    with open(out_tsv, 'w') as w:
        w.write('# plan 500 (updated plan %d): accepted m68k M4 objects (m4_m68k_status.py); rows = plan 495 inventory rows covered; M5 (plan 429) not included\n' % updated)
        w.write('\t'.join(COLS) + '\n')
        for x in out:
            w.write('\t'.join(str(x[c]) for c in COLS) + '\n')
    json.dump(collections.OrderedDict(plan=500, updated_plan=updated, tool='10_tools/reconstruction/m4_m68k_status.py', tool_sha256=sha(os.path.abspath(__file__)),
                                      accepted=ACCEPTED, inventory=P.INV, inventory_sha256=sha(P.INV), summary=summ, objects=out,
                                      output=out_tsv, output_sha256=sha(out_tsv)), open(out_json, 'w'), indent=1)
    print(json.dumps(summ))
    for x in out:
        print(x['name'], x['rows'], x['start'], x['end'], x['bytes'], x['l1'])


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
