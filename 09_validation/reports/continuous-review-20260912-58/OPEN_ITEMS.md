# 미완료 범위 — 이번 단계로 닫히지 않음

- 우선: 원본 `ipc_right_lookup_write` (`0x14db08`), `ipc_right_copyin_header` (`0x150364`), `ipc_right_copyin_compat` (`0x14fecc`)의 락·entry/type·uref·object ref·실패 시 소유권 계약. helper 이름과 Darwin 주석만으로 검증 처리하지 않는다.
- 송신 old 포트 5/6 정규화와 수신/정리의 16..21 분류 사이 생산자/허용 타입/복합 플래그 불변조건. 모든 호출자를 아직 확인하지 않았다.
- 헤더 최소 길이, DWORD end 계산 및 long descriptor product/add wrap에 대한 상위 입력 제한. 원소 개수와 payload allocation/정리 길이의 일관성. 이번 산술 결과는 실행 관측이 아니다.
- `vm_move`, `vm_deallocate`, copyin fault, OOL source deallocation 후 권한 실패, `ipc_port_check_circularity`와 queue 소비의 실제 동작. 현재 정리는 사용자 입력 상태를 되돌리는 전면 rollback이 아니다.
- 앞선 권한 copyout/release/send-once notification, entry grow/deallocate, object death/race 및 mqueue scheduler/interrupt, kernserv dispatch/생명주기 미완료 항목 유지.
- 전체 함수 의미 검증 원장 부재, IDA 보조 실패·Ghidra 경고·fragment/타입/ABI의 전수 의미 검증, 독립 원본 DB 대조 유지. 자료 확보 완료와 의미 검증 완료는 다르다.
- PD 수명/ref/reuse/GC, VM/pager/COW/shadow/PV/오류·wait, CR3/실제 TLB, RF/IDT/IRETD 재시도, scheduler/context/FPU/동시성, MMIO/IRQ/device의 native 검증 유지.
- IPC/MIG/BSD/VFS/UFS/network/DriverKit/ObjC 및 다른 서브시스템 전체 계약과 공개 소스 provenance 검증 유지.
- GCC 2.7 정확한 NeXT target 툴체인·C/ObjC/ASM/MIG ABI probe·전체 컴파일·Mach-O 링크·부팅은 미완료. SPARC 및 후속 아키텍처도 미완료.
- 신규 독립 계획 검토 미확보 상태를 숨기지 않는다. 이 단계에서는 새 검증 프로그램/동적 실행/커널 구현을 하지 않았다. 이전 실패 검토 요청을 우회하여 재요청하지 않는다.

전체 목표는 진행 중이다. 이번 본문·바이트 대조를 전체 복원이나 전이적 검증의 완료로 확대하지 않는다.
