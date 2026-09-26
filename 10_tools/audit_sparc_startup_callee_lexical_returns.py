"""Check bounded lexical return pairs in SPARC startup callee candidates."""
import csv, hashlib, json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'

def tsv(path):
    with path.open(encoding='utf-8',newline='') as h: return list(csv.DictReader(h,delimiter='\t'))

def main():
    startup=json.loads((REPORT/'startup-direct-call-edge-audit.json').read_text())['targets']['sparc']
    binary=(ROOT/'03_original/sparc/binaries/mach_kernel').read_bytes()
    inv=json.loads((ROOT/'03_original/sparc/inventory/macho.json').read_text())
    text=next(r for r in inv['sections'] if r['segment']=='__TEXT' and r['name']=='__text')
    base=int(text['address'],16); base_off=int(text['file_offset'])
    units=tsv(ROOT/'05_ida/exports/sparc/text-units.tsv'); by={int(r['address'],16):r for r in units}
    funcs={int(r['start'],16):r for r in json.loads((ROOT/'05_ida/exports/sparc/function-asm-index.json').read_text())}
    entries=[]
    for call in startup['calls']:
        start=int(call['target'],16); fun=funcs[start]; end=int(fun['end'],16)
        save=by[start]
        rets=[a for a,r in by.items() if start<=a<end and r['bytes']=='81c7e008']
        assert len(rets)==1
        ret=rets[0]; restore=by[ret+4]
        assert save['bytes']=='9de3bf98' and restore['bytes']=='81e80000'
        for a,r in ((start,save),(ret,by[ret]),(ret+4,restore)):
            o=base_off+a-base
            assert binary[o:o+int(r['length'])].hex()==r['bytes'] and r['kind']=='code'
        entries.append({'target':call['target'],'raw_symbol':call['target_symbol']['name'],'candidate_end':fun['end'],'entry_save_bytes':save['bytes'],'lexical_ret_address':hex(ret),'lexical_ret_bytes':by[ret]['bytes'],'following_restore_bytes':restore['bytes']})
    assert len(entries)==4
    report={'schema':1,'architecture':'sparc','original_sha256_recomputed_with_python':hashlib.sha256(binary).hexdigest(),'startup_callee_count':len(entries),'entries':entries,'all_entry_and_lexical_return_pair_bytes_match_original':True,'conclusion':'each selected candidate contains one lexical ret followed by restore within its current candidate range','interpretation_limit':'this does not establish that every path reaches the pair, runtime return to a particular caller, returned values, ABI, or function semantics'}
    (REPORT/'sparc-startup-callee-lexical-return-audit.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps({'startup_callee_count':len(entries),'all_checks_passed':True}))
if __name__=='__main__': main()
