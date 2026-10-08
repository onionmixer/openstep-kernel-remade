#!/usr/bin/env python3
"""l2_compare.py -- plan 399 item 2: compare a linked kernel with the original image (read only).

  python3 10_tools/reconstruction/l2_compare.py LINKED ORIGINAL OUT.json

Reports
  header      Mach-O header fields of both files
  commands    load commands in order: segments (name, vmaddr, vmsize, fileoff, filesize,
              maxprot, initprot, nsects, flags) and their sections (addr, size, offset, align,
              reloff, nreloc, flags), SYMTAB (symoff, nsyms, stroff, strsize), UNIXTHREAD
              (flavor, count, state words), other commands raw
  sections    per section present in both (by segment and section name): equal address and
              size, and for file-backed sections the byte comparison -- number of differing
              bytes and the first differing intervals (S_ZEROFILL sections have no file
              bytes and are compared by address and size only)
  symbols     nlist entries split into STAB, local and external; external SECT and ABS
              symbols compared by name (value, type, section name); names only in one file;
              multiplicities
  commons     original __DATA,__common names: address in the linked file, difference
  file        sizes and SHA-256 of both files
"""
import sys, os, json, struct, hashlib, collections

S_ZEROFILL = 1


def sha(b):
    return hashlib.sha256(b).hexdigest()


def parse(d):
    magic, cpu, sub, ft, ncmds, sizeofcmds, flags = struct.unpack_from('<7I', d, 0)
    assert magic == 0xfeedface, hex(magic)
    out = {'header': {'cputype': cpu, 'cpusubtype': sub, 'filetype': ft, 'ncmds': ncmds,
                      'sizeofcmds': sizeofcmds, 'flags': flags},
           'commands': [], 'sections': [], 'symtab': None}
    o = 28
    for _ in range(ncmds):
        cmd, cs = struct.unpack_from('<2I', d, o)
        if cmd == 1:
            seg = d[o + 8:o + 24].rstrip(b'\0').decode()
            va, vs, fo, fs, mp, ip, ns, fl = struct.unpack_from('<8I', d, o + 24)
            secs = []
            p = o + 56
            for _ in range(ns):
                sn = d[p:p + 16].rstrip(b'\0').decode()
                sg = d[p + 16:p + 32].rstrip(b'\0').decode()
                ad, sz, off, al, ro, nr, sf = struct.unpack_from('<7I', d, p + 32)
                s = {'segname': sg, 'sectname': sn, 'addr': ad, 'size': sz, 'offset': off, 'align': al,
                     'reloff': ro, 'nreloc': nr, 'flags': sf, 'index': len(out['sections']) + 1}
                secs.append(s)
                out['sections'].append(s)
                p += 68
            out['commands'].append({'cmd': 'LC_SEGMENT', 'segname': seg, 'vmaddr': va, 'vmsize': vs, 'fileoff': fo,
                                    'filesize': fs, 'maxprot': mp, 'initprot': ip, 'nsects': ns, 'flags': fl,
                                    'sections': [{k: s[k] for k in ('sectname', 'addr', 'size', 'offset', 'align',
                                                                     'reloff', 'nreloc', 'flags')} for s in secs]})
        elif cmd == 2:
            so, ny, st, ss = struct.unpack_from('<4I', d, o + 8)
            out['symtab'] = (so, ny, st, ss)
            out['commands'].append({'cmd': 'LC_SYMTAB', 'symoff': so, 'nsyms': ny, 'stroff': st, 'strsize': ss})
        elif cmd == 5:
            fl, cnt = struct.unpack_from('<2I', d, o + 8)
            regs = list(struct.unpack_from('<%dI' % cnt, d, o + 16))
            out['commands'].append({'cmd': 'LC_UNIXTHREAD', 'flavor': fl, 'count': cnt, 'state': regs})
        else:
            out['commands'].append({'cmd': cmd, 'cmdsize': cs, 'raw': d[o:o + cs].hex()})
        o += cs
    syms = []
    if out['symtab']:
        so, ny, st, ss = out['symtab']
        for i in range(ny):
            strx, ty, sect, desc, val = struct.unpack_from('<IBBhI', d, so + 12 * i)
            e = d.index(b'\0', st + strx) if strx else st
            nm = d[st + strx:e].decode('latin1') if strx else ''
            syms.append({'name': nm, 'type': ty, 'sect': sect, 'desc': desc, 'value': val})
    out['symbols'] = syms
    return out


def intervals(a, b, base):
    """differing byte intervals of equal-length a, b as [start address, end address)"""
    out, i, n = [], 0, len(a)
    while i < n:
        if a[i] != b[i]:
            j = i
            while j < n and a[j] != b[j]:
                j += 1
            out.append([hex(base + i), hex(base + j)])
            i = j
        else:
            i += 1
    return out


def main():
    lp, op, outp = sys.argv[1:4]
    L, O = open(lp, 'rb').read(), open(op, 'rb').read()
    pl, po = parse(L), parse(O)
    rep = {'file': {'linked': {'path': lp, 'size': len(L), 'sha256': sha(L)},
                    'original': {'path': op, 'size': len(O), 'sha256': sha(O)}, 'identical': L == O},
           'header': {'linked': pl['header'], 'original': po['header'],
                      'equal': pl['header'] == po['header']},
           'commands': {'linked': pl['commands'], 'original': po['commands']}}
    # commands compared field by field (without raw dumps of unknown ones)
    cdiff = []
    for i in range(max(len(pl['commands']), len(po['commands']))):
        a = pl['commands'][i] if i < len(pl['commands']) else None
        b = po['commands'][i] if i < len(po['commands']) else None
        if a != b:
            cdiff.append({'index': i, 'linked': a, 'original': b})
    rep['commands']['differences'] = cdiff
    # sections
    ls = {(s['segname'], s['sectname']): s for s in pl['sections']}
    os_ = {(s['segname'], s['sectname']): s for s in po['sections']}
    secs = {}
    for k in sorted(set(ls) | set(os_)):
        a, b = ls.get(k), os_.get(k)
        r = {'in_linked': a is not None, 'in_original': b is not None}
        if a and b:
            r.update(addr=[hex(a['addr']), hex(b['addr'])], size=[a['size'], b['size']],
                     align=[a['align'], b['align']], flags=[a['flags'], b['flags']],
                     same_place=(a['addr'], a['size']) == (b['addr'], b['size']))
            if (b['flags'] & 0xff) != S_ZEROFILL and a['size'] == b['size']:
                x = L[a['offset']:a['offset'] + a['size']]
                y = O[b['offset']:b['offset'] + b['size']]
                iv = intervals(x, y, b['addr'])
                r.update(bytes_equal=x == y, differing_bytes=sum(1 for i in range(len(x)) if x[i] != y[i]),
                         intervals=len(iv), first_intervals=iv[:40])
        secs['%s,%s' % k] = r
    rep['sections'] = secs
    # symbols
    def split(p):
        st = [y for y in p['symbols'] if y['type'] & 0xe0]
        loc = [y for y in p['symbols'] if not y['type'] & 0xe0 and not y['type'] & 1]
        ext = [y for y in p['symbols'] if not y['type'] & 0xe0 and y['type'] & 1]
        return st, loc, ext
    sn = lambda p, y: ('%s,%s' % (p['sections'][y['sect'] - 1]['segname'], p['sections'][y['sect'] - 1]['sectname'])
                       if y['sect'] else '')
    lst, lloc, lext = split(pl)
    ost, oloc, oext = split(po)
    lm = collections.defaultdict(list)
    om = collections.defaultdict(list)
    for y in lext:
        lm[y['name']].append((y['value'], y['type'], sn(pl, y)))
    for y in oext:
        om[y['name']].append((y['value'], y['type'], sn(po, y)))
    differ = sorted((n, [hex(v) for v, _, _ in lm[n]], [hex(v) for v, _, _ in om[n]], [t for _, t, _ in lm[n]],
                     [t for _, t, _ in om[n]]) for n in set(lm) & set(om) if lm[n] != om[n])
    rep['symbols'] = {'linked': {'stab': len(lst), 'local': len(lloc), 'external': len(lext)},
                      'original': {'stab': len(ost), 'local': len(oloc), 'external': len(oext)},
                      'external_only_linked': sorted(set(lm) - set(om))[:200],
                      'external_only_linked_count': len(set(lm) - set(om)),
                      'external_only_original': sorted(set(om) - set(lm)),
                      'external_differ_count': len(differ), 'external_differ': differ[:400],
                      'external_names_in_symtab_order_equal': [y['name'] for y in lext] == [y['name'] for y in oext]}
    # commons
    oc = [(y['value'], y['name']) for y in oext if sn(po, y) == '__DATA,__common']
    cm = []
    for v, n in sorted(oc):
        lv = [x for x, _, s in lm.get(n, [])]
        cm.append({'name': n, 'original': hex(v), 'linked': [hex(x) for x in lv], 'equal': lv == [v]})
    rep['commons'] = {'original_names': len(oc), 'equal': sum(1 for c in cm if c['equal']),
                      'differ': [c for c in cm if not c['equal']]}
    json.dump(rep, open(outp, 'w'), indent=1)
    print('identical file:', rep['file']['identical'], 'sizes', len(L), len(O))
    print('header equal:', rep['header']['equal'], 'command differences:', len(cdiff))
    for k, r in secs.items():
        if not (r.get('same_place') and r.get('bytes_equal', True)):
            print('  section', k, {x: r.get(x) for x in ('in_linked', 'in_original', 'addr', 'size', 'differing_bytes', 'intervals')})
    print('symbols', rep['symbols']['linked'], rep['symbols']['original'], 'ext differ', len(differ),
          'only linked', rep['symbols']['external_only_linked_count'], 'only original', len(rep['symbols']['external_only_original']))
    print('commons equal', rep['commons']['equal'], 'of', rep['commons']['original_names'])


if __name__ == '__main__':
    main()
