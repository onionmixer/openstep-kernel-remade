#!/usr/bin/env python3
"""stage_m68k.py -- plan 433 (M3-9, D068): m68k staging from the 07 overlay trees and the
reproduction of the plan 429/432 test results.

  python3 10_tools/reconstruction/stage_m68k.py stage STAGE_DIR
  python3 10_tools/reconstruction/stage_m68k.py cmd CC.cmd
  python3 10_tools/reconstruction/stage_m68k.py x86gate WORKDIR
  python3 10_tools/reconstruction/stage_m68k.py compare RUN_ID STAGE_DIR WORKDIR GATE.json RECORD.json
  Every command takes an optional leading --plan N (433 when absent; 435, 437, 438, 441, 444, 445, 446, 447, 449, 450, 451, 452): the
  record's plan number, the output prefix O<N>__ and the pre-registered exception list.

stage    s6l4-g1a-stage (the x86 base) + the real-machine SDK m68k headers (plan 413, local
         copy hash-checked against its target list) + 07_kernel/v183.34/common + 07_kernel/
         v183.34/m68k, copied in this order (a later file replaces an earlier one; D068 picks
         m68k, then common, then the 07 main tree).  STAGE_DIR.manifest.json: [path, origin,
         sha256] per file.  An overlay .c file must be its 07 main file plus inserted lines
         that each carry a registered marker (MARKERS; plan 435's D070 line at most once,
         right after '#import <sys/param.h>'; plan 437 generalisation).
cmd      the 205 compile lines of the plan 429 (run m3p429-cc2, -c only) and plan 432 (run
         m3p432-int) runs, output prefix O433__.
x86gate  re-stage every s6l4-g* x86 stage with stage_headers.py and its manifest options and
         require the manifests to be unchanged (the x86 build does not read v183.34).
compare  every O433 object against the test-run object (non-STABS section bytes and
         relocations with external symbol numbers replaced by names) and L1 against the
         original; the pre-registered exceptions are x86-subr_kudp and x86-if_venip.
Read-only apart from the outputs named above.
"""
import sys, os, re, json, glob, shutil, subprocess, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m0_m68k_cause as C
import m0_m68k_l1 as L
import m3_m68k_wide as W
import m3_m68k_diag as D

OVL = ['07_kernel/v183.34/common', '07_kernel/v183.34/m68k']
REFS = [('m3p429-cc2', 'W429__'), ('m3p432-int', 'A432__')]
PLAN = 433                                # set by --plan (plan 435)
EXCEPTS = {433: {'x86-subr_kudp': 'SDK machparam.h spl import not taken (D069 pending)',
                 'x86-if_venip': 'SDK machparam.h spl import not taken (D069 pending)'},
           435: {},
           437: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (expected to differ from the test run)'},
           441: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)'},
           444: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)'},
           445: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)'},
           446: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)'},
           447: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)'},
           449: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)'},
           450: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)'},
           451: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)'},
           452: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)',
                 'x86-ufs_alloc': 'i386 cylinder group byte swap removed, NeXTMach checks in the m68k overlay (plan 452)'},
           438: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (expected to differ from the test run)'}}
MARKERS = {'plan 435 (D070)': {'src/bsd/rpc/subr_kudp.c': 1, 'src/bsd/net/if_venip.c': 1},   # registered overlay
           'plan 437 (m68k)': {'src/bsd/kern/subr_prf.c': 5},          # markers: file -> number of marked lines
           'plan 441 (m68k)': {'src/kern/ast.c': 32},                  # (a begin..end block counts every line)
           'plan 444 (m68k)': {'src/bsd/kern/mach_process.c': 7, 'src/bsd/kern/kern_exec.c': 5},
           'plan 445 (m68k)': {'src/bsd/kern/kern_exec.c': 9},
           'plan 446 (m68k)': {'src/vm/vm_fault.c': 46},
           'plan 447 (m68k)': {'src/vm/vm_pageout.c': 26},
           'plan 449 (m68k)': {'src/bsd/ufs/ufs_vnodeops.c': 4, 'src/bsd/ufs/ufs_inode.c': 8},
           'plan 450 (m68k)': {'src/bsd/ufs/ufs_vfsops.c': 18},
           'plan 451 (m68k)': {'src/bsd/ufs/ufs_dir.c': 7},
           'plan 452 (m68k)': {'src/bsd/ufs/ufs_alloc.c': 64}}
DERIVED = '#import <machine/spl.h>\t/* plan 435 (D070): m68k inline spl */\n'
TEST_STAGE = '08_build/runs/tools/m0p432-stage-int'
sha = C.sha


def overlay_files(root):
    if not os.path.isdir(root):
        return []
    out = []
    for r, ds, fs in os.walk(root):
        ds.sort()
        for f in sorted(fs):
            p = os.path.join(r, f)
            rel = os.path.relpath(p, root)
            if rel == 'README.md':
                continue
            assert not os.path.islink(p), p
            out.append((rel, p))
    return out


def check_derived(rel, src):
    """plans 435/437: overlay source = 07 main file + inserted lines, each carrying a registered
    marker (nothing deleted or changed); the D070 line at most once, right after
    '#import <sys/param.h>'.  Placement of other marked lines is evidenced by the diff files."""
    A = open(os.path.join('07_kernel', rel)).readlines()
    B = open(src).readlines()
    assert not any(m in l for l in A for m in MARKERS), 'marker text in the 07 main file: ' + rel
    owner = {}                                  # line -> marker (plan 441: '<marker> begin' .. '<marker> end' blocks)
    open_m = None
    for i, l in enumerate(B):
        hit = [m for m in MARKERS if m in l]
        assert len(hit) <= 1, 'several markers on one line: %s:%d' % (rel, i + 1)
        if open_m:
            assert not hit or hit == [open_m], 'marker inside another block: %s:%d' % (rel, i + 1)
            owner[i] = open_m
            if open_m + ' end' in l:
                open_m = None
            continue
        if hit:
            owner[i] = hit[0]
            if hit[0] + ' begin' in l:
                assert hit[0] + ' end' not in l, rel
                open_m = hit[0]
            else:
                assert hit[0] + ' end' not in l, 'block end without begin: %s:%d' % (rel, i + 1)
    assert open_m is None, 'unclosed marker block in ' + rel
    marked = sorted(owner)
    assert marked, 'overlay source without a registered marker: ' + rel
    for i in marked:
        assert rel in MARKERS[owner[i]], 'marker not registered for %s: line %d' % (rel, i + 1)
    for m, files in MARKERS.items():
        n = sum(1 for i in marked if owner[i] == m)
        assert n == files.get(rel, 0), 'marker %r: %d lines in %s, registered %d' % (m, n, rel, files.get(rel, 0))
    d070 = [i for i in marked if owner[i] == 'plan 435 (D070)']
    assert len(d070) <= 1, (rel, d070)
    for i in d070:
        assert B[i] == DERIVED and i > 0 and B[i - 1] == '#import <sys/param.h>\n', rel
    assert [l for i, l in enumerate(B) if i not in set(marked)] == A, 'overlay source differs from 07 main file: ' + rel


def cmd_stage(stage):
    m = L.base_manifest()
    assert not os.path.exists(stage), stage
    files = L.sdk_files()
    shutil.copytree(L.BASE_STAGE, stage, symlinks=True)
    ent = collections.OrderedDict((e[0], list(e[:3])) for e in m['files'])
    for rel, h, dst in files:
        p = os.path.join(stage, dst)
        if os.path.exists(p):
            assert sha(p) == h, 'different file already at ' + dst
            continue
        os.makedirs(os.path.dirname(p), exist_ok=True)
        shutil.copyfile(os.path.join(L.SDK, rel), p)
        assert sha(p) == h
        ent[dst] = [dst, 'real machine ' + L.SDK_ROOT + rel, h]
    replaced, added = [], []
    for root in OVL:
        for rel, src in overlay_files(root):
            q = os.path.join(stage, rel)
            assert rel.startswith(('generated/', 'src/')), rel
            if rel.endswith('.c'):
                check_derived(rel, src)
            (replaced if os.path.exists(q) else added).append(rel)
            if os.path.exists(q):
                os.chmod(q, 0o644)
                os.remove(q)
            os.makedirs(os.path.dirname(q), exist_ok=True)
            shutil.copyfile(src, q)
            ent[rel] = [rel, src, sha(q)]
    on_disk = sorted(os.path.relpath(os.path.join(r, f), stage) for r, _, fs in os.walk(stage) for f in fs)
    assert on_disk == sorted(ent), 'stage content differs from manifest'
    for e in ent.values():
        assert sha(os.path.join(stage, e[0])) == e[2], e[0]
    json.dump(dict(plan=PLAN, base=L.BASE_STAGE, base_manifest_sha256=sha(L.BASE_STAGE + '.manifest.json'),
                   sdk_list=L.SDK_SHA, sdk_list_sha256=sha(L.SDK_SHA), overlays=OVL, replaced=replaced, added=added,
                   files=list(ent.values())), open(stage + '.manifest.json', 'w'), indent=1)
    print('stage', stage, 'files', len(ent), 'overlay replaced', len(replaced), 'added', len(added))


def ref_lines():
    out = []
    for rid, pfx in REFS:
        for l in open(os.path.join('08_build/runs', rid, 'run.cmd')):
            if l.startswith('RUN ') and ' -c ' in l:
                assert l.count('stage/' + pfx) == 1, l
                out.append((rid, pfx, l.rstrip('\n')))
    return out


def cmd_cmd(out):
    R = ref_lines()
    PFX = 'O%d__' % PLAN
    L_ = [l.replace('stage/' + pfx, 'stage/' + PFX) for _, pfx, l in R]
    E = ['EXPECT %s' % l.split()[-1][len('stage/'):] for l in L_]
    assert len(L_) == 205 and len(set(E)) == 205, (len(L_), len(set(E)))
    open(out, 'w').write('\n'.join(['# m3p%d: plan %d m68k compile from the 07 overlay stage (stage_m68k.py cmd)' % (PLAN, PLAN)] + L_ + E) + '\n')
    print('lines', len(L_))


def cmd_x86gate(workdir):
    os.makedirs(workdir, exist_ok=True)
    rows = []
    for p in sorted(glob.glob('08_build/runs/tools/s6l4-g*-stage.manifest.json')):
        m = json.load(open(p))
        name = os.path.basename(p)[:-len('.manifest.json')]
        out = os.path.join(workdir, name)
        assert not os.path.exists(out), out
        args = ['--prefer-07'] if m['prefer_07'] else []
        args += ['--nextdev'] if m['nextdev'] else []
        args += ['--bsd-set', m['bsd_set']] if m['bsd_set'] else []
        args += ['--mach-set', m['mach_set']] if m['mach_set'] else []
        for ps in m.get('public_sdk', []):   # plan 293 option of s6l4-g5a
            args += ['--public-sdk', ps]
        assert set(m) <= {'sources', 'files', 'unresolved', 'prefer_07', 'nextdev', 'bsd_set', 'bsd_not_adopted', 'mach_set',
                          'mach_replaced_07', 'mach_not_adopted', 'public_sdk'}, sorted(m)
        subprocess.run([sys.executable, '10_tools/reconstruction/stage_headers.py'] + args + [out] + m['sources'],
                       check=True, stdout=subprocess.DEVNULL)
        n = json.load(open(out + '.manifest.json'))
        rows.append(dict(stage=name, manifest_sha256=sha(p), files=len(m['files']), options=args,
                         same=(m == n), v183_paths=sum(1 for e in n['files'] if 'v183.34' in e[1])))
    print(json.dumps(rows, indent=1))
    assert all(r['same'] and not r['v183_paths'] for r in rows)
    json.dump(dict(plan=PLAN, tool='10_tools/reconstruction/stage_m68k.py', tool_sha256=sha(os.path.abspath(__file__)),
                   stage_headers_sha256=sha('10_tools/reconstruction/stage_headers.py'), stages=rows),
              open(os.path.join(workdir, 'x86gate.json'), 'w'), indent=1)


def cmd_compare(rid, stage, workdir, gate, outj):
    PFX, EXCEPT = 'O%d__' % PLAN, EXCEPTS[PLAN]
    T = {t['base']: t for t in W.targets()}
    by_obj = {}
    for r in json.load(open('09_validation/reconstruction/m3-m68k-wide-20261009.json'))['objects']:
        by_obj[r['object']] = r['verdict']
    for o, r in json.load(open('09_validation/reconstruction/m3-m68k-ast-20261009.json'))['objects_int'].items():
        assert o not in by_obj
        by_obj[o] = r['verdict']
    assert len(by_obj) == 205
    img = C.Img()
    img_names = {y['name'] for y in img.img.o['symbols']}   # plan 437: original symbol names
    os.makedirs(workdir, exist_ok=True)
    rows = []
    for rrid, pfx, l in ref_lines():
        f = os.path.basename(l.split()[-1])
        base = f[len(pfx):-2]
        t = T[base]
        ref = os.path.join('08_build/runs', rrid, 'out', f)
        new = os.path.join('08_build/runs', rid, 'out', PFX + base + '.o')
        cr, cn = D.canon(ref), D.canon(new)
        diff = sorted(k for k in set(cr) | set(cn) if cr.get(k) != cn.get(k))
        d = C.run_l1(new, os.path.join(workdir, 'l1-%s.json' % t['object']))
        no = macho_obj.parse(open(new, 'rb').read())
        undef_spl = sorted(y['name'] for y in no['symbols'] if y['kind'] == 'UNDF' and y['name'].startswith('_spl'))
        undef_new = sorted({y['name'] for y in no['symbols'] if y['kind'] == 'UNDF' and not y['stab']} - img_names
                           - {y['name'] for y in macho_obj.parse(open(ref, 'rb').read())['symbols']
                              if y['kind'] == 'UNDF' and not y['stab']})
        rows.append(dict(object=t['object'], ref_run=rrid, ref_sha256=sha(ref), sha256=sha(new),
                         byte_identical=sha(ref) == sha(new), sections_differ=diff,
                         verdict=d['object_verdict'], ref_verdict=by_obj[t['object']], exception=EXCEPT.get(t['object'], ''), undefined_spl=undef_spl, undefined_new_not_in_original=undef_new))
    S = collections.OrderedDict()
    S['objects'] = len(rows)
    S['same_non_stabs'] = sum(1 for r in rows if not r['sections_differ'])
    S['byte_identical'] = sum(1 for r in rows if r['byte_identical'])
    S['differ'] = sorted(r['object'] for r in rows if r['sections_differ'])
    S['differ_unexpected'] = sorted(r['object'] for r in rows if r['sections_differ'] and not r['exception'])
    S['object_match'] = [sum(r['ref_verdict'] == 'OBJECT_MATCH' for r in rows), sum(r['verdict'] == 'OBJECT_MATCH' for r in rows)]
    S['undefined_spl'] = {r['object']: r['undefined_spl'] for r in rows if r['undefined_spl']}   # plan 435
    S['undefined_new_not_in_original'] = {r['object']: r['undefined_new_not_in_original'] for r in rows
                                          if r['undefined_new_not_in_original']}   # plan 437
    S['lost'] = sorted(r['object'] for r in rows if r['ref_verdict'] == 'OBJECT_MATCH' and r['verdict'] != 'OBJECT_MATCH')
    S['gained'] = sorted(r['object'] for r in rows if r['ref_verdict'] != 'OBJECT_MATCH' and r['verdict'] == 'OBJECT_MATCH')
    sm = json.load(open(stage + '.manifest.json'))
    tm = {e[0]: e[2] for e in json.load(open(TEST_STAGE + '.manifest.json'))['files']}
    nm = {e[0]: e[2] for e in sm['files']}
    S['stage_vs_test_stage'] = sorted(p for p in set(tm) | set(nm) if tm.get(p) != nm.get(p))
    G = json.load(open(gate))
    S['x86gate'] = [[g['stage'], g['same']] for g in G['stages']]
    json.dump(dict(plan=PLAN, tool='10_tools/reconstruction/stage_m68k.py', tool_sha256=sha(os.path.abspath(__file__)),
                   run=rid, stage=stage, stage_manifest_sha256=sha(stage + '.manifest.json'),
                   sdk_input=dict(dir=L.SDK, list=sm['sdk_list'], list_sha256=sm['sdk_list_sha256']),
                   base=sm['base'], base_manifest_sha256=sm['base_manifest_sha256'],
                   overlay=[[e[0], e[1], e[2]] for e in sm['files'] if e[1].startswith('07_kernel/v183.34/')],
                   overlay_replaced=sm['replaced'], overlay_added=sm['added'],
                   refs=REFS, exceptions=EXCEPT, x86gate=G, summary=S, objects=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))


def main():
    global PLAN
    a = sys.argv[1:]
    if a[:1] == ['--plan'] and len(a) >= 2 and a[1].isdigit() and int(a[1]) in EXCEPTS:   # plan 435
        PLAN = int(a[1])
        a = a[2:]
    if a[:1] == ['stage'] and len(a) == 2:
        cmd_stage(a[1])
    elif a[:1] == ['cmd'] and len(a) == 2:
        cmd_cmd(a[1])
    elif a[:1] == ['x86gate'] and len(a) == 2:
        cmd_x86gate(a[1])
    elif a[:1] == ['compare'] and len(a) == 6:
        cmd_compare(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
