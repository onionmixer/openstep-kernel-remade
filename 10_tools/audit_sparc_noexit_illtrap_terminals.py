"""Verify raw terminal illtrap code items of SPARC no-exit candidates."""
import csv,hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
def tsv(p):
 with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def main():
 binary=(ROOT/'03_original/sparc/binaries/mach_kernel').read_bytes();inv=json.loads((ROOT/'03_original/sparc/inventory/macho.json').read_text());sec=next(x for x in inv['sections'] if x['segment']=='__TEXT' and x['name']=='__text');base=int(sec['address'],16);off=int(sec['file_offset'])
 terms=[x for x in tsv(ROOT/'05_ida/exports/sparc/noexit-candidate-terminal-items.tsv') if x['terminal_mnemonic']=='illtrap'];rows=[]
 for t in terms:
  a=int(t['terminal_address'],16);raw=bytes.fromhex(t['terminal_original_bytes']);pos=off+a-base;assert binary[pos:pos+len(raw)]==raw and len(raw)==4
  rows.append({'candidate_start':t['start'],'candidate_end':t['end'],'candidate_name':t['name'],'illtrap_address':t['terminal_address'],'original_instruction_word':raw.hex(),'ida_disassembly':t['terminal_ida_disassembly']})
 assert len(rows)==9
 out={'schema':1,'architecture':'sparc','original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'terminal_illtrap_candidate_count':len(rows),'rows':rows,'all_illtrap_code_items_match_original':True,'interpretation_limit':'illtrap opcode observation does not establish trap handling, runtime reachability, control target, ABI, or behavior'}
 (REPORT/'sparc-noexit-illtrap-terminal-audit.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(json.dumps({'terminal_illtrap_candidate_count':len(rows),'all_checks_passed':True}))
if __name__=='__main__':main()
