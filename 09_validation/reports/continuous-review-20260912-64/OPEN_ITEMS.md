# 남은 분석·검증

- 다음 정적 범위: space 생성/특수 생성/파괴, table 기본 descriptor 사용, growing wait/wakeup 및 namespace/ref 수명. table_init 이전 page-size 설정·기본 count 유지의 부팅 순서.
- traverse 전체 caller의 정상 종료/중도 탈출/재진입, next를 종료 뒤 다시 호출하지 않는 계약, caller의 hash/request/object 정리와 node free 순서. 모든 tree 형태의 연결/고유 key/정렬 순회 증명.
- kmem_realloc의 vm_map_find/lookup/lock_done, FUN_00173ebc 및 vm_map_pageable의 lock·object/page/alias·wire·실패 계약. 반환 0과 하위 helper 성공을 혼동하지 않는다.
- table alloc/free의 kalloc/kmem_alloc/kfree/kmem_free 전이적 수명·실패 처리. 원본 count/page_size 변경·특수 descriptor 및 크기 산술 overflow의 전역 도달성.
- 모든 entry 할당 caller의 type/object/request 완성, invalid name 인정 범위, free-list membership/세대 외 bits/NULL object, 중복 key와 index 0 예약, local hash 여유 slot/global membership-count 일치.
- split/join/delete/insert/traverse 조합의 모든 tree 형태 node 보존·해제 수명과 self-pointer 이동/복사·alias 배제.
- entry dealloc 전 정리 및 반환 entry 포인터 수명, pset remove/mqueue changed의 참조·대기자·wakeup, queue 전달/알림 연쇄.
- marequest 생성/rename/cancel/destroy·최종 호출 횟수, dead-name tagged request/ref, 알림 소비와 allocator 전체.
- register-only lock wait의 전역 분포/경합/CPU/interrupt/context/runtime patch/compiler 조건.
- header/long descriptor 길이·타입 인정 범위·dead-name uref/VM 이동·해제/circularity 및 권한 생산자.
- 전체 함수 의미 원장 부재, IDA 보조 실패/Ghidra 경고/fragment/ABI·독립 DB 및 source provenance. export·경고 개수·조건부 수열 계산을 전체 의미/실행 검증 완료로 판정하지 않는다.
- PD/ref/reuse/GC, VM/pager/COW/shadow/PV/오류·wait, CR3/TLB, RF/IDT/IRETD, scheduler/context/FPU/races 및 MMIO/IRQ/device native 검증.
- IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/ObjC 전체, GCC 2.7 NeXT target 툴체인/ABI probe/전체 컴파일/Mach-O 링크/부팅, SPARC·후속 아키텍처.
- 신규 독립 계획 검토 미확보. 새 실행 검증 프로그램/동적 실행/구현이나 이전 실패 검토의 우회/재요청은 하지 않았다.

전체 목표는 진행 중이다.
