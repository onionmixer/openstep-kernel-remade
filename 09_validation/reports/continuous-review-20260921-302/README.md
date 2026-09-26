# 302차 정적 검토 — _svc_getreq의 control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _svc_getreq(0x001370b4) 3개 body segment, 합계 585바이트를 원시 명령으로 검토했다. direct E8 call 2개, raw CALL EAX 7개, 조건분기 12개, 직접 JMP 5개 및 plain RET 1개가 있다. 직접 E8 caller는 0x00137330 한 곳이다.
