"""Census SPARC raw op=2/op3=0x38 items without inferring runtime targets."""
import bisect
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'


def tsv_rows(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def raw_item(binary, unit, text_start, text_offset):
    address = int(unit['address'], 16)
    raw = binary[text_offset + address - text_start:text_offset + address - text_start + 4]
    assert raw.hex() == unit['bytes']
    return {'address': unit['address'], 'kind': unit['kind'],
            'original_bytes': raw.hex(), 'ida_disassembly': unit['disassembly']}


def in_candidate(address, starts, ranges):
    index = bisect.bisect_right(starts, address) - 1
    return index >= 0 and address < ranges[index][1]


def main():
    binary = (ROOT / '03_original/sparc/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/sparc/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_offset = int(text['file_offset'])
    candidates = tsv_rows(ROOT / '05_ida/exports/sparc/function-candidate-lexical-exits.tsv')
    ranges = sorted((int(row['start'], 16), int(row['end'], 16)) for row in candidates)
    starts = [start for start, _ in ranges]
    units_list = tsv_rows(ROOT / '05_ida/exports/sparc/text-units.tsv')
    units = {int(row['address'], 16): row for row in units_list}
    xrefs_by_source = {}
    for xref in tsv_rows(ROOT / '05_ida/exports/sparc/xrefs.tsv'):
        xrefs_by_source.setdefault(int(xref['from'], 16), []).append(xref)
    rows = []
    mnemonic_counts = Counter()
    membership_counts = Counter()
    rd_counts = Counter()
    rs1_counts = Counter()
    i_bit_counts = Counter()
    next_kind_counts = Counter()
    xref_type_counts = Counter()
    xref_source_count_counts = Counter()
    for unit in units_list:
        if unit['kind'] != 'code' or int(unit['length']) != 4:
            continue
        source = int(unit['address'], 16)
        source_item = raw_item(binary, unit, text_start, text_offset)
        word = int.from_bytes(bytes.fromhex(source_item['original_bytes']), 'big')
        if word >> 30 != 2 or ((word >> 19) & 0x3f) != 0x38:
            continue
        mnemonic = source_item['ida_disassembly'].split(None, 1)[0]
        membership = 'candidate' if in_candidate(source, starts, ranges) else 'candidate_gap'
        rd = word & 0x1f
        rs1 = (word >> 14) & 0x1f
        i_bit = (word >> 13) & 1
        next_unit = units.get(source + 4)
        next_item = None if next_unit is None else raw_item(binary, next_unit, text_start, text_offset)
        source_xrefs = xrefs_by_source.get(source, [])
        mnemonic_counts[mnemonic] += 1
        membership_counts[membership] += 1
        rd_counts[str(rd)] += 1
        rs1_counts[str(rs1)] += 1
        i_bit_counts[str(i_bit)] += 1
        next_kind_counts['no_text_item' if next_item is None else next_item['kind']] += 1
        xref_source_count_counts[str(len(source_xrefs))] += 1
        for xref in source_xrefs:
            xref_type_counts[f"{xref['type']}:{xref['iscode']}"] += 1
        rows.append({
            'source_item': source_item,
            'source_candidate_membership': membership,
            'raw_fields': {'rd': rd, 'rs1': rs1, 'i_bit': i_bit},
            'next_text_item': next_item,
            'xref_count_at_source': len(source_xrefs),
            'xref_type_counts_at_source': dict(sorted(Counter(
                f"{xref['type']}:{xref['iscode']}" for xref in source_xrefs).items())),
        })
    assert len(rows) == 6264
    output = {
        'schema': 1,
        'architecture': 'sparc',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'op2_op3_38_code_item_count': len(rows),
        'ida_mnemonic_counts_as_tool_observations': dict(sorted(mnemonic_counts.items())),
        'source_candidate_membership_counts': dict(sorted(membership_counts.items())),
        'raw_rd_field_counts': dict(sorted(rd_counts.items(), key=lambda item: int(item[0]))),
        'raw_rs1_field_counts': dict(sorted(rs1_counts.items(), key=lambda item: int(item[0]))),
        'raw_i_bit_counts': dict(sorted(i_bit_counts.items(), key=lambda item: int(item[0]))),
        'next_text_item_kind_counts': dict(sorted(next_kind_counts.items())),
        'xref_type_counts': dict(sorted(xref_type_counts.items())),
        'xref_count_at_source_counts': dict(sorted(xref_source_count_counts.items(), key=lambda item: int(item[0]))),
        'all_opcode_items_match_original_big_endian_bytes': True,
        'interpretation_limit': ('raw op=2/op3=0x38 fields, tool mnemonics, next items, and xref distributions do '
                                 'not establish instruction semantics, register values, runtime targets, execution, '
                                 'return behavior, function boundaries, calling convention, ABI, or behavior'),
        'rows': rows,
    }
    (REPORT / 'sparc-op2-op3-38-census-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'op2_op3_38_code_item_count': len(rows), 'all_checks_passed': True}))


if __name__ == '__main__':
    main()
