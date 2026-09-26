"""Independent original-byte trace, frame, buffer and mapping audit.

Does not import the execution fixture. It consumes one backend's observations;
this is not an independent hardware run.
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


def trace_check(trace, iret_target):
    pcs = [int(p, 16) for p in trace]
    returns = []
    for pc, following in zip(pcs, pcs[1:] + [0x740000]):
        ins = A.instruction(pc)
        if ins.mnemonic == 'call':
            assert ins.operands[0].type == A.capstone.x86.X86_OP_IMM
            assert following == ins.operands[0].imm
            returns.append(pc + ins.size)
        elif ins.mnemonic == 'ret':
            assert following == (returns.pop() if returns else 0x740000)
        elif ins.mnemonic.startswith('iret'):
            assert pc == 0x186d7c and following == iret_target
        elif ins.group(A.capstone.CS_GRP_JUMP):
            if ins.operands[0].type == A.capstone.x86.X86_OP_IMM:
                allowed = {ins.operands[0].imm}
                if ins.mnemonic != 'jmp':
                    allowed.add(pc + ins.size)
                assert following in allowed, (hex(pc), hex(following))
            else:
                assert pc == 0x19211a
                target, = struct.unpack('<I', A.original(0x192124 + (14 - 1) * 4, 4))
                assert following == target
        else:
            assert following == pc + ins.size, (hex(pc), hex(following), ins.mnemonic)
    assert not returns


def main():
    rows = json.loads((HERE / 'resident-cases.json').read_text())
    expected_cases = set(itertools.product(('A', 'B'), ('_copyout', '_copyoutmsg'), (0x100, 0x1100),
                                          (2, 0x202, 0x402, 0x602), ('unqueued', 'active')))
    actual = {(r['target'], r['function'], r['destination'], r['flags'], r['fixture']['initial_queue']) for r in rows}
    assert actual == expected_cases and len(rows) == len(expected_cases)
    for row in rows:
        fault = row['fault']['after']
        assert fault == row['fault']['interrupts'][0]['snapshot']
        assert row['fault']['interrupts'][0]['vector'] == 14
        assert fault['cr2'] == 0x600000 + row['destination']
        trace_check(row['trace'], fault['eip'])
        trace_check(row['fixture']['insertion']['trace'], None)
        if row['fixture']['initial_queue'] == 'active':
            trace_check(row['fixture']['initial_activation']['trace'], None)
        assert row['trace'].count(hex(fault['eip'])) == 1
        assert row['handler']['after']['eax'] == 0 and row['handler']['after']['eip'] == 0x740000
        assert row['handler']['after']['esp'] == 0x710000 + struct.calcsize('<I')
        assert row['before']['buffer_hashes'] == A.expected_hashes(row['target'], 1, row['destination'], 0)
        assert row['after']['buffer_hashes'] == A.expected_hashes(row['target'], 1, row['destination'], 1)
        milestones = {int(m['pc'], 16): m for m in row['milestones']}
        raw = bytes.fromhex(milestones[0x187068]['frame'])
        fields = ['gs', 'fs', 'es', 'ds', 'edi', 'esi', 'ebp', 'pushad_esp', 'ebx', 'edx', 'ecx', 'eax', 'trap', 'error', 'eip', 'cs', 'eflags']
        assert len(raw) == struct.calcsize('<' + 'I' * len(fields))
        for index, field in enumerate(fields):
            observed, = struct.unpack_from('<I', raw, index * 4)
            expected = {'pushad_esp': fault['esp'] - 5 * 4, 'trap': 14, 'error': 3}.get(field, fault.get(field))
            mask = 0xffff if field in ('gs', 'fs', 'es', 'ds', 'cs') else 0xffffffff
            assert observed & mask == expected & mask
        for pc in (0x186d7c, fault['eip']):
            assert bytes.fromhex(milestones[pc]['frame']) == raw
        assert milestones[fault['eip']]['state']['cpu']['eflags'] == fault['eflags']
        assert milestones[0x1921ec]['state']['cpu']['eax'] == 0
        assert '0x1924a0' not in row['trace']
        payload = {'A': 0x900000, 'B': 0xa00000}[row['target']]
        assert milestones[0x19065c]['arguments'] == [0x684000, 0x600000, payload, 3, 0]
        assert row['invalidations'] == [0x600000 + off for off in range(0, 0x2000, 0x1000)]
        invalidation_indices = [i for i, pc in enumerate(row['trace']) if pc == '0x1908b4']
        store_indices = [i for i, pc in enumerate(row['trace']) if pc == '0x1908e8']
        assert max(invalidation_indices) < min(store_indices)
        assert max(store_indices) < row['trace'].index('0x186d7c') < row['trace'].index(hex(fault['eip']))
        assert row['pte_write_hooks'] == [{'pc': 0x1908e8, 'address': s['address'], 'width': 4, 'value': s['value']} for s in row['pte_store_attempts']]
        for off, store in zip(range(0, 0x2000, 0x1000), row['pte_store_attempts']):
            assert store['value'] == (payload + off) | 7 and store['old'] & 3 == 1
        assert len(row['pte_store_attempts']) == 0x2000 // 0x1000
        assert not row['pmap_stats_accesses'] and row['pmap_root_read_hooks']
        assert len(row['mappings_before']) == len(row['mappings_after']) == len(('A', 'B')) * len(('user', 'kernel')) * (0x2000 // 0x1000)
        for before, after in zip(row['mappings_before'], row['mappings_after']):
            assert (before['target'], before['space'], before['offset']) == (after['target'], after['space'], after['offset'])
            a, b = before['walk'], after['walk']
            assert int(a['pde'], 16) & ~0x20 == int(b['pde'], 16) & ~0x20
            assert a['pte_address'] == b['pte_address'] and a['physical'] == b['physical']
            wanted = int(a['pte'], 16)
            if before['target'] == row['target'] and before['space'] == 'user':
                wanted |= 2
            assert wanted & ~0x60 == int(b['pte'], 16) & ~0x60
        for field in ('object', 'pmap', 'map', 'bucket_data'):
            assert row['after'][field] == row['before'][field]
        assert row['after']['active_queue'] == [0x683000, 0x683000] and row['after']['active_count'] == 1
        assert milestones[0x172626]['state']['active_queue'] == [0x1f6e40, 0x1f6e40]
        assert milestones[0x172626]['state']['active_count'] == 0
        assert ('0x1725f6' in row['trace']) == (row['fixture']['initial_queue'] == 'active')
        expected_page = bytearray.fromhex(row['before']['page'])
        struct.pack_into('<2I', expected_page, 0, 0x1f6e40, 0x1f6e40)
        expected_page[0x1e] |= 2
        assert row['after']['page'] == expected_page.hex()
        expected_recover = {'_copyout': 0x189e70, '_copyoutmsg': 0x18a018}[row['function']]
        assert row['after']['recover'] == expected_recover and row['after']['uthread_byte'] == 'a5'
        for field in ('cs', 'ds', 'es', 'ss', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4'):
            assert row['after']['cpu'][field] == fault[field]
    summary = {'case_matrix_verified': len(rows), 'same_physical_permission_repair_and_original_retry': len(rows),
               'active_initial_queue_cases': sum(r['fixture']['initial_queue'] == 'active' for r in rows),
               'independent_frame_buffer_mapping_audits': len(rows), 'mismatches': [],
               'independent_hardware_backend': False, 'pager_io_verified': False, 'whole_analysis_complete': False}
    (HERE / 'independent-audit.json').write_text(json.dumps(summary, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
