# 301차 정적 검토 — _svcerr_progvers의 raw indirect-call inventory

원본 OPENSTEP x86 mach_kernel의 _svcerr_progvers(0x00137060) 단일 81바이트 body를 원시 명령으로 검토했다. direct E8 call과 branch는 없고 raw CALL EAX 하나가 있다. 직접 E8 caller는 0x0012d861 한 곳이다.
