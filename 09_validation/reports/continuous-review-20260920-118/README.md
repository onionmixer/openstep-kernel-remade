# 118차 연속 검토 — `_vm_map_copy`의 public wrapper 반환 경로

## 판정

원본 x86 명령으로 `_vm_move`, `_vm_read`, `_vm_write`, `_vm_copy` 네 직접 caller의
`_vm_map_copy` 반환 레지스터 경로를 확인했다. 이 묶음은 117차의 caller inventory 중 이
네 함수에만 한정하며, 모든 caller 또는 helper 내부의 rollback을 완료 판정하지 않는다.

`_vm_move`는 call `0x00178778` 뒤 EAX를 EBX에 저장하고 `TEST EBX,EBX`를 한다.
0이 아니면 `0x001787a1`의 helper call을 거쳐, `0x001787a6 MOV EAX,EBX` 및 RET로
반환한다. 0이면 output pointer에 값을 쓰고 같은 EAX=EBX 반환 tail로 합류한다.

`_vm_read`는 call `0x0017c82d`의 EAX를 local `-0xc`에 저장하고 `TEST EAX,EAX`를
한다. 0 경로에서만 두 output pointer에 값을 쓴다. 비0 경로는 조건부 helper call을
거칠 수 있고, `0x0017c879 MOV EAX,[EBP-0xc]`로 저장했던 반환값을 복원하여 RET한다.

`_vm_write`와 `_vm_copy`는 각각 `0x0017c8d1`, `0x0017c933` call 직후 epilogue/RET로
간다. 그 사이 EAX를 쓰는 명령은 이 직접 tail에 없다. 따라서 두 wrapper는 이 경로에서
callee EAX를 그대로 반환한다.

각 call은 원시 push 7개로 직전 인수를 쌓고 call 뒤 `ADD ESP,0x1c`를 사용하는 곳도
있다. Python 계산상 7 dword는 28 bytes이다. 이 수는 호출 규약의 전체 증명이 아니라
관측된 네 site의 stack 사용 사실을 보조한다.

## 범위와 한계

이 보고서는 숫자 EAX 값을 오류 상수로 번역하지 않는다. `0x001787a1`과
`0x0017c874` helper call의 내부 동작, output pointer의 객체 타입, side effect의
원자성, 그리고 나머지 7개 direct caller의 반환/정리 계약은 미해결이다.

