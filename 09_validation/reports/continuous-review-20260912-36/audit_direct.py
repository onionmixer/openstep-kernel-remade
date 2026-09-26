"""Independent recorded-byte/state audit of the supplemental direct call.

No execution-module imports. Not a complete CPU or native exception model.
"""
import copy
import itertools
import json
from pathlib import Path
import struct
import audit_diagnostic as E

HERE = Path(__file__).resolve().parent
R, G, F, B, A = E.R, E.G, E.F, E.B, E.A
VM, HW, PAGE, PG, DATA, PT, VA, PMAP, DESC, EXT = G.VM, G.HW, G.PAGE, G.PG, G.DATA, G.PT, G.VA, G.PMAP, G.DESC, G.EXT
KO, KM, KE, KVA, KP, EZ, XZ = G.KO, G.KM, G.KE, G.KVA, G.KP, G.EZ, G.XZ
NARGS = {0x19065c: 5, 0x190cfc: 2, 0x173d1c: 3, 0x174a90: 6, 0x16b790: 1,
         0x16b84c: 2, 0x176164: 3, 0x174848: 5, 0x173ebc: 4, 0x17b200: 3,
         0x175b2c: 4, 0x173898: 3, 0x17b6e8: 1}
MILESTONES = set(NARGS) | {0x174bf4, 0x173f04, 0x173f92, 0x173a11, 0x1735c3,
    0x173e3a, 0x190d7b, 0x190d9b, 0x190de5, 0x190e20, 0x190f1a, 0x1907b1,
    0x190788, 0x1909d5, 0x1909ed, 0x190aa7, 0x190ef4, 0x190af0, 0x16b3c1, 0x174933}
ZERO_PCS = (0x1019cc, 0x1019cf, 0x1019d2, 0x1019d5, 0x1019d8, 0x1019db, 0x1019de, 0x1019e1)


def references():
    rows = json.loads((HERE.parent / 'continuous-review-20260912-34/gc-cases.json').read_text())
    return {tuple(r['params']): r for r in rows if (r['last'], r['tick']) == (1, 3)}


def allowed_memory(expected, actual, target):
    # This GC-warmed direct-call boundary has no unexplained hardware A/D delta.
    # Reject all unrecorded byte changes; do not borrow the earlier broad alias mask.
    assert set(expected) == set(actual)
    for address, old_raw in expected.items():
        new_raw = actual[address]
        assert len(new_raw) == len(old_raw)
        assert bytes(new_raw) == bytes(old_raw), ('memory mismatch', hex(address))


def replay(row):
    # Store opcode/width/cardinality is checked by R.cardinality, including REP.
    memory = {a: bytearray(raw) for a, raw in G.regions(row['before']).items()}
    writes, trace, cursor = row['writes'], row['observation']['trace'], 0
    assert [w['trace_index'] for w in writes] == sorted(w['trace_index'] for w in writes)
    for point in row['points'] + [{'state': row['after'], 'trace_index': len(trace), 'write_cursor': len(writes)}]:
        end = point['write_cursor']
        assert cursor <= end <= len(writes)
        assert end == sum(w['trace_index'] < point['trace_index'] for w in writes)
        for w in writes[cursor:end]:
            matched = [a for a, raw in memory.items() if a <= w['address'] and w['address'] + w['width'] <= a + len(raw)]
            assert matched, ('uncaptured write', w)
            for a in matched:
                off = w['address'] - a
                memory[a][off:off + w['width']] = w['value'].to_bytes(w['width'], 'little')
        actual = G.regions(point['state'])
        allowed_memory(memory, actual, row['params'][0])
        memory = {a: bytearray(raw) for a, raw in actual.items()}
        cursor = end


def bridge(row, refs):
    params = tuple(row['params'])
    assert params in refs
    ref = refs[params]
    assert row['prefix34_canonical_sha256'] == G.canonical(ref)
    assert row['prefix_scope'] == 'producer full-row equality; independent direct audit starts at caller input'
    assert row['pre_input'] == ref['after']
    words = [F.STOP, PMAP, VA, DATA, 3, 0]
    assert row['input'] == {'call_stack': G.CALL_STACK, 'words': words, 'eflags': 2}
    expected = copy.deepcopy(ref['after'])
    for i, word in enumerate(words):
        G.R.patch(expected, 'stack_memory', G.CALL_STACK - F.STACK + i * 4, word)
    expected['cpu'].update(G.R.CALLEE, esp=G.CALL_STACK, eflags=2)
    assert row['before'] == expected, 'unreported direct caller boundary change'
    for k in ('actual_fault_reentry_verified', 'native_exception_verified', 'whole_ownership_verified'):
        assert row[k] is False, k


def final_model(row):
    b, actual = row['before'], row['after']
    e = copy.deepcopy(b)
    patch = G.R.patch
    def put(field, offset, *words):
        for i, word in enumerate(words):
            patch(e, field, offset + i * 4, word)
    put('kernel_object', 0, PG, PG)
    patch(e, 'kernel_object', 0x18, 2, 2)
    patch(e, 'kernel_object', 0x1a, 1, 2)
    raw = bytearray(0x30)
    F.put(raw, 8, KO, KO, 0, KO, KVA)
    F.put(raw, 0x1c, 1, fmt='H')
    raw[0x1e], raw[0x20] = 0x20, 4
    F.put(raw, 0x24, PT)
    e['kernel_page'] = raw.hex()
    put('kernel_map', 0xc, KE, KE)
    put('kernel_map', 0x1c, 1)
    put('kernel_map', 0x28, VM)
    put('kernel_map', 0x40, KE)
    put('kernel_map', 0x4c, B.value(b, 'kernel_map', 0x4c) + 3)
    e['kernel_entry'] = struct.pack('<11I', KM + 0xc, KM + 0xc, KVA, KVA + VM, KO, KVA, 0, 3, 7, 1, 1).hex()
    for field in ('entry_zone', 'extension_zone'):
        put(field, 8, 1, 0, 0)
    put('pmap', 0x10, 1, 0)
    put('kernel_pmap', 0x10, 1, 1)
    put('descriptor_arena', F.desc(PT) - DESC, 0, KP, KVA, EXT)
    put('descriptor_arena', F.desc(DATA) - DESC, 0, PMAP, VA)
    assert B.value(b, 'descriptor_arena', F.desc(DATA) - DESC + 0x10) == 3
    e['extension'] = struct.pack('<8I', F.ACTIVE, F.ACTIVE, F.desc(PT), PT, PMAP, 0, 1, 0).hex()
    put('buckets', ((KO + (KVA >> (VM.bit_length() - 1))) & 7) * 8 + 4, PG)
    e['globals'].update(free_count=0, pt_count=1, fault_count=b['globals']['fault_count'] + 1)
    e['new_globals']['wire_count'] = 1
    e['queues'].update(free=[F.FREE, F.FREE], pt=[EXT, EXT])
    e['pt_alloc_count'] = 1
    e['tlb_counters'] = [v + 1 for v in b['tlb_counters']]
    pt = bytearray(VM)
    for off in range(0, VM, HW):
        F.put(pt, (((VA + off) & (0x800000 - 1)) >> 12) * 4, (DATA + off) | 7)
    e['new_pt_frame'] = pt.hex()
    target = row['params'][0]
    roots = bytearray.fromhex(e['roots'][target])
    shared = bytearray.fromhex(e['raw_translation'][hex(F.SHARED)])
    for i, off in enumerate(range(0, VM, HW)):
        F.put(roots, i * 4, (PT + off) | 7)
        F.put(shared, ((KVA + off) >> 12 & 0x3ff) * 4, (PT + off) | 0x203)
    e['roots'][target] = roots.hex()
    e['raw_translation'][hex(F.SHARED)] = shared.hex()
    # All raw translation bytes must match; no unrecorded A/D changes are accepted.
    allowed_memory({F.ROOTS[k]: bytes.fromhex(v) for k, v in e['roots'].items()},
                   {F.ROOTS[k]: bytes.fromhex(v) for k, v in actual['roots'].items()}, target)
    allowed_memory({int(k, 16): bytes.fromhex(v) for k, v in e['raw_translation'].items()},
                   {int(k, 16): bytes.fromhex(v) for k, v in actual['raw_translation'].items()}, target)
    for key in e:
        if key not in ('cpu', 'stack_memory', 'roots', 'raw_translation', 'new_walks'):
            assert actual[key] == e[key], ('final state model', key)
    assert set(actual) == set(e)


def path_model(row):
    points, trace, writes = row['points'], row['observation']['trace'], row['writes']
    def at(pc):
        return [p for p in points if p['pc'] == hex(pc)]
    def one(pc):
        rows = at(pc)
        assert len(rows) == 1, hex(pc)
        return rows[0]
    args = [PMAP, VA, DATA, 3, 0]
    assert [p['args'] for p in at(0x19065c)] == [args, [KP, KVA, PT, 3, 1]]
    assert one(0x190cfc)['args'] == [PMAP, VA]
    assert one(0x173d1c)['args'] == [KM, one(0x190cfc)['cpu']['esp'] - 8, VM]
    for pc, args in ((0x176164, [KM, KVA, KVA + VM]), (0x174848, [KM, KO, KVA, KVA, KVA + VM]),
        (0x173ebc, [KO, KVA, VM, 1]), (0x17b200, [KO, KVA, 1]),
        (0x175b2c, [KM, KVA, KVA + VM, 0]), (0x173898, [KM, KVA, KE]), (0x17b6e8, [PG])):
        assert one(pc)['args'] == args
    zone_ops = [(p['pc'], p['args']) for p in points if p['pc'] in ('0x16b790', '0x16b84c')]
    assert zone_ops == [('0x16b790', [EZ]), ('0x16b84c', [EZ, KE]), ('0x16b790', [EZ]), ('0x16b790', [XZ])]
    assert [(p['cpu']['ebx'], p['cpu']['eax']) for p in at(0x16b3c1)] == [(EZ, KE), (EZ, KE), (XZ, EXT)]
    # First KE pop belongs to vm_map_findspace; only reinsertion uses this return site.
    assert [p['cpu']['eax'] for p in at(0x174933)] == [KE]
    assert one(0x173f04)['cpu']['eax'] == PG and one(0x190d9b)['cpu']['eax'] == EXT
    assert one(0x190de5)['cpu']['eax'] == PT and one(0x190de5)['cpu']['ebx'] == EXT
    assert one(0x190d7b)['cpu']['eax'] == 0
    assert B.read_word(G.regions(one(0x190d7b)['state']), one(0x173d1c)['args'][1]) == KVA
    zero = one(0x173f92)['state']
    assert zero['new_pt_frame'] == bytes(VM).hex() and B.value(zero, 'kernel_page', 0x20, 'B') == 5
    wired = at(0x19065c)[-1]['state']
    assert B.value(wired, 'kernel_page', 0x1c, 'H') == 1 and wired['new_globals']['wire_count'] == 1
    assert B.value(wired, 'kernel_page', 0x20, 'B') == 5
    assert B.value(one(0x175b2c)['state'], 'kernel_page', 0x20, 'B') == 4
    checks = [p for p in at(0x190788) if p['cpu']['edi'] == PMAP]
    assert len(checks) == 2
    assert not B.read_word(G.regions(checks[0]['state']), checks[0]['cpu']['eax']) & 1
    assert B.read_word(G.regions(checks[1]['state']), checks[1]['cpu']['eax']) & 1
    assert checks[0]['trace_index'] < one(0x190cfc)['trace_index'] < one(0x1907b1)['trace_index'] < checks[1]['trace_index']
    chunks = row['zero_chunks']
    assert len(chunks) == VM // 32
    for i, p in enumerate(chunks):
        assert (p['eax'], p['ecx'], p['edx']) == (0, VM - i * 32, PT + i * 32)
        assert trace[p['trace_index']] == '0x1019cc'
    zeros = [(w['pc'], w['address'], w['width'], w['value']) for w in writes if w['pc'] in ZERO_PCS]
    assert zeros == [(pc, PT + i * 32 + j * 4, 4, 0) for i in range(VM // 32) for j, pc in enumerate(ZERO_PCS)]
    return len(zeros)


def write_protection(row):
    writes = row['writes']
    def overlapping(address, size):
        return [w for w in writes if w['address'] < address + size and address < w['address'] + w['width']]
    def exact(address, size, wanted):
        assert [(w['pc'], w['address'], w['width'], w['value']) for w in overlapping(address, size)] == wanted, ('protected writes', hex(address))
    for address, size in ((DATA, VM), (PAGE, 0x30), (F.OBJ, 0x58)):
        exact(address, size, [])
    for off in range(0, VM, HW):
        address = F.SHARED + ((KVA + off) >> 12 & 0x3ff) * 4
        exact(address, 4, [(0x190aa7, address, 4, (PT + off) | 0x203)])
    address = F.ROOTS[row['params'][0]]
    exact(address, (F.BASE >> 22) * 4,
          [(0x190ef4, address + i * 4, 4, (PT + i * HW) | 7) for i in range(VM // HW)])
    for physical, owner, va in ((PT, KP, KVA), (DATA, PMAP, VA)):
        d = F.desc(physical)
        expected = [(0x1909de, d + 8, 4, va), (0x1909e4, d + 4, 4, owner), (0x1909e7, d, 4, 0)]
        if physical == PT:
            expected.append((0x190e06, d + 0xc, 4, EXT))
        exact(d, 0x14, expected)
    expected_pt_writes = [(pc, PT + i * 32 + j * 4, 4, 0) for i in range(VM // 32) for j, pc in enumerate(ZERO_PCS)]
    expected_pt_writes += [(0x190aa7, PT + (((VA + off) & (0x800000 - 1)) >> 12) * 4, 4, (DATA + off) | 7) for off in range(0, VM, HW)]
    exact(PT, VM, expected_pt_writes)
    expected_ptes = [(F.SHARED + ((KVA + off) >> 12 & 0x3ff) * 4, 4, (PT + off) | 0x203) for off in range(0, VM, HW)]
    expected_ptes += [(PT + (((VA + off) & (0x800000 - 1)) >> 12) * 4, 4, (DATA + off) | 7) for off in range(0, VM, HW)]
    assert [(w['address'], w['width'], w['value']) for w in writes if w['pc'] == 0x190aa7] == expected_ptes


def resource_transitions(row):
    """Single uncontended path only: actual zone unlink/count and lock writes.

    Exact sensitive-region policies complement replay, which alone cannot prove
    an INC/XCHG's recorded value or detect coherently falsified middle snapshots.
    """
    def exact(address, size, expected):
        observed = [(w['pc'], w['address'], w['width'], w['value']) for w in row['writes']
                    if w['address'] < address + size and address < w['address'] + w['width']]
        assert observed == expected, ('resource transition', hex(address))
    def rw_cycle(address):
        return [(0x15b5e7, address + 8, 4, 1), (0x15b69a, address + 6, 1, 0xa),
                (0x15b72f, address + 8, 4, 0), (0x15b753, address + 8, 4, 1),
                (0x15b7a2, address + 6, 1, 8), (0x15b7c4, address + 8, 4, 0)]
    exact(KM, 0xc, rw_cycle(KM) * 3)
    sleepable = row['params'][-1]
    for zone, element, operations in ((EZ, KE, ('pop', 'free', 'pop')), (XZ, EXT, ('pop',))):
        expected = []
        for operation in operations:
            if operation == 'pop':
                effect = [(0x16b3c1, zone + 8, 4, 1), (0x16b3c6, zone + 0x10, 4, 0), (0x16b3ce, zone + 0xc, 4, 0)]
                acquire, saved, release = 0x16b3ab, 0x16b3b4, 0x16b779
            else:
                effect = [(0x16b8d2, zone + 0x10, 4, element), (0x16b8d4, zone + 0xc, 4, element), (0x16b8d7, zone + 8, 4, 0)]
                acquire, saved, release = 0x16b87f, 0x16b888, 0x16b8f1
            if sleepable:
                lock = rw_cycle(zone + 0x30)
                expected += lock[:3] + effect + lock[3:]
            else:
                expected += [(acquire, zone, 4, 1), (saved, zone + 4, 4, 7)] + effect + [(release, zone, 4, 0)]
        exact(zone, 0x40, expected)
    ko_sites = ((0x178c4b, 1), (0x178c5a, 0), (0x173eed, 1), (0x173f89, 0),
                (0x1738df, 1), (0x1739f4, 0), (0x173a23, 1), (0x173a53, 0),
                (0x178c9f, 1), (0x178cbc, 0))
    exact(KO + 0x10, 4, [(pc, KO + 0x10, 4, value) for pc, value in ko_sites])
    for address, acquire, release in ((0x1f64e8, 0x173936, 0x17394e), (0x1f7418, 0x17b21e, 0x17b2b7)):
        exact(address, 4, [(acquire, address, 4, 1), (release, address, 4, 0)])
    for p in row['points']:
        pc, s = int(p['pc'], 16), p['state']
        if pc in (0x17b200, 0x17b6e8):
            assert B.value(s, 'kernel_object', 0x10) == 1
            assert s['globals']['queue_lock'] == int(pc == 0x17b6e8)
            assert B.value(s, 'kernel_map', 4) == 0x80000
        if pc in (0x16b790, 0x16b84c, 0x16b3c1):
            zone = p['cpu']['ebx'] if pc == 0x16b3c1 else p['args'][0]
            field, element = ('entry_zone', KE) if zone == EZ else ('extension_zone', EXT)
            assert zone in (EZ, XZ)
            assert B.value(s, 'kernel_object', 0x10) == 0 and s['globals']['queue_lock'] == 0
            assert B.value(s, 'kernel_map', 4) == (0xa0000 if zone == EZ else 0x80000)
            assert [B.value(s, field, off) for off in (8, 0xc, 0x10)] == ([1, 0, 0] if pc == 0x16b84c else [0, element, element])
            if sleepable:
                assert B.value(s, field, 0x34) == (0xa0000 if pc == 0x16b3c1 else 0x80000)
                assert B.value(s, field, 0x38) == 0
            else:
                assert B.value(s, field, 0) == int(pc == 0x16b3c1)


def audit(row, refs):
    bridge(row, refs)
    trace, obs = row['observation']['trace'], row['observation']
    assert row['failure'] is None and obs['error'] is None and obs['interrupts'] == []
    assert trace == row['recorded_heads'] and trace[0] == '0x19065c'
    F.C.trace_check(trace, F.STOP)
    assert obs['after'] == row['after']['cpu']
    assert row['after']['cpu']['eip'] == F.STOP and row['after']['cpu']['esp'] == G.CALL_STACK + 4
    for key, value in G.R.CALLEE.items():
        assert row['after']['cpu'][key] == value
    for key in ('cs', 'ss', 'ds', 'es', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4'):
        assert row['after']['cpu'][key] == row['before']['cpu'][key]
    for pc in (0x10ca6c, 0x163320, 0x1631a0, 0x16b3df, 0x190e51, 0x172038, 0x17390e,
               0x18b59b, 0x18b5dc, 0x18b5ef, 0x18c12c, 0x18c174, 0x18c187):
        assert hex(pc) not in trace
    assert [p['trace_index'] for p in row['points']] == [i for i, pc in enumerate(trace) if int(pc, 16) in MILESTONES]
    target, _, destination, _, _ = row['params']
    for state in [row['before'], row['after']]:
        F.contract(state, {'target': target, 'destination': destination})
    for point in row['points']:
        pc, state = int(point['pc'], 16), point['state']
        assert point['pc'] == trace[point['trace_index']]
        assert point['cpu'] == state['cpu'] and point['cpu']['eip'] == pc
        F.contract(state, {'target': target, 'destination': destination})
        if pc in NARGS:
            args = [B.read_word(G.regions(state), point['cpu']['esp'] + 4 + i * 4) for i in range(NARGS[pc])]
            assert point['args'] == args
        for key in ('frame', 'page', 'object'):
            assert state[key] == row['before'][key], ('preserved DATA state', key, point['pc'])
    final_model(row)
    zeros = path_model(row)
    write_protection(row)
    resource_transitions(row)
    counts = R.cardinality(row)
    stack = R.stack_flow(row)
    replay(row)
    return {'params': row['params'], **counts, **stack, 'zero_dword_stores': zeros,
            'supplemental_direct_passed': True, 'actual_fault_reentry_verified': False}


def main():
    refs = references()
    rows = json.loads((HERE / 'direct-cases.json').read_text())
    expected = set(itertools.product(F.ROOTS, F.COPY, (0x100, 0x1100), (2, 0x602), (1, 0)))
    assert len(rows) == len(expected) and {tuple(r['params']) for r in rows} == expected
    results = [audit(row, refs) for row in rows]
    summary = {'cases': len(results), 'heads': sum(r['heads'] for r in results),
        'writes': sum(r['writes'] for r in results), 'zero_dword_stores': sum(r['zero_dword_stores'] for r in results)}
    out = {'summary': summary, 'rows': results, 'all_passed': True, 'whole_goal_complete': False,
        'actual_fault_reentry_verified': False,
        'limits': 'one backend, declared synthetic ownership; prefix equality relies on producer; not general GPR/flags/effective-address evaluation or native exception handling'}
    (HERE / 'direct-audit.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps(summary))


if __name__ == '__main__':
    main()
