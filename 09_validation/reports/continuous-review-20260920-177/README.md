# `__vm_object_allocate` direct construction closure의 `+0x30` 초기 byte provenance

Object `+0x30`의 별도 lifetime을 좁히기 위해 template-copy helper `0x00178ba8`의 모든
원본 `CALL rel32` site를 `__text` 전체에서 계산했다. target은 5회뿐이며, 두 번은
`_vm_object_init`의 static destinations, 한 번은 allocation wrapper, 한 번은
`_vm_object_copy`, 한 번은 `_vm_object_shadow`다.

Helper의 raw body는 source `0x001f7360`, destination second argument, `ECX=0x16`,
`REP MOVSD`를 사용한다. Python 계산으로 22 dword는 88 bytes이고 `+0x30`은 그 copy
범위에 포함된다. template의 같은 offset 주소 `0x001f7390`은 `_vm_object_init`에서
`MOV dword ptr [0x001f7390],0`로 clear된다. 따라서 이 static template-clear가 먼저
실행되고 helper가 정상 수행한다는 조건에서, 다섯 direct construction path 모두 destination
`+0x30`에 zero bytes를 copy한다.

그 다섯 direct-caller body와 helper body의 explicit `dword [register+0x30]` write operand를
원본 decode로 검사한 결과는 0개다. `_vm_object_collapse`의 별도 complete-collapse path에만
`0x00179a79 MOV dword ptr [ESI+0x30],0`가 있으며, 이는 allocation construction closure와
분리된 post-construction clear다.

이는 direct construction의 initial-byte provenance에 대한 결론이다. indirect/computed helper
caller, REP/string copy의 source 변경, arithmetic alias store, non-export code, template clear의
실제 도달/재실행, allocation failure와 live object lifetime은 아직 이 static closure 밖이다.
`+0x30` type 또는 object API 의미는 export label로 확정하지 않았다.

원시 call sites·destination flow·Python 집계는 [vm-object-direct-construction-field30.json](vm-object-direct-construction-field30.json)에 기록했다.
