"""Original MIG stub execution with explicitly mocked kernel services.

Tests stack arguments, reply bytes and panic-path reachability, not IPC,
task allocation, scheduling, hardware panic, or kernel boot correctness.
"""
import collections
import hashlib
import importlib.util
import itertools
import json
from pathlib import Path
import struct
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('dispatch', HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py')
D = importlib.util.module_from_spec(spec)
spec.loader.exec_module(D)
R, U, X = D.R, D.U, D.X
REQ, REPLY, HANDLE, CHILD = [D.DATA + off for off in (0x900, 0xa00, 0xb00, 0xc00)]
PORT, CHILD_PORT = 0x10203040, 0x55667788
SENTINEL = 0x25252525
MASK = (1 << 32) - 1
WORD = struct.calcsize('<I')


def fresh(args):
    uc, trace, _ = D.fixture(0x603, 'unlocked', 'hit')
    D.put(uc, D.STACK, D.STOP, *args)
    return uc, trace


def return_mock(uc, result):
    esp = uc.reg_read(X.UC_X86_REG_ESP)
    ret = D.words(uc, esp, 1)[0]
    uc.reg_write(X.UC_X86_REG_EAX, result & MASK)
    uc.reg_write(X.UC_X86_REG_ECX, 0xc1c1c1c1)
    uc.reg_write(X.UC_X86_REG_EDX, 0xd2d2d2d2)
    uc.reg_write(X.UC_X86_REG_ESP, esp + WORD)
    return ret


def stopped_call(uc, start, name, argc):
    D.run_to(uc, start, R.NAMES[name])
    esp = uc.reg_read(X.UC_X86_REG_ESP)
    return D.words(uc, esp + WORD, argc)


def finish(uc, trace, start, entry):
    D.run_to(uc, start, D.STOP)
    assert uc.reg_read(X.UC_X86_REG_ESP) == D.STACK + WORD
    D.assert_callee_saved(uc)
    instructions = R.function_instructions(entry)
    assert set(trace) <= instructions.keys(), set(trace) - instructions.keys()
    for addr in set(trace):
        ins = instructions[addr]
        assert bytes(uc.mem_read(addr, ins.size)) == ins.bytes


def mig_case(kind, arg1, arg2, result, converted, malformed=None):
    entry = 0x16f9f0 if kind == 'task' else 0x16eb34
    uc, trace = fresh([REQ, REPLY])
    request = [0, 0x20 if kind == 'task' else 0x28, PORT, 0, 0, 0,
               D.words(uc, 0x1e0384 if kind == 'task' else 0x1e0184, 1)[0], arg1,
               D.words(uc, 0x1e0188, 1)[0], arg2]
    if malformed == 'length':
        request[1] ^= WORD
    elif malformed == 'complex':
        request[0] |= 0x80000000
    elif malformed == 'first_type':
        request[6] ^= 1
    elif malformed == 'second_type':
        assert kind == 'thread'
        request[8] ^= 1
    elif malformed is not None:
        raise AssertionError(malformed)
    D.put(uc, REQ, *request)
    before = struct.pack('<' + 'I' * 16, *([SENTINEL] * 16))
    uc.mem_write(REPLY, before)
    expected = bytearray(before)
    calls = []
    if malformed:
        struct.pack_into('<I', expected, 0x1c, (-304) & MASK)
        finish(uc, trace, entry, entry)
        assert not any(R.function_instructions(entry)[a].mnemonic == 'call' for a in trace)
    else:
        convert = '_convert_port_to_task' if kind == 'task' else '_convert_port_to_thread'
        args = stopped_call(uc, entry, convert, 1)
        assert args == [PORT]
        calls.append({'name': convert, 'arguments': args, 'mocked': True})
        start = return_mock(uc, converted)
        api = '_task_create' if kind == 'task' else '_thread_policy'
        args = stopped_call(uc, start, api, 3)
        if kind == 'task':
            assert args == [converted, arg1, D.STACK - WORD * 2]
            if result == 0:
                D.put(uc, args[2], CHILD)
        else:
            assert args == [converted, arg1, arg2]
        calls.append({'name': api, 'arguments': args, 'mocked': True})
        start = return_mock(uc, result)
        dealloc = '_task_deallocate' if kind == 'task' else '_thread_deallocate'
        args = stopped_call(uc, start, dealloc, 1)
        assert args == [converted]
        calls.append({'name': dealloc, 'arguments': args, 'mocked': True})
        start = return_mock(uc, 0)
        struct.pack_into('<I', expected, 0x1c, result)
        if kind == 'task' and result == 0:
            args = stopped_call(uc, start, '_convert_task_to_port', 1)
            assert args == [CHILD]
            calls.append({'name': '_convert_task_to_port', 'arguments': args, 'mocked': True})
            start = return_mock(uc, CHILD_PORT)
            struct.pack_into('<I', expected, 0, SENTINEL | 0x80000000)
            struct.pack_into('<I', expected, 4, 0x28)
            struct.pack_into('<I', expected, 0x20, D.words(uc, 0x1e0388, 1)[0])
            struct.pack_into('<I', expected, 0x24, CHILD_PORT)
        finish(uc, trace, start, entry)
    assert bytes(uc.mem_read(REPLY, len(expected))) == bytes(expected)
    assert bytes(uc.mem_read(REQ, len(request) * WORD)) == struct.pack('<' + 'I' * len(request), *request)
    return {'kind': kind, 'arg1': arg1, 'arg2': arg2, 'mock_result': result, 'converted': converted,
            'malformed': malformed, 'calls': calls, 'reply_exact': True, 'request_unchanged': True,
            'stack_and_callee_saved_verified': True, 'trace': [hex(a) for a in trace]}


def thread_fast_cases():
    rows = []
    for thread, policy, data in itertools.product((0, HANDLE), (0, 1, 2, 4, 5, MASK), (0, 100, MASK)):
        if thread and 1 <= policy <= 4:
            continue
        uc, trace = fresh([thread, policy, data, 0xedededed, 0xfefefefe])
        entry = R.NAMES['_thread_policy']
        finish(uc, trace, entry, entry)
        assert uc.reg_read(X.UC_X86_REG_EAX) == 4
        assert not any(R.function_instructions(entry)[a].mnemonic == 'call' for a in trace)
        rows.append({'thread': thread, 'policy': policy, 'data': data, 'eax': 4,
                     'unmocked_original_fastpath': True, 'trace': [hex(a) for a in trace]})
    return rows


def panic_cases():
    rows = []
    for rpc_result in ((-202) & MASK, (-201) & MASK, 5):
        uc, trace = fresh([HANDLE, REPLY])
        entry = R.NAMES['_port_allocate_EXTERNAL']
        args = stopped_call(uc, entry, '_mig_get_reply_port', 0)
        start = return_mock(uc, PORT)
        rpc_args = stopped_call(uc, start, '_msg_rpc', 5)
        assert rpc_args[1:] == [0, 0x28, 0, 0]
        start = return_mock(uc, rpc_result)
        if rpc_result == ((-202) & MASK):
            D.run_to(uc, start, R.NAMES['_mig_dealloc_reply_port'])
            esp = uc.reg_read(X.UC_X86_REG_ESP)
            assert D.words(uc, esp, 1) == [0x1d049a]
            # No argument push occurs after the completed msg_rpc cleanup.
            start_index = trace.index(start)
            tail = trace[start_index:]
            original = R.function_instructions(entry)
            assert not any(original[a].mnemonic == 'push' for a in tail)
            args = stopped_call(uc, R.NAMES['_mig_dealloc_reply_port'], '_panic', 1)
            message = bytes(uc.mem_read(args[0], 128)).split(b'\0', 1)[0].decode('ascii')
            assert message == 'mig_dealloc_reply_port'
            assert 0x1d049a not in trace
            rows.append({'rpc_result': rpc_result, 'outcome': 'stopped_at_real_panic_entry',
                         'panic_message': message, 'dealloc_call_has_no_argument_push': True,
                         'rpc_mock_arguments': rpc_args, 'trace': [hex(a) for a in trace]})
        else:
            finish(uc, trace, start, entry)
            assert uc.reg_read(X.UC_X86_REG_EAX) == rpc_result
            assert 0x1d0495 not in trace
            rows.append({'rpc_result': rpc_result, 'outcome': 'ordinary_error_return',
                         'rpc_mock_arguments': rpc_args, 'trace': [hex(a) for a in trace]})
    return rows


def main():
    rows = []
    for inherit, result, parent in itertools.product((0, 1, MASK), (0, 4, 5, MASK), (0, HANDLE)):
        rows.append(mig_case('task', inherit, 0, result, parent))
    for policy, data, result, thread in itertools.product((0, 1, 2, 4, MASK), (0, 1, 100, MASK), (0, 4, 5), (0, HANDLE)):
        rows.append(mig_case('thread', policy, data, result, thread))
    for kind, defects in [('task', ('length', 'complex', 'first_type')),
                          ('thread', ('length', 'complex', 'first_type', 'second_type'))]:
        for defect in defects:
            rows.append(mig_case(kind, 1, 100, 0, HANDLE, defect))
    fast, panic = thread_fast_cases(), panic_cases()
    summary = {'mig_cases': len(rows), 'mig_cases_by_kind': dict(collections.Counter(r['kind'] for r in rows)),
               'malformed_cases': sum(r['malformed'] is not None for r in rows),
               'unmocked_thread_fast_cases': len(fast), 'rpc_error_cases': len(panic),
               'total_cases': len(rows) + len(fast) + len(panic), 'failures': 0,
               'binary_sha256': hashlib.sha256(R.RAW).hexdigest()}
    (HERE / 'mig-execution.json').write_text(json.dumps({'summary': summary, 'mig': rows, 'thread_fast': fast,
                                                       'rpc_errors': panic}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
