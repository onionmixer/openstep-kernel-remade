# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 export body byte와
SHA-256, instruction VA→file byte 및 `__text` 전체 E8 rel32 target을 계산했다.

범위는 `FUN_0015b470`의 local raw control flow와 direct-relative caller/callee다. function identity,
ABI, type·structure·field·return/callee의 의미, indirect edge 및 runtime behavior는 범위 밖이다.
