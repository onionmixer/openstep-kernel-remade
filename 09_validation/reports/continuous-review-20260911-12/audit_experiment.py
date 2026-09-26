"""Audit isolation and every original access to the selected lock words."""
import base64
import collections
import difflib
import hashlib
import json
import re
from pathlib import Path
from run_experiment import HERE, ROOT, R, STAGES

CPP = Path('/home/onion/ghidra_12.1_PUBLIC/Ghidra/Features/Decompiler/src/decompile/cpp')


def load(stage, name):
    return json.loads((HERE / 'exports' / stage / name).read_text())


def indexed(rows):
    return {r['entry']: r for r in rows}


def node(text):
    match = re.fullmatch(r'\(([^,]+), (0x[0-9a-f]+), ([0-9]+)\)', text)
    assert match, text
    return match[1], int(match[2], 16), int(match[3])


def operations(function):
    return [o for b in function['high_blocks'] for o in b['operations']]


def main():
    job = json.loads((HERE / 'job.json').read_text())
    base_f = load('baseline', 'all-functions.json')
    base_d = indexed(load('baseline', 'data-records.json'))
    selected = {s: indexed(load(s, 'functions.json')) for s in STAGES}
    references = job['direct_operand_sites']
    # Builtin ids are pinned from this installed Ghidra source, not guessed.
    userop_source = (CPP / 'userop.cc').read_text()
    builtin = {kind: int(re.search(r'BUILTIN_VOLATILE_' + kind.upper() + r' = (0x[0-9a-f]+);', userop_source)[1], 16)
               for kind in ('read', 'write')}
    stages, diff = [], []
    for stage in STAGES:
        assert json.loads((HERE / 'exports' / f'{stage}-execution-marker.json').read_text()) == {
            'class': 'VolatileLockExperiment', 'version': 'volatile-lock-v1', 'stage': stage}
        assert json.loads((HERE / 'exports' / f'{stage}-input-functions.json').read_text()) == base_f
        assert indexed(json.loads((HERE / 'exports' / f'{stage}-input-data.json').read_text())) == base_d
        assert load(stage, 'all-functions.json') == base_f
        data = indexed(load(stage, 'data-records.json'))
        assert data.keys() == base_d.keys()
        changed = {a for a in data if data[a] != base_d[a]}
        assert changed == (set(job['locks']) if stage == 'volatile_only' else set()), (stage, changed)
        for addr in changed:
            assert {k: v for k, v in data[addr].items() if k not in ('volatile', 'mutability')} == {
                k: v for k, v in base_d[addr].items() if k not in ('volatile', 'mutability')}
            assert data[addr]['volatile'] and not base_d[addr]['volatile']
        for filename in ('code-units.tsv', 'references.tsv'):
            assert (HERE / 'exports' / stage / filename).read_bytes() == (HERE / 'exports/baseline' / filename).read_bytes()
        assert load(stage, 'initialized-memory.json') == load('baseline', 'initialized-memory.json')
        assert sorted(selected[stage]) == job['selected']
        assert all(f['completed'] for f in selected[stage].values())
        c_changed = []
        for addr in job['selected']:
            text = (HERE / 'exports' / stage / f'{addr}.c').read_text()
            base = (HERE / 'exports/baseline' / f'{addr}.c').read_text()
            if stage == 'baseline':
                old = (R.G / 'functions' / f'{addr}.c').read_text()
                old = re.sub(r'^\s*/\* Ghidra decompiler output,.*?\*/', '', old, count=1, flags=re.S).strip()
                assert text.strip() == old, addr
            if text != base:
                c_changed.append(addr)
                diff.extend(difflib.unified_diff(base.splitlines(True), text.splitlines(True),
                                               fromfile=f'baseline/{addr}.c', tofile=f'{stage}/{addr}.c'))
        if stage != 'volatile_only':
            assert not c_changed
        else:
            assert set(c_changed) <= {r['owner'] for r in references}
        stages.append({'stage': stage, 'data_metadata_changed': sorted(changed), 'data_change_count': len(changed),
                       'c_changed': c_changed, 'c_change_count': len(c_changed),
                       'function_metadata_listing_references_memory_identical': True})
    assert selected['baseline'] == selected['reopened_baseline']
    # Re-check initialized file-backed bytes against Mach-O segment mappings.
    coverage = bytearray(len(R.RAW))
    memory = load('baseline', 'initialized-memory.json')
    for block in memory:
        start, blob = int(block['start'], 16), base64.b64decode(block['bytes'])
        for seg in R.META['segments']:
            addr = int(seg['address'], 16)
            lo, hi = max(start, addr), min(start + len(blob), addr + seg['file_size'])
            if lo >= hi:
                continue
            off = seg['file_offset'] + lo - addr
            assert blob[lo-start:hi-start] == R.RAW[off:off+hi-lo]
            coverage[off:off+hi-lo] = bytes([1]) * (hi-lo)
    assert all(coverage)
    expected, actual, exchanges = collections.Counter(), collections.Counter(), []
    for ref in references:
        ins = R.function_instructions(int(ref['owner'], 16))[int(ref['site'], 16)]
        operands = [op for op in ins.operands if op.type == R.X86_OP_MEM and not op.mem.base and not op.mem.index and op.mem.disp == int(ref['lock'], 16)]
        assert len(operands) == 1 and operands[0].size == job['word_size']
        op = operands[0]
        for kind, flag in [('read', 1), ('write', 2)]:
            if op.access & flag:
                expected[(ref['owner'], ref['site'], ref['lock'], kind)] += 1
        if ins.mnemonic == 'xchg':
            ops = [o for o in operations(selected['volatile_only'][ref['owner']]) if o['address'] == ref['site'] and o['opcode'] == 'CALLOTHER']
            events = []
            for o in ops:
                identifier = node(o['inputs'][0])[1]
                events.append(next((k for k, v in builtin.items() if identifier == v), o.get('userop')))
            assert events == ['LOCK', 'read', 'write', 'UNLOCK'], (ref, events)
            exchanges.append({'owner': ref['owner'], 'site': ref['site'], 'lock': ref['lock'], 'event_order': events})
    for owner, f in selected['volatile_only'].items():
        for o in operations(f):
            if o['opcode'] != 'CALLOTHER':
                continue
            identifier = node(o['inputs'][0])[1]
            kind = next((k for k, v in builtin.items() if identifier == v), None)
            if kind is None:
                continue
            space, addr, annotation_size = node(o['inputs'][1])
            assert space == 'ram'
            lock = f'{addr:08x}'
            assert lock in job['locks']
            # Address annotation size is not the memory access width.
            width = node(o['output'])[2] if kind == 'read' else node(o['inputs'][2])[2]
            assert width == job['word_size']
            actual[(owner, o['address'], lock, kind)] += 1
    assert actual == expected, {'missing': list((expected-actual).items()), 'extra': list((actual-expected).items())}
    # All selected global wait/retry sites from the independent preceding scan.
    sites = json.loads((HERE.parent / 'continuous-review-20260911-11/scan.json').read_text())['sites']
    branch_rows = []
    for site in sites:
        if site['owner'] not in selected['baseline']:
            continue
        ins = R.function_instructions(int(site['owner'], 16))
        condition = site['condition']['address']
        read_pc = site['load']['address'] if site['load'] else condition
        matching = [ref for ref in references if ref['owner'] == site['owner'] and ref['site'] == read_pc]
        if not matching:
            continue
        exchange = int(next(i['address'] for i in site['following_window'] if i['mnemonic'] == 'xchg'), 16)
        cursor = exchange + ins[exchange].size
        for _ in range(8):
            op = ins[cursor]
            if op.mnemonic in ('je', 'jne'):
                break
            cursor += op.size
        assert op.mnemonic in ('je', 'jne')
        retry = f'{op.address:08x}'
        states = {}
        for stage in STAGES:
            ops = operations(selected[stage][site['owner']])
            states[stage] = {label: any(o['opcode'] == 'CBRANCH' and o['address'] == addr for o in ops)
                             for label, addr in [('wait', site['branch']['address']), ('retry', retry)]}
        assert all(states['volatile_only'].values())
        vf = selected['volatile_only'][site['owner']]
        wait_blocks = [b for b in vf['high_blocks'] if any(o['opcode'] == 'CBRANCH' and o['address'] == site['branch']['address'] for o in b['operations'])]
        read_blocks = [b for b in vf['high_blocks'] if any(o['opcode'] == 'CALLOTHER' and o['address'] == read_pc and node(o['inputs'][0])[1] == builtin['read'] for o in b['operations'])]
        assert len(wait_blocks) == 1 and len(read_blocks) == 1
        inside = read_blocks[0]['index'] == wait_blocks[0]['index']
        assert inside == (site['kind'] == 'memory_poll'), site
        branch_rows.append({'owner': site['owner'], 'wait': site['branch']['address'], 'retry': retry,
                            'kind': site['kind'], 'states': states, 'read_inside_wait_block': inside})
    summary = {'global_function_records': len(base_f), 'defined_data_records': len(base_d),
               'selected_functions': len(job['selected']), 'original_bytes_verified': sum(coverage),
               'stages': stages, 'original_operand_sites': len(references),
               'volatile_read_events': sum(n for key, n in actual.items() if key[-1] == 'read'),
               'volatile_write_events': sum(n for key, n in actual.items() if key[-1] == 'write'),
               'exchange_event_sequences_verified': len(exchanges), 'lock_wait_sites_verified': len(branch_rows),
               'wait_branches_recovered': sum(not r['states']['baseline']['wait'] for r in branch_rows),
               'retry_branches_recovered': sum(not r['states']['baseline']['retry'] for r in branch_rows),
               'reopened_baseline_exact': True}
    (HERE / 'audit.json').write_text(json.dumps({'summary': summary, 'builtin_ids': builtin,
                                               'wait_sites': branch_rows, 'exchange_sites': exchanges,
                                               'memory_events': [{'owner': k[0], 'site': k[1], 'lock': k[2], 'kind': k[3], 'count': n} for k, n in sorted(actual.items())]}, indent=2) + '\n')
    (HERE / 'decompiler-diffs.patch').write_text(''.join(diff))
    source_paths = [CPP / 'userop.cc', CPP / 'funcdata_varnode.cc', CPP / 'userop.hh']
    (HERE / 'tool-source-hashes.json').write_text(json.dumps([{'path': str(p), 'size': p.stat().st_size, 'sha256': hashlib.sha256(p.read_bytes()).hexdigest()} for p in source_paths], indent=2) + '\n')
    excerpts = []
    for path, needle, length in [(CPP / 'userop.cc', 'const uint4 UserPcodeOp::BUILTIN_VOLATILE_READ', 2),
                                 (CPP / 'userop.cc', 'UserPcodeOp *UserOpManage::registerBuiltin', 24),
                                 (CPP / 'funcdata_varnode.cc', 'bool Funcdata::replaceVolatile', 54)]:
        lines = path.read_text().splitlines()
        start = next(i for i, line in enumerate(lines) if needle in line)
        excerpts.append({'path': str(path), 'start_line': start + 1, 'excerpt': '\n'.join(lines[start:start+length])})
    (HERE / 'tool-source-evidence.json').write_text(json.dumps(excerpts, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
