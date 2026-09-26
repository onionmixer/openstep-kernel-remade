# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 export body byte와
SHA-256, selected instruction VA→file byte, `__text` 전체 E8 rel32 target 및 shift/subtract/LEA
계수를 계산했다.

범위는 `FUN_0016a30c`의 raw local data flow, coefficient 및 direct-relative caller closure다.
function identity, ABI, type·structure·field의 단위/의미, 반복 종료 보장, indirect edge 및 runtime
behavior는 범위 밖이다.
