#!/usr/bin/env python3
"""m3_m68k_machdep.py -- plan 430 (M3-6): test-only m68k machdep headers in a copy of the plan 427
stage; the 120 objects that failed in plan 429 are compiled and compared (plan 430.1).

  python3 10_tools/reconstruction/m3_m68k_machdep.py stage ITER
  python3 10_tools/reconstruction/m3_m68k_machdep.py cmd CC.cmd
  python3 10_tools/reconstruction/m3_m68k_machdep.py diag RUN_ID DIAG.json
  python3 10_tools/reconstruction/m3_m68k_machdep.py compare RUN_ID WORKDIR RECORD.json

stage    08_build/runs/tools/m0p430-stage-ITER = m0p427-stage + src/machdep/m68k/*.h (short headers
         written here for measurement only; eventc.h copied at run time from NeXTMach mk-108.1
         with its import lines mapped) + an m68k branch after the i386 branch of the seven
         src/machdep/machine dispatchers.  Nothing here goes into 07.
Read-only apart from the stage, command file, WORKDIR and records.
"""
import sys, os, re, json, shutil, collections, csv

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m0_m68k_cause as C
import m3_m68k_wide as W

BASE = '08_build/runs/tools/m0p427-stage'
NM = '01_resources/upstream/nextmach/mk-108.1'
DIAG429 = '08_build/artifacts/m3p429/diag.json'
PFX = 'M430__'
DISPATCH = ['machspl', 'pmap', 'thread', 'ast', 'mach_param', 'xpr', 'time_stamp']
HDR = {
    'machspl.h': '''/* plan 430 test-only m68k header (measurement; not 07) */
#ifndef _MACHDEP_M68K_MACHSPL_H_
#define _MACHDEP_M68K_MACHSPL_H_
typedef int spl_t;
#import <bsd/m68k/spl.h>
#endif
''',
    'pmap.h': '''/* plan 430 test-only m68k header (measurement; not 07) */
#ifndef _MACHDEP_M68K_PMAP_H_
#define _MACHDEP_M68K_PMAP_H_
#import <mach/vm_statistics.h>
#import <mach/m68k/vm_param.h>
struct pmap {
	unsigned int		mmu_rp[2];
	void			*pt1;
	int			ref_count;
	struct pmap_statistics	stats;		/* resident_count at 0x10 (_task_info) */
};
typedef struct pmap *pmap_t;
#define PMAP_NULL	((pmap_t) 0)
#define PMAP_ACTIVATE(pmap, thread, cpu)
#define PMAP_DEACTIVATE(pmap, thread, cpu)
#define PMAP_CONTEXT(pmap, thread)
#define pmap_resident_count(pmap)	((pmap)->stats.resident_count)
#define pmap_phys_address(frame)	((vm_offset_t) (m68k_ptob(frame)))
#define pmap_phys_to_frame(phys)	((unsigned int) (m68k_btop(phys)))
#endif
''',
    'thread.h': '''/* plan 430 test-only m68k header (measurement; not 07) */
#ifndef _MACHDEP_M68K_THREAD_H_
#define _MACHDEP_M68K_THREAD_H_
struct pcb {
	char	pcb_head[0x48];
	void	*pcb_regs;		/* +0x48: returned by USER_REGS (_init_task) */
	int	pcb_regs_valid;		/* +0x4c: tested by USER_REGS (_init_task) */
};
typedef struct pcb *pcb_t;
extern void *thread_user_state();
#define current_stack_pointer()	(stack_pointers[cpu_number()])
#define USER_REGS(thread) \\
    ((thread)->pcb->pcb_regs_valid ? (thread)->pcb->pcb_regs : (void *)thread_user_state(thread))
#define pcb_synch(thread)
#define pcb_common_init(task)
#define pcb_common_terminate(task)
#endif
''',
    'ast.h': '''/* plan 430 test-only m68k header (measurement; not 07): MACHINE_AST_PER_THREAD not defined */
#ifndef _MACHDEP_M68K_AST_H_
#define _MACHDEP_M68K_AST_H_
#endif
''',
    'mach_param.h': '''/* plan 430 test-only m68k header (measurement; not 07): original _hz = 64, _tick = 15625 */
#define	HZ	(64)
''',
    'xpr.h': '''/* plan 430 test-only m68k header (measurement; not 07) */
#ifndef _MACHDEP_M68K_XPR_H_
#define _MACHDEP_M68K_XPR_H_
#ifdef	KERNEL_BUILD
#import "uxpr.h"
#import "xpr_debug.h"
#endif
#import <machdep/m68k/eventc.h>
#import <mach/machine.h>	/* iteration 2: i386 gets it through the DriverKit chain of its xpr.h */
#define XPR_TIMESTAMP	event_get()
#endif
''',
    'time_stamp.h': '''/* plan 430 test-only m68k header (measurement; not 07) */
#ifndef _MACHDEP_M68K_TIME_STAMP_
#define _MACHDEP_M68K_TIME_STAMP_
#define TS_FORMAT TS_FORMAT_NeXT
#endif
''',
}
EVENTC_MAP = {'<next/cpu.h>': '<bsd/m68k/cpu.h>', '<next/spl.h>': '<bsd/m68k/spl.h>', '<sys/time_stamp.h>': '<kern/time_stamp.h>'}
sha = C.sha


def failed_bases():
    return [r['base'] for r in json.load(open(DIAG429))['rows'] if r['rc'] != 0]


def cmd_stage(it):
    stage = '08_build/runs/tools/m0p430-stage-%s' % it
    m = json.load(open(BASE + '.manifest.json'))
    assert not os.path.exists(stage)
    for e in m['files']:
        assert sha(os.path.join(BASE, e[0])) == e[2], e[0]
    shutil.copytree(BASE, stage, symlinks=True)
    d = os.path.join(stage, 'src/machdep/m68k')
    os.makedirs(d)
    added, changed = [], []
    for name, text in HDR.items():
        open(os.path.join(d, name), 'w').write(text)
        added.append(['src/machdep/m68k/' + name, 'plan 430 test-only header'])
    ev = open(os.path.join(NM, 'next/eventc.h')).read()
    for a, b in EVENTC_MAP.items():
        assert ev.count(a) == 1, a
        ev = ev.replace(a, b)
    open(os.path.join(d, 'eventc.h'), 'w').write(ev)
    added.append(['src/machdep/m68k/eventc.h', 'copied from %s/next/eventc.h, imports mapped %s' % (NM, EVENTC_MAP)])
    for h in DISPATCH:
        p = os.path.join(stage, 'src/machdep/machine/%s.h' % h)
        t = open(p).read()
        a = '#elif defined (__i386__)\n#include "machdep/i386/%s.h"\n' % h
        assert t.count(a) == 1, h
        os.chmod(p, 0o644)
        open(p, 'w').write(t.replace(a, a + '#elif defined (__m68k__)\n#include "machdep/m68k/%s.h"\n' % h))
        changed.append('src/machdep/machine/%s.h' % h)
    files = []
    chg = set(changed)
    for e in m['files']:
        h = sha(os.path.join(stage, e[0]))
        if e[0] in chg:
            files.append([e[0], 'plan 430: m68k branch added after the i386 branch', h])
        else:
            assert h == e[2], e[0]
            files.append(e[:3])
    for a in added:
        files.append([a[0], a[1], sha(os.path.join(stage, a[0]))])
    on_disk = sorted(os.path.relpath(os.path.join(r, f), stage) for r, _, fs in os.walk(stage) for f in fs)
    assert on_disk == sorted(e[0] for e in files)
    json.dump(dict(plan=430, base=BASE, base_manifest_sha256=sha(BASE + '.manifest.json'), changed=changed,
                   added=[a[0] for a in added], files=files), open(stage + '.manifest.json', 'w'), indent=1)
    print('stage', stage, 'files', len(files), 'added', len(added), 'changed', len(changed))


SOURCE_SIDE = {'L2_140__mach_process': 'PC (i386 register index) at bsd/kern/mach_process.c:170',
               'L2_208__kern_exec': 'PC (i386 register index) at bsd/kern/kern_exec.c:482',
               'L2_338__ns_timer': 'i386 inline asm divl at kern/ns_timer.c:43,47,147,150'}


def cmd_cmd(out, drop_source_side=False):
    fb = set(failed_bases())
    T = [t for t in W.targets() if t['base'] in fb]
    assert len(T) == 120
    if drop_source_side:
        T = [t for t in T if t['base'] not in SOURCE_SIDE]
    L = [W.m68k_line(t['line'], 'stage/%s%s.o' % (PFX, t['base'])) for t in T]
    E = ['EXPECT %s%s.o' % (PFX, t['base']) for t in T]
    open(out, 'w').write('\n'.join(['# m3p430: plan 430 m68k compile of the 120 machdep-blocked objects (m3_m68k_machdep.py cmd)']
                                   + L + E) + '\n')
    print('commands', len(L))


def cmd_diag(rid, outj):
    rdir = os.path.join('08_build/runs', rid)
    published = os.path.exists(os.path.join(rdir, 'out'))
    base_dir = os.path.join(rdir, 'out' if published else 'stage')
    if not published:
        man = {l.split()[-1]: l.split()[0] for l in open(os.path.join(rdir, 'output.manifest')).read().splitlines()}
        for p, h in man.items():
            if '/_log/' in p:
                assert sha(os.path.join(rdir, p)) == h, p
    runs = [l for l in open(os.path.join(rdir, 'run.cmd')).read().splitlines() if l.startswith('RUN ')]
    status = dict(l.split() for l in open(os.path.join(base_dir, '_log', 'status')).read().splitlines())
    rows, cls = [], collections.Counter()
    for i, l in enumerate(runs):
        base = l.split()[-1][len('stage/' + PFX):-2]
        rc = int(status['%02d' % i])
        err = open(os.path.join(base_dir, '_log', '%02d.err' % i), errors='replace').read().splitlines()
        errs = [e for e in err if re.search(r'error|No such file|undeclared|undefined', e, re.I) and 'warning' not in e]
        kinds = sorted({re.sub(r'^\S+?:\d+: ', '', e)[:90] for e in errs})
        for k in kinds:
            cls[k] += 1
        rows.append(dict(base=base, rc=rc, errors=kinds[:20], files=sorted({e.split(':')[0] for e in errs})))
    S = dict(published=published, commands=len(rows), failed=sum(1 for r in rows if r['rc']),
             error_kinds=dict(cls.most_common(40)))
    json.dump(dict(plan=430, run=rid, summary=S, rows=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))


def cmd_compare(rid, workdir, outj):
    syms = {r['name'] for r in csv.DictReader(open('03_original/m68k/inventory/symbols.tsv'), delimiter='\t')}
    T = {t['base']: t for t in W.targets() if t['base'] in set(failed_bases())}
    img = C.Img()
    os.makedirs(workdir, exist_ok=True)
    rows = []
    for base, t in sorted(T.items()):
        p = os.path.join('08_build/runs', rid, 'out', '%s%s.o' % (PFX, base))
        if not os.path.exists(p):
            continue
        o = macho_obj.parse(open(p, 'rb').read())
        und = sorted({y['name'] for y in o['symbols'] if y['kind'] == 'UNDF' and y.get('ext')} - syms)
        xo = macho_obj.parse(open(t['obj'], 'rb').read())
        xt = [s for s in xo['sections'] if (s['segname'], s['sectname']) == ('__TEXT', '__text')]
        ext = [y['name'] for y in xo['symbols'] if xt and y['kind'] == 'SECT' and y.get('ext') and not y['stab']
               and y['sect'] == xt[0]['index']]
        d = C.run_l1(p, os.path.join(workdir, 'l1-%s.json' % t['object']))
        _, ts, spans = C.compare_object(img, p, ext)
        f = [x for x in d['functions'] if x['section'] == '__TEXT,__text']
        rows.append(dict(object=t['object'], grade=t['grade'], i386_slice=t['i386_slice'], verdict=d['object_verdict'],
                         undefined_not_in_original=und, text_size=ts['size'],
                         functions=dict(collections.Counter(x['verdict'] for x in f)),
                         function_bytes=sum(x['object_range'][1] - x['object_range'][0] for x in f if x['verdict'] == 'MATCH'),
                         spans_equal=sum(1 for s in spans if s.get('equal')), spans=sum(1 for s in spans if 'image_address' in s)))
    S = collections.OrderedDict()
    S['compiled'] = len(rows)
    S['object_match'] = sum(r['verdict'] == 'OBJECT_MATCH' for r in rows)
    S['clean_set'] = [sum(1 for r in rows if r['grade'] == 'A' and r['i386_slice'] == 'OBJECT_MATCH' and r['verdict'] == 'OBJECT_MATCH'),
                      sum(1 for r in rows if r['grade'] == 'A' and r['i386_slice'] == 'OBJECT_MATCH')]
    S['functions'] = dict(sum((collections.Counter(r['functions']) for r in rows), collections.Counter()))
    S['match_bytes'] = [sum(r['function_bytes'] for r in rows), sum(r['text_size'] for r in rows)]
    S['spans_equal'] = [sum(r['spans_equal'] for r in rows), sum(r['spans'] for r in rows)]
    S['objects_with_undefined_not_in_original'] = {r['object']: r['undefined_not_in_original'] for r in rows if r['undefined_not_in_original']}
    S['undefined_not_in_original_names'] = dict(collections.Counter(n for r in rows for n in r['undefined_not_in_original']))
    json.dump(dict(plan=430, tool='10_tools/reconstruction/m3_m68k_machdep.py', tool_sha256=sha(os.path.abspath(__file__)),
                   run=rid, summary=S, objects=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))


def main():
    a = sys.argv[1:]
    if a[:1] == ['stage'] and len(a) == 2:
        cmd_stage(a[1])
    elif a[:1] == ['cmd'] and len(a) == 2:
        cmd_cmd(a[1])
    elif a[:1] == ['cmd2'] and len(a) == 2:
        cmd_cmd(a[1], drop_source_side=True)
    elif a[:1] == ['diag'] and len(a) == 3:
        cmd_diag(a[1], a[2])
    elif a[:1] == ['compare'] and len(a) == 4:
        cmd_compare(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
