# 남은 분석

이번에 kalloc/zone 초기화·할당/해제 정책을 연결해 callout의 기본 32-byte zone에 대한 조건부 실패 계약을 좁혔다. 일반 kalloc의 non-NULL 보장이나 allocator 전체 완료를 주장하지 않는다.

- 가까운 후속은 zget_space(0x16ada4)의 backing·canblock·free-space lock·할당/회수, descriptor 생성/초기화와 selector가 맞는 descriptor를 찾지 못할 때의 전제, zone boot/default space 생존 조건이다. 과거 PD 검증 범위와 겹치는 부분은 재사용하되 검증하지 않은 경로를 완료로 승격하지 않는다.
- kalloc_map/kernel_map, kmem_alloc_wired/pageable/free의 출력·오류·backing reference 전체; zone의 cur_size/max_size/count/freelist와 GC/reuse/aging 전체 producer. overflow·zero size·잘못된 free는 정적 분기 관찰과 정상 caller 입력 검증을 구분해야 한다.
- 모든 zchange 및 zone pointer/flag writer의 호출 시점·serialization, nonpageable spin/spl과 pageable lock, doing_alloc의 wait/wakeup/재시도, 실제 canblock=0의 하위 동작, register-only busy loop의 native 진행성.
- callout의 power/kern_serv/장치와 다른 external entry 소유권, log open/close/wakeup의 외부 직렬화·대기 thread 참조 producer/consumer. 72차 실제 caller 검토만으로 전체 lifetime race를 완료하지 않는다.
- 71차 clock hardware 초기화·hardclock/unsigned division·IRQ caller·전역 writer, thread_select/invoke/run/setrun·continuation/stack 전환과 kernel_thread 실패/worker count 검증도 남는다.
- 이전 IPC kobject/server·receive ref/output·queue 이동·msgcount/qlimit/seqno·rights/OOL VM/notification 및 DriverKit/network release 항목도 계속 유효하다.

전역 함수/경로 ledger, IDA 실패/경고·fragment·타입/ABI 독립 검토, PD reference/reuse/multi-backing/GC/aging/CR3, native fault/RF/IDT/IRETD/context/FPU, VM pager/COW/shadow/busy/absent/alias/PV/오류·대기, MMIO/IRQ/TLB/cache/장치, IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/Objective-C 의미와 provenance는 계속 미완료다.

실제 GCC 2.7 NeXT 툴체인·C/Objective-C/ASM/MIG probe·전체 Mach-O 빌드/link·boot/regression 및 SPARC/후속 architecture도 남는다. 신규 독립 계획 교차검토 미확보 상태에서 구현·새 실행 검증 프로그램·동적 실행으로 넘어가지 않으며 이전 실패 검토를 재요청·우회하지 않는다. 의미 있는 정적 분석이 남아 있으므로 전체 목표를 완료나 차단으로 표시하지 않는다.
