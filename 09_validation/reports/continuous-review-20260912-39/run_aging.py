"""Execute untouched original pmap_update until RET or before removal dispatch."""
import hashlib
import json
import struct
import sys
import capstone
import unicorn as U
from unicorn import x86_const as X
import inputs as I

REGS = {name: getattr(X, 'UC_X86_REG_' + name.upper()) for name in
        ('eax','ebx','ecx','edx','esi','edi','ebp','esp','eip','eflags')}
CS = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
INSTRUCTIONS = {i.address: bytes(i.bytes) for i in CS.disasm(I.original(I.ENTRY,0x1913eb-I.ENTRY),I.ENTRY)}
POINTS = {0x191171,0x191174,0x191274,0x191283,0x191276,0x19128a,0x1912af,0x1912be,
          0x1912cd,0x1912d5,0x1912eb,0x1912f0,0x1913db}


def execute(case):
    uc = U.Uc(U.UC_ARCH_X86,U.UC_MODE_32)
    uc.mem_map(0x100000,0x200000)
    for va,vs,offset,fs in I.SEGMENTS:
        uc.mem_write(va,I.RAW[offset:offset+fs])
    for base in (0x500000,I.DIRECTORY,I.PMAP,I.EXT):
        uc.mem_map(base,0x1000)
    def put(address,value,width=4):
        uc.mem_write(address,value.to_bytes(width,'little'))
    for head in (I.FREE_PT,I.FREE_PD):
        put(head,head);put(head+4,head)
    put(I.ACTIVE,I.EXT if case['active'] else I.ACTIVE)
    put(I.ACTIVE+4,I.EXT if case['active'] else I.ACTIVE)
    put(I.EXT,I.ACTIVE);put(I.EXT+4,I.ACTIVE)
    put(I.EXT+0x10,I.PMAP);put(I.EXT+0x14,I.SECTION)
    put(I.EXT+0x18,1,2);put(I.EXT+0x1a,case['wired'],2);put(I.EXT+0x1d,case['age'],1)
    put(I.PMAP,I.DIRECTORY);put(I.PDE,case['pde']);put(I.PDE+4,case['second_pde'])
    put(I.TICK,case['tick']);put(I.LAST,case['last']);put(I.STACK,I.STOP)
    uc.reg_write(REGS['esp'],I.STACK)
    for name,value in I.CALLEE.items():uc.reg_write(REGS[name],value)
    uc.reg_write(REGS['eflags'],2)
    trace,writes,reads,points,invalid,pde_reads,owner_reads = [],[],[],[],[],[],[]
    def registers():return {k:uc.reg_read(v) for k,v in REGS.items()}
    def code(engine,address,size,_):
        if address == I.DECISION:
            engine.emu_stop();return
        assert address in INSTRUCTIONS, ('unexpected instruction',hex(address))
        assert engine.mem_read(address,size) == INSTRUCTIONS[address]
        trace.append(address)
        if address in POINTS:points.append({'pc':address,'cpu':registers()})
    def write(engine,access,address,size,value,_):
        writes.append({'pc':engine.reg_read(REGS['eip']),'address':address,'width':size,
                       'value':value & ((1 << (size*8))-1)})
    def read(engine,access,address,size,value,_):
        pc=engine.reg_read(REGS['eip'])
        if I.PDE<=address<I.PDE+8:
            pde_reads.append({'pc':pc,'address':address,'width':size,
                             'value':int.from_bytes(engine.mem_read(address,size),'little')})
        if pc==0x1912ab:
            owner_reads.append({'pc':pc,'address':address,'width':size,
                               'value':int.from_bytes(engine.mem_read(address,size),'little')})
        if pc in (0x191283,0x191276):
            reads.append({'pc':pc,'address':address,'width':size,
                          'value':int.from_bytes(engine.mem_read(address,size),'little')})
    def bad(engine,access,address,size,value,_):
        invalid.append({'pc':engine.reg_read(REGS['eip']),'access':access,'address':address,'width':size})
        return False
    uc.hook_add(U.UC_HOOK_CODE,code)
    uc.hook_add(U.UC_HOOK_MEM_WRITE,write)
    uc.hook_add(U.UC_HOOK_MEM_READ,read)
    uc.hook_add(U.UC_HOOK_MEM_INVALID,bad)
    error=None
    try:uc.emu_start(I.ENTRY,I.STOP,count=512)
    except U.UcError as e:error={'errno':e.errno,'text':str(e)}
    cpu=registers()
    outcome='remove_decision' if cpu['eip']==I.DECISION else ('returned' if cpu['eip']==I.STOP else 'execution_error')
    return {'input':case,'outcome':outcome,'cpu':cpu,'trace':trace,'writes':writes,'threshold_reads':reads,
        'points':points,'invalid':invalid,'error':error,'pde_reads':pde_reads,'owner_reads':owner_reads,
        'after':{'last':int.from_bytes(uc.mem_read(I.LAST,4),'little'),
                 'age':int.from_bytes(uc.mem_read(I.EXT+0x1d,1),'little'),
                 'pde':int.from_bytes(uc.mem_read(I.PDE,4),'little'),
                 'second_pde':int.from_bytes(uc.mem_read(I.PDE+4,4),'little'),
                 'stack':bytes(uc.mem_read(I.STACK-0x28,0x2c)).hex(),
                 'extension':bytes(uc.mem_read(I.EXT,0x20)).hex()},
        'scope':'flat synthetic boundary; removal dispatch not executed; no native CPU/paging proof'}


def main():
    prior=I.preserve();smoke='--smoke' in sys.argv
    rows=[]
    for index,case in enumerate(I.matrix(smoke)):
        rows.append(execute(case))
        if index % 256 == 0:print(json.dumps({'completed':len(rows)}),flush=True)
    assert I.preserve()==prior
    name='smoke-cases.json' if smoke else 'aging-cases.json'
    (I.HERE/name).write_text(json.dumps(rows,separators=(',',':'))+'\n')
    out={'cases':len(rows),'outcomes':{o:sum(r['outcome']==o for r in rows) for o in sorted({r['outcome'] for r in rows})},
         'original_sha256':I.SHA,'prior_checkpoint_sha256':prior,'unicorn_version':U.__version__,
         'whole_goal_complete':False,'original_remove_executed':False}
    (I.HERE/('smoke-summary.json' if smoke else 'aging-summary.json')).write_text(json.dumps(out,indent=2)+'\n')
    print(json.dumps(out),flush=True)


if __name__=='__main__':main()
