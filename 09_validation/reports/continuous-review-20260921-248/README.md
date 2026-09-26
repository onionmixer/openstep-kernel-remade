# 248차 정적 검토 — `FUN_0015abe0`의 input 보정·절대 slot 갱신·조건부 helper edges

원본 OPENSTEP x86 `mach_kernel`의 `FUN_0015abe0`을 원시 명령으로 대조했다. 재부팅·QEMU·외부
소스·구현은 사용하지 않았다.

export instruction segment는 61·181·54·77바이트이며, 원본 `__text` E8 rel32 target 전수 계산에서
direct caller는 `0x0015b486`, `0x0016714b` 두 곳이다. 전자는 246차의 조건부 call site다.

함수는 입력을 EDI에 읽고 `-0xc`를 더한다. 이어 literal `0x001f63d0`을 push해 `0x0015b5d0`을
호출하고, EDI `+0x8`에 0을 쓴다. 절대 slot `0x001e5b9c`와 `0x001e5b98` 및 EDI `+0/+4`를
비교·write한 뒤 `0x001ded68`, `0x001f63b8`을 증가시키고 `0x0015b73c`을 호출한다.

`[0x001ded70]`이 nonzero인 경로는 해당 주소를 0으로 쓰고 0, 0, `0x001e5b98`을 push하여
`0x001631a0`을 호출한다. 뒤의 선택 경로는 `0x0015b098`, `0x0015b0dc`, `0x00168b50`,
`0x00173e90` direct call을 포함한다. 절대 slot, field, 반복, helper 및 입력 보정의 의미는
확정하지 않는다.

원시 명령과 Python 검산값은 [fun-0015abe0-static-evidence.json](fun-0015abe0-static-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
