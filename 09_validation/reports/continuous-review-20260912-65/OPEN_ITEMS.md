# 남은 분석·검증

- 다음 정적 범위: port_destroy의 backup/receive/메시지/dead-name/알림 정리와 ref 소비, mqueue_changed 및 wait/wakeup의 대기자 상태 계약.
- naked receive destination ref, pset의 지연 member 제거, right_clean inactive port 요청의 별도 종료 경로. dead-space marequest 생존/ref 및 모든 cancel/destroy 호출 횟수.
- space destroy/grow의 native 경합·lost wakeup·중복 호출/마지막 ref 안전성, 이후 inactive 접근 배제. 일반/특수 space의 모든 caller와 초기 descriptor 유효성.
- bootstrap 이전 page-size 설정과 zone/특수 space/table 초기화 실패 처리, native 부팅 순서. ipc_init task_create의 전수 ABI/소유권 및 suballoc 결과.
- traverse 전체 caller의 중도 종료/재진입, 모든 tree 형태의 고유 key/연결/수명 및 self-pointer 복사·이동·alias 배제.
- kmem_realloc의 vm_map_find/lookup/lock_done, FUN_00173ebc 및 vm_map_pageable의 lock·page/alias·wire·실패 계약. table wrapper/allocator 전이적 수명과 비기본 count/page-size 조건.
- 모든 entry 할당 caller의 type/object/request 완성, invalid name 인정 범위, free-list/세대/NULL object, index 0 예약, local hash 여유 slot 및 global membership-count 일치.
- entry dealloc 전 정리와 반환 포인터 수명, queue 전달/알림 연쇄 및 allocator 전체.
- register-only lock wait의 전역 분포/경합/CPU/interrupt/context/runtime patch/compiler 조건.
- header/long descriptor 길이·타입 인정 범위·dead-name uref/VM 이동·해제/circularity 및 권한 생산자.
- 전체 함수 의미 원장 부재, IDA 보조 실패/Ghidra 경고/fragment/ABI·독립 DB 및 source provenance. export·부분 caller/window·조건부 산술을 전체 의미/실행 완료로 판정하지 않는다.
- PD/ref/reuse/GC, VM/pager/COW/shadow/PV/오류·wait, CR3/TLB, RF/IDT/IRETD, scheduler/context/FPU/races 및 MMIO/IRQ/device native 검증.
- IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/ObjC 전체, GCC 2.7 NeXT target 툴체인/ABI probe/전체 컴파일/Mach-O 링크/부팅, SPARC·후속 아키텍처.
- 신규 독립 계획 검토 미확보. 새 실행 검증 프로그램/동적 실행/구현이나 이전 실패 검토의 우회/재요청은 하지 않았다.

전체 목표는 진행 중이다.
