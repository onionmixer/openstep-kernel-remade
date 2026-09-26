# 325차 정적 검토 — _unp_bind의 control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _unp_bind(0x00118708) 세 body segment, 합계 157바이트를 원시 명령으로 검토했다. direct E8 call 3개, 조건분기 4개, 직접 JMP 2개, plain RET 1개가 있다. 직접 E8 caller는 0x001181f9 한 곳이다.
