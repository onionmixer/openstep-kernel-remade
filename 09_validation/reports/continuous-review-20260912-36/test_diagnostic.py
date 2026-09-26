"""Reject corruption of diagnostic evidence, without changing any runtime state."""
import copy
import json
from pathlib import Path
import audit_diagnostic as A

HERE = Path(__file__).resolve().parent


def main():
    probe = json.loads((HERE / 'exception-probe.json').read_text())
    kernel = json.loads((HERE / 'latest-prefault.json').read_text())
    A.probe_check(probe)
    A.kernel_check(kernel)
    controls = []
    def reject(name, sample, mutate, checker):
        row = copy.deepcopy(sample)
        mutate(row)
        try:
            checker(row)
        except AssertionError:
            controls.append({'name': name, 'rejected': True})
        else:
            raise AssertionError('accepted altered diagnostic: ' + name)
    reject('change_second_vector_to_PF', probe, lambda r: r['cases'][0]['runs'][1]['events'][0].__setitem__('vector', 14), A.probe_check)
    reject('fake_RAM_identity', probe, lambda r: r['cases'][0]['runs'][0].__setitem__('after_ram_sha256', '0' * 64), A.probe_check)
    reject('missing_NOP_execution', probe, lambda r: r['cases'][1]['runs'][1].__setitem__('heads', []), A.probe_check)
    reject('change_restore_public_state', probe, lambda r: r['cases'][3]['restore_public_cpu_after'].__setitem__('eflags', 0), A.probe_check)
    reject('claim_hidden_context_equal', probe, lambda r: r['cases'][3].__setitem__('opaque_context_equal_claimed', True), A.probe_check)
    reject('misclaim_kernel_reuse', probe, lambda r: r.__setitem__('kernel_reuse_completed', True), A.probe_check)
    reject('omit_public_field', probe, lambda r: r['public_cpu_fields'].remove('gdtr'), A.probe_check)
    reject('kernel_vector8_relabelled14', kernel, lambda r: r['fault']['interrupts'][0].__setitem__('vector', 14), A.kernel_check)
    reject('wrong_GC_prefix_hash', kernel, lambda r: r.__setitem__('prefix34_canonical_sha256', '0' * 64), A.kernel_check)
    reject('wrong_caller_source', kernel, lambda r: r['caller_input']['words'].__setitem__(1, A.F.VA + 0x100), A.kernel_check)
    reject('unreported_DATA_state_edit', kernel, lambda r: A.G.R.patch(r['before'], 'frame', 0, 1, 1), A.kernel_check)
    reject('missing_prefault_stack_store', kernel, lambda r: r['writes'].pop(0), A.kernel_check)
    def fake_commit(r):
        r['writes'].append(dict(pc=int(r['fault']['trace'][-1], 16), trace_index=len(r['fault']['trace']) - 1,
                               address=A.F.DATA + r['params'][2], width=1, value=245))
    reject('failed_store_claimed_committed', kernel, fake_commit, A.kernel_check)
    out = {'all_rejected': True, 'controls': controls, 'scope': 'diagnostic integrity only; resource reuse remains unverified'}
    (HERE / 'diagnostic-negative-controls.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps({'diagnostic_corruptions_rejected': len(controls)}))


if __name__ == '__main__':
    main()
