# 313차 정적 검토 — _xdr_bp_getfile_arg의 control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _xdr_bp_getfile_arg(0x001389b4) 두 body segment, 합계 86바이트를 원시 명령으로 검토했다. direct E8 call 2개, 조건분기 4개, 직접 JMP 1개, plain RET 1개가 있다. 직접 E8 caller는 없다.
