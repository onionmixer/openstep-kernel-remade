#!/usr/bin/env python3
"""Reference-inferred placement of a zero-fill section (plan 46.1 / 46.2).

  zerofill_check.py --image IMG --obj X.o --section SEG,SECT --symbols SYMBOLS.tsv
                    [--known KNOWN.json] --out RESULT.json

l1_compare.py leaves a zero-fill section that has no symbols unverified.  This
tool records the circumstantial evidence for where such a section lies in the
image; its conclusion is 'reference-inferred' (never ownership) or 'fail'.

Source sections are placed only through object symbols whose names exist in the
image symbol table (one Delta per section, all such symbols must agree).  For
every relocation whose target is the zero-fill section Z:
  local          field' = F + Delta(Z) [- Delta(P) if pc-relative]
  scattered      same, with the target taken from r_value
so Delta(Z) = field' - F [+ Delta(P)], computed per reference from the image.
PAIR / SECTDIFF relocations touching Z, or a referring section without a
symbol placement, make the result 'fail'.

Checks: every Delta equal; candidate range aligned to the section alignment;
inside the image section of the same name, which must be zero-fill; no image
symbol inside the range; no overlap with ranges in KNOWN.json
([[lo, hi, label], ...], half-open).  A negative check repeats the inference
with one image field changed by +4 and must fail.

Decision D025 (plan 225.1): for a scattered record the range check uses its target
r_value (base_offset), not the field; the field's addend is listed in scattered_addends.

Decision D019 (plan 84, 84.1): when everything passes except the negative check,
and the only reason is that there is a single reference (one record, neither
scattered nor pc-relative, so its field target is range-checked), the
conclusion is 'reference-inferred-single' instead of 'fail'.
"""
import argparse, bisect, csv, hashlib, json, os, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import l1_compare as L

S_ZEROFILL = 1
TYPE = macho_obj.RELOC_TYPES_I386


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def sect_of(obj, addr):
    """Index of the object section holding addr (zero-size sections never match)."""
    for s in obj['sections']:
        if s['size'] and s['addr'] <= addr < s['addr'] + s['size']:
            return s['index']
    return None


def source_deltas(obj, imgsyms):
    """Delta per section from defined external symbols present in the image."""
    out = {}
    for y in obj['symbols']:
        if y['kind'] != 'SECT' or y['stab'] or y['name'] not in imgsyms:
            continue
        out.setdefault(y['sect'], set()).add(imgsyms[y['name']] - y['value'])
    return {k: (next(iter(v)) if len(v) == 1 else None) for k, v in out.items()}


def infer(obj, ob, zidx, deltas, read):
    """Per-reference Delta(Z) records; read(va, width) gives the image field."""
    z = [s for s in obj['sections'] if s['index'] == zidx][0]
    recs, problems = [], []
    for s in obj['sections']:
        rels = s['relocs']
        for i, r in enumerate(rels):
            kind = TYPE.get(r['type'])
            if r['scattered']:
                tgt = sect_of(obj, r['value'])
                if kind in ('PAIR', 'SECTDIFF', 'LOCAL_SECTDIFF'):
                    if tgt == zidx or (kind == 'PAIR' and i and sect_of(obj, rels[i - 1].get('value', -1)) == zidx):
                        problems.append('unsupported %s relocation at %s+%#x' % (kind, s['sectname'], r['address']))
                    continue
                if tgt != zidx:
                    continue
                base = r['value']
            else:
                if r['extern'] or r['symbolnum'] != zidx:
                    continue
                base = None
            w = 1 << r['length']
            F = int.from_bytes(ob[s['offset'] + r['address']:s['offset'] + r['address'] + w], 'little')
            dP = deltas.get(s['index'])
            if dP is None:
                problems.append('referring section %s has no symbol placement' % s['sectname'])
                continue
            va = s['addr'] + dP + r['address']
            got = read(va, w)
            m = 1 << (8 * w)
            dz = (got - F + (dP if r['pcrel'] else 0)) % m
            recs.append(dict(section=s['sectname'], offset=r['address'], image_va=va, width=w,
                             pcrel=bool(r['pcrel']), scattered=bool(r['scattered']), type=kind,
                             object_field=F, image_field=got,
                             base_offset=None if base is None else base - z['addr'],
                             delta=dz))
    return recs, problems


def conclude(ok, ok_before_negative, recs, negative):
    """Conclusion from the checks; 'reference-inferred-single' only under D019."""
    if ok:
        return 'reference-inferred'
    if (ok_before_negative and len(recs) == 1 and not recs[0]['scattered'] and not recs[0]['pcrel']
            and negative is not None and not negative['detected']):
        return 'reference-inferred-single'
    return 'fail'


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--image', required=True)
    ap.add_argument('--obj', required=True)
    ap.add_argument('--section', required=True)
    ap.add_argument('--symbols', required=True)
    ap.add_argument('--known')
    ap.add_argument('--out', required=True)
    ap.add_argument('--place-from-l1')   # plan 302: referring-section placements verified by l1_compare
    a = ap.parse_args()
    seg, sect = a.section.split(',')
    ob = open(a.obj, 'rb').read()
    obj = macho_obj.parse(ob)
    img = L.Image(a.image)
    imd = macho_obj.parse(open(a.image, 'rb').read())
    macho_obj.require_i386(obj, 'zerofill_check')  # plan 411: i386 little-endian only
    macho_obj.require_i386(imd, 'zerofill_check')
    rows = list(csv.DictReader(open(a.symbols), delimiter='\t'))
    imgsyms = {x['name']: int(x['value'], 16) for x in rows}
    zs = [s for s in obj['sections'] if s['segname'] == seg and s['sectname'] == sect]
    if len(zs) != 1 or (zs[0]['flags'] & 0xff) != S_ZEROFILL:
        sys.exit('section %s is not a single zero-fill section of the object' % a.section)
    z = zs[0]
    deltas = source_deltas(obj, imgsyms)
    delta_source = {k: 'symbol' for k, v in deltas.items() if v is not None}
    l1problems = []
    if a.place_from_l1:   # plan 302
        l1 = json.load(open(a.place_from_l1))
        inp = l1.get('inputs') or {}
        if inp.get(a.image) != sha(a.image) or inp.get(a.obj) != sha(a.obj):
            sys.exit('--place-from-l1: L1 inputs do not match --image/--obj by SHA-256')
        for s in obj['sections']:
            k = '%s,%s' % (s['segname'], s['sectname'])
            e = l1['sections'].get(k)
            if not e or not s['size'] or (s['flags'] & 0xff) in (S_ZEROFILL, 2, 5):   # zero-fill, cstring and literal-pointer sections are never used
                continue
            usable = (e.get('index') == s['index'] and e.get('size') == s['size'] and e.get('address') is not None
                      and e.get('placement') in ('given by objc metadata', 'given by symbol', 'inferred, verified by L1d')   # plan 339 (D041): L1d-inferred too
                      and e.get('byte_differences') == 0 and e.get('refs_differ') == 0 and e.get('refs_unverified') == 0)
            if not usable:
                continue
            dl = e['address'] - s['addr']
            if deltas.get(s['index']) is not None:
                if deltas[s['index']] != dl:
                    l1problems.append('section %s: symbol Delta %#x differs from L1 Delta %#x' % (k, deltas[s['index']], dl))
                continue
            deltas[s['index']] = dl
            delta_source[s['index']] = 'l1-inferred' if e.get('placement') == 'inferred, verified by L1d' else 'l1'   # plan 339
    rd = lambda va, w: int.from_bytes(img.read(va, w), 'little')
    recs, problems = infer(obj, ob, z['index'], deltas, rd)
    problems = l1problems + problems
    ds = sorted({r['delta'] for r in recs})
    res = dict(tool='zerofill_check.py', tool_sha256=sha(os.path.abspath(__file__)),
               command=' '.join(sys.argv), inputs={p: sha(p) for p in (a.image, a.obj, a.symbols) + ((a.known,) if a.known else ()) + ((a.place_from_l1,) if a.place_from_l1 else ())},
               section=dict(name=a.section, index=z['index'], object_addr=z['addr'], size=z['size'], align=1 << z['align']),
               source_section_deltas={str(k): v for k, v in deltas.items()},
               delta_source={str(k): v for k, v in delta_source.items()},
               references=len(recs), distinct_deltas=[hex(d) for d in ds],
               base_offsets=sorted({r['base_offset'] for r in recs if r['base_offset'] is not None}),
               # D025: a scattered record's target is its r_value (base_offset); the field may
               # carry an addend outside the section (e.g. array index arithmetic)
               field_target_offsets=sorted({(r['base_offset'] if r['scattered'] else r['object_field'] - z['addr'])
                                            for r in recs if not r['pcrel']}),
               scattered_addends=sorted({r['object_field'] - (z['addr'] + r['base_offset'])
                                         for r in recs if r['scattered'] and not r['pcrel']}),
               problems=problems, checks={}, records=recs)
    ok = not problems and len(ds) == 1 and recs
    ok_before_negative = False
    if ok:
        d = ds[0] - (1 << 32 if ds[0] >= 1 << 31 else 0)
        lo, hi = z['addr'] + d, z['addr'] + d + z['size']
        res['candidate'] = [lo, hi]
        c = res['checks']
        c['aligned'] = lo % (1 << z['align']) == 0
        isec = [s for s in imd['sections'] if s['segname'] == seg and s['sectname'] == sect]
        c['image_section'] = [(s['addr'], s['addr'] + s['size']) for s in isec]
        c['inside_zero_fill_image_section'] = any(s['addr'] <= lo and hi <= s['addr'] + s['size'] and (s['flags'] & 0xff) == S_ZEROFILL for s in isec)
        c['image_symbols_inside'] = sorted(n for n, v in imgsyms.items() if lo <= v < hi)
        known = json.load(open(a.known)) if a.known else []
        c['overlaps'] = [k for k in known if k[0] < hi and lo < k[1]]
        c['field_targets_in_range'] = all(0 <= t < z['size'] for t in res['field_target_offsets'])
        ok = c['aligned'] and c['inside_zero_fill_image_section'] and not c['image_symbols_inside'] and not c['overlaps'] and c['field_targets_in_range']
    ok_before_negative = bool(ok)
    # negative check: perturb the first reference's image field by +4
    if recs:
        bad = recs[0]['image_va']
        rd2 = lambda va, w: (rd(va, w) + (4 if va == bad else 0)) % (1 << (8 * w))
        r2, p2 = infer(obj, ob, z['index'], deltas, rd2)
        res['negative_check'] = dict(perturbed_va=bad, distinct_deltas=len({r['delta'] for r in r2}),
                                     detected=len({r['delta'] for r in r2}) > 1 or bool(p2))
        ok = ok and res['negative_check']['detected']
    res['conclusion'] = conclude(ok, ok_before_negative, recs, res.get('negative_check'))
    json.dump(res, open(a.out, 'w'), indent=1)
    print(json.dumps({k: v for k, v in res.items() if k not in ('records', 'inputs', 'source_section_deltas')}, indent=1)[:3000])


if __name__ == '__main__':
    main()
