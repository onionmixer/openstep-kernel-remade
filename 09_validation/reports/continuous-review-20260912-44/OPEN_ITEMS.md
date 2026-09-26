# 남은 전체 분석

[report43의 전체 미완료 목록](../continuous-review-20260912-43/OPEN_ITEMS.md)을 유지한다. callback 정적 계약을 확인했어도 그 함수들의 모든 실행 전제와 caller 전체 의미를 검증한 것은 아니다.

## NXMap·Objective-C 후속 의무

- NXMap prototype의 정확한 원본 선언·소스 계보, callback 전체 타입 및 GCC 2.7 함수 포인터 ABI를 확인한다. hashtable2.h의 유사 선언을 직접 근거로 대체하지 않는다.
- object-hash의 잘못 추론된 void와 callback 인자 생략을 DB 및 복원 타입에 반영하기 전, 관련 호출자 전체와 독립 검토 근거를 확보한다. 이번에는 DB를 바꾸지 않았다.
- 유효 table/selector/object 입력, bucket 수, sentinel key 제약, hash/equality 계약과 key 불변성, 충돌 탐색·wrap·insert/remove/rehash/reset의 실제 연속 실행을 검증한다.
- object-free의 key 소유권·value 관계, method의 실제 부작용과 실패/재진입을 검토한다. wrapper에 value 인자 읽기가 없다는 사실만으로 전체 value 수명을 판정하지 않는다.
- ObjC selector 등록·method cache/lookup/forwarding·nil·lock·동시성과 method ABI의 동적 결과는 별도 검증한다. 이번 AL 계산은 runtime 실행 증거가 아니다.

## 계속 남는 범위

독립 계획 교차검토 미수신에 따른 신규 실행·검증 코드 작성 보류, 전체 함수별 의미 원장과 과거 증거 등록, IDA 독립 바이트/DB/export, fragment 문맥 및 경고, PD 참조/재사용·다중 backing·aging/PT GC, native RF/IDT/IRETD/fault, scheduler/context/FPU, 메모리 소유권·pager/COW/alias/PV, 장치/MMIO/interrupt/TLB/cache를 유지한다.

IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv 전체의 의미 분석, 공개 소스 계보, 실제 GCC 2.7 툴체인·컴파일·Mach-O 링크·부팅 및 SPARC/후속 아키텍처별 검증도 미완료다. 이번 callback 분석으로 다른 subsystem 의무를 대체하지 않는다.
