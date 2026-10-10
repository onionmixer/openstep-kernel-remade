#!/usr/bin/env python3
"""m3_m68k_gdb.py -- plan 427 (M3-3): test the m68k configuration hypothesis GDB 1.  Test stage =
plan 426 stage with generated/gdb.h "#define GDB 1"; the 46 V10 objects are recompiled and compared
with the plan 426 run (plan 427.1).

  python3 10_tools/reconstruction/m3_m68k_gdb.py stage
  python3 10_tools/reconstruction/m3_m68k_gdb.py cmd CC.cmd
  python3 10_tools/reconstruction/m3_m68k_gdb.py compare RUN_ID WORKDIR RECORD.json

Read-only apart from the stage, the command file, WORKDIR and the record.
"""
import sys, os, re, json, shutil, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m0_m68k_cause as C
import m3_m68k_config as K
import m3_m68k_spl as P426

BASE = P426.STAGE
STAGE = '08_build/runs/tools/m0p427-stage'
GDBH = 'generated/gdb.h'
BASE_RUN = 'm3p426-cc1'
BASE_REC = '09_validation/reconstruction/m3-m68k-spl-20261009.json'
OLD_PFX, NEW_PFX = 'K426__', 'K427__'
sha = K.sha


def cmd_stage():
    m = json.load(open(BASE + '.manifest.json'))
    assert not os.path.exists(STAGE)
    for e in m['files']:
        assert sha(os.path.join(BASE, e[0])) == e[2], e[0]
    shutil.copytree(BASE, STAGE, symlinks=True)
    p = os.path.join(STAGE, GDBH)
    assert open(p, 'rb').read() == b'#define GDB 0\n'
    os.chmod(p, 0o644)
    open(p, 'wb').write(b'#define GDB 1\n')
    files = []
    for e in m['files']:
        h = sha(os.path.join(STAGE, e[0]))
        if e[0] == GDBH:
            files.append([e[0], 'plan 427: GDB 1 (was %s)' % e[1], h])
        else:
            assert h == e[2], e[0]
            files.append(e[:3])
    on_disk = sorted(os.path.relpath(os.path.join(r, f), STAGE) for r, _, fs in os.walk(STAGE) for f in fs)
    assert on_disk == sorted(e[0] for e in files)
    json.dump(dict(plan=427, base=BASE, base_manifest_sha256=sha(BASE + '.manifest.json'), changed=[GDBH], files=files),
              open(STAGE + '.manifest.json', 'w'), indent=1)
    print('stage', STAGE, 'files', len(files))


def cmd_cmd(out):
    src = [l for l in open('08_build/artifacts/m3p426/cc.cmd').read().splitlines() if l.startswith(('RUN ', 'EXPECT '))]
    L = [l.replace('stage/' + OLD_PFX, 'stage/' + NEW_PFX).replace('EXPECT ' + OLD_PFX, 'EXPECT ' + NEW_PFX) for l in src]
    assert sum(1 for l in L if l.startswith('RUN ')) == 92 and not any(OLD_PFX in l for l in L)
    open(out, 'w').write('\n'.join(['# m3p427: plan 427 m68k compile with GDB 1 (m3_m68k_gdb.py cmd)'] + L) + '\n')
    print('lines', len(L))


def cmd_compare(rid, workdir, outj):
    T = {t['base']: t for t in json.load(open(C.TARGETS))['targets']}
    lines, dn = P426.deps_of(rid)
    _, do = P426.deps_of(BASE_RUN)
    img = C.Img()
    os.makedirs(workdir, exist_ok=True)
    B = {r['object']: r for r in json.load(open(BASE_REC))['objects']}
    rows = []
    for w in lines:
        if '-M' in w:
            continue
        base = w[-1][len('stage/' + NEW_PFX):-2]
        t = T[base]
        src = w[w.index('-c') + 1]
        new = os.path.join('08_build/runs', rid, 'out', NEW_PFX + base + '.o')
        old = os.path.join('08_build/runs', BASE_RUN, 'out', OLD_PFX + base + '.o')
        so, _ = K.sections(old)
        sn, _ = K.sections(new)
        d = C.run_l1(new, os.path.join(workdir, 'l1-%s.json' % t['object']))
        _, ts, spans = C.compare_object(img, new, t['ext_text_symbols'])
        rows.append(dict(object=t['object'], identical_file=sha(old) == sha(new),
                         changed_sections=sorted(k for k in set(so) | set(sn) if so.get(k) != sn.get(k)),
                         deps_same=dn[src] == do[src], verdict=d['object_verdict'],
                         placements=d['placements'], text_size=ts['size'],
                         functions={f['names'][0]: f['verdict'] for f in d['functions'] if f['section'] == '__TEXT,__text'},
                         spans={s['name']: s.get('equal') for s in spans if 'image_address' in s}))
    S = collections.OrderedDict()
    S['objects'] = len(rows)
    S['control_violations'] = sorted(r['object'] for r in rows if r['object'] != 'x86-if_venip' and not r['identical_file'])
    S['deps_all_same'] = all(r['deps_same'] for r in rows)
    oldv = {o: b['verdict'] for o, b in B.items()}
    oldf = {(o, f): v for o, b in B.items() for f, v in b['functions'].items()}
    olds = {(o, n): e for o, b in B.items() for n, e in b['spans'].items()}
    newv = {r['object']: r['verdict'] for r in rows}
    newf = {(r['object'], f): v for r in rows for f, v in r['functions'].items()}
    news = {(r['object'], n): e for r in rows for n, e in r['spans'].items()}
    S['object_match'] = [sum(v == 'OBJECT_MATCH' for v in oldv.values()), sum(v == 'OBJECT_MATCH' for v in newv.values())]
    S['function_match'] = [sum(v == 'MATCH' for v in oldf.values()), sum(v == 'MATCH' for v in newf.values())]
    S['span_equal'] = [sum(1 for v in olds.values() if v), sum(1 for v in news.values() if v)]
    S['lost'] = dict(objects=sorted(o for o, v in oldv.items() if v == 'OBJECT_MATCH' and newv.get(o) != 'OBJECT_MATCH'),
                     functions=sorted('%s %s' % k for k, v in oldf.items() if v == 'MATCH' and newf.get(k) != 'MATCH'),
                     spans=sorted('%s %s' % k for k, v in olds.items() if v and not news.get(k)))
    S['gained'] = dict(objects=sorted(o for o, v in newv.items() if v == 'OBJECT_MATCH' and oldv.get(o) != 'OBJECT_MATCH'),
                       functions=sorted('%s %s' % k for k, v in newf.items() if v == 'MATCH' and oldf.get(k) != 'MATCH'),
                       spans=sorted('%s %s' % k for k, v in news.items() if v and not olds.get(k)))
    v = [r for r in rows if r['object'] == 'x86-if_venip'][0]
    S['prediction'] = {'x86-if_venip _VENIP_RIF span': news.get(('x86-if_venip', '_VENIP_RIF'))}
    S['if_venip'] = dict(verdict=v['verdict'], text_size=v['text_size'], placements=v['placements'],
                         changed_sections=v['changed_sections'])
    S['passed'] = (not S['control_violations'] and S['deps_all_same'] and not any(S['lost'].values())
                   and all(S['prediction'].values()))
    json.dump(dict(plan=427, tool='10_tools/reconstruction/m3_m68k_gdb.py', tool_sha256=sha(os.path.abspath(__file__)),
                   run=rid, stage=STAGE, stage_manifest_sha256=sha(STAGE + '.manifest.json'), baseline=BASE_RUN,
                   summary=S, objects=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))


def main():
    a = sys.argv[1:]
    if a == ['stage']:
        cmd_stage()
    elif a[:1] == ['cmd'] and len(a) == 2:
        cmd_cmd(a[1])
    elif a[:1] == ['compare'] and len(a) == 4:
        cmd_compare(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
