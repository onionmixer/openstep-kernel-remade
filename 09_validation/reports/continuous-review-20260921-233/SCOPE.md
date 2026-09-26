# 범위

원본 x86 `mach_kernel`과 원본-derived `full-pass5` export만 사용했다. Python은 wrapper body byte,
선택 instruction VA→file byte, `__text` 전체 E8 rel32 target과 레코드 수를 계산했다.

범위는 `_unix_syscall_` wrapper의 local instruction sequence와 `_unix_syscall` direct-call
closure다. vector/exception source, segment·privilege semantics, stack validity, IRETD effects,
interrupt/concurrency/runtime behavior는 범위 밖이다.
