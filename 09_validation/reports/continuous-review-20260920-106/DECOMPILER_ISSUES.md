# 106차 디컴파일 표현 검토

- `vm_map_remove` C는 clamp와 delete result 전달을 대체로 보존하지만, lock API 내부의
  interlock 및 wait/sleep 동작을 표현하지 않는다. 결과 0은 C type이 아니라 delete
  epilogue의 `XOR EAX,EAX` 원본 명령에서 확인했다.
- `vm_map_pageable` C의 `bVar8`는 kernel-map 여부에 따른 실제 lock-release 경로를
  축약한다. 원본은 non-kernel branch에서 `set_recursive` → `write_to_read` → wire loop →
  `clear_recursive` → `done`이며, kernel-map branch는 wire 전 `done`을 한다.
- `vm_map_delete`의 repeated `LOCK()` 표현은 export가 XCHG interlock loop를 C로 펴낸
  것이다. `map+0x38/+0x3c` cursor 갱신은 map write lock과 별도 interlock을 사용한다.
  C가 구조체 field name을 제공하지 않으므로 offset과 access width를 원본 기준으로 썼다.
- `vm_fault_wire`/`vm_fault_unwire`는 void C signature로 표시된다. 원본도 normal
  epilogue에서 EAX 상태를 caller가 계약으로 소비하지 않으며, `pmap_extract==0` 및
  `pmap_change_wiring` lookup failure는 panic path다. C의 generic pointer type을 성공
  보장이나 null validation으로 보충하지 않았다.
- `pmap_pageable`은 C의 빈 함수처럼 보이고 원본도 prologue/epilogue뿐이다. 이를
  `vm_map_pageable` 전체가 no-op이라는 해석에 사용하지 않았다.
- `page_set` C loop는 first store 전에 size==0 branch가 없다는 원본을 보존한다.
  step은 32 bytes이지만 size alignment, negative size, wrap guard는 원본에 없다.
- `vm_map_copy` C는 nested recursive calls의 map identity와 later conditional clear를
  멀리 떨어뜨려 표시한다. raw CALL target과 call-site 뒤 comparison을 별도로 확인했다.

이 항목들은 decompiler output의 한계와 원본 명령의 차이를 기록한 것이며, 별도 구조체
정의나 외부 소스의 의미를 가져오지 않는다.
