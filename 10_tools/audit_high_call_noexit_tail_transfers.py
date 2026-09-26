"""Audit two high-frequency direct-call candidates without lexical returns."""
import csv, hashlib, json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]; REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
CASES={'m68k':{'start':0x400165e,'branch':0x40016ca,'bytes':'60ff0000016a','target':0x4001836},'sparc':{'start':0xf0006600,'branch':0xf0006600,'bytes':'1080000b','target':0xf000662c}}
def tsv(p):
 with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def sign(v,b):return v-(1<<b) if v&(1<<(b-1)) else v
def main():
 out={}
 for arch,c in CASES.items():
  bin=(ROOT/'03_original'/arch/'binaries/mach_kernel').read_bytes(); inv=json.loads((ROOT/'03_original'/arch/'inventory/macho.json').read_text()); sec=next(x for x in inv['sections'] if x['segment']=='__TEXT' and x['name']=='__text'); base=int(sec['address'],16); off=int(sec['file_offset'])
  funcs=json.loads((ROOT/'05_ida/exports'/arch/'function-asm-index.json').read_text()); fun=next(x for x in funcs if int(x['start'],16)==c['start']); target_fun=next((x for x in funcs if int(x['start'],16)<=c['target']<int(x['end'],16)),None)
  units={int(x['address'],16):x for x in tsv(ROOT/'05_ida/exports'/arch/'text-units.tsv')}; unit=units[c['branch']]; pos=off+c['branch']-base; raw=bin[pos:pos+int(unit['length'])]; assert raw.hex()==c['bytes']==unit['bytes']
  if arch=='m68k':computed=(c['branch']+2+sign(int.from_bytes(raw[2:6],'big'),32))&0xffffffff
  else:computed=(c['branch']+(sign(int.from_bytes(raw,'big')&((1<<22)-1),22)<<2))&0xffffffff
  assert computed==c['target']
  x=[r for r in tsv(ROOT/'05_ida/exports'/arch/'xrefs.tsv') if int(r['from'],16)==c['branch'] and int(r['to'],16)==c['target']];assert len(x)==1 and x[0]['type']=='19' and x[0]['iscode']=='1'
  out[arch]={'original_sha256_recomputed_with_python':hashlib.sha256(bin).hexdigest(),'candidate':{k:fun[k] for k in ('start','end','name')},'tail_branch':{'address':hex(c['branch']),'original_bytes':raw.hex(),'computed_target':hex(computed),'xref':x[0]},'target_containing_candidate':None if target_fun is None else {k:target_fun[k] for k in ('start','end','name')},'interpretation_limit':'a tail branch explains lexical return absence for this candidate but does not establish behavior, ABI, values, or the semantics of the target'}
 report={'schema':1,'targets':out,'all_checks_passed':True};(REPORT/'high-call-noexit-tail-transfer-audit.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n');print(json.dumps({'all_checks_passed':True},ensure_ascii=False))
if __name__=='__main__':main()
