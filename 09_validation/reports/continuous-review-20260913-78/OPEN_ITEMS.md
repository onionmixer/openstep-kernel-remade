# 남은 OPENSTEP 원본 분석

78차는 매핑 제거에서 PTE/PV 및 PT accounting, VM page hash/object detach와 조건부
free queue 삽입까지 직접 본문을 연결했다. 아래 경계를 원본에서 계속 확인해야 한다.

1. vm_object_terminate(0x178d60), vm_object_remove(0x179764),
   vm_object_deactivate_pages(0x179084), vm_object_cache_trim(0x1790dc): object lock 소비,
   pager·wait·page 상태·해제 순서, object+0x20 연결 수명, 참조 WORD와 +0x1a WORD의 writer.
2. PTE/PV 생성·변경의 모든 writer: 첫 PTE와 sibling의 present/frame/mask 0x200 일관성,
   PV head/체인에 (pmap,VA)가 존재하는 조건, page_size/ptes_per_vm_page/page_mask/
   section_size와 helper PTE 경계의 대응, managed span·실제 region·pg_desc_tbl 일치.
3. PT/PD backing의 active/free queue와 WORD 통계 수명, 물리 allocator로의 후속 반환,
   실제 매핑·주소 재사용. PT free queue 이동과 VM page free queue 삽입은 별개로 추적한다.
4. vm_page_free/addfree 및 pmap helper의 모든 caller: object/active/inactive/free/PV/pmap
   lock·spl 순서, page flag와 hash 존재의 일관성, 이중 free 방지, native register spin 진행성.
5. unwire 하위 pmap_extract(0x190c24), pmap_change_wiring(0x190b5c),
   vm_page_unwire(0x17b7bc), pmap_pageable(0x1914c8)의 입력·실패·page/queue 계약.
   vm_phys_to_vm_page의 직접 변환은 이번에 검토했으나 실제 영역 초기화·모든 writer는 미완료다.
6. INVLPG/FS/CR3와 PTE/PDE 변경의 실제 CPU·IRQ·context·동시성 경계. pmap_remove_all의
   CR3 fallthrough에 대한 국소 산술 판정은 전역 중간 진입·native 실행 검증이 아니다.
7. VM find/insert 및 삭제 후 주소 재사용, child-map/분할/참조 수명, 76차 zone/GC의
   모든 writer·hint/count/정렬 불변식과 낮은 주소 재사용 도달성, tick/gc_control 직렬화.

loader/초기 entry/__common clearing·메모리 지도·pmap bootstrap·memset fragment와
함수 밖 코드/data·함수 경계·ABI/타입·Ghidra 경고/IDA 실패 독립 대조도 남아 있다.
전역 함수·경로 ledger와 IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/Objective-C,
VM/pager/COW, IRQ/scheduler/context/FPU/fault/MMIO의 남은 원본 경로를 부분 본문 검토로
전체 완료 처리하지 않는다.

현재 목표는 OPENSTEP 원본 분석에 한정한다. 외부/복원 코드 참고·구현·빌드·포팅으로
범위를 바꾸지 않는다. 의미 있는 원본 분석이 남아 있으므로 전체 완료도 차단도 아니다.
