# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 `_start` body bytes,
선택 instruction VA→file byte, `__text` 전체 E8 rel32 target과 레코드 수를 계산했다.

범위는 `_start` local instruction sequence와 `_gdt_init` direct caller closure다. boot entry source,
CPU mode·selector·far-jump·HLT effect, callee effects, hardware/runtime behavior는 범위 밖이다.
