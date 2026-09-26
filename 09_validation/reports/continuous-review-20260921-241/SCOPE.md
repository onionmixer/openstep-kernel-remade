# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 selected export
segment byte와 SHA-256, selected instruction VA→file byte, `__text` 전체 E8 rel32 target 및
명시한 EAX 값의 분기 predicate를 계산했다.

범위는 `_thread_dispatch`의 두 direct caller, entry의 raw exchange/branch sequence 및 첫 비교
분기다. ABI·type·structure·offset의 의미, loop의 동시성/lock 의미, switch table, 이후 block의
효과, indirect edge 및 runtime behavior는 범위 밖이다. Caller owner는 원본-derived export의 RET
경계를 교차 확인했다.
