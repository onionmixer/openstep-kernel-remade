# 115차 연속 검토 — vm_map_fork entry 출구와 parent lock epilogue

## 판정

원본 `_vm_map_fork` body는 시작에서 input map을 `_lock_write`에 전달하고 input map `+0x4c`
dword를 증가시킨다. 함수가 직접 디코드된 범위에는 하나의 `RET`만 있으며, tail은 parent
`+0x28` dword를 child map `+0x28`로 옮긴 후 input parent pointer로 `_lock_done`을 호출하고
child pointer를 EAX로 반환한다.

entry loop에서 `_vm_map_copy` call 결과는 `TEST EAX,EAX`로 검사한다. zero면 곧바로 같은
tail로 진행하고, nonzero면 diagnostic helper call 뒤 `JMP 0x00177ff0`로 같은 tail에 합류한다.
이 원시 control flow는 fork body의 직접 error-return/child-destroy rollback을 보이지 않는다.
그러나 helper가 내부에서 수행할 정리나 diagnostic call의 non-return 성질은 이 사실만으로
배제할 수 없다.

다른 entry branch에서 `WORD +0x28`이 nonzero면 `_vm_fault_unwire`을 호출한 직후 0으로
쓴다. 또 separate branch는 `_vm_fault_copy_entry`를 직접 호출한다. 따라서 fork body가
copy helper, unwire, fault-copy entry를 선택하는 위치와 parent unlock의 순서를 raw bytes로
연결했다.

Python Capstone contiguous decode span은 1,461 bytes와 477 instructions이며 28 direct
calls와 1 `RET`를 보였다. Exported function body aggregate는 1,437 bytes다. 이 차이는
export body fragment의 합과 raw start-to-ret span의 측정 기준 차이이므로 상호 대체하지
않는다.

## 원시 검증

- parent write lock / interlock increment: `0x00177a80`..`0x00177a89`.
- `_vm_map_copy` result merge: `0x00177e1a`..`0x00177e37`.
- unwire and clear: `0x00177e58`..`0x00177e62`.
- fault-copy entry call: `0x00177fe8`.
- parent `+0x28` transfer, `lock_done`, child return, sole `RET`: `0x00178007`..`0x00178028`.

Details: [`map-fork-exit-evidence.json`](map-fork-exit-evidence.json).

## 미해결

All helper-internal rollback/locking, non-return paths, child map destruction after a helper
failure, and cross-caller lock ordering still need separate raw analysis.
