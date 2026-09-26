"""Independent raw-Mach-O/state audit of recorded GC, without executor imports.

Compact prefix identity relies on producer full-row equality to preserved report33.
The independent new write/state audit begins at the explicit GC input boundary.
"""
import copy
import hashlib
import importlib.util
import itertools
import json
from pathlib import Path
import struct
from verify_artifacts import digest

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PRIOR = HERE.parent / 'continuous-review-20260911-33'
spec = importlib.util.spec_from_file_location('audit33', PRIOR / 'audit_results.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)
F, B, C, A = R.F, R.B, R.C, R.A
VM, HW, PAGE, PG, DATA, PT, VA, PMAP, DESC, EXT = R.VM, R.HW, R.PAGE, R.PG, R.DATA, R.PT, R.VA, R.PMAP, R.DESC, R.EXT
KO, KM, KE, KVA, KP, EZ, XZ, HASH = F.KO, F.KM, F.KE, F.KVA, F.KP, F.EZ, F.XZ, F.HASH
CALL_STACK, PD_HEAD, FREE_PT = R.CALL_STACK, 0x1f7aa8, R.FREE_PT
NARGS = {0x191144: 0, 0x16b84c: 2, 0x173e90: 3, 0x1765ac: 3, 0x176164: 3,
         0x1735f4: 2, 0x190c24: 2, 0x190b5c: 3, 0x178894: 1, 0x17b7bc: 1,
         0x1914c8: 4, 0x179bbc: 3, 0x18fb0c: 1, 0x17b540: 1, 0x17b5f8: 1,
         0x178c64: 1, 0x18fa44: 3, 0x190f90: 5}
MILESTONES = set(NARGS) | {0x191171, 0x19117c, 0x1911b9, 0x1911cd, 0x1911e4, 0x1911f0,
    0x191260, 0x1913db, 0x190c03, 0x173660, 0x1788cc, 0x1788f0, 0x17b809,
    0x17645d, 0x18fbf1, 0x18fc55, 0x18fc9f, 0x18fcd8, 0x18fd17,
    0x179c0d, 0x17b5ee, 0x176481, 0x18faa5, 0x18f8b9, 0x178cb4, 0x178d57, 0x17658c, 0x1765ef}
GCSIZES = {0x1f653c: 4, 0x1e773c: 4, 0x1f7aa0: 0x10, 0x1e25fc: 0x1e2618 - 0x1e25fc, 0x1dfd78: 4}


def canonical(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(',', ':')).encode()).hexdigest()


def references():
    for item in json.loads((PRIOR / 'artifact-hashes.json').read_text()):
        p = ROOT / item['path']
        assert p.stat().st_size == item['size'] and digest(p) == item['sha256'], p
    source = (PRIOR / 'dirty_remove_review.py').read_text()
    expected = source.replace("    save('latest-diagnostic.json', result)\n", '')
    expected = expected.replace('    return result\n\n\ndef main():', '    return uc, result\n\n\ndef main():').split('\n\ndef main():')[0]
    assert (HERE / 'dirty_prefix.py').read_text().rstrip() == expected.rstrip()
    rows = json.loads((PRIOR / 'dirty-remove-cases.json').read_text())
    return {tuple(r['params']): {'row': r, 'hash': canonical(r)} for r in rows}


def regions(s):
    result = R.regions(s)
    assert set(s['gc_regions']) == {hex(a) for a in GCSIZES}
    for a, size in GCSIZES.items():
        raw = bytes.fromhex(s['gc_regions'][hex(a)])
        assert len(raw) == size
        result[a] = raw
    return result


def gcval(s, a):
    return B.read_word(regions(s), a)


def bridge(row, ref):
    p = tuple(row['params'])
    assert p == tuple(ref['row']['params'])
    assert p in set(itertools.product(F.ROOTS, F.COPY, (0x100, 0x1100), (2, 0x602), (1, 0)))
    assert (row['last'], row['tick']) in ((1, 3), (0, 3), (1, 1), (1, 2))
    if (row['last'], row['tick']) != (1, 3):
        assert p[1:] == ('_copyout', 0x100, 2, 1)
    assert row['prefix33'] == {'canonical_sha256': ref['hash'],
        'scope': 'producer full-row equality; independent GC audit starts at explicit-input boundary'}
    expected = copy.deepcopy(ref['row']['after'])
    expected['gc_regions'] = {hex(a): (A.original(a, size) if a in (0x1e25fc, 0x1dfd78) else bytes(size)).hex()
                              for a, size in GCSIZES.items()}
    assert row['pre_input'] == expected, 'prefix33 projection or pre-seed GC controls'
    seeds = [[0x1f653c, [row['tick']]], [0x1e773c, [row['last']]], [0x1f7aa0, [0, 0, PD_HEAD, PD_HEAD]]]
    assert row['input'] == {'seeds': seeds, 'call_stack': CALL_STACK, 'stack_words': [F.STOP], 'eflags': 2}
    for a, words in seeds:
        expected['gc_regions'][hex(a)] = struct.pack('<' + 'I' * len(words), *words).hex()
    R.patch(expected, 'stack_memory', CALL_STACK - F.STACK, F.STOP)
    expected['cpu'].update(R.CALLEE, esp=CALL_STACK, eflags=2)
    assert row['before'] == expected, 'unreported GC input change'
    last, tick = gcval(row['before'], 0x1e773c), gcval(row['before'], 0x1f653c)
    return tick - (tick if last == 0 else last)


def memory_write_width(ins):
    """Bounded opcode/operand model: Capstone marks TEST memory as WRITE wrongly.

    This checks store cardinality/width, not general effective addresses or values.
    Unsupported opcodes or unobserved memory-destination forms fail closed.
    """
    supported = set('add and call cli cmp dec inc invlpg ja jae jb jbe je jg jge jle jmp jne lea mov neg nop not or pop push ret sar shl shr sti sub test xchg xor'.split())
    assert ins.mnemonic in supported, ('unsupported write-effect opcode', ins.mnemonic)
    mem = [op for op in ins.operands if op.type == A.capstone.x86.X86_OP_MEM]
    if ins.mnemonic in ('push', 'call'):
        assert len(ins.operands) == 1 and ins.operands[0].size == 4
        return 4
    if ins.mnemonic == 'xchg':
        assert len(mem) <= 1
        return mem[0].size if mem else 0
    if ins.mnemonic in ('mov', 'add', 'and', 'dec', 'inc', 'or', 'sub'):
        return ins.operands[0].size if ins.operands[0].type == A.capstone.x86.X86_OP_MEM else 0
    if ins.mnemonic in ('neg', 'not', 'sar', 'shl', 'shr', 'xor', 'pop'):
        assert not mem, ('unobserved memory destination', ins.mnemonic)
    return 0


def write_cardinality(row):
    by_index = {}
    for w in row['writes']:
        by_index.setdefault(w['trace_index'], []).append(w)
    for index, pc in enumerate(row['observation']['trace']):
        width = memory_write_width(A.instruction(int(pc, 16)))
        step = by_index.get(index, [])
        assert len(step) == int(bool(width)), ('instruction write cardinality', pc, index)
        if width:
            assert step[0]['width'] == width, ('instruction write width', pc, index)


def write_protection(row, gc):
    def overlap(w, address, size):
        return w['address'] < address + size and address < w['address'] + w['width']
    ptes = [F.SHARED + ((KVA + i) >> 12 & 0x3ff) * 4 for i in range(0, VM, HW)]
    for a in ptes:
        old = B.read_word(regions(row['before']), a)
        expected = [(0x190c03, a + 1, 1, (old >> 8 & 0xff) & 0xfd), (0x18fcd8, a, 4, 0)] if gc else []
        found = [w for w in row['writes'] if overlap(w, a, 4)]
        assert [(w['pc'], w['address'], w['width'], w['value']) for w in found] == expected, ('PTE write protection', hex(a))
    for offset, pc in ((4, 0x18fc9f), (0xc, 0x1911b9)):
        a = F.desc(PT) + offset
        found = [w for w in row['writes'] if overlap(w, a, 4)]
        expected = [(pc, a, 4, 0)] if gc else []
        assert [(w['pc'], w['address'], w['width'], w['value']) for w in found] == expected, ('PT descriptor write protection', hex(a))
    protected = [(DATA, VM), (PT, VM), (F.OBJ, 0x58), (PAGE + 8, 0x30 - 8), (PMAP, 0x1c), (F.desc(DATA), 0x14)]
    for a, size in protected:
        assert not any(overlap(w, a, size) for w in row['writes']), ('write to preserved region', hex(a))


def replay(row):
    memories = {a: bytearray(raw) for a, raw in regions(row['before']).items()}
    trace, writes = row['observation']['trace'], row['writes']
    assert [w['trace_index'] for w in writes] == sorted(w['trace_index'] for w in writes)
    for w in writes:
        assert 0 <= w['trace_index'] < len(trace) and trace[w['trace_index']] == hex(w['pc'])
        assert w['width'] in (1, 2, 4) and 0 <= w['value'] < 1 << (w['width'] * 8)
        ins = A.instruction(w['pc'])
        if ins.mnemonic in ('call', 'push'):
            assert w['width'] == 4 and F.STACK <= w['address'] and w['address'] + 4 <= 0x710004
        else:
            assert memory_write_width(ins) == w['width'], ('not original memory store', w)
    cursor = 0
    for point in row['points'] + [{'state': row['after'], 'trace_index': len(trace), 'write_cursor': len(writes)}]:
        end = point['write_cursor']
        assert cursor <= end <= len(writes)
        assert end == sum(w['trace_index'] < point['trace_index'] for w in writes)
        for w in writes[cursor:end]:
            matches = [(a, raw) for a, raw in memories.items() if a <= w['address'] and w['address'] + w['width'] <= a + len(raw)]
            assert matches, ('uncaptured write', w)
            for a, raw in matches:
                off = w['address'] - a
                raw[off:off + w['width']] = w['value'].to_bytes(w['width'], 'little')
        actual_regions = regions(point['state'])
        assert set(actual_regions) == set(memories)
        for a, expected in memories.items():
            actual = actual_regions[a]
            assert len(actual) == len(expected)
            if a in (F.SHARED, F.ROOTS[row['params'][0]]):
                for off in range(0, len(actual), 4):
                    old, new = struct.unpack_from('<I', expected, off)[0], struct.unpack_from('<I', actual, off)[0]
                    if a == F.SHARED and off not in [((KVA + i) >> 12 & 0x3ff) * 4 for i in range(0, VM, HW)]:
                        allow = 0x60 if old & 1 else 0
                    elif a == F.ROOTS[row['params'][0]] and off >= (F.BASE >> 22) * 4:
                        allow = 0x20 if old & 1 else 0
                    else:
                        allow = 0
                    assert new | old == new and (new ^ old) & ~allow == 0, (hex(a + off), hex(old), hex(new))
            else:
                assert actual == expected, ('write replay', hex(a), point.get('pc', 'after'))
            memories[a] = bytearray(actual)
        cursor = end


def stack_flow(row):
    """Track original ESP/EBP and actual return words, not only an abstract call graph.

    Restricted to the observed ordinary 32-bit prologue/epilogue opcodes. Unsupported
    stack-pointer operations, partial writes, IRET and alternate stacks fail closed.
    """
    trace = [int(pc, 16) for pc in row['observation']['trace']]
    raw = bytearray.fromhex(row['before']['stack_memory'])
    sp, bp = row['before']['cpu']['esp'], row['before']['cpu']['ebp']
    frames = [(sp, F.STOP)]
    by_index = {}
    for w in row['writes']:
        by_index.setdefault(w['trace_index'], []).append(w)
    points = {p['trace_index']: p for p in row['points']}
    sp_heads = []
    pushes, calls, returns = 0, 0, 0
    def read(a):
        assert F.STACK <= a and a + 4 <= F.STACK + len(raw), ('stack read outside capture', hex(a))
        return struct.unpack_from('<I', raw, a - F.STACK)[0]
    assert read(sp) == F.STOP
    for index, pc in enumerate(trace):
        ins = A.instruction(pc)
        nxt = trace[index + 1] if index + 1 < len(trace) else F.STOP
        assert F.STACK <= sp <= F.STACK + len(raw)
        sp_heads.append(sp)
        if index in points:
            assert points[index]['cpu']['esp'] == sp and points[index]['cpu']['ebp'] == bp, ('ESP/EBP model', hex(pc))
        step = by_index.get(index, [])
        _, modified = ins.regs_access()
        touched = {ins.reg_name(r) for r in modified} & {'esp', 'sp', 'spl', 'ebp', 'bp', 'bpl'}
        assert not touched & {'sp', 'spl', 'bp', 'bpl'}, ('partial stack register', hex(pc))
        handled = False
        if ins.mnemonic in ('push', 'call'):
            assert len(step) == 1, ('exactly one implicit stack write', hex(pc))
            w = step[0]
            assert w['pc'] == pc and w['address'] == sp - 4 and w['width'] == 4, ('implicit stack slot', hex(pc))
            if ins.mnemonic == 'call':
                assert ins.operands[0].type == A.capstone.x86.X86_OP_IMM
                assert w['value'] == pc + ins.size, ('CALL return word', hex(pc))
                frames.append((sp - 4, pc + ins.size))
                calls += 1
            else:
                op = ins.operands[0]
                assert op.size == 4
                if op.type == A.capstone.x86.X86_OP_IMM:
                    assert w['value'] == op.imm & 0xffffffff
                elif op.type == A.capstone.x86.X86_OP_REG:
                    name = ins.reg_name(op.reg)
                    if name in ('esp', 'ebp'):
                        assert w['value'] == (sp if name == 'esp' else bp)
                else:
                    raise AssertionError(('unsupported PUSH operand', hex(pc)))
                pushes += 1
            sp -= 4
            handled = True
        elif ins.mnemonic == 'pop':
            assert not step and len(ins.operands) == 1
            op = ins.operands[0]
            assert op.type == A.capstone.x86.X86_OP_REG and op.size == 4
            name = ins.reg_name(op.reg)
            assert name in ('ebp', 'ebx', 'esi', 'edi'), ('unsupported POP', hex(pc))
            if name == 'ebp':
                bp = read(sp)
            sp += 4
            handled = True
        elif ins.mnemonic == 'ret':
            assert not ins.operands and not step and frames, ('unsupported RET', hex(pc))
            slot, expected = frames.pop()
            assert sp == slot and read(sp) == expected == nxt, ('actual RET word/slot', hex(pc), hex(sp))
            sp += 4
            returns += 1
            handled = True
        elif ins.mnemonic == 'mov' and touched:
            assert ins.op_str in ('ebp, esp', 'esp, ebp') and not step
            if ins.op_str == 'ebp, esp':
                bp = sp
            else:
                sp = bp
            handled = True
        elif ins.mnemonic in ('add', 'sub') and touched:
            assert ins.operands[0].type == A.capstone.x86.X86_OP_REG and ins.reg_name(ins.operands[0].reg) == 'esp'
            assert ins.operands[0].size == 4 and ins.operands[1].type == A.capstone.x86.X86_OP_IMM and not step
            sp = (sp + (ins.operands[1].imm if ins.mnemonic == 'add' else -ins.operands[1].imm)) & 0xffffffff
            handled = True
        elif ins.mnemonic == 'lea' and touched:
            op = ins.operands[1]
            assert ins.reg_name(ins.operands[0].reg) == 'esp' and ins.operands[0].size == 4
            assert op.type == A.capstone.x86.X86_OP_MEM and ins.reg_name(op.mem.base) == 'ebp' and not op.mem.index and not op.mem.segment and not step
            sp = (bp + op.mem.disp) & 0xffffffff
            handled = True
        assert handled or not touched, ('unsupported stack register effect', hex(pc), ins.mnemonic, ins.op_str)
        for w in step:
            off = w['address'] - F.STACK
            if 0 <= off and off + w['width'] <= len(raw):
                raw[off:off + w['width']] = w['value'].to_bytes(w['width'], 'little')
    assert not frames
    assert sp == row['after']['cpu']['esp'] and bp == row['after']['cpu']['ebp']
    assert raw.hex() == row['after']['stack_memory']
    assert row['observation']['observed_esp_min'] == min(sp_heads)
    assert row['observation']['observed_esp_max'] == max(sp_heads)
    return {'calls': calls, 'pushes': pushes, 'returns': returns}


def after_model(row, gc):
    before, after = row['before'], row['after']
    e = copy.deepcopy(before)
    e['gc_regions'][hex(0x1e773c)] = struct.pack('<I', row['tick']).hex()
    if gc:
        for off in (0, 4):
            R.patch(e, 'kernel_object', off, KO)
        R.patch(e, 'kernel_object', 0x18, 1, 2)
        R.patch(e, 'kernel_object', 0x1a, 0, 2)
        for off in (0, 4):
            R.patch(e, 'kernel_page', off, F.FREE)
        R.patch(e, 'kernel_page', 0x1c, 0, 2)
        R.patch(e, 'kernel_page', 0x1e, 0x28, 1)
        R.patch(e, 'kernel_page', 0x20, 0, 1)
        for off in (0x10, 0x14):
            R.patch(e, 'kernel_pmap', off, 0)
        for off in (0xc, 0x10, 0x40):
            R.patch(e, 'kernel_map', off, KM + 0xc)
        for off in (0x1c, 0x28):
            R.patch(e, 'kernel_map', off, 0)
        R.patch(e, 'kernel_map', 0x4c, F.value(before, 'kernel_map', 0x4c) + 1)
        R.patch(e, 'kernel_entry', 0, 0)
        R.patch(e, 'kernel_entry', 0x28, 0, 2)
        for field, element in (('entry_zone', KE), ('extension_zone', EXT)):
            R.patch(e, field, 8, 0)
            R.patch(e, field, 0xc, element)
            R.patch(e, field, 0x10, element)
        R.patch(e, 'extension', 0, 0)
        for off in (4, 0xc):
            R.patch(e, 'descriptor_arena', F.desc(PT) - DESC + off, 0)
        R.patch(e, 'buckets', ((KO + (KVA >> 13)) & 7) * 8 + 4, 0)
        e['globals']['free_count'] = 1
        e['new_globals']['wire_count'] = 0
        e['queues']['free'] = [PG, PG]
        e['pt_free_queue'], e['pt_free_count'], e['pt_alloc_count'] = [FREE_PT, FREE_PT], 0, 0
        e['tlb_counters'] = [v + 2 for v in before['tlb_counters']]
        for i in range(0, VM, HW):
            R.patch(e['raw_translation'], hex(F.SHARED), ((KVA + i) >> 12 & 0x3ff) * 4, 0)
    # Validate permitted shared aliases independently; never excuse KVA changes as hardware.
    for field, key in (('raw_translation', hex(F.SHARED)), ('roots', row['params'][0])):
        expected, observed = bytes.fromhex(e[field][key]), bytes.fromhex(after[field][key])
        for off in range(0, len(expected), 4):
            old, new = struct.unpack_from('<I', expected, off)[0], struct.unpack_from('<I', observed, off)[0]
            if field == 'raw_translation' and off not in [((KVA + i) >> 12 & 0x3ff) * 4 for i in range(0, VM, HW)]:
                allow = 0x60 if old & 1 else 0
            elif field == 'roots' and off >= (F.BASE >> 22) * 4:
                allow = 0x20 if old & 1 else 0
            else:
                allow = 0
            assert new | old == new and (new ^ old) & ~allow == 0
        e[field][key] = after[field][key]
    for key in ('cpu', 'stack_memory', 'new_walks', 'data_high_walks'):
        e[key] = after[key]  # Separately checked by ABI, replay, raw-table walks.
    assert after == e, 'final GC ownership/state model'
    for k, v in R.CALLEE.items():
        assert after['cpu'][k] == v
    for k in ('cs', 'ds', 'es', 'ss', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4'):
        assert after['cpu'][k] == before['cpu'][k]
    assert after['cpu']['eip'] == F.STOP and after['cpu']['esp'] == CALL_STACK + 4
    assert after['cpu']['eflags'] & 0x600 == (0x200 if gc else 0)
    assert after['cpu']['eax'] == struct.unpack('<I', A.original(0x1e2600, 4))[0]


def audit_case(row, ref):
    delta = bridge(row, ref)
    gc = delta > 1
    assert row['failure'] is None and row['native_cpu_verified'] is False and row['whole_ownership_verified'] is False
    obs, writes = row['observation'], row['writes']
    trace = obs['trace']
    assert obs['error'] is None and not obs['interrupts'] and obs['after'] == row['after']['cpu']
    assert trace == row['recorded_heads'] and trace[0] == '0x191144'
    C.trace_check(trace, F.STOP)
    forbid = {0x10ca6c, 0x163320, 0x1631a0, 0x16b790, 0x178d60, 0x179084, 0x1790dc, 0x179764,
              0x18b59b, 0x18b5dc, 0x18b5ef, 0x191205, 0x19129f, 0x17b99c, 0x191428, 0x1019c0,
              0x18fc5c, 0x18faac, 0x18fc3e, 0x18fa90}
    assert not any(int(pc, 16) in forbid for pc in trace)
    assert [p['trace_index'] for p in row['points']] == [i for i, pc in enumerate(trace) if int(pc, 16) in MILESTONES]
    for s in [row['before']] + [p['state'] for p in row['points']] + [row['after']]:
        F.contract(s, ref['row']['prefix'])
        assert s['physical_segments'] == R.segment_model()
        assert s['gc_regions'][hex(0x1e25fc)] == A.original(0x1e25fc, GCSIZES[0x1e25fc]).hex()
    for p in row['points']:
        assert trace[p['trace_index']] == p['pc'] and p['cpu'] == p['state']['cpu'] and p['cpu']['eip'] == int(p['pc'], 16)
        if int(p['pc'], 16) in NARGS:
            mem = regions(p['state'])
            assert p['args'] == [B.read_word(mem, p['cpu']['esp'] + 4 + i * 4) for i in range(NARGS[int(p['pc'], 16)])]
    def points(pc):
        return [p for p in row['points'] if p['pc'] == hex(pc)]
    def one(pc):
        p = points(pc)
        assert len(p) == 1, hex(pc)
        return p[0]
    assert one(0x191171)['cpu']['ebx'] == delta
    tail = one(0x191260)
    assert B.read_word(regions(tail['state']), tail['cpu']['ebp'] - 8) == delta
    assert one(0x1913db)['cpu']['ebx'] == delta
    initial_last = row['tick'] if row['last'] == 0 else row['last']
    assert gcval(one(0x191171)['state'], 0x1e773c) == initial_last
    tick_writes = [(w['pc'], w['address'], w['width'], w['value']) for w in writes if w['address'] == 0x1e773c]
    expected_tick = ([(0x19115c, 0x1e773c, 4, row['tick'])] if row['last'] == 0 else []) + [(0x1913db, 0x1e773c, 4, row['tick'])]
    assert tick_writes == expected_tick
    calls = [(int(p['pc'], 16), p['args']) for p in row['points'] if int(p['pc'], 16) in NARGS]
    expected_calls = [(0x191144, [])]
    if gc:
        expected_calls += [(0x16b84c, [XZ, EXT]), (0x173e90, [KM, KVA, VM]), (0x1765ac, [KM, KVA, KVA + VM]),
            (0x176164, [KM, KVA, KVA + VM]), (0x1735f4, [KM, KE]), (0x190c24, [KP, KVA]),
            (0x190b5c, [KP, KVA, 0]), (0x178894, [PT]), (0x17b7bc, [PG]),
            (0x1914c8, [KP, KVA, KVA + VM, 1]), (0x179bbc, [KO, KVA, KVA + VM]), (0x18fb0c, [PT]),
            (0x190f90, [KP, KVA, 1, 0, 1]), (0x17b540, [PG]), (0x17b5f8, [PG]),
            (0x18fa44, [KP, KVA, KVA + VM]), (0x190f90, [KP, KVA, 0, 0, 1]),
            (0x178c64, [KO]), (0x16b84c, [EZ, KE])]
    assert calls == expected_calls
    if gc:
        assert len(points(0x19117c)) == 2 and len(points(0x1788cc)) == 2
        search = points(0x1788cc)
        assert [p['cpu']['edi'] for p in search] == [R.SEGMENTS, R.SEGMENTS + 0x1c]
        for p in search:
            assert p['cpu']['ebx'] == PT and p['cpu']['esi'] == PT >> (VM.bit_length() - 1)
            assert p['cpu']['edx'] == p['cpu']['edi'] + 4 and p['cpu']['eax'] == R.SEGCOUNT
        assert one(0x1788f0)['cpu']['eax'] == R.physical_lookup(search[-1]['state']['physical_segments'], PT) == PG
        assert one(0x173660)['cpu']['eax'] == PG and one(0x173660)['cpu']['esi'] == PT
        at = one(0x173660)
        assert B.read_word(regions(at['state']), at['cpu']['esp']) == PT
        pte = [F.SHARED + ((KVA + i) >> 12 & 0x3ff) * 4 for i in range(0, VM, HW)]
        old = [B.read_word(regions(row['before']), a) for a in pte]
        expected_stores = {0x190c03: [(a + 1, 1, (v >> 8 & 0xff) & 0xfd) for a, v in zip(pte, old)],
            0x18fcd8: [(a, 4, 0) for a in pte], 0x1911b9: [(F.desc(PT) + 0xc, 4, 0)],
            0x18fc9f: [(F.desc(PT) + 4, 4, 0)]}
        for pc, expected in expected_stores.items():
            found = [w for w in writes if w['pc'] == pc]
            assert [(w['address'], w['width'], w['value']) for w in found] == expected, hex(pc)
            assert [w['trace_index'] for w in found] == [p['trace_index'] for p in points(pc)]
        assert [p['cpu']['edx'] for p in points(0x190c03)] == [a + 1 for a in pte]
        assert [p['cpu']['eax'] & 0xff for p in points(0x190c03)] == [v for _, _, v in expected_stores[0x190c03]]
        assert [p['cpu']['esi'] for p in points(0x18fcd8)] == pte
        assert one(0x1911b9)['cpu']['eax'] == one(0x18fc9f)['cpu']['edi'] == F.desc(PT)
        assert points(0x190c03)[-1]['trace_index'] < one(0x18fbf1)['trace_index'] < points(0x18fcd8)[0]['trace_index']
        for a, v in zip(pte, old):
            assert B.read_word(regions(one(0x18fbf1)['state']), a) == v & ~0x200
        assert [p['cpu']['edx'] for p in points(0x18fc55)] == [KVA + i for i in range(0, VM, HW)]
        assert [p['cpu']['edx'] for p in points(0x18faa5)] == [KVA + i for i in range(0, VM, HW)]
        assert points(0x18fc55)[-1]['trace_index'] < one(0x18fc9f)['trace_index'] < points(0x18fcd8)[0]['trace_index']
        assert one(0x1911b9)['trace_index'] < points(0x16b84c)[0]['trace_index'] < one(0x173e90)['trace_index']
        assert one(0x17b809)['trace_index'] < one(0x179bbc)['trace_index'] < one(0x17b540)['trace_index'] < one(0x18fa44)['trace_index']
        assert one(0x18fa44)['trace_index'] < one(0x178c64)['trace_index'] < points(0x16b84c)[1]['trace_index'] < one(0x1911e4)['trace_index']
        assert one(0x18f8b9)['trace_index'] > one(0x18fa44)['trace_index']
        for a in pte:
            assert B.read_word(regions(one(0x18fa44)['state']), a) == 0
        active = one(0x17b809)['state']
        assert active['queues']['active'] == [PAGE, PG] and active['globals']['active_count'] == 2
        assert F.value(active, 'page', 0) == PG and F.value(active, 'page', 4) == 0x1f6e40
        assert F.value(active, 'kernel_page', 0) == 0x1f6e40 and F.value(active, 'kernel_page', 4) == PAGE
        assert F.value(active, 'kernel_page', 0x1c, 'H') == 0 and F.value(active, 'kernel_page', 0x1e, 'B') == 0x22
        for pc in (0x17b7bc, 0x17b809, 0x179bbc, 0x17b540, 0x17b5ee, 0x176481, 0x178c64):
            s = one(pc)['state']
            assert F.value(s, 'kernel_object', 0x10) == 0
            assert F.value(s, 'kernel_map', 4) == 0xa0000
            assert s['globals']['queue_lock'] == int(pc in (0x17b7bc, 0x17b809, 0x17b540, 0x17b5ee))
        freed = one(0x17b5ee)['state']
        assert freed['queues']['active'] == [PAGE, PAGE] and freed['queues']['free'] == [PG, PG]
        assert freed['globals']['active_count'] == freed['globals']['free_count'] == 1
        assert F.value(freed, 'kernel_page', 0x1e, 'B') == 0x28 and F.value(freed, 'kernel_page', 0x20, 'B') == 0
        held = one(0x178cb4)['state']
        assert F.value(held, 'kernel_object', 0x18, 'H') == 1
        assert F.value(held, 'kernel_object', 0x10) == held['globals']['object_cache_lock'] == 1
        released = one(0x178d57)['state']
        assert F.value(released, 'kernel_object', 0x10) == released['globals']['object_cache_lock'] == 0
        assert F.value(one(0x1765ef)['state'], 'kernel_map', 4) == 0x80000
    else:
        assert [p['pc'] for p in row['points']] == list(map(hex, (0x191144, 0x191171, 0x191260, 0x1913db)))
    write_cardinality(row)
    write_protection(row, gc)
    replay(row)
    stack = stack_flow(row)
    after_model(row, gc)
    return {'params': row['params'], 'last': row['last'], 'tick': row['tick'], 'passed': True,
            'gc_executed': gc, 'gc_heads': len(trace), 'pte_wired_clears': sum(w['pc'] == 0x190c03 for w in writes),
            'pte_clears': sum(w['pc'] == 0x18fcd8 for w in writes), 'stack_flow': stack}


def main():
    refs = references()
    rows = json.loads((HERE / 'gc-cases.json').read_text())
    matrix = {(p, 1, 3) for p in itertools.product(F.ROOTS, F.COPY, (0x100, 0x1100), (2, 0x602), (1, 0))}
    matrix |= {((t, '_copyout', 0x100, 2, 1), last, tick) for t in F.ROOTS for last, tick in ((0, 3), (1, 1), (1, 2))}
    assert len(rows) == len(matrix) and {(tuple(r['params']), r['last'], r['tick']) for r in rows} == matrix
    result = [audit_case(r, refs[tuple(r['params'])]) for r in rows]
    out = {'all_passed': True, 'cases': result, 'scope': 'recorded GC boundary onward; compact prefix producer equality, not native CPU/full ownership'}
    (HERE / 'independent-audit.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps({'independently_audited_cases': len(result), 'all_passed': True}))


if __name__ == '__main__':
    main()
