"""Whole-export EBX triage; entry-prefix screening is deliberately not full dataflow."""
import collections
import hashlib
import importlib.util
import json
from pathlib import Path
import sys
import capstone
from capstone.x86_const import X86_REG_EBX, X86_REG_BX, X86_REG_BL, X86_REG_BH

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('original', HERE.parent / 'cautious-followup-20260911/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)
ALIASES = {X86_REG_EBX, X86_REG_BX, X86_REG_BL, X86_REG_BH}


def prefix(entry, instructions):
    addr = entry
    examined = []
    first_push_seen = False
    while addr in instructions:
        ins = instructions[addr]
        examined.append(hex(addr))
        reads, writes = map(set, ins.regs_access())
        save_push = ins.mnemonic == 'push' and ins.op_str == 'ebx' and not first_push_seen
        if save_push:
            first_push_seen = True
        zero_idiom = ins.mnemonic in ('xor', 'sub') and ins.op_str == 'ebx, ebx'
        if reads & ALIASES and not save_push and not zero_idiom:
            return {'state': 'entry_ebx_read', 'address': hex(addr),
                    'instruction': ins.mnemonic + ' ' + ins.op_str, 'prefix': examined}
        if writes & ALIASES:
            return {'state': 'entry_prefix_write', 'address': hex(addr),
                    'instruction': ins.mnemonic + ' ' + ins.op_str, 'prefix': examined}
        if any(ins.group(g) for g in (capstone.CS_GRP_CALL, capstone.CS_GRP_JUMP,
                                      capstone.CS_GRP_RET, capstone.CS_GRP_IRET, capstone.CS_GRP_INT)):
            return {'state': 'control_transfer_stop', 'address': hex(addr),
                    'instruction': ins.mnemonic + ' ' + ins.op_str, 'prefix': examined}
        addr += ins.size
    return {'state': 'listing_gap_stop', 'address': hex(addr), 'prefix': examined}


def main():
    all_rows, c_hits, raw_hits = [], [], []
    for entry, f in sorted(R.FMAP.items()):
        path = R.G / 'functions' / f'{entry:08x}.c'
        text = path.read_text()
        instructions = R.function_instructions(entry)
        probe = prefix(entry, instructions)
        row = {'entry': hex(entry), 'name': f['name'],
               'fragment_named': f['name'].startswith('__analysis_fragment_'),
               'c_contains_unaff_ebx': 'unaff_EBX' in text, 'entry_prefix': probe,
               'c_lines': [{'line': n, 'text': line} for n, line in enumerate(text.splitlines(), 1)
                           if 'unaff_EBX' in line]}
        all_rows.append(row)
        if row['c_contains_unaff_ebx']:
            c_hits.append(row)
        if probe['state'] == 'entry_ebx_read':
            raw_hits.append(row)
    summary = {'functions_screened': len(all_rows), 'c_unaff_ebx': len(c_hits),
               'c_unaff_fragment_named': sum(r['fragment_named'] for r in c_hits),
               'c_unaff_other': sum(not r['fragment_named'] for r in c_hits),
               'raw_entry_prefix_ebx_reads': len(raw_hits),
               'raw_entry_prefix_nonfragment_reads': sum(not r['fragment_named'] for r in raw_hits),
               'prefix_states': dict(collections.Counter(r['entry_prefix']['state'] for r in all_rows))}
    result = {'summary': summary, 'c_candidates': c_hits, 'raw_prefix_candidates': raw_hits,
              'all_prefix_results': [{k: v for k, v in r.items() if k != 'c_lines'} for r in all_rows],
              'limits': 'Entry prefix only, stops at first control transfer/write/gap; no branch/call propagation. First PUSH EBX is assumed to be a save and excluded; later PUSH EBX is a read. The first-push assumption can miss nonstandard entry behavior. Fragment naming is not a proof of fragment semantics. Candidates are not confirmed ABI bugs.'}
    (HERE / 'abi-candidates.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(summary, indent=2))
    print('Non-fragment raw-prefix candidates:')
    for row in raw_hits:
        if not row['fragment_named']:
            print(row['entry'], row['name'], row['entry_prefix']['instruction'])


if __name__ == '__main__':
    main()
