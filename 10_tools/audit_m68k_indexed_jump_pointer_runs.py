"""Record conservative raw pointer runs behind indexed terminal indirect jumps."""
import csv,hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
def tsv(p):
 with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def main():
 binary=(ROOT/'03_original/m68k/binaries/mach_kernel').read_bytes();inv=json.loads((ROOT/'03_original/m68k/inventory/macho.json').read_text());sec=next(x for x in inv['sections'] if x['segment']=='__TEXT' and x['name']=='__text');base=int(sec['address'],16);off=int(sec['file_offset']);end=base+int(sec['size'])
 units=tsv(ROOT/'05_ida/exports/m68k/text-units.tsv');code_starts={int(x['address'],16) for x in units if x['kind']=='code'};provenance=json.loads((REPORT/'m68k-terminal-indirect-jump-provenance-audit.json').read_text())
 rows=[]
 for item in provenance['rows']:
  if item['provenance_window_kind']!='indexed_memory_load_window':continue
  lea=next(x for x in item['preceding_code_items'] if x['ida_disassembly'].startswith('lea'));lea_raw=bytes.fromhex(lea['original_bytes']);table=int.from_bytes(lea_raw[-4:],'big');values=[]
  for index in range(512):
   pos=off+table-base+4*index
   if not off<=pos+4<=off+(end-base):break
   value=int.from_bytes(binary[pos:pos+4],'big')
   if value not in code_starts:break
   values.append({'index':index,'file_offset':pos,'raw_big_endian_word':f'{value:08x}','code_item_start':hex(value)})
  assert values
  rows.append({'candidate_start':item['candidate_start'],'candidate_name':item['candidate_name'],'jump_address':item['jump_address'],'lea_address':lea['address'],'lea_original_bytes':lea_raw.hex(),'raw_pointer_run_base':hex(table),'contiguous_code_start_word_count':len(values),'words':values})
 assert len(rows)==8
 report={'schema':1,'architecture':'m68k','original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'indexed_terminal_jump_count':len(rows),'contiguous_code_start_word_total':sum(x['contiguous_code_start_word_count'] for x in rows),'rows':rows,'all_pointer_words_and_target_code_starts_match_original':True,'interpretation_limit':'a contiguous code-start pointer run is not proven to be a complete dispatch table; index bounds, selected runtime target, reachability, ABI, and behavior remain unproven'}
 (REPORT/'m68k-indexed-jump-pointer-run-audit.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n');print(json.dumps({'indexed_terminal_jump_count':len(rows),'contiguous_code_start_word_total':report['contiguous_code_start_word_total'],'all_checks_passed':True}))
if __name__=='__main__':main()
