# 범위

원본 OPENSTEP x86 mach_kernel와 그 바이너리에서 생성된 독립 full-pass5 export만
사용했다. Python으로 VA-to-file mapping, export segment 바이트·SHA-256, recorded
branch/rel32 call target 및 __text 내 직접 E8 rel32 target scan을 검증했다.

범위는 _xdr_rmtcall_args의 direct·indirect control-transfer inventory와 epilogue
경계다. indirect call target, operand 의미, ABI, parameter storage와 runtime 상태는
범위 밖이다.
