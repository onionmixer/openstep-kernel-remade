"""In-memory corruption controls; preserved evidence and original code stay unchanged."""
import copy
import json
from pathlib import Path
import audit_results as A

HERE = Path(__file__).resolve().parent


def point(r, pc):
    return next(p for p in r['points'] if p['pc'] == hex(pc))


def main():
    refs = A.references()
    rows = json.loads((HERE / 'dirty-remove-cases.json').read_text())
    base = next(r for r in rows if r['params'][2] == 0x1100 and r['params'][4] == 0)
    controls = []
    def reject(name, mutate):
        r = copy.deepcopy(base)
        mutate(r)
        try:
            A.audit_case(r, refs[tuple(r['params'])])
        except AssertionError:
            controls.append({'name': name, 'rejected': True})
        else:
            raise AssertionError('accepted corrupted evidence: ' + name)
    reject('missing_prefix_store', lambda r: r['prefix']['writes'].pop())
    reject('missing_prefix_trace', lambda r: r['prefix']['handler']['trace'].pop())
    reject('wrong_prefix_frame_error', lambda r: r['prefix']['cpu_frame_input']['words'].__setitem__(0, 3))
    reject('wrong_prefix_setup_trace', lambda r: r['prefix']['setup']['queue_preparation'][0]['call']['observation']['trace'].pop())
    reject('misclaim_native_CPU', lambda r: r.__setitem__('native_cpu_frame_verified', True))
    reject('misclaim_whole_ownership', lambda r: r.__setitem__('whole_ownership_verified', True))
    reject('wrong_scenario', lambda r: r['params'].__setitem__(2, 0x100))
    reject('unreported_page_change_before_input', lambda r: A.patch(r['pre_input'], 'page', 0x1e, 2, 1))
    reject('wrong_segment_count', lambda r: A.patch(r['before'], 'physical_segments', A.SEGCOUNT - A.SEGMENTS, 1))
    reject('wrong_segment_first_index', lambda r: A.patch(r['before'], 'physical_segments', 4, (A.DATA >> 13) + 1))
    reject('wrong_segment_descriptor_base', lambda r: A.patch(r['before'], 'physical_segments', 0, A.PG))
    reject('wrong_segment_exclusive_end', lambda r: A.patch(r['before'], 'physical_segments', 0x18, A.DATA))
    reject('segment_mutated_after_boundary', lambda r: A.patch(point(r, 0x1788cc)['state'], 'physical_segments', 4, 0))
    reject('wrong_declared_input_flags', lambda r: r['input'].__setitem__('eflags', 0x602))
    reject('undeclared_call_CR3_change', lambda r: r['before']['cpu'].__setitem__('cr3', A.F.ROOTS['B']))
    reject('undeclared_FS_change', lambda r: r['before']['cpu'].__setitem__('fs', 16))
    reject('premature_DATA_free', lambda r: A.patch(r['after'], 'page', 0x1e, 8, 1))
    reject('premature_kernel_PT_unwire', lambda r: A.patch(r['after'], 'kernel_page', 0x1c, 0, 2))
    reject('premature_object_resident_drop', lambda r: A.patch(r['after'], 'object', 0x1a, 0, 2))
    reject('destroyed_DATA_payload', lambda r: A.patch(r['after'], 'frame', r['params'][2], 0, 1))
    reject('erased_PV_stale_VA', lambda r: A.patch(r['after'], 'descriptor_arena', A.F.desc(A.DATA) - A.DESC + 8, 0))
    reject('lost_reference_attribute', lambda r: A.patch(r['after'], 'descriptor_arena', A.F.desc(A.DATA) - A.DESC + 0x10, 1, 1))
    reject('wrong_PT_free_count', lambda r: r['after'].__setitem__('pt_free_count', 0))
    reject('pretended_PT_backing_free', lambda r: r['after'].__setitem__('pt_alloc_count', 0))
    reject('wrong_DATA_active_count', lambda r: r['after']['globals'].__setitem__('active_count', 0))
    reject('wrong_wire_global', lambda r: r['after']['new_globals'].__setitem__('wire_count', 0))
    reject('wrong_lookup_representative_phys', lambda r: point(r, 0x178894)['args'].__setitem__(0, A.DATA + A.HW))
    def wrong_return(r):
        for pc in (0x1788f0, 0x18f95a):
            p = point(r, pc)
            p['cpu']['eax'] = p['state']['cpu']['eax'] = A.PG
    reject('wrong_lookup_return_consistent_CPU_views', wrong_return)
    reject('wrong_lookup_segment_cpu', lambda r: point(r, 0x1788cc)['cpu'].__setitem__('edi', A.SEGMENTS + 0x1c))
    reject('HW_count_used_as_VM_count', lambda r: point(r, 0x190f90)['args'].__setitem__(2, 2))
    reject('missing_first_PTE_clear', lambda r: r['writes'].remove(next(w for w in r['writes'] if w['pc'] == 0x18f96e)))
    reject('wrong_clean_store_target', lambda r: next(w for w in r['writes'] if w['pc'] == 0x18f95a).__setitem__('address', A.PG + 0x1e))
    reject('wrong_clean_store_width', lambda r: next(w for w in r['writes'] if w['pc'] == 0x18f95a).__setitem__('width', 4))
    reject('PDE_full_clear_instead_of_present_bit', lambda r: next(w for w in r['writes'] if w['pc'] == 0x191040).__setitem__('value', 0))
    reject('omitted_invalidation_checkpoint', lambda r: r['points'].remove(point(r, 0x18faac)))
    reject('wrong_invalidation_VA', lambda r: point(r, 0x18faac)['cpu'].__setitem__('edx', A.VA + A.HW))
    reject('reused_checkpoint_index', lambda r: point(r, 0x18f95e).__setitem__('trace_index', point(r, 0x18f95a)['trace_index']))
    reject('reused_write_cursor', lambda r: point(r, 0x18f95e).__setitem__('write_cursor', point(r, 0x18f95a)['write_cursor']))
    reject('premature_free_PT_queue', lambda r: point(r, 0x19104d)['state'].__setitem__('pt_free_queue', [A.EXT, A.EXT]))
    reject('missing_queue_store', lambda r: r['writes'].remove(next(w for w in r['writes'] if w['pc'] == 0x191074)))
    def branch_store(r):
        w = next(w for w in r['writes'] if w['pc'] == 0x191074)
        w['pc'] = 0x191030
        w['trace_index'] = r['observation']['trace'].index('0x191030')
    reject('branch_cannot_write_queue', branch_store)
    reject('changed_recover_lifetime', lambda r: r['after'].__setitem__('recover', 0))
    reject('wrong_callee_register', lambda r: r['after']['cpu'].__setitem__('ebx', 0))
    reject('missing_original_return', lambda r: r['observation']['trace'].pop())
    result = {'all_rejected': True, 'controls': controls, 'scope': 'in-memory recorded-evidence corruption, not native hardware fault injection'}
    (HERE / 'negative-controls.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'negative_controls_rejected': len(controls), 'all_rejected': True}))


if __name__ == '__main__':
    main()
