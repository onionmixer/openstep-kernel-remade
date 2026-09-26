"""Inspect direct-call adjacent data items without changing their classification."""
import csv
import hashlib
import json
from bisect import bisect_right
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
EXPECTED = {'m68k': 2, 'sparc': 4}


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def raw_item(binary, unit, text_start, text_offset):
    address = int(unit['address'], 16)
    position = text_offset + address - text_start
    original = binary[position:position + int(unit['length'])]
    assert original.hex() == unit['bytes']
    return {
        'address': unit['address'],
        'kind': unit['kind'],
        'original_bytes': original.hex(),
        'ida_disassembly': unit['disassembly'],
    }


def main():
    adjacency = json.loads((REPORT / 'multiarch-direct-call-adjacency-audit.json').read_text())
    architectures = {}
    for architecture in ('m68k', 'sparc'):
        binary = (ROOT / '03_original' / architecture / 'binaries/mach_kernel').read_bytes()
        inventory = json.loads((ROOT / '03_original' / architecture / 'inventory/macho.json').read_text())
        text = next(section for section in inventory['sections']
                    if section['segment'] == '__TEXT' and section['name'] == '__text')
        text_start = int(text['address'], 16)
        text_offset = int(text['file_offset'])
        units = read_tsv(ROOT / '05_ida/exports' / architecture / 'text-units.tsv')
        unit_index = {int(unit['address'], 16): index for index, unit in enumerate(units)}
        candidates = json.loads((ROOT / '05_ida/exports' / architecture / 'function-asm-index.json').read_text())
        ranges = sorted((int(candidate['start'], 16), int(candidate['end'], 16), candidate['name'])
                        for candidate in candidates)
        range_starts = [start for start, _end, _name in ranges]

        def owner(address):
            index = bisect_right(range_starts, address) - 1
            if index >= 0:
                start, end, name = ranges[index]
                if start <= address < end:
                    return {'start': hex(start), 'end': hex(end), 'name': name}
            return None

        rows = []
        for row in adjacency['architectures'][architecture]['rows']:
            for role, item in row['adjacent_items'].items():
                if item['kind'] == 'code':
                    continue
                source = int(row['source'], 16)
                target = int(row['target'], 16)
                source_index = unit_index[source]
                data_index = unit_index[int(item['address'], 16)]
                context_indexes = sorted({max(0, data_index - 1), data_index,
                                          min(len(units) - 1, data_index + 1), source_index})
                rows.append({
                    'source': row['source'],
                    'target': row['target'],
                    'edge_kind': row['edge_kind'],
                    'noncode_adjacent_role': role,
                    'source_candidate_owner': owner(source),
                    'target_candidate_owner': owner(target),
                    'context_items': [raw_item(binary, units[index], text_start, text_offset)
                                      for index in context_indexes],
                })
        assert len(rows) == EXPECTED[architecture]
        architectures[architecture] = {
            'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
            'noncode_adjacent_direct_call_count': len(rows),
            'all_exception_context_items_match_original_big_endian_bytes': True,
            'rows': rows,
        }
    output = {
        'schema': 1,
        'architectures': architectures,
        'interpretation_limit': ('adjacent data and current candidate ownership are boundary observations only; '
                                'they do not establish data semantics, argument preparation, delay-slot execution, '
                                'call return, reachability, function boundaries, ABI, or behavior'),
    }
    (REPORT / 'direct-call-adjacency-noncode-exceptions-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({architecture: {
        'noncode_adjacent_direct_call_count': data['noncode_adjacent_direct_call_count'],
        'all_checks_passed': True,
    } for architecture, data in architectures.items()}))


if __name__ == '__main__':
    main()
