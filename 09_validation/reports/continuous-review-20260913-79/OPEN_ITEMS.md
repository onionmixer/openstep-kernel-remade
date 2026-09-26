# 남은 OPENSTEP 원본 분석

79차는 object 종료와 cache 참조 소비, sleep의 전달 lock 해제, pager의 device/vnode
직접 경로를 연결했다. 단순 wrapper에서 멈추지 않고 vnode bitmap·집계·간접 호출 및
lock_write의 보존/대기를 확인했지만 아래 원본 경계는 여전히 남아 있다.

1. vnode_dealloc의 `0x17e0a6` 간접 호출: ops+0x18의 실제 table/target 집합, 속성 buffer의
   정확한 ABI·크기, vattr_null/vn_rele와 VFS 구현의 반환·wait·권한/context 복원.
   nonzero 반환 뒤 rollback 없는 정리 순서가 각 target 계약에 맞는지 확인한다.
2. vnode pager 생성·배열 확장과 packed 기록 writer: flat/2단 배열 선택과 count 범위,
   마지막 블록의 나머지 슬롯 초기화, ID table/집계 table 범위 및 직렬화, bitmap의 중복
   해제 방지·high-water/크기 조건. 검색 실패 시 기존 +0x20 보존의 실제 도달성을 확인한다.
3. device pager 생성: pager+4 목록, page metadata allocation(+8/+0xc), vm_page_remove의
   대상 object/hash와의 일치, free queue에 반환하지 않는 페이지 저장소 수명.
4. object+0x44 WORD의 모든 증감/wakeup writer, +0x20/+0x1c 연결 생성·복사·shadow·COW,
   cache trim snapshot-unlock-lookup 구간의 객체 수명과 다른 참조자, hash insert/중복 규칙.
   terminate의 pager 전 object unlock과 이후 무재획득 처리에 필요한 배타성도 확인한다.
5. pmap_clear_reference(0x19152c), pmap_is_modified(0x191500) 및 이전 unwire 하위
   pmap_extract/pmap_change_wiring/vm_page_unwire/pmap_pageable의 PTE/PV·page byte 계약.
6. lock_done, 재귀/owner/wait flag writer, thread_block_with_continuation과 wakeup/IRQ/
   scheduler/native context. thread_sleep·lock_write의 직접 본문 확인을 native 진행성
   또는 모든 lock 순서 검증으로 승격하지 않는다.
7. PTE/PV 생성·변경의 그룹/alias 불변식, PT/PD backing 재사용·실제 반환, 메모리 region과
   managed span/descriptor 일치, VM map find/insert와 낮은 주소 재사용, zone/GC의
   hint/count/정렬 및 모든 writer·tick/gc_control 직렬화는 계속 남아 있다.

loader/초기 entry/__common clearing·pmap bootstrap·함수 밖 코드/data·함수 경계·ABI/타입,
Ghidra 경고와 IDA 실패 독립 대조 및 전역 함수·경로 ledger도 미완료다.
IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/Objective-C, VM/pager/COW,
IRQ/scheduler/context/FPU/fault/MMIO의 다른 원본 경로를 이번 부분 검토로 전체 완료 처리하지 않는다.

현재 작업은 OPENSTEP 원본 분석뿐이다. 외부/복원 코드 참고·구현·빌드·포팅을 수행하지 않는다.
의미 있는 원본 분석이 남아 있어 전체 목표는 완료도 차단도 아니다.
