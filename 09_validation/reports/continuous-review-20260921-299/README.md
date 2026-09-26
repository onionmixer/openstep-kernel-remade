# 299차 정적 검토 — _svcerr_weakauth의 raw indirect-call inventory

원본 OPENSTEP x86 mach_kernel의 _svcerr_weakauth(0x00136fe0) 단일 54바이트 body를 원시 명령으로 검토했다. direct E8 call과 branch는 없고 raw CALL EAX 하나가 있다. 직접 E8 caller는 0x0012d9e2 한 곳이다.
