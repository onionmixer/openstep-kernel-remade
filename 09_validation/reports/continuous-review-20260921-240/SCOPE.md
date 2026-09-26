# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 export body
segment byte, selected instruction VA→file byte, 그리고 `__text` 전체 E8 rel32 target을 계산했다.

범위는 `_thread_invoke`의 선택한 call site에서 `_switch_context`를 거쳐 `__switch_tss`에 이르는
기계적 stack operand 흐름이다. ABI·type·structure·context/TSS·selector·제어레지스터의 의미,
stack 및 control-transfer의 유효성, runtime behavior는 범위 밖이다.
