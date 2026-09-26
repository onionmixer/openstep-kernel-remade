import json, re, collections, csv, base64, struct
from pathlib import Path
R=Path('/mnt/USERS/onion/DATA_ORIGN/Workspace/NeXT_DRIVER/openstep-kernel-remade');G=R/'04_ghidra/exports/x86/full-pass5'
fs=json.loads((G/'functions.json').read_text());fm={int(x['address'],16):x for x in fs}
high=[json.loads(l) for l in Path('/tmp/openstep-ghidra-review/functions.jsonl').read_text().splitlines()]
hm={int(x['entry'],16):x for x in high}
listing={int(a,16):(int(n),s) for a,n,s in (line.split('\t',2) for line in (G/'whole-program.asm').read_text().splitlines())}
units={int(x['start'],16):x for x in csv.DictReader((G/'code-units.tsv').open(),delimiter='\t')}
heads={a for a,x in units.items() if x['kind']=='instruction'}
allpc=set();alltokens=set();offcut=[];outsidebody=[];tables=collections.defaultdict(set);tableusers=collections.defaultdict(set)
for row in high:
 entry=int(row['entry'],16);f=fm[entry];pc={int(a,16) for a in row.get('pcode_addresses',[]) if re.fullmatch('[0-9a-fA-F]+',a)}
 tok={int(a,16) for a in row.get('c_token_addresses',[]) if re.fullmatch('[0-9a-fA-F]+',a)}
 allpc|=pc;alltokens|=tok
 body=set()
 for b in f['body']:body.update(range(int(b['start'],16),int(b['end_inclusive'],16)+1))
 bad=pc-heads
 if bad:offcut.append({'entry':hex(entry),'name':f['name'],'fragment':f['analysis_fragment'],'addresses':[hex(a) for a in sorted(bad)]})
 if pc-body:outsidebody.append({'entry':hex(entry),'name':f['name'],'fragment':f['analysis_fragment'],'outside_body_addresses':[hex(a) for a in sorted(pc-body)]})
 for t in row.get('jump_tables',[]):
  a=int(t['switch'],16);tables[a].update(int(c,16) for c in t['cases']);tableusers[a].add(entry)
fragbody_missing=[]
for f in fs:
 if not f['analysis_fragment']:continue
 entry=int(f['address'],16);own=[a for b in f['body'] for a in range(int(b['start'],16),int(b['end_inclusive'],16)+1) if a in heads]
 absent=[a for a in sorted(own) if a not in allpc]
 if absent:fragbody_missing.append({'entry':hex(entry),'name':f['name'],'absent_from_all_high_pcode':[{'address':hex(a),'assembly':listing[a][1]} for a in absent]})
audit=json.loads(Path('/tmp/openstep-deep-review.json').read_text());indirect=[x for x in audit['indirect'] if not x['call']]
unresolved=[x for x in indirect if int(x['from'],16) not in tables]
orphancases=[{'switch':hex(a),'target':hex(t)} for a,targets in tables.items() for t in targets if t not in heads]
# Data-owned areas inside __text: find pointer words naming entry blocks not represented in any high pcode.
meta=json.loads((R/'03_original/x86/inventory/macho.json').read_text());raw=(R/'03_original/x86/binaries/mach_kernel').read_bytes();sec=next(s for s in meta['sections'] if s['name']=='__text');lo=int(sec['address'],16);hi=lo+sec['size'];offset=sec['file_offset']
pointer_cases=[]
for a,u in units.items():
 if not lo<=a<hi or u['kind']!='data':continue
 for p in range(a,int(u['end_inclusive'],16)-2,4):
  target=struct.unpack_from('<I',raw,offset+p-lo)[0]
  if target in heads and target not in allpc:
   pointer_cases.append({'pointer':hex(p),'target':hex(target),'assembly':listing[target][1]})
result={'counts':{'high_functions':len(high),'high_failed':sum(not x['completed'] for x in high),'functions_with_pcode_not_at_listing_instruction_head':len(offcut),'unique_pcode_not_at_listing_instruction_head':len(allpc-heads),'functions_with_pcode_outside_declared_body':len(outsidebody),'synthetic_fragments_with_some_instructions_absent_from_all_high_pcode':len(fragbody_missing),'indirect_jumps':len(indirect),'indirect_jumps_with_no_high_jumptable':len(unresolved),'high_jumptable_switch_sites':len(tables),'high_jumptable_noninstruction_targets':len(orphancases),'data_code_pointers_to_heads_not_in_any_high_pcode':len(pointer_cases)},'offcut_pcode':offcut,'outside_body_pcode':outsidebody,'fragment_missing_pcode':fragbody_missing,'unresolved_indirect_jumps':unresolved,'jumptable_targets_not_instructions':orphancases,'pointer_cases_not_in_high_pcode':pointer_cases,'noreturn_functions':[{'entry':x['entry'],'name':x['name']} for x in high if x['noreturn']], 'caveat':'Absent high pcode or token mapping is not proof of missing semantics: optimization can remove/fold instructions. Offcut pcode and entry-context mismatches require review.'}
Path('/tmp/openstep-deep-review-pcode.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({'counts':result['counts'],'offcut':offcut,'noreturn':result['noreturn_functions'],'pointer_examples':pointer_cases[:20]},indent=2))
