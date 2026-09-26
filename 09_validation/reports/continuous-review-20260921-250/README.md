# 250차 정적 검토 — `_objc_msgSend`의 네 간접 `JMP EAX`와 두 raw lookup 경로

원본 OPENSTEP x86 `mach_kernel`의 export label `_objc_msgSend`를 원시 명령으로 대조했다. 재부팅·QEMU·
외부 소스·구현은 사용하지 않았다.

export instruction segment는 55·3·21·5·73·3·31바이트다. 원본 `__text` E8 rel32 target을 Python으로
전수 계산하면 이 entry의 direct caller는 2,764곳이다. 이 수치는 direct-relative edge만 포함한다.

첫 경로는 `[ESP+4]`에서 시작해 절대주소 `0x001e5604`와 AND한 결과로 분기한다. nonzero 경로는
`[ESP+8]` 및 입력에서 도달한 `+0x20`/`+0`/`+8`/indexed `EDX*4` operand를 읽고, 일치 경로에서
`[EAX+8]`을 EAX에 읽어 `JMP EAX`한다. miss 경로는 `0x001cd868`의 반환 EAX로 `JMP EAX`한다.

두 번째 경로는 `0x001e55ac`에 대해 `XCHG [EAX],ECX`와 backward branch를 실행한다. 이후 같은
형태의 lookup 뒤, 이 절대주소를 0으로 clear하고 `JMP EAX`한다. 총 네 `JMP EAX` site는 원본
바이트 `ff e0`이며, target 값 및 디스패치의 런타임 의미는 확정하지 않는다.

원시 명령과 Python 검산값은 [objc-msgsend-static-evidence.json](objc-msgsend-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
