#!/usr/bin/env python3
"""m4_m68k_data.py -- plan 774: acceptance of m68k data-only units (objects whose __data is checked, no __text).

  python3 10_tools/reconstruction/m4_m68k_data.py cmd SPEC OUT.cmd
  python3 10_tools/reconstruction/m4_m68k_data.py check SPEC RUN_ID OUT.json      (RUN_ID collected: reads out/)
  python3 10_tools/reconstruction/m4_m68k_data.py pins SPEC                       (prints the evidence-set hashes for SPEC 'pins')
  python3 10_tools/reconstruction/m4_m68k_data.py coverage SPEC CHECK.json OUT.tsv OUT.json
  python3 10_tools/reconstruction/m4_m68k_data.py selftest SPEC RUN_ID OUT.json [CHECK.json]   (mutation controls: every one must be rejected;
                                                                                  plan 781: CHECK.json, default the plan-777 path pattern)

Why a separate tool: m4_m68k_probe.py / m4_m68k_status.py assume rows with __text bounds (plan 774.2, codex 773.6);
they are left unchanged.  This tool never loosens their assertions.

SPEC (json): {"plan", "base" (stage dir made by stage_m68k.py --plan N stage),
  "units":     [{"name", "rel" (under src/src/), "target" (hex), "size", "kind", "ref", "ref_sha256", "deps_sha256"}],
  "m5_refresh":[{"name", "rel", "ref", "ref_sha256"}],
  "pins":      {"m4_set_sha256", "m5_set_sha256"},          # hashes of the explicit M4 / M5 evidence record lists
  "controls":  {"common_object": {"path", "sha256"}},        # object with a COMMON name that is not in the original
  "m5compare": "<dir>"}                                      # optional (plan 781): the M5 L1 record directory; default M5CMP
cmd      the compile lines (plan 430 option set, asserted equal to the x86 line options for x86-sourced files and to the M5
         majority) and a -M line per unit; per m5_refresh entry the M5 compile line of m5_m68k_srcvar.cc_line.
check    run: statuses are exactly 00..NN and all 0; every .err file (compile and -M) is empty; the run.cmd RUN lines equal the
         lines cmd generates.  Per unit: source in the run == stage manifest source == 07 file (origin under 07_kernel);
         L1 inputs are exactly {object, image} with the pinned image hash; L1 OBJECT_MATCH, no reasons; __DATA,__data size ==
         size, address == target, no byte/ref differences, placement 'given by symbol' (placement-only / literal rejected);
         no other section with content (literal __cstring allowed); the set of defined global symbols equals the set of
         original symbols inside the target range, each at the original address; COMMON and undefined names are all in the
         original (D136); the -M output is 'NAME.o: src/src/REL <headers>' with only src/... tokens, no i386, every header in
         the stage manifest and its content in the run equal to the manifest sha; canon equal to a pinned, different
         reference object (not the checked file, not from the same run directory); unit ranges do not overlap.  m5_refresh entries: OBJECT_MATCH or reasons ==
         [__DATA,__bss: unverified], __data (if any) as above, canon == pinned ref.
coverage re-verifies the check record against the files (object / L1 hashes, L1 inputs), pins the explicit evidence sets (M4:
         status table rows' L1; M5: plan 764 m5compare records) with the SPEC hashes, then computes the __data union.
"""
import sys, os, re, json, glob, hashlib, collections, shutil, tempfile, struct

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import macho_obj as M
import m0_m68k_cause as C
import m0_m68k_l1 as P413
import m3_m68k_diag as D
import m4_m68k_probe as P
import m5_m68k_srcvar as SV

SYMS = '03_original/m68k/inventory/symbols.tsv'
MACHO = '03_original/m68k/inventory/macho.json'
STATUS = '06_reconstruction/m68k-m4-status.tsv'
M5CMP = '08_build/artifacts/m4p764/m5compare'
OPT = ('-arch m68k -static -traditional-cpp -nostdinc -imacros src/generated/meta_features.h -DARCH_PRIVATE -D_KERNEL -DKERNEL '
       '-DKERNEL_PRIVATE -DDRIVER_PRIVATE -DKERNEL_BUILD -DINET -DMACH -DMULTICAST -DPOSIX_KERN -D_POSIX_SOURCE -DNeXT -D_NEXT_SOURCE '
       '-Isrc/generated -Isrc/src -Isrc/src/bsd -Isrc/src/bsd/include -Isrc/src/machdep -Isrc/components -Isrc/components/architecture '
       '-Isrc/components/driverkit-1 -Isrc/nextdev -Isrc/nextdev/bsd -Isrc/nextdev/ansi -g -O2')
DATA = '__DATA,__data'
HDR = re.compile(r'^src/[A-Za-z0-9_./+-]+$')


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def sha_bytes(b):
    return hashlib.sha256(b).hexdigest()


def load(spec):
    s = json.load(open(spec))
    assert set(s) in ({'plan', 'base', 'units', 'm5_refresh', 'pins', 'controls'},
                      {'plan', 'base', 'units', 'm5_refresh', 'pins', 'controls', 'm5compare'}), sorted(s)   # plan 781: optional m5compare
    assert isinstance(s.get('m5compare', M5CMP), str) and os.path.isdir(s.get('m5compare', M5CMP)), 'm5compare directory'
    names = [u['name'] for u in s['units']] + [u['name'] for u in s['m5_refresh']]
    assert len(names) == len(set(names)), 'duplicate unit names'
    for u in s['units']:
        assert set(u) == {'name', 'rel', 'target', 'size', 'kind', 'ref', 'ref_sha256', 'deps_sha256'}, sorted(u)
        assert re.match(r'^[a-z0-9_]+$', u['name']) and u['size'] > 0
    for u in s['m5_refresh']:
        assert set(u) == {'name', 'rel', 'ref', 'ref_sha256'}, sorted(u)
    assert set(s['pins']) == {'m4_set_sha256', 'm5_set_sha256'}
    assert set(s['controls']) == {'common_object'} and set(s['controls']['common_object']) == {'path', 'sha256'}
    return s


def orig_symbols():
    osym = {}
    for l in list(open(SYMS))[1:]:
        c = l.rstrip('\n').split('\t')
        if c[1].startswith('0x'):
            osym.setdefault(c[2], int(c[1], 16))
    return osym


def opts(line):
    return [a for a in line.split() if a.startswith(('-D', '-I'))]


def assert_options(s):
    cnt = collections.Counter(tuple(opts(l)) for l in open('08_build/artifacts/m3p430/cc.cmd') if l.startswith('RUN ') and ' -c ' in l)
    assert cnt.most_common(1)[0][0] == tuple(opts(OPT)) and cnt.most_common(1)[0][1] > sum(cnt.values()) // 2, 'plan 430 majority option set differs'
    for u in s['units']:
        if not u['rel'].startswith('machdep/m68k/'):
            assert opts(' '.join(P.x86_line(u['rel']))) == opts(OPT), ('x86 line options differ', u['rel'])


def expected_lines(s):
    """the RUN lines of the command file, in order, and the EXPECT lines"""
    L, E = [], []
    for u in s['m5_refresh']:
        w = SV.cc_line(dict(rel=u['rel'])).split()
        w[w.index('-o') + 1] = 'stage/Q%dR__%s.o' % (s['plan'], u['name'])
        L.append(' '.join(w))
        E.append('EXPECT Q%dR__%s.o' % (s['plan'], u['name']))
    for u in s['units']:
        L.append('RUN /bin/cc %s -c src/src/%s -o stage/Q%dD__%s.o' % (OPT, u['rel'], s['plan'], u['name']))
        L.append('RUN /bin/cc %s -M src/src/%s' % (OPT, u['rel']))
        E.append('EXPECT Q%dD__%s.o' % (s['plan'], u['name']))
    return L, E


def cmd_cmd(spec, out):
    s = load(spec)
    assert_options(s)
    L, E = expected_lines(s)
    open(out, 'w').write('\n'.join(['# m4p%d: plan %d data units (m4_m68k_data.py cmd)' % (s['plan'], s['plan'])] + L + E) + '\n')
    print('commands', len(L))


def data_sec(d):
    return d['sections'].get(DATA)


# ---------------------------------------------------------------- pure checks (each returns a list of failures)

def check_status(tokens, n):
    """tokens: the raw whitespace-split content of _log/status: exactly '00 0 01 0 ... NN 0' for n commands, nothing else"""
    bad = []
    if len(tokens) != 2 * n:
        bad.append('status has %d tokens, expected %d' % (len(tokens), 2 * n))
    if tokens[0::2] != ['%02d' % i for i in range(n)]:
        bad.append('status keys are not exactly 00..%02d in order' % (n - 1))
    if any(v != '0' for v in tokens[1::2]):
        bad.append('nonzero status')
    return bad


def check_log(names, n):
    """names: file names in the run's _log directory: exactly NN.err and NN.out for every command plus status"""
    want = {'status'} | {'%02d.%s' % (i, e) for i in range(n) for e in ('err', 'out')}
    return [] if set(names) == want and len(names) == len(want) else ['_log files differ: missing %s extra %s' % (sorted(want - set(names))[:3], sorted(set(names) - want)[:3])]


def check_err(text, what):
    return ['%s stderr not empty (%d bytes)' % (what, len(text))] if len(text) else []


def check_cmd(run_lines, expected):
    return [] if list(run_lines) == list(expected) else ['run.cmd RUN lines differ from the generated command lines']


def check_ref(u, obj_path, read_sha):
    bad = []
    if os.path.abspath(u['ref']) == os.path.abspath(obj_path):
        bad.append('reference object is the checked object')
    if os.path.dirname(os.path.abspath(u['ref'])) == os.path.dirname(os.path.abspath(obj_path)):
        bad.append('reference object comes from the same run directory as the checked object')
    if read_sha(u['ref']) != u['ref_sha256']:
        bad.append('reference object hash differs from the pinned hash')
    return bad


def deps_hash(text):
    toks = text.replace('\\\n', ' ').split()
    return sha_bytes('\n'.join([toks[0] if toks else ''] + sorted(toks[1:])).encode())


def check_deps(text, u, stman, read_run_sha):
    """text: -M output; read_run_sha(dep) -> sha256 of the header as staged in the run; u['deps_sha256'] pins the whole list"""
    bad = []
    if deps_hash(text) != u['deps_sha256']:
        bad.append('dependency list differs from the pinned list (a missing or extra header)')
    toks = text.replace('\\\n', ' ').split()
    want = os.path.basename(u['rel'])[:-2] + '.o:'
    if not toks or toks[0] != want:
        bad.append('dependency target token %s != %s' % (toks[:1], want))
    deps = toks[1:]
    if not deps or deps[0] != 'src/src/' + u['rel']:
        bad.append('first dependency is not the unit source')
    for d in deps:
        if not HDR.match(d):
            bad.append('dependency token outside src/: %s' % d)
            continue
        if 'i386' in d:
            bad.append('i386 header %s' % d)
        k = d[len('src/'):]
        if k not in stman:
            bad.append('not in the stage manifest: %s' % d)
        elif read_run_sha(d) != stman[k][1]:
            bad.append('header content differs from the stage manifest: %s' % d)
    return bad


def check_unit(path, l1, u, osym, plan):
    """pure check of one unit object; returns the list of failures (empty = accepted)"""
    bad = []
    o = M.parse(open(path, 'rb').read())
    if l1.get('object_verdict') != 'OBJECT_MATCH' or l1.get('object_reasons') != []:
        bad.append('L1 verdict %s %s' % (l1.get('object_verdict'), l1.get('object_reasons')))
    if l1.get('inputs') != {path: sha(path), P413.IMG: P413.IMG_SHA}:
        bad.append('L1 inputs are not exactly {object, pinned image}')
    s = data_sec(l1)
    tgt = int(u['target'], 16)
    if not s:
        bad.append('no __data section in L1')
    else:
        if s.get('size') != u['size']:
            bad.append('data size %s != %s' % (s.get('size'), u['size']))
        if s.get('address') != tgt:
            bad.append('data address %s != %s' % (s.get('address'), tgt))
        if s.get('byte_differences') != 0 or s.get('refs_differ') != 0 or s.get('refs_unverified') != 0:
            bad.append('differences %s %s %s' % (s.get('byte_differences'), s.get('refs_differ'), s.get('refs_unverified')))
        if s.get('placement') != 'given by symbol':
            bad.append('placement %s' % s.get('placement'))
    for k, v in l1['sections'].items():
        if k == DATA or not v.get('size'):
            continue
        if k == '__TEXT,__cstring' and str(v.get('placement', '')).startswith('literal'):
            continue
        bad.append('unexpected section with content: %s' % k)
    for x in o['sections']:
        if x['size'] and (x['segname'], x['sectname']) not in (('__DATA', '__data'), ('__TEXT', '__cstring')):
            bad.append('object section with content: %s,%s' % (x['segname'], x['sectname']))
    dsec = [x for x in o['sections'] if (x['segname'], x['sectname']) == ('__DATA', '__data')]
    defined = {y['name']: y for y in o['symbols'] if not y['stab'] and y['kind'] == 'SECT' and y['ext']}
    want = {n for n, v in osym.items() if tgt <= v < tgt + u['size']}
    if set(defined) != want:
        bad.append('defined global symbols differ from the original range: missing %s extra %s' % (sorted(want - set(defined))[:4], sorted(set(defined) - want)[:4]))
    if len(dsec) != 1:
        bad.append('object has %d __data sections' % len(dsec))
    elif s and s.get('address') is not None:
        delta = s['address'] - dsec[0]['addr']
        for n, y in defined.items():
            if n in osym and y['value'] + delta != osym[n]:
                bad.append('symbol %s at %#x, original %#x' % (n, y['value'] + delta, osym[n]))
    for y in o['symbols']:
        if y['stab']:
            continue
        if y['kind'] == 'COMMON' and y['name'] not in osym:
            bad.append('COMMON %s not in the original' % y['name'])
        if y['kind'] == 'UNDF' and y['name'] not in osym:
            bad.append('undefined %s not in the original' % y['name'])
    return bad


def check_refresh(l1):
    bad = []
    if not (l1.get('object_verdict') == 'OBJECT_MATCH' or l1.get('object_reasons') == ['__DATA,__bss: unverified']):
        bad.append('L1 %s %s' % (l1.get('object_verdict'), l1.get('object_reasons')))
    sd = data_sec(l1)
    if sd and (sd.get('byte_differences') != 0 or sd.get('refs_differ') != 0 or sd.get('refs_unverified') != 0 or sd.get('size', 0) <= 0):
        bad.append('data differences')
    return bad


# ---------------------------------------------------------------- check

def run_files(rid):
    rdir = os.path.join('08_build/runs', rid)
    assert os.path.isdir(os.path.join(rdir, 'out')) and not os.path.isdir(os.path.join(rdir, 'stage')), 'run %s is not collected' % rid
    return rdir, open(os.path.join(rdir, 'out', '_log', 'status')).read().split()


def cmd_check(spec, rid, outj):
    s = load(spec)
    assert_options(s)
    rdir, status = run_files(rid)
    runs = [l for l in open(os.path.join(rdir, 'run.cmd')).read().splitlines() if l.startswith('RUN ')]
    exp_run, _ = expected_lines(s)
    glob_fail = check_status(status, len(runs)) + check_cmd(runs, exp_run) + check_log(os.listdir(os.path.join(rdir, 'out', '_log')), len(runs))
    man = json.load(open(s['base'] + '.manifest.json'))
    stman = {f[0]: (f[1], f[2]) for f in man['files']}
    osym = orig_symbols()
    om = dict((l.split(' ', 2)[2], l.split(' ', 2)[0]) for l in open(os.path.join(rdir, 'output.manifest')).read().splitlines())
    art = '08_build/artifacts/m4p%d/%s' % (s['plan'], rid)
    os.makedirs(art, exist_ok=True)
    idx = {}
    for i, l in enumerate(runs):
        w = l.split()
        key = w[w.index('-c') + 1] if '-c' in w else w[w.index('-M') + 1]
        idx[(key, '-c' if '-c' in w else '-M')] = i
    for f in glob.glob(os.path.join(rdir, 'out', '_log', '*.err')):
        glob_fail += check_err(open(f, 'rb').read().decode('latin-1'), os.path.basename(f))
    res = []
    for kind, items in (('m5_refresh', s['m5_refresh']), ('unit', s['units'])):
        for u in items:
            pre = 'Q%d%s__%s.o' % (s['plan'], 'R' if kind == 'm5_refresh' else 'D', u['name'])
            p = os.path.join(rdir, 'out', pre)
            r = dict(name=u['name'], kind=kind, rel=u['rel'], object=p, failures=[])
            r['obj_sha256'] = sha(p)
            assert om.get('stage/' + pre) == r['obj_sha256'], ('output manifest', pre)
            src = 'src/src/' + u['rel']
            k = 'src/' + u['rel']
            if k not in stman:
                r['failures'].append('source not in the stage manifest')
            else:
                r['source_origin'] = stman[k][0]
                r['source_sha256'] = stman[k][1]
                if not stman[k][0].startswith('07_kernel/'):
                    r['failures'].append('source origin is not under 07_kernel')
                if sha(os.path.join(rdir, src)) != stman[k][1] or sha(stman[k][0]) != stman[k][1]:
                    r['failures'].append('source sha differs from the stage manifest / 07 file')
            l1 = C.run_l1(p, os.path.join(art, 'l1-%s.json' % u['name']))
            r['l1'] = os.path.join(art, 'l1-%s.json' % u['name'])
            r['l1_sha256'] = sha(r['l1'])
            r['failures'] += check_ref(u, p, sha)
            r['canon_equal_ref'] = D.canon(p) == D.canon(u['ref'])
            if not r['canon_equal_ref']:
                r['failures'].append('canon differs from the reference object')
            if kind == 'unit':
                r['failures'] += check_unit(p, l1, u, osym, s['plan'])
                out = open(os.path.join(rdir, 'out', '_log', '%02d.out' % idx[(src, '-M')]), errors='replace').read()
                r['failures'] += check_deps(out, u, stman, lambda d: sha(os.path.join(rdir, d)))
                r['headers'] = len(out.replace('\\\n', ' ').split()) - 2
                r['target'] = u['target']; r['size'] = u['size']; r['unit_kind'] = u['kind']
            else:
                r['failures'] += check_refresh(l1)
                sd = data_sec(l1)
                r['data'] = [sd['address'], sd['address'] + sd['size']] if sd else None
            r['ok'] = not r['failures']
            res.append(r)
    ranges = sorted((int(u['target'], 16), int(u['target'], 16) + u['size'], u['name']) for u in s['units'])
    overlap = [(a[2], b[2]) for a, b in zip(ranges, ranges[1:]) if b[0] < a[1]]
    rec = dict(plan=s['plan'], tool=os.path.relpath(os.path.abspath(__file__)), tool_sha256=sha(os.path.abspath(__file__)), spec_sha256=sha(spec), run=rid,
               run_cmd_sha256=sha(os.path.join(rdir, 'run.cmd')), base=s['base'], base_manifest_sha256=sha(s['base'] + '.manifest.json'),
               global_failures=glob_fail, overlaps=overlap, results=res,
               ok=(not glob_fail) and (not overlap) and all(r['ok'] for r in res), verified_bytes=sum(r['size'] for r in res if r['kind'] == 'unit' and r['ok']))
    json.dump(rec, open(outj, 'w'), indent=1)
    for r in res:
        print(r['kind'], r['name'], 'OK' if r['ok'] else 'FAIL %s' % r['failures'])
    print('global failures', glob_fail, 'overlaps', overlap, 'ok', rec['ok'], 'verified_bytes', rec['verified_bytes'])
    sys.exit(0 if rec['ok'] else 1)


# ---------------------------------------------------------------- coverage

def data_range(l1):
    s = data_sec(l1)
    if not s:
        return None
    assert s['size'] > 0 and s['byte_differences'] == 0 and s['refs_differ'] == 0 and s['refs_unverified'] == 0, 'data differences'
    return s['address'], s['address'] + s['size']


def check_inputs(l1):
    for p, h in l1['inputs'].items():
        assert os.path.exists(p) and sha(p) == h, ('input hash', p)


def m4_records():
    out = []
    st = [l.rstrip('\n').split('\t') for l in open(STATUS) if not l.startswith('#')]
    h = st[0]
    for r in st[1:]:
        d = dict(zip(h, r)); rec = json.load(open(d['record']))
        c = glob.glob('08_build/artifacts/m4p%d/%s/l1-%s-*.json' % (int(d['plan']), rec['run'], d['name']))
        sel = [(x, json.load(open(x))) for x in sorted(c)]
        sel = [(x, l) for x, l in sel if d['obj_sha256'] in l['inputs'].values()]
        assert sel, ('no L1 for the M4 row', d['name'])
        out.append((d['name'], sel[0][0], sel[0][1]))
    return out


def m5_records(s=None):
    out = []
    d = (s or {}).get('m5compare', M5CMP)   # plan 781: the spec may name the M5 L1 record directory
    for x in sorted(glob.glob(d + '/l1-x86-*.json')):
        out.append((re.match(r'l1-x86-(.+)\.json$', os.path.basename(x)).group(1), x, json.load(open(x))))
    assert len(out) == 205, len(out)
    return out


def set_hash(recs):
    return sha_bytes('\n'.join('%s\t%s\t%s' % (n, x, sha(x)) for n, x, l in sorted(recs)).encode())


def cmd_pins(spec):
    s = load(spec)   # plan 781: read the spec (its m5compare)
    print('m4_set_sha256', set_hash(m4_records()))
    print('m5_set_sha256', set_hash(m5_records(s)))


def verify_check_record(ck, read_sha, spec_sha, tool_sha, s):
    """re-verify a check record against the files and against the spec (every spec item present once, sizes and total equal); returns failures"""
    bad = []
    if not ck.get('ok'):
        bad.append('check record not ok')
    if ck.get('spec_sha256') != spec_sha or ck.get('tool_sha256') != tool_sha:
        bad.append('check record is stale (spec or tool changed)')
    want = {('unit', u['name']): u for u in s['units']}
    want.update({('m5_refresh', u['name']): u for u in s['m5_refresh']})
    got = [(r['kind'], r['name']) for r in ck['results']]
    if sorted(got) != sorted(want) or len(set(got)) != len(got):
        bad.append('check record items differ from the spec: missing %s extra %s' % (sorted(set(want) - set(got))[:3], sorted(set(got) - set(want))[:3]))
    for r in ck['results']:
        u = want.get((r['kind'], r['name']))
        if u and r['kind'] == 'unit' and (r.get('target') != u['target'] or r.get('size') != u['size']):
            bad.append('check record target/size differs from the spec: %s' % r['name'])
    if ck.get('verified_bytes') != sum(u['size'] for u in s['units']):
        bad.append('verified_bytes %s != sum of the spec unit sizes %s' % (ck.get('verified_bytes'), sum(u['size'] for u in s['units'])))
    for r in ck['results']:
        if read_sha(r['object']) != r['obj_sha256']:
            bad.append('object hash changed: %s' % r['name'])
        if read_sha(r['l1']) != r['l1_sha256']:
            bad.append('L1 record hash changed: %s' % r['name'])
    return bad


def cmd_coverage(spec, checkj, out_tsv, out_json):
    s = load(spec)
    ck = json.load(open(checkj))
    vb = verify_check_record(ck, sha, sha(spec), sha(os.path.abspath(__file__)), s)
    assert not vb, vb
    mj = json.load(open(MACHO))
    sec = [x for x in mj['sections'] if x['name'] == '__data'][0]
    A = int(sec['address'], 16); E = A + sec['size']
    rows = []
    refresh = {r['name'] for r in ck['results'] if r['kind'] == 'm5_refresh'}
    m4 = m4_records(); m5 = m5_records(s)
    assert set_hash(m4) == s['pins']['m4_set_sha256'], 'M4 evidence set differs from the SPEC pin'
    assert set_hash(m5) == s['pins']['m5_set_sha256'], 'M5 evidence set differs from the SPEC pin'
    for nm, x, l in m4:
        check_inputs(l)
        rg = data_range(l)
        if rg:
            rows.append(('M4', nm, rg, x, sha(x)))
    for nm, x, l in m5:
        check_inputs(l)
        if nm in refresh:
            continue
        rg = data_range(l)
        if rg:
            rows.append(('M5', nm, rg, x, sha(x)))
    for r in ck['results']:
        l = json.load(open(r['l1']))
        check_inputs(l)
        rg = data_range(l)
        if r['kind'] == 'm5_refresh':
            if rg:
                rows.append(('M5-refresh', r['name'], rg, r['l1'], sha(r['l1'])))
        else:
            assert rg, r['name']
            rows.append(('M4-data', r['name'], rg, r['l1'], sha(r['l1'])))
    for k, nm, rg, x, h_ in rows:
        assert A <= rg[0] < rg[1] <= E, ('range outside __data', nm)
    iv = sorted(rg for k, nm, rg, x, h_ in rows)
    m = []
    for a, b in iv:
        if m and a <= m[-1][1]:
            m[-1][1] = max(m[-1][1], b)
        else:
            m.append([a, b])
    gaps, cur = [], A
    for a, b in m:
        if a > cur:
            gaps.append((cur, a))
        cur = max(cur, b)
    if cur < E:
        gaps.append((cur, E))
    overl = []
    for i, (k1, n1, r1, *_) in enumerate(rows):
        for (k2, n2, r2, *_) in rows[i + 1:]:
            if r1[0] < r2[1] and r2[0] < r1[1]:
                overl.append((n1, n2, min(r1[1], r2[1]) - max(r1[0], r2[0])))
    K = open('03_original/m68k/binaries/mach_kernel', 'rb').read()
    rd = lambda a, n: K[sec['file_offset'] + a - A:sec['file_offset'] + a - A + n]
    osym_addr = set(orig_symbols().values())
    pad_like = [[hex(a), rd(a, 1) == b'\x00' and a not in osym_addr] for a, b in gaps if b - a == 1]
    with open(out_tsv, 'w') as w:
        w.write('# plan 774 (m4_m68k_data.py coverage): verified __DATA,__data ranges; evidence = hash-pinned L1 records (inputs re-hashed); not a source proof\n')
        w.write('start\tend\tbytes\tgroup\tobject\tl1_record\tl1_sha256\n')
        for k, nm, rg, x, h_ in sorted(rows, key=lambda r: r[2]):
            w.write('%#x\t%#x\t%d\t%s\t%s\t%s\t%s\n' % (rg[0], rg[1], rg[1] - rg[0], k, nm, x, h_))
    rec = dict(plan=s['plan'], tool_sha256=sha(os.path.abspath(__file__)), check_sha256=sha(checkj), spec_sha256=sha(spec), section=[hex(A), hex(E)], section_bytes=E - A,
               rows=len(rows), by_group=dict(collections.Counter(k for k, *_ in rows)), covered=sum(b - a for a, b in m),
               gaps=[[hex(a), hex(b), b - a] for a, b in gaps], gap_bytes=sum(b - a for a, b in gaps),
               gaps_ge2=[[hex(a), hex(b), b - a] for a, b in gaps if b - a > 1], work_bytes=sum(b - a for a, b in gaps if b - a > 1),
               one_byte_gaps=pad_like, overlaps=overl, tsv_sha256=sha(out_tsv))
    json.dump(rec, open(out_json, 'w'), indent=1)
    print('rows', rec['rows'], rec['by_group'], 'covered', rec['covered'], 'gap bytes', rec['gap_bytes'], 'work', rec['work_bytes'], 'gaps>=2', len(rec['gaps_ge2']), 'overlaps', overl)


# ---------------------------------------------------------------- selftest

def clear_ext_bit(data, name):
    """copy of a Mach-O object with the N_EXT bit of the named symbol cleared (a real 'definition missing' mutation)"""
    b = bytearray(data)
    ncmds = struct.unpack('>I', b[16:20])[0]
    off = 28
    for _ in range(ncmds):
        cmd, size = struct.unpack('>II', b[off:off + 8])
        if cmd == 2:
            symoff, nsyms, stroff, strsize = struct.unpack('>IIII', b[off + 8:off + 24])
            for i in range(nsyms):
                e = symoff + i * 12
                strx = struct.unpack('>I', b[e:e + 4])[0]
                nm = bytes(b[stroff + strx:b.index(0, stroff + strx)]).decode('latin-1')
                if nm == name:
                    assert b[e + 4] & 1
                    b[e + 4] &= 0xfe
                    return bytes(b)
        off += size
    raise AssertionError('symbol not found: ' + name)


def cmd_selftest(spec, rid, outj, checkj=None):
    s = load(spec)
    rdir, status = run_files(rid)
    osym = orig_symbols()
    art = '08_build/artifacts/m4p%d/%s/selftest' % (s['plan'], rid)
    os.makedirs(art, exist_ok=True)
    u0 = [u for u in s['units'] if u['name'] == 'tty_conf'][0]
    p0 = os.path.join(rdir, 'out', 'Q%dD__%s.o' % (s['plan'], u0['name']))
    tmpd = tempfile.mkdtemp()
    res = []

    def expect(name, bad, want_reject=True):
        res.append(dict(control=name, rejected=bool(bad), expect_rejected=want_reject, failures=list(bad)[:3]))

    def unit(name, path, u, osym_=None, edit_l1=None):
        l1 = C.run_l1(path, os.path.join(art, name.replace(' ', '_').replace('/', '_') + '.json'))
        if edit_l1:
            edit_l1(l1)
        expect(name, check_unit(path, l1, u, osym if osym_ is None else osym_, s['plan']))
    l1base = C.run_l1(p0, os.path.join(art, 'base.json'))
    expect('base accepted', check_unit(p0, l1base, u0, osym, s['plan']), False)
    raw = open(p0, 'rb').read()
    o = M.parse(raw)
    ds = [x for x in o['sections'] if x['sectname'] == '__data'][0]
    m1 = bytearray(raw); m1[ds['offset'] + ds['size'] - 1] ^= 0x01
    p1 = os.path.join(tmpd, 'c1.o'); open(p1, 'wb').write(m1); unit('data byte changed', p1, u0)
    unit('target address moved', p0, dict(u0, target=hex(int(u0['target'], 16) + 2)))
    unit('size differs', p0, dict(u0, size=u0['size'] + 2))
    unit('placement-only __data', p0, u0, edit_l1=lambda l1: l1['sections'][DATA].__setitem__('placement', 'placement-only'))
    unit('refs_differ 1', p0, u0, edit_l1=lambda l1: l1['sections'][DATA].__setitem__('refs_differ', 1))
    os6 = dict(osym); del os6['_linesw']; unit('defined symbol missing in the original', p0, u0, osym_=os6)
    os7 = dict(osym); os7['_linesw'] += 2; unit('symbol at another address', p0, u0, osym_=os7)
    os8 = dict(osym); os8['_fake_in_range'] = int(u0['target'], 16) + 4; unit('original has a symbol the object does not define', p0, u0, osym_=os8)
    p9 = os.path.join(tmpd, 'c9.o'); open(p9, 'wb').write(clear_ext_bit(raw, '_linesw')); unit('object definition missing (N_EXT cleared)', p9, u0)
    co = s['controls']['common_object']
    assert sha(co['path']) == co['sha256'], 'control object hash'
    unit('COMMON name not in the original', co['path'], [u for u in s['units'] if u['name'] == 'scsiconf'][0])
    p11 = os.path.join(tmpd, 'c11.o'); open(p11, 'wb').write(raw)
    l1 = C.run_l1(p11, os.path.join(art, 'c11.json')); m11 = bytearray(raw); m11[-1] ^= 0xff; open(p11, 'wb').write(m11)
    expect('object changed after L1', check_unit(p11, l1, u0, osym, s['plan']))
    pm = os.path.join(rdir, 'out', 'Q%dR__mach_process.o' % s['plan'])
    unit('object without __data', pm, u0)

    def e13(l1):
        l1['inputs'][P413.IMG] = '0' * 64
    unit('wrong image hash in the L1 inputs', p0, u0, edit_l1=e13)
    rg = sorted((int(u['target'], 16), int(u['target'], 16) + u['size']) for u in s['units'])
    shifted = sorted(rg + [(rg[0][0] + 2, rg[0][1] + 2)])
    expect('overlapping ranges', [x for x in zip(shifted, shifted[1:]) if x[1][0] < x[0][1]])
    n = len(status) // 2
    expect('status accepted (control)', check_status(status, n), False)
    expect('status keys wrong', check_status(['zz', '0'], 1))
    expect('status nonzero', check_status(status[:1] + ['1'] + status[2:], n))
    expect('status duplicate key', check_status(status + ['00', '0'], n))
    expect('status stray token', check_status(status + ['STRAY'], n))
    expect('status keys out of order', check_status(status[2:4] + status[0:2] + status[4:], n))
    expect('stderr whitespace', check_err(' \n', 'x'))
    names = sorted(os.listdir(os.path.join(rdir, 'out', '_log')))
    expect('log files accepted (control)', check_log(names, n), False)
    expect('a .err file missing', check_log([x for x in names if x != '00.err'], n))
    expect('an unexpected log file', check_log(names + ['99.err'], n))
    man = json.load(open(s['base'] + '.manifest.json')); stman = {f[0]: (f[1], f[2]) for f in man['files']}
    dtext = open(os.path.join(rdir, 'out', '_log', '04.out'), errors='replace').read()
    rs = lambda d: stman[d[len('src/'):]][1]
    expect('deps accepted (control)', check_deps(dtext, u0, stman, rs), False)
    expect('headers removed from the dependency list', check_deps('tty_conf.o: src/src/bsd/kern/tty_conf.c\n', u0, stman, rs))
    expect('one header dropped from the dependency list', check_deps(dtext.replace('src/src/bsd/sys/param.h', '', 1), u0, stman, rs))
    expect('dependency outside src/', check_deps(dtext + ' /outside/i386/evil.h', u0, stman, rs))
    expect('dependency not in the manifest', check_deps(dtext + ' src/src/nowhere.h', u0, stman, rs))
    expect('header content differs', check_deps(dtext, u0, stman, lambda d: '0' * 64 if d.endswith('param.h') else rs(d)))
    expect('wrong dependency target', check_deps(dtext.replace('tty_conf.o:', 'other.o:', 1), u0, stman, rs))
    exp_run, _ = expected_lines(s)
    runs = [l for l in open(os.path.join(rdir, 'run.cmd')).read().splitlines() if l.startswith('RUN ')]
    expect('run.cmd equals the generated lines (control)', check_cmd(runs, exp_run), False)
    expect('compile option removed', check_cmd([runs[0].replace('-arch m68k ', '')] + runs[1:], exp_run))
    expect('reference is the object itself', check_ref(dict(u0, ref=p0), p0, sha))
    expect('reference hash not pinned', check_ref(dict(u0, ref_sha256='0' * 64), p0, sha))
    expect('reference from the same run', check_ref(dict(u0, ref=os.path.join(rdir, 'out', 'Q%dD__uipc_proto.o' % s['plan'])), p0, sha))
    expect('reference independent and pinned (control)', check_ref(u0, p0, sha), False)
    ckp = checkj or '09_validation/reconstruction/m4-m68k-p%d-check-20261108.json' % s['plan']   # plan 781: explicit CHECK.json
    if os.path.exists(ckp):
        ck = json.load(open(ckp))
        ts, ss = sha(os.path.abspath(__file__)), sha(spec)   # plan 781: the actual tool and spec hashes (a stale record must fail the control)
        expect('check record verifies (control)', verify_check_record(ck, sha, ss, ts, s), False)
        expect('L1 record changed after check', verify_check_record(ck, lambda p: '0' * 64 if p.endswith('l1-counters.json') else sha(p), ss, ts, s))
        expect('refresh object changed after check', verify_check_record(ck, lambda p: '0' * 64 if p.endswith('Q%dR__ns_timer.o' % s['plan']) else sha(p), ss, ts, s))
        expect('check record from another spec', verify_check_record(ck, sha, '0' * 64, ts, s))
        import copy
        c1 = copy.deepcopy(ck); c1['results'] = [r for r in c1['results'] if r['name'] != 'conf']
        expect('a unit missing in the check record', verify_check_record(c1, sha, ss, ts, s))
        c2 = copy.deepcopy(ck); c2['results'].append(copy.deepcopy(c2['results'][-1]))
        expect('a unit twice in the check record', verify_check_record(c2, sha, ss, ts, s))
        c3 = copy.deepcopy(ck); c3['verified_bytes'] += 1
        expect('verified_bytes changed', verify_check_record(c3, sha, ss, ts, s))
        c4 = copy.deepcopy(ck); [r.__setitem__('size', r['size'] + 2) for r in c4['results'] if r['name'] == 'vers']
        expect('a unit size changed in the check record', verify_check_record(c4, sha, ss, ts, s))
    else:
        res.append(dict(control='check record present', rejected=False, expect_rejected=True, failures=['check record missing: controls cannot be skipped']))
    shutil.rmtree(tmpd)
    wrong = [r['control'] for r in res if r['expect_rejected'] != r['rejected']]
    rec = dict(plan=s['plan'], tool_sha256=sha(os.path.abspath(__file__)), run=rid, controls=res, wrong=wrong, negatives=sum(1 for r in res if r['expect_rejected']),
               positives=sum(1 for r in res if not r['expect_rejected']), ok=not wrong)
    json.dump(rec, open(outj, 'w'), indent=1)
    for r in res:
        print(('control ' if not r['expect_rejected'] else 'mutation'), r['control'], 'rejected' if r['rejected'] else 'ACCEPTED', r['failures'][:1])
    print('negatives', rec['negatives'], 'positives', rec['positives'], 'wrong', wrong, 'ok', rec['ok'])
    sys.exit(0 if rec['ok'] else 1)


if __name__ == '__main__':
    c = sys.argv[1]
    if c == 'cmd':
        cmd_cmd(sys.argv[2], sys.argv[3])
    elif c == 'check':
        cmd_check(sys.argv[2], sys.argv[3], sys.argv[4])
    elif c == 'pins':
        cmd_pins(sys.argv[2])
    elif c == 'coverage':
        cmd_coverage(sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5])
    elif c == 'selftest':
        cmd_selftest(sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5] if len(sys.argv) > 5 else None)
    else:
        raise SystemExit(__doc__)
