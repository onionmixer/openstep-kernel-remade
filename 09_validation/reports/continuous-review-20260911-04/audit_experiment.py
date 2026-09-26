"""Audit saved Ghidra stages with Python; never infer completion from exit status."""
import base64
import csv
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('original_input', HERE.parent / 'cautious-followup-20260911/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)


def stripped_banner(text):
    return re.sub(r'^\s*/\* Ghidra decompiler output,.*?\*/', '', text, count=1, flags=re.S).strip()


def main():
    stages = {name: {int(row['entry'], 16): row for row in json.loads((HERE / 'exports' / name / 'functions.json').read_text())}
              for name in ('baseline', 'noreturn', 'restored')}
    assert stages['baseline'].keys() == stages['noreturn'].keys() == stages['restored'].keys()
    heads = set()
    with (R.G / 'code-units.tsv').open() as stream:
        for row in csv.DictReader(stream, delimiter='\t'):
            if row['kind'] == 'instruction':
                heads.add(int(row['start'], 16))
    rows = []
    for entry, baseline in stages['baseline'].items():
        c = {name: (HERE / 'exports' / name / f'{entry:08x}.c').read_text() for name in stages}
        per_stage = {}
        for name in stages:
            row = stages[name][entry]
            assert row['completed'], (name, entry, row['message'])
            addresses = {int(a, 16) for a in row['pcode_addresses']}
            body = [(int(r['start'], 16), int(r['end'], 16)) for r in row['body']]
            outside = {a for a in addresses if not any(lo <= a <= hi for lo, hi in body)}
            for ins in row['listing']:
                data = base64.b64decode(ins['bytes_base64'])
                assert data == R.read_original(int(ins['address'], 16), len(data))
            per_stage[name] = {'noreturn': row['noreturn'], 'outside_body_pcode': [hex(a) for a in sorted(outside)],
                               'offcut_pcode': [hex(a) for a in sorted(addresses - heads)],
                               'pcode_address_count': len(addresses), 'c_sha256': hashlib.sha256(c[name].encode()).hexdigest()}
        rows.append({'entry': hex(entry), 'name': baseline['name'], 'stages': per_stage,
                     'c_changed': c['baseline'] != c['noreturn'], 'c_restored_exactly': c['baseline'] == c['restored'],
                     'metadata_restored_exactly': stages['baseline'][entry] == stages['restored'][entry],
                     'listing_unchanged_all_stages': all(baseline['listing'] == stages[s][entry]['listing'] for s in stages),
                     'body_unchanged_all_stages': all(baseline['body'] == stages[s][entry]['body'] for s in stages),
                     'baseline_matches_prior_export_c': stripped_banner((R.G / 'functions' / f'{entry:08x}.c').read_text()) == c['baseline'].strip()})
    lookup = {r['name']: r for r in rows}
    assert all(r['c_restored_exactly'] and r['metadata_restored_exactly'] for r in rows)
    assert all(r['listing_unchanged_all_stages'] and r['body_unchanged_all_stages'] for r in rows)
    for name in ('_NXDefaultExceptionRaiser', '__objc_msgForward'):
        assert lookup[name]['stages']['baseline']['outside_body_pcode']
        assert not lookup[name]['stages']['noreturn']['outside_body_pcode']
    assert lookup['__objc_msgForward']['stages']['baseline']['offcut_pcode']
    assert not lookup['__objc_msgForward']['stages']['noreturn']['offcut_pcode']
    controls = ('__switch_tss', '__call_with_stack', '_objc_msgSend', '_NXAllocErrorData')
    assert all(not lookup[name]['c_changed'] for name in controls)
    summary = {'selected_functions': len(rows), 'changed_c_outputs': sum(r['c_changed'] for r in rows),
               'exactly_restored_c_outputs': sum(r['c_restored_exactly'] for r in rows),
               'baseline_matches_prior_export_c': sum(r['baseline_matches_prior_export_c'] for r in rows),
               'listing_unchanged': all(r['listing_unchanged_all_stages'] for r in rows),
               'function_bodies_unchanged': all(r['body_unchanged_all_stages'] for r in rows),
               'control_functions_unchanged': list(controls)}
    result = {'summary': summary, 'functions': rows,
              'remaining': ['R02 padding remains classified as instructions in listing.',
                            'Function signatures, calling conventions and full semantic equivalence are not established.',
                            'Original DB/export have not been updated; these are reversible experimental C outputs.']}
    (HERE / 'audit.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(summary, indent=2))
    for name in ('_NXDefaultExceptionRaiser', '__objc_msgForward'):
        print(json.dumps(lookup[name], indent=2))


if __name__ == '__main__':
    main()
