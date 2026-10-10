#!/usr/bin/env python3
"""m3_m68k_offsets.py -- plan 443 (M3-19): offset/size probe of the m68k overlay structs and of
Mach structs against the original m68k bytes, plus the M3 closure evidence summary.

  python3 10_tools/reconstruction/m3_m68k_offsets.py stage STAGE_DIR
  python3 10_tools/reconstruction/m3_m68k_offsets.py cmd PROBE.cmd
  python3 10_tools/reconstruction/m3_m68k_offsets.py compare RUN_ID RECORD.json

stage    copy of 08_build/runs/tools/m0p441-stage (manifest-checked) + src/probe/m68k_offsets.c
         (written by this tool; plan 443.1 list), manifest beside it.
cmd      the kern/ast.c compile line of run m3p441-cc1 with source src/src/probe/m68k_offsets.c
         and output stage/P443__m68k_offsets.o.
compare  reads the marker-bracketed table from the probe object's __DATA,__data (big-endian
         words) and compares with the expected values (original-byte evidence in EXPECT);
         aggregates the M3 evidence (ABI record, diagnosis block kinds, generators, counts).
"""
import sys, os, json, shutil, subprocess, collections, hashlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj

BASE = '08_build/runs/tools/m0p441-stage'
CC = '08_build/artifacts/m3p441/cc.cmd'
PROBE = 'probe/m68k_offsets.c'
OUT = 'P443__m68k_offsets.o'
START, END = 0x4b524d33, 0x454e4421          # "KRM3", "END!"
# name, C expression, expected value or None, evidence
EXPECT = [
    ('pcb.pcb_regs', 'KR_OFF(struct pcb, pcb_regs)', 0x48, '_init_task 0x4002df2 movel a0@(0x48),d0'),
    ('pcb.pcb_regs_valid', 'KR_OFF(struct pcb, pcb_regs_valid)', 0x4c, '_init_task 0x4002dec tstl a0@(0x4c)'),
    ('pcb.pcb_flags', 'KR_OFF(struct pcb, pcb_flags)', 0x54, 'aston 0x4049464-0x404946e bset #4,a0@(0x54); 0x40494ae bclr'),
    ('pmap.stats.resident_count', 'KR_OFF(struct pmap, stats.resident_count)', 0x10, '_task_info 0x4052588 movel a0@(0x10),d3'),
    ('mon_global.mg_minor', 'KR_OFF(struct mon_global, mg_minor)', 0x30a, '_panic 0x400bcbe movew a3@(0x30a)'),
    ('mon_global.mg_seq', 'KR_OFF(struct mon_global, mg_seq)', 0x30c, '_panic 0x400bcb8 movew a3@(0x30c)'),
    ('mon_global.mg_anim_run', 'KR_OFF(struct mon_global, mg_anim_run)', 0x30e, '0x408a490/0x408acaa/0x40946e6 movel aN@(0x30e),d0'),
    ('mon_global.mg_major', 'KR_OFF(struct mon_global, mg_major)', 0x312, '_panic 0x400bcc4 movew a3@(0x312)'),
    ('regs.r_evec', 'KR_OFF(struct regs, r_evec)', 0x40, '_ptrace 0x400aee8 orl d0,a3@(0x40); 0x400af40 bset #7,a3@(0x40)'),
    ('regs.r_pc', 'KR_OFF(struct regs, r_pc)', 0x42, '_execve 0x4005044 movew ...,a0@(0x42)'),
    ('sizeof excp_frame', 'sizeof(struct excp_frame)', None, 'no original evidence (recorded only)'),
    ('sizeof regs', 'sizeof(struct regs)', None, 'no original evidence (recorded only)'),
    ('sizeof task', 'sizeof(struct task)', 0x80, '_task_init 0x4051ddc pea 0x80 (zinit element size)'),
    ('sizeof thread', 'sizeof(struct thread)', 0x184, '_thread_init 0x40527ec pea 0x184 (zinit element size)'),
    ('thread.pcb', 'KR_OFF(struct thread, pcb)', 0x24, '_init_task 0x4002de8 / aston movel a0@(0x24),a0'),
    ('task.map', 'KR_OFF(struct task, map)', 0x8, '_task_info 0x4052572 movel a4@(0x8),a0'),
    ('vm_map.pmap', 'KR_OFF(struct vm_map, pmap)', 0x20, '_task_info 0x4052584 movel a0@(0x20),a0'),
]
HEADERS = ['mach_host.h', 'mach/machine/vm_types.h', 'mach/vm_param.h', 'kern/task.h', 'kern/thread.h', 'vm/vm_map.h',
           'machdep/m68k/thread.h', 'machdep/m68k/pmap.h', 'mon/global.h', 'bsd/m68k/reg.h']


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def probe_text():
    L = ['/* plan 443 probe (m3_m68k_offsets.py): struct offsets/sizes as initialized data; MONITOR undefined */']
    L += ['#include <%s>' % h for h in HEADERS]
    L += ['#define KR_OFF(t, f) ((unsigned long)&((t *)0)->f)', '', 'unsigned long kr_m3_offsets[] = {', '    0x%xUL,' % START]
    L += ['    %s,\t/* %s */' % (e[1], e[0]) for e in EXPECT]
    L += ['    0x%xUL' % END, '};', '']
    return '\n'.join(L)


def cmd_stage(stage):
    m = json.load(open(BASE + '.manifest.json'))
    for e in m['files']:
        assert sha(os.path.join(BASE, e[0])) == e[2], e[0]
    assert not os.path.exists(stage)
    shutil.copytree(BASE, stage, symlinks=True)
    p = os.path.join(stage, 'src', PROBE)
    os.makedirs(os.path.dirname(p))
    open(p, 'w').write(probe_text())
    files = [list(e[:3]) for e in m['files']] + [['src/' + PROBE, 'plan 443 probe (m3_m68k_offsets.py)', sha(p)]]
    json.dump(dict(plan=443, base=BASE, base_manifest_sha256=sha(BASE + '.manifest.json'), added=['src/' + PROBE], files=files),
              open(stage + '.manifest.json', 'w'), indent=1)
    print('stage', stage, 'files', len(files))


def cmd_cmd(out):
    line = [l.rstrip('\n') for l in open(CC) if l.startswith('RUN ') and ' src/src/kern/ast.c ' in l]
    assert len(line) == 1
    w = line[0].split()
    w[w.index('-c') + 1] = 'src/src/' + PROBE
    w[w.index('-o') + 1] = 'stage/' + OUT
    open(out, 'w').write('# m3p443: plan 443 offset probe (m3_m68k_offsets.py cmd)\n' + ' '.join(w) + '\nEXPECT ' + OUT + '\n')
    print(' '.join(w)[-120:])


def kinds_of(path, key):
    r = json.load(open(path))
    c = collections.Counter()
    for row in r[key]:
        for b in row['blocks']:
            c[b['kind']] += 1
    return dict(c)


def cmd_compare(rid, outj):
    p = os.path.join('08_build/runs', rid, 'out', OUT)
    ob = open(p, 'rb').read()
    o = macho_obj.parse(ob)
    d = [s for s in o['sections'] if (s['segname'], s['sectname']) == ('__DATA', '__data')][0]
    data = ob[d['offset']:d['offset'] + d['size']]
    words = [int.from_bytes(data[i:i + 4], 'big') for i in range(0, len(data) - 3, 4)]
    i0 = words.index(START)
    vals = words[i0 + 1:i0 + 1 + len(EXPECT)]
    assert words[i0 + 1 + len(EXPECT)] == END
    rows = []
    for (name, expr, exp, ev), v in zip(EXPECT, vals):
        rows.append(dict(name=name, expr=expr, value='0x%x' % v, expected=None if exp is None else '0x%x' % exp,
                         equal=None if exp is None else v == exp, evidence=ev))
    gen = {}
    for args in ([], ['--arch', 'm68k']):
        r = subprocess.run([sys.executable, '10_tools/reconstruction/gen_config_headers.py'] + args + ['--check'],
                           stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        gen[' '.join(args) or 'x86'] = r.returncode
    S = collections.OrderedDict()
    S['probe'] = [sum(1 for r in rows if r['equal']), sum(1 for r in rows if r['equal'] is not None)]
    S['probe_mismatch'] = [r['name'] for r in rows if r['equal'] is False]
    S['abi_record'] = '09_validation/reconstruction/m0-abi-m68k-20261009.json'
    S['diag_kinds'] = {'plan 431': kinds_of('09_validation/reconstruction/m3-m68k-diag2-20261009.json', 'spans'),
                       'plan 436': kinds_of('09_validation/reconstruction/m3-m68k-diag3-20261009.json', 'rows')}
    S['diag_note'] = 'D-struct counts blocks whose only difference is a non-frame displacement; X/R blocks are not proof of absence'
    S['generators_check_rc'] = gen
    S['mig_record'] = '09_validation/reconstruction/m3-m68k-generated-20261009.json'
    nr = json.load(open('09_validation/reconstruction/m3-m68k-need-ast-20261009.json'))['summary']
    S['m68k_objects'] = dict(compiled=nr['objects'], object_match=nr['object_match'][1])
    ex = json.load(open('09_validation/reconstruction/m2-m68k-boundaries-built4-20261009.json'))['summary']['objects_exactness']
    S['exact_objects'] = [ex['exact_after'], ex['pct_after']]
    json.dump(dict(plan=443, tool='10_tools/reconstruction/m3_m68k_offsets.py', tool_sha256=sha(os.path.abspath(__file__)),
                   run=rid, probe_object_sha256=sha(p), summary=S, probe=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))
    for r in rows:
        print('%-26s %-6s %-6s %s' % (r['name'], r['value'], r['expected'], r['equal']))


def main():
    a = sys.argv[1:]
    if a[:1] == ['stage'] and len(a) == 2:
        cmd_stage(a[1])
    elif a[:1] == ['cmd'] and len(a) == 2:
        cmd_cmd(a[1])
    elif a[:1] == ['compare'] and len(a) == 3:
        cmd_compare(a[1], a[2])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
