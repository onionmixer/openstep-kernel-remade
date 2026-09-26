# 범위

원본 OPENSTEP x86 mach_kernel와 그 바이너리에서 생성된 독립 full-pass5 export만
사용했다. Python으로 VA-to-file mapping, export body 바이트·SHA-256 및 __text 내 직접
E8 rel32 target scan을 검증했다.

범위는 _gethostid의 raw frame, 두 absolute load, register-to-memory write, plain RET와
직접 rel32 caller count다. absolute address의 타입·의미, ABI, parameter storage,
return convention, indirect caller와 runtime 상태는 범위 밖이다.
