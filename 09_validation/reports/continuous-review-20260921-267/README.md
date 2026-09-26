# 267차 정적 검토 — _setpgrp의 raw direct-control-transfer 경계

원본 OPENSTEP x86 mach_kernel의 _setpgrp(0x00107cfc) body를 원시 명령으로 검토했다.
export body는 세 segment, 총 127바이트다. 기록된 control-transfer에는 conditional short branch
다섯 개, unconditional short jump 두 개, direct rel32 call 세 개와 plain RET 한 개가 있다.

직접 call target은 0x00107374, 0x00107340, 0x00107504이며, 모든 branch target은 원시
relative displacement로 Python에서 계산했다. 전체 __text의 직접 E8 rel32 target scan은 이
entry의 caller를 찾지 못했다. 이는 indirect·computed caller edge를 제외한다.

branch 조건, branch/callee의 의미, stack·register protocol, calling convention·parameter
storage·return ABI는 확정하지 않는다. 원시 바이트와 control-transfer evidence는
[setpgrp-raw-control-flow-evidence.json](setpgrp-raw-control-flow-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
