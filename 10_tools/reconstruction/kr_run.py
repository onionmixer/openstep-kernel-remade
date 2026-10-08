#!/usr/bin/env python3
"""Build-run protocol for the OPENSTEP i386 build host (plan sections 4 S1-3, 11 A2, 11.1).

  kr_run.py prepare ID SRC_DIR CMDFILE   make 08_build/runs/ID (never reuses an ID)
  kr_run.py launch ID                    start run.sh on the target via gcds (nohup)
  kr_run.py collect ID                   verify everything, then publish stage/ -> out/
  kr_run.py wait ID                      wait until DONE or FAILED exists and LOCK is released

CMDFILE lines (blank lines and '#' comments ignored):
  RUN <absolute-tool> <args...>   run in the run directory; stdout/stderr to stage/_log/NN.*
  RUNIN <dir> <absolute-tool> <args...>   (plan 297) the same, run in <dir> (relative to the run
                                  directory, under src/); an argument starting with @R/ or -I@R/
                                  has @R replaced by the run directory's absolute path;
                                  (plan 361.1) <dir> may also be stage/<name> (one level,
                                  [A-Za-z0-9_]+, not _log), made by run.sh after stage/_log,
                                  for tools that write into the current directory (mig -i)
  ABSROOT                         (plan 304, D033) point 08_build/runs/ABSROOT at this run's
                                  src/src under the LOCK; RUN/RUNIN words starting with @ABS/
                                  become /BinarySourceCache_Mario1A/mk/mk-183.34.4/ (the real
                                  machine links that path to ABSROOT)
  EXPECT <path under stage/>      required non-empty output (Mach-O magic if it ends in .o)
Arguments may only use [A-Za-z0-9_./=+,:@%-]; no shell metacharacters, no
redirection, no background.  Inputs are src/...; outputs must go to stage/...

Everything is verified with SHA-256: the target uses krsha256 (A1), the host
uses hashlib; the host (the NFS server) re-hashes every output from its disk.
"""
import hashlib, json, os, re, shutil, stat, subprocess, sys, time

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
RUNS = os.path.join(REPO, '08_build', 'runs')
REGISTRY = os.path.join(RUNS, 'REGISTRY')
TARGET_REPO = '/ndrv/openstep-kernel-remade'
KRSHA = '08_build/runs/tools/target/krsha256-default'
TOOLS_JSON = '08_build/toolchains/real-i386-20261001/sha256-vs-vm.json'
GCDS_DIR = os.path.abspath(os.path.join(REPO, '..'))          # NeXT_DRIVER/
REAL_ONLY_JSON = '08_build/toolchains/real-i386-20261001/real-only-20261002.json'
ALLOWED_TOOLS = ('/bin/cc', '/bin/as', '/bin/ld', '/usr/bin/mig', '/lib/cpp', '/usr/lib/migcom',
                 '/lib/i386/cpp', '/usr/lib/migcom3',
                 '/bin/strip')   # plan 402: strip -x of the linked kernel (Darwin Makefile.template:272)
# hashed against a real-machine-only record (no VM value; plan 86.1), all others need real == vm
REAL_ONLY_TOOLS = ('/usr/lib/migcom3',)
ARG_RE = re.compile(r'^[A-Za-z0-9_./=+,:@%-]+$')
ID_RE = re.compile(r'^[a-z0-9][a-z0-9._-]{2,60}$')
NAME_RE = re.compile(r'^[A-Za-z0-9_.,+-]+$')
STAGE_DIR_RE = re.compile(r'^stage/[A-Za-z0-9_]+$')   # plan 361.1: RUNIN output directory under stage/


def die(msg):
    sys.exit('kr_run: ' + msg)


def sha(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        for c in iter(lambda: f.read(1 << 20), b''):
            h.update(c)
    return h.hexdigest()


def kr_line(path, rel):
    """The exact line krsha256 prints: HEX SIZE PATH."""
    return '%s %d %s' % (sha(path), os.path.getsize(path), rel)


def walk_regular(root, top):
    """Relative paths of regular files under root/top; refuse anything else."""
    out, lower = [], {}
    for dp, dns, fns in os.walk(os.path.join(root, top)):
        for n in dns + fns:
            p = os.path.join(dp, n)
            rel = os.path.relpath(p, root)
            st = os.lstat(p)
            if not NAME_RE.match(n):
                die('bad file name: %s' % rel)
            if rel.lower() in lower:
                die('case collision: %s / %s' % (lower[rel.lower()], rel))
            lower[rel.lower()] = rel
            if stat.S_ISDIR(st.st_mode):
                continue
            if not stat.S_ISREG(st.st_mode):
                die('not a regular file: %s' % rel)
            if st.st_nlink != 1:
                die('hard link: %s' % rel)
            out.append(rel)
    return sorted(out)


ABS_PATH = '/BinarySourceCache_Mario1A/mk/mk-183.34.4/'   # plan 304 (D033)


def _abs_ok(no, w):
    if '@ABS' in w and (not w.startswith('@ABS/') or w.count('@ABS') > 1):
        die('line %d: bad @ABS use in %r' % (no, w))
    return w.startswith('@ABS/')


def parse_cmdfile(path):
    runs, expects = [], []
    absroot, absused = 0, False
    stagedirs = {}   # plan 361.1: lowercase -> stage/<name>
    for no, line in enumerate(open(path).read().splitlines(), 1):
        line = line.strip()
        if not line or line.startswith('#'):
            continue
        words = line.split()
        if words[0] == 'RUNIN' and len(words) >= 3:   # plan 297
            d = words[1]
            if STAGE_DIR_RE.match(d):   # plan 361.1: stage/<name>, not _log in any case, no case collision
                if d.lower() == 'stage/_log':
                    die('line %d: bad RUNIN directory %r' % (no, d))
                if stagedirs.get(d.lower(), d) != d:
                    die('line %d: RUNIN directory %r collides with %r' % (no, d, stagedirs[d.lower()]))
                stagedirs[d.lower()] = d
            elif not ARG_RE.match(d) or not d.startswith('src/') or '..' in d.split('/') or '@' in d:
                die('line %d: bad RUNIN directory %r' % (no, d))
            if words[2] not in ALLOWED_TOOLS:
                die('line %d: tool %s not allowed' % (no, words[2]))
            for w in words[3:]:
                if not ARG_RE.match(w):
                    die('line %d: bad argument %r' % (no, w))
                if '..' in w.split('/'):
                    die('line %d: ".." in %r' % (no, w))
                if '@R' in w and not (w.startswith('@R/') or w.startswith('-I@R/')) or w.count('@R') > 1:
                    die('line %d: bad @R use in %r' % (no, w))
                absused |= _abs_ok(no, w)
            runs.append(['RUNIN', d] + words[2:])
        elif words == ['ABSROOT']:   # plan 304
            absroot += 1
        elif words[0] == 'RUN' and len(words) >= 2:
            if words[1] not in ALLOWED_TOOLS:
                die('line %d: tool %s not allowed' % (no, words[1]))
            for w in words[2:]:
                if not ARG_RE.match(w):
                    die('line %d: bad argument %r' % (no, w))
                if '..' in w.split('/'):
                    die('line %d: ".." in %r' % (no, w))
                absused |= _abs_ok(no, w)
            runs.append(words[1:])
        elif words[0] == 'EXPECT' and len(words) == 2:
            if not ARG_RE.match(words[1]) or '..' in words[1].split('/') or words[1].startswith('/'):
                die('line %d: bad EXPECT path' % no)
            expects.append(words[1])
        else:
            die('line %d: unknown %r' % (no, line))
    if not runs or not expects:
        die('CMDFILE needs at least one RUN and one EXPECT')
    if absroot > 1:
        die('ABSROOT given more than once')
    if absused and not absroot:
        die('@ABS used without ABSROOT')
    if absroot:
        runs.insert(0, ['ABSROOT'])   # plan 304: marker entry, not a command
    return runs, expects


def tool_hashes():
    """{tool: {real, size}}: VM-agreed hashes, plus REAL_ONLY_TOOLS from the real-only record."""
    agreed = json.load(open(os.path.join(REPO, TOOLS_JSON)))
    real_only = json.load(open(os.path.join(REPO, REAL_ONLY_JSON)))['tools']
    out = {}
    for t in ALLOWED_TOOLS:
        if t in REAL_ONLY_TOOLS:
            r = real_only.get(t)
            if not r or not re.match(r'^[0-9a-f]{64}$', r.get('real', '')) or not isinstance(r.get('size'), int):
                die('tool %s has no real-machine hash in %s' % (t, REAL_ONLY_JSON))
            out[t] = dict(real=r['real'], size=r['size'])
        else:
            if t not in agreed or agreed[t]['real'] != agreed[t]['vm']:
                die('tool %s has no agreed hash in %s' % (t, TOOLS_JSON))
            out[t] = dict(real=agreed[t]['real'], size=agreed[t]['size'])
    return out


def registered():
    if not os.path.exists(REGISTRY):
        return set()
    return set(l.split('\t')[0] for l in open(REGISTRY).read().splitlines() if l)


def prepare(rid, src, cmdfile):
    if not ID_RE.match(rid):
        die('bad ID')
    if rid in registered():
        die('ID %s was used before (REGISTRY); IDs are never reused' % rid)
    rdir = os.path.join(RUNS, rid)
    if os.path.exists(rdir):
        die('%s exists' % rdir)
    runs, expects = parse_cmdfile(cmdfile)
    krsha = os.path.join(REPO, KRSHA)
    tools = tool_hashes()
    with open(REGISTRY, 'a') as f:                  # register first: an ID is burnt even if prepare fails
        f.write('%s\t%s\n' % (rid, time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime())))
    os.makedirs(rdir)
    shutil.copytree(src, os.path.join(rdir, 'src'), symlinks=True)
    shutil.copyfile(cmdfile, os.path.join(rdir, 'run.cmd'))
    absroot = bool(runs and runs[0] == ['ABSROOT'])
    if absroot:   # plan 304: marker inside src/src, hashed with the inputs
        runs = runs[1:]
        if not os.path.isdir(os.path.join(rdir, 'src', 'src')):
            die('ABSROOT needs src/src in SRC')
        with open(os.path.join(rdir, 'src', 'src', '.krabs'), 'w') as f:
            f.write(rid + '\n')
    files = walk_regular(rdir, 'src')
    if not files:
        die('empty SRC')
    for cmd in runs:   # plan 297: a RUNIN directory must exist in the copied tree
        if cmd[0] == 'RUNIN' and not STAGE_DIR_RE.match(cmd[1]) and not os.path.isdir(os.path.join(rdir, cmd[1])):
            die('RUNIN directory %s not in SRC' % cmd[1])
    stagedirs = []   # plan 361.1: made by run.sh after stage/_log, once each, in first-use order
    for cmd in runs:
        if cmd[0] == 'RUNIN' and STAGE_DIR_RE.match(cmd[1]) and cmd[1] not in stagedirs:
            stagedirs.append(cmd[1])
    tr = '%s/08_build/runs/%s' % (TARGET_REPO, rid)
    k = '%s/%s' % (TARGET_REPO, KRSHA)
    # expected lines, in the order the target will print them
    with open(os.path.join(rdir, 'tools.expected'), 'w') as f:
        for t in ALLOWED_TOOLS:
            f.write('%s %d %s\n' % (tools[t]['real'], tools[t]['size'], t))
    L = ['#!/bin/sh',
         '# generated by kr_run.py prepare %s -- do not edit (it is in input.expected)' % rid,
         'PATH=/bin:/usr/bin; export PATH; TZ=GMT; export TZ',
         'unset CDPATH ENV CPATH C_INCLUDE_PATH OBJC_INCLUDE_PATH LIBRARY_PATH NEXT_ROOT GCC_EXEC_PREFIX',
         'R=%s; K=%s' % (tr, k),
         'cd $R || exit 1',
         'mkdir %s/08_build/runs/LOCK 2>/dev/null || { echo LOCKED > $R/FAILED; exit 1; }' % TARGET_REPO,
         'echo "%s $$" > %s/08_build/runs/LOCK.owner' % (rid, TARGET_REPO),   # not inside LOCK: NFS silly-rename leaves .nfs* there
         'A=%s/08_build/runs/ABSROOT' % TARGET_REPO,
         'absclean() { %s }' % ('if [ -h $A ]; then rm -f $A || echo "ABSROOT cleanup failed" >> $R/FAILED; fi;' if absroot else ':;'),
         'fail() { echo "$1" > $R/FAILED; absclean; sync; rmdir %s/08_build/runs/LOCK; exit 1; }' % TARGET_REPO,
         "trap 'fail signal' 1 2 15" if absroot else ':',
         '[ -d stage ] && fail "stage exists"',
         '$K %s > input.actual 2>&1 || fail "input hash"' % ' '.join(files + ['run.cmd', 'run.sh']),
         'cmp -s input.actual input.expected || fail "input mismatch"',
         '$K %s > tools.actual 2>&1 || fail "tool hash"' % ' '.join(ALLOWED_TOOLS),
         'cmp -s tools.actual tools.expected || fail "tool mismatch"',
         'mkdir stage stage/_log || fail "mkdir stage"'] + [
         'mkdir %s || fail "mkdir %s"' % (d, d) for d in stagedirs] + [   # plan 361.1
         ': > stage/_log/status']
    if absroot:   # plan 304: replace a stale link only, then check the real-machine path reaches this run
        L += ['if [ -h $A ]; then rm -f $A || fail "ABSROOT stale link"; elif [ -f $A -o -d $A ]; then fail "ABSROOT is not a link"; fi',
              'ln -s %s/src/src $A || fail "ABSROOT ln"' % rid,
              '[ "`cat %s.krabs 2>/dev/null`" = "%s" ] || fail "ABSROOT marker"' % (ABS_PATH, rid)]
    for i, cmd in enumerate(runs):
        n = '%02d' % i
        ab = lambda w: ABS_PATH + w[len('@ABS/'):] if w.startswith('@ABS/') else w   # plan 304
        if cmd[0] == 'RUNIN':   # plan 297: (cd DIR && TOOL ARGS), @R -> $R (the run directory)
            line = '(cd %s && %s)' % (cmd[1], ' '.join(ab(w).replace('@R/', '$R/', 1) for w in cmd[2:]))
        else:
            line = ' '.join(ab(w) for w in cmd)
        L.append('%s > stage/_log/%s.out 2> stage/_log/%s.err; echo "%s $?" >> stage/_log/status'
                 % (line, n, n, n))
    L += ['$K %s > input.actual2 2>&1 || fail "input rehash"' % ' '.join(files + ['run.cmd', 'run.sh']),
          'cmp -s input.actual2 input.expected || fail "input changed during build"',
          'find stage ! -type f ! -type d -print > nonregular',
          'find stage -type f -links +1 -print > hardlinks',
          'sync',
          'find stage -type f -exec $K {} \\; > output.unsorted 2>&1 || fail "output hash"',
          'sort +2 output.unsorted > output.manifest',        # old sort: no -k
          'sync',
          'echo "%s `grep -c . stage/_log/status`" > DONE' % rid,
          'absclean',
          'sync',
          'rmdir %s/08_build/runs/LOCK' % TARGET_REPO,
          'exit 0']
    with open(os.path.join(rdir, 'run.sh'), 'w') as f:
        f.write('\n'.join(L) + '\n')
    with open(os.path.join(rdir, 'input.expected'), 'w') as f:
        for rel in files + ['run.cmd', 'run.sh']:
            f.write(kr_line(os.path.join(rdir, rel), rel) + '\n')
    meta = dict(id=rid, prepared_utc=time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime()),
                src=os.path.relpath(os.path.abspath(src), REPO), runs=runs, expects=expects,
                krsha256=dict(path=KRSHA, sha256=sha(krsha)), tools=TOOLS_JSON,
                tools_real_only=dict(record=REAL_ONLY_JSON, sha256=sha(os.path.join(REPO, REAL_ONLY_JSON)),
                                     tools=list(REAL_ONLY_TOOLS), note='real machine only, no VM cross-check'),
                tool_list=list(ALLOWED_TOOLS))
    with open(os.path.join(rdir, 'prepare.json'), 'w') as f:
        json.dump(meta, f, indent=1)
    print('prepared', rdir, '(%d input files, %d commands)' % (len(files), len(runs)))


def launch(rid):
    tr = '%s/08_build/runs/%s' % (TARGET_REPO, rid)
    if not os.path.exists(os.path.join(RUNS, rid, 'run.sh')):
        die('not prepared')
    lock = os.path.join(RUNS, 'LOCK')
    if os.path.exists(lock):                       # a previous run may still be releasing it
        owner = open(lock + '.owner').read().strip() if os.path.exists(lock + '.owner') else '?'
        die('LOCK held (%s); wait for it to go, or clear it by hand after checking the target' % owner)
    cmd = 'nohup sh %s/run.sh < /dev/null > %s/nohup.log 2>&1 & echo launched' % (tr, tr)
    env = dict(os.environ, GCDS_CONF='etc/gcds.cnf')
    r = subprocess.run(['./bin/gcds', 'next', cmd], cwd=GCDS_DIR, env=env,
                       capture_output=True, text=True, timeout=60)
    print(r.stdout.strip(), r.stderr.strip())
    if 'launched' not in r.stdout:
        die('launch failed')


def collect(rid):
    rdir = os.path.join(RUNS, rid)
    meta = json.load(open(os.path.join(rdir, 'prepare.json')))
    fails = []
    def need(c, m):
        if not c:
            fails.append(m)
    lock = os.path.join(RUNS, 'LOCK')
    if os.path.exists(lock) and os.path.exists(lock + '.owner') and open(lock + '.owner').read().split()[:1] == [rid]:
        die('run %s still holds LOCK (not finished)' % rid)
    if os.path.exists(os.path.join(rdir, 'FAILED')):
        die('target reported FAILED: ' + open(os.path.join(rdir, 'FAILED')).read().strip())
    need(os.path.exists(os.path.join(rdir, 'DONE')), 'no DONE')
    if fails:
        die('; '.join(fails))
    need(open(os.path.join(rdir, 'DONE')).read().split()[0] == rid, 'DONE has another ID')
    exp = open(os.path.join(rdir, 'input.expected')).read()
    need(open(os.path.join(rdir, 'input.actual')).read() == exp, 'input.actual differs')
    need(open(os.path.join(rdir, 'input.actual2')).read() == exp, 'input.actual2 differs')
    for line in exp.splitlines():                  # the host copy still equals what was prepared
        h, size, rel = line.split(' ')
        need(kr_line(os.path.join(rdir, rel), rel) == line, 'host input changed: %s' % rel)
    need(open(os.path.join(rdir, 'tools.actual')).read() == open(os.path.join(rdir, 'tools.expected')).read(),
         'tool hashes differ')
    need(open(os.path.join(rdir, 'nonregular')).read() == '', 'non-regular files in stage')
    need(open(os.path.join(rdir, 'hardlinks')).read() == '', 'hard links in stage')
    status = [l.split() for l in open(os.path.join(rdir, 'stage', '_log', 'status')).read().splitlines()]
    need(len(status) == len(meta['runs']), 'status lines %d != commands %d' % (len(status), len(meta['runs'])))
    for n, rc in status:
        need(rc == '0', 'command %s exit %s' % (n, rc))
    man = {}
    for line in open(os.path.join(rdir, 'output.manifest')).read().splitlines():
        h, size, rel = line.split(' ')
        man[rel] = (h, int(size))
    host_files = walk_regular(rdir, 'stage')
    need(set(host_files) == set(man), 'stage file set != manifest (%s)' % sorted(set(host_files) ^ set(man))[:5])
    for rel in host_files:
        if rel in man:
            need((sha(os.path.join(rdir, rel)), os.path.getsize(os.path.join(rdir, rel))) == man[rel],
                 'hash/size mismatch %s' % rel)
    for e in meta['expects']:
        p = os.path.join(rdir, 'stage', e)
        ok = os.path.isfile(p) and os.path.getsize(p) > 0
        if ok and e.endswith('.o'):
            ok = open(p, 'rb').read(4) in (b'\xce\xfa\xed\xfe', b'\xfe\xed\xfa\xce')
        need(ok, 'EXPECT %s missing, empty or not Mach-O' % e)
    if fails:
        print('COLLECT FAILED')
        for f in fails:
            print('  ', f)
        sys.exit(1)
    record = dict(meta, collected_utc=time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime()),
                  outputs={rel: dict(sha256=man[rel][0], size=man[rel][1]) for rel in sorted(man)},
                  status=status)
    with open(os.path.join(rdir, 'stage', 'run.json'), 'w') as f:
        json.dump(record, f, indent=1)
    os.rename(os.path.join(rdir, 'stage'), os.path.join(rdir, 'out'))
    for rel, (h, size) in man.items():             # re-check after publication
        p = os.path.join(rdir, 'out', rel[len('stage/'):])
        if sha(p) != h:
            die('changed after publication: %s' % rel)
    print('published', os.path.join(rdir, 'out'), '(%d files)' % len(man))


def wait(rid, limit=1800):
    rdir = os.path.join(RUNS, rid)
    t0 = time.time()
    while time.time() - t0 < limit:
        marker = os.path.exists(os.path.join(rdir, 'DONE')) or os.path.exists(os.path.join(rdir, 'FAILED'))
        if marker and not os.path.exists(os.path.join(RUNS, 'LOCK')):
            print('finished', rid, 'FAILED' if os.path.exists(os.path.join(rdir, 'FAILED')) else 'DONE')
            return
        time.sleep(3)
    die('timeout waiting for %s' % rid)


if __name__ == '__main__':
    a = sys.argv[1:]
    if a[:1] == ['prepare'] and len(a) == 4:
        prepare(a[1], a[2], a[3])
    elif a[:1] == ['launch'] and len(a) == 2:
        launch(a[1])
    elif a[:1] == ['collect'] and len(a) == 2:
        collect(a[1])
    elif a[:1] == ['wait'] and len(a) == 2:
        wait(a[1])
    else:
        sys.exit(__doc__)
