"""Audit terminal restore/return windows of SPARC no-exit candidates."""
import csv,hashlib,json
from collections import Counter
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
def tsv(p):
 with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def sign(v,b):return v-(1<<b) if v&(1<<(b-1)) else v
def main():
 binary=(ROOT/'03_original/sparc/binaries/mach_kernel').read_bytes();inv=json.loads((ROOT/'03_original/sparc/inventory/macho.json').read_text());sec=next(x for x in inv['sections'] if x['segment']=='__TEXT' and x['name']=='__text');base=int(sec['address'],16);off=int(sec['file_offset'])
 terms=[x for x in tsv(ROOT/'05_ida/exports/sparc/noexit-candidate-terminal-items.tsv') if x['terminal_mnemonic'] in {'restore','return'}];units=tsv(ROOT/'05_ida/exports/sparc/text-units.tsv');addrs=[int(x['address'],16) for x in units];xrefs={(int(x['from'],16),int(x['to'],16),x['type'],x['iscode']) for x in tsv(ROOT/'05_ida/exports/sparc/xrefs.tsv')};rows=[];preds=Counter()
 for term in terms:
  a=int(term['terminal_address'],16);idx=addrs.index(a);previous=units[idx-1];terminal=units[idx];assert int(previous['address'],16)+int(previous['length'])==a
  for address,u in ((int(previous['address'],16),previous),(a,terminal)):
   pos=off+address-base;assert binary[pos:pos+int(u['length'])].hex()==u['bytes'] and u['kind']=='code'
  pred=previous['disassembly'].split(maxsplit=1)[0];preds[pred]+=1;branch_target=None
  if pred.startswith('ba'):
   word=int(previous['bytes'],16);branch_target=(int(previous['address'],16)+(sign(word&((1<<22)-1),22)<<2))&0xffffffff;assert (int(previous['address'],16),branch_target,'19','1') in xrefs
  rows.append({'candidate_start':term['start'],'candidate_name':term['name'],'terminal_mnemonic':term['terminal_mnemonic'],'preceding_address':previous['address'],'preceding_original_bytes':previous['bytes'],'preceding_ida_disassembly':previous['disassembly'],'terminal_address':terminal['address'],'terminal_original_bytes':terminal['bytes'],'terminal_ida_disassembly':terminal['disassembly'],'computed_direct_branch_target':None if branch_target is None else hex(branch_target)})
 assert len(rows)==13 and preds==Counter({'jmp':12,'ba':1})
 out={'schema':1,'architecture':'sparc','original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'terminal_restore_or_return_count':len(rows),'preceding_control_mnemonic_counts':dict(preds),'rows':rows,'all_window_code_items_match_original':True,'interpretation_limit':'adjacency to a control transfer is static delay-slot evidence only; it does not establish architectural execution, reachability, return behavior, ABI, or semantics'}
 (REPORT/'sparc-noexit-restore-return-window-audit.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(json.dumps({'terminal_restore_or_return_count':len(rows),'all_checks_passed':True}))
if __name__=='__main__':main()
