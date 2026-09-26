"""Independent modular arithmetic/branch/write contract, not a full x86 emulator."""
import json
import struct
import sys
import capstone
import inputs as I

MASK=(1<<32)-1
CS=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
CS.detail=True
CODE={i.address:i for i in CS.disasm(I.original(I.ENTRY,0x1913eb-I.ENTRY),I.ENTRY)}


def trace_contract(c,e):
    # Single synthetic node and empty free queues: no subroutine is entered.
    choices={0x191154:c['last']!=0,0x191174:e['delta']<=1,0x191188:False,
        0x1911b1:True,0x1911fc:True,0x191274:e['index']<=4,
        0x1912b4:c['wired']!=0,0x1912be:not c['pde']&1,
        0x1912cd:e['delta']<=0,0x1912d5:bool(c['pde']&0x20),
        0x1912eb:c['age']>e['age'],0x1912f0:e['threshold'] is not None and e['threshold']>=e['age'],
        0x1913ba:not c['pde']&0x20}
    pc=I.ENTRY;heads=[];active_tests=0
    while pc not in (I.DECISION,I.STOP):
        ins=CODE[pc];heads.append(pc)
        assert len(heads)<512
        if pc==0x191283 and not e['mapped']:break
        if pc==0x191299:
            active_tests+=1
            taken=not c['active'] or active_tests>1
            pc=ins.operands[0].imm if taken else pc+ins.size
        elif pc in choices:pc=ins.operands[0].imm if choices[pc] else pc+ins.size
        elif ins.mnemonic=='jmp':pc=ins.operands[0].imm
        elif ins.mnemonic=='ret':pc=I.STOP
        else:
            assert not ins.group(capstone.CS_GRP_JUMP) and ins.mnemonic!='call',hex(pc)
            pc+=ins.size
    return heads


def cmp_bits(a,b,width):
    mask=(1<<width)-1;sign=1<<(width-1)
    a&=mask;b&=mask;r=(a-b)&mask
    bits={0:a<b,2:(r&0xff).bit_count()%2==0,4:bool((a^b^r)&0x10),
          6:r==0,7:bool(r&sign),11:bool((a^b)&(a^r)&sign)}
    return sum(int(v)<<k for k,v in bits.items()),sum(1<<k for k in bits)


def expected(c):
    initial=c['tick'] if c['last']==0 else c['last']
    raw_delta=(c['tick']-initial)&MASK
    delta=raw_delta if raw_delta < (1<<31) else raw_delta-(1<<32)
    index=delta//8  # Python floor division equals signed arithmetic shift here.
    address=0x1e2610 if index>4 else (0x1e2600+index*4)&MASK
    mapped=0x100000<=address and address+4<=0x300000
    threshold=struct.unpack('<I',I.original(address,4))[0] if mapped else None
    age,pde=c['age'],c['pde']
    remove=False
    if mapped and c['active']:
        if c['wired']!=0 or not pde&1:age=0
        elif pde&0x20:age=0;pde &= ~0x20
        elif delta>0:
            age=(age+(raw_delta&0xff))&0xff
            remove=c['age']>age or age>threshold
    outcome='execution_error' if not mapped else ('remove_decision' if remove else 'returned')
    last=(initial+raw_delta)&MASK if outcome=='returned' else initial
    return dict(delta=delta,raw_delta=raw_delta,index=index,address=address,threshold=threshold,
        mapped=mapped,age=age,pde=pde,last=last,outcome=outcome,free_queue_gate=delta>1,
        outside_declared_table=index<0)


def check(row):
    c=row['input'];e=expected(c)
    assert all(type(c[k]) is int and 0<=c[k]<=MASK for k in ('last','tick','pde','second_pde'))
    assert type(c['age']) is int and 0<=c['age']<=0xff
    assert type(c['wired']) is int and 0<=c['wired']<=0xffff
    assert type(c['active']) is bool
    assert row['outcome']==e['outcome']
    assert {k:row['after'][k] for k in ('age','pde','last')} == {k:e[k] for k in ('age','pde','last')}
    assert row['after']['second_pde']==c['second_pde']
    trace=row['trace']
    assert trace==trace_contract(c,e), 'original branch path mismatch'
    assert trace[0]==I.ENTRY and len(trace)<512
    assert (0x19117c in trace)==e['free_queue_gate']
    assert (0x191276 in trace)==(e['index']>4)
    assert (0x191283 in trace)==(e['index']<=4)
    assert (0x1913db in trace)==(e['outcome']=='returned')
    assert I.DECISION not in trace  # It is the unexecuted stop head.
    points={p['pc']:p['cpu'] for p in row['points']}
    required={0x191171,0x191174,0x191274,0x191283,0x191276,0x19128a,0x1912af,0x1912be,
              0x1912cd,0x1912d5,0x1912eb,0x1912f0,0x1913db}
    assert [p['pc'] for p in row['points']]==[pc for pc in trace if pc in required]
    for point in row['points']:
        cpu=point['cpu']
        assert cpu['eip']==point['pc']
        assert cpu['ebp']==I.STACK-4 and cpu['esp']==I.STACK-0x28
    assert points[0x191171]['ebx']==e['raw_delta']
    assert points[0x191174]['ebx']==e['raw_delta'], 'CMP delta operand differs despite matching flags'
    if 0x1913db in points:
        assert points[0x1913db]['ebx']==e['raw_delta'], 'last-tick ADD source differs'
    assert points[0x191274]['ebx']==(e['index']&MASK)
    assert points[0x191274]['eax']==4 and points[0x191274]['edx']==5
    observed_comparisons={0x191174:(points[0x191174]['ebx'],1,32),
                          0x191274:(points[0x191274]['ebx'],points[0x191274]['eax'],32)}
    # Data operands read via EBP are tied to the exact stack write/replay below.
    if 0x1912cd in points:observed_comparisons[0x1912cd]=(e['raw_delta'],0,32)
    if 0x1912eb in points:
        cpu=points[0x1912eb]
        assert cpu['eax']&0xff==e['age'] and cpu['edx']&0xff==c['age']
        assert cpu['esi']==e['age'] and cpu['ecx']==I.EXT
        observed_comparisons[0x1912eb]=(cpu['edx']&0xff,cpu['eax']&0xff,8)
    if 0x1912f0 in points:
        assert points[0x1912f0]['esi']==e['age']
        observed_comparisons[0x1912f0]=(e['threshold'],points[0x1912f0]['esi'],32)
    for pc,a,b,width in ((0x191174,e['raw_delta'],1,32),(0x191274,e['index']&MASK,4,32),
                         (0x1912cd,e['raw_delta'],0,32),(0x1912eb,c['age'],e['age'],8),
                         (0x1912f0,e['threshold'] or 0,e['age'],32)):
        if pc in points:
            flags,mask=cmp_bits(a,b,width)
            assert points[pc]['eflags']&mask==flags,('CMP flags',hex(pc))
            observed_flags,observed_mask=cmp_bits(*observed_comparisons[pc])
            assert points[pc]['eflags']&observed_mask==observed_flags,('observed CMP operands',hex(pc))
    threshold_pc=0x191276 if e['index']>4 else 0x191283
    cpu=points[threshold_pc]
    if threshold_pc==0x191276:
        assert cpu['edx']==5
        observed_ea=(cpu['edx']*4+0x1e25fc)&MASK
    else:
        assert cpu['ebx']==e['index']&MASK
        observed_ea=(cpu['ebx']*4+0x1e2600)&MASK
    assert observed_ea==e['address']
    for pc in (0x1912af,0x1912be,0x1912cd,0x1912d5):
        if pc in points:
            assert points[pc]['ecx']==I.EXT and points[pc]['edx']==0x600008
            if pc!=0x1912af:assert points[pc]['eax']&0xff==c['pde']&0xff
    if e['mapped']:
        assert row['error'] is None and not row['invalid']
        assert row['threshold_reads']==[{'pc':threshold_pc,'address':e['address'],'width':4,'value':e['threshold']}]
        assert points[0x19128a]['eax']==e['threshold']
    else:
        assert row['error'] and row['invalid']==[{'pc':threshold_pc,'access':19,'address':e['address'],'width':4}]
        assert row['threshold_reads']==[]
    if e['outcome']=='returned':
        assert row['cpu']['eip']==I.STOP and row['cpu']['esp']==I.STACK+4
        assert all(row['cpu'][k]==v for k,v in I.CALLEE.items())
    else:
        assert row['cpu']['ebp']==I.STACK-4 and row['cpu']['esp']==I.STACK-0x28
        if e['outcome']=='remove_decision':
            assert row['cpu']['eip']==I.DECISION
            assert row['cpu']['eax']&0xff==e['age'] and row['cpu']['edx']&0xff==c['age']
            assert row['cpu']['esi']==e['age'] and row['cpu']['ecx']==I.EXT
        else:assert row['cpu']['eip']==threshold_pc
    expected_writes=[(0x191144,I.STACK-4,4,I.CALLEE['ebp']),
                     (0x19114a,I.STACK-0x20,4,I.CALLEE['edi']),
                     (0x19114b,I.STACK-0x24,4,I.CALLEE['esi']),
                     (0x19114c,I.STACK-0x28,4,I.CALLEE['ebx'])]
    if c['last']==0:expected_writes.append((0x19115c,I.LAST,4,c['tick']))
    expected_writes.extend([(0x19116e,I.STACK-0xc,4,e['raw_delta']),
                            (0x191266,I.STACK-0x10,4,e['index']&MASK)])
    if e['mapped']:expected_writes.append((0x19128a,I.STACK-0x10,4,e['threshold']))
    if e['mapped'] and c['active']:
        if c['wired']==0 and c['pde']&1:
            expected_writes.append((0x1912c6,I.STACK-8,4,I.ACTIVE))
        if c['wired']!=0 or not c['pde']&1:
            expected_writes.append((0x1913cc,I.EXT+0x1d,1,0))
        elif c['pde']&0x20:
            expected_writes.extend([(0x1913bc,0x600008,1,(c['pde']&0xff)&~0x20),
                                    (0x1913bf,I.EXT+0x1d,1,0)])
        elif e['delta']>0:expected_writes.append((0x1912e3,I.EXT+0x1d,1,e['age']))
    if e['outcome']=='returned':expected_writes.append((0x1913db,I.LAST,4,e['last']))
    observed=[(w['pc'],w['address'],w['width'],w['value']) for w in row['writes']]
    assert observed==expected_writes
    stack=bytearray(0x2c);struct.pack_into('<I',stack,0x28,I.STOP)
    for pc,address,width,value in expected_writes:
        if I.STACK-0x28<=address and address+width<=I.STACK:
            off=address-(I.STACK-0x28)
            stack[off:off+width]=value.to_bytes(width,'little')
    assert row['after']['stack']==stack.hex()
    ext=bytearray(0x20)
    for off,val in ((0,I.ACTIVE),(4,I.ACTIVE),(0x10,I.PMAP),(0x14,0x800000)):
        struct.pack_into('<I',ext,off,val)
    struct.pack_into('<HH',ext,0x18,1,c['wired']);ext[0x1d]=e['age']
    assert row['after']['extension']==ext.hex()
    owners=([{'pc':0x1912ab,'address':I.PMAP,'width':4,'value':I.DIRECTORY}]
            if e['mapped'] and c['active'] else [])
    assert row['owner_reads']==owners
    pdes=[]
    if owners and c['wired']==0:
        pdes.append({'pc':0x1912ba,'address':0x600008,'width':1,'value':c['pde']&0xff})
        if c['pde']&1 and c['pde']&0x20:
            pdes.append({'pc':0x1913bc,'address':0x600008,'width':1,'value':c['pde']&0xff})
    assert row['pde_reads']==pdes
    return e


def main():
    smoke='--smoke' in sys.argv
    rows=json.loads((I.HERE/('smoke-cases.json' if smoke else 'aging-cases.json')).read_text())
    assert [r['input'] for r in rows]==I.matrix(smoke)
    results=[check(r) for r in rows]
    out={'cases':len(rows),'outside_table_reads_or_attempts':sum(e['outside_declared_table'] for e in results),
         'remove_decisions_not_executions':sum(e['outcome']=='remove_decision' for e in results),
         'flat_fixture_contract_verified':True,'full_CPU_semantics_verified':False,
         'original_remove_executed':False,'whole_goal_complete':False}
    (I.HERE/('smoke-audit.json' if smoke else 'aging-audit.json')).write_text(json.dumps(out,indent=2)+'\n')
    print(json.dumps(out))


if __name__=='__main__':main()
