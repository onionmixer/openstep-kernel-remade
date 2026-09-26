# 286차 정적 검토 — _xdr_rmtcallres의 direct·indirect control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _xdr_rmtcallres(0x001361f4) 두 body segment 합계
88바이트를 원시 명령으로 검토했다. direct rel32 call은 0x00138774와 0x00137a44에 각각
하나씩이며, raw CALL EAX는 하나다. conditional short branch는 2개, unconditional short
jump는 1개다.

전체 __text의 직접 E8 rel32 target scan은 이 entry의 caller를 찾지 못했다. indirect
call target, ABI·parameter storage·return ABI·runtime 의미는 확정하지 않는다.

원시 바이트와 segment hash는
[xdr-rmtcallres-control-transfer-evidence.json](xdr-rmtcallres-control-transfer-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
