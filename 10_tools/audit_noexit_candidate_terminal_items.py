"""Classify the final code item of every lexical-exit-free candidate."""
import csv, hashlib, json
from collections import Counter
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]; REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
def tsv(p):
 with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def main():
 targets={}
 for arch in ('m68k','sparc'):
  binary=(ROOT/'03_original'/arch/'binaries/mach_kernel').read_bytes(); inv=json.loads((ROOT/'03_original'/arch/'inventory/macho.json').read_text()); sec=next(x for x in inv['sections'] if x['segment']=='__TEXT' and x['name']=='__text'); base=int(sec['address'],16); off=int(sec['file_offset'])
  exits=tsv(ROOT/'05_ida/exports'/arch/'function-candidate-lexical-exits.tsv'); units=tsv(ROOT/'05_ida/exports'/arch/'text-units.tsv'); rows=[]; kinds=Counter()
  for candidate in exits:
   if int(candidate['lexical_exit_count']):continue
   start,end=int(candidate['start'],16),int(candidate['end'],16); code=[u for u in units if start<=int(u['address'],16)<end and u['kind']=='code']
   assert code; last=max(code,key=lambda u:int(u['address'],16)); address=int(last['address'],16); pos=off+address-base; assert binary[pos:pos+int(last['length'])].hex()==last['bytes']
   mnemonic=last['disassembly'].split(maxsplit=1)[0] if last['disassembly'] else '' ; kinds[mnemonic]+=1
   rows.append({'start':candidate['start'],'end':candidate['end'],'name':candidate['name'],'terminal_address':last['address'],'terminal_original_bytes':last['bytes'],'terminal_ida_disassembly':last['disassembly'],'terminal_mnemonic':mnemonic})
  expected={'m68k':195,'sparc':139}[arch];assert len(rows)==expected
  path=ROOT/'05_ida/exports'/arch/'noexit-candidate-terminal-items.tsv'
  with path.open('w',encoding='utf-8',newline='') as h:w=csv.DictWriter(h,fieldnames=rows[0].keys(),delimiter='\t');w.writeheader();w.writerows(rows)
  targets[arch]={'original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'candidate_without_lexical_exit_count':len(rows),'terminal_mnemonic_counts':dict(kinds),'every_terminal_code_item_matches_original':True,'tsv':str(path.relative_to(ROOT)),'interpretation_limit':'terminal mnemonic classification is an IDA-disassembly observation; it does not prove reachability, tail-transfer semantics, function boundaries, ABI, or behavior'}
 out={'schema':1,'targets':targets,'all_checks_passed':True};(REPORT/'noexit-candidate-terminal-item-audit.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(json.dumps(out,ensure_ascii=False,sort_keys=True))
if __name__=='__main__':main()
