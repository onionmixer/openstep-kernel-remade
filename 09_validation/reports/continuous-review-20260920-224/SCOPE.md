# 범위

원본 x86 `mach_kernel`과 원본-derived full-pass5 export만 사용했다. Python은 original
`__text`의 `E8 rel32` target을 모두 계산하고, 선택 instruction의 VA→file offset을
계산해 원본 bytes와 대조했다. 8-cell loop 범위·stride·table size도 Python으로 계산했다.

이 검토는 `_intr_initialize`·`_intr_change_ipl`의 국소 정적 흐름만 다룬다. PIC의 실제
hardware effect, runtime call order, slot/table lifetime, callback·interrupt execution,
SPL/lock reentrancy 및 진행성은 범위 밖이다.
