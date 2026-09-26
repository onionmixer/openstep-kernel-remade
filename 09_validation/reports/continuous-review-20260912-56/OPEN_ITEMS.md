# 남은 분석 — compat copyout 실패 표현 이후

[report55의 미완료 목록](../continuous-review-20260912-55/OPEN_ITEMS.md)을 유지하되 **첫 항목은 갱신한다**. 이 callee의 nonzero 정상 반환 가능성은 원본 CFG로 배제했다. 남는 항목은 성공 반환 안에서의 부분 손실·정리·소비자 처리다.

- `ipc_object_copyout_compat`, copyout_dest, destroy가 권한과 참조를 실제로 획득·이전·소모하는 경로를 확인한다.
- OOL 포트 할당 실패 시 현재 descriptor 정리, 타입 미변환·주소 0·잔존 count의 소비자 의미를 확인한다. 전체 rollback으로 취급하지 않는다.
- copyoutmap 오류 무시 후 source 배열 해제와 target allocation/port names 수명, 일반 OOL vm_move 이후 source deallocate의 성공·실패 계약을 연결한다.
- 송신 copyin이 carried type, descriptor 길이·count·size·포인터 범위·DWORD overflow를 어떤 단계에서 검증하는지 확인한다.
- queue send/receive의 kmsg 전달과 소유권, port/set 권한·락·참조, wait 결과의 생산자와 경쟁을 유지한다.
- kernserv의 RCV_INTERRUPTED 후 실제 필드 상태, TOO_LARGE 재할당, notification queue 수명, cache·재진입·port mutation을 연속 상태로 검증한다.
- boot listener 권한, 나머지 관리 stub, 모듈 이미지 mapping/relocation/보호/해제와 잔존 ObjC 참조는 미완료다.

전체 의미 원장·IDA 독립 증거·fragments/경고/타입/ABI, NXHash/NXMap/문자열, PD/VM/pager/COW/PV/aging/GC, native fault retry·scheduler/context/FPU, 장치/MMIO/IRQ/TLB/cache 및 IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv 전체 계약을 유지한다.

공개 소스 계보, 실제 GCC 2.7 전체 컴파일·Mach-O 링크·부팅, SPARC/후속 아키텍처 검증도 미완료다. 신규 독립 계획 검토는 확보되지 않아 새 실행/검증 프로그램과 복원 구현은 보류한다.
