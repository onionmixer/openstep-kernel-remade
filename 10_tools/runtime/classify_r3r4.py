#!/usr/bin/env python3
"""R3 (dispatch-table live values) and R4 (__OBJC changed words) classifier.

    classify_r3r4.py <label1> <label2>

Plan: 02_plan/RUNTIME_OBSERVATION_PLAN.md, sections "R3·R4 계획" and the
codex verdict table (grade L, "(no section)" targets, flags-2 extraction).
Inputs: the raw dumps of two snapshots, the original mach_kernel, macho.json,
symbols.tsv and the Ghidra full-pass5 functions.json (a hypothesis source).
All arithmetic is here, in Python.  KR_LIVE_DIR overrides the snapshot
directory (used by the synthetic self-test only).

A grade says only that a 32-bit value equals, or lies inside, something in
the original image.  It never says the word is a pointer, what the field
is, or which code reads it.
"""
import collections, hashlib, json, os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ORIG = os.path.join(ROOT, '03_original/x86/binaries/mach_kernel')
MACHO = os.path.join(ROOT, '03_original/x86/inventory/macho.json')
SYMS = os.path.join(ROOT, '03_original/x86/inventory/symbols.tsv')
FUNCS = os.path.join(ROOT, '04_ghidra/exports/x86/full-pass5/functions.json')
LIVE = os.environ.get('KR_LIVE_DIR') or os.path.join(ROOT, '09_validation/runtime/x86-live')
WANT_SHA = '33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890'
TABLES = ('_sysent', '_mach_trap_table', '_bdevsw', '_cdevsw', '_vfssw', '_idt', '_idt_pseudo')
DUMPS = (('TEXT', '__TEXT'), ('DATA', '__DATA'), ('OBJC', '__OBJC'))


def ints(d):
    return {k: (int(v, 16) if isinstance(v, str) and v.startswith('0x') else v) for k, v in d.items()}


class Image:
    def __init__(self):
        self.orig = open(ORIG, 'rb').read()
        if hashlib.sha256(self.orig).hexdigest() != WANT_SHA:
            sys.exit('original hash mismatch')
        m = json.load(open(MACHO))
        self.segs = {g['name']: ints(g) for g in m['segments']}
        self.sects = [ints(x) for x in m['sections']]
        rows = []
        with open(SYMS) as f:
            next(f)
            for line in f:
                p = line.rstrip('\n').split('\t')
                rows.append((int(p[1], 16), p[2], int(p[4]), int(p[6])))
        # T1: defined __text symbols (section ordinal 1, not debug) -- review Q2
        self.t1 = collections.defaultdict(list)
        for v, n, sec, dbg in rows:
            if sec == 1 and dbg == 0:
                self.t1[v].append(n)
        # defined symbols for table extents -- review Q1
        self.defined = sorted((v, n) for v, n, sec, dbg in rows if sec != 0 and dbg == 0)
        funcs = json.load(open(FUNCS))
        self.t2 = {int(f['address'], 16): f['name'] for f in funcs}
        bodies = []
        for f in funcs:
            for b in f['body']:
                bodies.append((int(b['start'], 16), int(b['end_inclusive'], 16), f['name']))
        self.bodies = bodies

    def seg_of(self, v):
        for name, g in self.segs.items():
            if name != '__PAGEZERO' and g['address'] <= v < g['address'] + g['size']:
                return name
        return None

    def target_section(self, v):
        seg = self.seg_of(v)
        if seg is None:
            return None
        for x in self.sects:
            if x['size'] and x['address'] <= v < x['address'] + x['size']:
                return x['segment'] + ',' + x['name']
        return seg + ',(no section)'

    def in_body(self, v):
        """Names of Ghidra candidates whose body range contains v (full scan)."""
        return sorted(set(n for st, en, n in self.bodies if st <= v <= en))

    def grade(self, v):
        if v == 0:
            return {'grade': 'Z'}
        if v in self.t1:
            return {'grade': 'T1', 'symbols': sorted(self.t1[v])}
        if v in self.t2:
            return {'grade': 'T2', 'candidate': self.t2[v]}
        seg = self.seg_of(v)
        if seg == '__TEXT':
            return {'grade': 'T3', 'target': self.target_section(v), 'in_candidate_body': self.in_body(v)}
        if seg in ('__DATA', '__OBJC'):
            return {'grade': 'D', 'target': self.target_section(v)}
        if seg == '__LINKEDIT':
            return {'grade': 'L'}
        return {'grade': 'X'}

    def file_word(self, va):
        """Original value of the word at va: file bytes, or 0 in zero-fill."""
        for g in self.segs.values():
            if g['name'] != '__PAGEZERO' and g['address'] <= va < g['address'] + g['size']:
                off = va - g['address']
                if off + 4 <= g['file_size']:
                    fo = g['file_offset'] + off
                    return int.from_bytes(self.orig[fo:fo + 4], 'little')
                if off >= g['file_size']:
                    return 0
                sys.exit('word at 0x%x straddles file_size' % va)
        sys.exit('0x%x not in image' % va)

    def flags2_bytes(self, v):
        """Original bytes from v up to NUL, only inside a flags-low-byte-2 section, bounded by its file-backed end."""
        for x in self.sects:
            if x['size'] and x['flags'] & 0xff == 2 and x['address'] <= v < x['address'] + x['size']:
                start = x['file_offset'] + (v - x['address'])
                end = x['file_offset'] + x['size']
                raw = self.orig[start:end]
                cut = raw.find(b'\0')
                return {'section': x['segment'] + ',' + x['name'],
                        'at_section_start': v == x['address'],
                        'bytes': (raw if cut < 0 else raw[:cut]).decode('latin-1'),
                        'nul_found': cut >= 0}
        return None


def load(label, img):
    d = {}
    for fname, seg in DUMPS:
        b = open(os.path.join(LIVE, label, fname + '.bin'), 'rb').read()
        if len(b) != img.segs[seg]['size']:
            sys.exit('%s/%s.bin: wrong size' % (label, fname))
        d[seg] = b
    return d


def live_word(snap, img, va):
    seg = img.seg_of(va)
    off = va - img.segs[seg]['address']
    return int.from_bytes(snap[seg][off:off + 4], 'little')


def r3(img, s1, s2):
    out = {}
    for name in TABLES:
        start = next(v for v, n in img.defined if n == name)
        end = min(v for v, n in img.defined if v > start)
        nxt = sorted(n for v, n in img.defined if v == end)
        if start % 4 or (end - start) % 4:
            sys.exit('%s: unaligned extent' % name)
        words = []
        for va in range(start, end, 4):
            f, a, b = img.file_word(va), live_word(s1, img, va), live_word(s2, img, va)
            w = {'offset': va - start, 'file': f, 'live1': a, 'live2': b,
                 'changed_vs_file': a != f, 'stable': a == b,
                 'grade_file': img.grade(f), 'grade_live1': img.grade(a)}
            if b != a:
                w['grade_live2'] = img.grade(b)
            words.append(w)
        assert len(words) == (end - start) // 4          # denominator check
        out[name] = {'start': start, 'extent_end': end, 'extent_end_symbols': nxt,
                     'extent_rule': 'up to the next defined symbol with a greater value (hypothesis)',
                     'words': words}
    return out


def r4(img, s1, s2):
    g = img.segs['__OBJC']
    recs = []
    for off in range(0, g['size'], 4):
        va = g['address'] + off
        f = img.file_word(va)
        a = int.from_bytes(s1['__OBJC'][off:off + 4], 'little')
        if a == f:
            continue
        b = int.from_bytes(s2['__OBJC'][off:off + 4], 'little')
        rec = {'va': va, 'section': img.target_section(va), 'file': f, 'live1': a, 'stable': a == b,
               'grade_file': img.grade(f), 'grade_live1': img.grade(a)}
        for key, v in (('file_flags2_bytes', f), ('live1_flags2_bytes', a)):
            x = img.flags2_bytes(v)
            if x is not None:
                rec[key] = x
        recs.append(rec)
    return recs


def gkey(gr):
    return gr['grade'] + (':' + gr['target'] if gr.get('target') else '')


def main():
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    l1, l2 = sys.argv[1:]
    img = Image()
    s1, s2 = load(l1, img), load(l2, img)
    t = r3(img, s1, s2)
    o = r4(img, s1, s2)
    json.dump(t, open(os.path.join(LIVE, l1 + '-r3-full.json'), 'w'), indent=1)
    json.dump(o, open(os.path.join(LIVE, l1 + '-r4-full.json'), 'w'), indent=1)
    # value-free summaries
    r3s = {}
    for name, tb in t.items():
        W = tb['words']
        r3s[name] = {
            'start': '0x%x' % tb['start'], 'extent_end': '0x%x' % tb['extent_end'],
            'extent_end_symbols': tb['extent_end_symbols'], 'words': len(W),
            'changed_vs_file': sum(w['changed_vs_file'] for w in W),
            'changed_between_snapshots': sum(not w['stable'] for w in W),
            'grade_live1_counts': dict(collections.Counter(gkey(w['grade_live1']) for w in W)),
            'changed_vs_file_transitions': dict(collections.Counter(
                gkey(w['grade_file']) + ' -> ' + gkey(w['grade_live1']) for w in W if w['changed_vs_file'])),
            't1_words': [{'offset': w['offset'], 'symbols': w['grade_live1']['symbols'],
                          'changed_vs_file': w['changed_vs_file']}
                         for w in W if w['grade_live1']['grade'] == 'T1'],
        }
    r4s = {
        'words': len(o),
        'by_section': dict(collections.Counter(r['section'] for r in o)),
        'stable': sum(r['stable'] for r in o),
        'transitions': dict(collections.Counter(
            '%s | %s -> %s' % (r['section'], gkey(r['grade_file']), gkey(r['grade_live1'])) for r in o)),
        'file_value_in_flags2_section': sum('file_flags2_bytes' in r for r in o),
        'live_value_in_flags2_section': sum('live1_flags2_bytes' in r for r in o),
    }
    common = {'schema': 1, 'labels': [l1, l2], 'original_sha256': WANT_SHA,
              'grade_rules': 'Z zero; T1 == nlist __text symbol; T2 == Ghidra full-pass5 start (hypothesis); '
                             'T3 inside __TEXT; D inside __DATA/__OBJC with target section; L inside __LINKEDIT; X other nonzero',
              'does_not_establish': ['that any word is a pointer', 'entry size or field meaning',
                                     'which code reads a table', 'what an X value refers to']}
    json.dump(dict(common, plan='R3', tables=r3s), open(os.path.join(LIVE, l1 + '-r3-summary.json'), 'w'), indent=1)
    json.dump(dict(common, plan='R4', objc=r4s), open(os.path.join(LIVE, l1 + '-r4-summary.json'), 'w'), indent=1)
    for name, x in r3s.items():
        print('%-17s words=%4d chg_vs_file=%3d chg_r1r2=%d grades=%s' % (
            name, x['words'], x['changed_vs_file'], x['changed_between_snapshots'], x['grade_live1_counts']))
    print('R4 words', r4s['words'], 'stable', r4s['stable'])


if __name__ == '__main__':
    main()
