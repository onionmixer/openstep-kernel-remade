#!/usr/bin/env python3
"""S2-B: candidate source functions for every original function (plan 16 / 16.1).

  s2b_candidates.py OUT.tsv REPORT.json [--mutate-always-medium] [--shuffle-negative] [--detail DETAIL.tsv]

--detail (plan 26.1) also writes every candidate before body grouping, with its own
current weighted score; the default outputs are unchanged.

Confidence never exceeds 'medium' here; 'high' needs compiled L1 evidence (S5).
Original-side features are validated against the original instruction bytes.
"""
import bisect, collections, csv, hashlib, json, math, os, random, re, sys, warnings
warnings.filterwarnings('ignore', category=DeprecationWarning)   # invalid escapes in reference strings

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import capstone
import l1_compare as L
import srcdefs
import objc_meta

REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
UP = os.path.join(REPO, '01_resources', 'upstream')
TREES = [('darwin01', 'darwin01/kernel'), ('darwin01-dk', 'darwin01/driverkit-1'), ('nextmach', 'nextmach'), ('mach4', 'mach4')]
REVISIONS = {'mach4': 'git 69fa77870f20d854c875135e116ebc80b118e7ff',
             'nextmach': 'git f6bdb9c3268f0eadc545d41bcc0564453b17001e',
             'darwin01': 'kernel-1.tar.gz sha256 0c19349be454d7162f497b55a7735b443f5506694215e2f3f5f026b597a54a01',
             'darwin01-dk': 'driverkit-139.1-1.tar.gz sha256 255235626e702fe52b28564c0bc5644a686f1e886697f1c567b6a4275bc43102'}
KEYWORDS = {'if', 'while', 'for', 'switch', 'return', 'sizeof', 'do', 'else', 'case', 'defined'}
CDEF = re.compile(r'^([A-Za-z_]\w*)\s*\(')
MDEF = re.compile(r'^([+-])\s*(\([^)]*\))?\s*(\w+)(.*)$')
CALL = re.compile(r'\b([A-Za-z_]\w*)\s*\(')
STR = re.compile(r'"((?:\\.|[^"\\\n])*)"')
IMPL = re.compile(r'^@implementation\s+(\w+)(?:\s*\(\s*(\w+)\s*\))?')


def unescape(s):
    import codecs
    try:
        return codecs.escape_decode(s.encode('latin1', 'replace'))[0]
    except Exception:
        return s.encode('latin1', 'replace')


def norm_hash(text):
    t = re.sub(r'/\*.*?\*/', '', text, flags=re.S)
    t = re.sub(r'//[^\n]*', '', t)
    t = re.sub(r'\s+', '', t)
    return hashlib.sha1(t.encode('latin1', 'replace')).hexdigest()[:16]


def selector_of(rest_after_name, first):
    """ObjC method selector from a definition line: '- (int)setX:(int)v y:(int)w' -> 'setX:y:'."""
    s = first + rest_after_name
    parts = re.findall(r'(\w+)\s*:', s)
    return ''.join(p + ':' for p in parts) if parts else first


def corpus():
    defs = []
    for tree, rel in TREES:
        root = os.path.join(UP, rel)
        for dp, dn, fn in os.walk(root):
            dn.sort()                                   # deterministic order (plan 27 design 3)
            if '/.git' in dp or '/CVS' in dp or '/ppc' in dp:
                continue
            for f in sorted(fn):
                if not f.endswith(('.c', '.m')):
                    continue
                p = os.path.join(dp, f)
                lines = open(p, errors='replace').read().splitlines()
                for name, i, j, head in srcdefs.find(lines):
                    body = '\n'.join(lines[i:j + 1])
                    prev = lines[i - 1] if i else ''
                    defs.append(dict(tree=tree, path=os.path.relpath(p, UP), line=i + 1, name=name, kind='c',
                                     static=('static' in prev or lines[i].startswith('static')),
                                     calls={c for c in CALL.findall(body) if c not in KEYWORDS and c != name},
                                     strings={unescape(s) for s in STR.findall(body)}, body=norm_hash(body)))
                if not f.endswith('.m'):
                    continue
                impl = None
                for i, l in enumerate(lines):
                    mi = IMPL.match(l)
                    if mi:
                        impl = (mi.group(1), mi.group(2))
                        continue
                    if l.startswith('@end'):
                        impl = None
                        continue
                    name = kind = None
                    if impl:
                        mm = MDEF.match(l)
                        if mm and not l.rstrip().endswith(';'):
                            name = selector_of(mm.group(4), mm.group(3))
                            kind = 'objc'
                    if not name:
                        continue
                    j = next((k for k in range(i, min(len(lines), i + 3000)) if lines[k].rstrip() == '}'), None)
                    if j is None:
                        continue
                    body = '\n'.join(lines[i:j + 1])
                    prev = lines[i - 1] if i else ''
                    d = dict(tree=tree, path=os.path.relpath(p, UP), line=i + 1, name=name, kind=kind,
                             static=('static' in prev or l.startswith('static')),
                             calls={c for c in CALL.findall(body) if c not in KEYWORDS and c != name},
                             strings={unescape(s) for s in STR.findall(body)}, body=norm_hash(body))
                    if kind == 'objc':
                        d['owner'], d['category'], d['mkind'] = impl[0], impl[1], 'instance' if mm.group(1) == '-' else 'class'
                    defs.append(d)
    return defs


def original_features(img, funcs, ext_text):
    text = [s for s in img.secs if s['sectname'] == '__text'][0]
    strsecs = [s for s in img.secs if s['sectname'] in ('__data', '__cstring', '__const')]
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    iv = []
    for k, f in enumerate(funcs):
        for s, e in f['ranges']:
            iv.append((s, e, k))
    iv.sort()
    starts = [x[0] for x in iv]
    fstart = {f['address'] for f in funcs}
    addr_name = {v: n for n, v in ext_text.items()}

    def owner(a):
        i = bisect.bisect_right(starts, a) - 1
        return iv[i][2] if i >= 0 and iv[i][0] <= a < iv[i][1] else None

    def decode(a):
        return next(md.disasm(img.read(a, 15), a), None)

    feats = [dict(calls=set(), strings=set(), unnamed_calls=0, tail_jumps=0, indirect=0) for _ in funcs]
    for row in csv.DictReader(open(os.path.join(REPO, '04_ghidra/exports/x86/full-pass5/references.tsv')), delimiter='\t'):
        t = row['type']
        if not row['to'].startswith('0x0') and t != 'COMPUTED_CALL':
            continue
        frm = int(row['from'], 16)
        k = owner(frm)
        if k is None:
            continue
        if t == 'COMPUTED_CALL':
            feats[k]['indirect'] += 1
            continue
        to = int(row['to'], 16)
        if t == 'UNCONDITIONAL_CALL':
            i = decode(frm)
            if i is None or i.mnemonic != 'call' or not i.operands or i.operands[0].type != capstone.x86.X86_OP_IMM \
                    or (i.operands[0].imm & 0xffffffff) != to:
                continue
            if to in addr_name:
                feats[k]['calls'].add(addr_name[to][1:])
            else:
                feats[k]['unnamed_calls'] += 1
        elif t == 'UNCONDITIONAL_JUMP':
            if to in fstart and owner(to) != k:
                feats[k]['tail_jumps'] += 1
        elif t in ('READ', 'WRITE', 'READ_WRITE', 'DATA'):
            sec = next((s for s in strsecs if s['addr'] <= to < s['addr'] + s['size']), None)
            if sec is None:
                continue
            i = decode(frm)
            ok = i is not None and any((op.type == capstone.x86.X86_OP_IMM and (op.imm & 0xffffffff) == to) or
                                       (op.type == capstone.x86.X86_OP_MEM and (op.mem.disp & 0xffffffff) == to)
                                       for op in i.operands)
            if not ok:
                continue
            b = img.read(to, min(512, sec['addr'] + sec['size'] - to)) or b''
            z = b.find(b'\0')
            if z < 3:
                continue
            s = b[:z]
            if sum(32 <= c < 127 or c in (9, 10, 13) for c in s) / len(s) >= 0.9:
                feats[k]['strings'].add(s)
    return feats


M68K_OR_STANDALONE = ('/next/', '/nextdev/', '/nextif/', '/fpsp/', '/mon/', '/stand/')


def path_class(tree, path):
    """'m68k-or-standalone' for NeXTMach paths that cannot be i386 kernel code, else 'kernel'."""
    if tree == 'nextmach' and any(x in '/' + path for x in M68K_OR_STANDALONE):
        return 'm68k-or-standalone'
    return 'kernel'


def main():
    out_tsv, out_json = sys.argv[1:3]
    always_medium = '--mutate-always-medium' in sys.argv
    shuffle = '--shuffle-negative' in sys.argv
    detail_path = sys.argv[sys.argv.index('--detail') + 1] if '--detail' in sys.argv else None
    detail = []
    img = L.Image(os.path.join(REPO, '03_original/x86/binaries/mach_kernel'))
    ext_text = {}
    for r in csv.DictReader(open(os.path.join(REPO, '03_original/x86/inventory/symbols.tsv')), delimiter='\t'):
        if r['type'] == '0xf' and r['section'] == '1':
            ext_text[r['name']] = int(r['value'], 16)
    names_plain = {n[1:] for n in ext_text}
    funcs = []
    for f in json.load(open(os.path.join(REPO, '04_ghidra/exports/x86/full-pass5/functions.json'))):
        if f['analysis_fragment']:
            continue
        a = int(f['address'], 16)
        funcs.append(dict(address=a, name=f['name'] if f['name'] in ext_text and ext_text[f['name']] == a else None,
                          ranges=[(int(b['start'], 16), int(b['end_inclusive'], 16) + 1) for b in f['body']]))
    funcs.sort(key=lambda f: f['address'])
    feats = original_features(img, funcs, ext_text)
    N = len(funcs)
    df = collections.Counter()
    for ft in feats:
        for c in ft['calls']:
            df['c:' + c] += 1
        for s in ft['strings']:
            df[b's:' + s] += 1
    w = lambda k: math.log(N / df[k]) if df[k] else 0.0
    tau = math.log(N / 5)
    defs = corpus()
    by_name = collections.defaultdict(list)
    by_base = collections.defaultdict(list)
    by_meth = collections.defaultdict(list)
    for d in defs:
        d['cfeat'] = {'c:' + c for c in d['calls'] if c in names_plain} | {b's:' + s for s in d['strings']}
        if d['kind'] == 'c':
            by_name[d['name']].append(d)
        else:
            by_meth[(d['owner'], d['category'], d['mkind'], d['name'])].append(d)
        by_base[os.path.basename(d['path'])].append(d)
    meta = objc_meta.Meta(img).read()
    imp_meth = {m['imp']: m for m in meta['methods']}
    # S2-A run labels per function (neighbours included)
    runs = list(csv.DictReader(open(os.path.join(REPO, '06_reconstruction/objects.tsv')), delimiter='\t'))
    rstart = [int(r['text_start'], 16) for r in runs]
    rng = random.Random(20261001)
    all_defs = [d for d in defs if d['kind'] == 'c']
    rows, stats = [], collections.Counter()
    for k, f in enumerate(funcs):
        of = {'c:' + c for c in feats[k]['calls']} | {b's:' + s for s in feats[k]['strings']}
        total = sum(w(x) for x in of)
        if f['name']:
            kind, cands = 'named', list(by_name.get(f['name'][1:], []))
        elif f['address'] in imp_meth:
            m = imp_meth[f['address']]
            kind, cands = 'objc', list(by_meth.get((m['owner'], m['category'], m['kind'], m['selector']), []))
        else:
            kind = 'unnamed'
            i = bisect.bisect_right(rstart, f['address']) - 1
            bases = set()
            for j in (i - 1, i, i + 1):
                if 0 <= j < len(runs):
                    bases |= set(runs[j]['labels'].split(','))
            cands = [d for b in sorted(bases) for d in by_base.get(b, []) if d['kind'] == 'c']
        if shuffle and kind == 'named' and cands:
            cands = [rng.choice([d for d in rng.sample(all_defs, 20) if d['name'] != f['name'][1:]] or all_defs)]
        if detail_path:
            for d in cands:
                sh = of & d['cfeat']
                detail.append((hex(f['address']), f['name'] or '', kind, d['tree'], d['path'], d['line'], d['name'],
                               d['body'], round(sum(w(x) for x in sh), 6), round(total, 6), path_class(d['tree'], d['path']),
                               ';'.join(sorted(x[2:] if isinstance(x, str) else x[2:].decode('latin1')[:30] for x in sh))[:300]))
        groups = collections.defaultdict(list)
        for d in cands:
            groups[d['body']].append(d)
        scored = sorted(((max(sum(w(x) for x in of & d['cfeat']) for d in g), h, g) for h, g in groups.items()),
                        key=lambda x: -x[0])
        top = scored[0][0] if scored else 0.0
        second = scored[1][0] if len(scored) > 1 else 0.0
        unresolved = feats[k]['unnamed_calls'] + feats[k]['tail_jumps'] + feats[k]['indirect']
        str_shared = 0.0
        if scored:
            str_shared = max(sum(w(x) for x in of & d['cfeat'] if isinstance(x, bytes)) for d in scored[0][2])
        if not cands:
            status, conf = 'unmapped', 'unknown'
        else:
            status = 'candidate'
            ok = total >= tau and top >= tau and (len(scored) == 1 or top - second >= tau / 2)
            if ok and unresolved and str_shared < tau:
                ok = False
            conf = 'medium' if (ok or (always_medium and cands)) else 'low'
        if len(scored) > 1 and top >= tau and second >= tau and top - second < tau / 2:
            disp = 'conflicting'
        elif len(scored) == 1 and len(cands) > 1:
            disp = 'identical-bodies'
        else:
            disp = 'single'
        topg = scored[0][2] if scored else []
        stats[(kind, conf)] += 1
        rows.append(dict(va=hex(f['address']), symbol=f['name'] or '', kind=kind, status=status, confidence=conf,
                         disposition=disp, top='; '.join('%s:%s:%d:%s' % (d['tree'], d['path'], d['line'], d['name']) for d in topg[:6]),
                         top_score=round(top, 3), second_score=round(second, 3), original_feature_weight=round(total, 3),
                         shared=';'.join(sorted(x[2:] if isinstance(x, str) else x[2:].decode('latin1')[:30]
                                                for x in (of & topg[0]['cfeat'] if topg else set())))[:300],
                         unresolved_edges=unresolved, candidates=len(cands)))
    with open(out_tsv, 'w') as o:
        o.write('# S2-B candidates (plan 16.1). binary_sha256 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; '
                'revisions: %s\n' % json.dumps(REVISIONS))
        cols = list(rows[0].keys())
        o.write('\t'.join(cols) + '\n')
        for r in rows:
            o.write('\t'.join(str(r[c]).replace('\\', '\\\\').replace('\t', '\\t').replace('\n', '\\n').replace('\r', '\\r')
                              for c in cols) + '\n')
    rep = dict(functions=N, tau=tau, by_kind_confidence={'%s/%s' % k: v for k, v in sorted(stats.items())},
               definitions=len(defs), mutate_always_medium=always_medium, shuffle_negative=shuffle)
    json.dump(rep, open(out_json, 'w'), indent=1)
    if detail_path:
        with open(detail_path, 'w') as o:
            o.write('va\tsymbol\tkind\ttree\tpath\tline\tname\tbody_hash\tscore\toriginal_feature_weight\tpath_class\tshared\n')
            for r in detail:
                o.write('\t'.join(str(x).replace('\\', '\\\\').replace('\t', '\\t').replace('\n', '\\n').replace('\r', '\\r') for x in r) + '\n')
    print(json.dumps(rep, indent=1))


if __name__ == '__main__':
    main()
