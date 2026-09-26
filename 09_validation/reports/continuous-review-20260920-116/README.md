# 116차 연속 검토 — vm_map_deallocate direct-caller inventory

## 판정

원본 export reference inventory에서 `_vm_map_deallocate` (`0x001747d8`)의 direct
unconditional call 37개를 찾았고, 이들은 27개 caller function에 분포한다. 전부 indirect
call 또는 decompiler-inferred edge가 아니라 original call instruction의 export reference다.

callee 자체는 non-null input에서 `+0x34` interlock을 얻어 `+0x30`을 감소시킨다. 감소 전
값이 양수이면 바로 epilogue로 간다. 0 이하이면 `_lock_write`, `+0x4c` increment,
`_vm_map_delete`, `_pmap_destroy`, `_zfree` 순서를 실행한다. 함수 tail에는 EAX로 상태값을
만드는 명령이 없으므로 direct callers에 성공/실패 return contract를 부여하지 않았다.

각 37 call 뒤의 세 원시 명령(총 111 instructions)을 Python dataflow로 검사했다. call
반환 후 EAX가 overwrite되기 전 EAX를 `TEST`/`CMP`하는 경우는 0개였다. 이는 단지 세
instruction window의 결과이며, caller가 그 이후 반환 레지스터를 사용하지 않는다는 전체
증명은 아니다.

## caller inventory

`caller-groups`와 site 목록은 [`map-deallocate-callers.json`](map-deallocate-callers.json)에
보존했다. 이름 없는 entry도 원본 function address와 call site를 그대로 기록했다.

## 미해결

Direct caller inventory는 indirect or computed calls, caller-local ownership semantics,
helper-internal locking, and lifetime after the three-instruction window를 완료하지 않는다.
각 task/IPC/driver caller의 object graph는 별도 원시 추적이 필요하다.
