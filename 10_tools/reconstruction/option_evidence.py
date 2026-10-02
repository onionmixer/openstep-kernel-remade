#!/usr/bin/env python3
"""Configuration-option evidence from reference source vs the original kernel
(plan section 22 / 22.1).  Analysis only: the output is candidate evidence for
a hypothesis, never a confirmed option value.

  option_evidence.py OUT.tsv REPORT.json [--options OPT,OPT,...]

Without --options the S4-A1 set below is used (plan 22); S4-A2 passes its own list (plan 23).

For each option the Darwin 0.1 kernel tree is scanned with a conditional stack
(comments removed).  A block whose directive is a single option condition
(#if OPT, #ifdef OPT, #if !OPT, #ifndef OPT, #if NCPUS > 1, #if NCPUS == 1,
their #else) implies a fact (OPT, value); a '&&' condition implies its simple
conjuncts only in its #if branch.  '#if 0' / '#ifdef notdef' code is dead.

Candidates (22.1 design 1):
  function  an external definition (srcdefs) lying wholly inside one block
  string    a string literal inside a block
A candidate counts for (OPT, value) only if every occurrence of the same
function name (definitions, '#define NAME') or the same literal anywhere in
the tree carries that fact.  The original is then checked: '_NAME' as an
external symbol, the literal as a NUL-bounded string.
"""
import collections, csv, json, os, re, sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import srcdefs

REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
TREE = os.path.join(REPO, '01_resources', 'upstream', 'darwin01', 'kernel')
ORIG = os.path.join(REPO, '03_original', 'x86', 'binaries', 'mach_kernel')
SYMS = os.path.join(REPO, '03_original', 'x86', 'inventory', 'symbols.tsv')
OPTIONS = ('MACH_ASSERT', 'MACH_FIXPRI', 'SIMPLE_CLOCK', 'STAT_TIME', 'NCPUS')
EXTS = ('.c', '.m', '.h')
STRING = re.compile(r'"((?:[^"\\\n]|\\.)*)"')
ESC = {'n': '\n', 't': '\t', 'r': '\r', '0': '\0', '\\': '\\', '"': '"', "'": "'", 'b': '\b', 'f': '\f'}


def strip_comments(text):
    """Remove /* */ and // comments, keep newlines and string literals."""
    out, i, n = [], 0, len(text)
    while i < n:
        c = text[i]
        if c == '"' or c == "'":
            j = i + 1
            while j < n and text[j] != c and text[j] != '\n':
                j += 2 if text[j] == '\\' else 1
            out.append(text[i:j + 1])
            i = j + 1
        elif text.startswith('/*', i):
            e = text.find('*/', i + 2)
            e = n if e < 0 else e + 2
            out.append(''.join(ch for ch in text[i:e] if ch == '\n'))
            i = e
        elif text.startswith('//', i):
            e = text.find('\n', i)
            i = n if e < 0 else e
        else:
            out.append(c)
            i += 1
    return ''.join(out)


def simple_fact(cond):
    """(option, value) for a single option condition, else None."""
    c = cond.strip()
    while c.startswith('(') and c.endswith(')'):
        c = c[1:-1].strip()
    for o in OPTIONS:
        if o == 'NCPUS':
            if re.fullmatch(r'NCPUS\s*>\s*1', c):
                return ('NCPUS', '>1')
            if re.fullmatch(r'NCPUS\s*==\s*1', c) or re.fullmatch(r'NCPUS\s*<=\s*1', c):
                return ('NCPUS', '1')
            continue
        if re.fullmatch(o, c) or re.fullmatch(r'defined\s*\(?\s*%s\s*\)?' % o, c):
            return (o, '1')
        if re.fullmatch(r'!\s*' + o, c) or re.fullmatch(r'!\s*defined\s*\(?\s*%s\s*\)?' % o, c):
            return (o, '0')
    return None


def invert(f):
    o, v = f
    if o == 'NCPUS':
        return (o, '1' if v == '>1' else '>1')
    return (o, '0' if v == '1' else '1')


def scan(path):
    """Per line: (dead, facts) where facts = frozenset of (block id, option, value)."""
    lines = strip_comments(open(path, errors='replace').read()).split('\n')
    stack, per_line, bid = [], [], 0
    # stack entries: dict(id, if_facts, else_facts, dead_if, branch)
    for l in lines:
        m = re.match(r'\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b(.*)', l)
        if m:
            d, rest = m.group(1), m.group(2).strip()
            if d in ('if', 'ifdef', 'ifndef'):
                bid += 1
                cond = rest if d == 'if' else ('!' + rest if d == 'ifndef' else rest)
                if d == 'ifdef':
                    cond = rest
                f = simple_fact(cond)
                iff, elf = [], []
                if f:
                    iff, elf = [f], [invert(f)]
                elif '&&' in cond and '||' not in cond:
                    iff = [x for x in (simple_fact(p) for p in cond.split('&&')) if x]
                dead = cond.strip() in ('0', 'notdef') or (d == 'ifdef' and rest == 'notdef')
                stack.append(dict(id=bid, if_facts=iff, else_facts=elf, dead_if=dead, branch='if'))
            elif d == 'elif' and stack:
                stack[-1].update(branch='elif', if_facts=[], else_facts=[], dead_if=False)
            elif d == 'else' and stack:
                stack[-1]['branch'] = 'else' if stack[-1]['branch'] == 'if' else 'elif'
            elif d == 'endif' and stack:
                stack.pop()
            per_line.append((True, frozenset()))      # directive lines are not code
            continue
        dead = any(s['dead_if'] and s['branch'] == 'if' for s in stack)
        facts = set()
        for s in stack:
            fs = s['if_facts'] if s['branch'] == 'if' else (s['else_facts'] if s['branch'] == 'else' else [])
            for o, v in fs:
                facts.add((s['id'], o, v))
        per_line.append((dead, frozenset(facts)))
    return lines, per_line


def unescape(s):
    out, i = [], 0
    while i < len(s):
        if s[i] == '\\' and i + 1 < len(s):
            c = s[i + 1]
            if c in ESC:
                out.append(ESC[c]); i += 2
            elif c in '01234567':
                j = i + 1
                while j < len(s) and j < i + 4 and s[j] in '01234567':
                    j += 1
                out.append(chr(int(s[i + 1:j], 8))); i = j
            else:
                out.append(c); i += 2
        else:
            out.append(s[i]); i += 1
    return ''.join(out)


def main():
    global OPTIONS
    out_tsv, out_json = sys.argv[1:3]
    if '--options' in sys.argv:
        OPTIONS = tuple(sys.argv[sys.argv.index('--options') + 1].split(','))
    funcs = collections.defaultdict(list)     # name -> [(rel, line, facts or None(dead), wholly-in facts)]
    strs = collections.defaultdict(list)      # literal -> [(rel, line, facts, dead)]
    defines = collections.defaultdict(list)   # name -> [(rel, line)]
    nfiles = 0
    for dp, dn, fn in os.walk(TREE):
        for f in sorted(fn):
            if not f.endswith(EXTS):
                continue
            p = os.path.join(dp, f)
            rel = os.path.relpath(p, TREE)
            nfiles += 1
            lines, per = scan(p)
            for i, l in enumerate(lines):
                m = re.match(r'\s*#\s*define\s+([A-Za-z_]\w*)', l)
                if m:
                    defines[m.group(1)].append((rel, i + 1))
                if per[i][0] and not re.match(r'\s*#', l):
                    dead = True
                else:
                    dead = per[i][0]
                if re.match(r'\s*#\s*(include|import)', l):
                    continue
                for s in STRING.findall(l):
                    strs[s].append((rel, i + 1, per[i][1], dead))
            for name, a, b, h in srcdefs.find(lines):
                common = per[a][1]
                for k in range(a, b + 1):
                    common = common & per[k][1] if not per[k][0] or not re.match(r'\s*#', lines[k]) else common
                funcs[name].append((rel, a + 1, per[a][1], per[a][0], common))
    syms = {}
    for r in csv.DictReader(open(SYMS), delimiter='\t'):
        if r['type'] == '0xf':
            syms[r['name']] = r['value']
    img = open(ORIG, 'rb').read()

    def str_hits(lit):
        b = unescape(lit).encode('latin1', 'replace')
        if not b:
            return []
        pat = b'\0' + b + b'\0'
        hits, k = [], img.find(pat)
        while k >= 0 and len(hits) < 5:
            hits.append(hex(k + 1)); k = img.find(pat, k + 1)
        return hits

    rows = []
    stats = collections.Counter()
    for name, occ in funcs.items():
        for rel, line, facts, dead, common in occ:
            for (bid, o, v) in common:
                stats['function_in_block'] += 1
                others = [x for x in occ if (o, v) not in {(ff[1], ff[2]) for ff in x[4]}]
                reason = ''
                if others:
                    reason = 'also defined outside branch: ' + ';'.join('%s:%d' % (x[0], x[1]) for x in others[:3])
                elif name in defines:
                    reason = 'name also #defined: ' + ';'.join('%s:%d' % d for d in defines[name][:3])
                elif dead:
                    reason = 'dead code'
                rows.append(dict(option=o, value=v, kind='function', item=name, source='%s:%d' % (rel, line),
                                 usable='no' if reason else 'yes', reason=reason,
                                 original=syms.get('_' + name, '')))
    for lit, occ in strs.items():
        if len(unescape(lit)) < 4:
            continue
        for rel, line, facts, dead in occ:
            for (bid, o, v) in facts:
                stats['string_in_block'] += 1
                others = [x for x in occ if (o, v) not in {(ff[1], ff[2]) for ff in x[2]}]
                reason = ''
                if others:
                    reason = 'also used outside branch: ' + ';'.join('%s:%d' % (x[0], x[1]) for x in others[:3])
                elif dead:
                    reason = 'dead code'
                rows.append(dict(option=o, value=v, kind='string', item=lit, source='%s:%d' % (rel, line),
                                 usable='no' if reason else 'yes', reason=reason,
                                 original=','.join(str_hits(lit))))
    rows.sort(key=lambda r: (r['option'], r['value'], r['kind'], r['item'], r['source']))
    cols = ['option', 'value', 'kind', 'item', 'source', 'usable', 'reason', 'original']
    with open(out_tsv, 'w') as o:
        o.write('\t'.join(cols) + '\n')
        for r in rows:
            o.write('\t'.join(str(r[c]).replace('\\', '\\\\').replace('\t', '\\t').replace('\n', '\\n') for c in cols) + '\n')
    summary = collections.defaultdict(lambda: collections.Counter())
    for r in rows:
        if r['usable'] == 'yes':
            summary['%s=%s' % (r['option'], r['value'])]['present' if r['original'] else 'absent'] += 1
    rep = dict(files=nfiles, stats=dict(stats), usable_evidence={k: dict(v) for k, v in sorted(summary.items())})
    json.dump(rep, open(out_json, 'w'), indent=1)
    print(json.dumps(rep, indent=1))


if __name__ == '__main__':
    main()
