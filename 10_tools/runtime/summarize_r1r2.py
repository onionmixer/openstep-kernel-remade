#!/usr/bin/env python3
"""Write the value-free, committable summary of two compared snapshots.

    summarize_r1r2.py <label1> <label2> <target-clock-1> <target-clock-2> <out-name>

Reads the local <label>-compare.json files (which hold live values and stay
out of git) and the raw dumps, and writes only counts, section names, dump
hashes and the one __TEXT header finding.  Live values, per-word addresses
and symbol markers are withheld: they include the site's network state.
"""
import collections, datetime, json, os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
LIVE = os.path.join(ROOT, '09_validation/runtime/x86-live')


def main():
    if len(sys.argv) != 6:
        sys.exit(__doc__)
    l1, l2, c1, c2, outname = sys.argv[1:]
    r1 = json.load(open(os.path.join(LIVE, l1 + '-compare.json')))
    r2 = json.load(open(os.path.join(LIVE, l2 + '-compare.json')))
    fmt = '%Y-%m-%d %H:%M:%S'
    interval = (datetime.datetime.strptime(c2, fmt) - datetime.datetime.strptime(c1, fmt)).total_seconds()
    changed = {}
    for fname, seg in (('TEXT', '__TEXT'), ('DATA', '__DATA'), ('OBJC', '__OBJC')):
        a = open(os.path.join(LIVE, l1, fname + '.bin'), 'rb').read()
        b = open(os.path.join(LIVE, l2, fname + '.bin'), 'rb').read()
        assert len(a) == len(b) and len(a) % 4 == 0
        changed[seg] = sum(1 for i in range(0, len(a), 4) if a[i:i + 4] != b[i:i + 4])
    hdr = [w for w in r1['segments']['__TEXT']['file_backed_diff_words']]
    summary = {
        'schema': 2,
        'plan': '02_plan/RUNTIME_OBSERVATION_PLAN.md R1,R2',
        'original_sha256': r1['original_sha256'],
        'snapshots': {l1: {'target_clock': c1, 'dump_sha256': r1['dumps']},
                      l2: {'target_clock': c2, 'dump_sha256': r2['dumps']}},
        'interval_seconds_target_clock': interval,
        'note_clock': 'the target clock is not the host clock; only the interval is used',
        'kmem_offset_equals_va': {l1: r1['kmem_offset_equals_va'], l2: r2['kmem_offset_equals_va'],
                                  'criterion': 'every file-backed __TEXT section byte-identical to the original'},
        'file_backed_section_equal': {l1: r1['file_backed_section_equal'], l2: r2['file_backed_section_equal']},
        'text_header_difference_words': len(hdr),
        'text_header_difference': {'file_offset': '0x7e4', 'load_command_index': 4, 'segment': '__LINKEDIT',
                                   'field': 'cmd', 'file': 1, 'live': 0, 'cause': 'not established'},
        'differs_from_original_by_section': {
            'definition': 'file-backed word != original, or zero-fill word != 0; sections from the original Mach-O section table',
            l1: r1['differs_from_original_by_section'], l2: r2['differs_from_original_by_section']},
        'words_changed_between_snapshots': changed,
        'withheld': 'live values, per-word addresses and symbol markers stay in the local *-compare.json',
        'does_not_establish': ['why any word differs', 'which function wrote it', 'structure/field layout',
                               'that a preceding symbol owns a word'],
    }
    out = os.path.join(LIVE, outname)
    with open(out, 'w') as f:
        f.write(json.dumps(summary, indent=1) + '\n')
    t = open(out).read()
    bad = [p for p in ('192.168', 'a8c0', '"live":  "0x') if p in t]
    print(out, 'bytes', len(t), 'ip-pattern hits', bad)
    return 1 if bad else 0


if __name__ == '__main__':
    sys.exit(main())
