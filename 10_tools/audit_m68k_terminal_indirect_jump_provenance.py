"""Preserve bounded raw provenance windows for m68k terminal indirect jumps."""
import csv,hashlib,json
from collections import Counter
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
def tsv(p):
 with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def classify(window):
 text=' | '.join(x['ida_disassembly'] for x in window)
 if 'movem.l' in text:return 'register_restore_window'
 if 'movea.l (a1,' in text or 'movea.l (a0,' in text:return 'indexed_memory_load_window'
 if 'movea.l (_' in text:return 'absolute_memory_load_window'
 if 'arg_0(sp),a0' in text:return 'stack_load_window'
 return 'source_not_resolved_in_three_preceding_code_items'
def main():
 binary=(ROOT/'03_original/m68k/binaries/mach_kernel').read_bytes();inv=json.loads((ROOT/'03_original/m68k/inventory/macho.json').read_text());sec=next(x for x in inv['sections'] if x['segment']=='__TEXT' and x['name']=='__text');base=int(sec['address'],16);off=int(sec['file_offset'])
 transfers=[x for x in tsv(ROOT/'05_ida/exports/m68k/noexit-terminal-jump-call-transfers.tsv') if x['transfer_kind']=='register_indirect_jmp'];units=tsv(ROOT/'05_ida/exports/m68k/text-units.tsv');addresses=[int(x['address'],16) for x in units];rows=[];counts=Counter()
 for transfer in transfers:
  source=int(transfer['transfer_address'],16);idx=addresses.index(source);window=units[max(0,idx-3):idx+1]
  assert int(window[-1]['address'],16)==source
  checked=[]
  for u in window:
   a=int(u['address'],16);pos=off+a-base;raw=binary[pos:pos+int(u['length'])];assert raw.hex()==u['bytes'] and u['kind']=='code';checked.append({'address':u['address'],'original_bytes':raw.hex(),'ida_disassembly':u['disassembly']})
  kind=classify(checked[:-1]);counts[kind]+=1
  rows.append({'candidate_start':transfer['candidate_start'],'candidate_name':transfer['candidate_name'],'jump_address':transfer['transfer_address'],'jump_original_bytes':transfer['original_bytes'],'provenance_window_kind':kind,'preceding_code_items':checked[:-1]})
 assert len(rows)==16
 out={'schema':1,'architecture':'m68k','original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'terminal_register_indirect_jump_count':len(rows),'provenance_window_kind_counts':dict(counts),'rows':rows,'every_jump_and_preceding_code_item_matches_original':True,'interpretation_limit':'bounded preceding windows do not resolve runtime register values or jump targets and do not establish reachability, ABI, or semantics'}
 (REPORT/'m68k-terminal-indirect-jump-provenance-audit.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(json.dumps({'terminal_register_indirect_jump_count':len(rows),'all_checks_passed':True}))
if __name__=='__main__':main()
