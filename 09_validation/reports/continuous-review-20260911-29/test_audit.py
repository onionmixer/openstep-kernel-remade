"""Corrupt observations, not original binary/DB; require independent rejection."""
import copy
import json
from pathlib import Path
import audit_results as A

HERE = Path(__file__).resolve().parent


def byte_change(row, field, offset, value, state='after'):
    data = bytearray.fromhex(row[state][field])
    data[offset] = value
    row[state][field] = data.hex()


def main():
    source = json.loads((HERE / 'missing-page-cases.json').read_text())[0]
    assert A.audit_case(source)
    tests = [
        ('old_protection_error_instead_of_nonpresent', lambda r: r.update(error_frame_input=3)),
        ('missing_zero_store', lambda r: r['writes'].pop(next(i for i, w in enumerate(r['writes']) if w['pc'] == 0x1019cc))),
        ('unzeroed_frame_tail', lambda r: byte_change(r, 'frame', A.VM - 1, 1)),
        ('managed_range_bypass', lambda r: r['before']['contract_globals'].update({'0x1e2480': 0})),
        ('missing_pt_extension', lambda r: byte_change(r, 'descriptor_arena', A.desc(A.PT) - A.DESC + 0xd, 0)),
        ('wrong_pv_owner', lambda r: byte_change(r, 'descriptor_arena', A.desc(A.PHYS) - A.DESC + 4, 1)),
        ('missing_second_pte_store', lambda r: r['writes'].pop(next(i for i, w in reversed(list(enumerate(r['writes']))) if w['pc'] == 0x190aa7))),
        ('wrong_extension_count', lambda r: byte_change(r, 'extension', 0x18, 0)),
        ('no_fault_instruction_retry', lambda r: r['handler']['trace'].remove(hex(r['fault']['after']['eip']))),
        ('inconsistent_root_label', lambda r: r.update(target='B')),
        ('broken_rep_progress', lambda r: r['allocator_rep'][1].update(ecx=12)),
        ('out_of_contract_write', lambda r: r['writes'].append({'pc': 0x1019cc, 'address': 0x700000, 'width': 4, 'value': 0})),
        ('empty_seed_execution_trace', lambda r: r['fixture']['seed_calls'][0]['observation'].update(trace=[])),
        ('empty_startup_execution_trace', lambda r: r['fixture']['startup_prefix']['observation'].update(trace=[])),
        ('wrong_fault_terminal_head', lambda r: r['fault']['trace'].__setitem__(-1, '0x0')),
        ('seed_wrong_entry_head', lambda r: r['fixture']['seed_calls'][0]['observation']['trace'].__setitem__(0, '0x0')),
        ('seed_interrupted', lambda r: r['fixture']['seed_calls'][0]['observation'].update(interrupts=[{'vector': 14}])),
        ('missing_direct_alias_evidence', lambda r: r['fixture'].update(direct_aliases=[])),
        ('wrong_alias_root', lambda r: r['fixture']['direct_aliases'][0].update(pde_address='0x0')),
    ]
    rows = []
    for name, change in tests:
        row = copy.deepcopy(source)
        change(row)
        rejected = False
        try:
            A.audit_case(row)
        except AssertionError:
            rejected = True
        assert rejected, name
        rows.append({'mutation': name, 'rejected': rejected})
    result = {'uncorrupted_case_passed': True, 'negative_cases': rows, 'all_rejected': True}
    (HERE / 'negative-controls.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'negative_cases': len(rows), 'all_rejected': True}))


if __name__ == '__main__':
    main()
