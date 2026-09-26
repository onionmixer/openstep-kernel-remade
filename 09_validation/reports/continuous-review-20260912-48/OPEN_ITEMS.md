# 남은 전체 분석

[report47의 전체 미완료 목록](../continuous-review-20260912-47/OPEN_ITEMS.md)을 유지한다. 이번에 bootstrap·growth·iterator·empty/reset/free의 정적 경로를 연결했지만 NXHash/NXMap 전체 실행 검증이나 전역 수명 검증이 완료된 것은 아니다.

## 후속 의무

- NXHash remove, insert-if-absent, copy, member/compare/equality의 계약과 실제 caller를 연결한다. iterator 반환형 누락을 관련 caller의 전체 상태·타입 검증에 반영한다.
- 초기화·조회·삽입·확장·정리의 연속 상태, cache 공유와 alias, prototype 불변성, callback 재진입·직렬화 및 실패/할당·회수 계약을 확인한다.
- 임시 rehash 본체의 info 초기화 부재와 no-effect callback 전달을 원본 사실로 유지한다. allocator가 특정 값으로 초기화한다고 가정하거나 관찰된 장애로 확대하지 않는다. 안전하면서 원본 동작을 보존하는 소스 표현은 별도 계획 검토와 ABI/실행 검증이 필요하다.
- capacity와 곱셈 경계의 caller 도달성·allocator 처리, 정리 중 callback이 보는 table 상태, 실제 순회/재삽입 순서와 count 보존을 검증한다.
- NXMap 원본 typedef/iterator 출처와 실제 GCC 2.7의 구조체 인자·반환 및 callback ABI를 확인한다. 현대 compiler 결과로 대체하지 않는다.
- report45 삭제 중 확장 후보와 NXMap 생성·삽입·삭제·순회·비교·reset/free 실행 검증을 유지한다.

코딩 전 독립 계획 검토 미수신 상태로 신규 실행/검증 프로그램·복원 구현은 보류한다. 이번 정적 분석을 독립 교차검토로 취급하지 않는다.

## 전체 범위 유지

전체 함수별 의미 원장·과거 증거 등록, IDA 독립 바이트/DB/export, fragments·경고·타입/ABI, PD 참조·재사용·다중 backing·aging/PT GC, native RF/IDT/IRETD/fault, scheduler/context/FPU를 유지한다.

메모리 소유권·pager/COW/alias/PV, 장치/MMIO/interrupt/TLB/cache, IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv, 공개 소스 계보, 실제 GCC 2.7 툴체인·전체 컴파일·Mach-O 링크·부팅 및 SPARC/후속 아키텍처 검증도 미완료다.
