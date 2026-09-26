"""Corrupted-record controls for the explicitly modeled PD lifecycle."""
import copy
import json
import struct
import audit_pd as A


def main():
    rows = json.loads((A.S.HERE / 'pd-cases.json').read_text())
    refs = A.S.references()
    baseline = rows[0]
    controls = []
    def stage(row, label):
        return next(s for s in row['stages'] if s['label'] == label)
    def point(row, label, pc):
        return next(p for p in stage(row, label)['points'] if p['pc'] == hex(pc))
    def cpu(row, label, pc, key, value):
        p = point(row, label, pc)
        p['cpu'][key] = p['state']['cpu'][key] = value
    def control(name, mutate, source=baseline):
        row = copy.deepcopy(source)
        mutate(row)
        try:
            A.lifecycle(row, refs[tuple(row['params'][:2])])
        except AssertionError as exc:
            controls.append({'name': name, 'rejected': True, 'reason': str(exc)})
        else:
            raise AssertionError(('corruption accepted', name))
    control('native claim', lambda r: r.__setitem__('native_cpu_verified', True))
    control('prefix identity', lambda r: r['prefix31'].__setitem__('before_sha256', '0' * 64))
    control('unreported seed', lambda r: r['seeded']['pd_regions'].__setitem__('0x1f7abc', '00000000'))
    control('inter-call backing edit', lambda r: A.patch(stage(r, 'create_slot1')['pre_input'], 'new_pt_frame', 0, 1, 1))
    control('wrong caller', lambda r: stage(r, 'destroy_first')['args'].__setitem__(0, A.S.PMAPS[1]))
    control('unchanged scheduler tick', lambda r: stage(r, 'gc_empty').__setitem__('tick', 5))
    control('drop lifecycle stage', lambda r: r['stages'].pop())
    control('drop original write', lambda r: stage(r, 'gc_empty')['writes'].pop())
    control('duplicate original write', lambda r: stage(r, 'gc_empty')['writes'].append(copy.deepcopy(stage(r, 'gc_empty')['writes'][-1])))
    control('CALL stack word', lambda r: next(w for w in stage(r, 'create_slot0')['writes'] if A.A.instruction(w['pc']).mnemonic == 'call').__setitem__('value', 0))
    control('checkpoint PC swap', lambda r: point(r, 'create_slot0', 0x18f54e).__setitem__('pc', '0x18f57d'))
    control('copy record omitted', lambda r: stage(r, 'create_slot0')['copies'].pop())
    control('copy source EAX', lambda r: stage(r, 'create_slot0')['copies'][0]['cpu'].__setitem__('eax', A.B.KR + 4))
    control('copy source ESI', lambda r: stage(r, 'create_slot0')['copies'][0]['cpu'].__setitem__('esi', 0))
    control('copy destination EDX', lambda r: stage(r, 'create_slot0')['copies'][0]['cpu'].__setitem__('edx', A.B.KVA))
    control('copy ESP', lambda r: stage(r, 'create_slot0')['copies'][0]['cpu'].__setitem__('esp', 0))
    control('copy EBP', lambda r: stage(r, 'create_slot0')['copies'][0]['cpu'].__setitem__('ebp', 0))
    control('copy CR3', lambda r: stage(r, 'create_slot0')['copies'][0]['cpu'].__setitem__('cr3', A.B.PT))
    control('copy physical walk', lambda r: stage(r, 'create_slot0')['copies'][0]['destination_walk'].__setitem__('physical', hex(A.B.KVA)))
    control('erase backing dirty bit', lambda r: stage(r, 'create_slot0')['copies'][1]['destination_walk'].__setitem__('pte', hex(A.B.PT | 0x203)))
    control('second slot BSF source', lambda r: cpu(r, 'create_slot1', 0x18f461, 'eax', 0))
    control('second slot BSF index', lambda r: cpu(r, 'create_slot1', 0x18f476, 'ebx', 0))
    control('destroy bitmap slot', lambda r: cpu(r, 'destroy_first', 0x18f797, 'ecx', 1))
    control('destroy bitmap EA', lambda r: cpu(r, 'destroy_first', 0x18f797, 'edx', A.B.EXT + 4))
    control('partial GC queue cursor', lambda r: cpu(r, 'gc_partial_first', 0x1911fe, 'ecx', A.S.PD_HEAD))
    control('dirty lookup PAGE', lambda r: cpu(r, 'gc_empty', 0x18fcbe, 'eax', A.B.PAGE))
    control('empty GC last tick', lambda r: cpu(r, 'gc_empty', 0x1913db, 'ebx', 0))
    control('premature PD free', lambda r: stage(r, 'gc_partial_first')['after']['pd_regions'].__setitem__('0x1f7aa0', '00' * 16))
    control('lost bitmap', lambda r: A.patch(stage(r, 'create_slot1')['after'], 'extension', 0x1c, 1, 1))
    control('old clean PT result', lambda r: A.patch(stage(r, 'gc_empty')['after'], 'kernel_page', 0x1e, 0x28, 1))
    control('zero after free', lambda r: stage(r, 'gc_empty')['after'].__setitem__('new_pt_frame', bytes(A.B.VM).hex()))
    control('stale EXT cleared', lambda r: stage(r, 'gc_empty')['after'].__setitem__('extension', bytes(0x20).hex()))
    reverse = next(r for r in rows if r['params'] == ['A', 1, 1])
    def wrong_hint(r):
        s = stage(r, 'gc_empty')['after']
        raw = bytearray.fromhex(s['pd_regions'][hex(A.S.ZONE)])
        raw[0xc:0x10] = A.S.PMAPS[1].to_bytes(4, 'little')
        s['pd_regions'][hex(A.S.ZONE)] = raw.hex()
    control('last_insert is not tail', wrong_hint, reverse)
    def coherent_stale_mapping(r):
        s = stage(r, 'gc_empty')
        fixes = []
        for index, w in enumerate(s['writes']):
            if w['pc'] == 0x18fcd8:
                w['value'] = (A.B.PT + len(fixes) * A.B.HW) | 3
                fixes.append((index, w['address'], w['value']))
        for p in s['points'] + [{'state': s['after'], 'write_cursor': len(s['writes'])}]:
            state = p['state']
            raw = bytearray.fromhex(state['raw_translation'][hex(A.B.SHARED)])
            for index, address, val in fixes:
                if index < p['write_cursor']:
                    struct.pack_into('<I', raw, address - A.B.SHARED, val)
            state['raw_translation'][hex(A.B.SHARED)] = raw.hex()
            mem = A.B.regions(state)
            state['new_walks'] = {name: [A.B.walk(mem, root, va + off) for off in range(0, A.B.VM, A.B.HW)]
                for name, root, va in [('kernel_low', A.B.KR, A.B.KVA),
                    ('kernel_high', A.B.ROOTS[r['params'][0]], A.B.BASE + A.B.KVA),
                    ('frame_high', A.B.ROOTS[r['params'][0]], A.B.BASE + A.B.PT),
                    ('user', A.B.ROOTS[r['params'][0]], A.B.VA)]}
    control('coherent stale mapping after PG free', coherent_stale_mapping)
    control('PDE backing clear ESI', lambda r: cpu(r, 'gc_empty', 0x18fcd8, 'esi', A.B.SHARED))
    control('GC descriptor backlink EA', lambda r: cpu(r, 'gc_empty', 0x191220, 'eax', A.B.desc(A.B.PT) + 4))
    A.S.save('negative-controls.json', {'controls': controls, 'all_rejected': True,
        'scope': 'corrupted records, not alternate original executions or exhaustive mutation coverage', 'whole_goal_complete': False})
    print(json.dumps({'negative_controls_rejected': len(controls)}))


if __name__ == '__main__':
    main()
