"""In-memory corruption controls for the supplemental direct-call evidence."""
import copy
import json
from pathlib import Path
import audit_direct as A

HERE = Path(__file__).resolve().parent


def main():
    rows = json.loads((HERE / 'direct-cases.json').read_text())
    refs = A.references()
    base = rows[0]
    A.audit(base, refs)
    controls = []
    def reject(name, mutate, checker=None):
        row = copy.deepcopy(base)
        mutate(row)
        try:
            (checker or (lambda r: A.audit(r, refs)))(row)
        except AssertionError:
            controls.append({'name': name, 'rejected': True})
        else:
            raise AssertionError('accepted altered direct record: ' + name)
    def point(row, pc):
        return next(p for p in row['points'] if p['pc'] == hex(pc))
    def word(row, pc):
        return next(w for w in row['writes'] if w['pc'] == pc)
    patch = A.G.R.patch
    reject('prefix_hash', lambda r: r.__setitem__('prefix34_canonical_sha256', '0' * 64))
    reject('prefix_gc_page_identity', lambda r: patch(r['pre_input'], 'kernel_page', 0x24, A.DATA))
    reject('undeclared_before_DATA_reset', lambda r: patch(r['before'], 'frame', 0, 1, 1))
    reject('undeclared_PDE_residue_normalization', lambda r: r['before']['roots'].__setitem__('A', '00000000' + r['before']['roots']['A'][8:]))
    reject('wrong_caller_protection', lambda r: r['input']['words'].__setitem__(4, 1))
    reject('false_actual_fault_completion', lambda r: r.__setitem__('actual_fault_reentry_verified', True))
    reject('reported_interrupt', lambda r: r['observation']['interrupts'].append({'vector': 8}))
    reject('missing_instruction_head', lambda r: r['recorded_heads'].pop())
    reject('missing_point', lambda r: r['points'].pop(0))
    reject('false_allocated_PG', lambda r: point(r, 0x173f04)['cpu'].__setitem__('eax', A.PAGE))
    reject('false_zone_pop_KE', lambda r: point(r, 0x16b3c1)['cpu'].__setitem__('eax', A.EXT))
    reject('false_EXT_return', lambda r: point(r, 0x190d9b)['cpu'].__setitem__('eax', A.KE))
    reject('wrong_wired_args', lambda r: point(r, 0x17b6e8)['args'].__setitem__(0, A.PAGE))
    reject('zero_chunk_wrong_physical_page', lambda r: r['zero_chunks'][0].__setitem__('edx', A.DATA))
    reject('missing_zero_store', lambda r: r['writes'].remove(word(r, A.ZERO_PCS[0])))
    reject('wrong_PTE_store_width', lambda r: word(r, 0x190aa7).__setitem__('width', 1))
    reject('dirty_bit_in_new_user_PTE', lambda r: [w.__setitem__('value', w['value'] | 0x40) for w in r['writes'] if w['pc'] == 0x190aa7 and A.PT <= w['address'] < A.PT + A.VM])
    reject('alter_DATA_attr', lambda r: patch(r['after'], 'descriptor_arena', A.F.desc(A.DATA) - A.DESC + 0x10, 0))
    reject('alter_DATA_payload', lambda r: patch(r['after'], 'frame', 0, 1, 1))
    reject('wrong_KO_reference_count', lambda r: patch(r['after'], 'kernel_object', 0x18, 3, 2))
    reject('wrong_map_timestamp', lambda r: patch(r['after'], 'kernel_map', 0x4c, 4))
    reject('wrong_fault_counter', lambda r: r['after']['globals'].__setitem__('fault_count', 4))
    reject('wrong_callee_restoration', lambda r: r['after']['cpu'].__setitem__('ebx', 0))
    reject('wrong_CALL_return_word', lambda r: next(w for w in r['writes'] if A.A.instruction(w['pc']).mnemonic == 'call').__setitem__('value', 0xdeadbeef))
    reject('missing_stack_write', lambda r: r['writes'].pop(0))
    reject('wrong_final_stack_word', lambda r: patch(r['after'], 'stack_memory', A.G.CALL_STACK - A.F.STACK, 0))
    # Test the sensitive-region policy independently of store-count and final-state checks.
    def paired_write(r, address):
        r['writes'] += [dict(pc=0x16b8d0, address=address, width=4, value=0, trace_index=0),
                        dict(pc=0x16b8d0, address=address, width=4, value=3, trace_index=1)]
    reject('balanced_DATA_attr_writes_component', lambda r: paired_write(r, A.F.desc(A.DATA) + 0x10), A.write_protection)
    reject('balanced_DATA_page_writes_component', lambda r: paired_write(r, A.PAGE + 0x20), A.write_protection)
    reject('balanced_DATA_payload_writes_component', lambda r: paired_write(r, A.DATA), A.write_protection)
    reject('additional_PTE_clear_restore_component', lambda r: paired_write(r, A.F.SHARED + ((A.KVA >> 12) & 0x3ff) * 4), A.write_protection)
    reject('additional_PT_write_component', lambda r: paired_write(r, A.PT + 0x100), A.write_protection)
    # This warm direct boundary permits no unrecorded A/D changes at all.
    positive = []
    old = bytearray(A.HW)
    A.F.put(old, 0, A.DATA | 3)
    new = bytearray(old)
    A.allowed_memory({A.F.SHARED: old}, {A.F.SHARED: new}, 'A')
    positive.append('identical_translation_bytes_allowed')
    for name, address, original, altered in (
        ('NP_shared_A_not_allowed', A.F.SHARED, 0, 0x20),
        ('present_shared_AD_not_allowed', A.F.SHARED, A.DATA | 3, A.DATA | 0x63),
        ('user_PDE_A_not_allowed', A.F.ROOTS['A'], A.PT | 7, A.PT | 0x27),
        ('physical_address_change_not_allowed', A.F.SHARED, A.DATA | 3, A.PT | 0x63),
        ('clearing_existing_AD_not_allowed', A.F.SHARED, A.DATA | 0x63, A.DATA | 3)):
        before, after = original.to_bytes(4, 'little'), altered.to_bytes(4, 'little')
        try:
            A.allowed_memory({address: before}, {address: after}, 'A')
        except AssertionError:
            controls.append({'name': name, 'rejected': True})
        else:
            raise AssertionError(name)
    # Reproduced review counterexamples: keep all intermediate memory observations
    # coherent until the next real overwrite, not just an isolated JSON value.
    def coherent_middle(r, pc, address, value, field, offset):
        write = next(w for w in r['writes'] if w['pc'] == pc and w['address'] == address)
        following = next(w for w in r['writes'] if w['trace_index'] > write['trace_index'] and w['address'] == address)
        write['value'] = value
        for p in r['points']:
            if write['trace_index'] < p['trace_index'] <= following['trace_index']:
                patch(p['state'], field, offset, value)
    reject('coherent_zone_unlink_missing', lambda r: coherent_middle(r, 0x16b3c6, A.EZ + 0x10, A.KE, 'entry_zone', 0x10))
    reject('coherent_zone_count_corruption', lambda r: coherent_middle(r, 0x16b3c1, A.EZ + 8, 9, 'entry_zone', 8))
    reject('coherent_allocator_KO_lock_missing', lambda r: coherent_middle(r, 0x173eed, A.KO + 0x10, 0, 'kernel_object', 0x10))
    def unrelated_AD(r):
        key = hex(A.F.SHARED)
        raw = bytearray.fromhex(r['after']['raw_translation'][key])
        value = int.from_bytes(raw[4:8], 'little')
        raw[4:8] = (value | 0x40).to_bytes(4, 'little')
        r['after']['raw_translation'][key] = raw.hex()
    reject('unrelated_shared_AD_change', unrelated_AD)
    out = {'all_rejected': True, 'controls': controls, 'positive_components': positive,
        'actual_fault_reentry_verified': False, 'scope': 'direct-call record audit; not fault reentry'}
    (HERE / 'direct-negative-controls.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps({'rejected': len(controls), 'positive_components': len(positive)}))


if __name__ == '__main__':
    main()
