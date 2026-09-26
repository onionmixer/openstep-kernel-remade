"""Audit control-transfer adjacency before terminal nop no-exit candidates."""
import csv,hashlib,json
from collections import Counter
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
def tsv(p):
 with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def sign(v,b):return v-(1<<b) if v&(1<<(b-1)) else v
def main():
 binary=(ROOT/'03_original/sparc/binaries/mach_kernel').read_bytes();inv=json.loads((ROOT/'03_original/sparc/inventory/macho.json').read_text());sec=next(x for x in inv['sections'] if x['segment']=='__TEXT' and x['name']=='__text');base=int(sec['address'],16);off=int(sec['file_offset'])
 terms=[x for x in tsv(ROOT/'05_ida/exports/sparc/noexit-candidate-terminal-items.tsv') if x['terminal_mnemonic']=='nop'];units=tsv(ROOT/'05_ida/exports/sparc/text-units.tsv');addrs=[int(x['address'],16) for x in units];xrefs={(int(x['from'],16),int(x['to'],16),x['type'],x['iscode']) for x in tsv(ROOT/'05_ida/exports/sparc/xrefs.tsv')};rows=[];counts=Counter()
 for t in terms:
  a=int(t['terminal_address'],16);idx=addrs.index(a);prev=units[idx-1];term=units[idx];assert int(prev['address'],16)+int(prev['length'])==a
  for address,u in ((int(prev['address'],16),prev),(a,term)):
   pos=off+address-base;assert binary[pos:pos+int(u['length'])].hex()==u['bytes'] and u['kind']=='code'
  m=prev['disassembly'].split(maxsplit=1)[0];counts[m]+=1;target=None
  if m=='ba':
   word=int(prev['bytes'],16);target=(int(prev['address'],16)+(sign(word&((1<<22)-1),22)<<2))&0xffffffff;assert (int(prev['address'],16),target,'19','1') in xrefs
  rows.append({'candidate_start':t['start'],'candidate_name':t['name'],'preceding_address':prev['address'],'preceding_original_bytes':prev['bytes'],'preceding_ida_disassembly':prev['disassembly'],'nop_address':term['address'],'nop_original_bytes':term['bytes'],'computed_direct_branch_target':None if target is None else hex(target)})
 assert len(rows)==59 and counts==Counter({'jmp':55,'ba':4})
 out={'schema':1,'architecture':'sparc','original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'terminal_nop_count':len(rows),'preceding_control_mnemonic_counts':dict(counts),'rows':rows,'all_window_code_items_match_original':True,'interpretation_limit':'control-transfer adjacency is static delay-slot evidence only and does not establish execution, reachability, return behavior, ABI, or semantics'}
 (REPORT/'sparc-noexit-nop-window-audit.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(json.dumps({'terminal_nop_count':len(rows),'all_checks_passed':True}))
if __name__=='__main__':main()
