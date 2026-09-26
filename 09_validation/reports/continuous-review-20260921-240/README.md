# 240차 정적 검토 — `_thread_invoke`에서 `__switch_tss`까지의 `_switch_context` 스택 경로

원본 OPENSTEP x86 `mach_kernel`의 `_thread_invoke`→`_switch_context`→`__switch_tss` 경로를
원시 명령으로 대조했다. 재부팅·QEMU·외부 소스·구현은 사용하지 않았다.

원본 `__text`의 E8 rel32 target을 Python으로 전수 계산하면 `_switch_context`의 direct caller는
`0x001639cd` 한 곳이다. 그 site 직전의 `PUSH ESI`, `PUSH EDI`, `PUSH EBX`와 callee의
`[EBP+8]`, `[EBP+0xc]`, `[EBP+0x10]` 읽기를 기계적으로 결합하면, 이 call site에서는 이 세
입력이 각각 EBX, EDI, ESI의 당시 값이다.

`_switch_context`는 세 번째 입력의 `+0x28` 및 첫 번째 입력의 `+0x28`을 local slot에 보관한다.
두 번째 입력이 nonzero인 경로는 첫 번째 입력, 세 번째 입력의 `+0x28`을 한 번 역참조한 값,
0을 차례로 push하고 `__switch_tss`를 호출한다. zero 경로는 첫 번째 입력, 같은 두 번째 값,
첫 번째 입력의 `+0x28`을 한 번 역참조한 값을 push한다. 따라서 `__switch_tss` 진입 시
`[ESP+4]`는 각각 0 또는 첫 번째 입력의 `+0x28`을 한 번 역참조한 값이다. 이는 호출 시점의
stack operand 배치만 서술한다.

그 밖에 함수는 비교에 따라 `MOV CR3`, `LLDT`, `LTR`, `CR0` read-modify-write를 포함한다.
함수 export에는 `0x0018d4bd..0x0018d4bf`의 세 `NOP`가 있어, export 명령 바이트 합 352와
entry부터 RET 뒤까지의 연속 범위 355를 혼동하지 않았다. 실행 가능한 export 구간은 321바이트와
31바이트다.

구조체·argument의 의미, selector/제어레지스터의 시스템 의미, stack validity, indirect edge 및
runtime 동작은 확정하지 않는다. 원시 명령과 Python 검산값은
[switch-context-stack-edge-evidence.json](switch-context-stack-edge-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
