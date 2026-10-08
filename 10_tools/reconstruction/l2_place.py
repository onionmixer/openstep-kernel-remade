#!/usr/bin/env python3
"""l2_place.py -- plan 408: link-placement proof for the grade-P objects (read only).

  python3 10_tools/reconstruction/l2_place.py OUT.json [--selftest]

Scope (plan 408 A): only the two section kinds whose ld placement is plain aligned
concatenation in input order -- __DATA,__bss (S_ZEROFILL) and the regular __TEXT,__const.
Literal sections (__cstring, __message_refs, __cls_refs ...) are coalesced by ld -r and are
out of scope; so is __common (allocated by the linker, plans 399-401).

Inputs: the link run 08_build/runs/s6p404-ln1 (run.cmd order, src/objs/*.o, the two ld -r
outputs out/libDriver_kern.o and out/libkobjc.o, out/mach_kernel.sys), the libcc.a members
named in 06_reconstruction/objects_toolchain.tsv (i386 slice of the fat archive), the
original image, 06_reconstruction/objects_partial.tsv, the rebuild records
09_validation/reconstruction/s6-l1-*-s6l4-*.json and the baseline records
09_validation/reconstruction/s6-l2-baseline-20261008/*.json.

Checks
  layout   per kind: inner ld -r layouts and the final layout by aligned concatenation;
           (a) end of the last contribution = section end (ld -r outputs and .sys),
           (b) multiset of (name, value) of all non-STAB N_SECT symbols in that section =
               expected (contribution start + n_value - input section addr),
           (c) the same for STAB N_STSYM / N_LCSYM whose n_sect is that section.
           The section starts of .sys are observed values, not predictions.
  objects  per P row: rebuilt object (link input) bound by hash to its s6l4 record and L1
           json; P consistency of that L1 json (l2_baseline.py rule) and its unverified
           sections = the row's; recorded object (baseline inputs) vs rebuilt object for
           each unverified section (size, align, flags, __const bytes, symbol names and
           section offsets); linked range of the section; __const bytes of the original at
           that range = object bytes; __bss inside the original __bss, recorded addresses
           from the row text inside the linked range; anchors (symbols / STABs) or
           "order-dependent attribution".
Limit: placement in this saved rebuild link only; it does not prove the historical
ownership of indistinguishable zero storage or repeated constants.
"""
import sys, os, re, json, glob, struct, hashlib, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj as M

RUN = '08_build/runs/s6p404-ln1/'
IMG = '03_original/x86/binaries/mach_kernel'
LIBCC = '03_original/x86/userland/binaries/lib/libcc.a'
PARTIAL = '06_reconstruction/objects_partial.tsv'
TOOLCHAIN = '06_reconstruction/objects_toolchain.tsv'
V = '09_validation/reconstruction/'
KINDS = (('__DATA', '__bss'), ('__TEXT', '__const'))
N_STSYM, N_LCSYM = 0x26, 0x28
SECTS = {'__DATA,__bss': ('__DATA', '__bss'), '__TEXT,__const': ('__TEXT', '__const')}


def sha(b):
    return hashlib.sha256(b).hexdigest()


def tsv(path):
    """rows of a project TSV as dicts; plain tab split (cells may contain '"')"""
    lines = open(path).read().split('\n')
    assert lines[-1] == ''
    hdr = lines[0].split('\t')
    rows = [l.split('\t') for l in lines[1:-1]]
    assert all(len(r) == len(hdr) for r in rows), path
    return [dict(zip(hdr, r)) for r in rows]


def up(x, a):
    return (x + a - 1) // a * a


class Obj:
    """one Mach-O file (object, ld -r output or the linked kernel)"""

    def __init__(self, name, data):
        self.name, self.data, self.sha = name, data, sha(data)
        self.m = M.parse(data)

    def sect(self, kind):
        for s in self.m['sections']:
            if (s['segname'], s['sectname']) == kind:
                return s
        return None

    def syms(self, s):
        """non-STAB N_SECT symbols in section s: list of (name, value)"""
        return [(y['name'], y['value']) for y in self.m['symbols']
                if not y['type'] & M.N_STAB and (y['type'] & M.N_TYPE) == M.N_SECT and y['sect'] == s['index']]

    def stabs(self, s):
        return [(y['name'], y['value']) for y in self.m['symbols']
                if y['type'] in (N_STSYM, N_LCSYM) and y['sect'] == s['index']]


def libcc_members(names):
    """i386 slice of the fat libcc.a, members by name -> bytes"""
    d = open(LIBCC, 'rb').read()
    magic, n = struct.unpack_from('>2I', d, 0)
    assert magic == 0xcafebabe
    sl = None
    for i in range(n):
        cpu, sub, off, size, al = struct.unpack_from('>5I', d, 8 + 20 * i)
        if cpu == 7:
            sl = d[off:off + size]
    assert sl and sl[:8] == b'!<arch>\n'
    out, p = {}, 8
    while p < len(sl):
        h = sl[p:p + 60]
        nm, size = h[:16].decode().strip(), int(h[48:58].decode().strip())
        body = sl[p + 60:p + 60 + size]
        if nm.startswith('#1/'):
            ln = int(nm[3:])
            nm, body = body[:ln].rstrip(b'\0').decode(), body[ln:]
        if nm in names:
            out[nm] = body
        p += 60 + size + (size & 1)
    return out, sha(d), sha(sl)


def layout(inputs, out_obj, kind, base=None):
    """aligned concatenation of `inputs` (list of Obj) for one section kind.
    Returns (contribs, checks); contribs: list of (Obj, start, size, input_sect)."""
    os_ = out_obj.sect(kind)
    res = {'kind': '%s,%s' % kind, 'output': out_obj.name}
    if os_ is None:
        res['absent'] = True
        return [], res
    cur = os_['addr'] if base is None else base
    contribs = []
    for o in inputs:
        s = o.sect(kind)
        if s is None or s['size'] == 0:
            continue
        cur = up(cur, 1 << s['align'])
        contribs.append((o, cur, s['size'], s))
        cur += s['size']
    res.update(start=os_['addr'], size=os_['size'], end_expected=cur, end_actual=os_['addr'] + os_['size'],
               end_ok=cur == os_['addr'] + os_['size'], contributions=len(contribs))
    exp_sym, exp_stab = collections.Counter(), collections.Counter()
    for o, st, sz, s in contribs:
        for nm, v in o.syms(s):
            exp_sym[(nm, st + v - s['addr'])] += 1
        for nm, v in o.stabs(s):
            exp_stab[(nm, st + v - s['addr'])] += 1
    act_sym = collections.Counter(out_obj.syms(os_))
    act_stab = collections.Counter(out_obj.stabs(os_))
    res.update(symbols=sum(act_sym.values()), symbols_ok=exp_sym == act_sym,
               symbols_missing=sorted(map(list, (exp_sym - act_sym).elements()))[:20],
               symbols_extra=sorted(map(list, (act_sym - exp_sym).elements()))[:20],
               stabs=sum(act_stab.values()), stabs_ok=exp_stab == act_stab,
               stabs_missing=sorted(map(list, (exp_stab - act_stab).elements()))[:20],
               stabs_extra=sorted(map(list, (act_stab - exp_stab).elements()))[:20])
    res['ok'] = res['end_ok'] and res['symbols_ok'] and res['stabs_ok']
    return contribs, res


def link_inputs():
    runs = [l[4:].split() for l in open(RUN + 'run.cmd') if l.startswith('RUN ')]
    libs = {}
    for r in runs:
        if r[:2] == ['/bin/ld', '-r']:
            libs[r[r.index('-o') + 1]] = [a for a in r if a.endswith('.o') and a.startswith('src/')]
    final = [r for r in runs if r[0] == '/bin/ld' and '-static' in r]
    assert len(final) == 1 and len(libs) == 2
    f = final[0]
    order = [a for a in f if a.endswith('.o') and a != f[f.index('-o') + 1]]
    return libs, order, '-lcc' in f


def build(perturb=None):
    libs, order, lcc = link_inputs()
    cache = {}

    def get(path):
        if path not in cache:
            cache[path] = Obj(path, open(path, 'rb').read())
        return cache[path]

    rep = {'inputs': {}, 'layouts': [], 'limit': 'placement in the saved rebuild link s6p404-ln1 only; '
           'historical ownership of indistinguishable zero storage or repeated constants is not proved; '
           'section starts of mach_kernel.sys are observed values'}
    sysk = get(RUN + 'out/mach_kernel.sys')
    rep['inputs'][sysk.name] = sysk.sha
    tc = tsv(TOOLCHAIN)
    names = [re.search(r'\(i386: ([^)]+)\)', r['source']).group(1) for r in tc]
    mem, lsha, slsha = libcc_members(names)
    rep['inputs'][LIBCC] = lsha
    rep['libcc'] = {'i386_slice_sha256': slsha, 'members': {k: sha(v) for k, v in mem.items()}}
    # member order observed from the text symbols of mach_kernel.sys
    tsec = sysk.sect(('__TEXT', '__text'))
    taddr = {nm: v for nm, v in sysk.syms(tsec)}
    mobjs = []
    for nm, b in mem.items():
        o = Obj('libcc.a(%s)' % nm, b)
        ext = [y['name'] for y in o.m['symbols'] if y['type'] == (M.N_SECT | M.N_EXT)]
        mobjs.append((min(taddr[e] for e in ext if e in taddr), o))
    mobjs = [o for _, o in sorted(mobjs, key=lambda t: t[0])]
    rep['libcc']['order_observed'] = [o.name for o in mobjs]
    final_inputs = []
    for a in order:
        p = RUN + ('out/' + os.path.basename(a) if a.startswith('stage/') else a)
        final_inputs.append(get(p))
    final_inputs += mobjs
    inner = {}
    for lib, ins in libs.items():
        lo = get(RUN + 'out/' + os.path.basename(lib))
        inner[lo.name] = [get(RUN + a) for a in ins]
    if perturb:
        perturb(final_inputs, inner)
    for o in list(cache.values()):
        rep['inputs'][o.name] = o.sha
    place = {}   # object path -> kind -> (linked start, size, input sect)
    for kind in KINDS:
        fc, fr = layout(final_inputs, sysk, kind)
        rep['layouts'].append(fr)
        for o, st, sz, s in fc:
            if o.name in inner:
                ic, ir = layout(inner[o.name], o, kind)
                rep['layouts'].append(ir)
                for io, ist, isz, isec in ic:
                    place.setdefault(io.name, {})[kind] = (st + ist - s['addr'], isz, isec)
            else:
                place.setdefault(o.name, {})[kind] = (st, sz, s)
    rep['layout_ok'] = all(r.get('ok', True) for r in rep['layouts'])
    return rep, place, cache


def p_consistent(d):
    fv = {f['verdict'] for f in d['functions']}
    return (d['object_verdict'] == 'NOT_MATCH' and fv <= {'MATCH', 'MATCH_UNVERIFIED'}
            and all(x.endswith(': unverified') for x in d['object_reasons']))


def objects(rep, place, cache):
    img = open(IMG, 'rb').read()
    rep['inputs'][IMG] = sha(img)
    sysk = cache[RUN + 'out/mach_kernel.sys']
    obss = sysk.sect(('__DATA', '__bss'))
    # original image sections (file offset per address) from the image's own header
    secs = []
    magic, cpu, sub, ft, n, sz, fl = struct.unpack_from('<7I', img, 0)
    o = 28
    for _ in range(n):
        cmd, cs = struct.unpack_from('<2I', img, o)
        if cmd == 1:
            ns = struct.unpack_from('<I', img, o + 48)[0]
            q = o + 56
            for _ in range(ns):
                sn = img[q:q + 16].rstrip(b'\0').decode()
                sg = img[q + 16:q + 32].rstrip(b'\0').decode()
                ad, size, off = struct.unpack_from('<3I', img, q + 32)
                secs.append(((sg, sn), ad, size, off))
                q += 68
        o += cs
    osec = {k: (a, s, f) for k, a, s, f in secs}
    reb = {}
    for f in glob.glob(V + 's6-l1-*-s6l4-*.json'):
        for r in json.load(open(f))['objects']:
            reb[r['object']] = r
    byhash = {c.sha: c for c in cache.values()}
    rows = tsv(PARTIAL)
    out = []
    for row in rows:
        r = {'object': row['object']}
        rb = reb[row['object']]
        lo = byhash.get(rb['obj_sha256'])
        r['rebuilt'] = {'record_obj': rb['obj'], 'obj_sha256': rb['obj_sha256'], 'link_input': lo.name if lo else None}
        if lo is None:
            r['problem'] = 'rebuilt object not among the link inputs'
            out.append(r)
            continue
        d = json.load(open(rb['l1']))
        unv = sorted(x.split(':')[0] for x in d['object_reasons'])
        r['l1'] = {'json': rb['l1'], 'bound': d['inputs'].get(rb['obj']) == rb['obj_sha256'],
                   'p_consistent': p_consistent(d), 'unverified': unv}
        listed = sorted(set(re.findall(r'__(?:DATA|TEXT),__\w+', row['unverified_sections'])))
        r['row_unverified'] = listed
        r['row_matches_l1'] = listed == unv
        bfile = glob.glob(V + 's6-l2-baseline-20261008/%03d-*.json' % rb['n'])[0]
        bj = json.load(open(bfile))
        rec = [k for k in bj['inputs'] if not k.startswith('03_original')][0]
        rob = Obj(rec, open(rec, 'rb').read())
        r['recorded'] = {'obj': rec, 'sha256': rob.sha, 'sha_ok': rob.sha == bj['inputs'][rec],
                         'same_bytes_as_rebuilt': rob.sha == lo.sha}
        secr = []
        for sname in unv:
            kind = SECTS.get(sname)
            e = {'section': sname}
            if kind is None:
                e['problem'] = 'section kind out of scope'
                secr.append(e)
                continue
            a, b = rob.sect(kind), lo.sect(kind)
            ra = lambda o_, s_: sorted((nm, v - s_['addr']) for nm, v in o_.syms(s_))
            e['recorded_vs_rebuilt'] = {
                'size_align_flags_equal': (a['size'], a['align'], a['flags']) == (b['size'], b['align'], b['flags']),
                'bytes_equal': True if kind[1] == '__bss' else
                rob.data[a['offset']:a['offset'] + a['size']] == lo.data[b['offset']:b['offset'] + b['size']],
                'symbols_equal': ra(rob, a) == ra(lo, b)}
            st, size, s = place[lo.name][kind]
            e['linked'] = [hex(st), hex(st + size)]
            e['size'] = size
            nsym, nstab = len(lo.syms(s)), len(lo.stabs(s))
            e['anchors'] = {'symbols': nsym, 'stabs': nstab}
            e['attribution'] = 'anchored' if nsym + nstab else 'order-dependent'
            oa, osz, ooff = osec[kind]
            e['inside_original_section'] = oa <= st and st + size <= oa + osz
            if kind[1] == '__const':
                e['original_bytes_equal'] = img[ooff + st - oa:ooff + st - oa + size] == \
                    lo.data[s['offset']:s['offset'] + size]
            else:
                # only the location written after "reference-inferred[-single] at" (an address or
                # [start, end)); other numbers in the text (Delta values, history) are not it
                txt = row['unverified_sections']
                locs = []
                for m in re.finditer(r'reference-inferred(?:-single)? at (?:\[0x([0-9a-f]+), 0x([0-9a-f]+)\)|0x([0-9a-f]+))', txt):
                    locs.append((int(m.group(1), 16), int(m.group(2), 16)) if m.group(1) else (int(m.group(3), 16), None))
                e['recorded_locations'] = [[hex(a_), hex(b_) if b_ is not None else None] for a_, b_ in locs]
                if locs:
                    e['recorded_equals_linked'] = all(a_ == st and (b_ is None or b_ == st + size) for a_, b_ in locs)
                else:
                    e['recorded_equals_linked'] = None   # unreferenced: no recorded location
            secr.append(e)
        r['sections'] = secr
        ok = (r['l1']['bound'] and r['l1']['p_consistent'] and r['recorded']['sha_ok'] and secr and
              all('problem' not in e and all(e['recorded_vs_rebuilt'].values()) and e['inside_original_section']
                  and e.get('original_bytes_equal', True) and e.get('recorded_equals_linked') is not False
                  for e in secr))
        r['proof_ok'] = bool(ok)
        out.append(r)
    rep['objects'] = out
    rep['summary'] = {
        'rows': len(out), 'proof_ok': sum(1 for x in out if x.get('proof_ok')),
        'row_matches_l1': sum(1 for x in out if x.get('row_matches_l1')),
        'rows_not_matching_l1': [x['object'] for x in out if not x.get('row_matches_l1')],
        'order_dependent': [(x['object'], e['section']) for x in out for e in x.get('sections', [])
                            if e.get('attribution') == 'order-dependent'],
        'failed': [x['object'] for x in out if not x.get('proof_ok')]}


def selftest():
    """each perturbation must break the layout proof"""
    res = {}

    def swap(fi, inner):
        i = next(k for k, o in enumerate(fi) if o.sect(('__DATA', '__bss')) and o.sect(('__DATA', '__bss'))['size'])
        j = next(k for k in range(i + 1, len(fi)) if fi[k].sect(('__DATA', '__bss')) and fi[k].sect(('__DATA', '__bss'))['size']
                 and fi[k].sect(('__DATA', '__bss'))['size'] != fi[i].sect(('__DATA', '__bss'))['size'])
        fi[i], fi[j] = fi[j], fi[i]

    def drop(fi, inner):
        i = next(k for k, o in enumerate(fi) if o.sect(('__TEXT', '__const')) and o.sect(('__TEXT', '__const'))['size'])
        del fi[i]

    def misalign(fi, inner):
        # a contribution that is preceded by alignment padding: dropping its alignment
        # moves it (one whose start is already aligned would not test anything)
        cur = None
        for o in fi:
            s = o.sect(('__TEXT', '__const'))
            if not s or not s['size']:
                continue
            if cur is None:
                cur = 0
            a = 1 << s['align']
            if up(cur, a) != cur:
                s['align'] = 0
                return
            cur = up(cur, a) + s['size']
        raise AssertionError('no padded __const contribution for the misalign test')

    for nm, f in (('swap_bss_order', swap), ('drop_const_input', drop), ('misalign_const', misalign)):
        rep, _, _ = build(f)
        res[nm] = {'layout_ok': rep['layout_ok'], 'detected': not rep['layout_ok']}
    return res


def main():
    out = sys.argv[1]
    rep, place, cache = build()
    objects(rep, place, cache)
    if '--selftest' in sys.argv:
        rep['selftest'] = selftest()
    json.dump(rep, open(out, 'w'), indent=1)
    for l in rep['layouts']:
        print('layout', l['output'].split('/')[-1], l['kind'], {k: l.get(k) for k in
              ('contributions', 'end_ok', 'symbols', 'symbols_ok', 'stabs', 'stabs_ok', 'absent')})
    print('layout_ok', rep['layout_ok'])
    print('summary', json.dumps(rep['summary']))
    if 'selftest' in rep:
        print('selftest', rep['selftest'])


if __name__ == '__main__':
    main()
