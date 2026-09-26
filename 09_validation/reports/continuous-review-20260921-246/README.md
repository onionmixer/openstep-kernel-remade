# 246차 정적 검토 — `FUN_0015b470`의 조건부 두 번째 direct call

원본 OPENSTEP x86 `mach_kernel`의 `FUN_0015b470`을 원시 명령으로 대조했다. 재부팅·QEMU·외부
소스·구현은 사용하지 않았다.

연속 export body는 34바이트다. 원본 `__text` E8 rel32 target을 Python으로 전수 계산하면 direct
caller는 `_thread_dispatch`의 `0x00163af6`와 `0x0016712c` 두 곳이다.

함수는 입력 `[EBP+8]`을 EBX에 읽어 push하고 `0x0018d238`을 direct call한다. stack을 4바이트
조정한 뒤 `[EBX+0x30]`과 반환 EAX를 비교한다. 같으면 `0x0015b48b`으로 가며, 다르면 EAX를
push하여 `0x0015abe0`을 direct call한다. 입력·return·field·callee의 의미 및 호출 결과는
확정하지 않는다.

원시 명령과 Python 검산값은 [fun-0015b470-static-evidence.json](fun-0015b470-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
