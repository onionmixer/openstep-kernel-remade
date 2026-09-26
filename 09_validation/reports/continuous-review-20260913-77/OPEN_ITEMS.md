# 남은 OPENSTEP 원본 분석

77차는 vm_map_delete와 바로 연결되는 객체 참조·page/pmap helper의 직접 본문을 검토했다.
외부 코드 없이 아래 경계를 계속 원본에서 확인해야 한다.

1. 물리 페이지/PV 반환: pmap_remove_all(0x18fb0c), vm_page_free(0x17b540),
   FUN_0018f7f8의 PTE/PV 목록·통계·실제 반환·TLB 순서. object 목록 next의 보존과
   queue/object/pmap lock 순서를 포함한다.
2. vm_object_terminate(0x178d60), vm_object_remove(0x179764),
   vm_object_deactivate_pages(0x179084), vm_object_cache_trim(0x1790dc)의 lock 소비,
   page 상태·pager·wait·오류 및 object+0x20 연결의 수명. WORD 참조/보조 필드의 writer도 필요하다.
3. unwire 하위 pmap_extract(0x190c24), pmap_change_wiring(0x190b5c),
   vm_phys_to_vm_page(0x178894), vm_page_unwire(0x17b7bc), pmap_pageable(0x1914c8)의
   입력·실패·page/queue 상태 계약과 page_size step 전제.
4. map find/insert의 주소 선택, 삭제 후 실제 재사용, entry 분할의 flags/참조 불변식,
   map+0x2c 경로와 child-map 수명·재귀·부모/자식 lock 순서. 빈 구간의 분할 가능성이
   확인됐지만 모든 caller 도달성과 allocator 실패/대기까지 완료된 것은 아니다.
5. pmap/PD 생성과 backing 재사용: 유효 directory 변환, pg_desc_tbl 범위,
   ptes_per_vm_page/slot/bitmap/queue 불변식, cleanup 시점 직렬화, CR3·FS·TLB native 경계.
6. 76차 GC/zone free-list와 descriptor의 모든 writer, 주소 정렬·비중첩·hint·count,
   map 재사용과 zone_free_space_add 낮은 주소 입력의 실제 도달성, tick/gc_control 직렬화.

75차 loader/entry/__common 초기화·메모리 지도·pmap bootstrap·memset fragment와
그 이전의 함수 밖 코드/data, 함수 경계, ABI/타입, Ghidra 경고·IDA 실패/독립 대조도 남아 있다.
전역 함수/경로 의미 ledger, IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/Objective-C,
VM/pager/COW/page 상태, IRQ/scheduler/context/FPU/fault/MMIO/native 동시성의 남은 경로를
부분 본문 검토로 전체 완료 처리하지 않는다.

현재 범위는 OPENSTEP 원본 분석뿐이다. 다른 코드 참고·소스 복원·구현·빌드·포팅으로
확장하지 않는다. 새 실행 검증 프로그램이나 독립 계획 검토를 수행했다고 주장하지 않는다.
