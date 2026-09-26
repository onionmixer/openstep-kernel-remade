"""Isolated Unicorn repeated page-fault experiment; never touches kernel fixtures.

Context controls restore the entire opaque CPU context, not old_exception alone.
No private struct offsets, host memory patches or installed library changes.
"""
import hashlib
import json
from pathlib import Path
import struct
import unicorn as U
from unicorn import x86_const as X
from unicorn.unicorn_py3.unicorn import uclib

HERE = Path(__file__).resolve().parent
PD, PT, ENTRY, ABSENT, RAM_SIZE, NOP = 0x1000, 0x2000, 0x3000, 0x4000, 0x10000, 0x3005
FIELDS = ('eax', 'ebx', 'ecx', 'edx', 'esi', 'edi', 'ebp', 'esp', 'eip', 'eflags',
          'cs', 'ss', 'ds', 'es', 'fs', 'gs', 'cr0', 'cr2', 'cr3', 'cr4', 'gdtr', 'idtr', 'ldtr', 'tr')


def cpu(uc):
    return {name: uc.reg_read(getattr(X, 'UC_X86_REG_' + name.upper())) for name in FIELDS}


def memory_hash(uc):
    return hashlib.sha256(bytes(uc.mem_read(0, RAM_SIZE))).hexdigest()


def setup():
    uc = U.Uc(U.UC_ARCH_X86, U.UC_MODE_32)
    uc.mem_map(0, RAM_SIZE)
    # Pre-set A on present PDE/code PTE to avoid confusing page-walk A effects
    # with context memory restoration. The data PTE remains absent.
    uc.mem_write(PD, struct.pack('<I', PT | 0x23))
    uc.mem_write(PT + (ENTRY >> 12) * 4, struct.pack('<I', ENTRY | 0x23))
    uc.mem_write(ENTRY, b'\xa1' + struct.pack('<I', ABSENT) + b'\x90')
    uc.reg_write(X.UC_X86_REG_CR3, PD)
    uc.reg_write(X.UC_X86_REG_CR0, 0x80000011)
    uc.reg_write(X.UC_X86_REG_CR2, ABSENT)
    uc.reg_write(X.UC_X86_REG_EIP, ENTRY)
    uc.reg_write(X.UC_X86_REG_ESP, 0x9000)
    uc.reg_write(X.UC_X86_REG_EAX, 0x22222222)
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    return uc


def run(uc, entry, expected=None):
    before, before_hash = cpu(uc), memory_hash(uc)
    events, heads, writes = [], [], []
    def intr(engine, vector, unused):
        events.append({'vector': vector, 'cpu': cpu(engine)})
        engine.emu_stop()
    def code(engine, address, size, unused):
        heads.append({'address': address, 'size': size})
    def write(engine, access, address, width, value, unused):
        writes.append({'address': address, 'width': width, 'value': value})
    hooks = [uc.hook_add(U.UC_HOOK_INTR, intr), uc.hook_add(U.UC_HOOK_CODE, code), uc.hook_add(U.UC_HOOK_MEM_WRITE, write)]
    try:
        uc.emu_start(entry, 0, timeout=1000000, count=1)
    finally:
        for handle in hooks:
            uc.hook_del(handle)
    after = cpu(uc)
    assert not writes and len(heads) == 1
    assert heads[0]['address'] == entry
    if expected is None:
        assert not events and entry == NOP and after['eip'] == NOP + 1
    else:
        assert [e['vector'] for e in events] == [expected]
        assert events[0]['cpu'] == after and after['eip'] == ENTRY and after['cr2'] == ABSENT
        assert after['eax'] == 0x22222222, 'faulting load must not commit'
    return dict(before=before, after=after, before_ram_sha256=before_hash,
                after_ram_sha256=memory_hash(uc), events=events, heads=heads, writes=writes)


def main():
    cases = []
    uc = setup()
    cases.append({'name': 'same_instance_repeated_NP', 'runs': [run(uc, ENTRY, 14), run(uc, ENTRY, 8)]})
    uc = setup()
    cases.append({'name': 'NOP_between_NP', 'runs': [run(uc, ENTRY, 14), run(uc, NOP), run(uc, ENTRY, 8)]})
    cases.append({'name': 'fresh_instance', 'runs': [run(setup(), ENTRY, 14)]})
    uc = setup()
    clean = uc.context_save()
    first = run(uc, ENTRY, 14)
    before_cpu, before_ram = cpu(uc), memory_hash(uc)
    uc.context_restore(clean)
    after_cpu, after_ram = cpu(uc), memory_hash(uc)
    assert before_cpu == after_cpu and before_ram == after_ram
    cases.append({'name': 'prefault_context_restore', 'runs': [first, run(uc, ENTRY, 14)],
                  'restore_public_cpu_before': before_cpu, 'restore_public_cpu_after': after_cpu,
                  'restore_ram_before': before_ram, 'restore_ram_after': after_ram,
                  'public_state_equal': True, 'opaque_context_equal_claimed': False})
    uc = setup()
    first = run(uc, ENTRY, 14)
    dirty = uc.context_save()
    before_cpu, before_ram = cpu(uc), memory_hash(uc)
    uc.context_restore(dirty)
    assert cpu(uc) == before_cpu and memory_hash(uc) == before_ram
    cases.append({'name': 'postfault_context_restore', 'runs': [first, run(uc, ENTRY, 8)], 'public_state_equal': True})
    library = Path(uclib._name)
    result = {'unicorn_version': U.__version__, 'library': str(library),
              'library_sha256': hashlib.sha256(library.read_bytes()).hexdigest(),
              'geometry': {'pd': PD, 'pt': PT, 'entry': ENTRY, 'absent': ABSENT, 'ram_size': RAM_SIZE, 'nop': NOP},
              'code_hex': (b'\xa1' + struct.pack('<I', ABSENT) + b'\x90').hex(),
              'public_cpu_fields': list(FIELDS), 'cases': cases, 'all_expected_results_observed': True,
              'scope': 'independent synthetic minimal paging fixture; context controls never applied to OPENSTEP CPU',
              'kernel_reuse_completed': False}
    (HERE / 'exception-probe.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'cases': len(cases), 'vectors': {c['name']: [e['vector'] for r in c['runs'] for e in r['events']] for c in cases}}))


if __name__ == '__main__':
    main()
