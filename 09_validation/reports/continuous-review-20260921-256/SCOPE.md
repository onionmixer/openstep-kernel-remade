# 범위

원본 OPENSTEP x86 mach_kernel와 그 바이너리에서 생성된 독립 full-pass5 export만
사용했다. Python으로 VA-to-file mapping, 일곱 export body segment의 바이트·SHA-256 및
__text 내 직접 E8 rel32 target scan을 검증했다.

범위는 _halt_cpu의 terminal HLT self-loop와 직접 rel32 caller 경계다. switch table,
strings, I/O, global operand, power-state call, ABI·stack protocol, HLT와 loop의 runtime
의미는 범위 밖이다.
