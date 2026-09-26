# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 export body 조각
byte 합계, VA→file byte 대조, `__text` 전체 E8 rel32 target 및 레코드 수를 계산했다.

범위는 `_dounmount`의 국소 data/control flow와 direct caller closure다. `CALL EAX` target,
모든 callee 효과, source signature, 자료형·ownership, VFS 의미, runtime execution·동시성은
범위 밖이다.
