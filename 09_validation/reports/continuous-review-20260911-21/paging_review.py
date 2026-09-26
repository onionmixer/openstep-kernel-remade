"""Execute original bootstrap and callees with synthetic, explicitly bounded RAM.

All calculations use Python. No binary patches, call mocks, or database edits.
Unicorn execution and the independent Python walker are not hardware boot proof.
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
ROOT = HERE.parents[2]
spec = importlib.util.spec_from_file_location('dispatch', HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py')
D = importlib.util.module_from_spec(spec)
spec.loader.exec_module(D)
R, U, X = D.R, D.U, D.X
PAGE, MASK, BASE = 0x1000, 0xffffffff, 0xc0000000
PMAP, STORE, GPTR = 0x1f63f0, 0x1f7a60, 0x1e19b0
REGION, AVAILABLE, END = 0x1f6e60, 0x1f63f8, 0x1f6e9c
RAM_SIZE, POOL = 0x1000000, 0x400000
INS = R.function_instructions(R.NAMES['_pmap_bootstrap'])


def run(uc, start, end):
    uc.ctl_remove_cache(start & -PAGE, (start & -PAGE) + PAGE)
    uc.emu_start(start, end, timeout=20000000, count=3000000)
    assert uc.reg_read(X.UC_X86_REG_EIP) == end, hex(uc.reg_read(X.UC_X86_REG_EIP))


def walk(uc, directory, linear):
    pde_address = directory + ((linear >> 22) & 0x3ff) * D.WORD
    pde, = D.words(uc, pde_address, 1)
    assert not pde & 0x80, 'Large pages outside this walker contract'
    row = {'linear': hex(linear), 'pde_address': hex(pde_address), 'pde': hex(pde)}
    if not pde & 1:
        return dict(row, present=False)
    pte_address = (pde & 0xfffff000) + ((linear >> 12) & 0x3ff) * D.WORD
    pte, = D.words(uc, pte_address, 1)
    row.update(pte_address=hex(pte_address), pte=hex(pte), present=bool(pte & 1))
    if pte & 1:
        row['physical'] = hex((pte & 0xfffff000) | (linear & 0xfff))
        row['writable'] = bool(pde & pte & 2)
        row['user'] = bool(pde & pte & 4)
    return row


def fixture(phys_end, conventional):
    uc = U.Uc(U.UC_ARCH_X86, U.UC_MODE_32)
    uc.mem_map(0, RAM_SIZE)
    for seg in R.META['segments']:
        if seg['file_size']:
            uc.mem_write(int(seg['address'], 16), R.RAW[seg['file_offset']:seg['file_offset'] + seg['file_size']])
    # Initialize descriptors with original code, then supply a flat protected-mode
    # entry state. This does not execute the bootloader or all of _i386_init.
    uc.reg_write(X.UC_X86_REG_ESP, D.STACK)
    D.put(uc, D.STACK, D.STOP)
    run(uc, R.NAMES['_gdt_init'], D.STOP)
    for reg, selector in ((X.UC_X86_REG_CS, 0x48), (X.UC_X86_REG_SS, 0x50),
                           (X.UC_X86_REG_DS, 0x50), (X.UC_X86_REG_ES, 0x50),
                           (X.UC_X86_REG_FS, 0x50), (X.UC_X86_REG_GS, 0x50)):
        uc.reg_write(reg, selector)
    for reg, value in D.REGS.values():
        uc.reg_write(reg, value)
    for address, value in ((0x1e0d0c, 0x2000), (0x1e89ec, 0x1fff), (0x1e2484, 0),
                            (0x1e75fc, 0), (0x1e7610, conventional), (0x1e7614, 0x90000),
                            (0x1f6e74, POOL), (REGION + 0x18, phys_end)):
        D.put(uc, address, value)
    uc.mem_write(0x1285c, b'\0\0')  # Video mapping branch deliberately excluded.
    uc.reg_write(X.UC_X86_REG_EFLAGS, 2)
    uc.reg_write(X.UC_X86_REG_ESP, D.STACK)
    D.put(uc, D.STACK, D.STOP, REGION, 1, AVAILABLE, END)
    return uc


def main():
    cases, all_visited = [], set()
    for phys_end, conventional in itertools.product((0x800000, 0xc00000), (0x20000, 0x31000)):
        uc = fixture(phys_end, conventional)
        visits = collections.Counter()
        control = []
        def trace(engine, address, size, unused):
            visits[address] += 1
            if address in (0x18f2a3, 0x18f31a, 0x18f323, 0x18f326):
                control.append({'site': hex(address), 'cr0': hex(engine.reg_read(X.UC_X86_REG_CR0)),
                                'cr3': hex(engine.reg_read(X.UC_X86_REG_CR3)),
                                'ebx': hex(engine.reg_read(X.UC_X86_REG_EBX)),
                                'edx': hex(engine.reg_read(X.UC_X86_REG_EDX))})
        hook = uc.hook_add(U.UC_HOOK_CODE, trace)
        initial_cr0 = uc.reg_read(X.UC_X86_REG_CR0)
        run(uc, R.NAMES['_pmap_bootstrap'], D.STOP)
        uc.hook_del(hook)
        D.assert_callee_saved(uc)
        assert uc.reg_read(X.UC_X86_REG_ESP) == D.STACK + D.WORD
        directory = uc.reg_read(X.UC_X86_REG_CR3)
        root, stored_physical = D.words(uc, STORE, 2)
        assert directory == stored_physical == conventional
        assert root == directory + ((BASE >> 22) * D.WORD)
        assert uc.reg_read(X.UC_X86_REG_CR0) == initial_cr0 | 0x80010000
        assert D.words(uc, AVAILABLE, 1) == [phys_end]
        assert D.words(uc, END, 1) == [phys_end + 0x4000000]
        # Mask hardware A/D bits for the directory equality check after paging.
        low = D.words(uc, directory, 0x100)
        high = D.words(uc, root, 0x100)
        assert [v & ~0x20 for v in low] == [v & ~0x20 for v in high]
        aliases = []
        gdt, = D.words(uc, GPTR, 1)
        for offset in (0, 0x9ffff, 0xa0000, 0xfffff, 0x100000, gdt, directory,
                       D.STACK, D.DATA + 0x900, phys_end - 1):
            pair = [walk(uc, directory, linear) for linear in (offset, BASE + offset)]
            assert all(r['present'] and int(r['physical'], 16) == offset for r in pair)
            assert all(r['writable'] and not r['user'] for r in pair)
            aliases.append(pair)
        absent = [walk(uc, directory, linear) for linear in (phys_end, BASE + phys_end)]
        assert all(not r['present'] for r in absent)
        cache_rows = [walk(uc, directory, BASE + offset) for offset in (0x9f000, 0xa0000, 0xff000, 0x100000)]
        assert [bool(int(r['pte'], 16) & 8) for r in cache_rows] == [False, True, True, False]
        relocation_end = 0x18ab8f + R.function_instructions(R.NAMES['_i386_init'])[0x18ab8f].size
        run(uc, 0x18ab84, relocation_end)
        assert uc.reg_read(X.UC_X86_REG_GDTR)[1:3] == (BASE + gdt, 0xff)
        # Loading ES now requires the high GDTR linear address to resolve through
        # the page tables. Use original MOV FS and original REP instructions.
        uc.reg_write(X.UC_X86_REG_ES, 0x10)
        fs = R.function_instructions(0x186ddc)[0x186dfc]
        uc.reg_write(X.UC_X86_REG_EAX, 0x50)
        run(uc, fs.address, fs.address + fs.size)
        rep_rows = []
        for site in (0x189a7e, 0x189a9f, 0x189ab7, 0x189b65, 0x189b87, 0x189b9f):
            # Decode from original bytes directly.
            ins = next(R.CS.disasm(R.read_original(site, 15), site, count=1))
            assert ins.mnemonic.startswith('rep movs')
            width = ins.operands[0].size
            for count, df in itertools.product((1, 3), (0, 1)):
                source, dest = D.DATA + 0x500, D.DATA + 0x900
                direction = -1 if df else 1
                for index in range(count):
                    uc.mem_write(source + direction * index * width, bytes([0xa5]) * width)
                    uc.mem_write(dest + direction * index * width, bytes([0xcc]) * width)
                for reg, val in ((X.UC_X86_REG_ECX, count), (X.UC_X86_REG_ESI, source), (X.UC_X86_REG_EDI, dest),
                                 (X.UC_X86_REG_EFLAGS, 2 | df << 10)):
                    uc.reg_write(reg, val)
                run(uc, site, site + ins.size)
                assert uc.reg_read(X.UC_X86_REG_ECX) == 0
                assert uc.reg_read(X.UC_X86_REG_ESI) == source + direction * count * width
                assert uc.reg_read(X.UC_X86_REG_EDI) == dest + direction * count * width
                for index in range(count):
                    physical = dest + direction * index * width
                    assert bytes(uc.mem_read(physical, width)) == bytes([0xa5]) * width
                rep_rows.append({'site': hex(site), 'width': width, 'count': count, 'df': df,
                                 'fs_base': 0, 'es_base': hex(BASE), 'physical_destination_matches_flat_offset': True})
        for pc in visits:
            ins = next(R.CS.disasm(R.read_original(pc, 15), pc, count=1))
            assert bytes(uc.mem_read(pc, ins.size)) == ins.bytes, hex(pc)
        all_visited.update(visits)
        cases.append({'physical_end': hex(phys_end), 'conventional_start': hex(conventional),
                      'cr0_before': hex(initial_cr0), 'control_transitions': control,
                      'directory': hex(directory), 'pmap_root': hex(root),
                      'available': hex(D.words(uc, AVAILABLE, 1)[0]), 'end': hex(D.words(uc, END, 1)[0]),
                      'allocation_end': hex(D.words(uc, 0x1f6e74, 1)[0]),
                      'instruction_visits': sum(visits.values()), 'unique_instructions': len(visits),
                      'visits': {hex(pc): n for pc, n in sorted(visits.items())},
                      'aliases': aliases, 'not_present_controls': absent, 'cache_boundary_entries': cache_rows,
                      'relocated_gdtr': list(uc.reg_read(X.UC_X86_REG_GDTR)), 'rep_tests': rep_rows})
        print(json.dumps({'case': len(cases), 'visits': sum(visits.values()), 'rep_tests': len(rep_rows)}), flush=True)
    summary = {'bootstrap_original_execution_cases': len(cases),
               'instruction_visits': sum(r['instruction_visits'] for r in cases),
               'unique_bootstrap_and_callee_instructions': len(all_visited),
               'low_high_alias_pairs': sum(len(r['aliases']) for r in cases),
               'paging_enabled_relocated_gdt_rep_tests': sum(len(r['rep_tests']) for r in cases),
               'mocked_calls': 0, 'patched_original_instructions': 0,
               'full_boot_or_all_runtime_mapping_invariant_proven': False}
    contexts = {}
    for entry in sorted(R.FMAP):
        seq = R.function_instructions(entry)
        if set(seq) & all_visited or entry in (R.NAMES['_gdt_init'], R.NAMES['_i386_init'], R.NAMES['_locate_gdt']):
            contexts[f'{entry:08x}'] = R.FMAP[entry]['name']
    result = {'summary': summary, 'binary_sha256': hashlib.sha256(R.RAW).hexdigest(),
              'original_contexts': contexts, 'cases': cases,
              'limits': ['Synthetic RAM and boot globals; _i386_init and firmware are not executed end-to-end.',
                         'Unicorn paging/segmentation behavior plus Python two-level walker, not physical hardware proof.',
                         'Video branch disabled; allocator failure, nonzero pmap_initialized and later user pmaps excluded.',
                         'REP instructions execute in initialized state, not entire copyin functions.',
                         'Initial low/high aliases explain selected flat-offset results but are not a global address-space contract.',
                         'Raw/high p-code was not changed and no GCC 2.7 implementation was produced.']}
    (HERE / 'paging-review.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
