# `vm_map_insert` direct allocation 경로의 three global map-root provenance

181차의 direct caller boundary를 map-root initializer까지 확장했다. `0x001e8de8`은
`_kmem_init` label의 `0x001740a4 CALL 0x001746a0` 반환 EAX를 `0x001740ab`에서 저장한
global이다. target helper는 EBX allocation pointer에 `+0x2c=1`을 기록하고 EAX=EBX로
복귀한다.

`0x001f6330`은 `_kalloc_init`의 `0x0015a682 MOV EDX,[0x001e8de8]` 뒤
`0x0015a688 MOV [0x001f6330],EDX`로 같은 pointer를 복사한다. `0x001f622c`은
`_ipc_init` label에서 `_kmem_suballoc` result EAX를 저장한 값이다. 이 helper도
`0x0017402d CALL 0x001746a0`의 EAX를 local에 보존하고 `0x0017407c MOV EAX,[EBP-8]`로
복귀한다.

full-pass5 exported bodies의 exact absolute memory-write audit에서는 세 global 각각에
direct writer가 하나뿐이다. 따라서 이 static path에서는 `vm_map_insert`의 direct caller
상위에서 널리 사용되는 three roots가 모두 map-create result로 이어진다. 이는 root 대상의
`+0x2c`가 이후에도 1임을 보장하는 결론이 아니다. map field의 alias write, indirect/non-export
writer, call 성공 및 runtime lifetime은 별도 문제다.

원시 writer·return flow·absolute-writer count는 [map-root-initializer-provenance.json](map-root-initializer-provenance.json)에 기록했다.
