# 121차 연속 검토 — map 함수군의 `WORD +0x28` writer inventory

## 판정

원본 export에서 `_vm_map`/`__vm_map` 이름군 27개의 모든 body fragment를 검사했다.
memory displacement가 `0x28`이고 operand width가 정확히 word인 access는 34개다.
Capstone operand access flag 기준 19개 read와 15개 write로 나뉜다. 이 방법은 같은
displacement의 dword map-field access를 의도적으로 제외한다.

15개 write 중 13개는 `MOV WORD PTR [...+0x28],0` clear다. insert/find의 새 entry
초기화, entry-unwire/delete, delete, copy-entry/copy, fork 경로에 분포한다. 나머지 두
write는 `_vm_map_pageable`에 있다. `0x00175e3f`는 word를 AX로 읽어 SI에 옮기고
`DEC SI` 뒤 `0x00175e47`에서 저장한다. `0x00175f4b`는 같은 흐름에서 `INC SI` 뒤
`0x00175f53`에서 저장한다.

이는 기존의 selected-path 관측보다 넓은 map-family writer inventory이다. 그러나
function prefix 밖의 alias, pointer provenance가 다른 `+0x28` field, computed memory
address, 그리고 runtime의 실제 도달 가능성은 이 정적 스캔만으로 제외하거나 확정할 수 없다.

## 한계

각 register가 같은 entry object를 가리킨다는 전 경로 증명, field 이름·자료형 범위,
overflow/underflow 처리, 동시성, and all-binary alias writers는 별도 원시 dataflow가
필요하다. 이 보고서는 operand width와 displacement가 일치하는 map-prefix body의
명령 인벤토리만 확정한다.

