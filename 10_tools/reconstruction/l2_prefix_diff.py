#!/usr/bin/env python3
"""l2_prefix_diff.py -- plan 466 (M5-23, D082): compare two full x86 rebuilds (l2_rebuild.py
results of the seven groups under two RID prefixes, e.g. s6l4 and s6l5).

  python3 10_tools/reconstruction/l2_prefix_diff.py OLD NEW RECORD.json

stages   per group RID suffix (g1a g2aa g2ba g3a g4a g5a g6a): the two stage manifests
         (08_build/runs/tools/<prefix>-<g>-stage.manifest.json), every key and every
         [path, origin, sha256] entry; the two command files with the RID replaced.
objects  the records 09_validation/reconstruction/s6-l1-*-<prefix>-*.json (exactly seven per
         prefix, rows 1..N contiguous, object SHA-256 checked); per row the object SHA-256; for
         rows whose SHA differs: non-STABS sections (m3_m68k_diag.canon: section bytes and
         relocations, external symbols by name), section headers (name, size, align, flags),
         non-STABS symbols (name, kind, ext, sect, value) and the Mach-O header fields; and whether
         the new object equals the old one after replacing the run path '/08_build/runs/<new>-'
         by '/08_build/runs/<old>-' (headers' inline STABS carry the real-machine absolute run
         path; plan 466.5, D083).
"""
import sys, os, json, glob, hashlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m3_m68k_diag as D

T = '08_build/runs/tools/'
V = '09_validation/reconstruction/'
GROUPS = ['g1a', 'g2aa', 'g2ba', 'g3a', 'g4a', 'g5a', 'g6a']


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def rows(prefix):
    recs = sorted(glob.glob(V + 's6-l1-*-%s-*.json' % prefix))
    assert len(recs) == 7, (prefix, recs)
    out = {}
    for f in recs:
        for x in json.load(open(f))['objects']:
            assert x['n'] not in out, x['n']
            assert sha(x['obj']) == x['obj_sha256'], x['obj']
            out[x['n']] = x
    assert sorted(out) == list(range(1, len(out) + 1))
    return recs, out


def obj_sig(p):
    o = macho_obj.parse(open(p, 'rb').read())
    return dict(header=[o[k] for k in ('cputype', 'cpusubtype', 'filetype', 'flags')],
                sections=[[s['segname'], s['sectname'], s['size'], s.get('align'), s.get('flags')] for s in o['sections']],
                symbols=[[y['name'], y['kind'], y.get('ext'), y.get('sect'), y.get('value')] for y in o['symbols'] if not y['stab']],
                stabs=sum(1 for y in o['symbols'] if y['stab']))


def main():
    if len(sys.argv) != 4:
        sys.exit(__doc__)
    old, new, outj = sys.argv[1:]
    st = []
    for g in GROUPS:
        a = json.load(open(T + '%s-%s-stage.manifest.json' % (old, g)))
        b = json.load(open(T + '%s-%s-stage.manifest.json' % (new, g)))
        fa = {e[0]: e for e in a['files']}
        fb = {e[0]: e for e in b['files']}
        ca = open(T + '%s-%s.cmd' % (old, g)).read().replace('%s-%s' % (old, g), 'RID')
        cb = open(T + '%s-%s.cmd' % (new, g)).read().replace('%s-%s' % (new, g), 'RID')
        st.append(dict(group=g, keys_differ=sorted(k for k in set(a) | set(b) if k != 'files' and a.get(k) != b.get(k)),
                       files=[len(fa), len(fb)], files_differ=sorted(p for p in set(fa) | set(fb) if fa.get(p) != fb.get(p)),
                       cmd_same=ca == cb))
    ra, A = rows(old)
    rb, B = rows(new)
    assert sorted(A) == sorted(B)
    diff = []
    for n in sorted(A):
        x, y = A[n], B[n]
        assert x['source'] == y['source'] and x['object'] == y['object'], n
        if x['obj_sha256'] == y['obj_sha256']:
            continue
        sx, sy = obj_sig(x['obj']), obj_sig(y['obj'])
        diff.append(dict(n=n, object=x['object'], source=x['source'], old=x['obj'], old_sha256=x['obj_sha256'],
                         new=y['obj'], new_sha256=y['obj_sha256'], canon_equal=D.canon(x['obj']) == D.canon(y['obj']),
                         header_equal=sx['header'] == sy['header'], sections_equal=sx['sections'] == sy['sections'],
                         symbols_equal=sx['symbols'] == sy['symbols'], stabs=[sx['stabs'], sy['stabs']],
                         run_path_count=open(y['obj'], 'rb').read().count(('/08_build/runs/%s-' % new).encode()),
                         rid_normalized_equal=open(y['obj'], 'rb').read().replace(('/08_build/runs/%s-' % new).encode(),
                                                                                  ('/08_build/runs/%s-' % old).encode())
                         == open(x['obj'], 'rb').read()))
    S = dict(stage_files_differ=sorted({p for s in st for p in s['files_differ']}),
             stage_keys_differ=[s['group'] for s in st if s['keys_differ']], cmd_differ=[s['group'] for s in st if not s['cmd_same']],
             objects=len(A), objects_sha_differ=[d['object'] for d in diff],
             differing_non_stabs_equal=all(d['canon_equal'] and d['header_equal'] and d['sections_equal'] and d['symbols_equal']
                                           for d in diff),
             sha_differ_not_rid_only=[d['object'] for d in diff if not d['rid_normalized_equal']])
    json.dump(dict(plan=466, tool='10_tools/reconstruction/l2_prefix_diff.py', tool_sha256=sha(os.path.abspath(__file__)),
                   old=old, new=new, records=dict(old=[[f, sha(f)] for f in ra], new=[[f, sha(f)] for f in rb]),
                   summary=S, stages=st, objects_differ=diff), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))


if __name__ == '__main__':
    main()
