# 260차 정적 검토 — _getdtablesize의 raw frame·return 경계

원본 OPENSTEP x86 mach_kernel의 _getdtablesize(0x00103e3c) 19바이트 body를 원시
명령으로 확인했다. 명령은 EBP frame 생성, absolute address 0x001e875c의 EAX load,
EAX+0x60 위치에 immediate 0x100 write, frame 복원 및 plain RET 순서다.

전체 __text의 직접 E8 rel32 target scan은 이 entry의 caller를 찾지 못했다. 이 결과는
indirect·computed caller edge를 제외한다. plain RET와 raw register·memory sequence만
확정하며, warning이 언급하는 calling convention·parameter storage·return value의 ABI
의미는 확정하지 않는다.

원시 바이트와 caller scan은 [getdtablesize-raw-interface-evidence.json](getdtablesize-raw-interface-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
