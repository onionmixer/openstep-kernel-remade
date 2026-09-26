"""Independent JSON arithmetic/trace audit, without importing fixture code."""
import importlib.util
import itertools
import json
from pathlib import Path
import struct

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('audit24', HERE.parent / 'continuous-review-20260911-24/audit_results.py')
A = importlib.util.module_from_spec(spec)
spec.loader.exec_module(A)


def trace_check(trace, stop, complete):
    pcs = [int(pc, 16) for pc in trace]
    calls = []
    for pc, following in zip(pcs, pcs[1:] + [stop]):
        ins = A.instruction(pc)
        if ins.mnemonic == 'call':
            assert ins.operands[0].type == A.capstone.x86.X86_OP_IMM
            assert following == ins.operands[0].imm
            calls.append(pc + ins.size)
        elif ins.mnemonic == 'ret':
            assert following == (calls.pop() if calls else stop)
        elif ins.mnemonic.startswith('iret'):
            assert pc == 0x186d7c and following in (0x189e70, 0x18a018)
        elif ins.group(A.capstone.CS_GRP_JUMP):
            if ins.operands[0].type == A.capstone.x86.X86_OP_IMM:
                allowed = {ins.operands[0].imm}
                if ins.mnemonic != 'jmp':
                    allowed.add(pc + ins.size)
                assert following in allowed, (hex(pc), hex(following))
            else:
                tables = {0x19211a: (0x192124, 14 - 1), 0x101669: (0x101670, 12 - 1)}
                base, index = tables[pc]
                assert following == struct.unpack('<I', A.original(base + index * 4, 4))[0]
        else:
            assert following == pc + ins.size, (hex(pc), hex(following))
    if complete:
        assert not calls
    else:
        assert calls == [0x186d68, 0x1870fe, 0x1921ec, 0x172070]


def main():
    rows = json.loads((HERE / 'protection-cases.json').read_text())
    summary = json.loads((HERE / 'protection-review.json').read_text())
    fields = ('target', 'function', 'hint', 'destination', 'flags', 'protection')
    expected = set(itertools.product(('A', 'B'), ('_copyout', '_copyoutmsg'), ('entry', 'sentinel'),
                                     (0x100, 0x1100), (2, 0x602), (1, 3)))
    assert len(rows) == len(expected) and {tuple(r[k] for k in fields) for r in rows} == expected
    for row in rows:
        reject = row['protection'] == 1
        trace_check(row['fixture']['lock_init']['trace'], 0x740000, True)
        trace_check(row['handler']['trace'], 0x740000 if reject else 0x17817c, reject)
        fault = row['fault']['after']
        assert row['fault']['interrupts'][0]['vector'] == 14
        assert row['fault']['interrupts'][0]['snapshot'] == fault
        assert fault['cr2'] == 0x600000 + row['destination']
        assert row['fault_buffer_hashes'] == A.expected_hashes(row['target'], 1, row['destination'], 0)
        assert row['final_buffer_hashes'] == row['fault_buffer_hashes']
        final = row['final_memory']
        assert final['entry'] == row['entry_before']
        assert final['fault_counter_after'] == (final['fault_counter_before'] + 1) & 0xffffffff
        assert final['stack_guards'] == {hex(0x710000 - 0x1000): (bytes([0xa7]) * 32).hex(),
                                          hex(0x710000 + 4 * 4): (bytes([0x5d]) * 32).hex()}
        assert row['fixture']['page_mask'] + 1 == row['fixture']['vm_size'] == 0x2000
        assert fault['cr2'] & ~row['fixture']['page_mask'] == 0x600000
        for mapping in row['fixture']['mappings']:
            assert mapping['low']['present'] and not mapping['low']['writable']
            assert mapping['high']['present'] and mapping['high']['writable']
        map_data = bytes.fromhex(row['map_before'])
        entry = bytes.fromhex(row['entry_before'])
        assert struct.unpack_from('<3I', map_data) == (0xffffffff, 8 << 16, 0)
        assert struct.unpack_from('<2I', map_data, 0xc) == (0x680600, 0x680600)
        assert struct.unpack_from('<I', map_data, 0x38)[0] == (0x680600 if row['hint'] == 'entry' else 0x680400 + 0xc)
        assert struct.unpack_from('<4I', entry) == (0x680400 + 0xc, 0x680400 + 0xc, 0x600000, 0x602000)
        assert struct.unpack_from('<I', entry, 0x1c)[0] == row['protection']
        m = {int(item['pc'], 16): item for item in row['milestones']}
        assert m[0x172038]['arguments'] == [0x680400, 0x600000, 3, 0, 0]
        assert m[0x178165]['state']['eax'] == 3 and m[0x178165]['state']['ebx'] == row['protection']
        assert (3 & row['protection'] != 3) == reject
        trace = row['handler']['trace']
        assert ('0x178081' in trace) == ('0x1780a7' in trace) == (row['hint'] == 'sentinel')
        assert '0x178131' not in trace
        if reject:
            assert final['map'] == row['map_before'] and final['recover'] == 0 and final['uthread_byte'] == 'a5'
            for field in ('ds', 'es', 'ss', 'fs', 'gs', 'cs', 'cr0', 'cr4'):
                assert row['handler']['after'][field] == fault[field]
            for pc in (0x178177, 0x172070, 0x1921ec):
                assert m[pc]['state']['eax'] == 2 and m[pc]['map'] == row['map_before']
            before = bytes.fromhex(m[0x187068]['frame'])
            after = bytes.fromhex(m[0x192213]['frame'])
            wanted = bytearray(before)
            landing = {'_copyout': 0x189e70, '_copyoutmsg': 0x18a018}[row['function']]
            struct.pack_into('<I', wanted, 0x38, landing)
            struct.pack_into('<H', wanted, 0x3c, 8)
            struct.pack_into('<I', wanted, 0x40, struct.unpack_from('<I', before, 0x40)[0] & ~0x400)
            assert after == wanted
            assert m[landing]['state']['eflags'] == fault['eflags'] & ~0x400
            assert row['handler']['after']['eax'] == A.instruction(landing + 12).operands[1].imm == 14
        else:
            expected_map = bytearray(map_data)
            struct.pack_into('<H', expected_map, 4, 1)
            assert final['map'] == expected_map.hex() and final['uthread_byte'] == '00'
            assert final['recover'] == {'_copyout': 0x189e70, '_copyoutmsg': 0x18a018}[row['function']]
            assert row['handler']['after']['eip'] == 0x17817c
            assert int(trace[-1], 16) == 0x17816a
            assert '0x17816d' not in trace and '0x186d7c' not in trace
    assert sum(r['protection'] == 1 for r in rows) == summary['protection_failure_to_EFAULT']
    result = {'case_matrix_verified': len(rows), 'lock_init_original_traces_checked': len(rows),
              'handler_original_traces_checked': len(rows), 'independent_buffer_hash_checks': len(rows),
              'complete_original_protection_rejection_paths': sum(r['protection'] == 1 for r in rows),
              'permission_gate_only_paths': sum(r['protection'] == 3 for r in rows),
              'vm_page_vs_hardware_page_checked': True, 'mismatches': [],
              'independent_hardware_backend': False, 'whole_analysis_complete': False}
    (HERE / 'independent-audit.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
