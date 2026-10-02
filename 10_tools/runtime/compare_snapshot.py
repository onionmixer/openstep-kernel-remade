#!/usr/bin/env python3
"""Compare a live x86 kernel snapshot with the original mach_kernel bytes.

    compare_snapshot.py <label> [<label2>]

Inputs: 09_validation/runtime/x86-live/<label>/{TEXT,DATA,OBJC}.bin written
by snapshot.sh on the target, the original 03_original/x86/binaries/
mach_kernel, and its macho.json / symbols.tsv inventories.

Output: 09_validation/runtime/x86-live/<label>-compare.json.  All address,
offset, size and count arithmetic is done here, in Python.

What the report may claim: which bytes of the running image equal the
file-backed original bytes, which differ, what the live values are, and
which original symbol precedes each differing word.  It does not name a
cause for a difference.  With a second label, words are also split into
stable and changed-between-snapshots.
"""
import bisect, collections, hashlib, json, os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ORIG = os.path.join(ROOT, '03_original/x86/binaries/mach_kernel')
MACHO = os.path.join(ROOT, '03_original/x86/inventory/macho.json')
SYMS = os.path.join(ROOT, '03_original/x86/inventory/symbols.tsv')
LIVE = os.path.join(ROOT, '09_validation/runtime/x86-live')
WANT_SHA = '33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890'
DUMPS = (('TEXT', '__TEXT'), ('DATA', '__DATA'), ('OBJC', '__OBJC'))


def ints(d):
    """macho.json stores numbers as hex strings; turn them into ints."""
    return {k: (int(v, 16) if isinstance(v, str) and v.startswith('0x') else v)
            for k, v in d.items()}


def sha(b):
    return hashlib.sha256(b).hexdigest()


def load_symbols():
    rows = []
    with open(SYMS) as f:
        next(f)
        for line in f:
            p = line.rstrip('\n').split('\t')
            if int(p[4]) == 0 or int(p[6]) != 0:
                continue
            rows.append((int(p[1], 16), p[2]))
    rows.sort()
    return [a for a, _ in rows], [n for _, n in rows]


def nearest(addrs, names, va):
    i = bisect.bisect_right(addrs, va) - 1
    if i < 0:
        return None
    return {'symbol': names[i], 'delta': va - addrs[i]}


def section_of(sections, va):
    for s in sections:
        if s['address'] <= va < s['address'] + s['size']:
            return s['segment'] + ',' + s['name']
    return None


def classify_value(segments, v):
    for g in segments:
        if g['name'] != '__PAGEZERO' and g['address'] <= v < g['address'] + g['size']:
            return 'in-image:' + g['name']
    return 'zero' if v == 0 else 'outside-image'


def main():
    if len(sys.argv) not in (2, 3):
        sys.exit(__doc__)
    orig = open(ORIG, 'rb').read()
    if sha(orig) != WANT_SHA:
        sys.exit('original hash mismatch')
    m = json.load(open(MACHO))
    m['segments'] = [ints(g) for g in m['segments']]
    m['sections'] = [ints(x) for x in m['sections']]
    segs = {g['name']: g for g in m['segments']}
    addrs, names = load_symbols()

    def load(label):
        d = {}
        for fname, seg in DUMPS:
            p = os.path.join(LIVE, label, fname + '.bin')
            b = open(p, 'rb').read()
            if len(b) != segs[seg]['size']:
                sys.exit('%s: size %d != segment size %d' % (p, len(b), segs[seg]['size']))
            d[seg] = b
        return d

    label = sys.argv[1]
    live = load(label)
    live2 = load(sys.argv[2]) if len(sys.argv) == 3 else None
    report = {'schema': 1, 'label': label, 'second_label': sys.argv[2] if live2 else None,
              'original_sha256': WANT_SHA, 'dumps': {}, 'segments': {}}
    for fname, seg in DUMPS:
        report['dumps'][fname] = sha(live[seg])

    for _, seg in DUMPS:
        g = segs[seg]
        b = live[seg]
        fb = orig[g['file_offset']:g['file_offset'] + g['file_size']]
        backed = g['file_size']
        # The word loops below assume a 4-byte boundary between the file-backed
        # part and the zero-fill tail; stop rather than miscount (review Q0).
        if backed % 4 or g['size'] % 4:
            sys.exit('%s: file_size/size not a multiple of 4' % seg)
        # word-granular diff of the file-backed part, byte-exact counts
        diff_bytes = sum(1 for i in range(backed) if b[i] != fb[i])
        words = []
        for off in range(0, backed, 4):
            if b[off:off + 4] != fb[off:off + 4]:
                va = g['address'] + off
                new = int.from_bytes(b[off:off + 4], 'little')
                old = int.from_bytes(fb[off:off + 4].ljust(4, b'\0'), 'little')
                w = {'va': '0x%x' % va, 'section': section_of(m['sections'], va),
                     'file': '0x%08x' % old, 'live': '0x%08x' % new,
                     'live_class': classify_value(m['segments'], new),
                     'near': nearest(addrs, names, va)}
                if live2 is not None:
                    w['stable'] = live2[seg][off:off + 4] == b[off:off + 4]
                words.append(w)
        # zero-fill tail (__bss/__common): nonzero words in the live image
        zf = []
        for off in range(backed - backed % 4, g['size'], 4):
            v = int.from_bytes(b[off:off + 4], 'little')
            if v:
                va = g['address'] + off
                z = {'va': '0x%x' % va, 'section': section_of(m['sections'], va),
                     'live': '0x%08x' % v, 'live_class': classify_value(m['segments'], v),
                     'near': nearest(addrs, names, va)}
                if live2 is not None:
                    z['stable'] = live2[seg][off:off + 4] == b[off:off + 4]
                zf.append(z)
        # Storage split (file-backed vs zero-fill tail) is not the section
        # split: the tail starts at file_size, which can fall inside __bss.
        # This count is by original section; a zero-fill word "differs from
        # the original" when it is nonzero (review Q0).
        key = lambda x: x['section'] or seg + ',(no section)'
        by_sect = collections.Counter(key(x) for x in words + zf)
        stab = collections.Counter((key(x), x.get('stable')) for x in words + zf)
        report.setdefault('differs_from_original_by_section', {})
        for k in sorted(by_sect):
            e = {'words': by_sect[k]}
            if live2 is not None:
                e['stable_in_second'] = stab[(k, True)]
                e['changed_in_second'] = stab[(k, False)]
            assert k not in report['differs_from_original_by_section']
            report['differs_from_original_by_section'][k] = e
        report['segments'][seg] = {
            'address': '0x%x' % g['address'], 'size': g['size'],
            'file_backed_size': backed, 'file_backed_equal': diff_bytes == 0,
            'file_backed_diff_bytes': diff_bytes, 'file_backed_diff_words': words,
            'zero_fill_size': g['size'] - backed, 'zero_fill_nonzero_words': zf,
        }
    # Per-section equality of every file-backed section.  Bytes of a segment
    # outside its sections (the Mach-O header and load commands at the start
    # of __TEXT) are reported by the word list above but are not section data.
    sect_eq = {}
    for x in m['sections']:
        if x['flags'] & 0xff == 1 or x['size'] == 0:      # zero-fill or empty
            continue
        g = segs[x['segment']]
        a = x['address'] - g['address']
        fo = x['file_offset']
        sect_eq[x['segment'] + ',' + x['name']] = (
            live[x['segment']][a:a + x['size']] == orig[fo:fo + x['size']])
    report['file_backed_section_equal'] = sect_eq
    # The kmem offset = VA premise is accepted only if every __TEXT section
    # (code, constants, strings) is byte-identical to the file.
    report['kmem_offset_equals_va'] = all(
        v for k, v in sect_eq.items() if k.startswith('__TEXT,'))
    out = os.path.join(LIVE, label + '-compare.json')
    with open(out, 'w') as f:
        json.dump(report, f, indent=1)
    for seg, r in report['segments'].items():
        print('%-7s backed=%d equal=%s diff_bytes=%d diff_words=%d zf_nonzero=%d' % (
            seg, r['file_backed_size'], r['file_backed_equal'], r['file_backed_diff_bytes'],
            len(r['file_backed_diff_words']), len(r['zero_fill_nonzero_words'])))
    for k, v in report['file_backed_section_equal'].items():
        if not v:
            print('section differs:', k)
    print('kmem_offset_equals_va:', report['kmem_offset_equals_va'], '->', out)


if __name__ == '__main__':
    main()
