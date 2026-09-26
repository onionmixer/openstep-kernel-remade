"""Extract raw LINK/SAVE entry operand fields from directly called targets only."""
import csv
import hashlib
import json
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
EXPECTED = {'m68k': 562, 'sparc': 2465}


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def signed(value, bits):
    return value - (1 << bits) if value & (1 << (bits - 1)) else value


def mnemonic(disassembly):
    return disassembly.split(None, 1)[0] if disassembly else '<empty>'


def main():
    architectures = {}
    for architecture in ('m68k', 'sparc'):
        binary = (ROOT / '03_original' / architecture / 'binaries/mach_kernel').read_bytes()
        inventory = json.loads((ROOT / '03_original' / architecture / 'inventory/macho.json').read_text())
        text = next(section for section in inventory['sections']
                    if section['segment'] == '__TEXT' and section['name'] == '__text')
        text_start = int(text['address'], 16)
        text_offset = int(text['file_offset'])
        edges = read_tsv(ROOT / '05_ida/exports' / architecture / 'direct-call-edges.tsv')
        incoming = defaultdict(int)
        for edge in edges:
            incoming[int(edge['target'], 16)] += 1
        units = {int(unit['address'], 16): unit for unit in
                 read_tsv(ROOT / '05_ida/exports' / architecture / 'text-units.tsv')}
        rows = []
        immediate_counts = Counter()
        save_i_bit_counts = Counter()
        save_rs1_counts = Counter()
        save_rd_counts = Counter()
        for target, caller_count in sorted(incoming.items()):
            unit = units[target]
            if architecture == 'm68k' and not unit['bytes'].startswith('4e56'):
                continue
            if architecture == 'sparc' and mnemonic(unit['disassembly']) != 'save':
                continue
            position = text_offset + target - text_start
            original = binary[position:position + int(unit['length'])]
            assert unit['kind'] == 'code'
            assert original.hex() == unit['bytes']
            if architecture == 'm68k':
                assert mnemonic(unit['disassembly']) == 'link'
                assert original[:2] == bytes.fromhex('4e56')
                immediate = int.from_bytes(original[2:4], 'big', signed=True)
                immediate_counts[immediate] += 1
                fields = {'signed_16bit_immediate': immediate}
            else:
                word = int.from_bytes(original, 'big')
                assert word >> 30 == 2
                rs1 = (word >> 14) & 0x1f
                rd = (word >> 25) & 0x1f
                immediate_mode = (word >> 13) & 1
                fields = {'rs1_field': rs1, 'rd_field': rd, 'i_bit': immediate_mode}
                save_i_bit_counts[immediate_mode] += 1
                save_rs1_counts[rs1] += 1
                save_rd_counts[rd] += 1
                if immediate_mode:
                    immediate = signed(word & 0x1fff, 13)
                    fields['signed_13bit_immediate'] = immediate
                    immediate_counts[immediate] += 1
                else:
                    fields['rs2_field'] = word & 0x1f
            rows.append({
                'target': hex(target),
                'direct_caller_edge_count': caller_count,
                'entry_original_bytes': original.hex(),
                'ida_disassembly': unit['disassembly'],
                'raw_operand_fields': fields,
            })
        assert len(rows) == EXPECTED[architecture]
        result = {
            'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
            'entry_observation_count': len(rows),
            'signed_immediate_counts': {str(key): value for key, value in immediate_counts.items()},
            'all_observed_entry_bytes_match_original_big_endian_bytes': True,
            'rows': rows,
        }
        if architecture == 'sparc':
            result['save_i_bit_counts'] = {str(key): value for key, value in save_i_bit_counts.items()}
            result['save_rs1_field_counts'] = {str(key): value for key, value in save_rs1_counts.items()}
            result['save_rd_field_counts'] = {str(key): value for key, value in save_rd_counts.items()}
        architectures[architecture] = result
    output = {
        'schema': 1,
        'architectures': architectures,
        'interpretation_limit': ('raw LINK/SAVE operand fields are instruction-level observations only; they do not '
                                'establish a stack frame, local variables, arguments, function boundaries, calling '
                                'convention, ABI, or behavior'),
    }
    (REPORT / 'direct-target-entry-frame-operand-observations.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({architecture: {
        'entry_observation_count': data['entry_observation_count'],
        'all_checks_passed': True,
    } for architecture, data in architectures.items()}))


if __name__ == '__main__':
    main()
