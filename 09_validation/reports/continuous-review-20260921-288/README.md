# 288차 정적 검토 — _xdr_des_block의 raw wrapper inventory

원본 OPENSTEP x86 mach_kernel의 _xdr_des_block(0x00136608) 단일 22바이트 body를
원시 명령으로 확인했다. entry에서 세 push 뒤 direct rel32 call 하나가 0x00137cac을
target으로 하고, frame 복원과 plain RET로 끝난다.

전체 __text의 직접 E8 rel32 target scan은 이 entry의 caller를 찾지 못했다. 이는
indirect·computed caller edge를 제외한다. operand·callee 의미, ABI·parameter storage·return
ABI·runtime 의미는 확정하지 않는다.

원시 바이트와 hash는 [xdr-des-block-raw-wrapper-evidence.json](xdr-des-block-raw-wrapper-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
