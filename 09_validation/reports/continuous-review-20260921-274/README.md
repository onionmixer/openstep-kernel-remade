# 274차 정적 검토 — _xdr_writeargs의 raw direct-control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _xdr_writeargs(0x00134154) export body를 원시
명령으로 검토했다. body는 세 segment, 총 160바이트다. 모든 recorded direct transfer를
Python으로 decode한 결과, direct rel32 call은 6개, conditional short branch는 9개,
unconditional short jump는 2개다.

직접 call target은 0x00137cac, 0x001379ec 세 site, 0x001383c8, 0x00137d78이다.
전체 __text의 직접 E8 rel32 target scan은 이 entry의 caller를 찾지 못했다. 이는
indirect·computed caller edge를 제외한다.

이 검토는 byte-level transfer inventory다. branch 조건·callee·stack protocol·calling
convention·parameter storage·return ABI 및 runtime 의미는 확정하지 않는다. 원시 전이
바이트와 segment hash는
[xdr-writeargs-control-transfer-evidence.json](xdr-writeargs-control-transfer-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
