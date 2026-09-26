# 253차 정적 검토 — `__stack_attach`의 HLT self-loop

원본 OPENSTEP x86 `mach_kernel`의 독립 export `__stack_attach`(`0x00186f74`)를 원시
명령으로 확인했다. export body는 6바이트 `50 ff d3 f4 eb fd`다.

명령 순서는 `PUSH EAX`, `CALL EBX`, `HLT`, `JMP 0x00186f77`이다. 마지막 상대 branch는
`HLT` 주소로 되돌아간다. 전체 `__text`의 직접 `E8 rel32` scan에서는 이 entry를 향하는
호출자가 없었다. 이는 간접·계산된 transfer를 제외한 결과다.

`CALL EBX`의 target과 이 루프의 runtime 의미는 확정하지 않는다. 원시 바이트, export-body
해시, 직접 caller scan 결과는 [hlt-self-loop-static-evidence.json](hlt-self-loop-static-evidence.json)에,
재현 검증 기준은 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
