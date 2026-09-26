"""In-memory corruption controls of the new independent stack/store gates."""
import copy
import json
import review as R


def coherent_stack(row):
    start = row['injected'] if 'handler' in row else row['before']
    raw, cursor = bytearray.fromhex(start['stack_memory']), 0
    row['writes'].sort(key=lambda w: w['trace_index'])
    for p in row['points'] + [{'state': row['after'], 'trace_index': len(R.trace_of(row))}]:
        end = sum(w['trace_index'] < p['trace_index'] for w in row['writes'])
        for w in row['writes'][cursor:end]:
            off = w['address'] - R.F.STACK
            if 0 <= off and off + w['width'] <= len(raw):
                raw[off:off + w['width']] = w['value'].to_bytes(w['width'], 'little')
        p['state']['stack_memory'] = raw.hex()
        if 'pc' in p:
            p['write_cursor'] = end
            if 'saved_frame' in p:
                a = row['frame_address'] - R.F.STACK
                p['saved_frame'] = raw[a:a + len(R.F.FIELDS) * 4].hex()
        cursor = end


def main():
    base = R.rows(32)[0]
    controls, positives = [], []
    def reject(name, mutate, checker, reason=None):
        row = copy.deepcopy(base)
        mutate(row)
        try:
            checker(row)
        except AssertionError as error:
            if reason is not None:
                assert reason in str(error), (name, error)
            controls.append(dict(name=name, rejected=True, reason=str(error)))
        else:
            raise AssertionError('accepted corrupted evidence: ' + name)
    def write(row, pc):
        return next(w for w in row['writes'] if w['pc'] == pc)
    def call_change(row, kind):
        w = write(row, 0x186d63)
        if kind == 'value':
            w['value'] = 0xdeadbeef
        elif kind == 'missing':
            row['writes'].remove(w)
        elif kind == 'duplicate':
            row['writes'].append(copy.deepcopy(w))
        elif kind == 'address':
            w['address'] -= 4
        coherent_stack(row)
        R.F.replay(row)
    for kind in ('value', 'missing', 'duplicate', 'address'):
        reject('coherent_CALL_' + kind, lambda row, k=kind: call_change(row, k), R.stack_flow)
    counterexample = copy.deepcopy(base)
    call_change(counterexample, 'value')
    R.F.audit_case(counterexample)
    positives.append(dict(name='old32_full_audit_accepts_coherent_wrong_CALL_return', accepted=True,
                          meaning='confirmed old audit gap, not an acceptable execution'))
    def pushad_change(row, kind):
        step = [w for w in row['writes'] if w['pc'] == 0x186d20]
        if kind == 'saved_esp':
            step[3]['value'] = row['injected']['cpu']['esp']
        elif kind == 'missing':
            row['writes'].remove(step[0])
        elif kind == 'duplicate':
            row['writes'].append(copy.deepcopy(step[0]))
        elif kind == 'address':
            step[0]['address'] += 4
        elif kind == 'register':
            step[0]['value'] ^= 1
        coherent_stack(row)
    for kind in ('saved_esp', 'missing', 'duplicate', 'address', 'register'):
        reject('PUSHAD_' + kind, lambda row, k=kind: pushad_change(row, k), R.stack_flow, 'PUSHAD')
    for pc in (0x186d21, 0x186d22, 0x186d23, 0x186d25):
        for kind in ('value', 'width', 'address'):
            def segment_change(row, pc=pc, kind=kind):
                w = write(row, pc)
                if kind == 'value':
                    w['value'] ^= 8
                elif kind == 'width':
                    w['width'] = 2
                else:
                    w['address'] += 4
                coherent_stack(row)
            reject('segment_' + hex(pc) + '_' + kind, segment_change, R.stack_flow)
    def late_store(row, address, value, pc=0x186d6b):
        index = R.trace_of(row).index(hex(pc))
        row['writes'].append(dict(pc=pc, trace_index=index, address=address, width=4, value=value))
        coherent_stack(row)
    # Component controls bypass cardinality intentionally to exercise actual reads.
    for name, offset in (('EIP', 4), ('CS', 8), ('EFLAGS', 12)):
        reject('IRETD_actual_' + name, lambda row, off=offset: late_store(row, row['injected']['cpu']['esp'] + off, 0xdeadbeef),
               R.stack_flow, 'IRETD actual frame reads')
    reject('POPAD_actual_EBP', lambda row: late_store(row, row['frame_address'] + 24, 0), R.stack_flow, 'POPAD register')
    reject('segment_POP_actual_GS', lambda row: late_store(row, row['frame_address'], 0), R.stack_flow)
    def ret_corruption(row):
        slot = write(row, 0x186d63)['address']
        candidate = next(w for w in row['writes'] if w['trace_index'] > write(row, 0x186d63)['trace_index']
                         and R.A.instruction(w['pc']).mnemonic == 'mov')
        row['writes'].append(dict(candidate, address=slot, width=4, value=0xdeadbeef))
        coherent_stack(row)
        R.F.replay(row)
    reject('RET_actual_overwritten_word', ret_corruption, R.stack_flow, 'actual RET word/slot')
    # If POPAD incorrectly loads savedESP, this bounded component must fail.
    skipped = copy.deepcopy(base)
    late_store(skipped, skipped['frame_address'] + 28, 0xdeadbeef)
    R.stack_flow(skipped)
    positives.append(dict(name='POPAD_ignores_saved_ESP_slot_component', accepted=True,
                          meaning='stack semantics component only; full original frame/cardinality gates reject this added write'))
    for mask, name in ((1 << 17, 'VM'), (1 << 14, 'NT')):
        reject('unsupported_IRETD_' + name, lambda row, mask=mask: row['injected']['cpu'].__setitem__('eflags', row['injected']['cpu']['eflags'] | mask),
               R.stack_flow, 'VM/NT unsupported')
    reject('unsupported_privilege_change', lambda row: row['injected']['cpu'].__setitem__('cs', 11), R.stack_flow)
    def fake_test(row):
        pc = 0x187071
        row['writes'].append(dict(pc=pc, trace_index=R.trace_of(row).index(hex(pc)), address=R.F.STACK, width=1, value=0))
    reject('TEST_byte_not_store', fake_test, R.cardinality, 'store cardinality/width')
    def rep_change(row, kind):
        trace = R.trace_of(row)
        indices = [i for i, pc in enumerate(trace) if pc == '0x17b384']
        w = next(w for w in row['writes'] if w['trace_index'] == indices[0])
        if kind == 'missing':
            row['writes'].remove(w)
        elif kind == 'duplicate':
            row['writes'].append(copy.deepcopy(w))
        else:
            terminal = next(i for i in indices if trace[i + 1] != '0x17b384')
            row['writes'].append(dict(w, trace_index=terminal))
    for kind in ('missing', 'duplicate', 'terminal_store'):
        reject('REP_MOVSD_' + kind, lambda row, k=kind: rep_change(row, k), R.cardinality, 'store cardinality/width')
    reject('MOVSX_register_not_store', lambda row: row['writes'].append(dict(pc=0x192198,
        trace_index=R.trace_of(row).index('0x192198'), address=R.F.STACK, width=1, value=0)), R.cardinality)
    def actual_pop_mismatch(row, offset):
        address = row['at_fault']['cpu']['esp'] + offset
        assert not any(w['address'] < address + 4 and address < w['address'] + w['width'] for w in row['writes'])
        for state in [row['at_fault'], row['injected']] + [p['state'] for p in row['points']] + [row['after']]:
            R.G.R.patch(state, 'stack_memory', address - R.F.STACK, 0xdeadbeef)
        R.F.audit_case(row)  # This contradiction used to pass the complete old audit.
    for name, offset in (('ebx', 0), ('esi', 4), ('edi', 8)):
        reject('actual_POP_vs_final_' + name, lambda row, off=offset: actual_pop_mismatch(row, off), R.stack_flow, 'known POP/final')
    def iret_current(row, name, value):
        p = next(p for p in row['points'] if p['pc'] == '0x186d7c')
        p['cpu'][name] = p['state']['cpu'][name] = value
        R.F.audit_case(row)
    for name, value in (('eflags', 0x4202), ('cs', 0x1b), ('ss', 0x18)):
        reject('IRETD_current_unsupported_' + name, lambda row, n=name, v=value: iret_current(row, n, v), R.stack_flow)
    output = {'controls': controls, 'all_rejected': True, 'component_positive_controls': positives,
              'scope': 'deepcopy evidence corruption and explicit isolated-component controls, not native fault injection'}
    (R.HERE / 'negative-controls.json').write_text(json.dumps(output, indent=2) + '\n')
    print(json.dumps({'rejected': len(controls), 'component_positives': len(positives)}))


if __name__ == '__main__':
    main()
