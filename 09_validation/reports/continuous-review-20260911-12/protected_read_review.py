"""Remaining protected-data read placement, independently checked original path.

The comparison snapshot is explicitly the printed-C ordering model, not a
compiled execution of the whole decompiled function or reconstructed source.
"""
import importlib.util
import json
import hashlib
from run_experiment import HERE, ROOT, R

spec = importlib.util.spec_from_file_location('dispatch', HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py')
D = importlib.util.module_from_spec(spec)
spec.loader.exec_module(D)
X, U = D.X, D.U
LOCK, QUEUE, MAXIMUM, MAPPED = 0x1f64cc, 0x1f64d0, 0x1def60, 0x1def64


def case(before, after):
    uc, trace, _ = D.fixture(0x603, 'unlocked', 'hit')
    D.put(uc, LOCK, 0)
    D.put(uc, QUEUE, before)
    D.put(uc, MAXIMUM, 0)
    D.put(uc, MAPPED, 1)
    reads, events = [], []
    # This models only the explicit queue snapshot placed before lock in C.
    printed_c_early_snapshot = D.words(uc, QUEUE, 1)[0]

    def code(engine, pc, size, unused):
        if pc == 0x15ec19:
            D.put(engine, QUEUE, after)
            events.append({'pc': hex(pc), 'kind': 'synthetic_protected_data_update_before_acquisition', 'value': after})

    def read(engine, access, address, size, value, unused):
        if address == QUEUE:
            reads.append({'pc': hex(engine.reg_read(X.UC_X86_REG_EIP)), 'value': D.words(engine, QUEUE, 1)[0]})

    uc.hook_add(U.UC_HOOK_CODE, code)
    uc.hook_add(U.UC_HOOK_MEM_READ, read)
    D.run_to(uc, 0x15ec08, 0x15ec5a)
    assert uc.reg_read(X.UC_X86_REG_EBX) == after
    assert reads == [{'pc': '0x15ec54', 'value': after}]
    assert D.words(uc, LOCK, 1)[0] == 1
    assert trace.index(0x15ec19) < trace.index(0x15ec54)
    original = R.function_instructions(R.NAMES['_mfs_cache_trim'])
    assert all(bytes(uc.mem_read(pc, original[pc].size)) == original[pc].bytes for pc in trace)
    return {'queue_before': before, 'queue_after': after, 'original_ebx_snapshot': after,
            'printed_c_ordering_model_snapshot': printed_c_early_snapshot,
            'snapshots_differ': before != after, 'queue_reads': reads, 'events': events,
            'trace': [hex(a) for a in trace]}


def main():
    funcs = json.loads((HERE / 'exports/volatile_only/functions.json').read_text())
    function = next(f for f in funcs if f['entry'] == '0015ec00')
    copies = [{'block': b['index'], 'operation': o} for b in function['high_blocks'] for o in b['operations']
              if o['opcode'] == 'COPY' and o['address'] == '0015ec08' and o['inputs'] == ['(ram, 0x1f64d0, 4)']]
    assert len(copies) == 1
    text = (HERE / 'exports/volatile_only/0015ec00.c').read_text()
    assert text.index('puVar4 = _vm_info_queue;') < text.index('iVar6 = _vm_info_lock_data;') < text.index('LOCK();')
    original = R.function_instructions(R.NAMES['_mfs_cache_trim'])
    assert original[0x15ec54].mnemonic == 'mov' and original[0x15ec54].operands[1].mem.disp == QUEUE
    pointers = (D.DATA + 0x900, D.DATA + 0xa00, D.DATA + 0xb00)
    rows = [case(before, after) for before in pointers for after in pointers]
    result = {'summary': {'cases': len(rows), 'snapshot_mismatches_under_changed_queue': sum(r['snapshots_differ'] for r in rows),
                           'failures': 0, 'limitation': 'Lock-only volatility restores lock accesses, not all protected-memory ordering.'},
              'high_pcode_early_snapshot': copies, 'raw_queue_read': {'address': '0015ec54', 'bytes': original[0x15ec54].bytes.hex(),
                                                                  'instruction': original[0x15ec54].op_str},
              'cases': rows,
              'scope': 'Original acquisition prefix only. External queue change is a hook, not a real concurrent updater; C snapshot is an ordering model only.'}
    (HERE / 'protected-read-review.json').write_text(json.dumps(result, indent=2) + '\n')
    paths = [ROOT / '03_original/x86/binaries/mach_kernel',
             HERE.parent / 'cautious-followup-20260911/review.py',
             HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py']
    (HERE / 'input-hashes.json').write_text(json.dumps([{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size,
                                                       'sha256': hashlib.sha256(p.read_bytes()).hexdigest()} for p in paths], indent=2) + '\n')
    print(json.dumps(result['summary'], indent=2))


if __name__ == '__main__':
    main()
