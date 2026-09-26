#!/usr/bin/env python3
"""Independent whole-text linear disassembly and raw Mach-O metadata exports."""
import json
import subprocess
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'03_original/x86/inventory/llvm'
OUT.mkdir(exist_ok=True)
binary=ROOT/'03_original/x86/binaries/mach_kernel'
records=[]
for name, flags in (
    ('text-linear.asm',['--macho','--disassemble','--full-leading-addr']),
    ('headers.txt',['--macho','--private-headers','--section-headers']),
    ('objc-metadata.txt',['--macho','--objc-meta-data']),
    ('section-bytes.txt',['--macho','--full-contents']),
):
    cmd=['llvm-objdump',*flags,str(binary)]
    with (OUT/name).open('w') as out, (OUT/(name+'.stderr')).open('w') as err:
        r=subprocess.run(cmd,stdout=out,stderr=err)
    records.append({'file':name,'command':cmd,'exit_code':r.returncode})
(OUT/'commands.json').write_text(json.dumps(records,indent=2)+'\n')
print(json.dumps(records,indent=2))
