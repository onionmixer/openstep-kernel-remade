"""Verify bounded original-text layout for every candidate gap with a direct transfer."""
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


def main():
    topology = json.loads((REPORT / 'candidate-gap-all-direct-transfer-topology-audit.json').read_text())
    targets = {}
    for architecture, topology_row in topology['targets'].items():
        binary = (ROOT / f'03_original/{architecture}/binaries/mach_kernel').read_bytes()
        inventory = json.loads((ROOT / f'03_original/{architecture}/inventory/macho.json').read_text())
        text = next(section for section in inventory['sections']
                    if section['segment'] == '__TEXT' and section['name'] == '__text')
        text_start = int(text['address'], 16)
        text_end = text_start + int(text['size'])
        text_offset = int(text['file_offset'])
        units = tsv_rows(ROOT / f'05_ida/exports/{architecture}/text-units.tsv')
        parsed_units = sorted(({
            'address': int(row['address'], 16),
            'length': int(row['length']), 'kind': row['kind'], 'bytes': row['bytes'],
            'disassembly': row['disassembly'],
        } for row in units), key=lambda row: row['address'])
        gaps = [(int(key.split('..')[0], 16), int(key.split('..')[1], 16), count)
                for key, count in topology_row['source_gap_all_direct_transfer_counts'].items()]
        rows = []
        total_gap_bytes = 0
        kind_totals = Counter()
        for start, end, transfer_count in sorted(gaps):
            assert text_start <= start < end <= text_end
            selected = [unit for unit in parsed_units if start <= unit['address'] < end]
            assert selected
            cursor = start
            item_kind_counts = Counter()
            item_bytes = bytearray()
            for unit in selected:
                assert unit['address'] == cursor
                assert unit['address'] + unit['length'] <= end
                file_offset = text_offset + unit['address'] - text_start
                raw = binary[file_offset:file_offset + unit['length']]
                assert raw.hex() == unit['bytes']
                item_bytes.extend(raw)
                cursor += unit['length']
                item_kind_counts[unit['kind']] += 1
            assert cursor == end
            span = binary[text_offset + start - text_start:text_offset + end - text_start]
            assert bytes(item_bytes) == span
            total_gap_bytes += end - start
            kind_totals.update(item_kind_counts)
            rows.append({
                'gap': {'start': hex(start), 'end': hex(end), 'byte_length': end - start},
                'direct_transfer_source_count': transfer_count,
                'text_item_count': len(selected),
                'text_item_kind_counts': dict(sorted(item_kind_counts.items())),
                'original_span_sha256_recomputed_with_python': hashlib.sha256(span).hexdigest(),
            })
        assert len(rows) == topology_row['source_gap_count']
        targets[architecture] = {
            'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
            'direct_transfer_gap_count': len(rows),
            'total_bounded_gap_byte_length': total_gap_bytes,
            'total_text_item_kind_counts': dict(sorted(kind_totals.items())),
            'all_gap_items_are_contiguous_and_match_original_bytes': True,
            'rows': rows,
        }
    output = {
        'schema': 1,
        'topology_input_sha256': hashlib.sha256(
            (REPORT / 'candidate-gap-all-direct-transfer-topology-audit.json').read_bytes()).hexdigest(),
        'targets': targets,
        'interpretation_limit': ('bounded gap layout and current item classifications do not establish gap code '
                                 'ownership, function boundaries, execution, control-flow reachability, calling '
                                 'convention, ABI, or behavior'),
    }
    (REPORT / 'candidate-gap-bounded-text-layout-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({architecture: target['direct_transfer_gap_count']
                      for architecture, target in targets.items()}, sort_keys=True))


if __name__ == '__main__':
    main()
