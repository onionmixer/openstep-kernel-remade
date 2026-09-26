"""Negative controls corrupt in-memory evidence only, never original inputs."""
import copy
import json
from pathlib import Path
import audit_results as A

HERE = Path(__file__).resolve().parent


def modify_hex(state, key, offset, value):
    data = bytearray.fromhex(state[key])
    data[offset] = value
    state[key] = data.hex()


def bad_globals(row):
    for op in row['operations']:
        for state in (op['before'], op['after']):
            state['contract_globals']['0x1e2480'] = 0


def bad_pde_clear(row):
    op = row['operations'][0]
    next(w for w in op['writes'] if w['pc'] == 0x191040)['value'] = 0
    for state in (op['after'], row['operations'][1]['before']):
        raw = bytearray.fromhex(state['roots'][row['target']])
        raw[0] = 0
        state['roots'][row['target']] = raw.hex()


def bad_point(row):
    next(m for m in row['operations'][0]['points'] if m['pc'] == '0x190d7b')['cpu']['eax'] = 3


def main():
    rows = json.loads((HERE / 'pt-cases.json').read_text())
    reuse = next(r for r in rows if r['kind'] == 'reuse_cycle' and r['wired'] == 1 and r['residue'])
    failure = next(r for r in rows if r['kind'] == 'new_va_failure' and r['entry_kind'] == 'pmap_enter')
    assert A.audit_case(reuse) and A.audit_case(failure)
    tests = [
        ('consistent_managed_bounds_corruption', reuse, bad_globals),
        ('clear_permissions_along_with_present', reuse, bad_pde_clear),
        ('null_free_tail', reuse, lambda r: r['operations'][0]['before'].update(pt_free_queue=[A.FREE, 0])),
        ('wrong_total_pt_count', reuse, lambda r: r['operations'][0]['before'].update(pt_alloc_count=0)),
        ('wrong_kernel_pv_va', reuse, lambda r: modify_hex(r['operations'][0]['before'], 'descriptor_arena', A.desc(A.PT) - A.DESC + 10, 0)),
        ('wrong_wired_count', reuse, lambda r: modify_hex(r['operations'][1]['after'], 'extension', 0x1a, 0)),
        ('destroy_np_residue', reuse, lambda r: modify_hex(r['operations'][0]['after'], 'pt_pair', 1, 0)),
        ('wrong_reuse_section', reuse, lambda r: modify_hex(r['operations'][5]['after'], 'extension', 0x16, 0)),
        ('missing_pde_install', reuse, lambda r: r['operations'][1]['writes'].pop(next(i for i, w in enumerate(r['operations'][1]['writes']) if w['pc'] == 0x190ef4))),
        ('missing_pte_clear', reuse, lambda r: r['operations'][4]['writes'].pop(next(i for i, w in enumerate(r['operations'][4]['writes']) if w['pc'] == 0x18f96e))),
        ('empty_inherited_startup', reuse, lambda r: r['fixture']['startup_prefix']['observation'].update(trace=[])),
        ('empty_inherited_seed', reuse, lambda r: r['fixture']['seed_calls'][0]['observation'].update(trace=[])),
        ('empty_data_allocation', reuse, lambda r: r['fixture']['data_allocation']['observation'].update(trace=[])),
        ('wrong_prepared_stack_arg', reuse, lambda r: r['operations'][1]['prepared_stack'].__setitem__(1, 0)),
        ('physical_frame_modified', reuse, lambda r: modify_hex(r['operations'][3]['after'], 'frame', 0, 0)),
        ('wrong_kmem_failure_value', failure, bad_point),
        ('missing_failure_timestamp', failure, lambda r: modify_hex(r['operations'][0]['after'], 'kernel_map', 0x4c, 0)),
        ('pretend_caller_returned', failure, lambda r: r.update(caller_return_verified=True)),
        ('missing_map_lock_init', failure, lambda r: r['fixture']['exhausted_kernel_map']['init']['observation'].update(trace=[])),
        ('wrong_lock_zero_jump_target', failure, lambda r: r['fixture']['exhausted_kernel_map']['init']['observation']['trace'].__setitem__(
            r['fixture']['exhausted_kernel_map']['init']['observation']['trace'].index('0x101669') + 1, '0x1016fc')),
        ('np_skip_missing_branch', reuse, lambda r: r['operations'][3]['observation']['trace'].remove('0x18f8b9')),
        ('np_skip_wrong_removed_count', reuse, lambda r: next(p for p in r['operations'][3]['points'] if p['pc'] == '0x190f90')['args'].__setitem__(2, 1)),
    ]
    results = []
    for name, base, mutate in tests:
        row = copy.deepcopy(base)
        mutate(row)
        rejected = False
        try:
            A.audit_case(row)
        except AssertionError:
            rejected = True
        assert rejected, name
        results.append({'mutation': name, 'rejected': True})
    out = {'uncorrupted_controls_passed': True, 'negative_cases': results, 'all_rejected': True}
    (HERE / 'negative-controls.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps({'negative_cases': len(results), 'all_rejected': True}))


if __name__ == '__main__':
    main()
