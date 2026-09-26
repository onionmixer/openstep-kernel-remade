# `0x001dcd88`·`0x001dcdc4` static target-table의 직접 writer 감사

171차에서 `_pmap_kgetport` label의 prefix가 세 간접 call의 초기 target을 두 file-backed
`__DATA` table에서 읽는다는 사실을 원본 바이트로 확인했다. 이 차수는 그 두 table 자체의
직접 writer를 구분한다. Python/Capstone으로 full-pass5의 exported function body 5,253개를
원시 decode하여 286,091 instruction을 검사했다.

`0x001dcd88`과 `0x001dcdc4`을 absolute base/index 없는 memory operand로 정확히 가리키는
instruction은 0개였고, 따라서 그 주소에 대한 정적 직접 memory write도 0개다. 두 주소를
immediate로 materialize하는 site는 2개뿐이다. `0x00134fa9 MOV [EBX+0x20],0x001dcd88`와
`0x00135400 MOV [EBX+8],0x001dcdc4`이며, 두 경우 모두 destination은 EBX 상대 주소다.
171차의 raw allocation/return chain에 따르면 전자는 second allocation의 `+0x20`, 후자는
outer allocation의 `+8`에 table 주소를 넣는 초기화다. 원본 instruction은 table bytes를
직접 변경하지 않는다.

export reference inventory도 각각 instruction materialization과 table data edge만 보인다.
`0x001dcd88`은 `0x00134fa9 → table`, `table → 0x00134fdc`; `0x001dcdc4`은
`0x00135400 → table`, `table → 0x00135bd8`이다. 이 inventory는 export가 만든 정적
reference graph이며, table의 모든 cell 또는 모든 runtime reference라는 뜻은 아니다.

따라서 현재 증거는 **초기 file image table 값**과 **그 주소를 allocation field에 넣는 두
직접 site**를 분리한다. register-derived pointer, alias를 통한 write, non-export executable
code, BSS/loader/runtime write 및 실제 allocation lifetime은 이 정적 전수 검사만으로 배제할
수 없다. label이나 추정 API 의미도 이 결론에 사용하지 않았다.

원시 검사 수치와 site 목록은 [static-target-table-writer-audit.json](static-target-table-writer-audit.json)에 있다.
