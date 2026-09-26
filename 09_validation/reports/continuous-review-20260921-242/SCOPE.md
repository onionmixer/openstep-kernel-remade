# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 export body byte와
SHA-256, selected instruction VA→file byte, `__text` 전체 E8 rel32 target을 계산했다.

범위는 `FUN_001639ec`의 local raw control flow와 direct-relative edge다. function identity, ABI,
type·structure·global의 의미, EBX 간접 target, indirect/computed entry edge 및 runtime behavior는
범위 밖이다.
