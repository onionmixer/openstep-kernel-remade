"""Check bounded lexical UNLK/RTS pairs in m68k startup callee candidates."""
import csv, hashlib, json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
def tsv(p):
    with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def main():
    calls=json.loads((REPORT/'startup-direct-call-edge-audit.json').read_text())['targets']['m68k']['calls']
    binary=(ROOT/'03_original/m68k/binaries/mach_kernel').read_bytes(); inv=json.loads((ROOT/'03_original/m68k/inventory/macho.json').read_text())
    sec=next(x for x in inv['sections'] if x['segment']=='__TEXT' and x['name']=='__text'); base=int(sec['address'],16); off=int(sec['file_offset'])
    units=tsv(ROOT/'05_ida/exports/m68k/text-units.tsv'); by={int(x['address'],16):x for x in units}; funcs={int(x['start'],16):x for x in json.loads((ROOT/'05_ida/exports/m68k/function-asm-index.json').read_text())}
    rows=[]
    for call in calls:
        start=int(call['target'],16); fun=funcs[start]; end=int(fun['end'],16); rts=[a for a,r in by.items() if start<=a<end and r['bytes']=='4e75']
        assert len(rts)==1; rts=rts[0]; unlk=by[rts-2]; entry=by[start]
        assert unlk['bytes']=='4e5e'
        for a,r in ((start,entry),(rts-2,unlk),(rts,by[rts])):
            pos=off+a-base; assert binary[pos:pos+int(r['length'])].hex()==r['bytes'] and r['kind']=='code'
        rows.append({'target':call['target'],'raw_symbol':call['target_symbol']['name'],'candidate_end':fun['end'],'entry_bytes':entry['bytes'],'lexical_unlk_address':hex(rts-2),'lexical_unlk_bytes':unlk['bytes'],'lexical_rts_address':hex(rts),'lexical_rts_bytes':by[rts]['bytes']})
    assert len(rows)==4
    out={'schema':1,'architecture':'m68k','original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'startup_callee_count':4,'entries':rows,'all_entry_and_lexical_return_pair_bytes_match_original':True,'conclusion':'each selected candidate contains one lexical UNLK/RTS pair within its current candidate range','interpretation_limit':'this does not establish that every path reaches the pair, runtime return to a particular caller, return values, ABI, or function semantics'}
    (REPORT/'m68k-startup-callee-lexical-return-audit.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(json.dumps({'startup_callee_count':4,'all_checks_passed':True}))
if __name__=='__main__':main()
