"""Deliberately corrupt recorded evidence in memory; finalized inputs stay read-only."""
import copy
import json
from pathlib import Path
import audit_results as A

HERE = Path(__file__).resolve().parent


def patch_hex(state, field, offset, value, width=4):
    raw = bytearray.fromhex(state[field])
    raw[offset:offset + width] = value.to_bytes(width, 'little')
    state[field] = raw.hex()


def point(row, pc):
    return next(p for p in row['points'] if p['pc'] == hex(pc))


def main():
    rows = json.loads((HERE / 'new-pt-cases.json').read_text())
    base = next(r for r in rows if r['caller'] and r['sleepable'] == 0)
    controls = []
    def reject(name, mutate):
        row = copy.deepcopy(base)
        mutate(row)
        try:
            A.audit_case(row)
        except AssertionError:
            controls.append({'name': name, 'rejected': True})
        else:
            raise AssertionError('accepted corrupted evidence: ' + name)
    reject('empty_main_trace', lambda r: r['observation'].__setitem__('trace', []))
    reject('empty_original_page_seed', lambda r: r['setup']['new_seed_calls'][0]['observation'].__setitem__('trace', []))
    reject('empty_original_lock_init', lambda r: r['setup']['new_lock_init'][0]['observation'].__setitem__('trace', []))
    reject('missing_original_cr3_reload', lambda r: r['setup']['new_cr3_reload'].__setitem__('trace', []))
    reject('wrong_prepared_stack', lambda r: r['prepared_stack'].__setitem__(1, A.KP))
    reject('wrong_real_kmem_argument', lambda r: point(r, 0x173d1c)['args'].__setitem__(0, A.KO))
    reject('wrong_kernel_object_offset', lambda r: patch_hex(r['after'], 'kernel_page', 0x18, 0))
    reject('missing_vm_wire_count', lambda r: patch_hex(r['after'], 'kernel_page', 0x1c, 0, 2))
    reject('missing_global_wire_count', lambda r: r['after']['new_globals'].__setitem__('wire_count', 0))
    reject('wrong_kernel_PV_owner', lambda r: patch_hex(r['after'], 'descriptor_arena', A.desc(A.PT) - A.DESC + 4, A.PMAP))
    reject('missing_data_PV', lambda r: patch_hex(r['after'], 'descriptor_arena', A.desc(A.DATA) - A.DESC + 4, 0))
    reject('wrong_extension_resident_count', lambda r: patch_hex(r['after'], 'extension', 0x18, 0, 2))
    reject('wrong_zone_allocation_count', lambda r: patch_hex(r['after'], 'entry_zone', 8, 2))
    reject('busy_page_after_wiring', lambda r: patch_hex(r['after'], 'kernel_page', 0x20, 5, 1))
    reject('wrong_map_protection', lambda r: patch_hex(r['after'], 'kernel_entry', 0x1c, 0))
    reject('wrong_map_timestamp', lambda r: patch_hex(r['after'], 'kernel_map', 0x4c, 2))
    reject('wrong_kernel_root_slice', lambda r: r['before']['pt_contract'].__setitem__('kernel_root', A.KR & -A.HW))
    reject('invented_present_walk', lambda r: r['before']['new_walks']['kernel_low'][0].__setitem__('present', True))
    reject('kernel_PTE_loses_writable', lambda r: r['after']['raw_translation'].__setitem__(hex(A.SHARED),
        bytes.fromhex(r['after']['raw_translation'][hex(A.SHARED)])[:0x80].hex() +
        (A.PT | 0x201).to_bytes(4, 'little').hex() + bytes.fromhex(r['after']['raw_translation'][hex(A.SHARED)])[0x84:].hex()))
    reject('wrong_zero_loop_progress', lambda r: r['zero_chunks'][0].__setitem__('edx', A.PT + 4))
    reject('missing_zero_write', lambda r: r['writes'].remove(next(w for w in r['writes'] if w['pc'] == 0x1019cc)))
    reject('PDE_store_loses_user', lambda r: next(w for w in r['writes'] if w['pc'] == 0x190ef4).__setitem__('value', A.PT | 3))
    reject('wrong_store_trace_location', lambda r: next(w for w in r['writes'] if w['pc'] == 0x190ef4).__setitem__('trace_index', 0))
    reject('missing_wiring_milestone', lambda r: r['points'].remove(point(r, 0x17b6e8)))
    reject('wrong_wiring_result', lambda r: point(r, 0x1735c3)['cpu'].__setitem__('eax', 5))
    reject('wrong_returned_kernel_VA', lambda r: patch_hex(point(r, 0x190d7b)['state'], 'stack_memory',
        point(r, 0x173d1c)['args'][1] - A.STACK, A.KVA + A.VM))
    reject('intermediate_zone_state_corruption', lambda r: patch_hex(point(r, 0x174848)['state'], 'entry_zone', 0x10, 0))
    def wrong_bounds_everywhere(r):
        for s in [r['before']] + [p['state'] for p in r['points']] + [r['after']]:
            s['contract_globals']['0x1e2480'] = A.PT
    reject('consistently_wrong_managed_bounds', wrong_bounds_everywhere)
    def illegal_edge(r):
        i = r['observation']['trace'].index('0x190d76')
        r['observation']['trace'][i + 1] = '0x190d7b'
    reject('skip_real_wired_allocator_call', illegal_edge)
    def false_alias(r, mode):
        for s in [r['before']] + [p['state'] for p in r['points']] + [r['after']]:
            if mode == 'pde':
                patch_hex(s['roots'], r['target'], ((A.BASE + A.PT) >> 22) * 4, 0)
            else:
                for off in range(0, A.VM, A.HW):
                    pte = 0 if mode == 'pte' else (A.PT + off) | 1
                    patch_hex(s['raw_translation'], hex(A.SHARED), (((A.PT + off) >> 12) & 0x3ff) * 4, pte)
            mem = A.regions(s)
            s['new_walks'] = {name: [A.walk(mem, root, va + off) for off in range(0, A.VM, A.HW)]
                for name, root, va in [('kernel_low', A.KR, A.KVA), ('kernel_high', A.ROOTS[r['target']], A.BASE + A.KVA),
                                      ('frame_high', A.ROOTS[r['target']], A.BASE + A.PT), ('user', A.ROOTS[r['target']], A.VA)]}
    reject('consistently_absent_kernel_high_PDE', lambda r: false_alias(r, 'pde'))
    reject('consistently_absent_frame_direct_PTE', lambda r: false_alias(r, 'pte'))
    reject('consistently_readonly_frame_direct_PTE', lambda r: false_alias(r, 'readonly'))
    def branch_writes(r):
        w = next(w for w in r['writes'] if w['pc'] == 0x16b3c1)
        w['pc'] = 0x16b3bf
        w['trace_index'] = r['observation']['trace'].index('0x16b3bf')
    reject('branch_instruction_cannot_write_zone', branch_writes)
    out = {'controls': controls, 'all_rejected': True, 'scope': 'corrupted evidence rejection, not real allocation failure injection'}
    (HERE / 'negative-controls.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps({'negative_controls_rejected': len(controls), 'all_rejected': True}))


if __name__ == '__main__':
    main()
