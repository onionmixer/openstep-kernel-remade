# 328차 정적 검토 — FUN_0012d3e0의 aggregate control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 FUN_0012d3e0(0x0012d3e0) 9개 body segment, 합계 517바이트를 원시 명령으로 검토했다. direct E8 call 10개, raw CALL EAX 3개, 조건분기 16개, 직접 JMP 9개가 있으며 직접 E8 caller는 없다.

각 export asm record의 명령 크기와 원본 바이트를 대조하고, 모든 direct E8/E9/Jcc 상대변위 대상도 Python으로 검증했다.
