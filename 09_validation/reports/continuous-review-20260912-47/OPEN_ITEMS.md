# 남은 전체 분석

[report46의 미완료 목록](../continuous-review-20260912-46/OPEN_ITEMS.md)을 유지한다. prototype의 정적 동일성·복사·조회 경로를 이번에 연결했지만 실제 연속 상태 검증은 끝나지 않았다.

## 이번 범위의 후속 확인

- NXHash의 별도 prototype cache bootstrap `1caf74`, capacity helper `1caebc`/`1caedc`, growth `1cb504`, reset/free/teardown을 연결한다. NXMap 구조·함수를 그대로 대입하지 않는다.
- cache 초기화와 조회·삽입의 caller 직렬화, prototype 불변성, callback 재진입 및 실패·할당/회수 계약을 확인한다. get-before-insert를 원자적 interning이라고 가정하지 않는다.
- NXMap 실제 생성·공유·해제, 서로 같은/다른 prototype과 hash 충돌, 기본/custom zone의 연속 상태를 검증한다. 변경한 callback 주소의 산술 표본을 유효한 실행 fixture로 재사용하지 않는다.
- NXMap 원본 typedef와 iterator 선언의 출처, GCC 2.7 aggregate 전달·함수 포인터 ABI 및 할당자 호출 규약을 실제 도구로 검증한다.
- 삽입·교체·삭제·확장·순회·비교·reset/free의 실행 검증, report45의 삭제 중 확장 후보, capacity 범위와 도달성은 남아 있다.

독립 계획 검토 미수신 조건으로 신규 실행/검증 코드와 복원 구현은 보류 상태다. 이번 정적 판독을 교차검토 통과로 대체하지 않는다.

## 전체 범위는 여전히 미완료

전체 함수별 의미 원장·과거 증거 등록, IDA 독립 바이트/DB/export 검증, fragments·경고·타입/ABI를 유지한다. PD 참조·재사용·다중 backing·aging/PT GC, native RF/IDT/IRETD/fault, scheduler/context/FPU, 메모리 소유권·pager/COW/alias/PV, 장치/MMIO/interrupt/TLB/cache도 남아 있다.

IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv, 공개 소스 계보, 실제 GCC 2.7 툴체인·전체 컴파일·Mach-O 링크·부팅과 SPARC/후속 아키텍처별 검증도 미완료다. 자료 확보 완료와 의미 검증·복원 완료는 다른 판정이다.
