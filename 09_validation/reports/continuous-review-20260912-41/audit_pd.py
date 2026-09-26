"""Read-only PD lifecycle evidence audit; no producer/emulator imports.

State replay, bounded original stack/store checks and explicit PD semantics;
not a second CPU implementation or proof of complete boot ownership.
"""
import collections
import copy
import json
import struct
import sys
import support as S

V = S.load('pd_consumer35', S.HERE.parent / 'continuous-review-20260912-35/review.py')
B, A = V.G.R.F.B, V.A  # Preserved report31 auditor and raw-Mach-O decoder.
X = A.capstone.x86
CALL_STACK = 0x70ff00
CALLEE = {'ebx': 0x12341111, 'esi': 0x23452222, 'edi': 0x34563333, 'ebp': 0x45674444}
NARGS = {0x15b54c: 2, 0x18f644: 1, 0x18f58c: 1, 0x18f40c: 1, 0x18f69c: 1,
         0x191144: 0, 0x173d1c: 3, 0x16b790: 1, 0x16b84c: 2, 0x173e90: 3,
         0x178894: 1, 0x18fb0c: 1, 0x17b540: 1, 0x190f90: 5}
MILESTONES = set(NARGS) | {0x18f429, 0x18f442, 0x18f461, 0x18f476, 0x18f484,
    0x18f4b4, 0x18f511, 0x18f54e, 0x18f57d, 0x18f60d, 0x18f684,
    0x18f756, 0x18f764, 0x18f786, 0x18f797, 0x1911fe, 0x191205,
    0x191220, 0x191234, 0x19124b, 0x19125c, 0x1913db,
    0x173f04, 0x173f92, 0x18fcbe, 0x18fcc5, 0x18fcd4, 0x18fcd8, 0x17b5ee}


def regions(state):
    out = B.regions(state)
    assert set(state['pd_regions']) == {hex(a) for a in S.EXTRA}
    for a, n in S.EXTRA.items():
        raw = bytes.fromhex(state['pd_regions'][hex(a)])
        assert len(raw) == n
        assert a not in out
        out[a] = raw
    return out


def word(state, a):
    return B.read_word(regions(state), a)


def value(state, field, offset, width=4):
    return int.from_bytes(bytes.fromhex(state[field])[offset:offset + width], 'little')


def patch(state, field, offset, number, width=4):
    raw = bytearray.fromhex(state[field])
    raw[offset:offset + width] = number.to_bytes(width, 'little')
    state[field] = raw.hex()


def memory_patch(state, address, raw):
    # Explicit preparation writes address existing physical snapshot fields only.
    if hex(address) in state['pd_regions']:
        assert len(raw) == S.EXTRA[address]
        state['pd_regions'][hex(address)] = raw.hex()
    elif address == CALL_STACK:
        data = bytearray.fromhex(state['stack_memory'])
        data[address - B.STACK:address - B.STACK + len(raw)] = raw
        state['stack_memory'] = data.hex()
    else:
        raise AssertionError(('unexpected preparation address', hex(address)))


def seed_check(row, reference):
    assert row['prefix31'] == {'setup_sha256': S.canonical(reference['setup']),
        'before_sha256': S.canonical(reference['before']),
        'scope': 'fresh setup and pre-allocation boundary exact equality'}
    assert {k: v for k, v in row['pre_input'].items() if k != 'pd_regions'} == reference['before']
    old = row['pre_input']['pd_regions']
    for a, n in S.EXTRA.items():
        expected = A.original(a, n) if a in (0x1e25fc, 0x1dfd78) else bytes(n)
        if a == 0x1f6e60:
            raw = bytearray(n)
            struct.pack_into('<2I', raw, 0x14, 0x414000, 0xc00000)
            expected = bytes(raw)
        assert old[hex(a)] == expected.hex(), ('pre-seed bytes', hex(a))
    zone = bytearray(0x40)
    struct.pack_into('<9I', zone, 0xc, S.PMAPS[1], S.PMAPS[0], 2 * 0x1c, 2 * 0x1c, 0x1c, B.VM, 0, 0, row['params'][1])
    segments = bytearray(0x3c)
    for i, (page, phys) in enumerate(((B.PAGE, B.DATA), (B.PG, B.PT))):
        struct.pack_into('<7I', segments, i * 0x1c, page, phys >> 13, 0, 0, 0, phys, phys + B.VM)
    struct.pack_into('<I', segments, 0x38, 2)
    expected_changes = [[S.ZONE, zone.hex()], [S.PMAPS[0], struct.pack('<7I', S.PMAPS[1], 0, 0, 0, 0, 0, 0).hex()],
        [S.PMAPS[1], bytes(0x1c).hex()], [0x1f7abc, struct.pack('<I', S.ZONE).hex()],
        [0x1f7aa0, struct.pack('<4I', 0, 0, S.PD_HEAD, S.PD_HEAD).hex()],
        [0x1e773c, struct.pack('<I', 1).hex()], [0x1f653c, struct.pack('<I', 1).hex()], [0x1f6e60, segments.hex()]]
    assert row['input'] == expected_changes
    expected = copy.deepcopy(row['pre_input'])
    for a, raw in expected_changes:
        memory_patch(expected, a, bytes.fromhex(raw))
    assert row['seeded'] == expected


def flow_and_cardinality(stage):
    pcs = [int(p, 16) for p in stage['recorded_heads']]
    by = collections.defaultdict(list)
    for w in stage['writes']:
        assert 0 <= w['trace_index'] < len(pcs) and w['pc'] == pcs[w['trace_index']]
        assert w['width'] in (1, 2, 4) and 0 <= w['value'] < (1 << (w['width'] * 8))
        by[w['trace_index']].append(w)
    returns = []
    for i, (pc, nxt) in enumerate(zip(pcs, pcs[1:] + [B.STOP])):
        ins = A.instruction(pc)
        if ins.mnemonic == 'call':
            assert ins.operands[0].type == X.X86_OP_IMM and nxt == ins.operands[0].imm
            returns.append(pc + ins.size)
        elif ins.mnemonic == 'ret':
            assert nxt == (returns.pop() if returns else B.STOP)
        elif ins.group(A.capstone.CS_GRP_JUMP):
            if ins.operands[0].type == X.X86_OP_IMM:
                allowed = {ins.operands[0].imm}
                if ins.mnemonic != 'jmp':
                    allowed.add(pc + ins.size)
                assert nxt in allowed
            else:
                assert pc == 0x101669 and (stage['label'].startswith('create_slot') or stage['label'] == 'pmap_zone_lock_init')
                # Original 15b553 pushes 0xc; original 18f676 pushes 0x1c.
                length = 0xc if stage['label'] == 'pmap_zone_lock_init' else 0x1c
                assert nxt == struct.unpack('<I', A.original(0x101670 + (length - 1) * 4, 4))[0]
        elif ins.mnemonic == 'rep movsd':
            assert pc == 0x17b384 and nxt in (pc, pc + ins.size)
        else:
            assert nxt == pc + ins.size
        if ins.mnemonic in ('bsf', 'rol', 'movzx', 'setne'):
            assert ins.operands[0].type == X.X86_OP_REG
            widths = []
        elif ins.mnemonic == 'cld':
            widths = []
        elif ins.mnemonic == 'rep movsd':
            widths = [4] if nxt == pc else []
        else:
            width = V.G.memory_write_width(ins)
            widths = [width] if width else []
        assert [w['width'] for w in by[i]] == widths, ('store cardinality', hex(pc))
    assert not returns
    V.stack_flow(stage)


def replay(stage, target):
    memories = {a: bytearray(raw) for a, raw in regions(stage['before']).items()}
    writes = stage['writes']
    assert [w['trace_index'] for w in writes] == sorted(w['trace_index'] for w in writes)
    cursor = 0
    for p in stage['points'] + [{'write_cursor': len(writes), 'trace_index': len(stage['recorded_heads']), 'state': stage['after']}]:
        end = p['write_cursor']
        assert end == sum(w['trace_index'] < p['trace_index'] for w in writes) and cursor <= end
        for w in writes[cursor:end]:
            matches = [(a, raw) for a, raw in memories.items() if a <= w['address'] and w['address'] + w['width'] <= a + len(raw)]
            assert matches, ('uncaptured physical write', w)
            for a, raw in matches:
                offset = w['address'] - a
                raw[offset:offset + w['width']] = w['value'].to_bytes(w['width'], 'little')
        observed = regions(p['state'])
        assert set(memories) == set(observed)
        for a, oldraw in memories.items():
            newraw = observed[a]
            if a in (B.SHARED, B.ROOTS[target]):
                for off in range(0, len(newraw), 4):
                    old, new = struct.unpack_from('<I', oldraw, off)[0], struct.unpack_from('<I', newraw, off)[0]
                    allow = (0x60 if a == B.SHARED else 0x20 if off >= (B.BASE >> 22) * 4 else 0) if old & 1 else 0
                    assert new | old == new and (new ^ old) & ~allow == 0, ('paging-only A/D', hex(a + off))
            else:
                assert newraw == oldraw, ('physical write replay', hex(a), p.get('pc'))
            memories[a] = bytearray(newraw)
        cursor = end


def check_stage(stage, previous, target):
    assert stage['pre_input'] == previous, 'continuous original state'
    expected = copy.deepcopy(previous)
    changes = [[CALL_STACK, struct.pack('<' + 'I' * (len(stage['args']) + 1), B.STOP, *stage['args']).hex()]]
    if stage['tick'] is not None:
        changes.append([0x1f653c, struct.pack('<I', stage['tick']).hex()])
    assert stage['input'] == {'memory_changes': changes, 'eflags': 2}
    for a, raw in changes:
        memory_patch(expected, a, bytes.fromhex(raw))
    expected['cpu'].update(CALLEE, esp=CALL_STACK, eflags=2)
    assert stage['before'] == expected, 'unreported inter-call mutation'
    assert stage['failure'] is None
    obs = stage['observation']
    assert obs['error'] is None and not obs['interrupts'] and obs['after'] == stage['after']['cpu']
    trace = stage['recorded_heads']
    assert trace == obs['trace'] and trace[0] == hex(stage['entry'])
    assert [p['trace_index'] for p in stage['points']] == [i for i, pc in enumerate(trace) if int(pc, 16) in MILESTONES]
    for p in stage['points']:
        assert trace[p['trace_index']] == p['pc'] and p['cpu'] == p['state']['cpu'] and p['cpu']['eip'] == int(p['pc'], 16)
        if int(p['pc'], 16) in NARGS:
            assert p['args'] == [word(p['state'], p['cpu']['esp'] + 4 + i * 4) for i in range(NARGS[int(p['pc'], 16)])]
    for state in [stage['before']] + [p['state'] for p in stage['points']] + [stage['after']]:
        B.state_contract(state, target)
        for key in ('object', 'page', 'pmap', 'map', 'entry', 'frame', 'pt_pair', 'copy_buffer_hashes', 'recover', 'uthread'):
            assert state[key] == previous[key], ('protected original state', key)
        assert state['pt_alloc_count'] == state['pt_free_count'] == state['globals']['pt_count'] == 0
    flow_and_cardinality(stage)
    replay(stage, target)
    after = stage['after']['cpu']
    assert after['eip'] == B.STOP and after['esp'] == CALL_STACK + 4
    for k, v in CALLEE.items():
        assert after[k] == v
    for k in ('cs', 'ss', 'ds', 'es', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4'):
        assert after[k] == previous['cpu'][k]


def semantics(row, reference):
    e = copy.deepcopy(row['seeded'])
    target, lock_mode, first_destroy = row['params']
    live, allocated, reclaimed = set(), False, False
    created = set()
    hint, free = S.PMAPS[1], list(S.PMAPS)
    pmap_bytes = {p: bytearray.fromhex(e['pd_regions'][hex(p)]) for p in S.PMAPS}
    pd_bytes = None
    for stage in row['stages']:
        label, after = stage['label'], stage['after']
        def points(pc):
            return [p for p in stage['points'] if p['pc'] == hex(pc)]
        def one(pc):
            found = points(pc)
            assert len(found) == 1, (label, hex(pc))
            return found[0]
        def stores(pc):
            return [(w['address'], w['width'], w['value']) for w in stage['writes'] if w['pc'] == pc]
        if label == 'pmap_zone_lock_init':
            raw = bytearray.fromhex(e['pd_regions'][hex(S.ZONE)])
            struct.pack_into('<3I', raw, 0x30, 0xffffffff, 0x80000, 0)
            e['pd_regions'][hex(S.ZONE)] = raw.hex()
        if label.startswith('create_slot'):
            slot = int(label[-1])
            pmap = S.PMAPS[slot]
            assert after['cpu']['eax'] == pmap
            assert one(0x18f40c)['args'] == [pmap]
            assert [p['args'] for p in points(0x173d1c)] == ([[B.KM, pmap, B.VM]] if slot == 0 else [])
            assert [p['args'] for p in points(0x16b790)] == [[S.ZONE]] + ([[B.EZ], [B.EZ], [B.XZ]] if slot == 0 else [])
            assert [p['args'] for p in points(0x16b84c)] == ([[B.EZ, B.KE]] if slot == 0 else [])
            assert pmap == free.pop(0)
            if hint == pmap:
                hint = 0
            live.add(slot)
            created.add(slot)
            pmap_bytes[pmap] = bytearray(struct.pack('<7I', B.KVA + slot * B.HW, B.PT + slot * B.HW, 1, 0, 0, 0, 0))
            if slot == 0:
                allocated = True
                pd_bytes = bytearray(B.VM)
                assert one(0x18f511)['cpu']['eax'] == B.PT
                assert stores(0x18f4b4) == [(0x1f7aa0, 4, 1)]
                assert stores(0x18f54e) == [(B.EXT + 0x18, 2, 1)]
                assert stores(0x18f57d) == [(B.EXT + 0x1c, 1, 1)]
            else:
                assert one(0x18f442)['cpu']['eax'] == 2 and one(0x18f442)['cpu']['edi'] == B.EXT
                assert one(0x18f461)['cpu']['eax'] == (~1 & 0xffffffff)
                for k, v in {'edi': B.EXT, 'ebx': 1, 'ecx': 1, 'eax': 2}.items():
                    assert one(0x18f476)['cpu'][k] == v
                assert one(0x18f476)['cpu']['edx'] & 0xff == 3
                assert stores(0x18f431) == [(B.EXT + 0x18, 2, 2)]
                assert stores(0x18f453) == [(0x1f7aa4, 4, 0)]
                assert stores(0x18f476) == [(B.EXT + 0x1c, 1, 3)]
                assert stores(0x18f484) == [(pmap, 4, B.KVA + B.HW)]
            source = bytes.fromhex(stage['before']['raw_translation'][hex(B.KR)])[:0x400]
            copies = stage['copies']
            trace = stage['recorded_heads']
            assert [c['trace_index'] for c in copies] == [i for i, pc in enumerate(trace) if pc == '0x18f62e']
            assert len(copies) == 0x400 // 4
            copy_writes = [w for w in stage['writes'] if w['pc'] == 0x18f62e]
            assert len(copy_writes) == len(copies)
            for i, (c, w) in enumerate(zip(copies, copy_writes)):
                off = i * 4
                expected_value = struct.unpack_from('<I', source, off)[0]
                cpu = c['cpu']
                expected_cpu = {'eip': 0x18f62e, 'eax': B.KR + off, 'ecx': B.KR + 0x400,
                    'edx': B.KVA + slot * B.HW + 0xc00 + off, 'esi': expected_value, 'ebx': pmap,
                    'esp': one(0x18f58c)['cpu']['esp'] - 12, 'ebp': one(0x18f58c)['cpu']['esp'] - 4,
                    'cr3': B.ROOTS[target]}
                assert all(cpu[k] == v for k, v in expected_cpu.items()), ('copy CPU/source/destination', i)
                assert c['source_value'] == expected_value
                physical = B.PT + slot * B.HW + 0xc00 + off
                assert (w['trace_index'], w['address'], w['width'], w['value']) == (c['trace_index'], physical, 4, expected_value)
                walk = c['destination_walk']
                assert walk['linear'] == hex(B.BASE + cpu['edx']) and walk['physical'] == hex(physical)
                assert walk['present'] and walk['writable'] and not walk['user']
                assert walk['pde_address'] == hex(B.ROOTS[target] + ((B.BASE + cpu['edx']) >> 22) * 4)
                assert walk['pde'] == hex(B.SHARED | 0x23)
                assert walk['pte_address'] == hex(B.SHARED + ((cpu['edx'] >> 12) & 0x3ff) * 4)
                assert walk['pte'] == hex((B.PT + slot * B.HW) | (0x203 if i == 0 else 0x263))
            pd_bytes[slot * B.HW + 0xc00:(slot + 1) * B.HW] = source
        else:
            assert not stage['copies']
        if label.startswith('destroy_'):
            slot = first_destroy if label == 'destroy_first' else 1 - first_destroy
            pmap = S.PMAPS[slot]
            old_count = len(live)
            live.remove(slot)
            free.append(pmap)
            free.sort()
            hint = pmap
            struct.pack_into('<I', pmap_bytes[pmap], 8, 0)
            for i, address in enumerate(free):
                struct.pack_into('<I', pmap_bytes[address], 0, free[i + 1] if i + 1 < len(free) else 0)
            assert [p['args'] for p in points(0x16b84c)] == [[S.ZONE, pmap]]
            assert one(0x18f764)['cpu']['eax'] == old_count
            for k, v in {'edx': B.EXT, 'ebx': B.desc(B.PT), 'esi': pmap, 'ecx': slot}.items():
                assert one(0x18f797)['cpu'][k] == v
            assert one(0x18f797)['cpu']['eax'] & 0xff == (0xff & ~(1 << slot))
            assert stores(0x18f75a) == [(B.EXT + 0x18, 2, len(live))]
            assert stores(0x18f797) == [(B.EXT + 0x1c, 1, sum(1 << i for i in live))]
            assert stores(0x18f780) == ([(0x1f7aa4, 4, 1)] if old_count == 2 else [])
        if label.startswith('gc_'):
            tick = stage['tick']
            assert word(stage['before'], 0x1e773c) == tick - 2
            e['pd_regions']['0x1e773c'] = e['pd_regions']['0x1f653c'] = struct.pack('<I', tick).hex()
            assert one(0x1911fe)['cpu']['ecx'] == B.EXT
            branch = stage['recorded_heads'][one(0x1911fe)['trace_index'] + 2]
            assert branch == ('0x191205' if label == 'gc_empty' else '0x19125c')
            assert stores(0x1913db) == [(0x1e773c, 4, tick)]
            assert one(0x1913db)['cpu']['ebx'] == 2
            if label != 'gc_empty':
                assert live and not points(0x16b84c) and not points(0x173e90) and not points(0x178894)
            else:
                reclaimed = True
                assert not live
                assert [p['args'] for p in points(0x16b84c)] == [[B.XZ, B.EXT], [B.EZ, B.KE]]
                assert one(0x173e90)['args'] == [B.KM, B.KVA, B.VM]
                assert [p['args'] for p in points(0x178894)] == [[B.PT]] * 3
                assert stores(0x191214) == [(0x1f7aa4, 4, 0)]
                assert stores(0x191220) == [(B.desc(B.PT) + 0xc, 4, 0)]
                assert stores(0x19124b) == [(0x1f7aa0, 4, 0)]
                assert one(0x191220)['trace_index'] < points(0x16b84c)[0]['trace_index'] < one(0x173e90)['trace_index'] < one(0x19124b)['trace_index']
                dirty = points(0x18fcbe)
                assert [value(p['state'], 'kernel_page', 0x1e, 1) for p in dirty] == [0x22, 0x02]
                assert all(p['cpu']['eax'] == B.PG for p in dirty)
                assert stores(0x18fcbe) == [(B.PG + 0x1e, 1, 2)] * 2
                assert stores(0x18fcc5) == [(B.desc(B.PT) + 0x10, 1, n) for n in (1, 3)]
                assert stores(0x18fcd4) == [(B.desc(B.PT) + 0x10, 1, 3)] * 2
                assert one(0x17b540)['args'] == [B.PG]
                assert value(one(0x17b540)['state'], 'kernel_page', 0x1e, 1) == 2
                assert word(one(0x19124b)['state'], 0x1f7aa0) == 1
                assert value(one(0x19124b)['state'], 'kernel_page', 0x1e, 1) == 8
                ptes = [B.SHARED + ((B.KVA + i * B.HW) >> 12 & 0x3ff) * 4 for i in range(B.VM // B.HW)]
                assert stores(0x18fcd8) == [(a, 4, 0) for a in ptes], 'PD backing PTE zero stores'
                assert [p['cpu']['esi'] for p in points(0x18fcd8)] == ptes, 'PD backing PTE clear EA'
                for a in ptes:
                    old = word(stage['before'], a)
                    overlapping = [w for w in stage['writes'] if w['address'] < a + 4 and a < w['address'] + w['width']]
                    assert [(w['pc'], w['address'], w['width'], w['value']) for w in overlapping] == [
                        (0x190c03, a + 1, 1, (old >> 8 & 0xff) & 0xfd), (0x18fcd8, a, 4, 0)], 'backing PTE inverse write policy'
                for offset, pc in ((4, 0x18fc9f), (0xc, 0x191220)):
                    a = B.desc(B.PT) + offset
                    overlapping = [w for w in stage['writes'] if w['address'] < a + 4 and a < w['address'] + w['width']]
                    assert [(w['pc'], w['address'], w['width'], w['value']) for w in overlapping] == [(pc, a, 4, 0)]
                assert one(0x191220)['cpu']['eax'] == B.desc(B.PT)
                assert one(0x191220)['cpu']['ecx'] == B.EXT and one(0x191220)['cpu']['esi'] == B.KVA
                assert all(p['cpu']['edi'] == B.desc(B.PT) for p in points(0x18fcc5))
                assert all(p['cpu']['ecx'] == B.desc(B.PT) for p in points(0x18fcd4))
        # Independent whole endpoint model for PD/zone ownership and common backing.
        zone = bytearray.fromhex(e['pd_regions'][hex(S.ZONE)])
        struct.pack_into('<3I', zone, 8, len(live), hint, free[0] if free else 0)
        if allocated and not lock_mode:
            struct.pack_into('<I', zone, 4, 7)
        e['pd_regions'][hex(S.ZONE)] = zone.hex()
        for pmap, raw in pmap_bytes.items():
            e['pd_regions'][hex(pmap)] = raw.hex()
        on_queue = allocated and not reclaimed and len(live) < 2
        end = B.EXT if on_queue else S.PD_HEAD
        e['pd_regions']['0x1f7aa0'] = struct.pack('<4I', int(allocated and not reclaimed), int(on_queue), end, end).hex()
        if allocated:
            for i in range(B.VM // B.HW):
                a = B.SHARED + ((B.KVA + i * B.HW) >> 12 & 0x3ff) * 4
                expected_pte = 0 if reclaimed else (B.PT + i * B.HW) | (0x263 if i in created else 0x203)
                assert word(after, a) == expected_pte, 'backing mapping lifetime'
                for name in ('kernel_low', 'kernel_high'):
                    walk = after['new_walks'][name][i]
                    assert walk['present'] is (not reclaimed)
                    if not reclaimed:
                        assert walk['physical'] == hex(B.PT + i * B.HW) and walk['writable'] and not walk['user']
            ext = bytearray(0x20)
            struct.pack_into('<6I', ext, 0, 0 if reclaimed else S.PD_HEAD, S.PD_HEAD, B.desc(B.PT), B.PT, 0, 0)
            struct.pack_into('<H', ext, 0x18, len(live))
            ext[0x1c] = sum(1 << i for i in live)
            e['extension'] = ext.hex()
            e['new_pt_frame'] = bytes(pd_bytes).hex()
            arena = bytearray.fromhex(row['seeded']['descriptor_arena'])
            struct.pack_into('<5I', arena, B.desc(B.PT) - B.DESC, 0, 0 if reclaimed else B.KP, B.KVA, 0 if reclaimed else B.EXT, 3 if reclaimed else 0)
            e['descriptor_arena'] = arena.hex()
            for key in ('kernel_map', 'kernel_entry', 'kernel_object', 'kernel_page', 'kernel_pmap', 'entry_zone', 'extension_zone', 'buckets'):
                e[key] = reference['after'][key]  # Pinned independently audited common wired-allocation path.
            e['globals']['fault_count'] = 1
            e['globals']['free_count'] = int(reclaimed)
            e['new_globals']['wire_count'] = int(not reclaimed)
            e['queues']['free'] = [B.PG, B.PG] if reclaimed else [B.FREE, B.FREE]
            e['tlb_counters'] = [3, 3] if reclaimed else [1, 1]
            if reclaimed:
                for off in (0, 4):
                    patch(e, 'kernel_object', off, B.KO)
                    patch(e, 'kernel_page', off, B.FREE)
                patch(e, 'kernel_object', 0x18, 1, 2)
                patch(e, 'kernel_object', 0x1a, 0, 2)
                patch(e, 'kernel_page', 0x1c, 0, 2)
                patch(e, 'kernel_page', 0x1e, 8, 1)
                patch(e, 'kernel_page', 0x20, 0, 1)
                for off in (0x10, 0x14):
                    patch(e, 'kernel_pmap', off, 0)
                for off in (0xc, 0x10, 0x40):
                    patch(e, 'kernel_map', off, B.KM + 0xc)
                for off in (0x1c, 0x28):
                    patch(e, 'kernel_map', off, 0)
                patch(e, 'kernel_map', 0x4c, value(reference['after'], 'kernel_map', 0x4c) + 1)
                patch(e, 'kernel_entry', 0, 0)
                patch(e, 'kernel_entry', 0x28, 0, 2)
                for key, element in (('entry_zone', B.KE), ('extension_zone', B.EXT)):
                    for off, v in ((8, 0), (0xc, element), (0x10, element)):
                        patch(e, key, off, v)
                e['buckets'] = row['seeded']['buckets']
        # CPU/stack are independently constrained by stack_flow/ABI; paging views
        # by state_contract and write replay. No A/D allowance in the PD itself.
        for key in ('cpu', 'stack_memory', 'roots', 'raw_translation', 'new_walks'):
            e[key] = after[key]
        assert after == e, ('PD lifetime endpoint model', label)


def lifecycle(row, reference):
    assert tuple(row['params']) in S.matrix(False)
    assert row['native_cpu_verified'] is False and row['whole_ownership_verified'] is False
    seed_check(row, reference)
    target, lock_mode, first = row['params']
    plan = [('pmap_zone_lock_init', 0x15b54c, [S.ZONE + 0x30, 1], None)] if lock_mode else []
    plan += [('create_slot0', 0x18f644, [0], None), ('gc_partial_first', 0x191144, [], 3),
             ('create_slot1', 0x18f644, [0], None), ('destroy_first', 0x18f69c, [S.PMAPS[first]], None),
             ('gc_partial_remaining', 0x191144, [], 5), ('destroy_last', 0x18f69c, [S.PMAPS[1 - first]], None),
             ('gc_empty', 0x191144, [], 7)]
    assert [(s['label'], s['entry'], s['args'], s['tick']) for s in row['stages']] == plan
    previous = row['seeded']
    for stage in row['stages']:
        check_stage(stage, previous, target)
        previous = stage['after']
    semantics(row, reference)
    return {'params': row['params'], 'stages_checked': len(row['stages']), 'passed': True,
            'bounded_lifetime_checks_passed': True}


def main():
    smoke = '--smoke' in sys.argv
    stem = 'smoke' if smoke else 'pd'
    rows = json.loads((S.HERE / (stem + '-cases.json')).read_text())
    assert [tuple(r['params']) for r in rows] == S.matrix(smoke)
    refs = S.references()
    out = [lifecycle(r, refs[tuple(r['params'][:2])]) for r in rows]
    S.save(stem + '-audit.json', {'cases': out, 'all_passed': True, 'whole_goal_complete': False,
        'scope': 'bounded PD lifecycle/critical copies/dirty backing plus state continuity, write replay and stack; not full CPU or boot proof'})
    print(json.dumps({'cases_checked': len(out), 'bounded_lifetime_checks_passed': True}))


if __name__ == '__main__':
    main()
