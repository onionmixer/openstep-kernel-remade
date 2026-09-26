# 119차 연속 검토 — `vm_fault` direct caller 전수의 반환 레지스터 경로

## 판정

원본 export의 direct unconditional call inventory에서 `0x00172038 _vm_fault`를 목표로 하는
site는 5개이며, 모두 원본 call 명령으로 다시 확인했다. 이 보고서는 각 site의 call 직후
제어·레지스터 경로를 다룬다. callee 내부의 status 값에 이름을 붙이거나 caller helper의
전체 동작을 추정하지 않는다.

`_vm_fault_wire` (`0x001735d5`)는 call 뒤 stack을 정리하고 loop index를 증가시킨다.
그 뒤의 원시 명령은 반환 EAX를 test·compare·store하지 않는다. 따라서 이 wire loop의
이 call site는 반환 레지스터를 직접 분기 조건으로 사용하지 않는다는 사실만 확정된다.

`_user_trap` (`0x00192000`)은 EAX를 local `-0x14`에 저장하고 stack 정리 뒤 그 local을
0과 비교한다. 비0 분기는 그 값을 별도 local `-0x1c`에 옮겨 분기한다.

`_kernel_trap` (`0x001921e7`)도 EAX를 local `-0xc`에 저장한다. stack 정리 및 한
global 검사 뒤 이 local을 0과 비교한다. 비0 분기는 helper call 및 그 helper EAX 검사로
이어진다.

`FUN_001923e0` (`0x0019242d`)은 call 직후 frame을 복원하고 RET한다. 해당 tail에는
EAX 쓰기가 없으므로 이 direct path에서 callee EAX가 wrapper EAX 반환값으로 보존된다.
`_PCexception` (`0x001a143c`)은 EAX를 EDX로 옮기고, 다른 상태 byte를 복원·stack 정리한
다음 `TEST EDX,EDX`로 분기한다.

다섯 call 모두 원시 push 5개로 직전 인수를 쌓고, Python 계산상 5 dword는 20 bytes다.
이는 관측된 call site의 stack 준비를 보조하는 수치이며 전체 ABI 증명은 아니다.

## 한계

이 전수는 export가 기록한 direct unconditional calls에 한정한다. indirect/computed
calls, helper 내부의 rollback·lock, 이후의 trap recovery, 동시성 및 EAX 수치의 오류명은
여전히 별도 추적 대상이다.

