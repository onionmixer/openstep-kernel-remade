# 235차 정적 검토 — `_start`의 `_gdt_init` 직접 caller 경계

원본 OPENSTEP x86 `mach_kernel`의 `_start` body와 `_gdt_init` 직접 caller를 원시 명령으로 대조했다.
재부팅·QEMU·외부 소스·구현은 사용하지 않았다.

원본 `__text` 전체 E8 rel32 target을 Python으로 계산하면 `_gdt_init`의 direct caller는 `_start`의
`0x001860e7` 한 site다. `_start`는 AX=`0x1234` 후 absolute `0x472` word write와 `CLD`를 실행하고,
`_gdt_init`, `0x0018b1a4`를 차례로 직접 call한다.

그 뒤 `JMPF 0x48:0x001860f8`, AX=`0x50`, DS/ES/FS/GS/SS write, `0x0018aafc` call,
`JMPF 0x8:0x00186117`, AX=`0x10`, DS/ES/SS write 및 세 직접 call이 이어지고 마지막은 `HLT`다.
이는 명령의 static 순서이며 far jump, segment selector, register write, HLT의 hardware/privilege
효과, boot 성공·후속 runtime behavior는 확정하지 않는다.

원시 명령과 Python 검산값은 [start-gdt-static-evidence.json](start-gdt-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
