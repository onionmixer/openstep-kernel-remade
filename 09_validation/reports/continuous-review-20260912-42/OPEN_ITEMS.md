# 남은 분석 — 전체 범위 유지

[report41의 전체 미완료 목록](../continuous-review-20260912-41/OPEN_ITEMS.md)을 그대로 유지한다. 이번 정적 검토는 동적 재사용·참조 수명이나 다중 PD backing 회수를 완료하지 않았다.

## 현재 단계에서 남은 작업

- [계획 교차검토](CROSS_REVIEW.md)의 정상적인 독립 검토 결과 확보 및 원본과의 재대조. 현재 의견 미수신이며 코딩 전 조건은 미충족이다.
- fresh 원본 생성 prefix에서 NULL/nonzero 분기, refcount 증가·비최종 감소·최종 반환·동일 슬롯 재사용까지 새 연속 실행.
- 새 경로에 대한 독립 consumer, refcount/lock/bitmap/zone/복사 주소·값·쓰기 검증, 기록 변조 대조와 재현성.
- 직접 호출자의 실제 map/pmap 참조 수명, 유효 매핑 제거, 실패/rollback 및 중첩·공유 map 전제 확인. 직접 호출 목록 확보를 함수 전체 분석 완료로 보지 않는다.
- 간접 호출 및 그 외 참조 형식에 대한 별도 검토. 이번 raw-call 대조는 보존 instruction의 `E8 rel32`로 한정된다.

## 계속 남는 전체 의무

다중 backing 큐/재시작, aging에서 다음 PT GC로 이어지는 동일 상태, 실제 새 PD 활성화, native RF/IDT/IRETD/fault 재시도, scheduler/context/FPU/경합, 부족·pager·COW·alias/PV·memory discovery, 장치와 MMIO·interrupt·TLB/cache를 유지한다.

IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv, 전체 함수 의미 상태 원장과 ABI/타입/경계/경고, 독립 IDA 바이트/DB/export 및 공개 소스 계보 검토도 남아 있다. GCC 2.7 실제 툴체인·컴파일·Mach-O 링크·부팅과 후속 아키텍처별 분석 역시 미완료다.
