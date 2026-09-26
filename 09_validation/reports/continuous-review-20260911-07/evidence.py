"""Pin sources, classify reviewed prefix candidates, preserve exact input hashes."""
import collections
import csv
import hashlib
import importlib.util
import json
from pathlib import Path
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('scan', HERE / 'abi_candidates.py')
A = importlib.util.module_from_spec(spec)
spec.loader.exec_module(A)
R, ROOT = A.R, A.R.ROOT


def main():
    candidates = json.loads((HERE / 'abi-candidates.json').read_text())
    classifications = []
    for row in candidates['raw_prefix_candidates']:
        a = int(row['entry'], 16)
        if a in (0x124cb8, 0x1ab830):
            kind = 'verified_hidden_aggregate_output'
        elif a in (0x17e5ec, 0x17e67c):
            kind = 'incoming_ebx_counter_contract_unresolved'
        elif row['entry_prefix']['instruction'].strip() == 'pushal':
            kind = 'assembly_register_frame_save'
        elif a == 0x186f74:
            kind = 'register_supplied_call_target'
        else:
            raise AssertionError(row)
        classifications.append({'entry': row['entry'], 'name': row['name'], 'classification': kind,
                                'first_read': row['entry_prefix']})
    refs = []
    with (R.G / 'references.tsv').open() as stream:
        for row in csv.DictReader(stream, delimiter='\t'):
            try:
                addr = int(row['to'], 16)
            except ValueError:
                continue
            if addr == 0x124cb8:
                refs.append(row)
    assert refs == [{'from': '0x0012417a', 'to': '0x00124cb8', 'type': 'UNCONDITIONAL_CALL', 'operand': '0'}]
    sources = {
        ROOT / '01_resources/upstream/nextmach/mk-108.1/nextif/in_bootp.c':
            ['in_bootp_makeifreq(', 'strcpy(ifr.ifr_name', '*p++ = ifp->if_unit', 'bcopy(sin, &ifr.ifr_addr', 'return (ifr)'],
        ROOT / '01_resources/upstream/darwin01/kernel/bsd/netinet/in_bootp.c':
            ['in_bootp_makeifreq(', 'strcpy(ifr.ifr_name', '*p++ = ifp->if_unit', 'bcopy(sin, &ifr.ifr_addr', 'return (ifr)'],
        ROOT / '01_resources/upstream/nextmach/mk-108.1/bsd/kern_acct.c':
            ['compress(t, ut)', 'register long t;', 'long ut;', 'compress(ru->ru_utime.tv_sec, ru->ru_utime.tv_usec)']}
    excerpts = []
    for path, needles in sources.items():
        data = path.read_bytes()
        lines = data.decode(errors='replace').splitlines()
        assert all(any(n in line for line in lines) for n in needles)
        excerpts.append({'path': str(path.relative_to(ROOT)), 'sha256': hashlib.sha256(data).hexdigest(),
                         'lines': [{'line': i, 'text': line} for i, line in enumerate(lines, 1)
                                   if any(n in line for n in needles)]})
    compress = R.FMAP[R.NAMES['_compress']]
    assert 'Bytef' in compress['signature']
    result = {'classifications': classifications,
              'classification_counts': dict(collections.Counter(r['classification'] for r in classifications)),
              'ifreq_direct_references': refs, 'source_excerpts': excerpts,
              'signature_contamination_example': {'entry': compress['address'], 'name': compress['name'],
                   'stored_signature': compress['signature'],
                   'raw_facts': 'Reads EBP+8 and EBP+0xc as numeric operands; clears EBX; returns accounting exponent/mantissa encoding. Source has compress(long t,long ut).',
                   'status': 'Stored four-argument Bytef prototype is incompatible with these facts; exact type-import origin not established.'}}
    (HERE / 'evidence.json').write_text(json.dumps(result, indent=2) + '\n')
    inputs = list(sources) + [ROOT / '03_original/x86/binaries/mach_kernel', R.G / 'functions.json', R.G / 'references.tsv']
    entries = {0x124154, 0x124cb8, 0x101b48, 0x1013cc, 0x1013e4, 0x103188, 0x103428}
    entries.update(int(r['entry'], 16) for r in classifications)
    for entry in sorted(entries):
        for ext in ('.asm', '.c'):
            inputs.append(R.G / 'functions' / (f'{entry:08x}' + ext))
        ida = ROOT / '05_ida/exports/x86/functions' / f'{entry:08x}.c'
        if ida.exists():
            inputs.append(ida)
    rows = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size,
             'sha256': hashlib.sha256(p.read_bytes()).hexdigest()} for p in inputs]
    (HERE / 'input-hashes.json').write_text(json.dumps(rows, indent=2) + '\n')
    print(json.dumps({'classification_counts': result['classification_counts'], 'input_files': len(rows)}, indent=2))


if __name__ == '__main__':
    main()
