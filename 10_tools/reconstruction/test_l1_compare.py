#!/usr/bin/env python3
"""Self-tests T1-T3 for l1_compare.py (plan sections 12 and 12.1).

  test_l1_compare.py RUN_OUT_DIR [--report FILE]

RUN_OUT_DIR is a published kr_run output with t1img (linked by the target ld
at __TEXT 0x100000) and the objects c_codegen.o, c_layout.o, ext.o,
asm_probe.o, asm_reloc.o.  Mutations are made on copies of t1img in a
temporary directory; the inputs are never changed.
"""
import json, os, shutil, sys, tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import l1_compare as L
import macho_obj

OBJS = ['c_codegen', 'c_layout', 'ext', 'asm_probe', 'asm_reloc']


def run(img_path, obj_path, user=None, ranges=None, from_image=True):
    img = L.Image(img_path)
    pl = L.placements_from_image(img, obj_path) if from_image else {}
    by_symbol = set(pl)
    for k, v in (user or {}).items():
        pl[k] = v
        by_symbol.discard(k)
    r = L.compare(img, obj_path, pl, ranges, by_symbol)
    return {','.join(f['names']): f['verdict'] for f in r['functions']}, r


def field(img_path, obj_path, sect, pred):
    """Image address of the first relocation field in sect satisfying pred."""
    img = L.Image(img_path)
    pl = L.placements_from_image(img, obj_path)
    o = macho_obj.read(obj_path)
    for s in o['sections']:
        if L.key(s) != sect:
            continue
        for r in s['relocs']:
            if pred(o, r):
                return pl[sect] + r['address'], o, s, r
    raise SystemExit('no field for test in %s %s' % (obj_path, sect))


def patch(path, addr, new4=None, xor_byte=None):
    img = L.Image(path)
    for s in img.secs:
        if s['addr'] <= addr < s['addr'] + s['size']:
            off = s['offset'] + addr - s['addr']
            break
    else:
        raise SystemExit('address %#x not in image' % addr)
    d = bytearray(open(path, 'rb').read())
    if new4 is not None:
        d[off:off + 4] = (new4 % (1 << 32)).to_bytes(4, 'little')
    if xor_byte is not None:
        d[off] ^= xor_byte
    open(path, 'wb').write(d)


def main():
    out = sys.argv[1]
    report = sys.argv[sys.argv.index('--report') + 1] if '--report' in sys.argv else None
    img0 = os.path.join(out, 't1img')
    o = {n: os.path.join(out, n + '.o') for n in OBJS}
    results, fails = [], []

    def expect(name, got, want):
        ok = all(got.get(k) == v for k, v in want.items())
        results.append(dict(test=name, want=want, got=got, ok=ok))
        if not ok:
            fails.append(name)

    # T1: everything matches against the linked image
    for n in OBJS:
        got, _ = run(img0, o[n])
        expect('T1 %s' % n, got, {k: 'MATCH' for k in got})
    base = {n: run(img0, o[n])[0] for n in OBJS}
    tmp = tempfile.mkdtemp(prefix='l1test-')
    try:
        def mutated(tag):
            p = os.path.join(tmp, tag)
            shutil.copyfile(img0, p)
            return p
        ext_addr = L.Image(img0).symbol('_kr_ext')
        leaf_addr = L.Image(img0).symbol('_kr_leaf')

        # M1: extern pc-relative call to _kr_ext retargeted to _kr_leaf
        p = mutated('m1')
        a, ob, s, r = field(img0, o['c_codegen'], '__TEXT,__text',
                            lambda ob, r: not r['scattered'] and r['extern'] and r['pcrel'])
        patch(p, a, new4=leaf_addr - (a + 4))
        got, _ = run(p, o['c_codegen'])
        expect('T2 M1 call target changed', got, dict(base['c_codegen'], _kr_calls='DIFF'))

        # M2: absolute _kr_global+8 field changed by +4
        p = mutated('m2')
        a, ob, s, r = field(img0, o['asm_reloc'], '__TEXT,__text',
                            lambda ob, r: not r['scattered'] and r['extern'] and not r['pcrel'])
        cur = int.from_bytes(L.Image(img0).read(a, 4), 'little')
        patch(p, a, new4=cur + 4)
        got, _ = run(p, o['asm_reloc'])
        expect('T2 M2 addend changed', got, dict(base['asm_reloc'], _kr_reloc_a='DIFF'))

        # M3: one jump-table entry of _kr_switch swapped with another entry's value
        img = L.Image(img0)
        pl = L.placements_from_image(img, o['c_codegen'])
        cg = macho_obj.read(o['c_codegen'])
        txt = [x for x in cg['sections'] if L.key(x) == '__TEXT,__text'][0]
        sw = [y['value'] for y in cg['symbols'] if y['name'] == '_kr_switch'][0]
        st = [y['value'] for y in cg['symbols'] if y['name'] == '_kr_store'][0]
        tab = sorted(r['address'] for r in txt['relocs'] if not r['scattered'] and not r['extern']
                     and r['symbolnum'] == txt['index'] and sw <= r['address'] < st)
        if len(tab) < 2:
            raise SystemExit('no jump table found for M3')
        a0, a1 = pl['__TEXT,__text'] + tab[0], pl['__TEXT,__text'] + tab[1]
        v1 = int.from_bytes(img.read(a1, 4), 'little')
        p = mutated('m3')
        patch(p, a0, new4=v1)
        got, _ = run(p, o['c_codegen'])
        expect('T2 M3 jump table entry', got, dict(base['c_codegen'], _kr_switch='DIFF'))

        # M4: a byte outside every relocation field in _kr_leaf
        p = mutated('m4')
        patch(p, leaf_addr, xor_byte=0x01)
        got, _ = run(p, o['c_codegen'])
        expect('T2 M4 plain byte', got, dict(base['c_codegen'], _kr_leaf='DIFF'))

        # M5: an external range for _kr_leaf that runs 4 bytes past the object range
        _, r0 = run(img0, o['c_codegen'])
        f = [x for x in r0['functions'] if '_kr_leaf' in x['names']][0]
        rng = {'_kr_leaf': (f['image_range'][0], f['image_range'][1] + 4)}
        got, _ = run(img0, o['c_codegen'], ranges=rng)
        expect('T2 M5 boundary', got, dict(base['c_codegen'], _kr_leaf='BOUNDARY'))

        # T3a: __data of asm_reloc is inferred (no symbol there) and verified
        _, r = run(img0, o['asm_reloc'])
        ok = r['sections']['__DATA,__data']['placement'] == 'inferred, verified by L1d'
        results.append(dict(test='T3a data placement inferred', ok=ok, got=r['sections']['__DATA,__data']['placement']))
        if not ok:
            fails.append('T3a')

        # M6: one data byte changed -> referencing functions are not MATCH
        dat = r['placements']['__DATA,__data']
        p = mutated('m6')
        patch(p, dat, xor_byte=0x01)
        got, r6 = run(p, o['asm_reloc'])
        ok = got.get('_kr_reloc_a') == 'DIFF' and got.get('_kr_other_sect') == 'DIFF'
        results.append(dict(test='T3 M6 data byte', ok=ok, got=got))
        if not ok:
            fails.append('T3 M6')

        # M7: one reference to Lkr_data pointed elsewhere -> inference ambiguous, nothing MATCH
        a, ob, s, rr = field(img0, o['asm_reloc'], '__TEXT,__kr_text2',
                             lambda ob, r: not r['scattered'] and not r['extern'])
        cur = int.from_bytes(L.Image(img0).read(a, 4), 'little')
        p = mutated('m7')
        patch(p, a, new4=cur + 0x40)
        got, r7 = run(p, o['asm_reloc'])
        ok = 'ambiguous' in r7['sections']['__DATA,__data']['placement'] and \
             got.get('_kr_reloc_a') != 'MATCH' and got.get('_kr_other_sect') != 'MATCH'
        results.append(dict(test='T3 M7 ambiguous inference', ok=ok, got=got,
                            placement=r7['sections']['__DATA,__data']['placement']))
        if not ok:
            fails.append('T3 M7')

        # M8: zero-fill placement given by the user (not by symbol) stays unverified
        user = L.placements_from_image(L.Image(img0), o['c_codegen'])
        got, _ = run(img0, o['c_codegen'], user={'__DATA,__common': user['__DATA,__common']},
                     from_image=True)
        # re-run with that section declared user-given
        img = L.Image(img0)
        pl = L.placements_from_image(img, o['c_codegen'])
        r8 = L.compare(img, o['c_codegen'], pl, None, set(pl) - {'__DATA,__common'})
        got = {','.join(f['names']): f['verdict'] for f in r8['functions']}
        expect('T3 M8 user zero-fill', got, dict(base['c_codegen'], _kr_calls='MATCH_UNVERIFIED',
                                                 _kr_store='MATCH_UNVERIFIED'))
    finally:
        shutil.rmtree(tmp)
    summary = dict(run=out, tests=len(results), failed=fails, results=results)
    if report:
        json.dump(summary, open(report, 'w'), indent=1)
    for x in results:
        print('%-4s %s' % ('ok' if x['ok'] else 'FAIL', x['test']))
    print('%d tests, %d failed' % (len(results), len(fails)))
    sys.exit(1 if fails else 0)


if __name__ == '__main__':
    main()
