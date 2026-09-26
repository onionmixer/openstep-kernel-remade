# 264차 정적 검토 — _getpgrp의 raw branch·call·return 경계

원본 OPENSTEP x86 mach_kernel의 _getpgrp(0x00107af0) 72바이트 body를 원시 명령으로
확인했다. body에는 두 conditional short branch, 0x00107374를 향하는 직접 rel32 call,
두 plain RET path가 있다. 이 entry에는 body 내부 direct call이 한 개이며, 전체 __text의
직접 E8 rel32 target scan은 caller를 찾지 못했다.

absolute/pointer-relative operand와 두 return path의 raw instruction sequence만 확정한다.
branch 조건의 의미, call target의 의미, calling convention·parameter storage·return ABI는
확정하지 않는다.

원시 바이트·branch/call target과 caller scan은
[getpgrp-raw-control-flow-evidence.json](getpgrp-raw-control-flow-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
