# 114차 연속 검토 — pmap additional-node retry와 temporary-node cleanup

## 판정

`_pmap_enter`의 physical-range additional-node path를 raw control flow로 재확인했다.
bucket의 primary map field가 already nonzero이고 local temporary-node slot `[EBP-0x0c]`이
zero일 때, 함수는 saved value `[EBP-0x10]`를 `_splx`에 전달하고 `pv_entry_zone`으로
`_zalloc`을 호출한다. 반환 EAX를 temporary slot에 저장한 뒤 `0x0019075c`로 jump한다.
그 target은 `_splvm` 호출부터 page-table lookup을 다시 시작한다.

재시도 뒤 additional node가 필요하면 temporary node의 `+8`, `+4`, `+0`을 순서대로
기록하고 bucket list head에 연결한 뒤 local slot을 0으로 만든다. 정상 끝에서는 saved
value로 `_splx`를 호출하며, local slot이 아직 nonzero일 때만 `_zfree(pv_entry_zone, slot)`
을 호출한다. 즉, retry 중 다른 변화로 node가 소비되지 않은 경우의 local cleanup은 raw
body에 직접 있다.

`_splvm` body는 `0x001e7714` global을 EAX로 읽고 return한다. `_pmap_enter` 자체에서
확인한 이 호출은 SPL acquisition의 완전한 증명이 아니다. 또한 `_zalloc` return 뒤 null
test가 없으므로, 이를 allocation-failure rollback이나 scheduler progress로 해석하지
않는다.

## 원시 검증

Python Capstone x86/32 decode checked 17 instructions covering the retry start, `_splx`,
`_zalloc`, retry jump, node link stores, final `_splx`, and conditional `_zfree`. All 17
assertions matched original bytes. Details: [`pmap-retry-evidence.json`](pmap-retry-evidence.json).

## 미해결

Interrupt-level semantics of all callers, interleaving across the retry window, `zalloc` zero
return behavior, and shared PV chain transformations in `pmap_remove`, `pmap_protect`, and
`pmap_copy_on_write` remain open.
