"""CPU-state raw/high representation audit, with explicit incomplete semantics."""
import collections
import hashlib
import json
from pathlib import Path
import re
from scan import HERE, R

LANGUAGE = Path('/home/onion/ghidra_12.1_PUBLIC/Ghidra/Processors/x86/data/languages/ia.sinc')


def node(value):
    m = re.fullmatch(r'\(([^,]+), (0x[0-9a-f]+), ([0-9]+)\)', value)
    assert m, value
    return m[1], int(m[2], 16), int(m[3])


def main():
    scan = json.loads((HERE / 'scan.json').read_text())
    funcs = {f['entry']: f for f in json.loads((HERE / 'exports/pcode.json').read_text())}
    assert set(funcs) == set(scan['owners']) and all(f['completed'] for f in funcs.values())
    rows, changes, reloads = [], [], []
    for entry, f in funcs.items():
        canonical = (R.G / 'functions' / (entry + '.c')).read_text()
        canonical = re.sub(r'\A/\* Ghidra decompiler output, not reconstructed GCC 2\.7 source\..*?\*/\s*', '', canonical, flags=re.S).strip()
        if canonical != (HERE / 'exports' / (entry + '.c')).read_text().strip():
            changes.append(entry)
    for site in scan['sites']:
        f = funcs[site['owner']]
        raw = next(i for i in f['raw_instructions'] if i['address'] == site['site'])
        all_high = [op for block in f['high_blocks'] for op in block['operations']]
        at_site = [op for op in all_high if op['address'] == site['site']]
        row = {**site, 'raw_operations': raw['operations'], 'high_operations_at_site': at_site}
        if site.get('direction') == 'write' or site['operation'] == 'clts':
            outputs = [node(op['output']) for op in raw['operations'] if op.get('output') and node(op['output'])[0] == 'register']
            dest, = outputs
            assert dest[0] == 'register'
            row['special_output'] = dest
            row['high_matching_register_writes'] = [op for op in at_site if op.get('output') and node(op['output']) == dest]
        if site['operation'] in ('lgdt', 'lidt'):
            raw_call, = raw['operations']
            assert raw_call['opcode'] == 'CALLOTHER'
            row['raw_descriptor_argument'] = node(raw_call['inputs'][1])
            original = R.function_instructions(int(site['owner'], 16))[int(site['site'], 16)]
            row['capstone_memory_operand_size'] = original.operands[0].size
        if site.get('special_register') == 'cr3' and site.get('direction') == 'read':
            instructions = R.function_instructions(int(site['owner'], 16))
            pc = int(site['site'], 16)
            ins = instructions[pc]
            nxt = instructions.get(pc + ins.size)
            if nxt and nxt.mnemonic == 'mov' and nxt.op_str == 'cr3, ' + ins.reg_name(ins.operands[0].reg):
                raw_next = next(i for i in f['raw_instructions'] if int(i['address'], 16) == nxt.address)
                high_pair = [op for op in all_high if int(op['address'], 16) in (pc, nxt.address)]
                reloads.append({'owner': site['owner'], 'name': site['name'], 'read_site': site['site'],
                                'rewrite_site': f'{nxt.address:08x}', 'raw': raw['operations'] + raw_next['operations'],
                                'high_at_pair': high_pair})
        rows.append(row)
    writes = [r for r in rows if 'special_output' in r]
    raw_empty = [r for r in rows if not r['raw_operations']]
    summary = {'fresh_functions': len(funcs), 'normalized_c_changed': len(changes),
               'sites': len(rows), 'raw_empty_sites': len(raw_empty),
               'raw_empty_operations': dict(collections.Counter(r['operation'] for r in raw_empty)),
               'control_debug_or_clts_writes': len(writes),
               'same_address_high_special_write_present': sum(bool(r['high_matching_register_writes']) for r in writes),
               'same_address_high_special_write_absent': sum(not r['high_matching_register_writes'] for r in writes),
               'cr3_read_rewrite_pairs': len(reloads),
               'cr3_pairs_with_no_high_operations_at_either_site': sum(not r['high_at_pair'] for r in reloads),
               'descriptor_load_sites': sum(r['operation'] in ('lgdt', 'lidt') for r in rows),
               'all_cpu_state_semantics_verified': False}
    source = LANGUAGE.read_text()
    lines = source.splitlines()
    needles = (':CLTS', ':WBINVD', ':LGDT', ':LIDT', ':LLDT', ':LTR', ':INVLPG')
    selected_lines = set()
    for i, line in enumerate(lines):
        if line.startswith(needles):
            selected_lines.update(range(i, min(i + 5, len(lines))))
    evidence = [{'line': i + 1, 'text': lines[i]} for i in sorted(selected_lines)]
    (HERE / 'pcode-audit.json').write_text(json.dumps({'summary': summary, 'sites': rows,
        'cr3_reload_pairs': reloads, 'changed_c_entries': changes,
        'language_source': {'path': str(LANGUAGE), 'sha256': hashlib.sha256(LANGUAGE.read_bytes()).hexdigest(), 'lines': evidence},
        'limits': ['Address-matched representation counts are not whole-function equivalence proofs.',
                   'Userop presence does not specify privilege, cache, descriptor, fault or device semantics.',
                   'CR3 read/rewrite value equality does not establish CPU-state operation redundancy.']}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
