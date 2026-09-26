# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 export metadata의
body 조각 byte 합계, 선택 명령 VA→file byte 대조, 원본 `__text` 전체 E8 rel32 target, 레코드 수를
계산했다.

범위는 `_thread_select`의 선택 명령과 `_choose_thread`의 direct-call closure다. 간접 caller,
callee 전체 효과, 구조체 layout·자료형·소유권, queue/lock 의미·진행성·동시성 및 runtime execution은
범위 밖이다.
