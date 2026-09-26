# 319차 정적 검토 — _mach_thread_self의 control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _mach_thread_self(0x001599e0) 단일 129바이트 body를 원시 명령으로 검토했다. direct E8 call 2개, 조건분기 5개, 직접 JMP 1개, plain RET 1개가 있다. 직접 E8 caller는 없다.
