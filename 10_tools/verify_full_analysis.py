#!/usr/bin/env python3
"""Verify exported function/fragment bodies and original-section byte coverage in Python."""
import csv
import hashlib
import json
import re
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
RUN=ROOT/'04_ghidra/exports/x86/full-pass5'
OUT=ROOT/'09_validation/reports/full-analysis'

def digest(p):
    h=hashlib.sha256()
    with p.open('rb') as stream:
        for block in iter(lambda:stream.read(1024*1024),b''):h.update(block)
    return h.hexdigest()

def main():
    OUT.mkdir(parents=True,exist_ok=True)
    meta=json.loads((ROOT/'03_original/x86/inventory/macho.json').read_text())
    binary=ROOT/'03_original/x86/binaries/mach_kernel';data=binary.read_bytes()
    assert digest(binary)==meta['sha256']
    manifest=json.loads((RUN/'manifest.json').read_text());functions=json.loads((RUN/'functions.json').read_text())
    assert manifest['binary_sha256']==meta['sha256'] and manifest['status']=='export_finished'
    failures=[];warnings=[];artifacts=[]
    original_functions=[f for f in functions if not f['analysis_fragment']]
    for f in functions:
        stem=f'{int(f["address"],16):08x}';source=RUN/'functions'/f'{stem}.c';assembly=RUN/'functions'/f'{stem}.asm'
        if f['status']!='decompiled' or not source.is_file() or not source.stat().st_size:
            failures.append({'address':f['address'],'reason':'missing or failed pseudocode'});continue
        text=source.read_text()
        if '{' not in text or '}' not in text:failures.append({'address':f['address'],'reason':'no C-like body'})
        asm_ranges=[]
        for line in assembly.read_text().splitlines():
            a,length,_=line.split('\t',2);asm_ranges.append((int(a,16),int(a,16)+int(length)))
        expected=set()
        for r in f['body']:expected.update(range(int(r['start'],16),int(r['end_inclusive'],16)+1))
        actual=set()
        for a,z in asm_ranges:actual.update(range(a,z))
        if actual!=expected:failures.append({'address':f['address'],'reason':'assembly/body byte mismatch'})
        notes=[line.strip() for line in text.splitlines() if 'WARNING:' in line]
        if notes:warnings.append({'address':f['address'],'analysis_fragment':f['analysis_fragment'],'warnings':notes})
    sec=next(s for s in meta['sections'] if s['name']=='__text');start=int(sec['address'],16);end=start+sec['size']
    kinds=bytearray(sec['size']);kind_id={'instruction':1,'data':2,'undefined':3}
    with (RUN/'code-units.tsv').open() as stream:
        for unit in csv.DictReader(stream,delimiter='\t'):
            a=max(int(unit['start'],16),start);z=min(int(unit['end_inclusive'],16)+1,end)
            if a>=z:continue
            if any(kinds[a-start:z-start]):raise ValueError('Overlapping code units')
            kinds[a-start:z-start]=bytes([kind_id[unit['kind']]])*(z-a)
    coverage=json.loads((RUN/'coverage.json').read_text())
    unclassified=[];padding=[]
    for r in coverage['undefined_ranges']:
        a=int(r['start'],16);z=int(r['end_inclusive'],16)+1
        if a<start or z>end:continue
        raw=data[sec['file_offset']+a-start:sec['file_offset']+z-start]
        if set(raw)<={0,0x90}:padding.append({**r,'bytes_hex':raw.hex(),'classification':'zero_or_nop_padding'})
        else:unclassified.append({**r,'bytes_hex':raw.hex()})
    found={int(f['address'],16) for f in functions}
    symbols=list(csv.DictReader((ROOT/'03_original/x86/inventory/symbols.tsv').open(),delimiter='\t'))
    actions=json.loads((ROOT/'09_validation/static/full-analysis/gap-actions.json').read_text())
    data_symbols={int(a['start'],16) for a in actions['data_corrections']}
    text_symbols=[s for s in symbols if int(s['section'])==sec['index']]
    missing_symbols=[s for s in text_symbols if int(s['value'],16) not in found|data_symbols]
    objc=json.loads((ROOT/'03_original/x86/inventory/objc.json').read_text())
    missing_imps=[m for m in objc['methods'] if int(m['imp'],16) not in found]
    # Verify every original code byte is represented in the independent linear export.
    linear=ROOT/'09_validation/static/full-analysis/text-linear.asm';expected=start
    for line in linear.read_text().splitlines():
        if line.startswith(';'):continue
        a,raw,_=line.split('\t',2);a=int(a,16);raw=bytes.fromhex(raw)
        assert a==expected
        assert raw==data[sec['file_offset']+a-start:sec['file_offset']+a-start+len(raw)]
        expected+=len(raw)
    assert expected==end
    header_end=28+meta['commands_size'];assert not any(data[header_end:sec['file_offset']])
    assert (ROOT/'04_ghidra/projects/x86-full.gpr').is_file()
    assert (RUN/'data-types.json').is_file() and (RUN/'references.tsv').is_file()
    for path in sorted(RUN.rglob('*')):
        if path.is_file():artifacts.append({'path':str(path.relative_to(ROOT)),'size':path.stat().st_size,'sha256':digest(path)})
    report={
        'binary_sha256':meta['sha256'],'primary_export':str(RUN.relative_to(ROOT)),
        'functions':len(original_functions),'synthetic_analysis_fragments':len(functions)-len(original_functions),
        'exported_pseudocode_units':len(functions),'export_failures':failures,
        'text_bytes':sec['size'],'instruction_bytes':kinds.count(1),'data_bytes':kinds.count(2),
        'padding_bytes':kinds.count(3),'unrepresented_bytes':kinds.count(0),
        'nonpadding_unclassified_ranges':unclassified,'orphan_instruction_ranges':coverage['orphan_instruction_ranges'],
        'original_text_symbols':len(text_symbols),'known_data_symbols':len(data_symbols),'missing_symbol_entries':missing_symbols,
        'objc_method_count':len(objc['methods']),'missing_objc_entries':missing_imps,
        'functions_or_fragments_with_warnings':len(warnings),
        'all_exported_units_have_complete_assembly_and_pseudocode':not failures,
        'byte_inventory_complete':not(unclassified or coverage['orphan_instruction_ranges'] or kinds.count(0)),
        'known_entries_complete':not(missing_symbols or missing_imps),
        'semantic_reconstruction_verified':False,'gcc27_build_verified':False,
    }
    (OUT/'audit.json').write_text(json.dumps(report,indent=2)+'\n')
    (OUT/'padding.json').write_text(json.dumps(padding,indent=2)+'\n')
    (OUT/'decompiler-warnings.json').write_text(json.dumps(warnings,indent=2)+'\n')
    (OUT/'artifact-hashes.json').write_text(json.dumps(artifacts,indent=2)+'\n')
    print(json.dumps(report,indent=2))
    if failures or unclassified or coverage['orphan_instruction_ranges'] or kinds.count(0) or missing_symbols or missing_imps:
        raise SystemExit(1)

if __name__=='__main__':main()
