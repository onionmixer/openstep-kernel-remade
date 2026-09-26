# 238차 정적 검토 — `__switch_tss`의 save/restore-like offset·간접 jump 경계

원본 OPENSTEP x86 `mach_kernel`의 `__switch_tss`를 원시 명령으로 대조했다. 재부팅·QEMU·외부
소스·구현은 사용하지 않았다.

원본 `__text`의 E8 rel32 target을 Python으로 전수 계산하면 이 entry의 direct caller는 두 site다:
`_switch_context`와 `_start_initial_context`. indirect/computed caller는 포함하지 않는다.

함수는 `[ESP+4]`를 EAX에 읽고 0인지 검사한다. nonzero 경로는 EDI/ESI/EBX/EBP를 EAX의
`+0x44/+0x40/+0x34/+0x3c`에 쓰고, `POP EDX` 뒤 `EDX`와 ESP를 EAX `+0x20/+0x38`에 쓴다.
두 경로 모두 다른 stack input에서 EDX를 얻어 이 네 offset을 레지스터로 읽고, EAX와 ESP를
다시 설정한 뒤 EDX=`[EDX+0x20]`, `JMP EDX`로 끝난다.

이는 register 및 memory operand의 static 흐름이다. 함수 label, offset의 구조체 의미, context/TSS
의미, stack validity, `JMP EDX` target·control transfer 및 runtime execution은 확정하지 않는다.

원시 명령과 Python 검산값은 [switch-tss-static-evidence.json](switch-tss-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
