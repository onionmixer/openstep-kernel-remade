# 남은 분석

이번에 mqueue send/receive, wait 준비, ring helper와 resume caller를 원본 전체 본문에 대조했다. 성공의 소비 의미·오류 output·timeout 재검사·후대 source 차이를 기록했지만 모든 caller·scheduler·native 경합을 완결한 것은 아니다.

- thread_go_and_switch, thread_block_with_continuation, timer set/reset/callback과 wait_result producer, spl/interrupt level·stack discard/resume의 실제 연결. 가까운 후속 범위다.
- kobject_server의 request/reply 소유권, kernel port receiver 사전 clear 조건, exception_raise_continue_slow 및 다른 receive caller의 queue reference·output 오류 처리.
- port/pset membership 변경과 message queue 이동, receiver wake/port 죽음이 겹치는 수명, SEND_ALWAYS/SWITCH 모든 caller, msgcount/qlimit/seqno의 전 생산자·소비자. 정적 재시도 경로가 native 진행성을 증명하지 않는다.
- right_dealloc/delta 등 user-reference API, 모든 cleanup caller의 admission·부분 확보 범위, OOL VM 이동/해제·alias·실패, DriverKit/network 특수 message release, 알림 template와 미검토 notify, kobject VM/pager/network 정리.

전체 함수/경로 ledger, IDA 실패/경고·fragment·type/ABI 독립 검토, PD reference/reuse/multi-backing/GC·aging·CR3, native fault/RF/IDT/IRETD, scheduler/context/FPU 전체, VM pager/COW/shadow/busy/absent/alias/PV/오류·대기, MMIO/IRQ/TLB/cache·장치, IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/Objective-C 전체 의미와 provenance는 계속 미완료다.

실제 GCC 2.7 NeXT 툴체인 고정·C/Objective-C/ASM/MIG probe·전체 Mach-O link·boot/regression 및 SPARC/후속 architecture도 남는다. 원본 주석·매크로·배치의 유일 복원을 주장하지 않는다. 새 독립 계획 검토 미확보 상태에서 구현·새 실행 검증 프로그램·동적 실행으로 전환하지 않았고 이전 실패 검토의 우회·재요청도 하지 않는다. 수행 가능한 정적 분석이 남아 있으므로 전체 완료나 차단으로 처리하지 않는다.
