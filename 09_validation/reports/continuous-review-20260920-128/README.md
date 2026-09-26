# 128차 연속 검토 — vnode pager dispatch slot의 static writer 경계

원본 vnode dispatch table의 pagein/pageout slot 8개를 원시 data에서 읽고, 모든 export
function body의 absolute write를 전수 검사했다. slot 값은 nfs `0x001338c0/0x00133de4`,
fifo `0x00139b14/0x00139b14`, spec `0x00139444/0x00139444`, ufs
`0x00145848/0x00145bbc`다. 이 8 slot의 absolute writer 수는 0개다.

이는 113차에서 확인한 `_vnode_pagein`의 `+0x74`와 `_vnode_pageout`의 `+0x78` 간접
call 흐름에 대한 static table 보강이다. writer 0은 export body의 absolute store가 없다는
뜻일 뿐, loader/BSS 동작, computed address store, non-exported code, runtime 불변성을
증명하지 않는다.

