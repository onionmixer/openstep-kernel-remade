"""Execute original caller -> hidden-EBX aggregate callee -> strcpy/bcopy.

No function mocks or kernel instruction patches. Stop immediately after the
aggregate-return call, before the rest of network boot initialization.
"""
import collections
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('fixtures', HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py')
D = importlib.util.module_from_spec(spec)
spec.loader.exec_module(D)
R, U, X = D.R, D.U, D.X
CALLER, CALLEE = R.NAMES['_in_bootp'], 0x124cb8
INS = R.function_instructions(CALLER)
CALL = next(i for i in INS.values() if i.mnemonic == 'call' and i.operands[0].imm == CALLEE)
RESUME = CALL.address + CALL.size
EXPECTED_HELPERS = (R.NAMES['_strcpy'], R.NAMES['_bcopy'], R.NAMES['_memcpy'])


def case(name, unit, marker, alignment):
    uc, trace, unused_reads = D.fixture(0x600, 'unlocked', 'hit')
    uc.mem_write(D.STACK - D.PAGE, bytes([marker]) * (D.PAGE * 2))
    ifp, name_ptr, sin = D.DATA + 0x100, D.DATA + 0x300, D.DATA + 0x500 + alignment
    D.put(uc, ifp, name_ptr)
    uc.mem_write(ifp + 8, struct.pack('<H', unit))
    uc.mem_write(name_ptr, name + b'\x00')
    sockaddr = bytes(range(16))
    uc.mem_write(sin, sockaddr)
    D.put(uc, D.STACK, D.STOP, ifp, sin, 0)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)  # Explicit DF=0 flat execution fixture.
    entry = {}
    writes = []
    caller_ebp = D.STACK - D.WORD
    output = caller_ebp - 0x20

    def on_code(engine, address, size, unused):
        if address == CALLEE:
            esp = engine.reg_read(X.UC_X86_REG_ESP)
            entry.update({'ebx': hex(engine.reg_read(X.UC_X86_REG_EBX)), 'esp': hex(esp),
                          'stack': [hex(v) for v in D.words(engine, esp, 3)]})
            assert engine.reg_read(X.UC_X86_REG_EBX) == output
            assert D.words(engine, esp, 3) == [RESUME, ifp, sin]

    def on_write(engine, access, address, size, value, unused):
        if output <= address < output + 0x20:
            writes.append({'address': hex(address), 'size': size, 'value': hex(value)})

    uc.hook_add(U.UC_HOOK_CODE, on_code)
    uc.hook_add(U.UC_HOOK_MEM_WRITE, on_write)
    D.run_to(uc, CALLER, RESUME)
    assert entry
    prefix = name + bytes([(unit + ord('0')) & 0xff]) + b'\x00'
    assert len(prefix) <= 16
    expected = prefix + bytes([marker]) * (16 - len(prefix)) + sockaddr
    actual = bytes(uc.mem_read(output, 0x20))
    assert actual == expected
    assert uc.reg_read(X.UC_X86_REG_EAX) == output
    assert uc.reg_read(X.UC_X86_REG_EBX) == output
    assert uc.reg_read(X.UC_X86_REG_ESI) == output
    assert uc.reg_read(X.UC_X86_REG_EDI) == 0
    assert uc.reg_read(X.UC_X86_REG_EBP) == caller_ebp
    assert uc.reg_read(X.UC_X86_REG_ESP) == int(entry['esp'], 16) + D.WORD
    assert all(a in trace for a in EXPECTED_HELPERS)
    assert D.IMP not in trace
    assert len(writes) == 8 and all(w['size'] == D.WORD for w in writes)
    return {'name': name.decode(), 'unit': unit, 'stack_marker': hex(marker), 'sockaddr_alignment_offset': alignment,
            'callee_entry': entry, 'caller_resume': hex(RESUME), 'output': actual.hex(),
            'untouched_name_tail_bytes': 16 - len(prefix), 'output_writes': writes,
            'original_helpers_executed': [hex(a) for a in EXPECTED_HELPERS],
            'trace': [hex(a) for a in trace], 'mocks': []}


def main():
    rows = [case(name, unit, marker, alignment)
            for name in (b'', b'en', b'abcdefgh', b'abcdefghijklmn')
            for unit in (0, 9, 10, 0xffff) for marker in (0xa5, 0x5a) for alignment in range(4)]
    result = {'summary': {'cases': len(rows), 'caller': hex(CALLER), 'callee': hex(CALLEE),
                          'call_site': hex(CALL.address), 'resume': hex(RESUME), 'returned_bytes': 0x20,
                          'cases_with_unwritten_name_tail': sum(r['untouched_name_tail_bytes'] > 0 for r in rows),
                          'unicorn_version': U.__version__, 'helper_mock_count': 0},
              'cases': rows,
              'limits': 'Bounded caller prefix and return only, synthetic interface/sockaddr/stack, DF=0. Not network boot, invalid-pointer/overflow testing, or a C undefined-behavior guarantee.'}
    (HERE / 'ifreq-execution.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result['summary'], indent=2))


if __name__ == '__main__':
    main()
