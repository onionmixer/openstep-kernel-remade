"""Original power callers/wrappers and registry lookup with explicit boundary mocks.

ObjC routing/locks/class/protocol/perform and APM connect/event are mocked.
Lookup method and object-number helper execute original instructions.
"""
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
POWER = R.NAMES['__io_setDriverPowerState']
MANAGEMENT = R.NAMES['__ioSetDriverPowerManagementState']
LOOKUP_METHOD, LOOKUP_HELPER = 0x1a4bdc, 0x1a3d58
REGISTRY_COUNTER, REGISTRY_HEAD = 0x1e8668, 0x1e866c
SELECTOR_SLOTS = {'lookup': 0x1f9230, 'class': 0x1f9234, 'conforms': 0x1f9238,
                  'perform': 0x1f923c, 'power': 0x1f9240, 'management': 0x1f9244,
                  'lock': 0x1f9220, 'unlock': 0x1f9474}
SELECTORS = {k: struct.unpack('<I', R.read_original(a, D.WORD))[0] for k, a in SELECTOR_SLOTS.items()}
CLASS_RECEIVER = struct.unpack('<I', R.read_original(0x1f9d68, D.WORD))[0]
ROUTES = ('power_direct', 'management_direct', 'shutdown', 'pm', 'kern_pm', 'callout', 'init')
LAYOUTS = {'empty': (0, [], []), 'all': (4, [0, 1, 2, 3], [0, 1, 2, 3]),
           'holes': (4, [0, 2, 3], [0, 3]), 'nonconforming': (4, [0, 1, 2, 3], [])}
ENTRIES = [POWER, MANAGEMENT, LOOKUP_METHOD, LOOKUP_HELPER] + [R.NAMES[n] for n in
           ('_md_shutdown_devices', '_PMSetPowerState', '_kern_PMSetPowerState', '_power_callout', '_power_init')]
INSTRUCTIONS = {}
for entry in ENTRIES:
    INSTRUCTIONS.update(R.function_instructions(entry))


def ret(uc, value):
    esp = uc.reg_read(X.UC_X86_REG_ESP)
    address = D.words(uc, esp, 1)[0]
    uc.reg_write(X.UC_X86_REG_EAX, value & 0xffffffff)
    uc.reg_write(X.UC_X86_REG_ESP, esp + D.WORD)
    uc.reg_write(X.UC_X86_REG_EIP, address)


def case(route, seed, layout, requested_state):
    bound, active, conforming = LAYOUTS[layout]
    uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
    nodes = {n: D.DATA + 0x100 + n * 0x20 for n in active}
    objects = {n: D.DATA + 0x400 + n * 0x20 for n in active}
    classes = {n: D.DATA + 0x600 + n * 0x20 for n in active}
    D.put(uc, REGISTRY_COUNTER, bound)
    D.put(uc, REGISTRY_HEAD, nodes[active[0]] if active else REGISTRY_HEAD)
    for index, n in enumerate(active):
        nxt = nodes[active[index + 1]] if index + 1 < len(active) else REGISTRY_HEAD
        D.put(uc, nodes[n], objects[n], n, nxt)
    # Prevent BIOS execution; hardware/real scheduler are out of scope.
    D.put(uc, 0x1e75b8, 0)
    D.put(uc, 0x1df224, 0)
    uc.reg_write(X.UC_X86_REG_EBX, seed)
    entry_map = {'power_direct': POWER, 'management_direct': MANAGEMENT,
                 'shutdown': R.NAMES['_md_shutdown_devices'], 'pm': R.NAMES['_PMSetPowerState'],
                 'kern_pm': R.NAMES['_kern_PMSetPowerState'], 'callout': R.NAMES['_power_callout'],
                 'init': R.NAMES['_power_init']}
    if route in ('power_direct', 'management_direct'):
        args = [requested_state]
    elif route == 'shutdown':
        args = [0, 0, 0]
    elif route == 'pm':
        args = [1, requested_state]
    elif route == 'kern_pm':
        args = [0x1e97b0, 1, requested_state]
    elif route == 'callout':
        args = [0, seed]
    else:
        args = []
    D.put(uc, D.STACK, D.STOP, *args)
    # Stop init/callout after their first complete PMSetPowerState call.
    stop = {'callout': 0x160b4f, 'init': 0x160c5f}.get(route, D.STOP)
    events, lookup_numbers, performed, helper_results, power_entries = [], [], [], [], []
    lookup_return = next(i.address + i.size for i in R.function_instructions(LOOKUP_METHOD).values()
                         if i.mnemonic == 'call' and i.operands[0].type == R.X86_OP_IMM and i.operands[0].imm == LOOKUP_HELPER)

    def on_code(engine, address, size, unused):
        if address in (POWER, MANAGEMENT):
            power_entries.append({'entry': hex(address), 'ebx': hex(engine.reg_read(X.UC_X86_REG_EBX))})
        if address == lookup_return:
            helper_results.append(engine.reg_read(X.UC_X86_REG_EAX))
        if address == R.NAMES['_PMConnect']:
            events.append({'mock': 'PMConnect', 'result': 0})
            ret(engine, 0)
            return
        if address == R.NAMES['_PMGetPowerEvent']:
            esp = engine.reg_read(X.UC_X86_REG_ESP)
            ptr = D.words(engine, esp + D.WORD, 1)[0]
            D.put(engine, ptr, 1)
            events.append({'mock': 'PMGetPowerEvent', 'event': 1})
            ret(engine, 0)
            return
        if address == R.NAMES['_objc_msgSend']:
            esp = engine.reg_read(X.UC_X86_REG_ESP)
            return_address, receiver, selector = D.words(engine, esp, 3)
            if selector == SELECTORS['lookup']:
                number, out = D.words(engine, esp + D.WORD * 3, 2)
                assert receiver == CLASS_RECEIVER
                lookup_numbers.append(number)
                events.append({'routing_mock': 'lookup', 'number': number, 'output_pointer': hex(out)})
                engine.reg_write(X.UC_X86_REG_EIP, LOOKUP_METHOD)
                return
            if selector in (SELECTORS['lock'], SELECTORS['unlock']):
                events.append({'mock': 'lock' if selector == SELECTORS['lock'] else 'unlock'})
                ret(engine, 0)
                return
            if selector == SELECTORS['class']:
                n = next(n for n, obj in objects.items() if obj == receiver)
                events.append({'mock': 'class', 'object_number': n})
                ret(engine, classes[n])
                return
            if selector == SELECTORS['conforms']:
                n = next(n for n, cls in classes.items() if cls == receiver)
                assert D.words(engine, esp + D.WORD * 3, 1) == [0x1fdd2c]
                events.append({'mock': 'conforms', 'object_number': n, 'result': n in conforming})
                ret(engine, int(n in conforming))
                return
            if selector == SELECTORS['perform']:
                n = next(n for n, obj in objects.items() if obj == receiver)
                action, state = D.words(engine, esp + D.WORD * 3, 2)
                performed.append({'object_number': n, 'action': hex(action), 'state': state})
                events.append({'mock': 'perform', **performed[-1]})
                ret(engine, 0)
                return
            raise AssertionError(('Unexpected selector', hex(selector), hex(return_address)))
        assert address in INSTRUCTIONS, ('Unexpected original execution', hex(address))
        assert bytes(engine.mem_read(address, size)) == R.read_original(address, size)

    uc.hook_add(U.UC_HOOK_CODE, on_code)
    D.run_to(uc, entry_map[route], stop, count=20000)
    effective_start = 0 if route == 'init' else seed
    expected_numbers = list(range(effective_start, bound + 1)) if effective_start < bound else [effective_start]
    assert lookup_numbers == expected_numbers
    expected_performed = [n for n in range(effective_start, bound) if n in active and n in conforming]
    assert [p['object_number'] for p in performed] == expected_performed
    expected_state = 3 if route == 'shutdown' else 1 if route in ('callout', 'init') else requested_state
    expected_selector = SELECTORS['management'] if route == 'management_direct' else SELECTORS['power']
    assert all(p['state'] == expected_state and p['action'] == hex(expected_selector) for p in performed)
    assert len(power_entries) == 1 and power_entries[0]['ebx'] == hex(effective_start)
    assert helper_results == [((-704 if n >= bound else 0 if n in active else -727) & 0xffffffff) for n in lookup_numbers]
    assert trace.count(LOOKUP_HELPER) == len(lookup_numbers)
    expected_ebx = 0 if route == 'init' else seed
    assert uc.reg_read(X.UC_X86_REG_EBX) == expected_ebx
    if route not in ('callout', 'init'):
        assert uc.reg_read(X.UC_X86_REG_ESP) == D.STACK + D.WORD
        for n in ('esi', 'edi', 'ebp'):
            reg, value = D.REGS[n]
            assert uc.reg_read(reg) == value
    return {'route': route, 'ambient_or_handle_ebx': hex(seed), 'effective_start': effective_start,
            'layout': layout, 'requested_state': requested_state, 'lookup_numbers': lookup_numbers,
            'helper_results': [hex(v) for v in helper_results], 'performed': performed,
            'power_entries': power_entries, 'stop': hex(stop), 'events': events,
            'trace': [hex(a) for a in trace]}


def main():
    assert hashlib.sha256(R.RAW).hexdigest() == '33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890'
    rows = [case(route, seed, layout, state) for route in ROUTES
            for seed in (0, 1, 2, 3, 4, 0x600100, 0xffffffff) for layout in LAYOUTS for state in (1, 3)]
    summary = {'cases': len(rows), 'routes': list(ROUTES), 'layouts': LAYOUTS,
               'cases_no_perform': sum(not r['performed'] for r in rows), 'unicorn_version': U.__version__,
               'real_lookup_helper': hex(LOOKUP_HELPER), 'real_lookup_method': hex(LOOKUP_METHOD)}
    (HERE / 'power-execution.json').write_text(json.dumps({'summary': summary, 'cases': rows,
          'limits': 'Synthetic registry and boundary mocks; no real driver/power/locking/APM/scheduler execution. init/callout stop after first PMSetPowerState return. Not a boot or hardware-failure proof.'}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
