# 271차 정적 검토 — _gethostid의 raw memory-transfer 경계

원본 OPENSTEP x86 mach_kernel의 _gethostid(0x0010b600) 21바이트 body를 원시
명령으로 확인했다. EBP frame 생성 뒤 absolute address 0x001e875c를 EAX로 load하고,
absolute address 0x001e8cd4를 EDX로 load한 후 EDX를 EAX+0x60 위치에 write한다. 끝은 plain RET다.

전체 __text의 직접 E8 rel32 target scan은 이 entry의 caller를 찾지 못했다. 이 결과는
indirect·computed caller edge를 제외한다. raw operand와 register-transfer 순서만 확정하며,
address type·의미, calling convention·parameter storage·return ABI는 확정하지 않는다.

원시 바이트와 caller scan은 [gethostid-raw-transfer-evidence.json](gethostid-raw-transfer-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
