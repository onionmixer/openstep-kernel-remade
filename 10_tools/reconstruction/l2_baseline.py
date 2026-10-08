#!/usr/bin/env python3
"""l2_baseline.py -- plan 394 item 12: L1 baseline of the selected historical objects.

  python3 10_tools/reconstruction/l2_baseline.py FORMS.tsv OUTDIR SUMMARY.json

For every row of 06_reconstruction/l2_build_forms.tsv take the object the selected run
produced (08_build/runs/<run>/out/<output name>, SHA-256 checked against the run's
out/run.json), run l1_compare.py against the original image (--place-from-image, plus
--place-from-objc for .m sources) and write OUTDIR/<n>-<output name>.json.  The summary
checks each baseline against the recorded grade:
  A / A*  -> object_verdict OBJECT_MATCH
  P       -> object_verdict NOT_MATCH, no function verdict other than MATCH /
             MATCH_UNVERIFIED, and only "<section>: unverified" reasons
Nothing is built and no record is changed.
"""
import sys, os, csv, json, hashlib, subprocess

IMG = '03_original/x86/binaries/mach_kernel'


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def main():
    forms, outdir, summ = sys.argv[1:4]
    os.makedirs(outdir, exist_ok=True)
    rows = list(csv.DictReader(open(forms), delimiter='\t'))
    res = []
    for n, r in enumerate(rows, 1):
        w = r['argv'].split()
        name = os.path.basename(w[w.index('-o') + 1])
        obj = '08_build/runs/%s/out/%s' % (r['run'], name)
        rec = {'n': n, 'object': r['object'], 'source': r['source'], 'text_start': r['text_start'],
               'text_end_exclusive': r['text_end_exclusive'], 'grade': r['grade'], 'run': r['run'], 'obj': obj}
        try:
            outs = json.load(open('08_build/runs/%s/out/run.json' % r['run']))['outputs']
            want = outs['stage/' + name]['sha256']
        except Exception as e:
            rec['problem'] = 'no run.json output record: %s' % e
            res.append(rec)
            continue
        if not os.path.exists(obj) or sha(obj) != want:
            rec['problem'] = 'object missing or hash differs from run.json'
            res.append(rec)
            continue
        out = os.path.join(outdir, '%03d-%s.json' % (n, name[:-2]))
        cmd = [sys.executable, '10_tools/reconstruction/l1_compare.py', '--image', IMG, '--obj', obj,
               '--place-from-image'] + (['--place-from-objc'] if r['source'].endswith('.m') else []) + ['--out', out]
        p = subprocess.run(cmd, capture_output=True, text=True)
        if p.returncode != 0 or not os.path.exists(out):
            rec['problem'] = 'l1_compare failed: ' + (p.stderr or p.stdout)[-300:]
            res.append(rec)
            continue
        d = json.load(open(out))
        fv = {}
        for f in d['functions']:
            fv[f['verdict']] = fv.get(f['verdict'], 0) + 1
        rec.update(l1=out, verdict=d['object_verdict'], reasons=d['object_reasons'], function_verdicts=fv)
        g = r['grade']
        if g in ('A', 'A*'):
            rec['consistent'] = d['object_verdict'] == 'OBJECT_MATCH'
        elif g == 'P':
            rec['consistent'] = (d['object_verdict'] == 'NOT_MATCH'
                                 and set(fv) <= {'MATCH', 'MATCH_UNVERIFIED'}
                                 and all(x.endswith(': unverified') for x in d['object_reasons']))
        else:
            rec['consistent'] = None
        res.append(rec)
        print(n, r['object'], g, d['object_verdict'], rec['consistent'], flush=True)
    json.dump({'forms': forms, 'forms_sha256': sha(forms), 'image_sha256': sha(IMG), 'objects': res},
              open(summ, 'w'), indent=1)
    bad = [x for x in res if x.get('problem') or not x.get('consistent')]
    print('objects', len(res), 'inconsistent or problem', len(bad))


if __name__ == '__main__':
    main()
