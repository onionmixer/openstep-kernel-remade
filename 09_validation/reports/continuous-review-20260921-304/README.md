# 304차 정적 검토 — __authenticate의 control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 __authenticate(0x00137340) 두 body segment, 합계 83바이트를 원시 명령으로 검토했다. raw CALL EAX 1개, 조건분기 1개, 직접 JMP 1개가 있으며 direct E8 call은 없다. 직접 E8 caller는 0x00137180 한 곳이다.
