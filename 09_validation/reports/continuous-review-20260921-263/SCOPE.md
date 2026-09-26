# 범위

원본 OPENSTEP x86 mach_kernel와 그 바이너리에서 생성된 독립 full-pass5 export만
사용했다. Python으로 VA-to-file mapping, export body 바이트·SHA-256 및 __text 내 직접
E8 rel32 target scan을 검증했다.

범위는 _getpid의 raw frame, absolute/pointer-relative operand, MOVSX, offset write,
plain RET와 직접 rel32 caller count다. operand type·의미, ABI, parameter storage,
return convention, indirect caller와 runtime 상태는 범위 밖이다.
