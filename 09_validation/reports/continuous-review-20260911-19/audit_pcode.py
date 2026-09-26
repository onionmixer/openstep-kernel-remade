"""FS/GS selector versus hidden-base representation audit."""
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
    selector_def = re.search(r'define register offset=(0x[0-9a-f]+) size=2\s*\[\s*ES\b([^]]*)\]', source)
    selector_names = ['ES'] + selector_def[2].split()
    hidden_def = re.search(r'define register offset=(0x[0-9a-f]+) size=\$\(SIZE\)\s*\[\s*FS_OFFSET\s+GS_OFFSET\s*\]', source)
    assert selector_def and hidden_def
    selectors = {n.lower(): ('register', int(selector_def[1], 16) + selector_names.index(n) * 2, 2) for n in ('FS', 'GS')}
    # Selected program is x86 32-bit; the read instruction independently confirms this node width.
    bases = {n: ('register', int(hidden_def[1], 16) + i * 4, 4) for i, n in enumerate(('fs', 'gs'))}
    scan = json.loads((HERE / 'scan.json').read_text())
    funcs = {f['entry']: f for f in json.loads((HERE / 'exports/pcode.json').read_text())}
    assert set(funcs) == {r['owner'] for r in scan['sites']} and all(f['completed'] for f in funcs.values())
    writes, accesses, changed = [], [], []
    for entry, f in funcs.items():
        canonical = (R.G / 'functions' / (entry + '.c')).read_text()
        canonical = re.sub(r'\A/\* Ghidra decompiler output, not reconstructed GCC 2\.7 source\..*?\*/\s*', '', canonical, flags=re.S).strip()
        if canonical != (HERE / 'exports' / (entry + '.c')).read_text().strip():
            changed.append(entry)
    for site in scan['sites']:
        f = funcs[site['owner']]
        raw = next(i for i in f['raw_instructions'] if i['address'] == site['site'])
        high = [op for b in f['high_blocks'] for op in b['operations']]
        at_site = [op for op in high if op['address'] == site['site']]
        if site['selector_write']:
            selector, base = selectors[site['target_selector']], bases[site['target_selector']]
            raw_selector = [op for op in raw['operations'] if op.get('output') and node(op['output']) == selector]
            assert len(raw_selector) == 1
            writes.append({**site, 'raw_operations': raw['operations'], 'high_operations_at_site': at_site,
                'raw_hidden_base_outputs': [op for op in raw['operations'] if op.get('output') and node(op['output']) == base],
                'raw_effect_userops': [op for op in raw['operations'] if op['opcode'] == 'CALLOTHER'],
                'high_selector_outputs': [op for op in at_site if op.get('output') and node(op['output']) == selector],
                'high_hidden_base_outputs': [op for op in at_site if op.get('output') and node(op['output']) == base]})
        if {'fs', 'gs'} & set(site['memory_segments']):
            accesses.append({**site, 'raw_operations': raw['operations'], 'high_operations_at_site': at_site,
                'raw_uses_hidden_base': any(node(v) in bases.values() for op in raw['operations'] for v in op['inputs'])})
    summary = {'fresh_functions': len(funcs), 'normalized_c_changed': len(changed),
               'selector_write_sites': len(writes),
               'selector_write_kinds': dict(collections.Counter(r['target_selector'] + '_' + r['operation'] for r in writes)),
               'raw_hidden_base_update_sites': sum(bool(r['raw_hidden_base_outputs']) for r in writes),
               'raw_selector_effect_userop_sites': sum(bool(r['raw_effect_userops']) for r in writes),
               'high_selector_output_sites': sum(bool(r['high_selector_outputs']) for r in writes),
               'high_hidden_base_output_sites': sum(bool(r['high_hidden_base_outputs']) for r in writes),
               'memory_override_sites': len(accesses), 'raw_hidden_base_consumer_sites': sum(r['raw_uses_hidden_base'] for r in accesses),
               'segment_state_fidelity_verified': False}
    lines = source.splitlines()
    needles = ('FS_OFFSET', 'GS_OFFSET', ':MOV Sreg,rm16', ':POP FS', ':POP GS')
    evidence = [{'line': i + 1, 'text': line} for i, line in enumerate(lines) if any(n in line for n in needles)]
    (HERE / 'pcode-audit.json').write_text(json.dumps({'summary': summary, 'selector_nodes': selectors, 'hidden_base_nodes': bases,
        'selector_writes': writes, 'memory_accesses': accesses, 'changed_c_entries': changed,
        'language_source': {'path': str(LANGUAGE), 'sha256': hashlib.sha256(LANGUAGE.read_bytes()).hexdigest(), 'lines': evidence},
        'limits': ['The source register declarations are paired with exported program nodes, not all architecture modes.',
                   'No exhaustive implicit segment-loading instruction or far-return audit.',
                   'A hidden-base input is not proof that a runtime adapter updates it correctly.']}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
