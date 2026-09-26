"""Single-sample INC/DEC analysis contract versus every original site.

This is a Python analysis model, not a Ghidra patch or GCC kernel source.
Normal memory/register completion only; no physical bus/SMP/page-fault proof.
"""
import collections
import importlib.util
import json
from scan import HERE, R

spec = importlib.util.spec_from_file_location('dispatch', HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py')
D = importlib.util.module_from_spec(spec)
spec.loader.exec_module(D)
X, U = D.X, D.U
FLAG_BITS = {'CF': 0, 'PF': 2, 'AF': 4, 'ZF': 6, 'SF': 7, 'OF': 11}
FLAG_MASK = sum(1 << bit for bit in FLAG_BITS.values())
GPRS = ('eax', 'ebx', 'ecx', 'edx', 'esi', 'edi', 'ebp', 'esp')


def normalized(operation, width, sampled_old, incoming_flags):
    """All result/flags use old/new temporaries, never re-read the operand."""
    bits = width * 8
    mask, sign = (1 << bits) - 1, 1 << (bits - 1)
    old = sampled_old & mask
    new = (old + (1 if operation == 'inc' else -1)) & mask
    flags = {'CF': bool(incoming_flags & 1), 'PF': (new & 0xff).bit_count() % 2 == 0,
             'AF': bool((old ^ new) & 0x10), 'ZF': new == 0, 'SF': bool(new & sign),
             'OF': old == (sign - 1 if operation == 'inc' else sign)}
    result_flags = incoming_flags & ~FLAG_MASK
    result_flags |= sum(int(flags[name]) << bit for name, bit in FLAG_BITS.items())
    return new, result_flags


def uc_register(name):
    return getattr(X, 'UC_X86_REG_' + name.upper())


def register_parts(name):
    if name in GPRS:
        return name, 0, 32
    if name in ('ax', 'bx', 'cx', 'dx', 'si', 'di', 'bp', 'sp'):
        return 'e' + name, 0, 16
    if name in ('al', 'bl', 'cl', 'dl', 'ah', 'bh', 'ch', 'dh'):
        return 'e' + name[0] + 'x', (8 if name[1] == 'h' else 0), 8
    raise AssertionError(name)


def ensure_mapped(uc, address, width):
    for page in range(address & -D.PAGE, ((address + width - 1) & -D.PAGE) + D.PAGE, D.PAGE):
        if not any(low <= page and page + D.PAGE - 1 <= high for low, high, _ in uc.mem_regions()):
            uc.mem_map(page, D.PAGE)


def site_cases(site, exhaustive_byte=False):
    uc, trace, _ = D.fixture(0x603, 'unlocked', 'hit')
    for name in GPRS:
        uc.reg_write(uc_register(name), D.DATA + 0x800 if name != 'esp' else D.STACK)
    width = site['width']
    bits = width * 8
    mask, sign = (1 << bits) - 1, 1 << (bits - 1)
    address = None
    if site['kind'] == 'memory':
        assert site['segment'] is None and site['address_size'] == 4
        address = site['displacement']
        if site['base']:
            address += uc.reg_read(uc_register(site['base']))
        if site['index']:
            address += uc.reg_read(uc_register(site['index'])) * site['scale']
        address &= (1 << (site['address_size'] * 8)) - 1
        ensure_mapped(uc, address, width)
        assert not (address < int(site['site'], 16) + site['length'] and int(site['site'], 16) < address + width)
    events = []

    def access(engine, kind, target, size, value, unused):
        assert target == address and size == width, (site, target, size)
        events.append(('read' if kind == U.UC_MEM_READ else 'write',
                       int.from_bytes(engine.mem_read(target, size), 'little') if kind == U.UC_MEM_READ else value & mask))

    uc.hook_add(U.UC_HOOK_MEM_READ | U.UC_HOOK_MEM_WRITE, access)
    if exhaustive_byte:
        assert width == 1
    values = list(range(mask + 1)) if exhaustive_byte else sorted({0, 1, 0xf, 0x10, sign - 1, sign, mask})
    rows = []
    for old in values:
        for carry in (0, 1):
            for dirty_status in (False, True):
                if site['kind'] == 'memory':
                    uc.mem_write(address, old.to_bytes(width, 'little'))
                else:
                    uc.reg_write(uc_register(site['register']), old)
                before_gpr = {name: uc.reg_read(uc_register(name)) for name in GPRS}
                incoming = 0x202 | carry | ((FLAG_MASK & ~1) if dirty_status else 0)
                uc.reg_write(X.UC_X86_REG_EFLAGS, incoming)
                trace.clear()
                events.clear()
                start = int(site['site'], 16)
                D.run_to(uc, start, start + site['length'])
                assert trace == [start]
                assert bytes(uc.mem_read(start, site['length'])).hex() == site['bytes']
                new, flags = normalized(site['mnemonic'], width, old, incoming)
                actual_flags = uc.reg_read(X.UC_X86_REG_EFLAGS)
                assert actual_flags == flags, (site, old, incoming, actual_flags, flags)
                expected_gpr = dict(before_gpr)
                if site['kind'] == 'memory':
                    assert int.from_bytes(uc.mem_read(address, width), 'little') == new
                    assert events == [('read', old), ('write', new)], (site, events)
                else:
                    assert uc.reg_read(uc_register(site['register'])) == new
                    assert not events
                    parent, shift, reg_bits = register_parts(site['register'])
                    reg_mask = ((1 << reg_bits) - 1) << shift
                    expected_gpr[parent] = (before_gpr[parent] & ~reg_mask) | (new << shift)
                assert {name: uc.reg_read(uc_register(name)) for name in GPRS} == expected_gpr
                # Compact reproducible rows; site and column descriptions are outside.
                rows.append([old, incoming, new, actual_flags, sum(k == 'read' for k, _ in events), sum(k == 'write' for k, _ in events)])
    return {'site': site['site'], 'owner': site['owner'], 'kind': site['kind'], 'width': width,
            'operation': site['mnemonic'], 'lock_prefix': site['lock_prefix'],
            'synthetic_operand_address': hex(address) if address is not None else None,
            'cases': rows, 'all_values_flags_registers_memory_effects_matched': True}


def main():
    scan = json.loads((HERE / 'scan.json').read_text())
    result = []
    for index, site in enumerate(scan['sites']):
        result.append(site_cases(site))
        if (index + 1) % 500 == 0:
            print(json.dumps({'sites_completed': index + 1, 'sites_total': len(scan['sites'])}), flush=True)
    summary = {'sites_executed': len(result), 'cases': sum(len(r['cases']) for r in result),
               'sites_by_kind': dict(collections.Counter(r['kind'] for r in result)),
               'sites_by_width': dict(collections.Counter(r['width'] for r in result)),
               'explicit_lock_sites': sum(r['lock_prefix'] for r in result),
               'mismatches': [], 'all_scanned_inc_dec_sites_executed': {r['site'] for r in result} == {r['site'] for r in scan['sites']},
               'limitations': ['Single instruction normal completion only.', 'Unicorn memory hooks are not physical bus observations.',
                              'No concurrent atomicity, page-fault restart, whole-function or GCC2.7 code-generation proof.',
                              'Python contract is not installed in Ghidra; previous decompiler limitations remain.']}
    (HERE / 'normalized-execution.json').write_text(json.dumps({'summary': summary,
        'case_columns': ['old', 'incoming_eflags', 'new', 'actual_eflags', 'memory_reads', 'memory_writes'], 'sites': result}, indent=2) + '\n')
    print(json.dumps(summary, indent=2), flush=True)


if __name__ == '__main__':
    main()
