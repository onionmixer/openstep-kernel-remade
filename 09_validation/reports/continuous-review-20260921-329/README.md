# 329차 정적 검토 — _vn_open의 aggregate control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _vn_open(0x0011df9c) 7개 body segment, 합계 601바이트를 원시 명령으로 검토했다. direct E8 call 7개, raw CALL EAX 4개, 조건분기 25개, 직접 JMP 7개, plain RET 1개가 있다. 직접 E8 caller는 0x0011cdc1 한 곳이다.

각 export asm record의 명령 크기와 원본 바이트를 대조하고, 모든 direct E8/E9/Jcc 상대변위 대상도 Python으로 검증했다.
