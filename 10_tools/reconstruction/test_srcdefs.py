#!/usr/bin/env python3
"""Regression test for srcdefs.find (plan 27 / 27.1).

  test_srcdefs.py [--report FILE]

Compares the current parser on all .c/.m files of the reference trees with the
pre-27.1 baseline (09_validation/reconstruction/s2d-srcdefs-baseline-20261001.tsv):
  T1  the five NeXTMach conditional-header definitions are found
  T2  every baseline definition is still found unchanged, except the listed
      range corrections (body previously ended at a macro's closing brace)
  T3  added definitions are listed in the report
  T4  no added definition's header ends in ';' (prototype)
"""
import json, os, sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import srcdefs

REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
UP = os.path.join(REPO, '01_resources', 'upstream')
ROOTS = ('darwin01/kernel', 'darwin01/driverkit-1', 'nextmach', 'mach4')
BASE = os.path.join(REPO, '09_validation/reconstruction/s2d-srcdefs-baseline-20261001.tsv')
TARGETS = {('nextmach/mk-108.1/netinet/if_ether.c', 'arpwhohas'), ('nextmach/mk-108.1/netinet/if_ether.c', 'arpresolve'),
           ('nextmach/mk-108.1/netinet/if_ether.c', 'arpinput'), ('nextmach/mk-108.1/netinet/if_ether.c', 'in_arpinput'),
           ('nextmach/mk-108.1/bsd/vfs_bio.c', 'bflush')}
# baseline tuple -> corrected tuple (old end was the '}' of a backslash-continued #define)
CORRECTED = {
    ('darwin01/kernel/vm/vm_fault.c', 'vm_fault_wire_fast', 1378, 1399): ('darwin01/kernel/vm/vm_fault.c', 'vm_fault_wire_fast', 1378, 1538),
    ('mach4/kernel/vm/vm_fault.c', 'vm_fault_wire_fast', 1657, 1678): ('mach4/kernel/vm/vm_fault.c', 'vm_fault_wire_fast', 1657, 1797),
    ('nextmach/mk-108.1/vm/vm_fault.c', 'vm_fault', 85, 124): ('nextmach/mk-108.1/vm/vm_fault.c', 'vm_fault', 85, 1186),
    ('nextmach/mk-108.1/vm/vm_fault.c', 'vm_fault_wire_fast', 1394, 1415): ('nextmach/mk-108.1/vm/vm_fault.c', 'vm_fault_wire_fast', 1394, 1547),
}


def current():
    out, heads = set(), {}
    for r in ROOTS:
        for dp, dn, fn in os.walk(os.path.join(UP, r)):
            dn.sort()
            if '/.git' in dp or '/CVS' in dp:
                continue
            for f in sorted(fn):
                if f.endswith(('.c', '.m')):
                    p = os.path.join(dp, f)
                    lines = open(p, errors='replace').read().splitlines()
                    for name, a, b, h in srcdefs.find(lines):
                        t = (os.path.relpath(p, UP), name, a + 1, b + 1)
                        out.add(t)
                        heads[t] = h
    return out, heads


def main():
    base = set()
    for l in open(BASE):
        if l.startswith('#') or l.startswith('path\t'):
            continue
        p, n, a, b = l.rstrip('\n').split('\t')
        base.add((p, n, int(a), int(b)))
    cur, heads = current()
    res, fails = [], []

    def check(name, ok, **info):
        res.append(dict(test=name, ok=bool(ok), **info))
        if not ok:
            fails.append(name)
    found = {(t[0], t[1]) for t in cur}
    check('T1 conditional-header targets', TARGETS <= found, missing=sorted(TARGETS - found))
    lost = sorted(base - cur - set(CORRECTED))
    bad_corr = sorted(k for k, v in CORRECTED.items() if k in cur or v not in cur)
    check('T2 baseline preserved', not lost and not bad_corr, lost=lost[:20], lost_count=len(lost), bad_corrections=bad_corr)
    added = sorted(cur - base - set(CORRECTED.values()))
    check('T3 added listed', True, added_count=len(added), added=['%s:%d-%d %s' % (t[0], t[2], t[3], t[1]) for t in added])
    proto = [t for t in added if heads[t].rstrip().endswith(';')]
    check('T4 no prototypes added', not proto, prototypes=proto)
    rep = dict(baseline=len(base), current=len(cur), tests=len(res), failed=fails, results=res)
    if '--report' in sys.argv:
        json.dump(rep, open(sys.argv[sys.argv.index('--report') + 1], 'w'), indent=1)
    for x in res:
        print('%-4s %s' % ('ok' if x['ok'] else 'FAIL', x['test']))
    print('baseline %d, current %d, added %d; %d tests, %d failed' % (len(base), len(cur), len(added), len(res), len(fails)))
    sys.exit(1 if fails else 0)


if __name__ == '__main__':
    main()
