# pmap bootstrap page-size derived globals의 static initializer boundary

`_pmap_bootstrap` label의 page-size dependent globals를 raw writer까지 분리했다.
`0x0018eefa MOV EDX,[0x001e0d0c]` 후 `EAX=EDX`, `SHR EAX,2`, `SHL EAX,0xc`가
`0x0018ef08 MOV [0x001f7ae8],EAX`로 이어지고, EDX의 `SHR 0xc`는
`0x0018ef10 MOV [0x001f7ae0],EDX`로 이어진다.

173차의 page-size static initializer `0x2000`과 helper return을 전제로 Python으로 계산하면
두 결과는 각각 `0x00800000` (8,388,608)과 `2`다. full-pass5 exported body의 exact absolute
write audit에서 두 global은 각각 이 bootstrap store 하나만 갖는다.

원본 `__text`의 `CALL rel32` target scan에서 bootstrap entry `0x0018eee8`의 direct site는
`0x0018ab7f` 하나다. 이는 173차의 `_start → _i386_init` direct path 내부이며 page-size helper
call 뒤에 놓인다. 따라서 shown static calls가 복귀하면 pmap derived-global store는 page size
setup 뒤에 있다.

이것은 runtime global 값의 관측이나 pmap bootstrap 성공 증명이 아니다. indirect/computed
bootstrap caller, source global 변경, non-export/alias writer, call failure, later overwrite와
live pmap lifetime은 계속 이 증거 범위 밖이다.

원시 sequence·Python 결과·writer/caller count는 [pmap-bootstrap-page-derived-globals.json](pmap-bootstrap-page-derived-globals.json)에 기록했다.
