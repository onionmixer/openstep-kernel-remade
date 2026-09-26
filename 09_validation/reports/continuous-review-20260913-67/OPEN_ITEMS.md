# 계속 열린 분석

이번에는 kmsg clean/body/partial/free와 object_destroy dispatch, copyin의 선택된 prefix-index caller 연결을 원본에 대조했다. 이 목록은 전체 목표를 축소하지 않는다.

- ipc_right_destroy 전체의 namespace lock·entry/hash·권한·reference 해제와 실패 경로. 보고서 66의 compat dead-name caller가 반환 상태를 무시하는 상황까지 연결해야 한다.
- ipc_mqueue_send/receive의 dead port 재검사·timeout/interruption·send-always 옵션·실패와 성공의 메시지 ownership, 모든 cleanup caller의 admission 및 부분 확보 범위. 이번 bounded copyin window는 전체 caller 검증을 대신하지 않는다.
- VM deallocate 및 OOL 저장소 생성·이전·부분 실패·alias 연결. cleanup의 무검사 descriptor/길이/포인터 읽기가 선행 검증과 실제로 맞물리는지 전체 경로로 확인해야 한다.
- KernDeviceInterruptMsgRelease/netipc_msg_release의 소유권 복귀·buffer 재사용·queue locking, 알림 template·다른 notify·kobject VM/pager/network dispatch의 전이적 정리.
- thread_setrun/reset_timeout/spl/current_thread, port destination reference와 receiver queue caller 불변식, register-only busy loop 및 native 경합.

전체 함수·경로별 의미 ledger와 IDA 실패/경고·fragment·type/ABI 독립 검토, PD reference/reuse/multi-backing/GC·aging·CR3, native fault/RF/IDT/IRETD, scheduler/context/FPU, VM pager/COW/shadow/busy/absent/alias/PV/오류·대기, MMIO/IRQ/TLB/cache·장치, IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/Objective-C 전체 의미 및 provenance는 계속 미완료다.

실제 GCC 2.7 NeXT 툴체인 고정·C/Objective-C/ASM/MIG probe·전체 Mach-O link·boot/regression과 SPARC/후속 architecture도 남아 있다. 원본 주석·매크로·배치의 유일한 복원을 주장하지 않는다. 새 독립 계획 검토 미확보 상태에서 구현·새 실행 검증 프로그램·동적 실행으로 넘어가지 않았고 이전 실패 검토의 우회·재요청도 하지 않는다. 수행 가능한 정적 분석이 남아 있으므로 전체 완료나 차단으로 판정하지 않는다.
