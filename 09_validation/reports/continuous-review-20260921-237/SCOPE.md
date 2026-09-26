# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 export body byte,
선택 instruction VA→file byte, `__text` E8 rel32 target 및 record 수를 계산했다.

범위는 `_start_initial_context`의 selected local instruction/data flow와 direct caller closure다.
layout/type/ownership, control-register·LLDT/LTR hardware effect, context semantics, callee·runtime
behavior는 범위 밖이다.
