#!/usr/bin/env python3
"""m68k_funcbytes.py -- plan 521: function-by-function byte comparison of an m68k object with the original (diagnostic).

  python3 10_tools/reconstruction/m68k_funcbytes.py LO HI OBJECT.o RECORD.json [ADDR=NAME ...]

LO, HI: the original range (hex).  Original functions: the entries of 06_reconstruction/m68k-functions.tsv in
[LO, HI) (start, end, name; an unnamed entry gets the name of an ADDR=NAME argument, a diagnostic mapping
that does not change the original symbol evidence).  Plan 525: an ADDR=NAME with ADDR outside [LO, HI) names unnamed
original data (a static): an original target va with ADDR <= va < the next original symbol after ADDR is
resolved to (NAME, va - ADDR); without such arguments the output is unchanged.  Object functions: the non-STABS symbols defined in
__TEXT,__text (external or local), each up to the next one or the end of the section.  Pairs by name.

Per pair: lengths; if equal, the bytes compared at the same function offset with every object relocation
field masked (count of differing bytes, first offsets), and every relocation field compared by target:
  object: VANILLA only (else exit); extern -> (symbol, addend; for a PC-relative field the addend is the
          stored displacement plus the field address); local -> the target in the section r_symbolnum names
          (else exit); scattered (plan 532) -> (the named SECT symbols at r_value in its section, effective
          target - r_value), equal when the anchor's one original address (function in range, ADDR=NAME
          mapping or original symbol; aliases must agree, else exit) plus that offset is the original target;
          plan 611: with no such symbol and r_value inside the object __cstring -> ('cstring', the NUL-terminated
          string at r_value, offset), equal when 0 <= offset <= its length (the NUL included) and the original
          target minus that offset lies in the original __cstring at a NUL-terminated string with the same bytes;
          plan 685: with no such symbol and r_value inside the object __text -> (the object function containing
          r_value, effective target - its start), equal when that function's one original address plus the offset
          is the original target (r_value in no function: exit);
          local -> the target address in the object
          (the stored word, or field address + displacement), resolved to
          (object function name, offset) for __text, ('cstring', content) for __cstring, else (symbol, offset);
          a PC-relative field is resolved from field address + stored displacement;
  original: the same field read from the image: absolute -> address, PC-relative -> field address +
          displacement; an address in [LO, HI) is resolved to (original function name, offset) with the
          mapping, in __cstring to ('cstring', content), else to (nearest symbol, offset), where the
          symbol is every alias at that address and the object name must be one of them.
Read-only apart from RECORD.json.
"""
import sys, os, json, struct, bisect, hashlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj

ORIG = '03_original/m68k/binaries/mach_kernel'
MACHO = '03_original/m68k/inventory/macho.json'
SYMS = '03_original/m68k/inventory/symbols.tsv'
FUNCS = '06_reconstruction/m68k-functions.tsv'


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def num(x):
    return int(x, 16) if isinstance(x, str) else x


class Image:
    def __init__(self):
        self.secs = json.load(open(MACHO))['sections']
        for s in self.secs:
            s['address'], s['size'], s['file_offset'] = num(s['address']), num(s['size']), num(s['file_offset'])
        self.b = open(ORIG, 'rb').read()
        rows = [l.rstrip('\n').split('\t') for l in open(SYMS)]
        h = rows[0]
        vi, ni = h.index('value'), h.index('name')
        self.syms = sorted((int(r[vi], 16), r[ni]) for r in rows[1:] if r[vi].startswith('0x'))
        self.addrs = [a for a, _ in self.syms]
        self.alias = {}                                  # address -> every name defined there (aliases)
        for a, n in self.syms:
            self.alias.setdefault(a, []).append(n)

    def sec(self, va):
        for s in self.secs:
            if s['address'] <= va < s['address'] + s['size']:
                return s
        return None

    def read(self, va, n):
        s = self.sec(va)
        o = s['file_offset'] + va - s['address']
        return self.b[o:o + n]

    def cstr(self, va):
        s = self.sec(va)
        o = s['file_offset'] + va - s['address']
        return self.b[o:self.b.index(b'\0', o, s['file_offset'] + s['size'])].decode('latin1')

    def sym(self, va):
        k = bisect.bisect_right(self.addrs, va) - 1
        return [','.join(sorted(self.alias[self.syms[k][0]])), va - self.syms[k][0]]


def cstr_at(buf, pos, lo, hi):
    """plan 611: the NUL-terminated bytes at pos within [lo, hi), or None (pos outside, or no NUL before hi)"""
    if not lo <= pos < hi:
        return None
    e = buf.find(b'\0', pos, hi)
    return None if e < 0 else buf[pos:e]


def cstr_ref_same(ostr, off, istr):
    """plan 611: a scattered __cstring reference (anchor string, offset) equals the original one"""
    return ostr is not None and istr is not None and 0 <= off <= len(ostr) and ostr == istr


def s32(v, n):
    bits = 8 * n
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def main(lo, hi, objp, outj, maps):
    lo, hi = int(lo, 16), int(hi, 16)
    img = Image()
    fn = [l.rstrip('\n').split('\t') for l in open(FUNCS) if l.strip() and not l.startswith('#')][1:]
    ofs = sorted((int(r[0], 16), int(r[1], 16), r[3]) for r in fn if lo <= int(r[0], 16) < hi)
    mp = {int(a, 16): n for a, n in (m.split('=') for m in maps)}
    ofs = [(a, e, n.split(',')[0] if n else mp.get(a, '')) for a, e, n in ofs]
    ostarts = [a for a, _, _ in ofs]
    dmap = sorted((a, n) for a, n in mp.items() if not lo <= a < hi)   # plan 525: unnamed original data (diagnostic)

    def orig_target(va):
        if lo <= va < hi:
            k = bisect.bisect_right(ostarts, va) - 1
            return [ofs[k][2], va - ofs[k][0]]
        s = img.sec(va)
        if s is not None and s['name'] == '__cstring':
            return ['cstring', img.cstr(va)]
        for a, n in reversed(dmap):                     # va in [ADDR, next original symbol after ADDR)
            k = bisect.bisect_right(img.addrs, a)
            if a <= va and (k == len(img.addrs) or va < img.addrs[k]):
                return [n, va - a]
        return img.sym(va)

    def orig_addr(names):
        """plan 532: the one original address of an anchor (aliases must agree); else exit"""
        got = set()
        for n in names:
            c = {s for s, _, fnm in ofs if fnm == n} | {a for a, m in dmap if m == n} | {a for a, m in img.syms if m == n}
            if len(c) > 1:
                raise SystemExit('anchor %s has several original addresses %s' % (n, sorted(map(hex, c))))
            got |= c
        if len(got) != 1:
            raise SystemExit('anchor %s: original address %s' % (names, sorted(map(hex, got))))
        return got.pop()

    d = open(objp, 'rb').read()
    o = macho_obj.parse(d)
    secs = o['sections']
    text = [s for s in secs if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
    tsyms = sorted((y['value'], y['name'], y['ext']) for y in o['symbols']
                   if y['kind'] == 'SECT' and not y['stab'] and y['sect'] == text['index'] and y['name'])
    objf = []
    for i, (v, n, ext) in enumerate(tsyms):
        end = tsyms[i + 1][0] if i + 1 < len(tsyms) else text['addr'] + text['size']
        objf.append((v, end, n, ext))
    ostarts_obj = [v for v, _, _, _ in objf]
    defs = sorted((y['value'], y['name']) for y in o['symbols'] if y['kind'] == 'SECT' and not y['stab'] and y['name'])

    def obj_target(a):
        s = next((x for x in secs if x['addr'] <= a < x['addr'] + x['size']), None)
        if s is text:
            k = bisect.bisect_right(ostarts_obj, a) - 1
            return [objf[k][2], a - objf[k][0]]
        if s is not None and s['sectname'] == '__cstring':
            off = s['offset'] + a - s['addr']
            return ['cstring', d[off:d.index(b'\0', off, s['offset'] + s['size'])].decode('latin1')]
        k = bisect.bisect_right([x for x, _ in defs], a) - 1
        return [defs[k][1], a - defs[k][0]] if k >= 0 else ['?', a]

    rel = {}
    for r in text['relocs']:
        if r['type'] != 0:
            raise SystemExit('unsupported relocation type %r' % r)
        if r['address'] in rel:
            raise SystemExit('two relocations at %#x' % r['address'])
        rel[r['address']] = r

    def sec_of(a):
        return next((x for x in secs if x['addr'] <= a < x['addr'] + x['size']), None)
    rows, objnames = [], {n: (v, e, x) for v, e, n, x in objf}
    for a, e, n in ofs:
        row = dict(name=n or '(unnamed %#x)' % a, original=[hex(a), e - a])
        if n not in objnames:
            row['object'] = None
            rows.append(row)
            continue
        v, oe, ext = objnames[n]
        row['object'] = [hex(v), oe - v, 'external' if ext else 'local']
        if oe - v != e - a:
            rows.append(row)
            continue
        ob = d[text['offset'] + v - text['addr']:text['offset'] + oe - text['addr']]
        ib = img.read(a, e - a)
        mask = [False] * (e - a)
        refs = []
        for ra, r in sorted(rel.items()):
            fo = ra - (v - text['addr'])
            if not 0 <= fo < e - a:
                continue
            ln = {0: 1, 1: 2, 2: 4}[r['length']]
            for i in range(fo, fo + ln):
                mask[i] = True
            ow = int.from_bytes(ob[fo:fo + ln], 'big')
            iw = int.from_bytes(ib[fo:fo + ln], 'big')
            field = v + fo                              # object address of the field (PC base of a PC-relative field)
            if r['scattered']:                          # plan 532: anchor (SECT symbol at r_value) + (effective target - r_value),
                tgt = (field + s32(ow, ln)) if r['pcrel'] else ow   # compared by original address
                rs = sec_of(r['value'])
                anc = sorted(y['name'] for y in o['symbols'] if not y['stab'] and y['kind'] == 'SECT' and y['name']
                             and rs is not None and y['sect'] == rs['index'] and y['value'] == r['value'])
                if not anc and rs is not None and rs['sectname'] == '__cstring':   # plan 611: anchor = the string at r_value
                    off = tgt - r['value']
                    iva = (a + fo + s32(iw, ln)) if r['pcrel'] else iw
                    ostr = cstr_at(d, rs['offset'] + r['value'] - rs['addr'], rs['offset'], rs['offset'] + rs['size'])
                    isec = img.sec(iva - off)
                    istr = None
                    if isec is not None and isec['name'] == '__cstring':
                        istr = cstr_at(img.b, isec['file_offset'] + iva - off - isec['address'], isec['file_offset'], isec['file_offset'] + isec['size'])
                    refs.append(dict(offset=fo, pcrel=r['pcrel'], object=['cstring', None if ostr is None else ostr.decode('latin1'), off],
                                     original=['cstring', None if istr is None else istr.decode('latin1'), off], anchor='cstring',
                                     same=cstr_ref_same(ostr, off, istr)))
                    continue
                if not anc and rs is text:              # plan 685: anchor = the object function containing r_value
                    k = bisect.bisect_right(ostarts_obj, r['value']) - 1
                    if not objf or k < 0 or not objf[k][0] <= r['value'] < objf[k][1]:
                        raise SystemExit('scattered relocation at %#x: r_value %#x in no object function' % (ra, r['value']))
                    off = tgt - objf[k][0]
                    oa = orig_addr([objf[k][2]])
                    iva = (a + fo + s32(iw, ln)) if r['pcrel'] else iw
                    refs.append(dict(offset=fo, pcrel=r['pcrel'], object=[objf[k][2], off], original=orig_target(iva),
                                     anchor='text', anchor_original=hex(oa), same=oa + off == iva))
                    continue
                if not anc:
                    raise SystemExit('scattered relocation at %#x: no symbol at r_value %#x' % (ra, r['value']))
                off = tgt - r['value']
                oa = orig_addr(anc)
                iva = (a + fo + s32(iw, ln)) if r['pcrel'] else iw
                refs.append(dict(offset=fo, pcrel=r['pcrel'], object=[','.join(anc), off], original=orig_target(iva),
                                 anchor_original=hex(oa), same=oa + off == iva))
                continue
            elif r['extern'] and r['pcrel']:            # stored displacement + field address = addend (plan 522, checked on objects)
                ot = [o['symbols'][r['symbolnum']]['name'], s32(ow, ln) + field]
            elif r['extern']:
                ot = [o['symbols'][r['symbolnum']]['name'], s32(ow, ln)]
            else:                                       # local: r_symbolnum is the section; the target must lie in it
                if r['symbolnum'] == 0:
                    raise SystemExit('R_ABS relocation at %#x' % ra)
                tgt = (field + s32(ow, ln)) if r['pcrel'] else ow
                ds = secs[r['symbolnum'] - 1]
                if not ds['addr'] <= tgt < ds['addr'] + ds['size']:
                    raise SystemExit('local target %#x outside its section %s' % (tgt, ds['sectname']))
                ot = obj_target(tgt)
            it = orig_target((a + fo + s32(iw, ln)) if r['pcrel'] else iw)
            same = ot == it or (ot[0] != 'cstring' and it[0] != 'cstring' and ot[0] in it[0].split(',') and ot[1] == it[1])
            refs.append(dict(offset=fo, pcrel=r['pcrel'], object=ot, original=it, same=same))
        diff = [i for i in range(e - a) if not mask[i] and ob[i] != ib[i]]
        row.update(byte_differences=len(diff), first_differences=[hex(i) for i in diff[:12]],
                   references=len(refs), refs_differ=[x for x in refs if not x['same']], same=not diff and all(x['same'] for x in refs))
        rows.append(row)
    extra = sorted(set(objnames) - {n for _, _, n in ofs})
    rec = dict(plan=521, tool=os.path.relpath(os.path.abspath(__file__)), tool_sha256=sha(os.path.abspath(__file__)),
               object=objp, object_sha256=sha(objp), range=[hex(lo), hex(hi)], mapping={hex(k): v for k, v in mp.items()},
               inputs={p: sha(p) for p in (ORIG, MACHO, SYMS, FUNCS)}, functions=rows, object_only=extra,
               same=sum(1 for r in rows if r.get('same')), total=len(rows))
    json.dump(rec, open(outj, 'w'), indent=1)
    print('%s: %d/%d functions byte-identical (relocations by target); object-only %s' % (os.path.basename(objp), rec['same'], rec['total'], extra))
    for r in rows:
        print('  %-28s orig %s obj %s %s' % (r['name'], r['original'][1], r['object'][1] if r.get('object') else '-',
              'SAME' if r.get('same') else ('bytes %s refs %d' % (r.get('byte_differences'), len(r.get('refs_differ', []))) if 'byte_differences' in r else 'len/absent')))


if __name__ == '__main__':
    if len(sys.argv) < 5:
        sys.exit(__doc__)
    main(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5:])
