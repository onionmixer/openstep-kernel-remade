"""Separate direct and indirect terminal jumps/calls of no-exit candidates."""
import csv,hashlib,json
from collections import Counter
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
def tsv(p):
 with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def sign(v,b):return v-(1<<b) if v&(1<<(b-1)) else v
def main():
 out={}
 for arch,mnem in [('m68k','jmp'),('sparc','call')]:
  binary=(ROOT/'03_original'/arch/'binaries/mach_kernel').read_bytes();inv=json.loads((ROOT/'03_original'/arch/'inventory/macho.json').read_text());sec=next(x for x in inv['sections'] if x['segment']=='__TEXT' and x['name']=='__text');base=int(sec['address'],16);off=int(sec['file_offset'])
  terms=[x for x in tsv(ROOT/'05_ida/exports'/arch/'noexit-candidate-terminal-items.tsv') if x['terminal_mnemonic']==mnem];xrefs={(int(x['from'],16),int(x['to'],16),x['type'],x['iscode']) for x in tsv(ROOT/'05_ida/exports'/arch/'xrefs.tsv')};rows=[];counts=Counter()
  for term in terms:
   src=int(term['terminal_address'],16);raw=bytes.fromhex(term['terminal_original_bytes']);pos=off+src-base;assert binary[pos:pos+len(raw)]==raw
   target=None
   if arch=='m68k' and raw[:2]==b'\x4e\xf9':target=int.from_bytes(raw[2:6],'big');kind='absolute_long_direct_jmp';assert (src,target,'19','1') in xrefs
   elif arch=='m68k':kind='register_indirect_jmp'
   else:
    word=int.from_bytes(raw,'big');assert word>>30==1;target=(src+(sign(word&((1<<30)-1),30)<<2))&0xffffffff;kind='relative_direct_call';assert (src,target,'17','1') in xrefs
   counts[kind]+=1;rows.append({'candidate_start':term['start'],'candidate_name':term['name'],'transfer_address':term['terminal_address'],'original_bytes':raw.hex(),'transfer_kind':kind,'computed_target':None if target is None else hex(target)})
  expected={'m68k':36,'sparc':4}[arch];assert len(rows)==expected
  path=ROOT/'05_ida/exports'/arch/'noexit-terminal-jump-call-transfers.tsv'
  with path.open('w',encoding='utf-8',newline='') as h:w=csv.DictWriter(h,fieldnames=rows[0].keys(),delimiter='\t');w.writeheader();w.writerows(rows)
  out[arch]={'original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'terminal_transfer_count':len(rows),'transfer_kind_counts':dict(counts),'every_direct_target_matches_xref':True,'tsv':str(path.relative_to(ROOT)),'interpretation_limit':'indirect transfers retain unknown runtime targets; direct target encoding does not establish reachability, ABI, values, or behavior'}
 report={'schema':1,'targets':out,'all_checks_passed':True};(REPORT/'noexit-terminal-jump-call-transfer-audit.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n');print(json.dumps(report,ensure_ascii=False,sort_keys=True))
if __name__=='__main__':main()
