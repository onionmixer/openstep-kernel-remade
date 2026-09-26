# 미완료 범위

- 다음 정적 우선순위: entry dealloc/hash와 pset remove/mqueue changed의 실제 소유권·순서. 이번 request release 연결만으로 전체 IPC 정리가 완결된 것은 아니다.
- marequest rename, 초기화/mask/table, 모든 create caller와 kmsg attach, 중복 key 방지, cancel/destroy 직렬화, 정확히 한 번의 destroy 및 clean의 비멱등성 전제.
- dead-name request의 index/name/tagged space 규약, table grow/전체 해제, compat request가 유지하는 space ref의 전체 균형.
- 알림 queue_send 옵션과 정상 전달/실패 소비, no_senders 연쇄, port active/ref/srights/sorights 불변조건 및 allocator의 실제 동작. 함수가 호출된 것만으로 최종 해제·전달을 보장하지 않는다.
- register-only lock wait의 전역 분포와 CPU/interrupt/preemption/context/경합/runtime patch/정확한 compiler 조건. 이번 패턴 확인은 전수 검사나 실행 관측이 아니다.
- 보고서 58·59의 header/long descriptor 길이, 타입 인정 범위, dead-name uref 한계, VM 이동/해제/circularity와 권한 생산자 검증 유지.
- 전체 함수 의미 원장 부재, IDA 보조 실패/Ghidra 경고/fragment/ABI·독립 DB 비교와 source provenance 미완료 유지.
- PD/ref/reuse/GC, VM/pager/COW/shadow/PV/오류·wait, CR3/TLB, RF/IDT/IRETD, scheduler/context/FPU/races, MMIO/IRQ/device native 검증 유지.
- IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/ObjC의 전체 계약 및 GCC 2.7 NeXT target 툴체인·ABI probe·전체 컴파일/Mach-O 링크/부팅, SPARC·후속 아키텍처 미완료 유지.
- 신규 독립 계획 검토 미확보. 새 검증 프로그램/동적 실행/커널 구현을 진행하지 않았으며 이전 실패 검토를 우회하거나 재요청하지 않았다.

전체 목표는 진행 중이며 이번 정적 증거를 전체 완료로 확대하지 않는다.
