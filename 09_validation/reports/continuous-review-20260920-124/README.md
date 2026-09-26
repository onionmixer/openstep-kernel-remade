# 124차 연속 검토 — `_vm_map_copy` direct caller 전수의 반환 흐름

## 판정

원본 export가 기록한 `_vm_map_copy` direct unconditional call 13개(11 function)를 모두
원시 call 명령으로 확인했다. 118차의 네 public wrapper에 더해 나머지 아홉 site의
call 직후 흐름을 대조했다.

`_table`, `_smmap`, 두 anonymous function의 네 site, `_map_fd`, `_vm_map_fork`는 EAX
또는 이를 옮긴 EBX를 0과 비교해 분기한다. `_smmap`, `_table`, `_map_fd`와 anonymous
경로 일부는 비교 경로에서 `0x001747d8` call도 수행한다. 이는 call ordering의 관측이며
그 helper의 전체 lifetime 의미는 주장하지 않는다.

anonymous `0x0015cffc`와 `0x0015d050` site는 EAX를 EBX에 저장한 다음 helper/deallocate
call을 수행하고서 `TEST EBX,EBX`로 분기한다. `0x0015d51c`는 EAX를 직접 test하며,
비0이면 EBX를 5로 설정한다. `_vm_map_copy` 내부의 recursive site `0x001778a2`는
stack 정리 뒤 map-pointer 비교와 lock helper call로 진행하며, 이 직후 EAX test/store는
없다.

이미 확인한 `_vm_move`, `_vm_read`, `_vm_write`, `_vm_copy`는 각각 저장·test·반환,
저장·test·복원 반환, 그리고 EAX를 쓰지 않는 epilogue 반환 경로를 유지한다.

## 한계

이 전수는 export의 direct unconditional calls만이다. indirect/computed callers,
helper 내부 rollback/lock, branch 이후의 전체 transaction, numerical status meaning은
미해결이다.

