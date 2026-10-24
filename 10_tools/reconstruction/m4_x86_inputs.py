#!/usr/bin/env python3
"""m4_x86_inputs.py -- plan 497 (M4-3): check that the x86 rebuild inputs other than the stages are
unchanged since a full rebuild prefix (the stages themselves are checked by stage_m68k.py x86gate).

  L2_FORMS=... L2_EXPECT=... python3 10_tools/reconstruction/m4_x86_inputs.py PREFIX RECORD.json

Per group (G1 G2a G2b G3 G4 G5 G6 -> g1a g2aa g2ba g3a g4a g5a g6a): the forms table named in
09_validation/reconstruction/s6-l1-<G>-<PREFIX>-<g>.json and its SHA-256 equal the current
L2_FORMS file; the command file regenerated with l2_rebuild.py (select_rows, lines_for, the same
body as cmd_prepare) equals 08_build/runs/tools/<PREFIX>-<g>.cmd after the run ID; the source list
(logical_source + companions) equals the stage manifest's sources.  Exit 1 on any difference.
Read-only apart from RECORD.json.
"""
import sys, os, json, hashlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import l2_rebuild as R

PAIRS = [('G1', 'g1a'), ('G2a', 'g2aa'), ('G2b', 'g2ba'), ('G3', 'g3a'), ('G4', 'g4a'), ('G5', 'g5a'), ('G6', 'g6a')]


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def main(prefix, outj):
    rows, ok = [], True
    for G, g in PAIRS:
        rid = '%s-%s' % (prefix, g)
        rec = json.load(open('09_validation/reconstruction/s6-l1-%s-%s.json' % (G, rid)))
        rs = R.select_rows(G, rid)
        body = ['# %s: plan 394 (D057) rebuild of group %s from 07 (%d objects; l2_rebuild.py)' % (rid, G, len(rs))]
        if G == 'G3':
            body.append('ABSROOT')
        names = set()
        for r in rs:
            ls, obj = R.lines_for(r)
            names.add(obj)
            body += ls
        body += ['EXPECT %s' % o for o in sorted(names)]
        cmd_now = '\n'.join(body) + '\n'
        cmd_run = open(R.T + rid + '.cmd').read()
        srcs = []
        for r in rs:
            for s in [R.logical_source(r)] + R.companions(r):
                if s not in srcs:
                    srcs.append(s)
        man = json.load(open(R.T + rid + '-stage.manifest.json'))
        row = dict(group=G, run=rid, forms=rec['forms'], forms_same=os.path.abspath(rec['forms']) == os.path.abspath(R.FORMS),
                   forms_sha256_same=rec['forms_sha256'] == sha(R.FORMS), command_same=cmd_now == cmd_run,
                   command_sha256=sha(R.T + rid + '.cmd'), sources_same=srcs == man['sources'], objects=len(rs))
        row['ok'] = row['forms_same'] and row['forms_sha256_same'] and row['command_same'] and row['sources_same']
        ok &= row['ok']
        rows.append(row)
    out = dict(plan=497, tool='10_tools/reconstruction/m4_x86_inputs.py', tool_sha256=sha(os.path.abspath(__file__)),
               l2_rebuild_sha256=sha('10_tools/reconstruction/l2_rebuild.py'), forms=R.FORMS, forms_sha256=sha(R.FORMS),
               expect=os.environ.get('L2_EXPECT'), expect_sha256=sha(os.environ['L2_EXPECT']) if os.environ.get('L2_EXPECT') else None,
               prefix=prefix, groups=rows, ok=ok)
    json.dump(out, open(outj, 'w'), indent=1)
    for r in rows:
        print(r['group'], r['run'], 'forms', r['forms_same'], r['forms_sha256_same'], 'cmd', r['command_same'], 'sources', r['sources_same'], r['objects'])
    print('ok', ok)
    sys.exit(0 if ok else 1)


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
