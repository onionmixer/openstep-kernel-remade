"""Independent raw Mach-O/trace and byte-state contract audit; no fixture import.

This audits recorded evidence from one backend, not a second hardware execution.
"""
import importlib.util
import itertools
import json
from pathlib import Path
import struct

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('audit24', HERE.parent / 'continuous-review-20260911-24/audit_results.py')
A = importlib.util.module_from_spec(spec)
spec.loader.exec_module(A)
VM, HW, OBJ, PAGE, PMAP, HASH = 0x2000, 0x1000, 0x682000, 0x683000, 0x684000, 0x685000
DESC, EXT, PT, PHYS, END = 0x690000, 0x699000, 0x810000, 0xb00000, 0xc00000
ROOTS = {'A': 0x800000, 'B': 0x802000}
HEADS = {'active': 0x1f6e40, 'inactive': 0x1f64e0, 'free': 0x1f6e48, 'pt': 0x1f7ac8}


def put(data, offset, *values, fmt='I'):
    struct.pack_into('<' + fmt * len(values), data, offset, *values)


def desc(phys):
    return DESC + (phys // VM) * 20


def trace_check(trace, stop, iret=None, open_prefix=False):
    pcs = [int(p, 16) for p in trace]
    assert pcs, 'empty original instruction trace'
    calls = []
    for pc, nxt in zip(pcs, pcs[1:] + [stop]):
        ins = A.instruction(pc)
        if ins.mnemonic == 'call':
            assert ins.operands[0].type == A.capstone.x86.X86_OP_IMM
            assert nxt == ins.operands[0].imm
            calls.append(pc + ins.size)
        elif ins.mnemonic == 'ret':
            assert nxt == (calls.pop() if calls else stop)
        elif ins.mnemonic.startswith('iret'):
            assert pc == 0x186d7c and nxt == iret
        elif ins.group(A.capstone.CS_GRP_JUMP):
            if ins.operands[0].type == A.capstone.x86.X86_OP_IMM:
                allowed = {ins.operands[0].imm}
                if ins.mnemonic != 'jmp':
                    allowed.add(pc + ins.size)
                assert nxt in allowed, (hex(pc), hex(nxt))
            else:
                assert pc == 0x19211a
                assert nxt == struct.unpack('<I', A.original(0x192124 + (14 - 1) * 4, 4))[0]
        elif pc in (0x17b150, 0x17b384):
            assert ins.bytes == bytes.fromhex('f3a5') and nxt in (pc, pc + ins.size)
        else:
            assert nxt == pc + ins.size, (hex(pc), hex(nxt), ins.mnemonic)
    assert not calls or open_prefix


def metadata(state, root, phase):
    # Independent anonymous single-object lifecycle model, from original offsets.
    allocated = phase in ('allocated', 'zero', 'pmap_entry', 'mapped', 'returned', 'final')
    mapped = phase in ('mapped', 'returned', 'final')
    returned = phase in ('returned', 'final')
    entered = phase not in ('before', 'trap')
    obj = bytearray(0x58)
    put(obj, 0, PAGE if allocated else OBJ, PAGE if allocated else OBJ)
    put(obj, 0x10, int(phase in ('lookup', 'allocated', 'zero')), VM * 4)
    put(obj, 0x18, 2 if entered and not returned else 1, int(allocated), fmt='H')
    put(obj, 0x44, int(entered and not returned), fmt='H')
    put(obj, 0x54, VM * 3 if allocated else 0)
    assert state['object'] == obj.hex(), ('object', phase)
    page = bytearray(0x30)
    if returned:
        put(page, 0, HEADS['active'], HEADS['active'])
    elif not allocated:
        put(page, 0, HEADS['free'], HEADS['free'])
    put(page, 8, OBJ, OBJ, 0, OBJ, VM * 3)
    page[0x1e] = 0x22 if returned else 0x20 if allocated else 0x28
    page[0x20] = 4 if returned else 5 if allocated else 1
    put(page, 0x24, PHYS)
    assert state['page'] == page.hex(), ('page', phase)
    pmap = bytearray(0x1c)
    put(pmap, 0, root, root, 1, 0, int(mapped), 0, 1)
    assert state['pmap'] == pmap.hex(), ('pmap', phase)
    ext = bytearray(0x20)
    put(ext, 0, HEADS['pt'], HEADS['pt'], desc(PT), PT, PMAP, 0)
    put(ext, 0x18, int(mapped), fmt='H')
    assert state['extension'] == ext.hex(), ('extension', phase)
    arena = bytearray(END // VM * 20)
    put(arena, desc(PT) - DESC + 0xc, EXT)
    if mapped:
        put(arena, desc(PHYS) - DESC, 0, PMAP, 0x600000)
    assert state['descriptor_arena'] == arena.hex(), ('descriptor_arena', phase)
    buckets = bytearray(8 * 8)
    if allocated:
        put(buckets, ((OBJ + 3) & 7) * 8 + 4, PAGE)
    assert state['buckets'] == buckets.hex(), ('buckets', phase)
    queues = {k: [h, h] for k, h in HEADS.items()}
    queues['pt'] = [EXT, EXT]
    if not allocated:
        queues['free'] = [PAGE, PAGE]
    if returned:
        queues['active'] = [PAGE, PAGE]
    assert state['queues'] == queues, ('queues', phase)
    g = state['globals']
    assert g['active_count'] == int(returned) and g['free_count'] == int(not allocated)
    assert g['pt_count'] == 1 and g['zero_count'] == int(phase in ('pmap_entry', 'mapped', 'returned', 'final'))
    assert g['fault_count'] == int(entered)
    for key in ('inactive_count', 'queue_lock', 'free_lock', 'ipl', 'reserved', 'minimum', 'target', 'inactive_target', 'object_cache_lock', 'exception_flag'):
        assert g[key] == 0, (key, phase)


def audit_case(row):
    target, name, dest, flags = row['target'], row['function'], row['destination'], row['flags']
    assert target in ROOTS and name in ('_copyout', '_copyoutmsg') and dest in (0x100, 0x1100) and flags in (2, 0x602)
    before, after, handler, fixture = row['before'], row['after'], row['handler'], row['fixture']
    root = ROOTS[target]
    assert row['failure'] is None and handler['error'] is None and not handler['interrupts']
    assert row['cpu_frame_injected'] and not row['native_frame_generation_verified'] and row['error_frame_input'] == 2
    assert fixture['vm_size'] == VM and fixture['page_mask'] == VM - 1
    assert fixture['pt_pair'] == PT and fixture['frame'] == PHYS
    assert fixture['pt_descriptor'] == desc(PT) and fixture['frame_descriptor'] == desc(PHYS)
    assert fixture['descriptor_arena_size'] == END // VM * 20
    globals_expected = {0x1f7ab0: DESC, 0x1f7ab8: 0, 0x1f7ae0: VM // HW, 0x1f7ae8: VM // 4 * HW,
                        0x1e247c: 0, 0x1e2480: END, 0x1e0d0c: VM, 0x1e89ec: VM - 1,
                        0x1f7438: HASH, 0x1f743c: 7, 0x1f6ea4: VM.bit_length() - 1}
    for addr, value in globals_expected.items():
        assert before['contract_globals'][hex(addr)] == value
    assert before['contract_globals']['0x1f63f0'] != PMAP
    assert after['contract_globals'] == before['contract_globals']
    metadata(before, root, 'before')
    metadata(after, root, 'final')
    assert before['copy_buffer_hashes'] == after['copy_buffer_hashes'] == A.expected_hashes(target, 1, dest, 0)
    dirty_frame = bytes((i * 19 + (i >> 7) + 0x53) & 0xff for i in range(VM))
    assert bytes.fromhex(before['frame']) == dirty_frame
    final = bytearray(VM)
    final[dest] = (0x100 * 17 + (0x100 >> 8) * 29 + 0xc7) & 0xff
    assert bytes.fromhex(after['frame']) == final
    assert before['pt_pair'] == bytes(VM).hex()
    assert after['map'] == before['map'] and after['entry'] == before['entry']
    # Entire target user half is empty except the two prepared PDEs; no count shortcut.
    words = struct.unpack('<1024I', bytes.fromhex(before['roots'][target]))
    assert words[0] == PT | 7 and words[1] & ~0x20 == (PT + HW) | 7
    assert all(x == 0 for x in words[2:0xc0000000 >> 22])
    for other in ROOTS:
        old = struct.unpack('<1024I', bytes.fromhex(before['roots'][other]))
        new = struct.unpack('<1024I', bytes.fromhex(after['roots'][other]))
        if other != target:
            assert old == new
        else:
            assert [x & ~0x20 for x in old] == [x & ~0x20 for x in new]
    # Contract for preserved direct aliases; these recorded walks are not a second full walker.
    alias_targets = (PHYS, PHYS + VM - 1, PT, PT + VM - 1, DESC, EXT, 0x710000)
    assert [int(w['linear'], 16) for w in fixture['direct_aliases']] == [0xc0000000 + a for a in alias_targets]
    for w in fixture['direct_aliases']:
        assert w['present'] and w['writable'] and not w['user']
        assert int(w['linear'], 16) - 0xc0000000 == int(w['physical'], 16)
        linear = int(w['linear'], 16)
        assert int(w['pde_address'], 16) == root + (linear >> 22) * 4
        pde, pte = int(w['pde'], 16), int(w['pte'], 16)
        assert pde & 3 == 3 and pte & 3 == 3 and not (pde & pte & 4)
        assert int(w['pte_address'], 16) == (pde & ~0xfff) + ((linear >> 12) & 0x3ff) * 4
        assert int(w['physical'], 16) == (pte & ~0xfff) + (linear & 0xfff)
    assert all(r['va'] >= 0xc0000000 for r in fixture['pre_fault_frame_references'] if r['root'] == target)
    fault = row['fault']['after']
    assert row['fault']['error'] is None and len(row['fault']['interrupts']) == 1
    assert row['fault']['interrupts'][0]['vector'] == 14 and row['fault']['interrupts'][0]['snapshot'] == fault
    fault_pc = {'_copyout': 0x189d1b, '_copyoutmsg': 0x189ec4}[name]
    entry = {'_copyout': 0x189cec, '_copyoutmsg': 0x189e8c}[name]
    assert fault['eip'] == fault_pc and fault['cr2'] == 0x600000 + dest and fault['cr3'] == root
    assert row['fault']['trace'][0] == hex(entry)
    assert row['fault']['trace'][-1] == hex(fault_pc)
    # Last faulting instruction is observed but not committed; audit prefix up to that head.
    trace_check(row['fault']['trace'][:-1], fault_pc)
    trace_check(handler['trace'], 0x740000, fault_pc)
    assert handler['trace'][0] == '0x1861cc'
    required = (0x172038, 0x17b200, 0x17b99c, 0x191428, 0x1019c0, 0x190998, 0x1909d5, 0x190f24, 0x186d7c, fault_pc)
    positions = [handler['trace'].index(hex(p)) for p in required]
    assert positions == sorted(positions) and all(handler['trace'].count(hex(p)) == 1 for p in required)
    for pc in (0x190cfc, 0x17a248, 0x16b790, 0x1924a0, 0x163320, 0x165328, 0x10ca6c, 0x1908b4, 0x190968,
               0x1631a0, 0x17a338, 0x18b59b, 0x18b5dc, 0x18b5ef):
        assert hex(pc) not in handler['trace']
    phases = [(0x187068, 'trap'), (0x1720d6, 'lookup'), (0x17269f, 'allocated'), (0x1729e9, 'zero'),
              (0x19065c, 'pmap_entry'), (0x173451, 'mapped'), (0x1921ec, 'returned'), (0x186d7c, 'returned'), (fault_pc, 'returned')]
    assert [int(m['pc'], 16) for m in row['milestones']] == [p for p, phase in phases]
    points = {int(m['pc'], 16): m for m in row['milestones']}
    for pc, phase in phases:
        st = points[pc]['state']
        metadata(st, root, phase)
        assert st['contract_globals'] == before['contract_globals']
        assert st['copy_buffer_hashes'] == before['copy_buffer_hashes']
        assert st['frame'] == (dirty_frame if phase in ('trap', 'lookup', 'allocated') else bytes(VM)).hex()
    assert points[0x1720d6]['state']['cpu']['eax'] == 0
    assert points[0x17269f]['state']['cpu']['eax'] == PAGE
    assert points[0x19065c]['args'] == [PMAP, 0x600000, PHYS, 3, 0]
    assert points[0x1921ec]['state']['cpu']['eax'] == 0
    raw = bytes.fromhex(points[0x187068]['saved_frame'])
    fields = ('gs', 'fs', 'es', 'ds', 'edi', 'esi', 'ebp', 'pushad_esp', 'ebx', 'edx', 'ecx', 'eax', 'trap', 'error', 'eip', 'cs', 'eflags')
    assert len(raw) == len(fields) * 4
    for i, field in enumerate(fields):
        value = struct.unpack_from('<I', raw, i * 4)[0]
        expected = {'pushad_esp': fault['esp'] - 5 * 4, 'trap': 14, 'error': 2}.get(field, fault.get(field))
        mask = 0xffff if field in ('gs', 'fs', 'es', 'ds', 'cs') else 0xffffffff
        assert value & mask == expected & mask
    for pc in (0x186d7c, fault_pc):
        assert bytes.fromhex(points[pc]['saved_frame']) == raw
    for field in ('eax', 'ebx', 'ecx', 'edx', 'esi', 'edi', 'ebp', 'esp', 'eflags', 'cs', 'ds', 'es', 'ss', 'fs', 'gs'):
        assert points[fault_pc]['state']['cpu'][field] == fault[field]
    assert after['cpu']['eax'] == 0 and after['cpu']['eip'] == 0x740000 and after['cpu']['esp'] == 0x710004
    for field, value in (('ebx', 0x12341111), ('esi', 0x23452222), ('edi', 0x34563333), ('ebp', 0x45674444)):
        assert after['cpu'][field] == value
    for field in ('cs', 'ds', 'es', 'ss', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4'):
        assert after['cpu'][field] == fault[field]
    assert after['cpu']['eflags'] & 0x600 == flags & 0x600
    assert after['recover'] == {'_copyout': 0x189e70, '_copyoutmsg': 0x18a018}[name] and after['uthread'] == 'a5'
    # REP must visit every original template DWORD then ECX=0; self-edge alone is insufficient.
    rep = row['allocator_rep']
    assert len(rep) == 0x30 // 4 + 1 and handler['trace'].count('0x17b384') == len(rep)
    for i, r in enumerate(rep):
        assert (r['ecx'], r['esi'], r['edi']) == (0x30 // 4 - i, 0x1f7440 + i * 4, PAGE + i * 4)
        assert r['eflags'] & 0x400 == 0
    assert row['zero_chunks'] == [{'eax': 0, 'ecx': VM - off, 'edx': PHYS + off} for off in range(0, VM, 0x20)]
    zero_pcs = tuple(range(0x1019cc, 0x1019e2, 3))
    zero_writes = [w for w in row['writes'] if w['pc'] in zero_pcs]
    expected_zero = [{'pc': pc, 'address': PHYS + off + i * 4, 'width': 4, 'value': 0}
                     for off in range(0, VM, 0x20) for i, pc in enumerate(zero_pcs)]
    assert zero_writes == expected_zero
    stores = [w for w in row['writes'] if w['pc'] == 0x190aa7]
    pte_base = PT + HW + ((0x600000 >> 12) & 0x3ff) * 4
    assert stores == [{'pc': 0x190aa7, 'address': pte_base + i * 4, 'width': 4, 'value': (PHYS + i * HW) | 7} for i in range(VM // HW)]
    ptes = bytearray(VM)
    for i in range(VM // HW):
        put(ptes, pte_base - PT + i * 4, (PHYS + i * HW) | 7)
    assert points[0x173451]['state']['pt_pair'] == ptes.hex()
    committed = bytearray(ptes)
    put(committed, pte_base - PT + (dest // HW) * 4, (PHYS + (dest // HW) * HW) | 0x67)
    assert after['pt_pair'] == committed.hex()
    expected_pv = [(0x1909de, desc(PHYS) + 8, 4, 0x600000), (0x1909e4, desc(PHYS) + 4, 4, PMAP),
                   (0x1909e7, desc(PHYS), 4, 0), (0x190f2e, PMAP + 0x10, 4, 1), (0x190f7d, EXT + 0x18, 2, 1)]
    pv_pcs = {p for p, a, w, v in expected_pv}
    assert [(w['pc'], w['address'], w['width'], w['value']) for w in row['writes'] if w['pc'] in pv_pcs] == expected_pv
    payload = [w for w in row['writes'] if PHYS <= w['address'] < PHYS + VM and w['pc'] not in zero_pcs]
    assert payload == [{'pc': fault_pc, 'address': PHYS + dest, 'width': 1, 'value': final[dest]}]
    # Reject all CPU stores outside the documented stack/metadata/target regions.
    allowed = [(0x70f020, 0x710004), (OBJ, OBJ + 0x58), (PAGE, PAGE + 0x30), (PMAP, PMAP + 0x1c),
               (0x680400, 0x680450), (0x680600, 0x68062c), (HASH, HASH + 64), (DESC, DESC + END // VM * 20),
               (EXT, EXT + 0x20), (PT, PT + VM), (PHYS, PHYS + VM), (0x680868, 0x680869)]
    allowed += [(h, h + 8) for h in HEADS.values()]
    allowed += [(a, a + 4) for a in (0x1e7714, 0x1f64e8, 0x1f6504, 0x1f6514, 0x1f6e34, 0x1f6e38, 0x1f6f2c, 0x1f7418, 0x1f74d4)]
    pcs = {int(p, 16) for p in handler['trace']}
    for w in row['writes']:
        assert w['pc'] in pcs
        assert any(a <= w['address'] and w['address'] + w['width'] <= b for a, b in allowed), w
    seed = fixture['seed_calls']
    assert [(s['entry'], s['args']) for s in seed] == [('0x17b134', [PAGE, OBJ, VM * 3, PHYS]), ('0x17b540', [PAGE])]
    for s in seed:
        obs = s['observation']
        assert obs['trace'] and obs['trace'][0] == s['entry']
        assert obs['error'] is None and not obs['interrupts']
        assert obs['after']['eip'] == 0x740000 and obs['after']['esp'] == 0x710000 - 0x100 + 4
        for field, value in (('ebx', 0x12341111), ('esi', 0x23452222), ('edi', 0x34563333), ('ebp', 0x45674444)):
            assert obs['after'][field] == value
        trace_check(obs['trace'], 0x740000)
    assert fixture['startup_prefix']['entry'] == '0x17aa08'
    prefix = fixture['startup_prefix']['observation']
    assert fixture['startup_prefix']['args'] == [] and prefix['trace'] and prefix['trace'][0] == '0x17aa08'
    assert prefix['error'] is None and not prefix['interrupts'] and prefix['after']['eip'] == 0x17aade
    trace_check(prefix['trace'], 0x17aade, open_prefix=True)
    reload = fixture['original_pre_fault_cr3_reload']
    assert reload['trace'] == ['0x18d3ef'] and reload['error'] is None and not reload['interrupts']
    assert reload['after']['eip'] == 0x18d3f2 and reload['after']['cr3'] == root
    assert A.instruction(0x18d3ef).mnemonic == 'mov' and A.instruction(0x18d3ef).op_str == 'cr3, eax'
    return True


def main():
    rows = json.loads((HERE / 'missing-page-cases.json').read_text())
    wanted = set(itertools.product(ROOTS, ('_copyout', '_copyoutmsg'), (0x100, 0x1100), (2, 0x602)))
    assert {(r['target'], r['function'], r['destination'], r['flags']) for r in rows} == wanted and len(rows) == len(wanted)
    for row in rows:
        audit_case(row)
    summary = {'case_matrix_verified': len(rows), 'original_missing_page_to_retry': len(rows),
               'full_metadata_byte_contracts': len(rows), 'original_zero_fill_stores': sum(len(r['zero_chunks']) * 8 for r in rows),
               'original_managed_pte_stores': sum(w['pc'] == 0x190aa7 for r in rows for w in r['writes']),
               'mismatches': [], 'native_cpu_frame_verified': False, 'whole_vm_verified': False, 'independent_hardware_backend': False}
    (HERE / 'independent-audit.json').write_text(json.dumps(summary, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
