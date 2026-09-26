# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 loop iterations,
offset series, export body byte 합계, VA→file byte, `__text` E8 rel32 caller와 record 수를 계산했다.

범위는 `_idt_init`의 selected loop instruction sequence와 direct caller closure다. data structure,
vector/descriptor/LIDT semantics, CPU state, callee effects와 runtime behavior는 범위 밖이다.
