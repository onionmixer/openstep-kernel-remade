#!/usr/bin/env python3
"""Stage a source file and the textual closure of its includes for a build run
(plan sections 20 / 20.2).

  stage_headers.py STAGE_DIR SOURCE_REL [SOURCE_REL ...]
  stage_headers.py --list SOURCE_REL ...      print the closure only
  --prefer-07   take a file from 07_kernel/<logical path> when it exists (plan 29.1)
  --nextdev     append the OPENSTEP 4.2 /NextDeveloper/Headers roots (decision D018,
                plan 73.1): Headers, Headers/bsd, Headers/ansi after all other roots,
                staged as nextdev/...; '#include ARCH_INCLUDE(p, s)' is followed as
                p + 'i386/' + s (the build is -arch i386); every nextdev file must match
                the real-machine SHA-256 list in
                09_validation/reconstruction/s4c-nextdev-headers-20261002.json
  --subst MAP.json   (with --nextdev; decision D020, plan 83.1-83.2) per-name
                substitution: MAP is {logical path: "sdk:<Headers-relative>" |
                "nextmach:<mk-108.1-relative>"}.  Keys are src/bsd/... names; the
                substitute is read in place of the Darwin file and staged under the
                same logical path (no -I change); its own includes resolve as usual.
                SDK files must match the real-machine SHA list, NeXTMach files the
                blob of commit NEXTMACH_COMMIT (no symlinks); a 07_kernel copy at a
                key under --prefer-07 is an error.  Checked before --list too.
  --bsd-set nextos   (with --nextdev; decision D021, plan 131-131.2) every logical
                src/bsd/X (also the SDK aliases bsd/X and nextdev/bsd/X) is read from
                the real-machine SDK Headers/bsd/X (include/X: Headers/ansi/X or bsd/X),
                or from NeXTMach mk-108.1 when the SDK has no such file or the file is
                in KERNEL_STRIPPED; never from Darwin or 07_kernel.  Names found in
                neither are recorded as unresolved with bsd_set: true.  An authored
                private header 07_kernel/nextdev_private/bsd/X (names the SDK strips or
                lacks, plan 132) is read before the SDK; its evidence is in PROVENANCE.tsv.
                With --prefer-07 the adopted copies 07_kernel/nextdev/<SDK path> and
                07_kernel/nextmach/<mk-108.1 path> are read before the local SDK/NeXTMach
                copies (plan 133); they must be byte-identical to the real-machine list /
                the pinned NeXTMach blob, and a BSD header read from outside 07_kernel is
                listed in the manifest under bsd_not_adopted (a final build needs none).
                Since plan 133 the BSD headers of 07_kernel live only there; the mode
                without --bsd-set falls back to Darwin for them and no longer describes
                the reconstructed source.
  --mach-set sdk   (with --nextdev; decision D022, plan 134) a header at a logical
                src/mach/X, src/kernserv/X, components/architecture/X or
                components/driverkit-1/driverkit/X whose name the real-machine SDK has
                (Headers/mach/X, kernserv/X, architecture/X, driverkit/X) is read from
                the SDK (with --prefer-07 the copy 07_kernel/nextdev/<SDK path> first);
                the SDK aliases nextdev/mach/X etc. map to those logical paths.  An
                authored 07_kernel/nextdev_private/<SDK path> (SDK text plus the kernel-
                private branch, plan 136) is read first.  Names
                the SDK lacks, and the public-form SDK headers in MACH_KERNEL_STRIPPED,
                keep the 07_kernel -> Darwin rule.  Since plan 135 the adopted SDK copies
                live in 07_kernel/nextdev/ only; without --mach-set those names fall back to
                Darwin and no longer describe the reconstructed source.

  --source-override LOGICAL=KIND:PATH   (diagnosis, plan 137; repeatable) read the
                source LOGICAL (src/<dir>/<name>.c) from mach4:<repo path> (Mach4
                MACH4_COMMIT) or nextmach:<mk-108.1 path> (NEXTMACH_COMMIT) instead of
                07_kernel/Darwin; the file must equal the pinned blob.  Its includes
                resolve from LOGICAL as usual (headers stay 07/SDK/Darwin).

SOURCE_REL is relative to the Darwin 0.1 kernel tree (e.g.
machdep/i386/libc/pagesize.c).  Every #include/#import is followed in every
conditional branch.  Resolution follows the build's include roots, quoted
names first in the including file's directory:

  -Isrc/generated              07_kernel/generated
  -Isrc/src                    darwin01/kernel
  -Isrc/src/bsd                darwin01/kernel/bsd
  -Isrc/src/bsd/include        darwin01/kernel/bsd/include
  -Isrc/src/machdep            darwin01/kernel/machdep
  -Isrc/components             darwin01            (architecture/...)
  -Isrc/components/architecture darwin01/architecture
  -Isrc/components/driverkit-1 darwin01/driverkit-1   (driverkit/... private headers, plan 81.1)

Unresolved names are recorded, not errors (whether they matter is decided by
preprocessing on the target).  STAGE_DIR must not exist; files are copied
byte for byte to src/..., components/architecture/..., generated/... and
STAGE_DIR.manifest.json lists [staged path, origin, sha256] plus the
unresolved includes.
"""
import hashlib, json, os, re, shutil, sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
UP = os.path.join(REPO, '01_resources', 'upstream')
D01 = os.path.join(UP, 'darwin01')
KERNEL = os.path.join(D01, 'kernel')
ARCH = os.path.join(D01, 'architecture')
GEN = os.path.join(REPO, '07_kernel', 'generated')
ROOTS = [GEN, KERNEL, os.path.join(KERNEL, 'bsd'), os.path.join(KERNEL, 'bsd', 'include'),
         os.path.join(KERNEL, 'machdep'), D01, ARCH,
         os.path.join(D01, 'driverkit-1')]   # Darwin driverkit headers (PrivateHeaders), plan 81.1
INC = re.compile(r'^\s*#\s*(?:include|import)\s*([<"])([^>"]+)[>"]')
ARCH_INC = re.compile(r'^\s*#\s*(?:include|import)\s*ARCH_INCLUDE\(\s*([^,\s]+)\s*,\s*([^)\s]+)\s*\)')
NEXTDEV = os.path.join(REPO, '01_resources', 'local_mirrors', 'headers', 'NextDeveloper', 'Headers')
NEXTDEV_ROOTS = [NEXTDEV, os.path.join(NEXTDEV, 'bsd'), os.path.join(NEXTDEV, 'ansi')]
NEXTDEV_LIST = os.path.join(REPO, '09_validation', 'reconstruction', 's4c-nextdev-headers-20261002.json')
TARGET_HEADERS = '/NextDeveloper/Headers'
NEXTMACH_REPO = os.path.join(UP, 'nextmach')
NEXTMACH = os.path.join(NEXTMACH_REPO, 'mk-108.1')
NEXTMACH_URL = 'https://github.com/johnsonjh/NeXTMach.git'
NEXTMACH_COMMIT = 'f6bdb9c3268f0eadc545d41bcc0564453b17001e'
MACH4_REPO = os.path.join(UP, 'mach4')
MACH4_URL = 'https://github.com/openmach/mach4.git'
MACH4_COMMIT = '69fa77870f20d854c875135e116ebc80b118e7ff'
OVERRIDE = {}   # logical source -> dict(file, note), --source-override (plan 137)
NEXTMACH_DIRS = ('sys', 'net', 'netinet', 'nfs', 'ufs', 'specfs', 'rpc', 'rpcsvc', 'nextif', 'netns',
                 'netimp', 'krpc')


K07 = os.path.join(REPO, '07_kernel')
PRIVATE = os.path.join(K07, 'nextdev_private')   # authored private BSD headers (plan 132)


def logical_of(path):
    """Logical stage path of a Darwin or generated path (same mapping as before plan 29.1)."""
    p = os.path.normpath(path)
    for base, pre in ((GEN, 'generated'), (KERNEL, 'src'), (ARCH, os.path.join('components', 'architecture')),
                      (D01, 'components'), (NEXTDEV, 'nextdev')):
        b = os.path.normpath(base) + os.sep
        if p.startswith(b):
            return os.path.join(pre, p[len(b):])
    raise SystemExit('stage_headers: %s is outside the staged trees' % path)


def darwin_of(logical):
    """Darwin (or generated) path of a logical stage path, or None."""
    for pre, base in (('generated', GEN), (os.path.join('components', 'architecture'), ARCH), ('src', KERNEL),
                      ('components', D01), ('nextdev', NEXTDEV)):
        if logical == pre or logical.startswith(pre + os.sep):
            return os.path.normpath(os.path.join(base, logical[len(pre) + 1:]))
    return None


KERNEL_STRIPPED = ('sys/ux_exception.h', 'sys/callout.h', 'sys/kernel.h')   # SDK copy lacks the kernel part (plan 83.1)
BSDSET = {'on': False}
MACHSET = {'on': False}
# SDK copies that are the public form (kernel-private branch removed; plan 134.2-134.5): not taken by --mach-set
MACH_KERNEL_STRIPPED = ('mach/mach_types.h', 'mach/std_types.h', 'mach/mach_traps.h', 'kernserv/lock.h',
                        'kernserv/clock_timer.h', 'kernserv/ns_timer.h', 'kernserv/prototypes.h')
# logical prefix -> SDK Headers prefix (decision D022, plan 134)
MACH_MAP = ((os.path.join('src', 'mach') + os.sep, 'mach' + os.sep),
            (os.path.join('src', 'kernserv') + os.sep, 'kernserv' + os.sep),
            (os.path.join('components', 'architecture') + os.sep, 'architecture' + os.sep),
            (os.path.join('components', 'driverkit-1', 'driverkit') + os.sep, 'driverkit' + os.sep))


def canonical(logical):
    """With --bsd-set, SDK aliases of BSD names map to the one logical path src/bsd/X;
    with --mach-set, nextdev/<SDK prefix>X maps to its MACH_MAP logical path."""
    if MACHSET['on']:
        for lp, sp in MACH_MAP:
            pre = os.path.join('nextdev', sp)
            if logical.startswith(pre):
                return lp + logical[len(pre):]
    if not BSDSET['on']:
        return logical
    for pre in (os.path.join('nextdev', 'bsd') + os.sep, os.path.join('src', 'bsd', 'bsd') + os.sep):
        if logical.startswith(pre):
            return os.path.join('src', 'bsd', logical[len(pre):])
    return logical


def bsd_pick(rel, prefer07=False):
    """(file, kind, source path) for a BSD name under --bsd-set, or None.  kind is
    authored, sdk or nextmach; sdk07/nextmach07 for the adopted 07_kernel copies."""
    sub = rel.split(os.sep)[0]
    if sub == 'include':
        name = rel[len('include') + 1:]
        cands = [os.path.join('ansi', name), os.path.join('bsd', name)]
    else:
        cands = [os.path.join('bsd', rel)]
        f = os.path.join(PRIVATE, 'bsd', rel)
        if os.path.isfile(f):
            _no_symlink(PRIVATE, os.path.join('bsd', rel))
            return f, 'authored', os.path.join('bsd', rel)
    if rel not in KERNEL_STRIPPED:
        for c in cands:
            f = os.path.join(K07, 'nextdev', c)
            if prefer07 and os.path.isfile(f):
                return f, 'sdk07', c
            f = os.path.join(NEXTDEV, c)
            if os.path.isfile(f):
                return f, 'sdk', c
    if sub in NEXTMACH_DIRS:
        f = os.path.join(K07, 'nextmach', rel)
        if prefer07 and os.path.isfile(f):
            return f, 'nextmach07', rel
        f = os.path.join(NEXTMACH, rel)
        if os.path.isfile(f) and not os.path.islink(f):
            return f, 'nextmach', rel
    return None


def mach_pick(logical, prefer07=False):
    """(file, kind, SDK path) for a --mach-set name the SDK has, or None; kind authored
    (07_kernel/nextdev_private, plan 136), sdk07 or sdk."""
    if not logical.endswith('.h'):
        return None
    for lp, sp in MACH_MAP:
        if logical.startswith(lp):
            name = sp + logical[len(lp):]
            f = os.path.join(PRIVATE, name)
            if os.path.isfile(f):
                _no_symlink(PRIVATE, name)
                return f, 'authored', name
            if name in MACH_KERNEL_STRIPPED:
                return None
            f = os.path.join(K07, 'nextdev', name)
            if prefer07 and os.path.isfile(f):
                return f, 'sdk07', name
            f = os.path.join(NEXTDEV, name)
            if os.path.isfile(f):
                _no_symlink(NEXTDEV, name)
                return f, 'sdk', name
            return None
    return None


def select(logical, prefer07, subst=None):
    """The file to read for a logical path: a --subst entry, else the 07_kernel copy first
    with --prefer-07, else Darwin."""
    if logical in OVERRIDE:
        return OVERRIDE[logical]['file']
    if subst and logical in subst:
        return subst[logical]['file']
    bsdpre = os.path.join('src', 'bsd') + os.sep
    if BSDSET['on'] and logical.startswith(bsdpre) and logical.endswith('.h'):   # headers only; BSD sources stay
        hit = bsd_pick(logical[len(bsdpre):], prefer07)
        return hit[0] if hit else None
    if MACHSET['on']:
        hit = mach_pick(logical, prefer07)
        if hit:
            return hit[0]
    cands = []
    if prefer07 and not logical.startswith('generated' + os.sep):
        cands.append(os.path.join(K07, logical))
    d = darwin_of(logical)
    if d:
        cands.append(d)
    return next((c for c in cands if os.path.isfile(c)), None)


def staged_name(path):
    """Logical stage path of an actual file (Darwin, generated or 07_kernel copy)."""
    p = os.path.normpath(path)
    b = os.path.normpath(K07) + os.sep
    if p.startswith(b) and not p.startswith(os.path.normpath(GEN) + os.sep):
        return p[len(b):]
    return logical_of(p)


def origin(path):
    p = os.path.realpath(path)
    for base, pre in ((K07, '07_kernel'), (UP, '')):
        b = os.path.realpath(base) + os.sep
        if p.startswith(b):
            return os.path.join(pre, p[len(b):]) if pre else p[len(b):]
    return p


def closure(sources, prefer07=False, nextdev=False, subst=None):
    """Follow #include/#import over logical paths (plan 29.1); returns (logical path, actual file)
    pairs in reading order and the unresolved includes."""
    roots = ROOTS + (NEXTDEV_ROOTS if nextdev else [])
    seen, order, unresolved = set(), [], []
    todo = []
    for s_ in sources:
        lg = logical_of(os.path.join(KERNEL, s_))
        f = select(lg, prefer07, subst)
        if f is None:
            raise SystemExit('stage_headers: no such source %s' % s_)
        todo.append((lg, f))
    # every build reads -imacros src/generated/meta_features.h (plan 48.2); stage it and its imports
    meta = os.path.join(GEN, 'meta_features.h')
    if os.path.isfile(meta):
        todo.append((logical_of(meta), meta))
    while todo:
        lg, f = todo.pop(0)
        if lg in seen:
            continue
        seen.add(lg)
        order.append((lg, f))
        for i, line in enumerate(open(f, errors='replace').read().split('\n')):
            m = INC.match(line)
            if m:
                q, name = m.groups()
            elif nextdev and ARCH_INC.match(line):
                p_, s_ = ARCH_INC.match(line).groups()
                q, name = '"', p_ + 'i386/' + s_   # the macro expands to a string (ARCH_INCLUDE.h)
            else:
                continue
            cand_logical = []
            if q == '"':
                cand_logical.append(os.path.normpath(os.path.join(os.path.dirname(lg), name)))
            cand_logical += [logical_of(os.path.join(r, name)) for r in roots]
            cand_logical = [canonical(c) for c in cand_logical]
            hit = next(((c, select(c, prefer07, subst)) for c in cand_logical if select(c, prefer07, subst)), None)
            if hit:
                todo.append(hit)
            else:
                u = dict(name=name, quote=q, at='%s:%d' % (origin(f), i + 1))
                if BSDSET['on'] and any(c.startswith(os.path.join('src', 'bsd') + os.sep) for c in cand_logical):
                    u['bsd_set'] = True
                unresolved.append(u)
    return order, unresolved


def sha(path):
    return hashlib.sha256(open(path, 'rb').read()).hexdigest()


def _clean_rel(rel, what):
    if not rel or os.path.isabs(rel) or os.path.normpath(rel) != rel or rel.split(os.sep)[0] == '..':
        raise SystemExit('stage_headers: --subst %s %r is not a clean relative path' % (what, rel))


def _no_symlink(base, rel):
    p = base
    for part in rel.split(os.sep):
        p = os.path.join(p, part)
        if os.path.islink(p):
            raise SystemExit('stage_headers: --subst source %s passes a symbolic link' % p)


def verify_nextmach(rel):
    """NeXTMach file mk-108.1/rel checked against the pinned commit blob; returns (file, note)."""
    import subprocess
    _no_symlink(NEXTMACH, rel)
    f = os.path.join(NEXTMACH, rel)
    obj = '%s:mk-108.1/%s' % (NEXTMACH_COMMIT, rel)
    ls = subprocess.run(['git', '-C', NEXTMACH_REPO, 'ls-tree', NEXTMACH_COMMIT, 'mk-108.1/' + rel],
                        capture_output=True).stdout.split()
    blob = subprocess.run(['git', '-C', NEXTMACH_REPO, 'cat-file', 'blob', obj], capture_output=True)
    if (not os.path.isfile(f) or ls[:2] != [b'100644', b'blob'] or blob.returncode != 0
            or blob.stdout != open(f, 'rb').read()):
        raise SystemExit('stage_headers: %s does not match %s' % (f, obj))
    return f, 'NeXTMach %s commit %s mk-108.1/%s (decision D013, D020, D021)' % (NEXTMACH_URL, NEXTMACH_COMMIT, rel)


def verify_pinned(repo, commit, prefix, rel, url, what):
    """A file of a pinned git checkout checked against its commit blob; returns (file, note)."""
    import subprocess
    base = os.path.join(repo, prefix) if prefix else repo
    _no_symlink(base, rel)
    f = os.path.join(base, rel)
    path = (prefix + '/' + rel) if prefix else rel
    ls = subprocess.run(['git', '-C', repo, 'ls-tree', commit, path], capture_output=True).stdout.split()
    blob = subprocess.run(['git', '-C', repo, 'cat-file', 'blob', '%s:%s' % (commit, path)], capture_output=True)
    if (not os.path.isfile(f) or ls[:2] != [b'100644', b'blob'] or blob.returncode != 0
            or blob.stdout != open(f, 'rb').read()):
        raise SystemExit('stage_headers: %s does not match %s:%s' % (f, commit, path))
    return f, '%s %s commit %s %s sha256 %s' % (what, url, commit, path, sha(f))


def add_override(spec):
    """Parse one --source-override LOGICAL=KIND:PATH (plan 137)."""
    key, eq, val = spec.partition('=')
    kind, colon, rel = val.partition(':')
    if not eq or not colon:
        raise SystemExit('stage_headers: --source-override %r is not LOGICAL=KIND:PATH' % spec)
    _clean_rel(key, 'override key')
    _clean_rel(rel, 'override source')
    if not (key.startswith('src' + os.sep) and key.endswith('.c')):
        raise SystemExit('stage_headers: --source-override key %s is not src/...c' % key)
    if key in OVERRIDE:
        raise SystemExit('stage_headers: --source-override duplicate key %s' % key)
    if kind == 'mach4':
        f, note = verify_pinned(MACH4_REPO, MACH4_COMMIT, '', rel, MACH4_URL, 'Mach4')
    elif kind == 'nextmach':
        f, note = verify_pinned(NEXTMACH_REPO, NEXTMACH_COMMIT, 'mk-108.1', rel, NEXTMACH_URL, 'NeXTMach')
    else:
        raise SystemExit('stage_headers: --source-override kind %r must be mach4 or nextmach' % kind)
    OVERRIDE[key] = dict(file=f, note=note)


def load_subst(path, prefer07):
    """Validate a --subst map (plan 83.2); returns ({logical: dict(file, kind, rel, sha256, note)}, map sha256)."""
    import subprocess
    raw = open(path, 'rb').read()
    pairs = json.loads(raw.decode('utf-8'), object_pairs_hook=lambda kv: kv)
    keys = [k for k, _ in pairs]
    if len(set(keys)) != len(keys):
        raise SystemExit('stage_headers: --subst duplicate key')
    nxsha = {x['path']: x['sha256'] for x in json.load(open(NEXTDEV_LIST))['target_files']}
    out = {}
    for key, val in pairs:
        _clean_rel(key, 'key')
        if not key.startswith(os.path.join('src', 'bsd') + os.sep):
            raise SystemExit('stage_headers: --subst key %s is outside src/bsd/' % key)
        d = darwin_of(key)
        if os.path.isdir(d):
            raise SystemExit('stage_headers: --subst key %s is a directory in Darwin' % key)
        if any(o != key and (o.startswith(key + os.sep) or key.startswith(o + os.sep)) for o in keys):
            raise SystemExit('stage_headers: --subst key %s collides with another key' % key)
        if prefer07 and os.path.exists(os.path.join(K07, key)):
            raise SystemExit('stage_headers: --subst key %s is shadowed by 07_kernel/%s' % (key, key))
        kind, _, rel = val.partition(':')
        _clean_rel(rel, 'source')
        if kind == 'sdk':
            _no_symlink(NEXTDEV, rel)
            f = os.path.join(NEXTDEV, rel)
            tp = TARGET_HEADERS + '/' + rel
            if not os.path.isfile(f) or nxsha.get(tp) is None or nxsha[tp] != sha(f):
                raise SystemExit('stage_headers: --subst %s does not match the real-machine list (%s)' % (f, tp))
            note = 'real machine %s sha256 %s; license TBD (D017)' % (tp, nxsha[tp])
        elif kind == 'nextmach':
            if rel.split(os.sep)[0] not in NEXTMACH_DIRS:
                raise SystemExit('stage_headers: --subst nextmach %s is outside %s' % (rel, ','.join(NEXTMACH_DIRS)))
            f, note = verify_nextmach(rel)
        else:
            raise SystemExit('stage_headers: --subst source %r must start with sdk: or nextmach:' % val)
        out[key] = dict(file=f, kind=kind, rel=rel, sha256=sha(f), note=note)
    return out, hashlib.sha256(raw).hexdigest()


def main():
    args = sys.argv[1:]
    prefer07 = '--prefer-07' in args
    nextdev = '--nextdev' in args
    args = [a for a in args if a not in ('--prefer-07', '--nextdev')]
    subst, subst_path, subst_sha = None, None, None
    while '--source-override' in args:
        i = args.index('--source-override')
        add_override(args[i + 1])
        del args[i:i + 2]
    if '--bsd-set' in args:
        i = args.index('--bsd-set')
        if args[i + 1] != 'nextos':
            raise SystemExit('stage_headers: --bsd-set takes nextos')
        del args[i:i + 2]
        if not nextdev:
            raise SystemExit('stage_headers: --bsd-set needs --nextdev')
        BSDSET['on'] = True
    if '--mach-set' in args:
        i = args.index('--mach-set')
        if args[i + 1] != 'sdk':
            raise SystemExit('stage_headers: --mach-set takes sdk')
        del args[i:i + 2]
        if not nextdev:
            raise SystemExit('stage_headers: --mach-set needs --nextdev')
        MACHSET['on'] = True
    if '--subst' in args:
        i = args.index('--subst')
        subst_path = args[i + 1]
        del args[i:i + 2]
        if not nextdev:
            raise SystemExit('stage_headers: --subst needs --nextdev')
        subst, subst_sha = load_subst(subst_path, prefer07)
    if args and args[0] == '--list':
        files, unres = closure(args[1:], prefer07, nextdev, subst)
        for lg, f in files:
            print(lg, origin(f) + (' SUBST' if subst and lg in subst else ''))
        for u in unres:
            print('UNRESOLVED', u['name'], u['at'])
        return
    stage, sources = args[0], args[1:]
    if os.path.exists(stage):
        raise SystemExit('stage_headers: %s exists' % stage)
    files, unres = closure(sources, prefer07, nextdev, subst)
    nxsha = {}
    if nextdev:
        nxsha = {x['path']: x['sha256'] for x in json.load(open(NEXTDEV_LIST))['target_files']}
    manifest = []
    not_adopted = []
    mach_replaced_07, mach_not_adopted = [], []
    nxsha_all = {x['path']: x['sha256'] for x in json.load(open(NEXTDEV_LIST))['target_files']} if nextdev else {}
    for lg, f in files:
        dst = os.path.join(stage, lg)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copyfile(f, dst)
        if sha(dst) != sha(f):
            raise SystemExit('stage_headers: copy mismatch %s' % dst)
        row = [lg, origin(f), sha(f)]
        d = darwin_of(lg)
        if lg in OVERRIDE:
            row.append('source-override: ' + OVERRIDE[lg]['note'])
            manifest.append(row)
            continue
        if BSDSET['on'] and lg.startswith(os.path.join('src', 'bsd') + os.sep) and lg.endswith('.h'):
            hit = bsd_pick(lg[len(os.path.join('src', 'bsd')) + 1:], prefer07)
            assert hit and os.path.normpath(hit[0]) == os.path.normpath(f)
            if hit[1] in ('sdk', 'sdk07'):
                tp = TARGET_HEADERS + '/' + hit[2]
                if nxsha_all.get(tp) != sha(f):
                    raise SystemExit('stage_headers: %s does not match the real-machine list (%s)' % (f, tp))
                row.append('bsd-set: real machine %s sha256 %s; license TBD (D017)' % (tp, nxsha_all[tp]))
            elif hit[1] == 'nextmach07':
                nf, note = verify_nextmach(hit[2])
                if sha(nf) != sha(f):
                    raise SystemExit('stage_headers: %s differs from NeXTMach %s' % (f, hit[2]))
                row.append('bsd-set: ' + note)
            elif hit[1] == 'authored':
                row.append('bsd-set: authored 07_kernel/nextdev_private/%s (evidence: 07_kernel/PROVENANCE.tsv)' % hit[2])
            else:
                row.append('bsd-set: ' + verify_nextmach(hit[2])[1])
            if prefer07 and hit[1] in ('sdk', 'nextmach'):
                not_adopted.append(lg)
            manifest.append(row)
            continue
        mhit = mach_pick(lg, prefer07) if MACHSET['on'] else None
        if mhit:
            assert os.path.normpath(mhit[0]) == os.path.normpath(f)
            tp = TARGET_HEADERS + '/' + mhit[2]
            if mhit[1] == 'authored':
                row.append('mach-set: authored 07_kernel/nextdev_private/%s from real machine %s sha256 %s (evidence: 07_kernel/PROVENANCE.tsv)' % (mhit[2], tp, nxsha_all.get(tp)))
            elif nxsha_all.get(tp) != sha(f):
                raise SystemExit('stage_headers: %s does not match the real-machine list (%s)' % (f, tp))
            else:
                row.append('mach-set: real machine %s sha256 %s; license TBD (D017)' % (tp, nxsha_all[tp]))
            for old in (os.path.join(K07, lg), d):
                if old and os.path.isfile(old):
                    row.append('replaces %s sha256 %s' % (origin(old), sha(old)))
                    break
            if os.path.isfile(os.path.join(K07, lg)):
                mach_replaced_07.append(lg)
            if prefer07 and mhit[1] == 'sdk':
                mach_not_adopted.append(lg)
            manifest.append(row)
            continue
        if subst and lg in subst:
            row.append('substituted: ' + subst[lg]['note'])
            row.append('replaces %s sha256 %s' % (origin(d), sha(d)) if os.path.isfile(d) else 'no Darwin file')
            manifest.append(row)
            continue
        if prefer07 and d and os.path.isfile(d) and sha(d) != sha(f):
            row.append('differs from %s sha256 %s' % (origin(d), sha(d)))
        if lg.startswith('nextdev' + os.sep):
            tp = TARGET_HEADERS + lg[len('nextdev'):]
            if d == os.path.normpath(f) and nxsha.get(tp) != sha(f):
                raise SystemExit('stage_headers: %s does not match the real-machine list (%s)' % (f, tp))
            row.append('real machine %s sha256 %s; license TBD (D017)' % (tp, nxsha.get(tp)))
            if nxsha.get(tp) != sha(f):
                row.append('differs from the real machine (07_kernel copy)')
        manifest.append(row)
    rep = dict(sources=sources, files=manifest, unresolved=unres)
    if prefer07:
        rep['prefer_07'] = True
    if nextdev:
        rep['nextdev'] = True
    if BSDSET['on']:
        rep['bsd_set'] = 'nextos'
        if prefer07:
            rep['bsd_not_adopted'] = not_adopted
    if OVERRIDE:
        rep['source_override'] = {k: v['note'] for k, v in OVERRIDE.items()}
    if MACHSET['on']:
        rep['mach_set'] = 'sdk'
        rep['mach_replaced_07'] = mach_replaced_07
        if prefer07:
            rep['mach_not_adopted'] = mach_not_adopted
    if subst:
        rep['subst'] = dict(map=subst_path, map_sha256=subst_sha,
                            entries={k: '%s:%s' % (v['kind'], v['rel']) for k, v in subst.items()})
    json.dump(rep, open(stage.rstrip('/') + '.manifest.json', 'w'), indent=1)
    print('staged %d files, %d unresolved includes -> %s' % (len(manifest), len(unres), stage))


if __name__ == '__main__':
    main()
