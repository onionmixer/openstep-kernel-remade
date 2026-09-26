"""Independent evidence consumer: raw instructions, state, stores and stack.

Imports preserved auditors only, never the new or previous execution producers.
Not a general CPU/flags/effective-address simulator or native hardware proof.
"""
import copy
import functools
import json
import struct
import sys
import support as S

V = S.load('consumer35', S.HERE.parent / 'continuous-review-20260912-35/review.py')
G, F, A = V.G, V.F, V.A
R = G.R
NARGS = {0x191144: 0, 0x18b964: 0, 0x18f7f8: 4, 0x178894: 1, 0x190f90: 5, 0x18b544: 1}
MILESTONES = set(NARGS) | {0x191174, 0x191260, 0x1912af, 0x1912e3, 0x1912eb, 0x1912f0,
    0x1912f6, 0x19133b, 0x19133e, 0x19139b, 0x1913bc, 0x1913c3, 0x1913db,
    0x18f95a, 0x18f95e, 0x18f96a, 0x18f96e, 0x18f9bc, 0x191040, 0x19104d, 0x191082}


@functools.lru_cache(maxsize=1)
def prior_segments():
    rows = json.loads((S.HERE.parent / 'continuous-review-20260911-33/dirty-remove-cases.json').read_text())
    return {tuple(r['params']): r['pre_input']['physical_segments'] for r in rows}


def cmp_bits(a, b, width):
    mask, sign = (1 << width) - 1, 1 << (width - 1)
    a, b = a & mask, b & mask
    result = (a - b) & mask
    bits = {0: a < b, 2: (result & 0xff).bit_count() % 2 == 0,
            4: bool((a ^ b ^ result) & 0x10), 6: result == 0,
            7: bool(result & sign), 11: bool((a ^ b) & (a ^ result) & sign)}
    return sum(int(v) << k for k, v in bits.items()), sum(1 << k for k in bits)


def bridge(row, ref):
    keys = R.PREFIX_KEYS
    assert row['prefix32'] == {'keys': sorted(keys), 'canonical_sha256': S.canonical({k: ref[k] for k in keys}),
                              'omitted_uncollected_fields': ['points', 'zero_chunks']}
    expected = copy.deepcopy(ref['after'])
    # These unpopulated descriptor bytes retain bootstrap values; count is zero.
    # Anchor to preserved report33's same post-prefix/pre-input observation.
    expected['physical_segments'] = prior_segments()[tuple(row['params'])]
    expected['gc_regions'] = {hex(a): (A.original(a, n) if a in (0x1e25fc, 0x1dfd78) else bytes(n)).hex()
                              for a, n in G.GCSIZES.items()}
    assert row['pre_input'] == expected, 'prefix projection/pre-input'
    age = 6 if row['mode'] == 'equal' else 7
    root = F.ROOTS[row['params'][0]]
    changes = [[R.SEGMENTS, R.segment_model()], [0x1f653c, struct.pack('<I', 3).hex()],
               [0x1e773c, struct.pack('<I', 1).hex()],
               [0x1f7aa0, struct.pack('<4I', 0, 0, G.PD_HEAD, G.PD_HEAD).hex()],
               [F.EXT + 0x1d, bytes([age]).hex()]]
    if row['mode'] == 'accessed':
        changes.append([root, bytes([bytes.fromhex(expected['roots'][row['params'][0]])[0] | 0x20]).hex()])
    changes.append([R.CALL_STACK, struct.pack('<I', F.STOP).hex()])
    assert row['input'] == {'memory_changes': changes, 'last': 1, 'tick': 3, 'age': age, 'eflags': 2}
    expected['physical_segments'] = R.segment_model()
    for address, raw in changes:
        if hex(address) in expected['gc_regions']:
            expected['gc_regions'][hex(address)] = raw
    R.patch(expected, 'extension', 0x1d, age, 1)
    if row['mode'] == 'accessed':
        raw = bytearray.fromhex(expected['roots'][row['params'][0]])
        raw[0] |= 0x20
        expected['roots'][row['params'][0]] = raw.hex()
    R.patch(expected, 'stack_memory', R.CALL_STACK - F.STACK, F.STOP)
    expected['cpu'].update(R.CALLEE, esp=R.CALL_STACK, eflags=2)
    assert row['before'] == expected, 'unreported input edit'


def after_model(row):
    before, after, mode = row['before'], row['after'], row['mode']
    e = copy.deepcopy(before)
    e['gc_regions'][hex(0x1e773c)] = struct.pack('<I', 3).hex()
    R.patch(e, 'extension', 0x1d, {'remove': 9, 'equal': 8, 'accessed': 0}[mode], 1)
    target = row['params'][0]
    root = bytearray.fromhex(e['roots'][target])
    if mode == 'remove':
        R.patch(e, 'page', 0x1e, 2, 1)
        R.patch(e, 'pmap', 0x10, 0)
        R.patch(e, 'descriptor_arena', F.desc(F.DATA) - F.DESC + 4, 0)
        R.patch(e, 'descriptor_arena', F.desc(F.DATA) - F.DESC + 0x10, 3, 1)
        R.patch(e, 'extension', 0, R.FREE_PT)
        R.patch(e, 'extension', 4, R.FREE_PT)
        R.patch(e, 'extension', 0x18, 0, 2)
        e['globals']['pt_count'] = 0
        e['queues']['pt'] = [F.ACTIVE, F.ACTIVE]
        e['pt_free_queue'], e['pt_free_count'] = [F.EXT, F.EXT], 1
        e['tlb_counters'][0] += 1
        e['new_pt_frame'] = bytes(F.VM).hex()
        for off in range(0, F.VM // F.HW * 4, 4):
            root[off] &= ~1
    elif mode == 'accessed':
        root[0] &= ~0x20
    e['roots'][target] = root.hex()
    # Independently checked below: stack flow, CPU ABI, physical walk contracts,
    # and write replay with narrowly specified automatic paging A/D allowance.
    for key in ('cpu', 'stack_memory', 'raw_translation', 'new_walks', 'data_high_walks'):
        e[key] = after[key]
    observed = bytes.fromhex(after['roots'][target])
    for off in range((F.BASE >> 22) * 4, len(root), 4):
        old, new = struct.unpack_from('<I', root, off)[0], struct.unpack_from('<I', observed, off)[0]
        assert new == old or (old & 1 and new == old | 0x20), 'unexpected high PDE change'
        struct.pack_into('<I', root, off, new)
    e['roots'][target] = root.hex()
    assert after == e, 'final semantic ownership model'
    for k, value in R.CALLEE.items():
        assert after['cpu'][k] == value
    assert after['cpu']['esp'] == R.CALL_STACK + 4 and after['cpu']['eip'] == F.STOP
    for k in ('cs', 'ds', 'es', 'ss', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4'):
        assert after['cpu'][k] == before['cpu'][k]
    if mode == 'remove':
        assert after['cpu']['eax'] == 7 and after['cpu']['eflags'] & 0x600 == 0x200


def check(row, reference):
    assert (tuple(row['params']), row['mode']) in S.matrix(False)
    assert row['failure'] is None and row['native_cpu_verified'] is False and row['whole_ownership_verified'] is False
    bridge(row, reference)
    obs, before = row['observation'], row['before']
    trace = obs['trace']
    assert not obs['interrupts'] and obs['error'] is None
    assert obs['after'] == row['after']['cpu']
    assert trace == row['recorded_heads'] and trace[0] == '0x191144' and trace[-1] == '0x1913ea'
    R.C.trace_check(trace, F.STOP)
    forbidden = {0x10ca6c, 0x163320, 0x1631a0, 0x16b790, 0x16b84c, 0x173e90,
                 0x17b540, 0x17b6e8, 0x18b59b, 0x18b5dc, 0x18b5ef, 0x191205,
                 0x191351, 0x191358, 0x191366, 0x18fa44}
    assert not any(int(pc, 16) in forbidden for pc in trace)
    assert [p['trace_index'] for p in row['points']] == [i for i, pc in enumerate(trace) if int(pc, 16) in MILESTONES]
    for state in [before] + [p['state'] for p in row['points']] + [row['after']]:
        F.contract(state, reference)
        assert state['physical_segments'] == R.segment_model()
    for point in row['points']:
        assert trace[point['trace_index']] == point['pc'], 'checkpoint trace identity'
        assert point['cpu'] == point['state']['cpu'] and point['cpu']['eip'] == int(point['pc'], 16)
        if int(point['pc'], 16) in NARGS:
            assert point['args'] == [G.B.read_word(G.regions(point['state']), point['cpu']['esp'] + 4 + 4 * i)
                                     for i in range(NARGS[int(point['pc'], 16)])]
    def points(pc):
        return [p for p in row['points'] if p['pc'] == hex(pc)]
    def one(pc):
        found = points(pc)
        assert len(found) == 1, hex(pc)
        return found[0]
    root = F.ROOTS[row['params'][0]]
    assert one(0x191174)['cpu']['ebx'] == 2
    assert one(0x1912af)['cpu']['edx'] == root and one(0x1912af)['cpu']['ecx'] == F.EXT
    assert one(0x1913db)['cpu']['ebx'] == 2
    old_age = row['input']['age']
    new_age = (old_age + 2) & 0xff
    for pc in (0x1912e3, 0x1912eb):
        if points(pc):
            cpu = one(pc)['cpu']
            assert cpu['ecx'] == F.EXT and cpu['eax'] & 0xff == new_age and cpu['edx'] & 0xff == old_age, 'aging operands/EA'
    for pc in (0x1912eb, 0x1912f0):
        if points(pc):
            assert one(pc)['cpu']['esi'] == new_age, 'aging comparison ESI'
    for pc, a, b, width in ((0x191174, 2, 1, 32), (0x1912eb, old_age, new_age, 8), (0x1912f0, 8, new_age, 32)):
        if points(pc):
            flags, mask = cmp_bits(a, b, width)
            assert one(pc)['cpu']['eflags'] & mask == flags, ('aging comparison flags', hex(pc))
    if points(0x1912f0):
        p = one(0x1912f0)
        assert G.B.read_word(G.regions(p['state']), p['cpu']['ebp'] - 0xc) == 8
    if points(0x1913bc):
        assert one(0x1913bc)['cpu']['edx'] == root and one(0x1913bc)['cpu']['ecx'] == F.EXT
    remove = row['mode'] == 'remove'
    assert len(points(0x1912f6)) == int(remove)
    assert len(points(0x1913bc)) == int(row['mode'] == 'accessed')
    if remove:
        assert one(0x18f7f8)['args'] == [F.PMAP, 0, 0x800000, 1]
        assert one(0x190f90)['args'] == [F.PMAP, 0, 1, 0, 1]
        assert one(0x178894)['args'] == [F.DATA]
        assert one(0x18b544)['args'] == [7]
        for pc in (0x19133b, 0x19133e):
            assert one(pc)['cpu']['cr3'] == root
        assert one(0x19133e)['cpu']['eax'] == root
        assert one(0x1913c3)['state']['pt_free_queue'] == [F.EXT, F.EXT]
        bp = one(0x1913c3)['cpu']['ebp']
        assert G.B.read_word(G.regions(one(0x1913c3)['state']), bp - 4) == F.ACTIVE
        assert trace[one(0x1913c3)['trace_index'] + 1:one(0x1913c3)['trace_index'] + 5] == [
            '0x1913c6', '0x191293', '0x191299', '0x1913d8']
    else:
        assert not any(points(pc) for pc in (0x18f7f8, 0x190f90, 0x178894, 0x19133b, 0x19133e))
    indices = [i for i, pc in enumerate(trace) if pc == '0x18f8b4']
    assert [s['trace_index'] for s in row['scans']] == indices
    expected_count = 0x800000 // F.VM if remove else 0
    assert len(row['scans']) == expected_count
    # Compact scan observations must agree with the actual intervening stack
    # writes, including values later overwritten before a full snapshot.
    if remove:
        local_address = one(0x18f7f8)['cpu']['esp'] - 4 - 0xc
        advances = [w for w in row['writes'] if w['pc'] == 0x18fa13]
        assert [(w['address'], w['width'], w['value']) for w in advances] == [
            (local_address, 4, (i + 1) * F.VM) for i in range(expected_count)], 'scan local-VA store progression'
        for i, write in enumerate(advances):
            end = indices[i + 1] if i + 1 < len(indices) else one(0x190f90)['trace_index']
            assert indices[i] < write['trace_index'] < end
        between = [w for w in row['writes'] if one(0x18f7f8)['trace_index'] < w['trace_index'] < one(0x19139b)['trace_index']
                   and w['address'] < local_address + 4 and local_address < w['address'] + w['width']]
        assert [(w['pc'], w['address'], w['width'], w['value']) for w in between] == [
            (0x18f807, local_address, 4, 0)] + [(0x18fa13, local_address, 4, (i + 1) * F.VM) for i in range(expected_count)]
    pt = bytes.fromhex(before['new_pt_frame'])
    for i, scan in enumerate(row['scans']):
        cpu, index = scan['cpu'], scan['trace_index']
        assert cpu['eip'] == 0x18f8b4 and cpu['edi'] == F.PT + i * 8
        assert scan['local_va'] == i * F.VM
        assert cpu['esp'] == one(0x18f7f8)['cpu']['esp'] - 0x28
        assert cpu['ebp'] == one(0x18f7f8)['cpu']['esp'] - 4
        assert scan['ptes'] == pt[i * 8:i * 8 + 8].hex()
        assert trace[index + 1] == '0x18f8b7'
        assert trace[index + 2] == ('0x18f8d0' if pt[i * 8] & 1 else '0x18f8b9')
    def stores(pc):
        return [(w['address'], w['width'], w['value']) for w in row['writes'] if w['pc'] == pc]
    expect = {0x1913db: [(0x1e773c, 4, 3)],
        0x1912e3: [] if row['mode'] == 'accessed' else [(F.EXT + 0x1d, 1, row['input']['age'] + 2)],
        0x1913bf: [(F.EXT + 0x1d, 1, 0)] if row['mode'] == 'accessed' else [],
        0x1913bc: [(root, 1, bytes.fromhex(before['roots'][row['params'][0]])[0] & ~0x20)] if row['mode'] == 'accessed' else [],
        0x191329: [(0x1f7af0, 4, 2)] if remove else [],
        0x18f95a: [(F.PAGE + 0x1e, 1, 2)] if remove else [],
        0x18f95e: [(F.desc(F.DATA) + 0x10, 1, 1)] if remove else [],
        0x18f96a: [(F.desc(F.DATA) + 0x10, 1, 3)] if remove else [],
        0x18f9bc: [(F.desc(F.DATA) + 4, 4, 0)] if remove else []}
    ptes = [F.PT + ((F.VA + off) >> 12) * 4 for off in range(0, F.VM, F.HW)]
    expect[0x18f96e] = [(a, 4, 0) for a in ptes] if remove else []
    expect[0x191040] = [(root + i * 4, 1, bytes.fromhex(before['roots'][row['params'][0]])[i * 4] & ~1)
                        for i in range(F.VM // F.HW)] if remove else []
    for pc, expected in expect.items():
        assert stores(pc) == expected, ('critical store', hex(pc))
    if remove:
        dirty = row['params'][2] // F.HW
        assert one(0x18f95a)['cpu']['edi'] == ptes[dirty]
        assert [p['cpu']['edi'] for p in points(0x18f96e)] == ptes
        assert one(0x18f95a)['cpu']['eax'] == F.PAGE
        assert [p['cpu']['esi'] for p in points(0x191040)] == [root + i * 4 for i in range(F.VM // F.HW)], 'PDE clear effective address'
        for pc in (0x18f95e, 0x18f96a):
            assert one(pc)['cpu']['ebx'] == F.desc(F.DATA)
        assert one(0x18f9bc)['cpu']['esi'] == F.desc(F.DATA)
        assert one(0x19104d)['cpu']['ebx'] == F.EXT
    cardinality = V.cardinality(row)
    stack = V.stack_flow(row)
    G.replay(row)
    after_model(row)
    return {'params': row['params'], 'mode': row['mode'], 'passed': True,
            'cardinality': cardinality, 'stack': stack, 'scanned_bundles': len(row['scans']), 'removed': remove}


def main():
    refs = S.references()
    smoke = '--smoke' in sys.argv
    stem = 'smoke' if smoke else 'removal'
    rows = json.loads((S.HERE / (stem + '-cases.json')).read_text())
    assert [(tuple(r['params']), r['mode']) for r in rows] == S.matrix(smoke)
    out = [check(r, refs[tuple(r['params'])]) for r in rows]
    S.save(stem + '-audit.json', {'all_passed': True, 'cases': out, 'whole_goal_complete': False,
        'scope': 'recorded original path; scoped state/store/stack model; not full CPU or native proof'})
    print(json.dumps({'independently_audited': len(out), 'removed': sum(r['removed'] for r in out)}))


if __name__ == '__main__':
    main()
