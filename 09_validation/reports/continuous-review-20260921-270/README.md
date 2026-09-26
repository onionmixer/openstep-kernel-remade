# 270차 정적 검토 — _setsid의 raw direct-control-transfer 경계

원본 OPENSTEP x86 mach_kernel의 _setsid(0x00108474) 92바이트 body를 원시 명령으로
검토했다. direct rel32 call 세 개의 target은 0x00107898, 0x001074d8, 0x00107504다.
conditional short branch 두 개와 unconditional short jump 한 개, plain RET 한 개도
relative displacement로 검증했다.

전체 __text의 직접 E8 rel32 target scan은 이 entry의 caller를 찾지 못했다. 이는
indirect·computed caller edge를 제외한다. branch 조건, callee, stack·register protocol,
calling convention·parameter storage·return ABI의 의미는 확정하지 않는다.

원시 바이트와 control-transfer evidence는
[setsid-raw-control-flow-evidence.json](setsid-raw-control-flow-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
