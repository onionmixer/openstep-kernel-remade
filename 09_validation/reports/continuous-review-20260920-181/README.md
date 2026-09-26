# `_vm_map_insert` direct callers의 map-guard provenance 경계

179차의 guard-zero allocation 조건을 실제 direct call graph와 구분했다. 원본 `__text` 전체에서
`_vm_map_insert` entry `0x00174848`를 목표로 하는 `CALL rel32`는 세 site뿐이다:
`0x00173b99`, `0x00173dd5`, `0x00174229`. 각 caller의 map argument는 모두 caller의 첫
stack argument에서 직접 전달된다.

| caller | register holding first argument | map-insert call 직전 전달 |
|---|---|---|
| `_kmem_alloc` label | `ESI = [EBP+8]` | `PUSH ESI; CALL 0x00174848` |
| `_kmem_alloc_wired` label | `EBX = [EBP+8]` | `PUSH EBX; CALL 0x00174848` |
| `_kmem_alloc_zone` label | `EBX = [EBP+8]` | `PUSH EBX; CALL 0x00174848` |

세 caller는 insert 전에 같은 register를 `_vm_map_find` label의 direct call에도 전달한다.
따라서 이 direct-caller bodies 안에는 map-create 또는 fork allocation 결과를 local로 만들어
`_vm_map_insert`에 넘기는 edge가 없다. 178차의 fork-local `+0x2c=0` store가 insert의
guard-zero branch에 실제 도달한다는 결론은 이 direct graph에서 나오지 않는다.

이 검사는 direct `CALL rel32`만 다룬다. caller의 caller가 전달한 map pointer, indirect/
computed call, memory alias, function-pointer edge와 runtime map state는 계속 미확정이다.
따라서 179차의 stale-byte 조건은 가능 조건으로만 유지하며 발생 사실로 승격하지 않는다.

raw edge·argument flow는 [vm-map-insert-direct-caller-guard-boundary.json](vm-map-insert-direct-caller-guard-boundary.json)에 기록했다.
