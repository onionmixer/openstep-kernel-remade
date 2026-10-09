#!/usr/bin/env python3
"""Placement of an ObjC object's regular __OBJC sections from metadata
correspondence (plan section 14.1).

Walk the object's own records (module -> symtab -> class / category ->
isa / ivars / method lists) using the object's section bytes (local
relocation fields hold object addresses) and pair each record with the image
record found by objc_meta (module by name, class by name, category by
(class, name)).  A section gets a placement only if every pair in it gives
the same Delta.  The caller then verifies all bytes and references (L1d).
"""
import os, struct, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj

REC = {'module': '__module_info', 'symtab': '__symbols', 'class': '__class', 'meta': '__meta_class',
       'ivars': '__instance_vars'}


class ObjView:
    def __init__(self, path):
        self.d = open(path, 'rb').read()
        self.o = macho_obj.parse(self.d)
        macho_obj.require_i386(self.o, 'objc_place')  # plan 411: i386 little-endian only
        self.by_name = {s['sectname']: s for s in self.o['sections'] if s['segname'] == '__OBJC'}

    def sect_at(self, a):
        for s in self.o['sections']:
            if s['addr'] <= a < s['addr'] + s['size']:
                return s
        return None

    def w(self, a, n=1):
        s = self.sect_at(a)
        if s is None or a + 4 * n > s['addr'] + s['size']:
            raise ValueError('object address %#x not readable' % a)
        o = s['offset'] + a - s['addr']
        return struct.unpack('<%dI' % n, self.d[o:o + 4 * n])

    def cstr(self, a):
        s = self.sect_at(a)
        if s is None:
            raise ValueError('object string %#x outside sections' % a)
        o = s['offset'] + a - s['addr']
        e = self.d.index(b'\0', o, s['offset'] + s['size'])
        return self.d[o:e].decode('latin1')


def pairs(objpath, meta):
    """[(section name, object address, image address, what)]"""
    v = ObjView(objpath)
    out = []
    mi = v.by_name.get('__module_info')
    if not mi or not mi['size']:
        return out, 'no module_info'
    img_mods = {m['name']: m for m in meta['modules']}
    img_cls = {c['name']: c for c in meta['classes']}
    img_cat = {(c['class_name'], c['name']): c for c in meta['categories']}
    for k in range(mi['size'] // 16):
        ma = mi['addr'] + 16 * k
        ver, size, name, symtab = v.w(ma, 4)
        mname = v.cstr(name)
        im = img_mods.get(mname)
        if im is None:
            return [], 'module %r not in image' % mname
        out.append(('__module_info', ma, im['address'], 'module ' + mname))
        if not symtab:
            continue
        out.append(('__symbols', symtab, im['symtab'], 'symtab ' + mname))
        selcnt, refs = v.w(symtab, 2)
        ncls_ncat = v.w(symtab + 8, 1)[0]
        ncls, ncat = ncls_ncat & 0xffff, ncls_ncat >> 16
        defs = v.w(symtab + 12, ncls + ncat) if ncls + ncat else ()
        for i, d in enumerate(defs):
            if i < ncls:
                isa, sup, nm, ver, info, isz, ivars, meths = v.w(d, 8)
                cname = v.cstr(nm)
                ic = img_cls.get(cname)
                if ic is None:
                    return [], 'class %r not in image' % cname
                out.append(('__class', d, ic['address'], 'class ' + cname))
                out.append(('__meta_class', isa, ic['isa'], 'metaclass ' + cname))
                if ivars:
                    out.append(('__instance_vars', ivars, ic['ivars'], 'ivars ' + cname))
                if meths:
                    out.append(('__inst_meth', meths, ic['methods'], 'inst methods ' + cname))
                mmeths = v.w(isa + 28, 1)[0]
                if mmeths:
                    out.append(('__cls_meth', mmeths, ic['meta_methods'], 'class methods ' + cname))
            else:
                cn, cl, im_, cm = v.w(d, 4)
                key = (v.cstr(cl), v.cstr(cn))
                ik = img_cat.get(key)
                if ik is None:
                    return [], 'category %r not in image' % (key,)
                out.append(('__category', d, ik['address'], 'category %s(%s)' % key))
                if im_:
                    out.append(('__cat_inst_meth', im_, ik['inst_methods'], 'cat inst methods %s(%s)' % key))
                if cm:
                    out.append(('__cat_cls_meth', cm, ik['class_methods'], 'cat class methods %s(%s)' % key))
    return out, None


def placements(objpath, meta):
    """{'__OBJC,<sect>': image address of the object's section start}, info"""
    ps, err = pairs(objpath, meta)
    info = dict(pairs=len(ps), error=err, sections={})
    if err:
        return {}, info
    v = ObjView(objpath)
    by = {}
    for sect, oa, ia, what in ps:
        s = v.by_name[sect]
        by.setdefault(sect, set()).add(ia - oa)
    out = {}
    for sect, ds in by.items():
        s = v.by_name[sect]
        if len(ds) == 1:
            out['__OBJC,%s' % sect] = s['addr'] + next(iter(ds))
            info['sections'][sect] = 'one delta'
        else:
            info['sections'][sect] = '%d different deltas (refused)' % len(ds)
    return out, info
