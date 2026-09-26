"""Conservative, scoped provenance review; not a general x86 verifier.

Reads original bytes and preserved analysis. Writes diagnostics only here.
All explicit calculations use Python. Unknown values are retained as unknown.
"""
import collections
import csv
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('previous_review', HERE.parent / 'cautious-followup-20260911/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)
from capstone import CS_GRP_JUMP, CS_GRP_RET, CS_AC_WRITE
from capstone.x86_const import X86_OP_REG, X86_OP_MEM, X86_OP_IMM

REGS = ('eax', 'ebx', 'ecx', 'edx', 'esi', 'edi', 'ebp', 'esp')
PARENT = {small: full for full, smalls in {
    'eax': ('eax', 'ax', 'al', 'ah'), 'ebx': ('ebx', 'bx', 'bl', 'bh'),
    'ecx': ('ecx', 'cx', 'cl', 'ch'), 'edx': ('edx', 'dx', 'dl', 'dh'),
    'esi': ('esi', 'si'), 'edi': ('edi', 'di'), 'ebp': ('ebp', 'bp'), 'esp': ('esp', 'sp')
}.items() for small in smalls}


def plus(value, delta):
    return (value[0], value[1] + delta) if value and value[0] in ('stack', 'const') else value if delta == 0 else None


def default_stack(offset):
    return ('arg', offset) if offset >= 4 and offset % 4 == 0 else None


class State:
    def __init__(self):
        self.reg = {r: None for r in REGS}
        self.reg['esp'] = ('stack', 0)
        self.stack = {}

    def copy(self):
        s = State()
        s.reg, s.stack = self.reg.copy(), self.stack.copy()
        return s

    def merge(self, other):
        before = (self.reg.copy(), self.stack.copy())
        for r in REGS:
            if self.reg[r] != other.reg[r]:
                self.reg[r] = None
        for off in self.stack.keys() | other.stack.keys():
            a, b = self.stack.get(off, default_stack(off)), other.stack.get(off, default_stack(off))
            self.stack[off] = a if a == b else None
        return before != (self.reg, self.stack)

    def address(self, ins, op):
        if op.mem.segment:
            return None
        base = self.reg.get(ins.reg_name(op.mem.base)) if op.mem.base else ('const', 0)
        index = self.reg.get(ins.reg_name(op.mem.index)) if op.mem.index else ('const', 0)
        if index and index[0] == 'const':
            return plus(base, op.mem.disp + index[1] * op.mem.scale)
        return None

    def read_memory(self, address, size=4):
        if not address or size != 4:
            return None
        if address[0] == 'stack':
            return self.stack.get(address[1], default_stack(address[1]))
        if address == ('const', 0x1e8b54):
            return ('active_thread', 0)
        return None

    def get(self, ins, op):
        if op.type == X86_OP_IMM:
            return ('const', op.imm)
        if op.type == X86_OP_REG:
            return self.reg.get(ins.reg_name(op.reg)) if op.size == 4 else None
        if op.type == X86_OP_MEM:
            return self.read_memory(self.address(ins, op), op.size)
        return None

    def write_memory(self, address, size, value):
        if address and address[0] == 'stack':
            start = address[1]
            # Invalidate overlapping word slots, including partial writes.
            for slot in range(start // 4 * 4, start + size, 4):
                self.stack[slot] = value if size == 4 and start == slot else None

    def put(self, ins, op, value):
        if op.type == X86_OP_REG:
            parent = PARENT.get(ins.reg_name(op.reg))
            if parent:
                self.reg[parent] = value if op.size == 4 else None
        elif op.type == X86_OP_MEM:
            self.write_memory(self.address(ins, op), op.size, value)


def transfer(ins, before):
    s = before.copy()
    ops, mnemonic = ins.operands, ins.mnemonic
    if mnemonic == 'mov':
        s.put(ins, ops[0], before.get(ins, ops[1]))
    elif mnemonic == 'lea':
        s.put(ins, ops[0], before.address(ins, ops[1]))
    elif mnemonic == 'push':
        value = before.get(ins, ops[0])
        s.reg['esp'] = plus(s.reg['esp'], -ops[0].size)
        s.write_memory(s.reg['esp'], ops[0].size, value)
    elif mnemonic == 'pop':
        value = before.read_memory(before.reg['esp'], ops[0].size)
        s.reg['esp'] = plus(s.reg['esp'], ops[0].size)
        s.put(ins, ops[0], value)
    elif mnemonic in ('add', 'sub') and ops[1].type == X86_OP_IMM:
        delta = ops[1].imm if mnemonic == 'add' else -ops[1].imm
        s.put(ins, ops[0], plus(before.get(ins, ops[0]), delta))
    elif mnemonic == 'xor' and ops[0].type == X86_OP_REG and ops[1].type == X86_OP_REG and ops[0].reg == ops[1].reg:
        s.put(ins, ops[0], ('const', 0))
    elif mnemonic == 'call':
        # Normal cdecl call/return summary; special nonlocal returns are outside
        # this model. Callee stack alias writes are not modeled.
        for r in ('eax', 'ecx', 'edx'):
            s.reg[r] = None
    elif mnemonic == 'leave':
        s.reg['esp'] = plus(before.reg['ebp'], 4)
        s.reg['ebp'] = before.read_memory(before.reg['ebp'])
    else:
        for reg in ins.regs_access()[1]:
            parent = PARENT.get(ins.reg_name(reg))
            if parent:
                s.reg[parent] = None
        for op in ops:
            if op.type == X86_OP_MEM and op.access & CS_AC_WRITE:
                s.write_memory(before.address(ins, op), op.size, None)
    return s


def flow(entry):
    insns = R.function_instructions(entry)
    incoming, queue = {entry: State()}, collections.deque([entry])
    exits = set()
    steps = 0
    while queue:
        a = queue.popleft()
        ins = insns[a]
        after = transfer(ins, incoming[a])
        steps += 1
        if steps > 100000:
            raise RuntimeError(('nonconvergence', hex(entry)))
        if ins.group(CS_GRP_RET) or ins.mnemonic.startswith('iret'):
            successors = []
        elif ins.group(CS_GRP_JUMP):
            successors = [ins.operands[0].imm] if ins.operands[0].type == X86_OP_IMM else []
            if not successors:
                exits.add((a, 'indirect-jump-not-expanded'))
            if ins.mnemonic != 'jmp':
                successors.append(a + ins.size)
        else:
            successors = [a + ins.size]
        for nxt in successors:
            if nxt not in insns:
                exits.add((a, hex(nxt)))
                continue
            if nxt not in incoming:
                incoming[nxt] = after.copy()
                queue.append(nxt)
            elif incoming[nxt].merge(after):
                queue.append(nxt)
    calls, writes = [], []
    for a, ins in insns.items():
        state = incoming.get(a)
        if ins.mnemonic == 'call':
            calls.append({'site': hex(a), 'target': hex(ins.operands[0].imm) if ins.operands[0].type == X86_OP_IMM else None,
                          'assembly': ins.mnemonic + ' ' + ins.op_str,
                          'arg1': state.read_memory(state.reg['esp']) if state else None,
                          'reached': state is not None})
        if ins.operands and ins.operands[0].type == X86_OP_MEM and ins.operands[0].mem.disp == 0x74 and ins.operands[0].access & CS_AC_WRITE:
            writes.append({'site': hex(a), 'assembly': ins.mnemonic + ' ' + ins.op_str,
                           'base': state.reg.get(ins.reg_name(ins.operands[0].mem.base)) if state else None,
                           'source': state.get(ins, ins.operands[1]) if state and len(ins.operands) > 1 else None,
                           'reached': state is not None})
    return {'entry': hex(entry), 'name': R.FMAP[entry]['name'], 'calls': calls, 'writes_74': writes,
            'unexpanded_edges': [{'from': hex(a), 'to': b} for a, b in sorted(exits)],
            'instruction_count': len(insns), 'reached_instructions': len(incoming), 'iterations': steps}


def model_tests():
    checks = []
    # Independent short instruction fixtures, decoded by the same ISA decoder.
    fixtures = [
        ('frame_arg1', '5589e58b7d08', 'edi', ('arg', 4)),
        ('active_thread', 'a1548b1e00', 'eax', ('active_thread', 0)),
        ('partial_register_kill', 'a1548b1e0066b80100', 'eax', None),
        ('normal_call_preserves_edi', '5589e58b7d08e800000000', 'edi', ('arg', 4)),
        ('normal_call_kills_eax', 'a1548b1e00e800000000', 'eax', None),
    ]
    for name, raw, reg, expected in fixtures:
        state = State()
        for ins in R.CS.disasm(bytes.fromhex(raw), 0x1000):
            state = transfer(ins, state)
        assert state.reg[reg] == expected, (name, state.reg)
        checks.append(name)
    a, b = State(), State()
    a.reg['edi'], b.reg['edi'] = ('arg', 4), ('active_thread', 0)
    assert a.merge(b) and a.reg['edi'] is None
    checks.append('conflicting_paths_become_unknown')
    a = State()
    a.write_memory(('stack', 4), 2, ('const', 0))
    assert a.read_memory(('stack', 4)) is None
    checks.append('partial_argument_write_invalidates_word')
    return checks


def dispatch_and_paths(results, candidates):
    instructions = R.function_instructions(R.NAMES['_PCemulateREAL'])
    rotate, load, call = instructions[0x1a2635], instructions[0x1a2650], instructions[0x1a2668]
    assert rotate.mnemonic == 'add' and rotate.operands[0].size == 1 and rotate.operands[1].imm == 0x70
    assert load.mnemonic == 'mov' and load.operands[1].mem.disp == 0x1e4b80 and load.operands[1].mem.scale == 4
    assert call.mnemonic == 'call' and call.operands[0].type == X86_OP_REG
    table_bytes = R.read_original(load.operands[1].mem.disp, 256 * 4)
    slots = struct.unpack('<256I', table_bytes)
    rows = [{'index': i, 'opcode': hex((i - rotate.operands[1].imm) & 0xff),
             'slot_address': hex(load.operands[1].mem.disp + i * 4), 'target': hex(v),
             'target_name': R.FMAP[v]['name'] if v in R.FMAP else None}
            for i, v in enumerate(slots) if v]
    assert all(int(r['target'], 16) in results for r in rows)
    edges = []
    for entry, result in results.items():
        for c in result['calls']:
            if c['target'] and int(c['target'], 16) in results:
                edges.append({'from_entry': hex(entry), 'to_entry': c['target'], 'site': c['site'],
                              'kind': 'direct', 'arg1': c['arg1']})
            if int(c['site'], 16) == call.address:
                assert c['arg1'] == ('arg', 4)
                edges.extend({'from_entry': hex(entry), 'to_entry': r['target'], 'site': c['site'],
                              'kind': 'original-file-dispatch-table', 'opcode': r['opcode'], 'arg1': c['arg1']}
                             for r in rows)
    paths = {}
    # Seed only an actual active-thread argument at an observed call site.
    for e in edges:
        if e['arg1'] == ('active_thread', 0):
            paths[int(e['to_entry'], 16)] = [e]
    changed = True
    while changed:
        changed = False
        for e in edges:
            src, dst = int(e['from_entry'], 16), int(e['to_entry'], 16)
            if src in paths and dst not in paths and e['arg1'] == ('arg', 4):
                paths[dst] = paths[src] + [e]
                changed = True
    linked = []
    for c in candidates:
        entry = int(c['owner']['entry'], 16)
        base = c['flow']['base']
        linked.append({'store': c['store'], 'target': c['target'], 'entry': hex(entry),
                       'base': base, 'path': paths.get(entry, []) if base == ('arg', 4) else [],
                       'provenance_linked': base == ('active_thread', 0) or base == ('arg', 4) and entry in paths})
    return {'table': {'base': hex(load.operands[1].mem.disp), 'entries': len(slots),
                      'bytes_sha256': hashlib.sha256(table_bytes).hexdigest(), 'nonzero_entries': rows},
            'edges': edges, 'candidate_links': linked,
            'counts': {'nonzero_table_entries': len(rows), 'linked_candidates': sum(x['provenance_linked'] for x in linked),
                       'unlinked_candidates': sum(not x['provenance_linked'] for x in linked)},
            'qualification': 'Establishes a normal-flow active-thread chain for each store, not all possible callers or runtime table mutations.'}


def broad_store_scan():
    ranges = sorted((int(r['start'], 16), int(r['end_inclusive'], 16), f['address'], f['name'])
                    for f in R.FUNCS for r in f['body'])
    starts = [r[0] for r in ranges]
    rows = []
    with (R.G / 'code-units.tsv').open() as stream:
        for unit in csv.DictReader(stream, delimiter='\t'):
            if unit['kind'] != 'instruction':
                continue
            address, size = int(unit['start'], 16), int(unit['length'])
            ins = next(R.CS.disasm(R.read_original(address, size), address, count=1))
            assert ins.size == size
            for index, op in enumerate(ins.operands):
                if op.type == X86_OP_MEM and op.mem.disp == 0x74 and op.access & CS_AC_WRITE:
                    src = ins.operands[1] if index == 0 and len(ins.operands) == 2 else None
                    kind = 'immediate' if src and src.type == X86_OP_IMM else 'register' if src and src.type == X86_OP_REG else 'other'
                    value = src.imm & 0xffffffff if kind == 'immediate' else None
                    owner = ranges[R.bisect.bisect_right(starts, address) - 1]
                    assert owner[0] <= address <= owner[1]
                    rows.append({'site': hex(address), 'assembly': ins.mnemonic + ' ' + ins.op_str,
                                 'owner_entry': owner[2], 'owner_name': owner[3], 'write_size': op.size,
                                 'source_kind': kind, 'immediate': hex(value) if value is not None else None,
                                 'immediate_is_known_function_entry': value in R.FMAP if value is not None else False})
    return {'scope': 'Explicit memory operands with encoded displacement 0x74 and Capstone write access; not every effective address alias.',
            'writes': rows, 'counts': {'writes': len(rows), 'source_kind': dict(collections.Counter(r['source_kind'] for r in rows)),
                                      'immediate_known_function_entry': sum(r['immediate_is_known_function_entry'] for r in rows),
                                      'immediate_categories': dict(collections.Counter('known-function' if r['immediate_is_known_function_entry']
                                          else 'zero' if r['immediate'] == '0x0' else 'other-immediate'
                                          for r in rows if r['source_kind'] == 'immediate'))}}


def main():
    previous = json.loads((HERE.parent / 'cautious-followup-20260911/supplementary-checks.json').read_text())
    candidates = previous['recovery_contexts']
    entries = {int(c['owner']['entry'], 16) for c in candidates}
    entries.update(R.NAMES[n] for n in ('_PCexception', '_PCemulatePROT', '_catch_trap'))
    # Include the bounded PC emulation region so intermediary wrappers and
    # table-only handler functions are not omitted.
    entries.update(a for a in R.FMAP if 0x1a1b60 <= a <= 0x1a3ac4 and not R.FMAP[a]['analysis_fragment'])
    results = {a: flow(a) for a in sorted(entries)}
    annotated = []
    for c in candidates:
        entry, store = int(c['owner']['entry'], 16), int(c['store'], 16)
        matches = [w for w in results[entry]['writes_74'] if int(w['site'], 16) == store]
        assert len(matches) == 1
        annotated.append({**c, 'flow': matches[0]})
    tests = model_tests()
    paths = dispatch_and_paths(results, annotated)
    broad = broad_store_scan()
    input_paths = [R.ROOT / '03_original/x86/binaries/mach_kernel', R.G / 'functions.json', R.G / 'code-units.tsv',
                   R.ROOT / '03_original/x86/inventory/macho.json',
                   HERE.parent / 'cautious-followup-20260911/review.py',
                   HERE.parent / 'cautious-followup-20260911/supplementary-checks.json']
    input_paths.extend(R.G / 'functions' / f'{a:08x}.asm' for a in sorted(entries))
    result = {'scope': 'Intraprocedural normal-flow argument provenance with cdecl ABI assumptions; unknown indirect jumps stop propagation.',
              'input_hashes': [{'path': str(p.relative_to(R.ROOT)), 'sha256': hashlib.sha256(p.read_bytes()).hexdigest()} for p in input_paths],
              'runtime': {'python': sys.version, 'capstone': R.capstone.__version__},
              'assumptions': ['Known normal callees preserve EBX/ESI/EDI/EBP/ESP and do not overwrite caller argument slots through aliases.',
                              'Interrupts, faults and nonlocal returns are not executed by this model.',
                              'Function boundaries come from saved Ghidra listing; this is not their independent validation.'],
              'candidates': annotated, 'functions': list(results.values()),
              'model_tests_passed': tests,
              'counts': {'candidate_base': dict(collections.Counter(str(c['flow']['base']) for c in annotated)),
                         'functions': len(results), 'unexpanded_edges': sum(len(f['unexpanded_edges']) for f in results.values())}}
    (HERE / 'provenance-flow.json').write_text(json.dumps(result, indent=2) + '\n')
    (HERE / 'dispatch-and-provenance-paths.json').write_text(json.dumps(paths, indent=2) + '\n')
    (HERE / 'all-explicit-displacement74-writes.json').write_text(json.dumps(broad, indent=2) + '\n')
    print(json.dumps(result['counts'], indent=2))
    print(json.dumps({'paths': paths['counts'], 'broad_store_scan': broad['counts'], 'model_tests': len(tests)}, indent=2))
    print('PC call edges:')
    for a, f in results.items():
        for c in f['calls']:
            if c['target'] and 0x1a1300 <= int(c['target'], 16) <= 0x1a3d20 or c['target'] is None:
                print(f['name'], c)


if __name__ == '__main__':
    main()
