"""Preserve original-code windows ending in m68k RTE for no-exit candidates."""
import csv,hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
def tsv(p):
 with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def main():
 binary=(ROOT/'03_original/m68k/binaries/mach_kernel').read_bytes();inv=json.loads((ROOT/'03_original/m68k/inventory/macho.json').read_text());sec=next(x for x in inv['sections'] if x['segment']=='__TEXT' and x['name']=='__text');base=int(sec['address'],16);off=int(sec['file_offset'])
 terms=[x for x in tsv(ROOT/'05_ida/exports/m68k/noexit-candidate-terminal-items.tsv') if x['terminal_mnemonic']=='rte'];units=tsv(ROOT/'05_ida/exports/m68k/text-units.tsv');addrs=[int(x['address'],16) for x in units];rows=[]
 for t in terms:
  a=int(t['terminal_address'],16);idx=addrs.index(a);window=units[max(0,idx-2):idx+1];assert window[-1]['bytes']=='4e73'
  checked=[]
  for u in window:
   va=int(u['address'],16);pos=off+va-base;raw=binary[pos:pos+int(u['length'])];assert raw.hex()==u['bytes'] and u['kind']=='code';checked.append({'address':u['address'],'original_bytes':raw.hex(),'ida_disassembly':u['disassembly']})
  rows.append({'candidate_start':t['start'],'candidate_name':t['name'],'candidate_end':t['end'],'window':checked})
 assert len(rows)==8
 out={'schema':1,'architecture':'m68k','original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'terminal_rte_candidate_count':len(rows),'rows':rows,'all_window_code_items_match_original':True,'interpretation_limit':'RTE opcode observation does not establish exception-frame validity, runtime control target, reachability, ABI, or behavior'}
 (REPORT/'m68k-noexit-rte-window-audit.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(json.dumps({'terminal_rte_candidate_count':len(rows),'all_checks_passed':True}))
if __name__=='__main__':main()
