# 정확한 VM-map prefix의 WORD `+0x28` writer closure

Map-entry WORD `+0x28`의 direct static writer를 정확한 `_vm_map*`/`__vm_map*` prefix
전체에서 다시 집계했다. 27 body(15,583 bytes, 5,635 instructions)에는 exact decoded
`word ptr [register+0x28]` write operand가 15개 있다. 13개는 immediate zero store이고,
나머지 2개는 `_vm_map_pageable`의 `MOV [EBX+0x28],SI`다.

zero stores는 insert/find의 guarded construction site, entry-unwire/delete, map-delete 두
path, copy-entry, map-copy 네 path, map-fork 두 path에 분포한다. variable stores는
`0x00175e47`과 `0x00175f53`이며 기존 raw control-flow evidence에서 각각 decrement/increment
path의 computed SI를 기록한다.

따라서 exact VM-map prefix body라는 범위에서 이 field를 명시적으로 write하는 instruction은
위 15개가 전부다. 178–184차의 direct map-root chain은 insert/find construction context를,
112·140차는 pageable/delete transition·unwire ordering을 보강한다.

이 closure는 numeric offset과 word width에 대한 것이다. 구조체 identity, arithmetic alias,
bulk copy, pointer-derived/non-export writer, indirect caller, runtime iteration 및 live entry
lifetime은 이 static operand inventory 밖이다.

전체 site 목록과 Python 집계는 [vm-map-word28-writer-closure.json](vm-map-word28-writer-closure.json)에 기록했다.
