"""Classify IDA function candidates by raw lexical return opcode observations."""
import csv, hashlib, json
from bisect import bisect_left
from collections import Counter
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
EXITS={'m68k':{'4e75':'rts'},'sparc':{'81c7e008':'ret','81c3e008':'retl'}}
def tsv(p):
    with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def main():
    targets={}
    for arch, opcodes in EXITS.items():
        binary=(ROOT/'03_original'/arch/'binaries/mach_kernel').read_bytes(); inv=json.loads((ROOT/'03_original'/arch/'inventory/macho.json').read_text())
        sec=next(x for x in inv['sections'] if x['segment']=='__TEXT' and x['name']=='__text'); base=int(sec['address'],16); offset=int(sec['file_offset'])
        funcs=json.loads((ROOT/'05_ida/exports'/arch/'function-asm-index.json').read_text()); units=tsv(ROOT/'05_ida/exports'/arch/'text-units.tsv')
        observed=[]
        for unit in units:
            if unit['bytes'] in opcodes:
                a=int(unit['address'],16); pos=offset+a-base
                assert binary[pos:pos+int(unit['length'])].hex()==unit['bytes'] and unit['kind']=='code'
                observed.append((a,opcodes[unit['bytes']]))
        observed.sort(); observed_addresses=[a for a,_kind in observed]
        rows=[]; counts=Counter(); opcode_counts=Counter()
        for fun in funcs:
            start,end=int(fun['start'],16),int(fun['end'],16)
            left,right=bisect_left(observed_addresses,start),bisect_left(observed_addresses,end)
            exits=observed[left:right]
            for _address, kind in exits: opcode_counts[kind]+=1
            counts['no_lexical_exit' if not exits else 'one_or_more_lexical_exits']+=1
            rows.append({'start':fun['start'],'end':fun['end'],'name':fun['name'],'lexical_exit_count':len(exits),'lexical_exits':','.join(f'{a:#x}:{k}' for a,k in exits)})
        with (ROOT/'05_ida/exports'/arch/'function-candidate-lexical-exits.tsv').open('w',encoding='utf-8',newline='') as h:
            w=csv.DictWriter(h,fieldnames=rows[0].keys(),delimiter='\t');w.writeheader();w.writerows(rows)
        targets[arch]={'original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'function_candidate_count':len(funcs),'candidate_exit_presence_counts':dict(counts),'lexical_exit_opcode_counts':dict(opcode_counts),'every_observed_exit_code_item_matches_original':True,'tsv':f'05_ida/exports/{arch}/function-candidate-lexical-exits.tsv','interpretation_limit':'lexical return opcode presence or absence does not prove a candidate boundary, reachability, non-returning behavior, ABI, or semantics'}
    out={'schema':1,'targets':targets,'all_checks_passed':True};(REPORT/'function-candidate-lexical-exit-audit.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(json.dumps(out,ensure_ascii=False,sort_keys=True))
if __name__=='__main__':main()
