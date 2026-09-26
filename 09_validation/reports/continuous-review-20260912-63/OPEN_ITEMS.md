# 남은 분석·검증

- 다음 정적 범위: splay traverse start/next/finish의 정렬 순회·delete flag·실제 node free와 마지막 상태. grow_table의 이동/고유 index count가 이 계약에 의존한다.
- table alloc/realloc/free의 원본 매핑·옛 table 보존·실패 경로. size descriptor 생성, osize>0 및 최대 크기, name/byte shift와 비용 비교 wrap의 도달성.
- space 생성/파괴와 growing wait/wakeup 협력, namespace lock을 놓은 동안의 table/space 수명. 성공 0이 실제 확장/active를 보장하지 않는 caller 재검사 계약.
- 모든 entry 할당 caller의 type/object/request 완성, invalid name 인정 범위, free-list membership/세대 외 bits/NULL object, 중복 key와 index 0 예약, local hash 여유 slot/global membership-count 일치.
- split/join/delete/insert/traverse 조합의 모든 tree 형태 node 보존·해제 수명. self-pointer가 있는 tree의 이동/복사 및 잘못된 alias 배제.
- entry dealloc 전 object/request 정리·hash 제거의 모든 caller 순서 및 반환 entry 포인터 수명.
- pset remove/mqueue changed의 참조·대기자·wakeup, queue 전달/알림 연쇄.
- marequest 생성/rename/cancel/destroy·최종 호출 횟수, dead-name tagged request/ref, 알림 소비와 allocator 전체.
- register-only lock wait의 전역 분포/경합/CPU/interrupt/context/runtime patch/compiler 조건.
- header/long descriptor 길이·타입 인정 범위·dead-name uref/VM 이동·해제/circularity 및 권한 생산자.
- 전체 함수 의미 원장 부재, IDA 보조 실패/Ghidra 경고/fragment/ABI·독립 DB 및 source provenance. export나 현재 경고 0개를 의미 검증 완료로 판정하지 않는다.
- PD/ref/reuse/GC, VM/pager/COW/shadow/PV/오류·wait, CR3/TLB, RF/IDT/IRETD, scheduler/context/FPU/races 및 MMIO/IRQ/device native 검증.
- IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/ObjC 전체, GCC 2.7 NeXT target 툴체인/ABI probe/전체 컴파일/Mach-O 링크/부팅, SPARC·후속 아키텍처.
- 신규 독립 계획 검토 미확보. 새 실행 검증 프로그램/동적 실행/구현이나 이전 실패 검토의 우회/재요청은 하지 않았다.

전체 목표는 진행 중이다.
