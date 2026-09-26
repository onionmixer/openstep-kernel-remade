# 남은 분석·검증

- 다음 정적 범위: splay insert, entry alloc/get/grow와 local/global lookup의 생산자 계약. 정렬/고유 key, 유효 cached-state, disjoint tree, 충돌 bit와 first pick의 성공 보장.
- split/join/delete를 조합한 모든 tree 형태의 node 보존·membership·해제 이후 수명. self-pointer가 있는 tree의 복사/이동, 출력 alias 및 malformed input의 호출자 배제 조건. 이번 정적 분기 대조를 전수 실행 검증으로 확대하지 않는다.
- table size>0, index 0 예약, local hash 여유 slot, 없는 index 삭제 방지, global count와 membership 일치 및 세대/이름 경계. bounds sentinel과 key 인정 범위.
- entry dealloc 전 object/request 정리·hash 제거의 모든 caller 순서. 독립적인 hash field의 역할과 수명.
- pset remove/mqueue changed의 참조·대기자·wakeup, queue 전달/알림 연쇄.
- marequest 생성/rename/cancel/destroy·최종 호출 횟수, dead-name tagged request/ref, 알림 소비와 allocator 전체.
- register-only lock wait의 전역 분포/경합/CPU/interrupt/context/runtime patch/compiler 조건.
- header/long descriptor 길이·타입 인정 범위·dead-name uref/VM 이동·해제/circularity 및 권한 생산자.
- 전체 함수 의미 원장 부재, IDA 보조 실패/Ghidra 경고/fragment/ABI·독립 DB 및 source provenance. 확보한 export를 의미 검증 완료로 판정하지 않는다.
- PD/ref/reuse/GC, VM/pager/COW/shadow/PV/오류·wait, CR3/TLB, RF/IDT/IRETD, scheduler/context/FPU/races 및 MMIO/IRQ/device native 검증.
- IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/ObjC 전체, GCC 2.7 NeXT target 툴체인/ABI probe/전체 컴파일/Mach-O 링크/부팅, SPARC·후속 아키텍처.
- 신규 독립 계획 검토 미확보. 새 실행 검증 프로그램/동적 실행/구현이나 이전 실패 검토의 우회/재요청은 하지 않았다.

전체 목표는 진행 중이다.
