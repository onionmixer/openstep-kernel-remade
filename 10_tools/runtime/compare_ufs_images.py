#!/usr/bin/env python3
"""Compare a NeXT UFS disk image before and after an offline change.  Read-only.

usage: compare_ufs_images.py BEFORE AFTER --new /path [--new /path ...] [--report FILE]

Passes (exit 0) only if the only change is the addition of the --new files in
existing directories:
  1. namespace/metadata: every path in BEFORE exists in AFTER with the same inode,
     mode, uid, gid, nlink, size and content SHA-256 (symlink target included);
     the only new paths are the --new ones; only their parent directories may
     change size/times/blocks.
  2. bytes: every changed 1 KiB fragment of the image lies in an allowed area:
     the new files' data and indirect blocks, the parent directories' blocks,
     the cylinder-group blocks, the primary superblock, the cylinder summary
     area, or the inode blocks -- and inside inode blocks only the new inodes
     and the parent directories' inodes may differ.
Plan: 02_plan/EMULATION_PLATFORM_PLAN.md ("i386 디스크에 PIC 수정본 기준 커널 넣기").
"""
import argparse, hashlib, importlib.util, json, mmap, os, struct, sys

HERE = os.path.dirname(os.path.abspath(__file__))
_spec = importlib.util.spec_from_file_location('ik', os.path.join(HERE, 'installed_kernel_identity.py'))
ik = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(ik)


def open_fs(path):
    img = ik.Image(path)
    return ik.UFS(img, ik.read_label(img))


def manifest(fs):
    """path -> metadata and content hash, for the whole tree."""
    out = {}
    stack = [(ik.ROOTINO, '/')]
    while stack:
        ino, path = stack.pop()
        node = fs.inode(ino)
        raw = node['raw']
        kind = node['mode'] & ik.S_IFMT
        rec = dict(ino=ino, mode=node['mode'], uid=struct.unpack('>H', raw[4:6])[0],
                   gid=struct.unpack('>H', raw[6:8])[0], nlink=node['nlink'], size=node['size'])
        if kind == ik.S_IFREG or (kind == ik.S_IFLNK and node['blocks']):
            rec['sha256'] = hashlib.sha256(fs.read_regular(node)[0]).hexdigest()
        elif kind == ik.S_IFLNK:
            rec['sha256'] = hashlib.sha256(raw[40:40 + node['size']]).hexdigest()
        out[path] = rec
        if kind == ik.S_IFDIR:
            for i, n in fs.readdir(node):
                if n not in ('.', '..'):
                    stack.append((i, path.rstrip('/') + '/' + n))
    return out


def file_frags(fs, ino):
    data, ind = fs.extents(fs.inode(ino))
    s = set(f for _, a, n in data for f in range(a, a + n))
    s.update(f for a in ind for f in range(a, a + fs.frag))
    return s


def inode_location(fs, ino):
    c = ino // fs.ipg
    fr = fs.cgstart(c) + fs.iblkno + ((ino % fs.ipg) // fs.inopb) * fs.frag
    return fr, (ino % fs.inopb) * ik.DINODE          # block start fragment, byte offset in block


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('before')
    ap.add_argument('after')
    ap.add_argument('--new', action='append', required=True)
    ap.add_argument('--report')
    a = ap.parse_args()
    fa, fb = open_fs(a.before), open_fs(a.after)
    need = ik.need
    need(fa.base == fb.base and fa.geo == fb.geo, 'geometry differs')
    fs = fb
    checks, notes = {}, []

    # 1. namespace and metadata
    ma, mb = manifest(fa), manifest(fb)
    new = set(a.new)
    parents = set(os.path.dirname(p) or '/' for p in new)
    added, removed = set(mb) - set(ma), set(ma) - set(mb)
    checks['added_paths_exactly_new'] = added == new
    checks['no_removed_paths'] = not removed
    changed = []
    for p in set(ma) & set(mb):
        x, y = ma[p], mb[p]
        if p in parents:
            same = all(x[k] == y[k] for k in ('ino', 'mode', 'uid', 'gid', 'nlink'))
        else:
            same = x == y
        if not same:
            changed.append(p)
    checks['no_other_metadata_or_content_change'] = not changed
    notes.append(dict(added=sorted(added), removed=sorted(removed)[:20], changed=sorted(changed)[:20],
                      files_before=len(ma), files_after=len(mb)))

    # 2. byte-level: every changed fragment must be in an allowed area
    new_inos = [mb[p]['ino'] for p in new if p in mb]
    parent_inos = [mb[p]['ino'] for p in parents]
    allowed = set()
    for ino in new_inos:
        allowed |= file_frags(fs, ino)
    for ino in parent_inos:
        allowed |= file_frags(fs, ino) | file_frags(fa, ino)
    cg_frags = set()
    for c in range(fs.ncg):
        start = fs.cgstart(c) + fs.cblkno
        cg_frags.update(range(start, start + fs.frag))
    sb_frags = set(range(ik.SBOFF // fs.fsize, (ik.SBOFF + 2048 + fs.fsize - 1) // fs.fsize))
    sbraw = fs.img.read(fs.base + ik.SBOFF, 2048)
    csaddr, cssize = struct.unpack('>2i', sbraw[152:160])
    cs_frags = set(range(csaddr, csaddr + (cssize + fs.fsize - 1) // fs.fsize))
    ino_ok = {}                                         # inode block start -> allowed byte offsets
    for ino in new_inos + parent_inos:
        blk, off = inode_location(fs, ino)
        ino_ok.setdefault(blk, set()).add(off)
    ino_block_frags = {}
    for blk in ino_ok:
        for k in range(fs.frag):
            ino_block_frags[blk + k] = blk
    A = mmap.mmap(fa.img.f.fileno(), 0, access=mmap.ACCESS_READ)
    B = mmap.mmap(fb.img.f.fileno(), 0, access=mmap.ACCESS_READ)
    need(len(A) == len(B), 'image sizes differ')
    bad, kinds = [], {}
    step = 1 << 20
    for off in range(0, len(A), step):
        if A[off:off + step] == B[off:off + step]:
            continue
        for o in range(off, min(off + step, len(A)), fs.fsize):
            if A[o:o + fs.fsize] == B[o:o + fs.fsize]:
                continue
            if o < fs.base:
                bad.append((o, 'front porch'))
                continue
            fr = (o - fs.base) // fs.fsize
            if fr in allowed:
                k = 'file/dir data'
            elif fr in cg_frags:
                k = 'cylinder group'
            elif fr in sb_frags:
                k = 'primary superblock'
            elif fr in cs_frags:
                k = 'cylinder summary'
            elif fr in ino_block_frags:
                blk = ino_block_frags[fr]
                k = 'inode block'
                base_o = fs.base + blk * fs.fsize
                for rec in range(o, o + fs.fsize, ik.DINODE):
                    if A[rec:rec + ik.DINODE] != B[rec:rec + ik.DINODE] and \
                            (rec - base_o) not in ino_ok[blk]:
                        bad.append((rec, 'other inode changed'))
            else:
                bad.append((o, 'fragment %d outside allowed areas' % fr))
                continue
            kinds[k] = kinds.get(k, 0) + 1
    checks['bytes_only_in_allowed_areas'] = not bad
    notes.append(dict(changed_fragments_by_area=kinds, violations=bad[:20], violation_count=len(bad)))

    out = dict(before=os.path.basename(a.before), after=os.path.basename(a.after), new=sorted(new),
               checks=checks, details=notes, passed=all(checks.values()))
    text = json.dumps(out, indent=1, ensure_ascii=False)
    print(text)
    if a.report:
        with open(a.report, 'w') as o:
            o.write(text + '\n')
    sys.exit(0 if out['passed'] else 1)


if __name__ == '__main__':
    try:
        main()
    except ik.Bad as e:
        sys.exit('STOP: %s' % e)
