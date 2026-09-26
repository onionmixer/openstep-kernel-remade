# 265차 정적 검토 — _getuid의 raw repeated transfer 경계

원본 OPENSTEP x86 mach_kernel의 _getuid(0x00107b38) 49바이트 body를 원시 명령으로
확인했다. body는 두 반복된 absolute/pointer-relative load chain, 두 MOVSX, 두 offset write,
frame 복원 및 plain RET로 구성되며 직접 call 명령은 없다.

전체 __text의 직접 E8 rel32 target scan도 이 entry의 caller를 찾지 못했다. 이 결과는
indirect·computed caller edge를 제외한다. raw register·memory operand 순서만 확정하며,
address·offset type과 의미, calling convention·parameter storage·return ABI는 확정하지 않는다.

원시 바이트와 caller scan은 [getuid-raw-transfer-evidence.json](getuid-raw-transfer-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
