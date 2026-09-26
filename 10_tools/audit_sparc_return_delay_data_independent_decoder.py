"""Record a big-endian independent-decoder observation for two SPARC data delay slots."""
import csv
import hashlib
import json
from pathlib import Path

import capstone

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
ADDRESSES = (0xF0007154, 0xF000721C)


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def main():
    binary = (ROOT / '03_original/sparc/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/sparc/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_offset = int(text['file_offset'])
    units = {int(unit['address'], 16): unit for unit in
             read_tsv(ROOT / '05_ida/exports/sparc/text-units.tsv')}
    decoder = capstone.Cs(capstone.CS_ARCH_SPARC, capstone.CS_MODE_BIG_ENDIAN)
    rows = []
    for address in ADDRESSES:
        unit = units[address]
        position = text_offset + address - text_start
        original = binary[position:position + int(unit['length'])]
        assert unit['kind'] == 'data'
        assert original.hex() == unit['bytes'] == '01000000'
        decoded = list(decoder.disasm(original, address))
        assert len(decoded) == 1
        instruction = decoded[0]
        rows.append({
            'address': hex(address),
            'ida_text_unit_kind': unit['kind'],
            'original_big_endian_bytes': original.hex(),
            'capstone_version': capstone.__version__,
            'capstone_architecture': 'CS_ARCH_SPARC',
            'capstone_mode': 'CS_MODE_BIG_ENDIAN',
            'independent_decoder': {
                'address': hex(instruction.address),
                'bytes': instruction.bytes.hex(),
                'mnemonic': instruction.mnemonic,
                'operands': instruction.op_str,
            },
        })
    output = {
        'schema': 1,
        'architecture': 'sparc',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'address_count': len(rows),
        'rows': rows,
        'all_ida_data_items_and_original_bytes_match': True,
        'interpretation_limit': ('an independent decoder rendering does not reclassify IDA data, establish '
                                'delay-slot execution, reachability, candidate boundaries, ABI, or behavior'),
    }
    (REPORT / 'sparc-return-delay-data-independent-decoder-observation.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'address_count': len(rows), 'all_checks_passed': True}))


if __name__ == '__main__':
    main()
