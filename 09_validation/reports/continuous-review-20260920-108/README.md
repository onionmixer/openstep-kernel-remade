# 108차 연속 검토 — VM 초기화와 map-entry `+0x28`의 구분

## 판정

원본 x86 명령으로 VM runtime 초기화 순서와 page-size 파생 전역을 확인했다.
`_i386_init`는 `0x0018ab2b`에서 `page_size` 전역에 `0x2000`을 저장하고,
`0x0018ab35`에서 `_vm_set_page_size`를 호출한다. Python 계산 결과 page size는 8192,
mask는 `0x1fff`, shift는 13이다. `_vm_set_page_size`는 `page_size-1`을 mask 전역에
기록하고, 1을 왼쪽 shift하여 page size와 같아질 때까지 shift 전역을 증가시킨다.

`_i386_init`는 이어서 `_pmap_bootstrap`을 호출한다. `_vm_mem_init`의 직접 call 순서는
`vm_page_startup`, `zone_bootstrap`, `vm_object_init`, `vm_map_init`, `kmem_init`,
`pmap_init`, `zone_init`, `vm_object_pager_wakeup`, `vm_pager_init`, `vm_user_init`이다.
이 순서는 해당 함수들이 성공하거나 초기화를 모두 마친다는 증명이 아니다.

`_vm_page_init`는 `_vm_page_template` 주소에서 destination으로 `rep movsd` 12회,
즉 Python 계산으로 48바이트를 복사한다. 뒤이어 page physical address를 page shift로
나누고 bucket-mask 전역과 결합하여 queue-lock array index를 만들며, 새 page를 list에
연결하고 byte `+0x20` bit `0x04`를 설정한다.

`_vm_object_init`는 object zone 및 object hash-entry zone을 만들고, object hash와
cache list의 sentinel 전역을 초기화한다. 마지막에는 두 static object storage에
`__vm_object_allocate`를 호출한다. `_vm_map_init`는 map zone, entry zone, kernel-entry
zone을 만들고 두 allocator에 초기 값을 준다. `_vm_map_create`는 새 **map**의 `+0x28`을
0으로, `+0x30`과 `+0x2c`을 1로 설정한다.

따라서 map 자체의 dword `+0x28`과 map entry의 WORD `+0x28`은 같은 offset이지만 서로
다른 구조체의 field다. 이들을 합쳐 하나의 counter로 해석하면 안 된다.

entry를 만드는 `_vm_map_insert`는 새 entry를 allocator에서 얻어 범위·object·protection
field를 기록하며, parent map `+0x2c`가 0이 아닐 때에만 새 entry WORD `+0x28`을 0으로
명시 기록한다. `vm_map_pageable`는 이 word를 읽고 감소 또는 증가시키며, delete helpers는
nonzero인 경우 `vm_fault_unwire`를 호출한 후 0으로 기록한다. split path는 `rep movsd`
11회로 entry의 44바이트를 복사한다. 따라서 현재 근거로 확정된 것은 직접 초기화·복사·
증감·삭제 write이며, 모든 entry 생성자와 alias writer의 완전 목록은 아니다.

`_pmap_bootstrap`는 page size에서 파생한 두 전역을 기록하고 bootstrap page-directory를
준비한 후 여러 구간을 page 단위로 순회하며 PDE/PTE를 갱신하고 CR3를 다시 load한다.
끝에서 CR3를 새 값으로 쓰고 CR0에 `0x80010000`을 OR한다. `pmap_init`는 page range
입력에서 resident table 영역과 세 zone을 만들며 sentinel 전역을 초기화한다.

## 근거와 한계

- 원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`
- 정적 디코드: Python `capstone`, original Mach-O `__text`
- 수치·copy length·function별 instruction/call count는 Python으로 계산했다.

세부 명령 evidence는 [`vm-init-entry-evidence.json`](vm-init-entry-evidence.json)에,
입력과 보고서의 hash 검증은 [`preservation.json`](preservation.json) 및
[`checkpoint.json`](checkpoint.json)에 있다.

## 계속 조사할 것

page/object/map/pmap의 간접 dispatch table, 모든 alias writer, runtime allocator의
success/failure 상태, page template의 생성 writer, object `+0x30`의 전체 수명 및 모든
entry WORD `+0x28`의 생성 경로는 남아 있다. pager와 PV의 dispatch table도 이 보고서의
완료 범위에 포함되지 않는다.
