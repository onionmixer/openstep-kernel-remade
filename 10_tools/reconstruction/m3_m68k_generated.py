#!/usr/bin/env python3
"""m3_m68k_generated.py -- plan 434 (M3-10): regenerate the 07 MIG outputs with mig -arch m68k
and compare them with the 07 files (made with -arch i386).

  python3 10_tools/reconstruction/m3_m68k_generated.py stage
  python3 10_tools/reconstruction/m3_m68k_generated.py cmd OUTDIR
  python3 10_tools/reconstruction/m3_m68k_generated.py compare RECORD.json RUN_ID...

stage    for each MIG run below, copy its input stage (prepare.json "src", every file checked
         against its manifest) to 08_build/runs/tools/m0p434-<run>-stage and add the SDK
         mach/m68k/machine_types.defs (plan 413 copy, checked against the target SHA list) at
         nextdev/mach/m68k/; manifest beside it.
cmd      OUTDIR/<run>.cmd = the run's own run.cmd with every "-arch i386" made "-arch m68k"
         (r_/n_ repeats and -nostdinc variants kept).
compare  RUN_IDs in the order of RUNS; every output of the old run is compared with the same
         path in the new run, and every 07 file that equals an old output with the new one.
Read-only apart from the outputs named above.
"""
import sys, os, json, shutil, hashlib, subprocess, collections

RUNS = ['s5p348-mig2', 's5p349-mig1', 's5p351-mig1', 's5p361-mig3', 's5p61-mig-1']
SDK = '08_build/artifacts/m0p413/sdk-m68k'
SDK_SHA = '08_build/artifacts/m0p413/sdk-m68k.target-sha.txt'
DEFS = 'mach/m68k/machine_types.defs'
K07 = ['07_kernel/src/mach', '07_kernel/src/mach_debug', '07_kernel/src/kernserv', '07_kernel/generated/mach']


def sha(p):
    h = hashlib.sha256()
    with open(p, 'rb') as f:
        for c in iter(lambda: f.read(1 << 20), b''):
            h.update(c)
    return h.hexdigest()


def src_of(run):
    return json.load(open(os.path.join('08_build/runs', run, 'prepare.json')))['src']


def stage_of(run):
    return '08_build/runs/tools/m0p434-%s-stage' % run


def sdk_defs():
    for l in open(SDK_SHA):
        h, sz, p = l.split()
        if p == '/NextDeveloper/Headers/' + DEFS:
            q = os.path.join(SDK, DEFS)
            assert sha(q) == h and os.path.getsize(q) == int(sz)
            return q, p, h
    raise SystemExit('no ' + DEFS + ' in ' + SDK_SHA)


def cmd_stage():
    q, origin, h = sdk_defs()
    for run in RUNS:
        src, dst = src_of(run), stage_of(run)
        m = json.load(open(src + '.manifest.json'))
        for e in m['files']:
            assert sha(os.path.join(src, e[0])) == e[2], e[0]
        on_disk = sorted(os.path.relpath(os.path.join(r, f), src) for r, _, fs in os.walk(src) for f in fs)
        assert on_disk == sorted(e[0] for e in m['files']), src
        assert not os.path.exists(dst), dst
        shutil.copytree(src, dst, symlinks=True)
        t = os.path.join(dst, 'nextdev', DEFS)
        assert os.path.isfile(os.path.join(dst, 'nextdev', 'mach', 'i386', 'machine_types.defs')) and not os.path.exists(t)
        os.makedirs(os.path.dirname(t))
        shutil.copyfile(q, t)
        assert sha(t) == h
        files = [list(e[:3]) for e in m['files']] + [['nextdev/' + DEFS, origin + ' (real machine; plan 413 copy)', h]]
        json.dump(dict(plan=434, base=src, base_manifest_sha256=sha(src + '.manifest.json'), sdk_list=SDK_SHA,
                       sdk_list_sha256=sha(SDK_SHA), added=['nextdev/' + DEFS], files=files),
                  open(dst + '.manifest.json', 'w'), indent=1)
        print('stage', dst, 'files', len(files))


def cmd_cmd(outdir):
    os.makedirs(outdir, exist_ok=True)
    for run in RUNS:
        L = open(os.path.join('08_build/runs', run, 'run.cmd')).read().splitlines()
        n = sum(l.count(' -arch i386 ') for l in L)
        assert n == sum(1 for l in L if l.startswith(('RUN ', 'RUNIN '))) and n > 0, run
        L = [l.replace(' -arch i386 ', ' -arch m68k ') for l in L if not l.startswith('#')]
        out = os.path.join(outdir, run + '.cmd')
        open(out, 'w').write('\n'.join(['# m3p434: plan 434 mig -arch m68k repeat of run %s (m3_m68k_generated.py cmd)' % run] + L) + '\n')
        print(out, 'commands', n)


def outputs(run):
    o = os.path.join('08_build/runs', run, 'out')
    return {os.path.relpath(os.path.join(r, f), o): sha(os.path.join(r, f))
            for r, _, fs in os.walk(o) for f in fs if '_log' not in os.path.relpath(r, o).split(os.sep)
            and os.path.relpath(os.path.join(r, f), o) != 'run.json'}   # run metadata, not a mig output


def cmd_compare(outj, new_runs):
    assert len(new_runs) == len(RUNS)
    k07 = collections.defaultdict(list)
    for d in K07:
        for f in sorted(os.listdir(d)):
            p = os.path.join(d, f)
            if os.path.isfile(p):
                k07[sha(p)].append(p)
    rows, files07 = [], []
    for old, new in zip(RUNS, new_runs):
        A, B = outputs(old), outputs(new)
        same = sorted(p for p in A if B.get(p) == A[p])
        rows.append(dict(old=old, new=new, outputs=len(A), new_outputs=len(B), same=len(same),
                         differ=sorted(p for p in A if p in B and B[p] != A[p]), missing=sorted(p for p in A if p not in B),
                         extra=sorted(p for p in B if p not in A)))
        for p, h in sorted(A.items()):
            for f in k07.get(h, []):
                files07.append(dict(file=f, old_run=old, output=p, sha256=h, new_sha256=B.get(p), same=B.get(p) == h))
    S = collections.OrderedDict()
    S['outputs'] = [sum(r['same'] for r in rows), sum(r['outputs'] for r in rows)]
    S['differ'] = {r['old']: r['differ'] for r in rows if r['differ']}
    S['missing_or_extra'] = {r['old']: [r['missing'], r['extra']] for r in rows if r['missing'] or r['extra']}
    S['files07'] = [len({x['file'] for x in files07 if all(y['same'] for y in files07 if y['file'] == x['file'])}),
                    len({x['file'] for x in files07})]
    gen = collections.OrderedDict()
    for args in ([], ['--arch', 'm68k']):
        r = subprocess.run([sys.executable, '10_tools/reconstruction/gen_config_headers.py'] + args + ['--check'],
                           stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        gen[' '.join(args) or 'x86'] = dict(check_rc=r.returncode, output=r.stdout.decode())
    gen['table_m68k'] = dict(path='06_reconstruction/config_options-m68k.tsv', sha256=sha('06_reconstruction/config_options-m68k.tsv'))
    gen['generator_sha256'] = sha('10_tools/reconstruction/gen_config_headers.py')
    gen['m68k_headers'] = {f: sha(os.path.join('07_kernel/v183.34/m68k/generated', f))
                           for f in sorted(os.listdir('07_kernel/v183.34/m68k/generated'))}
    mt = {k: [l.split() for l in open('08_build/artifacts/m3p434/mtools-%s.txt' % k)] for k in ('pre', 'post')}
    assert mt['pre'] == mt['post']
    S['generated_check_rc'] = [gen['x86']['check_rc'], gen['--arch m68k']['check_rc']]
    q, origin, h = sdk_defs()
    json.dump(dict(plan=434, config=gen, target_tools_before_after=mt['pre'], tool='10_tools/reconstruction/m3_m68k_generated.py', tool_sha256=sha(os.path.abspath(__file__)),
                   sdk_input=dict(file=q, origin=origin, sha256=h, list=SDK_SHA, list_sha256=sha(SDK_SHA)),
                   stages={r: dict(stage=stage_of(r), manifest_sha256=sha(stage_of(r) + '.manifest.json')) for r in RUNS},
                   summary=S, runs=rows, files07=files07), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))


def main():
    a = sys.argv[1:]
    if a == ['stage']:
        cmd_stage()
    elif a[:1] == ['cmd'] and len(a) == 2:
        cmd_cmd(a[1])
    elif a[:1] == ['compare'] and len(a) >= 3:
        cmd_compare(a[1], a[2:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
