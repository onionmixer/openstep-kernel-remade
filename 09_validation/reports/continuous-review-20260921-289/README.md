# 289차 정적 검토 — _xdr_replymsg의 원본 control-transfer 집계

원본 OPENSTEP x86 mach_kernel의 _xdr_replymsg(0x00136720) 13개 body segment 합계
817바이트를 정적 검토했다. Python이 full-pass5 instruction listing의 명령 주소·길이를
원본 바이트와 대조하며 집계한 결과는 direct rel32 call 18개, raw CALL EAX 6개,
conditional branch 32개, unconditional jump 13개, plain RET 1개다.

전체 __text의 직접 E8 rel32 target scan은 0x001359c6와 0x0013772a의 두 caller를
확인했다. indirect target과 모든 전이의 의미, ABI·parameter storage·return ABI·runtime
의미는 확정하지 않는다.

집계와 segment hash는
[xdr-replymsg-control-transfer-inventory.json](xdr-replymsg-control-transfer-inventory.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
