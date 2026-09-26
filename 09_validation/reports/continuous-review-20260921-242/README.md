# 242차 정적 검토 — `FUN_001639ec`의 조건부 `_thread_dispatch` edge와 간접 call 경계

원본 OPENSTEP x86 `mach_kernel`의 `FUN_001639ec`를 원시 명령으로 대조했다. 재부팅·QEMU·외부
소스·구현은 사용하지 않았다.

이 export의 연속 body는 `0x001639ec..0x00163a15` 42바이트다. Python으로 원본 `__text`의 E8
rel32 target을 전수 계산하면 이 entry를 향하는 direct-relative caller는 0곳이다. 이는
indirect/computed entry edge가 없다는 뜻은 아니다.

함수는 `[EBP+8]`을 EDX에 읽고, 절대주소 `0x001e8b54`에서 읽은 EAX의 `+0x34`를 EBX에 읽는다.
EDX가 zero이면 `0x00163a08`으로 분기한다. nonzero이면 EDX를 push하여 `_thread_dispatch`
(`0x00163ac4`)를 direct call하고 stack을 4바이트 조정한다. 두 경로는 `0x0018b60c`를 direct
call한 뒤 `CALL EBX`를 실행한다. EBX의 runtime value와 이 간접 call의 target은 확정하지 않는다.

원시 명령과 Python 검산값은 [fun-001639ec-static-evidence.json](fun-001639ec-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
