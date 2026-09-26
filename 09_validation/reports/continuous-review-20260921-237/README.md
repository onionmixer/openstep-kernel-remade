# 237차 정적 검토 — `_start_initial_context`의 control-register·전역 write 경계

원본 OPENSTEP x86 `mach_kernel`의 `_start_initial_context`를 원시 명령으로 대조했다. 재부팅·QEMU·
외부 소스·구현은 사용하지 않았다.

원본 `__text` E8 rel32 target을 Python으로 전수 계산하면 이 entry의 direct caller는 `_start`의
`0x0018612f` 한 site다. 함수는 첫 stack 입력을 EBX에 놓고 `EBX+0x28`을 ESI에 보관한다. pointer
chain에서 얻은 주소 `+0x18=1`, `[0x001e8b54]=EBX`, `[0x001f6354]=EBX+0x2c`,
`[0x001f74d8]=EBX+0x2c+0xff4` write가 있다.

ESI의 pointer chain `ESI → +0x1c` 값은 `MOV CR3,EAX`로 전달된다. `[0x001e19b0]` 기반 영역에는
`ESI+0x74/+0x78` 및 별도 `ESI/+4`에서 얻은 값의 분리·byte/word write가 있으며, 각각 `LLDT`
및 `LTR` 직전에 놓여 있다. 마지막에는 `MOV EAX,CR0`, `OR AL,8`, `MOV CR0,EAX`, 두 immediate 0과
ESI-derived pointer를 push한 직접 call이 있다.

이는 instruction과 operand의 static 기록이다. pointer chain의 자료형·수명, global의 의미,
CR3/CR0/LLDT/LTR의 hardware effect, initial context·processor state·callee와 runtime behavior는
확정하지 않는다.

원시 명령과 Python 검산값은 [start-initial-context-static-evidence.json](start-initial-context-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
