# 남은 분석 — 포트 권한 이전 이후

[report56의 목록](../continuous-review-20260912-56/OPEN_ITEMS.md)을 유지한다. object/right copyout의 직접 갱신과 성공 시 name 출력, destination 권한 소비 및 destroy의 분기를 확인했다. 전이적 참조 수명은 아직 완료하지 않았다.

- reverse lookup의 object lock/active 보장과 entry/hash의 일관성, entry/dead-name request table 성장 중 lock·재시도 계약을 확인한다.
- dnrequest에 추가한 space reference의 실제 해제와 tagged pointer 정렬·해석을 연결한다.
- release_send/release_receive, no-senders/send-once notification과 port 파괴의 최종 참조 회수·실패 처리를 검증한다.
- 송신 copyin의 carried-type·descriptor length/count/size 정규화와 검증을 확인한다. destroy의 default 무처리와 type helper의 panic을 유효 입력 전제로 숨기지 않는다.
- 성공 반환 안에서의 OOL 부분 손실, source 해제·target allocation·포트 이름 수명 및 소비자 해석을 유지한다.
- queue 전달·대기·권한/락/참조, scheduler 경쟁, kernserv의 수신 인터럽트 후 상태·재할당·notification queue·cache/재진입과 모듈 이미지 수명을 연결한다.

전체 의미 원장·IDA 독립 증거·fragments/경고/타입/ABI, NXHash/NXMap/문자열, PD/VM/pager/COW/PV/aging/GC, native fault retry·scheduler/context/FPU, 장치/MMIO/IRQ/TLB/cache, IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv 전체 계약은 미완료다.

공개 소스 계보, 실제 GCC 2.7 전체 컴파일·Mach-O 링크·부팅, SPARC/후속 아키텍처 검증도 유지한다. 신규 독립 계획 검토 미수신으로 새 실행/검증 프로그램과 복원 구현은 보류한다.
