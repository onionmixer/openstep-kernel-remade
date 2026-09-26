# 남은 분석

이번에 right_destroy 전체 본문과 namespace API wrapper, hash dispatch, port-deleted/no-senders 알림 본문을 원본에 대조했다. 반환 오류 전에 entry를 정리하는 compat 경로 및 알림에 저장값을 사용하는 순서를 연결했다. 모든 caller와 권한 생성자의 수명이 전이적으로 완결된 것은 아니다.

- ipc_mqueue_send/receive의 dead port 재검사, blocked sender/receiver, timeout/interruption, send-always 옵션과 kmsg ownership 이전·실패·파괴. 가까운 후속 범위다.
- 모든 cleanup/right_destroy caller의 admission, partial prefix와 저장소 범위, request 생성·취소·port 사망·space reference의 연결. right_dealloc/delta 등 user-reference 변경 API도 별도 의미 검증이 필요하다.
- OOL VM allocation/move/deallocate의 실패·alias·소유권, KernDeviceInterruptMsgRelease/netipc_msg_release의 buffer 재사용, 알림 template와 미검토 notify, kobject VM/pager/network 정리.
- thread_setrun/reset_timeout/spl/current_thread, port destination reference와 receiver queue caller 불변식, register-only busy loop와 native 경합.

전체 함수/경로 ledger, IDA 실패/경고·fragment·type/ABI 독립 검토, PD reference/reuse/multi-backing/GC·aging·CR3, native fault/RF/IDT/IRETD, scheduler/context/FPU, VM pager/COW/shadow/busy/absent/alias/PV/오류·대기, MMIO/IRQ/TLB/cache·장치, IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/Objective-C 전체 의미와 provenance는 계속 미완료다.

실제 GCC 2.7 NeXT 툴체인 고정·C/Objective-C/ASM/MIG probe·전체 Mach-O link·boot/regression 및 SPARC/후속 architecture도 남아 있다. 원본 주석·매크로·배치의 유일 복원을 주장하지 않는다. 새 독립 계획 검토 미확보 상태에서 구현·새 실행 검증 프로그램·동적 실행으로 전환하지 않았고 이전 실패 검토의 우회·재요청도 하지 않는다. 수행 가능한 정적 분석이 남아 있으므로 전체 완료나 차단으로 처리하지 않는다.
