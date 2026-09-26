# 130차 연속 검토 — `_vm_object_copy` direct caller와 output flag 소비

원본 export에서 `_vm_object_copy` (`0x001793b0`)의 direct unconditional call은 3개다.
`_vm_map_copy_entry`의 `0x00176812`, `_vm_map_copy`의 `0x001775ff`, `_vm_map_fork`의
`0x00177f6f`가 해당한다. 세 site 모두 stack 정리 뒤 local `[EBP-4]`를 0과 비교한다.
call 직후 EAX를 test/compare하지 않는다.

이는 107차에서 기록한 object-copy output flag의 map copy/fork 소비를 direct-caller
전수로 재확인한 것이다. local의 전체 provenance, flag의 이름·값 의미, object-copy
내부 allocation failure, and indirect callers는 이 관측으로 확정하지 않는다.

