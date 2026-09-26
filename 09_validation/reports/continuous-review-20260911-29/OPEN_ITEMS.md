# 잔여 분석 — 보고서29 이후

[보고서28 잔여 목록](../continuous-review-20260911-28/OPEN_ITEMS.md)의 전체 상위
의무를 유지한다. 이번에 연결한 범위는 익명 단일 object, detached free seed,
기존 PDE와 빈 target PTE, 빈 managed PV head에서의 할당/zero-fill/매핑/재시작이다.

- 실제 원본 object/map/pmap 생성과 전체 startup/메모리 발견, global descriptor
  table·PT/PV 소유권의 전체 일관성. 이번 descriptor/PT/object 준비는 합성이다.
- PDE 부재 시 PT 확장, wired allocator/zone와 연결된 실제 신규 자원 할당,
  free PT 재사용, 자원 실패·재검사·경합 중 선행 확장 처리.
- 기존 물리 매핑의 제거/대체, 여러 mapping의 PV 추가 노드 할당과 회수,
  dirty/reference bits, 전체 통계, TLB/cache의 실제 하드웨어 효과.
- pager device/vnode I/O, absent/error, error 포인터, COW/shadow/copy object,
  busy/wait/wakeup, map 변경과 재검사, pageout·free shortage 이후 실제 재시도.
- allocator의 활성/비활성 페이지 free, 비영 policy/sequential 적용,
  fictitious/already-free 경로, 실제 비동기/경합. 보고서28의 미검증 분기를 유지한다.
- CPU native IDT 진입 및 error/frame 생성, RF·CPL·스택 전환, 다른 예외,
  전체 문맥 전환·FS descriptor 조건·recover 수명.
- 부재 페이지에서 다중 byte/VM 경계의 부분 복사, 비연속 물리 페이지,
  copyin/read fault 등 이번 write/single-byte matrix 밖의 실제 진행.

전체 부팅/장치/동시성, ABI·타입·함수 경계·분리 조각 재결합, CPU 부작용 모델의
통합 및 전체 소비자 회귀, 동일 원본 IDA 독립 대조·교정안 재추출, 공개 소스 계보와
추적 가능한 복원 명세도 남아 있다. GCC 2.7 구현/컴파일/링크/부팅과 후속
아키텍처는 별도 미완료 단계이며, 이 보고서로 전체 목표를 완료 처리하지 않는다.

다음 우선 과제는 원본 PT 확장/할당의 생성·소유권 조건을 더 연결하는 것이다.
free-list 성공만을 전체 PT 생성의 대체 증거로 삼지 않고 신규 할당·실패 경로도
유지한다. 다음 코드도 계획 단계에서 독립 검토하고 원본/Python으로 재검증한다.
