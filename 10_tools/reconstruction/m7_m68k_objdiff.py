#!/usr/bin/env python3
"""m7_m68k_objdiff.py -- plan 779.3: compare rebuilt m68k objects with their reference objects (read-only).

  python3 10_tools/reconstruction/m7_m68k_objdiff.py PAIRS.json OUT.json

PAIRS.json: [{"label": .., "old": path, "new": path, "allow": [names], "allow_local_renames": bool}, ...]
Per pair:
  canon      section bytes and relocations by name (m3_m68k_diag.canon) equal
  sections   header fields and section list (segment, name, size, align, flags) equal (l2_prefix_diff.obj_sig)
  symbols    non-STABS symbol table in physical order, split into
               added_common  names that are COMMON in new and absent from old
               undf_to_common names that are undefined in old and COMMON in new
               local_renamed  local (non-external) symbols whose name changed at the same place (allowed only with
                              allow_local_renames)
               other          everything else (must be empty)
  stabs      counts only (debug records are not judged; header imports may renumber types)
  allowed    canon and sections equal, other empty, every added/undf_to_common name in allow
  identical  the files are byte-identical
"""
import sys, os, json, hashlib

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import macho_obj
import m3_m68k_diag as D
import l2_prefix_diff as PD


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def syms(p):
    o = macho_obj.parse(open(p, 'rb').read())
    return [(y['name'], y['kind'], bool(y.get('ext')), y.get('sect'), y.get('value')) for y in o['symbols'] if not y['stab']], \
        sum(1 for y in o['symbols'] if y['stab'])


def compare(old, new, allow, allow_local_renames):
    so, no = syms(old)
    sn, nn = syms(new)
    po, pn = PD.obj_sig(old), PD.obj_sig(new)
    r = dict(identical=sha(old) == sha(new), canon=D.canon(old) == D.canon(new),
             sections=(po['header'], po['sections']) == (pn['header'], pn['sections']), stabs=[no, nn])
    old_by = {s[0]: s for s in so}
    new_names = {s[0] for s in sn}
    added, u2c, ren, other = [], [], [], []
    rest_new = []
    for s in sn:
        o = old_by.get(s[0])
        if s[1] == 'COMMON' and o is None:
            added.append(s[0])
        elif s[1] == 'COMMON' and o is not None and o[1] == 'UNDF':
            u2c.append(s[0])
        else:
            rest_new.append(s)
    rest_old = [s for s in so if not (s[0] in u2c)]
    # old symbols must reappear unchanged and in the same relative order (local renames matched by position)
    if len(rest_old) != len(rest_new):
        other.append(['count', len(rest_old), len(rest_new)])
    for a, b in zip(rest_old, rest_new):
        if a == b:
            continue
        if allow_local_renames and not a[2] and not b[2] and a[1:] == b[1:]:
            ren.append([a[0], b[0]])
        else:
            other.append([list(a), list(b)])
    r.update(added_common=added, undf_to_common=u2c, local_renamed=ren, other=other[:20], n_other=len(other))
    bad = sorted(set(added + u2c) - set(allow))
    r['not_allowed'] = bad
    r['allowed'] = r['canon'] and r['sections'] and not other and not bad and (allow_local_renames or not ren)
    return r


def main(pairs_json, outj):
    pairs = json.load(open(pairs_json))
    res = []
    for p in pairs:
        r = compare(p['old'], p['new'], p.get('allow', []), p.get('allow_local_renames', False))
        res.append(dict(label=p['label'], old=p['old'], old_sha256=sha(p['old']), new=p['new'], new_sha256=sha(p['new']), **r))
    out = dict(tool='10_tools/reconstruction/m7_m68k_objdiff.py', tool_sha256=sha(os.path.abspath(__file__)),
               pairs=pairs_json, pairs_sha256=sha(pairs_json), results=res,
               summary=dict(n=len(res), allowed=sum(1 for r in res if r['allowed']), identical=sum(1 for r in res if r['identical'])))
    json.dump(out, open(outj, 'w'), indent=1)
    print(out['summary'])


if __name__ == '__main__':
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    main(*sys.argv[1:])
