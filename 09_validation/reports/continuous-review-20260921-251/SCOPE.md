# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 export segment byte와
SHA-256, selected VA→file byte 및 `__text` 전체 E8 rel32 target을 계산했다.

범위는 `_objc_msgSendSuper`의 selected raw control/data flow와 indirect JMP 경계다. ABI, selector,
class/cache/table/lock·stack slot의 의미, EAX target, all caller identities 및 runtime behavior는 범위 밖이다.
