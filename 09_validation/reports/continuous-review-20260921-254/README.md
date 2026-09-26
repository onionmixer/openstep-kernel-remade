# 254차 정적 검토 — `_kdp_panic`의 HLT와 decompiler infinite-loop 경고 경계

원본 OPENSTEP x86 `mach_kernel`의 `_kdp_panic`(`0x00185d80`) 22바이트 body를 원시
명령으로 확인했다. `CALL 0x001603b4` 뒤에는 `HLT`가 있으며, 그 뒤에
`MOV ESP,EBP; POP EBP; RET` 바이트가 계속된다.

따라서 이 body에는 `HLT` 주소로 돌아가는 직접 분기 명령이 없다. 이는 253차의
`__stack_attach`처럼 원시 바이트에서 확인한 HLT self-loop가 아니다. export-derived
warning의 infinite-loop 표현을 실제 동작이나 오류로 판정하지 않는다.

전체 `__text`의 직접 `E8 rel32` scan은 이 entry에 대한 호출자 네 개를 확인했다.
간접·계산된 caller edge는 이 수에 포함되지 않는다. 원시 바이트와 caller evidence는
[kdp-panic-hlt-static-evidence.json](kdp-panic-hlt-static-evidence.json)에, 재검증 입력
해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
