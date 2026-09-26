# guard-zero map-entry allocation에서 WORD `+0x28`의 stale-byte 가능 조건

178차의 `map+0x2c=0` guard branch가 entry allocation과 만나는 지점을 원본 명령으로
추적했다. `_vm_map_insert`는 `0x00174918`에서 map `+0x20`에 따라 두 global zone pointer
중 하나를 선택하고, `0x0017492e CALL 0x0016b790`의 EAX를 EBX entry 후보로 받는다.
반환 뒤에는 `+8`, `+0xc`, byte `+0x18`, `+0x10`, `+0x14`를 기록한다. `map+0x2c==0`이면
`0x0017496c JE 0x00174989`가 `+0x1c/+0x20/+0x24` stores와 `WORD [EAX+0x28]=0`을 함께
건너뛴다. 이 body의 explicit `WORD +0x28` write는 그 하나뿐이다.

allocation wrapper `0x0016b790`은 `0x0016b364`를 호출한다. 후자의 shown free-list pop은
`ESI=[zone+0x10]`, `ECX=[ESI]`, `zone+0x10=ECX` 후 EAX=ESI로 복귀한다. 이 sequence에는
`[ESI+0x28]` write가 없다. 그러므로 다음 조건이 동시에 충족되면, shown instructions만으로
`+0x28`을 zero로 만들 수 없다.

1. selected zone의 free-list pop이 nonzero ESI를 반환한다.
2. caller map의 `+0x2c`가 zero여서 guarded initialization을 skip한다.
3. 반환부터 entry linking까지 다른 경로가 해당 word를 쓰지 않는다.

이는 stale value가 runtime에 실제로 발생했다는 관측이 아니다. 새 zone supply와 free-list
내용, map pointer가 zero-guard construction에서 이 function으로 전달되는지, concurrent/alias
writer 및 이후 consumer는 미확정이다. 다만 guard-zero branch를 자동 zero-initialization으로
해석할 수 없다는 원본-byte 조건을 추가한다.

instruction path·write count·조건은 [map-entry-word28-guard-zero-allocation.json](map-entry-word28-guard-zero-allocation.json)에 기록했다.
