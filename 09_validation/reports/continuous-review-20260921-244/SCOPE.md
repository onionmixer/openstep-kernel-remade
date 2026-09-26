# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` export만 사용했다. Python은 export segment
byte와 SHA-256, selected instruction VA→file byte, `__text` 전체 E8 rel32 target을 계산했다.

범위는 `FUN_00163dc8`의 선택한 local arithmetic/control flow와 direct-relative callers/callees다.
function identity, ABI, type·structure·field/helper의 의미, 모든 shift-branch 산술, indirect edge 및
runtime behavior는 범위 밖이다.
