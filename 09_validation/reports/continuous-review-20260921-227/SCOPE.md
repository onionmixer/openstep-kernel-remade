# 범위

원본 x86 `mach_kernel` 및 원본-derived `full-pass5` assembly export만 사용했다. Python은 함수
export metadata의 비연속 body 조각 byte 합계, 선택 raw instruction byte, 주소→file offset, 레코드 수를 계산하고
원본 bytes와 대조했다.

범위는 `_choose_thread`의 한 본문에 한정한다. caller·callee 전체, 자료형과 구조체 layout,
queue 및 lock의 의미·진행성, 스케줄 정책·실행 결과·동시성은 범위 밖이다.
