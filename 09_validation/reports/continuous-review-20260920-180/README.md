# page template의 writer 순서·byte transform·copy 경계

Page template `0x001f7440..0x001f7470`은 raw file-backed data가 아니라 Mach-O `__DATA,__common`
range에 놓인다. 따라서 원본 파일 bytes만으로 template의 load-time byte 값을 읽을 수 없다.
그 대신 `_vm_page_startup` label의 raw writer sequence를 해석해 copy 이전에 확정되는 store와
source-dependent byte transform을 분리했다.

`_vm_page_startup`은 template `+0x14/+0x18`에 dword zero, `+0x1c`에 word zero,
`+0x20`에 byte one, `+0x24/+0x28/+0x2c`에 dword zero를 저장한다. `+0x1e`은 초기 byte `x`
에서 최종 `x & 0xe0`, `+0x21`은 초기 byte `y`에서 최종 `y & 0xe2`가 된다. Python으로
0..255을 모두 평가하면 가능한 최종값은 각각 8개 및 16개다. `+0x00..+0x13`, `+0x1d`,
`+0x1f`, `+0x22..+0x23`에는 이 writer range의 absolute store가 없다.

`__text` 전체의 direct `CALL rel32` scan에서 `_vm_page_startup` entry의 site는
`0x00173a7e` 하나이며, 173차의 static start path에서 이는 `_vm_mem_init` 아래다. 반면
170차가 확인한 바와 같이 `_vm_page_init` template-copy entry에는 direct `CALL rel32` site가
없다. 따라서 writer의 static boot reachability와 48-byte copy의 actual runtime reachability는
동일한 결론으로 합치지 않는다.

이 결과는 source-dependent fields와 non-file-backed initial state를 구분한다. Loader의 common
초기화, computed/non-export writer, boot call의 복귀, template 변경 후 copy 시점, page object
수명은 여전히 원본 정적 분석만으로 runtime 값으로 확정할 수 없다.

원시 writer·transform 계산·direct edge는 [page-template-runtime-value-boundary.json](page-template-runtime-value-boundary.json)에 기록했다.
