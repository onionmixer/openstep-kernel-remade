# 남은 분석

이번에는 callout entry 등록/제거에서 expire 전달·worker callback, clock/timer wrapper까지 원본으로 연결했다. 대기열 취소와 실행 완료 동기화가 다르다는 근거, 임시 목록 status=0 구간, 이미 등록된 entry의 delayed 재등록 무시, 64-bit clock과 timer 반올림 경계를 확인했다.

- 가장 가까운 후속: calloutEntryAllocate/Free, 일반 calloutDispatch/Unique/Delayed/Remove/RemoveAll와 WithArgument 변형의 소유권·pool 부족·중복 처리; 실행 중/임시 목록 entry의 재등록·free 가능 caller와 timer element 수명. 이번 count/queue 대응을 모든 producer에 적용해 검증해야 한다.
- hardware clock 초기화(0x187a40), hardclock callback(0x187938), unsigned division runtime(0x1d0fb4), system_timer_dispatch의 IRQ caller, splusclock/splsched의 실제 interrupt/CPU 의미. hz·counter/reload·attributes·callback 전역의 전체 writer, zero-fill/초기화 순서, overflow·zero sentinel 및 실제 clock monotonicity는 미완료다.
- thread_select/invoke/run/setrun, call_continuation, kernel_thread 생성/실패와 worker count 복구 조건, stack_privilege/terminate/halt_self 및 continuation 비복귀·stack 전환. creator와 worker의 block 뒤 fall-through를 실제 실행 계약으로 설명해야 한다.
- assert_wait/wakeup의 event/hash/link 불변식, timer callback과 clear_wait/IPC wait의 모든 취소·timeout·재등록 interleaving, register-only busy loop의 native 진행성. 정적 순서 관찰만으로 SMP/IRQ 경쟁의 안전성이나 실제 발생을 증명하지 않는다.
- 70차 OPEN_ITEMS의 IPC kobject/server, receive caller/ref/output, queue 이동과 msgcount/qlimit/seqno, rights·OOL VM·DriverKit/network release·notification template 작업은 그대로 남는다.

전역 함수/경로 ledger, IDA 실패/경고·fragment·타입/ABI 독립 검토, PD reference/reuse/multi-backing/GC/aging/CR3, native fault/RF/IDT/IRETD/context/FPU, VM pager/COW/shadow/busy/absent/alias/PV/오류·대기, MMIO/IRQ/TLB/cache/장치, IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/Objective-C의 전체 의미와 provenance는 계속 미완료다.

최종 결과물의 실제 GCC 2.7 NeXT 툴체인 고정·C/Objective-C/ASM/MIG probe·전체 Mach-O 빌드/link·boot/regression와 SPARC/후속 architecture도 완료하지 않았다. 원본 주석·매크로·소스 배치의 유일 복원을 주장하지 않는다. 신규 독립 계획 교차검토를 확보하지 않은 채 구현·동적 실행으로 넘어가지 않으며 이전 실패 검토의 우회·재요청도 하지 않는다. 수행 가능한 정적 분석이 남아 있으므로 목표를 완료 또는 차단으로 표시하지 않는다.
