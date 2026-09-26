"""Preserve raw SPARC op3=0x38 type-19 xref target sets without target calculation."""
import bisect
import csv
import hashlib
import json
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'


def rows(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def raw_item(binary, unit, text_start, text_offset):
    address = int(unit['address'], 16)
    raw = binary[text_offset + address - text_start:
                 text_offset + address - text_start + int(unit['length'])]
    assert raw.hex() == unit['bytes']
    return {'address': unit['address'], 'kind': unit['kind'],
            'original_bytes': raw.hex(), 'ida_disassembly': unit['disassembly']}


def membership(address, starts, ranges):
    index = bisect.bisect_right(starts, address) - 1
    return 'candidate' if index >= 0 and address < ranges[index][1] else 'candidate_gap'


def main():
    binary = (ROOT / '03_original/sparc/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/sparc/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_offset = int(text['file_offset'])
    candidates = rows(ROOT / '05_ida/exports/sparc/function-candidate-lexical-exits.tsv')
    ranges = sorted((int(row['start'], 16), int(row['end'], 16)) for row in candidates)
    starts = [start for start, _ in ranges]
    units = {int(row['address'], 16): row for row in rows(ROOT / '05_ida/exports/sparc/text-units.tsv')}
    by_source = defaultdict(list)
    for xref in rows(ROOT / '05_ida/exports/sparc/xrefs.tsv'):
        source = int(xref['from'], 16)
        if xref['type'] != '19' or source not in units:
            continue
        word = int.from_bytes(bytes.fromhex(units[source]['bytes']), 'big')
        if word >> 30 == 2 and ((word >> 19) & 0x3f) == 0x38:
            by_source[source].append(int(xref['to'], 16))
    result_rows = []
    source_membership_counts = Counter()
    target_membership_counts = Counter()
    edge_count = 0
    unique_targets = set()
    targets_per_source_counts = Counter()
    for source, targets in sorted(by_source.items()):
        source_item = raw_item(binary, units[source], text_start, text_offset)
        word = int.from_bytes(bytes.fromhex(source_item['original_bytes']), 'big')
        source_membership_counts[membership(source, starts, ranges)] += 1
        predecessors = []
        for address in (source - 12, source - 8, source - 4):
            unit = units.get(address)
            predecessors.append(None if unit is None else raw_item(binary, unit, text_start, text_offset))
        target_rows = []
        for target in sorted(set(targets)):
            target_unit = units.get(target)
            assert target_unit is not None and target_unit['kind'] == 'code'
            target_rows.append(raw_item(binary, target_unit, text_start, text_offset))
            target_membership_counts[membership(target, starts, ranges)] += 1
            unique_targets.add(target)
        assert len(targets) == len(target_rows)
        targets_per_source_counts[str(len(target_rows))] += 1
        edge_count += len(target_rows)
        result_rows.append({
            'source_item': source_item,
            'source_candidate_membership': membership(source, starts, ranges),
            'raw_fields': {'rd': word & 0x1f, 'rs1': (word >> 14) & 0x1f,
                           'i_bit': (word >> 13) & 1},
            'three_preceding_text_items': predecessors,
            'type19_xref_target_code_items': target_rows,
        })
    assert len(result_rows) == 105
    assert edge_count == 690 and len(unique_targets) == 681
    output = {
        'schema': 1,
        'architecture': 'sparc',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'op3_38_type19_xref_source_count': len(result_rows),
        'op3_38_type19_xref_edge_count': edge_count,
        'unique_type19_xref_target_count': len(unique_targets),
        'source_candidate_membership_counts': dict(sorted(source_membership_counts.items())),
        'target_candidate_membership_counts_per_xref_edge': dict(sorted(target_membership_counts.items())),
        'target_count_per_source_counts': dict(sorted(targets_per_source_counts.items(), key=lambda item: int(item[0]))),
        'all_source_and_xref_target_items_match_original_big_endian_bytes': True,
        'interpretation_limit': ('this preserves IDA type-19 xref target sets with raw source/target windows; it '
                                 'does not calculate a target from the op3=0x38 instruction, establish register '
                                 'values, runtime targets, dispatch semantics, execution, reachability, function '
                                 'boundaries, calling convention, ABI, or behavior'),
        'rows': result_rows,
    }
    (REPORT / 'sparc-op3-38-type19-xref-census-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'source_count': len(result_rows), 'edge_count': edge_count,
                      'unique_target_count': len(unique_targets), 'all_checks_passed': True}))


if __name__ == '__main__':
    main()
