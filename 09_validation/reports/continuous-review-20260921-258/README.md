# 258차 정적 검토 — _do_exit 및 analysis fragment의 self-loop 경계

원본 OPENSTEP x86 mach_kernel에서 _do_exit(0x00105afc)의 local export segment와 synthetic
analysis fragment __analysis_fragment_00105d58을 함께 검토했다. fragment는 3바이트
ADD ESP,4이며, 원시 바이트상 바로 뒤 local segment는 0x00105d5b에서 시작한다.

그 local segment의 마지막 두 바이트 0xebfe는 0x00105d78에서 자신으로 되돌아가는 short JMP다.
따라서 _do_exit body에는 직접 self-loop가 존재한다. fragment에 대한 직접 E8 rel32 caller는
없으며, _do_exit entry의 직접 E8 rel32 caller는 두 개다. 이는 indirect·computed edge를
제외한 결과다.

synthetic fragment의 decompiler 표현이나 self-loop의 도달 조건·runtime 의미는 확정하지 않는다.
원시 바이트, local segment hash 및 caller scan은
[do-exit-fragment-self-loop-evidence.json](do-exit-fragment-self-loop-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
