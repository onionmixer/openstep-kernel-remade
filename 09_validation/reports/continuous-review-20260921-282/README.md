# 282차 정적 검토 — _xdr_authunix_parms의 raw direct-control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _xdr_authunix_parms(0x001351d4) 두 body segment 합계
126바이트를 원시 명령으로 검토했다. direct rel32 call은 5개, conditional short branch는
5개, unconditional short jump는 1개다. 모든 conditional branch는 raw target
0x00135248로 향하며, direct call target은 0x00137a44, 0x00137fa0, 0x001379c4(2개),
0x00138134다.

전체 __text의 직접 E8 rel32 target scan은 0x001374c1과 0x001374d9의 두 caller를
확인했다. 이는 indirect·computed caller edge를 제외한다.

이 검토는 byte-level transfer inventory다. branch 조건·callee·stack protocol·calling
convention·parameter storage·return ABI 및 runtime 의미는 확정하지 않는다. 원시 전이
바이트와 segment hash는
[xdr-authunix-parms-control-transfer-evidence.json](xdr-authunix-parms-control-transfer-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
