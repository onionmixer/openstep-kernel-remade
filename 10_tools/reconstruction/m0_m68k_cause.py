#!/usr/bin/env python3
"""m0_m68k_cause.py -- plan 414: split the causes of the m68k differences left by plan 413
(cc-744.13 -arch m68k objects of 07 sources against the 1997 m68k original).

  python3 10_tools/reconstruction/m0_m68k_cause.py gridcmd GRID.cmd
  python3 10_tools/reconstruction/m0_m68k_cause.py grid RUN_ID WORKDIR GRID.json
  python3 10_tools/reconstruction/m0_m68k_cause.py hdr HDR.json
  python3 10_tools/reconstruction/m0_m68k_cause.py otoolsh RUN_ID VARIANT OTOOL_DIR OTOOL.sh
  python3 10_tools/reconstruction/m0_m68k_cause.py classify RUN_ID VARIANT OTOOL_DIR GRID.json HDR.json CLASS.json

gridcmd   the plan 413 m68k compile lines (08_build/artifacts/m0p413/cc.cmd) with the three words
          "-g -O3 -fno-omit-frame-pointer" replaced by each flag variant V0..V9.
grid      every variant object through l1_compare.py --place-from-image and the external-span
          comparison (relocation fields masked); V0 must reproduce the plan 413 objects.
          Two sets per variant: strict L1 function MATCH, and external spans equal with
          masked relocation fields AND equal span length.
hdr       the plan 413 preprocessing output (m0p413-pp1): for every (file, source line) outside
          the architecture directories, lines present for one architecture only (conditional
          structure) and lines present for both with different text (expansion).
otoolsh   shell script for the real machine: otool -tv of the variant objects and of the original.
classify  every external span still different under VARIANT: instructions normalised (absolute
          operands -> symbol+offset from relocation entries / the original's symbol table, branch
          targets inside the span -> span offsets) and classified D/R/O/X (plan 414.1).
Read-only apart from the files named above.
"""
import sys, os, re, json, csv, hashlib, difflib, subprocess, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import l1_compare
import m0_m68k_l1 as P413

A413 = '08_build/artifacts/m0p413'
CC413 = A413 + '/cc.cmd'
TARGETS = A413 + '/targets.json'
PP_RUN = '08_build/runs/m0p413-pp1'
CC_RUN = '08_build/runs/m0p413-cc1'
REC409 = '09_validation/reconstruction/m0-i386-18334-l1-20261009.json'
BASE_FLAGS = '-g -O3 -fno-omit-frame-pointer'
VARIANTS = collections.OrderedDict([
    ('V0', '-g -O3 -fno-omit-frame-pointer'), ('V1', '-g -O2'), ('V2', '-g -O2 -fno-omit-frame-pointer'),
    ('V3', '-g -O3'), ('V4', '-g -O'), ('V5', '-O3'), ('V6', '-O2'),
    ('V7', '-g -O3 -fno-omit-frame-pointer -fno-builtin'),
    ('V8', '-O3 -fno-omit-frame-pointer'), ('V9', '-O2 -fno-omit-frame-pointer'),
    ('V10', '-g -O2'), ('V11', '-g -O3 -fno-omit-frame-pointer')])      # plan 414.2
DROP = {'V10': ['-fwritable-strings'], 'V11': ['-fwritable-strings']}   # words removed from the line
GRID_RUNS = {'m0p414-fg1': ['V%d' % i for i in range(10)], 'm0p414-fg2': ['V10', 'V11']}
TEXT = '__TEXT,__text'
sha = P413.sha


def cc_lines():
    return [l for l in open(CC413).read().splitlines() if l.startswith('RUN ')]


def base_of(line):
    o = line.split()[-1]
    assert o.startswith('stage/') and o.endswith('.o'), o
    return o[len('stage/'):-2]


def cmd_gridcmd(out, names=None):
    L, E = [], []
    lines = cc_lines()
    V = collections.OrderedDict((v, f) for v, f in VARIANTS.items() if names is None or v in names)
    for v, fl in V.items():
        for l in lines:
            t = ' %s ' % BASE_FLAGS
            assert l.count(t) == 1, l
            b = base_of(l)
            n = l.replace(t, ' %s ' % fl)
            n = n[:n.rindex(' stage/')] + ' stage/%s__%s.o' % (v, b)
            for w in DROP.get(v, []):
                assert n.split().count(w) == 1, (v, w)
                n = n.replace(' %s ' % w, ' ', 1)
            L.append(n)
            E.append('EXPECT %s__%s.o' % (v, b))
    head = '# m0p414-fg: plan 414 m68k flag grid, %d variants x %d objects (m0_m68k_cause.py gridcmd); ' % (
        len(V), len(lines)) + '; '.join('%s=%s%s' % (v, f, ''.join(' without ' + w for w in DROP.get(v, [])))
                                         for v, f in V.items())
    open(out, 'w').write('\n'.join([head] + L + E) + '\n')
    print('commands', len(L))


# ---------------------------------------------------------------- spans

def ext_spans(obj, ob, ts, ext_names):
    """external symbol -> (start, end) offsets in the object __text: to the next external
    __text symbol (static functions in between stay inside), and whether statics are inside."""
    syms = sorted((y['value'] - ts['addr'], y['name'], bool(y.get('ext'))) for y in obj['symbols']
                  if y['kind'] == 'SECT' and not y['stab'] and y['sect'] == ts['index'])
    ext = [(o, n) for o, n, e in syms if e and n in ext_names]
    out = {}
    for i, (o, n) in enumerate(ext):
        end = ext[i + 1][0] if i + 1 < len(ext) else ts['size']
        statics = [m for o2, m, e in syms if not e and o < o2 < end]
        out[n] = (o, end, statics)
    return out


class Img:
    def __init__(self):
        assert sha(P413.IMG) == P413.IMG_SHA
        self.img = l1_compare.Image(P413.IMG)
        o = self.img.o
        self.text = [s for s in o['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
        self.starts = sorted({y['value'] for y in o['symbols'] if y['kind'] == 'SECT' and not y['stab']
                              and y['sect'] == self.text['index']})
        self.end = self.text['addr'] + self.text['size']
        self.byaddr = sorted((y['value'], y['name']) for y in o['symbols'] if y['kind'] == 'SECT' and not y['stab'])

    def extent(self, a):
        i = self.starts.index(a)
        return (self.starts[i + 1] if i + 1 < len(self.starts) else self.end) - a


def compare_object(img, path, ext_names):
    """strict L1 (l1_compare) and external-span comparison of one object."""
    ob = open(path, 'rb').read()
    obj = macho_obj.parse(ob)
    ts = [s for s in obj['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
    covered, _ = P413.reloc_fields(obj, ts)
    spans = []
    for n, (o, e, statics) in sorted(ext_spans(obj, ob, ts, ext_names).items(), key=lambda kv: kv[1][0]):
        ia = img.img.symbol(n)
        if ia is None:
            spans.append(dict(name=n, image=None))
            continue
        iext = img.extent(ia)
        got = img.img.read(ia, min(e - o, iext))
        mine = ob[ts['offset'] + o:ts['offset'] + e]
        k = len(got)
        first = next((j for j in range(k) if (o + j) not in covered and mine[j] != got[j]), None)
        spans.append(dict(name=n, image_address=ia, object_span=e - o, image_extent=iext, statics=statics,
                          masked_equal_prefix=first is None, first_diff=first,
                          equal=(first is None and e - o == iext)))
    return obj, ts, spans


def run_l1(path, out):
    cmd = [sys.executable, '10_tools/reconstruction/l1_compare.py', '--image', P413.IMG, '--obj', path,
           '--place-from-image', '--out', out]
    p = subprocess.run(cmd, capture_output=True, text=True)
    assert p.returncode == 0 and os.path.exists(out), (path, p.stderr[-800:])
    d = json.load(open(out))
    assert d['inputs'][path] == sha(path)
    return d


def cmd_grid(rids, workdir, outj):
    where = {v: r for r in rids.split(',') for v in GRID_RUNS[r]}
    T = {t['base']: t for t in json.load(open(TARGETS))['targets']}
    bases = [base_of(l) for l in cc_lines()]
    img = Img()
    os.makedirs(workdir, exist_ok=True)
    rows = []
    for v in VARIANTS:
        for b in bases:
            t = T[b]
            p = os.path.join('08_build/runs', where[v], 'out', '%s__%s.o' % (v, b))
            h = sha(p)
            if v == 'V0':
                assert h == sha(os.path.join(CC_RUN, 'out', b + '.o')), 'V0 does not reproduce plan 413: ' + b
            d = run_l1(p, os.path.join(workdir, 'l1-%s-%s.json' % (v, t['object'])))
            _, ts, spans = compare_object(img, p, t['ext_text_symbols'])
            funcs = [dict(names=f['names'], size=f['object_range'][1] - f['object_range'][0], verdict=f['verdict'])
                     for f in d['functions'] if f['section'] == TEXT]
            rows.append(dict(variant=v, object=t['object'], obj=p, obj_sha256=h, verdict=d['object_verdict'],
                             text_size=ts['size'], text_placed=d['placements'].get(TEXT) is not None,
                             functions=funcs, spans=spans))
        print(v, 'done', file=sys.stderr)
    # aggregation (python)
    S = collections.OrderedDict()
    sets = {}
    for v in VARIANTS:
        R = [r for r in rows if r['variant'] == v]
        strict = {(r['object'], f['names'][0]) for r in R for f in r['functions'] if f['verdict'] == 'MATCH'}
        span = {(r['object'], s['name']) for r in R for s in r['spans'] if s.get('equal')}
        sets[v] = (strict, span)
        S[v] = dict(flags=VARIANTS[v], object_match=sum(r['verdict'] == 'OBJECT_MATCH' for r in R),
                    function_match=len(strict),
                    function_match_bytes=sum(f['size'] for r in R for f in r['functions'] if f['verdict'] == 'MATCH'),
                    text_bytes=sum(r['text_size'] for r in R),
                    spans=sum(1 for r in R for s in r['spans'] if 'image_address' in s),
                    span_equal=len(span),
                    distinct_objects_vs_V0=sum(1 for r in R if r['obj_sha256'] != next(
                        x['obj_sha256'] for x in rows if x['variant'] == 'V0' and x['object'] == r['object'])))
    for v in VARIANTS:
        for name, i in (('strict', 0), ('span', 1)):
            for ref in ('V0', 'V1'):
                S[v]['%s_gained_vs_%s' % (name, ref)] = sorted('%s %s' % x for x in sets[v][i] - sets[ref][i])
                S[v]['%s_lost_vs_%s' % (name, ref)] = sorted('%s %s' % x for x in sets[ref][i] - sets[v][i])
    # per span: variants where it is equal
    allspans = sorted({(r['object'], s['name']) for r in rows for s in r['spans'] if 'image_address' in s})
    per = {('%s %s' % k): [v for v in VARIANTS if k in sets[v][1]] for k in allspans}
    S['spans_equal_in_no_variant'] = sum(1 for k in per if not per[k])
    S['spans_equal_in_all_variants'] = sum(1 for k in per if len(per[k]) == len(VARIANTS))
    json.dump(dict(plan=414, tool='10_tools/reconstruction/m0_m68k_cause.py', tool_sha256=sha(os.path.abspath(__file__)),
                   l1_compare_sha256=sha('10_tools/reconstruction/l1_compare.py'), runs=where,
                   variants=VARIANTS, dropped=DROP, image=dict(path=P413.IMG, sha256=P413.IMG_SHA),
                   summary=S, span_variants=per, objects=rows), open(outj, 'w'), indent=1)
    for v in VARIANTS:
        s = S[v]
        print(v, s['flags'].ljust(46), 'OM', s['object_match'], 'MATCH', s['function_match'], s['function_match_bytes'],
              'span_eq', s['span_equal'], '/', s['spans'], '+%d -%d' % (len(s['span_gained_vs_V0']), len(s['span_lost_vs_V0'])),
              'strict +%d -%d' % (len(s['strict_gained_vs_V0']), len(s['strict_lost_vs_V0'])),
              '| vs V1 span +%d -%d strict +%d -%d' % tuple(len(s[k]) for k in (
                  'span_gained_vs_V1', 'span_lost_vs_V1', 'strict_gained_vs_V1', 'strict_lost_vs_V1')))
    print('no variant', S['spans_equal_in_no_variant'], 'all variants', S['spans_equal_in_all_variants'])


# ---------------------------------------------------------------- headers

def lines_by_source(path):
    """(file, source line) -> [text] for non-blank output lines (line markers followed)."""
    out = collections.defaultdict(list)
    cur, ln = None, 0
    for l in open(path, errors='replace').read().splitlines():
        m = re.match(r'^# (\d+) "([^"]*)"', l)
        if m:
            cur, ln = m.group(2), int(m.group(1))
            continue
        if l.strip():
            out[(cur, ln)].append(l.strip())
        ln += 1
    return out


def cmd_hdr(outj):
    T = json.load(open(TARGETS))['targets']
    rows = []
    for t in T:
        a = lines_by_source(os.path.join(PP_RUN, 'out', t['base'] + '.i386.i'))
        b = lines_by_source(os.path.join(PP_RUN, 'out', t['base'] + '.m68k.i'))
        struct, expn = collections.defaultdict(list), collections.Counter()
        for k in sorted(set(a) | set(b), key=lambda k: (k[0] or '', k[1])):
            f = k[0]
            if P413.is_arch(f):
                continue
            if (k in a) != (k in b):
                src = os.path.join(P413.STAGE, f[len('src/'):]) if f and f.startswith('src/') else None
                txt = None
                if src and os.path.exists(src):
                    sl = open(src, errors='replace').read().splitlines()
                    txt = sl[k[1] - 1].strip()[:100] if 0 < k[1] <= len(sl) else None
                struct[f].append(dict(line=k[1], only='i386' if k in a else 'm68k', source_text=txt))
            elif a[k] != b[k]:
                expn[f] += 1
        rows.append(dict(object=t['object'], header_structural=bool(struct), structural=dict(struct),
                         expansion_lines=dict(expn)))
    S = dict(objects=len(rows), header_structural=sum(r['header_structural'] for r in rows),
             structural_files=dict(collections.Counter(f for r in rows for f in r['structural'])))
    json.dump(dict(plan=414, run=PP_RUN, summary=S, objects=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))


# ---------------------------------------------------------------- instruction level

NDRV = '/ndrv/openstep-kernel-remade/'
KRSHA = NDRV + '08_build/runs/tools/target/krsha256-default'
REG = re.compile(r'\b(d[0-7]|a[0-7]|sp|fp|pc|fp[0-7])\b')
NUM = re.compile(r'0x[0-9a-f]+(?::[bwl])?|\b\d+\b')
BR = re.compile(r'^(b(ra|sr|hi|ls|cc|cs|ne|eq|vc|vs|pl|mi|ge|lt|gt|le)|db\w+)$')


def cmd_otoolsh(rid, v, odir, out):
    """the real machine writes otool -tv of the variant objects and of the original into odir."""
    assert os.path.isdir(odir) and not os.listdir(odir), 'make an empty ' + odir + ' on the host first'
    L = ['# plan 414: read-only otool listings (m0_m68k_cause.py otoolsh)', 'O=%s%s' % (NDRV, odir)]
    L.append('/bin/otool -tv %s%s > $O/image.txt 2> $O/image.err' % (NDRV, P413.IMG))
    L.append('%s %s%s > $O/image.sha' % (KRSHA, NDRV, P413.IMG))
    for b in [base_of(l) for l in cc_lines()]:
        p = '08_build/runs/%s/out/%s__%s.o' % (rid, v, b)
        L.append('/bin/otool -tv %s%s > $O/%s.txt 2> $O/%s.err' % (NDRV, p, b, b))
    L.append('echo END > $O/end.txt')
    open(out, 'w').write('\n'.join(L) + '\n')
    print('lines', len(L))


def read_otool(path):
    """[(address, mnemonic, operands)] of the (__TEXT,__text) listing."""
    out = []
    for l in open(path, errors='replace').read().splitlines():
        w = l.split('\t')
        if len(w) >= 2 and re.match(r'^[0-9a-f]{8}$', w[0]):
            out.append((int(w[0], 16), w[1], w[2] if len(w) > 2 else ''))
    return out


class Symbolizer:
    """address -> 'name+off' with the preceding external symbol of the section that holds it;
    an address inside a cstring section -> STR"text" (plan 414.2: literals are compared by content)."""
    def __init__(self, sections, symbols, rd):
        self.secs, self.rd = sections, rd
        self.by = collections.defaultdict(list)
        for y in symbols:
            if y['kind'] == 'SECT' and not y['stab'] and y.get('ext'):
                self.by[y['sect']].append((y['value'], y['name']))
        for k in self.by:
            self.by[k].sort()

    def __call__(self, a):
        for s in self.secs:
            if s['addr'] <= a < s['addr'] + s['size'] or (s['size'] == 0 and a == s['addr']):
                if (s['flags'] & 0xff) == l1_compare.S_CSTRING:
                    b = self.rd(a, s['addr'] + s['size'] - a)
                    return 'STR%r' % b[:b.index(b'\0') if b'\0' in b else len(b)]
                L = [x for x in self.by.get(s['index'], []) if x[0] <= a]
                if L:
                    return '%s+%d' % (L[-1][1], a - L[-1][0])
                return '%s,%s+%d' % (s['segname'], s['sectname'], a - s['addr'])
        return None


def norm_span(ins, lo, hi, symz, rd, relocs=None):
    """normalised instructions of [lo, hi): branch targets (incl. dbcc) inside -> 'L+off', 32-bit
    values that are addresses -> symbol+off.  Object (relocs given): a 32-bit operand is matched to
    the relocation of the instruction whose stored 32-bit field has the same value (plan 414.2);
    an operand without one stays a number.  Jump tables: 'movel aN@(0x0:b,Rm:l:4),aN' + 'jmp aN@'
    with the table address among the 3 previous instructions -> '.long L+off' entries read from the
    bytes (rd(address, n)) while they point into the span.  Returns (instructions, notes)."""
    out, notes = [], []
    seq = [x for x in ins if lo <= x[0] < hi]
    skip_to = None
    for i, (a, mn, op) in enumerate(seq):
        if skip_to is not None:
            if a < skip_to:
                continue
            if a != skip_to:
                notes.append('desync after table at %d' % (skip_to - lo))
            skip_to = None
        nxt = seq[i + 1][0] if i + 1 < len(seq) else hi
        rel = sorted((r for r in (relocs or []) if a <= r['address'] < nxt), key=lambda r: r['address'])
        if BR.match(mn):
            m = re.match(r'^((?:d[0-7],)?)0x([0-9a-f]+):?([bwl]?)$', op)
            if m:
                t = int(m.group(2), 16)
                if rel and rel[0].get('extern'):
                    tgt = 'SYM:%s+0' % rel[0]['symname']
                elif lo <= t < hi:
                    tgt = 'L+%d' % (t - lo)
                else:
                    tgt = 'SYM:%s' % symz(t)
                op = m.group(1) + tgt
            else:
                notes.append('branch operand not parsed at %d' % (a - lo))
            out.append((mn, op))
            continue
        used = set()

        def sub(m):
            tok = m.group(0)
            v = int(tok[2:-2], 16)
            if relocs is not None:
                r = next((x for k, x in enumerate(rel) if k not in used and not x.get('pcrel')
                          and int.from_bytes(rd(x['address'], 4), 'big') == v), None)
                if r is None:
                    return tok                   # object: no relocation for this field -> a number
                used.add(rel.index(r))
                if r.get('extern'):
                    return '@%s+%d' % (r['symname'], v)
            if lo <= v < hi:
                return '@L+%d' % (v - lo)
            s2 = symz(v)
            return ('@' + s2) if s2 else tok
        out.append((mn, re.sub(r'0x[0-9a-f]+:l', sub, op)))
        if relocs is not None and len(used) != len([x for x in rel if not x.get('pcrel')]):
            notes.append('relocation not matched to an operand at %d' % (a - lo))
        jm = re.match(r'^(a[0-7])@$', op) if mn == 'jmp' else None
        if jm:
            reg = jm.group(1)
            prev = seq[max(0, i - 3):i]
            ok = any(m2 == 'movel' and re.match(r'^%s@\(0x0:b,[ad][0-7]:l:4\),%s$' % (reg, reg), o2) for _, m2, o2 in prev)
            ts = None
            for _, _, op2 in reversed(prev):
                for tok in re.findall(r'0x[0-9a-f]+:l', op2):
                    v = int(tok[2:-2], 16)
                    if a < v < hi:
                        ts = v
                if ts:
                    break
            if not ok or ts is None:
                notes.append('jmp %s without a recognised table at %d' % (reg, a - lo))
                continue
            e = ts
            while e + 4 <= hi:
                v = int.from_bytes(rd(e, 4), 'big')
                if not lo <= v < hi:
                    break
                out.append(('.long', 'L+%d' % (v - lo)))
                e += 4
            notes.append('table %d entries at %d' % ((e - ts) // 4, ts - lo))
            skip_to = e
    return out, notes


def obj_read(obj, ob, a, n):
    """n bytes at object address a (the section holding a)."""
    for s in obj['sections']:
        if s['addr'] <= a < s['addr'] + s['size']:
            k = s['offset'] + a - s['addr']
            return ob[k:k + min(n, s['addr'] + s['size'] - a)]
    return b''


SYMTOK = re.compile(r"(?:@|SYM:)(?:STR(?:b'(?:[^'\\]|\\.)*'|b\"(?:[^\"\\]|\\.)*\")|[^\s()]*?\+\d+)|L\+\d+")


def classify(A, B):
    """same / D (only plain displacement-immediate numbers differ; symbolic operands and branch
    targets must be equal) / R (consistent one-to-one register renaming) / O (same multiset, branch
    targets ignored; heuristic) / X."""
    if A == B:
        return 'same'
    if len(A) == len(B) and all(a[0] == b[0] for a, b in zip(A, B)):
        def strip(t):
            sy = SYMTOK.findall(t)
            return NUM.sub('N', SYMTOK.sub('S', t)), sy
        if all(strip(a[1]) == strip(b[1]) for a, b in zip(A, B)):
            return 'D'
        regs, ok = {}, True
        for a, b in zip(A, B):
            ra, rb = REG.findall(a[1]), REG.findall(b[1])
            if REG.sub('R', a[1]) != REG.sub('R', b[1]) or len(ra) != len(rb):
                ok = False
                break
            for x, y in zip(ra, rb):
                if regs.setdefault(x, y) != y:
                    ok = False
            if not ok:
                break
        if ok and len(set(regs.values())) == len(regs):
            return 'R'
    nb = lambda S: collections.Counter((m, SYMTOK.sub(lambda q: 'L' if q.group(0).startswith('L+') else q.group(0), o))
                                       for m, o in S)
    if nb(A) == nb(B):
        return 'O'
    return 'X'


def cmd_classify(rid, v, odir, gridj, hdrj, outj):
    G = json.load(open(gridj))
    H = {r['object']: r for r in json.load(open(hdrj))['objects']}
    T = {t['base']: t for t in json.load(open(TARGETS))['targets']}
    R409 = {o['object']: o for o in json.load(open(REC409))['slice']['objects']}
    img = Img()
    assert open(os.path.join(odir, 'image.sha')).read().split()[0] == P413.IMG_SHA
    assert open(os.path.join(odir, 'end.txt')).read().strip() == 'END'
    iins = read_otool(os.path.join(odir, 'image.txt'))
    isym = Symbolizer(img.img.o['sections'], img.img.o['symbols'], img.img.read)
    rows = []
    for b in [base_of(l) for l in cc_lines()]:
        t = T[b]
        g = [r for r in G['objects'] if r['variant'] == v and r['object'] == t['object']][0]
        p = os.path.join('08_build/runs', rid, 'out', '%s__%s.o' % (v, b))
        assert sha(p) == g['obj_sha256']
        assert os.path.getsize(os.path.join(odir, b + '.err')) == 0
        ob = open(p, 'rb').read()
        obj = macho_obj.parse(ob)
        ts = [s for s in obj['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
        names = {i: y['name'] for i, y in enumerate(obj['symbols'])}
        rel = []
        for r in ts['relocs']:
            r = dict(r)
            if not r['scattered'] and r['extern']:
                r['symname'] = names[r['symbolnum']]
            r['address'] = r['address'] + ts['addr']
            rel.append(r)
        osym = Symbolizer(obj['sections'], obj['symbols'], lambda x, n: obj_read(obj, ob, x, n))
        oins = read_otool(os.path.join(odir, b + '.txt'))
        for s in g['spans']:
            if 'image_address' not in s or s['equal']:
                continue
            span = ext_spans(obj, None, ts, t['ext_text_symbols'])[s['name']]
            A, ta = norm_span(oins, ts['addr'] + span[0], ts['addr'] + span[1], osym,
                              lambda x, n: ob[ts['offset'] + x - ts['addr']:ts['offset'] + x - ts['addr'] + n], rel)
            ia = s['image_address']
            B, tb = norm_span(iins, ia, ia + s['image_extent'], isym, img.img.read)
            k = classify(A, B)
            # size of the edit (diagnostic): instructions outside equal blocks after difflib alignment
            # with branch targets masked
            mk = lambda S: [(m, SYMTOK.sub(lambda q: 'L' if q.group(0).startswith('L+') else q.group(0), o)) for m, o in S]
            sm = difflib.SequenceMatcher(None, mk(A), mk(B), autojunk=False)
            edit = [[op, i2 - i1, j2 - j1] for op, i1, i2, j1, j2 in sm.get_opcodes() if op != 'equal']
            dpairs = []
            if k.startswith('D'):
                for x, y in zip(A, B):
                    if x != y:
                        dpairs.append([x[0], x[1], y[1]])
            rows.append(dict(object=t['object'], name=s['name'], klass=k, notes=[ta, tb],
                             object_span=s['object_span'], image_extent=s['image_extent'], statics=s['statics'],
                             instructions=[len(A), len(B)], d_pairs=dpairs,
                             edit_blocks=len(edit), edit_instructions=[sum(e[1] for e in edit), sum(e[2] for e in edit)],
                             header_structural_files=sorted(H[t['object']]['structural']),
                             i386_1997=R409[t['object']]['verdict']))
    S = dict(variant=v, spans=len(rows), klass=dict(collections.Counter(r['klass'] for r in rows)),
             with_notes=sum(1 for r in rows if r['notes'][0] or r['notes'][1]), with_statics=sum(1 for r in rows if r['statics']))
    json.dump(dict(plan=414, run=rid, variant=v, otool_dir=odir,
                   otool_image_sha256=sha(os.path.join(odir, 'image.txt')),
                   summary=S, spans=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))
    for r in rows:
        print(r['klass'].ljust(9), r['object'][4:].ljust(15), r['name'].ljust(24), r['instructions'],
              'edit', r['edit_blocks'], r['edit_instructions'],
              r['object_span'], r['image_extent'], r['notes'] if (r['notes'][0] or r['notes'][1]) else '', 'S' if r['statics'] else '',
              r['d_pairs'][:3] if r['klass'].startswith('D') else '')


def main():
    a = sys.argv[1:]
    if a[:1] == ['otoolsh'] and len(a) == 5:
        cmd_otoolsh(*a[1:])
        return
    if a[:1] == ['classify'] and len(a) == 7:
        cmd_classify(*a[1:])
        return
    if a[:1] == ['gridcmd'] and len(a) in (2, 3):
        cmd_gridcmd(a[1], a[2].split(',') if len(a) == 3 else None)
    elif a[:1] == ['grid'] and len(a) == 4:
        cmd_grid(*a[1:])
    elif a[:1] == ['hdr'] and len(a) == 2:
        cmd_hdr(a[1])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
