# 남은 전체 분석

[report42의 미완료 목록](../continuous-review-20260912-42/OPEN_ITEMS.md)을 유지한다. 이번 metadata 대조로 함수 의미 원장이나 PD 동적 후속 검증을 완료하지 않았다.

## 원장에 반영할 미완료 작업

- 정상적인 독립 계획 교차검토와 root의 재확인 후 원장 생성기/consumer를 작성한다. 현재 코딩 전 검토 조건은 미충족이다.
- 전체 단위별 과거 증거를 실제 scope와 연결한다. 기본 미등록 상태를 역사적으로 분석된 적 없다는 뜻으로 사용하지 않는다.
- 도구 성공/실패/미요청, 데이터로 정정된 과거 entry, 인위적 조각, 경고, 의미 검증 상태를 분리한다.
- IDA 실패의 Ghidra 경고 유무와 무관하게 근거·경계·ABI 검토를 유지한다. 조각들의 원래 제어 흐름 문맥 재결합과 IDA 독립 바이트/DB 검증도 남아 있다.
- NXMap prototype의 직접 선언·소스 계보를 찾아 형태적 추론과 구분한다. 지금 확보한 hashtable2.h는 해당 NXMap 상수의 직접 선언 근거가 아니다.

## 계속 유지하는 전체 범위

원본 함수 계약·타입·ABI·분기·오류/rollback·동시성과 호출자 전제, PD 참조/슬롯 재사용·다중 backing·aging/PT 회수, native RF/IDT/IRETD/fault 재시도, scheduler/context/FPU, 메모리 발견·소유권·alias/PV·pager/COW, 장치/MMIO/interrupt/TLB/cache 분석을 유지한다.

IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv, 공개 소스 계보, 실제 GCC 2.7 툴체인·컴파일·Mach-O 링크·부팅 및 후속 아키텍처별 검증 역시 미완료다. 원본 주석·매크로·파일 배치의 유일 복원은 바이너리만으로 확정할 수 없다.
