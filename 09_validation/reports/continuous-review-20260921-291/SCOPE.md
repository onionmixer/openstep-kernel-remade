# 범위

원본 OPENSTEP x86 mach_kernel와 그 바이너리에서 생성된 독립 full-pass5 export만
사용했다. Python으로 VA-to-file mapping, export segment 바이트·SHA-256, full-pass5
명령 listing과 원본 명령 바이트 길이의 일치, branch·raw indirect-jump opcode 분류 및
__text 내 직접 E8 rel32 target scan을 검증했다.

범위는 __seterr_reply의 byte-level branch·indirect-jump 집계와 epilogue 경계다.
jump-table entry/target, operand·branch 의미, ABI, parameter storage 및 runtime 상태는
범위 밖이다.
