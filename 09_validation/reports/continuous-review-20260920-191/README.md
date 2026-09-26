# VM-map prefix `dword +0x30` writer inventory와 object-field 분리

Object `+0x30` closure(190차)와 숫자 offset 충돌을 분리하기 위해 exact
`_vm_map*`/`__vm_map*` prefix의 `dword [register+0x30]` write operand를 전수 집계했다.
27 body(15,583 bytes, 5,635 instructions)에 writer는 29개다. `INC`가 22개, immediate
`1` store가 3개, register value `MOV` store가 4개다.

immediate one store는 map-create 한 곳과 map-fork 두 construction path에 있고, `INC`는
reference/clip/submap/protect/inherit/pageable/delete/copy/fork의 여러 path에 분포한다.
register `MOV` store는 deallocate, entry-delete, map-delete, map-copy에 하나씩 있다.
이 selected map-prefix writer set은 190차의 object-prefix explicit writer 한 개와 서로 다른
body set이다.

이는 같은 displacement `+0x30`이 원본 전체에서 단일 field identity를 뜻하지 않는다는
원시 operand 근거를 추가한다. map/object pointer provenance, alias/bulk writer,
non-export/differently named code, arithmetic wrap, runtime state와 object/entry lifetime은
이 name-scoped inventory로 확정하지 않는다.

전체 site와 Python counts는 [vm-map-field30-writer-inventory.json](vm-map-field30-writer-inventory.json)에 기록했다.
