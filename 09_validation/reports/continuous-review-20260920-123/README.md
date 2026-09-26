# 123차 연속 검토 — `_vm_map_fork` direct caller inventory

원본 export `references.tsv`에서 `0x00177a74 _vm_map_fork`를 목표로 하는 direct
unconditional call은 1개다. `_task_create`의 `0x00165a8a CALL 0x00177a74`가 그 site다.
call 직후 `0x00165a8f MOV [EBX+0xc],EAX`로 반환값을 저장하고, stack 정리 후 공통
초기화 주소 `0x00165ac5`로 jump한다. 이 관측 범위에서 EAX의 null/error test는 없다.

이는 export가 기록한 direct call 하나의 흐름만 확정한다. indirect/computed call, `[EBX+0xc]`
field의 type/lifetime, fork 내부의 rollback, and later task initialization outcome은 미해결이다.

