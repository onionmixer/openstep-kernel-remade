#!/usr/bin/env python3
"""S2-C: Darwin 0.1 vs NeXTMach per original function and per S2-A run (plan 26.1).

  s2c_source_choice.py DETAIL.tsv OUT.tsv REPORT.json

DETAIL.tsv is s2b_candidates.py --detail.  Per original function the best
current weighted score of each family is compared:
  darwin   = trees darwin01, darwin01-dk
  nextmach = tree nextmach, path_class 'kernel' only (m68k/standalone paths
             are counted separately and never win)
Categories: feature0 (original has no scoring feature), darwin_only,
nextmach_only, tie, darwin_better, nextmach_better, neither (no candidate in
either family).  The per-run 'priority' is an exploration-order hint only
(plan 26.1): 'darwin' or 'nextmach' when that side wins at least 3 functions
and at least twice the other side, otherwise 'mixed/undetermined'.  It is
not evidence about the original; ties and absences are not votes.
"""
import bisect, collections, csv, json, os, sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
FAM = {'darwin01': 'darwin', 'darwin01-dk': 'darwin', 'nextmach': 'nextmach'}


def main():
    detail, out_tsv, out_json = sys.argv[1:4]
    per = collections.defaultdict(lambda: dict(darwin=None, nextmach=None, nextmach_m68k=None, weight=0.0, symbol=''))
    for r in csv.DictReader(open(detail), delimiter='\t', quoting=csv.QUOTE_NONE):
        f = per[int(r['va'], 16)]
        f['weight'] = float(r['original_feature_weight'])
        f['symbol'] = r['symbol']
        fam = FAM.get(r['tree'])
        if fam is None:
            continue
        key = fam if not (fam == 'nextmach' and r['path_class'] != 'kernel') else 'nextmach_m68k'
        s = float(r['score'])
        if f[key] is None or s > f[key]:
            f[key] = s
    cat = {}
    for va, f in per.items():
        d, n = f['darwin'], f['nextmach']
        if f['weight'] == 0:
            c = 'feature0'
        elif d is None and n is None:
            c = 'neither'
        elif n is None:
            c = 'darwin_only'
        elif d is None:
            c = 'nextmach_only'
        elif d == n:
            c = 'tie'
        else:
            c = 'darwin_better' if d > n else 'nextmach_better'
        cat[va] = c
    runs = list(csv.DictReader(open(os.path.join(REPO, '06_reconstruction/objects.tsv')), delimiter='\t'))
    starts = [int(r['text_start'], 16) for r in runs]
    cols = ['feature0', 'neither', 'darwin_only', 'nextmach_only', 'tie', 'darwin_better', 'nextmach_better']
    agg = collections.defaultdict(collections.Counter)
    for va, c in cat.items():
        i = bisect.bisect_right(starts, va) - 1
        if i >= 0 and va < int(runs[i]['text_end'], 16):
            agg[i][c] += 1
    prio = collections.Counter()
    with open(out_tsv, 'w') as o:
        o.write('# S2-C exploration-order hint per S2-A run (plan 26.1); not evidence about the original\n')
        o.write('seq\tlabels\ttext_start\ttext_end\t' + '\t'.join(cols) + '\tpriority\n')
        for i, r in enumerate(runs):
            a = agg.get(i, collections.Counter())
            db, nb = a['darwin_better'], a['nextmach_better']
            p = 'mixed/undetermined'
            if db >= 3 and db >= 2 * nb:
                p = 'darwin'
            elif nb >= 3 and nb >= 2 * db:
                p = 'nextmach'
            prio[p] += 1
            o.write('\t'.join([r['seq'], r['labels'], r['text_start'], r['text_end']] + [str(a[c]) for c in cols] + [p]) + '\n')
    rep = dict(functions=len(cat), categories=dict(collections.Counter(cat.values())), runs=len(runs), priority=dict(prio))
    json.dump(rep, open(out_json, 'w'), indent=1)
    print(json.dumps(rep, indent=1))


if __name__ == '__main__':
    main()
