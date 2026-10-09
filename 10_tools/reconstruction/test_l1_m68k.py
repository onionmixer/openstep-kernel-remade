#!/usr/bin/env python3
"""Tests for the big-endian / m68k path of l1_compare (plan 411).

  test_l1_m68k.py RUN_OUT_DIR [--report FILE]

RUN_OUT_DIR is the out/ of kr_run m0p411-pr1: a-<arch>.o, b-<arch>.o (cc -static -O2) and
probe-<arch>.out (ld -static -e _kr_a) for m68k and i386 (control), plus the SPARC objects.
  P*  every object OBJECT_MATCH against its own link (m68k and i386)
  N1  a byte outside every relocation field of _kr_a changed in a copy -> _kr_a DIFF
  N2  an external pc-relative field of _kr_a changed -> _kr_a DIFF
  N3  an external absolute field in __data changed -> object NOT_MATCH
  N4  a local absolute field of _kr_a changed -> _kr_a DIFF
  R1  m68k object against the i386 link -> refused (CPU / byte order differ)
  R2  SPARC object -> refused (machine-specific relocation types not implemented)
"""
import json, os, shutil, sys, tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import l1_compare as L
import macho_obj


def run(img_path, obj_path):
    img = L.Image(img_path)
    pl = L.placements_from_image(img, obj_path)
    r = L.compare(img, obj_path, pl, None, set(pl))
    return r


def fverdict(r, name):
    return [f['verdict'] for f in r['functions'] if name in f['names']][0]


def main():
    out = sys.argv[1]
    rep = sys.argv[sys.argv.index('--report') + 1] if '--report' in sys.argv else None
    res = []

    def check(tid, what, ok, detail=''):
        res.append(dict(id=tid, what=what, ok=bool(ok), detail=detail))
        print('%-4s %-4s %s %s' % ('ok' if ok else 'FAIL', tid, what, detail))

    for arch in ('m68k', 'i386'):
        img = os.path.join(out, 'probe-%s.out' % arch)
        for f in ('a', 'b'):
            r = run(img, os.path.join(out, '%s-%s.o' % (f, arch)))
            check('P', '%s-%s.o OBJECT_MATCH' % (f, arch), r['object_verdict'] == 'OBJECT_MATCH',
                  r['object_verdict'] + ' ' + str(r['object_reasons'][:3]))
    # mutations on copies of the m68k link
    img_path = os.path.join(out, 'probe-m68k.out')
    obj_path = os.path.join(out, 'a-m68k.o')
    obj = macho_obj.read(obj_path)
    assert obj['cputype'] == macho_obj.CPU_M68K and obj['endian'] == 'big'
    img = L.Image(img_path)
    pl = L.placements_from_image(img, obj_path)
    text = [s for s in obj['sections'] if s['sectname'] == '__text'][0]
    data = [s for s in obj['sections'] if s['sectname'] == '__data'][0]
    ka = [y['value'] - text['addr'] for y in obj['symbols'] if y['name'] == '_kr_a'][0]
    starts = sorted({y['value'] - text['addr'] for y in obj['symbols']
                     if y['kind'] == 'SECT' and y['sect'] == text['index'] and not y['stab']})
    ke = ([x for x in starts if x > ka] + [text['size']])[0]
    fields = set()
    for r in text['relocs']:
        fields.update(range(r['address'], r['address'] + (1 << r['length'])))
    tdelta = pl['__TEXT,__text'] - text['addr']
    toff = lambda a: [s for s in img.secs if s['addr'] <= a < s['addr'] + s['size']][0]

    def file_off(addr):
        s = toff(addr)
        return s['offset'] + addr - s['addr']

    def mutated(tid, what, addr, expect_fn):
        tmp = tempfile.mkdtemp()
        try:
            p = os.path.join(tmp, 'img')
            b = bytearray(open(img_path, 'rb').read())
            b[file_off(addr)] ^= 0x01
            open(p, 'wb').write(bytes(b))
            r = run(p, obj_path)
            ok, det = expect_fn(r)
            check(tid, what, ok, det)
        finally:
            shutil.rmtree(tmp)

    nonfield = [k for k in range(ka, ke) if k not in fields][2]
    mutated('N1', 'byte outside relocation fields of _kr_a', text['addr'] + tdelta + nonfield,
            lambda r: (fverdict(r, '_kr_a') == 'DIFF', fverdict(r, '_kr_a')))
    ext_pc = [r for r in text['relocs'] if not r['scattered'] and r['extern'] and r['pcrel'] and ka <= r['address'] < ke][0]
    mutated('N2', 'external pc-relative field of _kr_a', text['addr'] + tdelta + ext_pc['address'] + 3,
            lambda r: (fverdict(r, '_kr_a') == 'DIFF', fverdict(r, '_kr_a')))
    ext_abs = [r for r in data['relocs'] if not r['scattered'] and r['extern']][0]
    ddelta = pl.get('__DATA,__data')
    if ddelta is None:
        check('N3', 'external absolute field in __data', False, '__data not placed by symbol')
    else:
        mutated('N3', 'external absolute field in __data', ddelta + ext_abs['address'] + 3,
                lambda r: (r['object_verdict'] == 'NOT_MATCH', str(r['object_reasons'][:2])))
    loc_abs = [r for r in text['relocs'] if not r['scattered'] and not r['extern'] and not r['pcrel']
               and ka <= r['address'] < ke][0]
    mutated('N4', 'local absolute field of _kr_a', text['addr'] + tdelta + loc_abs['address'] + 3,
            lambda r: (fverdict(r, '_kr_a') == 'DIFF', fverdict(r, '_kr_a')))
    try:
        run(os.path.join(out, 'probe-i386.out'), obj_path)
        check('R1', 'm68k object vs i386 image refused', False, 'compared')
    except macho_obj.MachOError as e:
        check('R1', 'm68k object vs i386 image refused', True, str(e))
    try:
        L.types_of(macho_obj.read(os.path.join(out, 'a-sparc.o')))
        check('R2', 'SPARC object refused', False, 'accepted')
    except macho_obj.MachOError as e:
        check('R2', 'SPARC object refused', True, str(e))
    nf = sum(1 for x in res if not x['ok'])
    print('%d tests, %d failed' % (len(res), nf))
    if rep:
        open(rep, 'w').write(json.dumps(dict(plan=411, out=out, tests=res), indent=1) + '\n')
    sys.exit(1 if nf else 0)


if __name__ == '__main__':
    main()
