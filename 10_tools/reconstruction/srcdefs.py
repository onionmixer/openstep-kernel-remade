#!/usr/bin/env python3
"""Shared C function-definition finder for reference source text (S2-A / S2-B).

A definition starts on a line beginning in column 0 with an identifier, an
optional return type on the same line, then NAME ( ... ).  Lines are joined
until the parentheses balance; if that point is followed by ';' it is a
prototype.  Otherwise it is a definition only if '{' follows after nothing
but blank lines, comments and K&R parameter declarations (lines ending in ';'
without '(' ), within 40 lines.  The body ends at the first line that is
exactly '}'.  Text only: no preprocessing (plan 16.1 explains the limits).

Plan 27.1 (variants A+B): preprocessor directive lines between the closing
parenthesis and '{' are ignored, and directive lines with their backslash
continuations never end a body.  Known limits: a function whose closing brace
is not in column 0 runs into the next one; files are split with splitlines().

  srcdefs.py FILE      list the definitions found
"""
import re, sys

KEYWORDS = {'if', 'while', 'for', 'switch', 'return', 'sizeof', 'do', 'else', 'case', 'defined', 'typedef'}
HEAD = re.compile(r'^(?:[A-Za-z_][\w\s\*]*?[\s\*])?([A-Za-z_]\w*)\s*\(')


def find(lines):
    """Yield (name, start_index, body_end_index, header_text)."""
    i = 0
    n = len(lines)
    while i < n:
        l = lines[i]
        if not l or l[0] in ' \t#/*{}' or '=' in l.split('(')[0]:
            i += 1
            continue
        m = HEAD.match(l)
        if not m or m.group(1) in KEYWORDS:
            i += 1
            continue
        # balance parentheses from the name's '('
        depth, j, pos, closed = 0, i, m.end() - 1, None
        while j < n and j < i + 30:
            s = lines[j] if j > i else l
            start = pos if j == i else 0
            for c in range(start, len(s)):
                if s[c] == '(':
                    depth += 1
                elif s[c] == ')':
                    depth -= 1
                    if depth == 0:
                        closed = (j, c)
                        break
            if closed:
                break
            j += 1
        if not closed:
            i += 1
            continue
        cj, cc = closed
        rest = lines[cj][cc + 1:].strip()
        if rest.startswith(';') or rest.startswith(','):
            i = cj + 1
            continue
        # code after the closing parenthesis up to '{', comments removed
        k = None
        code, incom = '', False
        for t in range(cj, min(n, cj + 40)):
            s0 = lines[t][cc + 1:] if t == cj else lines[t]
            if t != cj and re.match(r'\s*#', s0):
                continue
            q, x = '', 0
            while x < len(s0):
                if incom:
                    e2 = s0.find('*/', x)
                    if e2 < 0:
                        x = len(s0)
                    else:
                        incom, x = False, e2 + 2
                elif s0.startswith('/*', x):
                    incom, x = True, x + 2
                elif s0.startswith('//', x):
                    break
                else:
                    q += s0[x]
                    x += 1
            if '{' in q:
                code += q[:q.index('{')]
                k = t
                break
            code += ' ' + q
        if k is not None:
            pieces = [p.strip() for p in code.split(';')]
            if pieces and pieces[-1]:
                k = None                                  # text before '{' that is not a declaration
            elif any('(' in p and not re.search(r'\(\s*\*', p) for p in pieces[:-1]):
                k = None
        if k is None:
            i = cj + 1
            continue
        e, cont = None, False
        for t in range(k, min(n, k + 5000)):
            d = cont or bool(re.match(r'\s*#', lines[t]))
            cont = d and lines[t].rstrip().endswith('\\')
            if not d and lines[t].rstrip() == '}':
                e = t
                break
        if e is None:
            i = cj + 1
            continue
        yield m.group(1), i, e, '\n'.join(lines[i:cj + 1])
        i = e + 1


if __name__ == '__main__':
    lines = open(sys.argv[1], errors='replace').read().splitlines()
    for name, a, b, h in find(lines):
        print('%5d-%-5d %s' % (a + 1, b + 1, name))
