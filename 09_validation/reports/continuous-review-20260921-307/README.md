# 307차 정적 검토 — _xdr_bp_path_t의 control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _xdr_bp_path_t(0x00138814) 두 body segment, 합계 40바이트를 원시 명령으로 검토했다. direct E8 call 1개, 조건분기 1개, plain RET 2개가 있다. 직접 E8 caller는 없다.
