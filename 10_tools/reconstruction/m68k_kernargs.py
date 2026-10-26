#!/usr/bin/env python3
"""m68k_kernargs.py -- plan 515: the kernargs table of an m68k object against the original (diagnostic).

  python3 10_tools/reconstruction/m68k_kernargs.py OBJECT.o RECORD.json

struct kernargs { char *name; int *i_ptr; u_char *c_ptr; } (NeXTMach next/machargs.c), 12 bytes,
big-endian, read up to and including the all-zero terminator.
Original: 03_original/m68k/binaries/mach_kernel from the symbol _kernargs (no rounding of its
address); name = NUL-terminated string at the pointer, i_ptr = nearest symbol at or below the value
plus the difference, c_ptr = the number.
Object: __DATA,__data from the symbol _kernargs; every word is resolved through the section's
relocation entries (plain extern: symbol name + stored addend; plain local: target section by number;
scattered: r_value gives the target, the stored word minus r_value is the addend); a word without a
relocation entry is a number.  A target in __cstring gives the string content, another target the
object symbol at or below it plus the difference.
Entries are compared in order: name content, i_ptr (symbol, addend) or 0, c_ptr number.
Plan 516 (codex review): a plain local relocation is resolved in the section its r_symbolnum names
(R_ABS 0 gives a number) and the word must lie in that section; a scattered relocation's effective
target is the stored word, which must lie in the section of r_value (strings included); only
VANILLA, 4-byte, not PC-relative entries are accepted; addends are signed; table walks and string
reads stay inside their section; the record gives the table extent and the input hashes.
Read-only apart from RECORD.json.
"""
import sys, os, json, struct, bisect, hashlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj

ORIG = '03_original/m68k/binaries/mach_kernel'
MACHO = '03_original/m68k/inventory/macho.json'
SYMS = '03_original/m68k/inventory/symbols.tsv'
ENT = 12


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def num(x):
    return int(x, 16) if isinstance(x, str) else x


def s32(v):
    return v - (1 << 32) if v & 0x80000000 else v


def cstr(b, o, end):
    i = b.index(b'\0', o, end)          # ValueError when no NUL inside the section
    return b[o:i].decode('latin1')


def original():
    secs = json.load(open(MACHO))['sections']
    for s in secs:
        s['address'], s['size'], s['file_offset'] = num(s['address']), num(s['size']), num(s['file_offset'])
    b = open(ORIG, 'rb').read()

    def sec(va):
        for s in secs:
            if s['address'] <= va < s['address'] + s['size'] and s['file_offset']:
                return s
        raise ValueError('not file-backed: %#x' % va)

    def off(va):
        s = sec(va)
        return s['file_offset'] + va - s['address']

    def name(va):
        s = sec(va)
        assert s['name'] == '__cstring', (hex(va), s['name'])
        return cstr(b, off(va), s['file_offset'] + s['size'])
    rows = [l.rstrip('\n').split('\t') for l in open(SYMS)]
    h = rows[0]
    vi, ni = h.index('value'), h.index('name')
    syms = sorted((int(r[vi], 16), r[ni]) for r in rows[1:] if r[vi].startswith('0x'))
    addrs = [a for a, _ in syms]

    def sym(v):
        k = bisect.bisect_right(addrs, v) - 1
        return [syms[k][1], v - syms[k][0]]
    start = [a for a, n in syms if n == '_kernargs']
    assert len(start) == 1, start
    ts = sec(start[0])
    o, end = off(start[0]), ts['file_offset'] + ts['size']
    out = []
    while True:
        assert o + ENT * (len(out) + 1) <= end, 'no terminator inside ' + ts['name']
        n, ip, cp = struct.unpack_from('>III', b, o + ENT * len(out))
        e = dict(name=None if not n else name(n), i_ptr=sym(ip) if ip else 0, c_ptr=cp)
        out.append(e)
        if (n, ip, cp) == (0, 0, 0):
            nxt = [a for a, _ in syms if a > start[0]]
            return dict(address=hex(start[0]), section=ts['name'], extent=ENT * len(out),
                        next_symbol_gap=min(nxt) - start[0], entries=out)


def objtable(path):
    d = open(path, 'rb').read()
    o = macho_obj.parse(d)
    assert o['endian'] == 'big' and o['cputype'] == macho_obj.CPU_M68K
    secs = o['sections']
    data = [s for s in secs if (s['segname'], s['sectname']) == ('__DATA', '__data')]
    assert len(data) == 1
    ds = data[0]
    k = [y for y in o['symbols'] if y['name'] == '_kernargs' and y['kind'] == 'SECT' and not y['stab']]
    assert len(k) == 1 and k[0]['sect'] == ds['index'], k
    raw = d[ds['offset']:ds['offset'] + ds['size']]
    rel = {}
    for r in ds['relocs']:
        assert r['address'] not in rel, 'two relocations at one address'
        rel[r['address']] = r
    defs = sorted((y['value'], y['name']) for y in o['symbols'] if y['kind'] == 'SECT' and not y['stab'] and y['name'])
    dv = [v for v, _ in defs]

    def sec_of(a):
        for s in secs:
            if s['addr'] <= a < s['addr'] + s['size']:
                return s
        return None

    def target(s, a):
        assert s['addr'] <= a < s['addr'] + s['size'], ('target outside its section', hex(a), s['sectname'])
        if s['sectname'] == '__cstring':
            return ['cstring', cstr(d, s['offset'] + a - s['addr'], s['offset'] + s['size'])]
        j = bisect.bisect_right(dv, a) - 1
        assert j >= 0, hex(a)
        return [defs[j][1], a - defs[j][0]]

    def word(at):
        w = struct.unpack_from('>I', raw, at)[0]
        r = rel.get(at)
        if r is None:
            return ['number', w]
        assert r['type'] == 0 and r['length'] == 2 and not r['pcrel'], ('unsupported relocation', r)
        if r['scattered']:
            s = sec_of(r['value'])
            assert s is not None, r
            return target(s, w)                 # effective target = stored word, in r_value's section
        if r['extern']:
            return [o['symbols'][r['symbolnum']]['name'], s32(w)]
        if r['symbolnum'] == 0:                 # R_ABS
            return ['number', w]
        return target(secs[r['symbolnum'] - 1], w)
    base = k[0]['value'] - ds['addr']
    out = []
    while True:
        at = base + ENT * len(out)
        assert at + ENT <= ds['size'], 'no terminator inside __data'
        n, ip, cp = word(at), word(at + 4), word(at + 8)
        e = dict(name=n[1] if n[0] == 'cstring' else (None if n == ['number', 0] else n),
                 i_ptr=0 if ip == ['number', 0] else ip, c_ptr=cp[1] if cp[0] == 'number' else cp)
        out.append(e)
        if e['name'] is None and e['i_ptr'] == 0 and e['c_ptr'] == 0:
            return dict(data_size=ds['size'], kernargs_offset=base, extent=ENT * len(out), relocs=len(ds['relocs']),
                        reloc_kinds=sorted({(r['scattered'], r.get('extern'), r['type']) for r in ds['relocs']}, key=str),
                        entries=out)


def main(objp, outj):
    a, b = original(), objtable(objp)
    n = max(len(a['entries']), len(b['entries']))
    diffs = []
    for i in range(n):
        x = a['entries'][i] if i < len(a['entries']) else None
        y = b['entries'][i] if i < len(b['entries']) else None
        if x != y:
            diffs.append(dict(index=i, original=x, object=y))
    rec = dict(plan=515, tool=os.path.relpath(os.path.abspath(__file__)), tool_sha256=sha(os.path.abspath(__file__)),
               original=ORIG, original_sha256=sha(ORIG), object=objp, object_sha256=sha(objp),
               inputs={p: sha(p) for p in (MACHO, SYMS, os.path.relpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'macho_obj.py')))},
               original_entries=len(a['entries']), object_entries=len(b['entries']), equal=not diffs,
               extent_equal=a['extent'] == b['extent'], diffs=diffs,
               original_table=a, object_table=b)
    json.dump(rec, open(outj, 'w'), indent=1)
    print('entries original %d object %d (incl. terminator) equal %s diffs %d extent %d/%d (object __data %d, original next symbol %d)'
          % (len(a['entries']), len(b['entries']), not diffs, len(diffs), a['extent'], b['extent'], b['data_size'], a['next_symbol_gap']))
    for x in diffs[:20]:
        print(' ', x)


if __name__ == '__main__':
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    main(sys.argv[1], sys.argv[2])
