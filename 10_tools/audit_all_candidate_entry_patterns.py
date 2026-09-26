"""Census raw entry patterns for every m68k and SPARC function candidate start."""
import csv
import hashlib
import json
from collections import Counter
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


def main():
    output_targets = {}
    for architecture in ['m68k', 'sparc']:
        binary = (ROOT / f'03_original/{architecture}/binaries/mach_kernel').read_bytes()
        inventory = json.loads((ROOT / f'03_original/{architecture}/inventory/macho.json').read_text())
        text = next(section for section in inventory['sections']
                    if section['segment'] == '__TEXT' and section['name'] == '__text')
        text_start = int(text['address'], 16)
        text_offset = int(text['file_offset'])
        candidates = rows(ROOT / f'05_ida/exports/{architecture}/function-candidate-lexical-exits.tsv')
        units = {int(row['address'], 16): row
                 for row in rows(ROOT / f'05_ida/exports/{architecture}/text-units.tsv')}
        direct_targets = {int(row['target'], 16)
                          for row in rows(ROOT / f'05_ida/exports/{architecture}/direct-call-edges.tsv')}
        item_kind_counts = Counter()
        mnemonic_counts = Counter()
        direct_target_counts = Counter()
        raw_pattern_counts = Counter()
        field_counts = Counter()
        result_rows = []
        for candidate in candidates:
            start = int(candidate['start'], 16)
            unit = units.get(start)
            assert unit is not None
            entry = raw_item(binary, unit, text_start, text_offset)
            item_kind_counts[entry['kind']] += 1
            mnemonic = entry['ida_disassembly'].split(None, 1)[0]
            mnemonic_counts[mnemonic] += 1
            direct_state = 'direct_call_target' if start in direct_targets else 'not_direct_call_target'
            direct_target_counts[direct_state] += 1
            raw = bytes.fromhex(entry['original_bytes'])
            details = None
            if architecture == 'm68k':
                word = int.from_bytes(raw[:2], 'big')
                if word == 0x4e56:
                    assert len(raw) >= 4
                    immediate = int.from_bytes(raw[2:4], 'big', signed=True)
                    pattern = 'link_word_4e56'
                    details = {'signed_big_endian_16bit_immediate': immediate}
                    field_counts[str(immediate)] += 1
                else:
                    pattern = 'other_entry_word'
            else:
                assert len(raw) >= 4
                word = int.from_bytes(raw[:4], 'big')
                if word >> 30 == 2 and ((word >> 19) & 0x3f) == 0x3c:
                    pattern = 'save_op2_op3_3c'
                    details = {'rs1': (word >> 14) & 0x1f, 'rd': word & 0x1f,
                               'i_bit': (word >> 13) & 1,
                               'signed_low_13_field': (word & 0x1fff) - (1 << 13)
                               if word & (1 << 12) else word & 0x1fff}
                    field_counts[json.dumps(details, sort_keys=True)] += 1
                else:
                    pattern = 'other_entry_word'
            raw_pattern_counts[pattern] += 1
            result_rows.append({'candidate': {'name': candidate['name'], 'start': candidate['start'],
                                              'end': candidate['end'],
                                              'lexical_exit_count': candidate['lexical_exit_count']},
                                'entry_item': entry,
                                'direct_call_target_membership': direct_state,
                                'raw_entry_pattern': pattern,
                                'raw_pattern_details': details})
        expected = {'m68k': 3214, 'sparc': 5075}[architecture]
        assert len(result_rows) == expected
        output_targets[architecture] = {
            'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
            'function_candidate_count': len(result_rows),
            'entry_item_kind_counts': dict(sorted(item_kind_counts.items())),
            'entry_ida_mnemonic_counts_as_tool_observations': dict(sorted(mnemonic_counts.items())),
            'direct_call_target_membership_counts': dict(sorted(direct_target_counts.items())),
            'raw_entry_pattern_counts': dict(sorted(raw_pattern_counts.items())),
            'raw_pattern_field_counts': dict(sorted(field_counts.items())),
            'all_candidate_start_items_match_original_bytes': True,
            'rows': result_rows,
        }
    output = {
        'schema': 1,
        'targets': output_targets,
        'interpretation_limit': ('raw candidate entry patterns, operand fields, and direct-call target overlap do '
                                 'not establish a stack frame, function boundary, calling convention, ABI, arguments, '
                                 'return values, execution, or behavior'),
    }
    (REPORT / 'all-candidate-entry-patterns-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({architecture: target['function_candidate_count']
                      for architecture, target in output_targets.items()}, sort_keys=True))


if __name__ == '__main__':
    main()
