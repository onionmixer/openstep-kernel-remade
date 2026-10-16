#!/usr/bin/env python3
"""m5_m68k_nst.py -- plan 469 (M5-26): m68k kern/ns_timer.c, the six functions after the callout
queue (sched_usec_elapsed, microtime, microboot, us_timeout, us_abstimeout, us_untimeout):
variant comparison against the control object, final compile and acceptance.

  python3 10_tools/reconstruction/m5_m68k_srcvar.py stage SPEC.json STAGE_DIR   (staging)
  python3 10_tools/reconstruction/m5_m68k_srcvar.py cmd SPEC.json CC.cmd        (P469__<V>.o)
  python3 10_tools/reconstruction/m5_m68k_nst.py selftest OBJ.o
  python3 10_tools/reconstruction/m5_m68k_nst.py compare SPEC.json RUN_ID RECORD.json
  python3 10_tools/reconstruction/m5_m68k_nst.py cmdf CC.cmd
  python3 10_tools/reconstruction/m5_m68k_nst.py final RUN_ID REF.o RECORD.json

SPEC.json: an m5_m68k_srcvar.py spec with "source" (the m68k overlay), "control" K = [] and
"control_ref" (the plan 468 object), plus "targets": {variant: [function symbol, ...]}.
fsig     per object (plan 469.1/469.2): __text symbol groups (non-STABS SECT symbols at one
         address, names with the compiler '.N' suffix removed when normalising) with ranges to the
         next distinct address; per group the bytes with every relocation field zeroed and the
         relocations (offset in the group, pcrel, target): extern = (name, addend), local =
         (section, containing symbol, delta) of the effective address, scattered = (anchor
         r_value resolved likewise, addend).  Only VANILLA, 4-byte, non-straddling relocations
         and no R_ABS are accepted.  Non-text: section headers, file-backed bytes, bss size;
         symbols: (name, kind, ext, section name) without values.
compare  asserts every command status 0, every object present, K equal to control_ref (canon,
         Mach-O header, section headers, non-STABS symbols, fsig); per variant: groups differing
         from K, non-text and symbol equality with K, spans of the 19 original external
         functions (m0_m68k_cause.compare_object), undefined symbols not in the original.
         A variant passes when its target spans equal the original, only target groups differ
         from K, non-text and symbols equal K and no undefined symbol is new.
final    the overlay object RUN_ID/out/F469__ns_timer.o must equal REF.o (canon, header, section
         headers, non-STABS symbols), its L1 (--place-from-image) reasons must be exactly
         ['__DATA,__bss: unverified'], no undefined symbol new, m5_m68k_zerofill.py objs (REF) must
         pass and the bss candidate must not overlap the plan 467 nfs candidates; asserted.
"""
import sys, os, re, json, struct, hashlib, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

PLAN = 469
CC = '08_build/artifacts/m3p430/cc.cmd'
REL = 'kern/ns_timer.c'
P467_NFS = [(0x40b352c, 0x40b3530, 'x86-nfs_subr'), (0x40b3530, 0x40b3564, 'x86-nfs_vfsops')]


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def norm(name, strip):
    return re.sub(r'\.\d+$', '', name) if strip else name


def fsig(b, strip=True):
    import macho_obj
    o = macho_obj.parse(b)
    assert o['cputype'] == 6 and o['filetype'] == 1, (o['cputype'], o['filetype'])
    secs = {s['index']: s for s in o['sections']}
    syms = [y for y in o['symbols'] if y['kind'] == 'SECT' and not y['stab']]

    def locate(a, sect=None):
        cand = [s for s in o['sections'] if (sect is None or s['index'] == sect) and s['addr'] <= a < s['addr'] + s['size']]
        assert len(cand) == 1, ('address outside one section', hex(a), sect)
        s = cand[0]
        below = sorted((y['value'], norm(y['name'], strip)) for y in syms if y['sect'] == s['index'] and y['value'] <= a)
        if below:
            v = below[-1][0]
            return (s['sectname'], tuple(sorted(n for w, n in below if w == v)), a - v)
        return (s['sectname'], None, a - s['addr'])

    t = [s for s in o['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
    addrs = sorted({y['value'] for y in syms if y['sect'] == t['index']})
    assert addrs and addrs[0] == t['addr'], 'text does not start at a symbol'
    ranges = [(a, addrs[i + 1] if i + 1 < len(addrs) else t['addr'] + t['size']) for i, a in enumerate(addrs)]
    body = bytearray(b[t['offset']:t['offset'] + t['size']])
    rel = {a: [] for a, _ in ranges}
    for r in t['relocs']:
        assert r['type'] == 0 and r['length'] == 2, r
        a = r['address']
        grp = [lo for lo, hi in ranges if lo <= t['addr'] + a and t['addr'] + a + 4 <= hi]
        assert len(grp) == 1, ('relocation field straddles a range', hex(a))
        f = struct.unpack('>I', bytes(body[a:a + 4]))[0]
        fs = f - (1 << 32) if f & 0x80000000 else f
        P = t['addr'] + a
        if r['scattered']:
            V = r['value']
            add = (fs + P - V) if r['pcrel'] else (f - V)
            tgt = ('S', locate(V), add)
        elif r['extern']:
            add = (fs + P) if r['pcrel'] else f
            tgt = ('E', norm(o['symbols'][r['symbolnum']]['name'], strip), add)
        else:
            assert r['symbolnum'] != 0, 'R_ABS'
            eff = (P + fs) if r['pcrel'] else f
            tgt = ('L', locate(eff, r['symbolnum']))
        rel[grp[0]].append((P - grp[0], bool(r['pcrel']), tgt))
        body[a:a + 4] = b'\0\0\0\0'
    groups = {}
    for lo, hi in ranges:
        key = tuple(sorted(norm(y['name'], strip) for y in syms if y['sect'] == t['index'] and y['value'] == lo))
        assert key not in groups, ('duplicate group', key)
        groups[key] = (bytes(body[lo - t['addr']:hi - t['addr']]), tuple(sorted(rel[lo])))
    nontext = [(s['segname'], s['sectname'], s['size'], s.get('align'), s.get('flags'),
                b[s['offset']:s['offset'] + s['size']] if s['offset'] else None)
               for s in o['sections'] if s['index'] != t['index']]
    symbols = sorted((norm(y['name'], strip), y['kind'], bool(y.get('ext')),
                      secs[y['sect']]['sectname'] if y['kind'] == 'SECT' else None)
                     for y in o['symbols'] if not y['stab'])
    return dict(groups=groups, nontext=nontext, symbols=symbols)


def cmd_selftest(p):
    """K against K, and in-memory mutations that must change the signature (plan 469.2)."""
    import macho_obj
    b = open(p, 'rb').read()
    base = fsig(b)
    assert fsig(b) == base
    o = macho_obj.parse(b)
    t = [s for s in o['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
    kinds = {}
    for r in t['relocs']:
        k = 'scattered' if r['scattered'] else ('extern' if r['extern'] else 'local') + ('-pc' if r['pcrel'] else '-abs')
        kinds.setdefault(k, r['address'])
    out = {}
    for k, a in sorted(kinds.items()):
        m = bytearray(b)
        off = t['offset'] + a
        v = struct.unpack('>I', bytes(m[off:off + 4]))[0]
        m[off:off + 4] = struct.pack('>I', (v + 2) & 0xffffffff)
        out[k] = fsig(bytes(m)) != base
    covered = {r['address'] + i for r in t['relocs'] for i in range(4)}
    a = next(i for i in range(t['size']) if i not in covered)
    m = bytearray(b)
    m[t['offset'] + a] ^= 1
    out['plain-byte'] = fsig(bytes(m)) != base
    pc_targets = [(g, x) for g, (by, rl) in base['groups'].items() for x in rl if x[1] and x[2][0] == 'L']
    out['local-pc-targets-at-symbol-start'] = all(x[2][1][2] == 0 for g, x in pc_targets)
    print(json.dumps(dict(object=p, groups=len(base['groups']), mutation_changes_signature=out), indent=1))
    assert all(out.values()), out
    return out


def cmd_compare(spec, rid, outj):
    import m5_m68k_srcvar as SV
    import m5_m68k_nsq as Q
    import m0_m68k_cause as C
    import m3_m68k_diag as D
    import l2_prefix_diff as PD
    import macho_obj
    s = SV.load(spec)
    assert s['plan'] == PLAN and 'source' in s and set(s['targets']) <= set(s['variants']), s.keys()
    ctl = s['control']
    vs = sorted(s['variants'])
    stp = os.path.join('08_build/runs', rid, 'out', '_log', 'status')
    status = dict(l.split() for l in open(stp) if l.strip())
    assert len(status) == len(vs) and all(x == '0' for x in status.values()), status
    path = {v: os.path.join('08_build/runs', rid, 'out', 'P%d__%s.o' % (PLAN, v)) for v in vs}
    assert all(os.path.exists(p) for p in path.values())

    def sig(p):
        g = PD.obj_sig(p)
        return dict(canon=D.canon(p), header=g['header'], sections=g['sections'], symbols=g['symbols'])
    ks, rs = sig(path[ctl]), sig(s['control_ref'])
    assert ks == rs, {k: ks[k] == rs[k] for k in ks}
    kf = fsig(open(path[ctl], 'rb').read())
    assert kf == fsig(open(s['control_ref'], 'rb').read())
    img = C.Img()
    names = {y['name'] for y in img.img.o['symbols']}
    N = Q.names19()
    rows = []
    for v in vs:
        p = path[v]
        f = fsig(open(p, 'rb').read())
        diff = sorted(set(kf['groups']) ^ set(f['groups'])) + sorted(k for k in set(kf['groups']) & set(f['groups'])
                                                                   if kf['groups'][k] != f['groups'][k])
        _, ts, spans = C.compare_object(img, p, N)
        sp = {x['name']: x.get('equal') for x in spans if 'image_address' in x}
        o = macho_obj.parse(open(p, 'rb').read())
        undef = sorted({y['name'] for y in o['symbols'] if y['kind'] == 'UNDF' and not y['stab']} - names)
        tg = s['targets'].get(v, [])
        r = dict(variant=v, sha256=sha(p), targets=tg, groups_differ_from_K=[list(k) for k in diff],
                 nontext_equal_K=f['nontext'] == kf['nontext'], symbols_equal_K=f['symbols'] == kf['symbols'],
                 spans=sp, spans_missing=sorted(set(N) - set(sp)), undefined_not_in_original=undef,
                 text_size=ts['size'])
        r['ok'] = (v != ctl and bool(tg) and all(sp.get(n) is True for n in tg)
                   and all(len(k) == 1 and k[0] in tg for k in diff)
                   and r['nontext_equal_K'] and r['symbols_equal_K'] and not undef and not r['spans_missing'])
        rows.append(r)
    canon = {v: D.canon(path[v]) for v in vs}
    groups = []
    for v in vs:
        for g in groups:
            if canon[g[0]] == canon[v]:
                g.append(v)
                break
        else:
            groups.append([v])
    S = dict(control_equals_ref=True, ok=[r['variant'] for r in rows if r['ok']], canon_groups=groups,
             by_variant={r['variant']: dict(targets=r['targets'], differ=r['groups_differ_from_K'],
                                            target_spans={n: r['spans'].get(n) for n in r['targets']}) for r in rows})
    json.dump(dict(plan=PLAN, tool='10_tools/reconstruction/m5_m68k_nst.py', tool_sha256=sha(os.path.abspath(__file__)),
                   srcvar_sha256=sha(os.path.join(HERE, 'm5_m68k_srcvar.py')), run=rid, spec_sha256=sha(spec),
                   source=s['source'], source_sha256=sha(s['source']), base=s['base'],
                   base_manifest_sha256=sha(s['base'] + '.manifest.json'),
                   compile_line_sha256=hashlib.sha256(SV.cc_line(s).encode()).hexdigest(),
                   control_ref=s['control_ref'], control_ref_sha256=sha(s['control_ref']), names=N,
                   summary=S, variants=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))


def cc_line():
    hits = [l.rstrip('\n') for l in open(CC) if l.startswith('RUN ') and ' src/src/%s ' % REL in l]
    assert len(hits) == 1, len(hits)
    return hits[0]


def cmd_cmdf(out):
    w = cc_line().split()
    assert w[w.index('-c') + 1] == 'src/src/' + REL
    w[w.index('-o') + 1] = 'stage/F%d__ns_timer.o' % PLAN
    open(out, 'w').write('# m5p%d: plan %d final compile of the ns_timer overlay (m5_m68k_nst.py cmdf)\n' % (PLAN, PLAN)
                         + ' '.join(w) + '\nEXPECT F%d__ns_timer.o\n' % PLAN)
    print('commands', 1)


def cmd_final(rid, ref, outj):
    import m0_m68k_cause as C
    import m3_m68k_diag as D
    import l2_prefix_diff as PD
    import macho_obj
    p = os.path.join('08_build/runs', rid, 'out', 'F%d__ns_timer.o' % PLAN)
    art = '08_build/artifacts/m5p%d/%s' % (PLAN, rid)
    os.makedirs(art, exist_ok=True)
    ga, gb = PD.obj_sig(p), PD.obj_sig(ref)
    ref_equal = dict(canon=D.canon(p) == D.canon(ref), header=ga['header'] == gb['header'],
                     sections=ga['sections'] == gb['sections'], symbols=ga['symbols'] == gb['symbols'])
    d = C.run_l1(p, os.path.join(art, 'l1-F%d.json' % PLAN))
    img = C.Img()
    names = {y['name'] for y in img.img.o['symbols']}
    o = macho_obj.parse(open(p, 'rb').read())
    undef = sorted({y['name'] for y in o['symbols'] if y['kind'] == 'UNDF' and not y['stab']} - names)
    zj = os.path.join(art, 'zerofill-objs.json')
    z = subprocess.run([sys.executable, os.path.join(HERE, 'm5_m68k_zerofill.py'), 'objs', os.path.join(art, 'zerofill'), zj,
                        str(PLAN), 'x86-ns_timer:%s:%s' % (p, ref)], capture_output=True, text=True)
    zr = json.load(open(zj)) if os.path.exists(zj) else {}
    cand = (zr.get('summary') or {}).get('candidates', {}).get('x86-ns_timer')
    ov = [n for a, e, n in P467_NFS if cand and a < int(cand[1], 16) and int(cand[0], 16) < e]
    r = dict(obj=p, obj_sha256=sha(p), ref=ref, ref_sha256=sha(ref), ref_equal=ref_equal,
             l1=os.path.join(art, 'l1-F%d.json' % PLAN), l1_verdict=d['object_verdict'], l1_reasons=d.get('object_reasons'),
             undefined_not_in_original=undef, zerofill_returncode=z.returncode, zerofill_record=zj,
             zerofill_record_sha256=sha(zj) if os.path.exists(zj) else None, bss_candidate=cand, overlaps_plan467_nfs=ov)
    r['ok'] = (all(ref_equal.values()) and r['l1_reasons'] == ['__DATA,__bss: unverified'] and not undef
               and z.returncode == 0 and cand is not None and not ov)
    json.dump(dict(plan=PLAN, tool='10_tools/reconstruction/m5_m68k_nst.py', tool_sha256=sha(os.path.abspath(__file__)),
                   run=rid, result=r), open(outj, 'w'), indent=1)
    print(json.dumps(r, indent=1))
    assert r['ok'], 'plan 469 final check failed'


def main():
    a = sys.argv[1:]
    if a[:1] == ['selftest'] and len(a) == 2:
        cmd_selftest(a[1])
    elif a[:1] == ['compare'] and len(a) == 4:
        cmd_compare(*a[1:])
    elif a[:1] == ['cmdf'] and len(a) == 2:
        cmd_cmdf(a[1])
    elif a[:1] == ['final'] and len(a) == 4:
        cmd_final(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
