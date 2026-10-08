#!/usr/bin/env python3
"""Tests for zerofill_check --place-from-l1 (plan 302).

  test_zerofill_l1place.py IMAGE SYMBOLS KNOWN OBJC_OBJ C_OBJ

OBJC_OBJ: an ObjC object whose referring __text has no symbol placement (e.g. IOVPCodeDisplay).
C_OBJ: a C object whose __text is placed by symbols (control, e.g. generalFuncs).
"""
import json, os, shutil, subprocess, sys, tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
image, symbols, known, objc_obj, c_obj = sys.argv[1:6]
tmp = tempfile.mkdtemp(prefix='zfl1-')
results = []


def l1(img, obj, out, objc):
    cmd = [sys.executable, os.path.join(HERE, 'l1_compare.py'), '--image', img, '--obj', obj, '--place-from-image', '--out', out]
    if objc:
        cmd.append('--place-from-objc')
    subprocess.run(cmd, capture_output=True)
    return out


def zf(img, obj, l1path=None):
    out = os.path.join(tmp, 'zf.json')
    if os.path.exists(out):
        os.remove(out)
    cmd = [sys.executable, os.path.join(HERE, 'zerofill_check.py'), '--image', img, '--obj', obj, '--section', '__DATA,__bss',
           '--symbols', symbols, '--known', known, '--out', out]
    if l1path:
        cmd += ['--place-from-l1', l1path]
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode or not os.path.exists(out):
        return dict(rejected=(r.stderr or r.stdout).strip()[-200:])
    return json.load(open(out))


def check(name, ok, info=None):
    results.append((name, bool(ok), info))


def text_index(obj):
    sys.path.insert(0, HERE)
    import macho_obj
    m = macho_obj.parse(open(obj, 'rb').read())
    return str([s for s in m['sections'] if s['sectname'] == '__text'][0]['index'])


L_objc = l1(image, objc_obj, os.path.join(tmp, 'objc-l1.json'), True)
L_c = l1(image, c_obj, os.path.join(tmp, 'c-l1.json'), False)
ti = text_index(objc_obj)

r0 = zf(image, objc_obj)
check('P1 ObjC object without the option: fail (no symbol placement)', r0.get('conclusion') == 'fail', r0.get('problems'))
r1 = zf(image, objc_obj, L_objc)
check('P2 ObjC object with the option: reference-inferred, __text Delta from l1',
      r1.get('conclusion', '').startswith('reference-inferred') and r1.get('delta_source', {}).get(ti) == 'l1', (r1.get('conclusion'), r1.get('delta_source')))
c0, c1 = zf(image, c_obj), zf(image, c_obj, L_c)
check('P3 C control: same conclusion and candidate with and without the option, __text Delta from symbol',
      c0.get('conclusion') == c1.get('conclusion') and c0.get('candidate') == c1.get('candidate')
      and c1.get('delta_source', {}).get(text_index(c_obj)) == 'symbol', (c0.get('conclusion'), c1.get('conclusion'), c1.get('delta_source')))

# N1: object changed at the same path (L1 made from the original object)
o2 = os.path.join(tmp, os.path.basename(objc_obj)); shutil.copyfile(objc_obj, o2)
L_o2 = l1(image, o2, os.path.join(tmp, 'o2-l1.json'), True)
b = bytearray(open(o2, 'rb').read()); b[-1] ^= 1; open(o2, 'wb').write(bytes(b))
check('N1 object changed at the same path: rejected', 'rejected' in zf(image, o2, L_o2))
# N2: image changed (L1 made from the original image)
i2 = os.path.join(tmp, 'img'); shutil.copyfile(image, i2)
L_i2 = l1(i2, objc_obj, os.path.join(tmp, 'i2-l1.json'), True)
b = bytearray(open(i2, 'rb').read()); b[-1] ^= 1; open(i2, 'wb').write(bytes(b))
check('N2 image changed: rejected', 'rejected' in zf(i2, objc_obj, L_i2))
# P4 (was N3 before plan 339): placement downgraded to an inferred one
d = json.load(open(L_objc)); d['sections']['__TEXT,__text']['placement'] = 'inferred, verified by L1d'
p3 = os.path.join(tmp, 'n3.json'); json.dump(d, open(p3, 'w'))
r3 = zf(image, objc_obj, p3)
check('P4 L1d-inferred placement used (plan 339, D041): reference-inferred, __text Delta from l1-inferred',
      r3.get('conclusion', '').startswith('reference-inferred') and r3.get('delta_source', {}).get(ti) == 'l1-inferred', (r3.get('conclusion'), r3.get('delta_source')))
# N3a / N3b: an inferred placement that L1 did not fully verify is still not used
for tag, key in (('N3a', 'refs_unverified'), ('N3b', 'byte_differences'), ('N3c', 'refs_differ')):
    d = json.load(open(L_objc)); d['sections']['__TEXT,__text']['placement'] = 'inferred, verified by L1d'; d['sections']['__TEXT,__text'][key] = 1
    pp = os.path.join(tmp, tag + '.json'); json.dump(d, open(pp, 'w'))
    rr = zf(image, objc_obj, pp)
    check('%s inferred placement with %s 1 not used: fail' % (tag, key), rr.get('conclusion') == 'fail' and rr.get('delta_source', {}).get(ti) is None, rr.get('delta_source'))
# N3d: a bare 'inferred' placement (not verified by L1d) is not used
d = json.load(open(L_objc)); d['sections']['__TEXT,__text']['placement'] = 'inferred'
pp = os.path.join(tmp, 'n3d.json'); json.dump(d, open(pp, 'w'))
rr = zf(image, objc_obj, pp)
check('N3d bare inferred placement not used: fail', rr.get('conclusion') == 'fail' and rr.get('delta_source', {}).get(ti) is None, rr.get('delta_source'))
# N3e: an L1d-inferred placement conflicting with a symbol Delta (C control) fails, symbol provenance kept
d = json.load(open(L_c)); d['sections']['__TEXT,__text']['placement'] = 'inferred, verified by L1d'; d['sections']['__TEXT,__text']['address'] += 4
pp = os.path.join(tmp, 'n3e.json'); json.dump(d, open(pp, 'w'))
rr = zf(image, c_obj, pp)
check('N3e inferred placement conflicting with the symbol Delta: fail, symbol provenance kept',
      rr.get('conclusion') == 'fail' and any('differs from L1 Delta' in p for p in rr.get('problems', []))
      and rr.get('delta_source', {}).get(text_index(c_obj)) == 'symbol', (rr.get('conclusion'), rr.get('delta_source')))
# P5: real regression (plan 339): kmGraphics, whose __data placement is L1d-inferred and holds a pointer into __bss
km_obj = '08_build/runs/s5p336-it1/out/F__kmGraphics.o'
km_l1 = '09_validation/reconstruction/s5p336-it1-l1-kmGraphics-F-20261002.json'
rk = zf(image, km_obj, km_l1)
check('P5 kmGraphics: reference-inferred, 34 references, one Delta 0x1e3430, [0x1e7780, 0x1e8645), __data from l1-inferred',
      rk.get('conclusion', '').startswith('reference-inferred') and rk.get('references') == 34 and rk.get('distinct_deltas') == ['0x1e3430']
      and rk.get('candidate') == [0x1e7780, 0x1e8645] and 'l1-inferred' in rk.get('delta_source', {}).values()
      and rk.get('negative_check', {}).get('detected'), (rk.get('conclusion'), rk.get('references'), rk.get('distinct_deltas'), rk.get('candidate')))
# N4: no inputs field
d = json.load(open(L_objc)); d.pop('inputs')
p4 = os.path.join(tmp, 'n4.json'); json.dump(d, open(p4, 'w'))
check('N4 L1 without inputs: rejected', 'rejected' in zf(image, objc_obj, p4))
# N5: symbol / L1 conflict on the C control
d = json.load(open(L_c)); d['sections']['__TEXT,__text']['address'] += 4
p5 = os.path.join(tmp, 'n5.json'); json.dump(d, open(p5, 'w'))
r5 = zf(image, c_obj, p5)
check('N5 symbol Delta differs from L1 Delta: fail with a conflict problem',
      r5.get('conclusion') == 'fail' and any('differs from L1 Delta' in p for p in r5.get('problems', [])), r5.get('problems'))

shutil.rmtree(tmp)
fails = [x for x in results if not x[1]]
for name, ok, info in results:
    print('%-4s %s %s' % ('ok' if ok else 'FAIL', name, '' if ok else info))
print('%d tests, %d failed' % (len(results), len(fails)))
sys.exit(1 if fails else 0)
