"""Audit terminal BSR.L calls and following code addresses of m68k no-exit candidates."""
import csv,hashlib,json
from bisect import bisect_right
from collections import Counter
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
def tsv(p):
 with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def sign(v,b):return v-(1<<b) if v&(1<<(b-1)) else v
def main():
 binary=(ROOT/'03_original/m68k/binaries/mach_kernel').read_bytes();inv=json.loads((ROOT/'03_original/m68k/inventory/macho.json').read_text());sec=next(x for x in inv['sections'] if x['segment']=='__TEXT' and x['name']=='__text');base=int(sec['address'],16);off=int(sec['file_offset'])
 terms=[x for x in tsv(ROOT/'05_ida/exports/m68k/noexit-candidate-terminal-items.tsv') if x['terminal_mnemonic']=='bsr.l'];funcs=json.loads((ROOT/'05_ida/exports/m68k/function-asm-index.json').read_text());ranges=sorted((int(x['start'],16),int(x['end'],16),x) for x in funcs);starts=[x[0] for x in ranges];units={int(x['address'],16):x for x in tsv(ROOT/'05_ida/exports/m68k/text-units.tsv')};xrefs={(int(x['from'],16),int(x['to'],16),x['type'],x['iscode']) for x in tsv(ROOT/'05_ida/exports/m68k/xrefs.tsv')};rows=[];relations=Counter()
 for term in terms:
  src=int(term['terminal_address'],16);raw=bytes.fromhex(term['terminal_original_bytes']);pos=off+src-base;assert raw.hex()=='61ff'+raw.hex()[4:] and binary[pos:pos+len(raw)]==raw
  target=(src+2+sign(int.from_bytes(raw[2:6],'big'),32))&0xffffffff;assert (src,target,'17','1') in xrefs
  fall=src+len(raw);assert fall in units and units[fall]['kind']=='code';idx=bisect_right(starts,fall)-1;fun=ranges[idx][2] if idx>=0 and fall<ranges[idx][1] else None;rel='outside_candidate_ranges' if fun is None else ('same_candidate' if int(term['start'],16)==int(fun['start'],16) else 'other_candidate');relations[rel]+=1
  rows.append({'candidate_start':term['start'],'candidate_name':term['name'],'bsr_address':term['terminal_address'],'original_bytes':raw.hex(),'computed_call_target':hex(target),'fallthrough_address':hex(fall),'fallthrough_relation':rel,'fallthrough_candidate_start':None if fun is None else fun['start'],'fallthrough_candidate_name':None if fun is None else fun['name']})
 assert len(rows)==18
 out={'schema':1,'architecture':'m68k','original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'terminal_bsr_long_count':len(rows),'fallthrough_relation_counts':dict(relations),'rows':rows,'every_call_target_matches_type17_xref':True,'every_fallthrough_address_is_original_code_item':True,'interpretation_limit':'a BSR target and adjacent fall-through code item do not establish call return, reachability, candidate ownership, ABI, or behavior'}
 (REPORT/'m68k-noexit-terminal-bsr-fallthrough-audit.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(json.dumps({'terminal_bsr_long_count':len(rows),'all_checks_passed':True}))
if __name__=='__main__':main()
