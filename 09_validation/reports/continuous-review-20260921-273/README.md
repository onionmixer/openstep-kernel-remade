# 273차 정적 검토 — _xdr_fhandle의 raw wrapper·two-return 경계

원본 OPENSTEP x86 mach_kernel의 _xdr_fhandle(0x0013412c) 37바이트 body를 원시
명령으로 확인했다. body는 immediate 0x20, 두 stack-relative load를 push한 뒤
0x00137cac으로 direct rel32 call한다. 이어지는 conditional branch는 두 plain RET path 중
0x00134148 쪽으로 향한다.

전체 __text의 직접 E8 rel32 target scan은 caller 한 개를 확인했고, _xdr_fhstatus body의
0x00138ab3다. indirect·computed caller edge는 포함하지 않는다. stack slot·callee·branch
의미, calling convention·parameter storage·return ABI는 확정하지 않는다.

원시 바이트와 caller/control-transfer evidence는
[xdr-fhandle-raw-wrapper-evidence.json](xdr-fhandle-raw-wrapper-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
