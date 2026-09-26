# `vm_map_insert` direct allocation call-tree의 guard-root 집계

181–183차의 direct edges를 합쳐 `vm_map_insert`까지 이어지는 allocation helper call-tree의
static map roots를 집계했다. 세 direct insert caller는 `_kmem_alloc`, `_kmem_alloc_wired`,
`_kmem_alloc_zone`이며, 이 three helper에 대한 전체 direct `CALL rel32` source site는 22개다.

| helper | direct source sites | map root source 분포 |
|---|---:|---|
| `_kmem_alloc` | 3 | `0x001f6330`: 1, `0x001f622c`: 2 |
| `_kmem_alloc_wired` | 17 | `0x001e8de8`: 12, `0x001f6330`: 5 |
| `_kmem_alloc_zone` | 2 | `0x001f6330`: 1, `0x001dfcec`: 1 |

182·183차의 raw provenance에서 네 root 모두 `_vm_map_create` return으로 이어지고, 그 helper는
allocation result의 `+0x2c`에 1을 저장한다. 따라서 이 **direct rel32 allocation-call tree의
정적으로 식별 가능한 source**에는 fork-local `+0x2c=0` constructor value가 등장하지 않는다.

이는 `vm_map_insert` guard가 항상 nonzero라는 전역 결론이 아니다. map field의 later write,
indirect/computed caller, input argument alias, allocation helper의 actual path/return과 runtime
interleaving은 이 tree 밖이다. 179차 stale-word 조건은 그런 미확정 route에서만 여전히 가능한
조건으로 보존한다.

call-site 분류와 count는 [vm-map-insert-direct-allocation-root-inventory.json](vm-map-insert-direct-allocation-root-inventory.json)에 기록했다.
