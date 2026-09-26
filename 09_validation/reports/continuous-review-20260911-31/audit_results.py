"""Independent raw-Mach-O/recorded-state audit; never imports execution modules.

One emulator's evidence is checked, not independently executed hardware semantics.
Conditional-edge legality is checked, not a complete CPU flag evaluator.
"""
import importlib.util
import itertools
import json
from pathlib import Path
import struct

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('audit30', HERE.parent / 'continuous-review-20260911-30/audit_results.py')
B = importlib.util.module_from_spec(spec)
spec.loader.exec_module(B)
A, C = B.A, B.B
put, desc = C.put, C.desc
VM, HW, OBJ, PAGE, PMAP, HASH = C.VM, C.HW, C.OBJ, C.PAGE, C.PMAP, C.HASH
DESC, EXT, OLDPT, DATA, END = C.DESC, C.EXT, C.PT, C.PHYS, C.END
ROOTS, BASE = C.ROOTS, 0xc0000000
KM, KE, KO, PG, EZ, XZ = 0x69a000, 0x69a100, 0x69a200, 0x683100, 0x69a300, 0x69a400
KVA, PT, KP, KR, SHARED, VA = 0x820000, 0xb02000, 0x1f7a60, 0x20c00, 0x402000, 0x600000
FREE, ACTIVE, STACK, STOP = 0x1f6e48, 0x1f7ac8, 0x70f020, 0x740000
GLOBAL_ADDR = {'active_count': 0x1f6e34, 'inactive_count': 0x1f64d8, 'free_count': 0x1f6e38,
               'queue_lock': 0x1f64e8, 'free_lock': 0x1f7418, 'ipl': 0x1e7714,
               'reserved': 0x1e0d1c, 'minimum': 0x1e0d14, 'target': 0x1e0d10, 'inactive_target': 0x1e0d18,
               'zero_count': 0x1f6504, 'pt_count': ACTIVE - 8, 'fault_count': 0x1f6514,
               'object_cache_lock': 0x1f6f2c, 'exception_flag': 0x1f74d4}
NEW_ADDR = {'wire_count': 0x1f7470, 'kernel_map': 0x1e8de8, 'kernel_object': 0x1f6ea0,
            'entry_zone': 0x1f6ec0, 'extension_zone': 0x1f7ab4, 'ipl': 0x1e7714}
NARGS = {0x190cfc: 2, 0x173d1c: 3, 0x174a90: 6, 0x16b790: 1, 0x16b84c: 2,
         0x176164: 3, 0x174848: 5, 0x173ebc: 4, 0x17b200: 3, 0x175b2c: 4,
         0x173898: 3, 0x17b6e8: 1, 0x19065c: 5}
MILESTONES = set(NARGS) | {0x174bf4, 0x173f92, 0x173a11, 0x1735c3, 0x173e3a, 0x190d7b, 0x190de5, 0x190e20, 0x190f1a, 0x1907b1}


def value(s, field, offset=0, fmt='I'):
    return struct.unpack_from('<' + fmt, bytes.fromhex(s[field]), offset)[0]


def table_contract():
    # Tables reside in BSS: derive them from original bootstrap jump table + MOV immediates.
    kernel, user = [], []
    for prot in range(8):
        target = struct.unpack('<I', A.original(0x18ef30 + prot * 4, 4))[0]
        assert target in (0x18ef50, 0x18ef64, 0x18ef78)
        first = A.instruction(target)
        add = A.instruction(target + first.size)
        second = A.instruction(add.address + add.size)
        assert first.mnemonic == second.mnemonic == 'mov'
        assert add.mnemonic == 'add' and add.operands[1].imm == 4
        assert first.operands[1].type == second.operands[1].type == A.capstone.x86.X86_OP_IMM
        kernel.append(first.operands[1].imm)
        user.append(second.operands[1].imm)
    return {hex(a): struct.pack('<8I', *v).hex() for a, v in [(0x1f7a80, kernel), (0x1f7b00, user)]}


def regions(s):
    entries = [(a, bytes.fromhex(s[k])) for k, a in [
        ('object', OBJ), ('page', PAGE), ('pmap', PMAP), ('map', 0x680400), ('entry', 0x680600),
        ('frame', DATA), ('pt_pair', OLDPT), ('descriptor_arena', DESC), ('extension', EXT), ('buckets', HASH),
        ('kernel_pmap', KP), ('kernel_map', KM), ('kernel_entry', KE), ('kernel_object', KO),
        ('kernel_page', PG), ('entry_zone', EZ), ('extension_zone', XZ), ('new_pt_frame', PT), ('stack_memory', STACK)]]
    entries += [(ROOTS[n], bytes.fromhex(raw)) for n, raw in s['roots'].items()]
    entries += [(int(a, 16), bytes.fromhex(raw)) for a, raw in s['raw_translation'].items()]
    entries += [(int(a, 16), bytes.fromhex(raw)) for a, raw in s['protection_tables'].items()]
    entries += [(a, struct.pack('<I', s['globals'][k])) for k, a in GLOBAL_ADDR.items()]
    entries += [(a, struct.pack('<I', s['new_globals'][k])) for k, a in NEW_ADDR.items()]
    entries += [(int(a, 16), struct.pack('<I', v)) for a, v in s['contract_globals'].items()]
    entries += [(C.HEADS[k], struct.pack('<2I', *v)) for k, v in s['queues'].items()]
    entries += [(0x1f7ad8, struct.pack('<2I', *s['pt_free_queue'])),
                (0x1f7ad4, struct.pack('<I', s['pt_free_count'])), (0x1f7ad0, struct.pack('<I', s['pt_alloc_count'])),
                (0x1f7af0, struct.pack('<2I', *s['tlb_counters']))]
    result = {}
    for addr, raw in entries:
        if addr in result:
            assert result[addr] == raw, hex(addr)
        result[addr] = raw
    return result


def read_word(memory, address):
    matches = [struct.unpack_from('<I', raw, address - a)[0] for a, raw in memory.items()
               if a <= address and address + 4 <= a + len(raw)]
    assert matches and len(set(matches)) == 1, hex(address)
    return matches[0]


def walk(memory, root, linear):
    # Kernel pmap root is a directory slice: do NOT align it down like hardware CR3.
    pa = root + (linear >> 22) * 4
    pde = read_word(memory, pa)
    out = {'linear': hex(linear), 'pde_address': hex(pa), 'pde': hex(pde)}
    if not pde & 1:
        return dict(out, present=False)
    assert not pde & 0x80
    ta = (pde & -HW) + ((linear >> 12) & 0x3ff) * 4
    pte = read_word(memory, ta)
    out.update(pte_address=hex(ta), pte=hex(pte), present=bool(pte & 1))
    if pte & 1:
        out.update(physical=hex((pte & -HW) + (linear & (HW - 1))),
                   writable=bool(pde & pte & 2), user=bool(pde & pte & 4))
    return out


def state_contract(s, target):
    expected = {0x1f7ab0: DESC, 0x1f7ab8: 0, 0x1f7ae0: VM // HW, 0x1f7ae8: 0x800000,
                0x1e247c: 0, 0x1e2480: END, 0x1e0d0c: VM, 0x1e89ec: VM - 1,
                0x1f7438: HASH, 0x1f743c: 7, 0x1f6ea4: VM.bit_length() - 1, 0x1f63f0: KP}
    assert s['contract_globals'] == {hex(a): v for a, v in expected.items()}
    assert s['pt_contract'] == {'kernel_map': KM, 'kernel_object': KO, 'kernel_pmap_address': KP, 'kernel_root': KR}
    for k, v in {'kernel_map': KM, 'kernel_object': KO, 'entry_zone': EZ, 'extension_zone': XZ, 'ipl': 7}.items():
        assert s['new_globals'][k] == v
    assert s['protection_tables'] == table_contract()
    assert set(s['raw_translation']) == {hex(KR), hex(SHARED)}
    assert s['cpu']['cr3'] == ROOTS[target]
    m = regions(s)
    expected_walks = {name: [walk(m, root, va + off) for off in range(0, VM, HW)]
                      for name, root, va in [('kernel_low', KR, KVA), ('kernel_high', ROOTS[target], BASE + KVA),
                                             ('frame_high', ROOTS[target], BASE + PT), ('user', ROOTS[target], VA)]}
    assert s['new_walks'] == expected_walks
    for low, high, frame in zip(expected_walks['kernel_low'], expected_walks['kernel_high'], expected_walks['frame_high']):
        assert frame['present'] and frame['writable'] and not frame['user']
        assert int(frame['physical'], 16) == int(frame['linear'], 16) - BASE
        assert int(frame['pte'], 16) & ~0x60 == int(frame['physical'], 16) | 3
        assert int(low['pde'], 16) == SHARED | 3
        assert int(high['pde'], 16) & ~0x20 == SHARED | 3
        # An absent PDE cannot stand in for the preexisting shared kernel table.
        assert int(low['pde'], 16) & 1 and int(high['pde'], 16) & 1
        assert low['pte_address'] == high['pte_address'] and low['pte'] == high['pte']
        assert low['present'] == high['present']
        if low['present']:
            assert low['physical'] == high['physical']
            assert low['writable'] and high['writable'] and not low['user'] and not high['user']


def boundary_model(s, target, sleepable, final, caller):
    state_contract(s, target)
    obj = bytearray(0x58)
    put(obj, 0, PAGE, PAGE)
    put(obj, 0x14, VM * 4)
    put(obj, 0x18, 1, 1, fmt='H')
    put(obj, 0x54, VM * 3)
    assert s['object'] == obj.hex()
    page = bytearray(0x30)
    put(page, 8, OBJ, OBJ, 0, OBJ, VM * 3)
    page[0x1e], page[0x20] = 0x20, 5
    put(page, 0x24, DATA)
    assert s['page'] == page.hex()
    obj = bytearray(0x58)
    put(obj, 0, PG if final else KO, PG if final else KO)
    put(obj, 0x14, KVA + VM)
    put(obj, 0x18, 2 if final else 1, int(final), fmt='H')
    put(obj, 0x54, KVA if final else 0)
    assert s['kernel_object'] == obj.hex()
    page = bytearray(0x30)
    if not final:
        put(page, 0, FREE, FREE)
    put(page, 8, KO, KO, 0, KO, KVA)
    put(page, 0x1c, int(final), fmt='H')
    page[0x1e], page[0x20] = (0x20, 4) if final else (0x28, 1)
    put(page, 0x24, PT)
    assert s['kernel_page'] == page.hex()
    kernel_map = bytearray(0x50)
    put(kernel_map, 0, 0xffffffff, 0x80000)
    put(kernel_map, 0xc, KE if final else KM + 0xc, KE if final else KM + 0xc,
        KVA, KVA + VM, int(final), 0, KP, VM if final else 0, 1)
    put(kernel_map, 0x38, KM + 0xc, 0, KE if final else KM + 0xc)
    put(kernel_map, 0x4c, 3 if final else 0)
    assert s['kernel_map'] == kernel_map.hex()
    ent = bytearray(0x2c)
    if final:
        put(ent, 0, KM + 0xc, KM + 0xc, KVA, KVA + VM, KO, KVA, 0, 3, 7, 1, 1)
    assert s['kernel_entry'] == ent.hex()
    for field, element, size in [('entry_zone', KE, 0x2c), ('extension_zone', EXT, 0x20)]:
        zone = bytearray(0x40)
        put(zone, 4, 7 if final and not sleepable else 0, int(final))
        put(zone, 0xc, 0 if final else element, 0 if final else element, size, size, size, VM, 0, 0, sleepable)
        if sleepable:
            put(zone, 0x30, 0xffffffff, 0x80000)
        assert s[field] == zone.hex(), field
    mapped = final and caller
    pm = bytearray(0x1c)
    put(pm, 0, ROOTS[target], ROOTS[target], 1, 0, int(mapped), 0, 1)
    assert s['pmap'] == pm.hex()
    put(pm, 0, KR, 0x20000, 1, 0, int(final), int(final), 0)
    assert s['kernel_pmap'] == pm.hex()
    arena, ext = bytearray(END // VM * 20), bytearray(0x20)
    if final:
        put(arena, desc(PT) - DESC, 0, KP, KVA, EXT)
        put(ext, 0, ACTIVE, ACTIVE, desc(PT), PT, PMAP, 0)
        put(ext, 0x18, int(mapped), 0, fmt='H')
    if mapped:
        put(arena, desc(DATA) - DESC, 0, PMAP, VA)
    assert s['descriptor_arena'] == arena.hex() and s['extension'] == ext.hex()
    buckets = bytearray(64)
    put(buckets, ((OBJ + 3) & 7) * 8 + 4, PAGE)
    if final:
        put(buckets, ((KO + (KVA >> 13)) & 7) * 8 + 4, PG)
    assert s['buckets'] == buckets.hex()
    g = {k: 0 for k in GLOBAL_ADDR}
    g.update(ipl=7, free_count=int(not final), pt_count=int(final), fault_count=int(final))
    assert s['globals'] == g
    assert s['new_globals']['wire_count'] == int(final)
    assert s['pt_free_queue'] == [0x1f7ad8, 0x1f7ad8] and s['pt_free_count'] == 0
    assert s['pt_alloc_count'] == int(final)
    queues = {k: [h, h] for k, h in C.HEADS.items()}
    if final:
        queues['pt'] = [EXT, EXT]
    else:
        queues['free'] = [PG, PG]
    assert s['queues'] == queues
    assert s['tlb_counters'] == [int(final), int(final)]
    assert s['frame'] == bytes((i * 19 + (i >> 7) + 0x53) & 0xff for i in range(VM)).hex()
    assert s['pt_pair'] == bytes(VM).hex()
    assert s['copy_buffer_hashes'] == A.expected_hashes(target, 1, 0x100, 0)
    assert s['recover'] == 0 and s['uthread'] == 'a5'
    pt = bytearray(VM) if final else bytearray((i * 23 + (i >> 8) + 0x79) & 0xff for i in range(VM))
    if mapped:
        for off in range(0, VM, HW):
            put(pt, (((VA + off) & (0x800000 - 1)) >> 12) * 4, (DATA + off) | 7)
    assert s['new_pt_frame'] == pt.hex()
    root_words = B.words(s['roots'][target])
    expected_user = [0] * (BASE >> 22)
    if final:
        for i in range(VM // HW):
            expected_user[i] = (PT + i * HW) | 7
    assert root_words[:BASE >> 22] == expected_user
    for off in range(0, VM, HW):
        w = s['new_walks']['kernel_low'][off // HW]
        assert w['present'] == final
        if final:
            assert int(w['pte'], 16) == (PT + off) | 0x203 and not w['user'] and w['writable']
        else:
            assert int(w['pte'], 16) == 0


def replay(row):
    before = row['before']
    memories = {a: bytearray(raw) for a, raw in regions(before).items()}
    trace = row['observation']['trace']
    writes = row['writes']
    assert [w['trace_index'] for w in writes] == sorted(w['trace_index'] for w in writes)
    for w in writes:
        assert w['width'] in (1, 2, 4) and 0 <= w['value'] < (1 << (8 * w['width']))
        assert trace[w['trace_index']] == hex(w['pc'])
        ins = A.instruction(w['pc'])
        if ins.mnemonic in ('call', 'push'):
            assert w['width'] == 4 and STACK <= w['address'] and w['address'] + 4 <= 0x710004
        else:
            destinations = [op for op in ins.operands if op.type == A.capstone.x86.X86_OP_MEM and op.access & A.capstone.CS_AC_WRITE]
            assert any(op.size == w['width'] for op in destinations), (hex(w['pc']), ins.mnemonic, w)
    cursor = 0
    boundaries = row['points'] + [{'state': row['after'], 'write_cursor': len(writes), 'trace_index': len(trace)}]
    for point in boundaries:
        assert cursor <= point['write_cursor'] <= len(writes)
        assert point['write_cursor'] == sum(w['trace_index'] < point['trace_index'] for w in writes)
        for w in writes[cursor:point['write_cursor']]:
            matches = [(a, raw) for a, raw in memories.items() if a <= w['address'] and w['address'] + w['width'] <= a + len(raw)]
            assert matches, w
            for a, raw in matches:
                offset = w['address'] - a
                raw[offset:offset + w['width']] = w['value'].to_bytes(w['width'], 'little')
        observed = regions(point['state'])
        assert set(observed) == set(memories)
        for a, expected in memories.items():
            actual = observed[a]
            assert len(actual) == len(expected)
            if a == SHARED or a == ROOTS[row['target']]:
                for off in range(0, len(actual), 4):
                    old, new = struct.unpack_from('<I', expected, off)[0], struct.unpack_from('<I', actual, off)[0]
                    # Hardware A/D: only existing shared kernel aliases, never newly installed KVA or user PDEs.
                    if a == SHARED and off not in [((KVA + i) >> 12 & 0x3ff) * 4 for i in range(0, VM, HW)]:
                        permitted = 0x60 if old & 1 else 0
                    elif a == ROOTS[row['target']] and off >= (BASE >> 22) * 4:
                        permitted = 0x20 if old & 1 else 0
                    else:
                        permitted = 0
                    assert (new | old) == new and (new ^ old) & ~permitted == 0, (hex(a + off), hex(old), hex(new))
            else:
                assert actual == expected, (hex(a), point.get('pc', 'after'))
            memories[a] = bytearray(actual)
        cursor = point['write_cursor']


def preparation(row):
    f, target = row['setup'], row['target']
    assert f['vm_size'] == VM and f['kernel_pmap'] == KP and f['kernel_root'] == KR
    assert f['sleepable'] == row['sleepable'] and not f['register_backing']
    expected = [(f['startup_prefix'], 0x17aa08, [], 0x17aade),
                (f['seed_calls'][0], 0x17b134, [PAGE, OBJ, VM * 3, DATA], STOP),
                (f['seed_calls'][1], 0x17b540, [PAGE], STOP),
                (f['data_allocation'], 0x17b200, [OBJ, VM * 3, 1], STOP),
                (f['new_seed_calls'][0], 0x17b134, [PG, KO, KVA, PT], STOP),
                (f['new_seed_calls'][1], 0x17b540, [PG], STOP)]
    assert len(f['seed_calls']) == len(f['new_seed_calls']) == 2
    for item, entry, args, stop in expected:
        obs = item['observation']
        assert item['entry'] == hex(entry) and item['args'] == args
        assert obs['trace'] and obs['trace'][0] == hex(entry) and obs['error'] is None and not obs['interrupts']
        assert obs['after']['eip'] == stop
        C.trace_check(obs['trace'], stop, open_prefix=stop == 0x17aade)
    assert f['data_allocation']['observation']['after']['eax'] == PAGE
    init_addresses = [KM] + ([EZ + 0x30, XZ + 0x30] if row['sleepable'] else [])
    assert len(f['new_lock_init']) == len(init_addresses)
    for item, address in zip(f['new_lock_init'], init_addresses):
        assert item['entry'] == '0x15b54c' and item['args'] == [address, 1]
        obs = item['observation']
        assert obs['error'] is None and not obs['interrupts'] and obs['after']['eip'] == STOP
        B.lock_init_trace(obs['trace'])
    for name in ('original_pre_fault_cr3_reload', 'new_cr3_reload'):
        obs = f[name]
        assert obs['trace'] == ['0x18d3ef'] and obs['error'] is None and not obs['interrupts']
        assert obs['after']['eip'] == 0x18d3f2 and obs['after']['cr3'] == ROOTS[target]
    assert len(f['replaced_kernel_aliases']) == VM // HW
    for index, item in enumerate(f['replaced_kernel_aliases']):
        logical = KVA + index * HW
        a = SHARED + ((logical >> 12) & 0x3ff) * 4
        assert item['kernel']['linear'] == hex(logical) and item['active']['linear'] == hex(BASE + logical)
        assert item['kernel']['pte_address'] == item['active']['pte_address'] == hex(a)
        assert item['old'] & ~0x60 == logical | 3


def audit_case(row):
    target, sleepable, caller = row['target'], row['sleepable'], row['caller']
    assert target in ROOTS and sleepable in (0, 1) and type(caller) is bool
    preparation(row)
    before, after, obs = row['before'], row['after'], row['observation']
    entry = 0x19065c if caller else 0x190cfc
    args = [PMAP, VA, DATA, 3, 0] if caller else [PMAP, VA]
    assert row['entry'] == hex(entry) and row['args'] == args and row['prepared_stack'] == [STOP] + args
    assert list(struct.unpack_from('<' + 'I' * (len(args) + 1), bytes.fromhex(before['stack_memory']), 0x70ff00 - STACK)) == [STOP] + args
    assert before['cpu']['esp'] == 0x70ff00
    assert row['failure'] is None and obs['error'] is None and not obs['interrupts']
    assert obs['trace'] and obs['trace'][0] == hex(entry)
    C.trace_check(obs['trace'], STOP)
    assert obs['after'] == after['cpu'] and after['cpu']['eip'] == STOP and after['cpu']['esp'] == 0x70ff04
    for k, v in [('ebx', 0x12341111), ('esi', 0x23452222), ('edi', 0x34563333), ('ebp', 0x45674444)]:
        assert after['cpu'][k] == v
    for k in ('cs', 'ds', 'es', 'ss', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4'):
        assert before['cpu'][k] == after['cpu'][k]
    for pc in (0x10ca6c, 0x163320, 0x1631a0, 0x16b3df, 0x190e51, 0x172038, 0x17390e):
        assert hex(pc) not in obs['trace']
    boundary_model(before, target, sleepable, False, caller)
    boundary_model(after, target, sleepable, True, caller)
    expected_indices = [i for i, pc in enumerate(obs['trace']) if int(pc, 16) in MILESTONES]
    assert [p['trace_index'] for p in row['points']] == expected_indices
    for point in row['points']:
        assert obs['trace'][point['trace_index']] == point['pc']
        assert point['cpu'] == point['state']['cpu'] and point['cpu']['eip'] == int(point['pc'], 16)
        state_contract(point['state'], target)
        pc = int(point['pc'], 16)
        if pc in NARGS:
            raw = bytes.fromhex(point['state']['stack_memory'])
            actual = list(struct.unpack_from('<' + 'I' * NARGS[pc], raw, point['cpu']['esp'] + 4 - STACK))
            assert point['args'] == actual
    def points(pc):
        return [p for p in row['points'] if p['pc'] == hex(pc)]
    def one(pc):
        result = points(pc)
        assert len(result) == 1, hex(pc)
        return result[0]
    assert [p['args'] for p in points(0x19065c)] == ([args] if caller else []) + [[KP, KVA, PT, 3, 1]]
    assert one(0x190cfc)['args'] == [PMAP, VA]
    kmem = one(0x173d1c)
    assert kmem['args'] == [KM, one(0x190cfc)['cpu']['esp'] - 8, VM]
    find = one(0x174a90)
    assert find['args'][:3] == [KM, 0, 0] and find['args'][4:] == [VM, 1]
    assert read_word(regions(find['state']), find['args'][3]) == KVA
    for pc, expected in [(0x176164, [KM, KVA, KVA + VM]), (0x174848, [KM, KO, KVA, KVA, KVA + VM]),
                         (0x173ebc, [KO, KVA, VM, 1]), (0x17b200, [KO, KVA, 1]),
                         (0x175b2c, [KM, KVA, KVA + VM, 0]), (0x173898, [KM, KVA, KE]), (0x17b6e8, [PG])]:
        assert one(pc)['args'] == expected
    zone_ops = [(p['pc'], p['args']) for p in row['points'] if p['pc'] in ('0x16b790', '0x16b84c')]
    assert zone_ops == [('0x16b790', [EZ]), ('0x16b84c', [EZ, KE]), ('0x16b790', [EZ]), ('0x16b790', [XZ])]
    assert value(one(0x174848)['state'], 'entry_zone', 8) == 0
    assert value(one(0x174848)['state'], 'entry_zone', 0x10) == KE
    assert one(0x1735c3)['cpu']['eax'] == 0 and one(0x190d7b)['cpu']['eax'] == 0
    assert read_word(regions(one(0x190d7b)['state']), kmem['args'][1]) == KVA
    assert one(0x190de5)['cpu']['eax'] == PT and one(0x190de5)['cpu']['ebx'] == EXT
    zero = one(0x173f92)['state']
    assert zero['new_pt_frame'] == bytes(VM).hex() and value(zero, 'kernel_page', 0x20, 'B') == 5
    wired_entry = points(0x19065c)[-1]['state']
    assert value(wired_entry, 'kernel_page', 0x1c, 'H') == 1 and wired_entry['new_globals']['wire_count'] == 1
    assert value(wired_entry, 'kernel_page', 0x20, 'B') == 5
    assert value(one(0x175b2c)['state'], 'kernel_page', 0x20, 'B') == 4
    assert value(one(0x1735c3)['state'], 'kernel_page', 0x20, 'B') == 4
    chunks = row['zero_chunks']
    assert len(chunks) == VM // 32
    for i, chunk in enumerate(chunks):
        assert (chunk['eax'], chunk['ecx'], chunk['edx']) == (0, VM - i * 32, PT + i * 32)
        assert obs['trace'][chunk['trace_index']] == '0x1019cc'
    zero_pcs = [0x1019cc, 0x1019cf, 0x1019d2, 0x1019d5, 0x1019d8, 0x1019db, 0x1019de, 0x1019e1]
    zero_writes = [w for w in row['writes'] if w['pc'] in zero_pcs]
    assert [(w['pc'], w['address'], w['width'], w['value']) for w in zero_writes] == [
        (pc, PT + chunk * 32 + i * 4, 4, 0) for chunk in range(VM // 32) for i, pc in enumerate(zero_pcs)]
    ptes = [(w['address'], w['width'], w['value']) for w in row['writes'] if w['pc'] == 0x190aa7]
    expected_ptes = [(SHARED + (((KVA + off) >> 12) & 0x3ff) * 4, 4, (PT + off) | 0x203) for off in range(0, VM, HW)]
    if caller:
        expected_ptes += [(PT + (((VA + off) & (0x800000 - 1)) >> 12) * 4, 4, (DATA + off) | 7) for off in range(0, VM, HW)]
    assert ptes == expected_ptes
    assert [(w['address'], w['width'], w['value']) for w in row['writes'] if w['pc'] == 0x190ef4] == [
        (ROOTS[target] + i * 4, 4, (PT + i * HW) | 7) for i in range(VM // HW)]
    for pc, address, width, expected in [(0x190de5, EXT + 0xc, 4, PT), (0x190e06, desc(PT) + 0xc, 4, EXT),
                                         (0x17b7ac, NEW_ADDR['wire_count'], 4, 1), (0x17b7b2, PG + 0x1c, 2, 1)]:
        assert [(w['address'], w['width'], w['value']) for w in row['writes'] if w['pc'] == pc] == [(address, width, expected)]
    replay(row)
    return {'target': target, 'sleepable': sleepable, 'caller': caller,
            'trace_heads': len(obs['trace']), 'zero_dword_stores': len(zero_writes), 'pte_stores': len(ptes),
            'pde_stores': VM // HW, 'passed': True}


def main():
    rows = json.loads((HERE / 'new-pt-cases.json').read_text())
    assert len(rows) == len(set(itertools.product(ROOTS, (0, 1), (False, True))))
    assert {(r['target'], r['sleepable'], r['caller']) for r in rows} == set(itertools.product(ROOTS, (0, 1), (False, True)))
    result = [audit_case(row) for row in rows]
    out = {'cases': result, 'all_passed': True, 'scope': 'independent byte/state/trace audit of one backend, not native hardware or full ownership'}
    (HERE / 'independent-audit.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps({'independently_audited': len(result), 'all_passed': True}))


if __name__ == '__main__':
    main()
