#!/usr/bin/env python3
"""m2_m68k_libcc.py -- plan 422 (M2-8): are the libcc names in the m68k original's __text the
members of the preserved libcc.a?

  python3 10_tools/reconstruction/m2_m68k_libcc.py WORKDIR RECORD.json

The m68k slice of 03_original/x86/userland/binaries/lib/libcc.a (fat, SHA checked) is unpacked to
WORKDIR (an ignored artifact directory).  Members whose external __text symbols exist in the
image's __text are compared with l1_compare.py twice: --place-from-image, and the same with
--ranges from the image's external symbol bounds.  Each member's ___clz_tab bytes and the first
24 bytes of its __text are searched in the whole image; sizes, relocations and the image's
symbol extents are recorded (plan 422.1).
Read-only apart from WORKDIR and the record.
"""
import sys, os, json, struct, hashlib, subprocess, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj

LIB = '03_original/x86/userland/binaries/lib/libcc.a'
LIB_SHA = 'bccd689e3b5e7e85'
IMG = '03_original/m68k/binaries/mach_kernel'
IMG_SHA = 'dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75'


def sha(b):
    return hashlib.sha256(b).hexdigest()


def members(lib):
    magic, n = struct.unpack('>II', lib[:8])
    assert magic == 0xcafebabe
    sl = None
    for i in range(n):
        ct, cs, off, size, al = struct.unpack('>iiIII', lib[8 + 20 * i:28 + 20 * i])
        if ct == 6:
            sl = lib[off:off + size]
    assert sl[:8] == b'!<arch>\n'
    p, out = 8, []
    while p < len(sl):
        h = sl[p:p + 60]
        assert h[58:60] == b'`\n', p
        name, size = h[:16].decode().strip(), int(h[48:58])
        data = sl[p + 60:p + 60 + size]
        if name.startswith('#1/'):
            k = int(name[3:])
            name, data = data[:k].rstrip(b'\0').decode(), data[k:]
        out.append((name, data))
        p += 60 + size
        p += p & 1
    assert p == len(sl)
    return out


def main(workdir, out_json):
    lib = open(LIB, 'rb').read()
    assert sha(lib).startswith(LIB_SHA)
    ib = open(IMG, 'rb').read()
    assert sha(ib) == IMG_SHA
    img = macho_obj.parse(ib)
    text = [s for s in img['sections'] if s['sectname'] == '__text'][0]
    starts = sorted({y['value'] for y in img['symbols'] if y['kind'] == 'SECT' and not y['stab'] and y['sect'] == text['index']})
    addr = {y['name']: y['value'] for y in img['symbols'] if y['kind'] == 'SECT' and not y['stab']}
    tend = text['addr'] + text['size']

    def extent(a):
        i = starts.index(a)
        return (starts[i + 1] if i + 1 < len(starts) else tend) - a

    os.makedirs(workdir, exist_ok=True)
    mem = members(lib)
    rows, listing = [], []
    for name, data in mem:
        p = os.path.join(workdir, name)
        if os.path.exists(p):
            assert open(p, 'rb').read() == data, 'different file exists: ' + p
        else:
            open(p, 'wb').write(data)
        listing.append([name, len(data), sha(data)])
        if name.startswith('__.SYMDEF'):
            continue
        o = macho_obj.parse(data)
        ts = [s for s in o['sections'] if s['sectname'] == '__text']
        if not ts:
            continue
        ext = [y['name'] for y in o['symbols'] if y['kind'] == 'SECT' and y.get('ext') and not y['stab'] and y['sect'] == ts[0]['index']]
        hit = [e for e in ext if addr.get(e) is not None and text['addr'] <= addr[e] < tend]
        if not hit:
            continue
        res = {}
        for mode in ('place', 'ranges'):
            outp = os.path.join(workdir, 'l1-%s-%s.json' % (name, mode))
            cmd = [sys.executable, '10_tools/reconstruction/l1_compare.py', '--image', IMG, '--obj', p, '--place-from-image', '--out', outp]
            if mode == 'ranges':
                rp = os.path.join(workdir, 'ranges-%s.json' % name)
                json.dump({e: [addr[e], addr[e] + extent(addr[e])] for e in hit}, open(rp, 'w'))
                cmd += ['--ranges', rp]
            r = subprocess.run(cmd, capture_output=True, text=True)
            assert r.returncode == 0, r.stderr[-500:]
            d = json.load(open(outp))
            res[mode] = dict(verdict=d['object_verdict'], reasons=d['object_reasons'][:4],
                             functions=[[f['names'][0], f['verdict'], f.get('byte_differences')] for f in d['functions']
                                        if f['section'] == '__TEXT,__text'])
        tb = data[ts[0]['offset']:ts[0]['offset'] + ts[0]['size']]
        cz = [y for y in o['symbols'] if y['name'] == '___clz_tab' and y['kind'] == 'SECT']
        clz = None
        if cz:
            cs = [s for s in o['sections'] if s['index'] == cz[0]['sect']][0]
            k = cs['offset'] + cz[0]['value'] - cs['addr']
            tab = data[k:k + 256]
            clz = dict(section=cs['sectname'], found_in_image=ib.count(tab))
        und = sorted(y['name'] for y in o['symbols'] if y['kind'] == 'UNDF' and y.get('ext'))
        rows.append(dict(member=name, sha256=sha(data), text_size=ts[0]['size'],
                         relocations=sum(len(s['relocs']) for s in o['sections']), undefined=und,
                         symbols=[dict(name=e, image_address='0x%x' % addr[e], image_extent=extent(addr[e])) for e in hit],
                         text_prefix24_found_in_image=ib.count(tb[:24]), clz_tab=clz, l1=res))
    S = dict(members=len(mem), members_with_image_text_symbol=len(rows),
             verdicts={r['member']: [r['l1']['place']['verdict'], r['l1']['ranges']['verdict']] for r in rows},
             text_size_vs_image_extent={r['member']: [r['text_size'], [s['image_extent'] for s in r['symbols']]] for r in rows},
             prefix_found={r['member']: r['text_prefix24_found_in_image'] for r in rows},
             clz_tab_found={r['member']: (r['clz_tab'] or {}).get('found_in_image') for r in rows})
    json.dump(dict(plan=422, tool='10_tools/reconstruction/m2_m68k_libcc.py', tool_sha256=sha(open(os.path.abspath(__file__), 'rb').read()),
                   library=dict(path=LIB, sha256=sha(lib), slice='m68k'), image=dict(path=IMG, sha256=IMG_SHA),
                   l1_compare_sha256=sha(open('10_tools/reconstruction/l1_compare.py', 'rb').read()),
                   workdir=workdir, members=listing, summary=S, compared=rows,
                   note='OBJECT_MATCH would mean the member bytes equal the image range; NOT_MATCH with the recorded size, call '
                        'and table differences means the image holds another implementation.'), open(out_json, 'w'), indent=1)
    print(json.dumps(S, indent=1))


if __name__ == '__main__':
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    main(*sys.argv[1:])
