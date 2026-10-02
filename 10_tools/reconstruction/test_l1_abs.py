#!/usr/bin/env python3
"""Tests for the nonzero-ABS external resolution in l1_compare.py (plan 108.3), on the
mach_header probe object (s5p81-probe-1), whose 16 external relocations name the
linker-defined absolute symbol __mh_execute_header (0x100000 in the original)."""
import json, os, struct, subprocess, sys, tempfile
HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
import macho_obj, l1_compare as L
TOOL = os.path.join(HERE, 'l1_compare.py')
IMG = os.path.join(REPO, '03_original/x86/binaries/mach_kernel')
R = os.path.join(REPO, '08_build/runs/s5p81-probe-1')
OBJ = os.path.join(R, 'out/O3c__mach_header.o')
RG = os.path.join(R, 'ranges-mach_header.json')
TMP = tempfile.mkdtemp(prefix='l1abs-')


def run(img):
    out = os.path.join(TMP, 'r%d.json' % len(os.listdir(TMP)))
    subprocess.run([sys.executable, TOOL, '--image', img, '--obj', OBJ, '--place-from-image', '--ranges', RG,
                    '--out', out], check=True, capture_output=True)
    return json.load(open(out))


def patched_image(delta):
    """Copy of the image with the n_value of __mh_execute_header changed by delta."""
    d = bytearray(open(IMG, 'rb').read())
    ncmds = struct.unpack('<I', d[16:20])[0]
    off = 28
    for _ in range(ncmds):
        cmd, cs = struct.unpack('<2I', d[off:off + 8])
        if cmd == 2:                                   # LC_SYMTAB
            symoff, nsyms, stroff, strsize = struct.unpack('<4I', d[off + 8:off + 24])
            for i in range(nsyms):
                e = symoff + 12 * i
                strx = struct.unpack('<I', d[e:e + 4])[0]
                nm = bytes(d[stroff + strx:d.index(b'\0', stroff + strx)])
                if nm == b'__mh_execute_header':
                    v = struct.unpack('<I', d[e + 8:e + 12])[0]
                    d[e + 8:e + 12] = struct.pack('<I', v + delta)
                    p = os.path.join(TMP, 'img%d' % delta)
                    open(p, 'wb').write(d)
                    return p
        off += cs
    raise SystemExit('symbol not found')


def independent():
    """Each relocated field in the original must equal F + 0x100000 (no pc-relative ones here)."""
    o = macho_obj.parse(open(OBJ, 'rb').read()); ob = open(OBJ, 'rb').read()
    img = L.Image(IMG)
    t = [s for s in o['sections'] if s['sectname'] == '__text'][0]
    names = {y['index']: y['name'] for y in o['symbols']}
    n = ok = 0
    for r in t['relocs']:
        if not r['scattered'] and r.get('extern') and names.get(r['symbolnum']) == '__mh_execute_header':
            n += 1
            assert not r['pcrel']
            F = int.from_bytes(ob[t['offset'] + r['address']:t['offset'] + r['address'] + 4], 'little')
            got = int.from_bytes(img.read(0x15c2fc + r['address'] - t['addr'], 4), 'little')
            ok += got == F + 0x100000
    return n == 16 and ok == 16


def main():
    d0 = run(IMG)
    d4 = run(patched_image(4))
    img = L.Image(IMG)
    cases = [
        ('16 references resolve, OBJECT_MATCH', sum(len(f['refs_unverified']) for f in d0['functions']) == 0 and d0['object_verdict'] == 'OBJECT_MATCH'),
        ('independent expectation: original fields = F + 0x100000 (16/16)', independent()),
        ('patched ABS value (+4): references differ', sum(f['refs_differ'] for f in d4['functions']) == 16 and d4['object_verdict'] != 'OBJECT_MATCH'),
        ('zero-valued ObjC ABS markers are not resolved', img.abs_symbol('.objc_class_name_kmDevice') is None and len(img.abs) == 1),
        ('ABS symbols never used for placement', L.placements_from_image(img, OBJ) == {k: v for k, v in d0['placements'].items() if v is not None and k in L.placements_from_image(img, OBJ)}),
    ]
    bad = 0
    for name, ok in cases:
        bad += not ok
        print('%-4s %s' % ('ok' if ok else 'FAIL', name))
    print('%d tests, %d failed' % (len(cases), bad))
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
