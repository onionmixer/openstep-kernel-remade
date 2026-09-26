"""Verify raw disp22 internal direct branches in the bounded _strncpy candidate."""
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
START = 0xF000791C
END = 0xF0007FAC
RETURNS = {0xF0007F64, 0xF0007F74, 0xF0007F98}


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def signed(value, bits):
    return value - (1 << bits) if value & (1 << (bits - 1)) else value


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
    binary = (ROOT / '03_original/sparc/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/sparc/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_offset = int(text['file_offset'])
    units = {int(unit['address'], 16): unit for unit in
             read_tsv(ROOT / '05_ida/exports/sparc/text-units.tsv')}
    xrefs = read_tsv(ROOT / '05_ida/exports/sparc/xrefs.tsv')
    branches = [xref for xref in xrefs if xref['type'] == '19'
                and START <= int(xref['from'], 16) < END]
    rows = []
    mnemonic_counts = Counter()
    return_target_edges = 0
    for xref in branches:
        source = int(xref['from'], 16)
        target = int(xref['to'], 16)
        assert START <= target < END
        source_unit = units[source]
        target_unit = units[target]
        source_item = raw_item(binary, source_unit, text_start, text_offset)
        target_item = raw_item(binary, target_unit, text_start, text_offset)
        raw = bytes.fromhex(source_item['original_bytes'])
        word = int.from_bytes(raw, 'big')
        assert word >> 30 == 0
        assert ((word >> 22) & 7) == 2
        displacement = signed(word & 0x3fffff, 22)
        computed_target = (source + (displacement << 2)) & 0xffffffff
        assert computed_target == target
        name = source_item['ida_disassembly'].split(None, 1)[0]
        mnemonic_counts[name] += 1
        if target in RETURNS:
            return_target_edges += 1
        rows.append({
            'source': hex(source),
            'target': hex(target),
            'signed_big_endian_disp22': displacement,
            'source_item': source_item,
            'target_item': target_item,
        })
    assert len(rows) == 101
    output = {
        'schema': 1,
        'architecture': 'sparc',
        'candidate': {'start': hex(START), 'end': hex(END), 'raw_symbol': '_strncpy'},
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'internal_direct_branch_count': len(rows),
        'branch_mnemonic_counts': dict(mnemonic_counts),
        'all_branch_targets_inside_candidate': True,
        'direct_branch_targeting_lexical_ret_count': return_target_edges,
        'all_big_endian_disp22_targets_match_type19_xrefs_and_original_items': True,
        'rows': rows,
        'interpretation_limit': ('direct branch edges and an absence of direct branch targets at lexical returns do not '
                                'establish fallthrough, path reachability, delay-slot execution, return behavior, '
                                'complete boundaries, ABI, or function behavior'),
    }
    (REPORT / 'sparc-strncpy-internal-branches-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'internal_direct_branch_count': len(rows),
                      'direct_branch_targeting_lexical_ret_count': return_target_edges,
                      'all_checks_passed': True}))


if __name__ == '__main__':
    main()
