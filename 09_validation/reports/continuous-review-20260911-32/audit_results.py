"""Independent original-byte/state audit of fault + new PT evidence; no executor import."""
import importlib.util
import itertools
import json
from pathlib import Path
import struct

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('audit31', HERE.parent / 'continuous-review-20260911-31/audit_results.py')
B = importlib.util.module_from_spec(spec)
spec.loader.exec_module(B)
A, C = B.A, B.C
put, desc, value = B.put, B.desc, B.value
VM, HW, OBJ, PAGE, PMAP, HASH, DESC, EXT, OLDPT, DATA, END = B.VM, B.HW, B.OBJ, B.PAGE, B.PMAP, B.HASH, B.DESC, B.EXT, B.OLDPT, B.DATA, B.END
ROOTS, BASE, KM, KE, KO, PG, EZ, XZ = B.ROOTS, B.BASE, B.KM, B.KE, B.KO, B.PG, B.EZ, B.XZ
KVA, PT, KP, KR, SHARED, VA, FREE, ACTIVE, STACK, STOP = B.KVA, B.PT, B.KP, B.KR, B.SHARED, B.VA, B.FREE, B.ACTIVE, B.STACK, B.STOP
COPY = {'_copyout': (0x189cec, 0x189d1b, 0x189e70), '_copyoutmsg': (0x189e8c, 0x189ec4, 0x18a018)}
FIELDS = ('gs', 'fs', 'es', 'ds', 'edi', 'esi', 'ebp', 'pushad_esp', 'ebx', 'edx', 'ecx', 'eax', 'trap', 'error', 'eip', 'cs', 'eflags')


def regions(s):
    result = B.regions(s)
    result.update({0x710000: bytes.fromhex(s['copy_stack']),
                   0x680074: struct.pack('<I', s['recover']), 0x680868: bytes.fromhex(s['uthread'])})
    assert result[0x710000][:4] == result[STACK][0x710000 - STACK:0x710004 - STACK]
    return result


def contract(s, row):
    B.state_contract(s, row['target'])
    mem = regions(s)
    wanted = [B.walk(mem, ROOTS[row['target']], BASE + DATA + off) for off in range(0, VM, HW)]
    assert s['data_high_walks'] == wanted
    for off, w in zip(range(0, VM, HW), wanted):
        assert w['present'] and w['writable'] and not w['user']
        assert int(w['physical'], 16) == DATA + off and int(w['pte'], 16) & ~0x60 == (DATA + off) | 3
    assert s['copy_stack'] == struct.pack('<4I', STOP, VA + 0x100, VA + row['destination'], 1).hex()
    assert s['copy_buffer_hashes'] == A.expected_hashes(row['target'], 1, row['destination'], 0)


def boundary(s, row, final):
    contract(s, row)
    target, sleepable, dest = row['target'], row['sleepable'], row['destination']
    for obj_addr, page_addr, field, size, offset, ref in [(OBJ, PAGE, 'object', VM * 4, VM * 3, 1),
                                                        (KO, PG, 'kernel_object', KVA + VM, KVA, 2 if final else 1)]:
        obj = bytearray(0x58)
        put(obj, 0, page_addr if final else obj_addr, page_addr if final else obj_addr)
        put(obj, 0x14, size)
        put(obj, 0x18, ref, int(final), fmt='H')
        put(obj, 0x54, offset)  # Both last_alloc fields retain original preparation history.
        assert s[field] == obj.hex(), field
    page = bytearray(0x30)
    put(page, 0, 0x1f6e40 if final else PG, 0x1f6e40 if final else FREE)
    put(page, 8, OBJ, OBJ, 0, OBJ, VM * 3)
    page[0x1e], page[0x20] = (0x22, 4) if final else (0x28, 1)
    put(page, 0x24, DATA)
    assert s['page'] == page.hex()
    page = bytearray(0x30)
    if not final:
        put(page, 0, FREE, PAGE)
    put(page, 8, KO, KO, 0, KO, KVA)
    put(page, 0x1c, int(final), fmt='H')
    page[0x1e], page[0x20] = (0x20, 4) if final else (0x28, 1)
    put(page, 0x24, PT)
    assert s['kernel_page'] == page.hex()
    km = bytearray(0x50)
    put(km, 0, 0xffffffff, 0x80000)
    put(km, 0xc, KE if final else KM + 0xc, KE if final else KM + 0xc,
        KVA, KVA + VM, int(final), 0, KP, VM if final else 0, 1)
    put(km, 0x38, KM + 0xc, 0, KE if final else KM + 0xc)
    put(km, 0x4c, 3 if final else 0)
    assert s['kernel_map'] == km.hex()
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
        assert s[field] == zone.hex()
    pm = bytearray(0x1c)
    put(pm, 0, ROOTS[target], ROOTS[target], 1, 0, int(final), 0, 1)
    assert s['pmap'] == pm.hex()
    put(pm, 0, KR, 0x20000, 1, 0, int(final), int(final), 0)
    assert s['kernel_pmap'] == pm.hex()
    arena, ext, buckets = bytearray(END // VM * 20), bytearray(0x20), bytearray(64)
    if final:
        put(arena, desc(PT) - DESC, 0, KP, KVA, EXT)
        put(arena, desc(DATA) - DESC, 0, PMAP, VA)
        put(ext, 0, ACTIVE, ACTIVE, desc(PT), PT, PMAP, 0)
        put(ext, 0x18, 1, 0, fmt='H')
        put(buckets, ((OBJ + 3) & 7) * 8 + 4, PAGE)
        put(buckets, ((KO + (KVA >> 13)) & 7) * 8 + 4, PG)
    assert s['descriptor_arena'] == arena.hex() and s['extension'] == ext.hex() and s['buckets'] == buckets.hex()
    g = {k: 0 for k in B.GLOBAL_ADDR}
    g.update(ipl=7, free_count=0 if final else 2, active_count=int(final), pt_count=int(final),
             fault_count=2 if final else 0, zero_count=int(final))
    assert s['globals'] == g
    assert s['new_globals']['wire_count'] == int(final)
    assert s['pt_free_queue'] == [0x1f7ad8, 0x1f7ad8] and s['pt_free_count'] == 0
    assert s['pt_alloc_count'] == int(final) and s['tlb_counters'] == [int(final), int(final)]
    queues = {k: [h, h] for k, h in C.HEADS.items()}
    if final:
        queues.update(active=[PAGE, PAGE], pt=[EXT, EXT])
    else:
        queues['free'] = [PAGE, PG]
    assert s['queues'] == queues
    data = bytearray(VM) if final else bytearray((i * 19 + (i >> 7) + 0x53) & 0xff for i in range(VM))
    if final:
        data[dest] = (0x100 * 17 + (0x100 >> 8) * 29 + 0xc7) & 0xff
    assert s['frame'] == data.hex() and s['pt_pair'] == bytes(VM).hex()
    pt = bytearray(VM) if final else bytearray((i * 23 + (i >> 8) + 0x79) & 0xff for i in range(VM))
    if final:
        for off in range(0, VM, HW):
            flags = 0x67 if off == dest // HW * HW else 7
            put(pt, (((VA + off) & (0x800000 - 1)) >> 12) * 4, (DATA + off) | flags)
    assert s['new_pt_frame'] == pt.hex()
    user = [0] * (BASE >> 22)
    if final:
        for i in range(VM // HW):
            user[i] = (PT + i * HW) | 7
        user[(VA + dest) >> 22] |= 0x20
    assert B.B.words(s['roots'][target])[:BASE >> 22] == user
    for off, w in zip(range(0, VM, HW), s['new_walks']['kernel_low']):
        assert int(w['pte'], 16) == ((PT + off) | 0x203 if final else 0)
    assert s['recover'] == (COPY[row['function']][2] if final else 0) and s['uthread'] == 'a5'
    assert value(s, 'map', 0x24) == PMAP
    assert [value(s, 'entry', off) for off in (8, 0xc, 0x10, 0x14, 0x1c)] == [VA, VA + VM, OBJ, VM * 3, 3]


def preparation(row):
    B.preparation(row)
    calls = row['setup']['queue_preparation']
    expected = [('hold_pt_page', 0x17b200, [KO, KVA, 1], (1, 1, 0), (0, 1, 1)),
                ('free_data_first', 0x17b540, [PAGE], (0, 1, 1), (1, 0, 1)),
                ('free_pt_second', 0x17b540, [PG], (1, 0, 1), (2, 0, 0))]
    assert len(calls) == len(expected)
    for item, (label, entry, args, before_counts, after_counts) in zip(calls, expected):
        c, b, a = item['call'], item['before'], item['after']
        assert item['label'] == label and c['entry'] == hex(entry) and c['args'] == args
        obs = c['observation']
        assert obs['trace'] and obs['trace'][0] == hex(entry) and obs['error'] is None and not obs['interrupts']
        assert obs['after']['eip'] == STOP and obs['after'] == a['cpu']
        C.trace_check(obs['trace'], STOP)
        if entry == 0x17b200:
            assert obs['after']['eax'] == PG
        for s, counts in [(b, before_counts), (a, after_counts)]:
            assert (s['globals']['free_count'], value(s, 'object', 0x1a, 'H'), value(s, 'kernel_object', 0x1a, 'H')) == counts
            assert s['globals']['queue_lock'] == int(entry == 0x17b540)
            assert s['globals']['free_lock'] == 0
            held = 'object' if label == 'free_data_first' else 'kernel_object'
            assert value(s, held, 0x10) == 1
            assert s['frame'] == row['before']['frame'] and s['new_pt_frame'] == row['before']['new_pt_frame']
    assert calls[-1]['after']['queues']['free'] == [PAGE, PG]
    # Bridge the recorded original preparation to the actual copy input. Only the
    # declared caller-lock release and copy-call/buffer setup may intervene.
    last, start = calls[-1]['after'], row['before']
    for key in start:
        if key in ('cpu', 'stack_memory', 'copy_stack', 'copy_buffer_hashes', 'recover'):
            continue
        if key == 'kernel_object':
            expected = bytearray.fromhex(last[key])
            put(expected, 0x10, 0)
            assert start[key] == expected.hex()
        elif key == 'globals':
            assert start[key] == dict(last[key], queue_lock=0)
        else:
            assert start[key] == last[key], key
    assert row['setup']['copy_function'] == row['function'] and row['setup']['destination'] == row['destination']
    assert row['setup']['flags'] == row['flags']


def replay(row):
    memory = {a: bytearray(raw) for a, raw in regions(row['injected']).items()}
    trace, writes = row['handler']['trace'], row['writes']
    retry = trace.index(hex(COPY[row['function']][1]))
    target_pte = (((VA + row['destination']) & (0x800000 - 1)) >> 12) * 4
    assert [w['trace_index'] for w in writes] == sorted(w['trace_index'] for w in writes)
    for w in writes:
        assert 0 <= w['trace_index'] < len(trace) and trace[w['trace_index']] == hex(w['pc'])
        assert w['width'] in (1, 2, 4) and 0 <= w['value'] < (1 << (8 * w['width']))
        ins = A.instruction(w['pc'])
        if ins.mnemonic in ('push', 'call', 'pushal'):
            assert w['width'] == 4 and STACK <= w['address'] and w['address'] + 4 <= 0x710004
        else:
            dests = [op for op in ins.operands if op.type == A.capstone.x86.X86_OP_MEM and op.access & A.capstone.CS_AC_WRITE]
            assert any(op.size == w['width'] for op in dests), (hex(w['pc']), ins.mnemonic)
    cursor = 0
    for point in row['points'] + [{'state': row['after'], 'write_cursor': len(writes), 'trace_index': len(trace)}]:
        limit = point['write_cursor']
        assert cursor <= limit <= len(writes)
        assert limit == sum(w['trace_index'] < point['trace_index'] for w in writes)
        for w in writes[cursor:limit]:
            matches = [(a, raw) for a, raw in memory.items() if a <= w['address'] and w['address'] + w['width'] <= a + len(raw)]
            assert matches, w
            for a, raw in matches:
                off = w['address'] - a
                raw[off:off + w['width']] = w['value'].to_bytes(w['width'], 'little')
        actuals = regions(point['state'])
        assert set(actuals) == set(memory)
        for a, expected in memory.items():
            actual = actuals[a]
            assert len(expected) == len(actual)
            if a in (SHARED, ROOTS[row['target']], PT):
                for off in range(0, len(actual), 4):
                    old, new = struct.unpack_from('<I', expected, off)[0], struct.unpack_from('<I', actual, off)[0]
                    allowed = 0
                    if a == SHARED and off not in [(((KVA + i) >> 12) & 0x3ff) * 4 for i in range(0, VM, HW)]:
                        allowed = 0x60 if old & 1 else 0
                    elif a == ROOTS[row['target']] and off >= (BASE >> 22) * 4:
                        allowed = 0x20 if old & 1 else 0
                    elif point['trace_index'] > retry and old & 1:
                        if a == PT and off == target_pte:
                            allowed = 0x60
                        elif a == ROOTS[row['target']] and off == ((VA + row['destination']) >> 22) * 4:
                            allowed = 0x20
                    assert (new | old) == new and (new ^ old) & ~allowed == 0, (hex(a + off), hex(old), hex(new), point.get('pc'))
            else:
                assert actual == expected, (hex(a), point.get('pc', 'after'))
            memory[a] = bytearray(actual)
        cursor = limit


def audit_case(row):
    target, name, dest, flags, sleepable = [row[k] for k in ('target', 'function', 'destination', 'flags', 'sleepable')]
    assert target in ROOTS and name in COPY and dest in (0x100, 0x1100) and flags in (2, 0x602) and sleepable in (0, 1)
    preparation(row)
    before, at_fault, injected, after = [row[k] for k in ('before', 'at_fault', 'injected', 'after')]
    boundary(before, row, False)
    boundary(after, row, True)
    assert before['cpu']['esp'] == 0x710000 and before['cpu']['eflags'] == flags
    assert before['map'] == after['map'] and before['entry'] == after['entry']
    entry, fault_pc, recover = COPY[name]
    run, handler = row['fault'], row['handler']
    assert row['failure'] is None and row['native_cpu_frame_verified'] is False
    assert run['error'] is None and len(run['interrupts']) == 1
    event = run['interrupts'][0]
    fault = run['after']
    assert event['vector'] == 14 and event['snapshot'] == fault == at_fault['cpu']
    assert event['recover'] == recover == at_fault['recover']
    assert fault['eip'] == fault_pc and fault['cr2'] == VA + dest and fault['cr3'] == ROOTS[target]
    assert run['trace'][0] == hex(entry) and run['trace'][-1] == hex(fault_pc)
    C.trace_check(run['trace'][:-1], fault_pc)
    ins = A.instruction(fault_pc)
    mem, source = ins.operands
    assert ins.mnemonic == 'mov' and mem.type == A.capstone.x86.X86_OP_MEM and mem.size == 1
    assert ins.reg_name(mem.mem.segment) == 'fs' and source.type == A.capstone.x86.X86_OP_REG
    address = mem.mem.disp
    if mem.mem.base:
        address += fault[ins.reg_name(mem.mem.base)]
    if mem.mem.index:
        address += fault[ins.reg_name(mem.mem.index)] * mem.mem.scale
    assert address & 0xffffffff == fault['cr2']
    source_reg = ins.reg_name(source.reg)
    assert source_reg == 'bl'
    payload = (0x100 * 17 + (0x100 >> 8) * 29 + 0xc7) & 0xff
    assert fault['ebx'] & 0xff == payload
    # The observed first write failed: no data, allocator, map, or table mutation occurred.
    for k in before:
        if k not in ('cpu', 'stack_memory', 'recover'):
            assert at_fault[k] == before[k], k
    frame_addr = fault['esp'] - len(FIELDS) * 4
    cpu_addr = fault['esp'] - 4 * 4
    assert row['frame_address'] == frame_addr
    assert row['cpu_frame_input'] == {'address': cpu_addr, 'words': [2, fault_pc, fault['cs'], fault['eflags']]}
    for k in at_fault:
        if k == 'cpu':
            assert injected[k] == dict(at_fault[k], esp=cpu_addr)
        elif k == 'stack_memory':
            raw = bytearray.fromhex(at_fault[k])
            put(raw, cpu_addr - STACK, 2, fault_pc, fault['cs'], fault['eflags'])
            assert injected[k] == raw.hex()
        else:
            assert injected[k] == at_fault[k], k
    assert handler['error'] is None and not handler['interrupts'] and handler['after'] == after['cpu']
    trace = handler['trace']
    assert trace == row['recorded_heads'] and trace[0] == '0x1861cc'
    C.trace_check(trace, STOP, fault_pc)
    assert trace.count('0x186d7c') == trace.count(hex(fault_pc)) == 1
    assert trace[trace.index('0x186d7c') + 1] == hex(fault_pc)
    restart_next = fault_pc + ins.size
    assert trace[trace.index(hex(fault_pc)) + 1] == hex(restart_next)
    milestones = set(B.NARGS) | {0x187068, 0x1720d6, 0x17269f, 0x1729e9, 0x173f04, 0x173f92, 0x173a11,
        0x1735c3, 0x173e3a, 0x190d7b, 0x190de5, 0x190e20, 0x190f1a, 0x1907b1, 0x173451, 0x1921ec, 0x186d7c, fault_pc, restart_next}
    assert [p['trace_index'] for p in row['points']] == [i for i, pc in enumerate(trace) if int(pc, 16) in milestones]
    for point in row['points']:
        pc, s = int(point['pc'], 16), point['state']
        assert point['cpu'] == s['cpu'] and trace[point['trace_index']] == point['pc'] and s['cpu']['eip'] == pc
        contract(s, row)
        assert point['saved_frame'] == bytes.fromhex(s['stack_memory'])[frame_addr - STACK:frame_addr - STACK + len(FIELDS) * 4].hex()
        if pc in B.NARGS:
            assert point['args'] == list(struct.unpack_from('<' + 'I' * B.NARGS[pc], bytes.fromhex(s['stack_memory']), s['cpu']['esp'] + 4 - STACK))
    def points(pc):
        return [p for p in row['points'] if p['pc'] == hex(pc)]
    def one(pc):
        result = points(pc)
        assert len(result) == 1, hex(pc)
        return result[0]
    frame = bytes.fromhex(one(0x187068)['saved_frame'])
    for i, field in enumerate(FIELDS):
        actual = struct.unpack_from('<I', frame, i * 4)[0]
        expected = {'pushad_esp': fault['esp'] - 5 * 4, 'trap': 14, 'error': 2}.get(field, fault.get(field))
        mask = 0xffff if field in ('gs', 'fs', 'es', 'ds', 'cs') else 0xffffffff
        assert actual & mask == expected & mask, field
    for pc in (0x186d7c, fault_pc):
        assert bytes.fromhex(one(pc)['saved_frame']) == frame
    restored = one(fault_pc)['cpu']
    for field in ('eax', 'ebx', 'ecx', 'edx', 'esi', 'edi', 'ebp', 'esp', 'eflags', 'cs', 'ss', 'ds', 'es', 'fs', 'gs'):
        assert restored[field] == fault[field], field
    assert after['cpu']['eax'] == 0 and after['cpu']['eip'] == STOP and after['cpu']['esp'] == 0x710004
    for field, expected in [('ebx', 0x12341111), ('esi', 0x23452222), ('edi', 0x34563333), ('ebp', 0x45674444)]:
        assert after['cpu'][field] == expected
    for field in ('cs', 'ds', 'es', 'ss', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4'):
        assert after['cpu'][field] == fault[field]
    assert after['cpu']['eflags'] & 0x600 == flags & 0x600
    assert [p['args'] for p in points(0x17b200)] == [[OBJ, VM * 3, 1], [KO, KVA, 1]]
    assert one(0x17269f)['cpu']['eax'] == PAGE and one(0x173f04)['cpu']['eax'] == PG
    assert [p['args'] for p in points(0x19065c)] == [[PMAP, VA, DATA, 3, 0], [KP, KVA, PT, 3, 1]]
    for pc, args in [(0x190cfc, [PMAP, VA]), (0x176164, [KM, KVA, KVA + VM]),
                     (0x174848, [KM, KO, KVA, KVA, KVA + VM]), (0x173ebc, [KO, KVA, VM, 1]),
                     (0x175b2c, [KM, KVA, KVA + VM, 0]), (0x173898, [KM, KVA, KE]), (0x17b6e8, [PG])]:
        assert one(pc)['args'] == args
    kmem = one(0x173d1c)
    assert kmem['args'] == [KM, one(0x190cfc)['cpu']['esp'] - 8, VM]
    find = one(0x174a90)
    assert find['args'][:3] == [KM, 0, 0] and find['args'][4:] == [VM, 1]
    assert B.read_word(regions(find['state']), find['args'][3]) == KVA
    assert B.read_word(regions(one(0x190d7b)['state']), kmem['args'][1]) == KVA
    assert one(0x1735c3)['cpu']['eax'] == one(0x190d7b)['cpu']['eax'] == one(0x1921ec)['cpu']['eax'] == 0
    assert one(0x190de5)['cpu']['eax'] == PT and one(0x190de5)['cpu']['ebx'] == EXT
    zone_ops = [(p['pc'], p['args']) for p in row['points'] if p['pc'] in ('0x16b790', '0x16b84c')]
    assert zone_ops == [('0x16b790', [EZ]), ('0x16b84c', [EZ, KE]), ('0x16b790', [EZ]), ('0x16b790', [XZ])]
    for pc in (0x10ca6c, 0x163320, 0x1631a0, 0x16b3df, 0x190e51, 0x1924a0, 0x17390e, 0x186d51):
        assert hex(pc) not in trace
    assert trace.count('0x172038') == 1 and trace.count('0x190cfc') == 1
    user_entry = points(0x19065c)[0]
    for p in row['points']:
        if user_entry['trace_index'] <= p['trace_index'] <= one(0x173451)['trace_index']:
            for k in ('object', 'page', 'frame'):
                assert p['state'][k] == user_entry['state'][k], k
    assert value(user_entry['state'], 'object', 0x10) == 0
    assert value(user_entry['state'], 'object', 0x44, 'H') == 1
    assert value(user_entry['state'], 'page', 0x20, 'B') == 5
    assert one(0x1729e9)['state']['frame'] == one(fault_pc)['state']['frame'] == bytes(VM).hex()
    assert one(restart_next)['state']['frame'] == after['frame']
    assert one(0x173f92)['state']['new_pt_frame'] == bytes(VM).hex()
    writes = row['writes']
    zero_pcs = list(range(0x1019cc, 0x1019e2, 3))
    zeros = [w for w in writes if w['pc'] in zero_pcs]
    assert [(w['pc'], w['address'], w['width'], w['value']) for w in zeros] == [
        (pc, phys + off + i * 4, 4, 0) for phys in (DATA, PT) for off in range(0, VM, 32) for i, pc in enumerate(zero_pcs)]
    assert [(c['eax'], c['ecx'], c['edx']) for c in row['zero_chunks']] == [
        (0, VM - off, phys + off) for phys in (DATA, PT) for off in range(0, VM, 32)]
    for z in row['zero_chunks']:
        assert trace[z['trace_index']] == '0x1019cc'
    assert [z['trace_index'] for z in row['zero_chunks']] == [i for i, pc in enumerate(trace) if pc == '0x1019cc']
    template = bytearray(0x30)
    template[0x1e], template[0x20] = 0x20, 1
    assert [(w['address'], w['width'], w['value']) for w in writes if w['pc'] == 0x17b384] == [
        (page + off, 4, struct.unpack_from('<I', template, off)[0]) for page in (PAGE, PG) for off in range(0, len(template), 4)]
    assert trace.count('0x17b384') == 2 * (len(template) // 4 + 1)
    for address, sequence in [(0x1f6514, [(0x172041, 1), (0x1738a4, 2)]), (0x1f6504, [(0x1729e9, 1)])]:
        assert [(w['pc'], w['value']) for w in writes if w['address'] == address] == sequence
    assert [(w['pc'], w['address'], w['width'], w['value']) for w in writes if DATA <= w['address'] < DATA + VM and w['pc'] not in zero_pcs] == [(fault_pc, DATA + dest, 1, payload)]
    expected_ptes = [(SHARED + (((KVA + off) >> 12) & 0x3ff) * 4, 4, (PT + off) | 0x203) for off in range(0, VM, HW)]
    expected_ptes += [(PT + (((VA + off) & (0x800000 - 1)) >> 12) * 4, 4, (DATA + off) | 7) for off in range(0, VM, HW)]
    assert [(w['address'], w['width'], w['value']) for w in writes if w['pc'] == 0x190aa7] == expected_ptes
    assert [(w['address'], w['width'], w['value']) for w in writes if w['pc'] == 0x190ef4] == [(ROOTS[target] + i * 4, 4, (PT + i * HW) | 7) for i in range(VM // HW)]
    # Exact before/after retry PTEs, not merely permissive monotonic A/D acceptance.
    pt_before_retry = bytearray(VM)
    for off in range(0, VM, HW):
        put(pt_before_retry, (((VA + off) & (0x800000 - 1)) >> 12) * 4, (DATA + off) | 7)
    assert one(0x186d7c)['state']['new_pt_frame'] == one(fault_pc)['state']['new_pt_frame'] == pt_before_retry.hex()
    assert one(restart_next)['state']['new_pt_frame'] == after['new_pt_frame']
    replay(row)
    return {'target': target, 'function': name, 'destination': dest, 'flags': flags, 'sleepable': sleepable,
            'handler_heads': len(trace), 'zero_dword_stores': len(zeros), 'passed': True}


def main():
    rows = json.loads((HERE / 'fault-new-pt-cases.json').read_text())
    matrix = set(itertools.product(ROOTS, COPY, (0x100, 0x1100), (2, 0x602), (1, 0)))
    assert len(rows) == len(matrix)
    assert {tuple(r[k] for k in ('target', 'function', 'destination', 'flags', 'sleepable')) for r in rows} == matrix
    results = [audit_case(r) for r in rows]
    out = {'cases': results, 'all_passed': True, 'scope': 'independent original byte/state audit of one backend; explicit non-native CPU frame boundary'}
    (HERE / 'independent-audit.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps({'independently_audited': len(results), 'all_passed': True}))


if __name__ == '__main__':
    main()
