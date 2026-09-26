"""Cross-check every direct CALL in the SPARC function-candidate source gap."""
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
GAP_START = 0xF0003AA4
GAP_END = 0xF0004E70


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def signed_disp30(value):
    return value - (1 << 30) if value & (1 << 29) else value


def main():
    binary = (ROOT / '03_original/sparc/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/sparc/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_offset = int(text['file_offset'])
    units = read_tsv(ROOT / '05_ida/exports/sparc/text-units.tsv')
    units_by_address = {int(unit['address'], 16): unit for unit in units}
    unit_index = {int(unit['address'], 16): index for index, unit in enumerate(units)}
    xrefs = read_tsv(ROOT / '05_ida/exports/sparc/xrefs.tsv')
    edges = read_tsv(ROOT / '05_ida/exports/sparc/direct-call-edges.tsv')
    candidates = json.loads((ROOT / '05_ida/exports/sparc/function-asm-index.json').read_text())
    candidate_starts = {int(candidate['start'], 16) for candidate in candidates}
    gap_edges = [edge for edge in edges if GAP_START <= int(edge['source'], 16) < GAP_END]
    rows = []
    target_names = Counter()
    delay_slot_kind_counts = Counter()
    delay_slot_relation_counts = Counter()
    post_delay_kind_counts = Counter()
    post_delay_relation_counts = Counter()
    for edge in gap_edges:
        source = int(edge['source'], 16)
        target = int(edge['target'], 16)
        source_index = unit_index[source]
        source_window = units[source_index - 1:source_index + 3]
        assert len(source_window) == 4
        assert int(source_window[1]['address'], 16) == source
        assert int(source_window[2]['address'], 16) == source + 4
        assert int(source_window[3]['address'], 16) == source + 8
        assert all(unit['kind'] == 'code' for unit in source_window)
        checked_window = []
        for unit in source_window:
            address = int(unit['address'], 16)
            position = text_offset + address - text_start
            original = binary[position:position + int(unit['length'])]
            assert original.hex() == unit['bytes']
            checked_window.append({
                'address': unit['address'],
                'original_bytes': original.hex(),
                'ida_disassembly': unit['disassembly'],
            })
        source_raw = bytes.fromhex(source_window[1]['bytes'])
        assert source_raw.hex() == edge['instruction_bytes']
        word = int.from_bytes(source_raw, 'big')
        assert word >> 30 == 1
        displacement = signed_disp30(word & 0x3fffffff)
        computed_target = (source + (displacement << 2)) & 0xffffffff
        assert computed_target == target
        matching_xrefs = [xref for xref in xrefs if int(xref['from'], 16) == source
                          and int(xref['to'], 16) == target and xref['type'] == '17'
                          and xref['iscode'] == '1']
        assert len(matching_xrefs) == 1
        target_unit = units_by_address[target]
        assert target_unit['kind'] == 'code'
        target_position = text_offset + target - text_start
        target_raw = binary[target_position:target_position + int(target_unit['length'])]
        assert target_raw.hex() == target_unit['bytes']
        assert target in candidate_starts
        target_names[edge['target_raw_symbols'] or '<no_raw_symbol>'] += 1
        delay_slot = checked_window[2]
        post_delay = checked_window[3]
        delay_relation = ('inside_gap' if GAP_START <= source + 4 < GAP_END else 'outside_gap')
        post_relation = ('inside_gap' if GAP_START <= source + 8 < GAP_END else 'outside_gap')
        delay_slot_kind_counts[source_window[2]['kind']] += 1
        delay_slot_relation_counts[delay_relation] += 1
        post_delay_kind_counts[source_window[3]['kind']] += 1
        post_delay_relation_counts[post_relation] += 1
        rows.append({
            'source': edge['source'],
            'target': edge['target'],
            'signed_disp30': displacement,
            'instruction_bytes': edge['instruction_bytes'],
            'target_raw_symbols': edge['target_raw_symbols'],
            'source_window': checked_window,
            'delay_slot_item': {**delay_slot, 'gap_relation': delay_relation},
            'post_delay_item': {**post_delay, 'gap_relation': post_relation},
            'target_entry': {
                'address': target_unit['address'],
                'original_bytes': target_raw.hex(),
                'ida_disassembly': target_unit['disassembly'],
                'is_ida_candidate_start': True,
            },
            'xref': matching_xrefs[0],
        })
    assert len(rows) == 28
    output = {
        'schema': 1,
        'architecture': 'sparc',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'gap': {'start': hex(GAP_START), 'end_exclusive': hex(GAP_END)},
        'gap_direct_call_count': len(rows),
        'target_raw_symbol_edge_counts': dict(target_names),
        'delay_slot_item_kind_counts': dict(delay_slot_kind_counts),
        'delay_slot_gap_relation_counts': dict(delay_slot_relation_counts),
        'post_delay_item_kind_counts': dict(post_delay_kind_counts),
        'post_delay_gap_relation_counts': dict(post_delay_relation_counts),
        'all_source_windows_match_original_big_endian_bytes': True,
        'all_disp30_targets_match_type17_xrefs': True,
        'all_targets_are_original_code_items_and_ida_candidate_starts': True,
        'rows': rows,
        'interpretation_limit': ('static CALL windows, direct targets, and candidate-start membership do not '
                                'establish delay-slot execution, call return, gap ownership, reachability, ABI, or behavior'),
    }
    (REPORT / 'sparc-gap-direct-call-window-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'gap_direct_call_count': len(rows), 'all_checks_passed': True}))


if __name__ == '__main__':
    main()
