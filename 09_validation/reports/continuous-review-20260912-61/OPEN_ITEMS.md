# 남은 분석·검증

- 다음 정적 범위: splay split/join/bounds와 cached root/name/link의 계약. collision bit의 first pick 성공 보장, membership/세대 bits/중복 key 불변조건.
- table grow/entry alloc/get/local·global lookup. size>0, index 0 예약, local hash 여유 slot, 없는 index 삭제 방지, global count와 membership 일치.
- entry dealloc 전 object/request 정리·hash 제거의 전체 caller 순서. 독립적인 hash field를 구조체 zeroing으로 훼손하지 않도록 역할 구분.
- splay delete의 node zfree 이후 수명, 모든 tree 형태의 연결 보존/cached key, 상수 경고의 전체 CFG 대조. byte 확보를 warning 전수 해결로 확대하지 않는다.
- pset remove/mqueue changed의 참조·대기자·wakeup, queue 전달/알림 연쇄 미완료.
- 보고서 60의 marequest 생성/rename/cancel/destroy·최종 호출 횟수, dead-name tagged request/ref, 알림 소비와 allocator 전체 검증 유지.
- register-only lock wait의 전역 분포/경합/CPU/interrupt/context/runtime patch/compiler 조건 미완료 유지.
- 보고서 58·59의 header/long descriptor 길이·타입 인정 범위·dead-name uref/VM 이동·해제/circularity와 권한 생산자 검증 유지.
- 전체 함수 의미 원장 부재, IDA 보조 실패/Ghidra 경고/fragment/ABI·독립 DB 및 source provenance 미완료 유지.
- PD/ref/reuse/GC, VM/pager/COW/shadow/PV/오류·wait, CR3/TLB, RF/IDT/IRETD, scheduler/context/FPU/races와 MMIO/IRQ/device native 검증 유지.
- IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/ObjC 전체와 GCC 2.7 NeXT target 툴체인/ABI probe/전체 컴파일/Mach-O 링크/부팅, SPARC·후속 아키텍처 미완료 유지.
- 신규 독립 계획 검토 미확보. 새 검증 프로그램/동적 실행/구현이나 이전 실패 검토의 우회/재요청은 하지 않았다.

전체 목표는 진행 중이다.
