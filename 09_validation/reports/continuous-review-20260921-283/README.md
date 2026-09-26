# 283차 정적 검토 — _clnt_sperrno의 raw branch inventory

원본 OPENSTEP x86 mach_kernel의 _clnt_sperrno(0x00135dbc) 두 body segment 합계
51바이트를 원시 명령으로 검토했다. direct rel32 call은 없고, conditional short branch는
2개, unconditional short jump는 1개다. branch target은 각각 0x00135ddc,
0x00135dcc이며 jump target은 0x00135dea다.

전체 __text의 직접 E8 rel32 target scan은 0x0012f0dc와 0x0012f11a의 두 caller를
확인했다. 이는 indirect·computed caller edge를 제외한다.

이 검토는 byte-level branch inventory다. operand·상수·분기 조건·반환값·calling
convention 및 runtime 의미는 확정하지 않는다. 원시 바이트와 segment hash는
[clnt-sperrno-branch-evidence.json](clnt-sperrno-branch-evidence.json)에, 재검증 입력
해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
