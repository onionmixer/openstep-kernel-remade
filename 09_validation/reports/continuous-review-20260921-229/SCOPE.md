# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 export body 조각
byte 합계, VA→file byte 대조, `__text` 전체 E8 rel32 target, 레코드 수를 계산했다.

범위는 `_choose_pset_thread`의 선택 명령과 직접 caller closure다. indirect caller, 모든 callee
효과, 자료형·구조체 layout·ownership, queue/lock/state 의미와 runtime execution은 범위 밖이다.
