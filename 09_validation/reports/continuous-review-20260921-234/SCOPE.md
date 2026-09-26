# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 selected export
body byte 합계, VA→file byte 대조, wrapper-address dword의 whole-file occurrence 수와 record 수를
계산했다.

범위는 `_unix_syscall_` entry address의 두 code-operand consumer다. structure/descriptor/vector
meaning, privilege, exception flow, vector installation, runtime behavior는 범위 밖이다.
