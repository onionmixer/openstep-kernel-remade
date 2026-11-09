#!/usr/bin/env python3
"""m7_m68k_compare.py -- plan 778.16 P2: layered comparison of a linked m68k kernel with the original (big-endian).

  python3 10_tools/reconstruction/m7_m68k_compare.py LINK.json NAME FILE OUT.json

LINK.json is a link record (scratch/p778/p2_build.py): per link NAME the object order, the predicted contribution
addresses (layout), the reference (original) contribution addresses (ref_layout), the relocation sites whose value is
predicted to change (sites: [offset, delta, kind]) and the expected external symbol values (expect_syms).
Layers (plan 778.3 P4 / 778.16 (3)):
  B  header and load commands, field by field (segments, sections incl. reloff/nreloc/flags/reserved, LC_SYMTAB)
  C  symbols: stripped file -> physical tuples and string table bytes; otherwise external symbols vs the original,
     local/STABS counts; expected values from the link record
  D  section bytes: raw comparison at equal addresses, and per input contribution (predicted vs reference address);
     differing bytes inside a predicted relocation site are checked as whole 4-byte words (delta), others listed
  E  LC_UNIXTHREAD bytes
  F  whole file: differing byte ranges by file region
Read-only; python 3 standard library.  Byte equality is not a proof of source identity.
"""
import sys, os, json, struct, hashlib, bisect

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import m7_m68k_link as L

SEGF = ('vmaddr', 'vmsize', 'fileoff', 'filesize', 'maxprot', 'initprot', 'nsects', 'flags')
SECF = ('addr', 'size', 'offset', 'align', 'reloff', 'nreloc', 'flags', 'reserved1', 'reserved2')


def macho(b):
    h = dict(zip(('magic', 'cputype', 'cpusubtype', 'filetype', 'ncmds', 'sizeofcmds', 'flags'), struct.unpack('>7I', b[:28])))
    cmds, o = [], 28
    for i in range(h['ncmds']):
        cmd, cs = struct.unpack('>2I', b[o:o + 8])
        c = dict(cmd=cmd, cmdsize=cs, off=o)
        if cmd == 1:
            c['segname'] = b[o + 8:o + 24].rstrip(b'\0').decode()
            c.update(zip(SEGF, struct.unpack('>4I2i2I', b[o + 24:o + 56])))
            c['sects'] = []
            for j in range(c['nsects']):
                q = o + 56 + 68 * j
                s = dict(sectname=b[q:q + 16].rstrip(b'\0').decode(), segname=b[q + 16:q + 32].rstrip(b'\0').decode())
                s.update(zip(SECF, struct.unpack('>9I', b[q + 32:q + 68])))
                c['sects'].append(s)
        elif cmd == 2:
            c.update(zip(('symoff', 'nsyms', 'stroff', 'strsize'), struct.unpack('>4I', b[o + 8:o + 24])))
        else:
            c['raw'] = b[o:o + cs].hex()
        cmds.append(c)
        o += cs
    return h, cmds


def layer_b(hb, cb, ho, co):
    diffs = []
    for k in hb:
        if hb[k] != ho[k]:
            diffs.append(['header.' + k, hb[k], ho[k]])
    if len(cb) != len(co):
        diffs.append(['ncmds-list', [c['cmd'] for c in cb], [c['cmd'] for c in co]])
    for i, (x, y) in enumerate(zip(cb, co)):
        for k in sorted(set(x) | set(y)):
            if k in ('sects', 'off'):
                continue
            if x.get(k) != y.get(k):
                diffs.append(['cmd%d.%s' % (i, k), x.get(k), y.get(k)])
        for j, (s, t) in enumerate(zip(x.get('sects', []), y.get('sects', []))):
            for k in s:
                if s[k] != t.get(k):
                    diffs.append(['cmd%d.sect%d(%s).%s' % (i, j, t.get('sectname'), k), s[k], t.get(k)])
        if len(x.get('sects', [])) != len(y.get('sects', [])):
            diffs.append(['cmd%d.nsects-list' % i, len(x.get('sects', [])), len(y.get('sects', []))])
    return diffs


def symtab(b, cmds):
    st = [c for c in cmds if c['cmd'] == 2]
    if not st:
        return None, None, b''
    c = st[0]
    syms = []
    for k in range(c['nsyms']):
        sx, t, sc, de, v = struct.unpack('>IBBhI', b[c['symoff'] + 12 * k:c['symoff'] + 12 * k + 12])
        s0 = c['stroff'] + sx
        nm = b[s0:b.index(b'\0', s0)].decode('latin1') if sx else ''
        syms.append((sx, t, sc, de, v, nm))
    return c, syms, b[c['stroff']:c['stroff'] + c['strsize']]


def ranges(offs):
    out = []
    for x in sorted(offs):
        if out and x == out[-1][1]:
            out[-1][1] = x + 1
        else:
            out.append([x, x + 1])
    return out


def main(linkj, name, path, outp):
    rec = json.load(open(linkj))
    lk = rec['links'][name]
    ob = open(path, 'rb').read()
    W = L.World()
    orig = W.O['raw']
    res = dict(tool='m7_m68k_compare.py', tool_sha256=hashlib.sha256(open(__file__, 'rb').read()).hexdigest(),
               link_record=linkj, link_record_sha256=hashlib.sha256(open(linkj, 'rb').read()).hexdigest(),
               link=name, file=path, file_sha256=hashlib.sha256(ob).hexdigest(), file_size=len(ob),
               original_size=len(orig))
    hb, cb = macho(ob)
    ho, co = macho(orig)
    res['B'] = dict(diffs=layer_b(hb, cb, ho, co), header=hb,
                    segments=[{k: c.get(k) for k in ('segname',) + SEGF} for c in cb if c['cmd'] == 1])
    # ---- C
    stc, syms, strb = symtab(ob, cb)
    sto, osyms, ostrb = symtab(orig, co)
    C = {}
    if syms is not None:
        ext = [s for s in syms if s[1] & 1 and not s[1] & 0xe0]
        loc = [s for s in syms if not s[1] & 1 and not s[1] & 0xe0]
        stab = [s for s in syms if s[1] & 0xe0]
        C.update(nsyms=len(syms), external=len(ext), local=len(loc), stabs=len(stab))
        oe = {s[5]: s[1:5] for s in osyms}
        me = {}
        dup = []
        for s in ext:
            if s[5] in me:
                dup.append(s[5])
            me[s[5]] = s[1:5]
        C['external_duplicates'] = dup[:20]
        C['only_ours'] = sorted(set(me) - set(oe))[:50]
        C['only_original'] = sorted(set(oe) - set(me))[:50]
        C['n_only_ours'], C['n_only_original'] = len(set(me) - set(oe)), len(set(oe) - set(me))
        dif = [[n, me[n], oe[n]] for n in sorted(set(me) & set(oe)) if me[n] != oe[n]]
        C['external_tuple_differences'] = len(dif)
        C['external_tuple_first'] = dif[:30]
        exp = lk['expect_syms']
        bad = [[n, me.get(n, [None] * 4)[3], v] for n, v in sorted(exp.items()) if me.get(n, [None] * 4)[3] != v]
        C['expected_value_mismatch'] = len(bad)
        C['expected_value_first'] = bad[:30]
        C['physical_tuples_equal'] = syms == osyms
        if syms != osyms:
            fi = next((i for i, (x, y) in enumerate(zip(syms, osyms)) if x != y), min(len(syms), len(osyms)))
            C['first_physical_difference'] = [fi, syms[fi] if fi < len(syms) else None, osyms[fi] if fi < len(osyms) else None]
        C['string_table_equal'] = strb == ostrb
        C['string_table_size'] = [len(strb), len(ostrb)]
        C['name_order_sorted_external'] = [s[5] for s in ext] == sorted(s[5] for s in ext)
    res['C'] = C
    # ---- D
    osec = {s['name']: s for s in W.O['sects']}
    msec = {}
    for c in cb:
        for s in c.get('sects', []):
            msec[s['sectname']] = s
    D = {}
    for sn in ('__text', '__cstring', '__const', '__data'):
        if sn not in msec:
            D[sn] = dict(missing=True)
            continue
        m, o = msec[sn], osec[sn]
        mb = ob[m['offset']:m['offset'] + m['size']]
        n = min(len(mb), o['size']) if m['addr'] == o['addr'] else 0
        offs = [i for i in range(n) if mb[i] != o['data'][i]]
        D[sn] = dict(addr=[m['addr'], o['addr']], size=[m['size'], o['size']], raw_differ=len(offs),
                     raw_ranges=[[hex(o['addr'] + a), b - a] for a, b in ranges(offs)][:60], n_raw_ranges=len(ranges(offs)))
    # per-contribution
    P = {}
    for k, x in rec['objects'].items():
        P[k] = L.parse(x['path'])
    contrib = dict(checked=0, equal=0, site_words_ok=0, site_words_bad=[], unexplained=[], expected_unchanged=[],
                   fill_bytes=0, fill_differ=[])
    covered = {sn: [] for sn in ('__text', '__const', '__data')}
    for k in lk['order']:
        if k not in P:
            continue
        for s in P[k]['sects']:
            sn = s['name']
            if sn not in covered or not s['size']:
                continue
            a = lk['layout'][k][sn]
            r = rec['ref_layout'][k][sn]
            m = msec[sn]
            mine = ob[m['offset'] + a - m['addr']:m['offset'] + a - m['addr'] + s['size']]
            o = osec[sn]
            ref = o['data'][r - o['addr']:r - o['addr'] + s['size']]
            covered[sn].append((a, a + s['size']))
            contrib['checked'] += 1
            sites = {x[0]: x for x in lk['sites'].get(k, {}).get(sn, [])}
            difo = [i for i in range(s['size']) if i >= len(ref) or mine[i] != ref[i]]
            if not difo and not sites:
                contrib['equal'] += 1
                continue
            done = set()
            for off, (o0, delta, kd) in sorted(sites.items()):
                w1 = struct.unpack('>I', mine[off:off + 4])[0]
                w0 = struct.unpack('>I', ref[off:off + 4])[0]
                if (w1 - w0) & 0xffffffff == delta & 0xffffffff:
                    contrib['site_words_ok'] += 1
                else:
                    contrib['site_words_bad'].append([k, sn, off, hex(w1), hex(w0), delta, kd])
                done.update(range(off, off + 4))
            rest = [i for i in difo if i not in done]
            if rest:
                syms_k = sorted((x['value'] - s['addr'], x['name']) for x in P[k]['syms']
                                if not x['type'] & 0xe0 and L.kind(x) == 'SECT' and P[k]['sects'][x['sect'] - 1]['name'] == sn)
                for a0, b0 in ranges(rest):
                    j = bisect.bisect_right([y[0] for y in syms_k], a0) - 1
                    contrib['unexplained'].append([k, sn, a0, b0 - a0, hex(a + a0), syms_k[j][1] if j >= 0 else None])
    for sn, cov in covered.items():
        m, o = msec[sn], osec[sn]
        cov.sort()
        p = m['addr']
        gaps = []
        for a, b in cov + [(m['addr'] + m['size'], None)]:
            if a > p:
                gaps.append((p, a))
            p = max(p, b) if b else p
        for a, b in gaps:
            for x in range(a, b):
                contrib['fill_bytes'] += 1
                mb = ob[m['offset'] + x - m['addr']]
                obb = o['data'][x - o['addr']] if o['addr'] <= x < o['addr'] + o['size'] else None
                if mb != 0 or mb != obb:
                    contrib['fill_differ'].append([sn, hex(x), mb, obb])
    contrib['n_unexplained'] = len(contrib['unexplained'])
    contrib['n_site_words_bad'] = len(contrib['site_words_bad'])
    D['contributions'] = contrib
    res['D'] = D
    # ---- E
    tb = [c['raw'] for c in cb if c['cmd'] == 5]
    to = [c['raw'] for c in co if c['cmd'] == 5]
    res['E'] = dict(equal=tb == to, ours=tb, original=to)
    # ---- F
    regions = [('header', 0, 28), ('loadcmds', 28, 28 + ho['sizeofcmds'])]
    for c in co:
        for s in c.get('sects', []):
            if s['offset']:
                regions.append((s['sectname'], s['offset'], s['offset'] + s['size']))
        if c['cmd'] == 2:
            regions += [('symtab', c['symoff'], c['symoff'] + 12 * c['nsyms']), ('strtab', c['stroff'], c['stroff'] + c['strsize'])]
    n = min(len(ob), len(orig))
    offs = [i for i in range(n) if ob[i] != orig[i]]

    def region(x):
        for nm, a, b in regions:
            if a <= x < b:
                return nm
        return 'padding'
    rr = ranges(offs)
    byreg = {}
    for a, b in rr:
        byreg.setdefault(region(a), [0, 0])
        byreg[region(a)][0] += 1
        byreg[region(a)][1] += b - a
    res['F'] = dict(identical=ob == orig, size=[len(ob), len(orig)], differ_bytes=len(offs), ranges=len(rr),
                    by_region=byreg, first_ranges=[[a, b - a, region(a)] for a, b in rr[:60]])
    json.dump(res, open(outp, 'w'), indent=1, default=str)
    print(name, path, 'B', len(res['B']['diffs']), 'C', {k: C.get(k) for k in ('nsyms', 'external', 'local', 'stabs',
          'external_tuple_differences', 'expected_value_mismatch', 'physical_tuples_equal', 'string_table_equal')},
          'D', {sn: D[sn].get('raw_differ') for sn in ('__text', '__cstring', '__const', '__data')},
          'contrib', {k: contrib[k] for k in ('checked', 'equal', 'site_words_ok', 'n_site_words_bad', 'n_unexplained', 'fill_bytes')},
          'fill_differ', len(contrib['fill_differ']), 'E', res['E']['equal'], 'F', res['F']['identical'], res['F']['differ_bytes'],
          res['F']['by_region'])


if __name__ == '__main__':
    if len(sys.argv) != 5:
        sys.exit(__doc__)
    main(*sys.argv[1:])
