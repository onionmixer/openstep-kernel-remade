# zone allocation map-root `0x001dfcec`의 suballocation provenance

`_zget_space` label의 `0x0016aef4 CALL 0x00174170` (`_kmem_alloc_zone`)에 전달되는
`0x001dfcec` global을 원본으로 추적했다. 이 global의 exact absolute writer는 하나이며,
`_zone_init` label이 `0x0016b34e MOV EDX,[0x001e8de8]`, `0x0016b355 CALL 0x00173fbc`,
`0x0016b35a MOV [0x001dfcec],EAX` 순서로 설정한다.

`0x00173fbc` helper는 입력 map의 subrange 조건을 처리한 후 `0x0017402d CALL 0x001746a0`의
return EAX를 local `[EBP-8]`에 저장하고 EAX로 복귀한다. target map-create helper는
allocation result EBX의 `+0x2c`에 1을 저장한다. 따라서 이 root도 182차의 root들과
같이 map-create return에서 유래한다는 static provenance가 있다.

`_kmem_alloc_zone`의 direct `CALL rel32` caller는 두 개다. `_kalloc_noblock` path는
`0x001f6330`을, `_zget_space` path는 `0x001dfcec`을 첫 argument로 전달한다. 이는 direct
call graph의 argument source 사실이다. helper call의 성공·복귀, later field mutation,
alias/non-export writer, runtime map identity와 entry lifetime은 이 결론에 포함되지 않는다.

세부 원시 flow와 writer 수는 [zone-map-root-provenance.json](zone-map-root-provenance.json)에 기록했다.
