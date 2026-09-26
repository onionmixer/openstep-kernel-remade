# 139차 연속 검토 — vnode pager record count/table base reference 전수

모든 export function body에서 vnode pager count `0x001e7290`과 indexed table base
`0x001e7294` memory operand를 검사했다. count는 reference 6개, write 2개이며
`_vnode_pager_file_init`의 increment와 `_vnode_pager_shutdown`의 decrement다.

table base는 reference 9개, write 1개다. 유일한 write는 `_vnode_pager_file_init`
`0x0017d75d MOV [EAX*4+0x001e7294],ESI`다. 나머지 8개는 `FUN_0017cd58`, pagein,
pageout, truncate, vnode_dealloc의 indexed reads다.

이는 exact-displacement export-body inventory다. indexed EAX의 범위, table slot의
초기값/clear, computed base alias, non-exported code, and runtime concurrency는 이 정적
결과로 확정하지 않는다.

