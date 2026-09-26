# 332차 정적 검토 — _ttwrite의 aggregate control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _ttwrite(0x001108e8) 10개 body segment, 합계 1270바이트를 원시 명령으로 검토했다. direct E8 call 29개, raw CALL EAX 5개, 조건분기 63개, 직접 JMP 15개, plain RET 1개가 있으며 직접 E8 caller는 없다.

각 export asm record의 명령 크기와 원본 바이트를 대조하고, 모든 direct E8/E9/Jcc 상대변위 대상도 Python으로 검증했다. 전체 112개 전이 레코드의 정규 JSON SHA-256도 보존했다.
