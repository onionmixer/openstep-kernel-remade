#!/usr/bin/env python3
"""Audit all original text bytes, independently decode them, and expose gaps."""
import csv
import json
import struct
from pathlib import Path
import capstone

ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'04_ghidra/exports/x86/full-pass1'
OUT=ROOT/'09_validation/static/full-analysis'

def main():
    OUT.mkdir(parents=True,exist_ok=True)
    metadata=json.loads((ROOT/'03_original/x86/inventory/macho.json').read_text())
    binary=(ROOT/'03_original/x86/binaries/mach_kernel').read_bytes()
    sec=next(s for s in metadata['sections'] if s['name']=='__text')
    start=int(sec['address'],16); end=start+sec['size']
    code=binary[sec['file_offset']:sec['file_offset']+sec['size']]
    decoder=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    decoder.skipdata=True
    decoded=0; invalid=[]
    with (OUT/'text-linear.asm').open('w') as stream:
        stream.write('; Independent linear decode; embedded data may decode as instructions.\n')
        for insn in decoder.disasm(code,start):
            if insn.address != start+decoded: raise ValueError('Linear decoder omitted bytes')
            stream.write(f'{insn.address:#010x}\t{insn.bytes.hex()}\t{insn.mnemonic} {insn.op_str}\n')
            decoded += insn.size
            if insn.id==0: invalid.append({'address':hex(insn.address),'bytes':insn.bytes.hex()})
    assert decoded==len(code)
    coverage=json.loads((SOURCE/'coverage.json').read_text())
    functions=json.loads((SOURCE/'functions.json').read_text())
    symbol_rows=list(csv.DictReader((ROOT/'03_original/x86/inventory/symbols.tsv').open(),delimiter='\t'))
    func_starts={int(f['address'],16) for f in functions}
    missing_symbols=[s for s in symbol_rows if int(s['section'])==sec['index'] and int(s['value'],16) not in func_starts]
    code_units=[]
    classifications=bytearray(len(code))
    values={'instruction':1,'data':2,'undefined':3}
    with (SOURCE/'code-units.tsv').open() as stream:
        for u in csv.DictReader(stream,delimiter='\t'):
            a=int(u['start'],16); z=int(u['end_inclusive'],16)+1
            if z<=start or a>=end:continue
            lo=max(a,start)-start; hi=min(z,end)-start
            if any(classifications[lo:hi]): raise ValueError('Overlapping code units')
            classifications[lo:hi]=bytes([values[u['kind']]])*(hi-lo)
            code_units.append((a,z,u['kind']))
    gaps=[]
    for r in coverage['undefined_ranges']:
        a=int(r['start'],16); z=int(r['end_inclusive'],16)+1
        if a<start or z>end: continue
        raw=code[a-start:z-start]
        if all(b==0x90 for b in raw): category='nop_padding_candidate'
        elif all(b==0 for b in raw): category='zero_fill_candidate'
        elif a%4==0 and len(raw)%4==0 and all(start<=v<end for v in struct.unpack('<'+'I'*(len(raw)//4),raw)):
            category='code_pointer_table_candidate'
        else:category='requires_disassembly_review'
        insns=[{'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str} for i in decoder.disasm(raw,a)]
        gaps.append({**r,'category':category,'raw':raw.hex(),'linear_instructions':insns})
    summary={
        'binary_sha256':metadata['sha256'],'text_start':hex(start),'text_end_exclusive':hex(end),
        'text_bytes':len(code),'linear_decoded_bytes':decoded,'capstone_version':capstone.__version__,
        'ghidra_instruction_bytes':classifications.count(1),'ghidra_defined_data_bytes':classifications.count(2),
        'ghidra_undefined_bytes':classifications.count(3),'unrepresented_bytes':classifications.count(0),
        'ghidra_functions':len(functions),'missing_original_text_symbol_entries':missing_symbols,
        'invalid_linear_instructions':invalid,'orphan_instruction_ranges':coverage['orphan_instruction_ranges'],
        'unclassified_nonpadding_gaps':sum(g['category']=='requires_disassembly_review' for g in gaps),
        'complete':False,
    }
    (OUT/'initial-audit.json').write_text(json.dumps(summary,indent=2)+'\n')
    (OUT/'undefined-text-gaps.json').write_text(json.dumps(gaps,indent=2)+'\n')
    print({k:v for k,v in summary.items() if not isinstance(v,list)})
    print('text symbols without exact function entry:',len(missing_symbols))
    print('unclassified nonpadding gap examples:')
    for g in [g for g in gaps if g['category']=='requires_disassembly_review'][:14]:
        print(g)

if __name__=='__main__':main()
