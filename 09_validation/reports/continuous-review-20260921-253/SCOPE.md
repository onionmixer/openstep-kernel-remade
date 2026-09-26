# 범위

원본 OPENSTEP x86 `mach_kernel`와 그 바이너리에서 생성된 독립 `full-pass5` export만 사용했다.
Python으로 VA-to-file mapping, export body 바이트·SHA-256, `__text` 내 직접 `E8 rel32` target
scan을 검증했다.

범위는 `__stack_attach`의 네 명령과 HLT-address self-loop라는 정적 control-flow 사실이다.
`CALL EBX`의 간접 target, ABI·stack protocol, 호출 경로, HLT 후 runtime 동작과 이 루프의
의미는 범위 밖이다.
