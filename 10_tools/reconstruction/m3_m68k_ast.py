#!/usr/bin/env python3
"""m3_m68k_ast.py -- plan 432 (M3-8): test MACHINE_AST (aston/astoff on a 32-bit pcb_flags at
pcb+0x54, mask 0x10000000) and SIMPLE_CLOCK 1 in test-only stages (plan 432.1).

  python3 10_tools/reconstruction/m3_m68k_ast.py stage int|uchar
  python3 10_tools/reconstruction/m3_m68k_ast.py cmd int|uchar CC.cmd
  python3 10_tools/reconstruction/m3_m68k_ast.py compare RUN_INT RUN_UCHAR WORKDIR RECORD.json

Variant int: the test header; variant uchar: the pre-registered negative control (u_char at
+0x54, mask 0x10).  Nothing here goes into 07.
"""
import sys, os, re, json, shutil, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m0_m68k_cause as C
import m3_m68k_config as K
import m3_m68k_machdep as M
import m3_m68k_wide as W
import m3_m68k_diag as D2C

BASE = '08_build/runs/tools/m0p430-stage-2'
BASE_RUN = '08_build/runs/m3p430-it2/out'
BASE_REC = '09_validation/reconstruction/m3-m68k-machdep-20261009.json'
DIAG2 = '09_validation/reconstruction/m3-m68k-diag2-20261009.json'
PFX = {'int': 'A432__', 'uchar': 'U432__'}
TOKENS = re.compile(r'\b(ast_on|ast_off|ast_context|ast_propagate|aston|astoff|SIMPLE_CLOCK)\b')
sha = C.sha


def headers(v):
    if v == 'int':
        field, mask = 'int\tpcb_flags;\t\t/* +0x54 */', '0x10000000'
    else:
        field, mask = 'unsigned char\tpcb_flags;\t/* +0x54 (negative control) */', '0x10'
    th = M.HDR['thread.h'].replace(
        '\tint\tpcb_regs_valid;\t\t/* +0x4c: tested by USER_REGS (_init_task) */\n};',
        '\tint\tpcb_regs_valid;\t\t/* +0x4c: tested by USER_REGS (_init_task) */\n\tchar\tpcb_pad50[4];\t\t/* +0x50 */\n\t%s\n};' % field)
    assert th != M.HDR['thread.h']
    ast = ('/* plan 432 test-only m68k header (measurement; not 07) */\n#ifndef _MACHDEP_M68K_AST_H_\n'
           '#define _MACHDEP_M68K_AST_H_\n#define MACHINE_AST\n'
           '#define aston(mycpu)\t{ current_thread()->pcb->pcb_flags |= %s; }\n'
           '#define astoff(mycpu)\t{ current_thread()->pcb->pcb_flags &= ~%s; }\n#endif\n' % (mask, mask))
    return {'src/machdep/m68k/thread.h': th, 'src/machdep/m68k/ast.h': ast, 'generated/simple_clock.h': '#define SIMPLE_CLOCK 1\n'}


def cmd_stage(v):
    stage = '08_build/runs/tools/m0p432-stage-%s' % v
    m = json.load(open(BASE + '.manifest.json'))
    assert not os.path.exists(stage)
    for e in m['files']:
        assert sha(os.path.join(BASE, e[0])) == e[2], e[0]
    shutil.copytree(BASE, stage, symlinks=True)
    H = headers(v)
    for p, t in H.items():
        q = os.path.join(stage, p)
        assert os.path.exists(q), p
        os.chmod(q, 0o644)
        open(q, 'w').write(t)
    files = []
    for e in m['files']:
        h = sha(os.path.join(stage, e[0]))
        if e[0] in H:
            files.append([e[0], 'plan 432 (%s)' % v, h])
        else:
            assert h == e[2], e[0]
            files.append(e[:3])
    on_disk = sorted(os.path.relpath(os.path.join(r, f), stage) for r, _, fs in os.walk(stage) for f in fs)
    assert on_disk == sorted(e[0] for e in files)
    json.dump(dict(plan=432, variant=v, base=BASE, base_manifest_sha256=sha(BASE + '.manifest.json'), changed=sorted(H),
                   files=files), open(stage + '.manifest.json', 'w'), indent=1)
    print('stage', stage, 'changed', sorted(H))


def change_set():
    """bases whose source uses an AST or SIMPLE_CLOCK token (comments stripped)."""
    out = set()
    for l in open('08_build/artifacts/m3p430/cc2.cmd'):
        if not l.startswith('RUN '):
            continue
        w = l.split()
        src = os.path.join(BASE, w[w.index('-c') + 1][len('src/'):])
        t = re.sub(r'/\*.*?\*/', '', open(src, errors='replace').read(), flags=re.S)
        if TOKENS.search(t):
            out.add(w[-1][len('stage/M430__'):-2])
    return out


def cmd_cmd(v, out):
    L = [l.rstrip('\n') for l in open('08_build/artifacts/m3p430/cc2.cmd') if l.startswith(('RUN ', 'EXPECT '))]
    if v == 'uchar':
        cs = change_set()
        L = [l for l in L if any(('M430__%s.o' % b) in l for b in cs)]
    L = [l.replace('M430__', PFX[v]) for l in L]
    open(out, 'w').write('\n'.join(['# m3p432 (%s): plan 432 (m3_m68k_ast.py cmd)' % v] + L) + '\n')
    print('lines', len(L))


def cmd_compare(rid_int, rid_uchar, workdir, outj):
    cs = change_set()
    T = {t['base']: t for t in W.targets()}
    img = C.Img()
    os.makedirs(workdir, exist_ok=True)
    B = {o['object']: o for o in json.load(open(BASE_REC))['objects']}
    D2 = json.load(open(DIAG2))
    ast_spans = [(r['object'], r['span']) for r in D2['spans'] if any(b['signature'] and '0x54:w)' in b['signature'] for b in r['blocks'])
                 or r['span'] == '_ast_init']
    sc_spans = [('x86-thread', '_thread_info'), ('x86-sched_prim', '_sched_init'), ('x86-sched_prim', '_recompute_priorities')]

    def run_rows(rid, pfx):
        rows = {}
        for f in sorted(os.listdir(os.path.join('08_build/runs', rid, 'out'))):
            if not (f.startswith(pfx) and f.endswith('.o')):
                continue
            base = f[len(pfx):-2]
            t = T[base]
            p = os.path.join('08_build/runs', rid, 'out', f)
            so = D2C.canon(os.path.join(BASE_RUN, 'M430__%s.o' % base))   # relocations by symbol name
            sn = D2C.canon(p)
            xo = macho_obj.parse(open(t['obj'], 'rb').read())
            xt = [s for s in xo['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')]
            ext = [y['name'] for y in xo['symbols'] if xt and y['kind'] == 'SECT' and y.get('ext') and not y['stab'] and y['sect'] == xt[0]['index']]
            d = C.run_l1(p, os.path.join(workdir, '%s-l1-%s.json' % (pfx[:-2], t['object'])))
            _, ts, spans = C.compare_object(img, p, ext)
            rows[t['object']] = dict(base=base, changed=sorted(k for k in set(so) | set(sn) if so.get(k) != sn.get(k)),
                                     verdict=d['object_verdict'],
                                     functions={x['names'][0]: x['verdict'] for x in d['functions'] if x['section'] == '__TEXT,__text'},
                                     spans={s['name']: s.get('equal') for s in spans if 'image_address' in s})
        return rows
    A = run_rows(rid_int, PFX['int'])
    U = run_rows(rid_uchar, PFX['uchar'])
    S = collections.OrderedDict()
    S['change_set'] = sorted(T[b]['object'] for b in cs)
    S['control_violations'] = sorted(o for o, r in A.items() if r['base'] not in cs and r['changed'])
    oldv = {o: B[o]['verdict'] for o in A}
    S['object_match'] = [sum(v == 'OBJECT_MATCH' for v in oldv.values()), sum(r['verdict'] == 'OBJECT_MATCH' for r in A.values())]
    S['gained_objects'] = sorted(o for o, r in A.items() if r['verdict'] == 'OBJECT_MATCH' and oldv[o] != 'OBJECT_MATCH')
    S['lost_objects'] = sorted(o for o, r in A.items() if r['verdict'] != 'OBJECT_MATCH' and oldv[o] == 'OBJECT_MATCH')
    newsp = {(o, n): e for o, r in A.items() for n, e in r['spans'].items()}
    S['ast_spans_now_equal'] = {'%s %s' % k: newsp.get(k) for k in ast_spans}
    S['simple_clock_spans_now_equal'] = {'%s %s' % k: newsp.get(k) for k in sc_spans}
    usp = {(o, n): e for o, r in U.items() for n, e in r['spans'].items()}
    S['negative_control_ast_spans_equal'] = {'%s %s' % k: usp.get(k) for k in ast_spans}
    S['negative_control_object_match'] = sorted(o for o, r in U.items() if r['verdict'] == 'OBJECT_MATCH')
    json.dump(dict(plan=432, tool='10_tools/reconstruction/m3_m68k_ast.py', tool_sha256=sha(os.path.abspath(__file__)),
                   runs=[rid_int, rid_uchar], summary=S, objects_int=A, objects_uchar=U), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))


def main():
    a = sys.argv[1:]
    if a[:1] == ['stage'] and len(a) == 2:
        cmd_stage(a[1])
    elif a[:1] == ['cmd'] and len(a) == 3:
        cmd_cmd(a[1], a[2])
    elif a[:1] == ['compare'] and len(a) == 5:
        cmd_compare(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
