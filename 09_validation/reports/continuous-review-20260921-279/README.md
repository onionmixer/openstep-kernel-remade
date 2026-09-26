# 279차 정적 검토 — _xdr_diropres의 raw wrapper·two-return 경계

원본 OPENSTEP x86 mach_kernel의 _xdr_diropres(0x001348f0) 49바이트 body를 원시
명령으로 확인했다. body는 two immediate push, pointer-relative LEA, 세 register push 뒤
0x00137efc으로 direct rel32 call한다. 이어지는 conditional branch는 두 plain RET path 중
0x00134918 쪽으로 향한다.

전체 __text의 직접 E8 rel32 target scan은 이 entry의 caller를 찾지 못했다. 이는
indirect·computed caller edge를 제외한다. stack slot·immediate·callee·branch의 의미,
calling convention·parameter storage·return ABI는 확정하지 않는다.

원시 바이트와 caller/control-transfer evidence는
[xdr-diropres-raw-wrapper-evidence.json](xdr-diropres-raw-wrapper-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
