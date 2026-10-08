#!/usr/bin/env python3
"""l2_forms_s6p398.py -- plan 398 step (b): forms and expectations for the plan 398 rebuild.

  python3 10_tools/reconstruction/l2_forms_s6p398.py OUT_FORMS.tsv OUT_EXPECT.json

OUT_FORMS = 06_reconstruction/l2_build_forms.tsv rows 1..385 unchanged (same row numbers as
the plan 394 baseline) + one row per new data-only object (plan 397/398), made from the row of
a template object (the neighbour whose build form the plan 397 diagnosis used): the argv with
only the -c source and the -o name replaced, the same RUNIN directory and stage options; the
run column keeps the template's run (used only for grouping and header companions), basis is
"plan398-template:<template>".

OUT_EXPECT = per-row expectations for l2_rebuild.py check (env L2_EXPECT): rows whose object is
expected to change (plan 398 item 2) or is new; "place" gives explicit section placements
(l1_compare --place) for sections without a global symbol; "verdict" is the expected object
verdict and "reasons" the expected object reasons.  Rows without an entry must stay equal to
the baseline L1.  Nothing is built.
"""
import sys, csv, json, os

FORMS = '06_reconstruction/l2_build_forms.tsv'
NEW = [  # object, 07 logical source, template object, explicit placements
    ('x86-init_sysent', 'bsd/kern/init_sysent.c', 'x86-init_main', {}),
    ('x86-tty_conf', 'bsd/kern/tty_conf.c', 'x86-tty', {}),
    ('x86-uipc_proto', 'bsd/kern/uipc_proto.c', 'x86-uipc_mbuf', {}),
    ('x86-vfs_conf', 'bsd/vfs/vfs_conf.c', 'x86-vfs_bio', {}),
    ('x86-in_proto', 'bsd/netinet/in_proto.c', 'x86-in_pcb', {}),
    ('x86-ufs_tables', 'bsd/ufs/ufs_tables.c', 'x86-ufs_subr', {}),
    ('x86-param', 'conf/param.c', 'x86-ufs_vnodeops', {}),
    ('x86-counters', 'kern/counters.c', 'x86-ast', {}),
    ('x86-machdep_call', 'machdep/i386/machdep_call.c', 'x86-machdep', {}),
    ('x86-conf', 'bsd/dev/i386/conf.c', 'x86-cons', {}),
    ('x86-ioconf', 'conf/ioconf.c', 'x86-PCemulatePROT', {}),
    ('x86-vers', 'conf/vers.c', 'x86-init_main', {}),
    ('x86-libDriver_dma', 'driverkit/libDriver/dma.c', 'x86-IODirectDevice', {}),
    ('x86-SCSIGlobals', 'driverkit/libDriver/Kernel/SCSIGlobals.m', 'x86-SCSIGeneric', {}),
    ('x86-objc_globaldata', 'objc-runtime/objc-globaldata.m', 'x86-objc_globaltext', {}),
    ('x86-objc_vers', 'objc-runtime/objc_vers.c', 'x86-objc_zone', {}),
    ('x86-libDriver_vers', 'driverkit/libDriver/vers.c', 'x86-IODirectDevice', {'__TEXT,__const': '0x1d647c'}),
]
CHANGED = {  # existing object -> (expected verdict, expected reasons, placements); plan 397 items 8, 9 and plan 398 item 0
    'x86-rtc': ('OBJECT_MATCH', [], {}),
    'x86-mfs_prim': ('OBJECT_MATCH', [], {}),
    'x86-subr_log': ('OBJECT_MATCH', [], {}),
    'x86-nfs_subr': ('NOT_MATCH', ['__DATA,__bss: unverified'], {}),
    'x86-PCinit': ('OBJECT_MATCH', [], {'__TEXT,__const': '0x1d58e4'}),
    'x86-if_vtrip': ('OBJECT_MATCH', [], {}),
    'x86-swapfs': ('NOT_MATCH', ['__DATA,__bss: unverified'], {'__TEXT,__const': '0x1d1276'}),
    'x86-ufs_alloc': ('OBJECT_MATCH', [], {'__TEXT,__const': '0x1d1280'}),
}


def main():
    out_forms, out_exp = sys.argv[1:3]
    hdr = open(FORMS).readline().rstrip('\n').split('\t')
    rows = list(csv.DictReader(open(FORMS), delimiter='\t'))
    assert len(rows) == 385, len(rows)
    by = {}
    for r in rows:
        by.setdefault(r['object'], []).append(r)
    ids = set(by)
    exp = {}
    for n, r in enumerate(rows, 1):
        if r['object'] in CHANGED:
            assert len(by[r['object']]) == 1, r['object']
            v, why, pl = CHANGED[r['object']]
            exp[str(n)] = {'object': r['object'], 'verdict': v, 'reasons': why, 'place': pl, 'kind': 'changed'}
    assert len(exp) == len(CHANGED), sorted(exp)
    new_rows = []
    for obj, src, tmpl, pl in NEW:
        assert obj not in ids, obj
        assert os.path.isfile('07_kernel/src/' + src), src
        t = by[tmpl]
        assert len(t) == 1, tmpl
        t = dict(t[0])
        w = t['argv'].split()
        i, o = w.index('-c'), w.index('-o')
        if t['runin_dir']:
            w[i + 1] = os.path.relpath(src, t['runin_dir'][len('src/src/'):])
        else:
            w[i + 1] = 'src/src/' + src
        name = os.path.basename(w[o + 1])
        prefix = name.split('__', 1)[0]
        w[o + 1] = os.path.join(os.path.dirname(w[o + 1]), '%s__%s.o' % (prefix, obj[len('x86-'):]))
        t.update({'object': obj, 'table': 'objects_data', 'grade': 'A', 'source': '07_kernel/src/' + src,
                  'text_start': '', 'text_end_exclusive': '', 'basis': 'plan398-template:' + tmpl,
                  'argv': ' '.join(w), 'note': 'plan 398: new data-only object; form of ' + tmpl})
        new_rows.append(t)
        exp[str(len(rows) + len(new_rows))] = {'object': obj, 'verdict': 'OBJECT_MATCH', 'reasons': [], 'place': pl,
                                               'kind': 'new'}
    with open(out_forms, 'w') as f:
        f.write('\t'.join(hdr) + '\n')
        for r in rows + new_rows:
            f.write('\t'.join(r[h] for h in hdr) + '\n')
    json.dump({'forms': out_forms, 'expect': exp}, open(out_exp, 'w'), indent=1, sort_keys=True)
    print('rows', len(rows) + len(new_rows), 'expectations', len(exp))


if __name__ == '__main__':
    main()
