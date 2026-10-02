#!/usr/bin/env python3
"""S2-A: candidate map of the original __text by object file (plan 15 / 15.1).

  s2a_objects.py OUT.tsv REPORT.json

This is analysis, not confirmation: it never reports a confirmed boundary.
Confidence: B (labelled neighbours, data order consistent), C (name labels
only or data conflict), U (unassigned).  A is given only later by L1 matches.
"""
import bisect, collections, csv, json, os, re, struct, sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import capstone
import l1_compare as L
import srcdefs
import objc_meta

REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
UP = os.path.join(REPO, '01_resources', 'upstream')
TREES = [('darwin01', os.path.join(UP, 'darwin01', 'kernel')), ('darwin01-dk', os.path.join(UP, 'darwin01', 'driverkit-1')),
         ('nextmach', os.path.join(UP, 'nextmach')), ('mach4', os.path.join(UP, 'mach4'))]
CDEF = re.compile(r'^([A-Za-z_]\w*)\s*\(', re.M)
ADEF = re.compile(r'(?:ENTRY|Entry|ENTRY2|LEAF)\s*\(\s*(\w+)|^_(\w+):', re.M)


def definitions():
    where = collections.defaultdict(set)
    for tree, root in TREES:
        for dp, dn, fn in os.walk(root):
            if '/.git' in dp or '/CVS' in dp:
                continue
            for f in fn:
                p = os.path.join(dp, f)
                rel = os.path.relpath(p, UP)
                if f.endswith(('.c', '.m')):
                    for name, a0, b0, h in srcdefs.find(open(p, errors='replace').read().splitlines()):
                        where[name].add(rel)
                elif f.endswith(('.s', '.S')):
                    for m in ADEF.finditer(open(p, errors='replace').read()):
                        where[m.group(1) or m.group(2)].add(rel)
    return where


def main():
    out_tsv, out_json = sys.argv[1:3]
    img = L.Image(os.path.join(REPO, '03_original/x86/binaries/mach_kernel'))
    text = [s for s in img.secs if s['sectname'] == '__text'][0]
    data = [s for s in img.secs if s['sectname'] == '__data'][0]
    funcs = [f for f in json.load(open(os.path.join(REPO, '04_ghidra/exports/x86/full-pass5/functions.json')))
             if not f['analysis_fragment']]
    funcs.sort(key=lambda f: int(f['address'], 16))
    ext = {}
    for r in csv.DictReader(open(os.path.join(REPO, '03_original/x86/inventory/symbols.tsv')), delimiter='\t'):
        if r['type'] == '0xf':
            ext.setdefault(int(r['section']), {})[r['name']] = int(r['value'], 16)
    text_names = set(ext.get(1, {}))
    data_ext_addrs = set(ext.get(4, {}).values())
    where = definitions()
    meta = objc_meta.Meta(img).read()
    imp_module = {}
    cls_mod = {c['name']: c['module'] for c in meta['classes']}
    cat_mod = {(c['class_name'], c['name']): c['module'] for c in meta['categories']}
    for m in meta['methods']:
        mod = cat_mod[(m['owner'], m['category'])] if m['category'] else cls_mod[m['owner']]
        imp_module[m['imp']] = mod

    rows = []
    for f in funcs:
        a = int(f['address'], 16)
        ranges = [(int(b['start'], 16), int(b['end_inclusive'], 16) + 1) for b in f['body']]
        nbytes = sum(e - s for s, e in ranges)
        labels, cands, kind = set(), [], 'unlabelled'
        if a in imp_module:
            mod = imp_module[a]
            labels = {os.path.basename(mod)}
            cands = ['objc module ' + mod]
            kind = 'objc'
        elif f['name'] in text_names:
            c = sorted(where.get(f['name'][1:], ()))
            if c:
                labels = {os.path.basename(x) for x in c}
                cands = c
                kind = 'name'
            else:
                kind = 'named-no-reference'
        rows.append(dict(address=a, name=f['name'], bytes=nbytes, ranges=ranges, labels=labels,
                         candidates=cands, kind=kind))

    # runs over labelled functions
    runs = []
    for i, r in enumerate(rows):
        if not r['labels']:
            continue
        if runs and runs[-1]['labels'] & r['labels']:
            runs[-1]['labels'] &= r['labels']
            runs[-1]['members'].append(i)
        else:
            runs.append(dict(labels=set(r['labels']), members=[i]))
    for k, run in enumerate(runs):
        first, last = run['members'][0], run['members'][-1]
        run['probable_statics'] = [j for j in range(first, last + 1)
                                   if not rows[j]['labels'] and rows[j]['kind'] != 'named-no-reference']
        run['named_unlabelled_inside'] = [j for j in range(first, last + 1) if rows[j]['kind'] == 'named-no-reference']
        run['start'] = rows[first]['address']
        run['end'] = max(e for s, e in rows[last]['ranges'])
    # validated references text -> anonymous __data
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    starts = [r['address'] for r in rows]
    owner = {}
    for k, run in enumerate(runs):
        for j in range(run['members'][0], run['members'][-1] + 1):
            owner[j] = k
    stats = collections.Counter()
    refs_by_run = collections.defaultdict(list)
    for row in csv.DictReader(open(os.path.join(REPO, '04_ghidra/exports/x86/full-pass5/references.tsv')), delimiter='\t'):
        if row['type'] not in ('READ', 'WRITE', 'READ_WRITE', 'DATA') or not row['to'].startswith('0x0'):
            continue
        frm, to = int(row['from'], 16), int(row['to'], 16)
        if not (data['addr'] <= to < data['addr'] + data['size']) or not (text['addr'] <= frm < text['addr'] + text['size']):
            continue
        stats['candidate'] += 1
        if to in data_ext_addrs:
            stats['excluded_extern_symbol'] += 1
            continue
        insn = next(md.disasm(img.read(frm, 15), frm), None)
        ok = False
        if insn is not None:
            for op in insn.operands:
                if (op.type == capstone.x86.X86_OP_IMM and (op.imm & 0xffffffff) == to) or \
                   (op.type == capstone.x86.X86_OP_MEM and (op.mem.disp & 0xffffffff) == to):
                    ok = True
        if not ok:
            stats['rejected_by_decoding'] += 1
            continue
        stats['validated'] += 1
        j = bisect.bisect_right(starts, frm) - 1
        if j >= 0 and any(s <= frm < e for s, e in rows[j]['ranges']) and j in owner:
            refs_by_run[owner[j]].append(to)
            stats['used_in_run'] += 1
    # median-based order diagnostic (robust to a few references into other objects' data)
    meds = []
    for k, run in enumerate(runs):
        ds = sorted(refs_by_run.get(k, []))
        if ds:
            meds.append((k, ds[len(ds) // 2]))
    med_inversions = sum(1 for i in range(1, len(meds)) if meds[i][1] < meds[i - 1][1])
    prev = None
    violations = []
    for k, run in enumerate(runs):
        ds = refs_by_run.get(k, [])
        run['data_min'] = min(ds) if ds else None
        run['data_max'] = max(ds) if ds else None
        run['data_refs'] = len(ds)
        run['data_conflict'] = False
        if ds:
            if prev is not None and runs[prev]['data_max'] >= run['data_min']:
                run['data_conflict'] = True
                runs[prev]['data_conflict'] = True
                violations.append((prev, k))
            prev = k
    # Darwin conf/files order (diagnostic)
    order = []
    for fn in ('conf/files', 'conf/files.i386'):
        p = os.path.join(UP, 'darwin01', 'kernel', fn)
        for line in open(p, errors='replace'):
            w = line.split()
            if w and not w[0].startswith('#') and w[0].endswith(('.c', '.m', '.s')):
                order.append(os.path.basename(w[0]))
    pos = {b: i for i, b in enumerate(order)}
    seq = [min(pos[b] for b in run['labels'] if b in pos) for run in runs if any(b in pos for b in run['labels'])]
    tails = []                                             # longest increasing subsequence length
    for x in seq:
        i = bisect.bisect_left(tails, x)
        tails[i:i + 1] = [x]
    # bytes accounting
    in_run = set(j for run in runs for j in range(run['members'][0], run['members'][-1] + 1))
    acc = collections.Counter()
    for j, r in enumerate(rows):
        acc['labelled' if r['labels'] else ('inside_run' if j in in_run else 'unassigned')] += r['bytes']
    with open(out_tsv, 'w') as o:
        o.write('seq\tconfidence\tlabels\ttext_start\ttext_end\tstart_lower_bound\tend_upper_bound\tlabelled_functions\t'
                'probable_statics\tnamed_without_reference_inside\tdata_refs\tdata_min\tdata_max\tdata_conflict\tcandidates\n')
        for k, run in enumerate(runs):
            lo = runs[k - 1]['end'] if k else text['addr']
            hi = runs[k + 1]['start'] if k + 1 < len(runs) else text['addr'] + text['size']
            conf = 'B' if len(run['members']) >= 2 and not run['data_conflict'] else 'C'
            cands = sorted(set(c for j in run['members'] for c in rows[j]['candidates']
                               if os.path.basename(c.replace('objc module ', '')) in run['labels']))
            o.write('\t'.join(str(x) for x in (
                k, conf, ','.join(sorted(run['labels'])), hex(run['start']), hex(run['end']), hex(lo), hex(hi),
                len(run['members']), len(run['probable_statics']), len(run['named_unlabelled_inside']), run['data_refs'],
                hex(run['data_min']) if run['data_min'] else '', hex(run['data_max']) if run['data_max'] else '',
                run['data_conflict'], ';'.join(cands)[:2000])) + '\n')
    rep = dict(text_bytes=text['size'], functions=len(rows),
               function_kinds=collections.Counter(r['kind'] for r in rows),
               runs=len(runs), confidence=collections.Counter('B' if len(r['members']) >= 2 and not r['data_conflict'] else 'C' for r in runs),
               files_in_more_than_one_run=sorted(k for k, v in collections.Counter(
                   b for r in runs for b in r['labels'] if len(r['labels']) == 1).items() if v > 1),
               byte_accounting=dict(acc), reference_stats=dict(stats), data_order_violations=len(violations),
               data_median_order=dict(runs_with_data=len(meds), adjacent_inversions=med_inversions),
               darwin_conf_files_order=dict(runs_with_position=len(seq), longest_increasing=len(tails)))
    json.dump(rep, open(out_json, 'w'), indent=1, default=list)
    print(json.dumps(rep, indent=1, default=list))


if __name__ == '__main__':
    main()
