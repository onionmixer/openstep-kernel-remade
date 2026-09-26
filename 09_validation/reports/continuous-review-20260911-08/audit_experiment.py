"""Audit independent process inputs, exact storage, C deltas, and original bytes."""
import base64
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('original', HERE.parent / 'cautious-followup-20260911/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)
STAGES = ('baseline', 'hidden_only', 'compress_only', 'combined', 'reopened_baseline')


def load(stage, name):
    return json.loads((HERE / 'exports' / stage / name).read_text())


def by_entry(rows):
    return {r['entry']: r for r in rows}


def stripped(text):
    return re.sub(r'^\s*/\* Ghidra decompiler output,.*?\*/', '', text, count=1, flags=re.S).strip()


def main():
    job = json.loads((HERE / 'job.json').read_text())
    baseline = by_entry(load('baseline', 'all-functions.json'))
    funcs = {s: by_entry(load(s, 'functions.json')) for s in STAGES}
    expected_meta = {'baseline': set(), 'hidden_only': {'00124cb8', '001ab830'},
                     'compress_only': {'00103428'}, 'combined': {'00124cb8', '001ab830', '00103428'},
                     'reopened_baseline': set()}
    expected_c = {'baseline': set(), 'hidden_only': {'00124cb8', '001ab830', '00124154'},
                  'compress_only': {'00103428', '00103188'},
                  'combined': {'00124cb8', '001ab830', '00124154', '00103428', '00103188'},
                  'reopened_baseline': set()}
    rows = []
    for stage in STAGES:
        marker = json.loads((HERE / 'exports' / f'{stage}-execution-marker.json').read_text())
        assert marker == {'class': 'IsolatedStorageExperiment', 'version': 'isolated-storage-v2', 'stage': stage}
        initial = by_entry(json.loads((HERE / 'exports' / f'{stage}-input-functions.json').read_text()))
        assert initial == baseline, stage
        all_funcs = by_entry(load(stage, 'all-functions.json'))
        assert all_funcs.keys() == baseline.keys()
        metadata_changes = {a for a in baseline if all_funcs[a] != baseline[a]}
        assert metadata_changes == expected_meta[stage], (stage, metadata_changes)
        assert all(all_funcs[a]['body'] == baseline[a]['body'] for a in baseline)
        assert all(all_funcs[a]['locals'] == baseline[a]['locals'] for a in baseline)
        for name in ('code-units.tsv', 'references.tsv'):
            assert (HERE / 'exports' / stage / name).read_bytes() == (HERE / 'exports' / 'baseline' / name).read_bytes(), (stage, name)
        # Map.of JSON key order may vary across fresh JVMs; compare parsed values.
        assert load(stage, 'initialized-memory.json') == load('baseline', 'initialized-memory.json')
        assert sorted(funcs[stage]) == job['selected']
        assert all(f['completed'] for f in funcs[stage].values())
        c_changes = set()
        for entry in job['selected']:
            text = (HERE / 'exports' / stage / f'{entry}.c').read_text()
            base_text = (HERE / 'exports/baseline' / f'{entry}.c').read_text()
            if text != base_text:
                c_changes.add(entry)
            if stage == 'baseline':
                assert stripped((R.G / 'functions' / f'{entry}.c').read_text()) == text.strip(), entry
        assert c_changes == expected_c[stage], (stage, c_changes)
        if stage in ('hidden_only', 'combined'):
            for proposal in job['hidden']:
                entry = proposal['entry']
                f = funcs[stage][entry]
                assert f['custom_storage']
                assert f['return']['storage'] == 'EAX:4'
                assert [p['storage'] for p in f['parameters']] == ['EBX:4', 'Stack[0x4]:4', 'Stack[0x8]:4']
                assert all(p['length'] == job['word_size'] for p in f['parameters'])
                text = (HERE / 'exports' / stage / f'{entry}.c').read_text()
                assert 'unaff_EBX' not in text and 'return result_buffer;' in text
        if stage in ('compress_only', 'combined'):
            f = funcs[stage]['00103428']
            assert not f['custom_storage']
            assert [p['storage'] for p in f['parameters']] == ['Stack[0x4]:4', 'Stack[0x8]:4']
            assert all(p['type'] == '/int' and p['length'] == job['word_size'] for p in f['parameters'])
            text = (HERE / 'exports' / stage / '00103188.c').read_text()
            assert not any(token in text for token in ('unaff_EBX', 'unaff_ESI', 'Bytef', 'uLong'))
        rows.append({'stage': stage, 'metadata_changed': sorted(metadata_changes), 'c_changed': sorted(c_changes),
                     'metadata_change_count': len(metadata_changes), 'c_change_count': len(c_changes),
                     'input_state_identical': True, 'listing_references_memory_unchanged': True})
    assert funcs['baseline'] == funcs['reopened_baseline']
    coverage = bytearray(len(R.RAW))
    memory = load('baseline', 'initialized-memory.json')
    for block in memory:
        start = int(block['start'], 16)
        data = base64.b64decode(block['bytes'])
        for seg in R.META['segments']:
            address = int(seg['address'], 16)
            lo, hi = max(start, address), min(start + len(data), address + seg['file_size'])
            if lo >= hi:
                continue
            off = seg['file_offset'] + lo - address
            assert data[lo-start:hi-start] == R.RAW[off:off+hi-lo]
            coverage[off:off+hi-lo] = bytes([1]) * (hi-lo)
    assert all(coverage)
    compress_sites = [f'{i.address:08x}' for i in R.function_instructions(R.NAMES['_acct']).values()
                      if i.mnemonic == 'call' and i.operands[0].type == R.X86_OP_IMM and i.operands[0].imm == R.NAMES['_compress']]
    call_counts = []
    for owner, sites in [('00124154', ['0012417a']), ('00103188', compress_sites)]:
        for site in sites:
            counts = {}
            for stage in STAGES:
                matches = [r for r in funcs[stage][owner]['pcode_calls'] if r['address'] == site]
                assert len(matches) == 1
                counts[stage] = len(matches[0]['inputs']) - 1
            expected = {s: (3 if s in ('hidden_only', 'combined') else 2) for s in STAGES} if owner == '00124154' else {s: (2 if s in ('compress_only', 'combined') else 4) for s in STAGES}
            assert counts == expected, (site, counts)
            call_counts.append({'owner': owner, 'call_site': site, 'pcode_argument_counts': counts})
    # Rejected first attempt really did fail restoration/isolation; retain proof.
    rejected = HERE / 'rejected-transaction-attempt/exports'
    old_base = by_entry(json.loads((rejected / 'baseline/all-functions.json').read_text()))
    old_final = by_entry(json.loads((rejected / 'restored/all-functions.json').read_text()))
    not_restored = sorted(a for a in old_base if old_base[a] != old_final[a])
    assert not_restored
    summary = {'global_function_records': len(baseline), 'selected_functions': len(job['selected']),
               'independent_processes': len(STAGES), 'prior_export_c_matches': len(job['selected']),
               'reopened_c_and_metadata_exact': True, 'initialized_blocks': len(memory),
               'original_file_bytes_verified': sum(coverage), 'stages': rows,
               'rejected_first_attempt_unrestored_entries': not_restored}
    (HERE / 'audit.json').write_text(json.dumps({'summary': summary, 'calls': call_counts}, indent=2) + '\n')
    print(json.dumps({'summary': summary, 'calls': call_counts}, indent=2))


if __name__ == '__main__':
    main()
