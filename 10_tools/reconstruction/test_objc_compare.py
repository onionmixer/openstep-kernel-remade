#!/usr/bin/env python3
"""T-ObjC self-tests for the Objective-C extensions of l1_compare (plan 14 / 14.1).

  test_objc_compare.py RUN_OUT_DIR [--report FILE]

RUN_OUT_DIR holds tobjc (linked by the target ld) and objc_a.o, objc_b.o.
Mutations are applied to copies of tobjc in a temporary directory.
"""
import json, os, shutil, struct, sys, tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import l1_compare as L
import macho_obj
import objc_meta
import objc_place


def run(img_path, obj_path):
    img = L.Image(img_path)
    pl = L.placements_from_image(img, obj_path)
    meta = objc_meta.Meta(img).read()
    mp, minfo = L.placements_from_methods(meta['methods'], obj_path)
    rp, rinfo = objc_place.placements(obj_path, meta)
    minfo['records'] = rinfo
    pl.update(mp)
    pl.update(rp)
    by_objc = set(mp) | set(rp)
    r = L.compare(img, obj_path, pl, None, set(pl) - by_objc, minfo, by_objc)
    return r['object_verdict'], {','.join(f['names']): f['verdict'] for f in r['functions']}, r


def patch(path, addr, new4=None, xor_byte=None):
    img = L.Image(path)
    s = [x for x in img.secs if x['addr'] <= addr < x['addr'] + x['size']][0]
    off = s['offset'] + addr - s['addr']
    d = bytearray(open(path, 'rb').read())
    if new4 is not None:
        d[off:off + 4] = (new4 % (1 << 32)).to_bytes(4, 'little')
    if xor_byte is not None:
        d[off] ^= xor_byte
    open(path, 'wb').write(d)


def word(img, a):
    return struct.unpack('<I', img.read(a, 4))[0]


def main():
    out = sys.argv[1]
    report = sys.argv[sys.argv.index('--report') + 1] if '--report' in sys.argv else None
    img0p = os.path.join(out, 'tobjc')
    A, B = os.path.join(out, 'objc_a.o'), os.path.join(out, 'objc_b.o')
    results, fails = [], []

    def check(name, ok, **info):
        results.append(dict(test=name, ok=bool(ok), **info))
        if not ok:
            fails.append(name)

    img = L.Image(img0p)
    meta = objc_meta.Meta(img).read()
    va, fa, _ = run(img0p, A)
    vb, fb, rb = run(img0p, B)
    check('P1 objc_a OBJECT_MATCH', va == 'OBJECT_MATCH' and all(v == 'MATCH' for v in fa.values()), got=[va, fa])
    check('P2 objc_b OBJECT_MATCH', vb == 'OBJECT_MATCH' and all(v == 'MATCH' for v in fb.values()), got=[vb, fb])
    # the link really coalesced literals (otherwise the literal rules were not exercised)
    sec = {s['sectname']: s for s in img.secs}
    oa, ob = macho_obj.read(A), macho_obj.read(B)
    size = lambda o, n: sum(s['size'] for s in o['sections'] if s['sectname'] == n)
    for n in ('__message_refs', '__class_names', '__meth_var_names'):
        check('P3 %s coalesced' % n, sec[n]['size'] < size(oa, n) + size(ob, n),
              image=sec[n]['size'], objects=size(oa, n) + size(ob, n))

    cls = {c['name']: c for c in meta['classes']}
    meth = {(m['owner'], m['category'], m['kind'], m['selector']): m for m in meta['methods']}
    cat = {(c['class_name'], c['name']): c for c in meta['categories']}
    mods = {m['name']: m for m in meta['modules']}
    tmp = tempfile.mkdtemp(prefix='objctest-')
    try:
        def mutated(tag):
            p = os.path.join(tmp, tag)
            shutil.copyfile(img0p, p)
            return p

        # N1: a selector reference in objc_b's __text pointed at another slot
        bt = [s for s in ob['sections'] if s['sectname'] == '__text'][0]
        mrb = [s for s in ob['sections'] if s['sectname'] == '__message_refs'][0]
        rel = [r for r in bt['relocs'] if not r['scattered'] and not r['extern'] and r['symbolnum'] == mrb['index']]
        text_at = rb['placements']['__TEXT,__text']
        field = text_at + rel[0]['address']
        cur = word(img, field)
        mr = sec['__message_refs']
        other = [mr['addr'] + 4 * i for i in range(mr['size'] // 4) if mr['addr'] + 4 * i != cur][0]
        p = mutated('n1'); patch(p, field, new4=other)
        v, f, _ = run(p, B)
        check('N1 selector slot changed', v != 'OBJECT_MATCH' and 'DIFF' in f.values(), got=[v, f])

        # N2: KRBase instance size +4
        p = mutated('n2'); patch(p, cls['KRBase']['address'] + 20, new4=cls['KRBase']['instance_size'] + 4)
        v, f, _ = run(p, A)
        check('N2 instance size', v != 'OBJECT_MATCH', got=[v, f])

        # N3: IMP of -[KRBase x] replaced by the IMP of -[KRBase setX:]
        mx, ms = meth[('KRBase', None, 'instance', 'x')], meth[('KRBase', None, 'instance', 'setX:')]
        p = mutated('n3'); patch(p, mx['metadata_address'] + 8, new4=ms['imp'])
        v, f, _ = run(p, A)
        check('N3 method IMP', v != 'OBJECT_MATCH', got=[v, f])

        # N4: KRSub superclass name pointer -> the "KROther" name string
        kro_name = word(img, cls['KROther']['address'] + 8)
        p = mutated('n4'); patch(p, cls['KRSub']['address'] + 4, new4=kro_name)
        v, f, _ = run(p, A)
        check('N4 superclass string', v != 'OBJECT_MATCH', got=[v, f])

        # N5: the __cls_refs slot pointed at the "Object" string
        object_str = word(img, cls['KRBase']['isa'])          # metaclass isa = root class name
        p = mutated('n5'); patch(p, sec['__cls_refs']['addr'], new4=object_str)
        v, f, _ = run(p, B)
        check('N5 cls_refs slot content', v != 'OBJECT_MATCH' and f.get('-[KROther useBase]') == 'DIFF', got=[v, f])

        # N6: one byte of the type string of -[KRBase x]
        p = mutated('n6'); patch(p, word(img, mx['metadata_address'] + 4), xor_byte=0x01)
        v, f, _ = run(p, A)
        check('N6 method type string', v != 'OBJECT_MATCH', got=[v, f])

        # N7: category name pointer -> the "KRBase" string
        krb_name = word(img, cls['KRBase']['address'] + 8)
        p = mutated('n7'); patch(p, cat[('KROther', 'KRCat2')]['address'], new4=krb_name)
        v, f, _ = run(p, B)
        check('N7 category name', v != 'OBJECT_MATCH', got=[v, f])

        # N8: module size field of objc_a's module
        ma_name = [n for n, m in mods.items() if 'KRBase' in m['classes']][0]
        maddr = mods[ma_name]['address']
        p = mutated('n8'); patch(p, maddr + 4, new4=word(img, maddr + 4) + 1)
        v, f, _ = run(p, A)
        check('N8 module size', v != 'OBJECT_MATCH', got=[v, f])
    finally:
        shutil.rmtree(tmp)
    if report:
        json.dump(dict(run=out, tests=len(results), failed=fails, results=results), open(report, 'w'), indent=1)
    for x in results:
        print('%-4s %s' % ('ok' if x['ok'] else 'FAIL', x['test']))
    print('%d tests, %d failed' % (len(results), len(fails)))
    sys.exit(1 if fails else 0)


if __name__ == '__main__':
    main()
