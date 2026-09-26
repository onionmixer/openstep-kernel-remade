# 전체 export의 `+0x30`·`+0x28` write 후보와 offset 충돌

Open item 1의 object `+0x30` 및 map-entry WORD `+0x28` alias writer를 이름-prefix 밖까지
확장해 확인했다. Python/Capstone으로 full-pass5의 5,253개 exported function body
fragment를 원본 바이트에서 decode하고, write access인 memory operand의 displacement가
정확히 `0x30` 또는 `0x28`인 instruction을 추출했다.

`+0x30` write 후보는 119개 함수의 167개다. operand width는 byte 4개, word 7개,
dword 156개다. VM·map·object·page·pmap이라는 문자열을 이름에 포함하는 함수만 보아도
19개 함수의 37개 dword write가 남으며, 그중에는 map 자체의 `+0x30`, 다른 VM 구조체,
vnode pager 경로와 object-collapse clear가 함께 있다. 따라서 이 정적 displacement
집계만으로 object `+0x30` writer 전부를 정할 수 없다.

`+0x28` write 후보는 221개 함수의 343개다. 그중 WORD write는 13개 함수의 24개이며,
이름 필터 후보는 9개 함수의 15개다. 나머지 9개 WORD site는 `_soreceive`, `_tcp_mss`,
`__bios32`, `_gdt_init`에 있다. 즉 `+0x28` 및 word-width만으로 map entry를 판정하는
것도 성립하지 않는다.

map 이름군의 15개 WORD site는 insert/find의 0 초기화, pageable의 갱신, entry
unwire/delete와 copy/copy-entry/fork의 0 clear에 분포한다. 이는 기존 map-entry raw
경로를 확인하는 후보 집합이지만, 각 base register의 전역 alias·runtime lifetime은
이 scan으로 확정하지 않는다.

전체 집계 규칙과 candidate 주소는
[offset-write-collision-inventory.json](offset-write-collision-inventory.json)에 기록했다.
이 결과는 computed displacement, helper 내부 store, non-export code, pointer type과
runtime 도달을 포함하지 않는다.
