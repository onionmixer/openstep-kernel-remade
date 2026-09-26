"""In-memory evidence corruption controls, without original/runtime state edits."""
import copy
import json
from pathlib import Path
import audit_results as A

HERE = Path(__file__).resolve().parent


def point(r, pc):
    return next(p for p in r['points'] if p['pc'] == hex(pc))


def coherent_replay(r, field, address):
    """Repair captured bytes/cursors/walks, making controls internally consistent."""
    raw = bytearray.fromhex(r['before']['raw_translation'][hex(address)] if field == 'raw_translation' else r['before'][field])
    cursor = 0
    r['writes'].sort(key=lambda w: w['trace_index'])
    for p in r['points'] + [{'state': r['after'], 'trace_index': len(r['observation']['trace'])}]:
        end = sum(w['trace_index'] < p['trace_index'] for w in r['writes'])
        for w in r['writes'][cursor:end]:
            off = w['address'] - address
            if 0 <= off and off + w['width'] <= len(raw):
                raw[off:off + w['width']] = w['value'].to_bytes(w['width'], 'little')
        s = p['state']
        if field == 'raw_translation':
            s[field][hex(address)] = raw.hex()
            m = A.regions(s)
            s['new_walks'] = {name: [A.B.walk(m, root, va + off) for off in range(0, A.VM, A.HW)]
                for name, root, va in [('kernel_low', A.F.KR, A.KVA), ('kernel_high', A.F.ROOTS[r['params'][0]], A.F.BASE + A.KVA),
                    ('frame_high', A.F.ROOTS[r['params'][0]], A.F.BASE + A.PT), ('user', A.F.ROOTS[r['params'][0]], A.VA)]}
            s['data_high_walks'] = [A.B.walk(m, A.F.ROOTS[r['params'][0]], A.F.BASE + A.DATA + off) for off in range(0, A.VM, A.HW)]
        else:
            s[field] = raw.hex()
        if 'pc' in p:
            p['write_cursor'] = end
        cursor = end


def main():
    refs = A.references()
    rows = json.loads((HERE / 'gc-cases.json').read_text())
    base = next(r for r in rows if r['params'][4] == 0 and r['last'] == 1 and r['tick'] == 3)
    gate = next(r for r in rows if r['last'] == 0)
    controls = []
    def reject(name, mutate, sample=None):
        r = copy.deepcopy(base if sample is None else sample)
        mutate(r)
        try:
            A.audit_case(r, refs[tuple(r['params'])])
        except AssertionError:
            controls.append({'name': name, 'rejected': True})
        else:
            raise AssertionError('accepted corrupted evidence: ' + name)
    def cpu(r, pc, field, value):
        p = point(r, pc)
        p['cpu'][field] = p['state']['cpu'][field] = value
    reject('wrong_fresh_prefix_hash', lambda r: r['prefix33'].__setitem__('canonical_sha256', '0' * 64))
    reject('wrong_prefix_scenario', lambda r: r['params'].__setitem__(2, 0x1100))
    reject('unreported_prefix_metadata_change', lambda r: A.R.patch(r['pre_input'], 'kernel_page', 0x1c, 0, 2))
    reject('unreported_preseed_tick', lambda r: r['pre_input']['gc_regions'].__setitem__('0x1f653c', '01000000'))
    reject('wrong_PD_free_sentinel', lambda r: r['before']['gc_regions'].__setitem__('0x1f7aa0', bytes(16).hex()))
    reject('unreported_object_lock_seed', lambda r: A.R.patch(r['before'], 'kernel_object', 0x10, 1))
    reject('unreported_CR3_change', lambda r: r['before']['cpu'].__setitem__('cr3', A.F.ROOTS['B']))
    reject('unreported_FS_change', lambda r: r['before']['cpu'].__setitem__('fs', 16))
    reject('unreported_stack_argument_change', lambda r: A.R.patch(r['before'], 'stack_memory', A.CALL_STACK - A.F.STACK + 4, 0))
    reject('changed_aging_table', lambda r: r['before']['gc_regions'].__setitem__('0x1e25fc', bytes(A.GCSIZES[0x1e25fc]).hex()))
    reject('misclaim_native_CPU', lambda r: r.__setitem__('native_cpu_verified', True))
    reject('misclaim_whole_ownership', lambda r: r.__setitem__('whole_ownership_verified', True))
    reject('wrong_tick_gate_delta_CPU', lambda r: cpu(r, 0x191171, 'ebx', 1))
    reject('wrong_tick_saved_delta', lambda r: A.R.patch(point(r, 0x191260)['state'], 'stack_memory',
        point(r, 0x191260)['cpu']['ebp'] - 8 - A.F.STACK, 0))
    reject('wrong_tick_tail_delta_CPU', lambda r: cpu(r, 0x1913db, 'ebx', 0))
    reject('wrong_tick_final_update', lambda r: r['after']['gc_regions'].__setitem__('0x1e773c', '01000000'))
    reject('missing_initial_last_initialization', lambda r: r['writes'].remove(next(w for w in r['writes'] if w['pc'] == 0x19115c)), gate)
    reject('gate_pretends_memory_reclaimed', lambda r: r['after'].__setitem__('pt_alloc_count', 0), gate)
    reject('gate_unchanged_last_claim', lambda r: r['after']['gc_regions'].__setitem__('0x1e773c', '00000000'), gate)
    reject('wrong_PT_lookup_argument', lambda r: point(r, 0x178894)['args'].__setitem__(0, A.DATA))
    reject('wrong_lookup_return', lambda r: cpu(r, 0x173660, 'eax', A.PAGE))
    reject('wrong_lookup_saved_physical', lambda r: cpu(r, 0x173660, 'esi', A.DATA))
    reject('wrong_lookup_field_pointer', lambda r: cpu(r, 0x1788cc, 'edx', A.R.SEGMENTS))
    reject('wrong_wired_store_pointer', lambda r: cpu(r, 0x190c03, 'edx', A.F.SHARED))
    reject('wrong_wired_store_AL', lambda r: cpu(r, 0x190c03, 'eax', 0))
    reject('wrong_wired_store_byte_address', lambda r: next(w for w in r['writes'] if w['pc'] == 0x190c03).__setitem__('address', A.F.SHARED + ((A.KVA >> 12) & 0x3ff) * 4))
    reject('wrong_wired_store_width', lambda r: next(w for w in r['writes'] if w['pc'] == 0x190c03).__setitem__('width', 4))
    reject('missing_second_wired_clear', lambda r: r['writes'].remove([w for w in r['writes'] if w['pc'] == 0x190c03][-1]))
    reject('wrong_PTE_clear_value', lambda r: next(w for w in r['writes'] if w['pc'] == 0x18fcd8).__setitem__('value', 1))
    reject('wrong_descriptor_backlink_pointer', lambda r: cpu(r, 0x1911b9, 'eax', A.F.desc(A.DATA)))
    reject('wrong_remove_all_count', lambda r: point(r, 0x190f90)['args'].__setitem__(2, 0))
    reject('wrong_NP_second_remove_count', lambda r: [p for p in r['points'] if p['pc'] == '0x190f90'][-1]['args'].__setitem__(2, 1))
    reject('missing_lookup_segment_iteration', lambda r: r['points'].remove(point(r, 0x1788cc)))
    reject('wrong_transient_active_count', lambda r: point(r, 0x17b809)['state']['globals'].__setitem__('active_count', 1))
    reject('falsely_unchanged_DATA_queue_link', lambda r: A.R.patch(point(r, 0x17b809)['state'], 'page', 0, 0x1f6e40))
    reject('wrong_transient_PG_prev', lambda r: A.R.patch(point(r, 0x17b809)['state'], 'kernel_page', 4, 0x1f6e40))
    reject('wrong_page_free_object_lock', lambda r: A.R.patch(point(r, 0x17b540)['state'], 'kernel_object', 0x10, 1))
    reject('missing_page_free_queue_lock', lambda r: point(r, 0x17b540)['state']['globals'].__setitem__('queue_lock', 0))
    reject('missing_map_write_lock', lambda r: A.R.patch(point(r, 0x17b540)['state'], 'kernel_map', 4, 0x80000))
    reject('wrong_KO_reference_final', lambda r: A.R.patch(r['after'], 'kernel_object', 0x18, 0, 2))
    reject('wrong_KO_resident_final', lambda r: A.R.patch(r['after'], 'kernel_object', 0x1a, 1, 2))
    reject('erased_KO_last_alloc', lambda r: A.R.patch(r['after'], 'kernel_object', 0x54, 0))
    reject('erased_PG_stale_object', lambda r: A.R.patch(r['after'], 'kernel_page', 0x14, 0))
    reject('wrong_PG_busy_free_template', lambda r: A.R.patch(r['after'], 'kernel_page', 0x20, 1, 1))
    reject('lost_DATA_payload', lambda r: A.R.patch(r['after'], 'frame', r['params'][2], 0, 1))
    reject('lost_DATA_dirty_metadata', lambda r: A.R.patch(r['after'], 'page', 0x1e, 0x22, 1))
    reject('erased_PT_PV_stale_KVA', lambda r: A.R.patch(r['after'], 'descriptor_arena', A.F.desc(A.PT) - A.DESC + 8, 0))
    reject('erased_EXT_stale_prev', lambda r: A.R.patch(r['after'], 'extension', 4, 0))
    reject('wrong_free_entry_stale_prev', lambda r: A.R.patch(r['after'], 'kernel_entry', 4, 0))
    reject('missing_zone_count_drop', lambda r: A.R.patch(r['after'], 'extension_zone', 8, 1))
    reject('wrong_PT_alloc_count_final', lambda r: r['after'].__setitem__('pt_alloc_count', 1))
    reject('wrong_wire_count_final', lambda r: r['after']['new_globals'].__setitem__('wire_count', 1))
    reject('missing_final_NP_invalidation', lambda r: r['after'].__setitem__('tlb_counters', [3, 3]))
    reject('wrong_callee_register', lambda r: r['after']['cpu'].__setitem__('ebx', 0))
    reject('missing_free_metadata_store', lambda r: r['writes'].remove(next(w for w in r['writes'] if w['pc'] == 0x17b5de)))
    reject('missing_trace_return', lambda r: r['observation']['trace'].pop())
    reject('reused_write_cursor', lambda r: point(r, 0x17b809).__setitem__('write_cursor', point(r, 0x17b7bc)['write_cursor']))
    def branch_write(r):
        w = next(w for w in r['writes'] if w['pc'] == 0x17b5de)
        w['pc'] = 0x17b54d
        w['trace_index'] = r['observation']['trace'].index('0x17b54d')
        r['writes'].sort(key=lambda item: item['trace_index'])
    reject('branch_cannot_write_page', branch_write)
    def stack_corruption(r, mode):
        w = next(w for w in r['writes'] if w['pc'] == 0x1911c8)
        if mode == 'wrong_return':
            w['value'] = 0xdeadbeef
        elif mode == 'missing_call':
            r['writes'].remove(w)
        elif mode == 'duplicate_call':
            r['writes'].append(copy.deepcopy(w))
        elif mode == 'push_over_return':
            next(x for x in r['writes'] if x['pc'] == 0x16b851)['address'] = w['address']
        coherent_replay(r, 'stack_memory', A.F.STACK)
        A.replay(r)  # Coherent snapshots alone must not be the rejection reason.
    for mode in ('wrong_return', 'missing_call', 'duplicate_call', 'push_over_return'):
        reject('coherent_stack_' + mode, lambda r, mode=mode: stack_corruption(r, mode))
    r = copy.deepcopy(base)
    ret_slot = next(w for w in r['writes'] if w['pc'] == 0x1911c8)['address']
    r['writes'].append(dict(pc=0x16b8d0, trace_index=r['observation']['trace'].index('0x16b8d0'),
                           address=ret_slot, width=4, value=0xdeadbeef))
    coherent_replay(r, 'stack_memory', A.F.STACK)
    A.replay(r)
    try:
        A.stack_flow(r)
    except AssertionError as error:
        assert 'actual RET word/slot' in str(error), error
        controls.append({'name': 'coherent_overwrite_actual_RET_read', 'rejected': True, 'reason': str(error)})
    else:
        raise AssertionError('RET accepted overwritten actual return word')
    def extra_pte(r, test=False):
        trace = r['observation']['trace']
        first = trace.index(hex(0x16b858 if test else 0x16b8d0))
        second = next(i for i, pc in enumerate(trace) if i > first and pc == '0x15b5e7')
        a = A.F.SHARED + ((A.KVA >> 12) & 0x3ff) * 4
        old = A.B.read_word(A.regions(r['before']), a)
        for index, value in ((first, 0), (second, old)):
            width = 1 if test and index == first else 4
            r['writes'].append(dict(pc=int(trace[index], 16), trace_index=index, address=a, width=width, value=value))
        coherent_replay(r, 'raw_translation', A.F.SHARED)
        if not test:
            A.replay(r)
    reject('coherent_extra_PTE_clear_restore', extra_pte)
    reject('coherent_TEST_fake_memory_store', lambda r: extra_pte(r, True))
    # Exercise the reverse protection itself, not only the earlier cardinality gate.
    def protect_reject(name, address, width):
        r = copy.deepcopy(base)
        r['writes'].append(dict(pc=0x16b8d0, trace_index=0, address=address, width=width, value=0))
        try:
            A.write_protection(r, True)
        except AssertionError:
            controls.append({'name': name, 'rejected': True})
        else:
            raise AssertionError('protection accepted: ' + name)
    protect_reject('PTE_partial_overlap_before_start', A.F.SHARED + ((A.KVA >> 12) & 0x3ff) * 4 - 1, 2)
    protect_reject('PT_owner_partial_overlap', A.F.desc(A.PT) + 3, 2)
    protect_reject('PT_backlink_partial_overlap', A.F.desc(A.PT) + 0xb, 2)
    for name, address in [('DATA_payload', A.DATA), ('PT_frame', A.PT), ('DATA_object', A.F.OBJ),
                          ('DATA_page_nonqueue', A.PAGE + 8), ('user_pmap', A.PMAP), ('DATA_descriptor', A.F.desc(A.DATA))]:
        protect_reject('forbidden_write_' + name, address, 1)
    out = {'all_rejected': True, 'controls': controls, 'scope': 'in-memory recorded evidence corruption, not native CPU fault injection'}
    (HERE / 'negative-controls.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps({'negative_controls_rejected': len(controls), 'all_rejected': True}))


if __name__ == '__main__':
    main()
