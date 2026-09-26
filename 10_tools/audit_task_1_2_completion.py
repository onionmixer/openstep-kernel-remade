"""Cross-check the two planned prerequisite tasks for x86, m68k, and SPARC."""
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
MULTIARCH_REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
FULL_REPORT = ROOT / '09_validation/reports/full-analysis'
X86_SHA256 = '33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890'


def sha256(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    input_closure = json.loads((MULTIARCH_REPORT / 'multiarch-input-acquisition-inventory-closure.json').read_text())
    analysis_closure = json.loads((MULTIARCH_REPORT / 'multiarch-analysis-prerequisite-closure.json').read_text())
    x86_audit = json.loads((FULL_REPORT / 'audit.json').read_text())
    x86_manifest = json.loads((ROOT / '04_ghidra/exports/x86/full-pass5/manifest.json').read_text())
    x86_sha = sha256(ROOT / '03_original/x86/binaries/mach_kernel')
    assert x86_sha == X86_SHA256 == x86_audit['binary_sha256'] == x86_manifest['binary_sha256']
    assert x86_manifest['ghidra_version'] and x86_manifest['language'] and x86_manifest['compiler_spec']
    assert x86_audit['byte_inventory_complete']
    assert x86_audit['unrepresented_bytes'] == 0
    assert not x86_audit['nonpadding_unclassified_ranges']
    assert not x86_audit['orphan_instruction_ranges']
    assert input_closure['prerequisite_closure'] == {
        'os42j_input_acquisition_hash_and_fat_slice_validation': True,
        'big_endian_raw_macho_inventory_validation': True,
    }
    assert analysis_closure['prerequisite_closure'] == {
        'hash_matched_big_endian_analysis_configuration': True,
        'all_non_pagezero_load_range_item_mapping': True,
    }
    multiarch = {}
    for architecture in ('m68k', 'sparc'):
        source = input_closure['targets'][architecture]
        analysis = analysis_closure['targets'][architecture]
        assert source['fat_slice_bytes_equal_preserved_thin_binary']
        assert source['raw_inventory_sha256_and_big_endian_fields_match']
        assert source['raw_inventory_file_bounds_valid']
        assert all(analysis['analysis_input_configuration'].values())
        assert all(analysis['all_load_range_mapping'].values())
        multiarch[architecture] = {
            'input_acquisition_and_raw_inventory_closed': True,
            'hash_matched_big_endian_analysis_configuration_closed': True,
            'all_non_pagezero_load_range_item_mapping_closed': True,
            'original_sha256_recomputed_with_python': analysis['original_sha256_recomputed_with_python'],
            'load_item_count': analysis['all_load_range_mapping']['item_count'],
        }
    output = {
        'schema': 1,
        'task_1_hash_matched_analysis_configuration': {
            'x86': {
                'original_sha256_recomputed_with_python': x86_sha,
                'ghidra_manifest_sha256_matches_original': True,
                'ghidra_version_language_compiler_spec_recorded': True,
            },
            'm68k_and_sparc': multiarch,
            'complete_for_current_analysis_scope': True,
        },
        'task_2_listing_classification_and_original_mapping': {
            'x86': {
                'byte_inventory_complete': True,
                'unrepresented_byte_count': 0,
                'nonpadding_unclassified_range_count': 0,
                'orphan_instruction_range_count': 0,
            },
            'm68k_and_sparc': multiarch,
            'complete_for_current_analysis_scope': True,
        },
        'interpretation_limit': (
            'This completion audit covers only the two prerequisite tasks: input-matched analysis configuration '
            'and listing/classification/original-byte mapping. It does not complete semantic analysis or establish '
            'code/data truth, relocation cause, execution, function boundaries, ABI, types, or behavior.'),
    }
    (MULTIARCH_REPORT / 'task-1-2-completion-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({'task_1_complete': output['task_1_hash_matched_analysis_configuration']['complete_for_current_analysis_scope'],
                      'task_2_complete': output['task_2_listing_classification_and_original_mapping']['complete_for_current_analysis_scope']},
                     sort_keys=True))


if __name__ == '__main__':
    main()
