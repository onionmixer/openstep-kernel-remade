# 범위

원본 OPENSTEP x86 mach_kernel와 그 바이너리에서 생성된 독립 full-pass5 export만
사용했다. Python으로 VA-to-file mapping, 여섯 export body segment의 바이트·SHA-256 및
__text 내 직접 E8 rel32 target scan을 검증했다.

범위는 _PMSetCpuState의 HLT 인접 조건 branch와 fall-through 원시 바이트, 직접
self-branch의 부재다. absolute operand의 의미, HLT runtime 동작, ABI·stack protocol,
caller 의미와 decompiler warning의 정확성은 범위 밖이다.
