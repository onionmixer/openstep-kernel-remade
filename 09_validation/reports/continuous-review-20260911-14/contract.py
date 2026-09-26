"""Emit a tested analysis sidecar without changing Ghidra or kernel sources."""
import json
from normalized_execution import HERE, FLAG_BITS


def main():
    scan = json.loads((HERE / 'scan.json').read_text())
    execution = json.loads((HERE / 'normalized-execution.json').read_text())
    tested = {row['site'] for row in execution['sites']}
    assert tested == {row['site'] for row in scan['sites']}
    rows = []
    for site in scan['sites']:
        bits = site['width'] * 8
        rows.append({'site': site['site'], 'owner': site['owner'], 'bytes': site['bytes'],
                     'width_bits': bits, 'mask': (1 << bits) - 1,
                     'delta': 1 if site['mnemonic'] == 'inc' else -1,
                     'operand_kind': site['kind'],
                     'sample_operand_once': True, 'result_uses_sampled_old_only': True,
                     'flags_use_old_and_new_temporaries_only': True,
                     'updated_flags': ['PF', 'AF', 'ZF', 'SF', 'OF'], 'preserved_flag': 'CF',
                     'effect_sequence': ['read_memory_once', 'write_memory_once'] if site['kind'] == 'memory' else ['read_register', 'write_same_width_register'],
                     'explicit_lock_semantics_required': site['lock_prefix'],
                     'concurrent_atomicity_verified': False, 'fault_restart_verified': False})
    result = {'status': 'tested_analysis_contract_not_integrated_into_decompiler',
              'binary_sha256': scan['summary']['binary_sha256'], 'flag_bits': FLAG_BITS,
              'source_of_semantics': 'normalized_execution.normalized, compared with each original instruction under fixture states',
              'site_count': len(rows), 'sites': rows,
              'not_a_claim': ['No patch of original instructions, Ghidra language, canonical database, or kernel source.',
                             'No assertion that all other RMW operations or all architectural states are covered.']}
    (HERE / 'normalized-contract.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'sites': len(rows), 'status': result['status']}))


if __name__ == '__main__':
    main()
