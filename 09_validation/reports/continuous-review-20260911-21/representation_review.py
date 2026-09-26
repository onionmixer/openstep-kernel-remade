"""Audit boot side effects and original allocator return against saved decompilation."""
import itertools
import json
import re
from paging_review import HERE, ROOT, R, D, X, MASK


def main():
    previous = HERE.parent / 'continuous-review-20260911-18/exports/pcode.json'
    f = next(r for r in json.loads(previous.read_text()) if r['entry'] == '0018eee8')
    ops = [op for block in f['high_blocks'] for op in block['operations']]
    selected = ('0018f0ae', '0018f0b1', '0018f163', '0018f166', '0018f28f', '0018f292',
                '0018f2a3', '0018f31a', '0018f31d', '0018f323')
    rows = []
    for pc in selected:
        raw = next(r for r in f['raw_instructions'] if r['address'] == pc)
        high = [r for r in ops if r['address'] == pc]
        assert raw['operations']
        assert all(op['opcode'] == 'MULTIEQUAL' for op in high)
        rows.append({'site': pc, 'raw': raw, 'high_operations_at_site': high})
    # Check the entire function too, so address relocation alone cannot explain
    # absence of writes to these two explicit register varnodes.
    cpu_outputs = [op for op in ops if op.get('output') in ('(register, 0x320, 4)', '(register, 0x32c, 4)')]
    assert not cpu_outputs
    c_path = R.G / 'functions/0018eee8.c'
    c = c_path.read_text()
    normalized = re.sub(r'\A/\* Ghidra decompiler output, not reconstructed GCC 2\.7 source\..*?\*/\s*', '', c, flags=re.S).strip()
    assert normalized == (previous.parent / '0018eee8.c').read_text().strip()
    allocator = R.NAMES['_alloc_pages']
    alloc_c = (R.G / 'functions' / f'{allocator:08x}.c').read_text()
    assert 'void _alloc_pages(int param_1)' in alloc_c
    callers, heads = [], set()
    for entry in sorted(R.FMAP):
        seq = list(R.function_instructions(entry).values())
        for index, ins in enumerate(seq):
            heads.add(ins.address)
            if ins.mnemonic == 'call' and ins.operands[0].type == R.X86_OP_IMM and ins.operands[0].imm == allocator:
                callers.append({'owner': f'{entry:08x}', 'name': R.FMAP[entry]['name'], 'site': hex(ins.address),
                                'following_window': [{'site': hex(i.address), 'instruction': i.mnemonic + ' ' + i.op_str}
                                                     for i in seq[index + 1:index + 7]]})
    cases = []
    for page_mask, size, old in itertools.product((0xfff, 0x1fff), (0, 1, 0x1000, 0x2001), (0x400000, 0x402000, 0xfffff000)):
        uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
        D.put(uc, 0x1e2484, 0)
        D.put(uc, 0x1e89ec, page_mask)
        D.put(uc, 0x1f6e74, old)
        D.put(uc, D.STACK, D.STOP, size)
        D.run_to(uc, allocator, D.STOP)
        rounded = ((page_mask + size) & MASK) & (~page_mask & MASK)
        expected = (old + rounded) & MASK
        assert uc.reg_read(X.UC_X86_REG_EAX) == old
        assert D.words(uc, 0x1f6e74, 1) == [expected]
        D.assert_callee_saved(uc)
        for pc in trace:
            ins = next(R.CS.disasm(R.read_original(pc, 15), pc, count=1))
            assert bytes(uc.mem_read(pc, ins.size)) == ins.bytes
        cases.append({'page_mask': hex(page_mask), 'requested_size': size, 'old_pointer': hex(old),
                      'returned_eax': hex(uc.reg_read(X.UC_X86_REG_EAX)), 'new_pointer': hex(expected),
                      'wraparound_fixture': old + rounded > MASK})
    result = {'summary': {'known_instruction_heads_scanned': len(heads), 'control_sites_reviewed': len(rows),
                          'control_sites_without_address_matched_high_ops': sum(not r['high_operations_at_site'] for r in rows),
                          'control_sites_with_only_phi_operations': sum(bool(r['high_operations_at_site']) for r in rows),
                          'whole_function_high_cr0_cr3_outputs': len(cpu_outputs),
                          'alloc_pages_direct_calls': len(callers), 'allocator_return_execution_cases': len(cases),
                          'allocator_old_pointer_return_mismatches': 0},
              'paging_control': rows, 'canonical_paging_c_matches_previous_fresh_export': True,
              'allocator_c_declaration': 'void _alloc_pages(int param_1)',
              'allocator_candidate_contract': 'On pmap_initialized == 0: EAX = old allocation pointer; advance pointer by rounded size modulo 2^32.',
              'callers': callers, 'allocator_execution': cases,
              'limits': ['Allocator wraparound cases are arithmetic probes, not valid usable allocation fixtures.',
                         'No claim that exact pointer typedef or signedness is established by EAX return alone.',
                         'Indirect callers and initialized panic branch are not executed here.',
                         'No fresh Ghidra extraction or signature edits; prior report 18 export is hashed input.',
                         'High-pcode omission is not a claim that raw p-code or original instructions lack register writes.']}
    (HERE / 'representation-review.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result['summary'], indent=2))
    print(json.dumps(callers, indent=2))


if __name__ == '__main__':
    main()
