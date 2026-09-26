# 305차 정적 검토 — _xdr_void의 body inventory

원본 OPENSTEP x86 mach_kernel의 _xdr_void(0x001379b8) 단일 12바이트 body를 원시 명령으로 검토했다. direct call과 branch는 없고 plain RET 하나가 있다. 직접 E8 caller는 없다.
