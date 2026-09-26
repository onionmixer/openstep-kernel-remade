# 109차 연속 검토 — vnode pager record table과 간접 dispatch

## 판정

원본 x86 명령으로 vnode pager의 runtime record table writer와 이를 사용하는 indirect
dispatch를 연결했다. `_vnode_pager_init`는 vnode pager zone을 만들고 lock 및 list
sentinel `0x001e7288/0x001e728c`를 초기화한다.

`_vnode_pager_file_init`는 새 record를 list에 연결하고 global count `0x001e7290`을
증가시킨다. 증가한 값을 record `+0x30`에 기록한 다음, 같은 값을 index로 하여
`0x001e7294[index] = record`를 수행한다 (`0x0017d75d`). 이 table의 record pointer는
`vnode_pagein`, `vnode_pageout`, `vnode_pager_truncate`, `vnode_dealloc` 및 helper
`FUN_0017cd58`에서 byte index를 통해 다시 읽힌다.

`_vm_pager_get`·`_vm_pager_put`·`_vm_pager_deallocate`·`_vm_pager_has_page`는 pager
pointer의 first dword로 device/vnode helper를 고르는 직접 분기다. 따라서 wrapper 자체는
function-pointer indirect call이 아니다. vnode path의 실제 indirect calls는 다음이다.

- `_vnode_pagein`: record table → `record+8` → `+0x1c` → `+0x74`, `CALL EAX`.
- `_vnode_pageout`: 같은 graph의 `+0x78`, `CALL EAX`.
- `_vnode_pager_truncate`와 `_vnode_dealloc`에도 별도 `CALL EAX`가 있다.

`_vnode_pager_shutdown`은 list를 unlink하고 global count를 감소시킨다. 이 함수 본문에는
`0x001e7294[index]` slot을 clear하는 명령이 없다. 현재 증거는 table write·read와 shutdown
unlist를 보일 뿐이며, index 재사용 및 stale entry의 실제 관측은 정적 범위 밖이다.

## 범위

원본 `mach_kernel`과 full-pass5 export만 사용했다. 모든 count와 address mapping은 Python
으로 산출하거나 원시 x86 instruction에서 직접 읽었다. table entry, record, vnode와
callback table의 C type·field 이름은 확정하지 않았다.

세부 evidence는 [`pager-dispatch-evidence.json`](pager-dispatch-evidence.json)에 있다.

## 미해결

callback `+0x74/+0x78`의 setter와 invoked function의 전체 계약, table index 재사용,
device branch, pagerfile branch, PV chain 및 pageout과 object lifetime의 모든 rollback은
계속 검토한다.
