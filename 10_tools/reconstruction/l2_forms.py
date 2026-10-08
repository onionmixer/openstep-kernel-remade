#!/usr/bin/env python3
"""l2_forms.py -- plan 394 step 2a: per-object compile form table for the D057 full rebuild.

  python3 10_tools/reconstruction/l2_forms.py OUT.tsv

For every x86 object of 06_reconstruction/objects_confirmed.tsv and objects_partial.tsv
(identity = 07 source + original __text range; objects_toolchain.tsv is linked with -lcc,
D051, and is not rebuilt) find the command lines (RUN / RUNIN of
08_build/runs/tools/<run>.cmd) that compile its 07 source, then pick one:

  0. only lines of finished runs (08_build/runs/<run>/DONE and out/run.json, the
     run.cmd it executed) whose input snapshot of the source
     (08_build/runs/<run>/src/src/<logical>) has the SHA-256 of the current 07 file
     (so a diagnostic run of a scratch copy or an older text never qualifies);
     lines with -fno-common are dropped when the object has any line without it
     (GCC27_COMPATIBILITY.md: final builds use commons);
     lines whose run staged with the D021/D022 header sets (stage manifest bsd_set
     nextos and mach_set sdk; older modes fall back to Darwin headers, stage_headers.py)
     are preferred when the object has any;
  1. among those, runs named in the object's build column or evidence file
     (basis "named"), else all (basis "current-source"); latest prepared_utc first;
  2. in that run, the output name prefix F > O3c > U > O4u > O3d > other.
  Objects with no qualifying line get basis "NONE" and must be decided by hand.

Nothing is built and no record is changed; the table is the input to plan 394 step 2b/2c
and every row says how it was chosen.  Rows that need a manual decision are marked.
"""
import sys, os, re, csv, json, glob

T = '08_build/runs/tools/'
R = '08_build/runs/'
ABS = '/BinarySourceCache_Mario1A/mk/mk-183.34.4/'
RID = re.compile(r'\b(s\d+[a-z]?\d*(?:-[A-Za-z0-9_]+)+)\b')


def finished(rid):
    return os.path.exists(R + rid + '/DONE') and os.path.exists(R + rid + '/out/run.json')


def prepared(rid):
    try:
        return json.load(open(R + rid + '/out/run.json')).get('prepared_utc', '')
    except Exception:
        return ''


def sha(path):
    import hashlib
    return hashlib.sha256(open(path, 'rb').read()).hexdigest()


_snap = {}


def snap_sha(rid, logical):
    k = (rid, logical)
    if k not in _snap:
        p = R + rid + '/src/src/' + logical
        _snap[k] = sha(p) if os.path.isfile(p) else None
    return _snap[k]


PRIO = ['F', 'O3c', 'U', 'O4u', 'O3d']


def outname(line):
    w = line.split()
    return os.path.basename(w[w.index('-o') + 1]) if '-o' in w else ''


def rank(line):
    p = outname(line).split('__')[0]
    return PRIO.index(p) if p in PRIO else len(PRIO)


def compiled_sources():
    """{logical source path under 07_kernel/src: [(run, kind, dir, line, stage options)]}
    read from the command file each finished run actually executed (08_build/runs/<run>/run.cmd);
    the stage options come from the manifest of the run's src directory when it has one."""
    out = {}
    for f in sorted(glob.glob(R + '*/run.cmd')):
        rid = f.split('/')[-2]
        if not finished(rid):
            continue
        try:
            lines = open(f, encoding='latin-1').read().splitlines()
        except OSError:
            continue
        try:
            src_dir = json.load(open(R + rid + '/out/run.json')).get('src', '')
        except Exception:
            src_dir = ''
        man = src_dir + '.manifest.json'
        opts = None
        if os.path.exists(man):
            try:
                m = json.load(open(man))
                opts = {k: m[k] for k in m if k not in ('files', 'unresolved', 'bsd_not_adopted',
                                                          'mach_not_adopted', 'mach_replaced_07')}
            except Exception:
                opts = None
        for l in lines:
            w = l.split()
            if not w or w[0] not in ('RUN', 'RUNIN') or '-c' not in w:
                continue
            d = ''
            if w[0] == 'RUNIN':
                d, w = w[1], w[2:]
            else:
                w = w[1:]
            s = w[w.index('-c') + 1]
            if s.startswith('@ABS/'):
                logical = s[len('@ABS/'):]
            elif s.startswith('src/src/'):
                logical = s[len('src/src/'):]
            elif d.startswith('src/src/'):
                logical = os.path.normpath(os.path.join(d[len('src/src/'):], s))
            else:
                continue
            out.setdefault(logical, []).append((rid, w[0] if w else '', d, ' '.join(w), opts))
    return out


def main():
    outp = sys.argv[1]
    comp = compiled_sources()
    rows = []
    for tab in ('objects_confirmed', 'objects_partial'):
        for r in csv.reader(open('06_reconstruction/%s.tsv' % tab), delimiter='\t'):
            if not r or not r[0].startswith('x86'):
                continue
            src = r[5].split(' ')[0]
            assert src.startswith('07_kernel/src/'), src
            logical = src[len('07_kernel/src/'):]
            ev = r[-1]
            text = r[6] + ' ' + (open(ev, encoding='latin-1').read() if os.path.exists(ev) else '')
            named = set(RID.findall(text))
            cur = sha(src)
            cands = [c for c in comp.get(logical, []) if snap_sha(c[0], logical) == cur]
            nofc_all = [c for c in cands if '-fno-common' not in c[3].split()]
            if nofc_all:
                cands = nofc_all
            modern = [c for c in cands if c[4] and c[4].get('bsd_set') == 'nextos' and c[4].get('mach_set') == 'sdk']
            if modern:
                cands = modern
            pick = [c for c in cands if c[0] in named]
            basis = 'named'
            if not pick:
                pick, basis = cands, 'current-source'
            if not pick:
                rows.append([r[0], tab, r[7], src, r[3], r[4], '', 'NONE', '', '', '', '', ''])
                continue
            best = max(pick, key=lambda c: prepared(c[0]))
            same = [c for c in pick if c[0] == best[0]]
            same.sort(key=lambda c: rank(c[3]))
            chosen = same[0]
            note = []
            if '-fno-common' in chosen[3].split():
                note.append('only -fno-common lines compile the current source')
            if len(same) > 1:
                note.append('%d lines for this source in the run; chose %s' % (len(same), outname(chosen[3])))
            rows.append([r[0], tab, r[7], src, r[3], r[4], chosen[0], basis, prepared(chosen[0]), chosen[2],
                         json.dumps(chosen[4], sort_keys=True) if chosen[4] is not None else '',
                         chosen[3], '; '.join(note)])
    with open(outp, 'w') as f:
        f.write('\t'.join(['object', 'table', 'grade', 'source', 'text_start', 'text_end_exclusive', 'run',
                           'basis', 'prepared_utc', 'runin_dir', 'stage_options', 'argv', 'note']) + '\n')
        for x in rows:
            f.write('\t'.join(x) + '\n')
    n = {}
    for x in rows:
        n[x[7]] = n.get(x[7], 0) + 1
    print(len(rows), 'objects;', n)


if __name__ == '__main__':
    main()
