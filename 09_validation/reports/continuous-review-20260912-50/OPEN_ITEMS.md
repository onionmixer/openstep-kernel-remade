# 남은 전체 분석

[report49의 전체 의무](../continuous-review-20260912-49/OPEN_ITEMS.md)를 유지한다. 문자열 함수의 정적 경로가 연결되었지만 실제 caller·VM 보호·동시성·수명 검증은 끝나지 않았다.

## 직접 이어갈 의무

- unique-string/WithLength의 실제 caller에서 길이 signedness, NULL 입력, buffer 수명·변경·직렬화 전제를 확인한다. NoCopy의 직접 참조 부재를 간접 사용 부재로 판정하지 않는다.
- pool 잠금 생성과 0/1 상태, short/long `_kalloc` 실패·수명, chunk 교체와 문자열 불변성·VM 보호를 연결한다. 헤더 주석만으로 read-only 보호를 확정하지 않는다.
- NULL/빈 문자열 동등성과 NULL 저장 포인터의 모호성, 기존 포인터 교체/로그 경로를 실제 연속 상태로 검증한다. 현재는 조건부 정적 결과다.
- signed-byte strcmp의 다른 caller, struct-key hash/equality 및 관련 convenience prototype을 검토한다. equality의 0 검사와 정렬용 부호 소비를 구분한다.
- 디컴파일에서 누락된 포인터 반환 및 WithLength의 int/size_t 차이, report48의 구조체 레지스터 반환을 실제 GCC 2.7 ABI에 연결한다.
- report49의 NXHash 복사 소유권·삭제 이동·연속 상태, report45의 NXMap 삭제 중 확장 후보 및 NXMap 원본 선언 의무는 계속 남는다.

코딩 전 독립 계획 검토 미수신 조건으로 신규 실행/검증 프로그램·복원 구현은 보류한다. 정적 판독·산술을 독립 교차검토 또는 실행 통과로 대체하지 않는다.

## 전체 범위 유지

전체 함수별 의미 원장·과거 증거 등록, IDA 독립 바이트/DB/export, fragments·경고·타입/ABI, PD 참조·재사용·다중 backing·aging/PT GC, native RF/IDT/IRETD/fault, scheduler/context/FPU, 메모리 소유권·pager/COW/alias/PV와 장치/MMIO/interrupt/TLB/cache가 남아 있다.

IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv, 공개 소스 계보, 실제 GCC 2.7 툴체인·전체 컴파일·Mach-O 링크·부팅과 SPARC/후속 아키텍처별 검증도 미완료다. 자료 확보 완료를 원본 전체 의미 검증 또는 최종 복원 완료로 확대하지 않는다.
