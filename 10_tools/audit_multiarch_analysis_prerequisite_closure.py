"""Close the m68k/SPARC input-configuration and all-load-range mapping prerequisites."""
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
EXPECTED = {
    'm68k': {'sha256': 'dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75',
             'processor': '68K', 'cpu_type': 6},
    'sparc': {'sha256': '287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1',
              'processor': 'sparcb', 'cpu_type': 14},
}


def main():
    inventory_validation = json.loads((REPORT / 'raw-inventory-validation.json').read_text())['targets']
    ida_initial = json.loads((REPORT / 'ida-initial-validation.json').read_text())['targets']
    load_validation = json.loads((REPORT / 'all-load-units-validation.json').read_text())['targets']
    targets = {}
    for architecture, expected in EXPECTED.items():
        raw_sha = hashlib.sha256(
            (ROOT / '03_original' / architecture / 'binaries/mach_kernel').read_bytes()).hexdigest()
        inventory = inventory_validation[architecture]
        initial = ida_initial[architecture]
        load = load_validation[architecture]
        assert raw_sha == expected['sha256']
        assert inventory['sha256_match'] and inventory['big_endian'] == 'big'
        assert initial['input_sha256_match'] and initial['processor'] == expected['processor']
        assert initial['big_endian'] and initial['bits'] == 32
        assert load['original_sha256_recomputed_with_python'] == raw_sha
        assert load['all_expected_non_pagezero_load_ranges_exported']
        assert load['all_file_backed_original_bytes_match_raw_binary']
        assert load['all_ranges_have_continuous_address_coverage']
        assert load['all_ida_value_lengths_match_item_lengths']
        assert load['summary_matches_tsv_recomputation']
        targets[architecture] = {
            'original_sha256_recomputed_with_python': raw_sha,
            'analysis_input_configuration': {
                'raw_inventory_sha256_match': inventory['sha256_match'],
                'raw_inventory_byte_order': inventory['big_endian'],
                'ida_input_sha256_match': initial['input_sha256_match'],
                'ida_processor': initial['processor'], 'ida_big_endian': initial['big_endian'],
                'ida_bits': initial['bits'], 'ida_database_path_isolated_from_x86': initial['output_path_isolated_from_x86'],
            },
            'all_load_range_mapping': {
                'item_count': load['item_count'],
                'all_non_pagezero_ranges_exported': load['all_expected_non_pagezero_load_ranges_exported'],
                'file_backed_original_byte_mapping_verified': load['all_file_backed_original_bytes_match_raw_binary'],
                'range_address_coverage_continuous': load['all_ranges_have_continuous_address_coverage'],
                'all_ida_value_lengths_match_item_lengths': load['all_ida_value_lengths_match_item_lengths'],
                'summary_matches_tsv_recomputation': load['summary_matches_tsv_recomputation'],
            },
        }
    output = {
        'schema': 1, 'targets': targets,
        'prerequisite_closure': {
            'hash_matched_big_endian_analysis_configuration': True,
            'all_non_pagezero_load_range_item_mapping': True,
        },
        'interpretation_limit': (
            'This closes input/configuration and raw load-range mapping prerequisites only. IDA item kinds '
            'remain tool hypotheses, and this does not establish code/data truth, relocation cause, runtime '
            'memory, execution, control flow, function boundaries, ABI, types, or behavior.'),
    }
    (REPORT / 'multiarch-analysis-prerequisite-closure.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(output['prerequisite_closure'], sort_keys=True))


if __name__ == '__main__':
    main()
