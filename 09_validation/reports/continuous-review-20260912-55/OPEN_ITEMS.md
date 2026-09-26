# 남은 분석 — old IPC wrapper 이후

[report54의 미완료 목록](../continuous-review-20260912-54/OPEN_ITEMS.md)을 유지한다. 수신 인터럽트가 새 메시지 복사를 뜻하지 않는 점과 TOO_LARGE 크기 반환, 실제 old 오류 변환은 본문 수준으로 확인했다. 연속 실행 결과는 미검증이다.

- `ipc_kmsg_copyout_compat`가 오류를 반환할 때 kmsg의 size/delta·내용·port/VM 소유권을 확인한다. wrapper는 오류 후에도 caller로 put한다.
- `ipc_kmsg_copyin_compat`, queue send의 blocking/timeout/interrupt, 수신자에게 전달되는 kmsg 또는 크기와 ownership을 연결한다.
- mqueue_copyin의 포트/포트집합 권한·락·참조 획득과 object_release를 확인한다. request header 최소 크기와 buffer extent의 생산자 책임도 미완료다.
- wait_result/ith_state의 생산자, timeout·interrupt·termination 경쟁, halt 이후 복귀와 scheduler 계약을 확인한다.
- kernserv가 RCV_INTERRUPTED 뒤 처리하는 실제 필드 상태를 연속 입력으로 검증한다. local_port/size가 수신 전에 바뀐다는 사실을 반영한다.
- TOO_LARGE 재할당 실패·크기 불변식, notification queue의 제거/반복 수명, 일반 dispatch cache·재진입·포트 수정과 sentinel 처리를 유지한다.
- bcopy/memcpy의 DF·길이·overlap 전제, kmsg allocation sentinel별 실제 release 구현을 연결한다.
- boot listener 권한의 생성·이전, 나머지 관리 stub, 모듈 이미지 mapping/relocation/보호/해제, 등록 실패 후 shutdown과 잔존 ObjC 참조는 미완료다.

전체 함수 의미 원장·IDA 독립 증거·fragments/경고/타입/ABI, NXHash/NXMap/문자열, PD/VM/pager/COW/PV/aging/GC, native fault retry·scheduler/context/FPU, 장치/MMIO/IRQ/TLB/cache, IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv 전체 계약을 유지한다.

공개 소스 계보와 실제 GCC 2.7 툴체인·전체 컴파일·Mach-O 링크·부팅, SPARC/후속 아키텍처 검증도 미완료다. 독립 계획 검토 미수신으로 신규 실행/검증 프로그램과 복원 구현은 보류한다.
