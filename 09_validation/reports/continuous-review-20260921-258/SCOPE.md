# 범위

원본 OPENSTEP x86 mach_kernel와 그 바이너리에서 생성된 독립 full-pass5 export만
사용했다. Python으로 VA-to-file mapping, fragment와 인접 _do_exit export segment의
바이트·SHA-256 및 __text 내 직접 E8 rel32 target scan을 검증했다.

범위는 synthetic fragment와 인접 export segment의 원시 경계 및 _do_exit의 직접 self-loop다.
fragment ABI, decompiler control-flow 모델, loop 도달 조건, call target, stack protocol,
runtime 의미는 범위 밖이다.
