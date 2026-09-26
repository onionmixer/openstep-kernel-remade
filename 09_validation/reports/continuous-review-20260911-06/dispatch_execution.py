"""Bounded original x86 dispatch execution. All derived quantities use Python.

Original code is never patched. Synthetic objects/caches, a synthetic IMP, and
an explicit lookup mock are fixtures, not full runtime/ABI verification.
"""
import collections
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import sys
import unicorn as U
from unicorn import x86_const as X

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('original', HERE.parent / 'cautious-followup-20260911/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)
ROOT = R.ROOT
PAGE, DATA, STACK, IMP, STOP = 0x1000, 0x600000, 0x710000, 0x730000, 0x740000
OBJ, CLS, SUPER, CACHE, METHOD, FRAME = [DATA + x for x in (0, 0x100, 0x200, 0x300, 0x400, 0x800)]
MASK_ADDR, LOCK_ADDR = 0x1e5604, 0x1e55ac
WORD = struct.calcsize('<I')
REGS = {'ebx': (X.UC_X86_REG_EBX, 0x12341111), 'esi': (X.UC_X86_REG_ESI, 0x23452222),
        'edi': (X.UC_X86_REG_EDI, 0x34563333), 'ebp': (X.UC_X86_REG_EBP, 0x45674444)}
TARGETS = ('_objc_msgSend', '_objc_msgSendSuper', '__objc_msgForward', '_objc_msgSendv')
ALL_INS = {n: R.function_instructions(R.NAMES[n]) for n in TARGETS}
ALL_HEADS = set().union(*(set(v) for v in ALL_INS.values()))
VISITED = set()


def put(uc, addr, *values):
    uc.mem_write(addr, struct.pack('<' + 'I' * len(values), *values))


def words(uc, addr, count):
    return list(struct.unpack('<' + 'I' * count, uc.mem_read(addr, count * WORD)))


def fixture(selector, mode, path, eax=0x12345678, edx=0x87654321):
    uc = U.Uc(U.UC_ARCH_X86, U.UC_MODE_32)
    for seg in R.META['segments']:
        if seg['name'] == '__PAGEZERO':
            continue
        addr = int(seg['address'], 16)
        low = addr & -PAGE
        uc.mem_map(low, (addr + seg['size'] - low + PAGE - 1) & -PAGE)
        uc.mem_write(addr, R.RAW[seg['file_offset']:seg['file_offset'] + seg['file_size']])
    uc.mem_map(DATA, PAGE)
    uc.mem_map(STACK - PAGE, PAGE * 2)
    uc.mem_map(IMP, PAGE)
    uc.mem_map(STOP, PAGE)
    # Synthetic method returns explicit GPR values via real RET.
    uc.mem_write(IMP, b'\xb8' + struct.pack('<I', eax) + b'\xba' + struct.pack('<I', edx) + b'\xc3')
    put(uc, OBJ, CLS)
    put(uc, CLS + 0x20, CACHE)
    put(uc, SUPER, OBJ, CLS)
    put(uc, MASK_ADDR, 0xffffffff if mode == 'unlocked' else 0)
    put(uc, LOCK_ADDR, 0)
    cache_mask = 3
    put(uc, CACHE, cache_mask, 0)
    index = selector & cache_mask
    if path == 'collision':
        put(uc, METHOD + 0x20, selector ^ 0x100, 0, IMP)
        put(uc, CACHE + 8 + index * WORD, METHOD + 0x20)
        index = (index + 1) & cache_mask
    if path != 'miss':
        put(uc, METHOD, selector, 0, IMP)
        put(uc, CACHE + 8 + index * WORD, METHOD)
    for reg, value in REGS.values():
        uc.reg_write(reg, value)
    uc.reg_write(X.UC_X86_REG_ESP, STACK)
    trace, reads = [], []

    def code_hook(engine, address, size, unused):
        trace.append(address)
        if address in ALL_HEADS:
            VISITED.add(address)

    def read_hook(engine, access, address, size, value, unused):
        if FRAME <= address < FRAME + 0x200:
            reads.append({'address': hex(address), 'size': size})

    uc.hook_add(U.UC_HOOK_CODE, code_hook)
    uc.hook_add(U.UC_HOOK_MEM_READ, read_hook)
    return uc, trace, reads


def run_to(uc, start, end, count=1000):
    # Unicorn 2.1.4 retained a translated stop block when a previous `until`
    # address became the next start. Invalidate that translation, not bytes.
    uc.ctl_remove_cache(start & -PAGE, (start & -PAGE) + PAGE)
    uc.emu_start(start, end, timeout=1000000, count=count)
    assert uc.reg_read(X.UC_X86_REG_EIP) == end, hex(uc.reg_read(X.UC_X86_REG_EIP))


def assert_callee_saved(uc, ebx=None):
    for name, (reg, value) in REGS.items():
        if name == 'ebx' and ebx is not None:
            value = ebx
        assert uc.reg_read(reg) == value, name


def dispatch_case(name, mode, path, selector):
    uc, trace, _ = fixture(selector, mode, path)
    receiver_arg = SUPER if name == '_objc_msgSendSuper' else OBJ
    extras = [0xaabbccdd, 0x10203040, 0x55667788]
    put(uc, STACK, STOP, receiver_arg, selector, *extras)
    lookup = None
    if path == 'miss':
        run_to(uc, R.NAMES[name], R.NAMES['__class_lookupMethodAndLoadCache'])
        esp = uc.reg_read(X.UC_X86_REG_ESP)
        ret, cls, sel = words(uc, esp, 3)
        assert (cls, sel) == (CLS, selector)
        lookup = {'arguments': [hex(cls), hex(sel)], 'lock_at_lookup': words(uc, LOCK_ADDR, 1)[0],
                  'return_address': hex(ret), 'mock': True}
        assert lookup['lock_at_lookup'] == (mode == 'locked')
        uc.reg_write(X.UC_X86_REG_EAX, IMP)
        uc.reg_write(X.UC_X86_REG_ECX, 0xdeadc0de)
        uc.reg_write(X.UC_X86_REG_EDX, 0xfeedbabe)
        uc.reg_write(X.UC_X86_REG_ESP, esp + WORD)
        run_to(uc, ret, IMP)
    else:
        run_to(uc, R.NAMES[name], IMP)
    assert uc.reg_read(X.UC_X86_REG_ESP) == STACK
    assert words(uc, STACK, len(extras) + 3) == [STOP, OBJ, selector, *extras]
    assert words(uc, LOCK_ADDR, 1) == [0]
    assert_callee_saved(uc)
    tail = trace[-1]
    assert ALL_INS[name][tail].mnemonic == 'jmp' and ALL_INS[name][tail].op_str == 'eax'
    run_to(uc, IMP, STOP)
    assert uc.reg_read(X.UC_X86_REG_ESP) == STACK + WORD
    assert uc.reg_read(X.UC_X86_REG_EAX) == 0x12345678
    assert uc.reg_read(X.UC_X86_REG_EDX) == 0x87654321
    assert_callee_saved(uc)
    return {'function': name, 'mode': mode, 'path': path, 'selector': hex(selector),
            'tail_jump': hex(tail), 'stack_and_arguments_verified': True,
            'callee_saved_verified': True, 'lock_released_before_imp': True,
            'synthetic_imp_return_verified': True, 'lookup': lookup,
            'trace': [hex(a) for a in trace]}


def nil_cases():
    result = []
    for mode in ('unlocked', 'locked'):
        for edx in (0, 0x87654321, 0xffffffff):
            uc, trace, _ = fixture(0x600, mode, 'hit')
            put(uc, STACK, STOP, 0, 0x600)
            put(uc, LOCK_ADDR, 0x11223344)
            uc.reg_write(X.UC_X86_REG_EDX, edx)
            run_to(uc, R.NAMES['_objc_msgSend'], STOP)
            assert uc.reg_read(X.UC_X86_REG_EAX) == 0
            assert uc.reg_read(X.UC_X86_REG_EDX) == edx
            assert words(uc, LOCK_ADDR, 1) == [0x11223344]
            assert uc.reg_read(X.UC_X86_REG_ESP) == STACK + WORD
            assert_callee_saved(uc)
            result.append({'mode': mode, 'incoming_edx': hex(edx), 'returned_eax': 0,
                           'returned_edx': hex(edx), 'lock_untouched': True,
                           'trace': [hex(a) for a in trace]})
    return result


def wrapper_case(name, mode, arg_size, eax, edx):
    forward_selector = struct.unpack('<I', R.read_original(0x1f9cf0, WORD))[0]
    selector = forward_selector if name == '__objc_msgForward' else 0x603
    uc, trace, reads = fixture(selector, mode, 'collision', eax, edx)
    if name == '__objc_msgForward':
        original_selector = forward_selector ^ 1
        put(uc, STACK, STOP, OBJ, original_selector, 0x11223344, 0x55667788)
        expected = [0x1cebd5, OBJ, selector, original_selector, STACK + WORD]
        count = 0
    else:
        count = max((arg_size >> 2) - 2, 0)
        extras = [0x11000000 + n for n in range(count)]
        put(uc, FRAME, 0xbad00001, 0xbad00002, *extras)
        put(uc, STACK, STOP, OBJ, selector, arg_size, FRAME)
        expected = [0x1cec29, OBJ, selector, *extras]
    run_to(uc, R.NAMES[name], IMP)
    esp = uc.reg_read(X.UC_X86_REG_ESP)
    assert words(uc, esp, len(expected)) == expected
    assert words(uc, LOCK_ADDR, 1) == [0]
    if name == '_objc_msgSendv':
        assert reads == [{'address': hex(FRAME + 8 + n * WORD), 'size': WORD}
                         for n in reversed(range(count))]
        assert esp == STACK - (count + 4) * WORD
    else:
        assert esp == STACK - 6 * WORD
    run_to(uc, IMP, STOP)
    assert uc.reg_read(X.UC_X86_REG_EAX) == eax and uc.reg_read(X.UC_X86_REG_EDX) == edx
    assert uc.reg_read(X.UC_X86_REG_ESP) == STACK + WORD
    assert_callee_saved(uc)
    return {'function': name, 'mode': mode, 'arg_size': arg_size,
            'copied_extra_words': count if name == '_objc_msgSendv' else None,
            'imp_stack': [hex(v) for v in expected], 'frame_reads': reads,
            'returned_eax': hex(eax), 'returned_edx': hex(edx),
            'original_dispatch_executed': True, 'synthetic_imp': True,
            'trace': [hex(a) for a in trace]}


def real_method_case(method, route, mode, pattern):
    address = int(method['metadata_address'], 16)
    selector, types_ptr, imp = struct.unpack('<III', R.read_original(address, WORD * 3))
    assert imp == int(method['imp'], 16)
    uc, trace, _ = fixture(selector, mode, 'collision')
    put(uc, METHOD + 8, imp)
    out = DATA + 0xb00
    name = method['selector']
    if name == 'mappedRange':
        put(uc, OBJ + 8, *pattern)
        expected_eax, expected_edx = pattern
        hidden_ebx = None
    elif name == 'SCSI3_lun':
        put(uc, OBJ + 0x110, *pattern)
        expected_eax, expected_edx = pattern
        hidden_ebx = None
    else:
        assert name == 'nodeAddress'
        source = struct.pack('<II', *pattern)[:6]
        uc.mem_write(OBJ + 0x13c, source)
        uc.mem_write(out, b'\xa5' * 8)
        uc.reg_write(X.UC_X86_REG_EBX, out)
        hidden_ebx = out
        expected_eax, expected_edx = out, pattern[0]
    if route == '_objc_msgSendv':
        put(uc, FRAME, 0xbad00001, 0xbad00002)
        put(uc, STACK, STOP, OBJ, selector, 8, FRAME)
    else:
        put(uc, STACK, STOP, SUPER if route == '_objc_msgSendSuper' else OBJ, selector)
    # Run original dispatch and original method through RET, without IMP mock.
    run_to(uc, R.NAMES[route], STOP)
    assert imp in trace
    assert uc.reg_read(X.UC_X86_REG_EAX) == expected_eax
    assert uc.reg_read(X.UC_X86_REG_EDX) == expected_edx
    assert uc.reg_read(X.UC_X86_REG_ESP) == STACK + WORD
    assert words(uc, LOCK_ADDR, 1) == [0]
    assert_callee_saved(uc, hidden_ebx)
    buffer = None
    if hidden_ebx is not None:
        buffer = bytes(uc.mem_read(out, 8))
        assert buffer == source + b'\xa5\xa5'
    return {'method': method, 'route': route, 'mode': mode,
            'input_words': [hex(v) for v in pattern], 'eax': hex(expected_eax), 'edx': hex(expected_edx),
            'hidden_ebx': hex(hidden_ebx) if hidden_ebx is not None else None,
            'output_with_canary': buffer.hex() if buffer is not None else None,
            'original_method_executed': True, 'lookup_mock': False, 'synthetic_imp': False,
            'trace': [hex(a) for a in trace]}


def main():
    assert hashlib.sha256(R.RAW).hexdigest() == '33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890'
    dispatch = [dispatch_case(name, mode, path, selector)
                for name in ('_objc_msgSend', '_objc_msgSendSuper')
                for mode in ('unlocked', 'locked') for path in ('hit', 'collision', 'miss')
                for selector in range(0x600, 0x604)]
    nil = nil_cases()
    return_pairs = [(0, 0xffffffff), (0x12345678, 0x87654321)]
    forwarding = [wrapper_case('__objc_msgForward', mode, None, eax, edx)
                  for mode in ('unlocked', 'locked') for eax, edx in return_pairs]
    sizes = list(range(36)) + [63, 64, 65]
    vector = [wrapper_case('_objc_msgSendv', mode, size, eax, edx)
              for mode in ('unlocked', 'locked') for size in sizes for eax, edx in return_pairs]
    metadata = json.loads((ROOT / '03_original/x86/inventory/objc.json').read_text())
    methods = [m for m in metadata['methods'] if (m['owner'], m['selector']) in
               [('KernBusRangeMapping', 'mappedRange'), ('SCSIGeneric', 'SCSI3_lun'), ('IOTokenRing', 'nodeAddress')]]
    assert len(methods) == 3
    real = [real_method_case(m, route, mode, pair) for m in methods
            for route in ('_objc_msgSend', '_objc_msgSendSuper', '_objc_msgSendv')
            for mode in ('unlocked', 'locked') for pair in return_pairs]
    coverage = {name: {'listing_instruction_heads': len(ins), 'visited_heads': len(set(ins) & VISITED),
                       'unvisited': [{'address': hex(a), 'instruction': ins[a].mnemonic + ' ' + ins[a].op_str}
                                     for a in sorted(set(ins) - VISITED)]}
                for name, ins in ALL_INS.items()}
    summary = {'dispatch_cases': len(dispatch), 'nil_cases': len(nil), 'forwarding_cases': len(forwarding),
               'sendv_cases': len(vector), 'real_method_cases': len(real),
               'total_passed': sum(map(len, (dispatch, nil, forwarding, vector, real))),
               'coverage': coverage, 'unicorn_version': U.__version__,
               'scope': 'Synthetic objects/cache; primary matrix has synthetic IMP and mocked miss lookup. Separate real-method matrix executes three original methods. Not full concurrency/x87/aggregate ABI proof.'}
    result = {'summary': summary, 'dispatch': dispatch, 'nil': nil, 'forwarding': forwarding, 'sendv': vector, 'real_methods': real}
    (HERE / 'dispatch-execution.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
