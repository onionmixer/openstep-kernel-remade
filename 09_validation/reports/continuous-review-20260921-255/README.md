# 255차 정적 검토 — _PMSetCpuState HLT 경로와 decompiler infinite-loop 경고 경계

원본 OPENSTEP x86 mach_kernel의 _PMSetCpuState(0x00187460)를 원시 바이트로 검토했다.
entry에는 absolute memory operand를 비교한 뒤 0x001874e0로 가는 직접 JZ가 있다. 해당 block은
TEST EAX,EAX; JNZ 0x001874e5; HLT이며, HLT 바로 뒤에는
XOR EAX,EAX; MOV ESP,EBP; POP EBP; RET가 놓여 있다.

따라서 body에는 HLT 주소로 돌아가는 직접 self-branch가 없다. 이 사실은 export-derived
infinite-loop warning의 실제 동작·정확성을 판정하지 않는다. __stack_attach의 원시 HLT
self-loop와도 구별한다.

전체 __text의 직접 E8 rel32 scan은 이 entry에 대한 두 caller site를 확인했으며 둘 다
_idle_thread_continue body 안에 있다. 간접·계산된 caller edge는 포함하지 않는다. 원시
바이트와 segment hash는 [pmsetcpustate-hlt-static-evidence.json](pmsetcpustate-hlt-static-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
