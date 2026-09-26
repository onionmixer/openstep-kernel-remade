# 남은 전체 분석

[report44의 전체 미완료 목록](../continuous-review-20260912-44/OPEN_ITEMS.md)을 유지한다. 이번 삽입·삭제·확장 분석은 정적 경로 근거이며 함수 전체 실행 검증이 아니다.

## NXMap 후속 검증

- 실제 원본 create→insert→교체→remove→reset/free를 연속 실행해 key/value 반환과 소유권을 확인한다. 새로운 실행·검증 코드 작성 전 독립 계획 검토 조건은 여전히 미충족이다.
- 첫 bucket 빈 삽입의 확장 검사 생략, collision 구간의 pair 이동과 wrap, 꽉 찬 table의 선행 확장, 삭제의 전체 구간 재구성과 역순 재삽입을 검사한다.
- 삭제 중 재삽입이 확장을 유발하는 입력 후보는 원본 실행으로 확인해야 한다. 계산된 hash와 분기 예측만으로 동적 결과를 확정하지 않는다.
- 구간 길이 16/17의 scratch 분기, 정확한 heap 크기와 수명, callback 일관성·변이·재진입·할당 실패를 검토한다. 진단 로그를 중단/rollback과 혼동하지 않는다.
- lookup과 mutation 경로의 sentinel key, divisor 유효성, 32-bit overflow 및 최대 크기의 실제 도달 전제를 확인한다.
- 원본 callback typedef와 소스 계보, Ghidra void 추론과 실제 EAX 소비의 차이, 고정 zone/allocator 및 자유로운 callback 부작용의 경계를 명세한다. DB·복원 타입 수정은 아직 하지 않았다.

## 계속 유지하는 전체 의무

전체 함수별 의미 원장·과거 증거 등록, IDA 독립 바이트/DB/export 및 fragments/경고/ABI, PD 참조·재사용·다중 backing·aging/PT GC, native RF/IDT/IRETD/fault, scheduler/context/FPU, 메모리 소유권·pager/COW/alias/PV, 장치/MMIO/interrupt/TLB/cache를 유지한다.

IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv, 공개 소스 계보, 실제 GCC 2.7 툴체인·컴파일·Mach-O 링크·부팅, SPARC와 후속 아키텍처별 검증 역시 미완료다. 현재 정적 검토를 전체 분석 완료나 신규 동적 시험의 대체물로 사용하지 않는다.
