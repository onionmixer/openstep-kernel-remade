# 294차 정적 검토 — _svc_unregister의 raw direct-control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _svc_unregister(0x00136e40) 두 segment 합계 69바이트를 원시 명령으로 검토했다. direct call 2개, conditional branch 2개, jump 1개와 직접 E8 caller 0x0012d0d5를 확인했다.
