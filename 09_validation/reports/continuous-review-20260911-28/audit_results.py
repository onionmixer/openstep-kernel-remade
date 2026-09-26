"""Independent byte-level metadata model and original trace audit.

Never imports the execution fixture. Synthetic preparation is modeled as such;
no independent CPU/hardware execution is implied.
"""
import copy
import importlib.util
import itertools
import json
from pathlib import Path
import struct

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('audit24', HERE.parent / 'continuous-review-20260911-24/audit_results.py')
A = importlib.util.module_from_spec(spec)
spec.loader.exec_module(A)
OBJECTS = (0x682000, 0x682100)
PAGES = (0x683000, 0x683100, 0x683200)
HEADS = {'active': 0x1f6e40, 'inactive': 0x1f64e0, 'free': 0x1f6e48}
CALL_STACK = 0x710000 - 0x100


class Memory:
    def __init__(self, state):
        self.state = copy.deepcopy(state)
        self.regions = {int(k, 16): bytearray.fromhex(v) for group in ('objects', 'pages') for k, v in state[group].items()}
        self.regions[0x685000] = bytearray.fromhex(state['buckets'])
        for name, head in HEADS.items():
            self.regions[head] = bytearray(struct.pack('<2I', *state['queues'][name]))

    def span(self, address, size):
        for base, data in self.regions.items():
            if base <= address and address + size <= base + len(data):
                return data, address - base
        raise AssertionError(('unmodeled metadata address', hex(address), size))

    def get(self, address, size=4):
        data, offset = self.span(address, size)
        return int.from_bytes(data[offset:offset + size], 'little')

    def put(self, address, value, size=4):
        data, offset = self.span(address, size)
        data[offset:offset + size] = int(value).to_bytes(size, 'little')

    def exported(self):
        result = self.state
        for group in ('objects', 'pages'):
            result[group] = {k: self.regions[int(k, 16)].hex() for k in result[group]}
        result['buckets'] = self.regions[0x685000].hex()
        result['queues'] = {name: list(struct.unpack('<2I', self.regions[head])) for name, head in HEADS.items()}
        return result

    def bucket(self, obj, offset):
        return 0x685000 + (((offset >> 13) + obj) & 7) * 8

    def remove(self, page):
        if not self.get(page + 0x20, 1) & 4:
            return
        obj, offset = self.get(page + 0x14), self.get(page + 0x18)
        link = self.bucket(obj, offset) + 4
        visited = set()
        while self.get(link) != page:
            current = self.get(link)
            assert current in PAGES and current not in visited
            visited.add(current)
            link = current + 0x10
        self.put(link, self.get(page + 0x10))
        nxt, previous = self.get(page + 8), self.get(page + 0xc)
        self.put(nxt + (4 if nxt == obj else 0xc), previous)
        self.put(previous + (0 if previous == obj else 8), nxt)
        self.put(obj + 0x1a, self.get(obj + 0x1a, 2) - 1, 2)
        self.put(page + 0x20, self.get(page + 0x20, 1) & ~4, 1)

    def insert(self, page, obj, offset):
        assert not self.get(page + 0x20, 1) & 4
        self.put(page + 0x14, obj)
        self.put(page + 0x18, offset)
        bucket = self.bucket(obj, offset)
        self.put(page + 0x10, self.get(bucket + 4))
        self.put(bucket + 4, page)
        tail = self.get(obj + 4)
        self.put(tail + (0 if tail == obj else 8), page)
        self.put(page + 0xc, tail)
        self.put(page + 8, obj)
        self.put(obj + 4, page)
        self.put(page + 0x20, self.get(page + 0x20, 1) | 4, 1)
        self.put(obj + 0x1a, self.get(obj + 0x1a, 2) + 1, 2)

    def initialize(self, page, obj, offset, physical):
        self.regions[page][:] = bytes.fromhex(self.state['template'])
        self.put(page + 0x24, physical)
        self.insert(page, obj, offset)

    def addfree(self, page):
        assert not self.get(page + 0x1e, 1) & (1 | 2 | 8)
        assert not self.get(page + 0x20, 1) & 8
        head = HEADS['free']
        tail = self.get(head + 4)
        self.put(tail, page)
        self.put(page + 4, tail)
        self.put(page, head)
        self.put(head + 4, page)
        self.put(page + 0x1e, self.get(page + 0x1e, 1) | 8, 1)
        self.state['globals']['free_count'] += 1

    def alloc(self, obj, offset):
        head = HEADS['free']
        page = self.get(head)
        if page == head:
            return 0
        counts = self.state['globals']
        assert counts['free_count'] >= 0 and counts['reserved'] >= 0
        if counts['free_count'] < counts['reserved'] and not self.state['vm_privilege']:
            return 0
        nxt = self.get(page)
        self.put(nxt + 4, head)
        self.put(head, nxt)
        self.put(page + 0x1e, self.get(page + 0x1e, 1) & ~8, 1)
        counts['free_count'] -= 1
        self.remove(page)
        physical = self.get(page + 0x24)
        self.initialize(page, obj, offset, physical)
        self.put(obj + 0x54, offset)
        return page

    def lookup(self, obj, offset):
        page = self.get(self.bucket(obj, offset) + 4)
        visited = set()
        while page:
            assert page in PAGES and page not in visited
            visited.add(page)
            if self.get(page + 0x14) == obj and self.get(page + 0x18) == offset:
                return page
            page = self.get(page + 0x10)
        return 0


def trace_check(trace, stop=0x740000):
    pcs = [int(p, 16) for p in trace]
    returns = []
    for pc, following in zip(pcs, pcs[1:] + [stop]):
        ins = A.instruction(pc)
        if ins.mnemonic == 'call':
            assert ins.operands[0].type == A.capstone.x86.X86_OP_IMM
            assert following == ins.operands[0].imm
            returns.append(pc + ins.size)
        elif ins.mnemonic == 'ret':
            assert following == (returns.pop() if returns else stop)
        elif ins.group(A.capstone.CS_GRP_JUMP):
            assert ins.operands[0].type == A.capstone.x86.X86_OP_IMM
            allowed = {ins.operands[0].imm}
            if ins.mnemonic != 'jmp':
                allowed.add(pc + ins.size)
            assert following in allowed, (hex(pc), hex(following))
        elif bytes(ins.bytes) == b'\xf3\xa5':
            assert pc in (0x17b150, 0x17b384) and following in (pc, pc + ins.size)
        else:
            assert following == pc + ins.size, (hex(pc), hex(following), ins.mnemonic)
    assert not returns


def invariant_graph(memory):
    active = set()
    for obj in OBJECTS:
        assert memory.get(obj + 0x10) == 1 and memory.get(obj + 0x18, 2) == 1
        previous, page = obj, memory.get(obj)
        members = []
        while page != obj:
            assert page in PAGES and page not in members and page not in active
            assert memory.get(page + 0xc) == previous and memory.get(page + 0x14) == obj
            assert memory.get(page + 0x20, 1) & 4
            assert memory.lookup(obj, memory.get(page + 0x18)) == page
            members.append(page)
            active.add(page)
            previous, page = page, memory.get(page + 8)
        assert memory.get(obj + 4) == previous and memory.get(obj + 0x1a, 2) == len(members)
    hashed = set()
    for index in range(8):
        bucket = 0x685000 + index * 8
        assert memory.get(bucket) == 0
        page = memory.get(bucket + 4)
        while page:
            assert page in active and page not in hashed
            hashed.add(page)
            assert memory.bucket(memory.get(page + 0x14), memory.get(page + 0x18)) == bucket
            page = memory.get(page + 0x10)
    assert active == hashed
    head, previous = HEADS['free'], HEADS['free']
    page, free = memory.get(head), set()
    while page != head:
        assert page in PAGES and page not in free
        assert memory.get(page + 4) == previous and memory.get(page + 0x1e, 1) & 8
        free.add(page)
        previous, page = page, memory.get(page)
    assert memory.get(head + 4) == previous and len(free) == memory.state['globals']['free_count']


def validate_schedule(row):
    """Derive operations/admission values independently from the case label."""
    vm_size = 1 << 13
    offsets = [vm_size * (3 + 8 * i) for i in range(len(PAGES))]
    frames = [0x2000000 + vm_size * i for i in range(len(PAGES))]
    assert row['offsets'] == offsets and row['fixture']['synthetic_frames'] == frames
    scenario, seed, sequential = row['scenario'], row['seed'], row['sequential']
    expected = []
    if not scenario.startswith('empty'):
        expected += [('init', [p, OBJECTS[0], off, pa]) for p, off, pa in zip(PAGES, offsets, frames)]
        if seed == 'cached':
            expected.append(('seed_busy_clear', None))
        expected += [('addfree' if seed == 'cached' else 'free', [PAGES[i]]) for i in (1, 0, 2)]
    expected.append(('admission_configuration', None))
    for offset in offsets if scenario == 'cycle' else offsets[:1]:
        expected += [('alloc', [OBJECTS[1], offset, sequential]), ('lookup', [OBJECTS[1], offset])]
    if scenario == 'cycle':
        expected += [('alloc', [OBJECTS[1], offsets[-1] + vm_size, sequential])]
        expected += [('free', [p]) for p in PAGES]
        for offset, page in zip(offsets, PAGES):
            expected += [('alloc', [OBJECTS[0], offset, sequential]), ('lookup', [OBJECTS[0], offset])]
    assert [(op['name'], op.get('arguments')) for op in row['operations']] == expected, 'operation schedule/arguments'
    entries = {'init': 0x17b134, 'alloc': 0x17b200, 'lookup': 0x17af58, 'free': 0x17b540, 'addfree': 0x17b5f8}
    for op in row['operations']:
        if op['name'] in entries:
            assert op['entry'] == hex(entries[op['name']]), 'operation entry'
    admission = next(op for op in row['operations'] if op['name'] == 'admission_configuration')
    free_count = 0 if scenario.startswith('empty') else len(PAGES)
    reserved = free_count + 1 if scenario.startswith('below') else free_count if scenario.startswith('equal') else max(0, free_count - 1) if scenario.startswith('above') else 0
    assert admission['before']['globals']['free_count'] == free_count
    assert admission['reserved'] == reserved, 'scenario reserved'
    assert admission['privilege'] == int(scenario.endswith('_privileged')), 'scenario privilege'
    initial = row['operations'][0]['before']
    for obj in OBJECTS:
        wanted = bytearray(0x58)
        struct.pack_into('<2I', wanted, 0, obj, obj)
        struct.pack_into('<2I', wanted, 0x10, 1, vm_size * 32)
        struct.pack_into('<H', wanted, 0x18, 1)
        assert initial['objects'][hex(obj)] == wanted.hex(), 'initial object'
    assert initial['pages'] == {hex(p): (bytes([0xa7]) * 0x30).hex() for p in PAGES}
    assert initial['buckets'] == bytes(8 * 8).hex()
    assert initial['queues'] == {name: [head, head] for name, head in HEADS.items()}
    assert initial['vm_privilege'] == 0
    for name in ('active_count', 'inactive_count', 'free_count', 'free_lock', 'reserved', 'minimum', 'target', 'inactive_target'):
        assert initial['globals'][name] == 0
    assert initial['globals']['queue_lock'] == 1
    assert initial['copy_buffer_hashes'] == A.expected_hashes(row['target'], 1, 0x100, 0)


def main():
    cases = json.loads((HERE / 'allocator-cases.json').read_text())
    scenarios = ('cycle', 'empty_ordinary', 'empty_privileged', 'below_ordinary', 'below_privileged',
                 'equal_ordinary', 'equal_privileged', 'above_ordinary', 'above_privileged')
    actual = {(r['target'], r['seed'], r['sequential'], r['scenario']) for r in cases}
    expected = set(itertools.product(('A', 'B'), ('detached', 'cached'), (0, 1), scenarios))
    assert actual == expected and len(cases) == len(expected)
    counts = {'original_calls': 0, 'allocation_successes': 0, 'allocation_rejections': 0, 'cached_removal_calls': 0}
    payload = bytes((i * 19 + (i >> 7) + 0x53) & 0xff for i in range(0x10000))
    payload_hash = A.hashlib.sha256(payload).hexdigest()
    for row in cases:
        validate_schedule(row)
        assert row['fixture']['vm_size'] == 1 << 13
        template = bytearray(0x30)
        template[0x1e], template[0x20] = 0x20, 1
        assert row['fixture']['template'] == template.hex()
        trace_check(row['fixture']['startup_prefix']['trace'], 0x17aade)
        assert row['fixture']['startup_prefix']['after']['eip'] == 0x17aade
        assert row['fixture']['mapped_frame_references'] == []
        previous = None
        for op in row['operations']:
            before, after = op['before'], op['after']
            if previous is not None:
                assert {k: v for k, v in previous.items() if k != 'cpu'} == {k: v for k, v in before.items() if k != 'cpu'}
            memory = Memory(before)
            name = op['name']
            expected_eax = None
            if name == 'init':
                memory.initialize(*op['arguments'])
            elif name == 'seed_busy_clear':
                assert row['seed'] == 'cached'
                for page in PAGES:
                    assert memory.get(page + 0x20, 1) == 5
                    memory.put(page + 0x20, 4, 1)
            elif name == 'admission_configuration':
                memory.state['globals']['reserved'] = op['reserved']
                memory.state['vm_privilege'] = op['privilege']
            elif name == 'addfree':
                memory.addfree(op['arguments'][0])
            elif name == 'free':
                page, = op['arguments']
                memory.remove(page)
                if not memory.get(page + 0x1e, 1) & 8:
                    memory.addfree(page)
            elif name == 'alloc':
                obj, offset, sequential = op['arguments']
                assert sequential == row['sequential']
                expected_eax = memory.alloc(obj, offset)
                counts['allocation_successes' if expected_eax else 'allocation_rejections'] += 1
            elif name == 'lookup':
                expected_eax = memory.lookup(*op['arguments'])
            else:
                raise AssertionError(name)
            computed = memory.exported()
            assert {k: v for k, v in computed.items() if k != 'cpu'} == {k: v for k, v in after.items() if k != 'cpu'}, (row['scenario'], name, op.get('arguments'))
            assert after['physical_hash'] == payload_hash
            assert after['descriptor_guards'] == [(bytes([0xa7]) * (0x100 - 0x30)).hex()] * len(PAGES)
            assert after['object_guards'] == [(bytes([0xc3]) * (0x100 - 0x58)).hex()] * len(OBJECTS)
            invariant_graph(memory)
            if 'observation' in op:
                counts['original_calls'] += 1
                trace = op['observation']['trace']
                counts['cached_removal_calls'] += '0x17b2d0' in trace
                trace_check(trace)
                assert op['failure'] is None and op['observation']['error'] is None and not op['observation']['interrupts']
                assert trace[0] == op['entry'] and op['observation']['after'] == after['cpu']
                assert after['cpu']['eip'] == 0x740000 and after['cpu']['esp'] == CALL_STACK + 4
                if expected_eax is not None:
                    assert after['cpu']['eax'] == expected_eax
                for reg in ('ebx', 'esi', 'edi', 'ebp', 'cs', 'ds', 'es', 'ss', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4'):
                    assert before['cpu'][reg] == after['cpu'][reg]
                assert after['globals']['queue_lock'] == 1 and after['globals']['free_lock'] == 0
                assert after['globals']['ipl'] == before['globals']['ipl']
                assert op['write_count'] > 0
                if name == 'alloc' and expected_eax:
                    assert op['last_alloc_writes'] == [{'address': op['arguments'][0] + 0x54, 'size': 4, 'value': op['arguments'][1]}]
                else:
                    assert op['last_alloc_writes'] == []
                for forbidden in (0x1631a0, 0x17a338, 0x10ca6c, 0x18b59b, 0x18b5dc, 0x18b5ef):
                    assert hex(forbidden) not in trace
                if name == 'init' or (name == 'alloc' and expected_eax):
                    page = op['arguments'][0] if name == 'init' else expected_eax
                    pc = 0x17b150 if name == 'init' else 0x17b384
                    expected_rep = [{'pc': hex(pc), 'ecx': 0x30 // 4 - i, 'esi': 0x1f7440 + i * 4,
                                     'edi': page + i * 4, 'df': 0} for i in range(0x30 // 4 + 1)]
                    assert op['rep_observations'] == expected_rep
                    assert trace.count(hex(pc)) == len(expected_rep)
                else:
                    assert op['rep_observations'] == []
            previous = after
        assert previous == row['final']
    summary = json.loads((HERE / 'allocator-summary.json').read_text())
    for key, value in counts.items():
        assert summary[key] == value
    assert summary['fresh_cases'] == len(cases) and not summary['whole_analysis_complete']
    result = {'fresh_cases_verified': len(cases), **counts, 'full_metadata_transitions_verified': True,
              'mismatches': [], 'independent_hardware_backend': False, 'pager_io_verified': False,
              'whole_analysis_complete': False}
    (HERE / 'independent-audit.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
