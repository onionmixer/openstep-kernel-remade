# 남은 분석 — dispatch/MIG 경계 이후

[report53의 미완료 목록](../continuous-review-20260912-53/OPEN_ITEMS.md)을 유지한다. 관리 테이블의 사용 경로와 shutdown/load_objc stub의 형식 검사는 이번에 확인했지만, 권한·수명·IPC 전체 의미는 미완료다.

- boot listener port right의 생성·이전 및 실제 loader 송신 경로를 추적한다. local port 비교를 sender 인증 전체로 대체하지 않는다.
- msg_receive의 최소 헤더/버퍼 보장, RCV_TOO_LARGE 크기와 재할당 실패, RCV_INTERRUPTED의 메시지 상태, msg_send의 reply 내용·timeout·오류 의미를 확인한다.
- 일반 dispatch의 cache index 불변식, mapping 변경·삭제 시 무효화, NULL proc, request local port 변경 및 sentinel 반환의 실제 효과를 확인한다.
- main의 notification queue 제거·반복 수명과 callout/port callback 재진입을 검토한다. 이번 main 창을 함수 전체 의미 검증으로 집계하지 않는다.
- 나머지 관리 stub과 instance_loc, port_proc/port_serv, wire/unwire, version의 계약을 연결한다.
- 모듈 이미지 매핑·relocation·보호·해제 주체, 실패 등록 후 shutdown, 잔존 class/selector/protocol 참조와 직렬화는 미완료다.
- report52의 사전 조회 인자 불일치, 구형 metadata 변환, module record 진행성, add/removeHeader·class·category 및 cache 갱신을 계속 추적한다.

전체 함수 의미 원장, IDA 독립 증거, fragments·경고·타입/ABI, NXHash/NXMap/문자열 소유권, PD/VM/pager/COW/PV/aging/GC, native fault retry·scheduler/context/FPU, 장치/MMIO/IRQ/TLB/cache는 여전히 미완료다.

IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv 전체 계약, 공개 소스 계보, 실제 GCC 2.7 툴체인·전체 컴파일·Mach-O 링크·부팅과 SPARC/후속 아키텍처 검증을 유지한다. 독립 계획 검토 미수신으로 신규 실행/검증 프로그램과 복원 구현은 보류한다.
