# 293차 정적 검토 — _svc_register의 raw direct-control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _svc_register(0x00136de4) 두 segment 합계 89바이트를 원시 명령으로 검토했다. direct rel32 call 2개, conditional branch 2개, jump 1개와 직접 E8 caller 0x0012d094를 확인했다.
