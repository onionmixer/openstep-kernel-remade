# 249차 정적 검토 — `__call_with_stack`의 register/ESP 재설정과 간접 jump 경계

원본 OPENSTEP x86 `mach_kernel`의 `__call_with_stack`을 원시 명령으로 대조했다. 재부팅·QEMU·외부
소스·구현은 사용하지 않았다.

연속 export body는 12바이트다. 원본 `__text` E8 rel32 target을 Python으로 전수 계산하면 direct
caller는 `0x0018d4ee` 한 곳이다.

함수는 `[ESP+4]`를 EAX에 읽고, `[ESP+8]`을 ESP에 읽은 뒤 EBP=ESP로 둔다. 마지막 `JMP EAX`는
간접 control transfer이며 runtime target은 확정하지 않는다. 이 raw sequence는 Ghidra가
간접 jump를 call처럼 다룬 warning의 명령 수준 경계를 제공한다.

원시 명령과 Python 검산값은 [call-with-stack-static-evidence.json](call-with-stack-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
