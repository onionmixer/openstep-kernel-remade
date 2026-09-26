"""Independent PT lifecycle model and original-byte transfer audit; no executor import."""
import importlib.util
import itertools
import json
from pathlib import Path
import struct

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('audit29', HERE.parent / 'continuous-review-20260911-29/audit_results.py')
B = importlib.util.module_from_spec(spec)
spec.loader.exec_module(B)
A = B.A
VM, HW, OBJ, PAGE, PMAP, HASH, DESC, EXT, PT, PHYS, END = B.VM, B.HW, B.OBJ, B.PAGE, B.PMAP, B.HASH, B.DESC, B.EXT, B.PT, B.PHYS, B.END
ROOTS = B.ROOTS
KM, KE, ACTIVE, FREE, VAS = 0x69a000, 0x69a100, 0x1f7ac8, 0x1f7ad8, (0x600000, 0xa00000)
put, desc = B.put, B.desc


def words(data):
    raw = bytes.fromhex(data)
    return list(struct.unpack('<' + 'I' * (len(raw) // 4), raw))


def lock_init_trace(trace):
    """Specific lock_init(map,1) -> bzero(map,12) -> memset jump-table contract."""
    assert trace and trace[0] == '0x15b54c' and trace.count('0x101669') == 1
    length_push = A.instruction(0x15b553)
    assert length_push.mnemonic == 'push' and length_push.operands[0].imm == 12
    target = struct.unpack('<I', A.original(0x101670 + (length_push.operands[0].imm - 1) * 4, 4))[0]
    pcs, calls = [int(p, 16) for p in trace], []
    for pc, nxt in zip(pcs, pcs[1:] + [0x740000]):
        ins = A.instruction(pc)
        if ins.mnemonic == 'call':
            assert ins.operands[0].type == A.capstone.x86.X86_OP_IMM and nxt == ins.operands[0].imm
            calls.append(pc + ins.size)
        elif ins.mnemonic == 'ret':
            assert nxt == (calls.pop() if calls else 0x740000)
        elif ins.group(A.capstone.CS_GRP_JUMP):
            if ins.operands[0].type == A.capstone.x86.X86_OP_IMM:
                assert nxt in ({ins.operands[0].imm} if ins.mnemonic == 'jmp' else {ins.operands[0].imm, pc + ins.size})
            else:
                assert pc == 0x101669 and nxt == target
        else:
            assert nxt == pc + ins.size
    assert not calls


def shape(op, entry, args, label, partial=False, probe=None):
    assert (op['entry'], op['args'], op['label']) == (hex(entry), args, label)
    assert op['probe_va'] == probe and op['repeat_boundary'] == partial
    assert op['prepared_stack'] == [0x740000] + args
    assert op['before']['cpu']['esp'] == 0x710000 - 0x100
    obs = op['observation']
    assert op['failure'] is None and obs['error'] is None and not obs['interrupts']
    trace = obs['trace']
    assert trace and trace[0] == hex(entry)
    if partial:
        assert trace[-1] == '0x190cfc' and trace[-2] == '0x1907ac'
        B.trace_check(trace[:-1], 0x190cfc, open_prefix=True)
        assert obs['after']['eip'] == 0x190cfc
    else:
        stop = entry + A.instruction(entry).size if probe is not None else 0x740000
        assert op['stop'] == hex(stop)
        B.trace_check(trace, stop)
        assert obs['after']['eip'] == stop
        assert obs['after']['esp'] == 0x710000 - 0x100 + (0 if probe is not None else 4)
        for field, value in (('ebx', 0x12341111), ('esi', 0x23452222), ('edi', 0x34563333), ('ebp', 0x45674444)):
            assert obs['after'][field] == value
    assert obs['after'] == op['after']['cpu']
    for field in ('cs', 'ds', 'es', 'ss', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4'):
        assert op['before']['cpu'][field] == op['after']['cpu'][field]
    for pc in (0x10ca6c, 0x16b790, 0x178894, 0x173ebc, 0x163320, 0x1631a0):
        assert hex(pc) not in trace
    assert op['before']['frame'] == op['after']['frame']
    assert op['before']['copy_buffer_hashes'] == op['after']['copy_buffer_hashes']
    allowed = [(0x70f020, 0x710004), (PMAP, PMAP + 0x1c), (EXT, EXT + 0x20), (PT, PT + VM),
               (DESC, DESC + END // VM * 20), (KM, KM + 0x50)]
    active_root = op['before']['cpu']['cr3']
    allowed += [(active_root, active_root + 0xc00)]
    allowed += [(a, a + 4) for a in (0x1e7714, 0x1f7ac0, 0x1f7ac8, 0x1f7acc, 0x1f7ad4, 0x1f7ad8, 0x1f7adc, 0x1f7af0, 0x1f7af4)]
    pcs = {int(p, 16) for p in trace}
    for w in op['writes']:
        assert w['pc'] in pcs
        assert any(a <= w['address'] and w['address'] + w['width'] <= b for a, b in allowed), w


def data_state(state, target):
    expected_globals = {0x1f7ab0: DESC, 0x1f7ab8: 0, 0x1f7ae0: VM // HW, 0x1f7ae8: 0x800000,
                        0x1e247c: 0, 0x1e2480: END, 0x1e0d0c: VM, 0x1e89ec: VM - 1,
                        0x1f7438: HASH, 0x1f743c: 7, 0x1f6ea4: VM.bit_length() - 1}
    for address, value in expected_globals.items():
        assert state['contract_globals'][hex(address)] == value, hex(address)
    assert state['pt_contract']['kernel_pmap_address'] == state['contract_globals']['0x1f63f0']
    assert state['pt_contract']['kernel_pmap_address'] != PMAP
    assert words(state['kernel_pmap'])[0] == state['pt_contract']['kernel_root']
    obj = bytearray(0x58)
    put(obj, 0, PAGE, PAGE)
    put(obj, 0x14, VM * 4)
    put(obj, 0x18, 1, 1, fmt='H')
    put(obj, 0x54, VM * 3)
    assert state['object'] == obj.hex()
    page = bytearray(0x30)
    put(page, 8, OBJ, OBJ, 0, OBJ, VM * 3)
    page[0x1e], page[0x20] = 0x20, 5
    put(page, 0x24, PHYS)
    assert state['page'] == page.hex()
    buckets = bytearray(64)
    put(buckets, ((OBJ + 3) & 7) * 8 + 4, PAGE)
    assert state['buckets'] == buckets.hex()
    assert state['frame'] == bytes((i * 19 + (i >> 7) + 0x53) & 0xff for i in range(VM)).hex()
    assert state['copy_buffer_hashes'] == A.expected_hashes(target, 1, 0x100, 0)
    assert state['recover'] == 0 and state['uthread'] == 'a5'
    for k in ('active_count', 'inactive_count', 'free_count', 'queue_lock', 'free_lock', 'ipl', 'zero_count', 'fault_count'):
        assert state['globals'][k] == 0
    for k, h in (('active', 0x1f6e40), ('inactive', 0x1f64e0), ('free', 0x1f6e48)):
        assert state['queues'][k] == [h, h]


def pt_state(state, target, active, mapped, va, wired, referenced, residue, total=1):
    data_state(state, target)
    pm = bytearray(0x1c)
    put(pm, 0, ROOTS[target], ROOTS[target], 1, 0, int(mapped), wired if mapped else 0, 1)
    assert state['pmap'] == pm.hex()
    arena = bytearray(END // VM * 20)
    extension = bytearray(0x20)
    if total:
        kp = state['pt_contract']['kernel_pmap_address']
        assert kp != PMAP
        put(arena, desc(PT) - DESC, 0, kp, PT, EXT)
        h = ACTIVE if active else FREE
        put(extension, 0, h, h, desc(PT), PT, PMAP, va & -0x800000)
        put(extension, 0x18, int(mapped), wired if mapped else 0, fmt='H')
        if va:
            put(arena, desc(PHYS) - DESC, 0, PMAP if mapped else 0, va if mapped or referenced else 0)
        arena[desc(PHYS) - DESC + 0x10] = 2 if referenced else 0
    assert state['extension'] == extension.hex()
    assert state['descriptor_arena'] == arena.hex()
    assert state['pt_alloc_count'] == total and state['globals']['pt_count'] == int(active)
    assert state['pt_free_count'] == int(bool(total) and not active)
    assert state['queues']['pt'] == ([EXT, EXT] if active else [ACTIVE, ACTIVE])
    assert state['pt_free_queue'] == ([EXT, EXT] if total and not active else [FREE, FREE])
    table = bytearray(VM)
    if residue:
        put(table, 0, 0xdeadbe00)
    if mapped:
        off = ((va & (0x800000 - 1)) >> 12) * 4
        for i in range(VM // HW):
            put(table, off + i * 4, (PHYS + i * HW) | 7 | (wired << 9))
    # PTE A state is checked per operation, rather than conflating it with saved pg_desc reference.
    actual = words(state['pt_pair'])
    wanted = list(struct.unpack('<2048I', table))
    for a, b in zip(actual, wanted):
        assert a == b or (mapped and b & 1 and a == b | 0x20)
        assert not (a & 1 and a & 0x40), 'dirty path excluded'


def transitions(op, target):
    before, after = op['before'], op['after']
    # Replay observed CPU stores to root/PTE bytes; hardware A is allowed only for FS reads or kernel PDEs.
    for name, root in ROOTS.items():
        if name != target:
            assert before['roots'][name] == after['roots'][name]
        expected = bytearray.fromhex(before['roots'][name])
        for w in op['writes']:
            if root <= w['address'] < root + HW:
                off = w['address'] - root
                expected[off:off + w['width']] = w['value'].to_bytes(w['width'], 'little')
        actual = bytes.fromhex(after['roots'][name])
        for off in range(0, HW, 4):
            a, b = struct.unpack_from('<I', actual, off)[0], struct.unpack_from('<I', expected, off)[0]
            allow_a = name == target and (off >= 0xc00 or (op['probe_va'] is not None and off == (op['probe_va'] >> 22) * 4))
            assert a == b or (allow_a and b & 1 and a == b | 0x20)
    expected = bytearray.fromhex(before['pt_pair'])
    for w in op['writes']:
        if PT <= w['address'] < PT + VM:
            off = w['address'] - PT
            expected[off:off + w['width']] = w['value'].to_bytes(w['width'], 'little')
    if op['probe_va'] is not None:
        off = ((op['probe_va'] & (0x800000 - 1)) >> 12) * 4
        put(expected, off, struct.unpack_from('<I', expected, off)[0] | 0x20)
    assert expected.hex() == after['pt_pair']
    for k in ('object', 'page', 'map', 'entry', 'kernel_entry', 'kernel_pmap', 'pt_contract', 'contract_globals'):
        assert before[k] == after[k], k


def audit_case(row):
    target, fixture = row['target'], row['fixture']
    assert target in ROOTS and fixture['vm_size'] == VM
    inherited = [fixture['startup_prefix']] + fixture['seed_calls']
    expected_inherited = [(0x17aa08, [], 0x17aade), (0x17b134, [PAGE, OBJ, VM * 3, PHYS], 0x740000),
                          (0x17b540, [PAGE], 0x740000)]
    assert len(inherited) == len(expected_inherited)
    for item, (entry, args, stop) in zip(inherited, expected_inherited):
        obs = item['observation']
        assert item['entry'] == hex(entry) and item['args'] == args
        assert obs['trace'] and obs['trace'][0] == hex(entry) and obs['error'] is None and not obs['interrupts']
        assert obs['after']['eip'] == stop
        B.trace_check(obs['trace'], stop, open_prefix=stop == 0x17aade)
    reload = fixture['original_pre_fault_cr3_reload']
    assert reload['trace'] == ['0x18d3ef'] and reload['error'] is None and not reload['interrupts']
    assert reload['after']['cr3'] == ROOTS[target] and reload['after']['eip'] == 0x18d3f2
    alloc = fixture['data_allocation']
    assert alloc['entry'] == '0x17b200' and alloc['args'] == [OBJ, VM * 3, 1]
    obs = alloc['observation']
    assert obs['trace'] and obs['trace'][0] == '0x17b200' and obs['error'] is None and not obs['interrupts']
    assert obs['after']['eax'] == PAGE and obs['after']['eip'] == 0x740000
    B.trace_check(obs['trace'], 0x740000)
    ops = row['operations']
    for prev, nxt in zip(ops, ops[1:]):
        assert {k: v for k, v in prev['after'].items() if k != 'cpu'} == {k: v for k, v in nxt['before'].items() if k != 'cpu'}
    for op in ops:
        assert op['before']['cpu']['cr3'] == ROOTS[target]
        transitions(op, target)
    if row['kind'] == 'reuse_cycle':
        wired, residue = row['wired'], row['residue']
        assert wired in (0, 1) and type(residue) is bool and fixture['register_backing']
        assert len(ops) == 9
        backs = fixture['kernel_pt_backing']
        assert [int(w['linear'], 16) for w in backs] == [PT + off for off in range(0, VM, HW)]
        for w in backs:
            assert w['present'] and w['writable'] and not w['user']
            assert int(w['pte'], 16) & 0x200 and int(w['physical'], 16) == int(w['linear'], 16)
            assert int(w['pde_address'], 16) == fixture['kernel_root'] + (int(w['linear'], 16) >> 22) * 4
        first = ops[0]
        shape(first, 0x190f90, [PMAP, VAS[0], 0, 0, 1], 'retire_empty')
        pt_state(first['before'], target, True, False, 0, wired, False, residue)
        pt_state(first['after'], target, False, False, 0, wired, False, residue)
        assert words(first['before']['roots'][target])[:2] == [PT | 7, (PT + HW) | 7]
        assert all(v == 0 for v in words(first['before']['roots'][target])[2:0x300])
        assert words(first['before']['kernel_pmap'])[4:6] == [1, 1]
        previous_va, referenced = 0, False
        for i, va in enumerate(VAS):
            enter, probe, skipped, remove = ops[1 + i * 4:5 + i * 4]
            shape(enter, 0x19065c, [PMAP, va, PHYS, 3, wired], 'enter')
            shape(probe, 0x18a197, [], 'fs_read', probe=va + 0x100)
            section = va & -0x800000
            shape(skipped, 0x18fa44, [PMAP, section, section + VM], 'remove_nonpresent')
            shape(remove, 0x18fa44, [PMAP, va, va + VM], 'remove')
            pt_state(enter['before'], target, False, False, previous_va, wired, referenced, residue)
            pt_state(enter['after'], target, True, True, va, wired, referenced, residue)
            pt_state(probe['after'], target, True, True, va, wired, referenced, residue)
            pt_state(skipped['after'], target, True, True, va, wired, referenced, residue)
            pt_state(remove['after'], target, False, False, va, wired, True, residue)
            assert probe['writes'] == [] and probe['observation']['trace'] == ['0x18a197']
            ins = A.instruction(0x18a197)
            assert ins.mnemonic == 'mov' and ins.op_str == 'edx, dword ptr fs:[eax]'
            assert probe['before']['cpu']['eax'] == va + 0x100
            assert probe['after']['cpu']['edx'] == int.from_bytes(bytes.fromhex(probe['before']['frame'])[0x100:0x104], 'little')
            assert len(enter['expand_visits']) == 1 and enter['expand_visits'][0]['pde'] & 1 == 0
            assert [m['args'] for m in enter['points'] if m['pc'] == '0x190cfc'] == [[PMAP, va]]
            assert [m['cpu']['eax'] for m in enter['points'] if m['pc'] == '0x190d4d'] == [EXT]
            assert [m['cpu']['eax'] for m in enter['points'] if m['pc'] == '0x190e20'] == [PT]
            for pc in (0x173d1c, 0x16b790, 0x17b99c):
                assert hex(pc) not in enter['observation']['trace']
            pdi_addr = ROOTS[target] + (section >> 22) * 4
            assert [w for w in enter['writes'] if w['pc'] == 0x190ef4] == [
                {'pc': 0x190ef4, 'address': pdi_addr + j * 4, 'width': 4, 'value': (PT + j * HW) | 7} for j in range(VM // HW)]
            pte_addr = PT + ((va - section) >> 12) * 4
            assert [w for w in enter['writes'] if w['pc'] == 0x190aa7] == [
                {'pc': 0x190aa7, 'address': pte_addr + j * 4, 'width': 4, 'value': (PHYS + j * HW) | 7 | (wired << 9)} for j in range(VM // HW)]
            assert [w for w in remove['writes'] if w['pc'] == 0x18f96e] == [
                {'pc': 0x18f96e, 'address': pte_addr + j * 4, 'width': 4, 'value': 0} for j in range(VM // HW)]
            assert remove['invalidations'] == [va + j * HW for j in range(VM // HW)]
            skip_trace = skipped['observation']['trace']
            at = skip_trace.index('0x18f8b4')
            assert skip_trace[at + 1] == '0x18f8b7' and skip_trace[at + 2] == '0x18f8b9'
            assert skip_trace.count('0x18f8b9') == 1
            for pc in (0x18f8d0, 0x18f96e, 0x18f9bc, 0x191040):
                assert hex(pc) not in skip_trace
            assert [p['args'] for p in skipped['points'] if p['pc'] == '0x190f90'] == [[PMAP, section, 0, 0, 1]]
            assert skipped['invalidations'] == [section + j * HW for j in range(VM // HW)]
            assert skipped['after']['tlb_counters'] == [i * 2 + 1, i * 2 + 1]
            assert remove['after']['tlb_counters'] == [(i + 1) * 2, (i + 1) * 2]
            previous_va, referenced = va, True
        for op in (first, ops[4], ops[8]):
            clears = [w for w in op['writes'] if w['pc'] == 0x191040]
            va = VAS[0] if op is first else op['args'][1]
            addr = ROOTS[target] + ((va & -0x800000) >> 22) * 4
            original_root = bytes.fromhex(op['before']['roots'][target])
            assert clears == [{'pc': 0x191040, 'address': addr + i * 4, 'width': 1,
                               'value': original_root[addr - ROOTS[target] + i * 4] & 0xfe} for i in range(VM // HW)]
        assert all(op['before']['kernel_map'] == op['after']['kernel_map'] for op in ops)
    else:
        assert row['kind'] == 'new_va_failure' and len(ops) == 1 and not fixture['register_backing']
        assert fixture['kernel_pt_backing'] == []
        partial = row['entry_kind'] == 'pmap_enter'
        assert row['entry_kind'] in ('expand', 'pmap_enter') and row['caller_return_verified'] == (not partial)
        op = ops[0]
        shape(op, 0x19065c if partial else 0x190cfc, [PMAP, VAS[0], PHYS, 3, 0] if partial else [PMAP, VAS[0]],
              'caller_rechecks_failure' if partial else 'new_va_failure', partial=partial)
        for state in (op['before'], op['after']):
            pt_state(state, target, False, False, 0, 0, False, False, total=0)
            assert state['pt_contract']['kernel_map'] == KM and state['pt_contract']['kernel_object'] == OBJ
            assert all(v == 0 for v in words(state['roots'][target])[:0x300])
        expected_map = bytearray(0x50)
        put(expected_map, 0, 0xffffffff, 8 << 16, 0)
        put(expected_map, 0xc, KE, KE, 0x820000, 0x820000 + VM, 1)
        put(expected_map, 0x28, VM)
        put(expected_map, 0x38, KE, 0, KE)
        assert op['before']['kernel_map'] == expected_map.hex()
        entry = bytearray(0x2c)
        put(entry, 0, KM + 0xc, KM + 0xc, 0x820000, 0x820000 + VM)
        assert op['before']['kernel_entry'] == entry.hex()
        completed = 2 if partial else 1
        put(expected_map, 0x4c, completed)
        assert op['after']['kernel_map'] == expected_map.hex()
        trace = op['observation']['trace']
        assert len(op['expand_visits']) == completed + int(partial)
        assert all(v['pde'] & 1 == 0 for v in op['expand_visits'])
        for pc, eax in ((0x173d60, 3), (0x173d88, 1), (0x190d7b, 1), (0x190f1a, 1)):
            assert [m['cpu']['eax'] for m in op['points'] if int(m['pc'], 16) == pc] == [eax] * completed
        assert trace.count('0x173d1c') == trace.count('0x174a90') == completed
        kmem = [m for m in op['points'] if m['pc'] == '0x173d1c']
        finds = [m for m in op['points'] if m['pc'] == '0x174a90']
        assert len(kmem) == len(finds) == completed
        for m, f in zip(kmem, finds):
            assert m['args'][0] == KM and m['args'][2] == VM
            assert 0x70f020 <= m['args'][1] < 0x70ff00
            assert f['args'][0:3] == [KM, 0, 0] and f['args'][4:] == [VM, 1]
            assert 0x70f020 <= f['args'][3] < 0x70ff00
        init = fixture['exhausted_kernel_map']['init']
        assert init['entry'] == '0x15b54c' and init['args'] == [KM, 1]
        io = init['observation']
        assert io['trace'] and io['trace'][0] == init['entry'] and io['error'] is None and not io['interrupts']
        assert io['after']['eip'] == 0x740000
        lock_init_trace(io['trace'])
        reload = fixture['final_pre_call_flush']
        assert reload['trace'] == ['0x18d3ef'] and reload['error'] is None and not reload['interrupts']
        assert reload['after']['eip'] == 0x18d3f2 and reload['after']['cr3'] == ROOTS[target]
        assert trace.count('0x1907b1') == (completed if partial else 0)
        for pc in (0x190ef4, 0x190aa7, 0x190d86, 0x173e3a):
            assert hex(pc) not in trace
        assert op['after']['tlb_counters'] == [0, 0]
    return True


def main():
    rows = json.loads((HERE / 'pt-cases.json').read_text())
    cycles = [r for r in rows if r['kind'] == 'reuse_cycle']
    failures = [r for r in rows if r['kind'] == 'new_va_failure']
    assert {(r['target'], r['wired'], r['residue']) for r in cycles} == set(itertools.product(ROOTS, (0, 1), (False, True)))
    assert {(r['target'], r['entry_kind']) for r in failures} == set(itertools.product(ROOTS, ('expand', 'pmap_enter')))
    assert len(rows) == len(cycles) + len(failures) == 12 and len(cycles) == 8
    for row in rows:
        audit_case(row)
    result = {'cases_verified': len(rows), 'original_pt_reuse_cycles': len(cycles),
              'original_virtual_space_failure_cases': len(failures),
              'completed_expand_failure_returns': sum(2 if r['entry_kind'] == 'pmap_enter' else 1 for r in failures),
              'bounded_caller_rechecks': sum(r['entry_kind'] == 'pmap_enter' for r in failures),
              'mismatches': [], 'new_wired_allocation_success_verified': False, 'whole_pt_ownership_verified': False,
              'independent_hardware_backend': False}
    (HERE / 'independent-audit.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
