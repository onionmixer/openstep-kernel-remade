# 247차 정적 검토 — `FUN_0018d238`의 single direct caller·read-clear-return 흐름

원본 OPENSTEP x86 `mach_kernel`의 `FUN_0018d238`을 원시 명령으로 대조했다. 재부팅·QEMU·외부
소스·구현은 사용하지 않았다.

연속 export body는 22바이트다. 원본 `__text` E8 rel32 target을 Python으로 전수 계산하면 direct
caller는 `FUN_0015b470`의 `0x0015b478` 한 곳이다.

함수는 입력 `[EBP+8]`을 EAX에 읽고, `[EAX+0x2c]`을 EDX에 읽은 뒤 같은 field에 0을 쓴다.
그 다음 EDX를 EAX로 옮겨 RET한다. 이는 raw read-clear-return 순서일 뿐, input·field·반환값의
의미와 runtime 결과를 확정하지 않는다.

원시 명령과 Python 검산값은 [fun-0018d238-static-evidence.json](fun-0018d238-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
