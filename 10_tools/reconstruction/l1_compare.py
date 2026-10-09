#!/usr/bin/env python3
"""L1 / L1d comparison of a relocatable object against a linked image
(plan sections 12 and 12.1).

  l1_compare.py --image IMG --obj X.o [--place SEG,SECT=ADDR ...] [--place-from-image]
                [--ranges FILE.json] [--out RESULT.json]

Placement: Delta(section) = address in IMG - address in the object.
  --place SEG,SECT=ADDR   the object's section starts at ADDR in IMG
  --place-from-image      derive Delta from object symbols whose names exist in IMG
Sections without a placement are inferred from references in placed sections
and accepted only if every reference agrees and (file-backed sections) every
byte matches; zero-fill sections stay unverified.

For every placed, file-backed section the tool compares all bytes outside
relocation fields and recomputes each relocation the way the linker does:
  extern, absolute        F + S
  extern, pc-relative     F + S - Delta(P)
  local,  absolute        F + Delta(T)
  local,  pc-relative     F + Delta(T) - Delta(P)
  scattered VANILLA       F + Delta(sect of r_value) [- Delta(P) if pc-relative]
  SECTDIFF + PAIR         F + Delta(sect of A) - Delta(sect of B)
F = field in the object, S = address of the symbol name in IMG, P = section
holding the field, T = target section.  Field widths 1/2/4 bytes, modulo 2^(8w).

Function verdicts: MATCH (bytes equal, every reference verified, every
referenced data section verified), MATCH_UNVERIFIED (bytes equal, some
references or data sections unverified), DIFF, BOUNDARY (an external range
from --ranges disagrees with the object range).  Exit 0 = tool ran.
"""
import argparse, json, os, re, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj

S_ZEROFILL = 1
TYPE = macho_obj.RELOC_TYPES_I386      # i386 names; kept for callers (plan 411: per-object table below)


def types_of(obj):
    """plan 411: relocation type names of obj's CPU; SPARC/HPPA (machine-specific types not
    implemented) are refused."""
    t = macho_obj.reloc_types(obj['cputype'])
    if t is None:
        raise macho_obj.MachOError('cputype %d: relocation types not implemented' % obj['cputype'])
    return t


class Image:
    def __init__(self, path):
        self.d = open(path, 'rb').read()
        self.o = macho_obj.parse(self.d)
        self.secs = self.o['sections']
        self.sym = {}
        for y in self.o['symbols']:
            if y['kind'] == 'SECT' and not y['stab']:
                self.sym.setdefault(y['name'], set()).add(y['value'])
        # nonzero absolute symbols (e.g. the linker-defined __mh_execute_header), used only
        # to resolve external relocations; zero-valued ObjC markers stay unresolved (plan 108.3)
        self.abs = {}
        for y in self.o['symbols']:
            if y['kind'] == 'ABS' and not y['stab'] and y['value'] and y['name'] not in self.sym:
                self.abs.setdefault(y['name'], set()).add(y['value'])

    def read(self, addr, n):
        for s in self.secs:
            if s['addr'] <= addr and addr + n <= s['addr'] + s['size']:
                if (s['flags'] & 0xff) == S_ZEROFILL:
                    return None
                o = s['offset'] + addr - s['addr']
                return self.d[o:o + n]
        return None

    def abs_symbol(self, name):
        v = self.abs.get(name)
        if not v or len(v) != 1:
            return None
        return next(iter(v))

    def symbol(self, name):
        v = self.sym.get(name)
        if not v or len(v) != 1:
            return None                       # absent or ambiguous
        return next(iter(v))


def sect_of(obj, addr):
    """Index of the non-empty section holding addr.  Zero-size sections own no
    address (plan 71): an empty section sharing its start with the next one
    must not capture references meant for that section."""
    for s in obj['sections']:
        if s['size'] and s['addr'] <= addr < s['addr'] + s['size']:
            return s['index']
    return None


def key(s):
    return '%s,%s' % (s['segname'], s['sectname'])


S_CSTRING, S_LITPTR = 2, 5


def is_lit(s):
    return (s['flags'] & 0xff) in (S_CSTRING, S_LITPTR)


def _obj_cstr(ob, s, off):
    if not 0 <= off < s['size']:
        return None
    b = ob[s['offset'] + off:s['offset'] + s['size']]
    i = b.find(b'\0')
    return None if i < 0 else b[:i]


def _img_sect(img, addr, like):
    for t in img.secs:
        if t['segname'] == like['segname'] and t['sectname'] == like['sectname'] and \
                t['addr'] <= addr < t['addr'] + t['size']:
            return t
    return None


def _img_cstr(img, addr, like):
    t = _img_sect(img, addr, like)
    if t is None:
        return None
    b = img.read(addr, t['addr'] + t['size'] - addr)
    i = b.find(b'\0')
    return None if i < 0 else b[:i]


def lit_check(img, obj, ob, T, target, V):
    """Content check of a reference to literal section T (object address target,
    image field value V).  Returns ('equal'|'differs', reason)."""
    s = obj['sections'][T - 1]
    if (s['flags'] & 0xff) == S_CSTRING:
        a = _obj_cstr(ob, s, target - s['addr'])
        b = _img_cstr(img, V, s)
        if a is None:
            return 'differs', 'object string unreadable'
        if b is None:
            return 'differs', 'image value %#x not a string in %s' % (V, key(s))
        return ('equal' if a == b else 'differs'), 'cstring %r' % a[:40]
    off = target - s['addr']                       # literal pointer slot
    if off % 4 or not 0 <= off < s['size']:
        return 'differs', 'bad literal-pointer slot offset'
    rel = [r for r in s['relocs'] if r['address'] == off]
    if len(rel) != 1:
        return 'differs', 'literal-pointer slot without one relocation'
    r = rel[0]
    F2 = int.from_bytes(ob[s['offset'] + off:s['offset'] + off + 4], obj['endian'])
    if r['scattered']:
        C = sect_of(obj, r['value'])
    elif not r['extern']:
        C = r['symbolnum']
    else:
        return 'differs', 'extern literal pointer not supported'
    cs = obj['sections'][C - 1] if C else None
    if cs is None or (cs['flags'] & 0xff) != S_CSTRING:
        return 'differs', 'literal pointer target is not a cstring section'
    a = _obj_cstr(ob, cs, F2 - cs['addr'])
    t = _img_sect(img, V, s)
    if t is None or (V - t['addr']) % 4:
        return 'differs', 'image value %#x not a slot of %s' % (V, key(s))
    W = int.from_bytes(img.read(V, 4), obj['endian'])
    b = _img_cstr(img, W, cs)
    if a is None or b is None:
        return 'differs', 'literal-pointer string unreadable'
    return ('equal' if a == b else 'differs'), 'litptr %r' % a[:40]


def evaluate(img, obj, ob, delta, s, rel_iter_index):
    """Expected linked value of relocation i of section s; returns
    (field_addr_obj, width, expected or None, reason, refs(sections used))."""
    rels = s['relocs']
    r = rels[rel_iter_index]
    w = 1 << r['length']
    if w not in (1, 2, 4):
        raise ValueError('bad width')
    a = r['address']
    if a + w > s['size']:
        raise ValueError('field outside section')
    F = int.from_bytes(ob[s['offset'] + a:s['offset'] + a + w], obj['endian'])
    P = s['index']
    dP = delta.get(P)
    used = []
    if not r['scattered']:
        if r['extern']:
            name = obj['symbols'][r['symbolnum']]['name']
            S = img.symbol(name)
            how = 'extern'
            if S is None:
                S = img.abs_symbol(name)
                how = 'extern-abs'
            if S is None:
                return a, w, None, 'symbol %s not in image' % name, used
            exp = F + S - (dP if r['pcrel'] else 0)
            return a, w, exp, '%s %s' % (how, name), used
        if r['type'] != 0:                 # plan 411: only VANILLA is computed for plain entries
            return a, w, None, 'unsupported plain relocation type %d' % r['type'], used
        T = r['symbolnum']
        if T == 0:                         # plan 411: R_ABS (reloc.h), no section to index
            return a, w, None, 'R_ABS local relocation', used
        if is_lit(obj['sections'][T - 1]):
            return a, w, None, ('LIT', T, F, r['pcrel']), used
        used.append(T)
        if delta.get(T) is None:
            return a, w, None, 'section %d unplaced' % T, used
        exp = F + delta[T] - (dP if r['pcrel'] else 0)
        return a, w, exp, 'local sect %d' % T, used
    t = types_of(obj).get(r['type'])
    if t == 'VANILLA':
        A = sect_of(obj, r['value'])
        if A is not None and is_lit(obj['sections'][A - 1]):
            return a, w, None, ('LIT', A, F, r['pcrel']), used
        used.append(A)
        if A is None or delta.get(A) is None:
            return a, w, None, 'scattered target unplaced', used
        return a, w, F + delta[A] - (dP if r['pcrel'] else 0), 'scattered sect %d' % A, used
    if t in ('SECTDIFF', 'LOCAL_SECTDIFF'):
        pair = rels[rel_iter_index + 1] if rel_iter_index + 1 < len(rels) else None
        if not pair or not pair['scattered'] or types_of(obj).get(pair['type']) != 'PAIR':
            raise ValueError('SECTDIFF without PAIR')
        A, B = sect_of(obj, r['value']), sect_of(obj, pair['value'])
        if any(x is not None and is_lit(obj['sections'][x - 1]) for x in (A, B)):
            return a, w, None, 'unsupported: SECTDIFF with a literal section', used
        used += [A, B]
        if None in (A, B) or delta.get(A) is None or delta.get(B) is None:
            return a, w, None, 'sectdiff section unplaced', used
        return a, w, F + delta[A] - delta[B], 'sectdiff %d-%d' % (A, B), used
    raise ValueError('unsupported relocation type %s' % t)


def infer(img, obj, ob, delta):
    """Infer Delta for unplaced sections from references in placed sections."""
    cands = {}
    for s in obj['sections']:
        if delta.get(s['index']) is None or (s['flags'] & 0xff) == S_ZEROFILL:
            continue
        for i, r in enumerate(s['relocs']):
            if r['scattered'] and types_of(obj).get(r['type']) == 'PAIR':
                continue
            w = 1 << r['length']
            F = int.from_bytes(ob[s['offset'] + r['address']:s['offset'] + r['address'] + w], obj['endian'])
            got = img.read(s['addr'] + delta[s['index']] + r['address'], w)
            if got is None:
                continue
            V = int.from_bytes(got, obj['endian'])
            dP = delta[s['index']] if r['pcrel'] else 0
            if not r['scattered'] and not r['extern']:
                T = r['symbolnum']
                if T == 0 or r['type'] != 0:      # plan 411: R_ABS / non-VANILLA plain entry
                    continue
            elif r['scattered'] and types_of(obj).get(r['type']) == 'VANILLA':
                T = sect_of(obj, r['value'])
            else:
                continue
            if T is None or delta.get(T) is not None or is_lit(obj['sections'][T - 1]):
                continue
            cands.setdefault(T, set()).add((V - F + dP) % (1 << (8 * w)) if w == 4 else None)
    out = {}
    for T, c in cands.items():
        c.discard(None)
        out[T] = c
    return out


def compare(img, objpath, placements, ranges=None, by_symbol=(), method_info=None, by_objc=()):
    ob = open(objpath, 'rb').read()
    obj = macho_obj.parse(ob)
    # plan 411: object and image must be the same CPU and byte order, with implemented types
    if (obj['cputype'], obj['endian']) != (img.o['cputype'], img.o['endian']):
        raise macho_obj.MachOError('object %s/%s vs image %s/%s' % (obj['cputype'], obj['endian'],
                                                                  img.o['cputype'], img.o['endian']))
    types_of(obj)
    delta = {}
    for s in obj['sections']:
        if key(s) in placements and not is_lit(s):
            delta[s['index']] = placements[key(s)] - s['addr']
    status = {}                                    # section -> placement status
    for s in obj['sections']:
        if s['index'] in delta:
            status[s['index']] = ('given by symbol' if key(s) in by_symbol else
                                  'given by objc metadata' if key(s) in by_objc else 'given by user')
    # inference, repeated while it adds sections
    for _ in range(len(obj['sections'])):
        c = infer(img, obj, ob, delta)
        added = False
        for T, vals in c.items():
            if len(vals) == 1:
                delta[T] = next(iter(vals)) - (1 << 32 if next(iter(vals)) >= 1 << 31 else 0)
                status[T] = 'inferred'
                added = True
            else:
                status[T] = 'ambiguous %d candidates' % len(vals)
        if not added:
            break
    result = dict(object=objpath, sections={}, functions=[])
    sec_ok = {}
    func_ranges = []
    for s in obj['sections']:
        k, idx = key(s), s['index']
        ent = dict(index=idx, placement=status.get(idx, 'unplaced'), size=s['size'])
        result['sections'][k] = ent
        zero = (s['flags'] & 0xff) == S_ZEROFILL
        if is_lit(s):
            ent['placement'] = 'literal (references checked by content)'
            sec_ok[idx] = 'literal'
            continue
        if idx not in delta or delta[idx] is None:
            sec_ok[idx] = 'unverified'
            continue
        ent['address'] = s['addr'] + delta[idx]
        if zero:
            # bytes cannot be compared; the placement counts as verified only when it
            # came from symbol names present in the image
            ent['bytes'] = 'zero-fill (not comparable)'
            sec_ok[idx] = 'placement-only' if status.get(idx) == 'given by symbol' else 'unverified'
            continue
        orig = img.read(s['addr'] + delta[idx], s['size'])
        if orig is None:
            ent['bytes'] = 'not file-backed in image'
            sec_ok[idx] = 'fail'
            continue
        mask = [False] * s['size']
        refs = []
        i = 0
        rels = s['relocs']
        while i < len(rels):
            r = rels[i]
            if r['scattered'] and types_of(obj).get(r['type']) == 'PAIR':
                i += 1
                continue
            a, w, exp, why, used = evaluate(img, obj, ob, delta, s, i)
            for j in range(a, a + w):
                mask[j] = True
            got = int.from_bytes(orig[a:a + w], obj['endian'])
            if isinstance(why, tuple) and why[0] == 'LIT':
                _, T, Fv, pcrel = why
                if pcrel or w != 4:
                    res, why = 'unverified', 'unsupported: pc-relative or narrow literal reference'
                else:
                    res, why = lit_check(img, obj, ob, T, Fv, got)
                    why = 'literal ' + why
            elif exp is None:
                res = 'unverified'
            else:
                res = 'equal' if (exp % (1 << (8 * w))) == got else 'differs'
            refs.append(dict(address=a, width=w, result=res, why=why, used=used,
                             expected=None if exp is None else exp % (1 << (8 * w)), image=got))
            i += 1
        objb = ob[s['offset']:s['offset'] + s['size']]
        diffs = [j for j in range(s['size']) if not mask[j] and objb[j] != orig[j]]
        ent.update(byte_differences=len(diffs), first_differences=diffs[:8],
                   references=len(refs), refs_differ=sum(1 for x in refs if x['result'] == 'differs'),
                   refs_unverified=sum(1 for x in refs if x['result'] == 'unverified'))
        ent['_refs'] = refs
        ent['_diffs'] = diffs
        sec_ok[idx] = 'fail' if diffs or ent['refs_differ'] else ('unverified' if ent['refs_unverified'] else 'ok')
        if status.get(idx) == 'inferred' and sec_ok[idx] == 'ok':
            ent['placement'] = 'inferred, verified by L1d'
    # functions: symbols in code sections, grouped by address
    for s in obj['sections']:
        idx = s['index']
        if s['segname'] != '__TEXT' or idx not in delta or (s['flags'] & 0xff) == S_ZEROFILL:
            continue
        ent = result['sections'][key(s)]
        if '_refs' not in ent:
            continue
        syms = {}
        for y in obj['symbols']:
            if y['kind'] == 'SECT' and y['sect'] == idx and not y['stab']:
                syms.setdefault(y['value'] - s['addr'], []).append(y['name'])
        starts = sorted(syms)
        if not starts or starts[0] != 0:
            starts = [0] + starts
            syms.setdefault(0, ['<section start>'])
        for n, st in enumerate(starts):
            en = starts[n + 1] if n + 1 < len(starts) else s['size']
            rr = [x for x in ent['_refs'] if st <= x['address'] < en]
            dd = [x for x in ent['_diffs'] if st <= x < en]
            deps = set(u for x in rr for u in x['used'] if u is not None and u != idx)
            dep_state = {d: sec_ok.get(d, 'unverified') for d in deps}
            if dd or any(x['result'] == 'differs' for x in rr) or 'fail' in dep_state.values():
                verdict = 'DIFF'
            elif any(x['result'] == 'unverified' for x in rr) or 'unverified' in dep_state.values():
                verdict = 'MATCH_UNVERIFIED'
            else:
                verdict = 'MATCH'
            f = dict(names=syms[st], section=key(s), object_range=[st, en],
                     diff_offsets=dd, ref_diff_offsets=[x['address'] for x in rr if x['result'] == 'differs'],
                     zero_fill_placement_only=sorted(d for d, v in dep_state.items() if v == 'placement-only'),
                     image_range=[s['addr'] + delta[idx] + st, s['addr'] + delta[idx] + en],
                     verdict=verdict, byte_differences=len(dd),
                     refs=len(rr), refs_differ=sum(1 for x in rr if x['result'] == 'differs'),
                     refs_unverified=[x['why'] for x in rr if x['result'] == 'unverified'],
                     data_sections=dep_state)
            if ranges is not None:
                for nm in syms[st]:
                    if nm in ranges:
                        lo, hi = ranges[nm]
                        if lo != f['image_range'][0] or hi > f['image_range'][1]:
                            f['verdict'] = 'BOUNDARY'
                            f['boundary'] = dict(external=[lo, hi], object=f['image_range'])
            result['functions'].append(f)
    # object verdict: every non-empty section verified, every reference verified,
    # and (ObjC) a complete method correspondence
    reasons = []
    for s in obj['sections']:
        if not s['size']:
            continue
        ent = result['sections'][key(s)]
        st = sec_ok.get(s['index'])
        if st not in ('ok', 'placement-only', 'literal'):
            reasons.append('%s: %s' % (key(s), st))
        if ent.get('refs_differ') or ent.get('refs_unverified'):
            reasons.append('%s: %s refs differ, %s unverified' % (key(s), ent.get('refs_differ'), ent.get('refs_unverified')))
    if method_info is not None:
        result['methods'] = method_info
        # plan 299: an object with no method symbols has nothing to correspond (its sections are still gated above)
        if method_info['methods'] and (not method_info['placed'] or method_info['missing'] or method_info['ambiguous']):
            reasons.append('method correspondence incomplete')
    result['object_verdict'] = 'OBJECT_MATCH' if not reasons else 'NOT_MATCH'
    result['object_reasons'] = reasons
    for ent in result['sections'].values():
        ent.pop('_refs', None)
        ent.pop('_diffs', None)
    result['placements'] = {key(s): (s['addr'] + delta[s['index']] if s['index'] in delta and delta[s['index']] is not None else None)
                            for s in obj['sections']}
    return result


METH_RE = re.compile(r'^([+-])\[(\w+)(?:\((\w+)\))? (.+)\]$')


def placements_from_methods(meta_methods, objpath):
    """__text placement of an ObjC object from a complete, unambiguous
    correspondence of its method symbols with image metadata, keyed by
    (owner, category, kind, selector)."""
    obj = macho_obj.parse(open(objpath, 'rb').read())
    index = {}
    for m in meta_methods:
        index.setdefault((m['owner'], m['category'], m['kind'], m['selector']), []).append(m['imp'])
    deltas, missing, ambiguous, n = set(), [], [], 0
    for y in obj['symbols']:
        mm = METH_RE.match(y['name'])
        if not mm or y['kind'] != 'SECT':
            continue
        n += 1
        k = (mm.group(2), mm.group(3), 'instance' if mm.group(1) == '-' else 'class', mm.group(4))
        imps = index.get(k, [])
        if len(imps) != 1:
            (missing if not imps else ambiguous).append(y['name'])
            continue
        deltas.add((y['sect'], imps[0] - y['value']))
    info = dict(methods=n, missing=missing, ambiguous=ambiguous, deltas=len(set(d for _, d in deltas)), placed=False)
    out = {}
    if n and not missing and not ambiguous and len(deltas) == 1:
        sect, d = next(iter(deltas))
        s = obj['sections'][sect - 1]
        out[key(s)] = s['addr'] + d
        info['placed'] = True
    return out, info


def placements_from_image(img, objpath):
    obj = macho_obj.parse(open(objpath, 'rb').read())
    out = {}
    for s in obj['sections']:
        ds = set()
        for y in obj['symbols']:
            if y['kind'] == 'SECT' and y['sect'] == s['index'] and not y['stab']:
                v = img.symbol(y['name'])
                if v is not None:
                    ds.add(v - y['value'])
        if len(ds) == 1:
            out[key(s)] = s['addr'] + next(iter(ds))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--image', required=True)
    ap.add_argument('--obj', required=True)
    ap.add_argument('--place', action='append', default=[])
    ap.add_argument('--place-from-image', action='store_true')
    ap.add_argument('--place-from-objc', action='store_true')
    ap.add_argument('--ranges')
    ap.add_argument('--out')
    a = ap.parse_args()
    img = Image(a.image)
    pl = placements_from_image(img, a.obj) if a.place_from_image else {}
    by_symbol = set(pl)
    minfo = None
    if a.place_from_objc:
        import objc_meta
        import objc_place
        meta = objc_meta.Meta(img).read()
        mp, minfo = placements_from_methods(meta['methods'], a.obj)
        pl.update(mp)
        rp, rinfo = objc_place.placements(a.obj, meta)
        minfo['records'] = rinfo
        pl.update(rp)
        by_objc = set(rp) | set(mp)
    else:
        by_objc = set()
    for p in a.place:
        k, v = p.split('=')
        pl[k] = int(v, 0)
        by_symbol.discard(k)
    ranges = None
    if a.ranges:
        ranges = {k: tuple(v) for k, v in json.load(open(a.ranges)).items()}
    r = compare(img, a.obj, pl, ranges, by_symbol - by_objc, minfo, by_objc)
    import hashlib   # plan 302: bind the result to its inputs
    r['inputs'] = {x: hashlib.sha256(open(x, 'rb').read()).hexdigest() for x in (a.image, a.obj)}
    text = json.dumps(r, indent=1)
    if a.out:
        open(a.out, 'w').write(text + '\n')
    for f in r['functions']:
        print('%-18s %-28s %s' % (f['verdict'], ','.join(f['names']), f['section']))
    print('object:', r['object_verdict'], r['object_reasons'][:6])


if __name__ == '__main__':
    main()
