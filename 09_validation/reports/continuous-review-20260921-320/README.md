# 320차 정적 검토 — _swtch의 control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _swtch(0x001653b4) 단일 55바이트 body를 원시 명령으로 검토했다. direct E8 call 1개, 조건분기 2개, plain RET 1개가 있다. 직접 E8 caller는 없다.
