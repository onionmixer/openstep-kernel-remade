# 287차 정적 검토 — _xdr_callmsg의 원본 control-transfer 집계

원본 OPENSTEP x86 mach_kernel의 _xdr_callmsg(0x00136250) 네 body segment 합계
887바이트를 정적 검토했다. Python이 full-pass5 instruction listing의 각 명령 주소·길이를
원본 바이트와 대조하며 집계한 결과는 direct rel32 call 17개, raw CALL EAX 5개,
conditional branch 34개, unconditional jump 6개, plain RET 1개다.

전체 __text의 직접 E8 rel32 target scan은 0x00137648 한 곳의 caller를 확인했다.
이는 indirect·computed caller edge를 제외한다. indirect target과 모든 전이의 의미,
ABI·parameter storage·return ABI·runtime 의미는 확정하지 않는다.

집계와 segment hash는
[xdr-callmsg-control-transfer-inventory.json](xdr-callmsg-control-transfer-inventory.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
