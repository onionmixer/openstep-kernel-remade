"""Python-only measurement of independent Ghidra states and raw ABI evidence."""
import base64
import collections
import difflib
import hashlib
import json
import re
from pathlib import Path
from run_experiment import HERE, ROOT, R, STAGES


def read(stage, name):
    return json.loads((HERE / 'exports' / stage / name).read_text())


def indexed(rows):
    return {f['entry']: f for f in rows}


def main():
    job = json.loads((HERE / 'job.json').read_text())
    base = indexed(read('baseline', 'all-functions.json'))
    funcs = {s: indexed(read(s, 'functions.json')) for s in STAGES}
    targets = {p['entry'] for p in job['prototypes']}
    callers = {c['owner'] for c in job['direct_calls']}
    nr_callers = {c['owner'] for c in job['direct_calls'] if c['target'] == job['noreturn_entry']}
    stages = []
    diffs = []
    for stage in STAGES:
        marker = json.loads((HERE / 'exports' / f'{stage}-execution-marker.json').read_text())
        assert marker == {'class': 'ApiContractExperiment', 'version': 'api-contract-v1', 'stage': stage}
        initial = indexed(json.loads((HERE / 'exports' / f'{stage}-input-functions.json').read_text()))
        assert initial == base, stage
        all_f = indexed(read(stage, 'all-functions.json'))
        assert all_f.keys() == base.keys()
        changed = {a for a in base if base[a] != all_f[a]}
        expected = targets if stage in ('prototype_only', 'combined') else {job['noreturn_entry']} if stage == 'noreturn_only' else set()
        assert changed == expected, (stage, changed)
        assert all(base[a]['body'] == all_f[a]['body'] and base[a]['locals'] == all_f[a]['locals'] for a in base)
        for filename in ('code-units.tsv', 'references.tsv'):
            assert (HERE / 'exports' / stage / filename).read_bytes() == (HERE / 'exports/baseline' / filename).read_bytes()
        assert read(stage, 'initialized-memory.json') == read('baseline', 'initialized-memory.json')
        assert sorted(funcs[stage]) == job['selected']
        assert all(f['completed'] for f in funcs[stage].values())
        c_changed = set()
        for entry in job['selected']:
            text = (HERE / 'exports' / stage / f'{entry}.c').read_text()
            original = (HERE / 'exports/baseline' / f'{entry}.c').read_text()
            if stage == 'baseline':
                canonical = (R.G / 'functions' / f'{entry}.c').read_text()
                stripped = re.sub(r'^\s*/\* Ghidra decompiler output,.*?\*/', '', canonical, count=1, flags=re.S).strip()
                assert stripped == text.strip(), entry
            if text != original:
                c_changed.add(entry)
                diffs.extend(difflib.unified_diff(original.splitlines(True), text.splitlines(True),
                                                fromfile=f'baseline/{entry}.c', tofile=f'{stage}/{entry}.c'))
        expected_c = targets | callers if stage in ('prototype_only', 'combined') else nr_callers if stage == 'noreturn_only' else set()
        assert c_changed == expected_c, (stage, c_changed)
        for proposal in job['prototypes']:
            f = all_f[proposal['entry']]
            assert f['noreturn'] == (proposal['entry'] == job['noreturn_entry'] and stage in ('noreturn_only', 'combined'))
            if stage in ('prototype_only', 'combined'):
                assert not f['custom_storage'] and f['convention'] == '__cdecl'
                assert [p['name'] for p in f['parameters']] == [p['name'] for p in proposal['parameters']]
                assert [p['storage'] for p in f['parameters']] == [f'Stack[0x{(i+1)*job["word_size"]:x}]:{job["word_size"]}' for i in range(len(proposal['parameters']))]
                assert all(p['length'] == job['word_size'] for p in f['parameters'])
        stages.append({'stage': stage, 'input_metadata_identical': True, 'metadata_changed': sorted(changed),
                       'metadata_change_count': len(changed), 'c_changed': sorted(c_changed), 'c_change_count': len(c_changed),
                       'all_bodies_locals_listing_references_memory_unchanged': True})
    assert funcs['baseline'] == funcs['reopened_baseline']
    calls = []
    for site in job['direct_calls']:
        counts = {}
        for stage in STAGES:
            matches = [c for c in funcs[stage][site['owner']]['pcode_calls'] if c['address'] == site['site']]
            assert len(matches) == 1, (stage, site, matches)
            counts[stage] = len(matches[0]['inputs']) - 1
        is_nr = site['target'] == job['noreturn_entry']
        expected = {s: ((0 if is_nr else 3) if s in ('prototype_only', 'combined') else (1 if is_nr else 5)) for s in STAGES}
        assert counts == expected, (site, counts)
        calls.append(dict(site, pcode_argument_counts=counts))
    other_call_changes = []
    for entry in job['selected']:
        b = {r['address']: len(r['inputs']) - 1 for r in funcs['baseline'][entry]['pcode_calls']}
        c = {r['address']: len(r['inputs']) - 1 for r in funcs['combined'][entry]['pcode_calls']}
        for site in sorted(b.keys() | c.keys()):
            if b.get(site) != c.get(site) and site not in {r['site'] for r in job['direct_calls']}:
                other_call_changes.append({'owner': entry, 'site': site, 'baseline': b.get(site), 'combined': c.get(site)})
    coverage = bytearray(len(R.RAW))
    memory = read('baseline', 'initialized-memory.json')
    for block in memory:
        start, data = int(block['start'], 16), base64.b64decode(block['bytes'])
        for seg in R.META['segments']:
            addr = int(seg['address'], 16)
            lo, hi = max(start, addr), min(start + len(data), addr + seg['file_size'])
            if lo >= hi:
                continue
            off = seg['file_offset'] + lo - addr
            assert data[lo-start:hi-start] == R.RAW[off:off+hi-lo]
            coverage[off:off+hi-lo] = bytes([1]) * (hi-lo)
    assert all(coverage)
    raw = []
    for p in job['prototypes']:
        entry = int(p['entry'], 16)
        instructions = R.function_instructions(entry)
        frame_reads = []
        for ins in instructions.values():
            for op in ins.operands:
                if op.type == R.X86_OP_MEM and ins.reg_name(op.mem.base) == 'ebp' and op.mem.disp >= 8:
                    frame_reads.append({'address': f'{ins.address:08x}', 'offset': op.mem.disp,
                                        'instruction': f'{ins.mnemonic} {ins.op_str}', 'bytes': ins.bytes.hex()})
        assert sorted({r['offset'] for r in frame_reads}) == ([8, 12, 16] if p['parameters'] else [])
        ida_path = ROOT / '05_ida/exports/x86/functions' / f'{entry:08x}.c'
        ida = ida_path.read_text()
        raw.append({'entry': p['entry'], 'original_frame_argument_operands': frame_reads,
                    'instruction_count': len(instructions), 'ghidra_baseline_signature': base[p['entry']]['signature'],
                    'ghidra_combined_signature': funcs['combined'][p['entry']]['signature'],
                    'ida_stored_prototype': ida.split('{', 1)[0].split('*/', 1)[1].strip(),
                    'ida_noreturn_text_present': '__noreturn' in ida.split('{', 1)[0],
                    'ida_input_caveat': 'Stored ps2 snapshot export only; not a fresh same-input database verification.'})
    summary = {'global_function_records': len(base), 'selected_functions': len(job['selected']),
               'independent_processes': len(STAGES), 'direct_calls_verified': len(calls),
               'direct_calls_by_target': dict(collections.Counter(c['target'] for c in calls)),
               'initialized_blocks': len(memory), 'original_file_bytes_verified': sum(coverage),
               'reopened_exact': True, 'stages': stages}
    (HERE / 'decompiler-diffs.patch').write_text(''.join(diffs))
    (HERE / 'audit.json').write_text(json.dumps({'summary': summary, 'calls': calls, 'raw_abi': raw,
                                               'other_call_argument_changes': other_call_changes}, indent=2) + '\n')
    print(json.dumps({'summary': summary, 'other_call_argument_changes': other_call_changes}, indent=2))


if __name__ == '__main__':
    main()
