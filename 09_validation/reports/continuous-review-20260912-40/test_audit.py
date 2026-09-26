"""Corrupted-record controls, not executed alternative kernel inputs."""
import copy
import json
import audit_removal as A


def main():
    rows = json.loads((A.S.HERE / 'removal-cases.json').read_text())
    refs = A.S.references()
    base = rows[0]
    checks = []
    def control(name, mutate, source=base):
        row = copy.deepcopy(source)
        mutate(row)
        try:
            A.check(row, refs[tuple(row['params'])])
        except AssertionError as exc:
            checks.append({'name': name, 'rejected': True, 'reason': str(exc)})
        else:
            raise AssertionError(('corrupt evidence accepted', name))
    def point(row, pc):
        return next(p for p in row['points'] if p['pc'] == hex(pc))
    def cpu(row, pc, key, value):
        p = point(row, pc)
        p['cpu'][key] = p['state']['cpu'][key] = value
    control('prefix hash', lambda r: r['prefix32'].__setitem__('canonical_sha256', '0' * 64))
    control('claim native success', lambda r: r.__setitem__('native_cpu_verified', True))
    control('unreported input age', lambda r: A.R.patch(r['before'], 'extension', 0x1d, 8, 1))
    control('input last', lambda r: r['input'].__setitem__('last', 0))
    control('drop full scan', lambda r: r['scans'].pop())
    control('repeat scan bundle', lambda r: r['scans'].__setitem__(1, copy.deepcopy(r['scans'][0])))
    control('scan EDI', lambda r: r['scans'][0]['cpu'].__setitem__('edi', A.F.PT + 8))
    control('scan local VA', lambda r: r['scans'][0].__setitem__('local_va', A.F.VM))
    control('scan PTE bytes', lambda r: r['scans'][0].__setitem__('ptes', '01' + '00' * 7))
    control('scan EIP', lambda r: r['scans'][0]['cpu'].__setitem__('eip', 0))
    control('scan ESP', lambda r: r['scans'][0]['cpu'].__setitem__('esp', 0))
    control('scan EBP', lambda r: r['scans'][0]['cpu'].__setitem__('ebp', 0))
    control('overwritten scan local-VA write', lambda r: next(w for w in r['writes'] if w['pc'] == 0x18fa13).__setitem__('value', 0x6000))
    control('helper range', lambda r: point(r, 0x18f7f8)['args'].__setitem__(2, A.F.VA + A.F.VM))
    control('deallocate range start', lambda r: point(r, 0x190f90)['args'].__setitem__(1, A.F.VA))
    control('selected PDE index', lambda r: cpu(r, 0x1912af, 'edx', A.F.ROOTS[r['params'][0]] + 4))
    control('tick comparison operand', lambda r: cpu(r, 0x191174, 'ebx', 3))
    control('tail tick operand', lambda r: cpu(r, 0x1913db, 'ebx', 0))
    control('CR3 reload operand', lambda r: cpu(r, 0x19133e, 'eax', 0))
    control('dirty lookup page', lambda r: cpu(r, 0x18f95a, 'eax', A.F.PG))
    control('dirty PTE slot', lambda r: cpu(r, 0x18f95a, 'edi', A.F.PT))
    control('drop write', lambda r: r['writes'].pop())
    control('duplicate write', lambda r: r['writes'].append(copy.deepcopy(r['writes'][-1])))
    control('stack return word', lambda r: r['writes'][0].__setitem__('value', 0))
    control('unexpected DATA payload', lambda r: A.R.patch(r['after'], 'frame', 0, 1, 1))
    control('PT prematurely freed', lambda r: r['after'].__setitem__('pt_alloc_count', 0))
    control('kernel wire lost', lambda r: r['after']['new_globals'].__setitem__('wire_count', 0))
    control('wrong retired age', lambda r: A.R.patch(r['after'], 'extension', 0x1d, 0, 1))
    control('wrong TLB family', lambda r: r['after']['tlb_counters'].__setitem__(1, 2))
    control('dirty PV owner retained', lambda r: A.R.patch(r['after'], 'descriptor_arena', A.F.desc(A.F.DATA) - A.F.DESC + 4, A.F.PMAP))
    control('last tick not committed', lambda r: r['after']['gc_regions'].__setitem__('0x1e773c', '01000000'))
    control('false successful RET', lambda r: r['observation'].__setitem__('error', 'timeout'))
    control('missing milestone', lambda r: r['points'].pop())
    control('checkpoint ESP', lambda r: cpu(r, 0x1912f6, 'esp', 0))
    def swap_checkpoints(r):
        a, b = point(r, 0x1912e3), point(r, 0x1912eb)
        a['pc'], b['pc'] = b['pc'], a['pc']
        for p in (a, b):
            p['cpu']['eip'] = p['state']['cpu']['eip'] = int(p['pc'], 16)
    control('swapped PC and EIP checkpoints', swap_checkpoints)
    control('aging store ECX', lambda r: cpu(r, 0x1912e3, 'ecx', 0xdeadbeef))
    control('aging compare AL', lambda r: cpu(r, 0x1912eb, 'eax', 0xff))
    control('aging compare ESI', lambda r: cpu(r, 0x1912f0, 'esi', 0))
    control('aging compare flags', lambda r: cpu(r, 0x1912eb, 'eflags', 2))
    control('PDE clear ESI', lambda r: cpu(r, 0x191040, 'esi', A.F.ROOTS[r['params'][0]] + 8))
    control('PV dirty store EBX', lambda r: cpu(r, 0x18f95e, 'ebx', A.F.desc(A.F.DATA) + 4))
    control('PV reference store EBX', lambda r: cpu(r, 0x18f96a, 'ebx', A.F.desc(A.F.DATA) + 4))
    control('PV owner clear ESI', lambda r: cpu(r, 0x18f9bc, 'esi', A.F.desc(A.F.DATA) + 4))
    control('queue unlink EXT', lambda r: cpu(r, 0x19104d, 'ebx', A.F.EXT + 4))
    equal = next(r for r in rows if r['mode'] == 'equal')
    accessed = next(r for r in rows if r['mode'] == 'accessed')
    control('threshold equality removed', lambda r: r['after'].__setitem__('pt_free_count', 1), equal)
    control('accessed age not reset', lambda r: A.R.patch(r['after'], 'extension', 0x1d, 9, 1), accessed)
    A.S.save('negative-controls.json', {'controls': checks, 'all_rejected': True,
        'scope': 'record corruption rejection; no claim of mutation completeness or independent backend',
        'whole_goal_complete': False})
    print(json.dumps({'negative_controls_rejected': len(checks)}))


if __name__ == '__main__':
    main()
