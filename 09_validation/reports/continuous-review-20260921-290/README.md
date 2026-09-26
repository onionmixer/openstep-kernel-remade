# 290차 정적 검토 — _xdr_callhdr의 raw direct-control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _xdr_callhdr(0x00136a6c) 두 body segment 합계
118바이트를 원시 명령으로 검토했다. direct rel32 call은 5개이며 target은 0x00137a44
4개와 0x00137c58 1개다. conditional short branch 5개는 모두 0x00136ad8로 향하고,
unconditional short jump 1개는 0x00136ada로 향한다.

전체 __text의 직접 E8 rel32 target scan은 0x00135487 한 곳의 caller를 확인했다.
이는 indirect·computed caller edge를 제외한다. ABI·parameter storage·return ABI·runtime
의미는 확정하지 않는다.

원시 바이트와 segment hash는
[xdr-callhdr-control-transfer-evidence.json](xdr-callhdr-control-transfer-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
