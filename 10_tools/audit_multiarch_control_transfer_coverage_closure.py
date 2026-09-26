"""Close raw opcode-pattern coverage against the multiarch control-transfer audits."""
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'


def tsv_rows(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def report(name):
    path = REPORT / name
    raw = path.read_bytes()
    return json.loads(raw), hashlib.sha256(raw).hexdigest()


def main():
    outputs = {}
    m68_units = tsv_rows(ROOT / '05_ida/exports/m68k/text-units.tsv')
    m68_counts = {'bsr': 0, 'bcc_non_bsr': 0, 'dbcc': 0, 'jsr': 0, 'jmp': 0}
    for unit in m68_units:
        if unit['kind'] != 'code':
            continue
        word = int.from_bytes(bytes.fromhex(unit['bytes'])[:2], 'big')
        if word & 0xff00 == 0x6100:
            m68_counts['bsr'] += 1
        if word & 0xf000 == 0x6000 and word & 0xff00 != 0x6100:
            m68_counts['bcc_non_bsr'] += 1
        if word & 0xf0f8 == 0x50c8:
            m68_counts['dbcc'] += 1
        if word & 0xffc0 == 0x4e80:
            m68_counts['jsr'] += 1
        if word & 0xffc0 == 0x4ec0:
            m68_counts['jmp'] += 1
    direct, direct_hash = report('direct-call-edge-tsv-validation.json')
    type19, type19_hash = report('m68k-all-type19-direct-transfers-audit.json')
    jsr, jsr_hash = report('m68k-jsr-opcode-pattern-census-audit.json')
    jmp, jmp_hash = report('m68k-jmp-opcode-pattern-census-audit.json')
    m68_forms = type19['encoding_form_counts']
    assert m68_counts['bsr'] == direct['targets']['m68k']['edge_kind_counts']['bsr_long_relative']
    assert m68_counts['bcc_non_bsr'] == (m68_forms['bcc_byte_displacement'] +
                                         m68_forms['bcc_word_displacement'] +
                                         m68_forms['bcc_long_displacement'])
    assert m68_counts['dbcc'] == m68_forms['dbcc_word_displacement']
    assert m68_counts['jsr'] == jsr['jsr_opcode_pattern_count']
    assert m68_counts['jmp'] == jmp['jmp_opcode_pattern_count']
    outputs['m68k'] = {
        'original_sha256_recomputed_with_python': hashlib.sha256(
            (ROOT / '03_original/m68k/binaries/mach_kernel').read_bytes()).hexdigest(),
        'raw_opcode_pattern_counts': m68_counts,
        'fpu_branch_type19_xref_source_count': m68_forms['fpu_branch_long_displacement'],
        'coverage_input_report_sha256': {
            'direct_call_edge_tsv_validation': direct_hash,
            'all_type19_direct_transfers': type19_hash,
            'jsr_opcode_pattern_census': jsr_hash,
            'jmp_opcode_pattern_census': jmp_hash,
        },
        'all_selected_raw_opcode_counts_match_control_transfer_audits': True,
    }
    sparc_units = tsv_rows(ROOT / '05_ida/exports/sparc/text-units.tsv')
    sparc_counts = {'call_op1': 0, 'standard_branch_op0_op2_2': 0, 'op2_op3_38': 0}
    for unit in sparc_units:
        if unit['kind'] != 'code' or int(unit['length']) != 4:
            continue
        word = int.from_bytes(bytes.fromhex(unit['bytes']), 'big')
        if word >> 30 == 1:
            sparc_counts['call_op1'] += 1
        if word >> 30 == 0 and ((word >> 22) & 0x7) == 2:
            sparc_counts['standard_branch_op0_op2_2'] += 1
        if word >> 30 == 2 and ((word >> 19) & 0x3f) == 0x38:
            sparc_counts['op2_op3_38'] += 1
    standard, standard_hash = report('sparc-all-standard-type19-branches-audit.json')
    op38, op38_hash = report('sparc-op2-op3-38-census-audit.json')
    op38_xref, op38_xref_hash = report('sparc-op3-38-type19-xref-census-audit.json')
    assert sparc_counts['call_op1'] == direct['targets']['sparc']['edge_kind_counts']['call_relative']
    assert sparc_counts['standard_branch_op0_op2_2'] == standard['standard_op0_op2_2_type19_branch_count']
    assert sparc_counts['op2_op3_38'] == op38['op2_op3_38_code_item_count']
    assert op38_xref['op3_38_type19_xref_edge_count'] == 690
    outputs['sparc'] = {
        'original_sha256_recomputed_with_python': hashlib.sha256(
            (ROOT / '03_original/sparc/binaries/mach_kernel').read_bytes()).hexdigest(),
        'raw_opcode_pattern_counts': sparc_counts,
        'op3_38_type19_xref_edge_count': op38_xref['op3_38_type19_xref_edge_count'],
        'coverage_input_report_sha256': {
            'direct_call_edge_tsv_validation': direct_hash,
            'all_standard_type19_branches': standard_hash,
            'op2_op3_38_census': op38_hash,
            'op3_38_type19_xref_census': op38_xref_hash,
        },
        'all_selected_raw_opcode_counts_match_control_transfer_audits': True,
    }
    output = {
        'schema': 1,
        'targets': outputs,
        'interpretation_limit': ('coverage closure connects raw opcode-pattern counts with existing static audits; '
                                 'it does not establish instruction semantics, register values, runtime targets, '
                                 'execution, path reachability, function boundaries, calling convention, ABI, or behavior'),
    }
    (REPORT / 'multiarch-control-transfer-coverage-closure-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({architecture: row['raw_opcode_pattern_counts']
                      for architecture, row in outputs.items()}, sort_keys=True))


if __name__ == '__main__':
    main()
