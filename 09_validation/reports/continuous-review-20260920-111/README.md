# 111차 연속 검토 — vm_object template과 `+0x30`의 정적 수명 경계

## 판정

원본 x86 명령으로 `_vm_object_init`가 common 영역의 object template을 구성하고,
`__vm_object_allocate`가 그 template에서 새 object로 22 dword(88 bytes)를 복사함을
확인했다. zone 생성 인수도 `0x58`이므로, 이 복사 범위와 object allocation size는 같다.

template의 absolute `0x001f7390`은 base `0x001f7360`에서 `+0x30`이며,
`_vm_object_init`은 이 dword를 0으로 기록한다. 따라서 allocation 직후 `+0x30`의
초기값은 template-derived zero다. `_vm_object_collapse`의 complete-collapse 경로는
입력 object `ESI`의 `+0x28`, `+0x30`, `+0x34`를 순서대로 0으로 만든다. 이 경로는
`+0x28`과 `+0x2c`를 target object에 먼저 넘긴 뒤에 실행된다.

이는 `+0x30`의 이름·C type·모든 writer를 확정하지 않는다. `+0x30`을 다루는 map-entry
함수의 명령은 object-field 증거로 혼합하지 않았다. object address가 직접 register base로
확정되는 이 범위에서 확인한 사실은 초기 zero와 collapse 후 zero뿐이다.

## 원시 검증

Python Capstone x86/32 decode로 다음 명령을 binary bytes에서 재확인했다.

- `0x00178bbe`: `MOV ECX,0x16`; `0x00178bc3`: `REP MOVSD`.
- `0x00178aea`: `MOV dword ptr [0x001f7390],0x0`.
- `0x00179a72`, `0x00179a79`, `0x00179a80`: input object `+0x28/+0x30/+0x34` zero stores.

Python 산출값: `0x16 * 4 = 88`, `0x58 = 88`, `0x001f7390 - 0x001f7360 = 48 (0x30)`.

세부 machine-readable 기록은 [`object-template-field-evidence.json`](object-template-field-evidence.json)에 있다.

## 미해결

`+0x30`의 nonzero writer/reader가 object pointer alias를 통해 실행되는 경로, collapse
실패·retry 경로의 동시성, pager/object 종료와 이 필드의 전 수명은 계속 확인해야 한다.
