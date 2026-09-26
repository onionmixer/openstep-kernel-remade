# 106차 — VM 범위 전환·삭제 계약과 재귀 잠금 호출자

OPENSTEP x86 원본 `mach_kernel`만 분석했다. 105차에서 미완료로 남긴 VM 범위의
`FUN_00173ebc`, `vm_map_pageable`, `vm_map_remove`/`vm_map_delete`와 wire/unwire,
page/object/pmap 보조 경로를 원본 명령으로 다시 대조했다. 지정된 recursive-lock 직접
호출 8개도 원본에서 확인했다.

이 결과는 선택한 VM 계약과 지정 재귀 호출자의 국소 검토를 완료한 것이다. 전체 VM,
모든 간접 호출, runtime 값·경합·소유권, 전체 커널 분석 완료를 뜻하지 않는다.

## 1. 반환·실패 계약

- `vm_map_remove` `0x1765ac`은 write lock을 잡고 map의 `+0x4c`을 증가시킨다. start는
  map `+0x14`보다 작으면 올리고, end는 `+0x18`보다 크면 내리며, end < start이면
  start=end로 바꾼다. 이후 `vm_map_delete(map,start,end)`의 EAX를 보존해 lock을 풀고
  반환한다. `vm_map_delete`의 정상 epilogue는 EAX=0이므로, 이 선택 경로에서
  `vm_map_remove`가 반환하는 값은 0이다. `zalloc` 실패는 rollback 반환이 아니라 panic
  호출로 간다.
- `vm_map_pageable` `0x175b2c`도 같은 clamp를 write lock 아래에서 수행한다. 네 번째
  물리 인자가 0인 경로는 대상 entry의 WORD `+0x28`을 증가시키며 old value가 0일 때
  object allocate/shadow를 수행하고, kernel map이면 lock을 푼 후 wire한다. 다른 map은
  recursive identity를 설정하고 write→read 전환한 뒤 wire, clear-recursive, done 순서로
  끝난다. 성공 반환은 0이다.
- 그 인자가 0이 아닌 경로는 먼저 대상 모든 entry의 `WORD[+0x28]`이 0이 아닌지 검사한다.
  하나라도 0이면 `lock_done` 뒤 EAX=4를 반환하며, 그 전까지의 start split은 되돌리지
  않는다. preflight 통과 뒤에는 count를 감소시키고 old value가 1인 entry에서 unwire한다.
  이 함수에는 하위 `vm_fault_wire`/`vm_fault_unwire` 결과를 소비하는 분기가 없다.
- `FUN_00173ebc` `0x173ebc`은 세 번째 인자가 0이면 즉시 1을 반환한다. nonzero일 때
  `vm_page_alloc_sequential`이 0을 반환하면 object interlock을 풀고 네 번째 인자가 0이면
  0을 반환한다. nonzero이면 page-needed wakeup/sleep 뒤 재시도한다. 성공 page마다
  `vm_page_zero_fill`, flag bit clear, `size -= page_size`, `address += page_size`가
  실행된다. size 정렬·underflow는 이 본문이 검사하지 않으므로 caller 계약이다.

## 2. delete와 수명 전환

`vm_map_delete` `0x176164`는 map lock을 새로 획득하지 않는다. caller가 보유한 lock을
전제로 cursor `map+0x38/+0x3c`를 갱신하고, 경계가 entry 내부이면 11 DWORD(44바이트)를
복사해 start/end split entry를 만든다. split마다 map `+0x1c`를 증가시키고, flag byte
`entry+0x18`의 mask 5에 따라 object reference 또는 `entry+0x10` 객체의 `+0x30` count를
증가시킨다.

삭제 entry마다 old WORD `+0x28`이 nonzero이면 `vm_fault_unwire` 후 명시적으로 0을
쓴다. 이어서 조건부 `vm_object_page_remove`, 조건부 `vm_object_pmap_remove`,
`pmap_remove`가 실행되고, entry는 doubly-linked map list에서 unlink된다. map `+0x1c`와
`+0x28`은 각각 감소한다. flag mask 5인 object path는 object `+0x30`을 감소시키고 0 이하
일 때 그 object map 전체 delete와 free 경로로 간다. 다른 path는 `vm_object_deallocate`를
호출한다. 두 번째 unwire 검사 위치도 원본에 있으나, 첫 경로가 WORD를 0으로 쓴 정상
순서에서는 다시 unwire하지 않는다.

`vm_fault_unwire`는 page-queue interlock 아래 매 page에서 `pmap_extract`가 0이면 panic,
그 외에는 `pmap_change_wiring(...,0)`, `vm_phys_to_vm_page`, `vm_page_unwire` 순서다.
`vm_phys_to_vm_page` 결과에는 이 caller의 NULL 검사가 없다. `pmap_change_wiring`도
mapping lookup 실패 시 panic 경로를 가지며 정상 반환값을 제공하지 않는다. 반대로
`vm_fault_wire`는 fast helper의 EAX가 nonzero일 때 일반 `vm_fault`를 호출하지만, 일반
fault EAX를 소비하지 않고 다음 page로 진행한다. 따라서 이 선택 범위는 success/rollback을
보장하지 않는다.

`pmap_pageable` `0x1914c8`은 RET만 있는 no-op이다. 이것은 상위 `vm_map_pageable`의
entry count/lock/object/pmap 효과를 no-op로 만드는 근거가 아니다. `pmap_remove` 역시
void이며 page-size literal을 이용한 TLB invalidation 또는 batch removal을 수행한다.

## 3. 지정 recursive-lock 호출자

| 호출자 | set_recursive | clear_recursive | 원본에서 확인한 범위 |
|---|---:|---:|---|
| `kmem_alloc_wait` | `0x174541` | `0x174560` | write lock 뒤 `vm_map_find` 호출을 감싸며, clear 뒤에 결과별 done/sleep/retry를 수행 |
| `vm_map_pageable` | `0x175ff0` | `0x17603e` | non-kernel map의 wire 경로에서 write→read 전환 뒤 wire loop를 감싸며, clear 뒤 done |
| `vm_map_copy` | `0x1776c0`, `0x177885` | `0x1778b3`, `0x1778c7` | entry kind에 따라 source/destination map을 재귀로 설정하여 nested `vm_map_copy`를 호출하고, 같은 map인지 비교한 조건으로 각 clear |

`lock_set_recursive`가 write bit만 확인한다는 기존 사실은 유지한다. 위 표는 해당 직접
호출의 지배적 해제 경로를 확인한 것이며, 호출자가 실제 lock owner인지 또는 간접 호출을
포함한 전체 recursive API 수명이 증명됐다는 뜻은 아니다.

## 검증

원본 SHA-256은
`33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다. 선택한 일반
본문 18개, body 9,659바이트, 명령 3,498개를 Python/Capstone 4.0.2 x86-32로 원본에서
정적으로 해독했다. 직접 CALL 156개와 conditional/unconditional J 계열 506개를 기록했다.
선택 본문의 body 범위·명령 길이와, 지정 recursive CALL 8개를 원본 바이트에 assertion했다.

상세 범위·한계는 [SCOPE.md](SCOPE.md), 디컴파일러 차이는
[DECOMPILER_ISSUES.md](DECOMPILER_ISSUES.md), 구조화된 증거는
[vm-contract-evidence.json](vm-contract-evidence.json), 후속 항목은
[OPEN_ITEMS.md](OPEN_ITEMS.md)에 있다.
