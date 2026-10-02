#!/usr/bin/env python3
"""Score the S1-C option matrix against the original kernel (plan 13 / 13.1).

  score.py RUN_OUT_DIR SAMPLES_DIR REPORT.json

For every (set, sample object, function): place the object's __text by the
function names in the original symbol table, compare with l1_compare, and
classify only inside the Ghidra full-pass5 body of that function:
  BODY_MATCH   no ordinary-byte and no reference difference inside the body,
               every referenced section verified (zero-fill: placement only)
  BODY_DIFF    otherwise (count of differing bytes inside the body)
  UNPLACED     the object's names did not give one consistent placement
Padding after the body is reported separately.  Samples with no BODY_MATCH in
any set are "source uncertain" and do not count for ranking.
"""
import json, os, sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import l1_compare as L

REPO = os.path.abspath(os.path.join(HERE, '..', '..', '..'))
ORIG = os.path.join(REPO, '03_original/x86/binaries/mach_kernel')
GHIDRA = os.path.join(REPO, '04_ghidra/exports/x86/full-pass5/functions.json')


def main():
    out, sdir, report = sys.argv[1:4]
    prov = json.load(open(os.path.join(sdir, 'provenance.json')))
    sets = prov['sets']
    img = L.Image(ORIG)
    gh = {}
    for f in json.load(open(GHIDRA)):
        if not f['analysis_fragment'] and len(f['body']) == 1:
            b = f['body'][0]
            gh[f['name']] = (int(b['start'], 16), int(b['end_inclusive'], 16) + 1)
    rows = []
    for sid in sorted(sets):
        for smp in prov['samples']:
            fname = os.path.basename(smp['file'])[:-2]
            obj = os.path.join(out, '%s__%s.o' % (sid, fname))
            pl = L.placements_from_image(img, obj)
            ranges = {('_' + n): gh['_' + n] for n in smp['functions'] if '_' + n in gh}
            r = L.compare(img, obj, pl, ranges, set(pl))
            ob = open(obj, 'rb').read()
            for fn in smp['functions']:
                name = '_' + fn
                row = dict(set=sid, flags=sets[sid], sample=fname, family=smp['family'], function=name)
                fs = [f for f in r['functions'] if name in f['names']]
                if not fs or r['placements'].get('__TEXT,__text') is None:
                    row['verdict'] = 'UNPLACED'
                    rows.append(row)
                    continue
                f = fs[0]
                st, en = f['object_range']
                lo, hi = gh[name]
                img_start = f['image_range'][0]
                b0, b1 = st + (lo - img_start), st + (hi - img_start)
                body_diff = [x for x in f['diff_offsets'] if b0 <= x < b1]
                body_ref = [x for x in f['ref_diff_offsets'] if b0 <= x < b1]
                pad_diff = [x for x in f['diff_offsets'] if x >= b1]
                obj_len = en - st
                deps_bad = [d for d, v in f['data_sections'].items() if v in ('fail', 'unverified')]
                ok = lo == img_start and not body_diff and not body_ref and not deps_bad and obj_len >= hi - lo
                row.update(verdict='BODY_MATCH' if ok else 'BODY_DIFF', body_bytes=hi - lo, object_bytes=obj_len,
                           body_byte_diffs=len(body_diff), body_ref_diffs=len(body_ref),
                           padding_diffs=len(pad_diff), deps_unverified_or_failed=deps_bad,
                           start_matches=lo == img_start, l1_verdict=f['verdict'])
                rows.append(row)
    # source-uncertain samples: no BODY_MATCH in any set
    matched = {(x['sample'], x['function']) for x in rows if x['verdict'] == 'BODY_MATCH'}
    qualified = sorted(set(k for k in matched))
    summary = {}
    for sid in sorted(sets):
        rs = [x for x in rows if x['set'] == sid and (x['sample'], x['function']) in matched]
        summary[sid] = dict(flags=sets[sid], qualified_rows=len(rs),
                            body_match=sum(1 for x in rs if x['verdict'] == 'BODY_MATCH'),
                            by_family={})
        for x in rs:
            fam = summary[sid]['by_family'].setdefault(x['family'], [0, 0])
            fam[1] += 1
            fam[0] += x['verdict'] == 'BODY_MATCH'
    uncertain = sorted(set((x['sample'], x['function']) for x in rows) - matched)
    rep = dict(run=out, original_sha256='33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890',
               qualified=qualified, source_uncertain=uncertain, summary=summary, rows=rows)
    json.dump(rep, open(report, 'w'), indent=1)
    # matrix print: rows = sample/function, cols = sets
    keys = sorted(set((x['sample'], x['function']) for x in rows))
    print('%-34s %s' % ('sample/function', ' '.join(sorted(sets))))
    for k in keys:
        cells = []
        for sid in sorted(sets):
            x = [y for y in rows if y['set'] == sid and (y['sample'], y['function']) == k][0]
            if x['verdict'] == 'BODY_MATCH':
                cells.append('  M')
            elif x['verdict'] == 'UNPLACED':
                cells.append('  U')
            else:
                cells.append('%3d' % min(999, x['body_byte_diffs'] + x['body_ref_diffs']))
        print('%-34s %s' % ('%s/%s' % k, ' '.join(cells)))
    print('source uncertain:', ['%s/%s' % k for k in uncertain])
    for sid in sorted(sets):
        s = summary[sid]
        print('%s %-48s match %d/%d %s' % (sid, s['flags'] or '(no -O)', s['body_match'], s['qualified_rows'],
                                           {k: '%d/%d' % tuple(v) for k, v in sorted(s['by_family'].items())}))


if __name__ == '__main__':
    main()
