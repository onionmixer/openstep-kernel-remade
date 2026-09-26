# 남은 전체 분석

[report48의 전체 미완료 목록](../continuous-review-20260912-48/OPEN_ITEMS.md)을 유지한다. 이번 NXHash 연산별 정적 판독을 전체 caller/실행 검증 완료로 간주하지 않는다.

## 직접 이어갈 분석

- `NXUniqueStringNoCopy`와 관련 unique-string/atom caller, string hash/equality 및 할당·불변성 계약을 연결한다. `1cbe46`의 IfAbsent 호출이 자료상 연결되었지만 caller 전체는 아직 미검증이다.
- NXHashRemove의 실제 caller에서 저장 객체의 회수·참조 수명·동시성·불변성 전제를 확인한다. NULL data 분기 결과는 실제 caller 도달성이나 실행 시험이 아니다.
- create/insert/if-absent/remove/copy/compare/empty/reset/free의 실제 연속 상태, collision 배열 이동·할당 실패·재진입·count를 검증한다.
- copy에서 공유되는 data/prototype/info와 free callback의 소유권, 서로 다른 prototype 비교의 전제, `NXIsEqualHashTable` 선언의 출처를 확인한다.
- report48의 iterator 레지스터 반환·임시 info 초기화 부재, report45의 NXMap 삭제 중 확장 후보, NXMap 원본 typedef 및 GCC 2.7 aggregate/callback ABI를 유지한다.

독립 계획 검토 미수신 조건으로 신규 실행/검증 프로그램과 복원 구현은 보류 상태다. 원본 정적 판독이나 Python 산술을 교차검토·native 실행 통과로 대체하지 않는다.

## 전체 의무 유지

전체 함수별 의미 원장·과거 증거 등록, IDA 독립 바이트/DB/export, fragments·경고·타입/ABI, PD 참조·재사용·다중 backing·aging/PT GC, native RF/IDT/IRETD/fault, scheduler/context/FPU, 메모리 소유권·pager/COW/alias/PV와 장치/MMIO/interrupt/TLB/cache가 남아 있다.

IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv, 공개 소스 계보, 실제 GCC 2.7 툴체인·전체 컴파일·Mach-O 링크·부팅, SPARC/후속 아키텍처별 검증도 미완료다. 분석 자료 확보와 최종 복원 완료를 구분한다.
