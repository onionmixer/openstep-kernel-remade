"""Contrast an explicit event reading of canonical C with original trace.

This is a Python model of the displayed statement order, NOT C execution or
an assertion about a specific compiler's treatment of out/LOCK/UNLOCK helpers.
"""
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent


def main():
    audit = json.loads((HERE / 'call-review.json').read_text())
    source = audit['original_contexts']['0018c7b0']['decompiled_c']
    needles = ['out(0x4d0,(char)uVar4);', 'out(0x4d1,(char)(uVar4 >> 8));',
               '_DAT_001e7618 = _DAT_001e7618 + 2;', 'DAT_001e7720 = uVar4;']
    lines = source.splitlines()
    locs = {n: [i + 1 for i, line in enumerate(lines) if n in line] for n in needles}
    assert all(len(v) == 1 for v in locs.values())
    assert [locs[n][0] for n in needles] == sorted(locs[n][0] for n in needles)
    rows = []
    for index, case in enumerate(audit['executions']):
        if not case['mode_changed']:
            continue
        old = int(case['old_counter'], 16)
        old_mode = int(case['initial_mode'], 16)
        new_mode = case['observed']['mode']
        counter_at_entry = (old + 1) & 0xffffffff
        c_events = [
            {'kind': 'out', 'port': '0x4d0', 'size': 1, 'value': new_mode & 0xff,
             'mode_at_out': old_mode, 'counter_at_out': counter_at_entry},
            {'kind': 'out', 'port': '0x4d1', 'size': 1, 'value': new_mode >> 8,
             'mode_at_out': old_mode, 'counter_at_out': counter_at_entry},
            {'kind': 'write', 'address': '0x1e7618', 'size': 4, 'value': (counter_at_entry + 2) & 0xffffffff},
            {'kind': 'write', 'address': '0x1e7720', 'size': 2, 'value': new_mode}]
        # Initial INC belongs to the enclosing unregister suffix, not change_mode.
        actual = case['events'][1:]
        assert actual != c_events
        actual_out = [e for e in actual if e['kind'] == 'out']
        model_out = [e for e in c_events if e['kind'] == 'out']
        assert [(e['port'], e['value']) for e in actual_out] == [(e['port'], e['value']) for e in model_out]
        assert actual_out[1]['counter_at_out'] != model_out[1]['counter_at_out']
        assert all(a['mode_at_out'] != b['mode_at_out'] for a, b in zip(actual_out, model_out))
        actual_counter = [e for e in actual if e['kind'] == 'write' and e['address'] == '0x1e7618']
        model_counter = [e for e in c_events if e['kind'] == 'write' and e['address'] == '0x1e7618']
        assert actual_counter[-1]['value'] == model_counter[-1]['value'] == case['observed']['counter']
        rows.append({'execution_index': index, 'original_events': actual, 'displayed_c_order_model': c_events,
                     'same_final_mode_and_counter': True, 'same_port_values': True,
                     'different_intermediate_state': True,
                     'original_counter_stores': len(actual_counter), 'model_counter_stores': len(model_counter)})
    summary = {'changed_path_comparisons': len(rows),
               'different_event_sequences': sum(r['different_intermediate_state'] for r in rows),
               'same_final_state_and_port_values': len(rows),
               'decompiled_c_executed': False, 'canonical_export_modified': False}
    result = {'summary': summary, 'canonical_c_line_numbers': locs, 'comparisons': rows,
              'limits': ['The display-order model treats LOCK/UNLOCK as markers; their runtime definitions are absent.',
                         'No compiler-codegen or hardware claim; final-state equality is insufficient to prove ordering fidelity.',
                         'Original mode update and two counter INCs are proven by bytes and bounded execution.',
                         'No proposed volatile/IR repair is applied by this report.']}
    (HERE / 'order-review.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
