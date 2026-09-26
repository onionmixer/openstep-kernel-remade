# 243차 정적 검토 — `FUN_0018b60c`의 CLI/STI·간접 callback·literal port write 경계

원본 OPENSTEP x86 `mach_kernel`의 `FUN_0018b60c`를 원시 명령으로 대조했다. 재부팅·QEMU·외부
소스·구현은 사용하지 않았다.

함수의 연속 export body는 206바이트다. 원본 `__text`의 E8 rel32 target을 Python으로 전수
계산하면 이 entry의 direct caller는 23곳이며, `FUN_001639ec`의 `0x00163a08`도 그중 하나다.
indirect/computed caller는 이 결과에 포함하지 않는다.

함수는 `CLI` 후 `[0x001e7714]`를 읽고 같은 절대주소에 0을 쓴다. ESI가 0보다 큰 경로에서
EBX=`ESI*4+0x001e76f4`를 계산하여 내림차순으로 검사한다. nonzero `[EBX]` 항목은 0으로 clear한
뒤, 항목의 `+8`을 전역 slot에 쓰고 `STI`를 실행한다. 이어 0, 0, 항목 `+0`을 push하고 항목
`+4`에서 읽은 EAX로 `CALL EAX`를 실행한 뒤 다시 `CLI`한다. 간접 target 및 항목 구조의 의미는
확정하지 않는다.

후반부는 16비트 memory operand 두 개를 OR하여 CX와 비교하고, 값이 다를 때 literal `0x21`,
`0xa1`을 EDX에 넣어 `OUT DX,AL`을 두 번 실행한다. 이 literal port·CLI/STI·LOCK INC의
아키텍처 또는 장치 의미와 실행 결과는 주장하지 않는다.

원시 명령과 Python 검산값은 [fun-0018b60c-static-evidence.json](fun-0018b60c-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
