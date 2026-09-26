"""Negative controls mutate memory copies, not preserved evidence or original input."""
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
    rows = json.loads((HERE / 'fault-new-pt-cases.json').read_text())
    base = next(r for r in rows if r['sleepable'] == 0)
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
    reject('empty_queue_preparation_trace', lambda r: r['setup']['queue_preparation'][0]['call']['observation'].__setitem__('trace', []))
    reject('wrong_free_order_counts', lambda r: r['setup']['queue_preparation'][1]['after']['globals'].__setitem__('free_count', 2))
    reject('missing_preexisting_seed_trace', lambda r: r['setup']['new_seed_calls'][0]['observation'].__setitem__('trace', []))
    reject('wrong_copy_length', lambda r: patch_hex(r['before'], 'copy_stack', 12, 16))
    reject('wrong_actual_fault_vector', lambda r: r['fault']['interrupts'][0].__setitem__('vector', 13))
    reject('missing_fault_terminal_head', lambda r: r['fault']['trace'].pop())
    reject('wrong_CPU_frame_error_input', lambda r: r['cpu_frame_input']['words'].__setitem__(0, 3))
    reject('wrong_injected_stack_word', lambda r: patch_hex(r['injected'], 'stack_memory', r['cpu_frame_input']['address'] - A.STACK, 3))
    reject('unreported_memory_change_at_injection', lambda r: patch_hex(r['injected'], 'kernel_page', 0x20, 5, 1))
    reject('misclaim_native_frame', lambda r: r.__setitem__('native_cpu_frame_verified', True))
    reject('saved_frame_not_real_stack', lambda r: patch_hex(point(r, 0x186d7c)['state'], 'stack_memory', r['frame_address'] - A.STACK + 0x38, A.STOP))
    reject('saved_frame_string_changed', lambda r: point(r, 0x186d7c).__setitem__('saved_frame', bytes(len(A.FIELDS) * 4).hex()))
    reject('wrong_data_allocator_return', lambda r: point(r, 0x17269f)['cpu'].__setitem__('eax', A.PG))
    reject('wrong_PT_allocator_return', lambda r: point(r, 0x173f04)['cpu'].__setitem__('eax', A.PAGE))
    reject('wrong_second_allocator_object', lambda r: [p for p in r['points'] if p['pc'] == '0x17b200'][1]['args'].__setitem__(0, A.OBJ))
    reject('nested_data_busy_lost', lambda r: patch_hex(point(r, 0x173f92)['state'], 'page', 0x20, 4, 1))
    reject('nested_data_object_ref_lost', lambda r: patch_hex(point(r, 0x173f92)['state'], 'object', 0x18, 1, 2))
    reject('kernel_object_stale_offset_erased', lambda r: patch_hex(r['before'], 'kernel_object', 0x54, 0))
    reject('data_object_stale_offset_erased', lambda r: patch_hex(r['before'], 'object', 0x54, 0))
    reject('wrong_final_active_count', lambda r: r['after']['globals'].__setitem__('active_count', 2))
    reject('wrong_final_PT_wire_count', lambda r: patch_hex(r['after'], 'kernel_page', 0x1c, 0, 2))
    reject('wrong_final_data_PV', lambda r: patch_hex(r['after'], 'descriptor_arena', A.desc(A.DATA) - A.DESC + 4, A.KP))
    reject('conflate_zero_counter_with_zero_calls', lambda r: r['after']['globals'].__setitem__('zero_count', 2))
    reject('missing_wire_fast_fault_counter', lambda r: r['after']['globals'].__setitem__('fault_count', 1))
    reject('missing_second_zero_chunk', lambda r: r['zero_chunks'].pop())
    reject('missing_zero_store', lambda r: r['writes'].remove(next(w for w in r['writes'] if w['pc'] == 0x1019cc)))
    reject('missing_retry_store', lambda r: r['writes'].remove(next(w for w in r['writes'] if w['pc'] == A.COPY[r['function']][1])))
    reject('wrong_retry_payload', lambda r: next(w for w in r['writes'] if w['pc'] == A.COPY[r['function']][1]).__setitem__('value', 0))
    reject('DATA_already_written_at_retry_head', lambda r: patch_hex(point(r, A.COPY[r['function']][1])['state'], 'frame', r['destination'], 0xe4, 1))
    reject('PT_dirty_before_retry', lambda r: patch_hex(point(r, A.COPY[r['function']][1])['state'], 'new_pt_frame',
        (((A.VA + r['destination']) & (0x800000 - 1)) >> 12) * 4, (A.DATA + r['destination'] // A.HW * A.HW) | 0x67))
    reject('wrong_final_recover', lambda r: r['after'].__setitem__('recover', 0))
    reject('wrong_final_uthread', lambda r: r['after'].__setitem__('uthread', '00'))
    reject('wrong_returned_kernel_VA', lambda r: patch_hex(point(r, 0x190d7b)['state'], 'stack_memory',
        point(r, 0x173d1c)['args'][1] - A.STACK, A.KVA + A.VM))
    def alias_missing(r, phys):
        for s in [r['before'], r['at_fault'], r['injected']] + [p['state'] for p in r['points']] + [r['after']]:
            for off in range(0, A.VM, A.HW):
                patch_hex(s['raw_translation'], hex(A.SHARED), (((phys + off) >> 12) & 0x3ff) * 4, 0)
            mem = A.regions(s)
            s['new_walks'] = {name: [A.B.walk(mem, root, va + off) for off in range(0, A.VM, A.HW)]
                for name, root, va in [('kernel_low', A.KR, A.KVA), ('kernel_high', A.ROOTS[r['target']], A.BASE + A.KVA),
                                      ('frame_high', A.ROOTS[r['target']], A.BASE + A.PT), ('user', A.ROOTS[r['target']], A.VA)]}
            s['data_high_walks'] = [A.B.walk(mem, A.ROOTS[r['target']], A.BASE + A.DATA + off) for off in range(0, A.VM, A.HW)]
    reject('consistently_missing_DATA_high_alias', lambda r: alias_missing(r, A.DATA))
    reject('consistently_missing_PT_high_alias', lambda r: alias_missing(r, A.PT))
    def branch_writes(r):
        w = next(w for w in r['writes'] if w['pc'] == 0x16b3c1)
        w['pc'] = 0x16b3bf
        w['trace_index'] = r['handler']['trace'].index('0x16b3bf')
    reject('branch_cannot_write_zone', branch_writes)
    def wrong_pt_return_consistent(r):
        p = point(r, 0x173f04)
        p['cpu']['eax'] = p['state']['cpu']['eax'] = A.PAGE
    reject('wrong_PT_return_consistent_CPU_views', wrong_pt_return_consistent)
    def early_ad_consistent(r):
        s = point(r, A.COPY[r['function']][1])['state']
        off = (((A.VA + r['destination']) & (0x800000 - 1)) >> 12) * 4
        patch_hex(s, 'new_pt_frame', off, (A.DATA + r['destination'] // A.HW * A.HW) | 0x67)
        memory = A.regions(s)
        s['new_walks']['user'] = [A.B.walk(memory, A.ROOTS[r['target']], A.VA + i) for i in range(0, A.VM, A.HW)]
    reject('early_retry_AD_consistent_walks', early_ad_consistent)
    reject('zero_loop_trace_index_reused', lambda r: r['zero_chunks'][1].__setitem__('trace_index', r['zero_chunks'][0]['trace_index']))
    reject('unreported_preparation_metadata_change', lambda r: patch_hex(r['setup']['queue_preparation'][-1]['after'], 'entry_zone', 0x18, 0))
    out = {'controls': controls, 'all_rejected': True, 'scope': 'in-memory evidence corruption, not native exception or real resource failure injection'}
    (HERE / 'negative-controls.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps({'negative_controls_rejected': len(controls), 'all_rejected': True}))


if __name__ == '__main__':
    main()
