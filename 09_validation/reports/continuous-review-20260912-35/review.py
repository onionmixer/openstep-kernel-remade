"""Read-only consumer regression: original-byte store counts and actual stack flow.

No producer imports/runs. Not a complete GPR/flags/effective-address emulator.
"""
import collections
import importlib.util
import json
from pathlib import Path
import struct
from verify_artifacts import preserved

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PRIOR = HERE.parent / 'continuous-review-20260912-34'
spec = importlib.util.spec_from_file_location('audit34', PRIOR / 'audit_results.py')
G = importlib.util.module_from_spec(spec)
spec.loader.exec_module(G)
A, F, B = G.A, G.F, G.B
X = A.capstone.x86
SOURCES = {31: ('continuous-review-20260911-31', 'new-pt-cases.json'),
           32: ('continuous-review-20260911-32', 'fault-new-pt-cases.json'),
           33: ('continuous-review-20260911-33', 'dirty-remove-cases.json'),
           34: ('continuous-review-20260912-34', 'gc-cases.json')}


def rows(number):
    directory, filename = SOURCES[number]
    return json.loads((HERE.parent / directory / filename).read_text())


def trace_of(row):
    return row['handler' if 'handler' in row else 'observation']['trace']


def cardinality(row):
    trace = trace_of(row)
    by = collections.defaultdict(list)
    for w in row['writes']:
        assert 0 <= w['trace_index'] < len(trace) and trace[w['trace_index']] == hex(w['pc'])
        assert w['width'] in (1, 2, 4) and 0 <= w['value'] < 1 << (8 * w['width'])
        by[w['trace_index']].append(w)
    rep_runs, rep_at = [], []
    for index, pc in enumerate(trace):
        ins = A.instruction(int(pc, 16))
        if ins.mnemonic == 'pushal':
            assert ins.bytes == bytes.fromhex('60') and int(pc, 16) == 0x186d20
            widths = [4] * 8
        elif ins.mnemonic in ('popal', 'iretd', 'cld'):
            assert not ins.operands
            widths = []
        elif ins.mnemonic == 'push' and ins.op_str in ('ds', 'es', 'fs', 'gs'):
            assert int(pc, 16) in (0x186d21, 0x186d22, 0x186d23, 0x186d25)
            widths = [4]  # Recorded backend writes full slot; not all native CPUs.
        elif ins.mnemonic in ('movzx', 'movsx', 'setne'):
            assert ins.operands[0].type == X.X86_OP_REG
            widths = []
        elif ins.mnemonic == 'rep movsd':
            assert int(pc, 16) == 0x17b384 and ins.bytes == bytes.fromhex('f3a5')
            rep_at.append(index)
            more = index + 1 < len(trace) and trace[index + 1] == pc
            widths = [4] if more else []
            if not more:
                # Original17b37f loads ECX=0xc. Last callback observes ECX=0.
                load = A.instruction(0x17b37f)
                assert load.mnemonic == 'mov' and load.op_str == 'ecx, 0xc'
                assert len(rep_at) == load.operands[1].imm + 1
                rep_runs.append(rep_at)
                rep_at = []
        else:
            width = G.memory_write_width(ins)
            widths = [width] if width else []
        assert [w['width'] for w in by[index]] == widths, ('store cardinality/width', pc, index)
    assert not rep_at
    return {'heads': len(trace), 'writes': len(row['writes']), 'rep_runs': len(rep_runs)}


def stack_flow(row):
    trap = 'handler' in row
    start = row['injected'] if trap else row['before']
    obs = row['handler'] if trap else row['observation']
    trace = [int(pc, 16) for pc in obs['trace']]
    raw = bytearray.fromhex(start['stack_memory'])
    sp, bp, ebx = (start['cpu'][k] for k in ('esp', 'ebp', 'ebx'))
    root_slot = row['before']['cpu']['esp'] if trap else sp
    frames = [(root_slot, F.STOP)]
    by = collections.defaultdict(list)
    for w in row['writes']:
        assert 0 <= w['trace_index'] < len(trace) and w['pc'] == trace[w['trace_index']]
        by[w['trace_index']].append(w)
    points = {p['trace_index']: p for p in row['points']}
    stats = dict(calls=0, returns=0, pushes=0, pushad=0, popad=0, segment_pushes=0, segment_pops=0, iretd=0)
    heads, trap_base = [], None
    restored_segments = {}
    known = {k: None for k in ('eax', 'ecx', 'edx', 'esi', 'edi')}
    aliases = {'eax': {'eax', 'ax', 'al', 'ah'}, 'ecx': {'ecx', 'cx', 'cl', 'ch'},
               'edx': {'edx', 'dx', 'dl', 'dh'}, 'esi': {'esi', 'si', 'sil'}, 'edi': {'edi', 'di', 'dil'}}
    def read(address):
        assert F.STACK <= address and address + 4 <= F.STACK + len(raw), ('stack capture', hex(address))
        return struct.unpack_from('<I', raw, address - F.STACK)[0]
    assert read(root_slot) == F.STOP
    if trap:
        # The interrupted copy prefix contains no outstanding nested CALL.
        F.C.trace_check(row['fault']['trace'][:-1], row['at_fault']['cpu']['eip'])
        assert start['cpu']['cs'] == 8 and start['cpu']['ss'] == 16
        assert start['cpu']['eflags'] & ((1 << 17) | (1 << 14)) == 0, 'VM/NT unsupported'
        assert row['native_cpu_frame_verified'] is False
    for index, pc in enumerate(trace):
        ins, step = A.instruction(pc), by[index]
        nxt = trace[index + 1] if index + 1 < len(trace) else F.STOP
        assert F.STACK <= sp <= F.STACK + len(raw)
        heads.append(sp)
        if index in points:
            p = points[index]
            assert p['cpu'] == p['state']['cpu']
            assert (p['cpu']['esp'], p['cpu']['ebp']) == (sp, bp), ('stack checkpoint', hex(pc))
            if ebx is not None:
                assert p['cpu']['ebx'] == ebx, ('known POP/checkpoint', hex(pc), 'ebx')
            for name, value in known.items():
                if value is not None:
                    assert p['cpu'][name] == value, ('known POP/checkpoint', hex(pc), name)
            if trap:
                assert p['cpu']['cs'] == 8 and p['cpu']['ss'] == 16, 'unsupported checkpoint CS/SS'
        _, modified = ins.regs_access()
        names = {ins.reg_name(r) for r in modified}
        for name, family in aliases.items():
            if names & family:
                known[name] = None
        touched = names & {'esp', 'sp', 'spl', 'ebp', 'bp', 'bpl'}
        assert not touched & {'sp', 'spl', 'bp', 'bpl'}
        previous_ebx = ebx
        if names & {'ebx', 'bx', 'bl', 'bh'}:
            ebx = None  # Do not seed unknown arithmetic from checkpoint observations.
        handled = False
        if ins.mnemonic == 'pushal':
            assert trap and pc == 0x186d20 and stats['pushad'] == 0
            order = ('edi', 'esi', 'ebp', 'esp', 'ebx', 'edx', 'ecx', 'eax')
            expected = [(sp - 32 + i * 4, 4, sp if k == 'esp' else start['cpu'][k]) for i, k in enumerate(order)]
            assert [(w['address'], w['width'], w['value']) for w in step] == expected, 'PUSHAD slots/saved ESP'
            sp -= 32
            stats['pushad'] += 1
            handled = True
        elif ins.mnemonic in ('push', 'call'):
            assert len(step) == 1 and step[0]['address'] == sp - 4 and step[0]['width'] == 4, ('stack implicit slot', hex(pc))
            value = step[0]['value']
            if ins.mnemonic == 'call':
                assert ins.operands[0].type == X.X86_OP_IMM and nxt == ins.operands[0].imm
                assert value == pc + ins.size, ('CALL return word', hex(pc))
                frames.append((sp - 4, value))
                stats['calls'] += 1
            else:
                op = ins.operands[0]
                if op.type == X.X86_OP_IMM:
                    assert value == op.imm & 0xffffffff
                else:
                    assert op.type == X.X86_OP_REG
                    name = ins.reg_name(op.reg)
                    push_known = {'esp': sp, 'ebp': bp, 'ebx': previous_ebx}.get(name)
                    if name in ('ds', 'es', 'fs', 'gs'):
                        assert trap and pc in (0x186d21, 0x186d22, 0x186d23, 0x186d25)
                        push_known = start['cpu'][name]
                        stats['segment_pushes'] += 1
                    else:
                        assert op.size == 4
                    if push_known is not None:
                        assert value == push_known, ('known PUSH value', hex(pc), name)
                stats['pushes'] += 1
            sp -= 4
            handled = True
        elif ins.mnemonic == 'pop':
            assert not step and len(ins.operands) == 1 and ins.operands[0].type == X.X86_OP_REG
            name = ins.reg_name(ins.operands[0].reg)
            assert name in ('eax', 'ecx', 'edx', 'ebp', 'ebx', 'esi', 'edi', 'ds', 'es', 'fs', 'gs')
            value = read(sp)
            if name == 'ebp':
                bp = value
            if name == 'ebx':
                ebx = value
            if name in known:
                known[name] = value
            if name in ('ds', 'es', 'fs', 'gs'):
                assert trap and pc in (0x186d72, 0x186d74, 0x186d76, 0x186d77)
                assert value & 0xffff == start['cpu'][name]
                restored_segments[name] = value & 0xffff
                stats['segment_pops'] += 1
            sp += 4
            handled = True
        elif ins.mnemonic == 'popal':
            assert trap and pc == 0x186d78 and not step and stats['popad'] == 0
            for i, name in enumerate(('edi', 'esi', 'ebp', 'esp', 'ebx', 'edx', 'ecx', 'eax')):
                if name != 'esp':  # POPAD ignores the saved original ESP slot.
                    assert read(sp + i * 4) == start['cpu'][name], ('POPAD register', name)
                    if name in known:
                        known[name] = read(sp + i * 4)
            bp, ebx = read(sp + 8), read(sp + 16)
            sp += 32
            stats['popad'] += 1
            handled = True
        elif ins.mnemonic == 'iretd':
            assert trap and pc == 0x186d7c and not step and stats['iretd'] == 0
            assert index in points
            current = points[index]['cpu']
            assert current['eflags'] & ((1 << 17) | (1 << 14)) == 0, 'IRETD current VM/NT unsupported'
            assert current['cs'] == 8 and current['ss'] == 16, 'IRETD current CS/SS unsupported'
            assert frames == [(root_slot, F.STOP)], 'unreturned handler CALL at IRETD'
            assert sp == start['cpu']['esp'] + 4, 'IRETD actual SP'
            expected = (row['at_fault']['cpu']['eip'], start['cpu']['cs'], start['cpu']['eflags'])
            assert tuple(read(sp + i * 4) for i in range(3)) == expected, 'IRETD actual frame reads'
            assert nxt == expected[0] and expected[1] & 3 == 0
            assert restored_segments == {k: start['cpu'][k] for k in ('ds', 'es', 'fs', 'gs')}
            sp += 12
            assert sp == row['at_fault']['cpu']['esp']
            stats['iretd'] += 1
            handled = True
        elif ins.mnemonic == 'ret':
            assert not ins.operands and not step and frames
            slot, expected = frames.pop()
            assert sp == slot and read(sp) == expected == nxt, ('actual RET word/slot', hex(pc))
            sp += 4
            stats['returns'] += 1
            handled = True
        elif ins.mnemonic == 'mov' and touched:
            assert not step
            if ins.op_str == 'ebp, esp':
                bp = sp
            elif ins.op_str == 'esp, ebp':
                sp = bp
            else:
                assert trap and pc == 0x186d69 and ins.op_str == 'esp, ebx'
                assert previous_ebx is not None and previous_ebx == trap_base, 'callee-restored trap-base EBX'
                sp = previous_ebx
            handled = True
        elif ins.mnemonic in ('add', 'sub') and touched:
            assert not step and ins.operands[0].type == X.X86_OP_REG and ins.reg_name(ins.operands[0].reg) == 'esp'
            assert ins.operands[1].type == X.X86_OP_IMM
            sp = (sp + (ins.operands[1].imm if ins.mnemonic == 'add' else -ins.operands[1].imm)) & 0xffffffff
            handled = True
        elif ins.mnemonic == 'lea' and touched:
            assert not step
            dst, src = ins.operands
            assert dst.type == X.X86_OP_REG and dst.size == 4 and src.type == X.X86_OP_MEM and not src.mem.index and not src.mem.segment
            d, b = ins.reg_name(dst.reg), ins.reg_name(src.mem.base)
            if d == 'esp' and b == 'ebp':
                sp = (bp + src.mem.disp) & 0xffffffff
            else:
                assert trap and pc == 0x186d40 and d == 'ebp' and b == 'esp'
                bp = (sp + src.mem.disp) & 0xffffffff
            handled = True
        if trap and pc == 0x186d4a:
            assert ins.op_str == 'ebx, esp'
            ebx = trap_base = sp
            assert trap_base == row['frame_address']
        assert handled or not touched, ('unsupported stack effect', hex(pc), ins.mnemonic, ins.op_str)
        for w in step:
            off = w['address'] - F.STACK
            if 0 <= off and off + w['width'] <= len(raw):
                raw[off:off + w['width']] = w['value'].to_bytes(w['width'], 'little')
    assert not frames and (sp, bp) == (row['after']['cpu']['esp'], row['after']['cpu']['ebp'])
    if ebx is not None:
        assert row['after']['cpu']['ebx'] == ebx, ('known POP/final', 'ebx')
    for name, value in known.items():
        if value is not None:
            assert row['after']['cpu'][name] == value, ('known POP/final', name)
    assert raw.hex() == row['after']['stack_memory']
    assert min(heads) == obs['observed_esp_min'] and max(heads) == obs['observed_esp_max']
    assert stats['iretd'] == int(trap)
    return stats


def main():
    preservation = preserved()
    refs = G.references()
    refs32 = G.R.references()
    result = []
    for number in SOURCES:
        for index, row in enumerate(rows(number)):
            if number == 31:
                B.audit_case(row)
            elif number == 32:
                F.audit_case(row)
            elif number == 33:
                G.R.audit_case(row, refs32[tuple(row['params'])])
            else:
                G.audit_case(row, refs[tuple(row['params'])])
            counts = cardinality(row)
            stack = stack_flow(row)
            result.append(dict(report=number, index=index, original_audit_passed=True, cardinality=counts, stack=stack))
        print(json.dumps({'report': number, 'rows_checked': len(rows(number))}), flush=True)
    output = {'cases': result, 'all_passed': True, 'whole_goal_complete': False,
              'scope': 'read-only recorded31..34 regression; full original audit plus bounded store/stack model; not native CPU or full EA/flags'}
    (HERE / 'consumer-regression.json').write_text(json.dumps(output, indent=2) + '\n')
    assert preserved() == preservation
    (HERE / 'preservation.json').write_text(json.dumps(preservation, indent=2) + '\n')


if __name__ == '__main__':
    main()
