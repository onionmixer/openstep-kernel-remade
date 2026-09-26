# 303차 정적 검토 — _svc_run의 control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _svc_run(0x00137300) 두 body segment, 합계 61바이트를 원시 명령으로 검토했다. direct E8 call 4개, 조건분기 1개, 직접 JMP 2개가 있으며 간접 call은 없다. 직접 E8 caller는 0x0012d112 한 곳이다.
