"""Selected raw opcode/source evidence and local checkpoints, not full decompilation proof."""
import hashlib
import json
from pathlib import Path
import inputs as I
import capstone


def main():
    expected={0x191168:'2b1d3c771e00',0x191174:'0f8ee6000000',0x191263:'c1fb03',
        0x191274:'7e0a',0x191283:'8b049d00261e00',0x1912e1:'00d0',
        0x1912e3:'88411d',0x1912eb:'7709',0x1912f0:'0f83cd000000',
        0x1913bc:'8022df',0x1913db:'011d3c771e00'}
    for address,hexbytes in expected.items():
        raw=bytes.fromhex(hexbytes);assert I.original(address,len(raw))==raw,hex(address)
    assert list(__import__('struct').unpack('<6I',I.original(0x1e2600,24)))==[8,12,16,24,32,5]
    assert I.original(0x1e25fc,4)==bytes.fromhex('73000000')
    files=[I.BINARY,I.ROOT/'04_ghidra/exports/x86/full-pass5/functions/00191144.asm',
           I.ROOT/'04_ghidra/exports/x86/full-pass5/functions/00191144.c',
           I.ROOT/'04_ghidra/exports/x86/full-pass5/functions/00191144.json',
           I.ROOT/'04_ghidra/exports/x86/full-pass5/functions/00163d94.asm',
           I.ROOT/'04_ghidra/exports/x86/full-pass5/functions/00162dc0.asm',
           I.ROOT/'01_resources/upstream/darwin01/kernel/machdep/i386/pmap.c',
           I.ROOT/'01_resources/upstream/darwin01/kernel/machdep/i386/pmap_private.h']
    cs=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    heads={ins.address:ins.size for ins in cs.disasm(I.original(I.ENTRY,0x1913eb-I.ENTRY),I.ENTRY)}
    for line in files[1].read_text().splitlines():
        address,size,_=line.split('\t',2)
        assert heads[int(address,16)]==int(size)
    evidence=[{'path':str(p.relative_to(I.ROOT)),'size':p.stat().st_size,
               'sha256':hashlib.sha256(p.read_bytes()).hexdigest()} for p in files]
    out={'inputs':evidence,'opcodes':{hex(k):v for k,v in expected.items()},
         'prior_checkpoint_sha256':I.preserve(),'whole_goal_complete':False,
         'scope':'raw branch/width/table evidence; Ghidra listing address/size correspondence, not full semantic proof'}
    (I.HERE/'source-basis.json').write_text(json.dumps(out,indent=2)+'\n')
    print(json.dumps({'basis_files':len(files),'critical_opcodes':len(expected)}))


if __name__=='__main__':main()
