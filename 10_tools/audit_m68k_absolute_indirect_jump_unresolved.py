"""Record why two m68k terminal indirect jump targets remain unresolved."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
def main():
 binary=(ROOT/'03_original/m68k/binaries/mach_kernel').read_bytes();inv=json.loads((ROOT/'03_original/m68k/inventory/macho.json').read_text());prov=json.loads((REPORT/'m68k-terminal-indirect-jump-provenance-audit.json').read_text())
 rows={x['candidate_name']:x for x in prov['rows']};call=rows['_call_continuation'];mon=rows['_mon_exit'];common=next(s for s in inv['sections'] if s['segment']=='__DATA' and s['name']=='__common');rv=0x40b57c8;start=int(common['address'],16);assert start<=rv<start+int(common['size']) and common['file_offset']==0
 out={'schema':1,'architecture':'m68k','original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'stack_fed_jump':{'candidate':call['candidate_name'],'jump_address':call['jump_address'],'window':call['preceding_code_items'],'conclusion':'the terminal a0 jump follows an observed stack-derived a0 load'},'common_backed_jump':{'candidate':mon['candidate_name'],'jump_address':mon['jump_address'],'global_address':hex(rv),'common_section':common,'conclusion':'the terminal a0 jump follows an observed _reboot_vector load, but the global is in non-file-backed __common'},'required_disposition':'retain both runtime jump targets as unresolved from original file bytes alone','interpretation_limit':'this does not establish runtime values, targets, reachability, ABI, or behavior'}
 (REPORT/'m68k-absolute-indirect-jump-unresolved-audit.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(json.dumps({'all_checks_passed':True}))
if __name__=='__main__':main()
