# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 export body byte와
SHA-256, instruction VA→file byte 및 `__text` 전체 E8 rel32 target을 계산했다.

범위는 `__call_with_stack`의 local raw instruction sequence와 direct-relative caller다. ABI,
stack validity, EAX indirect target, call/jump 의미 및 runtime behavior는 범위 밖이다.
