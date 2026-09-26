"""Audit isolation, recovered placement, and rejected RMW access multiplicity."""
import base64
import collections
import difflib
import json
import re
from run_experiment import HERE, ROOT, R, STAGES

BUILTINS = json.loads((HERE.parent / 'continuous-review-20260911-12/audit.json').read_text())['builtin_ids']


def load(stage, name):
    return json.loads((HERE / 'exports' / stage / name).read_text())


def indexed(rows):
    return {r['entry']: r for r in rows}


def node(text):
    m = re.fullmatch(r'\(([^,]+), (0x[0-9a-f]+), ([0-9]+)\)', text)
    assert m, text
    return m[1], int(m[2], 16), int(m[3])


def ops(function):
    return [o for b in function['high_blocks'] for o in b['operations']]


def memory_events(function):
    result = []
    for o in ops(function):
        if o['opcode'] != 'CALLOTHER':
            continue
        kind = next((kind for kind, value in BUILTINS.items() if value == node(o['inputs'][0])[1]), None)
        if kind:
            result.append((o['address'], f'{node(o["inputs"][1])[1]:08x}', kind))
    return result


def dominators(function):
    blocks = {b['index']: b for b in function['high_blocks']}
    roots = [i for i, b in blocks.items() if not b['incoming']]
    assert len(roots) == 1
    root = roots[0]
    for i, b in blocks.items():
        assert len(b['incoming']) == b['in_size'] and len(b['outgoing']) == b['out_size']
        assert all(j in blocks and i in blocks[j]['incoming'] for j in b['outgoing'])
    reachable, todo = set(), [root]
    while todo:
        i = todo.pop()
        if i not in reachable:
            reachable.add(i)
            todo.extend(blocks[i]['outgoing'])
    d = {i: ({root} if i == root else set(reachable)) for i in reachable}
    while True:
        old = {i: set(v) for i, v in d.items()}
        for i in reachable - {root}:
            incoming = [d[j] for j in blocks[i]['incoming'] if j in reachable]
            d[i] = {i} | set.intersection(*incoming)
        if d == old:
            return blocks, d


def main():
    job = json.loads((HERE / 'job.json').read_text())
    all_f = load('baseline', 'all-functions.json')
    all_d = indexed(load('baseline', 'data-records.json'))
    selected = {s: indexed(load(s, 'functions.json')) for s in STAGES}
    active = {'baseline': set(), 'lock_only': set(job['locks']), 'data_only': set(job['related_data']),
              'combined': set(job['locks']) | set(job['related_data']), 'reopened_baseline': set()}
    expected = collections.Counter()
    for ref in job['direct_operand_sites']:
        ins = R.function_instructions(int(ref['owner'], 16))[int(ref['site'], 16)]
        for op in ins.operands:
            if op.type != R.X86_OP_MEM or op.mem.base or op.mem.index or op.mem.disp != int(ref['target'], 16) or ins.mnemonic == 'lea':
                continue
            assert op.size == job['word_size']
            for kind, flag in [('read', 1), ('write', 2)]:
                if op.access & flag:
                    expected[(ref['owner'], ref['site'], ref['target'], kind)] += 1
    stages, diff = [], []
    discrepancies = []
    for stage in STAGES:
        assert json.loads((HERE / 'exports' / f'{stage}-execution-marker.json').read_text()) == {
            'class': 'ProtectedDataExperiment', 'version': 'protected-data-v1', 'stage': stage}
        assert json.loads((HERE / 'exports' / f'{stage}-input-functions.json').read_text()) == all_f
        assert indexed(json.loads((HERE / 'exports' / f'{stage}-input-data.json').read_text())) == all_d
        assert load(stage, 'all-functions.json') == all_f
        data = indexed(load(stage, 'data-records.json'))
        assert data.keys() == all_d.keys()
        changed = {a for a in all_d if data[a] != all_d[a]}
        assert changed == active[stage]
        for a in changed:
            assert data[a]['volatile'] and not all_d[a]['volatile']
            assert {k: v for k, v in data[a].items() if k not in ('volatile', 'mutability')} == {k: v for k, v in all_d[a].items() if k not in ('volatile', 'mutability')}
        for filename in ('code-units.tsv', 'references.tsv'):
            assert (HERE / 'exports' / stage / filename).read_bytes() == (HERE / 'exports/baseline' / filename).read_bytes()
        assert load(stage, 'initialized-memory.json') == load('baseline', 'initialized-memory.json')
        assert sorted(selected[stage]) == job['selected'] and all(f['completed'] for f in selected[stage].values())
        c_changed = []
        for a in job['selected']:
            text = (HERE / 'exports' / stage / f'{a}.c').read_text()
            base = (HERE / 'exports/baseline' / f'{a}.c').read_text()
            if text != base:
                c_changed.append(a)
                diff.extend(difflib.unified_diff(base.splitlines(True), text.splitlines(True), fromfile=f'baseline/{a}.c', tofile=f'{stage}/{a}.c'))
            if stage == 'baseline':
                old = re.sub(r'^\s*/\* Ghidra decompiler output,.*?\*/', '', (R.G / 'functions' / f'{a}.c').read_text(), count=1, flags=re.S).strip()
                assert text.strip() == old
        actual = collections.Counter((owner, site, target, kind) for owner, f in selected[stage].items() for site, target, kind in memory_events(f))
        expect = collections.Counter({key: count for key, count in expected.items() if key[2] in active[stage]})
        missing, extra = expect - actual, actual - expect
        assert not missing, (stage, missing)
        for key, count in extra.items():
            ins = R.function_instructions(int(key[0], 16))[int(key[1], 16)]
            assert ins.mnemonic in ('inc', 'dec') and key[-1] == 'read' and count == 4
            discrepancies.append({'stage': stage, 'owner': key[0], 'site': key[1], 'target': key[2], 'kind': key[3],
                                  'instruction': f'{ins.mnemonic} {ins.op_str}', 'expected': expect[key], 'actual': actual[key]})
        if stage in ('baseline', 'lock_only', 'reopened_baseline'):
            assert not extra
        else:
            assert extra, 'Expected expanded-volatility fidelity failure must not be hidden'
        stages.append({'stage': stage, 'data_change_count': len(changed), 'c_changed': c_changed, 'c_change_count': len(c_changed),
                       'volatile_reads': sum(v for k, v in actual.items() if k[-1] == 'read'),
                       'volatile_writes': sum(v for k, v in actual.items() if k[-1] == 'write'),
                       'expected_reads': sum(v for k, v in expect.items() if k[-1] == 'read'),
                       'expected_writes': sum(v for k, v in expect.items() if k[-1] == 'write'),
                       'extra_read_effects': sum(extra.values()), 'extra_read_sites': len(extra),
                       'active_data_access_fidelity_pass': actual == expect,
                       'metadata_listing_references_memory_isolation_pass': True})
    assert selected['baseline'] == selected['reopened_baseline']
    prior = HERE.parent / 'continuous-review-20260911-12'
    prior_job = json.loads((prior / 'job.json').read_text())
    for a in prior_job['selected']:
        for old, new in [('baseline', 'baseline'), ('volatile_only', 'lock_only')]:
            assert (prior / 'exports' / old / f'{a}.c').read_bytes() == (HERE / 'exports' / new / f'{a}.c').read_bytes()
    placement = []
    for stage in STAGES:
        f = selected[stage]['0015ec00']
        blocks, dom = dominators(f)
        queue = [(b['index'], o) for b in blocks.values() for o in b['operations']
                 if o['opcode'] == 'CALLOTHER' and o['address'] == '0015ec54' and node(o['inputs'][0])[1] == BUILTINS['read']]
        acquisitions = [(b['index'], i) for b in blocks.values() for i, o in enumerate(b['operations'])
                        if o['opcode'] == 'CALLOTHER' and o.get('userop') == 'LOCK' and o['address'] == '0015ec19']
        assert len(acquisitions) == 1
        acquire_block, acquire_position = acquisitions[0]
        # Initial draft assumed the hoisted COPY retained address 0015ec08.
        # Baseline places it at 0015ec10. Use CFG dominance/order, not that label.
        early = [o for b in blocks.values() for i, o in enumerate(b['operations'])
                 if o['opcode'] == 'COPY' and o['inputs'] == ['(ram, 0x1f64d0, 4)']
                 and b['index'] in dom[acquire_block] and (b['index'] != acquire_block or i < acquire_position)]
        retry = [b for b in blocks.values() if any(o['opcode'] == 'CBRANCH' and o['address'] == '0015ec24' for o in b['operations'])]
        assert bool(queue) == (stage in ('data_only', 'combined'))
        assert bool(early) == (stage not in ('data_only', 'combined'))
        assert bool(retry) == (stage in ('lock_only', 'combined'))
        row = {'stage': stage, 'queue_read_at_original_site': bool(queue), 'early_queue_copy_present': bool(early),
               'acquisition_retry_present': bool(retry)}
        if queue and retry:
            retry_block = retry[0]
            success = [i for i in retry_block['outgoing'] if blocks[i]['start'] != '0015ec08']
            assert len(success) == 1 and success[0] in dom[queue[0][0]]
            row['queue_read_dominated_by_success_edge_destination'] = True
        placement.append(row)
    coverage = bytearray(len(R.RAW))
    for block in load('baseline', 'initialized-memory.json'):
        start, blob = int(block['start'], 16), base64.b64decode(block['bytes'])
        for seg in R.META['segments']:
            addr = int(seg['address'], 16)
            lo, hi = max(start, addr), min(start + len(blob), addr + seg['file_size'])
            if lo < hi:
                off = seg['file_offset'] + lo - addr
                assert blob[lo-start:hi-start] == R.RAW[off:off+hi-lo]
                coverage[off:off+hi-lo] = bytes([1]) * (hi-lo)
    assert all(coverage)
    summary = {'functions_checked': len(all_f), 'defined_data_checked': len(all_d), 'selected_functions': len(job['selected']),
               'original_file_bytes_verified': sum(coverage), 'prior_selected_c_controls_verified': len(prior_job['selected']),
               'stages': stages, 'expanded_volatility_accepted_as_faithful_model': False}
    (HERE / 'audit.json').write_text(json.dumps({'summary': summary, 'placement': placement, 'access_discrepancies': discrepancies}, indent=2) + '\n')
    (HERE / 'decompiler-diffs.patch').write_text(''.join(diff))
    print(json.dumps({'summary': summary, 'placement': placement}, indent=2))


if __name__ == '__main__':
    main()
