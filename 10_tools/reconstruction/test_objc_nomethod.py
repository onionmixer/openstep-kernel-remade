#!/usr/bin/env python3
"""Tests for an Objective-C object with no methods (plan 299): l1_compare no longer reports
"method correspondence incomplete" for it, but a changed __module_info or __text still fails.

  test_objc_nomethod.py IMAGE OBJ

OBJ is a method-less ObjC object built for IMAGE (e.g. Kernel/generalFuncsPrivate.m).  The
mutations are applied to copies of IMAGE in a temporary directory.
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
    return L.compare(img, obj_path, pl, None, set(pl) - by_objc, minfo, by_objc)


def file_offset(img_path, va):
    m = macho_obj.parse(open(img_path, 'rb').read())
    for s in m['sections']:
        if s['addr'] <= va < s['addr'] + s['size'] and s['offset']:
            return s['offset'] + va - s['addr']
    raise ValueError('%#x not in a file-backed section' % va)


def main():
    img, obj = sys.argv[1], sys.argv[2]
    tmp = tempfile.mkdtemp(prefix='objcnm-')
    results = []

    def check(name, ok, info):
        results.append((name, ok, info))

    r = run(img, obj)
    nmeth = r['methods']['methods']
    check('P1 object has no methods', nmeth == 0, nmeth)
    check('P2 no method-correspondence reason', 'method correspondence incomplete' not in r['object_reasons'], r['object_reasons'])
    sec = r['sections']
    mod_va, text_va = sec['__OBJC,__module_info']['address'], sec['__TEXT,__text']['address']
    check('P3 __module_info and __text placed, 0 differences',
          sec['__OBJC,__module_info']['byte_differences'] == 0 and sec['__TEXT,__text']['byte_differences'] == 0, None)

    def mutated(tag, va, xor):
        p = os.path.join(tmp, tag)
        shutil.copyfile(img, p)
        b = bytearray(open(p, 'rb').read())
        o = file_offset(img, va)
        b[o] ^= xor
        open(p, 'wb').write(bytes(b))
        return run(p, obj)

    m = mutated('n1', mod_va + 4, 0x01)          # module size word
    check('N1 module size changed -> NOT_MATCH via __module_info', m['object_verdict'] == 'NOT_MATCH' and
          any('__module_info' in x for x in m['object_reasons']), m['object_reasons'])
    m = mutated('n2', text_va + 3, 0x40)         # a byte inside the first function
    check('N2 __text byte changed -> NOT_MATCH via __text', m['object_verdict'] == 'NOT_MATCH' and
          any('__TEXT,__text' in x for x in m['object_reasons']), m['object_reasons'])
    shutil.rmtree(tmp)
    fails = [x for x in results if not x[1]]
    for name, ok, info in results:
        print('%-4s %s %s' % ('ok' if ok else 'FAIL', name, '' if ok else info))
    print('%d tests, %d failed' % (len(results), len(fails)))
    sys.exit(1 if fails else 0)


if __name__ == '__main__':
    main()
