# 330차 정적 검토 — _dirremove의 aggregate control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _dirremove(0x0013f1a4) 7개 body segment, 합계 675바이트를 원시 명령으로 검토했다. direct E8 call 16개, 조건분기 30개, 직접 JMP 11개, plain RET 1개가 있으며 raw CALL EAX는 없다. 직접 E8 caller는 3개다.

각 export asm record의 명령 크기와 원본 바이트를 대조하고, 모든 direct E8/E9/Jcc 상대변위 대상도 Python으로 검증했다.
