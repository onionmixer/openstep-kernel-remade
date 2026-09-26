# 남은 분석

이번에 timer setup/adapter/set/reset, ticks/ns/deadline ABI, thread timeout/clear_wait 및 go_and_switch/block 진입을 원본에 대조했다. callout backend가 실제 callback을 실행/취소하는 경합과 machine context switch까지 검증한 것은 아니다.

- calloutEntryDispatchDelayed/Remove와 service dispatch·queue/thread lifecycle, 재등록·취소·in-flight callback, clock_value와 ns_per_tick 초기화·clock domain. 가까운 timer 후속 범위다.
- thread_select/invoke/run, thread_setrun의 queue·priority·CPU/processor-set·idle 조건, call_continuation와 machine-dependent stack/context 전환, spl/interrupt level과 실제 scheduler 실행.
- assert_wait/wakeup producer의 event hash·link 불변식, thread 생성/timeout element 초기화·수명, depress timer, 모든 IPC wake/timeout/cancel interleaving. register-only busy loop의 native 진행성은 계속 미검증이다.
- kobject_server와 kernel port 제거 조건, exception continuation slow 및 다른 receive caller의 queue reference/output 오류 처리, port/pset queue 이동, msgcount/qlimit/seqno 전체 producer/consumer, right_dealloc/delta, OOL VM·특수 DriverKit/network message release·알림 template.

전체 함수/경로 ledger, IDA 실패/경고·fragment·type/ABI 독립 검토, PD reference/reuse/multi-backing/GC·aging·CR3, native fault/RF/IDT/IRETD, scheduler/context/FPU 전체, VM pager/COW/shadow/busy/absent/alias/PV/오류·대기, MMIO/IRQ/TLB/cache·장치, IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/Objective-C 전체 의미와 provenance는 계속 미완료다.

실제 GCC 2.7 NeXT 툴체인 고정·C/Objective-C/ASM/MIG probe·전체 Mach-O link·boot/regression 및 SPARC/후속 architecture도 남는다. 원본 주석·매크로·배치의 유일 복원을 주장하지 않는다. 새 독립 계획 검토 미확보 상태에서 구현·새 실행 검증 프로그램·동적 실행으로 전환하지 않았고 이전 실패 검토의 우회·재요청도 하지 않는다. 수행 가능한 정적 분석이 남아 있으므로 전체 완료나 차단으로 처리하지 않는다.
