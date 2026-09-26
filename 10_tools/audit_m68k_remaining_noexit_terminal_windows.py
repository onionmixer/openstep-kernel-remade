"""Preserve raw boundary windows for remaining m68k no-exit terminal forms."""
import csv,hashlib,json
from collections import Counter
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
COVERED={'bra.l','bra.s','bra.w','jmp','bsr.l','rte','jsr'}
def tsv(p):
 with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def main():
 binary=(ROOT/'03_original/m68k/binaries/mach_kernel').read_bytes();inv=json.loads((ROOT/'03_original/m68k/inventory/macho.json').read_text());sec=next(x for x in inv['sections'] if x['segment']=='__TEXT' and x['name']=='__text');base=int(sec['address'],16);off=int(sec['file_offset'])
 terms=[x for x in tsv(ROOT/'05_ida/exports/m68k/noexit-candidate-terminal-items.tsv') if x['terminal_mnemonic'] not in COVERED];units=tsv(ROOT/'05_ida/exports/m68k/text-units.tsv');addrs=[int(x['address'],16) for x in units];rows=[];counts=Counter()
 for t in terms:
  a=int(t['terminal_address'],16);idx=addrs.index(a);prior=[u for u in units[:idx] if u['kind']=='code'][-2:];window=prior+[units[idx]];assert int(window[-1]['address'],16)==a
  checked=[]
  for u in window:
   va=int(u['address'],16);pos=off+va-base;raw=binary[pos:pos+int(u['length'])];assert raw.hex()==u['bytes'] and u['kind']=='code';checked.append({'address':u['address'],'original_bytes':raw.hex(),'ida_disassembly':u['disassembly']})
  end=int(t['end'],16);next_unit=next((u for u in units if int(u['address'],16)==end),None);next_checked=None
  if next_unit:
   pos=off+end-base;raw=binary[pos:pos+int(next_unit['length'])];assert raw.hex()==next_unit['bytes'];next_checked={'address':next_unit['address'],'kind':next_unit['kind'],'original_bytes':raw.hex(),'ida_disassembly':next_unit['disassembly']}
  counts[t['terminal_mnemonic']]+=1;rows.append({'candidate_start':t['start'],'candidate_end':t['end'],'candidate_name':t['name'],'terminal_mnemonic':t['terminal_mnemonic'],'window':checked,'item_at_candidate_end':next_checked})
 assert len(rows)==14
 out={'schema':1,'architecture':'m68k','original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'remaining_terminal_window_count':len(rows),'terminal_mnemonic_counts':dict(counts),'rows':rows,'all_window_and_candidate_end_items_match_original':True,'interpretation_limit':'bounded code windows and candidate-end adjacency do not establish transfer semantics, reachability, function boundaries, ABI, or behavior'}
 (REPORT/'m68k-remaining-noexit-terminal-window-audit.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(json.dumps({'remaining_terminal_window_count':len(rows),'all_checks_passed':True}))
if __name__=='__main__':main()
