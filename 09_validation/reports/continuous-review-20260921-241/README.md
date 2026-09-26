# 241차 정적 검토 — `_thread_dispatch`의 두 direct caller·초기 exchange loop·상태 분기

원본 OPENSTEP x86 `mach_kernel`의 `_thread_dispatch` entry와 `_thread_invoke`에서의 direct call
edge를 원시 명령으로 대조했다. 재부팅·QEMU·외부 소스·구현은 사용하지 않았다.

원본 `__text`의 E8 rel32 target을 Python으로 전수 계산하면 `_thread_dispatch` (`0x00163ac4`)의
direct caller는 `_thread_invoke` 내부 `0x001639d5`와 별도 export `FUN_001639ec` 내부
`0x00163a00`의 두 site다. `_thread_invoke`는 `0x001639e8`의 RET에서 끝나므로, 두 번째 site를
그 함수의 일부로 취급하지 않았다. indirect/computed caller는 이 결과에 포함하지 않는다.

entry는 첫 입력을 EBX에 읽어 `EBX+0x20`을 ESI로 만든다. 이어 `MOV [ESI]`, `TEST`, backward
`JNZ`, `XCHG [ESI],1`, `XOR EAX,1`, `TEST`, backward `JZ`의 제어 흐름을 가진다. 이는 원시
read/exchange/branch 순서이며, offset·loop의 동시성 또는 객체 의미는 확정하지 않는다.

그 뒤 `EBX+0x4c`를 EAX로 읽고 AH의 두 비트를 clear한 뒤 비교 분기에 사용한다. Python으로
명시 비교값을 추적하면 EAX=4, 12, 14는 `0x00163cf8`; 5, 13, 15는 `0x00163d04`; 6, 7, 22는
`0x00163b70`; 132는 `0x00163d16`으로 첫 도달한다. 이 값 이외의 입력이나 해당 block 이후의
동작은 이 표로 주장하지 않는다.

export에는 분기 table·NOP 등의 비명령/분리 영역이 있으므로 전체를 연속 함수 바이트로 합산하지
않았다. 초기 분석 대상은 111·34·21바이트의 세 연속 export instruction segment다.

원시 명령과 Python 검산값은 [thread-dispatch-entry-evidence.json](thread-dispatch-entry-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
