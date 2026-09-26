# 남은 분석 — 이번 결과로 닫지 않은 범위

이번에 port_destroy/check_circularity, 선택 알림, queue dequeue, kmsg_destroy의 지연 큐, thread_go의 원본 switch와 순서 차이를 기록했다. 직접 호출 대상까지 전이적으로 완결되었다는 판정은 아니다.

## 가까운 후속 범위

- ipc_kmsg_clean 및 body/header 정리: message type별 권한·OOL 메모리·request 정리, 부분 실패와 중첩 파괴, ipc_kmsg_free의 특수 할당 종류. 이번에는 호출 순서와 signed size dispatch만 확정했다.
- ipc_right_destroy 전체: dead-name compat caller가 보관한 notify port와 반환 상태를 구분했지만, callee의 모든 namespace lock·reference·entry/hash 해제 경로는 아직 남는다.
- ipc_mqueue_send/receive: dead port, blocked sender 재검사, timeout/interruption, send-always 옵션, 메시지 ownership 전달과 실패 시 caller 책임. port_destroy가 sender에 0을 써 깨우는 것과 실제 송신 성공은 같은 판정이 아니다.
- 알림 template 초기화 및 다른 notify 함수: 일반/compat layout·ID·descriptor·권한 종류, allocation failure cleanup 전체. 이번 선택 함수의 template 주소·복사·호출만으로 layout 전체가 검증되지 않는다.
- thread_setrun/reset_timeout/spl/current_thread 연결, receiver queue를 비우는 모든 caller 조건, port destination reference의 생성·해제 전 구간, malformed chain과 native 경합. register-only busy loop는 계속 독립 쟁점이다.
- ipc_kobject_destroy의 VM/pager/network dispatch 대상 전체. Darwin 참고 소스와 원본의 case 차이를 누락하지 않는다.

## 전체 목표에서 계속 열린 범위

함수·경로별 의미 검증을 일관되게 추적하는 전체 ledger, IDA 보조 실패/경고와 미식별 조각·타입·ABI의 독립 검토가 남아 있다. 전체 export 확보와 전체 의미 복원은 다르다.

PD reference/reuse·multi-backing·GC와 aging 연결, CR3/페이지 테이블, native fault/RF/IDT/IRETD retry, scheduler/context/FPU, VM pager/COW/shadow/busy/absent/alias/PV/오류·대기와 ownership, MMIO/IRQ/TLB/cache 및 장치 동작은 아직 전이적으로 완결되지 않았다.

IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/Objective-C 전체 의미, 참고 소스 provenance, 실제 GCC 2.7 NeXT 툴체인 고정 및 C/Objective-C/ASM/MIG probe·전체 Mach-O link·boot/regression, SPARC와 후속 architecture 분석도 남아 있다. 원본 주석·매크로·소스 배치는 바이너리만으로 유일하게 복원된다고 주장하지 않는다.

새 독립 계획 검토가 확보되지 않은 상태에서 구현·새 실행 검증 프로그램·동적 실행으로 전환하지 않았다. 기존 실패 검토의 우회·재요청은 하지 않는다. 정적 원본 대조를 계속할 수 있으므로 전체 완료나 차단으로 처리하지 않는다.
