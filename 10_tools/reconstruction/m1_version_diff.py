#!/usr/bin/env python3
"""m1_version_diff.py -- plan 410 (D065): what differs between the x86 mk-183.34.4 kernel and the
i386 mk-183.34 kernel in the plan-409 candidate objects.  Read-only apart from OUTDIR/WORKDIR.

  python3 10_tools/reconstruction/m1_version_diff.py run      OUT.json OUTDIR
  python3 10_tools/reconstruction/m1_version_diff.py selftest OUT.json WORKDIR

Function ranges come from the s6 rebuilt object (external, static and ObjC method symbols of
__TEXT,__text); its __text is L1-equal to the x86 original, so x86 address = recorded x86
placement + offset.  183.34 correspondence is by entry point only: an external name unique in
the 183.34 __text, or the unique IMP of (class, category, kind, selector).  A static function
has no entry of its own; it is located only when plan 409 placed the whole __text with one Delta.
Each located function (length = rebuilt-object length) is classified:
  same                 bytes equal
  address_only         every byte outside the object's relocation fields equal, and every
                       differing field is predicted exactly, in both images, by the object's
                       relocation (l1_compare.evaluate / lit_check): external symbols by name,
                       local targets only through 183.34 placements made from names ('given by
                       symbol' / 'given by objc metadata'; never inferred ones), literals by content
  unresolved_address   bytes outside the fields equal, some differing field not resolvable
  content              a byte outside the relocation fields differs (both sides disassembled;
                       the 183.34 side is the interval to its next entry point, not a size)
  symbol_absent        the entry point does not exist in 183.34
  not_located          static function, __text not placed in 183.34 as a whole, or some entry point
                       of the object is absent in 183.34 (layout changed; no aligned comparison)
Data-only version objects: their data sections are compared where plan 409 placed them;
an unplaced section is searched for by its first 16 bytes (a search candidate, not a placement).
"""
import sys, os, json, hashlib, re, subprocess, difflib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj, l1_compare, objc_meta

X86 = '03_original/x86/binaries/mach_kernel'
X86_SHA = '33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890'
OLD = '03_original/x86-mk-183.34/binaries/mach_kernel'
OLD_SHA = 'cb6217c2f454c07b4eb8d6a98850cb2e3bb9cadac477449ea1ad17999bcdf78f'
M0 = '09_validation/reconstruction/m0-i386-18334-l1-20261009.json'
CODE = ['x86-FBConsole', 'x86-unix_startup', 'x86-rtc', 'x86-IODisk', 'x86-BasicConsole',
        'x86-mach_clock', 'x86-pmap', 'x86-km', 'x86-IOAudio']
DATA = ['x86-vers', 'x86-libDriver_vers', 'x86-objc_vers']
TEXT = '__TEXT,__text'
METH = re.compile(r'^([+-])\[(\w+)(?:\((\w+)\))? (.+)\]$')


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


class Img:
    def __init__(self, path):
        self.path = path
        self.d = open(path, 'rb').read()
        self.o = macho_obj.parse(self.d)
        macho_obj.require_i386(self.o, 'm1_version_diff')  # plan 411: i386 little-endian only
        self.text = [s for s in self.o['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
        self.sym = {}
        for y in self.o['symbols']:
            if not y['stab'] and y['kind'] in ('SECT', 'ABS'):
                self.sym.setdefault(y['name'], []).append(y)
        self.l1 = l1_compare.Image(path)
        self.meta = objc_meta.Meta(self.l1).read()
        self.imp = {}
        for m in self.meta['methods']:
            self.imp.setdefault((m['owner'], m['category'], m['kind'], m['selector']), []).append(m['imp'])
        t = self.text
        self.entries = sorted({y['value'] for v in self.sym.values() for y in v
                               if y['kind'] == 'SECT' and y['sect'] == t['index']} |
                              {a for v in self.imp.values() for a in v if t['addr'] <= a < t['addr'] + t['size']})

    def text_sym(self, name):
        v = [y for y in self.sym.get(name, []) if y['kind'] == 'SECT' and y['sect'] == self.text['index']]
        return v[0]['value'] if len(v) == 1 else None

    def any_sym(self, name):
        v = self.sym.get(name, [])
        return v[0]['value'] if len(v) == 1 else None

    def read(self, addr, n):
        for s in self.o['sections']:
            if s['addr'] <= addr and addr + n <= s['addr'] + s['size'] and (s['flags'] & 0xff) != 1:
                o = s['offset'] + addr - s['addr']
                return self.d[o:o + n]
        return None

    def next_entry(self, addr):
        later = [a for a in self.entries if a > addr]
        return later[0] if later else self.text['addr'] + self.text['size']


def obj_functions(objpath):
    ob = open(objpath, 'rb').read()
    o = macho_obj.parse(ob)
    macho_obj.require_i386(o, 'm1_version_diff')
    t = [s for s in o['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')]
    if not t or not t[0]['size']:
        return o, ob, None, []
    t = t[0]
    by = {}
    for y in o['symbols']:
        if y['kind'] == 'SECT' and not y['stab'] and y['sect'] == t['index']:
            by.setdefault(y['value'] - t['addr'], []).append(y)
    starts = sorted(by)
    if starts[0] != 0:
        starts = [0] + starts
        by[0] = [dict(name='<section start>', ext=False)]
    fields = []
    for i, r in enumerate(t['relocs']):
        if r['scattered'] and l1_compare.TYPE.get(r['type']) == 'PAIR':
            continue
        name = o['symbols'][r['symbolnum']]['name'] if (not r['scattered'] and r['extern']) else None
        fields.append(dict(off=r['address'], w=1 << r['length'], pcrel=bool(r['pcrel']), name=name, rel=i))
    fs = []
    for i, st in enumerate(starts):
        en = starts[i + 1] if i + 1 < len(starts) else t['size']
        fs.append(dict(start=st, end=en, syms=by[st], fields=[f for f in fields if st <= f['off'] < en]))
    return o, ob, t, fs


def entry_of(img, ys):
    """183.34 / x86 entry of a function from its symbols: ('ext', name) or ('method', key)."""
    for y in ys:
        if y.get('ext'):
            return ('ext', y['name'], img.text_sym(y['name']))
    for y in ys:
        m = METH.match(y['name'])
        if m:
            k = (m.group(2), m.group(3), 'instance' if m.group(1) == '-' else 'class', m.group(4))
            v = img.imp.get(k, [])
            return ('method', y['name'], v[0] if len(v) == 1 else None)
    return ('static', ys[0]['name'], None)


def disasm(img, addr, n):
    b = img.read(addr, n)
    tmp = os.path.join(WORK, 'dis.bin')
    open(tmp, 'wb').write(b)
    p = subprocess.run(['objdump', '-D', '-b', 'binary', '-m', 'i386', '--adjust-vma=0x%x' % addr, tmp],
                       capture_output=True, text=True, check=True)
    lines = [l for l in p.stdout.split('\n') if re.match(r'^\s+[0-9a-f]+:\t', l)]
    return lines


def classify(xi, si, fn, xa, sa, ctx):
    """ctx: obj, ob, text section, dx/ds (section index -> Delta in x86 / 183.34; ds holds only
    placements made from names), slice_text_placed."""
    n = fn['end'] - fn['start']
    bx, bs = xi.read(xa, n), si.read(sa, n)
    if bs is None:
        return dict(kind='content', why='183.34 range leaves the section')
    if bx == bs:
        return dict(kind='same')
    mask = set()
    for f in fn['fields']:
        mask.update(range(f['off'] - fn['start'], f['off'] - fn['start'] + f['w']))
    outside = [k for k in range(n) if bx[k] != bs[k] and k not in mask]
    if outside:
        return dict(kind='content', first_diff=outside[0], diff_bytes=len(outside))
    o, ob, t = ctx['obj'], ctx['ob'], ctx['text']
    unresolved, checked = [], 0
    for f in fn['fields']:
        k = f['off'] - fn['start']
        if bx[k:k + f['w']] == bs[k:k + f['w']]:
            continue
        checked += 1
        ok = True
        for img, delta, b, base in ((xi, dict(ctx['dx']), bx, xa), (si, dict(ctx['ds']), bs, sa)):
            delta[t['index']] = base - fn['start'] - t['addr']       # this function's Delta (field section)
            a, w, exp, why, used = l1_compare.evaluate(img.l1, o, ob, delta, t, f['rel'])
            V = int.from_bytes(b[k:k + f['w']], 'little')
            if img is si and t['index'] in used and not ctx['slice_text_placed']:
                ok, why = False, 'refers to __text, which is not placed as a whole in 183.34'
            elif isinstance(why, tuple) and why[0] == 'LIT':
                _, T, Fv, pcrel = why
                if pcrel or w != 4:
                    ok, why = False, 'pc-relative or narrow literal reference'
                else:
                    res, why = l1_compare.lit_check(img.l1, o, ob, T, Fv, V)
                    ok = ok and res == 'equal'
            elif exp is None:
                ok = False
            else:
                ok = ok and (exp % (1 << (8 * w))) == V
            if not ok:
                unresolved.append(dict(off=k, image='x86' if img is xi else '183.34', why=str(why)))
                break
    if unresolved:
        return dict(kind='unresolved_address', fields_differing=checked, unresolved=unresolved)
    return dict(kind='address_only', fields_differing=checked)


def analyse(xi, si, rows, outdir):
    res = []
    for r in rows:
        if r['object'] not in CODE:
            continue
        o, ob, t, fs = obj_functions(r['obj'])
        xdet = r['x86_detail']
        xt, st = xdet['placements'].get(TEXT), r['slice_text']
        named = ('given by symbol', 'given by objc metadata')
        idx = {'%s,%s' % (q['segname'], q['sectname']): q for q in o['sections']}
        dx = {idx[k]['index']: v - idx[k]['addr'] for k, v in xdet['placements'].items() if v is not None}
        ds = {idx[k]['index']: v - idx[k]['addr'] for k, v in r['slice_detail']['placements'].items()
              if v is not None and r['slice_detail']['sections'][k]['placement'] in named}
        ctx = dict(obj=o, ob=ob, text=t, dx=dx, ds=ds, slice_text_placed=st is not None)
        rec = dict(object=r['object'], obj=r['obj'], obj_sha256=r['obj_sha256'], x86_text=xt,
                   slice_text=st, slice_text_placement=r['slice_text_placement'], functions=[])
        # a static function is located by the whole-__text Delta only when every entry point of
        # the object exists in 183.34 (an absent one means the object's layout changed)
        absent = [entry_of(si, fn['syms'])[1] for fn in fs
                  if entry_of(si, fn['syms'])[0] != 'static' and entry_of(si, fn['syms'])[2] is None]
        rec['entry_points_absent'] = absent
        for fn in fs:
            xa = xt + fn['start']
            how, name, sa = entry_of(si, fn['syms'])
            if how == 'static' and st is not None and not absent:
                sa = st + fn['start']
            # the x86 entry must agree with the recorded placement (checks the correspondence rule)
            if how != 'static':
                _, _, xa2 = entry_of(xi, fn['syms'])
                assert xa2 == xa, (r['object'], name, xa2, xa)
            e = dict(names=[y['name'] for y in fn['syms']], entry=how, object_range=[fn['start'], fn['end']],
                     x86_address=xa, slice_address=sa, relocation_fields=len(fn['fields']))
            if sa is None:
                e['kind'] = 'symbol_absent' if how != 'static' else 'not_located'
            else:
                e.update(classify(xi, si, fn, xa, sa, ctx))
                if sa is not None and how != 'static':
                    e['slice_interval'] = si.next_entry(sa) - sa
                if e['kind'] == 'content' and outdir:
                    L = fn['end'] - fn['start']
                    I = min(e.get('slice_interval', L), si.text['addr'] + si.text['size'] - sa)
                    dx, ds = disasm(xi, xa, L), disasm(si, sa, I)
                    strip = lambda ls: [l.split('\t', 2)[-1].strip() for l in ls]
                    diff = list(difflib.unified_diff(strip(dx), strip(ds), 'x86 mk-183.34.4', 'i386 mk-183.34',
                                                     n=2, lineterm=''))
                    fnm = re.sub(r'[^A-Za-z0-9_.-]', '_', '%s-%s' % (r['object'], e['names'][0]))[:120] + '.txt'
                    p = os.path.join(outdir, fnm)
                    open(p, 'w').write('\n'.join(['# plan 410: %s %s' % (r['object'], e['names']),
                                                  '# x86 %#x len %d (rebuilt-object length); 183.34 %#x interval %d (to next entry point; not a size)'
                                                  % (xa, L, sa, I), '', '## diff (instruction text only)'] + diff +
                                                 ['', '## x86 mk-183.34.4'] + dx + ['', '## i386 mk-183.34'] + ds) + '\n')
                    e['disassembly'] = p
                    e['disassembly_sha256'] = sha(p)
                    e['diff_lines'] = sum(1 for l in diff if l[:1] in '+-' and not l.startswith(('+++', '---')))
            rec['functions'].append(e)
        res.append(rec)
    return res


def analyse_data(xi, si, rows):
    res = []
    for r in rows:
        if r['object'] not in DATA:
            continue
        o = macho_obj.parse(open(r['obj'], 'rb').read())
        rec = dict(object=r['object'], obj=r['obj'], sections=[])
        for s in o['sections']:
            k = '%s,%s' % (s['segname'], s['sectname'])
            if not s['size']:
                continue
            xa = r['x86_detail']['placements'].get(k)
            sa = r['slice_detail']['placements'].get(k)
            bx = xi.read(xa, s['size'])
            e = dict(section=k, size=s['size'], x86_address=xa, x86_strings=[x.decode('latin1') for x in bx.split(b'\0') if x])
            if sa is None:
                hits = []
                i = si.d.find(bx[:16])
                while i >= 0:
                    hits.append(i)
                    i = si.d.find(bx[:16], i + 1)
                e['slice'] = 'unplaced; first-16-byte search hits (file offsets): %s' % hits
                if len(hits) == 1:
                    tail = si.d[hits[0]:hits[0] + s['size']]
                    e['slice_search_strings'] = [x.decode('latin1') for x in tail.split(b'\0') if x]
            else:
                bs = si.read(sa, s['size'])
                if bs is None:      # the 183.34 section ends earlier: read to its end
                    sec = [q for q in si.o['sections'] if q['addr'] <= sa < q['addr'] + q['size']][0]
                    bs = si.read(sa, sec['addr'] + sec['size'] - sa)
                    e['slice_range_leaves_section'] = '%s,%s' % (sec['segname'], sec['sectname'])
                e.update(slice_address=sa, slice_bytes_read=len(bs), equal=bx == bs,
                         slice_strings=[x.decode('latin1') for x in bs.split(b'\0') if x])
            rec['sections'].append(e)
        res.append(rec)
    return res


def rows_from_m0():
    m = json.load(open(M0))
    sx = {(r['object'], r['source']): r for r in m['selftest']['objects']}
    rows = []
    for r in m['slice']['objects']:
        if r['object'] in CODE + DATA:
            x = sx[(r['object'], r['source'])]
            assert sha(r['obj']) == r['obj_sha256'] == x['obj_sha256']
            assert sha(x['detail']) == x['detail_sha256'] and sha(r['detail']) == r['detail_sha256']
            assert x['verdict'] in ('OBJECT_MATCH', 'NOT_MATCH')
            rows.append(dict(object=r['object'], obj=r['obj'], obj_sha256=r['obj_sha256'],
                             x86_detail=json.load(open(x['detail'])), slice_detail=json.load(open(r['detail'])),
                             slice_text=r['text_address'], slice_text_placement=r['text_placement']))
    assert sorted(r['object'] for r in rows) == sorted(CODE + DATA)
    return rows


def kinds(res):
    c = {}
    for rec in res:
        for e in rec['functions']:
            c[e['kind']] = c.get(e['kind'], 0) + 1
    return c


def main():
    global WORK
    mode, out, d = sys.argv[1:4]
    os.makedirs(d, exist_ok=True)
    WORK = d
    assert sha(X86) == X86_SHA and sha(OLD) == OLD_SHA
    rows = rows_from_m0()
    xi = Img(X86)
    if mode == 'run':
        si = Img(OLD)
        res = analyse(xi, si, rows, d)
        dat = analyse_data(xi, si, rows)
        os.remove(os.path.join(d, 'dis.bin'))
        R = dict(plan=410, tool='10_tools/reconstruction/m1_version_diff.py', inputs={X86: X86_SHA, OLD: OLD_SHA, M0: sha(M0)},
                 function_kinds=kinds(res), objects=res, data_objects=dat)
    else:
        # 1. x86 against itself (183.34 placements replaced by the x86 ones): every function "same"
        for r in rows:
            r['slice_text'] = r['x86_detail']['placements'].get(TEXT)
            r['slice_detail'] = r['x86_detail']
        same = analyse(xi, xi, rows, None)
        k1 = kinds(same)
        assert set(k1) == {'same'}, k1
        rows = rows_from_m0()
        si = Img(OLD)
        base = analyse(xi, si, rows, None)
        # pick an address_only-or-same external function with an external relocation field
        pick = None
        for rec in base:
            for e in rec['functions']:
                if pick is None and e['entry'] == 'ext' and e['kind'] in ('same', 'address_only') and e['relocation_fields']:
                    pick = (rec['object'], e)
        obj, e = pick
        fn = [f for f in obj_functions([r for r in rows if r['object'] == obj][0]['obj'])[3]
              if f['start'] == e['object_range'][0]][0]
        mask = set()
        for f in fn['fields']:
            mask.update(range(f['off'], f['off'] + f['w']))
        nonfield = [k for k in range(fn['start'], fn['end']) if k not in mask][0] - fn['start']
        ext = [f for f in fn['fields'] if f['name']][0]
        tests = {}

        def mutated(tag, patch):
            b = bytearray(si.d)
            patch(b)
            p = os.path.join(d, 'mut-%s' % tag)
            open(p, 'wb').write(bytes(b))
            mi = Img(p)
            got = analyse(xi, mi, rows_from_m0(), None)
            g = [x for rec in got if rec['object'] == obj for x in rec['functions']
                 if x['object_range'] == e['object_range']][0]
            os.remove(p)
            return g['kind']

        off = lambda a: si.text['offset'] + a - si.text['addr']
        tests['opcode_byte'] = mutated('op', lambda b: b.__setitem__(off(e['slice_address'] + nonfield),
                                                                        b[off(e['slice_address'] + nonfield)] ^ 0xff))
        fo = off(e['slice_address'] + ext['off'] - fn['start'])
        tests['extern_field'] = mutated('fld', lambda b: b.__setitem__(fo, (b[fo] + 1) & 0xff))
        nm = e['names'][0].encode()
        so = si.d.rindex(b'\0' + nm + b'\0') + 1   # its string-table entry (the table is at the file end)
        tests['name_removed'] = mutated('nm', lambda b: b.__setitem__(so + 1, ord('Q')))
        ok = (tests['opcode_byte'] == 'content' and tests['extern_field'] == 'unresolved_address'
              and tests['name_removed'] == 'symbol_absent')
        R = dict(plan=410, mode='selftest', x86_vs_x86=k1, picked=[obj, e['names'], e['kind']], mutations=tests, ok=ok)
        assert ok, R
    open(out, 'w').write(json.dumps(R, indent=1) + '\n')
    print(json.dumps({k: v for k, v in R.items() if k not in ('objects', 'data_objects')}, indent=1))


if __name__ == '__main__':
    main()
