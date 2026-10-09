#!/usr/bin/env python3
"""Read Objective-C (NeXT ObjC 1, i386) metadata from a linked Mach-O image.

Walks __OBJC,__module_info -> symtab -> class/category definitions -> method
lists, and returns one record per method:
  owner, category (or None), kind ('instance'/'class'), selector, types, imp,
  metadata_address, list_address
Layouts used (all little-endian 32-bit words), as seen in the T-ObjC image and
the original kernel:
  module   {version, size, name*, symtab*}
  symtab   {sel_ref_cnt, refs*, cls_def_cnt:16, cat_def_cnt:16, defs*[]}
  class    {isa*, super*, name*, version, info, instance_size, ivars*, methods*, cache*, protocols*}
  category {category_name*, class_name*, instance_methods*, class_methods*, protocols*}
  method list {next*, count, {sel*, types*, imp*}[count]}
Class isa points to the metaclass record; names are C strings.

  objc_meta.py IMAGE [--compare-inventory objc.json]
"""
import json, os, struct, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import l1_compare as L


class Meta:
    def __init__(self, img):
        L.macho_obj.require_i386(img.o, 'objc_meta')  # plan 411: i386 little-endian only
        self.img = img
        self.sec = {(s['segname'], s['sectname']): s for s in img.secs}

    def w(self, a, n=1):
        b = self.img.read(a, 4 * n)
        if b is None:
            raise ValueError('unreadable %#x' % a)
        return struct.unpack('<%dI' % n, b)

    def cstr(self, a):
        for s in self.img.secs:
            if s['addr'] <= a < s['addr'] + s['size']:
                b = self.img.read(a, s['addr'] + s['size'] - a)
                i = b.find(b'\0')
                if i < 0:
                    raise ValueError('unterminated string at %#x' % a)
                return b[:i].decode('latin1')
        raise ValueError('string address %#x outside sections' % a)

    def methods_of(self, lst, owner, cat, kind, out):
        while lst:
            nxt, count = self.w(lst, 2)
            for i in range(count):
                ma = lst + 8 + 12 * i
                sel, typ, imp = self.w(ma, 3)
                out.append(dict(owner=owner, category=cat, kind=kind, selector=self.cstr(sel),
                                types=self.cstr(typ), imp=imp, metadata_address=ma, list_address=lst))
            lst = nxt

    def read(self):
        mi = self.sec.get(('__OBJC', '__module_info'))
        out, classes, cats, mods = [], [], [], []
        if not mi or not mi['size']:
            return dict(methods=out, classes=classes, categories=cats, modules=mods)
        for k in range(mi['size'] // 16):
            ver, size, name, symtab = self.w(mi['addr'] + 16 * k, 4)
            mods.append(dict(address=mi['addr'] + 16 * k, name=self.cstr(name) if name else None,
                             symtab=symtab, classes=[], categories=[]))
            if not symtab:
                continue
            selcnt, refs = self.w(symtab, 2)
            cnts = self.img.read(symtab + 8, 4)
            ncls, ncat = struct.unpack('<2H', cnts)
            defs = self.w(symtab + 12, ncls + ncat) if ncls + ncat else ()
            for i, d in enumerate(defs):
                if i < ncls:
                    isa, sup, nm, v, info, isz, ivars, meths = self.w(d, 8)
                    cname = self.cstr(nm)
                    misa_m = self.w(isa + 28, 1)[0]
                    classes.append(dict(name=cname, address=d, instance_size=isz, isa=isa, ivars=ivars,
                                        methods=meths, meta_methods=misa_m, module=mods[-1]['name']))
                    mods[-1]['classes'].append(cname)
                    self.methods_of(meths, cname, None, 'instance', out)
                    misa, msup, mnm, mv, minfo, misz, mivars, mmeths = self.w(isa, 8)
                    self.methods_of(mmeths, cname, None, 'class', out)
                else:
                    cn, cl, im, cm = self.w(d, 4)
                    cat, cls = self.cstr(cn), self.cstr(cl)
                    cats.append(dict(name=cat, class_name=cls, address=d, inst_methods=im, class_methods=cm,
                                     module=mods[-1]['name']))
                    mods[-1]['categories'].append((cls, cat))
                    self.methods_of(im, cls, cat, 'instance', out)
                    self.methods_of(cm, cls, cat, 'class', out)
        return dict(methods=out, classes=classes, categories=cats, modules=mods)


def main():
    img = L.Image(sys.argv[1])
    m = Meta(img).read()
    print('classes %d categories %d methods %d' % (len(m['classes']), len(m['categories']), len(m['methods'])))
    if '--compare-inventory' in sys.argv:
        inv = json.load(open(sys.argv[sys.argv.index('--compare-inventory') + 1]))
        a = set(((x['owner'] if x['category'] is None else '%s(%s)' % (x['owner'], x['category'])),   # inventory form
                 x['kind'], x['selector'], x['types'], x['imp'], x['metadata_address']) for x in m['methods'])
        b = set((x['owner'], x['kind'], x['selector'], x['types'], int(x['imp'], 16), int(x['metadata_address'], 16))
                for x in inv['methods'])
        print('inventory methods %d; equal sets: %s; only mine %d only inventory %d' % (len(b), a == b, len(a - b), len(b - a)))
        for x in sorted(a - b)[:5]:
            print('  only mine', x)
        for x in sorted(b - a)[:5]:
            print('  only inventory', x)


if __name__ == '__main__':
    main()
