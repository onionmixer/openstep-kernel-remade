#!/usr/bin/env python3
"""m3_m68k_config.py -- plan 425 (M3-1): test the m68k configuration hypothesis DRIVERKIT 0
(-> MACH_SLOCKS 0 with NCPUS 1) by recompiling the plan 414 V10 objects.

  python3 10_tools/reconstruction/m3_m68k_config.py stage
  python3 10_tools/reconstruction/m3_m68k_config.py cmd CC.cmd
  python3 10_tools/reconstruction/m3_m68k_config.py compare RUN_ID WORKDIR RECORD.json

stage    copy 08_build/runs/tools/m0p413-stage to 08_build/runs/tools/m0p425-stage (every file
         hash-checked against the m0p413 manifest) and write "#define DRIVERKIT 0" into
         generated/driverkit.h; the new manifest records exactly that one change.
cmd      the plan 414 V10 compile lines (grid2.cmd) with stage/K425__BASE.o outputs, plus the
         same lines with -M (m68k dependency lists, captured in _log).
compare  section-level comparison with the V10 objects (stabs separated), L1 and external-span
         comparison against the original (m0_m68k_cause helpers), pre-registered control and
         prediction checks (plan 425.1).
Read-only apart from the stage, the command file, WORKDIR and the record.
"""
import sys, os, re, json, shutil, hashlib, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m0_m68k_cause as C

BASE = '08_build/runs/tools/m0p413-stage'
STAGE = '08_build/runs/tools/m0p425-stage'
CHANGED = 'generated/driverkit.h'
NEW = b'#define DRIVERKIT 0\n'
GRID2 = '08_build/artifacts/m0p414/grid2.cmd'
V10_RUN = '08_build/runs/m0p414-fg2'
CLASS = '08_build/artifacts/m0p414/class-V10.json'
D_SPANS_NOTE = 'plan 414.3: the 11 D spans (utask +4, processor.slot_num +8)'


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def cmd_stage():
    m = json.load(open(BASE + '.manifest.json'))
    assert not os.path.exists(STAGE)
    for e in m['files']:
        assert sha(os.path.join(BASE, e[0])) == e[2], e[0]
    shutil.copytree(BASE, STAGE, symlinks=True)
    p = os.path.join(STAGE, CHANGED)
    assert open(p, 'rb').read() == b'#define DRIVERKIT 1\n'
    os.chmod(p, 0o644)
    open(p, 'wb').write(NEW)
    files = []
    for e in m['files']:
        h = sha(os.path.join(STAGE, e[0]))
        if e[0] == CHANGED:
            assert h == hashlib.sha256(NEW).hexdigest()
            files.append([e[0], 'plan 425: DRIVERKIT 0 (was %s)' % e[1], h])
        else:
            assert h == e[2], e[0]
            files.append(e[:3])
    on_disk = sorted(os.path.relpath(os.path.join(r, f), STAGE) for r, _, fs in os.walk(STAGE) for f in fs)
    assert on_disk == sorted(e[0] for e in files)
    json.dump(dict(plan=425, base=BASE, base_manifest_sha256=sha(BASE + '.manifest.json'), changed=[CHANGED],
                   files=files), open(STAGE + '.manifest.json', 'w'), indent=1)
    print('stage', STAGE, 'files', len(files), 'changed', CHANGED)


def v10_lines():
    return [l for l in open(GRID2).read().splitlines() if l.startswith('RUN ') and ' stage/V10__' in l]


def cmd_cmd(out):
    L, M_, E = [], [], []
    for l in v10_lines():
        base = l.split()[-1][len('stage/V10__'):-2]
        L.append(l.replace(' stage/V10__', ' stage/K425__'))
        E.append('EXPECT K425__%s.o' % base)
        w = l.split()
        w[w.index('-c')] = '-M'
        M_.append(' '.join(w[:w.index('-o')]))
    assert len(L) == 46
    open(out, 'w').write('\n'.join(['# m3p425: plan 425 m68k compile with DRIVERKIT 0 (V10 flags), 46 objects + -M lists '
                                    '(m3_m68k_config.py cmd)'] + L + M_ + E) + '\n')
    print('commands', len(L) + len(M_))


def sections(p):
    b = open(p, 'rb').read()
    o = macho_obj.parse(b)
    out = {}
    for s in o['sections']:
        k = '%s,%s' % (s['segname'], s['sectname'])
        out[k] = (b[s['offset']:s['offset'] + s['size']] if s['size'] and s['offset'] else b'',
                  [(r['address'], r.get('symbolnum'), r.get('extern'), r['length'], r['pcrel'], r['type']) for r in s['relocs']],
                  s['size'])
    syms = sorted((y['name'], y['kind'], y['value']) for y in o['symbols'] if not y['stab'])
    return out, syms


def cmd_compare(rid, workdir, outj):
    T = {t['base']: t for t in json.load(open(C.TARGETS))['targets']}
    lines = [l.split() for l in open(os.path.join('08_build/runs', rid, 'run.cmd')).read().splitlines() if l.startswith('RUN ')]
    img = C.Img()
    os.makedirs(workdir, exist_ok=True)
    rows = []
    for i, w in enumerate(lines):
        if '-M' in w:
            continue
        base = w[-1][len('stage/K425__'):-2]
        t = T[base]
        new = os.path.join('08_build/runs', rid, 'out', 'K425__%s.o' % base)
        old = os.path.join(V10_RUN, 'out', 'V10__%s.o' % base)
        # m68k dependency list from the -M line of the same source
        mi = [j for j, x in enumerate(lines) if '-M' in x and x[-1] == w[w.index('-c') + 1]]
        assert len(mi) == 1
        deps = open(os.path.join('08_build/runs', rid, 'out', '_log', '%02d.out' % mi[0])).read().replace('\\\n', ' ').split()
        uses_lock = any(d.endswith('src/kern/lock.h') for d in deps)
        so, yo = sections(old)
        sn, yn = sections(new)
        changed = sorted(k for k in set(so) | set(sn) if so.get(k) != sn.get(k))
        d = C.run_l1(new, os.path.join(workdir, 'l1-%s.json' % t['object']))
        _, ts, spans = C.compare_object(img, new, t['ext_text_symbols'])
        funcs = {f['names'][0]: f['verdict'] for f in d['functions'] if f['section'] == '__TEXT,__text'}
        # simple_lock references left in the object
        ob = macho_obj.parse(open(new, 'rb').read())
        slk = sorted({y['name'] for y in ob['symbols'] if y['kind'] == 'UNDF' and y['name'].startswith('_simple_')})
        rows.append(dict(object=t['object'], uses_lock_h_m68k=uses_lock, identical_file=sha(old) == sha(new),
                         changed_sections=changed, symbols_changed=yo != yn, verdict=d['object_verdict'],
                         functions=funcs, spans={s['name']: s.get('equal') for s in spans if 'image_address' in s},
                         simple_lock_refs=slk))
    G = json.load(open('08_build/artifacts/m0p414/grid.json'))
    base_rows = {r['object']: r for r in G['objects'] if r['variant'] == 'V10'}
    cls = json.load(open(CLASS))
    dspans = [(s['object'], s['name']) for s in cls['spans'] if s['klass'] == 'D']
    xspans = [(s['object'], s['name']) for s in cls['spans'] if s['klass'] != 'D']
    S = collections.OrderedDict()
    S['objects'] = len(rows)
    S['uses_lock_h_m68k'] = sum(r['uses_lock_h_m68k'] for r in rows)
    S['identical_files'] = sum(r['identical_file'] for r in rows)
    S['code_changed'] = sorted(r['object'] for r in rows if [k for k in r['changed_sections'] if k != '__TEXT,__text' or True]
                               and any(k.startswith('__TEXT,__text') for k in r['changed_sections']))
    S['changed_sections'] = dict(collections.Counter(k for r in rows for k in r['changed_sections']))
    # control: objects not including kern/lock.h must have identical non-stab sections
    S['control_violations'] = [r['object'] for r in rows if not r['uses_lock_h_m68k'] and r['changed_sections']]
    v10_obj = {o: b['verdict'] for o, b in base_rows.items()}
    v10_fn = {(o, f['names'][0]): f['verdict'] for o, b in base_rows.items() for f in b['functions']}
    v10_sp = {(o, s['name']): s.get('equal') for o, b in base_rows.items() for s in b['spans'] if 'image_address' in s}
    new_obj = {r['object']: r['verdict'] for r in rows}
    new_fn = {(r['object'], f): v for r in rows for f, v in r['functions'].items()}
    new_sp = {(r['object'], n): e for r in rows for n, e in r['spans'].items()}
    S['object_match'] = [sum(v == 'OBJECT_MATCH' for v in v10_obj.values()), sum(v == 'OBJECT_MATCH' for v in new_obj.values())]
    S['function_match'] = [sum(v == 'MATCH' for v in v10_fn.values()), sum(v == 'MATCH' for v in new_fn.values())]
    S['span_equal'] = [sum(1 for v in v10_sp.values() if v), sum(1 for v in new_sp.values() if v)]
    S['lost'] = dict(objects=sorted(o for o, v in v10_obj.items() if v == 'OBJECT_MATCH' and new_obj.get(o) != 'OBJECT_MATCH'),
                     functions=sorted('%s %s' % k for k, v in v10_fn.items() if v == 'MATCH' and new_fn.get(k) != 'MATCH'),
                     spans=sorted('%s %s' % k for k, v in v10_sp.items() if v and not new_sp.get(k)))
    S['gained'] = dict(objects=sorted(o for o, v in new_obj.items() if v == 'OBJECT_MATCH' and v10_obj.get(o) != 'OBJECT_MATCH'),
                       functions=sorted('%s %s' % k for k, v in new_fn.items() if v == 'MATCH' and v10_fn.get(k) != 'MATCH'),
                       spans=sorted('%s %s' % k for k, v in new_sp.items() if v and not v10_sp.get(k)))
    S['prediction_d_spans'] = {'%s %s' % k: new_sp.get(k) for k in dspans}
    S['x_spans_now_equal'] = sorted('%s %s' % k for k in xspans if new_sp.get(k))
    S['mach_factor_simple_lock_refs'] = [r['simple_lock_refs'] for r in rows if r['object'] == 'x86-mach_factor']
    S['passed'] = (not S['control_violations'] and not any(S['lost'].values())
                   and all(S['prediction_d_spans'].values()))
    json.dump(dict(plan=425, tool='10_tools/reconstruction/m3_m68k_config.py', tool_sha256=sha(os.path.abspath(__file__)),
                   run=rid, stage=STAGE, stage_manifest_sha256=sha(STAGE + '.manifest.json'), baseline=V10_RUN,
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
