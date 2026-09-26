# 284차 정적 검토 — _xdr_pmap의 raw direct-control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _xdr_pmap(0x001360c0) 두 body segment 합계 82바이트를
원시 명령으로 검토했다. direct rel32 call은 4개이며 모두 0x00137a44를 target으로 한다.
conditional short branch는 3개이며 모두 0x00136108로 향하고, unconditional short jump
1개는 0x0013610a로 향한다.

전체 __text의 직접 E8 rel32 target scan은 이 entry의 caller를 찾지 못했다. 이는
indirect·computed caller edge를 제외한다. 이 검토는 byte-level transfer inventory이며,
ABI·parameter storage·return ABI·runtime 의미는 확정하지 않는다.

원시 바이트와 segment hash는
[xdr-pmap-control-transfer-evidence.json](xdr-pmap-control-transfer-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
