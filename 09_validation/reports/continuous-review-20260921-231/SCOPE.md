# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 export body 조각
byte 합계, VA→file byte 대조, `__text` 전체 E8 rel32 target 및 레코드 수를 계산했다.

범위는 `_unmount`에서 `_dounmount`로 향하는 국소 값 흐름이다. `0x0011c0f8` 등의 callee 효과,
source signature·자료형·ownership, indirect/table caller, VFS 의미·동시성·runtime execution은
범위 밖이다.
