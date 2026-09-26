"""Compare original wait/retry branches with raw and optimized P-code."""
import collections
import hashlib
import json
import re
from scan import HERE, ROOT, R


def main():
    scan = json.loads((HERE / 'scan.json').read_text())
    funcs = json.loads((HERE / 'exports/pcode.json').read_text())
    rows = []
    for f in funcs:
        assert f['completed'], f['name']
        canonical = (R.G / 'functions' / (f['entry'] + '.c')).read_text()
        canonical = re.sub(r'^\s*/\* Ghidra decompiler output,.*?\*/', '', canonical, count=1, flags=re.S).strip()
        assert canonical == (HERE / 'exports' / (f['entry'] + '.c')).read_text().strip()
        raw = {i['address']: i for i in f['raw_instructions']}
        for site in scan['sites']:
            if site['owner'] != f['entry']:
                continue
            cond, branch = site['condition']['address'], site['branch']['address']
            original = R.function_instructions(int(f['entry'], 16))
            raw_branch = raw[branch]
            assert any(o['opcode'] == 'CBRANCH' for o in raw_branch['operations'])
            # Use operation addresses, not [block.start, block.stop] interval:
            # optimized blocks may combine non-contiguous original locations.
            high_branch = [{'index': b['index'], 'start': b['start'], 'stop': b['stop'], 'operations': b['operations']}
                           for b in f['high_blocks'] if any(o['address'] == branch and o['opcode'] == 'CBRANCH' for o in b['operations'])]
            exchange = int(next(i['address'] for i in site['following_window'] if i['mnemonic'] == 'xchg'), 16)
            cursor = exchange + original[exchange].size
            tail = []
            for _ in range(8):
                i = original[cursor]
                tail.append(i)
                cursor += i.size
                if i.mnemonic in ('je', 'jne'):
                    break
            retry = tail[-1]
            assert retry.mnemonic in ('je', 'jne') and retry.operands[0].type == R.X86_OP_IMM
            retry_addr = f'{retry.address:08x}'
            assert any(o['opcode'] == 'CBRANCH' for o in raw[retry_addr]['operations'])
            high_retry = [o for b in f['high_blocks'] for o in b['operations'] if o['address'] == retry_addr and o['opcode'] == 'CBRANCH']
            row = {'owner': f['entry'], 'name': f['name'], 'site': branch, 'kind': site['kind'],
                   'raw_condition_operations': raw[cond]['operations'],
                   'raw_load_operations': raw[site['load']['address']]['operations'] if site['load'] else None,
                   'high_wait_blocks': high_branch, 'high_wait_branch_present': bool(high_branch),
                   'raw_retry_address': retry_addr, 'raw_retry_target': hex(retry.operands[0].imm),
                   'high_retry_branch_present': bool(high_retry)}
            if f['name'] == '_thread_policy':
                assert len(high_branch) == 1
                assert not any(o['opcode'] == 'LOAD' for o in high_branch[0]['operations'])
                load_pc = site['load']['address']
                loads = [(b['index'], o) for b in f['high_blocks'] for o in b['operations'] if o['address'] == load_pc and o['opcode'] == 'LOAD']
                assert len(loads) == 1 and loads[0][0] != high_branch[0]['index']
                row['thread_policy_load_outside_wait_block'] = True
                row['thread_policy_load_block'] = loads[0][0]
            rows.append(row)
    paths = [ROOT / '03_original/x86/binaries/mach_kernel',
             ROOT / '01_resources/upstream/darwin01/kernel/mach/i386/simple_lock.h',
             ROOT / '01_resources/upstream/darwin01/kernel/mach/boolean.h',
             ROOT / '01_resources/upstream/darwin01/kernel/mach/i386/boolean.h',
             HERE.parent / 'cautious-followup-20260911/review.py',
             HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py']
    inputs = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size, 'sha256': hashlib.sha256(p.read_bytes()).hexdigest()} for p in paths]
    (HERE / 'input-hashes.json').write_text(json.dumps(inputs, indent=2) + '\n')
    summary = {'selected_functions': len(funcs), 'selected_sites': len(rows),
               'raw_wait_and_retry_branches_present': len(rows),
               'high_wait_branches_absent': [r['site'] for r in rows if not r['high_wait_branch_present']],
               'high_retry_branches_absent': [r['raw_retry_address'] for r in rows if not r['high_retry_branch_present']],
               'canonical_selected_c_exact': True}
    (HERE / 'pcode-audit.json').write_text(json.dumps({'summary': summary, 'sites': rows}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
