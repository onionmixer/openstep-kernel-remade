import csv, json, re, hashlib, collections, bisect
from pathlib import Path
import capstone
from capstone.x86_const import X86_OP_IMM

R=Path('/mnt/USERS/onion/DATA_ORIGN/Workspace/NeXT_DRIVER/openstep-kernel-remade')
G=R/'04_ghidra/exports/x86/full-pass5'
def j(p): return json.loads(p.read_text())
meta=j(R/'03_original/x86/inventory/macho.json'); raw=(R/'03_original/x86/binaries/mach_kernel').read_bytes()
sec=next(s for s in meta['sections'] if s['name']=='__text'); lo=int(sec['address'],16); hi=lo+sec['size']; off=sec['file_offset']
funcs=j(G/'functions.json'); fmap={int(f['address'],16):f for f in funcs}
units=list(csv.DictReader((G/'code-units.tsv').open(),delimiter='\t'))
listing={int(a,16):(int(n),t) for a,n,t in (line.split('\t',2) for line in (G/'whole-program.asm').read_text().splitlines())}
kind=bytearray(sec['size']); heads={}; owners=collections.defaultdict(list)
for row in units:
 a=int(row['start'],16);z=int(row['end_inclusive'],16)+1
 if lo<=a<hi:
  kind[a-lo:z-lo]=bytes([{'instruction':1,'data':2,'undefined':3}[row['kind']]])*(z-a)
  heads[a]=row
for f in funcs:
 for r in f['body']:
  for a in range(int(r['start'],16),int(r['end_inclusive'],16)+1): owners[a].append(int(f['address'],16))
def owner(a): return [{'address':hex(x),'name':fmap[x]['name'],'fragment':fmap[x]['analysis_fragment']} for x in owners.get(a,[])]
def loc(a):
 if not lo<=a<hi:return {'address':hex(a),'kind':'outside_text','owners':owner(a)}
 return {'address':hex(a),'kind':{0:'unrepresented',1:'instruction',2:'data',3:'undefined'}[kind[a-lo]],'head':a in heads,'owners':owner(a)}
cs=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);cs.detail=True
decoded={};decode_errors=[];length_mismatch=[];direct=[];indirect=[];fallthrough=[]
for a,row in heads.items():
 if row['kind']!='instruction':continue
 ins=next(cs.disasm(raw[off+a-lo:off+a-lo+15],a,count=1),None)
 if not ins:decode_errors.append({'address':hex(a),'ghidra':listing[a]});continue
 decoded[a]=ins
 if ins.size!=int(row['length']):length_mismatch.append({'address':hex(a),'ghidra':listing[a],'capstone':[ins.size,ins.mnemonic,ins.op_str],'bytes':ins.bytes.hex()})
 isjump=ins.group(capstone.CS_GRP_JUMP);iscall=ins.group(capstone.CS_GRP_CALL)
 if isjump or iscall:
  event={'from':hex(a),'instruction':ins.mnemonic+' '+ins.op_str,'owners':owner(a),'call':iscall}
  if ins.operands and ins.operands[0].type==X86_OP_IMM:
   target_operand = ins.operands[-1] if ins.mnemonic in ('ljmp','lcall') else ins.operands[0]
   event['target']=loc(target_operand.imm & 0xffffffff)
   if ins.mnemonic in ('ljmp','lcall'): event['far_segment_selector']=hex(ins.operands[0].imm)
   direct.append(event)
  else:indirect.append(event)
 if not ins.group(capstone.CS_GRP_RET) and not ins.group(capstone.CS_GRP_IRET) and ins.mnemonic not in ('jmp','ljmp','ud2'):
  nxt=a+ins.size
  if lo<=nxt<hi and (kind[nxt-lo]!=1 or nxt not in heads or set(owners.get(a,[]))!=set(owners.get(nxt,[]))):
   fallthrough.append({'from':hex(a),'instruction':ins.mnemonic+' '+ins.op_str,'owners':owner(a),'next':loc(nxt)})
warnfiles=[];warning_categories=collections.Counter();removed=set();removed_context=[];patterns=collections.defaultdict(list)
for f in funcs:
 text=(G/'functions'/f'{int(f["address"],16):08x}.c').read_text()
 ws=re.findall(r'WARNING: ([^\n]*)',text)
 if ws:warnfiles.append(f['address'])
 for w in ws:warning_categories[re.sub(r'0x[0-9a-fA-F]+','<address>',w).strip(' */')]+=1
 unreachable=re.findall(r'Removing unreachable block \(ram,0x([0-9a-fA-F]+)\)',text)
 for a in unreachable:removed.add(int(a,16))
 if unreachable:removed_context.append({'function':f['address'],'name':f['name'],'fragment':f['analysis_fragment'],'addresses':sorted(set('0x'+a for a in unreachable))})
 for label,pattern in [('halt_baddata',r'\bhalt_baddata\b'),('unaff',r'\bunaff_\w+'),('in_register',r'\bin_(?:EAX|EBX|ECX|EDX|ESI|EDI|EBP|ESP|[A-Z]+)\b'),('uninitialized_stack',r'\bin_stack_\w+'),('indirect_call',r'\(\*'),('undefined_type',r'\bundefined\d*\b')]:
  if re.search(pattern,text):patterns[label].append(f['address'])
 before_body=text[text.find('{')+1:text.rfind('}')]
 stripped=re.sub(r'/\*.*?\*/','',before_body,flags=re.S).strip()
 if not stripped or stripped=='return;':patterns['empty_or_return_only'].append(f['address'])
refs=list(csv.DictReader((G/'references.tsv').open(),delimiter='\t'))
refedges={(int(x['from'],16),int(x['to'],16)) for x in refs if re.fullmatch(r'0x[0-9a-fA-F]+',x['from']) and re.fullmatch(r'0x[0-9a-fA-F]+',x['to'])}
no_ref=[x for x in direct if (int(x['from'],16),int(x['target']['address'],16)) not in refedges]
badtargets=[x for x in direct if x['target']['kind']!='instruction' or not x['target'].get('head')]
crossfunc=[x for x in direct if not x['call'] and x['owners'] and x['target']['owners'] and not {r['address'] for r in x['owners']} & {r['address'] for r in x['target']['owners']}]
badfall=[x for x in fallthrough if x['next']['kind']!='instruction' or not x['next'].get('head')]
fragcalls=[x for x in direct if x['call'] and any(o['fragment'] for o in x['target']['owners'])]
overlap=[hex(a) for a,own in owners.items() if len(own)>1]
dataowned=[hex(a) for a,own in owners.items() if lo<=a<hi and kind[a-lo]!=1]
unknown=[loc(a) for a,row in heads.items() if row['kind']=='instruction' and not owners.get(a)]
result={'sha256':hashlib.sha256(raw).hexdigest(),'counts':{'functions':len(funcs),'decoded_instruction_heads':len(decoded),'decode_errors':len(decode_errors),'length_mismatch':len(length_mismatch),'direct_branches_calls':len(direct),'indirect_branches_calls':len(indirect),'suspicious_direct_targets':len(badtargets),'cross_function_jumps':len(crossfunc),'suspicious_fallthrough':len(badfall),'changed_owner_fallthrough':len(fallthrough),'missing_reference_edges':len(no_ref),'calls_into_fragments':len(fragcalls),'multiple_owner_bytes':len(overlap),'owned_noninstruction_bytes':len(dataowned),'orphan_instruction_heads':len(unknown),'warning_files':len(warnfiles),'unreachable_warning_files':len(removed_context),'unreachable_warning_unique_addresses':len(removed)},'decode_errors':decode_errors,'length_mismatch':length_mismatch,'bad_targets':badtargets,'cross_function_jumps':crossfunc,'indirect':indirect,'fallthrough':fallthrough,'bad_fallthrough':badfall,'missing_reference_edges':no_ref,'calls_into_fragments':fragcalls,'multiple_owner_bytes':overlap,'owned_noninstruction_bytes':dataowned,'orphan_instruction_heads':unknown,'warning_categories':dict(warning_categories),'unreachable':removed_context,'patterns':dict(patterns)}
Path('/tmp/openstep-deep-review.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({'counts':result['counts'],'warning_categories':result['warning_categories'],'patterns':{k:len(v) for k,v in patterns.items()},'bad_targets':badtargets[:25],'bad_fallthrough':badfall[:15]},indent=2))
