# 범위

원본 x86 `mach_kernel`과 그 원본-derived full-pass5 함수 export만 사용했다. Python은
선택한 `_spl*` 22개 본문의 크기·고정 수준·`OUT`·`LOCK INC` 수를 계산하고, 기록한
명령의 VA→file offset 변환과 원본 bytes를 대조했다.

이 범위는 PIC 장치의 실제 동작, runtime level/table 값, callback target·ABI·진행성,
interrupt delivery, CPU 인터럽트 상태, lock 경쟁, 모든 SPL caller 또는 전체 IRQ 의미를
증명하지 않는다.
