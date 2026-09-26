# 남은 OPENSTEP 원본 분석

76차는 zone collect/reclaim의 직접 bookkeeping과 lock 소비, GC gate 및 VM 반환
wrapper를 검증했다. 실제 VM/page 해제와 이후 주소 재사용은 아직 닫히지 않았다.

## 가까운 다음 경계

1. vm_map_delete(0x176164)의 범위·entry 분할·object reference·pmap·페이지·대기 및
   오류 처리를 원본에서 연결한다. 빈/경계 밖 구간의 실제 동작과 부분 실패, 반환 상태를
   무시하는 reclaim caller의 조건을 구분한다.
2. map find/insert의 주소 선택과 해제 후 재사용을 연결한다. 74차 zone_free_space_add에
   기존 head보다 낮은 주소의 새 영역이 들어가는 경로의 실제 도달 가능성을 확인한다.
   원본의 비인접 분기 관찰만으로 정상 실행상의 손실이나 안전성을 단정하지 않는다.
3. zone free list 및 descriptor의 모든 writer: 정렬·비중첩·hint 최저 주소·entry 수,
   zone cur_size/in-use count, zchange 및 목록 수명. collect가 원소를 detach하는 순간의
   저장소 소유권과 reclaim이 남기는 작은 fringe의 header 조건도 필요하다.
4. num_zones/first/next의 snapshot 수명, backend→zone 및 backend→all-zones lock 순서,
   pageable lock·spl·인터럽트와 register-only spin의 native 진행성을 검토한다.
5. consider_zone_gc의 tick producer와 rate/allowed writer, gc_control argument·_suser의
   실제 ABI/오류/직렬화, cache-clear 하위 함수와 다른 GC 진입점을 검토한다.

75차의 loader/초기 entry와 __common clearing, 메모리 지도 및 pmap bootstrap,
page_size/region/bucket의 간접 writer, memset fragment 경계도 계속 미완료다.

전역 함수·경로별 의미 ledger와 함수 밖 코드/data/fragment·ABI/타입,
Ghidra 경고·IDA 실패/해석 독립 대조, callout/clock/IRQ/scheduler/context/FPU/fault,
IPC/권리/notification, VM/pager/COW/page 상태와 오류·대기, PD/GC/reuse/CR3,
장치/MMIO/TLB/cache, BSD/VFS/UFS/network/DriverKit/kernserv/Objective-C의 남은 원본 경로를
전체 완료로 승격하지 않는다.

다른 코드를 참고하지 않는다. 소스 복원·구현·빌드·포팅은 현재 범위 밖이며,
의미 있는 원본 분석이 남아 있으므로 목표는 완료도 차단도 아니다.
