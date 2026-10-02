#!/usr/bin/env python3
"""Read kernel files from OPENSTEP disk/CD images and compare them with 03_original.

Read-only.  Plan and codex review: 02_plan/EMULATION_PLATFORM_PLAN.md,
"설치된 커널 대조 계획".

usage:
  installed_kernel_identity.py --image ARCH=PATH [--image ARCH=PATH ...]
      [--ref NAME=IMAGE:/ufs/path ...] [--ufsread PATH] --out-dir DIR --report FILE

  --image    a VM disk (or raw image) whose root kernel files are extracted to
             OUT_DIR/ARCH/extracted/
  --ref      an extra image whose single UFS file is extracted as a reference
             (for example the install CD's /mach_kernel)
  --ufsread  OPENSTEP_BOOTCD 04_tools/ufsread.py, used only as a secondary
             byte-for-byte cross-check of every extracted file

Every image must carry a NeXT "dlV3" disk label; the UFS start is taken from
the label and must equal the first superblock magic.  Extraction stops with an
error on any structural inconsistency (label checksum, superblock geometry,
backup superblock, cylinder-group magic, inode or fragment allocation,
di_blocks, holes, duplicate names).
"""
import argparse, hashlib, json, os, re, struct, subprocess, sys

UFS_MAGIC = 0x00011954
CG_MAGIC = 0x00090255
SBOFF = 8192
ROOTINO = 2
NDADDR, NIADDR = 12, 3
DINODE = 128
DIRBLK = 1024                            # observed: records end on 1024-byte boundaries
S_IFMT, S_IFDIR, S_IFREG, S_IFLNK = 0o170000, 0o040000, 0o100000, 0o120000
LABEL_COPIES = (0, 15, 30, 45)          # 512-byte sectors (observed on the disks; CDs use 0)
REPO = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..'))
BASELINE = {
    'i386': '03_original/x86/binaries/mach_kernel',
    'm68k': '03_original/m68k/binaries/mach_kernel',
    'sparc': '03_original/sparc/binaries/mach_kernel',
}
CPUTYPE = {6: 'm68k', 7: 'i386', 14: 'sparc'}


class Bad(Exception):
    pass


def need(cond, msg):
    if not cond:
        raise Bad(msg)


def sha(b):
    return hashlib.sha256(b).hexdigest()


def label_checksum(b):
    s = 0
    for i in range(0, len(b), 2):
        s += (b[i] << 8) + b[i + 1]
    s += s >> 16
    return s & 0xffff


class Image:
    def __init__(self, path):
        self.path = path
        self.f = open(path, 'rb')
        self.f.seek(0, 2)
        self.size = self.f.tell()

    def read(self, off, n):
        need(0 <= off and off + n <= self.size, 'read outside image: %d+%d' % (off, n))
        self.f.seek(off)
        b = self.f.read(n)
        need(len(b) == n, 'short read at %d' % off)
        return b


def read_label(img):
    """All dlV3 copies; checksum over 0..0x22d with label_blkno zeroed."""
    copies = []
    for sec in LABEL_COPIES:
        off = sec * 512
        if off + 0x230 > img.size:
            continue
        b = bytearray(img.read(off, 0x230))
        if b[:4] != b'dlV3':
            continue
        blkno = struct.unpack('>I', b[4:8])[0]
        z = bytearray(b)
        z[4:8] = b'\0\0\0\0'
        stored = struct.unpack('>H', b[0x22e:0x230])[0]
        need(label_checksum(bytes(z[:0x22e])) == stored,
             'label checksum mismatch at sector %d' % sec)
        copies.append((sec, blkno, bytes(z)))
    need(copies, 'no dlV3 label')
    for sec, blkno, z in copies[1:]:
        need(z == copies[0][2], 'label copy at sector %d differs' % sec)
    z = copies[0][2]
    secsize = struct.unpack('>i', z[0x5c:0x60])[0]
    front = struct.unpack('>H', z[0x70:0x72])[0]
    parts = []
    for i in range(8):
        e = z[0xbe + 46 * i:0xbe + 46 * (i + 1)]
        base, size = struct.unpack('>ii', e[:8])
        if size > 0:
            parts.append(dict(index=i, base=base, size=size,
                              type=e[37:45].split(b'\0')[0].decode('latin1')))
    return dict(copies=[[s, b] for s, b, _ in copies], secsize=secsize, front=front,
                kernel=z[0x84:0x9c].split(b'\0')[0].decode('latin1'),
                root_rw=z[0xbc:0xbe].decode('latin1'), partitions=parts)


def read_label_any(img):
    """Disk images keep dlV3 at 512-byte sectors 0/15/30/45; CD images at offset 0."""
    return read_label(img)


class UFS:
    def __init__(self, img, label, first_magic_must_match=True):
        self.img = img
        need(label['partitions'] and label['partitions'][0]['index'] == 0,
             'partition 0 missing')
        p = label['partitions'][0]
        need(p['type'] == '4.3BSD', 'partition 0 type %r' % p['type'])
        self.base = (label['front'] + p['base']) * label['secsize']
        self.part_bytes = p['size'] * label['secsize']
        need(self.base + self.part_bytes <= img.size, 'partition beyond image end')
        # Disks: the label's UFS must also be the first superblock in the image.
        # Hybrid boot CDs carry another UFS (the El Torito floppy image) before it.
        self.first_magic = self._first_magic()
        if first_magic_must_match:
            need(self.first_magic == self.base,
                 'label UFS start %d != first magic %s' % (self.base, self.first_magic))
        sb = img.read(self.base + SBOFF, 2048)
        self.geo = self._geometry(sb)
        g = self.geo
        (self.sblkno, self.cblkno, self.iblkno, self.dblkno, self.cgoffset, self.cgmask,
         self.fs_size, self.ncg, self.bsize, self.fsize, self.frag, self.nindir,
         self.inopb, self.ipg, self.fpg) = (g[k] for k in (
             'sblkno', 'cblkno', 'iblkno', 'dblkno', 'cgoffset', 'cgmask', 'size', 'ncg',
             'bsize', 'fsize', 'frag', 'nindir', 'inopb', 'ipg', 'fpg'))
        need(self.bsize == self.fsize * self.frag, 'bsize != fsize*frag')
        need(self.nindir == self.bsize // 4, 'nindir')
        need(self.inopb == self.bsize // DINODE, 'inopb')
        need(self.fs_size * self.fsize <= self.part_bytes, 'fs larger than partition')
        need(self.ncg == -(-self.fs_size // self.fpg), 'ncg')
        # backup superblock in cylinder group 0
        bsb = img.read(self.base + (self.cgstart(0) + self.sblkno) * self.fsize, 2048)
        need(self._geometry(bsb) == g, 'cg0 backup superblock geometry differs')
        self.cgs = {}

    def _first_magic(self):
        m = struct.pack('>I', UFS_MAGIC)
        step = 1 << 20
        pos = 0
        while pos < self.img.size:
            chunk = self.img.read(pos, min(step + 4, self.img.size - pos))
            i = chunk.find(m)
            while i >= 0:
                cand = pos + i - 1372 - SBOFF
                if cand >= 0 and cand % 512 == 0:
                    return cand
                i = chunk.find(m, i + 1)
            pos += step
        return None

    @staticmethod
    def _geometry(sb):
        need(struct.unpack('>I', sb[1372:1376])[0] == UFS_MAGIC, 'superblock magic')
        names = ('sblkno', 'cblkno', 'iblkno', 'dblkno', 'cgoffset', 'cgmask')
        g = dict(zip(names, struct.unpack('>6i', sb[8:32])))
        g.update(zip(('size', 'dsize', 'ncg', 'bsize', 'fsize', 'frag'),
                     struct.unpack('>6i', sb[36:60])))
        g['fragshift'], g['fsbtodb'] = struct.unpack('>2i', sb[96:104])
        g['nindir'], g['inopb'] = struct.unpack('>2i', sb[116:124])
        g['ipg'], g['fpg'] = struct.unpack('>2i', sb[184:192])
        return g

    def cgbase(self, c):
        return self.fpg * c

    def cgstart(self, c):
        return self.cgbase(c) + self.cgoffset * (c & ~self.cgmask)

    def frag_bytes(self, frag, n):
        return self.img.read(self.base + frag * self.fsize, n)

    # Cylinder groups use the fixed layout found in these images: cg_cgx @12,
    # ncyl/niblk @16, ndblk @20, cg_cs (ndir, nbfree, nifree, nffree) @24,
    # inode-used map @724 (256 bytes), cg_magic @980, fragment-free map @984.
    # Established from the bytes: magic found at 980 in every cg, and in every
    # cg of os42j.iso and the three disks the map popcounts equal cg_cs.
    CG_IUSED, CG_MAGIC_OFF, CG_FREE = 724, 980, 984

    def cg(self, c):
        if c not in self.cgs:
            b = self.frag_bytes(self.cgstart(c) + self.cblkno, self.bsize)
            need(struct.unpack('>I', b[self.CG_MAGIC_OFF:self.CG_MAGIC_OFF + 4])[0] == CG_MAGIC,
                 'cg %d magic' % c)
            need(struct.unpack('>i', b[12:16])[0] == c, 'cg %d cgx' % c)
            niblk = struct.unpack('>h', b[18:20])[0]
            ndblk = struct.unpack('>i', b[20:24])[0]
            ndir, nbfree, nifree, nffree = struct.unpack('>4i', b[24:40])
            need(niblk == self.ipg and self.ipg <= 8 * (self.CG_MAGIC_OFF - self.CG_IUSED),
                 'cg %d niblk' % c)
            used = sum((b[self.CG_IUSED + (i >> 3)] >> (i & 7)) & 1 for i in range(niblk))
            fr = [(b[self.CG_FREE + (d >> 3)] >> (d & 7)) & 1 for d in range(ndblk)]
            full = sum(1 for k in range(0, ndblk - ndblk % self.frag, self.frag)
                       if all(fr[k:k + self.frag]))
            need(used == niblk - nifree and full == nbfree and sum(fr) - full * self.frag == nffree,
                 'cg %d maps disagree with cg_cs' % c)
            self.cgs[c] = (b, self.CG_IUSED, self.CG_FREE)
        return self.cgs[c]

    def inode_used(self, ino):
        b, iused, _ = self.cg(ino // self.ipg)
        i = ino % self.ipg
        return (b[iused + (i >> 3)] >> (i & 7)) & 1 == 1

    def frags_allocated(self, frag, n):
        c = frag // self.fpg
        need(c == (frag + n - 1) // self.fpg, 'extent crosses cylinder group')
        b, _, free = self.cg(c)
        for k in range(n):
            d = frag % self.fpg + k
            if (b[free + (d >> 3)] >> (d & 7)) & 1:
                return False
        return True

    def inode(self, ino):
        need(0 < ino < self.ncg * self.ipg, 'inode %d out of range' % ino)
        c = ino // self.ipg
        fr = self.cgstart(c) + self.iblkno + ((ino % self.ipg) // self.inopb) * self.frag
        d = self.img.read(self.base + fr * self.fsize + (ino % self.inopb) * DINODE, DINODE)
        mode, nlink = struct.unpack('>HH', d[0:4])
        size = struct.unpack('>Q', d[8:16])[0]
        need(size < 1 << 31, 'inode %d size %d' % (ino, size))
        return dict(ino=ino, mode=mode, nlink=nlink, size=size,
                    db=list(struct.unpack('>12i', d[40:88])),
                    ib=list(struct.unpack('>3i', d[88:100])),
                    blocks=struct.unpack('>i', d[104:108])[0], raw=d)

    def extents(self, node):
        """(logical block, fragment address, fragment count) for every data block,
        plus the indirect blocks; stops on any hole."""
        size = node['size']
        nblk = -(-size // self.bsize)
        data, indirect = [], []
        tables = {}

        def table(level, frag):
            need(frag != 0, 'hole: indirect pointer is 0')
            if frag not in tables:
                indirect.append(frag)
                tables[frag] = struct.unpack('>%di' % self.nindir, self.frag_bytes(frag, self.bsize))
            return tables[frag]

        for lbn in range(nblk):
            if lbn < NDADDR:
                a = node['db'][lbn]
            else:
                r = lbn - NDADDR
                if r < self.nindir:
                    a = table(0, node['ib'][0])[r]
                else:
                    r -= self.nindir
                    need(r < self.nindir * self.nindir, 'file needs triple indirect')
                    a = table(0, table(1, node['ib'][1])[r // self.nindir])[r % self.nindir]
            need(a != 0, 'hole at logical block %d' % lbn)
            if lbn == nblk - 1 and lbn < NDADDR:
                n = -(-(size - lbn * self.bsize) // self.fsize)
            else:
                n = self.frag
            data.append((lbn, a, n))
        return data, indirect

    def read_regular(self, node):
        data, indirect = self.extents(node)
        for lbn, a, n in data:
            need(self.frags_allocated(a, n), 'data fragments of inode %d not allocated' % node['ino'])
        for a in indirect:
            need(self.frags_allocated(a, self.frag), 'indirect block of inode %d not allocated' % node['ino'])
        nfrag = sum(n for _, _, n in data) + len(indirect) * self.frag
        # di_blocks counts device blocks: fragments << fs_fsbtodb
        need(node['blocks'] == nfrag << self.geo['fsbtodb'],
             'inode %d di_blocks %d != %d' % (node['ino'], node['blocks'], nfrag << self.geo['fsbtodb']))
        out = bytearray()
        left = node['size']
        for lbn, a, n in data:
            k = min(self.bsize, left)
            out += self.frag_bytes(a, k)
            left -= k
        need(len(out) == node['size'], 'length')
        return bytes(out), dict(data_extents=len(data), indirect_blocks=len(indirect),
                                fragments=nfrag)

    def readdir(self, node):
        need(node['mode'] & S_IFMT == S_IFDIR, 'not a directory')
        data, _ = self.read_regular(node)
        need(len(data) % DIRBLK == 0, 'directory size')
        ents = []
        for blk in range(0, len(data), DIRBLK):
            off = blk
            while off < blk + DIRBLK:
                ino, reclen, namlen = struct.unpack('>IHH', data[off:off + 8])
                need(reclen >= 8 and reclen % 4 == 0 and off + reclen <= blk + DIRBLK,
                     'directory record at %d' % off)
                if ino:
                    need(0 < namlen <= reclen - 8 - 1 and data[off + 8 + namlen] == 0,
                         'directory name at %d' % off)
                    ents.append((ino, data[off + 8:off + 8 + namlen].decode('latin1')))
                off += reclen
        names = [n for _, n in ents]
        need(len(names) == len(set(names)), 'duplicate directory names')
        need(('.' in names) and ('..' in names), 'no . or ..')
        return ents


def audit(fs):
    """Whole-file-system audit, read-only.  Walks every directory from the root and
    returns counts; a sound file system has every error count 0."""
    owner, dup, seen = {}, 0, set()
    stack, errors, reachable = [ROOTINO], [], []
    while stack:
        ino = stack.pop()
        if ino in seen:
            continue
        seen.add(ino)
        node = fs.inode(ino)
        kind = node['mode'] & S_IFMT
        if kind in (S_IFREG, S_IFDIR) or (kind == S_IFLNK and node['blocks']):
            try:
                data, ind = fs.extents(node)
            except Bad as e:
                errors.append('inode %d: %s' % (ino, e))
                continue
            frags = [f for _, a, n in data for f in range(a, a + n)]
            frags += [f for a in ind for f in range(a, a + fs.frag)]
            nfrag = sum(n for _, _, n in data) + len(ind) * fs.frag
            if node['blocks'] != nfrag << fs.geo['fsbtodb']:
                errors.append('inode %d di_blocks' % ino)
            for f in frags:
                if f in owner:
                    dup += 1
                else:
                    owner[f] = ino
        if kind == S_IFDIR:
            try:
                ents = fs.readdir(node)
            except Bad as e:
                errors.append('dir inode %d: %s' % (ino, e))
                continue
            stack.extend(i for i, n in ents if n not in ('.', '..'))
    for c in range(fs.ncg):
        fs.cg(c)                                  # every cg: magic, cgx, maps == cg_cs
    ref_free = sum(1 for f in owner if not fs.frags_allocated(f, 1))
    not_used = sum(1 for i in seen if not fs.inode_used(i))
    return dict(inodes=len(seen), referenced_fragments=len(owner), duplicate_refs=dup,
                referenced_but_free=ref_free, reachable_inode_not_iused=not_used,
                cylinder_groups_checked=fs.ncg, errors=errors[:20], error_count=len(errors))


def macho(data):
    """Header, and per-section file ranges of a thin Mach-O."""
    m = data[:4]
    if m == b'\xfe\xed\xfa\xce':
        e = '>'
    elif m == b'\xce\xfa\xed\xfe':
        e = '<'
    else:
        return None
    cputype, subtype, ftype, ncmds, sizeofcmds, flags = struct.unpack(e + '6i', data[4:28])
    off, sects = 28, []
    for _ in range(ncmds):
        cmd, size = struct.unpack(e + '2I', data[off:off + 8])
        if cmd == 1:                                   # LC_SEGMENT
            seg = data[off + 8:off + 24].split(b'\0')[0].decode('latin1')
            fileoff, filesize = struct.unpack(e + '2I', data[off + 32:off + 40])
            nsects = struct.unpack(e + 'I', data[off + 48:off + 52])[0]
            sects.append(dict(seg=seg, sect=None, offset=fileoff, size=filesize))
            for k in range(nsects):
                s = off + 56 + 68 * k
                name = data[s:s + 16].split(b'\0')[0].decode('latin1')
                ssize, soff = struct.unpack(e + '2I', data[s + 36:s + 44])
                sflags = struct.unpack(e + 'I', data[s + 64:s + 68])[0]
                if sflags & 0xff != 1 and soff:          # not zerofill
                    sects.append(dict(seg=seg, sect=name, offset=soff, size=ssize))
        off += size
    return dict(endian='big' if e == '>' else 'little', cputype=cputype,
                arch=CPUTYPE.get(cputype), filetype=ftype, ncmds=ncmds, sections=sects)


def fat_slices(data):
    if data[:4] != b'\xca\xfe\xba\xbe':
        return None
    n = struct.unpack('>I', data[4:8])[0]
    out = []
    for i in range(n):
        cputype, sub, off, size, align = struct.unpack('>5I', data[8 + 20 * i:28 + 20 * i])
        out.append(dict(index=i, cputype=cputype, arch=CPUTYPE.get(cputype), offset=off,
                        size=size, data=data[off:off + size]))
    return out


def versions(data):
    return sorted(set(v.decode('latin1') for v in re.findall(rb'NeXT Mach \d[ -~]{0,200}', data)))


def describe(data):
    d = dict(size=len(data), sha256=sha(data), magic=data[:4].hex())
    fs = fat_slices(data)
    if fs:
        d['fat'] = [dict(index=s['index'], arch=s['arch'], cputype=s['cputype'],
                         offset=s['offset'], size=s['size'], sha256=sha(s['data']),
                         versions=versions(s['data'])) for s in fs]
    else:
        mo = macho(data)
        if mo:
            d['macho'] = dict(arch=mo['arch'], endian=mo['endian'], filetype=mo['filetype'])
        d['versions'] = versions(data)
    return d


def thin_for(data, arch):
    fs = fat_slices(data)
    if fs:
        for s in fs:
            if s['arch'] == arch:
                return s['data']
        return None
    return data


def diff(a, b):
    if a == b:
        return dict(equal=True)
    r = dict(equal=False, size_a=len(a), size_b=len(b))
    if len(a) != len(b):
        n = 0
        while n < min(len(a), len(b)) and a[n] == b[n]:
            n += 1
        r['common_prefix'] = n
        return r
    ranges, i = [], 0
    while i < len(a):
        if a[i] != b[i]:
            j = i
            while j < len(a) and a[j] != b[j]:
                j += 1
            if ranges and i - ranges[-1][1] <= 16:
                ranges[-1][1] = j
            else:
                ranges.append([i, j])
            i = j
        else:
            i += 1
    r['differing_bytes'] = sum(1 for x, y in zip(a, b) if x != y)
    mo = macho(a)
    out = []
    for s, e in ranges:
        where = []
        if mo:
            for sec in mo['sections']:
                if sec['sect'] and sec['offset'] < e and s < sec['offset'] + sec['size']:
                    where.append('%s,%s' % (sec['seg'], sec['sect']))
        out.append(dict(start=s, end=e, length=e - s, sections=where))
    r['ranges'] = out
    return r


def cross_check(ufsread, path, base, ufs_path, data, tmp):
    if not ufsread:
        return None
    r = subprocess.run([sys.executable, ufsread, 'cat', path, ufs_path, '--base', str(base),
                        '-o', tmp], capture_output=True)
    need(r.returncode == 0, 'ufsread failed: %s' % r.stderr[-300:])
    other = open(tmp, 'rb').read()
    os.unlink(tmp)
    need(other == data, 'ufsread output differs for %s' % ufs_path)
    return True


def extract_image(arch, path, out_dir, ufsread):
    img = Image(path)
    label = read_label_any(img)
    fs = UFS(img, label)
    root = fs.inode(ROOTINO)
    need(fs.inode_used(ROOTINO), 'root inode not allocated')
    ents = fs.readdir(root)
    rec = dict(image=os.path.basename(path), image_size=img.size, label=label,
               ufs_base=fs.base, geometry=fs.geo, files=[])
    by_ino = {}
    for ino, name in ents:
        by_ino.setdefault(ino, []).append(name)
    for ino, name in sorted(ents, key=lambda e: e[1]):
        if not re.search(r'mach|kernel', name, re.I):
            continue
        node = fs.inode(ino)
        need(fs.inode_used(ino), 'inode %d of %s not allocated' % (ino, name))
        kind = node['mode'] & S_IFMT
        f = dict(name='/' + name, ino=ino, mode='%o' % node['mode'], nlink=node['nlink'],
                 size=node['size'], same_inode_names=sorted('/' + n for n in by_ino[ino]))
        if kind == S_IFLNK:
            if node['blocks'] == 0 and node['size'] <= 60:
                f['symlink'] = node['raw'][40:40 + node['size']].decode('latin1')
            else:
                f['symlink'] = fs.read_regular(node)[0].decode('latin1')
        elif kind == S_IFREG:
            data, layout = fs.read_regular(node)
            f.update(describe(data))
            f['layout'] = layout
            dest = os.path.join(out_dir, arch, 'extracted')
            os.makedirs(dest, exist_ok=True)
            fp = os.path.join(dest, name)
            with open(fp, 'wb') as o:
                o.write(data)
            f['extracted_to'] = os.path.relpath(fp, REPO)
            f['ufsread_equal'] = cross_check(ufsread, path, fs.base, '/' + name, data,
                                             fp + '.ufsread.tmp')
        else:
            f['type'] = 'other'
        rec['files'].append(f)
    return rec, fs


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--image', action='append', default=[])
    ap.add_argument('--ref', action='append', default=[])
    ap.add_argument('--ufsread')
    ap.add_argument('--out-dir', required=True)
    ap.add_argument('--report', required=True)
    a = ap.parse_args()
    os.makedirs(a.out_dir, exist_ok=True)
    report = dict(schema=1, tool='10_tools/runtime/installed_kernel_identity.py',
                  baselines={}, refs={}, disks={}, comparisons=[])
    for arch, p in BASELINE.items():
        b = open(os.path.join(REPO, p), 'rb').read()
        report['baselines'][arch] = dict(path=p, size=len(b), sha256=sha(b), versions=versions(b))
    refdata = {}
    for spec in a.ref:
        name, rest = spec.split('=', 1)
        path, ufs_path = rest.rsplit(':', 1)
        img = Image(path)
        label = read_label_any(img)
        fs = UFS(img, label, first_magic_must_match=False)
        node = None
        cur = fs.inode(ROOTINO)
        for part in [x for x in ufs_path.split('/') if x]:
            hits = [i for i, n in fs.readdir(cur) if n == part]
            need(len(hits) == 1, '%s: %s' % (name, part))
            cur = node = fs.inode(hits[0])
        need(node['mode'] & S_IFMT == S_IFREG, '%s not regular' % ufs_path)
        need(fs.inode_used(node['ino']), '%s inode not allocated' % ufs_path)
        data, layout = fs.read_regular(node)
        d = describe(data)
        d.update(image=os.path.basename(path), ufs_base=fs.base, first_superblock_base=fs.first_magic,
                 path=ufs_path, layout=layout,
                 ufsread_equal=cross_check(a.ufsread, path, fs.base, ufs_path, data,
                                           os.path.join(a.out_dir, name + '.ufsread.tmp')))
        report['refs'][name] = d
        refdata[name] = data
    for spec in a.image:
        arch, path = spec.split('=', 1)
        rec, fs = extract_image(arch, path, a.out_dir, a.ufsread)
        report['disks'][arch] = rec
        base = open(os.path.join(REPO, BASELINE[arch]), 'rb').read()
        for f in rec['files']:
            if 'extracted_to' not in f:
                continue
            data = open(os.path.join(REPO, f['extracted_to']), 'rb').read()
            thin = thin_for(data, arch)
            c = dict(arch=arch, file=f['name'], against=BASELINE[arch])
            if thin is None:
                c['result'] = 'no %s slice' % arch
            else:
                c['thin_sha256'] = sha(thin)
                c.update(diff(thin, base))
            report['comparisons'].append(c)
            for rname, rdata in refdata.items():
                rthin = thin_for(rdata, arch)
                if rthin is None:
                    continue
                c = dict(arch=arch, file=f['name'], against='ref:' + rname,
                         ref_thin_sha256=sha(rthin))
                c.update(diff(thin, rthin) if thin is not None else dict(result='no slice'))
                report['comparisons'].append(c)
    for rname, rdata in refdata.items():
        for arch in BASELINE:
            rthin = thin_for(rdata, arch)
            if rthin is None:
                continue
            base = open(os.path.join(REPO, BASELINE[arch]), 'rb').read()
            c = dict(arch=arch, file='ref:' + rname, against=BASELINE[arch],
                     thin_sha256=sha(rthin))
            c.update(diff(rthin, base))
            report['comparisons'].append(c)
    with open(a.report, 'w') as o:
        json.dump(report, o, indent=1, ensure_ascii=False)
        o.write('\n')
    for c in report['comparisons']:
        print('%-5s %-14s vs %-40s %s' % (c['arch'], c['file'], c['against'],
                                          'EQUAL' if c.get('equal') else
                                          c.get('result') or 'DIFF %s' % {k: c[k] for k in c if k in (
                                              'size_a', 'size_b', 'differing_bytes', 'common_prefix')}))


if __name__ == '__main__':
    try:
        main()
    except Bad as e:
        sys.exit('STOP: %s' % e)
