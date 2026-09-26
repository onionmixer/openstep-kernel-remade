# 251차 정적 검토 — `_objc_msgSendSuper`의 네 간접 JMP와 `[ESP+0xc]` 갱신 경로

원본 OPENSTEP x86 `mach_kernel`의 export label `_objc_msgSendSuper`를 원시 명령으로 대조했다.
재부팅·QEMU·외부 소스·구현은 사용하지 않았다.

export instruction segment는 69·3·28·84·3·38바이트이며, 원본 `__text` E8 rel32 target 전수
계산에서 direct caller는 148곳이다. 네 indirect `JMP EAX`는 모두 `ff e0`이다.

첫 lookup 형태의 match 경로는 `[ESP+0xc]`에서 EDI를 읽고, `[EDI]`을 ESI로 읽어 같은 stack
slot에 쓴 뒤 EAX로 jump한다. miss 경로도 이 stack-slot read/write 뒤 `0x001cd868`을 direct
call하고 반환 EAX로 jump한다. 두 번째 형태는 `0x001e55ac`에 `XCHG [EAX],ECX` 반복을 수행하고,
성공·miss 경로에서 해당 절대주소를 0으로 쓴 뒤 jump한다. ABI·stack 의미·EAX target은 확정하지
않는다.

원시 명령과 Python 검산값은 [objc-msgsend-super-static-evidence.json](objc-msgsend-super-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
