# 326차 정적 검토 — _mach_kernel_trap의 control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _mach_kernel_trap(0x00192698) 단일 245바이트 body를 원시 명령으로 검토했다. direct E8 call 5개, raw CALL EAX 2개, 조건분기 6개, 직접 JMP 1개, plain RET 1개가 있다. 직접 E8 caller는 0x00186e8a 한 곳이다.
