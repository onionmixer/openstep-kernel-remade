# 317차 정적 검토 — _mach_host_self의 control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _mach_host_self(0x00157cd8) 단일 42바이트 body를 원시 명령으로 검토했다. direct E8 call 2개와 plain RET 1개가 있으며 branch와 직접 E8 caller는 없다.
