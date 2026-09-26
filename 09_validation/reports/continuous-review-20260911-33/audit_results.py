"""Independent raw instruction/state audit; imports no execution modules.

Prefix trace/store/boundary equality is checked against immutable report32.
Original intermediate CPU observations in report32 are not newly recollected here.
"""
import copy
import importlib.util
import itertools
import json
from pathlib import Path
import struct
from verify_artifacts import digest

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PRIOR = HERE.parent / 'continuous-review-20260911-32'
spec = importlib.util.spec_from_file_location('audit32', PRIOR / 'audit_results.py')
F = importlib.util.module_from_spec(spec)
spec.loader.exec_module(F)
B, C, A = F.B, F.C, F.A
VM, HW, PAGE, PG, DATA, PT, VA, PMAP, DESC, EXT = F.VM, F.HW, F.PAGE, F.PG, F.DATA, F.PT, F.VA, F.PMAP, F.DESC, F.EXT
SEGMENTS, SEGCOUNT, CALL_STACK = 0x1f6e60, 0x1f6e98, 0x70ff00
FREE_PT = 0x1f7ad8
CALLEE = {'ebx': 0x12341111, 'esi': 0x23452222, 'edi': 0x34563333, 'ebp': 0x45674444}
PREFIX_KEYS = {'target', 'function', 'destination', 'flags', 'sleepable', 'setup', 'before', 'fault',
    'at_fault', 'cpu_frame_input', 'frame_address', 'native_cpu_frame_verified', 'injected',
    'handler', 'recorded_heads', 'writes', 'after', 'failure'}
NARGS = {0x18fa44: 3, 0x18f7f8: 4, 0x178894: 1, 0x190f90: 5}
MILESTONES = set(NARGS) | {0x18faac, 0x18f8e4, 0x18f94c, 0x18f95a, 0x18f95e,
    0x18f96a, 0x18f96e, 0x18f9bc, 0x191040, 0x19104d, 0x191082, 0x1788cc, 0x1788f0}


def references():
    for item in json.loads((PRIOR / 'artifact-hashes.json').read_text()):
        p = ROOT / item['path']
        assert p.stat().st_size == item['size'] and digest(p) == item['sha256'], p
    rows = json.loads((PRIOR / 'fault-new-pt-cases.json').read_text())
    return {tuple(r[k] for k in ('target', 'function', 'destination', 'flags', 'sleepable')): r for r in rows}


def segment_model():
    raw = bytearray(SEGCOUNT - SEGMENTS + 4)
    for i, (page, phys) in enumerate(((PAGE, DATA), (PG, PT))):
        F.put(raw, i * 0x1c, page, phys >> (VM.bit_length() - 1), 0, 0, 0, phys, phys + VM)
    assert SEGMENTS + 2 * 0x1c == SEGCOUNT
    F.put(raw, SEGCOUNT - SEGMENTS, 2)
    return raw.hex()


def physical_lookup(raw, physical):
    data = bytes.fromhex(raw)
    count = struct.unpack_from('<I', data, SEGCOUNT - SEGMENTS)[0]
    for i in range(count):
        base, first, _, _, _, start, end = struct.unpack_from('<7I', data, i * 0x1c)
        if start <= physical < end:
            return base + ((physical >> (VM.bit_length() - 1)) - first) * 0x30
    return 0


def regions(s):
    out = F.regions(s)
    out[SEGMENTS] = bytes.fromhex(s['physical_segments'])
    return out


def patch(s, field, offset, value, width=4):
    raw = bytearray.fromhex(s[field])
    raw[offset:offset + width] = value.to_bytes(width, 'little')
    s[field] = raw.hex()


def bridge(row, reference):
    prefix = row['prefix']
    assert set(prefix) == PREFIX_KEYS
    assert tuple(prefix[k] for k in ('target', 'function', 'destination', 'flags', 'sleepable')) == tuple(row['params'])
    for k in PREFIX_KEYS:
        assert prefix[k] == reference[k], ('prefix', k)
    F.boundary(prefix['after'], prefix, True)
    expected = copy.deepcopy(prefix['after'])
    expected['physical_segments'] = row['pre_input']['physical_segments']
    assert row['pre_input'] == expected
    assert len(bytes.fromhex(expected['physical_segments'])) == SEGCOUNT - SEGMENTS + 4
    assert int.from_bytes(bytes.fromhex(expected['physical_segments'])[-4:], 'little') == 0
    assert row['input'] == {'segments_address': SEGMENTS, 'segments_bytes': segment_model(),
                           'call_stack': CALL_STACK, 'args': [PMAP, VA, VA + VM], 'eflags': 2}
    expected['physical_segments'] = segment_model()
    raw = bytearray.fromhex(expected['stack_memory'])
    F.put(raw, CALL_STACK - F.STACK, F.STOP, PMAP, VA, VA + VM)
    expected['stack_memory'] = raw.hex()
    expected['cpu'].update(CALLEE, esp=CALL_STACK, eflags=2)
    assert row['before'] == expected, 'unreported change at explicit segment/caller boundary'
    assert physical_lookup(segment_model(), DATA) == PAGE
    assert physical_lookup(segment_model(), DATA + VM - 1) == PAGE
    assert physical_lookup(segment_model(), DATA + VM) == PG
    assert physical_lookup(segment_model(), PT + VM) == 0


def replay(row):
    memories = {a: bytearray(raw) for a, raw in regions(row['before']).items()}
    trace, writes = row['observation']['trace'], row['writes']
    assert [w['trace_index'] for w in writes] == sorted(w['trace_index'] for w in writes)
    for w in writes:
        assert 0 <= w['trace_index'] < len(trace)
        assert w['width'] in (1, 2, 4) and 0 <= w['value'] < (1 << (w['width'] * 8))
        assert trace[w['trace_index']] == hex(w['pc'])
        ins = A.instruction(w['pc'])
        if ins.mnemonic in ('call', 'push'):
            assert w['width'] == 4 and F.STACK <= w['address'] and w['address'] + 4 <= 0x710004
        else:
            dest = [op for op in ins.operands if op.type == A.capstone.x86.X86_OP_MEM and op.access & A.capstone.CS_AC_WRITE]
            assert any(op.size == w['width'] for op in dest), ('not a matching original memory store', w)
    cursor = 0
    for point in row['points'] + [{'state': row['after'], 'trace_index': len(trace), 'write_cursor': len(writes)}]:
        end = point['write_cursor']
        assert cursor <= end <= len(writes)
        assert end == sum(w['trace_index'] < point['trace_index'] for w in writes)
        for w in writes[cursor:end]:
            matches = [(a, raw) for a, raw in memories.items() if a <= w['address'] and w['address'] + w['width'] <= a + len(raw)]
            assert matches, ('uncaptured write', w)
            for a, raw in matches:
                off = w['address'] - a
                raw[off:off + w['width']] = w['value'].to_bytes(w['width'], 'little')
        observed = regions(point['state'])
        assert set(observed) == set(memories)
        for a, expected in memories.items():
            actual = observed[a]
            assert len(expected) == len(actual)
            if a in (F.SHARED, F.ROOTS[row['params'][0]]):
                for off in range(0, len(actual), 4):
                    old, new = struct.unpack_from('<I', expected, off)[0], struct.unpack_from('<I', actual, off)[0]
                    if a == F.SHARED and off not in [((F.KVA + i) >> 12 & 0x3ff) * 4 for i in range(0, VM, HW)]:
                        permit = 0x60 if old & 1 else 0
                    elif a == F.ROOTS[row['params'][0]] and off >= (F.BASE >> 22) * 4:
                        permit = 0x20 if old & 1 else 0
                    else:
                        permit = 0
                    assert new | old == new and (new ^ old) & ~permit == 0, (hex(a + off), hex(old), hex(new))
            else:
                assert actual == expected, ('write replay', hex(a), point.get('pc', 'after'))
            memories[a] = bytearray(actual)
        cursor = end


def after_model(row):
    before, after = row['before'], row['after']
    e = copy.deepcopy(before)
    patch(e, 'page', 0x1e, 0x02, 1)
    patch(e, 'pmap', 0x10, 0)
    patch(e, 'descriptor_arena', F.desc(DATA) - DESC + 4, 0)
    patch(e, 'descriptor_arena', F.desc(DATA) - DESC + 0x10, 3, 1)
    patch(e, 'extension', 0, FREE_PT)
    patch(e, 'extension', 4, FREE_PT)
    patch(e, 'extension', 0x18, 0, 2)
    e['globals']['pt_count'] = 0
    e['queues']['pt'] = [F.ACTIVE, F.ACTIVE]
    e['pt_free_queue'], e['pt_free_count'] = [EXT, EXT], 1
    e['tlb_counters'] = [v + 1 for v in before['tlb_counters']]
    e['new_pt_frame'] = bytes(VM).hex()
    for i in range(VM // HW):
        raw = bytearray.fromhex(e['roots'][row['params'][0]])
        old = struct.unpack_from('<I', raw, i * 4)[0]
        F.put(raw, i * 4, old & ~1)
        e['roots'][row['params'][0]] = raw.hex()
    # These regions/views are checked independently by replay, contract and ABI below.
    for key in ('cpu', 'stack_memory', 'raw_translation', 'new_walks', 'data_high_walks'):
        e[key] = after[key]
    # Only high-kernel PDE Accessed is permitted outside original PDE clear writes.
    target = row['params'][0]
    raw = bytearray.fromhex(e['roots'][target])
    observed = bytes.fromhex(after['roots'][target])
    for off in range((F.BASE >> 22) * 4, len(raw), 4):
        old, new = struct.unpack_from('<I', raw, off)[0], struct.unpack_from('<I', observed, off)[0]
        assert new == old or (old & 1 and new == old | 0x20)
        F.put(raw, off, new)
    e['roots'][target] = raw.hex()
    assert after == e, 'final ownership/state model'
    for field, value in CALLEE.items():
        assert after['cpu'][field] == value
    for field in ('cs', 'ds', 'es', 'ss', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4'):
        assert after['cpu'][field] == before['cpu'][field]
    assert after['cpu']['esp'] == CALL_STACK + 4 and after['cpu']['eip'] == F.STOP
    assert after['cpu']['eax'] == 7  # observed splx residual, not a pmap_remove success ABI.
    assert after['cpu']['eflags'] & 0x600 == 0x200  # caller DF clear; original splx executes STI.


def audit_case(row, reference):
    bridge(row, reference)
    assert row['failure'] is None and not row['native_cpu_frame_verified'] and not row['whole_ownership_verified']
    obs = row['observation']
    trace = obs['trace']
    assert obs['error'] is None and not obs['interrupts'] and obs['after'] == row['after']['cpu']
    assert trace == row['recorded_heads'] and trace[0] == '0x18fa44'
    C.trace_check(trace, F.STOP)
    forbidden = {0x10ca6c, 0x163320, 0x1631a0, 0x16b790, 0x16b84c, 0x17b540, 0x17b6e8,
                 0x18b59b, 0x18b5dc, 0x18b5ef, 0x18fa90, 0x18faa5}
    assert not any(int(pc, 16) in forbidden for pc in trace)
    assert [p['trace_index'] for p in row['points']] == [i for i, pc in enumerate(trace) if int(pc, 16) in MILESTONES]
    for s in [row['before']] + [p['state'] for p in row['points']] + [row['after']]:
        F.contract(s, row['prefix'])
        assert s['physical_segments'] == segment_model()
    for p in row['points']:
        assert trace[p['trace_index']] == p['pc'] and p['cpu'] == p['state']['cpu'] and p['cpu']['eip'] == int(p['pc'], 16)
        if int(p['pc'], 16) in NARGS:
            memory = regions(p['state'])
            assert p['args'] == [B.read_word(memory, p['cpu']['esp'] + 4 + i * 4) for i in range(NARGS[int(p['pc'], 16)])]
    def points(pc):
        return [p for p in row['points'] if p['pc'] == hex(pc)]
    def one(pc):
        found = points(pc)
        assert len(found) == 1, hex(pc)
        return found[0]
    assert one(0x18fa44)['args'] == [PMAP, VA, VA + VM]
    assert one(0x18f7f8)['args'] == [PMAP, VA, VA + VM, 1]
    assert one(0x178894)['args'] == [DATA]
    assert one(0x190f90)['args'] == [PMAP, VA, 1, 0, 1]
    assert [p['cpu']['edx'] for p in points(0x18faac)] == [VA + off for off in range(0, VM, HW)]
    assert points(0x18faac)[-1]['trace_index'] < one(0x18f7f8)['trace_index']
    lookup = one(0x1788cc)
    assert lookup['cpu']['ebx'] == DATA and lookup['cpu']['edi'] == SEGMENTS and lookup['cpu']['edx'] == SEGMENTS + 4
    assert lookup['cpu']['eax'] == SEGCOUNT
    assert lookup['cpu']['esi'] == DATA >> (VM.bit_length() - 1)
    assert one(0x1788f0)['cpu']['eax'] == one(0x18f95a)['cpu']['eax'] == physical_lookup(lookup['state']['physical_segments'], DATA) == PAGE
    assert one(0x18f95a)['state']['page'] == row['before']['page']
    assert F.value(one(0x18f95e)['state'], 'page', 0x1e, 'B') == 2
    for pc in (0x18f95e, 0x18f96a):
        assert one(pc)['cpu']['ebx'] == F.desc(DATA)
    assert F.value(one(0x18f96a)['state'], 'descriptor_arena', F.desc(DATA) - DESC + 0x10, 'B') == 1
    assert one(0x18f9bc)['cpu']['esi'] == F.desc(DATA)
    offset = ((VA & (0x800000 - 1)) >> 12) * 4
    pte_addresses = [PT + offset + i * 4 for i in range(VM // HW)]
    clears = points(0x18f96e)
    assert [p['cpu']['edi'] for p in clears] == pte_addresses
    dirty_index = row['params'][2] // HW
    assert one(0x18f95a)['cpu']['edi'] == pte_addresses[dirty_index]
    assert one(0x18f95a)['trace_index'] < one(0x18f95e)['trace_index'] < one(0x18f96a)['trace_index'] < clears[dirty_index]['trace_index']
    if dirty_index:
        assert clears[0]['trace_index'] < one(0x178894)['trace_index']
    assert clears[-1]['trace_index'] < one(0x18f9bc)['trace_index'] < one(0x190f90)['trace_index']
    expected_stores = {0x18f95a: [(PAGE + 0x1e, 1, 2)], 0x18f95e: [(F.desc(DATA) + 0x10, 1, 1)],
        0x18f96a: [(F.desc(DATA) + 0x10, 1, 3)], 0x18f96e: [(a, 4, 0) for a in pte_addresses],
        0x18f9bc: [(F.desc(DATA) + 4, 4, 0)],
        0x191040: [(F.ROOTS[row['params'][0]] + i * 4, 1,
                     bytes.fromhex(row['before']['roots'][row['params'][0]])[i * 4] & ~1) for i in range(VM // HW)]}
    for pc, want in expected_stores.items():
        found = [w for w in row['writes'] if w['pc'] == pc]
        assert [(w['address'], w['width'], w['value']) for w in found] == want, hex(pc)
        assert [w['trace_index'] for w in found] == [p['trace_index'] for p in points(pc)]
    assert [p['cpu']['esi'] for p in points(0x191040)] == [a for a, _, _ in expected_stores[0x191040]]
    assert points(0x191040)[0]['trace_index'] > one(0x190f90)['trace_index']
    assert points(0x191040)[-1]['trace_index'] < one(0x19104d)['trace_index'] < one(0x191082)['trace_index']
    assert one(0x19104d)['state']['queues']['pt'] == [EXT, EXT]
    assert one(0x191082)['state']['pt_free_queue'] == [EXT, EXT]
    replay(row)
    after_model(row)
    return {'params': row['params'], 'passed': True, 'remove_heads': len(trace), 'dirty_lookups': len(points(0x178894)),
            'pte_clears': len(clears), 'pde_invalidations': len(points(0x191040))}


def main():
    refs = references()
    rows = json.loads((HERE / 'dirty-remove-cases.json').read_text())
    matrix = set(itertools.product(F.ROOTS, F.COPY, (0x100, 0x1100), (2, 0x602), (1, 0)))
    assert len(rows) == len(matrix) and {tuple(r['params']) for r in rows} == matrix
    result = [audit_case(r, refs[tuple(r['params'])]) for r in rows]
    out = {'all_passed': True, 'cases': result, 'scope': 'recorded original execution; native hardware/full ownership not verified'}
    (HERE / 'independent-audit.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps({'independently_audited_cases': len(result), 'all_passed': True}))


if __name__ == '__main__':
    main()
