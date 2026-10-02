#!/usr/bin/env python3
"""Reproducible S2-B scorer validation (plan 16.1 checks, script added in plan 27 design 4).

  s2b_validate.py SCORER.py WORKDIR OUT.json

Runs SCORER three times (normal, --shuffle-negative, --mutate-always-medium)
with PYTHONHASHSEED=0 and reports
  positive  S1-C byte-matched functions whose best candidate group contains the
            Darwin file the S1-C sample was cut from
  negative  named rows rated medium when every candidate is a random other
            definition (criterion: at most 2 %)
  mutation  named rows rated medium by the always-medium mutant (must be 100 %,
            showing the negative test can detect it)
  real_named / all   rating counts of the normal run
"""
import collections, csv, json, os, subprocess, sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))


def run(scorer, out, extra):
    env = dict(os.environ, PYTHONHASHSEED='0')
    subprocess.run([sys.executable, scorer, out + '.tsv', out + '.json'] + extra, check=True, env=env,
                   stdout=subprocess.DEVNULL, cwd=REPO)
    return [r for r in csv.DictReader((l for l in open(out + '.tsv') if not l.startswith('#')), delimiter='\t')]


def named_medium(rows):
    named = [r for r in rows if r['kind'] == 'named' and r['confidence'] != 'unknown']
    med = sum(1 for r in named if r['confidence'] == 'medium')
    return [med, len(named), 100.0 * med / len(named) if named else 0.0]


def main():
    scorer, work, out_json = sys.argv[1:4]
    os.makedirs(work, exist_ok=True)
    prov = json.load(open(os.path.join(REPO, '10_tools/reconstruction/s1c/samples-1/provenance.json')))
    s1c = json.load(open(os.path.join(REPO, '09_validation/reconstruction/s1c-options-20261001.json')))
    truth = {}
    for s in prov['samples']:
        for f in s['functions']:
            truth.setdefault(f, set()).add('darwin01/kernel/' + s['reference'])
    targets = sorted({sym for _, sym in s1c['qualified']})
    normal = run(scorer, os.path.join(work, 'normal'), [])
    by_sym = {r['symbol']: r for r in normal}
    pos = []
    for sym in targets:
        r = by_sym.get(sym)
        ok = bool(r) and any(p in r['top'] for p in truth.get(sym[1:], ()))
        pos.append(dict(symbol=sym, ok=ok, confidence=r and r['confidence'], top=r and r['top'][:200]))
    neg = named_medium(run(scorer, os.path.join(work, 'negative'), ['--shuffle-negative']))
    mut = named_medium(run(scorer, os.path.join(work, 'mutation'), ['--mutate-always-medium']))
    rep = dict(scorer=os.path.relpath(scorer, REPO) if os.path.isabs(scorer) else scorer,
               positive='%d/%d' % (sum(p['ok'] for p in pos), len(pos)), positive_detail=pos,
               negative=neg, mutation=mut, real_named=named_medium(normal),
               all=dict(collections.Counter(r['confidence'] for r in normal)))
    json.dump(rep, open(out_json, 'w'), indent=1)
    print(json.dumps({k: v for k, v in rep.items() if k != 'positive_detail'}, indent=1))


if __name__ == '__main__':
    main()
