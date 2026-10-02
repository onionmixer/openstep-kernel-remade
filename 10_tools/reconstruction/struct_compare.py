#!/usr/bin/env python3
"""Compare C struct definitions across the three BSD header sources (plan 79, 79.1).

  struct_compare.py OUT.json

Sources (roots relative to the repository):
  S  real-machine OPENSTEP 4.2 SDK   01_resources/local_mirrors/headers/NextDeveloper/Headers/
  N  NeXTMach mk-108.1              01_resources/upstream/nextmach/mk-108.1/
  D  Darwin 0.1 kernel              01_resources/upstream/darwin01/kernel/

Mode: raw conditional text.  For each struct the body is taken from 'struct NAME {'
to its balanced closing brace (comments and string literals masked before brace
matching); comments are removed and whitespace is collapsed per line, blank lines
dropped.  Preprocessor lines inside the body are kept as text, i.e. no macro
profile is applied.  Equal text does not prove an equal ABI (typedefs, array
constants and embedded types may differ); layout decisions need original bytes.

Outcome per struct: all-equal, S=N!=D, S=D!=N, N=D!=S, all-different, or
missing / ambiguous (no or several definitions of that tag in a file).
"""
import hashlib, json, os, re, sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
ROOTS = {
    'S': '01_resources/local_mirrors/headers/NextDeveloper/Headers/',
    'N': '01_resources/upstream/nextmach/mk-108.1/',
    'D': '01_resources/upstream/darwin01/kernel/',
}
# struct -> {source: header path}; verified struct lines are in plan 79.1
TABLE = [
    ('ifnet', 'bsd/net/if.h', 'net/if.h', 'bsd/net/if.h'),
    ('ifaddr', 'bsd/net/if.h', 'net/if.h', 'bsd/net/if.h'),
    ('mbuf', 'bsd/sys/mbuf.h', 'sys/mbuf.h', 'bsd/sys/mbuf.h'),
    ('socket', 'bsd/sys/socketvar.h', 'sys/socketvar.h', 'bsd/sys/socketvar.h'),
    ('sockbuf', 'bsd/sys/socketvar.h', 'sys/socketvar.h', 'bsd/sys/socketvar.h'),
    ('proc', 'bsd/sys/proc.h', 'sys/proc.h', 'bsd/sys/proc.h'),
    ('ucred', 'bsd/sys/ucred.h', 'sys/ucred.h', 'bsd/sys/ucred.h'),
    ('file', 'bsd/sys/file.h', 'sys/file.h', 'bsd/sys/file.h'),
    ('vnode', 'bsd/sys/vnode.h', 'sys/vnode.h', 'bsd/sys/vnode.h'),
    ('uio', 'bsd/sys/uio.h', 'sys/uio.h', 'bsd/sys/uio.h'),
    ('timeval', 'bsd/sys/time.h', 'sys/time.h', 'bsd/sys/time.h'),
    ('rusage', 'bsd/sys/resource.h', 'sys/resource.h', 'bsd/sys/resource.h'),
    ('user', 'bsd/sys/user.h', 'sys/user.h', 'bsd/sys/user.h'),
]


def mask(text):
    """Copy of text with comments and string/char literals replaced by spaces
    (newlines kept), so braces inside them do not count."""
    out, i, n = [], 0, len(text)
    while i < n:
        c = text[i]
        if text.startswith('/*', i):
            j = text.find('*/', i + 2)
            j = n if j < 0 else j + 2
            out.append(re.sub(r'[^\n]', ' ', text[i:j])); i = j
        elif text.startswith('//', i):
            j = text.find('\n', i)
            j = n if j < 0 else j
            out.append(' ' * (j - i)); i = j
        elif c in '"\'':
            j = i + 1
            while j < n and text[j] != c and text[j] != '\n':
                j += 2 if text[j] == '\\' else 1
            j = min(j + 1, n)
            out.append(' ' * (j - i)); i = j
        else:
            out.append(c); i += 1
    return ''.join(out)


def definitions(text, name):
    """List of (start_line, end_line, body_text) for each 'struct name {'."""
    m = mask(text)
    defs = []
    for mm in re.finditer(r'\bstruct\s+%s\s*\{' % re.escape(name), m):
        depth, j = 0, mm.end() - 1
        while j < len(m):
            if m[j] == '{':
                depth += 1
            elif m[j] == '}':
                depth -= 1
                if depth == 0:
                    break
            j += 1
        if depth != 0:
            continue
        body = m[mm.end():j]
        lines = [' '.join(l.split()) for l in body.split('\n')]
        lines = [l for l in lines if l]
        defs.append((text.count('\n', 0, mm.start()) + 1, text.count('\n', 0, j) + 1, lines))
    return defs


def classify(b):
    s, n, d = b['S'], b['N'], b['D']
    if s == n == d:
        return 'all-equal'
    if s == n:
        return 'S=N!=D'
    if s == d:
        return 'S=D!=N'
    if n == d:
        return 'N=D!=S'
    return 'all-different'


def compare(name, paths):
    rec = dict(struct=name, sources={})
    bodies, problem = {}, None
    for k, rel in paths.items():
        p = os.path.join(REPO, ROOTS[k], rel)
        if not os.path.isfile(p):
            rec['sources'][k] = dict(path=ROOTS[k] + rel, missing_file=True)
            problem = problem or 'missing'
            continue
        raw = open(p, 'rb').read()
        defs = definitions(raw.decode('latin-1'), name)
        rec['sources'][k] = dict(path=ROOTS[k] + rel, sha256=hashlib.sha256(raw).hexdigest(),
                                 definitions=[dict(lines=[a, b], body_lines=len(body)) for a, b, body in defs])
        if not defs:
            problem = problem or 'missing'
        elif len(defs) > 1:
            problem = problem or 'ambiguous'
        else:
            bodies[k] = defs[0][2]
    rec['outcome'] = problem if problem else classify(bodies)
    return rec


def main():
    out = sys.argv[1]
    recs = [compare(t[0], dict(S=t[1], N=t[2], D=t[3])) for t in TABLE]
    res = dict(tool='struct_compare.py', tool_sha256=hashlib.sha256(open(os.path.abspath(__file__), 'rb').read()).hexdigest(),
               mode='raw conditional text (comments removed, whitespace collapsed, preprocessor lines kept)',
               note='source comparison only; not ABI or layout proof (plan 79.1)', roots=ROOTS, results=recs)
    json.dump(res, open(out, 'w'), indent=1)
    for r in recs:
        print('%-8s %s' % (r['struct'], r['outcome']))


if __name__ == '__main__':
    main()
