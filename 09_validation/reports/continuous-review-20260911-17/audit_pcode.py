"""Address-matched raw/high effects, distinguishing absence from equivalence."""
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
    source = LANGUAGE.read_text()
    match = re.search(r'define register offset=(0x[0-9a-f]+) size=1\s*\[\s*CF\b([^]]*)\]', source)
    names = ['CF'] + match[2].split()
    if_node = ('register', int(match[1], 16) + names.index('IF'), 1)
    scan = json.loads((HERE / 'scan.json').read_text())
    funcs = {f['entry']: f for f in json.loads((HERE / 'exports/pcode.json').read_text())}
    assert set(funcs) == set(scan['owners']) and all(f['completed'] for f in funcs.values())
    control, io, changes = [], [], []
    userops = collections.defaultdict(set)
    for entry, function in funcs.items():
        fresh = (HERE / 'exports' / (entry + '.c')).read_text().strip()
        canonical = (R.G / 'functions' / (entry + '.c')).read_text()
        canonical = re.sub(r'\A/\* Ghidra decompiler output, not reconstructed GCC 2\.7 source\..*?\*/\s*', '', canonical, flags=re.S).strip()
        if canonical != fresh:
            changes.append(entry)
    for site in scan['sites']:
        f = funcs[site['owner']]
        raw = next(i for i in f['raw_instructions'] if i['address'] == site['site'])
        high = [op for block in f['high_blocks'] for op in block['operations']]
        at_site = [op for op in high if op['address'] == site['site']]
        if site['operation'] in ('cli', 'sti'):
            expected = int(site['operation'] == 'sti')
            assert len(raw['operations']) == 1
            op = raw['operations'][0]
            assert op['opcode'] == 'COPY' and node(op['output']) == if_node
            assert node(op['inputs'][0]) == ('const', expected, 1)
            writes = [op for op in high if op.get('output') and node(op['output']) == if_node]
            same = [op for op in writes if op['address'] == site['site']]
            control.append({**site, 'raw_operations': raw['operations'],
                            'high_operations_at_site': at_site, 'high_if_writes_at_site': same,
                            'all_function_high_if_writes': writes})
        elif site['kind'] == 'port_io':
            raw_calls = [op for op in raw['operations'] if op['opcode'] == 'CALLOTHER']
            assert len(raw_calls) == 1
            id_node = node(raw_calls[0]['inputs'][0])
            assert id_node[0] == 'const'
            userops[site['operation']].add(id_node[1])
            matching = [op for op in at_site if op['opcode'] == 'CALLOTHER' and node(op['inputs'][0]) == id_node]
            raw_width = node(raw_calls[0]['output'])[2] if site['operation'] == 'in' else node(raw_calls[0]['inputs'][2])[2]
            assert raw_width == site['width']
            high_widths = [(node(op['output'])[2] if op.get('output') else None)
                           if site['operation'] == 'in' else node(op['inputs'][2])[2] for op in matching]
            io.append({**site, 'raw_callother': raw_calls[0], 'high_callother_at_site': matching,
                       'same_address_callother_count': len(matching),
                       'raw_data_width': raw_width, 'high_data_widths': high_widths})
    summary = {'fresh_functions': len(funcs), 'decompile_completed': sum(f['completed'] for f in funcs.values()),
               'normalized_c_changed_from_canonical': len(changes),
               'cli_sti_sites': len(control),
               'raw_if_updates_verified': len(control),
               'high_if_write_present_at_original_site': sum(bool(r['high_if_writes_at_site']) for r in control),
               'high_if_write_absent_at_original_site': sum(not r['high_if_writes_at_site'] for r in control),
               'cli_sti_owners_without_any_high_if_write': len({r['owner'] for r in control if not r['all_function_high_if_writes']}),
               'port_io_sites': len(io),
               'port_io_same_address_match_counts': dict(collections.Counter(r['same_address_callother_count'] for r in io)),
               'port_io_matching_width_sites': sum(r['high_data_widths'] == [r['width']] for r in io),
               'port_input_result_omitted_sites': sum(r['operation'] == 'in' and r['high_data_widths'] == [None] for r in io),
               'all_effect_fidelity_verified': False}
    lines = source.splitlines()
    evidence = [{'line': i + 1, 'text': line} for i, line in enumerate(lines)
                if line.startswith((':CLI', ':STI', ':IN ', ':OUT '))]
    (HERE / 'pcode-audit.json').write_text(json.dumps({'summary': summary, 'if_node': if_node,
        'observed_userop_ids': {k: sorted(v) for k, v in userops.items()},
        'control_sites': control, 'io_sites': io, 'changed_c_entries': changes,
        'language_source': {'path': str(LANGUAGE), 'sha256': hashlib.sha256(LANGUAGE.read_bytes()).hexdigest(), 'lines': evidence},
        'limits': ['An absent address-matched IF write alone is not whole-function equivalence proof.',
                   'Same-address CALLOTHER preserves an explicit I/O marker, not port/value/order/fault correctness.',
                   'Normalized C comparison removes only the canonical provenance header.']}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))
    print(json.dumps({'if_node': if_node, 'userops': {k: sorted(v) for k, v in userops.items()}}, indent=2))


if __name__ == '__main__':
    main()
