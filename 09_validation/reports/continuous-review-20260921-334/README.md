# 334차 정적 검토 — FUN_001afbdc의 aggregate control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 FUN_001afbdc(0x001afbdc) 15개 body segment, 합계 1749바이트를 원시 명령으로 검토했다. direct E8 call 27개, raw indirect CALL 0개, 조건분기 33개, 직접 JMP 16개, plain RET 1개가 있으며 직접 E8 caller는 없다.

각 export asm record의 명령 크기와 원본 바이트를 대조하고, 모든 direct E8/E9/Jcc 상대변위 대상도 Python으로 검증했다. 전체 77개 전이 레코드의 정규 JSON SHA-256도 보존했다.
