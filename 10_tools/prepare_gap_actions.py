#!/usr/bin/env python3
"""Calculate bounded code/data correction ranges in Python from saved evidence."""
import csv
import json
import struct
from pathlib import Path
import capstone

ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'04_ghidra/exports/x86/full-pass2'
OUT=ROOT/'09_validation/static/full-analysis/gap-actions.json'

def main():
    meta=json.loads((ROOT/'03_original/x86/inventory/macho.json').read_text())
    data=(ROOT/'03_original/x86/binaries/mach_kernel').read_bytes()
    section=next(s for s in meta['sections'] if s['name']=='__text')
    start=int(section['address'],16);end=start+section['size'];fileoff=section['file_offset']
    syms=list(csv.DictReader((ROOT/'03_original/x86/inventory/symbols.tsv').open(),delimiter='\t'))
    protos=[s for s in syms if s['name'].startswith('_NX') and s['name'].endswith('Prototype')]
    data_actions=[]
    for s in protos:
        va=int(s['value'],16)
        words=struct.unpack_from('<4I',data,fileoff+va-start)
        assert all(start<=w<end for w in words[:3]) and words[3]==0
        data_actions.append({'start':hex(va),'end_inclusive':hex(va+15),'symbol':s['name'],
                             'words':[hex(w) for w in words],'evidence':'SDK objc/hashtable2.h; three function pointers and zero style; original symbol'})
    ctxs=json.loads((ROOT/'04_ghidra/exports/x86/repair-pass2/gap-contexts.json').read_text())
    contexts={int(c['start'],16):c for c in ctxs}
    coverage=json.loads((SOURCE/'coverage.json').read_text())
    decoder=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    decoder.skipdata=True
    actions=[];excluded=[]
    for kind in ('undefined_ranges','orphan_instruction_ranges'):
        for r in coverage[kind]:
            a=int(r['start'],16);z=int(r['end_inclusive'],16)+1
            if a<start or z>end:continue
            raw=data[fileoff+a-start:fileoff+z-start]
            if all(v in (0,0x90) for v in raw):continue
            if any(int(d['start'],16)<=a<=int(d['end_inclusive'],16) for d in data_actions):continue
            if a%4==0 and len(raw)%4==0 and all(start<=v<end for v in struct.unpack('<'+'I'*(len(raw)//4),raw)):
                excluded.append({**r,'classification':'code_pointer_array','words':[hex(w) for w in struct.unpack('<'+'I'*(len(raw)//4),raw)]});continue
            instructions=list(decoder.disasm(raw,a))
            if sum(i.size for i in instructions)!=len(raw):
                raise ValueError(f'Undecodable action bytes: {a:#x}')
            while instructions and instructions[0].mnemonic=='nop': instructions.pop(0)
            while instructions and (instructions[-1].mnemonic=='nop' or not any(instructions[-1].bytes)): instructions.pop()
            if not instructions:continue
            if any(i.id==0 for i in instructions):raise ValueError(f'Invalid instruction inside fragment: {a:#x}')
            a=instructions[0].address;z=instructions[-1].address+instructions[-1].size
            ctx=contexts.get(int(r['start'],16),{})
            role='orphan_instruction_fragment' if kind=='orphan_instruction_ranges' else 'skipped_instruction_fragment'
            if ctx.get('previous') in ('HLT','INT3'):role='resumable_instruction_tail'
            elif any(t.get('noreturn') for t in ctx.get('targets',[])):role='noreturn_fallthrough_fragment'
            actions.append({'start':hex(a),'end_inclusive':hex(z-1),'origin_range':r,'role':role,
                            'context':ctx,'instructions':[{'address':hex(i.address),'bytes':i.bytes.hex(),'text':i.mnemonic+' '+i.op_str} for i in instructions]})
    OUT.write_text(json.dumps({'data_corrections':data_actions,'code_actions':actions,'pointer_arrays':excluded},indent=2)+'\n')
    print({'data_corrections':len(data_actions),'code_actions':len(actions),'pointer_arrays':len(excluded)})

if __name__=='__main__':main()
