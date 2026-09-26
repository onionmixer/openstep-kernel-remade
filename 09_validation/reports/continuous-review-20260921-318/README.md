# 318차 정적 검토 — _mig_get_reply_port의 control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _mig_get_reply_port(0x00158f88) 단일 43바이트 body를 원시 명령으로 검토했다. direct E8 call 1개, 조건분기 1개, plain RET 1개가 있다. 직접 E8 caller는 16개다.
