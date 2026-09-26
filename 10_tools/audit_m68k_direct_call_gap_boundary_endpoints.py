"""Record raw boundary evidence for every m68k direct-call source gap."""
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'


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
    binary = (ROOT / '03_original/m68k/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/m68k/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_offset = int(text['file_offset'])
    gap_report = json.loads((REPORT / 'm68k-direct-call-outside-function-candidates.json').read_text())
    gaps = gap_report['gaps_containing_direct_call_sources']
    edges = read_tsv(ROOT / '05_ida/exports/m68k/direct-call-edges.tsv')
    edge_by_source = {int(edge['source'], 16): edge for edge in edges}
    xrefs = read_tsv(ROOT / '05_ida/exports/m68k/xrefs.tsv')
    units = read_tsv(ROOT / '05_ida/exports/m68k/text-units.tsv')
    units_by_address = {int(unit['address'], 16): unit for unit in units}
    unit_index = {int(unit['address'], 16): index for index, unit in enumerate(units)}
    candidates = json.loads((ROOT / '05_ida/exports/m68k/function-asm-index.json').read_text())
    candidate_starts = {int(candidate['start'], 16) for candidate in candidates}
    rows = []
    selected_sources = set()
    for gap in gaps:
        start = int(gap['gap_start'], 16)
        end = int(gap['gap_end_exclusive'], 16)
        source_addresses = [int(gap['first_direct_call_source'], 16),
                            int(gap['last_direct_call_source'], 16)]
        selected_sources.update(source_addresses)
        calls = []
        for source in dict.fromkeys(source_addresses):
            edge = edge_by_source[source]
            target = int(edge['target'], 16)
            index = unit_index[source]
            source_unit = units[index]
            assert source_unit['kind'] == 'code'
            source_evidence = raw_item(binary, source_unit, text_start, text_offset)
            raw = bytes.fromhex(source_evidence['original_bytes'])
            if edge['edge_kind'] == 'bsr_long_relative':
                assert int.from_bytes(raw[:2], 'big') == 0x61ff
                displacement = int.from_bytes(raw[2:6], 'big', signed=True)
                computed_target = (source + 2 + displacement) & 0xffffffff
            elif edge['edge_kind'] == 'jsr_absolute_long':
                assert int.from_bytes(raw[:2], 'big') == 0x4eb9
                displacement = None
                computed_target = int.from_bytes(raw[2:6], 'big')
            else:
                raise AssertionError(edge['edge_kind'])
            assert computed_target == target
            target_unit = units_by_address[target]
            assert target_unit['kind'] == 'code'
            matching_xrefs = [xref for xref in xrefs if int(xref['from'], 16) == source
                              and int(xref['to'], 16) == target and xref['type'] == '17'
                              and xref['iscode'] == '1']
            assert len(matching_xrefs) == 1
            next_unit = units[index + 1]
            calls.append({
                'source': edge['source'],
                'target': edge['target'],
                'edge_kind': edge['edge_kind'],
                'signed_displacement_for_bsr': displacement,
                'source_item': source_evidence,
                'next_text_item': raw_item(binary, next_unit, text_start, text_offset),
                'target_item': raw_item(binary, target_unit, text_start, text_offset),
                'target_is_ida_candidate_start': target in candidate_starts,
                'xref': matching_xrefs[0],
            })
        preceding = next((unit for unit in units if int(unit['address'], 16) + int(unit['length']) == start), None)
        first_gap_unit = units_by_address[start]
        first_following_candidate_unit = units_by_address[end]
        rows.append({
            'gap_start': gap['gap_start'],
            'gap_end_exclusive': gap['gap_end_exclusive'],
            'gap_size': gap['gap_size'],
            'direct_call_source_count': gap['direct_call_source_count'],
            'item_ending_at_gap_start': (raw_item(binary, preceding, text_start, text_offset)
                                         if preceding is not None else None),
            'first_gap_item': raw_item(binary, first_gap_unit, text_start, text_offset),
            'item_at_gap_end': raw_item(binary, first_following_candidate_unit, text_start, text_offset),
            'endpoint_calls': calls,
        })
    assert len(rows) == gap_report['gap_count_containing_direct_call_sources'] == 66
    assert sum(row['direct_call_source_count'] for row in rows) == 1127
    output = {
        'schema': 1,
        'architecture': 'm68k',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'gap_count': len(rows),
        'total_direct_call_sources_in_gaps': sum(row['direct_call_source_count'] for row in rows),
        'unique_endpoint_direct_call_source_count': len(selected_sources),
        'all_gap_boundary_items_match_original_big_endian_bytes': True,
        'all_endpoint_call_targets_match_original_encoding_and_type17_xref': True,
        'all_endpoint_call_targets_are_original_code_items': True,
        'rows': rows,
        'interpretation_limit': ('gap-boundary items and endpoint direct-call windows do not establish function '
                                'ownership, complete boundaries, call return, reachability, ABI, or behavior'),
    }
    (REPORT / 'm68k-direct-call-gap-boundary-endpoints-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'gap_count': len(rows),
                      'total_direct_call_sources_in_gaps': output['total_direct_call_sources_in_gaps'],
                      'unique_endpoint_direct_call_source_count': len(selected_sources),
                      'all_checks_passed': True}))


if __name__ == '__main__':
    main()
