# 106차 범위·검증 방법

## 입력과 제한

원본 OPENSTEP x86 `mach_kernel`, 이 바이너리에서 생성된 Mach-O inventory와 Ghidra
ASM/C/metadata export, 기존 원본 분석 보고서 및 현재 정책만 읽었다. `01_resources`,
`07_kernel`, 다른 커널 소스·문서·웹은 읽지 않았다. 원본 binary, Ghidra/IDA DB, 기존
export와 확정 보고서는 수정하지 않았다. 구현·복원·빌드·실행·에뮬레이션도 수행하지 않았다.

Ghidra MCP 스킬을 기존 export와 원본 바이트 대조에만 적용했다. live DB 수정은 하지
않았다. 모든 주소 mapping, size/count/hash와 집계는 Python으로 수행했다. 새 독립 계획
교차검토가 수신되지 않았다는 제한도 그대로 유지한다.

## 선택 본문

- backing helper `0x173ebc`, `vm_page_alloc_sequential` `0x17b200`,
  `vm_page_zero_fill` `0x17b99c`, `page_set` `0x1019c0`.
- `vm_map_pageable` `0x175b2c`, `vm_map_delete` `0x176164`,
  `vm_map_remove` `0x1765ac`, `vm_fault_wire` `0x17358c`,
  `vm_fault_unwire` `0x1735f4`, `vm_fault_wire_fast` `0x173898`.
- `vm_object_pmap_remove` `0x179350`, `vm_object_page_remove` `0x179bbc`,
  `pmap_remove` `0x18fa44`, `pmap_change_wiring` `0x190b5c`,
  `pmap_extract` `0x190c24`, `pmap_pageable` `0x1914c8`.
- 지정 recursive API caller `kmem_alloc_wait` `0x174518` 및 `vm_map_copy` `0x176888`.

## 정적 검증

1. 원본 SHA-256과 Mach-O `__text` mapping을 Python으로 확인했다. selected address의
   file offset은 `__text.file_offset + VA - __text.address`로 계산했다.
2. 각 metadata body segment를 원본에서 Capstone 4.0.2/x86-32으로 해독했다. segment 끝
   명령의 end address와 metadata inclusive end를 비교하고, segment byte 합계와 body_bytes를
   assertion했다.
3. 18개 일반 body의 합계는 body bytes 9,659, instruction heads 3,498, CALL 156,
   J 계열 branch 506이다. 이 수치는 전체 커널 coverage가 아니다.
4. `0x174541`, `0x174560`, `0x175ff0`, `0x17603e`, `0x1776c0`, `0x177885`,
   `0x1778b3`, `0x1778c7`의 원본 5-byte CALL target을 각각 set/clear recursive API로
   assertion했다.
5. 전체 5,253 ASM export를 direct-CALL literal 대상으로만 survey하여 backing/pageable/
   remove/delete/wire helper의 직접 caller를 열거했다. 간접 call/table/alias 또는 whole
   caller graph 증명으로 사용하지 않았다.

## 미입증 범위

page-size/page-shift 및 queue/template globals의 runtime 초기화와 writer, zalloc/panic 이후
동작, page/object/map/pmap의 모든 alias/indirect caller, object `+0x30`과 entry WORD count의
overflow/underflow 도달성, cross-thread ownership, IRQ/lock 진행성은 미완료다. clamp,
split, void return 또는 caller가 EAX를 읽지 않는 명령 사실만으로 memory safety, rollback,
fault completion, deadlock 부재를 선언하지 않는다.
