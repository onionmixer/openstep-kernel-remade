# 140차 연속 검토 — map entry word `+0x28`과 `_vm_fault_unwire` direct caller 전수

원본 export에서 `_vm_fault_unwire` (`0x001735f4`) direct unconditional call은 9개다.
entry-unwire, entry-delete, delete 두 path, copy-entry, copy 두 path, fork의 8개 site는
nonzero `WORD [...+0x28]` 검사 뒤 helper call을 하고 해당 word를 0으로 쓴다.

나머지 `_vm_map_pageable` site `0x00175e56`은 word를 AX로 읽어 decrement한 뒤 저장하고,
prior AX가 1일 때 helper를 호출한다. 따라서 이 direct-caller inventory에서 helper call은
selected word lifecycle transitions와 함께 관측된다.

이는 map-prefix function들의 raw instruction order다. field type·counter semantics,
helper 내부 작업, indirect callers, computed aliases, and runtime reachability는 이
보고서에서 확정하지 않는다.

