#!/usr/bin/env python3
"""m3_m68k_spl.py -- plan 426 (M3-2): inline spl on m68k.  Test stage = plan 425 stage plus
generated/iplmeas.h (NIPLMEAS 0) and one '#import <bsd/m68k/spl.h>' in the KERNEL block of the
SDK copy src/bsd/m68k/machparam.h; the 46 V10 objects are recompiled and compared with the plan
425 run (plan 426.1).

  python3 10_tools/reconstruction/m3_m68k_spl.py stage
  python3 10_tools/reconstruction/m3_m68k_spl.py cmd CC.cmd
  python3 10_tools/reconstruction/m3_m68k_spl.py compare RUN_ID WORKDIR RECORD.json

Read-only apart from the stage, the command file, WORKDIR and the record.
"""
import sys, os, re, json, shutil, hashlib, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m0_m68k_cause as C
import m3_m68k_config as K

BASE = K.STAGE
STAGE = '08_build/runs/tools/m0p426-stage'
IPL = 'generated/iplmeas.h'
IPL_TEXT = b'#define NIPLMEAS 0\n'
MP = 'src/bsd/m68k/machparam.h'
OLD_LINE = b'#if\tKERNEL\n#define\tNBPG\tm68k_page_size\t\t/* bytes/page */\n'
NEW_LINE = b'#if\tKERNEL\n#import <bsd/m68k/spl.h>\t/* plan 426 test: inline spl */\n#define\tNBPG\tm68k_page_size\t\t/* bytes/page */\n'
BASE_RUN = '08_build/runs/m3p425-cc1'
BASE_REC = '09_validation/reconstruction/m3-m68k-config-driverkit-20261009.json'
NEW_DEPS = {'src/generated/iplmeas.h', 'src/src/bsd/m68k/spl.h', 'src/src/bsd/m68k/psl.h', 'src/src/kernserv/m68k/spl.h'}
sha = K.sha


def cmd_stage():
    m = json.load(open(BASE + '.manifest.json'))
    assert not os.path.exists(STAGE)
    for e in m['files']:
        assert sha(os.path.join(BASE, e[0])) == e[2], e[0]
    shutil.copytree(BASE, STAGE, symlinks=True)
    p = os.path.join(STAGE, MP)
    b = open(p, 'rb').read()
    assert b.count(OLD_LINE) == 1, 'machparam.h text not as expected'
    os.chmod(p, 0o644)
    open(p, 'wb').write(b.replace(OLD_LINE, NEW_LINE))
    q = os.path.join(STAGE, IPL)
    assert not os.path.exists(q)
    open(q, 'wb').write(IPL_TEXT)
    files = []
    for e in m['files']:
        h = sha(os.path.join(STAGE, e[0]))
        if e[0] == MP:
            files.append([e[0], 'plan 426: SDK copy + one #import line (was %s)' % e[1], h])
        else:
            assert h == e[2], e[0]
            files.append(e[:3])
    files.append([IPL, 'plan 426: NIPLMEAS 0', sha(q)])
    on_disk = sorted(os.path.relpath(os.path.join(r, f), STAGE) for r, _, fs in os.walk(STAGE) for f in fs)
    assert on_disk == sorted(e[0] for e in files)
    json.dump(dict(plan=426, base=BASE, base_manifest_sha256=sha(BASE + '.manifest.json'), changed=[MP], added=[IPL],
                   files=files), open(STAGE + '.manifest.json', 'w'), indent=1)
    print('stage', STAGE, 'files', len(files))


def cmd_cmd(out):
    src = [l for l in open('08_build/artifacts/m3p425/cc.cmd').read().splitlines() if l.startswith(('RUN ', 'EXPECT '))]
    L = [l.replace('stage/K425__', 'stage/K426__').replace('EXPECT K425__', 'EXPECT K426__') for l in src]
    assert sum(1 for l in L if l.startswith('RUN ')) == 92
    open(out, 'w').write('\n'.join(['# m3p426: plan 426 m68k compile with inline spl via machparam.h (m3_m68k_spl.py cmd)'] + L) + '\n')
    print('lines', len(L))


def deps_of(rid):
    lines = [l.split() for l in open(os.path.join('08_build/runs', rid, 'run.cmd')).read().splitlines() if l.startswith('RUN ')]
    out = {}
    for i, w in enumerate(lines):
        if '-M' in w:
            out[w[-1]] = set(open(os.path.join('08_build/runs', rid, 'out', '_log', '%02d.out' % i)).read().replace('\\\n', ' ').split()[1:])
    return lines, out


def cmd_compare(rid, workdir, outj):
    T = {t['base']: t for t in json.load(open(C.TARGETS))['targets']}
    lines, dn = deps_of(rid)
    _, do = deps_of('m3p425-cc1')
    img = C.Img()
    os.makedirs(workdir, exist_ok=True)
    B = {r['object']: r for r in json.load(open(BASE_REC))['objects']}
    rows = []
    for w in lines:
        if '-M' in w:
            continue
        base = w[-1][len('stage/K426__'):-2]
        t = T[base]
        src = w[w.index('-c') + 1]
        new = os.path.join('08_build/runs', rid, 'out', 'K426__%s.o' % base)
        old = os.path.join(BASE_RUN, 'out', 'K425__%s.o' % base)
        oo = macho_obj.parse(open(old, 'rb').read())
        spl_ref = sorted({y['name'] for y in oo['symbols'] if y['kind'] == 'UNDF' and re.match(r'_spl', y['name'])})
        so, _ = K.sections(old)
        sn, _ = K.sections(new)
        changed = sorted(k for k in set(so) | set(sn) if so.get(k) != sn.get(k))
        added = dn[src] - do[src]
        removed = do[src] - dn[src]
        d = C.run_l1(new, os.path.join(workdir, 'l1-%s.json' % t['object']))
        _, ts, spans = C.compare_object(img, new, t['ext_text_symbols'])
        on = macho_obj.parse(open(new, 'rb').read())
        rows.append(dict(object=t['object'], spl_refs_425=spl_ref,
                         spl_refs_426=sorted({y['name'] for y in on['symbols'] if y['kind'] == 'UNDF' and y['name'].startswith('_spl')}),
                         uses_machparam='src/src/bsd/m68k/machparam.h' in do[src], deps_added=sorted(added), deps_removed=sorted(removed),
                         identical_file=sha(old) == sha(new), changed_sections=changed, verdict=d['object_verdict'],
                         functions={f['names'][0]: f['verdict'] for f in d['functions'] if f['section'] == '__TEXT,__text'},
                         spans={s['name']: s.get('equal') for s in spans if 'image_address' in s}))
    S = collections.OrderedDict()
    S['objects'] = len(rows)
    S['spl_objects'] = sorted(r['object'] for r in rows if r['spl_refs_425'])
    S['control_violations'] = sorted(r['object'] for r in rows if not r['spl_refs_425'] and r['changed_sections'])
    S['deps_prediction'] = dict(
        machparam_objects=sum(r['uses_machparam'] for r in rows),
        exact_four_added=sum(1 for r in rows if r['uses_machparam'] and set(r['deps_added']) == NEW_DEPS and not r['deps_removed']),
        others_unchanged=sum(1 for r in rows if not r['uses_machparam'] and not r['deps_added'] and not r['deps_removed']))
    S['spl_refs_left'] = {r['object']: r['spl_refs_426'] for r in rows if r['spl_refs_426']}
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
    S['prediction'] = {k: news.get(k) for k in (('x86-subr_kudp', '_ku_sendto_mbuf'), ('x86-if_venip', '_VENIP_RIF'))}
    S['prediction'] = {'%s %s' % k: v for k, v in S['prediction'].items()}
    S['at_risk'] = {'x86-subr_kudp _ku_recvfrom (function)': newf.get(('x86-subr_kudp', '_ku_recvfrom')),
                    **{'x86-if_venip %s (span)' % n: news.get(('x86-if_venip', n)) for n in ('_VENIP_PRIVATE', '_VENIP_ENADDRP', '_VENIP_IPADDR')}}
    S['venip_config_span'] = news.get(('x86-if_venip', '_venip_config'))
    S['passed'] = (not S['control_violations'] and not any(S['lost'].values()) and all(S['prediction'].values())
                   and S['deps_prediction']['exact_four_added'] == S['deps_prediction']['machparam_objects']
                   and S['deps_prediction']['others_unchanged'] == len(rows) - S['deps_prediction']['machparam_objects'])
    json.dump(dict(plan=426, tool='10_tools/reconstruction/m3_m68k_spl.py', tool_sha256=sha(os.path.abspath(__file__)),
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
