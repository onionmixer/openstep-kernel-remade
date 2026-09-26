# 남은 전체 분석

[report45의 미완료 목록](../continuous-review-20260912-45/OPEN_ITEMS.md)을 유지한다. 이번 정적 생성·순회·비교 검토는 NXMap 전체 실행 검증을 대체하지 않는다.

## NXMap 후속 의무

- 실제 생성의 prototype 조회·재사용·할당과 hash callback, 기본/custom zone, 잘못된 prototype의 할당·회수 및 실패 계약을 검증한다.
- 원본 prototype/iterator 선언·출처와 GCC 2.7 aggregate/함수 포인터 ABI를 확인한다.
- 합법적인 capacity 범위, 크기·shift 경계의 실제 caller 도달성, allocator 실패와 초기화 순서를 검증한다. 계산상 큰 입력을 실제 실행 성공 사례로 취급하지 않는다.
- 순회 완료·빈 table·변경 중 순회·출력 포인터·cursor 전제, value가 다른 table의 key 기반 비교와 서로 다른 prototype의 관계를 원본 실행으로 확인한다.
- 삽입/교체/삭제/확장/reset/free의 실제 연속 상태, 삭제 중 확장 후보, callback 일관성·소유권·재진입·동시성 의무는 그대로 남아 있다.

독립 계획 검토를 받기 전 신규 실행·검증 코드를 작성하지 않는 조건은 계속 미충족 상태다. 이번에는 안전성 판정을 우회하는 에이전트 재요청이나 동적 프로그램 구현을 하지 않았다.

## 전체 범위 유지

전체 함수별 의미 원장·과거 증거 등록, IDA 독립 바이트/DB/export 및 fragments/경고/ABI, PD 참조·재사용·다중 backing·aging/PT GC, native RF/IDT/IRETD/fault, scheduler/context/FPU, 메모리 소유권·pager/COW/alias/PV, 장치/MMIO/interrupt/TLB/cache를 유지한다.

IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv, 공개 소스 계보, 실제 GCC 2.7 툴체인·컴파일·Mach-O 링크·부팅과 SPARC/후속 아키텍처별 검증도 미완료다.
