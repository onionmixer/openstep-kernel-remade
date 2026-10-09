#!/usr/bin/env python3
"""extract_fat_slice.py -- plan 410 (D065): copy one slice of a preserved fat Mach-O into a new
03_original directory and write its provenance record.

  python3 10_tools/extract_fat_slice.py UNIVERSAL UNIVERSAL_SHA INDEX SLICE_SHA DEST_DIR

DEST_DIR/binaries/mach_kernel and DEST_DIR/provenance.json must not exist (nothing is
overwritten).  The slice is taken from the fat header entry INDEX; the container and the
slice must hash to the given SHA-256 values, and the copy is re-read and re-hashed.
"""
import sys, os, struct, hashlib, json, time

CPU = {6: 'm68k', 7: 'i386', 14: 'sparc'}


def sha(b):
    return hashlib.sha256(b).hexdigest()


def main():
    uni, uni_sha, index, slice_sha, dest = sys.argv[1:6]
    index = int(index)
    out = os.path.join(dest, 'binaries', 'mach_kernel')
    prov = os.path.join(dest, 'provenance.json')
    for p in (out, prov):
        if os.path.exists(p):
            sys.exit('exists: ' + p)
    u = open(uni, 'rb').read()
    assert sha(u) == uni_sha, 'container hash'
    magic, n = struct.unpack('>II', u[:8])
    assert magic == 0xcafebabe and 0 <= index < n
    cpu, sub, off, size, align = struct.unpack('>5I', u[8 + 20 * index:28 + 20 * index])
    s = u[off:off + size]
    assert len(s) == size and sha(s) == slice_sha, 'slice hash'
    head = s[:4]
    order = {b'\xce\xfa\xed\xfe': 'little-endian', b'\xfe\xed\xfa\xce': 'big-endian'}[head]
    vers = sorted({x.decode('latin1') for x in s.split(b'\0') if x.startswith(b'NeXT Mach ')})
    os.makedirs(os.path.dirname(out), exist_ok=True)
    with open(out, 'wb') as f:
        f.write(s)
    back = open(out, 'rb').read()
    assert len(back) == size and sha(back) == slice_sha
    me = os.path.relpath(os.path.abspath(__file__), os.getcwd())
    rec = {
        'schema': 1,
        'container': {'path': uni, 'sha256': uni_sha, 'size': len(u), 'magic': 'CAFEBABE', 'fat_arch_count': n,
                      'provenance': os.path.join(os.path.dirname(os.path.dirname(uni)), 'provenance.json')},
        'slice': {'architecture': CPU.get(cpu, str(cpu)), 'fat_index': index, 'cputype_raw': '0x%08x' % cpu,
                  'cpusubtype_raw': '0x%08x' % sub, 'offset': off, 'size': size, 'alignment_exponent': align,
                  'magic_bytes': head.hex().upper(), 'byte_order': order, 'sha256': slice_sha,
                  'versions': vers, 'destination': out},
        'extraction': {'tool': me, 'tool_sha256': sha(open(__file__, 'rb').read()),
                       'command': ' '.join(['python3', me] + sys.argv[1:6]),
                       'utc': time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime())},
        'note': ('Added by plan 410 under user decision D065. The binary is git-ignored; this record, the '
                 'container provenance it points to and the inventory beside it are the tracked facts. '
                 '03_original/manifest.json and the container provenance are unchanged and do not list this slice.'),
    }
    open(prov, 'w').write(json.dumps(rec, indent=2) + '\n')
    print(json.dumps(rec, indent=2))


if __name__ == '__main__':
    main()
