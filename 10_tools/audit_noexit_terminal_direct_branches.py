"""Verify direct terminal branches of lexical-exit-free candidates against raw bytes."""
import csv, hashlib, json
from bisect import bisect_right
from collections import Counter
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
def tsv(p):
 with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def sign(v,b):return v-(1<<b) if v&(1<<(b-1)) else v
def main():
 targets={}
 for arch, mnemonics in {'m68k':{'bra.l','bra.s','bra.w'},'sparc':{'ba,a','ba'}}.items():
  binary=(ROOT/'03_original'/arch/'binaries/mach_kernel').read_bytes();inv=json.loads((ROOT/'03_original'/arch/'inventory/macho.json').read_text());sec=next(x for x in inv['sections'] if x['segment']=='__TEXT' and x['name']=='__text');base=int(sec['address'],16);off=int(sec['file_offset'])
  terms=tsv(ROOT/'05_ida/exports'/arch/'noexit-candidate-terminal-items.tsv');funcs=json.loads((ROOT/'05_ida/exports'/arch/'function-asm-index.json').read_text());ranges=sorted((int(x['start'],16),int(x['end'],16),x) for x in funcs);starts=[a for a,_b,_c in ranges]; xrefs=tsv(ROOT/'05_ida/exports'/arch/'xrefs.tsv');xrefset={(int(x['from'],16),int(x['to'],16),x['type'],x['iscode']) for x in xrefs}
  rows=[];relation=Counter()
  for term in terms:
   if term['terminal_mnemonic'] not in mnemonics:continue
   source=int(term['terminal_address'],16); raw=bytes.fromhex(term['terminal_original_bytes']);pos=off+source-base;assert binary[pos:pos+len(raw)]==raw
   if arch=='m68k':
    assert raw[0]==0x60
    if raw[1]==0:disp=sign(int.from_bytes(raw[2:4],'big'),16)
    elif raw[1]==0xff:disp=sign(int.from_bytes(raw[2:6],'big'),32)
    else:disp=sign(raw[1],8)
    target=(source+2+disp)&0xffffffff
   else:
    word=int.from_bytes(raw,'big');disp=sign(word&((1<<22)-1),22);target=(source+(disp<<2))&0xffffffff
   assert (source,target,'19','1') in xrefset
   index=bisect_right(starts,target)-1; target_fun=ranges[index][2] if index>=0 and target<ranges[index][1] else None
   key='outside_candidate_ranges' if target_fun is None else ('same_candidate' if int(term['start'],16)==int(target_fun['start'],16) else 'other_candidate')
   relation[key]+=1
   rows.append({'source_candidate_start':term['start'],'source_candidate_name':term['name'],'branch_address':term['terminal_address'],'original_bytes':raw.hex(),'computed_target':hex(target),'target_relation':key,'target_candidate_start':None if target_fun is None else target_fun['start'],'target_candidate_name':None if target_fun is None else target_fun['name']})
  expected={'m68k':114,'sparc':15}[arch];assert len(rows)==expected
  path=ROOT/'05_ida/exports'/arch/'noexit-terminal-direct-branches.tsv'
  with path.open('w',encoding='utf-8',newline='') as h:w=csv.DictWriter(h,fieldnames=rows[0].keys(),delimiter='\t');w.writeheader();w.writerows(rows)
  targets[arch]={'original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'verified_terminal_direct_branch_count':len(rows),'target_relation_counts':dict(relation),'every_computed_target_matches_type19_xref':True,'tsv':str(path.relative_to(ROOT)),'interpretation_limit':'direct branch target and candidate overlap do not establish path reachability, complete function boundaries, ABI, or behavior'}
 out={'schema':1,'targets':targets,'all_checks_passed':True};(REPORT/'noexit-terminal-direct-branch-audit.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(json.dumps(out,ensure_ascii=False,sort_keys=True))
if __name__=='__main__':main()
