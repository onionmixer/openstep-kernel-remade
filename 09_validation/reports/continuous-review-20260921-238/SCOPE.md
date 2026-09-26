# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 export body byte,
selected instruction VA→file byte, `__text` 전체 E8 rel32 target 및 record 수를 계산했다.

범위는 `__switch_tss`의 local instruction/data flow와 direct caller closure다. structure/type,
context/TSS semantics, stack·jump target validity, control-transfer and runtime behavior는 범위 밖이다.
