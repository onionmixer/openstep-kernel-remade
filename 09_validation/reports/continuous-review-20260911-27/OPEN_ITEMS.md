# 잔여 분석 — 보고서27 이후

[보고서26 잔여 목록](../continuous-review-20260911-26/OPEN_ITEMS.md) 및 그 목록이
계승한 전체 의무를 유지한다. 새 정적 색인의 완성을 전체 의미 분석이나 원본
VM 경로의 실행 완료로 취급하지 않는다.

이번에 추가한 근거는 VM 주요 결과/재시도/인자 계약과 선택 함수 본문 전체의
기계적 branch/call census다. 미검증 경로는 [VM 계약](VM_CONTRACTS.md)과
[제어 이전 색인](transfer-index.json)의 원본 주소로 추적할 수 있다.
report26 미관찰은 다른 보고서에서도 미분석이라는 뜻이 아니다.

다음 실행 검증 전에 해결할 상태/계약:

- page alloc 및 free의 원본 queue·hash·memq·busy/wanted와 paging/ref 수명.
  free-page 부족 시 scheduler/thread_sleep와 pageout wakeup의 실제 진행 조건.
- PT 확장에 필요한 kernel_map·wired allocation·PT free/active 목록·descriptor
  및 원본 생성/소유권. 자원 실패 후 재검사와 타 실행 주체의 선행 확장 처리.
- 물리 매핑 교체의 기존 PV 제거·새 PV 추가·통계·PTE 및 dirty 상태. managed
  범위를 바꾸어 PV를 우회하는 fixture로 전체 경로를 대체하지 않기.
- pager 실제 device/vnode 경로와 간접 operation 호출, 페이지 도착/오류/absent,
  NULL/비NULL error 포인터. mock 반환값은 원본 I/O 성공 증거가 아니다.
- busy/wait의 0/4/그 외 결과, copy-object 대기, map 재검사 후 object/offset/
  wired protection 변화. 반환0과 매핑완료·실제 명령 진행을 분리하여 검사.

native IDT/CPU frame, CPL/문맥 전환, 비연속 물리 페이지와 VM 경계 복사,
FS/descriptor/recover 수명, 전체 부팅, ABI/타입/함수 경계, CPU 부작용 통합 및
전체 소비자 회귀, 동시성/장치/TLB/cache, 동일 원본 IDA 대조와 교정안 재추출,
공개 소스 계보·추적 가능한 복원 명세도 계속 남는다.

GCC 2.7 구현·컴파일·링크·부팅과 후속 아키텍처는 별도 미완료 단계다.
다음 검증 코드도 작성 전에 독립 Codex 검토를 받고 원본으로 재검증한다.
