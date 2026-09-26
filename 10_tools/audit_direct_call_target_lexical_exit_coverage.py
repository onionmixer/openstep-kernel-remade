"""Cross raw direct-call targets with lexical-exit candidate classifications."""
import csv, json
from collections import Counter
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
REPORT=ROOT/'09_validation/reports/multiarch-input-20260921'
def tsv(p):
    with p.open(encoding='utf-8',newline='') as h:return list(csv.DictReader(h,delimiter='\t'))
def main():
    targets={}
    for arch in ('m68k','sparc'):
        edges=tsv(ROOT/'05_ida/exports'/arch/'direct-call-edges.tsv')
        candidates=tsv(ROOT/'05_ida/exports'/arch/'function-candidate-lexical-exits.tsv')
        by_start={int(x['start'],16):x for x in candidates}; counts=Counter(); unique=Counter(); reviewed=[]
        for edge in edges:
            target=int(edge['target'],16); c=by_start.get(target)
            key='not_candidate_start' if c is None else ('candidate_with_lexical_exit' if int(c['lexical_exit_count']) else 'candidate_without_lexical_exit')
            counts[key]+=1; unique[(key,target)]+=1
        for (key,target), edge_count in sorted(unique.items()):
            if key=='candidate_without_lexical_exit':
                c=by_start[target];reviewed.append({'target':hex(target),'name':c['name'],'direct_call_edge_count':edge_count,'candidate_end':c['end']})
        targets[arch]={'direct_call_edge_count':len(edges),'target_classification_edge_counts':dict(counts),'unique_direct_call_target_classification_counts':dict(Counter(key for key,_target in unique)),'called_candidate_without_lexical_exit_count':len(reviewed),'called_candidates_without_lexical_exit':reviewed,'interpretation_limit':'lexical exit absence does not prove non-returning behavior or an incorrect boundary; this only prioritizes raw control-flow review'}
    out={'schema':1,'targets':targets,'all_checks_passed':True};(REPORT/'direct-call-target-lexical-exit-coverage.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(json.dumps(out,ensure_ascii=False,sort_keys=True))
if __name__=='__main__':main()
