# 잔여 분석 — 보고서28 이후

[보고서27 잔여 목록](../continuous-review-20260911-27/OPEN_ITEMS.md)과 전체 상위
의무를 유지한다. 이번 원본 page metadata 할당/해제/재할당 및 reserve 경계 시험으로
아래 범위를 완료 처리하지 않는다.

- vm_fault의 lookup miss에서 실제 allocator를 거쳐 zero-fill/pager/매핑으로
  연결되는 경로. 이번 시험은 allocator를 직접 호출했다.
- pageout wakeup 및 실제 대기자 처리, free-page 부족 후 thread_sleep/scheduler
  진행, pageout으로 자원이 생긴 뒤의 재시도.
- policy 비영의 sequential vm_policy_apply와 previous-page 조건, active/inactive
  page free, fictitious/already-free 분기 및 실제 경합/비동기 조건.
- 전체 startup/메모리 구성·object/map/pmap 생성, 실제 물리 frame/PV 소유권,
  PT 신규 할당·물리 매핑 교체·dirty/TLB/cache와 통계 정합.
- pager device/vnode operation 및 실제 I/O 성공/오류/absent, error 포인터,
  COW/shadow/copy object와 map 변경·wait/wakeup·재시도.

native IDT/CPU frame 생성·CPL/문맥 전환, 비연속 물리 페이지와 VM 경계 복사,
FS/descriptor/recover 수명, 전체 부팅, ABI/타입/함수 경계, CPU 부작용 표현 통합
및 전체 소비자 회귀, 장치/동시성, 동일 원본 IDA 대조·교정안 재추출, 공개 소스
계보·추적 가능한 복원 명세도 계속 남는다.

다음 실행 검증은 이 allocator 결과를 원본 vm_fault의 부재 페이지 처리와 연결할
선행조건을 원본에서 조사하고 코딩 전에 교차검토해야 한다. 합성 mapping 변경이나
mock 성공으로 원본 page-in을 대신하지 않는다.

GCC 2.7 구현·컴파일·링크·부팅과 후속 아키텍처는 별도 미완료 단계다.
