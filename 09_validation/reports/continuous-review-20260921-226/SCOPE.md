# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` assembly export만 사용했다. Python은
export metadata의 비연속 body 조각 byte 합계, 원시 instruction bytes, 주소→file offset, 레코드 수를
계산하고 원본과 대조했다.

범위는 `_thread_setrun` 본문의 국소 control/data flow다. 직접·간접 caller, callee 효과,
자료형·구조체 layout·소유권, lock 의미·진행성·동시성, scheduler의 실제 선택 및 runtime
execution은 범위 밖이다.
