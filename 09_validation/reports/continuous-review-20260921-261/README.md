# 261차 정적 검토 — _fork의 raw wrapper 경계

원본 OPENSTEP x86 mach_kernel의 _fork(0x00106818) 14바이트 body를 원시 명령으로
확인했다. EBP frame 생성 뒤 immediate 0을 push하고 0x00106838으로 직접 call한 다음 frame을
복원하고 plain RET를 실행한다.

전체 __text의 직접 E8 rel32 target scan은 _fork entry의 caller를 찾지 못했다. 이 결과는
indirect·computed caller edge를 제외한다. direct callee address, push immediate, plain RET
순서만 확정하며, calling convention·parameter storage·callee 의미·return ABI는 확정하지 않는다.

원시 바이트와 caller scan은 [fork-raw-wrapper-evidence.json](fork-raw-wrapper-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
