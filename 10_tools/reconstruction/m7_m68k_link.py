#!/usr/bin/env python3
"""m7_m68k_link.py -- plan 778.8 P0: offline (no ld) model of the m68k kernel link from the 296 accepted objects.

  python3 10_tools/reconstruction/m7_m68k_link.py spec   OUT.json
  python3 10_tools/reconstruction/m7_m68k_link.py common OUT.json
  python3 10_tools/reconstruction/m7_m68k_link.py depcmd OUTDIR   (plan 778.12 P3a: -M command files for objects without one)
  python3 10_tools/reconstruction/m7_m68k_link.py deps PLAN.json OUT.json   (plan 778.12 P3a: per-object dependency lists)

Read-only.  Inputs are rebuilt from the evidence records (not from scratch files):
  M4: 06_reconstruction/m68k-m4-status.tsv rows -> the plan's L1 record whose inputs contain obj_sha256
  M5: M5DIR/l1-x86-*.json minus tty_pty (M4 has it), kern_exec, mach_process, ns_timer
  R/D: CHECK_RD results (m5_refresh -> R:, data units -> D:)
  plan 786: M5DIR = the plan 786 m5compare records (plan 784: plan 784; plan 782: plan 779), CHECK_RD = the plan 781 data check record (before plan 782: the plan 764
  m5compare and the plan 777 check record; the plan 778 records were made with those and the pre-779 status table)
Every object file is re-hashed against its record.

spec    object list, text order, data-unit candidate positions (data/const/bss monotone vs text order), the cstring
        placements whose first-seen merge equals the original __cstring bytes.
common  plan 778.8 (4): (a) linker model (hypothesis (d) of 778.7: first encounter of an external UNDF/COMMON name in
        link order and physical nlist order; max size; definitions win; alignment min(pow2(size), cap)); (b) address and
        relocation checks against the original; (c) minimum-change assignment of the original __common order to link
        positions (dynamic programming, optimal position sets); (d) over the cstring-consistent placements of the
        data units that mention original __common names.
Nothing here proves the original objects' declarations; results are candidates consistent with the bytes.
"""
import sys, os, re, json, glob, struct, hashlib, itertools, collections

ORIG = '03_original/m68k/binaries/mach_kernel'
ORIG_SHA = 'dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75'
STATUS = '06_reconstruction/m68k-m4-status.tsv'
M5DIR = '08_build/artifacts/m4p786/m5compare'   # plan 786 (before: m4p784/m5compare, plan 784; m4p779/m5compare, plan 782; m4p764/m5compare, plan 778)
CHECK_RD = '09_validation/reconstruction/m4-m68k-p781-check-20261109.json'   # plan 782 (before: m4-m68k-p777-check-20261108.json)
M5SKIP = {'tty_pty', 'kern_exec', 'mach_process', 'ns_timer'}
SEC = {'t': ('__TEXT', '__text'), 'd': ('__DATA', '__data'), 'c': ('__TEXT', '__const'),
       's': ('__TEXT', '__cstring'), 'b': ('__DATA', '__bss')}
NOT_TARGET = ('D:counters', 'D:init_sysent', 'D:ufs_tables', 'D:vers')   # 778.8 (4)(c): no mentions, not assignment targets


def die(m):
    sys.exit('m7_m68k_link: ' + m)


def need(c, m):
    if not c:
        die(m)


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


# ---------------------------------------------------------------- big-endian Mach-O
def parse(path):
    b = open(path, 'rb').read()
    magic, cpu, sub, ft, nc, sz, fl = struct.unpack('>7I', b[:28])
    need(magic == 0xfeedface, 'not a big-endian Mach-O: ' + path)
    out = dict(cpusubtype=sub, filetype=ft, sects=[], syms=[], raw=b)
    o = 28
    for i in range(nc):
        cmd, cs = struct.unpack('>2I', b[o:o + 8])
        if cmd == 1:
            ns = struct.unpack('>I', b[o + 48:o + 52])[0]
            p = o + 56
            for j in range(ns):
                sn = b[p:p + 16].rstrip(b'\0').decode()
                sg = b[p + 16:p + 32].rstrip(b'\0').decode()
                ad, s, off, al, ro, nr, f2 = struct.unpack('>7I', b[p + 32:p + 60])
                rel = [struct.unpack('>2I', b[ro + 8 * k:ro + 8 * k + 8]) for k in range(nr)]
                zf = (f2 & 0xff) == 1
                out['sects'].append(dict(seg=sg, name=sn, addr=ad, size=s, offset=off, align=al, flags=f2,
                                         relocs=rel, data=None if zf else b[off:off + s]))
                p += 68
        elif cmd == 2:
            so, ns, sto, ss = struct.unpack('>4I', b[o + 8:o + 24])
            for k in range(ns):
                sx, t, sc, de, v = struct.unpack('>IBBhI', b[so + 12 * k:so + 12 * k + 12])
                nm = b[sto + sx:b.index(b'\0', sto + sx)].decode('latin1')
                out['syms'].append(dict(i=k, name=nm, type=t, sect=sc, value=v))
        o += cs
    return out


def kind(s):
    t = s['type']
    if t & 0xe0:
        return 'stab'
    ty = t & 0x0e
    if ty == 0:
        return 'COMMON' if s['value'] else 'UNDF'
    return {2: 'ABS', 0x0e: 'SECT'}.get(ty, hex(ty))


def ext_relocs(o):
    """(section name, offset, symbol name, length, pcrel) for non-scattered external relocations."""
    out = []
    for s in o['sects']:
        for a, w in s['relocs']:
            if a & 0x80000000:
                continue
            if (w >> 4) & 1:
                out.append((s['name'], a, o['syms'][w >> 8]['name'], (w >> 5) & 3, (w >> 7) & 1))
    return out


# ---------------------------------------------------------------- inputs
def load_objects():
    objs = []

    def add(key, path, osha, l1):
        need(os.path.isfile(path), 'missing object ' + path)
        need(sha(path) == osha, 'object hash differs ' + path)
        sec = l1['sections']
        o = dict(key=key, path=path, sha256=osha, verdict=l1.get('object_verdict'))
        for k, (sg, sn) in SEC.items():
            s = sec.get(sg + ',' + sn)
            o[k] = s.get('address') if s and s.get('size') else None
            o[k + 'l'] = s['size'] if s and s.get('size') else 0
        objs.append(o)

    rows = [x.rstrip('\n').split('\t') for x in open(STATUS) if not x.startswith('#')]
    h = rows[0]
    for r in rows[1:]:
        d = dict(zip(h, r))
        rec = json.load(open(d['record']))
        hit = None
        for x in sorted(glob.glob('08_build/artifacts/m4p%d/%s/l1-%s-*.json' % (int(d['plan']), rec['run'], d['name']))):
            l = json.load(open(x))
            ps = [p for p, v in l['inputs'].items() if v == d['obj_sha256']]
            if ps:
                hit = (ps[0], l)
                break
        need(hit is not None, 'no L1 for M4 ' + d['name'])
        add('M4:' + d['name'], hit[0], d['obj_sha256'], hit[1])
    for f in sorted(glob.glob(M5DIR + '/l1-x86-*.json')):
        nm = re.match(r'l1-x86-(.+)\.json$', os.path.basename(f)).group(1)
        if nm in M5SKIP:
            continue
        l = json.load(open(f))
        ps = [(p, v) for p, v in l['inputs'].items() if p != ORIG]
        need(len(ps) == 1 and l['inputs'].get(ORIG) == ORIG_SHA, 'bad M5 inputs ' + f)
        add('M5:' + nm, ps[0][0], ps[0][1], l)
    ck = json.load(open(CHECK_RD))
    for r in ck['results']:
        need(r.get('ok') is True, 'R/D check result not ok ' + r['name'])
        l1 = json.load(open(r['l1']))
        need(sha(r['l1']) == r['l1_sha256'], 'R/D l1 hash ' + r['name'])
        need(l1['inputs'].get(r['object']) == r['obj_sha256'], 'R/D l1 inputs ' + r['name'])
        add(('R:' if r['kind'] == 'm5_refresh' else 'D:') + r['name'], r['object'], r['obj_sha256'], l1)
    cnt = collections.Counter(o['key'][:2] for o in objs)
    need(len(objs) == 296 and cnt == {'M4': 76, 'M5': 204, 'R:': 3, 'D:': 13}, 'object set %d %s' % (len(objs), dict(cnt)))
    need(len(set(o['key'] for o in objs)) == 296, 'duplicate keys')
    return {o['key']: o for o in objs}


def text_order(objs):
    T = sorted([k for k in objs if objs[k]['t']], key=lambda k: objs[k]['t'])
    for a, b in zip(T, T[1:]):
        need(objs[a]['t'] + objs[a]['tl'] == objs[b]['t'], 'text gap/overlap %s %s' % (a, b))
    return T


def candidates(objs, T, k):
    o = objs[k]
    pos = []
    for i in range(len(T) + 1):
        ok = True
        for key in ('d', 'c', 'b'):
            if not o[key]:
                continue
            pv = [objs[x][key] for x in T[:i] if objs[x][key]]
            nx = [objs[x][key] for x in T[i:] if objs[x][key]]
            if (pv and max(pv) > o[key]) or (nx and min(nx) < o[key]):
                ok = False
                break
        if ok:
            pos.append(i)
    return pos


def build_order(T, place):
    """place: {unit: text index}; units at one index keep name order (asserted irrelevant by callers)."""
    ins = collections.defaultdict(list)
    for k in sorted(place):
        ins[place[k]].append(k)
    out = []
    for i in range(len(T) + 1):
        out += ins.get(i, [])
        if i < len(T):
            out.append(T[i])
    return out


def section(o, sn):
    for s in o['sects']:
        if s['name'] == sn:
            return s
    return None


class World:
    def __init__(self):
        need(sha(ORIG) == ORIG_SHA, 'original hash')
        self.O = parse(ORIG)
        self.objs = load_objects()
        self.P = {k: parse(o['path']) for k, o in self.objs.items()}
        self.T = text_order(self.objs)
        self.D = sorted(k for k in self.objs if k.startswith('D:'))
        need(all(not self.objs[k]['t'] for k in self.D), 'data unit with text')
        self.cand = {k: candidates(self.objs, self.T, k) for k in self.D}
        cm = section(self.O, '__common')
        self.CB, self.CE = cm['addr'], cm['addr'] + cm['size']
        self.osect = {s['name']: s for s in self.O['sects']}
        self.ocom = sorted((s['value'], s['name']) for s in self.O['syms']
                           if kind(s) == 'SECT' and self.CB <= s['value'] < self.CE and s['sect'] == 6)
        self.oaddr = {n: a for a, n in self.ocom}

    def ofoff(self, a):
        for s in self.O['sects']:
            if s['addr'] <= a < s['addr'] + s['size'] and s['data'] is not None:
                return s['offset'] + a - s['addr']
        return None

    def cstring_ok(self):
        orig = self.osect['__cstring']['data']
        cs = {k: (section(p, '__cstring') or {}).get('data') or b'' for k, p in self.P.items()}
        dstr = [k for k in self.D if cs[k]]
        good = []
        n = 0
        for combo in itertools.product(*[self.cand[k] for k in dstr]):
            n += 1
            order = build_order(self.T, dict(zip(dstr, combo)))
            seen = set()
            out = []
            for k in order:
                for s in cs[k].split(b'\0')[:-1]:
                    if s not in seen:
                        seen.add(s)
                        out.append(s + b'\0')
            if b''.join(out) == orig:
                good.append(dict(zip(dstr, combo)))
        return dstr, n, good


# ---------------------------------------------------------------- spec
def inputs():
    """plan 782: the evidence inputs of this run (paths and hashes)"""
    return dict(status=STATUS, status_sha256=sha(STATUS), m5dir=M5DIR,
                m5_set_sha256=hashlib.sha256('\n'.join('%s %s' % (f, sha(f)) for f in sorted(glob.glob(M5DIR + '/l1-x86-*.json'))).encode()).hexdigest(),
                check_rd=CHECK_RD, check_rd_sha256=sha(CHECK_RD))


def cmd_spec(out):
    W = World()
    dstr, n, good = W.cstring_ok()
    rec = dict(plan='M7 P0 spec (method plan 778.8)', inputs=inputs(), tool_sha256=sha(os.path.abspath(__file__)), original=ORIG, original_sha256=ORIG_SHA,
               objects=[dict(key=k, path=o['path'], sha256=o['sha256'], verdict=o['verdict'],
                             **{x: o[x] for x in ('t', 'tl', 'd', 'dl', 'c', 'cl', 's', 'sl', 'b', 'bl')})
                        for k, o in sorted(W.objs.items())],
               text_order=W.T, text_bytes=sum(W.objs[k]['tl'] for k in W.T),
               unit_candidates=W.cand, cstring_units=dstr, cstring_combos=n, cstring_good=good,
               cstring_good_positions={k: sorted(set(g[k] for g in good)) for k in dstr})
    json.dump(rec, open(out, 'w'), indent=1)
    print('objects', len(W.objs), 'text objects', len(W.T), 'text bytes', rec['text_bytes'],
          'cstring combos', n, 'byte-identical', len(good))


# ---------------------------------------------------------------- common
def pow2(s):
    return 1 << (s - 1).bit_length() if s > 1 else 1


def mentions_of(P, k):
    """physical nlist order of external UNDF/COMMON names; value = COMMON size or 0."""
    return [(s['name'], s['value']) for s in P[k]['syms'] if s['type'] & 1 and kind(s) in ('UNDF', 'COMMON')]


def joint_sizes(W, size, cap):
    """forward/backward feasible size sets of the original __common names (known sizes fixed)."""
    names = [n for a, n in W.ocom]
    A = W.oaddr
    N = len(names)
    al = lambda s: min(pow2(s), cap)
    cand = []
    for i, n in enumerate(names):
        gap = (A[names[i + 1]] if i + 1 < N else W.CE) - A[n]
        cand.append([size[n]] if n in size else list(range(1, gap + 1)))
    ok = lambda i, s, t: (A[names[i]] + s + al(t) - 1) // al(t) * al(t) == A[names[i + 1]]
    fw = [set(cand[0])]
    for i in range(1, N):
        fw.append({t for t in cand[i] if any(ok(i - 1, s, t) for s in fw[i - 1])})
    bw = [None] * N
    bw[N - 1] = {s for s in fw[N - 1] if A[names[N - 1]] + s == W.CE}
    for i in range(N - 2, -1, -1):
        bw[i] = {s for s in fw[i] if any(ok(i, s, t) for t in bw[i + 1])}
    feasible = all(bw)
    witness = None
    if feasible:      # prefer the largest sizes, left to right, keeping the rest feasible
        witness = {}
        prev = None
        for i, n in enumerate(names):
            opts = sorted(bw[i], reverse=True)
            if prev is not None:
                opts = [t for t in opts if ok(i - 1, prev, t)]
            need(opts, 'witness construction')
            prev = opts[0]
            witness[n] = prev
    return names, bw, feasible, witness


def alloc(seq, size, cap, start):
    a = start
    out = {}
    for n in seq:
        A = min(pow2(size[n]), cap)
        a = (a + A - 1) // A * A
        out[n] = a
        a += size[n]
    return out, a


def model_seq(W, order, defined, extra=None):
    """(d) first-encounter sequence; extra: {name: order index} synthetic mentions inserted (sorted with the object's
    UNDF/COMMON names, which the assembler emits in name order)."""
    seen = set()
    seq = []
    byk = collections.defaultdict(list)
    for n, j in (extra or {}).items():
        byk[order[j]].append(n)
    for k in order:
        names = [n for n, v in mentions_of(W.P, k)]
        if byk.get(k):
            names = sorted(set(names) | set(byk[k]))
        for n in names:
            if n not in seen:
                seen.add(n)
                if n not in defined and n != '__mh_execute_header':   # ld makes the header symbol (778.7)
                    seq.append(n)
    return seq


def dp_assign(W, order, protected, mpos):
    """Assign each original __common name (address order) to a link position.
    cost(n, j): 0 if j is n's first mention; +1 if j is not a mention of n (addition at j); +1 per mention before j
    (removal), infeasible if any of them is protected (an external relocation to n in that object).
    order constraint: positions non-decreasing; strictly increasing where the name order descends."""
    names = [n for a, n in W.ocom]
    L = len(order)
    allowed = [order[j] not in NOT_TARGET for j in range(L)]
    INF = float('inf')

    def cost(n):
        ms = sorted(mpos.get(n, []))
        row = [INF] * L
        p = 0
        for j in range(L):
            while p < len(ms) and ms[p] < j:
                if (order[ms[p]], n) in protected:
                    return row            # a protected mention before j: j and every later position infeasible
                p += 1
            if allowed[j]:
                row[j] = p + (0 if p < len(ms) and ms[p] == j else 1)
        return row

    C = [cost(n) for n in names]
    N = len(names)
    strict = [i > 0 and names[i] < names[i - 1] for i in range(N)]
    F = [C[0][:]]
    for i in range(1, N):
        pm = [INF] * L
        best = INF
        for j in range(L):           # prefix minima of F[i-1] up to j (or j-1 if strict)
            if strict[i]:
                pm[j] = best
                best = min(best, F[i - 1][j])
            else:
                best = min(best, F[i - 1][j])
                pm[j] = best
        F.append([C[i][j] + pm[j] for j in range(L)])
    B = [None] * N
    B[N - 1] = [0] * L
    for i in range(N - 2, -1, -1):
        sm = [INF] * L
        best = INF
        for j in range(L - 1, -1, -1):  # suffix minima of C[i+1]+B[i+1] from j (or j+1 if strict[i+1])
            v = C[i + 1][j] + B[i + 1][j]
            if strict[i + 1]:
                sm[j] = best
                best = min(best, v)
            else:
                best = min(best, v)
                sm[j] = best
        B[i] = sm
    opt = min(F[N - 1])
    sets = []
    for i in range(N):
        sets.append([j for j in range(L) if F[i][j] + B[i][j] == opt])
    # one traceback: leftmost feasible optimal choice, left to right
    choice = []
    prev = -1
    acc = 0
    for i in range(N):
        js = [j for j in sets[i] if (j > prev if strict[i] else j >= prev)
              and acc + C[i][j] + B[i][j] == opt]
        need(js, 'traceback')
        j = js[0]
        acc += C[i][j]
        choice.append(j)
        prev = j
    return opt, names, C, sets, choice


def cmd_common(out):
    W = World()
    dstr, ncs, good = W.cstring_ok()
    P = W.P
    order0 = W.T
    defined = set()
    size = {}
    for k in W.objs:
        for s in P[k]['syms']:
            if not s['type'] & 1:
                continue
            if kind(s) == 'SECT':
                defined.add(s['name'])
            elif kind(s) == 'COMMON':
                size[s['name']] = max(size.get(s['name'], 0), s['value'])
    onames = [n for a, n in W.ocom]
    oset = set(onames)
    need(not (oset & defined), 'original __common name defined by an object')
    comm_names = set(size)
    overridden = sorted(comm_names & defined)
    known = {n: size[n] for n in onames if n in size}
    undeclared = [n for n in onames if n not in size]
    bm = [k for k in W.objs if any(n == '_bootp' for n, v in mentions_of(P, k))]   # plan 782: _bootp may now be mentioned
    rec = dict(plan='M7 P0 common (method plan 778.8)', inputs=inputs(), tool_sha256=sha(os.path.abspath(__file__)), original_sha256=ORIG_SHA,
               common=[hex(W.CB), hex(W.CE)], original_names=len(onames), input_common_names=len(comm_names),
               overridden=overridden, surviving_in_original=sum(1 for n in comm_names if n in oset),
               surviving_not_in_original=sorted(n for n in comm_names - defined if n not in oset),
               undeclared=undeclared, assumptions=[
                   '__common start taken from the original (preceding sections not modelled)',
                   'direct link of the objects (no intermediate ld -r)',
                   'sizes of undeclared names: largest jointly feasible witness (not evidence)',
                   ('_bootp mentioned by %s; the synthetic mention at the DP position merges with it' % ', '.join(sorted(bm)) if bm else
                    '_bootp has no mention: synthetic declaration, its position is not a prediction'),
                   'units %s are not assignment targets' % ', '.join(NOT_TARGET)])
    # (1) alignment cap test on known neighbours
    caps = {}
    for cap in (1, 2, 4, 8, 16, 1 << 30):
        bad = 0
        tested = 0
        for a, b in zip(onames, onames[1:]):
            if a in known and b in known:
                tested += 1
                A = min(pow2(known[b]), cap)
                if (W.oaddr[a] + known[a] + A - 1) // A * A != W.oaddr[b]:
                    bad += 1
        caps[str(cap)] = dict(tested=tested, mismatches=bad)
    rec['cap_test'] = caps
    # (2) joint size feasibility
    _, bw, feas, witness = joint_sizes(W, known, 4)
    rec['size_feasible_cap4'] = feas
    rec['undeclared_size_ranges'] = {n: [min(bw[onames.index(n)]), max(bw[onames.index(n)])] for n in undeclared}
    rec['undeclared_sum'] = dict(gaps=sum(((W.oaddr[onames[i + 1]] if i + 1 < len(onames) else W.CE) - W.oaddr[n])
                                          for i, n in enumerate(onames) if n not in known),
                                 sum_of_minima=sum(min(bw[onames.index(n)]) for n in undeclared),
                                 witness_sum=sum(witness[n] for n in undeclared))
    full = dict(known)
    full.update({n: witness[n] for n in undeclared})
    # protected mentions: external relocation to the name in that object
    protected = set()
    reloc_list = []
    for k in W.objs:
        for sn, a, nm, ln, pc in ext_relocs(P[k]):
            if nm in oset:
                protected.add((k, nm))
                reloc_list.append((k, sn, a, nm, ln, pc))
    rec['relocations_to_original_common'] = len(reloc_list)
    rec['mentions_without_relocation'] = dict(
        UNDF=sum(1 for k in W.objs for n, v in mentions_of(P, k) if n in oset and not v and (k, n) not in protected),
        COMMON=sum(1 for k in W.objs for n, v in mentions_of(P, k) if n in oset and v and (k, n) not in protected))
    # (d) placements of the mentioning units
    ment_units = [k for k in W.D if any(n in oset for n, v in mentions_of(P, k))]
    need(sorted(ment_units + list(NOT_TARGET)) == W.D, 'mentioning units %s' % ment_units)
    cs_fixed = {}
    for k in dstr:
        cs_fixed[k] = sorted(set(g[k] for g in good))
    combos = []
    free = [k for k in ment_units if k not in dstr]
    others = [k for k in W.D if k not in ment_units]
    for g in good:
        for c in itertools.product(*[W.cand[k] for k in free]):
            pl = dict(g)
            pl.update(zip(free, c))
            for k in others:
                pl[k] = W.cand[k][0]
            combos.append(pl)
    rec['placements_tested'] = len(combos)
    results = []
    best = None
    for pl in combos:
        idx = collections.Counter(pl[k] for k in ment_units)
        need(max(idx.values()) == 1, 'two mentioning units at one text index')
        order = build_order(W.T, pl)
        pos = {k: i for i, k in enumerate(order)}
        mpos = collections.defaultdict(list)
        for k in order:
            for n, v in mentions_of(P, k):
                if n in oset:
                    mpos[n].append(pos[k])
        opt, names, C, sets, choice = dp_assign(W, order, protected, mpos)
        results.append((opt, pl))
        if best is None or opt < best[0]:
            best = (opt, pl, order, mpos, names, C, sets, choice)
    costs = collections.Counter(r[0] for r in results)
    rec['dp_cost_distribution'] = {str(k): v for k, v in sorted(costs.items())}
    optc = best[0]
    bestpl = [r[1] for r in results if r[0] == optc]
    rec['dp_best_cost'] = optc
    rec['dp_best_placements'] = len(bestpl)
    rec['dp_best_positions'] = {k: sorted(set(p[k] for p in bestpl)) for k in ment_units}
    opt, pl, order, mpos, names, C, sets, choice = best
    rec['dp_reported_placement'] = pl
    rows = []
    adds = collections.defaultdict(list)
    rems = collections.defaultdict(list)
    for i, n in enumerate(names):
        ms = mpos.get(n, [])
        first = ms[0] if ms else None
        j = choice[i]
        r = dict(name=n, first=order[first] if first is not None else None, chosen=order[j],
                 optimal=[order[x] for x in sets[i]], cost=C[i][j])
        if j != first:
            rows.append(r)
            if j not in ms:
                adds[order[j]].append(n)
            for m in ms:
                if m < j:
                    rems[order[m]].append(n)
    rec['dp_changed_names'] = rows
    rec['dp_ambiguous_names'] = {n: [order[x] for x in sets[i]] for i, n in enumerate(names) if len(sets[i]) > 1}
    rec['dp_additions'] = dict(adds)
    rec['dp_removals'] = dict(rems)
    # (a)(b) simulate with as-is mentions (+ _bootp at its chosen position) and with the DP assignment
    def check(seq, cap, label):
        addr, end = alloc(seq, full, cap, W.CB)
        same = sum(1 for n in seq if addr.get(n) == W.oaddr.get(n))
        rel_ok = rel_bad = rel_assumed = rel_other = 0
        bad = []
        for k, sn, a, nm, ln, pc in reloc_list:
            key = {'__text': 't', '__data': 'd', '__const': 'c'}.get(sn)
            if key is None or not W.objs[k][key] or ln != 2 or pc:
                rel_other += 1
                continue
            s = section(P[k], sn)
            addend = struct.unpack('>i', s['data'][a:a + 4])[0]
            ov = W.objs[k][key] + a
            f = W.ofoff(ov)
            word = struct.unpack('>I', W.O['raw'][f:f + 4])[0]
            pred = (addr[nm] + addend) & 0xffffffff if nm in addr else None
            if pred == word:
                if nm in known:
                    rel_ok += 1
                else:
                    rel_assumed += 1
            else:
                rel_bad += 1
                if len(bad) < 20:
                    bad.append([k, sn, hex(a), nm, addend, hex(word), hex(pred) if pred is not None else None])
        return dict(label=label, cap=cap, names=len(seq), same_order=seq == onames, address_equal=same,
                    end=hex(end), end_equal=end == W.CE, reloc_equal_known=rel_ok, reloc_equal_assumed_size=rel_assumed,
                    reloc_differ=rel_bad, reloc_not_checked=rel_other, reloc_differ_first=bad)
    bj = names.index('_bootp')
    sims = []
    for cap in (4, 8):
        sims.append(check(model_seq(W, order, defined, {'_bootp': choice[bj]}), cap, 'as-is mentions + synthetic _bootp'))
        # by construction this sequence is the original order; it tests sizes, alignment and relocation addends only
        sims.append(check(dp_seq(W, order, defined, names, choice), cap, 'DP assignment (order fitted)'))
    rec['simulations'] = sims
    json.dump(rec, open(out, 'w'), indent=1)
    print('cap test', {k: v['mismatches'] for k, v in caps.items()}, 'tested', caps['4']['tested'])
    print('undeclared', len(undeclared), rec['undeclared_sum'], 'feasible', feas)
    print('relocations', len(reloc_list), 'mentions without relocation', rec['mentions_without_relocation'])
    print('placements', len(combos), 'dp cost distribution', rec['dp_cost_distribution'], 'best placements', len(bestpl))
    print('best positions', rec['dp_best_positions'])
    print('changed names', len(rows), 'ambiguous', len(rec['dp_ambiguous_names']))
    print('additions', {k: len(v) for k, v in adds.items()}, 'removals', {k: len(v) for k, v in rems.items()})
    for s in sims:
        print('sim', s['label'], 'cap', s['cap'], 'order', s['same_order'], 'addr', s['address_equal'], 'end', s['end_equal'],
              'reloc ok', s['reloc_equal_known'], 'assumed', s['reloc_equal_assumed_size'], 'differ', s['reloc_differ'],
              'unchecked', s['reloc_not_checked'])


# ---------------------------------------------------------------- P3a dependency lists (plan 778.12)
def run_lines(rd):
    return [l.split() for l in open(os.path.join(rd, 'run.cmd')) if l.startswith('RUN ')]


def dep_line(w):
    """plan 778.12 (3): the creating compile line with -c -> -M and the '-o OUTPUT' pair removed."""
    need(w.count('-c') == 1 and w.count('-o') == 1, 'compile line form: ' + ' '.join(w[:3]))
    j = w.index('-o')
    return ['-M' if x == '-c' else x for x in w[:j] + w[j + 2:]]


def creating(o):
    m = re.match(r'(08_build/runs/[^/]+)/(out|stage)/(.+)$', o['path'])
    need(m, 'object not in a run: ' + o['path'])
    rd, base = m.group(1), m.group(3)
    L = run_lines(rd)
    hit = [i for i, w in enumerate(L) if '-o' in w and w[w.index('-o') + 1] == 'stage/' + base]
    need(len(hit) == 1, 'creating line for %s: %d' % (o['key'], len(hit)))
    return rd, hit[0], L


def existing_dep(rd, L, w):
    want = dep_line(w)
    st = {}
    for d in ('out', 'stage'):
        p = os.path.join(rd, d, '_log', 'status')
        if os.path.exists(p):
            st = dict(x.split() for x in open(p).read().splitlines())
            break
    for i, x in enumerate(L):
        if x == want:
            for d in ('out', 'stage'):
                f = os.path.join(rd, d, '_log', '%02d.out' % i)
                e = os.path.join(rd, d, '_log', '%02d.err' % i)
                if os.path.exists(f) and os.path.getsize(f) > 0 and st.get('%02d' % i) == '0' and \
                        os.path.exists(e) and os.path.getsize(e) == 0:
                    return f
    return None


def cmd_depcmd(outdir):
    objs = load_objects()
    have, todo = {}, collections.defaultdict(list)
    for k in sorted(objs):
        rd, i, L = creating(objs[k])
        f = existing_dep(rd, L, L[i])
        if f:
            have[k] = dict(run=rd, line=i, dep=f, dep_sha256=sha(f))
        else:
            src = json.load(open(os.path.join(rd, 'prepare.json')))['src']
            todo[src].append((k, rd, i, dep_line(L[i])))
    os.makedirs(outdir, exist_ok=True)
    plan = []
    for n, (src, items) in enumerate(sorted(todo.items()), 1):
        rid = 'm7p778-dep-%d' % n
        lines = ['# %s: plan 778.12 P3a -M of the creating compile lines (stage %s)' % (rid, src)]
        lines += [' '.join(w) for k, rd, i, w in items]          # w keeps its leading 'RUN'
        lines.append('EXPECT _log/status')
        p = os.path.join(outdir, rid + '.cmd')
        open(p, 'w').write('\n'.join(lines) + '\n')
        plan.append(dict(run=rid, cmd=p, src=src, objects=[dict(key=k, creating_run=rd, creating_line=i, index=j)
                                                           for j, (k, rd, i, w) in enumerate(items)]))
    rec = dict(plan='778.12 P3a', tool_sha256=sha(os.path.abspath(__file__)), existing=have, new_runs=plan)
    json.dump(rec, open(os.path.join(outdir, 'm7p778-dep-plan.json'), 'w'), indent=1)
    print('existing -M', len(have), collections.Counter(k[:2] for k in have))
    for p in plan:
        print(p['run'], p['src'], len(p['objects']), collections.Counter(o['key'][:2] for o in p['objects']))


def parse_dep(text):
    """NeXT cc -M output: 'target.o: dep dep \\' continuation lines; returns the dependency list (order kept)."""
    t = text.replace('\\\n', ' ')
    lines = [l for l in t.split('\n') if l.strip()]
    need(len(lines) == 1 and ':' in lines[0], 'unexpected -M output form')
    deps = lines[0].split(':', 1)[1].split()
    need(all(not d.startswith('/') for d in deps), 'absolute dependency path')
    return deps


def cmd_deps(planj, out):
    P = json.load(open(planj))
    objs = load_objects()
    res = {}
    for k, v in P['existing'].items():
        need(sha(v['dep']) == v['dep_sha256'], 'dep hash ' + k)
        res[k] = dict(src=v['dep'], deps=parse_dep(open(v['dep']).read()))
    for r in P['new_runs']:
        rd = '08_build/runs/' + r['run']
        st = dict(x.split() for x in open(rd + '/out/_log/status').read().splitlines())
        for o in r['objects']:
            n = '%02d' % o['index']
            need(st.get(n) == '0', 'status %s %s' % (r['run'], n))
            f = '%s/out/_log/%s.out' % (rd, n)
            res[o['key']] = dict(src=f, deps=parse_dep(open(f).read()))
    need(set(res) == set(objs), 'dependency set != objects')
    rec = dict(plan='778.12 P3a', tool_sha256=sha(os.path.abspath(__file__)), plan_json=planj, plan_json_sha256=sha(planj),
               objects={k: dict(src=v['src'], src_sha256=sha(v['src']), deps=v['deps']) for k, v in sorted(res.items())})
    json.dump(rec, open(out, 'w'), indent=1)
    print('objects', len(res), 'dependency entries', sum(len(v['deps']) for v in res.values()))


def dp_seq(W, order, defined, names, choice):
    """sequence produced when each original name is first mentioned exactly at its chosen position."""
    pos = dict(zip(names, choice))
    return [n for n in sorted(names, key=lambda n: (pos[n], n))]


if __name__ == '__main__':
    if len(sys.argv) == 3 and sys.argv[1] == 'spec':
        cmd_spec(sys.argv[2])
    elif len(sys.argv) == 3 and sys.argv[1] == 'common':
        cmd_common(sys.argv[2])
    elif len(sys.argv) == 3 and sys.argv[1] == 'depcmd':
        cmd_depcmd(sys.argv[2])
    elif len(sys.argv) == 4 and sys.argv[1] == 'deps':
        cmd_deps(sys.argv[2], sys.argv[3])
    else:
        die(__doc__)
