# 244차 정적 검토 — `FUN_00163dc8`의 두 helper edge·누적 field·조건부 clamp 경계

원본 OPENSTEP x86 `mach_kernel`의 `FUN_00163dc8`을 원시 명령으로 대조했다. 재부팅·QEMU·외부
소스·구현은 사용하지 않았다.

export의 실행 명령은 79·57·173·127바이트의 네 연속 구간이며, 원본 `__text`의 E8 rel32 target
전수 계산에서 direct caller는 9곳이다. `0x00164020`은 `_thread_setrun`에서의 caller site다.

함수는 입력 `[EBP+8]`을 ESI에 읽고, `[0x001f653c]-[ESI+0x70]`을 local에 저장한 뒤 현재
`[0x001f653c]` 값을 `[ESI+0x70]`에 쓴다. 이어 `+0xf0/+0xf8/+0x10c` 비교와
`+0xe0/+0xe8/+0x104` 비교 각각의 불일치 경로에서 두 주소를 push해 `0x0016a30c`를 호출한다.
일치 경로는 field 간 SUB를 사용한다.

이후 EBX를 `[ESI+0x110]`에 더하고, `[ESI+0x180]+0x178` operand와 IMUL한 EBX를
`[ESI+0x114]`에 더한다. local이 `0x1e`보다 클 때 `+0x68/+0x6c`을 0으로 쓴다. tail에서는 두
누적 field를 0으로 쓰고, 조건부로 `[ESI+0x6c] >> 25`와 `[ESI+0x50]`의 차이를 0 하한으로
clamp하여 `+0x58`에 쓴다. 이는 raw arithmetic/data flow이며 field·helper의 의미는 확정하지
않는다.

원시 명령과 Python 검산값은 [fun-00163dc8-static-evidence.json](fun-00163dc8-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
