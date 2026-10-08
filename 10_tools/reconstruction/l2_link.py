#!/usr/bin/env python3
"""l2_link.py -- plan 399 (L2-1): prepare a trial link of the rebuilt objects.

  python3 10_tools/reconstruction/l2_link.py prepare RID RESULTS_PREFIX

RESULTS_PREFIX selects the rebuild results 09_validation/reconstruction/s6-l1-*-<prefix>-*.json
(one record per forms row, rows 1..N; every row must equal its baseline or meet its plan 398
expectation, no problem; object SHA-256 checked).  Nothing is built here: the tool writes

  08_build/runs/tools/RID-src/objs/NNN__<name>.o   copies of the objects (SHA-256 checked)
  08_build/runs/tools/RID.cmd                      kr_run commands (below)
  08_build/runs/tools/RID.link.json                the link list and its basis

and prints the kr_run commands.  Link order (plan 399 item 0, verdicts in items 6-8):
  - objects with __text: original __text address order (L1 placement);
  - data-only objects: after the object named in AFTER (each within the range the original
    section placement allows, choice from the cited Darwin build lists);
  - the run is cut into: LDOBJS (libc + OBJS + ioconf), the libDriver bundle (from the
    object after ioconf through machdepFuncs.c, data-only members in order, libDriver vers
    last; Darwin driverkit-1/libDriver/Makefile:631 `$(LD) -r -o $@ $(OFILES) vers.o`),
    the libobjc bundle (HashTable.m .. objc-sel.m in original order, objc_vers last;
    Darwin objc/Makefile.postamble:155 `ld -r`), the mach user stubs, vers.o;
  - commands: ld -r libDriver, ld -r libobjc, then
    /bin/ld -static -e _start -segaddr __TEXT 0x100000 -segaddr __LINKEDIT 0x780000
      -segalign 0x1000 -force_cpusubtype_ALL -u __muldi3 -o stage/mach_kernel
      <LDOBJS> stage/libDriver_kern.o stage/libkobjc.o <mach stubs> <vers.o> -lcc
    (Darwin 0.1 conf/Makefile.i386:55-64, Makefile.template:386-387), linked as stage/mach_kernel.sys;
  - plan 402: /bin/strip -x -o stage/mach_kernel stage/mach_kernel.sys (Darwin 0.1
    conf/Makefile.template:272 SYS_RULE_2=strip -x -o $@ $@.sys).
"""
import sys, os, json, glob, hashlib, shutil

V = '09_validation/reconstruction/'
T = '08_build/runs/tools/'

# data-only object (07 path under src/) -> the object (07 path) it follows in the link
AFTER = {
    'bsd/kern/init_sysent.c': 'bsd/kern/init_main.c',          # only allowed position; files:361-362
    'bsd/kern/tty_conf.c': 'bsd/kern/tty.c',                   # files:396-399 tty, tty_compat, tty_conf, tty_pty
    'bsd/kern/uipc_proto.c': 'bsd/kern/uipc_mbuf.c',           # files:403-404
    'bsd/vfs/vfs_conf.c': 'bsd/vfs/vfs_bio.c',                 # only allowed position; files:131/134
    'bsd/netinet/in_proto.c': 'bsd/netinet/in_pcb.c',          # only allowed position; files:220-222
    'bsd/ufs/ufs_tables.c': 'bsd/ufs/ufs_subr.c',              # only allowed position
    'conf/param.c': 'bsd/ufs/ufs_vnodeops.c',                  # allowed ufs_vnodeops..ipc_init; files:410-412 param before ipc
    'kern/counters.c': 'kern/ast.c',                           # only allowed position; files:431-433
    'machdep/i386/machdep_call.c': 'machdep/i386/machdep.c',   # only allowed position; files.i386:36-38
    'bsd/dev/i386/conf.c': 'driverkit/i386/autoconf_i386.m',   # files.i386:47-50 autoconf_i386, conf, cons
    'conf/ioconf.c': 'machdep/i386/pc_support/PCemulatePROT.c',  # Makefile.template:232 ${OBJS} subr_prof.o ioconf.o
    'driverkit/libDriver/dma.c': 'driverkit/disk_label.c',     # libDriver Makefile:117 disk_label.c dma.c label_subr.c
    'driverkit/libDriver/Kernel/SCSIGlobals.m': 'driverkit/libDriver/Kernel/SCSIGeneric.m',  # Makefile:110-111
    'objc-runtime/objc-globaldata.m': 'objc-runtime/objc-errors.m',  # objc *.o name order
    'objc-runtime/objc_vers.c': 'objc-runtime/objc-sel.m',     # only allowed position; last member
    'driverkit/libDriver/vers.c': 'driverkit/machdepFuncs.c',  # libDriver Makefile:631 OFILES vers.o
    'conf/vers.c': 'mach/vm_write.c',                          # Makefile.template:386-387 ... $(MACH_OFILES) vers.o
}
LD = ['/bin/ld', '-static', '-e', '_start', '-segaddr', '__TEXT', '0x100000', '-segaddr', '__LINKEDIT', '0x780000',
      '-segalign', '0x1000', '-force_cpusubtype_ALL', '-u', '__muldi3']


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def load(prefix):
    rows = {}
    for f in sorted(glob.glob(V + 's6-l1-*-%s-*.json' % prefix)):
        for x in json.load(open(f))['objects']:
            assert x['n'] not in rows, x['n']
            assert (x.get('same_as_baseline') or x.get('expected_ok')) and not x.get('problem'), x['n']
            assert sha(x['obj']) == x['obj_sha256'], x['n']
            rows[x['n']] = x
    assert sorted(rows) == list(range(1, len(rows) + 1)), 'rows not contiguous'
    return rows


def link_order(rows):
    src = {n: x['source'][len('07_kernel/src/'):] for n, x in rows.items()}
    text = {}
    for n, x in rows.items():
        t = (json.load(open(x['l1']))['sections'].get('__TEXT,__text') or {}).get('address')
        if t is not None:
            text[n] = t
    order = sorted(text, key=lambda n: text[n])
    by_src = {}
    for n in rows:
        by_src.setdefault(src[n], []).append(n)
    data_only = [n for n in rows if n not in text]
    assert sorted(src[n] for n in data_only) == sorted(AFTER), sorted(src[n] for n in data_only)
    # insert data-only objects; chains (an AFTER target that is itself data-only) are not used
    for s, after in AFTER.items():
        (n,), (a,) = by_src[s], by_src[after]
        order.insert(order.index(a) + 1, n)
    return order, src


def cmd_prepare(rid, prefix):
    rows = load(prefix)
    order, src = link_order(rows)
    S = [src[n] for n in order]
    i_io = S.index('conf/ioconf.c')
    i_mdf = S.index('driverkit/libDriver/vers.c')
    assert S[i_mdf - 1] == 'driverkit/machdepFuncs.c'
    i_ht = S.index('objc-runtime/HashTable/HashTable.m')
    assert i_ht == i_mdf + 1
    i_ov = S.index('objc-runtime/objc_vers.c')
    i_v = S.index('conf/vers.c')
    assert i_v == len(S) - 1
    ldobjs, libdrv, libobjc, mach, vers = order[:i_io + 1], order[i_io + 1:i_mdf + 1], order[i_ht:i_ov + 1], \
        order[i_ov + 1:i_v], order[i_v:]
    assert all(S[k].startswith('mach/') for k in range(i_ov + 1, i_v)), 'non-stub in the mach range'
    assert all(src[n].startswith('objc-runtime/') for n in libobjc)
    sd = T + rid + '-src'
    cmdf = T + rid + '.cmd'
    for p in (sd, cmdf, T + rid + '.link.json'):
        if os.path.exists(p):
            raise SystemExit('%s exists' % p)
    os.makedirs(sd + '/objs')
    name = {}
    for k, n in enumerate(order, 1):
        b = '%03d__%s' % (k, os.path.basename(rows[n]['obj']).split('__', 1)[1])
        dst = sd + '/objs/' + b
        shutil.copyfile(rows[n]['obj'], dst)
        assert sha(dst) == rows[n]['obj_sha256']
        name[n] = 'src/objs/' + b
    lines = ['# %s: plan 399/402 link (diagnosis) of the %s rebuild (%d objects; l2_link.py)' % (rid, prefix, len(order)),
             'RUN /bin/ld -r -o stage/libDriver_kern.o ' + ' '.join(name[n] for n in libdrv),
             'RUN /bin/ld -r -o stage/libkobjc.o ' + ' '.join(name[n] for n in libobjc),
             'RUN ' + ' '.join(LD + ['-o', 'stage/mach_kernel.sys'] + [name[n] for n in ldobjs] +
                                ['stage/libDriver_kern.o', 'stage/libkobjc.o'] + [name[n] for n in mach + vers] + ['-lcc']),
             'RUN /bin/strip -x -o stage/mach_kernel stage/mach_kernel.sys',
             'EXPECT libDriver_kern.o', 'EXPECT libkobjc.o', 'EXPECT mach_kernel.sys', 'EXPECT mach_kernel']
    open(cmdf, 'w').write('\n'.join(lines) + '\n')
    rec = {'rid': rid, 'results_prefix': prefix, 'objects': len(order),
           'parts': {'ldobjs': [src[n] for n in ldobjs], 'libDriver': [src[n] for n in libdrv],
                     'libobjc': [src[n] for n in libobjc], 'mach': [src[n] for n in mach], 'vers': [src[n] for n in vers]},
           'rows': [{'n': n, 'source': src[n], 'obj': rows[n]['obj'], 'sha256': rows[n]['obj_sha256'], 'copy': name[n]}
                    for n in order],
           'after': AFTER, 'ld': LD, 'libs': ['-lcc (/lib/libcc.a)'], 'strip': ['/bin/strip', '-x']}
    json.dump(rec, open(T + rid + '.link.json', 'w'), indent=1)
    print('parts', {k: len(v) for k, v in rec['parts'].items()}, 'command lengths', [len(l) for l in lines[1:5]])
    print('next: python3 10_tools/reconstruction/kr_run.py prepare %s %s %s; launch; wait; collect' % (rid, sd, cmdf))


if __name__ == '__main__':
    a = sys.argv[1:]
    if len(a) == 3 and a[0] == 'prepare':
        cmd_prepare(a[1], a[2])
    else:
        raise SystemExit(__doc__)
