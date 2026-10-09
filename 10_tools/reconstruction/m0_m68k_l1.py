#!/usr/bin/env python3
"""m0_m68k_l1.py -- plan 413 (M0-2): does cc-744.13 -arch m68k reproduce the code of the
1997 original m68k kernel?  07 sources rebuilt for m68k are compared (L1) with
03_original/m68k/binaries/mach_kernel.

  python3 10_tools/reconstruction/m0_m68k_l1.py stage
  python3 10_tools/reconstruction/m0_m68k_l1.py select TARGETS.json PP.cmd
  python3 10_tools/reconstruction/m0_m68k_l1.py cccmd TARGETS.json PPCHECK.json CC.cmd
  python3 10_tools/reconstruction/m0_m68k_l1.py ppcheck RUN_ID TARGETS.json PPCHECK.json
  python3 10_tools/reconstruction/m0_m68k_l1.py compare RUN1 RUN2 TARGETS.json PPCHECK.json WORKDIR REPORT.json

stage    copy 08_build/runs/tools/s6l4-g1a-stage (manifest-checked) to
         08_build/runs/tools/m0p413-stage and add the OPENSTEP SDK m68k headers fetched to
         08_build/artifacts/m0p413/sdk-m68k (hash-checked against the real machine's
         krsha256 list) next to their i386 counterparts.  No existing file is replaced.
select   objects of the plan 409 record that are grade A, not ObjC, OBJECT_MATCH in both the
         x86 self-test and the i386 mk-183.34 slice, whose external __TEXT,__text symbols
         all exist in the m68k original, built from a .c outside an i386 directory, and
         whose every i386 header (s6l4-g1a -M list) is an SDK copy with an SDK m68k
         counterpart.  Writes the funnel, the targets and a preprocessing command file
         (-E for i386 and m68k; the s6l4-g1a compile line with only -arch/-c/-o changed).
cccmd    m68k compile command file for the targets that preprocessed in the pp run.
ppcheck  every line of both .i files gets its source file from the line markers; the
         difference (markers and blank lines ignored) is "arch_only" when every differing
         line comes from an i386/ or m68k/ directory, "expansion" when the shared text
         differs but the .c itself only through one-for-one replaced lines (header macros),
         "source_structural" when .c lines appear or disappear (conditional text).  The .c
         is also searched for architecture names.
compare  both runs must give the same .o bytes; each object goes through l1_compare.py
         --place-from-image against the m68k original.  Counts cover __TEXT,__text.
         Compiler messages are compared with the s6l4-g1a i386 compile of the object.
         Diagnostics (not verdicts): relocation classes, DIFF split by cause, and for
         every external function a byte comparison at its image address with relocation
         fields masked (also where l1_compare could not place the section).
Read-only apart from the files named above.
"""
import sys, os, re, json, csv, shutil, hashlib, difflib, subprocess, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import l1_compare

REC = '09_validation/reconstruction/m0-i386-18334-l1-20261009.json'
BASE_STAGE = '08_build/runs/tools/s6l4-g1a-stage'
BASE_RUN = '08_build/runs/s6l4-g1a'
STAGE = '08_build/runs/tools/m0p413-stage'
SDK = '08_build/artifacts/m0p413/sdk-m68k'
SDK_SHA = '08_build/artifacts/m0p413/sdk-m68k.target-sha.txt'
SDK_ROOT = '/NextDeveloper/Headers/'
SDK_MAP = {'architecture': 'components/architecture', 'ansi': 'nextdev/ansi', 'bsd': 'src/bsd',
           'bsd/rpc': 'src/bsd/rpc', 'kernserv': 'src/kernserv', 'mach': 'src/mach'}
IMG = '03_original/m68k/binaries/mach_kernel'
IMG_SHA = 'dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75'
SYMS = '03_original/m68k/inventory/symbols.tsv'
TEXT = '__TEXT,__text'
MARK = re.compile(r'^# (\d+) "([^"]*)"')
ARCH_WORD = re.compile(r'i386|m68k|mc68000|__BIG_ENDIAN__|__LITTLE_ENDIAN__|BYTE_ORDER|sparc|hppa|\bppc\b|__ppc__'
                       r'|__ARCHITECTURE__|__TARGET_ARCHITECTURE__')


def sha(p):
    h = hashlib.sha256()
    with open(p, 'rb') as f:
        for c in iter(lambda: f.read(1 << 20), b''):
            h.update(c)
    return h.hexdigest()


def base_manifest():
    m = json.load(open(BASE_STAGE + '.manifest.json'))
    for e in m['files']:
        assert sha(os.path.join(BASE_STAGE, e[0])) == e[2], e[0]
    return m


def sdk_files():
    out = []
    for l in open(SDK_SHA):
        h, sz, p = l.split()
        assert p.startswith(SDK_ROOT)
        rel = p[len(SDK_ROOT):]
        loc = os.path.join(SDK, rel)
        assert sha(loc) == h and os.path.getsize(loc) == int(sz), loc
        area, arch, name = rel.rsplit('/', 2)
        assert arch == 'm68k' and area in SDK_MAP, rel
        out.append((rel, h, os.path.join(SDK_MAP[area], 'm68k', name)))
    n = sum(len(f) for _, _, f in os.walk(SDK))
    assert n == len(out), (n, len(out))
    return out


def cmd_stage():
    m = base_manifest()
    assert not os.path.exists(STAGE), STAGE
    files = sdk_files()
    shutil.copytree(BASE_STAGE, STAGE, symlinks=True)
    added, kept = [], []
    for rel, h, dst in files:
        assert os.path.isdir(os.path.join(STAGE, os.path.dirname(dst).rsplit('/', 1)[0], 'i386')), dst
        p = os.path.join(STAGE, dst)
        if os.path.exists(p):
            assert sha(p) == h, 'different file already at ' + dst
            kept.append([dst, SDK_ROOT + rel, h])
            continue
        os.makedirs(os.path.dirname(p), exist_ok=True)
        shutil.copyfile(os.path.join(SDK, rel), p)
        assert sha(p) == h
        added.append([dst, SDK_ROOT + rel, h])
    man = dict(plan=413, base=BASE_STAGE, base_manifest_sha256=sha(BASE_STAGE + '.manifest.json'),
               sdk_list=SDK_SHA, sdk_list_sha256=sha(SDK_SHA), added=added, already_present=kept,
               files=[e[:3] for e in m['files']] + [[a, 'real machine ' + s, h] for a, s, h in added])
    on_disk = sorted(os.path.relpath(os.path.join(r, f), STAGE) for r, _, fs in os.walk(STAGE) for f in fs)
    assert on_disk == sorted(e[0] for e in man['files']), 'stage content differs from manifest'
    json.dump(man, open(STAGE + '.manifest.json', 'w'), indent=1)
    print('stage', STAGE, 'files', len(man['files']), 'added', len(added), 'already present', len(kept))


def run_lines():
    return [l.split() for l in open(os.path.join(BASE_RUN, 'run.cmd')).read().splitlines() if l.startswith('RUN ')]


def cmd_select(out_json, pp_cmd):
    rec = json.load(open(REC))
    slice_objs = rec['slice']['objects']
    self_v = {o['object']: o['verdict'] for o in rec['selftest']['objects']}
    m68 = {}
    for r in csv.DictReader(open(SYMS), delimiter='\t'):
        if r['defined_external'] == '1':
            m68[r['name']] = r
    bman = {e[0]: e for e in base_manifest()['files']}
    sman = json.load(open(STAGE + '.manifest.json'))
    sdk_added = {e[0] for e in sman['added']} | {e[0] for e in sman['already_present']}
    runs = run_lines()
    by_out, by_mdep = {}, {}
    for i, w in enumerate(runs):
        o = w[w.index('-o') + 1] if '-o' in w else None
        if '-M' in w:
            by_mdep.setdefault(w[-1], []).append(i)
        elif o:
            by_out[os.path.basename(o)] = i
    funnel = collections.OrderedDict()
    funnel['plan409_objects'] = len(slice_objs)
    targets, excluded = [], []
    step = collections.Counter()
    for o in slice_objs:
        def drop(why):
            excluded.append(dict(object=o['object'], why=why))
            step[why.split(':')[0]] += 1
        if not (o['grade'] == 'A' and not o['objc'] and o['verdict'] == 'OBJECT_MATCH'
                and self_v.get(o['object']) == 'OBJECT_MATCH'):
            drop('not A/non-ObjC/OBJECT_MATCH in both')
            continue
        assert sha(o['obj']) == o['obj_sha256'], o['object']
        ob = macho_obj.parse(open(o['obj'], 'rb').read())
        tidx = [s['index'] for s in ob['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')]
        ext = [y['name'] for y in ob['symbols'] if y['kind'] == 'SECT' and not y['stab'] and y.get('ext')
               and y['sect'] in tidx]
        if not ext:
            drop('no external __text symbol')
            continue
        miss = [n for n in ext if n not in m68]
        if miss:
            drop('external __text symbol not in m68k original: ' + ','.join(miss[:3]))
            continue
        base = os.path.basename(o['obj'])
        line = runs[by_out[base]]
        src = line[-3] if line[-2] == '-o' else None
        assert src and line[line.index('-c') + 1] == src, base
        if not src.endswith('.c'):
            drop('not a .c source')
            continue
        if '/i386/' in src:
            drop('source in an i386 directory')
            continue
        mi = by_mdep[src]
        assert len(mi) == 1, src
        txt = open(os.path.join(BASE_RUN, 'out', '_log', '%02d.out' % mi[0])).read().replace('\\\n', ' ')
        tgt, deps = txt.split(':', 1)
        assert tgt.strip() == os.path.basename(src)[:-2] + '.o', (tgt, src)
        deps = deps.split()
        assert deps[0] == src
        bad = []
        for d in deps:
            if '/i386/' not in d:
                continue
            rel = d[len('src/'):]
            note = bman[rel][3] if len(bman[rel]) > 3 else ''
            if 'real machine /NextDeveloper/Headers/' not in note:
                bad.append('not an SDK copy ' + rel)
            elif rel.replace('/i386/', '/m68k/') not in sdk_added:
                bad.append('no SDK m68k counterpart ' + rel)
        if bad:
            drop('i386 header: ' + bad[0])
            continue
        targets.append(dict(object=o['object'], source=o['source'], obj_i386=o['obj'],
                            obj_i386_sha256=o['obj_sha256'], base=base[:-2], src=src, line=line,
                            ext_text_symbols=ext, deps=deps,
                            text_size=sum(s['size'] for s in ob['sections'] if s['index'] in tidx)))
    funnel['excluded'] = dict(step)
    funnel['targets'] = len(targets)
    funnel['target_text_bytes'] = sum(t['text_size'] for t in targets)
    L = ['# m0p413-pp: plan 413 (M0-2) preprocessing of %d objects for i386 and m68k (m0_m68k_l1.py select)' % len(targets)]
    E = []
    for t in targets:
        for arch in ('i386', 'm68k'):
            w = list(t['line'])
            assert w[:4] == ['RUN', '/bin/cc', '-arch', 'i386'] and w.count('-c') == 1
            w[3] = arch
            w[w.index('-c')] = '-E'
            w[-1] = 'stage/%s.%s.i' % (t['base'], arch)
            L.append(' '.join(w))
            E.append('EXPECT %s.%s.i' % (t['base'], arch))
    open(pp_cmd, 'w').write('\n'.join(L + E) + '\n')
    json.dump(dict(plan=413, record=REC, record_sha256=sha(REC), stage_manifest_sha256=sha(STAGE + '.manifest.json'),
                   base_run_cmd_sha256=sha(os.path.join(BASE_RUN, 'run.cmd')), funnel=funnel,
                   excluded=excluded, targets=targets), open(out_json, 'w'), indent=1)
    print(json.dumps(funnel))


def cmd_cccmd(tj, pj, cc_cmd):
    T = json.load(open(tj))['targets']
    P = {r['object']: r for r in json.load(open(pj))['objects']}
    L = ['# m0p413-cc: plan 413 (M0-2) m68k compile (m0_m68k_l1.py cccmd)']
    E = []
    for t in T:
        if t['object'] not in P:
            continue
        w = list(t['line'])
        assert w[:4] == ['RUN', '/bin/cc', '-arch', 'i386']
        w[3] = 'm68k'
        w[-1] = 'stage/%s.o' % t['base']
        L.append(' '.join(w))
        E.append('EXPECT %s.o' % t['base'])
    L[0] += ', %d objects' % len(E)
    open(cc_cmd, 'w').write('\n'.join(L + E) + '\n')
    print('objects', len(E))


def read_i(path):
    """[(source file, text)] for the non-blank, non-marker lines of a .i file."""
    cur, out = None, []
    for l in open(path, errors='replace').read().splitlines():
        m = MARK.match(l)
        if m:
            cur = m.group(2)
            continue
        if l.startswith('#'):
            out.append((cur, l.strip()))   # other directives (#pragma, #ident) kept as text
            continue
        if l.strip():
            out.append((cur, l.strip()))
    return out


def is_arch(f):
    return f is not None and ('/i386/' in f or '/m68k/' in f)


def cmd_ppcheck(rid, tj, pj):
    rdir = os.path.join('08_build/runs', rid)
    T = json.load(open(tj))['targets']
    rows = []
    for t in T:
        a = os.path.join(rdir, 'out', t['base'] + '.i386.i')
        b = os.path.join(rdir, 'out', t['base'] + '.m68k.i')
        A, B = read_i(a), read_i(b)
        sm = difflib.SequenceMatcher(None, [x[1] for x in A], [x[1] for x in B], autojunk=False)
        files, nd, src = collections.Counter(), 0, collections.Counter()
        for op, i1, i2, j1, j2 in sm.get_opcodes():
            if op == 'equal':
                continue
            for f, _ in A[i1:i2] + B[j1:j2]:
                files[f] += 1
                nd += 1
                if f == t['src']:   # one-for-one replaced lines = macro expansion; else conditional text
                    src['replaced' if op == 'replace' and i2 - i1 == j2 - j1 else 'structural'] += 1
        shared = sorted(f for f in files if not is_arch(f))
        words = []
        for n, l in enumerate(open(os.path.join(STAGE, t['src'][len('src/'):]), errors='replace'), 1):
            if ARCH_WORD.search(l):
                words.append('%d: %s' % (n, l.strip()[:120]))
        if not nd:
            k = 'identical'
        elif not shared:
            k = 'arch_only'
        elif src['structural']:
            k = 'source_structural'
        else:
            k = 'expansion'        # shared text differs only through header macros/declarations
        rows.append(dict(object=t['object'], i386=a, i386_sha256=sha(a), m68k=b, m68k_sha256=sha(b),
                         lines=[len(A), len(B)], differing_lines=nd, klass=k,
                         source_lines=dict(src), source_arch_words=words,
                         shared_files=shared, shared_lines=sum(files[f] for f in shared),
                         arch_files=sorted(f for f in files if is_arch(f))))
    S = dict(collections.Counter(r['klass'] for r in rows))
    json.dump(dict(plan=413, run=rid, summary=S, objects=rows), open(pj, 'w'), indent=1)
    print(S)
    for r in rows:
        if r['klass'] == 'source_structural' or r['source_arch_words']:
            print(r['object'], r['klass'], r['source_lines'], r['source_arch_words'][:3])


def reloc_fields(obj, s):
    """byte offsets inside section s covered by relocation fields, and the class census."""
    covered, census = set(), collections.Counter()
    for r in s['relocs']:
        w = 1 << r['length']
        covered.update(range(r['address'], r['address'] + w))
        typ = r['type']
        census['%s w%d %s type%d' % ('scattered' if r['scattered'] else ('extern' if r['extern'] else 'local'),
                                     w, 'pc' if r['pcrel'] else 'abs', typ)] += 1
    return covered, census


def cmd_compare(r1, r2, tj, pj, workdir, report):
    assert sha(IMG) == IMG_SHA
    img = l1_compare.Image(IMG)
    T = json.load(open(tj))['targets']
    P = {r['object']: r for r in json.load(open(pj))['objects']}
    T = [t for t in T if t['object'] in P]
    os.makedirs(workdir, exist_ok=True)
    # image external symbols of __text, for extents to the next external symbol
    isecs = img.o['sections']
    itext = [s for s in isecs if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
    starts = sorted({y['value'] for y in img.o['symbols'] if y['kind'] == 'SECT' and not y['stab']
                     and y['sect'] == itext['index']})
    tend = itext['addr'] + itext['size']

    def iextent(a):
        i = starts.index(a)
        return (starts[i + 1] if i + 1 < len(starts) else tend) - a

    # compiler diagnostics of each m68k compile against the s6l4-g1a i386 compile of the same
    # object (file:line prefixes dropped, lines compared as a sorted list)
    ccruns = [l.split() for l in open(os.path.join('08_build/runs', r1, 'run.cmd')).read().splitlines()
              if l.startswith('RUN ')]
    cc_idx = {os.path.basename(w[-1]): i for i, w in enumerate(ccruns)}
    base_idx = {os.path.basename(w[-1]): i for i, w in enumerate(run_lines()) if '-c' in w}

    def diag_lines(path):
        return sorted(re.sub(r'^\S+?:\d+: ', '', l) for l in open(path).read().splitlines())

    rows = []
    for t in T:
        p1 = os.path.join('08_build/runs', r1, 'out', t['base'] + '.o')
        e_m = os.path.join('08_build/runs', r1, 'out', '_log', '%02d.err' % cc_idx[t['base'] + '.o'])
        e_i = os.path.join(BASE_RUN, 'out', '_log', '%02d.err' % base_idx[t['base'] + '.o'])
        diag_same = diag_lines(e_m) == diag_lines(e_i)
        p2 = os.path.join('08_build/runs', r2, 'out', t['base'] + '.o')
        h1, h2 = sha(p1), sha(p2)
        out = os.path.join(workdir, 'l1-%s.json' % t['object'])
        cmd = [sys.executable, '10_tools/reconstruction/l1_compare.py', '--image', IMG, '--obj', p1,
               '--place-from-image', '--out', out]
        p = subprocess.run(cmd, capture_output=True, text=True)
        assert p.returncode == 0 and os.path.exists(out), (t['object'], p.stderr[-800:])
        d = json.load(open(out))
        assert d['inputs'][p1] == h1
        ob = open(p1, 'rb').read()
        obj = macho_obj.parse(ob)
        ts = [s for s in obj['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')][0]
        covered, census = reloc_fields(obj, ts)
        narrow = sorted(r['address'] for r in ts['relocs'] if (1 << r['length']) != 4 or r['type'] != 0)
        funcs = []
        for fn in d['functions']:
            if fn['section'] != TEXT:
                continue
            lo, hi = fn['object_range']
            cause = []
            if fn['verdict'] == 'DIFF':
                if fn['byte_differences']:
                    cause.append('code bytes')
                if fn['refs_differ']:
                    cause.append('relocation value')
                if 'fail' in fn['data_sections'].values():
                    cause.append('referenced data section failed')
            funcs.append(dict(names=fn['names'], size=hi - lo, verdict=fn['verdict'], diff_cause=cause,
                              narrow_or_nonvanilla=[a for a in narrow if lo <= a < hi]))
        # diagnostic: every external function at its own image address, relocation fields masked
        syms = sorted((y['value'] - ts['addr'], y['name']) for y in obj['symbols']
                      if y['kind'] == 'SECT' and not y['stab'] and y['sect'] == ts['index'])
        diag = []
        for i, (off, name) in enumerate(syms):
            if name not in t['ext_text_symbols']:
                continue
            nxt = next((o2 for o2, _ in syms[i + 1:] if o2 > off), ts['size'])
            ia = img.symbol(name)
            got = img.read(ia, nxt - off) if ia is not None else None
            if got is None:
                diag.append(dict(name=name, image=None))
                continue
            mine = ob[ts['offset'] + off:ts['offset'] + nxt]
            first = next((k for k in range(nxt - off) if (off + k) not in covered and mine[k] != got[k]), None)
            diag.append(dict(name=name, image_address=ia, object_size=nxt - off, image_extent=iextent(ia),
                             masked_equal=first is None, first_diff=first))
        sec = d['sections'].get(TEXT)
        rows.append(dict(object=t['object'], source=t['source'], pp=P[t['object']]['klass'],
                         obj=p1, obj_sha256=h1, run2_same=(h1 == h2),
                         diagnostics_lines=len(diag_lines(e_m)), diagnostics_same_as_i386=diag_same,
                         verdict=d['object_verdict'], reasons=d['object_reasons'],
                         text_size=ts['size'], text_address=d['placements'].get(TEXT),
                         text_placement=sec['placement'] if sec else None,
                         reloc_census=dict(census), functions=funcs, masked=diag,
                         detail=out, detail_sha256=sha(out)))
    # aggregation (python)
    S = collections.OrderedDict()
    S['objects'] = len(rows)
    S['deterministic'] = sum(r['run2_same'] for r in rows)
    S['diagnostics_same_as_i386'] = sum(r['diagnostics_same_as_i386'] for r in rows)
    S['objects_with_diagnostics'] = sum(1 for r in rows if r['diagnostics_lines'])
    S['pp'] = dict(collections.Counter(r['pp'] for r in rows))
    S['verdict'] = dict(collections.Counter(r['verdict'] for r in rows))
    S['verdict_by_pp'] = {k: dict(collections.Counter(r['verdict'] for r in rows if r['pp'] == k))
                          for k in sorted({r['pp'] for r in rows})}
    S['text_bytes'] = sum(r['text_size'] for r in rows)
    S['text_placed_objects'] = sum(r['text_address'] is not None for r in rows)
    S['text_bytes_unplaced'] = sum(r['text_size'] for r in rows if r['text_address'] is None)
    fc, fb, dc = collections.Counter(), collections.Counter(), collections.Counter()
    for r in rows:
        for f in r['functions']:
            fc[f['verdict']] += 1
            fb[f['verdict']] += f['size']
            for c in f['diff_cause']:
                dc[c] += 1
    S['functions'] = dict(fc)
    S['function_bytes'] = dict(fb)
    S['function_bytes_pct_of_text'] = {k: round(100.0 * v / S['text_bytes'], 2) for k, v in fb.items()}
    S['diff_causes'] = dict(dc)
    S['match_with_narrow_or_nonvanilla'] = sum(1 for r in rows for f in r['functions']
                                               if f['verdict'].startswith('MATCH') and f['narrow_or_nonvanilla'])
    md = [m for r in rows for m in r['masked']]
    S['masked_external_functions'] = len(md)
    S['masked_equal'] = sum(1 for m in md if m.get('masked_equal'))
    S['masked_equal_same_extent'] = sum(1 for m in md if m.get('masked_equal') and m['object_size'] == m['image_extent'])
    S['masked_not_in_image'] = sum(1 for m in md if m.get('image') is None and 'image_address' not in m)
    cen = collections.Counter()
    for r in rows:
        cen.update(r['reloc_census'])
    S['reloc_census_text'] = dict(cen)
    json.dump(dict(plan=413, tool='10_tools/reconstruction/m0_m68k_l1.py', tool_sha256=sha(os.path.abspath(__file__)),
                   l1_compare_sha256=sha('10_tools/reconstruction/l1_compare.py'),
                   macho_obj_sha256=sha('10_tools/reconstruction/macho_obj.py'),
                   image=dict(path=IMG, sha256=sha(IMG)), runs=[r1, r2],
                   targets=tj, targets_sha256=sha(tj), ppcheck=pj, ppcheck_sha256=sha(pj),
                   summary=S, objects=rows), open(report, 'w'), indent=1)
    print(json.dumps(S, indent=1))


def main():
    a = sys.argv[1:]
    if a[:1] == ['stage'] and len(a) == 1:
        cmd_stage()
    elif a[:1] == ['select'] and len(a) == 3:
        cmd_select(a[1], a[2])
    elif a[:1] == ['cccmd'] and len(a) == 4:
        cmd_cccmd(a[1], a[2], a[3])
    elif a[:1] == ['ppcheck'] and len(a) == 4:
        cmd_ppcheck(a[1], a[2], a[3])
    elif a[:1] == ['compare'] and len(a) == 7:
        cmd_compare(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
