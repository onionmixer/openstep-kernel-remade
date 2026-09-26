# 285차 정적 검토 — _xdr_rmtcall_args의 direct·indirect control-transfer inventory

원본 OPENSTEP x86 mach_kernel의 _xdr_rmtcall_args(0x00136114) 세 body segment 합계
218바이트를 원시 명령으로 검토했다. direct rel32 call은 5개이며 모두 0x00137a44를
target으로 한다. raw CALL EAX 명령은 6개이고, 조건 분기는 6개, unconditional short
jump는 2개다.

전체 __text의 직접 E8 rel32 target scan은 이 entry의 caller를 찾지 못했다. indirect
call target, call의 의미, ABI·parameter storage·return ABI·runtime 의미는 확정하지
않는다.

원시 바이트와 segment hash는
[xdr-rmtcall-args-control-transfer-evidence.json](xdr-rmtcall-args-control-transfer-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
