"""Stable-memory raw P-code flag comparison, with AF omission made explicit."""
import hashlib
import json
from pathlib import Path
import re
from normalized_execution import HERE, R, normalized, FLAG_BITS, FLAG_MASK


def node(text):
    m = re.fullmatch(r'\(([^,]+), (0x[0-9a-f]+), ([0-9]+)\)', text)
    assert m, text
    return m[1], int(m[2], 16), int(m[3])


def signed(value, width):
    bits = width * 8
    return value - (1 << bits) if value & (1 << (bits - 1)) else value


def interpret(operations, address, initial, incoming, registers):
    state = {('ram', address, 4): initial}
    state.update({('register', offset, 1): (incoming >> FLAG_BITS[name]) & 1 for name, offset in registers.items()})

    def get(text):
        n = node(text)
        return n[1] if n[0] == 'const' else state[n]

    for op in operations:
        args = [get(text) for text in op['inputs']]
        code = op['opcode']
        if code == 'INT_ADD':
            value = args[0] + args[1]
        elif code == 'INT_SUB':
            value = args[0] - args[1]
        elif code in ('INT_SCARRY', 'INT_SBORROW'):
            width = node(op['inputs'][0])[2]
            result = signed(args[0], width) + (signed(args[1], width) if code == 'INT_SCARRY' else -signed(args[1], width))
            sign = 1 << (width * 8 - 1)
            value = not (-sign <= result < sign)
        elif code == 'INT_SLESS':
            width = node(op['inputs'][0])[2]
            value = signed(args[0], width) < signed(args[1], width)
        elif code == 'INT_EQUAL':
            value = args[0] == args[1]
        elif code == 'INT_AND':
            value = args[0] & args[1]
        elif code == 'POPCOUNT':
            value = args[0].bit_count()
        else:
            raise AssertionError(op)
        out = node(op['output'])
        state[out] = int(value) & ((1 << (out[2] * 8)) - 1)
    result_flags = incoming & ~FLAG_MASK
    result_flags |= sum(state[('register', offset, 1)] << FLAG_BITS[name] for name, offset in registers.items())
    return state[('ram', address, 4)], result_flags


def main():
    language = Path('/home/onion/ghidra_12.1_PUBLIC/Ghidra/Processors/x86/data/languages/ia.sinc')
    text = language.read_text()
    match = re.search(r'define register offset=(0x[0-9a-f]+) size=1\s*\[\s*CF\b([^]]*)\]', text)
    assert match
    names = ['CF'] + match[2].split()
    base = int(match[1], 16)
    registers = {name: base + names.index(name) for name in FLAG_BITS}
    raw_path = HERE.parent / 'continuous-review-20260911-11/exports/pcode.json'
    function = next(f for f in json.loads(raw_path.read_text()) if f['entry'] == '0015ec00')
    samples = [i for i in function['raw_instructions'] if i['address'] in ('0015ec81', '0015ec87')]
    rows = []
    for sample in samples:
        ins = R.function_instructions(R.NAMES['_mfs_cache_trim'])[int(sample['address'], 16)]
        address = ins.operands[0].mem.disp
        assert not any(node(op['output'])[:2] == ('register', registers['AF']) for op in sample['operations'] if op.get('output'))
        for old in (0, 1, 0xf, 0x10, 0x7fffffff, 0x80000000, 0xffffffff):
            for carry in (0, 1):
                for af in (0, 1):
                    incoming = 0x202 | carry | (af << FLAG_BITS['AF'])
                    expected_value, expected_flags = normalized(ins.mnemonic, 4, old, incoming)
                    actual_value, actual_flags = interpret(sample['operations'], address, old, incoming, registers)
                    assert actual_value == expected_value
                    differing = [name for name, bit in FLAG_BITS.items() if bool(actual_flags & (1 << bit)) != bool(expected_flags & (1 << bit))]
                    assert set(differing) <= {'AF'}
                    assert bool(actual_flags & (1 << FLAG_BITS['AF'])) == bool(af)
                    rows.append({'site': sample['address'], 'old': old, 'incoming_flags': incoming,
                                 'raw_pcode_flags': actual_flags, 'normalized_flags': expected_flags, 'different_flags': differing})
    scan = json.loads((HERE / 'scan.json').read_text())
    summary = {'raw_pcode_samples': len(samples), 'cases': len(rows),
               'af_mismatch_cases': sum(bool(r['different_flags']) for r in rows),
               'other_flag_mismatch_cases': sum(bool(set(r['different_flags']) - {'AF'}) for r in rows),
               'flag_consumer_inventory': len(scan['flag_consumers']),
               'raw_pcode_full_flag_fidelity_pass': False,
               'limits': ['Stable-memory sample P-code interpretation only; not all Ghidra INC/DEC forms extracted.',
                          'Consumer inventory is not a reaching-definitions proof or an assertion of real runtime impact.']}
    (HERE / 'flags-review.json').write_text(json.dumps({'summary': summary, 'flag_register_offsets': registers,
                                                      'samples': samples, 'cases': rows, 'consumer_inventory': scan['flag_consumers']}, indent=2) + '\n')
    paths = [language, raw_path, R.ROOT / '03_original/x86/binaries/mach_kernel',
             HERE.parent / 'cautious-followup-20260911/review.py',
             HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py']
    (HERE / 'input-hashes.json').write_text(json.dumps([{'path': str(p.relative_to(R.ROOT)) if p.is_relative_to(R.ROOT) else str(p),
                                                       'size': p.stat().st_size, 'sha256': hashlib.sha256(p.read_bytes()).hexdigest()} for p in paths], indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
