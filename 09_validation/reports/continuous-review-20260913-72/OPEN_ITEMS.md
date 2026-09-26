# 남은 분석

14개 `_callout*` 이름의 export 본문은 70~72차 검토에 매핑했다. 이는 해당 본문의 정적 검토 범위를 추적하는 목록이지 모든 caller와 실행 조건의 완료 판정이 아니다.

- calloutEntryAllocate의 kalloc 반환/오류·blocking 계약, Free의 kfree·allocation provenance, pool 범위 판정의 전제, 모든 external entry 생성/종료 caller. power 관련 callback과 kern_serv/장치 caller, export 외·간접 호출을 포함한 소유권 ledger가 필요하다.
- logwakeup/close/open의 외부 serialization, log callback의 대기 thread 참조 producer와 selwakeup/deallocate_interrupt/signal/wakeup 계약. entry를 callback이 읽지 않는 사실은 전역 상태 재사용·pointer race 검증을 대신하지 않는다.
- 71차의 clock 후속: hardware 초기화 0x187a40, hardclock callback 0x187938, unsigned division runtime 0x1d0fb4, IRQ caller와 spl 동작, 전역 writer/zero-fill/boot 순서·overflow/zero sentinel·실제 monotonicity.
- thread_select/invoke/run/setrun, call_continuation, kernel_thread 생성 실패 및 worker count, stack_privilege/terminate/halt_self, continuation 비복귀/stack 교체. assert_wait/wakeup의 event/hash/link 불변식과 timer/IPC wait interleaving, register-only busy loop의 native 진행성도 남는다.
- IPC kobject/server, receive caller/ref/output, queue 이동·msgcount/qlimit/seqno, rights·OOL VM·DriverKit/network release·notification template에 대한 이전 OPEN_ITEMS는 계속 유효하다.

전체 함수/경로 ledger, IDA 실패/경고·fragment·타입/ABI 독립 검토, PD reference/reuse/multi-backing/GC/aging/CR3, native fault/RF/IDT/IRETD/context/FPU, VM pager/COW/shadow/busy/absent/alias/PV/오류·대기, MMIO/IRQ/TLB/cache/장치, IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/Objective-C 의미와 provenance는 계속 미완료다.

실제 GCC 2.7 NeXT 툴체인 고정·C/Objective-C/ASM/MIG probe·전체 Mach-O 빌드/link·boot/regression 및 SPARC/후속 architecture도 완료하지 않았다. 신규 독립 계획 교차검토 미확보 상태에서 구현·동적 실행으로 넘어가지 않으며 이전 실패 검토를 우회·재요청하지 않는다. 수행 가능한 정적 분석이 있으므로 목표 완료 또는 차단으로 표시하지 않는다.
