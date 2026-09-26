"""Make the remaining no-exit terminal review queue explicit from raw terminal items."""
import csv,hashlib,json
from collections import Counter
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
COVERED={'m68k':{'bra.l','bra.s','bra.w','jmp','bsr.l','rte'},'sparc':{'ba,a','ba','call','restore','return','nop','illtrap'}}
def tsv(p):
 with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def main():
 targets={}
 for arch in ('m68k','sparc'):
  binary=(ROOT/'03_original'/arch/'binaries/mach_kernel').read_bytes();inv=json.loads((ROOT/'03_original'/arch/'inventory/macho.json').read_text());sec=next(x for x in inv['sections'] if x['segment']=='__TEXT' and x['name']=='__text');base=int(sec['address'],16);off=int(sec['file_offset'])
  terms=tsv(ROOT/'05_ida/exports'/arch/'noexit-candidate-terminal-items.tsv');remaining=[];covered=Counter()
  for t in terms:
   a=int(t['terminal_address'],16);raw=bytes.fromhex(t['terminal_original_bytes']);pos=off+a-base;assert binary[pos:pos+len(raw)]==raw
   if t['terminal_mnemonic'] in COVERED[arch]:covered[t['terminal_mnemonic']]+=1
   else:remaining.append(t)
  expected={'m68k':195,'sparc':139}[arch];assert len(terms)==expected
  path=ROOT/'05_ida/exports'/arch/'noexit-terminal-review-queue.tsv'
  with path.open('w',encoding='utf-8',newline='') as h:w=csv.DictWriter(h,fieldnames=remaining[0].keys(),delimiter='\t');w.writeheader();w.writerows(remaining)
  targets[arch]={'original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'noexit_terminal_candidate_count':len(terms),'specialized_terminal_review_count':sum(covered.values()),'specialized_terminal_mnemonic_counts':dict(covered),'remaining_terminal_review_count':len(remaining),'remaining_terminal_mnemonic_counts':dict(Counter(x['terminal_mnemonic'] for x in remaining)),'every_terminal_item_matches_original':True,'remaining_queue_tsv':str(path.relative_to(ROOT)),'interpretation_limit':'coverage counts track bounded static audits only and do not prove function boundaries, reachability, ABI, or semantics'}
 out={'schema':1,'targets':targets,'all_checks_passed':True};(REPORT/'noexit-terminal-analysis-coverage-audit.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(json.dumps(out,ensure_ascii=False,sort_keys=True))
if __name__=='__main__':main()
