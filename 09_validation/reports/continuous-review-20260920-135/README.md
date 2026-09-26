# 135차 연속 검토 — `_pmap_create` direct caller와 map creation 체인

원본 `_pmap_create`는 argument가 nonzero이면 `XOR EAX,EAX`로 복귀한다. 0이면 zone allocation
후 EAX=allocated pointer로 복귀한다. allocation result가 0이면 panic call 뒤 계속되는
형태다.

export direct caller는 7개다. `_smmap`, `FUN_00108cec`, `FUN_0015ce08`,
`FUN_0015d3fc`, `_map_fd`, `_task_create`의 6개는 call 뒤 EAX를 push하여
`0x001746a0 _vm_map_create`에 전달한다. `_vm_map_fork`는 `0x00177a96`에서 EAX를 local
`-0x18`에 저장한다. 이 관측은 pmap 생성 결과가 map creation/fork에 전달되는 원시 경로를
보여 주며 allocation lifetime·failure recovery는 확정하지 않는다.

