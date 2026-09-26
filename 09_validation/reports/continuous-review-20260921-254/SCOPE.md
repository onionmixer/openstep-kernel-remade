# 범위

원본 OPENSTEP x86 `mach_kernel`와 그 바이너리에서 생성된 독립 `full-pass5` export만
사용했다. Python으로 VA-to-file mapping, export body 바이트·SHA-256, `__text` 내 직접
`E8 rel32` target scan을 검증했다.

범위는 `_kdp_panic` body의 HLT 뒤 원시 명령과 직접 self-branch의 부재다. HLT의 runtime
동작, call target의 의미, ABI·stack protocol, caller의 의미와 decompiler warning의 정확성은
범위 밖이다.
