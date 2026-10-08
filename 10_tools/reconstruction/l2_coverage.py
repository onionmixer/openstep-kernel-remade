#!/usr/bin/env python3
"""l2_coverage.py -- plan 396 (L2-A), plan 397 B1, plan 398 (env L2_COVER=s6l1): what the rebuilt objects do and do not supply for
the original kernel image.  Read-only: nothing is built, no record is changed.

  python3 10_tools/reconstruction/l2_coverage.py OUT.json

Inputs: the plan 394/395 rebuild results 09_validation/reconstruction/s6-l0-*.json (one
selected object per forms row; rows 184/185/208 come from run s6l0-p395a and row 244 from
s6l0-p395b, plan 395), their L1 json, 06_reconstruction/objects_toolchain.tsv (libgcc
members linked with -lcc, D051), the original image and its inventory.

Reports (plan 396 item 4):
  rows           selected object, object SHA-256, L1 json per forms row
  regular        per original non-literal, non-zero-fill section: placed intervals (method,
                 containment, alignment, overlaps) and unassigned intervals with their
                 non-zero byte count and whether the gap equals the next placed object's
                 alignment padding; original symbols inside unassigned intervals
  bss            inferred __bss intervals (L1), unplaced __bss, size sums
  common         original __common names vs object COMMON requests (max size, declarers),
                 strong definitions; next distinct original address as an upper bound
  cstring        S_CSTRING_LITERALS sections: original strings (offset, bytes) not supplied
                 by any object, and object strings absent from the original
  literal_ptrs   S_LITERAL_POINTERS sections: multiset of pointed-to strings, original vs
                 objects
  symbols        original external / absolute names without a definition in the objects or
                 libgcc members; names defined more than once; definitions the original lacks
"""
import sys, os, csv, json, glob, struct, hashlib, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj as M

IMG = '03_original/x86/binaries/mach_kernel'
V = '09_validation/reconstruction/'
SUPERSEDE = {184: 's6l0-p395a', 185: 's6l0-p395a', 208: 's6l0-p395a', 244: 's6l0-p395b'}
S_CSTRING_LITERALS, S_LITERAL_POINTERS, S_ZEROFILL = 2, 5, 1


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def select_rows():
    # plan 398: env L2_COVER=s6l1 reads the plan 398 rebuild (rows 1..402, s6-l1-<G>-s6l1-*.json);
    # a row is accepted when it equals the baseline L1 or meets its plan 398 expectation
    if os.environ.get('L2_COVER') == 's6l1':
        out = {}
        for f in sorted(glob.glob(V + 's6-l1-*-s6l1-*.json')):
            for x in json.load(open(f))['objects']:
                assert x['n'] not in out, x['n']
                assert (x.get('same_as_baseline') or x.get('expected_ok')) and not x.get('problem'), x['n']
                assert sha(x['obj']) == x['obj_sha256'], x['n']
                out[x['n']] = x
        assert sorted(out) == list(range(1, len(out) + 1)), 'rows not contiguous'
        return out
    seen = {}
    for f in sorted(glob.glob(V + 's6-l0-*.json')):
        d = json.load(open(f))
        for x in d['objects']:
            seen.setdefault(x['n'], []).append((d['run'], x))
    out = {}
    for n, v in seen.items():
        want = SUPERSEDE.get(n)
        pick = [x for r, x in v if r == want] if want else [x for r, x in v]
        assert len(pick) == 1, (n, [r for r, _ in v])
        x = pick[0]
        assert x.get('same_as_baseline') and not x.get('problem'), n
        assert sha(x['obj']) == x['obj_sha256'], n
        out[n] = x
    return out


def main():
    outp = sys.argv[1]
    img = open(IMG, 'rb').read()
    im = M.parse(img)
    isec = {(s['segname'], s['sectname']): s for s in im['sections']}
    toff = lambda va, s: s['offset'] + va - s['addr']   # image file offset of a VA in section s

    def img_bytes(sec, a, b):
        s = isec[sec]
        return img[toff(a, s):toff(b, s)]

    rows = select_rows()
    rep = {'image_sha256': sha(IMG), 'rows': {}, 'regular': {}, 'bss': {}, 'common': {}, 'cstring': {},
           'literal_ptrs': {}, 'symbols': {}}
    objs = {}
    for n, x in sorted(rows.items()):
        raw = open(x['obj'], 'rb').read()
        objs[n] = (raw, M.parse(raw), json.load(open(x['l1'])))
        rep['rows'][n] = {'object': x['object'], 'source': x['source'], 'obj': x['obj'],
                          'obj_sha256': x['obj_sha256'], 'l1': x['l1']}

    # libgcc members (text ranges from the toolchain table)
    lib = []
    for r in csv.reader(open('06_reconstruction/objects_toolchain.tsv'), delimiter='\t'):
        if r and r[0].startswith('x86'):
            lib.append((int(r[3], 16), int(r[4], 16), r[0]))

    # ---- regular sections
    placed = collections.defaultdict(list)   # (seg,sect) -> [(lo, hi, row, method, align)]
    for n, (raw, m, l1) in objs.items():
        oalign = {(s['segname'], s['sectname']): s['align'] for s in m['sections']}
        for k, v in l1['sections'].items():
            seg, sect = k.split(',')
            s = isec.get((seg, sect))
            if not s or s['flags'] & 0xff in (S_CSTRING_LITERALS, S_LITERAL_POINTERS, S_ZEROFILL):
                continue
            if v.get('address') is None or not v.get('size'):
                continue
            placed[(seg, sect)].append((v['address'], v['address'] + v['size'], n, v['placement'], oalign.get((seg, sect))))
    for lo, hi, name in lib:
        placed[('__TEXT', '__text')].append((lo, hi, name, 'libgcc (objects_toolchain.tsv)', 2))
    # plan 397 B1: libgcc _udivdi3.o __const (256 B ___clz_tab; x86-libcc-libgcc2.md says its section
    # bytes equal the original) -- checked here independently against the bit_length table
    clz_lo = 0x1d68b0
    clz_ok = img_bytes(('__TEXT', '__const'), clz_lo, clz_lo + 256) == bytes(i.bit_length() for i in range(256))
    if clz_ok:
        placed[('__TEXT', '__const')].append((clz_lo, clz_lo + 256, 'x86-libcc-_udivdi3',
                                              'libgcc __const (x86-libcc-libgcc2.md; bit_length table)', 2))
    # plan 397 B1: sections L1 left unplaced (no symbol) are placed conditionally: in link order
    # (object __text order) right after the previous placed object of that section, aligned, if the
    # object bytes (no relocations) equal the original bytes there and the next placed object is not
    # overlapped.  Same bytes occur more than once, so this is supported by order, not a unique match.
    taddr = {n: (l1['sections'].get('__TEXT,__text') or {}).get('address') for n, (raw, m, l1) in objs.items()}
    # plan 398: link-order key; an object without __text (data-only) goes right after the object
    # with __text whose placed section of the same kind starts last before its own (same section)
    lkey = {n: float(t) for n, t in taddr.items() if t is not None}
    for n, (raw, m, l1) in objs.items():
        if taddr[n] is not None:
            continue
        best = None
        for k, v in l1['sections'].items():
            if k == '__TEXT,__text' or v.get('address') is None or not v.get('size'):
                continue
            prev = [(objs[o][2]['sections'][k]['address'], o) for o in objs if taddr[o] is not None
                    and (objs[o][2]['sections'].get(k) or {}).get('address') is not None
                    and objs[o][2]['sections'][k]['address'] < v['address']]
            if prev:
                a0, o = max(prev)
                cand = taddr[o] + 0.5 + (v['address'] - a0) * 1e-9
                best = cand if best is None else min(best, cand)
        assert best is not None, ('no link position for', n)
        lkey[n] = best
    rep['link_keys_data_only'] = {n: lkey[n] for n in objs if taddr[n] is None}
    cond = []
    for n in sorted(objs, key=lambda n: lkey[n]):
        raw, m, l1 = objs[n]
        for os_ in m['sections']:
            key = (os_['segname'], os_['sectname'])
            s = isec.get(key)
            if (not s or not os_['size'] or s['flags'] & 0xff in (S_CSTRING_LITERALS, S_LITERAL_POINTERS, S_ZEROFILL)
                    or (l1['sections'].get('%s,%s' % key) or {}).get('address') is not None):
                continue
            before = [p for p in placed[key] if isinstance(p[2], int) and lkey[p[2]] < lkey[n]]
            after = [p for p in placed[key] if isinstance(p[2], int) and lkey[p[2]] > lkey[n]]
            prev_end = max(p[1] for p in before) if before else s['addr']
            nxt = min(p[0] for p in after) if after else s['addr'] + s['size']
            al = 1 << os_['align']
            lo = (prev_end + al - 1) // al * al
            hi = lo + os_['size']
            same = (os_['nreloc'] == 0 and hi <= nxt
                    and raw[os_['offset']:os_['offset'] + os_['size']] == img_bytes(key, lo, hi))
            cond.append({'row': n, 'section': '%s,%s' % key, 'address': hex(lo), 'size': os_['size'],
                         'align': os_['align'], 'bytes_equal': same})
            if same:
                placed[key].append((lo, hi, n, 'conditional: link order + bytes (plan 397 B1)', os_['align']))
    rep['conditional_placements'] = cond
    rep['libgcc_const'] = {'address': hex(clz_lo), 'size': 256, 'bit_length_table': clz_ok}
    symbols = [r for r in csv.DictReader(open('03_original/x86/inventory/symbols.tsv'), delimiter='\t') if r['debug'] == '0']
    for key, s in isec.items():
        if s['flags'] & 0xff in (S_CSTRING_LITERALS, S_LITERAL_POINTERS, S_ZEROFILL) or not s['size']:
            continue
        P = sorted(placed.get(key, []), key=lambda t: t[0])
        lo0, hi0 = s['addr'], s['addr'] + s['size']
        problems = []
        for a in P:
            if not (lo0 <= a[0] and a[1] <= hi0):
                problems.append(('outside section', a[:3]))
            if a[4] is not None and a[0] % (1 << a[4]):
                problems.append(('misaligned', a[:3], a[4]))
        for a, b in zip(P, P[1:]):
            if b[0] < a[1]:
                problems.append(('overlap', a[:3], b[:3]))
        gaps, cur = [], lo0
        for i, a in enumerate(P):
            if a[0] > cur:
                gaps.append((cur, a[0], a))
            cur = max(cur, a[1])
        if hi0 > cur:
            gaps.append((cur, hi0, None))
        G = []
        for g0, g1, nxt in gaps:
            b = img_bytes(key, g0, g1)
            pad = None
            if nxt is not None and nxt[4] is not None:
                al = 1 << nxt[4]
                pad = (g1 % al == 0) and (g1 - g0) < al and not any(b)
            inside = sorted((r['name'], r['value']) for r in symbols if g0 <= int(r['value'], 16) < g1
                            and int(r['type'], 16) & 0xe == 0xe)
            G.append({'lo': hex(g0), 'hi': hex(g1), 'size': g1 - g0, 'nonzero': sum(1 for c in b if c),
                      'alignment_padding_of_next': pad, 'next': nxt[2] if nxt else None, 'symbols': inside[:20]})
        cov = sum(a[1] - a[0] for a in P)
        rep['regular']['%s,%s' % key] = {'size': s['size'], 'placed': len(P), 'covered': cov, 'problems': problems,
                                         'gaps': G, 'gap_bytes': sum(g['size'] for g in G),
                                         'gap_nonzero_bytes': sum(g['nonzero'] for g in G),
                                         'gaps_not_padding': [g for g in G if not g['alignment_padding_of_next']]}

    # ---- __bss
    inf, unpl, tot = [], [], 0
    for n, (raw, m, l1) in objs.items():
        for s in m['sections']:
            if (s['segname'], s['sectname']) == ('__DATA', '__bss'):
                tot += s['size']
        b = l1['sections'].get('__DATA,__bss')
        if b and b.get('size'):
            if b.get('placement') == 'inferred' and b.get('address') is not None:
                inf.append((b['address'], b['address'] + b['size'], n))
            else:
                unpl.append((n, b['size'], b.get('placement')))
    inf.sort()
    rep['bss'] = {'original_size': isec[('__DATA', '__bss')]['size'], 'object_bss_total': tot,
                  'inferred_union': sum(b - a for a, b, _ in inf),
                  'inferred_overlaps': [(x, y) for x, y in zip(inf, inf[1:]) if y[0] < x[1]],
                  'unplaced': unpl, 'unplaced_total': sum(s for _, s, _ in unpl)}
    rep['bss']['remaining_after_inferred'] = rep['bss']['original_size'] - rep['bss']['inferred_union']
    rep['bss']['excess_before_alignment'] = rep['bss']['unplaced_total'] - rep['bss']['remaining_after_inferred']

    # ---- symbols and commons
    sectname = {s['index']: (s['segname'], s['sectname']) for s in im['sections']}
    odefs = collections.defaultdict(list)   # name -> [(row, kind, size)]
    for n, (raw, m, l1) in objs.items():
        for y in m['symbols']:
            if y['stab'] or not y['ext']:
                continue
            if y['kind'] in ('SECT', 'ABS'):
                odefs[y['name']].append((n, y['kind'], None, bool(y['type'] & 0x10)))
            elif y['kind'] == 'COMMON':
                odefs[y['name']].append((n, 'COMMON', y['value'], bool(y['type'] & 0x10)))
    for _, _, name in lib:
        sym = '_' + name.split('-')[-1]   # x86-libcc-_muldi3 -> __muldi3 (C name _muldi3 + leading _)
        odefs[sym].append((name, 'LIBGCC', None, False))
    orig = {r['name']: r for r in symbols if int(r['type'], 16) & 0xe in (0xe, 0x2)}
    missing = collections.Counter()
    miss_list = []
    for name, r in orig.items():
        if name in odefs:
            continue
        if name == '__mh_execute_header':
            continue
        sec = sectname.get(int(r['section'])) if r['section'] != '0' else ('ABS',)
        missing[','.join(sec)] += 1
        miss_list.append((name, r['value'], ','.join(sec)))
    strong = {k: [d for d in v if d[1] in ('SECT', 'ABS', 'LIBGCC')] for k, v in odefs.items()}
    dups = {k: v for k, v in strong.items() if len(v) > 1}
    extra = sorted(k for k in odefs if k not in orig)
    rep['symbols'] = {'original_defined': len(orig), 'missing_by_section': dict(missing),
                      'missing': sorted(miss_list, key=lambda t: t[1]), 'strong_duplicates': dups,
                      'defined_not_in_original': extra[:200], 'defined_not_in_original_count': len(extra),
                      'private_extern': sorted(k for k, v in odefs.items() if any(d[3] for d in v)),
                      'linker_defined': ['__mh_execute_header']}
    commons = sorted((int(r['value'], 16), r['name']) for r in symbols if r['section'] == '6')
    caddr = sorted({a for a, _ in commons})
    cend = isec[('__DATA', '__common')]['addr'] + isec[('__DATA', '__common')]['size']
    over, nocommon = [], []
    for a, name in commons:
        req = [d for d in odefs.get(name, []) if d[1] == 'COMMON']
        st = [d for d in odefs.get(name, []) if d[1] != 'COMMON']
        bound = next((x for x in caddr if x > a), cend) - a
        if req:
            mx = max(d[2] for d in req)
            if mx > bound:
                over.append((name, hex(a), mx, bound))
        elif not st:
            nocommon.append((name, hex(a)))
    data_named_commons = sorted(k for k, v in odefs.items() if any(d[1] == 'COMMON' for d in v)
                                and k in orig and orig[k]['section'] != '6')
    rep['common'] = {'original_names': len(commons), 'request_exceeds_upper_bound': over,
                     'original_common_without_object_request_or_definition': nocommon,
                     'common_requests_for_names_the_original_defines_outside_common': data_named_commons}

    # plan 397 B1: first-mention simulation of __common allocation order (hypothesis, plan 397 0 (j)):
    # objects in __text order, each object's UNDF/COMMON symbols in symbol-table order; a name's place is
    # its first mention.  Reported: names mentioned, longest increasing subsequence against the original
    # address order, names outside it (with the first-mentioning object), names nobody mentions.
    import bisect
    crank = {name: i for i, (_, name) in enumerate(commons)}
    seen, seqn = {}, []
    for n in sorted(objs, key=lambda n: lkey[n]):
        for y in objs[n][1]['symbols']:
            if not y['stab'] and y['kind'] in ('UNDF', 'COMMON') and y['name'] in crank and y['name'] not in seen:
                seen[y['name']] = (n, y['kind'])
                seqn.append(y['name'])
    seq = [crank[x] for x in seqn]
    tails, tidx, prevp = [], [], [-1] * len(seq)
    for i, v in enumerate(seq):
        k = bisect.bisect_left(tails, v)
        if k == len(tails):
            tails.append(v); tidx.append(i)
        else:
            tails[k] = v; tidx[k] = i
        prevp[i] = tidx[k - 1] if k else -1
    keep, i = set(), (tidx[-1] if tidx else -1)
    while i >= 0:
        keep.add(i); i = prevp[i]
    rep['common']['first_mention_simulation'] = {
        'original_names': len(commons), 'mentioned': len(seq), 'lis': len(tails),
        'outside_lis': [(seqn[i], rep['rows'][seen[seqn[i]][0]]['source'], seen[seqn[i]][1]) for i in range(len(seq)) if i not in keep],
        'unmentioned': [name for _, name in commons if name not in seen]}

    # ---- literal sections
    def cstrings(blob):
        out, i = [], 0
        while i < len(blob):
            j = blob.find(b'\0', i)
            if j < 0:
                j = len(blob)
            out.append((i, blob[i:j]))
            i = j + 1
        return out
    for key, s in isec.items():
        if s['flags'] & 0xff != S_CSTRING_LITERALS:
            continue
        o_set = set()
        for n, (raw, m, l1) in objs.items():
            for os_ in m['sections']:
                if (os_['segname'], os_['sectname']) == key and os_['size']:
                    o_set |= {b for _, b in cstrings(raw[os_['offset']:os_['offset'] + os_['size']]) if b}
        orig_str = [(off, b) for off, b in cstrings(img_bytes(key, s['addr'], s['addr'] + s['size'])) if b]
        miss = [(hex(s['addr'] + off), b.decode('latin1')) for off, b in orig_str if b not in o_set]
        extra_s = sorted(b.decode('latin1') for b in o_set - {b for _, b in orig_str})
        rep['cstring']['%s,%s' % key] = {'original_nonempty': len(orig_str), 'object_distinct': len(o_set),
                                          'original_not_supplied': miss, 'object_not_in_original': extra_s}

    def str_at(sections, raw_or_img, addr, is_img):
        for s in sections:
            if s['addr'] <= addr < s['addr'] + s['size'] and s['size']:
                off = s['offset'] + addr - s['addr']
                end = raw_or_img.index(b'\0', off)
                return (s['segname'], s['sectname'], raw_or_img[off:end])
        return None
    for key, s in isec.items():
        if s['flags'] & 0xff != S_LITERAL_POINTERS:
            continue
        orig_c = collections.Counter()
        blob = img_bytes(key, s['addr'], s['addr'] + s['size'])
        for k in range(0, len(blob), 4):
            v = struct.unpack_from('<I', blob, k)[0]
            orig_c[str(str_at(im['sections'], img, v, True))] += 1
        obj_c = collections.Counter()
        for n, (raw, m, l1) in objs.items():
            for os_ in m['sections']:
                if (os_['segname'], os_['sectname']) != key or not os_['size']:
                    continue
                for k in range(0, os_['size'], 4):
                    v = struct.unpack_from('<I', raw, os_['offset'] + k)[0]
                    obj_c[str(str_at(m['sections'], raw, v, False))] += 1
        rep['literal_ptrs']['%s,%s' % key] = {
            'original_slots': sum(orig_c.values()), 'object_slots': sum(obj_c.values()),
            'original_distinct': len(orig_c), 'object_distinct': len(obj_c),
            'original_not_in_objects': sorted(set(orig_c) - set(obj_c))[:50],
            'objects_not_in_original': sorted(set(obj_c) - set(orig_c))[:50]}

    json.dump(rep, open(outp, 'w'), indent=1, default=str)
    r = rep
    print('regular:', {k: (v['gap_bytes'], v['gap_nonzero_bytes'], len(v['gaps_not_padding']), len(v['problems']))
                       for k, v in r['regular'].items()})
    print('bss:', {k: v for k, v in r['bss'].items() if k != 'inferred_overlaps'})
    print('symbols missing:', r['symbols']['missing_by_section'], 'dups', len(r['symbols']['strong_duplicates']),
          'extra', r['symbols']['defined_not_in_original_count'], 'pext', len(r['symbols']['private_extern']))
    print('common:', len(r['common']['request_exceeds_upper_bound']),
          len(r['common']['original_common_without_object_request_or_definition']),
          len(r['common']['common_requests_for_names_the_original_defines_outside_common']))
    fm = r['common']['first_mention_simulation']
    print('common first mention:', fm['original_names'], fm['mentioned'], fm['lis'], len(fm['unmentioned']))
    print('conditional placements:', [(c['row'], c['address'], c['bytes_equal']) for c in r['conditional_placements']],
          'libgcc const', r['libgcc_const'])
    print('cstring:', {k: (len(v['original_not_supplied']), len(v['object_not_in_original'])) for k, v in r['cstring'].items()})
    print('literal_ptrs:', {k: (v['original_slots'], v['object_slots'], len(v['original_not_in_objects']),
                                len(v['objects_not_in_original'])) for k, v in r['literal_ptrs'].items()})


if __name__ == '__main__':
    main()
