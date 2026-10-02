#!/usr/bin/env python3
"""Undefined identifiers reached by preprocessor conditionals (plan 23.2).

  undef_conditionals.py RUN_DIR FILE.i MACROS.out [--json OUT.json]

FILE.i gives the files the preprocessor read (line markers); MACROS.out is
the '-E -dM' dump of the same compilation.  For every #if/#elif in a read
file, each identifier is checked; when it is a macro, the identifiers of its
definition are followed transitively (function-like parameters excluded).
An identifier that is neither defined nor 'defined' is reported with the
chain that reached it, e.g. MACH_SLOCKS -> DRIVERKIT.  This catches what a
literal-only scan misses (plan 23.2: kern/lock.h MACH_SLOCKS).
"""
import json, os, re, sys

IDENT = re.compile(r'[A-Za-z_]\w*')


def strip_comments(t):
    return re.sub(r'/\*.*?\*/', lambda m: '\n' * m.group(0).count('\n') + ' ', t, flags=re.S)


def macros(path):
    out = {}
    for l in open(path, errors='replace'):
        m = re.match(r'#define\s+([A-Za-z_]\w*)(\(([^)]*)\))?\s?(.*)$', l.rstrip('\n'))
        if m:
            params = set(p.strip() for p in m.group(3).split(',')) if m.group(2) else set()
            out[m.group(1)] = (params, m.group(4))
    return out


def chase(name, defs, seen=()):
    """Yield chains (tuple of names) ending in an undefined identifier."""
    if name == 'defined' or name in seen:
        return
    if name not in defs:
        yield seen + (name,)
        return
    params, body = defs[name]
    for idn in IDENT.findall(re.sub(r'"(?:[^"\\]|\\.)*"', '', body)):
        if idn not in params:
            yield from chase(idn, defs, seen + (name,))


def main():
    run, ipath, mpath = sys.argv[1:4]
    defs = macros(mpath)
    read = sorted(set(re.findall(r'^# \d+ "([^"]+)"', open(ipath, errors='replace').read(), re.M)))
    found = {}
    for f in read:
        p = os.path.join(run, f)
        lines = strip_comments(open(p, errors='replace').read()).split('\n')
        for n, l in enumerate(lines):
            m = re.match(r'\s*#\s*(if|elif|ifdef|ifndef)\b(.*)', l)
            if not m:
                continue
            expr = m.group(2)
            # identifiers inside defined(X) / defined X are tests of definedness, not values
            tested = set(re.findall(r'defined\s*\(?\s*([A-Za-z_]\w*)', expr))
            if m.group(1) in ('ifdef', 'ifndef'):
                continue
            for idn in IDENT.findall(expr):
                if idn in tested:
                    continue
                for chain in chase(idn, defs):
                    key = chain[-1]
                    found.setdefault(key, {}).setdefault(' -> '.join(chain), []).append('%s:%d' % (f, n + 1))
    rep = {k: {c: sorted(set(v)) for c, v in d.items()} for k, d in sorted(found.items())}
    if '--json' in sys.argv:
        json.dump(dict(run=run, read=len(read), macros=len(defs), undefined=rep),
                  open(sys.argv[sys.argv.index('--json') + 1], 'w'), indent=1)
    for k, d in rep.items():
        for c, v in d.items():
            print('%-28s %-40s %3d  %s' % (k, c, len(v), v[0]))


if __name__ == '__main__':
    main()
