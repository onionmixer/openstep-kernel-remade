# 남은 분석과 검증

- 새 중요 항목: 원본 register-only lock wait의 전체 분포와 실제 동작 조건. CPU/interrupt/preemption/context, 초기 lock 값, 경합 가능성, runtime patch 여부 및 정확한 원본 compiler/옵션을 확인해야 한다. 이번 11곳과 이전 57의 4곳은 전수 결과가 아니다. plain 소스나 Ghidra 루프를 경합 진행성 증명으로 사용하지 않는다.
- 다음 정적 범위: `ipc_port_dncancel`, `ipc_space_release`, marequest cancel, entry dealloc/hash와 알림용 port copy/send/notify의 요청·권한·참조·락 계약. 현재 helper 호출만 확인한 부분을 실제 release 완료로 판정하지 않는다.
- `ipc_pset_remove`/`ipc_mqueue_changed`의 wakeup과 ref, splay lookup 및 table/tree 일관성. clear_receiver의 pset ref 읽기와 unlock 순서 차이를 원본 기준으로 유지한다.
- dead-name request와 uref 한계의 생성·변경 불변조건. 본문의 검사가 없는 조합을 실제 reachable로 단정하지 않는다.
- 보고서 58의 헤더 최소 길이/long descriptor DWORD 길이/old 타입 5·6과 수신·정리 16..21의 인정 범위, VM 이동/해제/circularity, 입력 생산자 및 오류 시 소유권은 유지한다.
- 앞선 mqueue scheduler/interrupt, kernserv dispatch/수명, IPC/MIG/BSD/VFS/UFS/network/DriverKit/ObjC 전체 계약은 미완료다.
- 전체 함수 의미 검증 원장 부재, IDA 보조 실패/Ghidra 경고/fragment/ABI와 독립 DB 대조 및 공개 소스 provenance 미완료를 유지한다.
- PD 수명/ref/reuse/GC, VM/pager/COW/shadow/PV/오류·wait, CR3/실제 TLB, RF/IDT/IRETD 재시도, scheduler/context/FPU/동시성 및 MMIO/IRQ/device native 검증도 남아 있다.
- GCC 2.7 정확한 NeXT target 툴체인/ABI probe/전체 C·ObjC·ASM·MIG 컴파일/Mach-O 링크/부팅 및 SPARC·후속 아키텍처는 미완료다.
- 신규 독립 계획 검토는 확보되지 않았다. 이번 단계에서 새 검증 프로그램/동적 실행/구현은 하지 않았고 이전 실패 검토를 우회하거나 재요청하지 않았다.

이번 정적 본문 대조는 구체적 진전이지만 전체 목표 완료가 아니다.
