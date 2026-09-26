# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 selected instruction
VA→file byte, `__text` 전체 E8 rel32 target과 record 수를 계산했다.

범위는 `_thread_invoke` selected caller-site local sequence와 `_switch_context` direct caller closure다.
source ABI·types·fields/globals, callee/return effect, dispatch/context semantics, runtime scheduling은
범위 밖이다.
