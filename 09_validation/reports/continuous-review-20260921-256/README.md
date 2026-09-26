# 256차 정적 검토 — _halt_cpu의 HLT self-loop

원본 OPENSTEP x86 mach_kernel의 _halt_cpu(0x0018cea0) export body를 원시 명령으로
검증했다. 마지막 3바이트는 HLT와 HLT 주소 0x0018cf50으로 되돌아가는 short JMP다.

terminal block 앞에는 parameter bit test, JZ, 두 immediate push, 직접 call 및 NOP 두 개가
있다. 이 명령 순서는 loop에 도달하기 전의 정적 byte sequence일 뿐, I/O·power-state·HLT의
runtime 의미나 loop 도달 조건을 확정하지 않는다.

전체 __text의 직접 E8 rel32 scan은 이 entry의 caller 한 개를 확인했고, _panic body의
0x0010cab4다. 간접·계산된 caller edge는 포함하지 않는다. 원시 바이트와 segment hash는
[halt-cpu-self-loop-static-evidence.json](halt-cpu-self-loop-static-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
