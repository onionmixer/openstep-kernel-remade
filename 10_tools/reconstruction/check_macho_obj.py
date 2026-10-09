#!/usr/bin/env python3
"""Cross-check macho_obj.py against llvm-objdump (independent implementation).

  check_macho_obj.py FILE.o...     exit 0 only if sections, symbols and
                                   relocations agree for every file

Compared: section name/segment/size/address; symbol name/value/scope/section
(or UND); relocation address/pcrel/length/extern/type/scattered and the
symbol, section or value it refers to.  Anything llvm-objdump prints that this
script cannot parse is a failure, not a skip.
"""
import os, re, subprocess, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj

LLVM = 'llvm-objdump-14'
LEN = {'byte': 0, 'word': 1, 'long': 2}
TYPES = macho_obj.RELOC_TYPES_I386


def llvm(args, path):
    r = subprocess.run([LLVM, '--macho'] + args + [path], capture_output=True, text=True)
    if r.returncode != 0 or r.stderr.strip():
        raise RuntimeError('llvm-objdump %s: %s' % (args, r.stderr.strip()))
    return r.stdout.splitlines()


def check(path):
    o = macho_obj.read(path)
    fails = []
    secs = o['sections']
    # sections
    rows = [l.split() for l in llvm(['-h'], path) if re.match(r'^\s+\d+ ', l)]
    if len(rows) != len(secs):
        fails.append('section count %d != llvm %d' % (len(secs), len(rows)))
    for s, r in zip(secs, rows):
        if (s['sectname'], s['size'], s['addr']) != (r[1], int(r[2], 16), int(r[3], 16)):
            fails.append('section %s: mine %s/%#x/%#x llvm %s' % (s['sectname'], s['sectname'], s['size'], s['addr'], r[1:4]))
    # symbols
    mine = set()
    for y in o['symbols']:
        if y['stab']:
            continue
        if y['kind'] == 'COMMON':
            mine.add((y['name'], y['value'], 'COM', True))     # n_value = size
            continue
        where = 'UND' if y['kind'] == 'UNDF' else ('ABS' if y['kind'] == 'ABS' else
                '%s,%s' % (secs[y['sect'] - 1]['segname'], secs[y['sect'] - 1]['sectname']))
        mine.add((y['name'], y['value'] if where != 'UND' else 0, where, y['ext'] or where == 'UND'))
    theirs = set()
    for l in llvm(['-t'], path):
        c = re.match(r'^([0-9a-f]{8})\s+\*COM\*\s+[0-9a-f]{8} (.+)$', l)
        if c:                                          # common: first column is n_value (the size)
            theirs.add((c.group(2), int(c.group(1), 16), 'COM', True))
            continue
        m = re.match(r'^([0-9a-f]{8}) (.{7}) (\S+)\s+(.+)$', l)
        if not m:
            if l.strip() and not l.endswith(':') and l.strip() != 'SYMBOL TABLE:':
                fails.append('unparsed symbol line %r' % l)
            continue
        val, flags, sect, name = m.groups()
        where = 'UND' if sect == '*UND*' else ('ABS' if sect == '*ABS*' else sect)
        theirs.add((name, int(val, 16), where, 'g' in flags or where == 'UND'))
    if mine != theirs:
        fails.append('symbols differ: only mine %s only llvm %s' % (sorted(mine - theirs)[:4], sorted(theirs - mine)[:4]))
    # relocations
    blocks, cur = {}, None
    for l in llvm(['-r'], path):
        m = re.match(r'^Relocation information \((\S+)\) (\d+) entries', l)
        if m:
            cur = m.group(1); blocks[cur] = []; continue
        if cur and re.match(r'^[0-9a-f]{8} ', l):
            blocks[cur].append(l)
        elif cur and re.match(r'^\s+(True|False)\s+\S+\s+n/a\s+PAIR\s+True\s+0x[0-9a-f]+$', l):
            blocks[cur].append('PAIR ' + l.strip())     # PAIR rows print no address
        elif cur and l.strip() and not l.startswith('address'):
            fails.append('unparsed reloc line %r' % l)
    for s in secs:
        key = '%s,%s' % (s['segname'], s['sectname'])
        got = blocks.get(key, [])
        if len(got) != len(s['relocs']):
            fails.append('%s: %d relocs, llvm %d' % (key, len(s['relocs']), len(got)))
            continue
        for rel, line in zip(s['relocs'], got):
            if line.startswith('PAIR '):            # i386 only (other CPUs print PAIR as a normal row)
                f = line.split()
                ok = (rel['scattered'] and TYPES.get(rel['type']) == 'PAIR' and (f[1] == 'True') == rel['pcrel']
                      and LEN.get(f[2]) == rel['length'] and int(f[6], 16) == rel['value'])
                if not ok:
                    fails.append('%s PAIR mismatch: mine %s llvm %r' % (key, rel, line))
                continue
            f = line.split()
            addr, pcrel, length, ext, typ, scat = f[:6]
            ref = ' '.join(f[6:])
            # plan 411: llvm-objdump names only the i386 types; it prints m68k/SPARC types as numbers
            exp_type = TYPES.get(rel['type'], str(rel['type'])) if o['cputype'] == macho_obj.CPU_I386 else str(rel['type'])
            ok = (int(addr, 16) == rel['address'] and (pcrel == 'True') == rel['pcrel'] and
                  LEN.get(length) == rel['length'] and typ == exp_type[:7] and (scat == 'True') == rel['scattered'])  # llvm prints 7 chars
            if rel['scattered']:
                ok = ok and int(ref.split()[0], 16) == rel['value']
            else:
                ok = ok and (ext == 'True') == rel['extern']
                if rel['extern']:
                    ok = ok and ref == o['symbols'][rel['symbolnum']]['name']
                else:
                    sec = secs[rel['symbolnum'] - 1] if 0 < rel['symbolnum'] <= len(secs) else None
                    ok = ok and sec is not None and ref == '%d (%s,%s)' % (rel['symbolnum'], sec['segname'], sec['sectname'])
            if not ok:
                fails.append('%s reloc mismatch: mine %s llvm %r' % (key, rel, line))
    for key in blocks:
        if key not in ['%s,%s' % (s['segname'], s['sectname']) for s in secs]:
            fails.append('llvm reloc block for unknown section %s' % key)
    return o, fails


if __name__ == '__main__':
    bad = 0
    for p in sys.argv[1:]:
        o, fails = check(p)
        nrel = sum(len(s['relocs']) for s in o['sections'])
        nscat = sum(1 for s in o['sections'] for r in s['relocs'] if r['scattered'])
        print('%-60s sections %2d symbols %3d relocs %3d (scattered %d): %s' % (
            p, len(o['sections']), len(o['symbols']), nrel, nscat, 'AGREE' if not fails else 'DIFF'))
        for f in fails:
            print('   ', f)
        bad += bool(fails)
    sys.exit(1 if bad else 0)
